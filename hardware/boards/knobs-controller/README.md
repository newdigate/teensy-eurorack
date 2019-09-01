# Knobs Controller

An independent rotary encoder and potentiometer breakout board based on Arduino MKR Zero, SAMD21G18A-MU. 
* 4 x 12bit rotary potentiometers
* 3 x RGB Illuminated rotary encoder w/ switch
* Communicates with mainboard via serial.

In this experiment, instead of using 3 pins per rotary encoder/switch and 1 pin per potentiometer, I want to reduce the number of pins used by my main micro-controller down to just a pair of serial rx and tx pins, by introducing an intermediate micro-controller (ARM cortex M0 / SAMD21G) and writing some firmware to relay input and receive commands via serial TX/RX, I can reduce the number of signals down to 4: +5V, GND ,TX,RX;  

I started with the schematic of aduino mkr zero (available from arduino ( [MKRZero-reference.zip](https://content.arduino.cc/assets/MKRZero-reference.zip)) as eagle .sch and .brd) and removed components from the circuit which I don't need. I needed to keep the SWD (Serial wire debug) pins on the micro-controller available, so I can upload a bootloader- as the usb connection won't be available until the bootloader is programmed via the 6-pin SWD header.

## Build details
build details for knob controller can be found here - [BUILD.md](BUILD.md) 

## Bill of materials
BOM can be found here [Bill-of-materials.md](Bill-of-materials.md)

## Images

![top view](images/Knob_controller_top_view.png)

![bottom view](images/Knob_controller_bottom_view.png)
