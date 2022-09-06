#include "osr_03.h"

ApiStatus func_80240020_AB62B0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    evt_set_variable(script, *args, sin_deg(evt_get_variable(script, *args)) * 20.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80240090_AB6320(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags |= 1;
    script->varTable[0] = gPlayerData.currentPartner;
    gPlayerData.currentPartner = PARTNER_TWINK;
    return ApiStatus_DONE2;
}

ApiStatus func_802400C4_AB6354(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0);

    script->varTable[0] = npc->pos.x + (sin_deg(npc->yaw + gCameras[CAM_DEFAULT].currentYaw + 180.0f) * 20.0f);
    script->varTable[1] = npc->pos.y + 18.0f;
    script->varTable[2] = npc->pos.z - (cos_deg(npc->yaw + gCameras[CAM_DEFAULT].currentYaw + 180.0f) * 20.0f);
    return ApiStatus_DONE2;
}


ApiStatus func_802401A0_AB6430(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
        script->functionTemp[2] = 0;
    }
    switch (script->functionTemp[2]) {
    case 0:
        set_screen_overlay_color(0, 0xD0U, 0xD0U, 0xD0U);
        set_screen_overlay_params_front(1U, script->functionTemp[1]);
        if (script->functionTemp[1] == 0xFF) {
            script->functionTemp[2] = 1;
            break;
        }
        script->functionTemp[1] += 0x40;
        if (script->functionTemp[1] < 0x100) {       
            break;
        }
        script->functionTemp[1] = 0xFF;
        break;
    case 1:
        set_screen_overlay_color(0, 0xD0U, 0xD0U, 0xD0U);
        set_screen_overlay_params_front(1U, script->functionTemp[1]);
        if (script->functionTemp[1] == 0) {
            return ApiStatus_DONE2;
        }
        script->functionTemp[1] -= 0x40;
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = 0;
        }
        break;
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "world/area_osr/osr_03/AB62B0", func_80240290_AB6520);
