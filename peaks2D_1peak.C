
// peak finding macro for the calibration of CACTUS and SiRi with 12C
// data; written by Alexander Bürger on 2010-01-22
// Modified to be used for the 186W(a,t)188Re g.s. and the 9/2+ state in 19F from 16O(a,p)19F
// by Cecilie, 11 March 2019
//
// first, the macro has to be compiled and loaded:
// .L peaks2D_1peak.C++
//
// then, for SiRi:
// start_ede()                    // write to "peaks_ede.csv", start at back=0 front=0 peak=0
// start_ede("mypeaks.csv")       // write to "mypeaks.csv", start at back=0 front=0 peak=0
// start_ede("mypeaks.csv",2)     // write to "mypeaks.csv", start at back=2 front=0 peak=0
// start_ede("mypeaks.csv",2,3)   // write to "mypeaks.csv", start at back=2 front=3 peak=0
// start_ede("mypeaks.csv",2,3,1) // write to "mypeaks.csv", start at back=2 front=3 peak=1
//
// here, the peaks are 0=g.s., 1=4.4MeV, 2=9.6MeV in the matrices
// m_e_de_bXfY; click on the respective peak to zoom in; if you zoomed
// in enough either press 'x' or continue clicking until the macro
// decides it is enough; then the macro will try to determine the peak
// position with 2 methods: 2D takes the weighted mean of the 20
// highest bins in the zoomed area -- the result is shown in magenta;
// proj first projects and then takes the weighted mean of the highest
// 10 bins -- the result is in blue; the results are printed on the
// screen and written to the file; columns are separated by tab
// characters for easy inclusion in a spreadsheet (filetype "CSV");
// you can then check the fit results on the screen; when you are
// done, press 'c' or space to go to the next peak
//
// for CACTUS:
// start_nai()                 // write to "peaks_nai.csv", start at detector 0
// start_nai("cactus.csv")     // write to "cactus.csv", start at detector 0
// start_nai("cactus.csv", 3)  // write to "cactus.csv", start at detector 3
//
// here, the peaks are 0=4.4MeV, 1=511keV in the matrices
// m_nai_e_t_XY; the procedure is as for SiRi
//
// the macro can be stopped at any time by pressing 'q'; it must be
// stopped before reloading


#include <TAxis.h>
#include <TCanvas.h>
#include <TDirectory.h>
#include <TH2.h>
#include <TLine.h>
#include <TPad.h>
#include <TSystem.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

static const bool debug  = 0;
//static const int nmax_proj = 5;
static const int nmax_proj = 20;    // more channels
static const int nmax_2d   = 2*nmax_proj;

class Peaks2D : public TNamed {
public:
    Peaks2D(float mwx, float mwy);
    virtual ~Peaks2D();

    static const char* P2D_OBJECT;
    static const char* P2D_EXECNAME;

    void Start();
    bool HandleExec();

protected:
    virtual void UnZoom();
    virtual TH2* NextMatrix() = 0;
    virtual void ShowPeak(double px2d, double py2d, double pxp, double pyp);
    void DrawPeakCross(double px2d, double py2d, double pxp, double pyp);

private:
    bool ZoomIn(int px, int py);
    void DrawMatrix();
    void FindPeak();
    void FindPeak2D(double& peakx, double& peaky);
    double FindPeak1D(TH1* h, int xf, int xl);
    void FindPeakProjection(double& peakx, double& peaky);
    void DoNextMatrix();

    TH2* matrix;
    float minwidthx, minwidthy;
    enum {ZOOMING, SHOWING} state;

    ClassDef(Peaks2D,1);
};

const char* Peaks2D::P2D_OBJECT = "Peaks2D_object";
const char* Peaks2D::P2D_EXECNAME = "Peaks2D_exec";
ClassImp(Peaks2D);

// ------------------------------------------------------------------------

Peaks2D::Peaks2D(float mwx, float mwy)
    : TNamed(P2D_OBJECT, P2D_OBJECT)
    , matrix(0)
    , minwidthx(mwx)
    , minwidthy(mwy)
    , state(ZOOMING)
{
    if( debug )
        cout << "Peaks2D constructor" << endl;
}
// ------------------------------------------------------------------------

