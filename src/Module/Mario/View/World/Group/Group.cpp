/// *** Mario ::View :: World :: Group  *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c) 2014, by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman <vitaliyacm@gmail.com>
     *
     * @date 2014-03-23 21:36:00 :: 2014-03-27 21:47:13
     *
     * @address /Ukraine/Ivano-Frankivsk/Chornovola/104
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Directive   *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "Group.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Default constructor.
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Mario :: View :: World :: Group :: Group()
{
    //- Initialization -//
    this -> height = 0.0;
    this -> width = 0.0;

    this -> bottom = 0.0;
    this -> left = 0.0;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Size group
 *
 * @param Height
 * @param width
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Mario :: View :: World :: Group :: Group( double Height, double Width )
{
    //- Initialization -//
    this -> height = Height;
    this -> width = Width;

    this -> bottom = 0.0;
    this -> left = 0.0;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Size and position group
 *
 * @param Bottom
 * @param Left
 * @param Height
 * @param Width
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Mario :: View :: World :: Group :: Group( 
    double Bottom, 
    double Left, 
    double Height, 
    double Width 
)
{
    //- Initialization -//
    this -> height = Height;
    this -> width = Width;

    this -> bottom = Bottom;
    this -> left = Left;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Copy constructor.
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Mario :: View :: World :: Group :: Group( 
    const Mario :: View :: World :: Group & Orig 
)
{
    //- Reinitialization -//
    this -> height = Orig.height;
    this -> width = Orig.width;

    this -> bottom = Orig.bottom;
    this -> left = Orig.left;

    this -> group = Orig.group;
    this -> block = Orig.block;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Destructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * 
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Mario :: View :: World :: Group :: ~Group()
{
    // -Free resources -//
    this -> group.clear();
    this -> block.clear();
}

//- SECTION :: MAIN -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * AddSubGroup
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Add subgroup to current group.
 *
 * @param &SubGroup
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Mario :: View :: World :: Group :: AddSubGroup( 
    Mario :: View :: World :: Group & SubGroup 
)
{
    this -> group.push_back( SubGroup );
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * AddBlock
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Add block to current group.
 *
 * @param &InnerBlock
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Mario :: View :: World :: Group :: AddBlock( 
    Mario :: View :: World :: Block & InnerBlock 
)
{
    this -> block.push_back( InnerBlock );
}


//- SECTION :: GET -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetHeight
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Get height of group
 *
 * @return double Height of group
*///*** *** *** *** *** *** *** *** *** *** *** *** *
double Mario :: View :: World :: Group :: GetHeight()
{
    return this -> height;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetWidth
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Get width of group
 *
 * @return double Width of group
*///*** *** *** *** *** *** *** *** *** *** *** *** *
double Mario :: View :: World :: Group :: GetWidth()
{
    return this -> width;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetBottom
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Get bottom of group
 *
 * @return double Bottom of group
*///*** *** *** *** *** *** *** *** *** *** *** *** *
double Mario :: View :: World :: Group :: GetBottom()
{
    return this -> bottom;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetLeft
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Get left of group
 *
 * @return double Left of group
*///*** *** *** *** *** *** *** *** *** *** *** *** *
double Mario :: View :: World :: Group :: GetLeft()
{
    return this -> left;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetGroups
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Get ref to subgroups by current group
 *
 * @return Group& Ref to subgroups by current group
*///*** *** *** *** *** *** *** *** *** *** *** *** *
std :: list < Mario :: View :: World :: Group > & Mario :: View :: World :: Group :: GetGroups()
{
    return this -> group;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetBlocks
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Get ref to blocks by current group
 *
 * @return Block& Ref to blocks by current group
*///*** *** *** *** *** *** *** *** *** *** *** *** *
std :: list < Mario :: View :: World :: Block > & Mario :: View :: World :: Group :: GetBlocks()
{
    return this -> block;
}


//- SECTION :: SET -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * SetHeight
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Set height of group
 *
 * @param double Height of group
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Mario :: View :: World :: Group :: SetHeight( double Height )
{
    this -> height = Height;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * SetWidth
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Set width of group
 *
 * @param double Width of group
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Mario :: View :: World :: Group :: SetWidth( double Width )
{
    this -> width = Width;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * SetBottom
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Set bottom of group
 *
 * @param double Bottom point of group
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Mario :: View :: World :: Group :: SetBottom( double Bottom )
{
    this -> bottom = Bottom;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * SetLeft
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Set left of group
 *
 * @param double Left point of group
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Mario :: View :: World :: Group :: SetLeft( double Left )
{
    this -> left = Left;
}
