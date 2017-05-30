# matrix-cascade
A customizable cascade animation of katakana characters, just like in the Matrix movies.

## command-line argument explanation
+ arg 1: The width (in regular characters) of the animation
+ arg 2: The height (in regular characters) of the animation
+ arg 3: The color to display the animation. Legend below:
    1 = red
    2 = green
    3 = yellow
    4 = blue
    5 = magenta
    6 = cyan
    7 = light grey (often the same as default)
    9 = default (usually light grey/white)

+ arg 4: The frequency of new "lines" cascading.
    + More specifically, this is the probability, as a percentage, for each column, that a new line will start at the top of the screen
    + 10 is a good choice for this value

+ arg 5: The wait time, in milliseconds, between printing each frame of the
animation. 
    + Note that if you go fullscreen, the time it takes to print each
frame can bottleneck the timing of the animation, so there *can* be an 
effective limit on how fast the animation can proceed.

## Useful note
This thing *will* run forever, so hit CTRL+C to stop it in the terminal.

