#include <Audio.h>
#include <ST7735_t3.h> // Hardware-specific library

#include "teensy_eurorack.h"
#include "teensy_eurorack_audio.h"
#include "ScopeView.h"

ST7735_t3 TFT = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
// GUItool: begin automatically generated code
AudioOutputTDM                  tdm2;           //xy=514,291
AudioInputTDM                  tdm;           //xy=514,291
AudioInputOutputSPI         ad7606_ad5754;         //xy=484,1490
AudioSynthWaveformSine   sine1;          //xy=272,218
AudioSynthWaveformSine   sine2;          //xy=272,218
AudioSynthWaveformSine   sine3;          //xy=272,218
AudioSynthWaveformSine   sine4;          //xy=272,218
AudioSynthWaveformSine   sine5;          //xy=272,218
AudioSynthWaveformSine   sine6;          //xy=272,218
AudioSynthWaveformSine   sine7;          //xy=272,218
AudioSynthWaveformSine   sine8;          //xy=272,218
AudioRecordQueue         audioRecordQueue1; 
AudioRecordQueue         audioRecordQueue2; 
AudioRecordQueue         audioRecordQueue3; 
AudioRecordQueue         audioRecordQueue4; 
AudioRecordQueue         audioRecordQueue5; 
AudioRecordQueue         audioRecordQueue6; 
AudioRecordQueue         audioRecordQueue7; 
AudioRecordQueue         audioRecordQueue8;

AudioRecordQueue         audioRecordQueue9; 
AudioRecordQueue         audioRecordQueue10; 
AudioRecordQueue         audioRecordQueue11; 
AudioRecordQueue         audioRecordQueue12; 
AudioRecordQueue         audioRecordQueue13; 
AudioRecordQueue         audioRecordQueue14;
 
AudioConnection          patchCord1(sine1, 0, ad7606_ad5754, 0);
AudioConnection          patchCord2(sine2, 0, ad7606_ad5754, 1);
AudioConnection          patchCord3(sine3, 0, ad7606_ad5754, 2);
AudioConnection          patchCord4(sine4, 0, ad7606_ad5754, 3);
AudioConnection          patchCord5(sine5, 0, ad7606_ad5754, 4);
AudioConnection          patchCord6(sine6, 0, ad7606_ad5754, 5);
AudioConnection          patchCord7(sine7, 0, ad7606_ad5754, 6);
AudioConnection          patchCord8(sine8, 0, ad7606_ad5754, 7);

AudioConnection          patchCord9(ad7606_ad5754, 0, audioRecordQueue1, 0);
AudioConnection          patchCord10(ad7606_ad5754, 1, audioRecordQueue2, 0);
AudioConnection          patchCord11(ad7606_ad5754, 2, audioRecordQueue3, 0);
AudioConnection          patchCord12(ad7606_ad5754, 3, audioRecordQueue4, 0);
AudioConnection          patchCord13(ad7606_ad5754, 4, audioRecordQueue5, 0);
AudioConnection          patchCord14(ad7606_ad5754, 5, audioRecordQueue6, 0);
AudioConnection          patchCord15(ad7606_ad5754, 6, audioRecordQueue7, 0);
AudioConnection          patchCord16(ad7606_ad5754, 7, audioRecordQueue8, 0);

AudioConnection          patchCord17(tdm, 0, audioRecordQueue9, 0);
AudioConnection          patchCord18(tdm, 2, audioRecordQueue10, 0);
AudioConnection          patchCord19(tdm, 4, audioRecordQueue11, 0);
AudioConnection          patchCord20(tdm, 6, audioRecordQueue12, 0);
AudioConnection          patchCord21(tdm, 8, audioRecordQueue13, 0);
AudioConnection          patchCord22(tdm, 10, audioRecordQueue14, 0);

AudioControlCS42448             cs42448_1;      //xy=614,540
// GUItool: end automatically generated code

uint16_t colors[8] = {ST7735_GREEN,ST7735_RED,ST7735_BLUE,ST7735_CYAN,ST7735_MAGENTA,ST7735_YELLOW,0xFFAA,ST7735_WHITE};

