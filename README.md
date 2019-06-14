<img src='https://github.com/newdigate/teensy-eurorack/raw/kryonos/hardware/images/kryonos%20v6.png' width='350px'/><img src='https://github.com/newdigate/teensy-eurorack/raw/kryonos/hardware/images/kryonos%20v6-2.png' width='350px'/>

# Teensy eurorack experiments
* Please be cautious - this is a work in progress. Lots of this stuff works. but also im sure theres going to be stuff that doesnt work, or could do with improvement. Please feel free to chirp in - Im an enthusiast and I'd always prefer to know if theres a better way of doing things... 

## Kryonos instrument 
This instrument (hardware docs [here](hardware)) is an attempt to create a generic/universal eurorack module with these components:
 * [teensy 3.6 board](https://www.pjrc.com/store/teensy36.html "teensy 3.6 board")
 * cs42448 audio codec
   * 3 stereo inputs / 4 stereo outputs
   * 24 bits/sample
 * ad7606 adc
   * 8 control voltage inputs
   * configurable voltage range (0 to 5V, 0 to +10V, -10 to +10V)
   * 16 bits/sample
 * ad5754 dac
   * 4 control voltage outputs
   * configurable voltage range (0 to 5V, 0 to +10V, -10 to +10V)
   * 16 bits/sample
 * 1.44" 128x128 16bit color display (ST7735 chipset)
 * USB host and USB device 
 * 2 x rotary encoder/switch combos
 * euro-rack compatible front panel
 * micro-sd breakout
