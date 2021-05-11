#ifndef TIMER_H
#define TIMER_H




class Timer{

public:

    Timer(unsigned long periodMicros){

        //setPeriodMicros(periodMicros);
        //startTick();
        
    }




    void setPeriodMicros(unsigned long periodMicros){
        mPeriodMicros =  periodMicros;        
    }

    
    void startTick(){
        mStartedMicros =  micros();        
    }

    bool epochDone(){
        unsigned long currentMicros = micros();
        if (currentMicros - mStartedMicros >mPeriodMicros ){
            return true;
        } else {
            return false;
        }
    }

    bool pollAndReset(){
        bool isDone = epochDone();
        if (isDone){
            startTick();
        }
        return isDone;
    }


    
    unsigned long mPeriodMicros;
    unsigned long mStartedMicros;

private:

};



#endif
