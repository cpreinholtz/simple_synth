////////////////////////////////////////////////////////////////
//Definitions
////////////////////////////////////////////////////////////////

#include "common.h"
#include "clk.h"
#include "hat.h"



////////////////////////////////////////////////////////////////
//Globals
////////////////////////////////////////////////////////////////
byte kCh;
byte kVal=0x40;
byte kCtrl;
int kPage =1;


////////////////////////////////////////////////////////////////
//Constants fo looping
////////////////////////////////////////////////////////////////

//how many knobs are on yer controller
const int CTRL_PER_PAGE = 16;
const int NUM_PADS = 8;


////////////////////////////////////////////////////////////////
//knobs and pages
////////////////////////////////////////////////////////////////
//CC ctrl per knob in order from left to right then top to bottom
int ctrlIndexed [CTRL_PER_PAGE] ={0x7, 0x4A, 0x47, 0x4C, 0x4d, 0x5D, 0x49, 0x4B, 
                        0x72, 0x12, 0x13, 0x10, 0x11, 0x5B, 0x4F, 0x48 };

                        
//CC ctrl per knob in order from left to right then top to bottom
int pageIndexed [NUM_PADS] ={0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D };
////////////////////////////////////////////////////////////////
//Helpers
////////////////////////////////////////////////////////////////




int getHelper(){
    int i;
    for ( i= 0; i < CTRL_PER_PAGE; i++){
        if (ctrlIndexed[i] == kCtrl){break;}
    }
    return i;
}

int getPage(){
    int i;
    for ( i= 0; i < NUM_PADS; i++){
        if (pageIndexed[i] == kCtrl){break;}
    }
    return i;
}







////////////////////////////////////////////////////////////////
//Pages
////////////////////////////////////////////////////////////////
void noop(){}

//tCcHandlerList is a list of pointers to functions with no args and that return void
typedef void (*tCcHandlerList[CTRL_PER_PAGE]) ();





//Handlers per knob in order from left to right then top to bottom
tCcHandlerList handleMePlease [] = {

    {
        ctrlBpm,                    noop,                       noop,                           noop,
        noop,                       noop,                       noop,                           noop,
        noop,                       noop,                       noop,                           noop,
        noop,                       noop,                       noop,                           noop
    },
    {
        ctrlHatMod,                 ctrlHatFirstStep,           ctrlHatLastStep,                ctrlHatPoly,
        ctrlHatNumStep,             ctrlHatOffset, noop,                       noop, 
        ctrlHatRes,                       ctrlHatLpCut,                       ctrlHatLpEnvAmnt,                           ctrlHatLpEnvDecay,
        ctrlHatHpCut,                       ctrlHatDecay,                       noop,                           noop,

    },
    {
        noop,                       noop,                       noop,                           noop,
        noop,                       noop,                       noop,                           noop,
        noop,                       noop,                       noop,                           noop,
        noop,                       noop,                       noop,                           noop
    }

};






void ccHandler(byte ch, byte ctrl, byte val){

    if (val == 0x40) {return;}    
    Serial.println(" cc");
    
    kCh = ch;    
    kCtrl = ctrl;
    kVal = val;


    int ctrlKnob = getHelper();
    if( ctrlKnob >=0 and ctrlKnob < CTRL_PER_PAGE ){
        Serial.println("ctrlKnob");
        Serial.println(ctrlKnob);
        //use the current page, and the ctrl Knob CC to call the correct handler
        handleMePlease[kPage][ctrlKnob]();           
    } else {
        int page = getPage();
        if( page >=0 and page < NUM_PADS and page < ARRAY_SIZE(handleMePlease) ){
            Serial.println("page");
            Serial.println(page);
            //switch the current page
            kPage = page;            
        } else {
            Serial.println("unrecognised cc");        
            Serial.println(kCtrl);
        }
    }    
}




void setDefaults(){
    kVal = 0x40;
    
    setHatDefaults();

    mixer1.gain(0,1.0);
    mixer1.gain(3,0.0);

    
    for (byte page = 0; page < ARRAY_SIZE(handleMePlease); page ++){
        for (int ctrlKnob = 0; ctrlKnob < CTRL_PER_PAGE; ctrlKnob++){
            handleMePlease[page][ctrlKnob]();
        }
    }   




   
    
}
