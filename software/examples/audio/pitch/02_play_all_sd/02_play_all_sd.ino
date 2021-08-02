#include <Arduino.h>
#include <Audio.h>
#include <SD.h>
#include <TeensyVariablePlayback.h>
#include <Bounce.h>
#include <teensy_eurorack.h>

// GUItool: begin automatically generated code
AudioPlaySdResmp         playSd1;        //xy=324,457
AudioOutputTDM           tdm1;           //xy=1377,352
AudioConnection          patchCord1(playSd1, 0, tdm1, 0);
AudioConnection          patchCord2(playSd1, 1, tdm1, 2);
AudioControlCS42448      cs42448;      //xy=793,1101
// GUItool: end automatically generated code


Bounce button0 = Bounce(TEENSY_EURORACK_PIN_ENC1_SW, 10);
Bounce button1 = Bounce(TEENSY_EURORACK_PIN_ENC2_SW, 10);

#define A14 10

//char* _filenames[100] = {"BASS.wav", "BASSSL01.wav", "BASSSL03.wav", "BASSSL04.wav"};
char** _filenames;

int16_t _fileIndex = 0;
uint16_t _numWaveFiles = 0; //4;

const int analogInPin = 14;
unsigned long lastSamplePlayed = 0;
bool _filePlayFailed = false;
 
double getPlaybackRate(int16_t analog) { //analog: 0..1023
    return  (analog - 512.0) / 512.0;
}

uint16_t getNumWavFilesInDirectory(char *directory);
void populateFilenames(char *directory, char **filenames);

void setup() {
    analogReference(0);
    pinMode(analogInPin, INPUT_DISABLE);   // i.e. Analog
    pinMode(TEENSY_EURORACK_PIN_ENC1_SW, INPUT_PULLUP);
    pinMode(TEENSY_EURORACK_PIN_ENC2_SW, INPUT_PULLUP);

    Serial.begin(57600);
    while (!Serial) {
      delay(100);
    }
    Serial.println("Starting...");
    while (!(SD.begin(BUILTIN_SDCARD))) {
        // stop here if no SD card, but print a message
        Serial.println("Unable to access the SD card");
        delay(500);
    }
    cs42448.enable();
    cs42448.volume(0.5f);

    playSd1.enableInterpolation(true);
    int newsensorValue = analogRead(analogInPin);
    playSd1.setPlaybackRate(getPlaybackRate(newsensorValue));
    
    _numWaveFiles = getNumWavFilesInDirectory("/");
    Serial.printf("Num wave files: %d\n", _numWaveFiles);
    _filenames = new char*[_numWaveFiles];
    populateFilenames("/", _filenames);

    Serial.println("Populated...");
    AudioMemory(24);
}

char fname[100];
            
void loop() {

    int newsensorValue = analogRead(analogInPin);
    playSd1.setPlaybackRate(getPlaybackRate(newsensorValue));

    button0.update();
    if (button0.fallingEdge()) {
        _fileIndex++;
        _fileIndex %= _numWaveFiles;
        Serial.printf("Next %i\n", _fileIndex );
        if (playSd1.isPlaying())
            playSd1.stop();
        lastSamplePlayed = 0;
        _filePlayFailed = false;
    }
    
    button1.update();
    if (button1.fallingEdge()) {
        _fileIndex--;
        _fileIndex %= _numWaveFiles;
        Serial.printf("Next %i\n", _fileIndex );
        if (playSd1.isPlaying())
            playSd1.stop();
        lastSamplePlayed = 0;
        _filePlayFailed = false;
    }
    
    unsigned currentMillis = millis();
    if (currentMillis > lastSamplePlayed + 500 && !_filePlayFailed) {
        if (!playSd1.isPlaying()) {
            playSd1.stop();
            
            Serial.printf("try playing %d: %s %s\n", _fileIndex, _filenames[_fileIndex], fname);
            memcpy(fname, _filenames[_fileIndex], strlen(_filenames[_fileIndex])+1);
            
            if (playSd1.playWav(fname)) {
              lastSamplePlayed = currentMillis;
              Serial.printf("playing %s\n", _filenames[_fileIndex]);
            } else {
              _filePlayFailed = true;
              Serial.printf("failed to play %s\n", _filenames[_fileIndex]);
            }

            Serial.print("Memory: ");
            Serial.print(AudioMemoryUsage());
            Serial.print(",");
            Serial.print(AudioMemoryUsageMax());
            Serial.println();
        }
    }
    delay(10);
}

uint16_t getNumWavFilesInDirectory(char *directory) {
  File dir = SD.open(directory);
  uint16_t numWaveFiles = 0;

  while (true) { 

    File files =  dir.openNextFile();
    if (!files) {
      //If no more files, break out.
      break;
    }

    String curfile = files.name(); //put file in string
    
    int m = curfile.lastIndexOf(".WAV");
    int a = curfile.lastIndexOf(".wav");
    int underscore = curfile.indexOf("_");
    int underscore2 = curfile.indexOf("._");
    // if returned results is more then 0 add them to the list.
    if ((m > 0 || a > 0) && (underscore != 0) && (underscore2 != 0) ) {  
        numWaveFiles++;
    }
    
    files.close();
  }
  // close 
  dir.close();
  return numWaveFiles;
}

void populateFilenames(char *directory, char **filenames) {
  File dir = SD.open(directory);
  uint16_t index = 0;

  while (true) { 

    File files =  dir.openNextFile();
    if (!files) {
      //If no more files, break out.
      break;
    }

    String curfile = files.name(); //put file in string
    
    int m = curfile.lastIndexOf(".WAV");
    int a = curfile.lastIndexOf(".wav");
    int underscore = curfile.indexOf("_");
    int underscore2 = curfile.indexOf("._");
    // if returned results is more then 0 add them to the list.
    if ((m > 0 || a > 0) && (underscore != 0) && (underscore2 != 0) ) {  
    
        Serial.printf(" ---- %s\n", curfile.c_str());
        filenames[index] = new char[curfile.length()+1] {0};
        memcpy(filenames[index], curfile.c_str(), curfile.length());
        Serial.printf(" ------ %s\n", filenames[index]);
        index++;
    } 
    files.close();
  }
  // close 
  dir.close();
}
