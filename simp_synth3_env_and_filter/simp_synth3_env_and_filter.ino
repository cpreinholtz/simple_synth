#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioAmplifier           amp4; //xy=60.000003814697266,302.50000381469727
AudioAmplifier           amp3; //xy=61.25,263.75000381469727
AudioAmplifier           amp5; //xy=61.25,343.75
AudioAmplifier           amp2; //xy=62.5,217.5
AudioAmplifier           amp1;           //xy=65.50000762939453,169.25000190734863
AudioSynthWaveformSine   sine1;          //xy=75.00000381469727,118.50000190734863
AudioSynthNoisePink      pink1;          //xy=221.00000381469727,378.7500009536743
AudioSynthWaveformModulated waveformMod3; //xy=242.25000381469727,302.00000381469727
AudioSynthWaveformModulated waveformMod1;   //xy=243.00000381469727,202.75000095367432
AudioSynthWaveformModulated waveformMod2; //xy=246.00000381469727,250.75000095367432
AudioSynthWaveformDc     dc1;            //xy=330.00000381469727,501.7500009536743
AudioMixer4              mixer1;         //xy=421.00000381469727,296.7500009536743
AudioEffectEnvelope      envelope2; //xy=484.00000381469727,440.7500009536743
AudioEffectEnvelope      envelope1;      //xy=512.0000038146973,200.75000095367432
AudioMixer4              mixer3; //xy=610,492.5
AudioFilterStateVariable filter1;        //xy=664.0000038146973,298.7500009536743
AudioEffectFreeverb      freeverb1;      //xy=773.0000038146973,369.7500009536743
AudioMixer4              mixer2; //xy=796.0000038146973,214.75000095367432
AudioOutputAnalog        dac1;           //xy=876.0000038146973,293.7500009536743
AudioConnection          patchCord1(amp4, 0, waveformMod2, 1);
AudioConnection          patchCord2(amp3, 0, waveformMod3, 0);
AudioConnection          patchCord3(amp5, 0, waveformMod3, 1);
AudioConnection          patchCord4(amp2, 0, waveformMod2, 0);
AudioConnection          patchCord5(amp1, 0, waveformMod1, 0);
AudioConnection          patchCord6(sine1, amp1);
AudioConnection          patchCord7(sine1, amp2);
AudioConnection          patchCord8(sine1, amp3);
AudioConnection          patchCord9(sine1, amp4);
AudioConnection          patchCord10(sine1, amp5);
AudioConnection          patchCord11(sine1, 0, mixer3, 1);
AudioConnection          patchCord12(pink1, 0, mixer1, 3);
AudioConnection          patchCord13(waveformMod3, 0, mixer1, 2);
AudioConnection          patchCord14(waveformMod1, 0, mixer1, 0);
AudioConnection          patchCord15(waveformMod2, 0, mixer1, 1);
AudioConnection          patchCord16(dc1, envelope2);
AudioConnection          patchCord17(mixer1, envelope1);
AudioConnection          patchCord18(envelope2, 0, mixer3, 0);
AudioConnection          patchCord19(envelope1, 0, filter1, 0);
AudioConnection          patchCord20(mixer3, 0, filter1, 1);
AudioConnection          patchCord21(filter1, 0, freeverb1, 0);
AudioConnection          patchCord22(filter1, 0, mixer2, 0);
AudioConnection          patchCord23(freeverb1, 0, mixer2, 1);
AudioConnection          patchCord24(mixer2, dac1);
// GUItool: end automatically generated code






///////////////////////////////////////////////
//CONSTANTS
///////////////////////////////////////////////

#define DEBUG_ENABLE

const byte CTRL_MASTER_FREQ = 99;


const byte CTRL_SAW_MIX = 100;
const byte CTRL_SQ_MIX = 101;
const byte CTRL_SIN_MIX = 102;
const byte CTRL_NOISE_MIX = 103;

const byte CTRL_FILT_CUTOFF = 104;
const byte CTRL_FILT_MIX = 105;

const byte CTRL_REVERB_SIZE = 106;
const byte CTRL_REVERB_DAMP = 107;
const byte CTRL_REVERB_MIX = 108;

