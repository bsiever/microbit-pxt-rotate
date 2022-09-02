

//% color=#000033 
//% icon="\uf021"
//% block="Display Rotate"
namespace rotate {

    export enum Direction {
        Normal = 0,
        LogoRight = 1,
        UpsideDown = 2,
        LogoLeft = 3, 
    }

    //% shim=rotate::_rotateTo
    function _rotateTo(dir: number) {
        // Per https://github.com/microsoft/pxt-microbit/issues/4292
        0;
    }

    //% blockId="rotateTo" block="rotate display to %direction"
    export function rotateTo(direction: Direction) : void {
        _rotateTo(direction)
    }
}
