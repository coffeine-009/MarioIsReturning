/// *** Main file(Point of entry)   *** *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-11-20 14:58:00
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "src/Module/Application/Bootstrap.h"

using namespace Application;

/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#define KEY_ESCAPE 27




//
//void initialize ()
//{
//    glMatrixMode(GL_PROJECTION);												// select projection matrix
//    glViewport(0, 0, win.width, win.height);									// set the viewport
//    glMatrixMode(GL_PROJECTION);												// set matrix mode
//    glLoadIdentity();															// reset projection matrix
//    GLfloat aspect = (GLfloat) win.width / win.height;
//	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);		// set up a perspective projection matrix
//    glMatrixMode(GL_MODELVIEW);													// specify which matrix is the current matrix
//    glShadeModel( GL_SMOOTH );
//    glClearDepth( 1.0f );														// specify the clear value for the depth buffer
//    glEnable( GL_DEPTH_TEST );
//    glDepthFunc( GL_LEQUAL );
//    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );						// specify implementation-specific hints
//	glClearColor(0.0, 0.0, 0.0, 1.0);											// specify clear values for the color buffers
//}
//
//
//void keyboard ( unsigned char key, int mousePositionX, int mousePositionY )
//{
//  switch ( key )
//  {
//    case KEY_ESCAPE:
//      exit ( 0 );
//      break;
//
//    default:
//      break;
//  }
//}

int main( int argc, char ** argv )
{
    //- Create new application -//
    Bootstrap * app = new Bootstrap( "configuration.xml" );
        app -> SetInstance( app );
        app -> Init( argc, argv );

    app -> Run();

	return 0;
}
