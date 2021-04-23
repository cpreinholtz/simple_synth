#include "common.h"
#include "octo.h"

const int stepsPerQuater = 4;
const int quatersPerEpoch = 4;
const int stepsPerEpoch = stepsPerQuater * quatersPerEpoch;

unsigned long nextStep = stepsPerEpoch;

//unsigned long microsPerEpoch = bpm * 60 *1000000;


//this is quater note bpm
unsigned long bpm = 30;


//double quartersPerSec = (double)bpm /60.0;
//double stepsPerSec = quartersPerSec * (double)stepsPerQuater;

//unsigned long microsPerSec = 1000000;
//unsigned long microsPerStep = microsPerSec / stepsPerSec ;
unsigned long microsPerStep =  (unsigned long) (1000000.0 / ( (double)bpm /60.0 * (double)stepsPerQuater ))  ;

unsigned long lastStepMicros = micros();





//CCIN BPM
void ctrlBpm(){
    static byte lastVal =20;
    lastVal = getNext(lastVal);
    setBpm( ( 40+(int)lastVal )  *2 );
}




void setBpm(int b){
    bpm = b;
    microsPerStep =  (unsigned long) (1000000.0 / ( (double)bpm /60.0 * (double)stepsPerQuater ))  ;
}


void checkTime(){
    unsigned long currentMicros = micros();

    if (currentMicros - lastStepMicros >= microsPerStep){

        activateStep();
        show();
        lastStepMicros = currentMicros;
        nextStep = nextStep + 1;
    }    
}




typedef void (*dHandlerList[]) ();
dHandlerList dHandles = {
    hatActiveStep,
    noop
};




void activateStep(){

    digitalWrite(ledPin, HIGH);   // set the LED on
    if ( (nextStep) %stepsPerQuater ==0 ){
        digitalWrite(ledPin, HIGH);   // set the LED 
    } else {
        digitalWrite(ledPin, LOW);   // set the LED 
    }
  
    for (int i=0; i< ARRAY_SIZE(dHandles); i++){
        dHandles[i]();        
    }

}
