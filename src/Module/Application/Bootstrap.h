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


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Application
{
    /** *** *** *** *** *** *** *** *** *** *** *** *** *
     * Bootstrap
     * ---  --- --- --- --- --- --- --- --- --- --- --- *
     *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *
    class Bootstrap
    {
        /// *** Properties  *** ///
        private:
            //TODO: Add config
        public:
            static Bootstrap * instance;    //- For Singleton -//

        /// *** Methods     *** ///
        public:
            Bootstrap();
            Bootstrap( const char * ConfigFileName );
            Bootstrap( const Bootstrap & Orig );
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
            static Bootstrap * GetInstance(); //- Implement Singleton -//

            //- SECTION :: SET -//
            static void SetInstance( Bootstrap * Instance );//- Singleton -//
    };
}
