#include <Audio.h>
#include <ST7735_t3.h> // Hardware-specific library
#include "teensy_eurorack_audio.h"
#include "teensy_eurorack.h"
#include "AudioLevelView.h"

// GUItool: begin automatically generated code
AudioInputTDM            tdm1;           //xy=401,330
AudioOutputTDM           tdm3;           //xy=962,420

AudioAnalyzeRMS          analyze1l_rms;
AudioAnalyzePeak         analyze1l_p2p;
AudioAnalyzeRMS          analyze1r_rms;
AudioAnalyzePeak         analyze1r_p2p;

AudioAnalyzeRMS          analyze2l_rms;
AudioAnalyzePeak         analyze2l_p2p;
AudioAnalyzeRMS          analyze2r_rms;
AudioAnalyzePeak         analyze2r_p2p;

AudioAnalyzeRMS          analyze3l_rms;
AudioAnalyzePeak         analyze3l_p2p;
AudioAnalyzeRMS          analyze3r_rms;
AudioAnalyzePeak         analyze3r_p2p;

AudioConnection          connection1(tdm1, 0, analyze1l_rms, 0);
AudioConnection          connection2(tdm1, 0, analyze1l_p2p, 0);
AudioConnection          connection3(tdm1, 2, analyze1r_rms, 0);
AudioConnection          connection4(tdm1, 2, analyze1r_p2p, 0);

AudioConnection          connection5(tdm1, 4, analyze2l_rms, 0);
AudioConnection          connection6(tdm1, 4, analyze2l_p2p, 0);
AudioConnection          connection7(tdm1, 6, analyze2r_rms, 0);
AudioConnection          connection8(tdm1, 6, analyze2r_p2p, 0);

AudioConnection          connection9(tdm1, 8, analyze3l_rms, 0);
AudioConnection          connection10(tdm1, 8, analyze3l_p2p, 0);
AudioConnection          connection11(tdm1, 10,analyze3r_rms, 0);
AudioConnection          connection12(tdm1, 10,analyze3r_p2p, 0);

AudioControlCS42448      cs42448_1;      //xy=614,540
// GUItool: end automatically generated code

ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

AudioLevelView levelView1l_p2p = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 10, 10, 64, 3);
AudioLevelView levelView1l_rms = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 14, 10, 64, 3);
AudioLevelView levelView1r_p2p = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 18, 10, 64, 3);
AudioLevelView levelView1r_rms = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 22, 10, 64, 3);

AudioLevelView levelView2l_p2p = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 26, 10, 64, 3);
AudioLevelView levelView2l_rms = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 30, 10, 64, 3);
AudioLevelView levelView2r_p2p = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 34, 10, 64, 3);
AudioLevelView levelView2r_rms = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 38, 10, 64, 3);

AudioLevelView levelView3l_p2p = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 42, 10, 64, 3);
AudioLevelView levelView3l_rms = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 46, 10, 64, 3);
AudioLevelView levelView3r_p2p = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 50, 10, 64, 3);
AudioLevelView levelView3r_rms = AudioLevelView(tft, ST7735_GREEN, ST7735_BLACK, 54, 10, 64, 3);

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
  //tft.useFrameBuffer(true);
  //tft.updateScreenAsync(true);
}

void loop() {
    if (analyze1l_rms.available()){
        levelView1l_rms.updateLevel(analyze1l_rms.read());
    }

    if (analyze1l_p2p.available()){
        levelView1l_p2p.updateLevel(analyze1l_p2p.read());
    }

    if (analyze1r_rms.available()){
        levelView1r_rms.updateLevel(analyze1r_rms.read());
    }

    if (analyze1r_p2p.available()){
        levelView1r_p2p.updateLevel(analyze1r_p2p.read());
    }

    
    
    if (analyze2l_rms.available()){
        levelView2l_rms.updateLevel(analyze2l_rms.read());
    }

    if (analyze2l_p2p.available()){
        levelView2l_p2p.updateLevel(analyze2l_p2p.read());
    }

    if (analyze2r_rms.available()){
        levelView2r_rms.updateLevel(analyze2r_rms.read());
    }

    if (analyze2r_p2p.available()){
        levelView2r_p2p.updateLevel(analyze2r_p2p.read());
    }

    
    
    if (analyze3l_rms.available()){
        levelView3l_rms.updateLevel(analyze3l_rms.read());
    }

    if (analyze3l_p2p.available()){
        levelView3l_p2p.updateLevel(analyze3l_p2p.read());
    }

    if (analyze3r_rms.available()){
        levelView3r_rms.updateLevel(analyze3r_rms.read());
    }

    if (analyze3r_p2p.available()){
        levelView3r_p2p.updateLevel(analyze3r_p2p.read());
    }

    delay(2);
}
