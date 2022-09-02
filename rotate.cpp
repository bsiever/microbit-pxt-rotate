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
#if MICROBIT_CODAL
static  MatrixPoint normal[5*5] =
{
    {0,0},{0,1},{0,2},{0,3},{0,4},
    {1,0},{1,1},{1,2},{1,3},{1,4},
    {2,0},{2,1},{2,2},{2,3},{2,4},
    {3,0},{3,1},{3,2},{3,3},{3,4},
    {4,0},{4,1},{4,2},{4,3},{4,4}
};

static  MatrixPoint logoright[5*5] =
{
    {4,0},{3,0},{2,0},{1,0},{0,0},
    {4,1},{3,1},{2,1},{1,1},{0,1},
    {4,2},{3,2},{2,2},{1,2},{0,2},
    {4,3},{3,3},{2,3},{1,3},{0,3},
    {4,4},{3,4},{2,4},{1,4},{0,4}
};


static  MatrixPoint logoleft[5*5] =
{
    {0,4},{1,4},{2,4},{3,4},{4,4},
    {0,3},{1,3},{2,3},{3,3},{4,3},
    {0,2},{1,2},{2,2},{3,2},{4,2},
    {0,1},{1,1},{2,1},{3,1},{4,1},
    {0,0},{1,0},{2,0},{3,0},{4,0}
};



static  MatrixPoint upsidedown[5*5] =
{
    {4,4},{4,3},{4,2},{4,1},{4,0},
    {3,4},{3,3},{3,2},{3,1},{3,0},
    {2,4},{2,3},{2,2},{2,1},{2,0},
    {1,4},{1,3},{1,2},{1,1},{1,0},
    {0,4},{0,3},{0,2},{0,1},{0,0}
};



    // Get pins
    static NRF52Pin* ledRowPins[5] = {&uBit.io.row1, &uBit.io.row2, &uBit.io.row3, &uBit.io.row4, &uBit.io.row5};
    static NRF52Pin* ledColPins[5] = {&uBit.io.col1, &uBit.io.col2, &uBit.io.col3, &uBit.io.col4, &uBit.io.col5};
    static MatrixMap ledMatrixMap;
    // Display old instance
    uBit.display.~MicroBitDisplay(); 

    MatrixPoint *grid = normal;
    switch(direction) {
        case 1: // LogoRight
            grid = logoright;
        break;
        case 2: // UpsideDown
            grid = upsidedown;
        break;
        case 3: // LogoLeft
            grid = logoleft;
        break;
        default: 
            //Nothing. normal is default
        break;
    }
    ledMatrixMap = {5, 5, 5, 5, (Pin**)ledRowPins, (Pin**)ledColPins, grid};
    new (&uBit.display) MicroBitDisplay(ledMatrixMap);
#else
       uBit.display.rotateTo((DisplayRotation)direction);
#endif   
    }
}