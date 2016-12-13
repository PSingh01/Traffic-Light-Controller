#include <project.h>
#include <stdbool.h> 

int main()
{
    enum states { // Declaration of states
        NSGreen,
        NSYellow,
        AllRed,
        WGreen,
        WYellow,
        EGreen,
        EYellow,
        NASAGreen,
        NASAYellow,
        SAGreen,
        SSAGreen,
        SSAYellow,
        SGreen,
    }; enum states1{
        TNModeBlinkOn,
        TNModeBlinkOff
    };
  
    
    int state2 = 0, state3 = 0; // state2 will hold the count for the states
       
    enum states state = NSGreen;    //Defining the intial state
    enum states1 state1 = TNModeBlinkOn;
    
    for(;;){       
    if(!TLCMode_Read()){
        if (state2 == 15) state2 = 0;
        switch (state) {
            case NSGreen:
                NGreen_Write(1), NYellow_Write(0), NRed_Write(0);
                SGreen_Write(1), SYellow_Write(0), SRed_Write(0);
                WGreen_Write(0), WYellow_Write(0), WRed_Write(1);
                EGreen_Write(0), EYellow_Write(0), ERed_Write(1);
                NAGreen_Write(0), NAYellow_Write(0), NARed_Write(1);
                SAGreen_Write(0), WYellow_Write(0), WRed_Write(1);
                if(state2 == 0)
                    state = NSYellow;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    NYellow_Write(1),NGreen_Write(0);
                    SYellow_Write(1), SGreen_Write(0);
                    CyDelay(3000);
                    NRed_Write(1),NYellow_Write(0);
                    SRed_Write(1), SYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                break;
            case NSYellow:
                CyDelay (10000);                                              
                NGreen_Write(0), NYellow_Write(1);
                SGreen_Write(0), SYellow_Write(1);
                WRed_Write(1);
                ERed_Write(1);
                NARed_Write(1);
                SARed_Write(1);
                if(state2 == 1)
                    state = AllRed;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    NRed_Write(1),NYellow_Write(0);
                    SRed_Write(1), SYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                CyDelay (3000);
                break;
            case AllRed:  
                
                NYellow_Write(0), NRed_Write(1);
                SYellow_Write(0), SRed_Write(1);
                WYellow_Write(0), WRed_Write(1);
                EYellow_Write(0), ERed_Write(1);
                NARed_Write(1);
                SARed_Write(1);
                if(state2 == 2)
                    state = WGreen;
                if((state2 == 5) && (ESensor_Read()))
                state = EGreen;
                if(((state2 == 5) && (!ESensor_Read())) || ((state2 == 8) && (NASensor_Read()))){
                    state = NASAGreen;
                    if(state2 != 8) state2 = 8;
                }if(((state2 == 5) && (!ESensor_Read()))|| ((state2 == 8) && (!NASensor_Read()))){
                    state = SSAGreen;
                    state2 = 11; 
                }if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(2000);
                    break;
                }break;
            case WGreen:
                CyDelay (1250);
                NRed_Write(1);
                SRed_Write(1);
                WRed_Write(0), WGreen_Write(1);
                ERed_Write(1);
                NARed_Write(1);
                SARed_Write(1);
                if(state2 == 3)
                    state = WYellow;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    WYellow_Write(1),WGreen_Write(0);
                    CyDelay(3000);
                    WRed_Write(1),WYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                break;
            case WYellow:
                CyDelay (7500);
                NRed_Write(1);
                SRed_Write(1);
                WGreen_Write(0), WYellow_Write(1);
                ERed_Write(1);
                NARed_Write(1);
                SARed_Write(1);
                if(state2 == 4)
                    state = AllRed;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    WRed_Write(1),WYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                CyDelay(2750);
                break;
            case EGreen:
                CyDelay (1000);
                NRed_Write(1);
                SRed_Write(1);
                WYellow_Write(0);
                WRed_Write(1);
                ERed_Write(0), EGreen_Write(1);
                NARed_Write(1);
                SARed_Write(1);
                if(state2 == 6)
                    state = EYellow;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    EYellow_Write(1),EGreen_Write(0);
                    CyDelay(3000);
                    ERed_Write(1),EYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                break;
            case EYellow:
                CyDelay (5000);
                NRed_Write(1);
                SRed_Write(1);
                WRed_Write(1);
                ERed_Write(0), EGreen_Write(0), EYellow_Write(1);
                NARed_Write(1);
                SARed_Write(1);
                if(state2 == 7)
                    state = AllRed;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    ERed_Write(1),EYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                CyDelay (2750);
                EYellow_Write(0);
                break;
            case NASAGreen:
                CyDelay(1000);
                NRed_Write(1);
                SRed_Write(1);
                WRed_Write(1);
                ERed_Write(1);
                NARed_Write(0), NAGreen_Write(1);
                SARed_Write(0), SAGreen_Write(1);
                if(state2 == 9)
                    state = NASAYellow;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    NAYellow_Write(1),NAGreen_Write(0);
                    SAYellow_Write(1), SAGreen_Write(0);
                    CyDelay(3000);
                    NARed_Write(1),NAYellow_Write(0);
                    SARed_Write(1), SAYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                break;
            case NASAYellow:
                CyDelay (4000);
                NRed_Write(1);
                SRed_Write(1);
                WRed_Write(1);
                ERed_Write(1);
                NAGreen_Write(0), NAYellow_Write(1);
                SAGreen_Write(0), SAGreen_Write(1);
                if(state2 == 10)
                    state = SAGreen;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    SAGreen_Write(0), SAYellow_Write(1);
                    CyDelay(3000);
                    NARed_Write(1),NAYellow_Write(0);
                    SARed_Write(1), SAYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                break;    
            case SAGreen:
                CyDelay (2500);
                NRed_Write(1);
                SRed_Write(1);
                WRed_Write(1);
                EYellow_Write(0), ERed_Write(1);
                NAYellow_Write(0), NARed_Write(1);
                SAYellow_Write(0), SAGreen_Write(1);
                if(state2 == 11)
                    state = SSAGreen;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    SAYellow_Write(1),SAGreen_Write(0);
                    CyDelay(3000);
                    SARed_Write(1), SAYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                break;
            case SSAGreen:
                CyDelay (1000);
                NRed_Write(1);
                SRed_Write(0), SGreen_Write(1);
                WRed_Write(1);
                ERed_Write(1);
                EYellow_Write(0), NARed_Write(1);
                SARed_Write(0), SAGreen_Write(1);
                if(state2 == 12)
                    state = SSAYellow;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    SAYellow_Write(1),SAGreen_Write(0);
                    SYellow_Write(1), SGreen_Write(0);
                    CyDelay(3000);
                    SARed_Write(1),SAYellow_Write(0);
                    SRed_Write(1), SYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                break;
            case SSAYellow:
                CyDelay (6000);
                NRed_Write(1);
                SGreen_Write(1);
                WRed_Write(1);
                ERed_Write(1);
                NARed_Write(1);
                SAGreen_Write(0), SAYellow_Write(1);
                if(state2 == 13)
                    state = SGreen;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    SYellow_Write(1), SGreen_Write(0);
                    CyDelay(3000);
                    SARed_Write(1),SAYellow_Write(0);
                    SRed_Write(1), SYellow_Write(0);
                    CyDelay(2000);
                    break;
                }
                break;   
            case SGreen:
                CyDelay (3000);
                NRed_Write(1);
                SGreen_Write(1);
                WRed_Write(1);
                ERed_Write(1);
                NARed_Write(1);
                SAYellow_Write(0),SARed_Write(1);
                if(state2 == 14)
                    state = NSGreen;
                if(TLCMode_Read()){
                    state2 = 0;
                    state = NSGreen; 
                    CyDelay(3000);
                    SYellow_Write(1), SGreen_Write(0);
                    CyDelay(3000);
                    SRed_Write(1), SYellow_Write(0);
                    CyDelay(1500);
                    break;
                }
                CyDelay(1000);
                break;   
        }
    state2++;
    
    } if (TLCMode_Read()){
                                                
        NGreen_Write(0), NYellow_Write(1), NRed_Write(0);
        SGreen_Write(0), SYellow_Write(1), SRed_Write(0);
        WGreen_Write(0), WYellow_Write(0), WRed_Write(1);
        EGreen_Write(0), EYellow_Write(0), ERed_Write(1);
        NAGreen_Write(0), NAYellow_Write(0), NARed_Write(1);
        SAGreen_Write(0), SAYellow_Write(0), SARed_Write(1);
        CyDelay(1500);
        NYellow_Write(0);
        SYellow_Write(0);
        WRed_Write(0);
        EYRed_Write(0);
        NARed_Write(0);
        SARed_Write(0);
        
        if(!TLCMode_Read()){
            NYellow_Write(1);
            SYellow_Write(1);
            WYellow_Write(1);
            EYellow_Write(1);
            NAYellow_Write(1);
            SAYellow_Write(1);
            CyDelay(3000);
            NRed_Write(1),NYellow_Write(0);
            SRed_Write(1), SYellow_Write(0);
            WRed_Write(1), WYellow_Write(0);
            ERed_Write(1), EYellow_Write(0);
            NARed_Write(1), NAYellow_Write(0);
            SARed_Write(1), SAYellow_Write(0);
            break;
        } CyDelay(1000);
                
    }
}}

/* [] END OF FILE */
