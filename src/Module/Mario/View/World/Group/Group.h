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
#ifndef GROUP_H
    #define	GROUP_H

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <list>

#include "../Block/Block.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
namespace Mario
{
    namespace View
    {
        namespace World
        {
            /** *** *** *** *** *** *** *** *** *** *** *** *** *
             * Croup
             *  --- --- --- --- --- --- --- --- --- --- --- --- *
             * Group of elements for display. Use for simple 
             * configuration of levels.
            *///*** *** *** *** *** *** *** *** *** *** *** *** *
            class Group
            {
                /// *** Properties  *** ///
                protected:
                    //- Size -//
                    double height;  //- Height of group -//
                    double width;   //- Width of group  -//
                    
                    //- Position -//
                    double bottom;  //- Bottom point of group   -//
                    double left;    //- Left point of group     -//
                    
                    //- Content -//
                    std :: list < Group > group;//- List of subgroups       -//
                    std :: list < Block > block;//- List contained blocks   -//

                /// *** Methods     *** ///
                public:
                    Group();
                    Group( double Height, double Width );
                    Group( 
                        double Bottom, 
                        double Left, 
                        double Height, 
                        double Width 
                    );
                    Group( const Group & Orig );
                    ~Group();

                    //- SECTION :: MAIN -//
                    void AddBlock( Block & InnerBlock );
                    void AddSubGroup( Group & SubGroup );

                    //- SECTION :: GET -//
                    double GetHeight();
                    double GetWidth();

                    double GetBottom();
                    double GetLeft();

                    std :: list < Block > & GetBlocks();
                    std :: list < Group > & GetGroups();

                    //- SECTION :: SET -//
                    void SetHeight( double Height );
                    void SetWidth( double Width );

                    void SetBottom( double Bottom );
                    void SetLeft( double Left );
            };
        }
    }
}

#endif	/* GROUP_H */