ScopeView scopeViewCV1 = ScopeView(TFT, audioRecordQueue1, colors[0], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewCV2 = ScopeView(TFT, audioRecordQueue2, colors[1], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewCV3 = ScopeView(TFT, audioRecordQueue3, colors[2], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewCV4 = ScopeView(TFT, audioRecordQueue4, colors[3], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewCV5 = ScopeView(TFT, audioRecordQueue5, colors[4], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewCV6 = ScopeView(TFT, audioRecordQueue6, colors[5], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewCV7 = ScopeView(TFT, audioRecordQueue7, colors[6], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewCV8 = ScopeView(TFT, audioRecordQueue8, colors[7], (int16_t)ST7735_BLACK, 64); 

ScopeView scopeViewAudio1 = ScopeView(TFT, audioRecordQueue9, colors[0], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewAudio2 = ScopeView(TFT, audioRecordQueue10, colors[1], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewAudio3 = ScopeView(TFT, audioRecordQueue11, colors[2], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewAudio4 = ScopeView(TFT, audioRecordQueue12, colors[3], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewAudio5 = ScopeView(TFT, audioRecordQueue13, colors[4], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewAudio6 = ScopeView(TFT, audioRecordQueue14, colors[5], (int16_t)ST7735_BLACK, 64); 


unsigned long start_time;
void setup() {
 
  Serial.begin(9600);
  //while(!Serial) {
  //  delay(1);
  //}

  AudioNoInterrupts();  
  AudioMemory(580);
  cs42448_1.enable();
  cs42448_1.volume(1);
  AudioInterrupts();    // enable, both tones will start together
  
  TFT.initR(INITR_144GREENTAB);
  TFT.setRotation(3);
  TFT.fillScreen(ST7735_BLACK);
  noInterrupts();
  sine8.frequency(1000);
  sine8.amplitude(0.8);
  
  sine7.frequency(500);
  sine7.amplitude(0.8);
  
  sine6.frequency(250);
  sine6.amplitude(0.8);
  
  sine5.frequency(100);
  sine5.amplitude(0.8);
  
  sine4.frequency(4);
  sine4.amplitude(0.8);
  
  sine3.frequency(2);
  sine3.amplitude(0.8);
  
  sine2.frequency(1);
  sine2.amplitude(0.8);
  
  sine1.frequency(0.5);
  sine1.amplitude(0.8);
  audioRecordQueue1.begin();
  audioRecordQueue2.begin(); 
  audioRecordQueue3.begin();
  audioRecordQueue4.begin();
  audioRecordQueue5.begin();
  audioRecordQueue6.begin();
  audioRecordQueue7.begin();
  audioRecordQueue8.begin(); 

  audioRecordQueue9.begin();
  audioRecordQueue10.begin();
  audioRecordQueue11.begin();
  audioRecordQueue12.begin();
  audioRecordQueue13.begin();
  audioRecordQueue14.begin(); 
  interrupts();
  start_time = millis();
}

unsigned count = 0, count2 = 0;
void loop() {
  if (count % 150 == 0) {
    scopeViewCV1.checkForUpdateBuffer();
    scopeViewCV2.checkForUpdateBuffer();
    scopeViewCV3.checkForUpdateBuffer();
    scopeViewCV4.checkForUpdateBuffer();
    scopeViewCV5.checkForUpdateBuffer();
    scopeViewCV6.checkForUpdateBuffer();
    scopeViewCV7.checkForUpdateBuffer();
    scopeViewCV8.checkForUpdateBuffer();
    scopeViewAudio1.checkForUpdateBuffer();
    scopeViewAudio2.checkForUpdateBuffer();
    scopeViewAudio3.checkForUpdateBuffer();
    scopeViewAudio4.checkForUpdateBuffer();
    scopeViewAudio5.checkForUpdateBuffer();
    scopeViewAudio6.checkForUpdateBuffer();
    
    scopeViewCV1.undrawScope();
    scopeViewCV2.undrawScope();
    scopeViewCV3.undrawScope();
    scopeViewCV4.undrawScope();
    scopeViewCV5.undrawScope();
    scopeViewCV6.undrawScope();
    scopeViewCV7.undrawScope();
    scopeViewCV8.undrawScope();
    scopeViewAudio1.undrawScope();
    scopeViewAudio2.undrawScope();
    scopeViewAudio3.undrawScope();
    scopeViewAudio4.undrawScope();
    scopeViewAudio5.undrawScope();
    scopeViewAudio6.undrawScope();
    
    scopeViewCV1.drawScope();
    scopeViewCV2.drawScope();
    scopeViewCV3.drawScope();
    scopeViewCV4.drawScope();
    scopeViewCV5.drawScope();
    scopeViewCV6.drawScope();
    scopeViewCV7.drawScope();    
    scopeViewCV8.drawScope();  
    scopeViewAudio1.drawScope();  
    scopeViewAudio2.drawScope();  
    scopeViewAudio3.drawScope();  
    scopeViewAudio4.drawScope();  
    scopeViewAudio5.drawScope();  
    scopeViewAudio6.drawScope();  
  }
    
  while (audioRecordQueue1.available() > 2) {
      audioRecordQueue1.readBuffer();
      audioRecordQueue1.freeBuffer();
  }

    
  while (audioRecordQueue2.available() > 2) {
      audioRecordQueue2.readBuffer();
      audioRecordQueue2.freeBuffer();
  }

      
  while (audioRecordQueue3.available() > 2) {
      audioRecordQueue3.readBuffer();
      audioRecordQueue3.freeBuffer();
  }

      
  while (audioRecordQueue4.available() > 2) {
      audioRecordQueue4.readBuffer();
      audioRecordQueue4.freeBuffer();
  }

      
  while (audioRecordQueue5.available() > 2) {
      audioRecordQueue5.readBuffer();
      audioRecordQueue5.freeBuffer();
  }

      
  while (audioRecordQueue6.available() > 2) {
      audioRecordQueue6.readBuffer();
      audioRecordQueue6.freeBuffer();
  }

      
  while (audioRecordQueue7.available() > 2) {
      audioRecordQueue7.readBuffer();
      audioRecordQueue7.freeBuffer();
  }

  while (audioRecordQueue8.available() > 2) {
      audioRecordQueue8.readBuffer();
      audioRecordQueue8.freeBuffer();
  }
  
  while (audioRecordQueue9.available() > 2) {
      audioRecordQueue9.readBuffer();
      audioRecordQueue9.freeBuffer();
  }

  while (audioRecordQueue10.available() > 2) {
      audioRecordQueue10.readBuffer();
      audioRecordQueue10.freeBuffer();
  }

  while (audioRecordQueue11.available() > 2) {
      audioRecordQueue11.readBuffer();
      audioRecordQueue11.freeBuffer();
  }

  while (audioRecordQueue12.available() > 2) {
      audioRecordQueue12.readBuffer();
      audioRecordQueue12.freeBuffer();
  }

  while (audioRecordQueue13.available() > 2) {
      audioRecordQueue13.readBuffer();
      audioRecordQueue13.freeBuffer();
  }

  while (audioRecordQueue14.available() > 2) {
      audioRecordQueue14.readBuffer();
      audioRecordQueue14.freeBuffer();
  } 
  //delayMicroseconds(100);
  count++;
  if (count % 100000 == 0) {
    unsigned long newmillis = millis() - start_time;   
    count2++;
    Serial.print(newmillis / (1000.0 * 60.0 * 60.0* 24.0));
    Serial.print("d, ");
     
    Serial.print(newmillis / (1000.0 * 60.0 * 60.0));
    Serial.print("h =");
    
    Serial.print(newmillis / (1000.0 * 60.0));
    Serial.print(" min; ");
    Serial.print(count2);
    Serial.print(" all=");
    Serial.print(AudioProcessorUsage());
    Serial.print(",");
    Serial.print(AudioProcessorUsageMax());
    Serial.print("    ");
    Serial.print("Memory: ");
    Serial.print(AudioMemoryUsage());
    Serial.print(",");
    Serial.print(AudioMemoryUsageMax());
    Serial.println();
  }
}
