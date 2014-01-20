/// *** Configuration :: Ini :: Object  *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-12-12 10:25:00 :: 2013-12-29 13:11:45
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Object Ini
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <istream>
#include <fstream>
#include <cstring>
#include <wchar.h>
#include <map>
#include <clocale>

using namespace std;


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Configuration
{
    namespace Ini
    {
        class Object
        {
            /// *** Properties  *** ///
            protected:
                wstring name;                   //- Object name             -//
                map < wstring, wstring > data;  //- Properties and values   -//
                map < wstring, Object > subObject;  //- Sub objects         -//


            /// *** Methods     *** ///
            public:
                Object();
                Object( wstring Name );
                Object( const Object & Orig );
                ~Object();


                //- SECTION :: GET -//
                wstring GetName();

                bool            GetBoolean  ( wstring PropertyName );
                double          GetDouble   ( wstring PropertyName );
                float           GetFloat    ( wstring PropertyName );
                int             GetInt      ( wstring PropertyName );
                long            GetLong     ( wstring PropertyName );
                unsigned int    GetUInt     ( wstring PropertyName );
                wstring         GetString   ( wstring PropertyName );


                //- SECTION :: SET -//
                void SetSubObject( map < wstring, Object > SubObject );


                //- SECTION :: MAIN -//
                void AddProperty( wstring Name, wstring Value );
                void AddSubObject( wstring Name, Object SubObject );


                //- Operators -//
                Object & operator = ( const Object & Orig );
                Object & operator = ( Object & Orig );
                
                Object operator [] ( wstring Key );
        };
    }
}
