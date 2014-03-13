/* 
 * File:   MenuMainItem.h
 * Author: vitaliy
 *
 * Created on February 14, 2014, 10:58 AM
 */

#ifndef MENUMAINITEMHELPER_H
    #define	MENUMAINITEMHELPER_H

#include <GL/gl.h>

namespace Application
{
    namespace View
    {
        namespace Helper
        {
            class MenuMainItemHelper
            {
                public:
                    MenuMainItemHelper();
                    MenuMainItemHelper( const MenuMainItemHelper & Orig );
                    ~MenuMainItemHelper();

                    void Render();
            };
        }
    }
}

#endif	/* MENUMAINITEMHELPER_H */

