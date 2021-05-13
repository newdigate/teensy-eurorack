#include <Audio.h>
#include "teensy_eurorack_audio.h"

// GUItool: begin automatically generated code
AudioOutputTDM           tdm2;           //xy=1037.8889694213867,542.1110763549805
AudioInputOutputSPI           spi;         //xy=253.8888282775879,242.22220611572266
AudioSynthWaveformSineHires   sine1;          //xy=766.9999732971191,97.77776336669922
AudioSynthWaveformSineHires   sine2;          //xy=766.999927520752,133.3333683013916
AudioSynthWaveformSineHires   sine8;          //xy=769.2221870422363,356.66664123535156
AudioSynthWaveformSineHires   sine3;          //xy=770.3332901000977,172.22220039367676
AudioSynthWaveformSineHires   sine5;          //xy=770.3332672119141,248.88892650604248
AudioSynthWaveformSineHires   sine6;          //xy=770.3332710266113,284.4444122314453
AudioSynthWaveformSineHires   sine7;          //xy=770.3332138061523,318.8888273239136
AudioSynthWaveformSineHires   sine4;          //xy=772.5555877685547,210.00000286102295

AudioConnection          patchCord23(sine1, 0, spi, 0);
AudioConnection          patchCord24(sine2, 0, spi, 1);
AudioConnection          patchCord25(sine3, 0, spi, 2);
AudioConnection          patchCord26(sine4, 0, spi, 3);
AudioConnection          patchCord27(sine5, 0, spi, 4);
AudioConnection          patchCord28(sine6, 0, spi, 5);
AudioConnection          patchCord29(sine7, 0, spi, 6);
AudioConnection          patchCord30(sine8, 0, spi, 7);
AudioControlCS42448      cs42448_1;      //xy=553.4443435668945,831.111083984375

// GUItool: end automatically generated code

unsigned long start_time;
void setup() {
 
  Serial.begin(9600);

  AudioNoInterrupts();  
  
  AudioMemory(160);
  cs42448_1.enable()  ;
  cs42448_1.volume(1);
  AudioInterrupts();    // enable, both tones will start together

  sine8.frequency(6000);
  sine8.amplitude(1);
  
  sine7.frequency(4000);
  sine7.amplitude(1);
  
  sine6.frequency(3000);
  sine6.amplitude(1);
  
  sine5.frequency(2000);
  sine5.amplitude(1);
  
  sine4.frequency(1000);
  sine4.amplitude(1);
  
  sine3.frequency(500);
  sine3.amplitude(1);
  
  sine2.frequency(400);
  sine2.amplitude(1);
  
  sine1.frequency(300);
  sine1.amplitude(1);

  start_time = millis();
}

char timestring[] = "                      ";

unsigned count = 0, count2 = 0;
void loop() {
   
  //delayMicroseconds(100);
  count++;
  if (count % 50000 == 0) {   
    unsigned long newmillis = millis() - start_time;


     
    count2++;
    unsigned long days = newmillis / (1000 * 60 * 60 * 24);
    unsigned long remainer = newmillis - (days * 1000 * 60 * 60 * 24);
    unsigned long hours = remainer / (1000 * 60 * 60);
    remainer = remainer - (hours * 1000 * 60 * 60);
    unsigned long minutes = remainer / (1000 * 60);
    remainer = remainer - (minutes * 1000 * 60);
    unsigned long seconds = remainer / 1000;
    remainer = remainer - (seconds * 1000);

    //tft.fillScreen(ST7735_BLACK);


    int n = sprintf(timestring, "%2u:%2u:%2u:%2u.%u", days, hours, minutes, seconds, remainer / 100);
    bool fullUpdate = count2 % 100 == 0;
    if (fullUpdate) {
      Serial.print(timestring);
      Serial.print(" ");
      Serial.print(count2/50);
      Serial.print(" all=");
      Serial.print(AudioProcessorUsage());
      Serial.print(",");
      Serial.print(AudioProcessorUsageMax());
      Serial.print("    ");
      Serial.print("Memory: ");
      Serial.print(AudioMemoryUsage());
      Serial.print(",");
      Serial.print(AudioMemoryUsageMax());
      Serial.print("    ");
      Serial.print("Free Mem: ");
//      Serial.print(memfree());
      Serial.println();
    }
    
  }
}
