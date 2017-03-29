/*****************************************************************************
 *  Main Module header
 *
 *
 ****************************************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__

#include <htc.h>
#include "types.h"
#include "rtc.h"

/* Useful Macros */
#define MAKEWORD(h, l)      (((UINT16)((UINT8)(h))) << (UINT8)8) | (UINT16)( ((UINT8)(l)) )
#define LOBYTE(w)           ((UINT8)(w))
#define HIBYTE(w)           ((UINT8)(((UINT16)(w) >> (UINT8)8) & 0xff))
#define LOWORD(l)           ((UINT16)(l))
#define HIWORD(l)           ((UINT16)(((UINT32)(l) >> (UINT8)16) & (UINT16)0xFFFF))
#define MAKEUINT32(h, l)    ((UINT32)(((UINT16)(l)) | ((UINT32)((UINT16)(h))) << (UINT8)16))

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

extern volatile UINT16 g_wFrameCounter;                 // 750ms counter
extern volatile  UINT8 g_yTimedOut;                     // 1=A time out occured

extern void DelayShort(void);

extern int long TimeOut = 0;

#endif /* __MAIN_H__ */
