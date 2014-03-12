/// *** Main file(Point of entry)   *** *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman <vitaliyacm@gmail.com>
     *
     * @date 2013-11-20 14:58:00 :: 2014-02-12 17:49:12
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "src/Library/Coffeine/Configuration/ReaderInterface.h"
#include "src/Library/Coffeine/Configuration/Ini/Reader.h"
#include "src/Module/Application/Bootstrap.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * main
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Entry point
 *
 * @param int argc
 * @param char ** argv
 * @return int
*///*** *** *** *** *** *** *** *** *** *** *** *** *
int main( int argc, char ** argv )
{
    //- Read configuration -//
    Configuration :: ReaderInterface * config = new Configuration :: Ini :: Reader( 
        "src/Module/Application/Configuration/application.ini", 
        L"production", 
        L"development" 
    );
        //- Read configuration from file and parse -//
        config -> Read();

    //- Create new application -//
    Application :: Bootstrap * app = Application :: Bootstrap :: GetInstance( config );
        //- Initialization application -//
        app -> Init( argc, argv );

    //- Free memory for confuguration -//
    delete config;

    //- Run application -//
    app -> Run();

    return 0;
}
