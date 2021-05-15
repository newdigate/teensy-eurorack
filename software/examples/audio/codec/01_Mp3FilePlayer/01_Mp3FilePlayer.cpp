// Simple MP3 player example
//
// Requires the audio shield:
//   http://www.pjrc.com/store/teensy3_audio.html
//
// This example code is in the public domain.

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

#include <play_sd_mp3.h>


// GUItool: begin automatically generated code
AudioPlaySdMp3           playMp31;       //xy=154,78
AudioOutputTDM           tdm;           //xy=334,89
AudioConnection          patchCord1(playMp31, 0, tdm, 0);
AudioConnection          patchCord2(playMp31, 1, tdm, 2);

AudioConnection          patchCord3(playMp31, 0, tdm, 4);
AudioConnection          patchCord4(playMp31, 1, tdm, 6);

AudioConnection          patchCord5(playMp31, 0, tdm, 8);
AudioConnection          patchCord6(playMp31, 1, tdm, 10);

AudioConnection          patchCord7(playMp31, 0, tdm, 12);
AudioConnection          patchCord8(playMp31, 1, tdm, 14);

AudioControlCS42448      cs42448;
// GUItool: end automatically generated code
int  __bss_end = 0; // needed to compile, used in codecs.cpp : int AudioCodec::freeRam(void)

void setup() {
  Serial.begin(9600);

  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example

  AudioNoInterrupts();  
  
  AudioMemory(160);
  cs42448.enable();
  cs42448.volume(1);
  AudioInterrupts();  


  if (!(SD.begin(BUILTIN_SDCARD))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

  // Start playing the file.  This sketch continues to
  // run while the file plays.
  playMp31.play(filename);

  // Simply wait for the file to finish playing.
  while (playMp31.isPlaying()) {
    // uncomment these lines if your audio shield
    // has the optional volume pot soldered
    //float vol = analogRead(15);
    //vol = vol / 1024;
    // sgtl5000_1.volume(vol);

#if 0
	 Serial.print("Max Usage: ");
	 Serial.print(playMp31.processorUsageMax());
	 Serial.print("% Audio, ");
	 	 
	 Serial.print(AudioProcessorUsageMax());	 
	 Serial.println("% All");
	 
	 AudioProcessorUsageMaxReset();
	 playMp31.processorUsageMaxReset();
	 playMp31.processorUsageMaxResetDecoder();
#endif 
	 
	 delay(1000);
  }
}


void loop() {
  playFile("SDTEST1.mp3");	
  playFile("SDTEST2.mp3");
  playFile("SDTEST3.mp3");
  playFile("SDTEST4.mp3");
  delay(500);
}
