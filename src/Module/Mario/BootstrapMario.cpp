/// *** Mario   *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2014-02-14 11:25:00 :: 
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Main file for module
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directives  *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <X11/X.h>

#include "BootstrapMario.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Default
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Mario :: BootstrapMario :: BootstrapMario()
{
    this -> field = new Mario :: Controller :: FieldController();
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Copy
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Mario :: BootstrapMario :: BootstrapMario( const BootstrapMario & Orig )
{
    this -> field = new Mario :: Controller :: FieldController();
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Destructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * 
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Mario :: BootstrapMario :: ~BootstrapMario()
{
    delete this -> field;
}

//- SECTION :: MAIN -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Render
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Render module: Mario
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Mario :: BootstrapMario :: Render()
{
    //- Render field -//
    this -> field -> Render();
}
