#include "obk_08.h"

static char* N(exit_str_0) = "obk_01";

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD4110", func_802408A0_BD4110);

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD4110", func_80240920_BD4190);

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD4110", func_802409E8_BD4258);

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD4110", func_80240A7C_BD42EC);

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD4110", func_80240AF0_BD4360);

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD4110", func_80240CA0_BD4510);

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD4110", func_80240D10_BD4580);

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD4110", func_80240FD8_BD4848);

ApiStatus func_80240FE4_BD4854(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    switch (script->functionTemp[1]) {
        case 0:
            npc->duration = rand_int(180) + 30;
            npc->pos.z = -430.0f;
            npc->pos.y = rand_int(50) + 40.0f;
            npc->moveSpeed = (2.0f * rand_float()) + 2.0f;
            if (rand_int(100) < 50) {
                npc->pos.x = 270.0f;
                npc->yaw = 270.0f;
            } else {
                npc->pos.x = -270.0f;
                npc->yaw = 90.0f;
            }
            script->functionTemp[1] = 1;
            break;
        case 1:
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[1] = 2;
            }
            break;
        case 2:
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (npc->pos.x < -280.0f || npc->pos.x > 280.0f) {
                script->functionTemp[1] = 0;
            }
            break;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD4110", func_8024116C_BD49DC);