const byte CTRL_VCA_A = 109;
const byte CTRL_VCA_D = 110;
const byte CTRL_VCA_S = 111;
const byte CTRL_VCA_R = 112;

const byte CTRL_VCF_A = 113;
const byte CTRL_VCF_D = 114;
const byte CTRL_VCF_S = 115;
const byte CTRL_VCF_R = 116;
const byte CTRL_VCF_AMNT = 117;


const byte CTRL_LFO_F = 118;
const byte CTRL_LFO_A = 119;
const byte CTRL_LFO_FMOD1 = 120;
const byte CTRL_LFO_FMOD2 = 121;
const byte CTRL_LFO_FMOD3 = 122;
const byte CTRL_LFO_SMOD2 = 123;
const byte CTRL_LFO_SMOD3 = 124;
const byte CTRL_LFO_VCFMOD = 125;

const float VCF_SCALE = 10000;
const int VCF_MAX = 127;

//lookup table
float midiLookUp[127];

///////////////////////////////////////////////
//globals
///////////////////////////////////////////////
byte lastNote=0;

byte lastValidVcfCutoff=0;
byte lastValidVcfAmmount=0;



///////////////////////////////////////////////
//Helper functions
///////////////////////////////////////////////
void setAllOscFreq(float f){    
    waveformMod1.frequency(f);
    waveformMod2.frequency(f);
    waveformMod3.frequency(f);
}


//AMMOUNT + CUTOFF cannot exceed MAX or filter gets noizy
void filterSetFreqFromVal(byte val){
    if ((int)val + (int) lastValidVcfAmmount > VCF_MAX) {
        val = VCF_MAX - lastValidVcfAmmount;
    }
    filter1.frequency(VCF_SCALE * (float)val / 127.0);
    lastValidVcfCutoff = val;
}

void filterSetAmmountFromVal(byte val){
    if ((int)val + (int) lastValidVcfCutoff > VCF_MAX) {
        val = VCF_MAX - lastValidVcfCutoff;
    }
    dc1.amplitude((float)val / 127.0);
    lastValidVcfAmmount = val;
}



///////////////////////////////////////////////
//CALLBACKS
///////////////////////////////////////////////


//with this scheme we get a new envelope every time a new note is hit,
//and the envelope realses only when that new note is released
void handleNoteOn(byte channel, byte note, byte velocity){
    Serial.println("note on");
    setAllOscFreq(midiLookUp[note]);
    envelope1.noteOn();
    envelope2.noteOn();
    lastNote = note;
}


void handleNoteOff(byte channel, byte note, byte velocity){
    Serial.println("note off");
    if (note == lastNote){
        envelope1.noteOff();
        envelope2.noteOff();
    }
}





