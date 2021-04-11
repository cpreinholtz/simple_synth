#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoisePink      pink1;          //xy=66,315
AudioSynthWaveform       waveform3;      //xy=81,258
AudioSynthWaveform       waveform1;      //xy=83,141
AudioSynthWaveform       waveform2;      //xy=83,201
AudioMixer4              mixer1;         //xy=266,233
AudioEffectEnvelope      envelope1;      //xy=357,137
AudioOutputAnalog        dac1;           //xy=721,230
AudioConnection          patchCord1(pink1, 0, mixer1, 3);
AudioConnection          patchCord2(waveform3, 0, mixer1, 2);
AudioConnection          patchCord3(waveform1, 0, mixer1, 0);
AudioConnection          patchCord4(waveform2, 0, mixer1, 1);
AudioConnection          patchCord5(mixer1, envelope1);
AudioConnection          patchCord6(envelope1, dac1);
// GUItool: end automatically generated code



///////////////////////////////////////////////
//CONSTANTS

#define DEBUG_ENABLE

const byte CTRL_MASTER_FREQ = 99;


const byte CTRL_SAW_MIX = 100;
const byte CTRL_SQ_MIX = 101;
const byte CTRL_SIN_MIX = 102;
const byte CTRL_NOISE_MIX = 103;

const byte CTRL_FILT_CUTOFF = 104;
const byte CTRL_FILT_MIX = 105;

//lookup table
float midiLookUp[127];

///////////////////////////////////////////////

void ctrlChange(byte ch, byte ctrl, byte val){
#ifdef DEBUG_ENABLE
    Serial.println("ctrl change hit");
    Serial.println(ctrl);
    Serial.println(val);
#endif
    
    switch (ctrl) {
    
        case CTRL_SAW_MIX:
#ifdef DEBUG_ENABLE
            Serial.println("saw mix");
#endif       
            mixer1.gain(0,((float)val)/127.0 );
            break;
      
        case CTRL_SQ_MIX:
#ifdef DEBUG_ENABLE
            Serial.println("sq mix");
#endif       
            mixer1.gain(1,((float)val)/127.0 );
            break;
      
        case CTRL_SIN_MIX:
#ifdef DEBUG_ENABLE
            Serial.println("sn mix");
#endif       
            mixer1.gain(2,(2.0*(float)val)/127.0 );
            break;
      
        case CTRL_NOISE_MIX:
#ifdef DEBUG_ENABLE
            Serial.println("nz mix");
#endif       
            mixer1.gain(3,((float)val)/127.0 );
            break;



        case CTRL_MASTER_FREQ: 
            Serial.println("setting note to ");
            float f = midiLookUp[val];


            Serial.println("setting note to ");
            Serial.println(val);
            Serial.println(f);

            setAllOscFreq(midiLookUp[val]);
            allNoteOn();
            delay(10);
            allNoteOff();            
            break;
            
        default:
#ifdef DEBUG_ENABLE
            Serial.println("default switch");
            Serial.println(val);
            Serial.println(f);
#endif       
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

void allNoteOn(){
    envelope1.noteOn();
    //envelope2.noteOn();
}
void allNoteOff(){
    envelope1.noteOff();
    //envelope2.noteOff();
}


void setup() {
    // initialize serial communications at 9600 bps:
    //
#ifdef DEBUG_ENABLE
    Serial.begin(9600);
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
    
    envelope1.delay(0);
    envelope1.attack(0);
    envelope1.hold(0);
    envelope1.decay(100);
    envelope1.sustain(1.0);
    envelope1.release(700);

    //mixer2.gain(0 , 1.0);
    //mixer2.gain(1 , 0.0);
    //mixer2.gain(2 , 0.0);
    //mixer2.gain(3 , 0.0);

    //dc1.amplitude(1.0);

    //freeverbs1.roomsize(0.0);
    //freeverbs1.damping(1.0);

    //envelope2.sustain(1.0);

    initLookupTable();

    allNoteOn();
    delay(10);
    allNoteOff();
}


void loop() {
    usbMIDI.read();
}
