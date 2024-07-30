# PWM Trainer

This tool is designed to help train beginners to electronics and robotics get comfortable with how Pulse Width Modulation works.

## Concept

A small box with a screen, RGB LED and 3 dials. It can also have a power switch, and mode button.

Power wise, some sort of USB power. It doesn't need to be battery operated.

The main mode:

- Each dial controls the PWM duty cycle for the R, G and B channels of the LEDs
- The screen shows either the ratio percentage, or a square wave for each channel.
- The LED will be showing the appropriate colour.

Alternative mode

- Control one LED colour
- Dial 1 controls the PWM frequency down to 1 Hz
- Dial 2 controls the PWM duty cycle
- Screen displays the values along with a rendering of the square wave

Potentially have test points for 3 PWM signals, and a ground point exposed.

## Plan to make it

Use the microviews in my storage, this might be enough for the display. It might need a larger screen, but start here.
The microview is basically an Arduino plus display.

I have some pleasing potentiometers with a linear dial, which I can use for the 3 controls.
Use an RGB LED that takes 3 power inputs along with resistors, not a smart LED - that way, an oscilloscope probe would show the same waveform.

Design a board (strip board/perf board/protoboard) layout for this - which will also likely mount the potentiometers.
Design a 3D printed case which accounts for the user elements, power/programming cable and test points.

It should probably be prototyped with less fancy potentiometers on a breadboard first, so we can chekc viability of the display on the Microview.

## Software

Design this for reproducibility

- Electronics design should be KiCAD.
- Layout/Case design in FreeCAD
- Code using Arduino IDE/Toolchain

Store STLs, board layout PDF's in this repository, along with code and guides both on building and using this tool.

