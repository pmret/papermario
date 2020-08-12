#ifndef _ITER_
#define _ITER_

#include "ultra64.h"
#include "types.h"

typedef enum Iter {
	FIRST = 0xFFFFFFFF,
	LAST = 0x0000000A,
	NEXT = 0x00000000,
	PREV = 0x00000001
} Iter;

#endif