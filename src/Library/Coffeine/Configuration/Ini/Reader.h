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
     * @description Reader for Ini files. 
     *  Implement Configuration ReaderInterface
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directives  *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#ifndef READER_H
    #define READER_H


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <clocale>
#include <cstring>
#include <fstream>
#include <istream>
#include <map>
#include <vector>
#include <wchar.h>

#include <boost/algorithm/string.hpp>

#include "../ReaderInterface.h"
#include "Section.h"
#include "../Exception/ParseException.h"


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
                wstring sectionName;    //- Section name        -//
                wstring subSectionName; //- Sub section name    -//

                Section data;           //- Read content        -//

            private:
                Section * currentSection;   //- Pointer for parse   -//


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

#endif /* READER_H */
