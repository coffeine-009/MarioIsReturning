/* 
 * File:   Brick.h
 * Author: vitaliy
 *
 * Created on March 14, 2014, 4:05 PM
 */

#ifndef BRICK_H
    #define	BRICK_H

#include <GL/gl.h>
#include "Block.h"

namespace Mario
{
    namespace View
    {
        namespace World
        {
            class Brick : public Block
            {
                private:
                public:
                    Brick();
                    Brick( const Brick & Orig );
                    ~Brick();

                    virtual void Render();
            };
        }
    }
}

#endif	/* BRICK_H */

