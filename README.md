<img src='https://github.com/newdigate/teensy-eurorack/raw/master/hardware/images/Ubuntu%20assembly%20v120.3.png' width='250px'/>

# Teensy eurorack experiments
This is a work-in-progress repository of analog/digital audio experiments for teensy 3.6 micro-controllers, generally mounted on eurorack rails; 

This repo contains 
* source code for firmware/applications
* circuits and printed circuit board designs created using Autodesk Eagle CAD.
* eurorack panel designs created using [FrontPanel designer](http://www.schaeffer-ag.de/en/downloads/front_panel_designer/?no_cache=1 "Front panel designer download")

Ideally, I'd like to create a low-cost gereric, programmable do-it-yourself modular audio component. 

## Ubuntu instrument 
This instrument (hardware docs [here](hardware)) is an attempt to create a generic/universal eurorack module with these components:
 * [teensy 3.6 board](https://www.pjrc.com/store/teensy36.html "teensy 3.6 board")
 * Teensy guitar audio pro soundcard by [blackaddr](http://www.blackaddr.com)
   * audio input/thru/output (low impedence input, swichable gain)
   * midi in/out
 * 1.44" 128x128 16bit color display (ST7735 chipset)
 * USB host and USB device 
 * 4 x rotary encoder/switch combos
 * custom break-out pcb [details here](/hardware/ubuntu/eagle/ubuntu "custom breakout board circuit and pcb") 
 * euro-rack compatible front panel [details here](https://github.com/newdigate/teensy-eurorack/tree/master/hardware/panels "eurorack panels")

<table> 
  
<tr>
<td>
  
 ![teensy 3.6 board](https://raw.githubusercontent.com/newdigate/teensy-eurorack/master/hardware/images/teensy3.6.svg?sanitize=true "teensy 3.6 board") 

</td>
<td>
  teensy 3.6
</td>   
</tr> 
  
  
<tr>
<td>
  
![128x128 16bit color oled display](https://raw.githubusercontent.com/newdigate/teensy-eurorack/master/hardware/images/st7735.svg?sanitize=true "128x128 16bit color oled display")

</td>
<td>
  ST7735 display
</td>   
</tr> 

<tr>
    <td>

  <img src="https://raw.githubusercontent.com/newdigate/teensy-eurorack/master/hardware/images/Ubuntu%20assembly%20v120.3.png" width="150px"/>

  </td>
    <td>
    <a href="https://github.com/newdigate/teensy-eurorack/tree/master/hardware">
      panel v2
      </a>
    </td>
    
  </tr>
</table>

I am using tip-tip audio rails as a chassis and as power source.
