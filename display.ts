

//% color=#000033 
//% icon="\uf021"
//% block="Rotate display"
namespace display {

    export enum Direction {
        //% block="normal"
        Normal = 0,
        //% block="logo to right"
        LogoToRight = 1,
        //% block="upside down"
        UpsideDown = 2,
        //% block="logo to left"
        LogoToLeft = 3,
    }

    //% shim=display::_rotateTo
    function _rotateTo(dir: number) {
        // Per https://github.com/microsoft/pxt-microbit/issues/4292
        0;
    }

    //% blockId="rotateTo" block="rotate display to %direction"
    export function rotateTo(direction: Direction) : void {
        _rotateTo(direction)
    }
}
