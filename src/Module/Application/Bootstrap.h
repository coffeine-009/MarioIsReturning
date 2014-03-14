/// *** Application *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-11-21 13:53:00 :: 
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Main file for module
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directives  *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#ifndef BOOTSTRAP_H
    #define BOOTSTRAP_H


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <GL/gl.h>
#include <GL/freeglut_std.h>

#include "../../Library/Coffeine/Configuration/ReaderInterface.h"
#include "../../Library/Coffeine/Configuration/Object.h"

#include "Controler/MenuMainController.h"
#include "../Mario/BootstrapMario.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Application
{
    /** *** *** *** *** *** *** *** *** *** *** *** *** *
     * Application mode
    *///*** *** *** *** *** *** *** *** *** *** *** *** *
    enum Mode
    {
        MENU, 
        GAME
    };

    /** *** *** *** *** *** *** *** *** *** *** *** *** *
     * Bootstrap
     * ---  --- --- --- --- --- --- --- --- --- --- --- *
     *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *
    class Bootstrap
    {
        /// ***Constants    *** ///
        

        /// *** Properties  *** ///
        private:
            Configuration :: Object config; //- Application configuration   -//

            Mode mode;                      //- Current application mode    -//

            //- Controllers -//
            Application :: Controller :: MenuMainController * menuMain;

            //- Modules -//
            Mario :: BootstrapMario * mario;

            static Bootstrap * instance;    //- For Singleton -//

        /// *** Methods     *** ///
        public:
            Bootstrap();
            Bootstrap( Configuration :: ReaderInterface * Config );
            ~Bootstrap();

            //- SECTION :: MAIN -//
            //-  -//
            bool Init( int Argc, char ** Argv );
            void Run();

            //- Event listeners -//
            void Render();      //- Render all and display -//

            //- Bind with GLUT -//
            static void Display();
            static void Keyboard(
                unsigned char Key,
                GLint MousePositionX,
                GLint MousePositionY
            );

            //- SECTION :: OPERATORS -//
            Bootstrap * operator = ( const Bootstrap & Orig );

            //- SECTION :: GET -//
            static Bootstrap * GetInstance( 
                Configuration :: ReaderInterface * Config 
            ); //- Implement Singleton -//

            //- SECTION :: SET -//
    };
}

#endif /* BOOTSTRAP_H */
