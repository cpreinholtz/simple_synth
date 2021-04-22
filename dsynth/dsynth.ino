#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     dcHatVcf;            //xy=405.2222328186035,518.5555763244629
AudioSynthNoiseWhite     noiseHat; //xy=457.00001525878906,392.3335394859314
AudioEffectEnvelope      envelopeHatVcf; //xy=575.2222747802734,490.5556354522705
AudioFilterStateVariable filterHatLp; //xy=720.222240447998,411.55559158325195
AudioFilterStateVariable filterHatHp; //xy=914.222282409668,417.5556335449219
AudioEffectEnvelope      envelopeHatAmp; //xy=1123.5557022094727,474.88896560668945
AudioMixer4              mixer1;         //xy=1371.3333435058594,438.66666412353516
AudioOutputAnalogStereo  dacs1;          //xy=1657.929084777832,391.76205253601074
AudioConnection          patchCord1(dcHatVcf, envelopeHatVcf);
AudioConnection          patchCord2(noiseHat, 0, filterHatLp, 0);
AudioConnection          patchCord3(noiseHat, 0, mixer1, 3);
AudioConnection          patchCord4(envelopeHatVcf, 0, filterHatLp, 1);
AudioConnection          patchCord5(filterHatLp, 0, filterHatHp, 0);
AudioConnection          patchCord6(filterHatHp, 2, envelopeHatAmp, 0);
AudioConnection          patchCord7(envelopeHatAmp, 0, mixer1, 0);
AudioConnection          patchCord8(mixer1, 0, dacs1, 0);
AudioConnection          patchCord9(mixer1, 0, dacs1, 1);
// GUItool: end automatically generated code

#include "common.h"
#include "cc_in.h"
#include "clk.h"

///////////////////////////////////////////////
//CONSTANTS
///////////////////////////////////////////////
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))
#define DEBUG_ENABLE
const int ledPin = 13;






///////////////////////////////////////////////
//CALLBACKS
///////////////////////////////////////////////
//with this scheme we get a new envelope every time a new note is hit,
//and the envelope realses only when that new note is released
void handleNoteOn(byte channel, byte note, byte velocity){
    Serial.println("note on");
}


void handleNoteOff(byte channel, byte note, byte velocity){
    Serial.println("note off");
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
    usbMIDI.setHandleControlChange(ccHandler);
    usbMIDI.setHandleNoteOn(handleNoteOn);
    usbMIDI.setHandleNoteOff(handleNoteOff);
    // initialize the digital pin as an output.
    pinMode(ledPin, OUTPUT);
    AudioMemory(400);
    
    initLookupTable();//common
    setDefaults();//cc in

}




void loop() {
    usbMIDI.read();
    checkTime();//clk
    //noiseHat.amplitude(1.0);
}
