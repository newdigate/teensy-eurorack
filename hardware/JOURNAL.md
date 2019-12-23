# Journal

## 2 december 2019

mainboard v1.5 and knobs v1.5 pcb arrived from jlcpcb. 

while assembling mainboard v1.5. my heat gun died before i could start baking. 

i’m waiting for a new heat gun to arrive today hopefully. i received a new heat gun replacement yesterday but unfortunately i got the same s/e sensor error. so i ordered a whole new heat gun station. 
i have solder pasted and placed all components on the top side and i’m ready and waiting for my new heat gun station. 

new heat gun station arrived today. i will start backing tomorrow. 

## Tuesday 3 November 2019

assembled my main board today. there are a few solder bridges in the cs42448 chip - needs a little work. 
quite happy with my new hot air gun. although there were initial teething problems. i was switching the solder iron on without realising it was the soldering iron switch not the heat gun switch. 

## Monday 16 November 2019

after assemblying and some refluxing. mainboard sound card audio out was tested successfully.

knobs controller 
* v1.5 assembled
* has issue with uart tx/rx not connected to microcontroller. 
* v1.6 ordered. 

mainboard v1.5 assembled - 
* pull up resistor for adc reset no longer connected to microcontroller. 
* no free pins on teensy, so i introduced i2c gpio breakout ic. freed up 4 pins on the teensy - so i reconnected the ad reset pin. 
* i also introduced a different eurorack power connector 16 pins instead of 10. i have wired the extra pins to the a serial port on the back side of the teensy 4. i have added jumper switches to enable slave and master modes, if you need to crossover tx/rx.  also added a jumper setting for the 5v source to switch between eurorack 5v and 5v via regulator via eurorack 12v. the power regulator makes a very high pitch noise when i connect the input to 12v.

top breakout board

* unfortunate the cv input is not entirely working so far, i seem to just get 0v values. 
* i will test the cv output soon. 
* i am thinking of combining the knobs controller and the top breakout board. 

top breakout test rig. 
i’d like to build a breakout to test top breakout. using the mainboard is very clumsy and i don’t have access to the signals i need to inspect. 

tuesday 17 december 
created test rig for top breakout board and a jig to help solder the pins on the underside of the teensy. ordered from jlcpcb. 

## 22 december 2019
made a few updates to top breakout board. v1.6: rotated display 90 degrees. added test points for various traces. removed connection from dac to miso as it should not be needed and could be causing interference with adc. improved annotation. ordered green board from jlc. 
