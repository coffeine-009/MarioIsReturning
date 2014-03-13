/// *** Application :: Controller :: MenuMain   *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2014-02-14 10:26:00 :: 
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Main menu controller
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directives  *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#ifndef MENUMAINCONTROLLER_H
    #define	MENUMAINCONTROLLER_H


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <GL/gl.h>

#include "../View/MenuMainView.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Application
{
    namespace Controller
    {
        class MenuMainController
        {
            /// *** Properties  *** ///
            private:
                Application :: View :: MenuMainView * view;

            /// *** Methods     *** ///
            public:
                MenuMainController();
                MenuMainController( const MenuMainController & Orig );
                ~MenuMainController();

                //- SECTION ::  -//
                void Render();

                //- SECTION :: ACTION -//
                void NewGameAction();
                void QuitAction();
        };
    }
}

#endif	/* MENUMAINCONTROLLER_H */
