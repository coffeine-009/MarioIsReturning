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

Configuration :: Ini :: Reader :: Reader( std :: wstring FileName )
{
    this -> fileName = FileName;
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
    std :: ifstream file( this -> fileName );

    file.close();
}