void Peaks2D::Start()
{
    DoNextMatrix();
    Draw();
    gPad->AddExec(P2D_EXECNAME, "Peaks2D_exec()");
    if( debug )
        cout << "Peaks2D::Peaks2D: AddExec done" << endl;
}

// ------------------------------------------------------------------------

Peaks2D::~Peaks2D()
{
    if( debug )
        cout << "Peaks2D destructor" << endl;
}

// ------------------------------------------------------------------------

bool Peaks2D::HandleExec()
{
    if( debug ) {
        static int count = 0;
        if( !((++count) & 0xff) )
            cout << "Peaks2D::HandleExec " << count << endl;
    }

    // stop zooming when key is pressed
    const int event  = gPad->GetEvent();
    const int eventx = gPad->GetEventX();
    const int eventy = gPad->GetEventY();

    // some checks...
    if( !matrix )
        return false;

    // quit everything when 'q' was pressed
    if( event == kKeyPress && eventx == 'q' ) {
        cout << "Quit on 'q' key." << endl;
        return false;
    }

    if( event == kKeyPress && eventx == 'x' && state == ZOOMING ) {
        // accept zoom when 'x' is pressed
        if( debug )
            cout << "Accepted zoom on 'x' key." << endl;
        state = SHOWING;
        FindPeak();
    } else if( state == ZOOMING  && event == kButton1Up ) {
        // check that selected object is a matrix
        TObject *s = gPad->GetSelected();
        if( !s || !s->InheritsFrom("TH2") )
            return true;
        // only zoon if mouse clicked (exactly: released)
        if( debug )
            cout << "About to zoom in." << endl;
        if( !ZoomIn(eventx, eventy) ) {
            if( debug )
                cout << "Minimal zoom, showing peaks." << endl;
            state = SHOWING;
            FindPeak();
        }
    } else if( state == SHOWING && event == kKeyPress && (eventx == 'c' || eventx == ' ') ) {
        if( debug )
            cout << "end of show. FindMatrix()." << endl;
        DoNextMatrix();
        if( !matrix ) {
            if( debug )
                cout << "No matrix. Stop." << endl;
            else
                cout << "Stop." << endl;
            return false;
        }
        state = ZOOMING;
    }
    return true;
}

// ------------------------------------------------------------------------

bool Peaks2D::ZoomIn(int px, int py)
{
    // only go down to a minimum width
    TAxis *xax = matrix->GetXaxis(), *yax = matrix->GetYaxis();
    float widthx = xax->GetBinUpEdge(xax->GetLast()) - xax->GetBinLowEdge(xax->GetFirst());
    float widthy = yax->GetBinUpEdge(yax->GetLast()) - yax->GetBinLowEdge(yax->GetFirst());

    const float x = gPad->PadtoX(gPad->AbsPixeltoX(px));
    const float y = gPad->PadtoY(gPad->AbsPixeltoY(py));
    if( debug )
        cout << "zoom: click on x= " << x << " y= " << y
             << " widthx=" << widthx << " widthy=" << widthy << endl;

    if( widthx >= minwidthx ) {
        widthx = std::max(minwidthx/2, widthx/4);
        xax->SetRangeUser(x-widthx,   x+widthx);
    }
    if( widthy >= minwidthy ) {
        widthy = std::max(minwidthy/2, widthy/4);
        yax->SetRangeUser(y-widthy, y+widthy);
    }
    return widthx >= minwidthx || widthy >= minwidthy;
}

// ------------------------------------------------------------------------

void Peaks2D::UnZoom()
{
    if( debug )
        cout << "unzoom" << endl;
    if( matrix ) {
        matrix->GetXaxis()->UnZoom();
        matrix->GetYaxis()->UnZoom();
        DrawMatrix();
    }
}

// ------------------------------------------------------------------------

void Peaks2D::DoNextMatrix()
{
    UnZoom();
    matrix = NextMatrix();
    UnZoom();
}

