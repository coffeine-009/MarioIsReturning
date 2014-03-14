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


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "FieldController.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///

Mario :: Controller :: FieldController :: FieldController()
{
    this -> view = new Mario :: View :: FieldView();
}

Mario :: Controller :: FieldController :: FieldController( const FieldController & Orig )
{
    
}

Mario :: Controller :: FieldController :: ~FieldController()
{
    delete this -> view;
}

void Mario :: Controller :: FieldController :: Render()
{
    this -> view -> Render();
}
