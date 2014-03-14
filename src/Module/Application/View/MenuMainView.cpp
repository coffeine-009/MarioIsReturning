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


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "MenuMainView.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
Application :: View :: MenuMainView :: MenuMainView()
{
    this -> itemHelper = new Application :: View :: Helper :: MenuMainItemHelper();
}

Application :: View :: MenuMainView :: MenuMainView( const MenuMainView & Orig )
{
    
}

Application :: View :: MenuMainView :: ~MenuMainView()
{
    delete this -> itemHelper;
}

void Application :: View :: MenuMainView :: Render()
{
    glClearColor( 0.55f, 0.55f, 1.0f, 1.0 );
    glClear( GL_COLOR_BUFFER_BIT/* | GL_DEPTH_BUFFER_BIT*/ );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -10, 10, -6, 6, -1, 1 );

    glPushMatrix();
    
        glPushMatrix();
            glTranslatef( 0.0f, 4.0f, 0.0f );
            this -> itemHelper -> Render();
        glPopMatrix();

        glPushMatrix();
            glTranslatef( 0.0f, 1.0f, 0.0f );
            this -> itemHelper -> Render();
        glPopMatrix();
    
    glPopMatrix();
}
