#include <Audio.h>
#include <ST7735_t3.h> // Hardware-specific library
#include <ResponsiveAnalogRead.h>

#include "teensy_eurorack.h"
#include "input_output_spi.h"
#include "ScopeView.h"

ST7735_t3 TFT = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// GUItool: begin automatically generated code
AudioInputTDM            tdm;            //xy=210.11108779907227,555.4443893432617
AudioInputOutputSPI      ad7606;         //xy=253.8888282775879,242.22220611572266
AudioRecordQueue         audioRecordQueue9; //xy=551.6665954589844,622.2221488952637
AudioRecordQueue         audioRecordQueue7; //xy=553.8888320922852,354.444393157959
AudioRecordQueue         audioRecordQueue10; //xy=553.888916015625,655.5554962158203
AudioRecordQueue         audioRecordQueue11; //xy=553.8889541625977,688.8888387680054
AudioRecordQueue         audioRecordQueue8; //xy=556.1110382080078,391.11108016967773
AudioRecordQueue         audioRecordQueue12; //xy=555.0000762939453,722.2222347259521
AudioRecordQueue         audioRecordQueue13; //xy=554.9999313354492,756.6666603088379
AudioRecordQueue         audioRecordQueue14; //xy=554.9999313354492,792.2221641540527
AudioRecordQueue         audioRecordQueue6; //xy=557.2220993041992,308.8888530731201
AudioRecordQueue         audioRecordQueue5; //xy=564.9999771118164,256.66662406921387
AudioRecordQueue         audioRecordQueue3; //xy=567.2221984863281,176.6666259765625
AudioRecordQueue         audioRecordQueue4; //xy=569.4443359375,217.77774238586426
AudioRecordQueue         audioRecordQueue1; //xy=570.5554885864258,97.77776336669922
AudioRecordQueue         audioRecordQueue2; //xy=572.7776794433594,134.4444284439087
AudioSynthWaveformSine   sine10;         //xy=751.1111102634006,491.11109627617725
AudioSynthWaveformSine   sine13;         //xy=753.3333324856228,603.3333184983995
AudioSynthWaveformSine   sine15;         //xy=753.3333625793457,683.3333053588867
AudioSynthWaveformSine   sine16;         //xy=753.3333587646484,722.2221755981445
AudioSynthWaveformSine   sine12;         //xy=754.4444435967339,559.9999851650662
AudioSynthWaveformSine   sine9;          //xy=757.7777769300673,453.33331849839954
AudioSynthWaveformSine   sine14;         //xy=757.7777862548828,644.4443759918213
AudioSynthWaveformSine   sine11;         //xy=758.8888880411783,525.5555407206217
AudioSynthWaveformSine   sine1;          //xy=766.9999732971191,97.77776336669922
AudioSynthWaveformSine   sine2;          //xy=766.999927520752,133.3333683013916
AudioSynthWaveformSine   sine8;          //xy=769.2221870422363,356.66664123535156
AudioSynthWaveformSine   sine3;          //xy=770.3332901000977,172.22220039367676
AudioSynthWaveformSine   sine5;          //xy=770.3332672119141,248.88892650604248
AudioSynthWaveformSine   sine6;          //xy=770.3332710266113,284.4444122314453
AudioSynthWaveformSine   sine7;          //xy=770.3332138061523,318.8888273239136
AudioSynthWaveformSine   sine4;          //xy=772.5555877685547,210.00000286102295
AudioSynthWaveformDc     dc1;            //xy=226,901
AudioSynthWaveformDc     dc2;            //xy=226,946
AudioSynthWaveformDc     dc3;            //xy=227,995
AudioSynthWaveformDc     dc4;            //xy=229,1039
AudioRecordQueue         queue4;         //xy=534,1040
AudioRecordQueue         queue1;         //xy=550,902
AudioRecordQueue         queue2;         //xy=551,945
AudioRecordQueue         queue3;         //xy=560,989

