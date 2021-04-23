


//lookup table
float midiLookUp[127];






void initLookupTable(){
    float a = 440; // a is 440 hz...
    for (int x = 0; x < 127; ++x)
    {
        midiLookUp[x] = (a / 32.0) * ( pow(2,(((float)x - 9.0) / 12.0)) )  ;
#ifdef DEBUG_ENABLE
            Serial.println("setting note to ");
            Serial.println(x);
            Serial.println(midiLookUp[x]);
#endif           
        
    }
}





////////////////////////////////////////////////
//Map 127 to 0 to 1.0
////////////////////////////////////////////////

float m127(byte val){
    //return map(val, 0,127, 0.0 , 1.0);
    return  (  (float) val /127.0 );
}


////////////////////////////////////////////////
//Get the next by diffing from 0x40 (for arturia thing)
////////////////////////////////////////////////
byte getNext(byte lastVal){
    
    //abs value of differnce of kval and 0x40
    byte diff;
    byte nextVal;
    byte limit;

    Serial.println("lastVal");
    Serial.println(lastVal);

    if (kVal > 0x40){
        diff  = kVal - 0x40;
        limit = 127 - lastVal;
        
        if (limit > diff) {
            nextVal = lastVal + diff;
        } else {
            nextVal = lastVal + limit;
        }
        
    //kVal<40
    } else {
        diff  = 0x40 - kVal;
        limit = lastVal;        
        if (limit > diff) {
            nextVal = lastVal - diff;
        } else {
            nextVal = lastVal - limit;
        }
    }
    Serial.println(nextVal);
    return nextVal;
    
}
