/* 
 * File:   Block.h
 * Author: vitaliy
 *
 * Created on February 14, 2014, 11:26 AM
 */

#ifndef BLOCKHELPER_H
    #define	BLOCKHELPER_H

#include <GL/gl.h>

#include "../World/Block/Block.h";
#include "../World/Block/Brick.h";

namespace Mario
{
    namespace View
    {
        namespace Helper
        {
            enum BlockType
            {
                ARMOR, 
                BONUS, 
                BONUS_BRICK, 
                BONUS_UNVISIBLE, 
                BRICK
            };
            
            /**
             * 
             */
            class BlockHelper
            {
                private:
                    BlockType * type;
                    Mario :: View :: World :: Block * block;

                public:
                    BlockHelper();
                    BlockHelper( BlockType Type );
                    BlockHelper( const BlockHelper & Orig );
                    ~BlockHelper();

                    void Render();
            };
        }
    }
}

#endif	/* BLOCKHELPER_H */
