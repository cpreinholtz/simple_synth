void setConstantSettings(){  
    //no set

    //Oscilators
    waveformMod1Osc1Voice1.begin(1.0, 200, WAVEFORM_SAWTOOTH);
    waveformMod2Osc1Voice1.begin(1.0, 200, WAVEFORM_SQUARE);
    waveformMod3Osc1Voice1.begin(1.0, 200, WAVEFORM_TRIANGLE);
    waveformMod4Osc1Voice1.begin(1.0, 200, WAVEFORM_SINE);
    
    waveformMod1Osc2Voice1.begin(1.0, 200, WAVEFORM_SAWTOOTH);
    waveformMod2Osc2Voice1.begin(1.0, 200, WAVEFORM_SQUARE);
    waveformMod3Osc2Voice1.begin(1.0, 200, WAVEFORM_TRIANGLE);
    waveformMod4Osc2Voice1.begin(1.0, 200, WAVEFORM_SINE);
    
    
    
    pinkVoice1.amplitude(1.0);
    
    mixerOsc1Voice1.gain(0, 1.0);
    mixerOsc1Voice1.gain(1, 0.0);
    mixerOsc1Voice1.gain(2, 0.0);
    mixerOsc1Voice1.gain(3, 0.0);
    
    mixerOsc2Voice1.gain(0, 0.0);
    mixerOsc2Voice1.gain(1, 1.0);
    mixerOsc2Voice1.gain(2, 0.0);
    mixerOsc2Voice1.gain(3, 0.0);
    
    mixerVoice1.gain(3, 0.0);
    
    mixerOsc2Voice1.gain(0, 1.0);
    mixerOsc2Voice1.gain(1, 1.0);
    mixerOsc2Voice1.gain(2, 1.0);
    mixerOsc2Voice1.gain(3, 1.0);
    
    ///////////////////////////////////////////////
    //VCA
    envelopeVoice1.delay( 0.0);
    envelopeVoice1.hold( 0.0);
    
    envelopeVoice1.delay( 0.0);
    envelopeVoice1.hold( 0.0);
    
    
    
    
    
    
    ///////////////////////////
    //Vcf
    
    ampVcf.gain(0.5);
    
    envelopeVcf.delay( 0.0);
    envelopeVcf.hold( 0.0);
    
    dcVcfEnvAmmount.amplitude(1.0);
    
    sineLfoVcf.amplitude(1.0);
    
    filterVcf.octaveControl(2.5);
    
    
    
    
    mixerLpassHpass.gain(0, 1.0);
    mixerLpassHpass.gain(1, 0.0);
    mixerLpassHpass.gain(2, 0.0);
    mixerLpassHpass.gain(3, 0.0);
    
    
    
    /////////////////////////////////////////
    //fx
    mixerDelayFb.gain(0, 1.0);
    mixerDelayFb.gain(1, 0.0);
    mixerDelayFb.gain(2, 0.0);
    
    mixerDelayFf.gain(0, 1.0);
    mixerDelayFf.gain(1, 1.0);
    mixerDelayFf.gain(2, 0.0);
    mixerDelayFf.gain(3, 0.0);
    
    /////////////////////////////////////////
    //final mix
    mixerFinalL.gain(0, 0.0);
    mixerFinalL.gain(1, 1.0);
    mixerFinalL.gain(2, 0.0);
    mixerFinalL.gain(3, 0.0);
    
    mixerFinalR.gain(0, 0.0);
    mixerFinalR.gain(1, 1.0);
    mixerFinalR.gain(2, 0.0);
    mixerFinalR.gain(3, 0.0);

}
