/* 
 * File:   FieldView.h
 * Author: vitaliy
 *
 * Created on March 13, 2014, 5:50 PM
 */

#ifndef FIELDVIEW_H
    #define	FIELDVIEW_H

#include <GL/gl.h>
#include "Helper/BlockHelper.h"

namespace Mario
{
    namespace View
    {
        class FieldView
        {
            private:
                unsigned int countBlocks;

                Mario :: View :: Helper :: BlockHelper * block;

            public:
                FieldView();
                FieldView( const FieldView & Orig );
                ~FieldView();

                void Render();
        };
    }
}

#endif	/* FIELDVIEW_H */

