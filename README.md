# digital eurorack audio-module prototyping dev-kit
[![Join the chat at https://gitter.im/newdigate/teensy-eurorack](https://badges.gitter.im/newdigate/teensy-eurorack.svg)](https://gitter.im/newdigate/teensy-eurorack?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

open source [hardware](hardware) and [software](software) for a [teensy 3.6](https://www.pjrc.com/store/teensy36.html "teensy 3.6 board") eurorack shield 
* interfacing these components
  * **audio:** CS42448 multi-channel audio codec ( 6-in / 8-out sound card)
  * **analog ins/outs:** -10V to 10V 16bit/sample control voltage inputs and outputs
  * **display:** ST7735 128x128 16bit-color tft display
  * **breakouts:** - for uSD card, USB host/device, midi in/out
* 20HP aluminium panel mounted for eurorack case
* program using arduino/teensyduino (plus teensy audio library)

<img src='hardware/images/kryonos%20v11.png' width='800px'/>

## disclaimer
* This is a work in progress -- please be cautious.
* Speak-up - Im an enthusiast and I'd always prefer to know if theres a better way of doing things... 

## support
What you can do if you like to see progress with this project
* star this repository
* subscribe [Nic N on youtube](https://www.youtube.com/channel/UChMicDp8wUXYzBhEN-Wvb5g) & [DIY Audio Electronics Maker](https://www.youtube.com/channel/UChMicDp8wUXYzBhEN-Wvb5g)
* clone this repo, make improvements, commit & send pull-requests

## todo 
- [x] ~~Breakout board for rotary encoders and pots~~
- [ ] Adapt mainboard with fpc connector from new breakout board
- [x] ~~Include schematics and board for uSD adapter~~
- [ ] Isolate analog grounds
- [ ] Vertical alignment of FPC connectors between top breakout and mainboard
- [ ] Testing
  - [x] ~~CS42448 audio codec~~
  - [x] ~~control voltage input~~
  - [x] ~~control voltage output~~
  - [ ] usb host/device
  - [ ] midi in/out
  - [ ] sd card adapter
- [ ] Document 
  - [ ] order & build process
  - [ ] software process
- [ ] Firmware
  - [ ] Sliced audio loops
  - [ ] Midi looping


## Kryonos instrument 
This instrument (hardware docs [here](hardware)) is an attempt to create a generic/universal eurorack module with these components:
 * [teensy 3.6 board](https://www.pjrc.com/store/teensy36.html "teensy 3.6 board")
 * cs42448 audio codec ( [datasheet](https://statics.cirrus.com/pubs/proDatasheet/CS42448_F5.pdf) )
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

## social media
* facebook: 
  * [Moolet](https://www.facebook.com/Moolet-249737938397431/)
* youtube:
  * [Nic N](https://www.youtube.com/channel/UChMicDp8wUXYzBhEN-Wvb5g) 
  * [DIY Audio Electronics Maker](https://www.youtube.com/channel/UChMicDp8wUXYzBhEN-Wvb5g)

## videos 
[![youtube: Eurorack digital audio modules powered by teensy micro-controller](https://img.youtube.com/vi/6zt6OF7UOTc/0.jpg)](https://www.youtube.com/watch?v=6zt6OF7UOTc)

<img src='/hardware/images/kryonos%20v6.png' width='200px'/><img src='/hardware/images/kryonos%20v6-2.png' width='200px'/>
