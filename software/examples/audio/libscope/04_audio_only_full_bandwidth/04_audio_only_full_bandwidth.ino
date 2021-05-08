#include <Audio.h>
#include <ST7735_t3.h> // Hardware-specific library
#include "teensy_eurorack.h"
#include "ScopeView.h"

ST7735_t3 TFT = ST7735_t3(TFT_CS, TFT_DC, TFT_RST);

// GUItool: begin automatically generated code
AudioInputTDM            tdm;            //xy=293,565
AudioRecordQueue         audioRecordQueue9; //xy=569,455
AudioRecordQueue         audioRecordQueue10; //xy=571,488
AudioRecordQueue         audioRecordQueue11; //xy=571,521
AudioRecordQueue         audioRecordQueue13; //xy=572,589
AudioRecordQueue         audioRecordQueue14; //xy=572,625
AudioRecordQueue         audioRecordQueue12; //xy=573,555
AudioSynthWaveformSine   sine10;         //xy=805,442
AudioSynthWaveformSine   sine13;         //xy=807,554
AudioSynthWaveformSine   sine15;         //xy=807,634
AudioSynthWaveformSine   sine16;         //xy=807,673
AudioSynthWaveformSine   sine12;         //xy=808,510
AudioSynthWaveformSine   sine9;          //xy=811,404
AudioSynthWaveformSine   sine14;         //xy=811,595
AudioSynthWaveformSine   sine11;         //xy=812,476
AudioOutputTDM           tdm2;           //xy=1120,552
AudioConnection          patchCord1(tdm, 0, audioRecordQueue9, 0);
AudioConnection          patchCord2(tdm, 2, audioRecordQueue10, 0);
AudioConnection          patchCord3(tdm, 4, audioRecordQueue11, 0);
AudioConnection          patchCord4(tdm, 6, audioRecordQueue12, 0);
AudioConnection          patchCord5(tdm, 8, audioRecordQueue13, 0);
AudioConnection          patchCord6(tdm, 10, audioRecordQueue14, 0);
AudioConnection          patchCord7(sine10, 0, tdm2, 2);
AudioConnection          patchCord8(sine13, 0, tdm2, 8);
AudioConnection          patchCord9(sine15, 0, tdm2, 12);
AudioConnection          patchCord10(sine16, 0, tdm2, 14);
AudioConnection          patchCord11(sine12, 0, tdm2, 6);
AudioConnection          patchCord12(sine9, 0, tdm2, 0);
AudioConnection          patchCord13(sine14, 0, tdm2, 10);
AudioConnection          patchCord14(sine11, 0, tdm2, 4);
AudioControlCS42448      cs42448_1;      //xy=634,730
// GUItool: end automatically generated code

uint16_t colors[8] = {ST7735_GREEN,ST7735_RED,ST7735_BLUE,ST7735_CYAN,ST7735_MAGENTA,ST7735_YELLOW,0xFFAA,ST7735_WHITE};

ScopeView scopeViewAudio1 = ScopeView(TFT, audioRecordQueue9, colors[0], (int16_t)ST7735_BLACK, 64);
ScopeView scopeViewAudio2 = ScopeView(TFT, audioRecordQueue10, colors[1], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewAudio3 = ScopeView(TFT, audioRecordQueue11, colors[2], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewAudio4 = ScopeView(TFT, audioRecordQueue12, colors[3], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewAudio5 = ScopeView(TFT, audioRecordQueue13, colors[4], (int16_t)ST7735_BLACK, 64); 
ScopeView scopeViewAudio6 = ScopeView(TFT, audioRecordQueue14, colors[5], (int16_t)ST7735_BLACK, 64);


const int num_sine_generators = 8;
AudioSynthWaveformSine* sine_generators[num_sine_generators] = {
        &sine9, &sine10, &sine11, &sine12, &sine13, &sine14, &sine15, &sine16 };

const int num_scopes = 6;
ScopeView* scopeViews[num_scopes] = {
        &scopeViewAudio1, &scopeViewAudio2, &scopeViewAudio3, &scopeViewAudio4, &scopeViewAudio5, &scopeViewAudio6};

AudioRecordQueue* recordQueues[num_scopes] = {
        &audioRecordQueue9,  &audioRecordQueue10,
        &audioRecordQueue11, &audioRecordQueue12,
        &audioRecordQueue13, &audioRecordQueue14 };


unsigned long start_time;
void setup() {
 
  Serial.begin(9600);
  //while(!Serial) {
  //  delay(1);
  //}

  AudioNoInterrupts();  
  
  AudioMemory(100);
  cs42448_1.enable();
  cs42448_1.volume(1);
  AudioInterrupts();    // enable, both tones will start together
  
  TFT.initR(INITR_144GREENTAB);
  TFT.setRotation(3);
  TFT.fillScreen(ST7735_BLACK);
  TFT.useFrameBuffer(true);
  TFT.updateScreenAsync(true);
  //noInterrupts();

    for (int i=0; i<num_sine_generators; i++) {
        sine_generators[i]->frequency(100.0);
        sine_generators[i]->amplitude(0.5);
    }

    for (int i=0; i<num_scopes; i++) {
        recordQueues[i]->begin();
    }
  //interrupts();
  start_time = millis();
}

char timestring[] = "                      ";

void updateTFTTime(char *oldString, char *newString, bool rerender) {
  int c=0;
  if (!rerender) {
    int len1 = strlen(oldString);
    int len2 = strlen(newString);
    while(oldString[c] == newString[c] && c < len1 && c < len2 ){
      c++;      
    }
  }
  TFT.setCursor(c * 6,0);
  TFT.setTextColor(ST7735_BLACK);
  TFT.print( (char * ) (oldString + c)); 
  
  TFT.setCursor(c * 6,0);
  TFT.setTextColor(ST7735_WHITE);
  TFT.print( (char * ) (newString + c));    
}

unsigned count = 0, count2 = 0;
void loop() {
  if (count % 20 == 0) {
      for (int i=0; i<num_scopes; i++){
          scopeViews[i]->checkForUpdateBuffer();
      }

      for (int i=0; i<num_scopes; i++){
          scopeViews[i]->undrawScope();
      }

      for (int i=0; i<num_scopes; i++){
          scopeViews[i]->drawScope();
      }
    
      //TFT.updateScreen();
  }


    for (int i=0; i<num_scopes; i++) {
        if (recordQueues[i]->available() > 2) {
            recordQueues[i]->end();
            while (recordQueues[i]->available() > 2) {
                recordQueues[i]->readBuffer();
                recordQueues[i]->freeBuffer();
            }
            recordQueues[i]->begin();
        }
    }


    //delayMicroseconds(100);
  count++;
  if (count % 10000 == 0) {   
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


    char newtimestring[] = "                      ";
    int n = sprintf(newtimestring, "%2u:%2u:%2u:%2u.%u", days, hours, minutes, seconds, remainer / 100);
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
      Serial.print(memfree());
      Serial.println();
    }
    updateTFTTime(timestring, newtimestring, fullUpdate);
    memcpy(timestring, newtimestring, strlen(newtimestring) );
    
  }
}
