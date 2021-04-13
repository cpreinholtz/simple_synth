
/*

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
