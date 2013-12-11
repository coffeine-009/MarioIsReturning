/*
 * File:   Reader.cpp
 * Author: vitaliy
 *
 * Created on November 27, 2013, 6:11 PM
 */

#include <string.h>

#include "Reader.h"

Configuration :: Ini :: Reader :: Reader()
{

}

Configuration :: Ini :: Reader :: Reader( const char * FileName )
{
    //- Initialization -//
    this -> fileName = std :: string( FileName );
    this -> sectionName = L"";
    this -> subSectionName = L"";
}

Configuration :: Ini :: Reader :: Reader(
    const char * FileName,
    const wchar_t * SectionName
)
{
    //- Initialization -//
    this -> fileName = std :: string( FileName );
    this -> sectionName = std :: wstring( SectionName );
    this -> subSectionName = L"";
}

Configuration :: Ini :: Reader :: Reader(
    const char * FileName, 
    const wchar_t * SectionName, 
    const wchar_t * SubSectionName
)
{
    //- Initialization -//
    this -> fileName = std :: string( FileName );
    this -> sectionName = std :: wstring( SectionName );
    this -> subSectionName = std :: wstring( SubSectionName );
}

Configuration :: Ini :: Reader :: Reader( const Reader& Orig )
{

}

Configuration :: Ini :: Reader :: ~Reader()
{

}

bool Configuration :: Ini :: Reader :: Read()
{
    //- Read data from file -//
    std :: wifstream file( this -> fileName.c_str(), std :: ios :: binary );

    wchar_t line[128];
    file.getline( line, 128 );

    file.close();
}
