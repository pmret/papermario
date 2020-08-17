#include "common.h"

ApiStatus SpeakToPlayer(ScriptInstance* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, 0);
}

ApiStatus EndSpeech(ScriptInstance* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, 1);
}

ApiStatus ContinueSpeech(ScriptInstance* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, 2);
}

ApiStatus SpeakToNpc(ScriptInstance* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, 3);
}

INCLUDE_ASM(code_f4c60_len_4300, _show_message);

INCLUDE_API_ASM(code_f4c60_len_4300, ShowMessageAtScreenPos);

INCLUDE_API_ASM(code_f4c60_len_4300, ShowMessageAtWorldPos);

INCLUDE_API_ASM(code_f4c60_len_4300, CloseMessage);

INCLUDE_API_ASM(code_f4c60_len_4300, SwitchMessage);

INCLUDE_API_ASM(code_f4c60_len_4300, ShowChoice);

ApiStatus CloseChoice(ScriptInstance* script, s32 isInitialCall) {
    close_message(D_802DB268);
    return ApiStatus_DONE1;
}

ApiStatus CancelMessage(ScriptInstance* script, s32 isInitialCall) {
    cancel_message(gCurrentPrintContext);
    return ApiStatus_DONE2;
}

ApiStatus CancelMessageAndBlock(ScriptInstance* script, s32 isInitialCall) {
    cancel_message(gCurrentPrintContext);
    return ApiStatus_BLOCK;
}

ApiStatus SetMessageImages(ScriptInstance* script, s32 isInitialCall) {
    set_message_images(*script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_802D0C94(ScriptInstance* script, s32 initialCall) {
    if (get_variable(script, *script->ptrReadPos) == 0) {
        D_8009A650[0] |= 0x10;
    } else {
        D_8009A650[0] &= ~0x10;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetMessageString(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    Bytecode string = get_variable(script, *ptrReadPos++);
    Bytecode index = get_variable(script, *ptrReadPos++);

    set_message_string(string, index);
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM(code_f4c60_len_4300, SetMessageValue);
// TODO: Figure out why there's an extra NOP after this function
// It's probably because of a file split issue
/*
ApiStatus SetMessageValue(ScriptInstance* script, s32 initialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    Bytecode value = get_variable(script, *ptrReadPos++);
    Bytecode index = get_variable(script, *ptrReadPos);

    set_message_value(value, index);
    return ApiStatus_DONE2;
}
*/

INCLUDE_API_ASM(code_f4c60_len_4300, HidePlayerShadow);

INCLUDE_API_ASM(code_f4c60_len_4300, DisablePlayerPhysics);

INCLUDE_API_ASM(code_f4c60_len_4300, DisablePlayerInput);

INCLUDE_API_ASM(code_f4c60_len_4300, SetPlayerPos);

INCLUDE_API_ASM(code_f4c60_len_4300, SetPlayerCollisionSize);

INCLUDE_API_ASM(code_f4c60_len_4300, SetPlayerSpeed);

INCLUDE_API_ASM(code_f4c60_len_4300, SetPlayerJumpscale);

INCLUDE_API_ASM(code_f4c60_len_4300, SetPlayerAnimation);

INCLUDE_API_ASM(code_f4c60_len_4300, SetPlayerActionState);

INCLUDE_API_ASM(code_f4c60_len_4300, MovePlayerTo);

INCLUDE_ASM(code_f4c60_len_4300, player_jump);

INCLUDE_API_ASM(code_f4c60_len_4300, PlayerJump);

INCLUDE_API_ASM(code_f4c60_len_4300, PlayerJump1);

INCLUDE_API_ASM(code_f4c60_len_4300, PlayerJump2);

INCLUDE_API_ASM(code_f4c60_len_4300, InterpPlayerYaw);

INCLUDE_API_ASM(code_f4c60_len_4300, PlayerFaceNpc);

INCLUDE_API_ASM(code_f4c60_len_4300, GetPlayerTargetYaw);

INCLUDE_API_ASM(code_f4c60_len_4300, SetPlayerFlagBits);

INCLUDE_API_ASM(code_f4c60_len_4300, GetPlayerActionState);

INCLUDE_API_ASM(code_f4c60_len_4300, GetPlayerPos);

INCLUDE_API_ASM(code_f4c60_len_4300, GetPlayerAnimation);

INCLUDE_API_ASM(code_f4c60_len_4300, FullyRestoreHPandFP);

INCLUDE_API_ASM(code_f4c60_len_4300, FullyRestoreSP);

INCLUDE_API_ASM(code_f4c60_len_4300, EnablePartner);

INCLUDE_API_ASM(code_f4c60_len_4300, DisablePartner);

INCLUDE_API_ASM(code_f4c60_len_4300, ForceExitHeading);

INCLUDE_API_ASM(code_f4c60_len_4300, UseExitHeading);

INCLUDE_ASM(code_f4c60_len_4300, func_802D23F8);

INCLUDE_API_ASM(code_f4c60_len_4300, DisablePulseStone);

INCLUDE_API_ASM(code_f4c60_len_4300, GetCurrentPartner);

INCLUDE_API_ASM(code_f4c60_len_4300, Disable8bitMario);

INCLUDE_API_ASM(code_f4c60_len_4300, PlaySoundAtPlayer);

INCLUDE_ASM(code_f4c60_len_4300, func_802D2D30);

INCLUDE_ASM(code_f4c60_len_4300, func_802D2F34);

INCLUDE_API_ASM(code_f4c60_len_4300, CreateImageObj);

INCLUDE_API_ASM(code_f4c60_len_4300, RemoveImageObj);

INCLUDE_API_ASM(code_f4c60_len_4300, SetObjPosition);

INCLUDE_API_ASM(code_f4c60_len_4300, SetObjRotation);

INCLUDE_API_ASM(code_f4c60_len_4300, SetObjScale);

INCLUDE_API_ASM(code_f4c60_len_4300, SetObjJumpScale);

INCLUDE_API_ASM(code_f4c60_len_4300, JumpObj);

INCLUDE_ASM(code_f4c60_len_4300, func_802D4164);

INCLUDE_ASM(code_f4c60_len_4300, func_802D43F4);

INCLUDE_ASM(code_f4c60_len_4300, func_802D4488);

INCLUDE_ASM(code_f4c60_len_4300, func_802D4560);
