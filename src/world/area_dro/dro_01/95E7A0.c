#include "dro_01.h"

#define MAP_NAME dup_dro_01
#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"
#define MAP_NAME dro_01

#define MAP_NAME dup_dro_01
#include "world/common/GetCurrentFloor.inc.c"
#define MAP_NAME dro_01

INCLUDE_ASM(s32, "world/area_dro/dro_01/95E7A0", func_802435D4_95E7D4);

#define MAP_NAME dup_dro_01
#include "world/common/GetEntryPos.inc.c"
#define MAP_NAME dro_01

#define MAP_NAME dup_dro_01
#include "world/common/GetCurrentCameraYawClamped180.inc.c"
#define MAP_NAME dro_01

INCLUDE_ASM(s32, "world/area_dro/dro_01/95E7A0", func_802437DC_95E9DC);

#include "world/common/SomeMatrixOperations.inc.c"
