#include <Audio.h>
#include "teensy_eurorack.h"
#include "teensy_eurorack_audio.h"

// GUItool: begin automatically generated code
AudioInputTDM               tdm1;           //xy=230,1623
AudioOutputTDM              tdm3;           //xy=1017,1730
AudioInputOutputSPI         ad7606_ad5754;         //xy=484,1490
AudioConnection             patchCord1(tdm1, 0, ad7606_ad5754, 0);
AudioConnection             patchCord2(tdm1, 0, ad7606_ad5754, 1);
AudioConnection             patchCord3(tdm1, 0, ad7606_ad5754, 2);
AudioConnection             patchCord4(tdm1, 0, ad7606_ad5754, 3);
AudioConnection             patchCord5(tdm1, 0, ad7606_ad5754, 4);
AudioConnection             patchCord6(tdm1, 0, ad7606_ad5754, 5);
AudioConnection             patchCord7(tdm1, 0, ad7606_ad5754, 6);
AudioConnection             patchCord8(tdm1, 0, ad7606_ad5754, 7);
AudioControlCS42448         cs42448_1;      //xy=477,1598
// GUItool: end automatically generated code

void setup() {
  AudioMemory(80);
  Serial.begin(9600);

  AudioNoInterrupts();  
  cs42448_1.enable();
  cs42448_1.volume(1);
  AudioInterrupts();    // enable, both tones will start together
  delay(100);
}

unsigned count = 0, count2 = 0;
void loop() {
   count++;

  if (count % 5000000 == 0) {
    count2 ++;
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
    Serial.print("    ");
    Serial.print("Free Mem: ");
    Serial.print(memfree());
    Serial.println();
  }
}
