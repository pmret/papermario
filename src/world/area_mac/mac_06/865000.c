#include "mac_06.h"

extern u32 N(unkAngle1);
extern s32 N(unkAngle2);
extern s32 N(unkAngle3);

void N(unkVtxFunc001)(Vtx* firstVertex, Vtx* copiedVertices, s32 numVertices, s32* arg3);

#include "world/common/resolve_npc.inc.c"

#include "world/common/UnkAngleFunc001.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_06/865000", mac_06_unkVtxFunc001);

#include "world/common/unkAngleFuncs023.inc.c"

#include "world/common/UnkFloatFunc001.inc.c"

#include "world/common/UnkPlayerPosFunc.inc.c"

#include "world/common/atomic/WhaleGeyser.inc.c"
