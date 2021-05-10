#ifndef POLLER_H
#define POLLER_H


#include <ADC.h>
#include <ADC_util.h>



class Handler{
    public:
        Handler(){
            firstRead(0.0);
        }

        void firstRead(float firstVal){
            mLastVal = firstVal;
        }

        bool isDifferent(float nextVal){
            if (abs(nextVal - mLastVal) > 0.05){
                return true;
            } else {
                return false;
            }
            
        }

        void handle(float nextVal){
            if (isDifferent(nextVal)){
                handleVirtual(nextVal);
                mLastVal = nextVal;
            }
        }
        
        virtual void handleVirtual(float nextVal); 

        
        
        float mLastVal;     
           
    private:

        
}

class Osc1AmpHandler: public Handler{
    public:
        handleVirtual(float nextVal){
            mixerVoice1.gain(0,nextVal)
        }
}





class Poller{
public:
    Poller(int inPin, int s8a, int s8b, int s8c, int s64a, int s64b, int s64c, bool isAnalog = True){
        kInPin = inPin;
        kS8a = s8a;
        kS8b = s8b;
        kS8c = s8c;
        kS64a = s64a;
        kS64b = s64b;
        kS64c = s64c;
        kIsAnalog = isAnalog;



        pinMode(kS8a, OUTPUT);
        pinMode(kS8b, OUTPUT);
        pinMode(kS8c, OUTPUT);
        pinMode(kS64a, OUTPUT);
        pinMode(kS64b, OUTPUT);
        pinMode(kS64c, OUTPUT);

        pinMode(kInPin, INPUT);

        if (kIsAnalog) {

            adc->adc0->setAveraging(16); // set number of averages
            adc->adc0->setResolution(16); // set bits of resolution
            adc->adc0->setConversionSpeed(ADC_CONVERSION_SPEED::MED_SPEED); // change the conversion speed
            adc->adc0->setSamplingSpeed(ADC_SAMPLING_SPEED::MED_SPEED); // change the sampling speed

        }



    };




  
  
  
private:

    //pins for digital outs and ins
    int  kS8a, kS8b, kS8c, kS64a, kD64b, kS64c, kInPin;
    bool kIsAnalog;
    ADC *adc = new ADC(); // adc object





};



#endif
