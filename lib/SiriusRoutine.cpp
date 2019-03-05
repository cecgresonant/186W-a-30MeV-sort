
#include "SiriusRoutine.h"

#include "Event.h"
#include "Histogram1D.h"
#include "Histogram2D.h"

#include <TFile.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

#define NDEBUG
#include "debug.h"

// ########################################################################
// ########################################################################

SiriusRoutine::SiriusRoutine()
    : gain_e   ( GetParameters(), "gain_e",    64 )
    , gain_de  ( GetParameters(), "gain_de",   64 )
    , gain_ge  ( GetParameters(), "gain_ge",    6 )
    , gain_na  ( GetParameters(), "gain_na",   32 )
    , shift_e  ( GetParameters(), "shift_e",   64 )
    , shift_de ( GetParameters(), "shift_de",  64 )
    , shift_ge ( GetParameters(), "shift_ge",   6 )
    , shift_na ( GetParameters(), "shift_na",  32 )
    , shift_tge( GetParameters(), "shift_tge",  6 )
    , shift_tna( GetParameters(), "shift_tna", 32 )
    , gain_tge ( GetParameters(), "gain_tge",   6 )
    , gain_tna ( GetParameters(), "gain_tna",  32 )
    , time_start( 0 )
    , time_diff( 0 )
{
    for(int i=0; i<64; ++i) {
        gain_e  .Set( i, 5   );
        gain_de .Set( i, 2.5 );
        shift_e .Set( i, 0 );
        shift_de.Set( i, 0 );
    }
    for(int i=0; i<32; ++i) {
        gain_na  .Set( i, 1 );
        gain_tna .Set( i, 1 );
        shift_na .Set( i, 0 );
        shift_tna.Set( i, 0 );
    }
    for(int i=0; i<6; ++i) {
        gain_ge  .Set( i, 1 );
        gain_tge .Set( i, 1 );
        shift_ge .Set( i, 0 );
        shift_tge.Set( i, 0 );
    }
}

// ########################################################################

bool SiriusRoutine::Start()
{
    CreateSpectra();
    return true;
}

// ########################################################################

bool SiriusRoutine::End()
{
    return true;
}

// ########################################################################

static bool set_par(Parameters& parameters, std::istream& ipar,
                    const std::string& name, int size)
{
    Parameter* p = parameters.Find(name);
    if( !p )
        return false;

    std::vector<Parameter::param_t> values;
    float tmp;
    for(int i=0; i<size; ++i) {
        tmp = 0;
        ipar >> tmp;
        values.push_back(tmp);
    }
    p->Set( values );

    return ipar;
}

static bool set_gainshift(Parameters& parameters, std::istream& ipar)
{
    return set_par(parameters, ipar, "gain_e",    64 )
        && set_par(parameters, ipar, "gain_de",   64 )
        && set_par(parameters, ipar, "gain_ge",    6 )
        && set_par(parameters, ipar, "gain_na",   32 )
        && set_par(parameters, ipar, "shift_e",   64 )
        && set_par(parameters, ipar, "shift_de",  64 )
        && set_par(parameters, ipar, "shift_ge",   6 )
        && set_par(parameters, ipar, "shift_na",  32 )
        && set_par(parameters, ipar, "shift_tge",  6 )
        && set_par(parameters, ipar, "shift_tna", 32 )
        && set_par(parameters, ipar, "gain_tge",   6 )
        && set_par(parameters, ipar, "gain_tna",  32 );
}

// ########################################################################

bool SiriusRoutine::Command(const std::string& cmd)
{
    std::istringstream icmd(cmd.c_str());

    std::string name, tmp;
    icmd >> name;
    
    if( name == "gain" ) {
        icmd >> tmp;
        if( tmp == "file" ) {
            std::string filename;
            icmd >> filename; // XXX no spaces possible
            std::ifstream gainfile(filename.c_str());
            if( !set_gainshift(GetParameters(), gainfile) ) {
                std::cerr << "gain file: error reading '"<<filename<<"'.\n";
                return false;
            }
        } else if( tmp == "data" ) {
            if( !set_gainshift(GetParameters(), icmd) ) {
                std::cerr << "gain data: error reading calibration data.\n";
                return false;
            }
        } else {
            std::cerr << "gain: Expected 'file' or 'data', not '"<<tmp<<"'.\n";
            return false;
        }
    } else if( name == "parameter" ) {
        return GetParameters().SetAll(icmd);
    } else {
        return false;
    }
    return true;
}

// ########################################################################

unsigned long SiriusRoutine::Timediff(const Event& event)
{
    if( event.has_time ) {
        if( time_start == 0 )
            time_start = event.time;
        time_diff = event.time - time_start;
    }
    return time_diff;
}
