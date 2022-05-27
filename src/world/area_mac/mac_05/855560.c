#include "mac_05.h"

extern u32 N(unkAngle1);
extern s32 N(unkAngle2);
extern s32 N(unkAngle3);

void N(unkVtxFunc001)(Vtx* firstVertex, Vtx* copiedVertices, s32 numVertices, s32* arg3);

#include "world/common/resolve_npc.inc.c"

#include "world/common/UnkAngleFunc001.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/855560", mac_05_unkVtxFunc001);

#include "world/common/unkAngleFuncs023.inc.c"

#include "world/common/UnkFloatFunc001.inc.c"

#include "world/common/UnkPlayerPosFunc.inc.c"

#include "world/common/PlayFX3D.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/855560", func_80243CD4_855E44);

INCLUDE_ASM(s32, "world/area_mac/mac_05/855560", func_80243D78_855EE8);
