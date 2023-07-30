#include "common.h"
#include "npc.h"
#include "../../partners.h"

API_CALLABLE(N(ToadHouse_DisableStatusBar)) {
    status_bar_ignore_changes();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ToadHouse_ShowWorldStatusBar)) {
    status_bar_respond_to_changes();
    sync_status_bar();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ToadHouse_UpdateScreenOverlay)) {
    Bytecode* args = script->ptrReadPos;
    s32 type = evt_get_variable(script, *args++);
    s32 zoom = evt_get_variable(script, *args++);

    set_screen_overlay_center(SCREEN_LAYER_FRONT, 0, 190, 145);
    set_screen_overlay_params_front(type, zoom);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ToadHouse_CamSetFOV)) {
    Bytecode* args = script->ptrReadPos;
    s32 camIdx = evt_get_variable(script, *args++);

    gCameras[camIdx].vfov = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ToadHouse_AwaitScriptComplete)) {
    Bytecode* args = script->ptrReadPos;
    s32 waitingScriptID = evt_get_variable(script, *args++);

    if (!does_script_exist(waitingScriptID)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(ToadHouse_PartnerSuspendAbilityScript)) {
    if (gPlayerData.curPartner == PARTNER_NONE) {
        return ApiStatus_DONE2;
    }
    partner_suspend_ability_script();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ToadHouse_PartnerResumeAbilityScript)) {
    partner_resume_ability_script();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ToadHouse_DoesPlayerNeedSleep)) {
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

API_CALLABLE(N(ToadHouse_InitScreenOverlay)) {
    Bytecode* args = script->ptrReadPos;
    s32 r = evt_get_variable(script, *args++);
    s32 g = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);

    set_screen_overlay_color(SCREEN_LAYER_FRONT, r, g, b);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ToadHouse_PutPartnerAway)) {
    Bytecode* args = script->ptrReadPos;
    Bytecode saveToVar = *args++;

    evt_set_variable(script, saveToVar, gPlayerData.curPartner);
    switch_to_partner(PARTNER_NONE);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ToadHouse_GetPartnerBackOut)) {
    Bytecode* args = script->ptrReadPos;
    Bytecode readFromVar = *args++;

    switch_to_partner((s8)evt_get_variable(script, readFromVar));
    return ApiStatus_DONE2;
}

// do nothing (unused)
API_CALLABLE(N(ToadHouse_Stub)) {
    return ApiStatus_DONE2;
}
