#include "common.h"
#include "npc.h"
#include "../../partners.h"

ApiStatus N(ToadHouse_DisableStatusMenu)(Evt* script, s32 isInitialCall) {
    func_800E9894();
    return ApiStatus_DONE2;
}

ApiStatus N(ToadHouse_ShowStatusMenu)(Evt* script, s32 isInitialCall) {
    func_800E98C4();
    sync_status_menu();
    return ApiStatus_DONE2;
}

ApiStatus N(ToadHouse_UpdateScreenOverlay)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 type = evt_get_variable(script, *args++);
    s32 zoom = evt_get_variable(script, *args++);

    set_screen_overlay_center(0, 0, 190, 145);
    set_screen_overlay_params_front(type, zoom);
    return ApiStatus_DONE2;
}

ApiStatus N(ToadHouse_CamSetFOV)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 camIdx = evt_get_variable(script, *args++);

    gCameras[camIdx].vfov = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus N(ToadHouse_AwaitScriptComplete)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 waitingScriptID = evt_get_variable(script, *args++);
    
    if (!does_script_exist(waitingScriptID)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus N(ToadHouse_PartnerSuspendAbilityScript)(Evt* script, s32 isInitialCall) {
    if (gPlayerData.currentPartner == PARTNER_NONE) {
        return ApiStatus_DONE2;
    }
    partner_suspend_ability_script();
    return ApiStatus_DONE2;
}

ApiStatus N(ToadHouse_PartnerResumeAbilityScript)(Evt* script, s32 isInitialCall) {
    partner_resume_ability_script();
    return ApiStatus_DONE2;
}

ApiStatus N(ToadHouse_DoesPlayerNeedSleep)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[1] = FALSE;
    if (playerData->curMaxHP != playerData->curHP) {
        return ApiStatus_DONE2;
    }
    if (playerData->curMaxFP != playerData->curFP) {
        return ApiStatus_DONE2;
    }
    if (playerData->specialBarsFilled != playerData->maxStarPower * 256) {
        return ApiStatus_DONE2;
    }
    script->varTable[1] = TRUE;

    return ApiStatus_DONE2;
}

ApiStatus N(ToadHouse_InitScreenOverlay)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 R = evt_get_variable(script, *args++);
    s32 G = evt_get_variable(script, *args++);
    s32 B = evt_get_variable(script, *args++);

    set_screen_overlay_color(0, R, G, B);
    return ApiStatus_DONE2;
}

ApiStatus N(ToadHouse_PutPartnerAway)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode saveToVar = *args++;

    evt_set_variable(script, saveToVar, gPlayerData.currentPartner);
    switch_to_partner(PARTNER_NONE);
    return ApiStatus_DONE2;
}

ApiStatus N(ToadHouse_GetPartnerBackOut)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode readFromVar = *args++;

    switch_to_partner((s8)evt_get_variable(script, readFromVar));
    return ApiStatus_DONE2;
}

// do nothing (unused)
ApiStatus N(ToadHouse_Stub)(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}
