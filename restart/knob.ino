#include "util.h"

float gVal;




pinkVoice

////////////////////////////////////////////////
//0.7
void setOsc1Amp(){
    dbg("Osc1Amp");
    dbg(gVal);
    mixerVoice1.gain(0, gVal);
}

//0.6
void setOsc1Shape(){
    dbg("Osc1Shape");
    dbg(gVal);
    dcOsc1Shape.amplitude(gVal);
}

//0.5
void setVcaVelocity(){
    dbg("VcaVelocity");
    dbg(gVal);

    
    //todo
}

//0.4
void setVcaAttack(){
    dbg("setVcaAttack");
    dbg(gVal);
    envelopeVoice1.attack(kEnvScale* gVal);
}

//0.3
void setVcaDecay(){
    dbg("setVcaDecay");
    dbg(gVal);
    envelopeVoice1.decay(kEnvScale* gVal);
}

//0.2
void setVcaSustain(){
    dbg("setVcaSustain");
    dbg(gVal);
    envelopeVoice1.sustain( gVal);
}

//0.1
void setVcaRelease(){
    dbg("setVcaRelease");
    dbg(gVal);
    envelopeVoice1.release(kEnvScale* gVal);
}


///////////////////////////////////////////////////


//4.1
void setOsc2Amp(){
    dbg("setOsc2Amp");
    dbg(gVal);
    //dcOsc2Shape.amplitude(gVal);
    mixerVoice1.gain(1,gVal)
}

//4.2
void setOsc2Shape(){
    dbg("Osc2Shape");
    dbg(gVal);
    dcOsc2Shape.amplitude(gVal);
}


//4.3
void setOsc2Detune(){
    dbg("setOsc2Detune");
    dbg(gVal);
    //dcOsc2Shape.amplitude(gVal); //todo
}

//4.4
void setGlide(){
    dbg("setGlide");
    dbg(gVal);
    //todo
}

//4.5
void setNoise(){
    dbg("noise");
    dbg(gVal);
    mixerVoice1.gain(2, gVal);
}




///////////////////////////////////////////


//2.7
void setVcfCutoff(){
    dbg("setVcfCutoff");
    dbg(gVal);
    filterVcf.frequency(10000.0*gVal);
}

//2.6
void setVdfResonance(){
    dbg("setVdfResonance");
    dbg(gVal);
    filterVcf.resonance(0.7+ 4.3*gVal);
}

//2.5
void setVcfAmmount(){
    dbg("setVcfAmmount");
    dbg(gVal);
    mixerVcf.gain(0,gVal);
}


//2.4
void setVcfVelocity(){
    dbg("setVcfVelocity");
    dbg(gVal);
    //todo
}

//2.3
void setVcfAttack(){
    dbg("setVcfAttack");
    dbg(gVal);
    envelopeVcf.attack(kEnvScale* gVal);
}

//2.2
void setVcfDecay(){
    dbg("setVcfDecay");
    dbg(gVal);
    envelopeVcf.decay(kEnvScale* gVal);
}

//2.1
void setVcfSustain(){
    dbg("setVcfSustain");
    dbg(gVal);
    envelopeVcf.sustain(gVal);
}

//2.0
void setVcfRelease(){
    dbg("setVcfRelease");
    dbg(gVal);
    envelopeVcf.release(kEnvScale* gVal);    
}

///////////////////////////////////////////

//4.0 
void setLfo1Ammount(){
    dbg("setLfo1Ammount");
    dbg(gVal);
    mixerVcf.gain(1,gVal);
}

//1.0
void setLfo1Speed(){
    dbg("setLfo1Speed");
    dbg(gVal);
    sineLfoVcf.frequency(40.0*gVal);
}


//3.1
void setLfo2Ammount(){
    dbg("setLfo2Ammount");
    dbg(gVal); //todo
}

//1.1
void setLfo2Speed(){
    dbg("setLfo2Speed");
    dbg(gVal);//todo
}

////////////////////////////////////////////
//3.0
void setBcRate(){
    dbg("setBcRate");
    dbg(gVal);
    bitcrusher1.sampleRate(44000.0*(1.0-gVal));
}
//0.0
void setBcDepth(){
    dbg("setBcDepth");
    dbg(gVal);
    bitcrusher1.sampleRate((int)(16*(1.0-gVal)));
}
//1.7
void setBcMix(){
    dbg("setBcMix");
    dbg(gVal);
    ampBc.gain(gVal);
}
//1.6
void setBcPan(){
    dbg("setBcPan");
    dbg(gVal);
    mixerFxL.gain(2,1.0-gVal);
    mixerFxR.gain(2,gVal);
}

////////////////////////////////////////////
//1.5
void setRvbRate(){
    dbg("setRvbRate");
    dbg(gVal);
    freeverbs1.roomsize(1.0-gVal);
}
//1.4
void setRvbDepth(){
    dbg("setRvbDepth");
    dbg(gVal);
    freeverbs1.damping(1.0-gVal);
}
//1.3
void setRvbMix(){
    dbg("setRvbMix");
    dbg(gVal);
    ampRvb.gain(gVal);
}
//1.2
void setRvbPan(){
    dbg("setRvbPan");
    dbg(gVal);
    mixerFxL.gain(1,1.0-gVal);
    mixerFxR.gain(1,gVal);
}

////////////////////////////////////////////
//3.7
void setDlyRate(){
    dbg("setDlyTime");
    dbg(gVal);
    delay1.delay(0,2000.0*gVal);
}
//3.6
void setDlyDepth(){
    dbg("setDlyDepth");
    dbg(gVal);
    mixerDelayFb.gain(3, gval);
}
//3.5
void setDlyMix(){
    dbg("setDlyMix");
    dbg(gVal);
    ampDly.gain(gVal);
}
//3.4
void setDlyPan(){
    dbg("setDlyPan");
    dbg(gVal);
    mixerFxL.gain(0,1.0-gVal);
    mixerFxR.gain(0,gVal);
} 


//3.3
void setDryMix(){
    dbg("setDryMix");
    dbg(gVal);
    ampDry.gain(gVal);
}
//3.2
void setDryPan(){
    dbg("setDryPan");
    dbg(gVal);
    mixerFxL.gain(3,1.0-gVal);
    mixerFxR.gain(3,gVal);
} 

////////////////////////////////////////////



tHandlerList myKnobs = {

//0.0 - 0.7
setBcDepth, setVcaRelease, setVcaSustain, setVcaDecay ,setVcaAttavk, setVcaVelocity, setOsc1Shape, setOsc1Amp,

//1.0 - 1.7
setLfo1Speed, setLfo2Speed, setRvbPan, setRvbMix, setRvbDepth, setRvbRate, setBcPan, setBcMix,

//2.0 - 2.7
setVcfRelease, setVcfSustain, setVcfDecay, setVcfAttack, setVcfVelocity, setVcfAmmount, setVdfResonance, setVcfCutoff,

//3.0 - 3.7
setBcRate, setLfo2Ammount, setDryPan, setDryMix, setDlyPan, setDlyMix, setDlyDepth, setDlyRate,

//4.0 - 4.4
setLfo1Ammount, setOsc2Amp, setOsc2Shape, setOsc2Detune, setGlide
};
