#include "osr_03.h"

INCLUDE_ASM(s32, "world/area_osr/osr_03/AB62B0", func_80240020_AB62B0);

INCLUDE_ASM(s32, "world/area_osr/osr_03/AB62B0", func_80240090_AB6320);

ApiStatus func_802400C4_AB6354(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0);

    script->varTable[0] = npc->pos.x + (sin_deg(npc->yaw + gCameras[CAM_DEFAULT].currentYaw + 180.0f) * 20.0f);
    script->varTable[1] = npc->pos.y + 18.0f;
    script->varTable[2] = npc->pos.z - (cos_deg(npc->yaw + gCameras[CAM_DEFAULT].currentYaw + 180.0f) * 20.0f);
    return ApiStatus_DONE2;
}


INCLUDE_ASM(s32, "world/area_osr/osr_03/AB62B0", func_802401A0_AB6430);

INCLUDE_ASM(s32, "world/area_osr/osr_03/AB62B0", func_80240290_AB6520);
