/* 
 * File:   Block.cpp
 * Author: vitaliy
 * 
 * Created on February 14, 2014, 11:26 AM
 */

#include "BlockHelper.h"


Mario :: View :: Helper :: BlockHelper :: BlockHelper()
{
    this -> type = BRICK;

    switch( this -> type )
    {
        case BRICK:
        {
            this -> block = new Mario :: View :: World :: Brick();
        }break;
    }
}

Mario :: View :: Helper :: BlockHelper :: BlockHelper( BlockType Type )
{
    this -> type = Type;

    switch( this -> type )
    {
        case BRICK:
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
