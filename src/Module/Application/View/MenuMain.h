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
#ifndef MENUMAIN_H
    #define	MENUMAIN_H


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Application
{
    namespace View
    {
        class MenuMain
        {
            /// *** Properties  *** ///
            private:

            /// *** Methods     *** ///
            public:
                MenuMain();
                MenuMain( const MenuMain & Orig );
                ~MenuMain();

                //- SECTION :: VIEW -//
                void NewGameView();
                void QuitView();
        };
    }
}

#endif	/* MENUMAIN_H */
