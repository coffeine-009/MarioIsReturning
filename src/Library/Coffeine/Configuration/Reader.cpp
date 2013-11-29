/*
 * File:   Reader.cpp
 * Author: vitaliy
 *
 * Created on November 27, 2013, 6:11 PM
 */

#include <string.h>

#include "Reader.h"

Configuration :: Reader::Reader()
{

}

Configuration :: Reader :: Reader( std :: wstring FileName )
{
    this -> fileName = FileName;
}

Configuration :: Reader::Reader( const Reader& Orig )
{

}

Configuration :: Reader::~Reader()
{

}

bool Configuration :: Reader :: Read()
{

}

