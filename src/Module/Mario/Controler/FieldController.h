/// *** Mario :: Controller :: Field    *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman <vitaliyacm@gmail.com>
     *
     * @date 2014-02-13 12:28:00 :: 
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Controller for field
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directives  *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#ifndef FIELDCONTROLLER_H
    #define	FIELDCONTROLLER_H


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <GL/gl.h>
#include "../View/FieldView.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Mario
{
    namespace Controller
    {
        /** *** *** *** *** *** *** *** *** *** *** *** *** *
         * FieldController
         * ---  --- --- --- --- --- --- --- --- --- --- --- *
         * Control game component - field
        *///*** *** *** *** *** *** *** *** *** *** *** *** *
        class FieldController
        {
            /// *** Properties  *** ///
            Mario :: View :: FieldView * view;

            /// *** Methods     *** ///
            public:
                FieldController();
                FieldController( const FieldController & Orig );
                ~FieldController();

                //- SECTION :: ACTION -//
                void ChangeViewportAction();

                //- SECTION :: MAIN -//
                void Render();
        };
    }
}

#endif	/* FIELDCONTROLLER_H */
