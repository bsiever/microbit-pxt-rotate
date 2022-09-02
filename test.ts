
input.onButtonPressed(Button.A, function () {
    rotate.rotateTo(rotate.Direction.Normal)
    basic.showIcon(IconNames.Heart)
    basic.showString("Hello World")
})

input.onButtonPressed(Button.B, function () {
    rotate.rotateTo(rotate.Direction.LogoRight)
})

input.onButtonPressed(Button.AB, function () {
    rotate.rotateTo(rotate.Direction.UpsideDown)
    basic.showIcon(IconNames.Heart)
    basic.showString("Hello World")
})

basic.forever(function () {
    basic.showIcon(IconNames.Heart)
    basic.showString("Hello World 2")
})


basic.forever(function () {
    if (input.acceleration(Dimension.X) < -800) {
        rotate.rotateTo(rotate.Direction.LogoLeft)
    } else if (input.acceleration(Dimension.X) > 800) {
        rotate.rotateTo(rotate.Direction.LogoRight)
    } else if (input.acceleration(Dimension.Y) < -800) {
        rotate.rotateTo(rotate.Direction.UpsideDown)
    } else if (input.acceleration(Dimension.Y) > 800) {
        rotate.rotateTo(rotate.Direction.Normal)
    }
    basic.pause(500)
})


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
