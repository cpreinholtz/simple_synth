


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


void checkTime(){
    unsigned long currentMicros = micros();

    if (currentMicros - lastEpochMicros >= nextStep * microsPerStep){
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

        drum1.noteOn();

}
