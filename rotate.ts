

//% color=#000033 
//% icon="\uf021"
//% block="Display Rotate"
//% group="micro:bit (V2)"
namespace rotate {

    export enum Direction {
        Normal = 0,
        LogoRight = 1,
        UpsideDown = 2,
        LogoLeft = 3, 
    }

    function _rotateTo(dir: int) {
        // Per https://github.com/microsoft/pxt-microbit/issues/4292
        0;
    }

    //% blockId="rotateTo" block="rotate display to %direction"
    //% shim=rotate::rotateTo
    //% group="micro:bit (V2)"
    export function rotateTo(direction: Direction) : void {
        _rotateTo(direction)
    }
}
