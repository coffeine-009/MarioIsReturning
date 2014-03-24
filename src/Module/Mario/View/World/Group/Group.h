/// *** Mario ::View :: World :: Group  *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c) 2014, by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman <vitaliyacm@gmail.com>
     *
     * @date 2014-03-23 21:36:00 - 
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

#ifndef GROUP_H
    #define	GROUP_H

#include <list>

#include "../Block/Block.h"

namespace Mario
{
    namespace View
    {
        namespace World
        {
            /** *** *** *** *** *** *** *** *** *** *** *** *** *
             * Croup
             *  --- --- --- --- --- --- --- --- --- --- --- --- *
             * Group of elements for display
            *///*** *** *** *** *** *** *** *** *** *** *** *** *
            class Group
            {
                /// *** Properties  *** ///
                protected:
                    //- Size -//
                    double height;
                    double width;
                    
                    //- Position -//
                    double bottom;
                    double left;
                    
                    //- Content -//
                    std :: list < Group > group;
                    std :: list < Block > block;

                /// *** Methods     *** ///
                public:
                    Group();
                    Group( const Group & Orig );
                    ~Group();

                    //- SECTION :: MAIN -//
                    void AddSubGroup( Group & SubGroup );
                    void AddBlock( Block & InnerBlock );

                    //- SECTION :: GET -//
                    double GetHeight();
                    double GetWidth();

                    double GetBottom();
                    double GetLeft();

                    std :: list < Group > & GetGroups();
                    std :: list < Block > & GetBlocks();

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
