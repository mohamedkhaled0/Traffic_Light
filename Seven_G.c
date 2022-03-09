#include "Seven_G.h"
#include "std_macros.h"

 void SevenSegmentUpdate (unsigned int counter){
	unsigned int x = 0 ;

	x = counter % 10 ;
	SEG_EN2(1);
	SEG_EN1(0);
	SEG_A(READBIT(x,0));
	SEG_B(READBIT(x,1));
	SEG_C(READBIT(x,2));
	SEG_D(READBIT(x,3));
	_delay_ms(1);

	x = counter / 10 ;
	SEG_EN2(0);
	SEG_EN1(1);
	SEG_A(READBIT(x,0));
	SEG_B(READBIT(x,1));
	SEG_C(READBIT(x,2));
	SEG_D(READBIT(x,3));
	_delay_ms(1);
 }
 void SevenSegmentInit (){
	SevenSegmentDir = 0xFF;
	SEG_EN2(1);
	SEG_EN1(1);
	PORTD = 0xff;
}
