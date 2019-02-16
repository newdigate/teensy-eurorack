# hardware 
## [circuits](circuits)
### 4 pcb boards
 * adapter board
   * connects between teensy 3.6 board and sound card (Teensy guitar audio pro by blackaddr)
   * converts to a 40 pin flat-flexible-cable (0.5 mm) for connectivity to circuitry pcb
 * circuitry board
   * analog
     * converts adc/dac input/output voltage levels
       * teensy uses 1.2v reference
     * voltage protection on input 
   * digital
     * voltage conversion 
     * voltage protection in digital trigger inputs
 * rotary encoder breakout board
   * 4 x quadrature rotary encoders
 * jack and midi interface breakout (8 thonkk jack connectors and 2 female DIN midi connectors)
   * 2 x cv in
   * 2 x cv out
   * 2 x trigger in
   * 2 x trigger out
   * 1 x midi in
   * 1 x midi /out
 
 ### todo
 * these circuits are not complete... 
   * analog in/out 
      * need to adjust adv and dac voltages
        * [mattb - teensy cv](https://github.com/mattb/teensy-cv)
        * [cutlasses - GlitchDelayV2](https://raw.githubusercontent.com/cutlasses/GlitchDelayV2/master/build/v2/Bottom%20Schematic.png)
      * potentiometer input is noisy, try to add bypass caps
   * there is an air-wire on the adapter pcb which causes an issue for one of the rotaty encoders
   * need to add bypass caps to stabilize noise
   
## bom
 * teensy 3.6 board
 * blackaddr teensy guitaar audio pro shield

![ubuntu2.1](https://github.com/newdigate/teensy-eurorack/raw/master/hardware/images/Ubuntu%20assembly%20v120.3.png)
