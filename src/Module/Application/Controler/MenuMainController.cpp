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


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "MenuMainController.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
Application :: Controller :: MenuMainController :: MenuMainController()
{
    this -> view = new Application :: View :: MenuMainView();
}

Application :: Controller :: MenuMainController :: MenuMainController( 
    const MenuMainController & Orig 
)
{
    
}

Application :: Controller :: MenuMainController :: ~MenuMainController()
{
    //delete this -> view;
}

void Application :: Controller :: MenuMainController :: Render()
{
    this -> view -> Render();
}

void Application :: Controller :: MenuMainController :: NewGameAction()
{

}

void Application :: Controller :: MenuMainController :: QuitAction()
{

}

