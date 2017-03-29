
#include "alarm.h"
#include "main.h"
#include "glcd.h"

void Alarm_1(void);
void Alarm_2(void);
void WriteDay(void);
void WriteAlarmScreen(void);


void AlarmMenu(void)
{
 WriteAlarmScreen();

	while(550)
		{
		glcdMoveTo(57, 3);
		glcdWriteChar(PinAlarm1);
		glcdMoveTo(63, 3);
		glcdWriteChar(PinAlarm2);
	

		if(A_UP_ON)
			{
			Vdelay_ms(500);
			PinAlarm2 = PinAlarm2 + 1;
			PinAlarmTotal = PinAlarmTotal + 1;
			if(PinAlarm2 > 57)
				{
				PinAlarm1 = PinAlarm1 + 1;
				PinAlarm2 = 48;
				}
			}

		if(PinAlarmTotal > 24)				//Total alarms
			{
			PinAlarm1 = 48;
			PinAlarm2 = 49;
			PinAlarmTotal = 1;
			}
		if(A_DAY_ON)
			{
			Vdelay_ms(400);
			if(PinAlarmTotal == 1)
				{
				Alarm_1();
				}
			if(PinAlarmTotal == 2)
				{
				Alarm_2();
				}

			}

		if(TimeOut == 100000)						//adds a time out for a about a 1.5 mins to put in code
			{
			goto Exit;
			}
		TimeOut = TimeOut + 1;
			
		}
	Exit: ;
}

void WriteAlarmScreen(void)
{
 	PIN_TLED = 1;
	Vdelay_ms(500);
	PIN_TLED = 0;
	glcdClearScreen();
	glcdMoveTo(25, 0);
	glcdWriteString("Select Alarm:");
	glcdMoveTo(57, 3);
	glcdWriteChar(PinAlarm1);
	glcdMoveTo(63, 3);
	glcdWriteChar(PinAlarm2);
}

void Alarm_1(void)
{
	PIN_TLED = 1;
	Vdelay_ms(500);
	PIN_TLED = 0;
	glcdClearScreen();
	glcdMoveTo(45, 0);
	glcdWriteString("Alarm 1");

	while(900)
		{
		glcdMoveTo(48, 3);
		glcdWriteChar(49);
		glcdMoveTo(54, 3);
		glcdWriteChar(50);
		glcdMoveTo(60, 3);
		glcdWriteString(":");
		glcdMoveTo(65, 3);
		glcdWriteChar(51);
		glcdMoveTo(71, 3);
		glcdWriteChar(52);

		if(A_HR_ON)
			{
			Vdelay_ms(400);
			}

		if(SWITCH_DOWN)
			{
			Vdelay_ms(400);
			Alarm1 = Alarm1 + 1;
			 if(Alarm1 > 1)
				{
				 Alarm1 = 0;
				}
			 if(Alarm1 == 0)
				{
				 glcdMoveTo(110, 0);
				 glcdWriteChar("OFF");
				}
			 if(Alarm1 == 1)
				{
				 glcdMoveTo(110, 0);
				 glcdWriteChar("   ");
				 glcdMoveTo(110, 0);
				 glcdWriteChar("ON");
				}

			}

		if(A_DAY_ON)
			{
			Vdelay_ms(400);
			Alarm1DAY = Alarm1DAY + 1;
			}
			
			

		}
		

}

void Alarm_2(void)
{

}

void WriteDay(void)
{

}

void Sound(void)
{
	 Tune: ;
	 ASONG = 1;
	 Vdelay_ms(2);
	 ASONG = 0;
	 Vdelay_ms(2);
	 ASONG = 1;
	 Vdelay_ms(2);
	 ASONG = 0;
	 Vdelay_ms(2);
	 Vdelay_ms(0);
	 Alarm = Alarm + 1;
	 if(Alarm < 500)
		{
		 goto Tune;
		}
			Vdelay_ms(6000);
		PIN_TLED = 1;
		Vdelay_ms(6000);
		PIN_TLED = 0;
		Vdelay_ms(6000);
		PIN_TLED = 1;
		Vdelay_ms(6000);
		PIN_TLED = 0;
		Vdelay_ms(6000);
		PIN_TLED = 1;
		Vdelay_ms(6000);
		PIN_TLED = 0;
		Vdelay_ms(6000);
		PIN_TLED = 1;
		Vdelay_ms(6000);
		PIN_TLED = 0;
		Vdelay_ms(6000);
		PIN_TLED = 1;
		Vdelay_ms(6000);
		PIN_TLED = 0;
		Vdelay_ms(6000);
		PIN_TLED = 1;
		Vdelay_ms(6000);
		PIN_TLED = 0;
		Vdelay_ms(5000);
		PIN_TLED = 1;
		Vdelay_ms(5000);
		PIN_TLED = 0;
		Vdelay_ms(5000);
		PIN_TLED = 1;
		Vdelay_ms(5000);
		PIN_TLED = 0;
		Vdelay_ms(5000);
		PIN_TLED = 1;
		Vdelay_ms(5000);
		PIN_TLED = 0; 
}

void AlarmCheck(void)
{
 

		if(39)
	{
	Alarm = 0;
	Sound();
	}

}