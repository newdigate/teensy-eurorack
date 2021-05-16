#include <Audio.h>
#include <ST7735_t3.h> // Hardware-specific library
#include "teensy_eurorack_audio.h"
#include "teensy_eurorack.h"
#include "AudioLevelView.h"

// GUItool: begin automatically generated code
AudioInputTDM            tdm1;           //xy=401,330
AudioOutputTDM           tdm3;           //xy=962,420
AudioAnalyzeRMS          analyzeRms;
AudioAnalyzePeak         analyzePeak;
AudioConnection          connection3(tdm1, 0, analyzeRms, 0);
AudioConnection          connection4(tdm1, 0, analyzePeak, 0);
AudioControlCS42448      cs42448_1;      //xy=614,540
// GUItool: end automatically generated code

ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

AudioLevelView levelViewCV1 = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 10, 10, 64, 15);
AudioLevelView levelViewCV2 = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 30, 10, 64, 15);

void setup() {

  Serial.begin(9600);
  AudioNoInterrupts();  

  AudioMemory(160);
  cs42448_1.enable();
  cs42448_1.volume(1);
  AudioInterrupts();    // enable, both tones will start together
  delay(100);

  tft.initR(INITR_144GREENTAB);
  tft.setRotation(3);
  tft.fillScreen(ST7735_BLACK);
  tft.useFrameBuffer(true);
  tft.updateScreenAsync(true);
}

void loop() {
    if (analyzeRms.available()){
        levelViewCV1.updateLevel(analyzeRms.read());
    }

    if (analyzePeak.available()){
        levelViewCV2.updateLevel(analyzePeak.read());
    }
}