#ifndef _CAM_
#define _CAM_

#include "ultra64.h"
#include "types.h"

typedef enum Cam {
	DEFAULT = 0x00000000,
	BATTLE = 0x00000001,
	TATTLE = 0x00000002,
	CAM3 = 0x00000003
} Cam;

#endif