// ------------------------------------------------------------------------

void Peaks2D::DrawMatrix()
{
    if( matrix ) {
        matrix->Draw();
        if( debug )
            cout << "Peaks2D::DrawMatrix: draw" << endl;
    }
    this->Draw();
    if( gPad )
        gPad->Update();
}

// ------------------------------------------------------------------------

void Peaks2D::FindPeak2D(double& peakx, double& peaky)
{
    TAxis *xax = matrix->GetXaxis(), *yax = matrix->GetYaxis();
    int xf = xax->GetFirst();
    int xl = xax->GetLast();
    int yf = yax->GetFirst();
    int yl = yax->GetLast();

    // find the nmax bins with the highest contents and calculate
    // their weighted average

    double sumw = 0, sumxw = 0, sumyw = 0;
    // first, find the highest value
    double nextmax = -1;
    for(int x=xf; x<=xl; ++x) {
        for(int y=yf; y<=yl; ++y) {
            double b = matrix->GetBinContent(x, y);
            if( b>0 && b>nextmax )
                nextmax = b;
        }
    }
    for(int i=0; i<nmax_2d; ++i) {
        double maxi = nextmax;
        if( maxi<0 )
            break;
        nextmax = -1;
        for(int x=xf; x<=xl; ++x) {
            for(int y=yf; y<=yl; ++y) {
                double b = matrix->GetBinContent(x, y);
                if( b == maxi ) {
                    // sum all values equal to the highest
                    sumxw += x*maxi;
                    sumyw += y*maxi;
                    sumw  += maxi;
                } else if( b>0 && b<maxi && b>nextmax ) {
                    // and determine the next-hightest value
                    nextmax = b;
                }
            }
        }
    }
    if( sumw>0 ) {
        peakx = xax->GetXmin() + xax->GetBinWidth(1)*(sumxw / sumw - 0.5);
        peaky = yax->GetXmin() + yax->GetBinWidth(1)*(sumyw / sumw - 0.5);
    } else {
        peakx = peaky = -1e20;
    }
}

// ------------------------------------------------------------------------

double Peaks2D::FindPeak1D(TH1* h, int xf, int xl)
{
    // find the nmax_proj bins with the highest contents and calculate
    // their weighted average

    double sumw = 0, sumxw = 0;
    // first, find the highest value
    double nextmax = -1;
    for(int x=xf; x<=xl; ++x) {
        double b = h->GetBinContent(x);
        if( b>0 && b>nextmax )
            nextmax = b;
    }
    for(int i=0; i<nmax_proj; ++i) {
        double maxi = nextmax;
        if( maxi<0 )
            break;
        nextmax = -1;
        for(int x=xf; x<=xl; ++x) {
            double b = h->GetBinContent(x);
            if( b == maxi ) {
                // sum all values equal to the highest
                sumxw += x*maxi;
                sumw  += maxi;
            } else if( b>0 && b<maxi && b>nextmax ) {
                // and determine the next-hightest value
                nextmax = b;
            }
        }
    }
    if( sumw>0 ) {
        TAxis *xax = h->GetXaxis();
        return xax->GetXmin() + xax->GetBinWidth(1)*(sumxw / sumw - 0.5);
    } else {
        return -1e20;
    }
}

// ------------------------------------------------------------------------

void Peaks2D::FindPeakProjection(double& peakx, double& peaky)
{
    // get the bin numbers to which we have zoomed
    TAxis *xax = matrix->GetXaxis(), *yax = matrix->GetYaxis();
    int xf = xax->GetFirst();
    int xl = xax->GetLast();
    int yf = yax->GetFirst();
    int yl = yax->GetLast();

    // project on X in the selected Y range and find peak
    TH1* p = matrix->ProjectionX("__w_eee_ird", yf, yl, "o");
    peakx = FindPeak1D(p, xf, xl);
    delete p;

    // project on X in the selected X range and find peak
    p = matrix->ProjectionY("__w_eee_ird", xf, xl, "o");
    peaky = FindPeak1D(p, yf, yl);
    delete p;
}

