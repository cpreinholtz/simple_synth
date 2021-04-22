
/*


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noiseHat; //xy=270.3333320617676,749.000205039978
AudioSynthWaveformDc     dcHatVcf;            //xy=306.33332443237305,886.3333206176758
AudioSynthSimpleDrum     drum2; //xy=419.66680908203125,440.66668128967285
AudioSynthNoiseWhite     noise1;         //xy=422.6666488647461,498.6666831970215
AudioSynthNoiseWhite     noise3; //xy=440.3333549499512,208.00000619888306
AudioSynthSimpleDrum     drum1;          //xy=441.2698783874512,341.76197147369385
AudioSynthSimpleDrum     drum3; //xy=442.3333549499512,254.00000762939453
AudioEffectEnvelope      envelopeHatVcf; //xy=476.33336639404297,858.3333797454834
AudioSynthNoiseWhite     noise2;         //xy=503.6667900085449,613.6666669845581
AudioAmplifier           ampDrum2; //xy=573.3332481384277,439.66668128967285
AudioFilterStateVariable filterHatLp; //xy=621.3333320617676,779.3333358764648
AudioFilterStateVariable filter1;        //xy=635.3333282470703,201.0000057220459
AudioAmplifier           ampDrum1;           //xy=651.3336563110352,342.6666955947876
AudioEffectEnvelope      envelopeD3;      //xy=681.6666259765625,602.6666650772095
AudioEffectDigitalCombine combine1;       //xy=738.6666641235352,444.66668224334717
AudioFilterStateVariable filterHatHp; //xy=815.3333740234375,785.3333778381348
AudioMixer4              mixerSnare; //xy=879.3333129882812,195
AudioEffectEnvelope      envelopeHatAmp; //xy=1024.6667938232422,842.6667098999023
AudioMixer4              mixer64; //xy=1206.3333358764648,252.00009155273438
AudioMixer4              mixer6; //xy=1404.6668243408203,450.0000114440918
AudioOutputAnalogStereo  dacs1;          //xy=1657.929084777832,391.76205253601074
AudioConnection          patchCord1(noiseHat, 0, filterHatLp, 0);
AudioConnection          patchCord2(dcHatVcf, envelopeHatVcf);
AudioConnection          patchCord3(drum2, ampDrum2);
AudioConnection          patchCord4(noise1, 0, combine1, 1);
AudioConnection          patchCord5(noise3, 0, filter1, 0);
AudioConnection          patchCord6(drum1, ampDrum1);
AudioConnection          patchCord7(drum3, 0, mixerSnare, 3);
AudioConnection          patchCord8(envelopeHatVcf, 0, filterHatLp, 1);
AudioConnection          patchCord9(noise2, envelopeD3);
AudioConnection          patchCord10(ampDrum2, 0, combine1, 0);
AudioConnection          patchCord11(filterHatLp, 0, filterHatHp, 0);
AudioConnection          patchCord12(filter1, 0, mixerSnare, 0);
AudioConnection          patchCord13(filter1, 1, mixerSnare, 1);
AudioConnection          patchCord14(filter1, 2, mixerSnare, 2);
AudioConnection          patchCord15(ampDrum1, 0, mixer64, 1);
AudioConnection          patchCord16(envelopeD3, 0, mixer64, 3);
AudioConnection          patchCord17(combine1, 0, mixer64, 2);
AudioConnection          patchCord18(filterHatHp, 2, envelopeHatAmp, 0);
AudioConnection          patchCord19(mixerSnare, 0, mixer64, 0);
AudioConnection          patchCord20(envelopeHatAmp, 0, mixer6, 1);
AudioConnection          patchCord21(mixer64, 0, mixer6, 0);
AudioConnection          patchCord22(mixer6, 0, dacs1, 0);
AudioConnection          patchCord23(mixer6, 0, dacs1, 1);
// GUItool: end automatically generated code







///////////////////////////////////////////////
//Drum
///////////////////////////////////////////////
void ctrlDrum1Amplitude(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    ampDrum1.gain( m127(lastVal) );
}  
void ctrlDrum1Frequency(){
    static byte lastVal =20;
    lastVal = getNext(lastVal);
    drum1.frequency( midiLookUp[lastVal]);
    
}
void ctrlDrum1Mod(){
    static byte lastVal =82;
    lastVal = getNext(lastVal);
    d1M = 1+ (byte) ( (float)stepsPerEpoch*(1.0-m127(lastVal))); 

    Serial.println("d1M");     
    Serial.println(d1M);     
}

void ctrlDrum1Offset(){
    static byte lastVal =32;
    lastVal = getNext(lastVal);
    d1O = (byte) ( (float)stepsPerEpoch*m127(lastVal));  
    Serial.println("d1O");     
    Serial.println(d1O);  
}


void ctrlDrum2Amplitude(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    ampDrum2.gain( m127(lastVal) );
    noise1.amplitude(m127(lastVal));
}  
void ctrlDrum2Frequency(){
    static byte lastVal =20;
    lastVal = getNext(lastVal);
    drum2.frequency( midiLookUp[lastVal]);
    
}
void ctrlDrum2Mod(){
    static byte lastVal =107;
    lastVal = getNext(lastVal);
    d2M = 1+ (byte) ( (float)stepsPerEpoch*(1.0-m127(lastVal)));        
}

void ctrlDrum2Offset(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    d2O = (byte) ( (float)stepsPerEpoch*m127(lastVal));    
}



void ctrlDrum3Amplitude(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    noise2.amplitude(m127(lastVal));
}  

void ctrlDrum3Length(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelopeD3.attack(10*m127(lastVal) );
    envelopeD3.decay(100*m127(lastVal) );
}



void ctrlDrum3Mod(){
    static byte lastVal =66;
    lastVal = getNext(lastVal);
    d3M = 1+ (byte) ( (float)stepsPerEpoch*(1.0-m127(lastVal)));       
}

void ctrlDrum3Offset(){
    static byte lastVal =23;
    lastVal = getNext(lastVal);
    d3O = (byte) ( (float)stepsPerEpoch*m127(lastVal));    
}


















































void ctrlChange(byte ch, byte ctrl, byte val){
#ifdef DEBUG_ENABLE
    Serial.println("ctrl change hit");
    Serial.println(ctrl);
    Serial.println(val);
#endif
    
    switch (ctrl) {
///////////////////////////////////////////////
//OSCILLATOR MIX
///////////////////////////////////////////////
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
            
        case CTRL_OSC1_MIX:
            mixer13.gain(0,((float)val)/127.0 );
            break;

            
///////////////////////////////////////////////
//OSCILLATOR MIX 2
///////////////////////////////////////////////
        case CTRL_2SAW_MIX:
            mixer11.gain(0,((float)val)/127.0 );
            break;      
        case CTRL_2SQ_MIX:
            mixer11.gain(1,((float)val)/127.0 );
            break;      
        case CTRL_2SIN_MIX:
            mixer11.gain(2,(2.0*(float)val)/127.0 );
            break;      
        case CTRL_2NOISE_MIX:
            mixer11.gain(3,((float)val)/127.0 );
            break;
            
        case CTRL_OSC2_MIX:
            mixer13.gain(1,((float)val)/127.0 );
            break;

        case CTRL_DETUNE_FREQ:          
            kDetune = val;  
            setAllOsc2Freq(getFreqFromDetune());
            break;          

            
            
///////////////////////////////////////////////
//VCA
///////////////////////////////////////////////
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

///////////////////////////////////////////////
//VCA 2
///////////////////////////////////////////////
        case CTRL_2VCA_A:
            envelope3.attack( 2000 * ((float)val)/127.0 );
            break;      
        case CTRL_2VCA_D:
            envelope3.decay(  2000 * ((float)val)/127.0 );
            break;      
        case CTRL_2VCA_S:
            envelope3.sustain(((float)val)/127.0 );
            break;      
        case CTRL_2VCA_R:
            envelope3.release( 2000 * ((float)val)/127.0 );
            break;

///////////////////////////////////////////////
//FILTER
///////////////////////////////////////////////
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


///////////////////////////////////////////////
//FILTER 2
///////////////////////////////////////////////
        case CTRL_2FILT_CUTOFF:
            filter2SetFreqFromVal(val);
            break;
        case CTRL_2VCF_AMNT:
            filter2SetAmmountFromVal(val);
            break;     
        case CTRL_2VCF_A:
            envelope2.attack( 2000 * ((float)val)/127.0 );
            break;      
        case CTRL_2VCF_D:
            envelope2.decay(  2000 * ((float)val)/127.0 );
            break;      
        case CTRL_2VCF_S:
            envelope2.sustain(((float)val)/127.0 );
            break;      
        case CTRL_2VCF_R:
            envelope2.release( 2000 * ((float)val)/127.0 );
            break;

///////////////////////////////////////////////
//EFFECTS DRY
///////////////////////////////////////////////
        case CTRL_FX_DRY_MIX_L:
            mixer2.gain(0, (float)val/127.0);
            break;
        case CTRL_FX_DRY_MIX_R:
            mixer4.gain(0, (float)val/127.0);
            break;


///////////////////////////////////////////////
//EFFECTS REVERB
///////////////////////////////////////////////
        case CTRL_FX_REVERB_SIZE:
            freeverbs1.roomsize((float)val/127.0);
            break;
        case CTRL_FX_REVERB_DAMP:
            freeverbs1.damping((float)val/127.0);
            break;            
        case CTRL_FX_REVERB_MIX_L:
            mixer2.gain(1, (float)val/127.0);
            break;
        case CTRL_FX_REVERB_MIX_R:
            mixer4.gain(1,(float)val/127.0);
            break;
            



///////////////////////////////////////////////
//EFFECTS BC
///////////////////////////////////////////////
   
        case CTRL_FX_BC_MIX_L:
            mixer2.gain(2, (float)val/127.0);
            break;
        case CTRL_FX_BC_MIX_R:
            mixer4.gain(2, (float)val/127.0);
            break;     
        case CTRL_FX_BC_BITS:
            bitcrusher1.bits( (int)(16*(float)val/127.0));
            break;
        case CTRL_FX_BC_RATE:
            bitcrusher1.sampleRate( (int)(44000*(float)val/127.0) );
            break;

///////////////////////////////////////////////
//EFFECTS Delay
///////////////////////////////////////////////
            

        case CTRL_FX_DLYMIX_L:
            mixer2.gain(3, (float)val/127.0);
            break;
        case CTRL_FX_DLYMIX_R:
            mixer4.gain(3, (float)val/127.0);
            break;

        case CTRL_FX_DLY1_S:
            delay1.delay(0, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY1_L:
            mixer5.gain(0, (float)val/127.0);
            break;
        case CTRL_FX_DLY1_R:
            mixer7.gain(0, (float)val/127.0);
            break;

        case CTRL_FX_DLY2_S:
            delay1.delay(1, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY2_L:
            mixer5.gain(1, (float)val/127.0);
            break;
        case CTRL_FX_DLY2_R:
            mixer7.gain(1, (float)val/127.0);
            break;

        case CTRL_FX_DLY3_S:
            delay1.delay(2, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY3_L:
            mixer5.gain(2, (float)val/127.0);
            break;
        case CTRL_FX_DLY3_R:
            mixer7.gain(2, (float)val/127.0);
            break;

        case CTRL_FX_DLY4_S:
            delay1.delay(3, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY4_L:
            mixer5.gain(3, (float)val/127.0);
            break;
        case CTRL_FX_DLY4_R:
            mixer7.gain(3, (float)val/127.0);
            break;

        case CTRL_FX_DLY5_S:
            delay1.delay(4, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY5_L:
            mixer6.gain(0, (float)val/127.0);
            break;
        case CTRL_FX_DLY5_R:
            mixer8.gain(0, (float)val/127.0);
            break;

        case CTRL_FX_DLY6_S:
            delay1.delay(5, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY6_L:
            mixer6.gain(1, (float)val/127.0);
            break;
        case CTRL_FX_DLY6_R:
            mixer8.gain(1, (float)val/127.0);
            break;

        case CTRL_FX_DLY7_S:
            delay1.delay(6, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY7_L:
            mixer6.gain(2, (float)val/127.0);
            break;
        case CTRL_FX_DLY7_R:
            mixer8.gain(2, (float)val/127.0);
            break;

        case CTRL_FX_DLY8_S:
            delay1.delay(7, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY8_L:
            mixer6.gain(3, (float)val/127.0);
            break;
        case CTRL_FX_DLY8_R:
            mixer8.gain(3, (float)val/127.0);
            break;



///////////////////////////////////////////////
//LFO
///////////////////////////////////////////////
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
            
///////////////////////////////////////////////
//LFO 2
///////////////////////////////////////////////
        case CTRL_2LFO_A:
            sine2.amplitude(((float)val)/127.0);
            break;
        case CTRL_2LFO_F:
            sine2.frequency(60 * ((float)val)/127.0);
            break;     
                        
        case CTRL_2LFO_FMOD1:
            amp6.gain(((float)val)/127.0 );
            break;  
        case CTRL_2LFO_FMOD2:
            amp7.gain(((float)val)/127.0 );
            break;    
        case CTRL_2LFO_FMOD3:
            amp8.gain(((float)val)/127.0 );
            break;    
            
        case CTRL_2LFO_SMOD2:
            amp9.gain(((float)val)/127.0 );
            break;    
                  
        case CTRL_2LFO_VCFMOD:
            mixer12.gain(1,((float)val)/127.0 );
            break; 
///////////////////////////////////////////////
//DEFAULT
///////////////////////////////////////////////
        default:
#ifdef DEBUG_ENABLE
            Serial.println("default switch");
#endif       
            break;
            
  }  
}

*/
