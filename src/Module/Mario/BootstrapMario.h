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
#ifndef BOOTSTRAPMARIO_H
    #define BOOTSTRAPMARIO_H


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "Controler/FieldController.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Mario
{
    /** *** *** *** *** *** *** *** *** *** *** *** *** *
     * BootstrapMario
     * ---  --- --- --- --- --- --- --- --- --- --- --- *
     * Bootstrap for module Mario.
     * Initialization game.
    *///*** *** *** *** *** *** *** *** *** *** *** *** *
    class BootstrapMario
    {
        /// *** Properties  *** ///
        private:
            Mario :: Controller :: FieldController * field;
            

        /// *** Methods     *** ///
        public:
            BootstrapMario();
            BootstrapMario( const BootstrapMario & Orig );
            ~BootstrapMario();

            //- SECTION :: MAIN -//
            void Render();
    };
}

#endif	/* BOOTSTRAPMARIO_H */
