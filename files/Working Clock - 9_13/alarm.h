#ifndef __ALARM_H__
#define __ALARM_H__

/* Define Ports */
#define A_UP         RD0                        //Menu Select UP
#define A_DOWN       RD1                        //Menu Select Down
#define A_HR         RD3                        //HR Increase
#define A_MIN         RD2                        //Min Increase
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

extern int Exit = 0;
extern int PinAlarm1 = 48;
extern int PinAlarm2 = 49;
extern int PinAlarmTotal = 1;


#define PIN_TLED    LATA0
#define PIN_SWITCH  RB2  
#define SWITCH_UP   (PIN_SWITCH)
#define SWITCH_DOWN (!PIN_SWITCH)

unsigned int Alarm;
unsigned int AlarmHR;
unsigned int AlarmMIN;
unsigned int AlarmDay;
unsigned int Alarm1;
unsigned int Alarm2;
unsigned int Alarm3;
unsigned int Alarm4;
unsigned int Alarm5;
unsigned int Alarm6;
unsigned int Alarm7;
unsigned int Alarm8;
unsigned int Alarm9;
unsigned int Alarm10;
unsigned int Alarm1HR;
unsigned int Alarm2HR;
unsigned int Alarm3HR;
unsigned int Alarm4HR;
unsigned int Alarm5HR;
unsigned int Alarm6HR;
unsigned int Alarm7HR;
unsigned int Alarm8HR;
unsigned int Alarm9HR;
unsigned int Alarm10HR;
unsigned int Alarm1MIN;
unsigned int Alarm2MIN;
unsigned int Alarm3MIN;
unsigned int Alarm4MIN;
unsigned int Alarm5MIN;
unsigned int Alarm6MIN;
unsigned int Alarm7MIN;
unsigned int Alarm8MIN;
unsigned int Alarm9MIN;
unsigned int Alarm10MIN;
unsigned Alarm1DAY;
unsigned int Alarm2DAY;
unsigned int Alarm3DAY;
unsigned int Alarm4DAY;
unsigned int Alarm5DAY;
unsigned int Alarm6DAY;
unsigned int Alarm7DAY;
unsigned int Alarm8DAY;
unsigned int Alarm9DAY;
unsigned int Alarm10DAY;

/* this might work adding Sound notes setup
define Note_A
define Note_B
*/

#endif /* __ALARM_H__ */
