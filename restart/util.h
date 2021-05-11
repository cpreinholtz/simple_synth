#ifndef UTIL_H
#define UTIL_H





///////////////////////////////////
//type defines
///////////////////////////////////
//tCcHandlerList is a list of pointers to functions with no args and that return void
typedef void (*tHandlerList[]) ();









///////////////////////////////////
//util functions
///////////////////////////////////
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))
#define dbg(A) (Serial.println(A))


///////////////////////////////////
//externs
///////////////////////////////////
//extern ADC *adc; //in poll.ino





#endif
