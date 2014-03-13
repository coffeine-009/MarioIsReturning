/// *** Application :: View :: MenuMain *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2014-02-14 10:51:00 :: 
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Main menu view
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directives  *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#ifndef MENUMAINVIEW_H
    #define	MENUMAINVIEW_H


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "GL/gl.h"

#include "Helper/MenuMainItemHelper.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Application
{
    namespace View
    {
        class MenuMainView
        {
            /// *** Properties  *** ///
            private:
                Application :: View :: Helper :: MenuMainItemHelper * itemHelper;

            /// *** Methods     *** ///
            public:
                MenuMainView();
                MenuMainView( const MenuMainView & Orig );
                ~MenuMainView();

                void Render();

                //- SECTION :: VIEW -//
//                void NewGameView();
//                void QuitView();
        };
    }
}

#endif	/* MENUMAINVIEW_H */
