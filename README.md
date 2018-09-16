# Teensy eurorack experiments

This is a work-in-progress repository of analog/digital audio experiments for teensy 3.6 micro-controllers, generally mounted on eurorack rails; 

This repo contains 
* source code for firmware/applications
* circuits and printed circuit board designs created using Autodesk Eagle CAD.
* eurorack panel designs created using [FrontPanel designer](http://www.schaeffer-ag.de/en/downloads/front_panel_designer/?no_cache=1 "Front panel designer download")

**Strictly speaking, its not eurorack, yet!** Currently, only using the euro-rack form factor and power supply connector. And the audio jacks are 1/4" stereo TRS jacks! None of these projects currently interface with CV and trigger/gate, although I hope to soon.

Ideally, I'd like to create a low-cost gereric, programmable do-it-yourself modular audio component. 

## Ubuntu instrument 
This is an attempt to create a generic/universal eurorack module with these peripherals
 * Teensy guitar audio pro soundcard by [blackaddr](http://www.blackaddr.com)
   * audio input/thru/output (low impedence input, swichable gain)
   * midi in/out
 * 1.44" 128x128 16bit color display (ST7735 chipset)
 * USB host and USB device 
 * 4 x rotary encoder/switch combos
 * custom break-out pcb

<table> 
  <tr>
    <td>
      <a href="https://github.com/newdigate/teensy-eurorack/tree/master/hardware/ubuntu">
      panel v1
      </a>
    </td>
    
<td>
    <a href="https://github.com/newdigate/teensy-eurorack/tree/master/hardware/ubuntu-v2.0">
      panel v2
  </a>
    </td>   
  </tr>

<tr>
<td>
<img src="https://raw.githubusercontent.com/newdigate/teensy-eurorack/master/hardware/ubuntu/images/20hp-Ubuntu-instruments-number-one.PNG" width="150px"/>
    </td>
    
<td>
<img src="https://raw.githubusercontent.com/newdigate/teensy-eurorack/master/hardware/ubuntu-v2.0/panels/images/20hp-Ubuntu-instruments-number-two-2.png" width="150px"/>
    </td>   
  </tr>
</table>

I am using tip-tip audio rails as a chassis and as power source.

### bill of materials
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
