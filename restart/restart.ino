#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformModulated waveformMod3Osc2Voice1;   //xy=771.3333358764648,1141.0000114440918
AudioSynthWaveformModulated waveformMod4Osc2Voice1;   //xy=783.3333358764648,1212.000072479248
AudioSynthWaveformModulated waveformMod1Osc2Voice1;   //xy=787.3333206176758,1026.0000734329224
AudioSynthWaveformModulated waveformMod2Osc2Voice1;   //xy=789.3333511352539,1087.0000734329224
AudioSynthWaveformModulated waveformMod1Osc1Voice1;   //xy=796.0002517700195,794.3335084915161
AudioSynthWaveformModulated waveformMod2Osc1Voice1;   //xy=797.0002517700195,844.3335084915161
AudioSynthWaveformModulated waveformMod4Osc1Voice1;   //xy=801.3334808349609,942.000072479248
AudioSynthWaveformModulated waveformMod3Osc1Voice1;   //xy=804.0002517700195,890.3334159851074
AudioSynthNoisePink      pinkVoice1;          //xy=1052.6667366027832,1331.0000381469727
AudioMixer4              mixerOsc2Voice1;         //xy=1067.333480834961,1061.0000305175781
AudioMixer4              mixerOsc1Voice1;         //xy=1098.0003967285156,822.333438873291
AudioMixer4              mixerVoice1;         //xy=1327.3334121704102,994.0000267028809
AudioEffectEnvelope      envelopeVoice1;      //xy=1460.0000839233398,911.3333597183228
AudioMixer4              mixerAllVoices;         //xy=1804.515625,904.515625
AudioSynthWaveformDc     dcVcfEnvAmmount;            //xy=1806.0001220703125,1518.3333740234375
AudioEffectEnvelope      envelopeVcf;      //xy=1816.0002784729004,1405.3334169387817
AudioFilterStateVariable filterVcf;        //xy=1998,994.3333129882812
AudioMixer4              mixerVcf;         //xy=2018.0000953674316,1276.3333911895752
AudioSynthWaveformSine   sineLfoVcf;          //xy=2098.000114440918,1499.3333973884583
AudioMixer4              mixerLpassHpass;        //xy=2214.0000953674316,1128.3332691192627
AudioMixer4              mixerDelayFb;         //xy=2479,1432.3333129882812
AudioEffectDelay         delay1;         //xy=2642.00040435791,1436.3333234786987
AudioEffectBitcrusher    bitcrusher1;    //xy=3074.000476837158,1570.3333387374878
AudioEffectFreeverbStereo freeverbs1;     //xy=3096.0000495910645,1257.3332624435425
AudioMixer4              mixerFxL;         //xy=3320.0000495910645,1231.3333234786987
AudioMixer4              mixerFxR;         //xy=3512.000232696533,1444.3332681655884
AudioSynthSimpleDrum     drumSnare;          //xy=3622.0003662109375,1287.3334035873413
AudioSynthNoiseWhite     noiseSnare;         //xy=3644.000244140625,1336.3333129882812
AudioSynthNoiseWhite     noiseHat;         //xy=3665.0001220703125,1390.3332815170288
AudioSynthSimpleDrum     drumKick;          //xy=3754.0001220703125,1234.3333730697632
AudioAmplifier           ampSnare;       //xy=3844.0003700256348,1282.3333740234375
AudioFilterStateVariable filterHat; //xy=3895.5156745910645,1387.5156354904175
AudioAmplifier           ampKick;       //xy=3965.000244140625,1206.3334035873413
AudioEffectDigitalCombine combine1;       //xy=4001.0000495910645,1335.3333234786987
AudioEffectEnvelope      envelopeHAt;     //xy=4060.0001258850098,1390.3333129882812
AudioMixer4              mixerFinalL;    //xy=4320.000049591064,1112.333343744278
AudioMixer4              mixerFinalR;    //xy=4615.000049591064,1424.3333234786987
AudioOutputAnalogStereo  dacs1;          //xy=4696.000049591064,1244.3333234786987
AudioConnection          patchCord1(waveformMod3Osc2Voice1, 0, mixerOsc2Voice1, 2);
AudioConnection          patchCord2(waveformMod4Osc2Voice1, 0, mixerOsc2Voice1, 3);
AudioConnection          patchCord3(waveformMod1Osc2Voice1, 0, mixerOsc2Voice1, 0);
AudioConnection          patchCord4(waveformMod2Osc2Voice1, 0, mixerOsc2Voice1, 1);
AudioConnection          patchCord5(waveformMod1Osc1Voice1, 0, mixerOsc1Voice1, 0);
AudioConnection          patchCord6(waveformMod2Osc1Voice1, 0, mixerOsc1Voice1, 1);
AudioConnection          patchCord7(waveformMod4Osc1Voice1, 0, mixerOsc1Voice1, 3);
AudioConnection          patchCord8(waveformMod3Osc1Voice1, 0, mixerOsc1Voice1, 2);
AudioConnection          patchCord9(pinkVoice1, 0, mixerVoice1, 2);
AudioConnection          patchCord10(mixerOsc2Voice1, 0, mixerVoice1, 1);
AudioConnection          patchCord11(mixerOsc1Voice1, 0, mixerVoice1, 0);
AudioConnection          patchCord12(mixerVoice1, envelopeVoice1);
AudioConnection          patchCord13(envelopeVoice1, 0, mixerAllVoices, 0);
AudioConnection          patchCord14(mixerAllVoices, 0, filterVcf, 0);
AudioConnection          patchCord15(dcVcfEnvAmmount, envelopeVcf);
AudioConnection          patchCord16(envelopeVcf, 0, mixerVcf, 0);
AudioConnection          patchCord17(filterVcf, 0, mixerLpassHpass, 0);
AudioConnection          patchCord18(filterVcf, 2, mixerLpassHpass, 1);
AudioConnection          patchCord19(mixerVcf, 0, filterVcf, 1);
AudioConnection          patchCord20(sineLfoVcf, 0, mixerVcf, 1);
AudioConnection          patchCord21(mixerLpassHpass, 0, mixerDelayFb, 0);
AudioConnection          patchCord22(mixerDelayFb, delay1);
AudioConnection          patchCord23(delay1, 0, mixerDelayFb, 3);
AudioConnection          patchCord24(delay1, 0, freeverbs1, 0);
AudioConnection          patchCord25(delay1, 0, bitcrusher1, 0);
AudioConnection          patchCord26(delay1, 0, mixerFxL, 0);
AudioConnection          patchCord27(delay1, 0, mixerFxR, 0);
AudioConnection          patchCord28(bitcrusher1, 0, mixerFxR, 2);
AudioConnection          patchCord29(bitcrusher1, 0, mixerFxL, 2);
AudioConnection          patchCord30(freeverbs1, 0, mixerFxL, 1);
AudioConnection          patchCord31(freeverbs1, 1, mixerFxR, 1);
AudioConnection          patchCord32(mixerFxL, 0, mixerFinalL, 1);
AudioConnection          patchCord33(mixerFxR, 0, mixerFinalR, 1);
AudioConnection          patchCord34(drumSnare, ampSnare);
AudioConnection          patchCord35(noiseSnare, 0, combine1, 1);
AudioConnection          patchCord36(noiseHat, 0, filterHat, 0);
AudioConnection          patchCord37(drumKick, ampKick);
AudioConnection          patchCord38(ampSnare, 0, combine1, 0);
AudioConnection          patchCord39(filterHat, 0, envelopeHAt, 0);
AudioConnection          patchCord40(ampKick, 0, mixerFinalL, 0);
AudioConnection          patchCord41(ampKick, 0, mixerFinalR, 0);
AudioConnection          patchCord42(combine1, 0, mixerFinalL, 2);
AudioConnection          patchCord43(combine1, 0, mixerFinalR, 2);
AudioConnection          patchCord44(envelopeHAt, 0, mixerFinalL, 3);
AudioConnection          patchCord45(envelopeHAt, 0, mixerFinalR, 3);
AudioConnection          patchCord46(mixerFinalL, 0, dacs1, 0);
AudioConnection          patchCord47(mixerFinalR, 0, dacs1, 1);
// GUItool: end automatically generated code









///////////////////////////////////////////////
//SETUP / LOOP
///////////////////////////////////////////////


void setup() {

#ifdef DEBUG_ENABLE
    Serial.begin(9600);
#endif
    AudioMemory(400);




}




void loop() {
    usbMIDI.read();
}
