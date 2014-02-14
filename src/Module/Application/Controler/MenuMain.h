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
#ifndef MENUMAIN_H
    #define	MENUMAIN_H


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Application
{
    namespace Controller
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

                //- SECTION :: ACTION -//
                void NewGameAction();
                void QuitAction();
        };
    }
}

#endif	/* MENUMAIN_H */
