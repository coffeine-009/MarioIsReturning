/// *** Application *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-11-21 13:53:00
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Main file for module
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "Bootstrap.h"

/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
//- Default value for instance -//
Application :: Bootstrap * Application :: Bootstrap :: instance = NULL;

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor default
 * ---  --- --- --- --- --- --- --- --- --- --- --- *
 * @param void
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Application :: Bootstrap :: Bootstrap()
{
    //TODO: add default init
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor configuration
 * ---  --- --- --- --- --- --- --- --- --- --- --- *
 * @param const char * ConfigFileName
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Application :: Bootstrap::Bootstrap( Configuration :: ReaderInterface * Config )
{
    this -> config = Config -> GetObject();
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor copy
 * ---  --- --- --- --- --- --- --- --- --- --- --- *
 * @param const Bootstrap & Orig
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Application :: Bootstrap :: Bootstrap( const Bootstrap& Orig )
{
    //TODO: add copy code
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Destructor
 * ---  --- --- --- --- --- --- --- --- --- --- --- *
 * @param void
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Application :: Bootstrap :: ~Bootstrap()
{
    //- Free memory -//
}

/// *** SECTION :: MAIN *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Init
 * ---  --- --- --- --- --- --- --- --- --- --- --- *
 * @description Initialization
 * @param int Argc
 * @param char ** Argv
 * @return bool
*///*** *** *** *** *** *** *** *** *** *** *** *** *
bool Application :: Bootstrap :: Init( int Argc, char ** Argv )
{
    //- Initialization GLUT -//
    glutInit( &Argc, Argv );

    //- Set display mode -//
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );

    //- Initialization window -//
    glutInitWindowSize( 
        this -> config[ L"view" ][ L"window" ].GetInt( L"width" ), 
        this -> config[ L"view" ][ L"window" ].GetInt( L"height" )
    );
    //- Title of window -//
    wstring window_title = this -> config[ L"view" ][ L"window" ].GetString( L"title" );
    glutCreateWindow( 
        string( 
            window_title.begin(), 
            window_title.end()
        ).c_str()
    );

    //- Bind events and listeners -//
    glutDisplayFunc( Display );
    glutIdleFunc( Display );
    glutKeyboardFunc( Keyboard );

    return true;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Run
 * ---  --- --- --- --- --- --- --- --- --- --- --- *
 * @description Running application
 * @param void
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Application :: Bootstrap :: Run()
{
    //- Run cycle of program -//
    glutMainLoop();
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Render
 * ---  --- --- --- --- --- --- --- --- --- --- --- *
 * @description Rendering all and display
 * @param void
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Application :: Bootstrap :: Render()
{
    //TODO: render childs

    // init
    glMatrixMode(GL_PROJECTION);												// select projection matrix
    glViewport(0, 0, 640, 480);									// set the viewport
    glMatrixMode(GL_PROJECTION);												// set matrix mode
    glLoadIdentity();															// reset projection matrix
    GLfloat aspect = (GLfloat) 640 / 480;
	gluPerspective(45, aspect, 1.0f, 500.0f);		// set up a perspective projection matrix
    glMatrixMode(GL_MODELVIEW);													// specify which matrix is the current matrix
    glShadeModel( GL_SMOOTH );
    glClearDepth( 1.0f );														// specify the clear value for the depth buffer
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );						// specify implementation-specific hints
	glClearColor(0.0, 0.0, 0.0, 1.0);



    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		     // Clear Screen and Depth Buffer
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-3.0f);

	/*
	 * Triangle code starts here
	 * 3 verteces, 3 colors.
	 */
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(-1.0f,-1.0f, 0.0f);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f( 1.0f,-1.0f, 0.0f);
	glEnd();

	glutSwapBuffers();
}

void Application :: Bootstrap :: Display()
{
    instance -> Render();
}

void Application :: Bootstrap :: Keyboard(
    unsigned char Key,
    GLint MousePositionX,
    GLint MousePositionY
)
{
    #define KEY_ESCAPE 27
    //TODO: write
    switch( Key )
    {
        case KEY_ESCAPE:
        {
            exit(0);
        }break;

        default:
        {

        }break;
    }
}

Application :: Bootstrap * Application :: Bootstrap :: operator = ( const Bootstrap & Orig )
{
    *this = Orig;

    return this;
}

/// *** SECTION :: GET  *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetInstance
 * ---  --- --- --- --- --- --- --- --- --- --- --- *
 * @param void
 * @return Application :: Bootstrap * Instance
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Application :: Bootstrap * Application :: Bootstrap :: GetInstance( 
    Configuration :: ReaderInterface * Config 
)
{
    if( instance == NULL )
    {
        instance = new Bootstrap( Config );
    }

    return instance;
}

/// *** SECTION :: SET  *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * SetInstance
 * ---  --- --- --- --- --- --- --- --- --- --- --- *
 * @param Application :: Bootstrap * Instance
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Application :: Bootstrap :: SetInstance( Application :: Bootstrap * Instance )
{
    instance = Instance;
}
