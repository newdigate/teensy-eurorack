# Teensy eurorack experiments

This repository is a work-in-progress evolution of analog/digital audio experiments for teensy 3.6 micro-controllers involving 
* firmware/applications
* circuits
* printed circuit board designs 
* eurorack panel designs

**Strictly speaking, its not eurorack, yet!** Currently this project only uses the euro-rack form factor and power supply connector.

Currently this project does not interface with CV and trigger/gate. And the audio jacks are 1/4" stereo TRS jacks! But hopefully soon I would like to drive these devices with CV voltages and gates logic...

Ideally, I'd like to create a low-cost gereric, programmable do-it-yourself modular audio component. 

## Ubuntu instrument, revision 1.01
This is my first attempt to create a generic microcontroller with an audio card using eurorack form factor. I am using tip-tip audio rails as a chassis and as power source.

### hardware requirements
 * [1 x teensy 3.6 board](https://www.pjrc.com/store/teensy36.html "teensy 3.6 board")
   * ![teensy 3.6 board](https://raw.githubusercontent.com/newdigate/teensy-eurorack/master/hardware/ubuntu/panels/teensy3.6/teensy3.6.svg?sanitize=true "teensy 3.6 board")
 * [1 x blackaddr guitar audio pro shield](http://blackaddr.com/products/)
 * a custom breakout board circuit and pcb [details here](/hardware/ubuntu/eagle/ubuntu "custom breakout board circuit and pcb") 
 * 1 x 1.44" SPI TFT LCD Module Display PCB Adapter ST7735 
   * ![128x128 16bit color oled display](https://raw.githubusercontent.com/newdigate/teensy-eurorack/master/hardware/ubuntu/panels/tft/st7735/1.44-inch/st7735.svg?sanitize=true "128x128 16bit color oled display")
 * 1 x euro-rack compatible front panel [details here](/hardware/ubuntu/panels/Ubuntu "eurorack panels")
 
 ### images
<img src="https://raw.githubusercontent.com/newdigate/teensy-eurorack/master/hardware/ubuntu/images/IMG_0633.png" width="350px"/>

<img src="https://raw.githubusercontent.com/newdigate/teensy-eurorack/master/hardware/ubuntu/eagle/ubuntu/images/Teensy36-ubuntu-breakout.schematic.png" width="350px"/>

<img src="https://raw.githubusercontent.com/newdigate/teensy-eurorack/master/hardware/ubuntu/panels/Ubuntu/20hp-Ubuntu-instruments-number-one.svg?sanitize=true" width="350px"/>
