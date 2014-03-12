/// *** Configuration :: Exception :: ParseException    *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman <vitaliyacm@gmail.com>
     *
     * @date 2014-02-11 22:54:00 :: 2014-02-12 22:02:00
     *
     * @address /Ukraine/Ivano-Frankivsk/Chornovola/104
     *
     * @description ParseException
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directives  *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#ifndef PARSEEXCEPTION_H
        #define	PARSEEXCEPTION_H

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <exception>
#include <cstring>


using namespace std;


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Configuration
{
    namespace Exception
    {
        /** *** *** *** *** *** *** *** *** *** *
         * ParseException
         *  --- --- --- --- --- --- --- --- --- *
         * Type of exception - parse
        *///*** *** *** *** *** *** *** *** *** *
        class ParseException : public exception
        {
            /// *** Properties  *** ///
            protected:
                char message[ 128 ];

            /// *** Methods     *** ///
            public:
                ParseException( const char * Message );

                virtual const char * what() const throw();
        };
    }
}

#endif	/* PARSEEXCEPTION_H */
