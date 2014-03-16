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

void Mario :: View :: World :: Brick :: Render()
{
    //- Background -//
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    glBegin( GL_QUADS );
        glColor3f( 0.8f, 0.1f, 0.3f );

        glVertex2f( 0.0f, 0.0f );
        glVertex2f( 1.0f, 0.0f );
        glVertex2f( 1.0f, 1.0f );
        glVertex2f( 0.0f, 1.0f );
    glEnd();

    //- Frame -//
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glBegin( GL_QUADS );
        glColor3f( 1.0f, 1.0f, 1.0f );

        glVertex2f( 0.0f, 0.0f );
        glVertex2f( 1.0f, 0.0f );
        glVertex2f( 1.0f, 1.0f );
        glVertex2f( 0.0f, 1.0f );
    glEnd();

    //- Vizerunok -//
    glLineWidth( 3.0f );
    glColor3f( 1.0f, 1.0f, 1.0f );
    glBegin( GL_LINES );
        glVertex2f( 0.65f, 0.65f );
        glVertex2f( 1.0f, 0.65f );

        glVertex2f( 0.65f, 0.35f );
        glVertex2f( 0.65f, 1.0f );

        glVertex2f( 0.58f, 0.35f );
        glVertex2f( 0.65f, 0.35f );

        glVertex2f( 0.58f, 0.2f );
        glVertex2f( 0.58f, 0.35f );

        glVertex2f( 0.5f, 0.2f );
        glVertex2f( 0.58f, 0.2f );

        glVertex2f( 0.5f, 0.0f );
        glVertex2f( 0.5f, 0.2f );

        
        glVertex2f( 0.25f, 0.2f );
        glVertex2f( 0.5f, 0.2f );

        glVertex2f( 0.25f, 0.2f );
        glVertex2f( 0.25f, 0.3f );
        
        glVertex2f( 0.15f, 0.3f );
        glVertex2f( 0.25f, 0.3f );

        glVertex2f( 0.15f, 0.3f );
        glVertex2f( 0.15f, 0.4f );
        
        glVertex2f( 0.0f, 0.4f );
        glVertex2f( 0.15f, 0.4f );
    glEnd();
}
