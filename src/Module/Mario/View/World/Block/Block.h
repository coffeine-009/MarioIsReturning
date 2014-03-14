/* 
 * File:   Block.h
 * Author: vitaliy
 *
 * Created on March 14, 2014, 3:48 PM
 */

#ifndef BLOCK_H
    #define	BLOCK_H

namespace Mario
{
    namespace View
    {
        namespace World
        {
            class Block
            {
                private:
                    
                public:
                    Block();
                    Block( const Block & Orig );
                    ~Block();

                    virtual void Render();
            };
        }
    }
}

#endif	/* BLOCK_H */

