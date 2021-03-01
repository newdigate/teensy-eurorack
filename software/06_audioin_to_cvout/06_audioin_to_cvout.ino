#include <Audio.h>
#include "input_shared_ad7606.h"
#include "output_shared_ad5754_dual.h"

// GUItool: begin automatically generated code
AudioInputTDM            tdm1;           //xy=401,330
AudioOutputTDM           tdm3;           //xy=962,420
AudioOutputSharedAD5754Dual     ad5754;           //xy=514,291
AudioInputSharedAD7606          ad7606;
AudioConnection          patchCord1(tdm1, 0, ad5754, 0);
AudioConnection          patchCord2(tdm1, 0, ad5754, 1);
AudioConnection          patchCord3(tdm1, 0, ad5754, 2);
AudioConnection          patchCord4(tdm1, 0, ad5754, 3);
AudioConnection          patchCord5(tdm1, 0, ad5754, 4);
AudioConnection          patchCord6(tdm1, 0, ad5754, 5);
AudioConnection          patchCord7(tdm1, 0, ad5754, 6);
AudioConnection          patchCord8(tdm1, 0, ad5754, 7); 
AudioControlCS42448      cs42448_1;      //xy=614,540
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

unsigned count = 0;
void loop() {
   count++;

  if (count % 5000000 == 0) {
    Serial.print("all=");
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


unsigned memfree(void) {
  extern unsigned long _ebss;
  extern unsigned long _sdata;
  extern unsigned long _estack;
  const unsigned DTCM_START = 0x20000000UL;
  unsigned dtcm = (unsigned)&_estack - DTCM_START;
  unsigned stackinuse = (unsigned) &_estack -  (unsigned) __builtin_frame_address(0);
  unsigned varsinuse = (unsigned)&_ebss - (unsigned)&_sdata;
  unsigned freemem = dtcm - (stackinuse + varsinuse);
  return freemem;
}
