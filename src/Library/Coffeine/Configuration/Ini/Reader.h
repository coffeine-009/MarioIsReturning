/// *** Configuration :: Ini :: Reader  *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-11-27 18:11:50 :: 2014-02-05 17:26:07
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

#include "../ReaderInterface.h"
#include "Section.h"


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
                Section * currentSection;


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

                //- SECTION :: GET -//
                virtual Configuration :: Object & GetObject();

                //- SECTION :: MAIN -//
                virtual void Read();

            private:
                void Parse( wstring Line );
                Object ParseObject( wstring Line, wstring Value );
        };
    }
}
