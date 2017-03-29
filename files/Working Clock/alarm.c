
#include "alarm.h"
#include "main.h"
#include "glcd.h"
#include "rtc.h"
#include "types.h"

void AlarmMenu(void);
void AlarmCheck(void);
void AlarmScreenCustom(void);

void Alarm_1(void);
void Alarm_2(void);
void Alarm_3(void);
void Alarm_4(void);

void Sound(void);
void Sound2(void);

void AlarmScreenPreset(void);
void AlarmSundayPreset(void);
void AlarmFridayPreset(void);

const UINT8 cszAlarmMainMenu[7][20]= {"Preset Alarms", "Custom Alarms", "                 ", "              ", "      ", "     ", "Exit to Clock" };
const UINT8 cszPresetAlarms[7][20] = {"Sunday AM", "Friday PM", "     ", "     ", "     ", "     ", "Exit to Clock" };

void AlarmMenu(void)
{
	UINT8 y;
	PIN_TLED = 1; Vdelay_ms(200);
	PIN_TLED = 0; glcdClearScreen();
	for(y = 0; y < 7; y++)
	{
	glcdMoveTo(19, y+1);
	glcdWriteString((UINT8*)&(cszAlarmMainMenu[y][0]));
	}
	while(1)
	{
		if(A_HR_ON)
			{
			AlarmScreenPreset(); Vdelay_ms(100);
			}
		if(A_MIN_ON)
			{
			AlarmScreenCustom(); Vdelay_ms(100);
			}
		if(SWITCH_DOWN)
			{
			break;
			}
	}
Vdelay_ms(75); return;
}

void AlarmScreenPreset(void)
{
	UINT8 y;
	PIN_TLED = 1; Vdelay_ms(200);
	PIN_TLED = 0; glcdClearScreen();
	for(y = 0; y < 7; y++)
	{
	glcdMoveTo(19, y+1);
	glcdWriteString((UINT8*)&(cszPresetAlarms[y][0]));
	}
	while(1)
	{
		if(A_HR_ON)
			{
			AlarmSundayPreset(); Vdelay_ms(100);
			}
		if(A_MIN_ON)
			{
			AlarmFridayPreset(); Vdelay_ms(100);
			}
		if(SWITCH_DOWN)
			{
			break;
			}
	}
Vdelay_ms(75); return;
}

void AlarmSundayPreset(void)
{
 	PIN_TLED = 1; Vdelay_ms(200);
	PIN_TLED = 0; glcdClearScreen();
	glcdMoveTo(0, 0); glcdWriteString("Sunday Alarms");
		if(AlarmSunday == 1)
		{
		glcdMoveTo(85, 0); glcdWriteString("ON ");
		}
		if(AlarmSunday == 0)
		{
		glcdMoveTo(85, 0); glcdWriteString("OFF");
		}
	while(1)
	{
		if(A_DOWN_ON)
			{
			if(AlarmSunday == 1)
				{
			AlarmSunday = 0; glcdMoveTo(85, 0); glcdWriteString("OFF");	Vdelay_ms(150);
				}
			else
				{
			AlarmSunday = AlarmSunday++; glcdMoveTo(85, 0); glcdWriteString("ON "); Vdelay_ms(150);
				}
			}
		if(SWITCH_DOWN)
			{
			break;
			}
	}
Vdelay_ms(75); return;
}

void AlarmFridayPreset(void)
{
 	PIN_TLED = 1; Vdelay_ms(200);
	PIN_TLED = 0; glcdClearScreen();
	glcdMoveTo(0, 0); glcdWriteString("Friday Alarms");
		if(AlarmFriday == 1)
		{
		glcdMoveTo(85, 0); glcdWriteString("ON ");
		}
		if(AlarmFriday == 0)
		{
		glcdMoveTo(85, 0); glcdWriteString("OFF");
		}
	while(1)
	{
		if(A_DOWN_ON)
			{
			if(AlarmFriday == 1)
				{
			AlarmFriday = 0; glcdMoveTo(85, 0); glcdWriteString("OFF");	Vdelay_ms(150);
				}
			else
				{
			AlarmFriday++; glcdMoveTo(85, 0); glcdWriteString("ON "); Vdelay_ms(150);
				}
			}

		if(SWITCH_DOWN)
			{
			break;
			}
	}
Vdelay_ms(75); return;
}

void AlarmScreenCustom(void)
{
UINT8 PinAlarm1, PinAlarm2, PinAlarmTotal;
PinAlarm1 = 48;
PinAlarm2 = 49;
PinAlarmTotal = 1;
TimeOut2 = 0;
PIN_TLED = 1;
Vdelay_ms(200);
PIN_TLED = 0;
glcdClearScreen();
glcdMoveTo(25, 0); glcdWriteString("Select Alarm:");
glcdMoveTo(57, 3); glcdWriteChar(PinAlarm1);
glcdMoveTo(63, 3); glcdWriteChar(PinAlarm2);

while(1)
{
glcdMoveTo(57, 3);
glcdWriteChar(PinAlarm1);
glcdMoveTo(63, 3);
glcdWriteChar(PinAlarm2);

	if(A_UP_ON)
		{
		Vdelay_ms(150);
		PinAlarm2 = PinAlarm2 + 1;
		PinAlarmTotal = PinAlarmTotal + 1;
		if(PinAlarm2 > 57)
			{
			PinAlarm1 = PinAlarm1 + 1;
			PinAlarm2 = 48;
			}
		}

if(PinAlarmTotal > 24) //Total alarms
{
PinAlarm1 = 48;
PinAlarm2 = 49;
PinAlarmTotal = 1;
}
if(A_DAY_ON)
{
Vdelay_ms(100);
if(PinAlarmTotal == 1)
{
Alarm_1();
}
if(PinAlarmTotal == 2)
{
Alarm_2();
}

}

if(TimeOut2 == 100000) //adds a time out for a about a 1.5 mins to put in code
{
goto Exit;
}
TimeOut2 = TimeOut2 + 1;

}

Exit: ;
Vdelay_ms(75); return;
}

