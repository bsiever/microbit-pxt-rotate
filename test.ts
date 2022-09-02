basic.forever(function () {
    basic.showIcon(IconNames.Heart)
    basic.showString("Hello World!")
})

basic.forever(function () {
    if (input.acceleration(Dimension.X) < -800) {
        display.rotateTo(display.Direction.LogoToLeft)
    } else if (input.acceleration(Dimension.X) > 800) {
        display.rotateTo(display.Direction.LogoToRight)
    } else if (input.acceleration(Dimension.Y) < -800) {
        display.rotateTo(display.Direction.UpsideDown)
    } else if (input.acceleration(Dimension.Y) > 800) {
        display.rotateTo(display.Direction.Normal)
    }
    basic.pause(500)
})





// input.onButtonPressed(Button.A, function () {
//     display.rotateTo(display.Direction.Normal)
//     basic.showIcon(IconNames.Heart)
//     basic.showString("Hello World")
// })

// input.onButtonPressed(Button.B, function () {
//     display.rotateTo(display.Direction.LogoRight)
// })

// input.onButtonPressed(Button.AB, function () {
//     display.rotateTo(display.Direction.UpsideDown)
//     basic.showIcon(IconNames.Heart)
//     basic.showString("Hello World")
// })



// basic.forever(function () {
//     basic.showIcon(IconNames.Heart)
//     basic.showString("Hello World")
//     if (input.acceleration(Dimension.X) < -800) {
//         rotate.rotateTo(rotate.Direction.LogoLeft)
//     } else if (input.acceleration(Dimension.X) > 800) {
//         rotate.rotateTo(rotate.Direction.LogoRight)
//     } else if (input.acceleration(Dimension.Y) < -800) {
//         rotate.rotateTo(rotate.Direction.UpsideDown)
//     } else if (input.acceleration(Dimension.Y) > 800) {
//         rotate.rotateTo(rotate.Direction.Normal)
//     }
// })
