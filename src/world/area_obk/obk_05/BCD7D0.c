#include "obk_05.h"

extern s16 D_8024100C_BCE06C[4];

ApiStatus func_80240770_BCD7D0(Evt* script, s32 isInitialCall) {
    if (gPlayerStatus.position.y < -50.0f) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_802407A0_BCD800(Evt* script, s32 isInitialCall) {
    script->functionTemp[1] = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802407AC_BCD80C(Evt* script, s32 isInitialCall) {
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

ApiStatus func_80240934_BCD994(Evt* script, s32 isInitialCall) {
    s32 var0 = script->varTable[0];
    s32 var1 = script->varTable[1];
    s32 temp;  
    
    if (var1 == 0) {
        script->functionTemp[2] = D_8024100C_BCE06C[rand_int(3)];
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
