/* 
 * File:   Block.cpp
 * Author: vitaliy
 * 
 * Created on February 14, 2014, 11:26 AM
 */

#include "BlockHelper.h"


Mario :: View :: Helper :: BlockHelper :: BlockHelper()
{
    this -> type = new BlockType();
}

Mario :: View :: Helper :: BlockHelper :: BlockHelper( BlockType Type )
{
    this -> type = Type;

    switch( this -> type )
    {
        case BlockType :: BRICK:
        {
            this -> block = new Mario :: View :: World :: Brick();
        }break;
    }
}

Mario :: View :: Helper :: BlockHelper :: BlockHelper( const BlockHelper & Orig )
{
    
}

Mario :: View :: Helper :: BlockHelper :: ~BlockHelper()
{
    delete this -> type;
    delete this -> block;
}

//- SECTION :: MAIN -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Render
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Render
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Mario :: View :: Helper :: BlockHelper :: Render()
{
    this -> block -> Render();
}
