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
#ifndef POINT_H
    #define POINT_H


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <cstring>


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Graphics
{
    namespace Geometry
    {
        /** *** *** *** *** *** *** *** *** *** *** *** *** *
         * Point
         * ---  --- --- --- --- --- --- --- --- --- --- --- *
         * Object for work with point
        *///*** *** *** *** *** *** *** *** *** *** *** *** *
        class Point
        {
            /// *** Properties  *** ///
            protected:
                unsigned int dimension;
                double * coords;


            /// *** Methods     *** ///
            public:
                Point( unsigned int Dimension );
                Point( unsigned int Dimension, double * Coords );
                Point( const Point & orig );
                ~Point();

                //- SECTION :: MAIN -//
                double distance( Point & Point );

                //- SECTION :: OPERATORS -//
                Point & operator = ( Point & Point );
                Point & operator = ( Point Point );

                const Point operator + ( const Point & Point );
                const Point operator - ( const Point & Point );
        };
    }
}

#endif /* POINT_H */
