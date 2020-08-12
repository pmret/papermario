#ifndef _ENCOUNTER_TRIGGER_
#define _ENCOUNTER_TRIGGER_

#include "ultra64.h"
#include "types.h"

typedef enum EncounterTrigger {
	NONE = 0x00000001,
	JUMP = 0x00000002,
	SPIN = 0x00000003,
	HAMMER = 0x00000004,
	PARTNER = 0x00000006
} EncounterTrigger;

#endif