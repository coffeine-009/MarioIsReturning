/*
 * File:   Reader.cpp
 * Author: vitaliy
 *
 * Created on November 27, 2013, 6:11 PM
 */

#include <string.h>

#include "ReaderInterface.h"
#include "Object.h"


Configuration :: ReaderInterface :: ReaderInterface()
{

}

Configuration :: ReaderInterface :: ReaderInterface( string FileName )
{
    this -> fileName = FileName;
}

Configuration :: ReaderInterface :: ~ReaderInterface()
{
    this -> fileName.clear();
}

void Configuration :: ReaderInterface :: Read()
{
    
}

//Configuration :: Object Configuration :: ReaderInterface :: GetObject()
//{
//    return Configuration :: Object();
//}