// ------------------------------------------------------------------------

void Peaks2D::FindPeak()
{
    // first try to find the peak in the matrix
    double peakx_2d, peaky_2d;
    FindPeak2D(peakx_2d, peaky_2d);

    // try again, now in the matrix projections
    double peakx_p, peaky_p;
    FindPeakProjection(peakx_p, peaky_p);
    
    ShowPeak(peakx_2d, peaky_2d, peakx_p, peaky_p);
}

// ------------------------------------------------------------------------

void Peaks2D::ShowPeak(double, double, double, double)
{
}

// ------------------------------------------------------------------------

void Peaks2D::DrawPeakCross(double px2d, double py2d, double pxp, double pyp)
{
    TAxis *xax = matrix->GetXaxis(), *yax = matrix->GetYaxis();
    float wx = xax->GetBinUpEdge(xax->GetLast()) - xax->GetBinLowEdge(xax->GetFirst());
    xax->SetRangeUser(pxp-2*wx, pxp+2*wx);
    float wy = yax->GetBinUpEdge(yax->GetLast()) - yax->GetBinLowEdge(yax->GetFirst());
    yax->SetRangeUser(pyp-2*wy, pyp+2*wy);

    if( debug )
        cout << "DrawPeakCross: "
             << " widthx=" << wx << " widthy=" << wy << endl;

    TLine l;
    l.SetLineWidth(5);

    // draw 2d peak in magenta
    l.SetLineColor(kMagenta);
    l.DrawLine(px2d-wx/4, py2d-wy/4, px2d+wx/4, py2d+wy/4);
    l.DrawLine(px2d+wx/4, py2d-wy/4, px2d-wx/4, py2d+wy/4);
    // draw projection peak in blue
    l.SetLineColor(kBlue);
    l.DrawLine(pxp-wx/4, pyp, pxp+wx/4, pyp);
    l.DrawLine(pxp, pyp-wy/4, pxp, pyp+wy/4);

    gPad->Update();
}

// ========================================================================

// function added to the canvas as an exec; this function is called
// every time the mouse is moved, a key is pressed, ...; the purpose
// is to forward the call to the correct object
void Peaks2D_exec()
{
    TObject* o = gPad->GetPrimitive(Peaks2D::P2D_OBJECT);
    Peaks2D* p2d = (Peaks2D*)o;
    if( !o ) {
        if( debug )
            cout << "No Peaks2D object, removing exec '" << Peaks2D::P2D_EXECNAME << "'" << endl;
        gPad->DeleteExec(Peaks2D::P2D_EXECNAME);
    } else if( !p2d->HandleExec() ) {
        if( debug )
            cout << "Removing exec '" << Peaks2D::P2D_EXECNAME << "'" << endl;
        gPad->DeleteExec(Peaks2D::P2D_EXECNAME);
        delete p2d;
    }
}

// ========================================================================

class Peaks_EDE : public Peaks2D {
public:
    Peaks_EDE(const char* outfilename, int back=0, int front=0, int peak=-1);

protected:
    TH2* NextMatrix();
    void ShowPeak(double px2d, double py2d, double pxp, double pyp);

private:
    const char* outfilename;
    int iBack, iFront, iPeak;
    static const int nPeaks;
    ClassDef(Peaks_EDE,1);
};
ClassImp(Peaks_EDE);

// ------------------------------------------------------------------------

Peaks_EDE::Peaks_EDE(const char* on, int back, int front, int peak)
    : Peaks2D(500, 300)
    , outfilename(on)
    , iBack(back)
    , iFront(front)
    , iPeak(peak)
{
}

// ------------------------------------------------------------------------

//const int Peaks_EDE::nPeaks = 3;  // three peaks
//const int Peaks_EDE::nPeaks = 2;    // two peaks
const int Peaks_EDE::nPeaks = 1;    // one peak


// ------------------------------------------------------------------------

