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

INCLUDE_ASM(ApiStatus, "evt/msg_api", _show_message, ScriptInstance* script, s32 isInitialCall, s32 arg2);

ApiStatus ShowMessageAtScreenPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        s32 stringID = get_variable(script, *args++);
        s32 x = get_variable(script, *args++);
        s32 y = get_variable(script, *args++);
        s32* temp802DB264 = &D_802DB264;

        *temp802DB264 = 0;
        gCurrentPrintContext = load_string(stringID, temp802DB264);
        clamp_printer_coords(gCurrentPrintContext, x, y);
    }

    if (gCurrentPrintContext->stateFlags & 0x40) {
        return ApiStatus_DONE1;
    }

    if (D_802DB264 != 1) {
        return ApiStatus_BLOCK;
    }

    script->varTable[0] = gCurrentPrintContext->currentOption;
    return ApiStatus_DONE1;
}

ApiStatus ShowMessageAtWorldPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PrintContext** currentPrintContext;
    s32* currentCameraID = &gCurrentCameraID;

    if (isInitialCall) {
        s32 stringID = get_variable(script, *args++);
        s32 x = get_variable(script, *args++);
        s32 y = get_variable(script, *args++);
        s32 z = get_variable(script, *args++);
        s32 x2;
        s32 y2;
        s32 z2;
        s32* temp802DB264 = &D_802DB264;

        *temp802DB264 = 0;
        currentPrintContext = &gCurrentPrintContext;
        *currentPrintContext = load_string(stringID, temp802DB264);
        get_screen_coords(*currentCameraID, x, y, z, &x2, &y2, &z2);
        clamp_printer_coords(*currentPrintContext, x2, y2);
    }

    if (gCurrentPrintContext->stateFlags & 0x40) {
        return ApiStatus_DONE1;
    }

    if (D_802DB264 != 1) {
        return ApiStatus_BLOCK;
    }

    script->varTable[0] = gCurrentPrintContext->currentOption;
    return ApiStatus_DONE1;
}

ApiStatus CloseMessage(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        close_message(gCurrentPrintContext);
    }

    if (gCurrentPrintContext->stateFlags & 0x40) {
        return ApiStatus_DONE1;
    } else if (D_802DB264 != 1) {
        return ApiStatus_BLOCK;
    } else {
        script->varTable[0] = gCurrentPrintContext->currentOption;
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
        script->varTable[0] = gCurrentPrintContext->currentOption;
        return ApiStatus_DONE1;
    }
}

ApiStatus ShowChoice(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PrintContext** temp802DB268;

    if (isInitialCall) {
        s32 stringID = get_variable(script, *args++);

        script->functionTemp[1].s = 0;
        D_802DB268 = load_string(stringID, &script->functionTemp[1]);
    }

    temp802DB268 = &D_802DB268;
    script->varTable[0] = gCurrentPrintContext->currentOption = (*temp802DB268)->currentOption;

    if ((*temp802DB268)->stateFlags & 0x40) {
        return ApiStatus_DONE1;
    }

    return script->functionTemp[1].s == 1;
}

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
        gOverrideFlags |= 0x10;
    } else {
        gOverrideFlags &= ~0x10;
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
