/* 
 * File:   FieldView.h
 * Author: vitaliy
 *
 * Created on March 13, 2014, 5:50 PM
 */

#ifndef FIELDVIEW_H
    #define	FIELDVIEW_H

namespace Mario
{
    namespace View
    {
        class FieldView
        {
            private:
                

            public:
                FieldView();
                FieldView( const FieldView & Orig );
                ~FieldView();

                void Render();
        };
    }
}

#endif	/* FIELDVIEW_H */