TH2* Peaks_EDE::NextMatrix()
{
    if( debug )
        cout << "Peaks_EDE::NextMatrix start: i=" << iPeak << " f=" << iFront << " b=" << iBack << endl;

    // go to next peak/front/back detector
    iPeak += 1;
    if( iPeak >= nPeaks ) {
        iPeak = 0;
        iFront += 1;
        if( iFront >= 8 ) {
            iFront = 0;
            iBack += 1;
        }
    }
    // check if everything is in range
    if( iPeak<0 || iPeak>nPeaks || iBack<0 || iBack>7 || iFront<0 || iFront>7 ) {
        if( debug )
            cout << "Peaks_EDE::NextMatrix : out of range" << endl;
        return 0;
    }

    // build matrix name
    char tmp[128];
    snprintf(tmp, sizeof(tmp), "m_e_de_b%df%d", iBack, iFront);

    // find matrix
    return (TH2*)gDirectory->Get(tmp);
}

// ------------------------------------------------------------------------

void Peaks_EDE::ShowPeak(double px2d, double py2d, double pxp, double pyp)
{
    DrawPeakCross(px2d,  py2d, pxp, pyp);

    //const char* peakname[nPeaks] = {"12C_0M", "12C_4M", "12C_9M" };// three peaks
    //const char* peakname[nPeaks] = {"188Re_0", "19F_6" }; // two peaks, g.s. of 188Re and 6th Ex of 19F
    const char* peakname[nPeaks] = {"186W_0gs" }; // one peak
    if( iPeak==0 )
        cout << "\tb(2d)=" << iBack << "\tf(2d)=" << iFront
             << "\tb(proj)=" << iBack << "\tf(proj)=" << iFront << endl;
    cout << peakname[iPeak] << '\t' << px2d << '\t' << py2d << '\t' << pxp << '\t' << pyp << endl;

    if( outfilename ) {
        ofstream fout(outfilename, ios::app|ios::out);
        if( iPeak==0 )
            fout << "\tb(2d)=" << iBack << "\tf(2d)=" << iFront
                 << "\tb(proj)=" << iBack << "\tf(proj)=" << iFront << endl;
        fout << peakname[iPeak] << '\t' << px2d << '\t' << py2d << '\t' << pxp << '\t' << pyp << endl;
    }
}

// ========================================================================

// start peak fitting for SiRi
void start_ede(const char* outfilename="peaks_ede.csv", int back=0, int front=0, int peak=-1)
{
    if( !gPad ) {
        new TCanvas();
        gSystem->ProcessEvents();
    }
    if( !gPad ) {
        cout << "No gPad. Stop." << endl;
        return;
    }
    gPad->SetLogz();

    cout << "#name\tpeak2d_x\tpeak2d_y\tproj_x\tproj_y" << endl;
    if( outfilename ) {
        ofstream fout(outfilename, ios::app|ios::out);
        fout << "#name\tpeak2d_x\tpeak2d_y\tproj_x\tproj_y" << endl;
    }
    (new Peaks_EDE(outfilename, back, front, peak))->Start();
}

// ========================================================================

class PeaksAny : public Peaks2D {
public:
    PeaksAny(const char* outfilename, TH2* matrix);

protected:
    TH2* NextMatrix();
    void ShowPeak(double px2d, double py2d, double pxp, double pyp);

private:
    const char* outfilename;
    TH2* matrix;
    int iPeak;

    ClassDef(PeaksAny,1);
};
ClassImp(PeaksAny);

// ------------------------------------------------------------------------

PeaksAny::PeaksAny(const char* on, TH2* m)
    : Peaks2D(400, 200)
    , outfilename(on)
    , matrix(m)
    , iPeak(-1)
{
}

// ------------------------------------------------------------------------

TH2* PeaksAny::NextMatrix()
{
    iPeak += 1;
    return matrix;
}

// ------------------------------------------------------------------------

void PeaksAny::ShowPeak(double px2d, double py2d, double pxp, double pyp)
{
    DrawPeakCross(px2d,  py2d, pxp, pyp);

    std::ostringstream o;
    o << matrix->GetName() << "_p" << iPeak
      << '\t' << px2d << '\t' << py2d << '\t' << pxp << '\t' << pyp;

    cout << o.str() << endl;
    if( outfilename ) {
        ofstream fout(outfilename, ios::app|ios::out);
        fout << o.str() << endl;
    }
}

