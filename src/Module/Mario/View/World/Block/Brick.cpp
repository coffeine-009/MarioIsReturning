/* 
 * File:   Brick.cpp
 * Author: vitaliy
 * 
 * Created on March 14, 2014, 4:05 PM
 */

#include "Brick.h"

Mario :: View :: World :: Brick :: Brick()
{
    
}

Mario :: View :: World :: Brick :: Brick( const Brick & Orig )
{
    
}

Mario :: View :: World :: Brick :: ~Brick()
{
    
}

Mario :: View :: World :: Brick :: Render()
{
    glBegin( GL_QUADS );
        //glColor3f(1.0f,0.0f,0.0f);

        glVertex2f( 0.0f, 0.0f );
        glVertex2f( 1.0f, 0.0f );
        glVertex2f( 1.0f, 1.0f );
        glVertex2f( 0.0f, 1.0f );
    glEnd();
}
