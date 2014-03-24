
#include "Group.h"

Mario :: View :: World :: Group :: Group()
{

}

Mario :: View :: World :: Group :: Group( const Group & Orig )
{

}

Mario :: View :: World :: Group :: ~Group()
{

}

//- SECTION :: MAIN -//
/**
 * 
 * @param SubGroup
 */
void Mario :: View :: World :: Group :: AddSubGroup( Group & SubGroup )
{
    this -> group.push_back( SubGroup );
}

