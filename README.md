# Rotate Display

```package
pins=github:bsiever/microbit-pxt-rotate
```

This extension allows screen orientation to be changed.  


```sig
display.rotateTo(direction: display.Direction) : void
```

Set the screen orientation.

### ~alert

# Simulated Microbit

Screen changes impact the real micro:bit, but not the simulated micro:bit.

# Example 

The following program will show the behavior of rotating the display on a real micro:bit. Hold the micro:bit with the logo pointed skyward.  It will continually scoll an icon and words across the screen.  It will adjust as you rotate the micro:bit clockwise or counter clockwise (logo to the left, logo to the right, and logo down).

```block
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
```

# Acknowledgements 

Many thanks to Martin Williams for updating CODAL to include `rotateTo()` support (I only did line of code.  Martin did the hard work. See [PR](https://github.com/lancaster-university/codal-microbit-v2/pull/227))!

Icon based on [Font Awesome icon 0xF021](https://www.iconfinder.com/search?q=f021) SVG.

# Misc. 

I develop micro:bit extensions in my spare time to support activities I'm enthusiastic about, like summer camps and science curricula.  You are welcome to become a sponsor of my micro:bit work (one time or recurring payments), which helps offset equipment costs: [here](https://github.com/sponsors/bsiever). Any support at all is greatly appreciated!

## Supported targets

for PXT/microbit

```package
microbit-pxt-rotate=github:bsiever/microbit-pxt-rotate
```

<script src="https://makecode.com/gh-pages-embed.js"></script>
<script>makeCodeRender("{{ site.makecode.home_url }}", "{{ site.github.owner_name }}/{{ site.github.repository_name }}");</script>