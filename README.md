# digital eurorack audio-module prototyping dev-kit [![Join the chat at https://gitter.im/newdigate/teensy-eurorack](https://badges.gitter.im/newdigate/teensy-eurorack.svg)](https://gitter.im/newdigate/teensy-eurorack?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

*(work in progress)* open source **[hardware](hardware) and [software](software) for a ~~[teensy 3.6](https://www.pjrc.com/store/teensy36.html "teensy 3.6 board")~~ eurorack shield** (working on updating to [teensy 4](https://www.pjrc.com/teensy-4-0/) )


* [what is it](#what-is-it)
* [software](#software)
* [support](#support)
* [todo](#todo)
* [social media](#social-media)
* [videos](#videos)

## what is it 
A set of circuits and pc-board designs integrating all the components you need for prototyping a digital audio module for eurorack

*audio codec circuit originally started as a discussion on quad audio channel outputs and a pcb design integrating teensy and cs42448 from Paul Stoffregen on [pjrc forum](https://forum.pjrc.com/threads/41371-Quad-channel-output-on-Teensy-3-6?p=138828&viewfull=1#post138828)*
* cortex m7 microcontroller (teensy 4.0) interfacing the follow components
  * **audio:** multi-channel audio codec ( 6-in / 8-out 24-bit sound card - [CS42448](https://statics.cirrus.com/pubs/proDatasheet/CS42448_F5.pdf) )
  * **analog ins/outs:** -10V to 10V 16bit/sample control voltage 4 x inputs and 4 x outputs ( [ad7606](https://www.analog.com/media/en/technical-documentation/data-sheets/ad7606_7606-6_7606-4.pdf), [ad5754](https://www.analog.com/media/en/technical-documentation/data-sheets/AD5724_5734_5754.pdf) )
  * **display:** ST7735 128x128 16bit-color tft display
  * **breakouts:** - for uSD card, USB host/device, midi in/out, 2 x teensy analog in/out (0 to 3v3 w/protection)
* 20HP aluminium panel mounted for eurorack case
* write arduino compatible c/c++ firmware & program using arduino/teensyduino ([plus teensy audio library](https://www.pjrc.com/teensy/gui/))

<img src='hardware/images/kryonos%20v11.png' width='800px'/>

## software 
* All schematics and circuit boards designed using Autodesk Eagle cad
* Autodesk Fusion 360 used for mechanical layout
* My free license to autodesk fusion 360 has expired
* I am planning to migrate away from proprietry software and subscription licenses
  * circuits and pc-boards to [Kicad](http://kicad-pcb.org/) 
  * physical design to [FreeCAD](https://github.com/FreeCAD/FreeCAD)
  * CAM using [opencamlib](https://github.com/aewallin/opencamlib)
 
## support
This project is a work-in-progress! 

What you can do if you like to see progress with this project?
* star this repository
* subscribe [Nic N on youtube](https://www.youtube.com/channel/UChMicDp8wUXYzBhEN-Wvb5g) & [DIY Audio Electronics Maker](https://www.youtube.com/channel/UChMicDp8wUXYzBhEN-Wvb5g)
* clone this repo, make improvements, commit & send pull-requests

## todo 
- [ ] Migrate circuits and pcbs to kicad
- [ ] Teensy 4.0 changes
  - [ ] move control-voltage adc and dacs off main-board and on to top-breakout board
  - [ ] reduce main board to double layer board, instead of 4-layer board
  - [ ] increase horizontal size from 20HP to 24HP  
- [ ] Breakout board for rotary encoders and pots
  - [x] ~~Order~~
  - [ ] Assemble
  - [ ] Certify
- [ ] ~~change all 0603 resistors and caps with 0805~~
- [ ] Adapt mainboard with fpc connector from new breakout board
- [x] ~~Include schematics and board for uSD adapter~~
- [x] ~~Isolate analog grounds~~
- [ ] Vertical alignment of FPC connectors between top breakout and mainboard
- [ ] Finalize circuits / boards
- [ ] Testing
  - [x] ~~CS42448 audio codec~~
  - [x] ~~control voltage input~~
  - [x] ~~control voltage output~~
  - [ ] usb host/device
  - [ ] midi in/out
  - [ ] sd card extension & adapter
- [ ] Document 
  - [ ] order & build process
  - [ ] software process
- [ ] Firmware
  - [ ] Sliced audio loops
  - [ ] Midi looping

## social media
* facebook: 
  * [Moolet](https://www.facebook.com/Moolet-249737938397431/)
* youtube:
  * [Nic N](https://www.youtube.com/channel/UChMicDp8wUXYzBhEN-Wvb5g) 
  * [DIY Audio Electronics Maker](https://www.youtube.com/channel/UChMicDp8wUXYzBhEN-Wvb5g)

## videos 
[![youtube: Eurorack digital audio modules powered by teensy micro-controller](https://img.youtube.com/vi/6zt6OF7UOTc/0.jpg)](https://www.youtube.com/watch?v=6zt6OF7UOTc)

<img src='/hardware/images/kryonos%20v6.png' width='200px'/><img src='/hardware/images/kryonos%20v6-2.png' width='200px'/>
