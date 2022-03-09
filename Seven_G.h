#ifndef  SEVENG_H
#define  SEVENG_H

 #define SevenSegmentDir DDRD
 #define SevenSegmentData PORTD

 #define SEG_A(x)     if (x==0) CLRBIT(PORTD,0); else SETBIT(PORTD,0);
 #define SEG_B(x)     if (x==0) CLRBIT(PORTD,1); else SETBIT(PORTD,1);
 #define SEG_C(x)     if (x==0) CLRBIT(PORTD,2); else SETBIT(PORTD,2);
 #define SEG_D(x)     if (x==0) CLRBIT(PORTD,3); else SETBIT(PORTD,3);
 #define SEG_EN1(x)   if (x==0) CLRBIT(PORTD,4); else SETBIT(PORTD,4);
 #define SEG_EN2(x)   if (x==0) CLRBIT(PORTD,5); else SETBIT(PORTD,5);
 void SevenSegmentInit ();
 void SevenSegmentUpdate (unsigned int counter);

#endif
