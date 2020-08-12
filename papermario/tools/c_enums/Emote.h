#ifndef _EMOTE_
#define _EMOTE_

#include "ultra64.h"
#include "types.h"

typedef enum Emote {
	EXCLAMATION = 0x00000000,
	SHOCK = 0x00000001,
	QUESTION = 0x00000002,
	FRUSTRATION = 0x00000003,
	ELLIPSIS = 0x00000004,
	INVALID = 0x00000005
} Emote;

#endif