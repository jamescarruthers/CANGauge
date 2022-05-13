# CANGauge
A gauge for Megasquirt.

It uses an OLED display and a Teensy 4.0.

There are a number of types of gauges. Bar and radial gauges, even history line graphs and tables like you might see in TunerStudio when tuning. The size of the gauge is shown in the function name; gaugeBar6432 means that the gauge is 64 by 32 pixels. The first two paramters of the gauge set where to position the gauge on the dash, the next two paramters are the value (see megasquirt.h for values) and the gauge definition. Some gauges have more parameters.

Gauges use definitions to set default values for minimum, maximum and warning values etc. There are a number of these to use with the basic values such as RPM, MAP, coolant etc You can write more of them if you're going to use more niche values. You should change these values to reflect your own engine.

Dashes are where you choose which gauges you want to display. There is a dash called dashCrank() which is shown when the RPM is less than 500. After that you can choose whichever dash you want to display.

There is a function called simulator() that you can use to simulate as if the engine is running. It doesn't output all values but is enough to design dashes and gauges away from the car. See simulator.h for the values it outputs.

TO DO:
Add code for a button, to allow dashes to be cycles through.
