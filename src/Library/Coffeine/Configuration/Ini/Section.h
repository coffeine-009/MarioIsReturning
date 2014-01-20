/// *** Configuration :: Ini :: Section  *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-12-12 10:03:00 :: 2014-01-20 22:06:05
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Section Ini
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <cstring>

#include "Object.h"

using namespace std;


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Configuration
{
    namespace Ini
    {
        class Section
        {
            /// *** Properties  *** ///
            protected:
                wstring name;                       //- Section name        -//
                map < wstring, Section > subSection;//- Subsections         -//
                map < wstring, Object > objects;    //- Section's objects   -//


            /// *** Methods     *** ///
            public:
                Section();
                Section( wstring Name );
                Section( const Section & Orig );
                ~Section();


                //- SECTION :: GET -//
                wstring GetName();
                Section GetSubSection( wstring SubSection );


                //- SECTION :: SET -//
                void SetName( wstring Name );
                void SetSubSections( map < wstring, Section > SubSections );


                //- SECTION :: MAIN -//
                void AddSubSection( Section SubSection );
                void AddObject( Object Object );


                //- SECTION :: OPERATORS -//
                Section & operator = ( const Section & Orig );
                Section & operator = ( Section & Orig );

                Object operator [] ( wstring ObjectName );
        };
    }
}
