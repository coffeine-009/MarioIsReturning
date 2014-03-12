/// *** Configuration :: Exception :: ParseException    *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman <vitaliyacm@gmail.com>
     *
     * @date 2014-02-11 22:54:00 :: 2014-02-12 21:58:42
     *
     * @address /Ukraine/Ivano-Frankivsk/Chornovola/104
     *
     * @description ParseException
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "ParseException.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Custom
 *
 * @param const char * Message
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Exception :: ParseException :: ParseException( const char * Message )
{
    //- Copy message -//
    strcpy(
        this -> message, 
        Message
    );
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * what
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Return message
 *
 * @return const char *
*///*** *** *** *** *** *** *** *** *** *** *** *** *
const char * Configuration :: Exception :: ParseException :: what() const throw()
{
    return this -> message;
}