AudioOutputTDM           tdm2;           //xy=1037.8889694213867,542.1110763549805
AudioConnection          patchCord1(tdm, 0, audioRecordQueue9, 0);
AudioConnection          patchCord2(tdm, 2, audioRecordQueue10, 0);
AudioConnection          patchCord3(tdm, 4, audioRecordQueue11, 0);
AudioConnection          patchCord4(tdm, 6, audioRecordQueue12, 0);
AudioConnection          patchCord5(tdm, 8, audioRecordQueue13, 0);
AudioConnection          patchCord6(tdm, 10, audioRecordQueue14, 0);
AudioConnection          patchCord7(ad7606, 0, audioRecordQueue1, 0);
AudioConnection          patchCord8(ad7606, 1, audioRecordQueue2, 0);
AudioConnection          patchCord9(ad7606, 2, audioRecordQueue3, 0);
AudioConnection          patchCord10(ad7606, 3, audioRecordQueue4, 0);
AudioConnection          patchCord11(ad7606, 4, audioRecordQueue5, 0);
AudioConnection          patchCord12(ad7606, 5, audioRecordQueue6, 0);
AudioConnection          patchCord13(ad7606, 6, audioRecordQueue7, 0);
AudioConnection          patchCord14(ad7606, 7, audioRecordQueue8, 0);
AudioConnection          patchCord15(sine10, 0, tdm2, 2);
AudioConnection          patchCord16(sine13, 0, tdm2, 8);
AudioConnection          patchCord17(sine15, 0, tdm2, 12);
AudioConnection          patchCord18(sine16, 0, tdm2, 14);
AudioConnection          patchCord19(sine12, 0, tdm2, 6);
AudioConnection          patchCord20(sine9, 0, tdm2, 0);
AudioConnection          patchCord21(sine14, 0, tdm2, 10);
AudioConnection          patchCord22(sine11, 0, tdm2, 4);
AudioConnection          patchCord23(sine1, 0, ad7606, 0);
AudioConnection          patchCord24(sine2, 0, ad7606, 1);
AudioConnection          patchCord25(sine8, 0, ad7606, 7);
AudioConnection          patchCord26(sine3, 0, ad7606, 2);
AudioConnection          patchCord27(sine5, 0, ad7606, 4);
AudioConnection          patchCord28(sine6, 0, ad7606, 5);
AudioConnection          patchCord29(sine7, 0, ad7606, 6);
AudioConnection          patchCord30(sine4, 0, ad7606, 3);
AudioConnection          patchCord31(dc1, queue1);
AudioConnection          patchCord32(dc2, queue2);
AudioConnection          patchCord33(dc3, queue3);
AudioConnection          patchCord34(dc4, queue4);
AudioControlCS42448      cs42448_1;      //xy=553.4443435668945,831.111083984375
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

ScopeView scopeViewPot1 = ScopeView(TFT, queue1, colors[2], (int16_t)ST7735_BLACK, 64);
ScopeView scopeViewPot2 = ScopeView(TFT, queue2, colors[3], (int16_t)ST7735_BLACK, 64);
ScopeView scopeViewPot3 = ScopeView(TFT, queue3, colors[4], (int16_t)ST7735_BLACK, 64);
ScopeView scopeViewPot4 = ScopeView(TFT, queue4, colors[5], (int16_t)ST7735_BLACK, 64);

ResponsiveAnalogRead analogPot1(TEENSY_EURORACK_PIN_POT1, true, 1.0);
ResponsiveAnalogRead analogPot2(TEENSY_EURORACK_PIN_POT2, true, 1.0);
ResponsiveAnalogRead analogPot3(TEENSY_EURORACK_PIN_POT3, true, 1.0);
ResponsiveAnalogRead analogPot4(TEENSY_EURORACK_PIN_POT4, true, 1.0);

