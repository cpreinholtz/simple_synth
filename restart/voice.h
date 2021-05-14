#ifndef VOICE_H
#define VOICE_H

#include "util.h"


extern float midiLookUp[128];
extern bool gNoteOn [128];
extern float glideTimeMillis;
extern float gLastFrequency;
extern float gDetune;



class Voice{
    public:
        Voice(AudioSynthWaveformModulated * w0, AudioSynthWaveformModulated * w1, AudioSynthWaveformModulated * w2, AudioSynthWaveformModulated * w3,
            AudioSynthWaveformModulated * w4, AudioSynthWaveformModulated * w5, AudioSynthWaveformModulated * w6, AudioSynthWaveformModulated * w7
        ){
            

            waves[0]=w0;
            waves[1]=w1;
            waves[2]=w2;
            waves[3]=w3;
            
            waves2[0]=w4;
            waves2[1]=w5;
            waves2[2]=w6;
            waves2[3]=w7;

            
            lastServiceMillis = 1;  
            noteOnMillis = 1;     
            targetFrequency =100.0;
            startFrequency = 99.0;
            currentFrequency = targetFrequency;
            gLastFrequency = 100.0;
            gDetune = 0.0;
        }

        void noteOn(byte channel, byte note, byte velocity){
            noteOnMillis = millis();
            setTargetFreqFromVal(note);

            startFrequency = gLastFrequency;

            gLastFrequency = targetFrequency;


            setStepFreuequency();
            
            
            
        }

        void setTargetFreqFromVal(byte val){
            targetFrequency = midiLookUp[val];
        }

        

        void setStepFreuequency(bool force = false){

            unsigned long currentMillis = millis();
            if (lastServiceMillis< currentMillis){
                float diffF = targetFrequency - startFrequency;
                unsigned long elapseMillis = currentMillis - noteOnMillis;                
                float stepFrequency ;
                if(diffF !=0.0 and glideTimeMillis >0.0 and elapseMillis < glideTimeMillis ){           
                    stepFrequency = diffF / (glideTimeMillis/(float)elapseMillis )+startFrequency ; 
                } else {
                    stepFrequency = targetFrequency;
                }
                
                setWaves(stepFrequency);   
                lastServiceMillis = currentMillis;
            }         
        }


        

        void setWaves(float f){
            for( unsigned int i =0; i<ARRAY_SIZE(waves); i++){
                waves[i]->frequency(f);
                waves2[i]->frequency(f * 0.5 * (1.0-gDetune));
            }
            currentFrequency = f;
        }



        unsigned long noteOnMillis;
        unsigned long lastServiceMillis;
        float startFrequency;
        float currentFrequency;
        float targetFrequency;
        AudioSynthWaveformModulated * waves[4];
        AudioSynthWaveformModulated * waves2[4];
        
};



#endif
