
/// *** Application *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-11-27 18:11:50
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Main file for module
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <istream>
#include <fstream>
#include <cstring>
#include <wchar.h>
#include <map>
#include <clocale>

#include "../ReaderInterface.h"

/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Configuration
{
    namespace Ini
    {
        class Reader : public Configuration :: ReaderInterface
        {
            /// *** Properties  *** ///
            protected:
                std :: string fileName;
                std :: wstring sectionName;
                std :: wstring subSectionName;

                //std :: map < std :: wstring > data;

            /// *** Methods     *** ///
            public:
                Reader();
                Reader( const char * FileName );
                Reader(
                    const char * FileName,
                    const wchar_t * SectionName
                );
                Reader(
                    const char * FileName,
                    const wchar_t * SectionName,
                    const wchar_t * SubSectionName
                );
                Reader( const Reader & Orig );
                virtual ~Reader();

                //- SECTION :: MAIN -//
                bool Read();


        };
    }
}
