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
AudioSynthWaveformDc     dc1;            //xy=175,438
AudioMixer4              mixer1;         //xy=266,233
AudioEffectEnvelope      envelope2; //xy=329,377
AudioEffectEnvelope      envelope1;      //xy=357,137
AudioFilterStateVariable filter1;        //xy=509,235
AudioEffectFreeverb      freeverb1;      //xy=618,306
AudioMixer4              mixer2; //xy=641,151
AudioOutputAnalog        dac1;           //xy=721,230
AudioConnection          patchCord1(pink1, 0, mixer1, 3);
AudioConnection          patchCord2(waveform3, 0, mixer1, 2);
AudioConnection          patchCord3(waveform1, 0, mixer1, 0);
AudioConnection          patchCord4(waveform2, 0, mixer1, 1);
AudioConnection          patchCord5(dc1, envelope2);
AudioConnection          patchCord6(mixer1, envelope1);
AudioConnection          patchCord7(envelope2, 0, filter1, 1);
AudioConnection          patchCord8(envelope1, 0, filter1, 0);
AudioConnection          patchCord9(filter1, 0, freeverb1, 0);
AudioConnection          patchCord10(filter1, 0, mixer2, 0);
AudioConnection          patchCord11(freeverb1, 0, mixer2, 1);
AudioConnection          patchCord12(mixer2, dac1);
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


const float VCF_SCALE = 10000;
const int VCF_MAX = 127;

//lookup table
float midiLookUp[127];

///////////////////////////////////////////////
byte lastNote=0;

byte lastValidVcfCutoff=0;
byte lastValidVcfAmmount=0;


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





void setAllOscFreq(float f){    
    waveform1.frequency(f);
    waveform2.frequency(f);
    waveform3.frequency(f);
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



    //freeverbs1.roomsize(0.0);
    //freeverbs1.damping(1.0);

    //envelope2.sustain(1.0);

    initLookupTable();

}






void loop() {
    usbMIDI.read();
}
