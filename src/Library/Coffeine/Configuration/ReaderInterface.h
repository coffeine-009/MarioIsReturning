
/// *** Application *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-11-27 18:11:50 :: ....-..-.. ..:..:..
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Main file for module
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <cstring>
#include <istream>

using namespace std;


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Configuration
{
    class ReaderInterface
    {
        /// *** Properties  *** ///
        protected:
            string fileName;

        /// *** Methods     *** ///
        public:
            ReaderInterface();
            ReaderInterface( string FileName );
            ~ReaderInterface();

            //- SECTION :: MAIN -//
            virtual void Read();

            //- SECTION :: GET -//
    };
}
