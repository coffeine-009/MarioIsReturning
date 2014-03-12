/// *** Configuration :: ReaderInterface    *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-11-27 18:11:50 :: 2014-02-06 17:49:44
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Base class for release pattern Adapter
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directives  *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#ifndef READERINTERFACE_H
    #define READERINTERFACE_H


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <cstring>
#include <istream>

#include "Object.h"

using namespace std;


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Configuration
{
    class ReaderInterface
    {
        /// *** Properties  *** ///
        protected:
            string fileName;    //- Full path to file   -//

            Object result;      //- Object for return   -//

        /// *** Methods     *** ///
        public:
            ReaderInterface();
            ReaderInterface( string FileName );
            ~ReaderInterface();

            //- SECTION :: MAIN -//
            virtual void Read();

            //- SECTION :: GET -//
            virtual Configuration :: Object & GetObject();
    };
}

#endif /* READERINTERFACE_H */