void ctrlChange(byte ch, byte ctrl, byte val){
#ifdef DEBUG_ENABLE
    Serial.println("ctrl change hit");
    Serial.println(ctrl);
    Serial.println(val);
#endif
    
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

        case CTRL_VCA_A:
            envelope1.attack( 2000 * ((float)val)/127.0 );
            break;      
        case CTRL_VCA_D:
            envelope1.decay(  2000 * ((float)val)/127.0 );
            break;      
        case CTRL_VCA_S:
            envelope1.sustain(((float)val)/127.0 );
            break;      
        case CTRL_VCA_R:
            envelope1.release( 2000 * ((float)val)/127.0 );
            break;

            
        case CTRL_FILT_CUTOFF:
            filterSetFreqFromVal(val);
            break;
        case CTRL_VCF_AMNT:
            filterSetAmmountFromVal(val);
            break;     
        case CTRL_VCF_A:
            envelope2.attack( 2000 * ((float)val)/127.0 );
            break;      
        case CTRL_VCF_D:
            envelope2.decay(  2000 * ((float)val)/127.0 );
            break;      
        case CTRL_VCF_S:
            envelope2.sustain(((float)val)/127.0 );
            break;      
        case CTRL_VCF_R:
            envelope2.release( 2000 * ((float)val)/127.0 );
            break;

        case CTRL_REVERB_SIZE:
            freeverb1.roomsize((float)val/127.0);
            break;
        case CTRL_REVERB_DAMP:
            freeverb1.damping((float)val/127.0);
            break;            
        case CTRL_REVERB_MIX:
            mixer2.gain(1, (float)val/127.0);
            mixer2.gain(0,1.0- (float)val/127.0);
            break;

            
        case CTRL_LFO_A:
            sine1.amplitude(((float)val)/127.0);
            break;
        case CTRL_LFO_F:
            sine1.frequency(60 * ((float)val)/127.0);
            break;     
            
        case CTRL_LFO_FMOD1:
            amp1.gain(((float)val)/127.0 );
            break;  
        case CTRL_LFO_FMOD2:
            amp2.gain(((float)val)/127.0 );
            break;    
        case CTRL_LFO_FMOD3:
            amp3.gain(((float)val)/127.0 );
            break;    
            
        case CTRL_LFO_SMOD2:
            amp4.gain(((float)val)/127.0 );
            break;    
        case CTRL_LFO_SMOD3:
            amp5.gain(((float)val)/127.0 );
            break; 
                  
        case CTRL_LFO_VCFMOD:
            mixer3.gain(1,((float)val)/127.0 );
            break; 

            
        default:
#ifdef DEBUG_ENABLE
            Serial.println("default switch");
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



///////////////////////////////////////////////
//SETUP / LOOP
///////////////////////////////////////////////


void setup() {
    // initialize serial communications at 9600 bps:
    //
#ifdef DEBUG_ENABLE
    Serial.begin(9600);
#endif
    usbMIDI.setHandleControlChange(ctrlChange);
    usbMIDI.setHandleNoteOn(handleNoteOn);
    usbMIDI.setHandleNoteOff(handleNoteOff);
    AudioMemory(20);

    int default_freq = 200;
    float default_amp = .25;
    float default_pw = .15;
    
    waveformMod1.begin(default_amp,default_freq, WAVEFORM_SAWTOOTH);    
//    waveformMod1.frequency(default_freq);
//    waveformMod1.amplitude(default_amp);
//    waveformMod1.pulseWidth(default_pw);

    waveformMod2.begin(default_amp, default_freq, WAVEFORM_PULSE);    
//    waveformMod2.frequency(default_freq);
//    waveformMod2.amplitude(default_amp);
//    waveformMod2.pulseWidth(default_pw);

    waveformMod3.begin(default_amp, default_freq ,WAVEFORM_TRIANGLE_VARIABLE);    
//    waveformMod3.frequency(default_freq);
//    waveformMod3.amplitude(default_amp);
//    waveformMod3.pulseWidth(default_pw);
    

    pink1.amplitude(default_amp);

    mixer1.gain(0 , 1.0);
    mixer1.gain(1 , 1.0);
    mixer1.gain(2 , 1.0);
    mixer1.gain(3 , 1.0);
    
    envelope1.delay(0);
    envelope1.attack(0);
    envelope1.hold(0);
    envelope1.decay(100);
    envelope1.sustain(.5);
    envelope1.release(100);

    envelope2.delay(0);
    envelope2.attack(0);
    envelope2.hold(0);
    envelope2.decay(0);
    envelope2.sustain(1.0);
    envelope2.release(100);


    filter1.octaveControl(3);
    filterSetFreqFromVal(50);
    filterSetAmmountFromVal(0);


    mixer2.gain(0 , 1.0);
    mixer2.gain(1 , 0.0);
    mixer2.gain(2 , 0.0);
    mixer2.gain(3 , 0.0);

    mixer3.gain(0 , 1.0);
    mixer3.gain(1 , 0.0);
    mixer3.gain(2 , 0.0);
    mixer3.gain(3 , 0.0);

    //LFO
    sine1.frequency(1.0);
    sine1.amplitude(0.0);
    amp1.gain(0.0);
    amp2.gain(0.0);
    amp3.gain(0.0);
    amp4.gain(0.0);
    amp5.gain(0.0);


    initLookupTable();

}




void loop() {
    usbMIDI.read();
}
