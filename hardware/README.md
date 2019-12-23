# schematics, printed circuit boards, and panels
* schematic and circuit board files for each board [here](boards)
* panel designs [here](panel)
* schematic [circuit images](#circuits-images)
  * [main-board](#mainboard)
  * [top-breakout board](#top-breakout-board)
  * [knobs-controller board](#knobs-controller-board)

<img src='images/x-front.png' height='150px'/>  <img src='images/x-frontside.png' height='150px'/> <img src='images/x-side.png' height='150px'/> <img src='images/x-backside.png' height='150px'/>  <img src='images/x-back.png' height='150px'/> 

![boards](technical-drawing.svg)

# circuits images
## mainboard
### Teensy micro-controller connections
![teensy circuit](boards/mainboard/images/circuit_sheet_teensy.png)
### cs42448 audio codec
![codec circuit](boards/mainboard/images/circuit_sheet_codec.png)
### power
![power circuit](boards/mainboard/images/circuit_sheet_power.png)
### midi
![midi circuit](boards/mainboard/images/circuit_sheet_midi.png)
### audio in
![audio in circuit](boards/mainboard/images/circuit_sheet_audio_in.png)
### audio out
![audio out circuit](boards/mainboard/images/circuit_sheet_audio_out.png)

## Top-breakout board
### dac
![dac-connectors](boards/topbreakout/images/topbreakout-dac-connectors.png)
### adc
![adc-connectors](boards/topbreakout/images/topbreakout-adc-connectors.png)
### fpc
![fpc-connectors](boards/topbreakout/images/topbreakout-fpc-connectors.png)
### tft
![tft-connector](boards/topbreakout/images/topbreakout-tft-connector.png)
### ad7606
![ad7606](boards/topbreakout/images/topbreakout-ad7606.png)
### ad5754 
![ad5754](boards/topbreakout/images/topbreakout-ad5754.png)
### midi
![midi](boards/topbreakout/images/topbreakout-midi.png)

## Knobs-controller board
### credits
* this board is based on [Arduino MKR Zero](https://store.arduino.cc/arduino-mkr-zero-i2s-bus-sd-for-sound-music-digital-audio-data) design by Arturo Guadalupi (v5.0)
### knobs microcontroller
![knobs main](boards/knobs-controller/images/schematic_kc_main.png)
### power
![knobs power](boards/knobs-controller/images/schematic_kc_power.png)
### encoder
![knobs rgb encoder](boards/knobs-controller/images/schematic_kc_rgb_encoder.png)
