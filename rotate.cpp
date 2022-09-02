/**
* Bill Siever
* 2022-09-01 Initial Version
*
* Development environment specifics:
* Written in Microsoft PXT
*
* This code is released under the [MIT License](http://opensource.org/licenses/MIT).
* Please review the LICENSE.md file included with this example. If you have any questions 
* or concerns with licensing, please contact techsupport@sparkfun.com.
* Distributed as-is; no warranty is given.
*/

#include "pxt.h"
#include "MicroBitI2C.h"
#include "MicroBit.h"


using namespace pxt;

namespace rotate { 
    
   //%
   void _rotateTo(int direction) {
    if(direction<0 || direction>3) direction = 0;

    /*
     MATRIX_DISPLAY_ROTATION_0,
        MATRIX_DISPLAY_ROTATION_90,
        MATRIX_DISPLAY_ROTATION_180,
        MATRIX_DISPLAY_ROTATION_270
        */
       uBit.display.rotateTo((DisplayRotation)direction);
   }
}