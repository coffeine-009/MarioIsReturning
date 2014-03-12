/// *** Graphics :: Geometry :: 2D :: Point *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2014 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman <vitaliyacm@gmail.com>
     *
     * @date 2014-03-07 16:01:00 ::
     *
     * @address /Ukraine/Ivano-Frankivsk/Petranka
     *
     * @description 2D Point
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directives  *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "../Point.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Graphics
{
    namespace Geometry
    {
        namespace _2D
        {
            /**
             * Point
             */
            class Point : public Graphics :: Geometry :: Point
            {
                /// *** Properties  *** ///
                protected:
                    double x;
                    double y;

                /// *** Methods     *** ///
                public:
                    Point();
                    Point( const Point & orig );
                    ~Point();

                    //- SECTION :: MAIN -//
                    double distance( Point & Point );

                    //- SECTION :: OPERATORS -//
                    Point & operator + ( Point & Point );
                    Point & operator - ( Point & Point );
            };
        }
    }
}

/// *** Implements  *** ///
Graphics :: Geometry :: _2D :: Point :: Point()
{

}

Graphics :: Geometry :: _2D :: Point :: Point( const Point & orig )
{

}

Graphics :: Geometry :: _2D :: Point :: ~Point()
{

}
