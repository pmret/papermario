#include "end_01.h"

extern s32 N(D_80245D34_E0B094);

API_CALLABLE(N(func_802428C0_E07C20)) {
    func_8011B950(0x5B, -1, 1, 0);
    set_background_color_blend(0, 0, 0, 255);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242900_E07C60)) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }
    
    script->functionTemp[1] -= 10;
    if (script->functionTemp[1] < 0) {
        script->functionTemp[1] = 0;
    }
    
    set_background_color_blend(0, 0, 0, script->functionTemp[1]);
    
    if (script->functionTemp[1] == 0) {
        func_8011B950(0x5B, -1, 0, 0);
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80242978_E07CD8)) {
    Npc* npc;

    if (isInitialCall) {
        script->functionTempPtr[2] = get_npc_safe(script->varTable[10]);
        script->functionTemp[0] = 0;
    }
    npc = script->functionTempPtr[2];
    npc->rotation.y = update_lerp(4, 810.0f, 0.0f, script->functionTemp[0], 45);
    npc->alpha = update_lerp(4, 0.0f, 255.0f, script->functionTemp[0], 45);

    script->functionTemp[0]++;
    if (script->functionTemp[0] < 0x2E) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(func_80242A68_E07DC8)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Npc* npc;

    if (isInitialCall) {
        script->functionTempPtr[1] = resolve_npc(script, npcID);
        npc = script->functionTempPtr[1];
        script->functionTemp[2] = npc->pos.x;
        script->functionTempF[3] = 180.0f;
        script->functionTemp[0] = 72;
    }
    
    npc = script->functionTempPtr[1];
    script->functionTempF[3] = clamp_angle(script->functionTempF[3] - 5.0f);
    npc->pos.x = npc->pos.x + (cos_deg(script->functionTempF[3]) * 6.0f);
    npc->pos.z = npc->pos.z + (sin_deg(script->functionTempF[3]) * 2.5f);
    npc->renderYaw = clamp_angle(180.0f - script->functionTempF[3]);
    
    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80242B68_E07EC8)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Npc* npc;

    if (isInitialCall) {
        script->functionTempPtr[1] = resolve_npc(script, npcID);
        npc = script->functionTempPtr[1];
        script->functionTemp[2] = npc->pos.x;
        script->functionTempF[3] = 180.0f;
        script->functionTemp[0] = 72;
    }
    
    npc = script->functionTempPtr[1];
    script->functionTempF[3] = clamp_angle(script->functionTempF[3] + 5.0f);
    npc->pos.x = npc->pos.x + (cos_deg(script->functionTempF[3]) * 6.0f);
    npc->pos.z = npc->pos.z + (sin_deg(script->functionTempF[3]) * 2.5f);
    npc->renderYaw = clamp_angle(180.0f - script->functionTempF[3]);
    
    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80242C68_E07FC8)) {
    Bytecode* args = script->ptrReadPos;
    N(D_80245D34_E0B094) = evt_get_variable(script, *args++);
    
    return ApiStatus_DONE2;
}

void N(func_80242C94_E07FF4)(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, SHADE, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, SHADE, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, N(D_80245D34_E0B094) & 0xFF);
}
