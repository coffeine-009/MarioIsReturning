/// *** Configuration :: ReaderInterface    *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-11-27 18:11:50 :: 2014-02-06 17:49:44
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Base class for release pattern Adapter
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "ReaderInterface.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Default
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: ReaderInterface :: ReaderInterface()
{
    this -> fileName = "";
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Custom
 *
 * @param string FileName
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: ReaderInterface :: ReaderInterface( string FileName )
{
    this -> fileName = FileName;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Destructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 *
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: ReaderInterface :: ~ReaderInterface()
{
    //- Free memory -//
    this -> fileName.clear();
}


//- SECTION :: Name -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Read
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Read file and parse him
 *
 * @param void
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Configuration :: ReaderInterface :: Read()
{
    //- Method for overload -//
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetObject
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Convert data to Object
 *
 * @param void
 * @return Object &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object & Configuration :: ReaderInterface :: GetObject()
{
    //- Method for overload -//
    return this -> result;
}
