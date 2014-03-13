/* 
 * File:   MenuMainItem.cpp
 * Author: vitaliy
 * 
 * Created on February 14, 2014, 10:58 AM
 */

#include "MenuMainItemHelper.h"

Application :: View :: Helper :: MenuMainItemHelper :: MenuMainItemHelper()
{
    
}

Application :: View :: Helper :: MenuMainItemHelper :: MenuMainItemHelper( 
    const MenuMainItemHelper & Orig 
)
{
    
}

Application :: View :: Helper :: MenuMainItemHelper :: ~MenuMainItemHelper()
{
    
}


void Application :: View :: Helper :: MenuMainItemHelper :: Render()
{
    glPushMatrix();

        glEnable( GL_BLEND );
        glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

        glBegin( GL_QUADS );
            glColor4f( 0.0f,0.0f,0.0f, 0.5f );

            glVertex2f( -5.0f, -1.0f );
            glVertex2f( -5.0f, 1.0f );

            glVertex2f( 5.0f, 1.0f );
            glVertex2f( 5.0f, -1.0f );
        glEnd();
    glPopMatrix();
}

