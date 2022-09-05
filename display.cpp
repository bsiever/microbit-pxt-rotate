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
#include "MicroBit.h"


using namespace pxt;

namespace display { 
    
   //%
   void _rotateTo(int direction) {
    static int lastDirection = 0;
    if(direction<0 || direction>3) direction = 0;
    // If not changed, return
    if(lastDirection == direction) {
        return;
    }
    lastDirection = direction;

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
    // Stop animations (to avoid retained objects)
    uBit.display.stopAnimation();
//    uBit.display.printChar(' ',0);
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
    static NRFLowLevelTimer *timerPointer = NULL;

    if(timerPointer)
        delete timerPointer;
    // Get address that will be used for timer object...so we can manually capture the memory and release it 
    // Fix error due to memory leak in https://github.com/lancaster-university/codal-microbit-v2/blob/111e4cf829fdfea25e301375643d1bad71fb7070/source/MicroBitDisplay.cpp#L43%C2%A0
    // NOTE: THIS IS HORRIBLE.  THIS SHOULD NEVER BE DONE. 
    // Allocate and delete an object to see where it will be allocated next.   
    // Store in static variable and delete on next execution (before replacement)
    timerPointer = new NRFLowLevelTimer(NRF_TIMER4, TIMER4_IRQn);
    delete timerPointer;
    new (&uBit.display) MicroBitDisplay(ledMatrixMap);
#else
       uBit.display.rotateTo((DisplayRotation)direction);
#endif   
    }
}