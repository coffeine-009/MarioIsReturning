/// *** Graphics :: Geometry :: Point *** *** *** *** *** *** *** *** ///

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
     * @description Point
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directives  *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///


/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "Point.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Create empty point
 *
 * @param unsigned int Dimension
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Graphics :: Geometry :: Point :: Point( unsigned int Dimension )
{
    this -> coords = new double[ this -> dimension = Dimension ];
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Create point
 *
 * @param unsigned int Dimension
 * @param double * Coords
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Graphics :: Geometry :: Point :: Point( 
    unsigned int Dimension, 
    double * Coords
)
{
    //- Create memory for coords -//
    this -> coords = new double[ this -> dimension = Dimension ];

    //- Copy coords -//
    memcpy(
        this -> coords, 
        Coords, 
        this -> dimension * sizeof( double )
    );
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Copy constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Redefine point from exist
 *
 * @param const Point & Orig
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Graphics :: Geometry :: Point :: Point( const Point & Orig )
{
    if( this -> dimension > 0 )
    {
        //- Delete current point's coords -//
        //delete [] this -> coords;
    }

    //- Create memory for new point's coords -//
    this -> coords = new double[ this -> dimension = Orig.dimension ];

    //- Copy new coords -//
    memcpy( 
        this -> coords, 
        Orig.coords, 
        this -> dimension * sizeof( double ) 
    );
}

Graphics :: Geometry :: Point :: ~Point()
{
    delete [] this -> coords;
}


//- SECTION :: OPERATORS -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator +
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Add to current point other
 *
 * @param Graphics :: Geometry :: Point & Point
 * @return Graphics :: Geometry :: Point &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
const Graphics :: Geometry :: Point Graphics :: Geometry :: Point :: operator + (
    const Graphics :: Geometry :: Point & Point
)
{
    Graphics :: Geometry :: Point result( *this );

    //- Check dimension -//
    if( result.dimension != Point.dimension )
    {
        //- Fail, dimension not equals -//
        //throw PointDimensionException();
    }

    //- Add coords -//
    for( unsigned int i = 0; i < result.dimension; i++ )
    {
        result.coords[ i ] += Point.coords[ i ];
    }

    return result;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator -
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Sum from curent point other
 *
 * @param Graphics :: Geometry :: Point & Point
 * @return Graphics :: Geometry :: Point &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
const Graphics :: Geometry :: Point Graphics :: Geometry :: Point :: operator - (
    const Graphics :: Geometry :: Point & Point
)
{
    Graphics :: Geometry :: Point result( *this );

    //- Check dimension -//
    if( result.dimension != Point.dimension )
    {
        //- Fail, dimension not equals -//
        //throw PointDimensionException();
    }

    //- Sub coords -//
    for( unsigned int i = 0; i < this -> dimension; i++ )
    {
        result.coords[ i ] -= Point.coords[ i ];
    }

    return result;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator =
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Sum from curent point other
 *
 * @param Graphics :: Geometry :: Point & Point
 * @return Graphics :: Geometry :: Point &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Graphics :: Geometry :: Point & Graphics :: Geometry :: Point :: operator = (
    Graphics :: Geometry :: Point & Orig
)
{
    //- Delete current point's coords -//
    delete [] this -> coords;

    //- Create memory for new point's coords -//
    this -> coords = new double[ this -> dimension = Orig.dimension ];

    //- Copy new coords -//
    memcpy( 
        this -> coords, 
        Orig.coords, 
        this -> dimension * sizeof( double ) 
    );

    return * this;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator =
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Sum from curent point other
 *
 * @param Graphics :: Geometry :: Point & Point
 * @return Graphics :: Geometry :: Point &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Graphics :: Geometry :: Point & Graphics :: Geometry :: Point :: operator = (
    Graphics :: Geometry :: Point Orig
)
{
    //- Delete current point's coords -//
    delete [] this -> coords;

    //- Create memory for new point's coords -//
    this -> coords = new double[ this -> dimension = Orig.dimension ];

    //- Copy new coords -//
    memcpy( 
        this -> coords, 
        Orig.coords, 
        this -> dimension * sizeof( double ) 
    );

    return * this;
}
