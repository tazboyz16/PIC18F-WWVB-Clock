#ifndef __ALARM_H__
#define __ALARM_H__

/* Define Ports */
#define A_UP         RD0                        //Menu Select UP
#define A_DOWN       RD1                        //Menu Select Down
#define A_HR         RD3                        //HR Increase
#define A_MIN        RD2                        //Min Increase
#define A_DAY        RD4                        //Day Increase

#define ASONG        LATD5                        //Alarm Output

#define A_UP_ON			(!A_UP)				//  ON is when Button is Pressed down
#define A_UP_OFF		(A_UP)
#define A_DOWN_ON		(!A_DOWN)
#define A_DOWN_OFF		(A_DOWN)
#define A_HR_ON			(!A_HR)
#define A_HR_OFF		(A_HR)
#define A_MIN_ON		(!A_MIN)
#define A_MIN_OFF		(A_MIN)
#define A_DAY_ON		(!A_DAY)
#define A_DAY_OFF		(A_DAY)

#define PIN_TLED    LATA0
#define PIN_SWITCH  RB2  
#define SWITCH_UP   (PIN_SWITCH)
#define SWITCH_DOWN (!PIN_SWITCH)	

unsigned char AlarmHR;
unsigned char AlarmMIN;
unsigned char AlarmDay;
unsigned char AlarmSec;		//used so alarm doesnt keep going off

extern char AlarmSunday = 1;
extern char AlarmFriday = 0;

extern char Alarm1 = 0;
extern char Alarm1DAY = 1;
extern char Alarm1HR = 0x00;
extern char Alarm1MIN = 0x00;


#endif /* __ALARM_H__ */
