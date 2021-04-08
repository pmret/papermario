#include "common.h"

ApiStatus _show_message(ScriptInstance* script, s32 isInitialCall, s32 arg2);

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

INCLUDE_ASM(ApiStatus, "f4c60_len_4300", _show_message, ScriptInstance* script, s32 isInitialCall, s32 arg2);

INCLUDE_ASM(s32, "f4c60_len_4300", ShowMessageAtScreenPos, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "f4c60_len_4300", ShowMessageAtWorldPos, ScriptInstance* script, s32 isInitialCall);

ApiStatus CloseMessage(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        close_message(gCurrentPrintContext);
    }

    if (gCurrentPrintContext->stateFlags & 0x40) {
        return ApiStatus_DONE1;
    } else if (D_802DB264 != 1) {
        return ApiStatus_BLOCK;
    } else {
        script->varTable[0] = gCurrentPrintContext->unk_4E8;
        return ApiStatus_DONE1;
    }
}

ApiStatus SwitchMessage(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        load_message_to_printer(get_variable(script, *args), gCurrentPrintContext);
    }

    if (gCurrentPrintContext->stateFlags & 0x40) {
        return ApiStatus_DONE1;
    } else if (D_802DB264 != 1) {
        return ApiStatus_BLOCK;
    } else {
        script->varTable[0] = gCurrentPrintContext->unk_4E8;
        return ApiStatus_DONE1;
    }
}

INCLUDE_ASM(s32, "f4c60_len_4300", ShowChoice, ScriptInstance* script, s32 isInitialCall);

ApiStatus CloseChoice(ScriptInstance* script, s32 isInitialCall) {
    close_message(D_802DB268);
    return ApiStatus_DONE1;
}

ApiStatus CancelMessage(ScriptInstance* script, s32 isInitialCall) {
    cancel_message(gCurrentPrintContext);
    return ApiStatus_DONE2;
}

ApiStatus CancelMessageAndBlock() {
    cancel_message(gCurrentPrintContext);
    return ApiStatus_BLOCK;
}

ApiStatus SetMessageImages(ScriptInstance* script, s32 isInitialCall) {
    set_message_images(*script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_802D0C94(ScriptInstance* script, s32 initialCall) {
    if (get_variable(script, *script->ptrReadPos) == 0) {
        OVERRIDE_FLAG_SET(0x10);
    } else {
        OVERRIDE_FLAG_UNSET(0x10);
    }
    return ApiStatus_DONE2;
}

ApiStatus SetMessageString(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 string = get_variable(script, *args++);
    s32 index = get_variable(script, *args++);

    set_message_string(string, index);
    return ApiStatus_DONE2;
}

ApiStatus SetMessageValue(ScriptInstance* script, s32 initialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 value = get_variable(script, *ptrReadPos++);
    s32 index = get_variable(script, *ptrReadPos);

    set_message_value(value, index);
    return ApiStatus_DONE2;
}
