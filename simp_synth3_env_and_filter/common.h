//Always use include guards
#ifndef COMMON_H
#define COMMON_H




//common functions defined
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

#define dbg(A) ( Serial.println(A))
//#define dbg(A) ( )

//lookup table
extern float midiLookUp[127];




#endif 
