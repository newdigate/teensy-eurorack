# software examples

* [ad5754](ad5754) 
  * [ad5754/01_write_ad5754](ad5754/01_write_ad5754) 
    * set 4 x control voltages using single ad5754 dac
  * [ad5754/02_write_both_ad5754](ad5754/02_write_both_ad5754)
    * set 8 x control voltages using both ad5754 dacs
  

* [audio](audio): examples using teensy audio library
  * [audio/audio_thru_with_scope](audio/audio_thru_with_scope)
    * route audio in -> audio out 
    * display audio in wave graph
  * [audio/audio_to_cv/01_audio_to_cv](audio/audio_to_cv/01_audio_to_cv) 
    * route audio input to cv output
  * [audio/cv_out/01_cv_output](audio/cv_out/01_cv_output)
    * output a sine wave on cv


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

* [knobs](knobs)
  * [knobs/just_encoders](knobs/just_encoders)
    * read values of 3 rotary encoders
    * output changes on serial monitor
  * [knobs/just_encoders_and_display](knobs/just_encoders_and_display)
    * read values of 3 rotary encoders
    * output changes on serial monitor
    * initialize st7735 and display some text
  
[midi](midi)
 * [midi/01_MidiIn_display](midi/01_MidiIn_display)
 * [midi/02_MidiOut](midi/02_MidiOut)



## builds
[![example-ad5754-01](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-ad5754-01.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-ad5754-01.yml)

[![example-ad5754-02](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-ad5754-02.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-ad5754-02.yml)

[![example-audio-libscope-audio-only](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-libscope-04_audio_only_full_bandwidth.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-libscope-04_audio_only_full_bandwidth.yml)

[![example-audio-libscope-fullbandwidth](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-libscope-03_full_bandwidth.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-libscope-03_full_bandwidth.yml)

[![example-audio-libscope-input](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-libscope-02_input_scopes.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-libscope-02_input_scopes.yml)

[![example-audio-player](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-audio-player.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-audio-player.yml)

[![example-audio-thru](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-audio-thru_with_scope.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-audio-thru_with_scope.yml)

[![example-audio-thru](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-audio-thru_with_scope.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-audio-thru_with_scope.yml)

[![example-audiocv-scope](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-audio-simplescope-01_audiocv_scope.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-audio-simplescope-01_audiocv_scope.yml)

[![example-cv-out](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-cv-out.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-cv-out.yml)

[![example-cv-scope](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-audio-simplescope-02_simple_cv_scope.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-audio-simplescope-02_simple_cv_scope.yml)

[![example-graphics-heart](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-graphics-01_heart.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-graphics-01_heart.yml)

[![example-graphics-test](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-graphics-00_graphicstest.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-graphics-00_graphicstest.yml)

[![example-knobs-just-encoders](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-knobs-just-encoders.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-knobs-just-encoders.yml)

[![example-knobs-just-encoders-and-display](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-knobs-just-encoders_and_display.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-knobs-just-encoders_and_display.yml)

[![example-midi-in](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-midi-01_midiin_display.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-midi-01_midiin_display.yml)

[![example-midi-out](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-midi-02_midiout.yml/badge.svg)](https://github.com/newdigate/teensy-eurorack/actions/workflows/teensy-examples-midi-02_midiout.yml)

