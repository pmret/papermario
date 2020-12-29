#include "kmr_20.h"

#define MAP_NAME dup_kmr_20
#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"
#define MAP_NAME kmr_20

#define MAP_NAME dup_kmr_20
#include "world/common/GetCurrentFloor.inc.c"
#define MAP_NAME kmr_20

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED5A0", func_802417B4_8ED5D4);

#define MAP_NAME dup_kmr_20
#include "world/common/GetEntryPos.inc.c"
#define MAP_NAME kmr_20

#define MAP_NAME dup_kmr_20
#include "world/common/GetCurrentCameraYawClamped180.inc.c"
#define MAP_NAME kmr_20

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED5A0", func_802419BC_8ED7DC);

#define MAP_NAME dup3_kmr_20
#include "world/common/SomeMatrixOperations.inc.c"
#define MAP_NAME kmr_20

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED5A0", func_80241C9C_8EDABC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED5A0", func_80241CF0_8EDB10);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED5A0", func_80241D1C_8EDB3C);