// ========================================================================

// start peak fitting for SiRi
void start_any(const char* outfilename="peaks_any.csv", TH2* matrix=0)
{
    if( !gPad ) {
        new TCanvas();
        gSystem->ProcessEvents();
    }
    if( !gPad ) {
        cout << "No gPad. Stop." << endl;
        return;
    }
    gPad->SetLogz();
    if( !matrix ) {
        TList *Obj = gPad->GetListOfPrimitives();
        TListIter next(Obj);
        TObject *select  = next();
        while( select && !select->InheritsFrom("TH2") )
            select  = next();
        if( select )
            matrix = (TH2*)select;
    }
    if( !matrix ) {
        cout << "No TH2. Stop." << endl;
        return;
    }

    (new PeaksAny(outfilename, matrix))->Start();
}

// ========================================================================

class Peaks_NAI : public Peaks2D {
public:
    Peaks_NAI(const char* outfilename, int det=0);

protected:
    TH2* NextMatrix();
    void ShowPeak(double px2d, double py2d, double pxp, double pyp);

private:
    const char* outfilename;
    int iDet, iPeak;
    float px4, py4;
    ClassDef(Peaks_NAI,1);
};
ClassImp(Peaks_NAI);

// ------------------------------------------------------------------------

Peaks_NAI::Peaks_NAI(const char* on, int det)
    : Peaks2D(150, 20)
    , outfilename(on)
    , iDet(det)
    , iPeak(-1)
{
}

// ------------------------------------------------------------------------

TH2* Peaks_NAI::NextMatrix()
{
    if( debug )
        cout << "Peaks_NAI::NextMatrix start: i=" << iPeak << " d=" << iDet << endl;

    // go to next peak/front/back detector
    iPeak += 1;
    if( iPeak >= 2 ) {
        iPeak = 0;
        iDet += 1;
    }
    // check if everything is in range
    if( iPeak<0 || iPeak>2 || iDet<0 || iDet>27 ) {
        if( debug )
            cout << "Peaks_NAI::NextMatrix : out of range" << endl;
        return 0;
    }

    // build matrix name
    char tmp[128];
    snprintf(tmp, sizeof(tmp), "m_nai_e_t_%02d", iDet);

    // find matrix
    return (TH2*)gDirectory->Get(tmp);
}

// ------------------------------------------------------------------------

void Peaks_NAI::ShowPeak(double px2d, double py2d, double pxp, double pyp)
{
    DrawPeakCross(px2d,  py2d, pxp, pyp);

    if( iPeak == 0 ) {
        //px4 = pxp; py4 = pyp;
        px4 = px2d; py4 = py2d;
    } else {
        //cout << iDet << '\t' << pxp << '\t' << px4 << '\t' << pyp << '\t' << py4 << endl;
        cout << iDet << '\t' << px2d << '\t' << px4 << '\t' << py2d << '\t' << py4 << endl;
        if( outfilename ) {
            ofstream fout(outfilename, ios::app|ios::out);
            fout << iDet << '\t' << px2d << '\t' << px4 << '\t' << py2d << '\t' << py4 << endl;
        }
    }
}

// ========================================================================

// start peak fitting for CACTUS
void start_nai(const char* outfilename="peaks_nai.csv", int det=0)
{
    if( !gPad ) {
        new TCanvas();
        gSystem->ProcessEvents();
    }
    if( !gPad ) {
        cout << "No gPad. Stop." << endl;
        return;
    }
    gPad->SetLogz();

    cout << "#det\tpeak_E_511k\tpeak_E_4M\tpeak_t_511k\tpeak_t_4M" << endl;
    if( outfilename ) {
        ofstream fout(outfilename, ios::app|ios::out);
        fout << "#det\tpeak_E_511k\tpeak_E_4M\tpeak_t_511k\tpeak_t_4M" << endl;
    }
    (new Peaks_NAI(outfilename, det))->Start();
}
