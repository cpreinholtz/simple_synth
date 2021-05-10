#include "voice.h"


//with this scheme we get a new envelope every time a new note is hit,
//and the envelope realses only when that new note is released
void handleNoteOn(byte channel, byte note, byte velocity){
    Serial.println("note on");
}


void handleNoteOff(byte channel, byte note, byte velocity){
    Serial.println("note off");
}
