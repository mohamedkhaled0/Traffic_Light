#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#include "avr/io.h"
#include "util/delay.h"
#define SETBIT(REG,BIT)  (REG |= 1 << BIT)
#define CLRBIT(REG,BIT)  (REG &= ~(1 << BIT))
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)

#endif /* STD_MACROS_H_ */
