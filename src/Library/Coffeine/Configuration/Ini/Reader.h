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

#include <boost/algorithm/string.hpp>

#include "../Object.h"
#include "../ReaderInterface.h"
#include "Section.h"
#include "Object.h"


using namespace std;


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Configuration
{
    namespace Ini
    {
        class Reader : public Configuration :: ReaderInterface
        {
            /// *** Properties  *** ///
            protected:
                wstring sectionName;
                wstring subSectionName;

                Section data;

            private:
                Object * currentSection;


            /// *** Methods     *** ///
            public:
                Reader();
                Reader( string FileName );
                Reader(
                    string FileName,
                    wstring SectionName
                );
                Reader(
                    string FileName,
                    wstring SectionName,
                    wstring SubSectionName
                );
                Reader( const Reader & Orig );
                ~Reader();

                //- SECTION :: MAIN -//
                void Read();
                Configuration :: Object GetObject();

            protected:
                void Parse( wstring Line );
        };
    }
}
