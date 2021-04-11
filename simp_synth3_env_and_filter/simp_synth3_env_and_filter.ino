
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>


// GUItool: begin automatically generated code
AudioSynthNoisePink      pink1;          //xy=141,400
AudioSynthWaveform       waveform3;      //xy=156,343
AudioSynthWaveform       waveform1;      //xy=158,226
AudioSynthWaveform       waveform2;      //xy=158,286
AudioMixer4              mixer1;         //xy=385,288
AudioOutputAnalog        dac1;           //xy=547,246
AudioConnection          patchCord1(pink1, 0, mixer1, 3);
AudioConnection          patchCord2(waveform3, 0, mixer1, 2);
AudioConnection          patchCord3(waveform1, 0, mixer1, 0);
AudioConnection          patchCord4(waveform2, 0, mixer1, 1);
AudioConnection          patchCord5(mixer1, dac1);
AudioControlSGTL5000     sgtl5000_1;     //xy=174,471
// GUItool: end automatically generated code



// GUItool: begin automatically generated code
//AudioSynthWaveform       waveform1;      //xy=156,226
//AudioOutputAnalog        dac1;           //xy=331,221
//AudioConnection          patchCord1(waveform1, dac1);
// GUItool: end automatically generated code

///////////////////////////////////////////////
//CONSTANTS

#define DEBUG_ENABLE

const byte CTRL_MASTER_FREQ = 99;


const byte CTRL_SAW_MIX = 100;
const byte CTRL_SQ_MIX = 101;
const byte CTRL_SIN_MIX = 102;
const byte CTRL_NOISE_MIX = 103;

//lookup table
float midiLookUp[127];

///////////////////////////////////////////////

void ctrlChange(byte ch, byte ctrl, byte val){
    switch (ctrl) {
    
        case CTRL_SAW_MIX:
            mixer1.gain(0,((float)val)/127.0 );
            break;
      
        case CTRL_SQ_MIX:
            mixer1.gain(1,((float)val)/127.0 );
            break;
      
        case CTRL_SIN_MIX:
            mixer1.gain(2,(2.0*(float)val)/127.0 );
            break;
      
        case CTRL_NOISE_MIX:
            mixer1.gain(3,((float)val)/127.0 );
            break;

        case CTRL_MASTER_FREQ: 
            float f = midiLookUp[val];

#ifdef DEBUG_ENABLE
            Serial.println("setting note to ");
            Serial.println(val);
            Serial.println(f);
#endif            

            setAllOscFreq(midiLookUp[val]);
            break;
  }  
}


void initLookupTable(){
    float a = 440; // a is 440 hz...
    for (int x = 0; x < 127; ++x)
    {
        midiLookUp[x] = (a / 32.0) * ( pow(2,(((float)x - 9.0) / 12.0)) )  ;
#ifdef DEBUG_ENABLE
            Serial.println("setting note to ");
            Serial.println(x);
            Serial.println(midiLookUp[x]);
#endif           
        
    }
}

//float midiNoteToFreq(byte note){
//    return midiLookUp[note];
//}

void setAllOscFreq(float f){    
    waveform1.frequency(f);
    waveform2.frequency(f);
    waveform3.frequency(f);
}


void setup() {
    // initialize serial communications at 9600 bps:
    //
#ifdef DEBUG_ENABLE
    Serial.begin(9600);
#else    
    //usbMIDI.setHandleControlChange(ctrlChange);
#endif
    usbMIDI.setHandleControlChange(ctrlChange);
    AudioMemory(20);

    int default_freq = 200;
    float default_amp = .25;
    float default_pw = .15;
    
    waveform1.begin(WAVEFORM_SAWTOOTH);    
    waveform1.frequency(default_freq);
    waveform1.amplitude(default_amp);
    waveform1.pulseWidth(default_pw);

    waveform2.begin(WAVEFORM_SQUARE);    
    waveform2.frequency(default_freq);
    waveform2.amplitude(default_amp);
    waveform2.pulseWidth(default_pw);

    waveform3.begin(WAVEFORM_SINE);    
    waveform3.frequency(default_freq);
    waveform3.amplitude(default_amp);
    waveform3.pulseWidth(default_pw);
    

    pink1.amplitude(default_amp);

    mixer1.gain(0 , 1.0);
    mixer1.gain(1 , 1.0);
    mixer1.gain(2 , 1.0);
    mixer1.gain(3 , 1.0);

    initLookupTable();
  
}


void loop() {
    usbMIDI.read();
}
