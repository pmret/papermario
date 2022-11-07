#include "osr_03.h"

ApiStatus func_80240020_AB62B0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    evt_set_variable(script, *args++, sin_deg(evt_get_variable(script, *args)) * 20.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80240090_AB6320(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags |= PEACH_STATUS_FLAG_IS_PEACH;
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
            set_screen_overlay_color(0, 208, 208, 208);
            set_screen_overlay_params_front(1, script->functionTemp[1]);
            if (script->functionTemp[1] == 255) {
                script->functionTemp[2] = 1;
                break;
            }
            script->functionTemp[1] += 64;
            if (script->functionTemp[1] < 256) {       
                break;
            }
            script->functionTemp[1] = 255;
            break;
        case 1:
            set_screen_overlay_color(0, 208, 208, 208);
            set_screen_overlay_params_front(1, script->functionTemp[1]);
            if (script->functionTemp[1] == 0) {
                return ApiStatus_DONE2;
            }
            script->functionTemp[1] -= 64;
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[1] = 0;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80240290_AB6520(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 frequency;
    s32 duration;
    
    if (isInitialCall) {
        duration = evt_get_variable(script, *args++);
        frequency = 2.0f * evt_get_float_variable(script, *args++);
        script->functionTemp[0] = duration;
        if (frequency > 10.0f) {
            frequency = 10.0f;
        }
        
        start_rumble((u8) ((frequency / 10.0f) * 256.0f), (duration & 0xFFFF) * 2);
    }
    
    script->functionTemp[0] -= 1;  
    if (script->functionTemp[0] == 0)
    {
        return ApiStatus_DONE1;
    }
    
    return ApiStatus_BLOCK;
}