void Alarm_1(void)		
{
	UINT8 y, yb, yAhr, yAmin, yAday, yPM, yHr;
	PIN_TLED = 1; Vdelay_ms(200); PIN_TLED = 0;

	glcdClearScreen(); glcdMoveTo(0, 0); glcdWriteString("Custom Alarm 1");
		if(Alarm1 == 1)
		{
		glcdMoveTo(100, 0);	glcdWriteString("ON ");
		}
		if(Alarm1 == 0)
		{
		glcdMoveTo(100, 0);	glcdWriteString("OFF");
		}
	while(1)
		{

		yHr = rtc24to12Hour(Alarm1HR, &yPM); glcdMoveTo(104, 2); glcdDrawImage( (yPM?BMP_PM:BMP_AM) );
		glcdMoveTo(35, 2); yAhr = Alarm1HR >> 4; glcdDrawImage(yAhr);
		glcdMoveTo(49, 2); glcdDrawImage(Alarm1HR & 0x0f);
		glcdMoveTo(63, 2); glcdDrawImage(BMP_COLON);
		glcdMoveTo(70, 2); yAmin = Alarm1MIN >> 4; glcdDrawImage(yAmin);
		glcdMoveTo(84, 2); glcdDrawImage(Alarm1MIN & 0x0f);

		
		if(A_HR_ON)
			{
			y = (rtcBCDToDec(Alarm1HR));
			y++;
				if(y == 24)
				y = 00;
			Alarm1HR = (rtcDecToBCD(y));
			Vdelay_ms(100);
			}
		if(A_MIN_ON)
			{
			y = (rtcBCDToDec(Alarm1MIN));
			y++;
			if( y == 60)
			y = 00;
			Alarm1MIN = (rtcDecToBCD(y));
			Vdelay_ms(100);
			}

		if(A_DOWN_ON)
			{
			if(Alarm1 == 1)
				{
			Alarm1 = 0; glcdMoveTo(100, 0); glcdWriteString("OFF");	Vdelay_ms(150);
				}
			else
				{
			Alarm1++; glcdMoveTo(100, 0); glcdWriteString("ON "); Vdelay_ms(150);
				}
			}

		if(A_DAY_ON)
			{
			Alarm1DAY++; Vdelay_ms(150);
			}


		if(SWITCH_DOWN)
			{
			break;
			}

		}
Vdelay_ms(75);
TimeOut2 = 100000;
return;
}

void Alarm_2(void)
{

}

void Alarm_3(void)
{

}

void Alarm_4(void)
{

}





void AlarmCheck(void)
{
	if(AlarmSunday == 1)
	{
		if(AlarmDay == 7)	//Sunday
		{
	 	if(AlarmHR == 0x10 && AlarmMIN == 0x40 && AlarmSec == 0x00)
			{
		 	Sound();
			}
		if(AlarmHR == 0x10 && AlarmMIN == 0x45 && AlarmSec == 0x00)
			{
			 Sound();
			}
		}
	}

	if(AlarmFriday == 1)
	{
	if(AlarmDay == 5) //Friday
		{
	 if(AlarmHR == 0x18 && AlarmMIN == 0x55 && AlarmSec == 0x00)
		{
		 Sound();
		}
	if(AlarmHR == 0x19 && AlarmMIN == 0x00 && AlarmSec == 0x00)
		{
		 Sound();
		}
	if(AlarmHR == 0x19 && AlarmMIN == 0x40 && AlarmSec == 0x00)
		{
		 Sound();
		}
	if(AlarmHR == 0x19 && AlarmMIN == 0x45 && AlarmSec == 0x00)
		{
		 Sound();
		}
	if(AlarmHR == 0x20 && AlarmMIN == 0x10 && AlarmSec == 0x00)
		{
		 Sound();
		}
	if(AlarmHR == 0x20 && AlarmMIN == 0x15 && AlarmSec == 0x00)
		{
		 Sound();
		}
	}
}

	if(Alarm1 == 1)
	{	
		if(Alarm1DAY == AlarmDay && Alarm1HR == AlarmHR && Alarm1MIN == AlarmMIN && AlarmSec == 0x00)
		{
		Sound();
		}
	}




	if(AlarmDay == 7 && AlarmHR == 0x03 && AlarmMIN == 0x30 && AlarmSec == 0x00)    //Prototype alarm
		{
		Sound2();
		}

}

void Sound(void)
{
	PIN_TLED = 1; 
	ASONG = 1;
	Vdelay_ms(10);
	PIN_TLED = 0;
	ASONG = 0;
}

void Sound2(void)
{
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(0); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(0); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(1); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(1); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(2); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(2); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(3); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(3); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(4); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(4); ASONG = 0; PIN_TLED = 0;
 	PIN_TLED = 1; ASONG = 1; Vdelay_ms(5); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(5); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(6); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(6); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(7); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(7); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(8); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(8); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(9); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(9); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(10); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(10); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(11); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(11); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(12); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(12); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(13); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(13); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(14); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(14); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(15); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(15); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(16); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(16); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(17); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(17); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(18); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(18); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(19); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(19); ASONG = 0; PIN_TLED = 0;
	PIN_TLED = 1; ASONG = 1; Vdelay_ms(20); ASONG = 0; PIN_TLED = 0; Vdelay_ms(0); ASONG = 1; PIN_TLED = 1; Vdelay_ms(20); ASONG = 0; PIN_TLED = 0;

}