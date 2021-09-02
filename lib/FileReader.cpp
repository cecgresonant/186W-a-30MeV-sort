/*
 * FileReader.cpp
 *
 *  Created on: 10.03.2010
 *      Author: Alexander Bürger
 */

#include "FileReader.h"

#include "Buffer.h"

FileReader::FileReader()
    : file_stdio(0)
//    , file_gz(0)
    , errorflag( true )
{
}

// ########################################################################

FileReader::~FileReader()
{
    Close();
}

// ########################################################################

int FileReader::Read(char* data, unsigned int size_req)
{
    if( errorflag || (!file_stdio /*&& !file_gz*/) )
        return -1;

    unsigned int have = 0;
    while( have<size_req ) {
        int now = -1;
        if( file_stdio )
            now = std::fread(data+have, 1, size_req-have, file_stdio);
        /*else if( file_gz )
            now = gzread(file_gz, data+have, size_req-have);*/
        if( now<=0 ) {
            errorflag = (now<0 || (have!= 0 && have!=size_req));
            Close();
            return errorflag ? -1 : 0;
        } else {
            have += now;
        }
    }
    return 1;
}

// ########################################################################

bool FileReader::Open(const std::string & filename, unsigned int want)
{
    Close();
 /*   if( filename.find(".gz") == filename.size()-3 ) {
        file_gz = gzopen(filename.c_str(), "rb");
        errorflag = (file_gz == 0)
            || gzseek(file_gz, want, SEEK_SET) != (int)want;
    } else {*/
        file_stdio = fopen(filename.c_str(), "rb");
        errorflag = (file_stdio == 0)
            || std::fseek(file_stdio, want, SEEK_SET) != (int)want;
 //   }
    return !errorflag;
}

// ########################################################################

void FileReader::Close()
{
    if( file_stdio ) {
        std::fclose(file_stdio);
        file_stdio = 0;
    }
/*    if( file_gz ) {
        gzclose(file_gz);
        file_gz = 0;
    }*/
}
