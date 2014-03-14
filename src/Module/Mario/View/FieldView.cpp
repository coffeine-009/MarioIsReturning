/* 
 * File:   FieldView.cpp
 * Author: vitaliy
 * 
 * Created on March 13, 2014, 5:50 PM
 */

#include "FieldView.h"


Mario :: View :: FieldView :: FieldView()
{
    this -> countBlocks = 2;
    this -> block = new Mario :: View :: Helper :: BlockHelper[ this -> countBlocks ];
}

Mario :: View :: FieldView :: FieldView( const FieldView & Orig )
{
    
}

Mario :: View :: FieldView :: ~FieldView()
{
    delete [] this -> block;
}

void Mario :: View :: FieldView :: Render()
{
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT/* | GL_DEPTH_BUFFER_BIT*/ );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    glOrtho( -10, 10, -6, 6, -1, 1 );
    
            glPushMatrix();
                glTranslated( -10.0f, -6.0f, 0.0f );
//                glBegin(GL_LINES);
//                    glColor3f(0.0f,0.0f,0.0f);
//
//                    glVertex2f( -10.0f, 0.0f );
//                    glVertex2f( 10.0f, 0.0f );
//
//                    glVertex2f( 0.0f, -10.0f );
//                    glVertex2f( 0.0f, 10.0f );
//                glEnd();

                glPushMatrix();

                    for( unsigned int i = 0; i < this -> countBlocks; i++ )
                    {
                        glTranslatef( (GLfloat)(i), 0.0f, 0.0f);
                        glColor3f(1.0f, (GLfloat)i,0.0f);
                        this -> block[ i ].Render();
                    }

                glPopMatrix();
            glPopMatrix();
}