unsigned long start_time;
void setup() {
    pinMode(TEENSY_EURORACK_PIN_POT1, INPUT_DISABLE);
    pinMode(TEENSY_EURORACK_PIN_POT2, INPUT_DISABLE);
    pinMode(TEENSY_EURORACK_PIN_POT3, INPUT_DISABLE);
    pinMode(TEENSY_EURORACK_PIN_POT4, INPUT_DISABLE);

    analogReadResolution(12);
    analogPot1.enableEdgeSnap();
    analogPot1.setAnalogResolution(4096);
    analogPot2.enableEdgeSnap();
    analogPot2.setAnalogResolution(4096);
    analogPot3.enableEdgeSnap();
    analogPot3.setAnalogResolution(4096);
    analogPot4.enableEdgeSnap();
    analogPot4.setAnalogResolution(4096);

    Serial.begin(9600);
    //while(!Serial) {
    //  delay(1);
    //}

    AudioNoInterrupts();

    AudioMemory(160);
    cs42448_1.enable();
    cs42448_1.volume(1);
    AudioInterrupts();    // enable, both tones will start together

    TFT.initR(INITR_144GREENTAB);
    TFT.setRotation(3);
    TFT.fillScreen(ST7735_BLACK);
    TFT.useFrameBuffer(true);
    TFT.updateScreenAsync(true);
    //noInterrupts();
    sine8.frequency(1000);
    sine8.amplitude(0.7);

    sine7.frequency(AUDIO_SAMPLE_RATE_EXACT/128.0);
    sine7.amplitude(0.7);

    sine6.frequency(AUDIO_SAMPLE_RATE_EXACT*2.0/128.0);
    sine6.amplitude(0.7);

    sine5.frequency(AUDIO_SAMPLE_RATE_EXACT*0.5/128.0);
    sine5.amplitude(0.7);

    sine4.frequency(AUDIO_SAMPLE_RATE_EXACT*4.0/128.0);
    sine4.amplitude(0.7);

    sine3.frequency(AUDIO_SAMPLE_RATE_EXACT*8.0/128.0);
    sine3.amplitude(0.7);

    sine2.frequency(AUDIO_SAMPLE_RATE_EXACT*0.25/128.0);
    sine2.amplitude(0.7);

    sine1.frequency(AUDIO_SAMPLE_RATE_EXACT*0.125/128.0);
    sine1.amplitude(0.7);

    sine9.frequency(AUDIO_SAMPLE_RATE_EXACT*12.0/128.0);
    sine9.amplitude(0.7);

    sine10.frequency(AUDIO_SAMPLE_RATE_EXACT*6.0/128.0);
    sine10.amplitude(0.7);

    sine11.frequency(250);
    sine11.amplitude(0.7);

    sine12.frequency(100);
    sine12.amplitude(0.7);

    sine13.frequency(125);
    sine13.amplitude(0.7);

    sine14.frequency(750);
    sine14.amplitude(0.7);

    sine15.frequency(4000);
    sine15.amplitude(0.7);

    sine16.frequency(1500);
    sine16.amplitude(0.7);

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

    queue1.begin();
    queue2.begin();
    queue3.begin();
    queue4.begin();
    dc1.amplitude(0.5, 1);
    dc1.amplitude(-0.5, 1);
    dc1.amplitude(0.25, 1);
    dc1.amplitude(-0.25, 1);
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
    if (count % 50 == 0) {
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

        scopeViewPot1.checkForUpdateBuffer();
        scopeViewPot2.checkForUpdateBuffer();
        scopeViewPot3.checkForUpdateBuffer();
        scopeViewPot4.checkForUpdateBuffer();

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

        scopeViewPot1.undrawScope();
        scopeViewPot2.undrawScope();
        scopeViewPot3.undrawScope();
        scopeViewPot4.undrawScope();

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

        scopeViewPot1.drawScope();
        scopeViewPot2.drawScope();
        scopeViewPot3.drawScope();
        scopeViewPot4.drawScope();
        //TFT.updateScreen();
    }

    if (audioRecordQueue1.available() > 2) {
        audioRecordQueue1.end();
        while (audioRecordQueue1.available() > 2) {
            audioRecordQueue1.readBuffer();
            audioRecordQueue1.freeBuffer();
        }
        audioRecordQueue1.begin();
    }


    if (audioRecordQueue2.available() > 2) {
        audioRecordQueue2.end();
        while (audioRecordQueue2.available() > 2) {
            audioRecordQueue2.readBuffer();
            audioRecordQueue2.freeBuffer();
        }
        audioRecordQueue2.begin();
    }


    if (audioRecordQueue3.available() > 2) {
        audioRecordQueue3.end();
        while (audioRecordQueue3.available() > 2) {
            audioRecordQueue3.readBuffer();
            audioRecordQueue3.freeBuffer();
        }
        audioRecordQueue3.begin();
    }


    if (audioRecordQueue4.available() > 2) {
        audioRecordQueue4.end();
        while (audioRecordQueue4.available() > 2) {
            audioRecordQueue4.readBuffer();
            audioRecordQueue4.freeBuffer();
        }
        audioRecordQueue4.begin();
    }


    if (audioRecordQueue5.available() > 2) {
        audioRecordQueue5.end();
        while (audioRecordQueue5.available() > 2) {
            audioRecordQueue5.readBuffer();
            audioRecordQueue5.freeBuffer();
        }
        audioRecordQueue5.begin();
    }


    if (audioRecordQueue6.available() > 2) {
        audioRecordQueue6.end();
        while (audioRecordQueue6.available() > 2) {
            audioRecordQueue6.readBuffer();
            audioRecordQueue6.freeBuffer();
        }
        audioRecordQueue6.begin();
    }


    if (audioRecordQueue7.available() > 2) {
        audioRecordQueue7.end();
        while (audioRecordQueue7.available() > 2) {
            audioRecordQueue7.readBuffer();
            audioRecordQueue7.freeBuffer();
        }
        audioRecordQueue7.begin();
    }

    if (audioRecordQueue8.available() > 2) {
        audioRecordQueue8.end();
        while (audioRecordQueue8.available() > 2) {
            audioRecordQueue8.readBuffer();
            audioRecordQueue8.freeBuffer();
        }
        audioRecordQueue8.begin();
    }

    if (audioRecordQueue9.available() > 2) {
        audioRecordQueue9.end();
        while (audioRecordQueue9.available() > 2) {
            audioRecordQueue9.readBuffer();
            audioRecordQueue9.freeBuffer();
        }
        audioRecordQueue9.begin();
    }

    if (audioRecordQueue10.available() > 2) {
        audioRecordQueue10.end();
        while (audioRecordQueue10.available() > 2) {
            audioRecordQueue10.readBuffer();
            audioRecordQueue10.freeBuffer();
        }
        audioRecordQueue10.begin();
    }

    if (audioRecordQueue11.available() > 2) {
        audioRecordQueue11.end();
        while (audioRecordQueue11.available() > 2) {
            audioRecordQueue11.readBuffer();
            audioRecordQueue11.freeBuffer();
        }
        audioRecordQueue11.begin();
    }

    if (audioRecordQueue12.available() > 2) {
        audioRecordQueue12.end();
        while (audioRecordQueue12.available() > 2) {
            audioRecordQueue12.readBuffer();
            audioRecordQueue12.freeBuffer();
        }
        audioRecordQueue12.begin();
    }

    if (audioRecordQueue13.available() > 2) {
        audioRecordQueue13.end();
        while (audioRecordQueue13.available() > 2) {
            audioRecordQueue13.readBuffer();
            audioRecordQueue13.freeBuffer();
        }
        audioRecordQueue13.begin();
    }

    if (audioRecordQueue14.available() > 2) {
        audioRecordQueue14.end();
        while (audioRecordQueue14.available() > 2) {
            audioRecordQueue14.readBuffer();
            audioRecordQueue14.freeBuffer();
        }
        audioRecordQueue14.begin();
    }


    if (queue1.available() > 2) {
        queue1.end();
        while (queue1.available() > 2) {
            queue1.readBuffer();
            queue1.freeBuffer();
        }
        queue1.begin();
    }

    if (queue2.available() > 2) {
        queue2.end();
        while (queue2.available() > 2) {
            queue2.readBuffer();
            queue2.freeBuffer();
        }
        queue2.begin();
    }

    if (queue3.available() > 2) {
        queue3.end();
        while (queue3.available() > 2) {
            queue3.readBuffer();
            queue3.freeBuffer();
        }
        queue3.begin();
    }

    if (queue4.available() > 2) {
        queue4.end();
        while (queue4.available() > 2) {
            queue4.readBuffer();
            queue4.freeBuffer();
        }
        queue4.begin();
    }

    if (count % 20000 == 0) {
        analogPot1.update();
        analogPot2.update();
        analogPot3.update();
        analogPot4.update();

        // if the responsive value has change, print out 'changed'
        if(analogPot1.hasChanged()) {
            float ff = (analogPot1.getValue()/2048.0) - 1.0f;
            dc1.amplitude(ff, 10);
        }

        if(analogPot2.hasChanged()) {
            float ff = (analogPot2.getValue()/2048.0) - 1.0f;
            dc2.amplitude(ff, 10);
        }

        if(analogPot3.hasChanged()) {
            float ff = (analogPot3.getValue()/2048.0) - 1.0f;
            dc3.amplitude(ff, 10);
        }

        if(analogPot4.hasChanged()) {
            float ff = (analogPot4.getValue()/2048.0) - 1.0f;
            dc4.amplitude(ff, 10);
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
            Serial.print(count2/100);
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