#include "common.h"

const int stepsPerQuater = 4;
const int quatersPerEpoch = 4;
const int stepsPerEpoch = stepsPerQuater * quatersPerEpoch;

int nextStep = 0;

//unsigned long microsPerEpoch = bpm * 60 *1000000;


//this is quater note bpm
unsigned long bpm = 30;


//double quartersPerSec = (double)bpm /60.0;
//double stepsPerSec = quartersPerSec * (double)stepsPerQuater;

//unsigned long microsPerSec = 1000000;
//unsigned long microsPerStep = microsPerSec / stepsPerSec ;
unsigned long microsPerStep =  (unsigned long) (1000000.0 / ( (double)bpm /60.0 * (double)stepsPerQuater ))  ;

unsigned long lastEpochMicros = micros();

void setBpm(int b){
    bpm = b;
    microsPerStep =  (unsigned long) (1000000.0 / ( (double)bpm /60.0 * (double)stepsPerQuater ))  ;
}


void checkTime(){
    unsigned long currentMicros = micros();

    if (currentMicros - lastEpochMicros >= (nextStep+1) * microsPerStep){
        Serial.println("step");
        Serial.println(nextStep);
        Serial.println(stepsPerEpoch);
        activateStep();
        nextStep = (nextStep + 1) % stepsPerEpoch;
        Serial.println(nextStep);
        if (nextStep==0){
            lastEpochMicros = currentMicros;
            
        }
    }
    
}

void activateStep(){
Serial.println("(nextStep+d1O) %d1M");
Serial.println( (nextStep+d1O) %d1M);
  digitalWrite(ledPin, HIGH);   // set the LED on
    if ( (nextStep) %stepsPerQuater ==0 ){
        digitalWrite(ledPin, HIGH);   // set the LED 
    } else {
        digitalWrite(ledPin, LOW);   // set the LED 
    }
  
    if ( (nextStep+d1O) %d1M ==0 ){
        drum1.noteOn();
    }
    
    if ( (nextStep+d2O) %d2M ==0 ){
        drum2.noteOn();
    }
    
    if ( (nextStep+d3O) %d3M ==0 ){
        envelopeD3.noteOn();
    }

}
