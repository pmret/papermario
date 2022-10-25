#include "obk_01.h"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_80240B24_BBDCC4);

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_80240B78_BBDD18);

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD980", func_80240BB0_BBDD50);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

ApiStatus func_80240F38_BBE0D8(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    switch (script->functionTemp[1]) {
        case 0:
            npc->pos.z = rand_int(100) + 180;
            npc->pos.y = rand_int(100) - 200;
            npc->moveSpeed = (2.0f * rand_float()) + 2.0f;
            if (rand_int(100) < 50) {
                npc->pos.x = 920.0f;
                npc->yaw = 270.0f;
            } else {
                npc->pos.x = -20.0f;
                npc->yaw = 90.0f;
            }
            script->functionTemp[1] = 1;
            break;
        case 1:
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (npc->pos.x < -30.0f || npc->pos.x > 930.0f) {
                script->functionTemp[1] = 0;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

extern s16 D_80244A54_BC1BF4[];

ApiStatus func_80241094_BBE234(Evt* script, s32 isInitialCall) {
    s32 var0 = script->varTable[0];
    s32 var1 = script->varTable[1];
    s32 temp;

    if (var1 == 0) {
        script->functionTemp[2] = D_80244A54_BC1BF4[rand_int(3)];
        var1 = rand_int(50) + 30;
    }
    var1--;

    temp = script->functionTemp[2];
    if (var0 < temp) {
        var0 += 10;
        if (temp < var0) {
            var0 = temp;
        }
    }
    if (temp < var0) {
        var0 -= 10;
        if (var0 < temp) {
            var0 = temp;
        }
    }

    script->varTable[0] = var0;
    script->varTable[1] = var1;
    return ApiStatus_DONE2;
}
