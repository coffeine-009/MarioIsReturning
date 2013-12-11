
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
#include <cstring>
#include <istream>


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Configuration
{
    class ReaderInterface
    {
        /// *** Properties  *** ///
        protected:
            //std :: wstring fileName;

        /// *** Methods     *** ///
        public:
            ReaderInterface();
            ReaderInterface( const char * FileName );
////            Reader(
////                std :: wstring FileName,
////                std :: wstring SectionName,
////                std :: wstring SubSectionName
////            );
//            Reader( const Reader & Orig );
//            virtual ~Reader();

            //- SECTION :: MAIN -//
            virtual bool Read();




    };
}
