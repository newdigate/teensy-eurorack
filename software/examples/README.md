# software examples

* [ad5754](ad5754)
  * how to set 4 x control voltages using single ad5754 dac
  * how to set 8 x control voltages using both ad5754 dacs
* [audio](audio): examples using TeensyAudioLibrary
  * how to route audio input to audio output and display audio wave
  * how to route audio input to cv output
  * how to send a sine wave to cv output
* [audio/libscope](audio/libscope): examples using [teensy-audio-libtftscope](https://github.com/newdigate/teensy-audio-libtftscope) 
  * [audio/libscope/02_input_scopes](audio/libscope/02_input_scopes)
    * output sine waves on all audio and cv outputs
    * display all audio and cv inputs on a scope view
  * [audio/libscope/03_full_bandwidth](audio/libscope/03_full_bandwidth)
    * output sine waves on all audio and cv outputs
    * display all audio and cv inputs on a scope view
    * display 4 x potentiometer values on a scope view   
  * [audio/libscope/04_audio_only_full_bandwidth](audio/libscope/04_audio_only_full_bandwidth)
    * output sine waves on all audio outputs
    * display all audio inputs on a scope view
* [audio/player](audio/player) using [FrankBoesing/Arduino-Teensy-Codec-lib](https://github.com/FrankBoesing/Arduino-Teensy-Codec-lib)
  * play .mp3 and .aac audio files from micro SD card
  * read mp3 tags
  * display jpeg of album cover if available
* [audio/simple_scope](audio/simple_scope)
  * [audio/simple_scope/01_audiocv_scope](audio/simple_scope/01_audiocv_scope)
    * display graph of incoming audio and cv (no dependencies) 
  * [audio/simple_scope/02_simple_cv_scope](audio/simple_scope/02_simple_cv_scope)
    * display graph of incoming cv (no dependencies)
* [graphics](graphics)
  * [graphics/00_graphicstest](graphics/00_graphicstest)
    * Adafruit graphics test adapted for teensy-eurorack parameters
  * [graphics/01_heart](graphics/01_heart)
    * Draw anti-aliased bezier curves (using [newdigate/teensy-libcurve](https://github.com/newdigate/teensy-libcurve))

[knobs](knobs)

[midi](midi)