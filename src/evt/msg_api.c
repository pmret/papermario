#include "common.h"

extern s32 D_802DAE50;
extern s32 D_802DAE54;

ApiStatus _show_message(Evt* script, s32 isInitialCall, s32 arg2);

ApiStatus SpeakToPlayer(Evt* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, 0);
}

ApiStatus EndSpeech(Evt* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, 1);
}

ApiStatus ContinueSpeech(Evt* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, 2);
}

ApiStatus SpeakToNpc(Evt* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, 3);
}

s32 _show_message(Evt* script, s32 isInitialCall, s32 arg2) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 screenX, screenY, screenZ;
    Npc* npc;
    Npc* npc2;
    f32 yaw;
    f32 angle;
    f32 x, z;
    f32* yawPtr;
    s32 temp_fp;
    s32 npcID;
    s32 msgID;
    s32 animID;
    s32 ret;

    npc2 = NULL;

    if (isInitialCall) {
        D_802DB264 = 0;
        temp_fp = evt_get_variable(script, *args++);
        script->varTable[13] = evt_get_variable(script, *args++);
        script->varTable[14] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        D_802DAE54 = 0;
        D_802DAE50 = 0;

        if (script->functionTemp[1] & 0x100) {
            D_802DAE50 = evt_get_variable(script, *args++);
            D_802DAE54 = evt_get_variable(script, *args++);
        }

        switch (arg2) {
            case 0:
                msgID = evt_get_variable(script, *args++);
                gCurrentPrintContext = msg_get_printer_for_msg(msgID, &D_802DB264);
                break;
            case 1:
                close_message(gCurrentPrintContext);
                break;
            case 2:
                msgID = evt_get_variable(script, *args++);
                msg_printer_load_msg(msgID, gCurrentPrintContext);
                break;
            case 3:
                npcID = evt_get_variable(script, *args++);
                msgID = evt_get_variable(script, *args++);
                npc2 = resolve_npc(script, npcID);
                gCurrentPrintContext = msg_get_printer_for_msg(msgID, &D_802DB264);
                break;
        }

        if (temp_fp == NPC_PLAYER) {
            get_screen_coords(gCurrentCameraID, playerStatus->position.x,
                              playerStatus->position.y + playerStatus->colliderHeight, playerStatus->position.z,
                              &screenX, &screenY, &screenZ);
            script->functionTemp[3] = playerStatus->anim;
            npc = (Npc*) NPC_PLAYER;
            script->varTable[15] = playerStatus->targetYaw;
        } else {
            npc = resolve_npc(script, temp_fp);
            get_screen_coords(gCurrentCameraID, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z,
                              &screenX, &screenY, &screenZ);
            script->functionTemp[3] = npc->currentAnim;
            script->varTable[15] = npc->yaw;
        }

        msg_printer_set_origin_pos(gCurrentPrintContext, screenX + D_802DAE50, screenY + D_802DAE54);
        script->varTablePtr[12] = npc;

        if (npc != (Npc*) NPC_PLAYER) {
            if (arg2 == 3) {
                yawPtr = &npc2->yaw;
                angle = atan2(npc->pos.x, npc->pos.z, npc2->pos.x, npc2->pos.z);
            } else {
                yawPtr = &playerStatus->targetYaw;
                angle = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
            }

            yaw = clamp_angle(angle + 180.0f);
            switch (script->functionTemp[1] & 0xF) {
                case 0:
                    npc->yaw = angle;
                    *yawPtr = yaw;
                    break;
                case 1:
                    npc->yaw = yaw;
                    *yawPtr = yaw;
                    break;
                case 2:
                    npc->yaw = angle;
                    *yawPtr = angle;
                    break;
                case 3:
                    npc->yaw = yaw;
                    *yawPtr = angle;
                    break;
                case 4:
                    npc->yaw = angle;
                    break;
                case 5:
                    break;
            }
        }
    }

    npc = script->varTablePtr[12];
    if (npc != (Npc*) NPC_PLAYER) {
        get_screen_coords(gCurrentCameraID, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, &screenX, &screenY, &screenZ);
        animID = script->varTable[13];
        if (animID != -1) {
            if (!(gCurrentPrintContext->stateFlags & 0x80)) {
                animID = script->varTable[14];
            }
            set_npc_animation(npc, animID);
        }
    } else {
        get_screen_coords(gCurrentCameraID, playerStatus->position.x, playerStatus->position.y + playerStatus->colliderHeight, playerStatus->position.z, &screenX, &screenY, &screenZ);
        if (script->varTable[13] != -1) {
            if (gCurrentPrintContext->stateFlags & 0x80) {
                playerStatus->anim = script->varTable[13];
            } else {
                playerStatus->anim = script->varTable[14];
            }
        }
    }

    if (!(script->functionTemp[1] & 0x200)) {
        msg_printer_set_origin_pos(gCurrentPrintContext, screenX + D_802DAE50, screenY + D_802DAE54);
    }

    if (gCurrentPrintContext->stateFlags & 0x40) {
        return TRUE;
    }

    if (D_802DB264 != 1) {
        return FALSE;
    }

    if (script->varTable[13] != -1) {
        if (npc != (Npc*) NPC_PLAYER) {
            set_npc_animation(npc, script->functionTemp[3]);
        } else {
            playerStatus->anim = script->functionTemp[3];
        }
    }
    if (script->functionTemp[1] & 0x10) {
        npc->yaw = script->varTable[0xF];
    }
    return TRUE;
}

ApiStatus ShowMessageAtScreenPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        s32 msgID = evt_get_variable(script, *args++);
        s32 x = evt_get_variable(script, *args++);
        s32 y = evt_get_variable(script, *args++);
        s32* temp802DB264 = &D_802DB264;

        *temp802DB264 = 0;
        gCurrentPrintContext = msg_get_printer_for_msg(msgID, temp802DB264);
        msg_printer_set_origin_pos(gCurrentPrintContext, x, y);
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

ApiStatus ShowMessageAtWorldPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    MessagePrintState** currentPrintContext;
    s32* currentCameraID = &gCurrentCameraID;

    if (isInitialCall) {
        s32 msgID = evt_get_variable(script, *args++);
        s32 x = evt_get_variable(script, *args++);
        s32 y = evt_get_variable(script, *args++);
        s32 z = evt_get_variable(script, *args++);
        s32 x2;
        s32 y2;
        s32 z2;
        s32* temp802DB264 = &D_802DB264;

        *temp802DB264 = 0;
        currentPrintContext = &gCurrentPrintContext;
        *currentPrintContext = msg_get_printer_for_msg(msgID, temp802DB264);
        get_screen_coords(*currentCameraID, x, y, z, &x2, &y2, &z2);
        msg_printer_set_origin_pos(*currentPrintContext, x2, y2);
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

ApiStatus CloseMessage(Evt* script, s32 isInitialCall) {
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

ApiStatus SwitchMessage(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        msg_printer_load_msg(evt_get_variable(script, *args), gCurrentPrintContext);
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

ApiStatus ShowChoice(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    MessagePrintState** temp802DB268;

    if (isInitialCall) {
        s32 msgID = evt_get_variable(script, *args++);

        script->functionTemp[1] = 0;
        D_802DB268 = msg_get_printer_for_msg(msgID, &script->functionTemp[1]);
    }

    temp802DB268 = &D_802DB268;
    script->varTable[0] = gCurrentPrintContext->currentOption = (*temp802DB268)->currentOption;

    if ((*temp802DB268)->stateFlags & 0x40) {
        return ApiStatus_DONE1;
    }

    return script->functionTemp[1] == 1;
}

ApiStatus CloseChoice(Evt* script, s32 isInitialCall) {
    close_message(D_802DB268);
    return ApiStatus_DONE1;
}

ApiStatus CancelMessage(Evt* script, s32 isInitialCall) {
    cancel_message(gCurrentPrintContext);
    return ApiStatus_DONE2;
}

s32 cancel_current_message(void) {
    cancel_message(gCurrentPrintContext);
    return 0;
}

ApiStatus SetMessageImages(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    set_message_images((MessageImageData*) *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802D0C94(Evt* script, s32 initialCall) {
    Bytecode* args = script->ptrReadPos;

    if (evt_get_variable(script, *args++) == 0) {
        gOverrideFlags |= GLOBAL_OVERRIDES_10;
    } else {
        gOverrideFlags &= ~GLOBAL_OVERRIDES_10;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetMessageMsg(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 msg = evt_get_variable(script, *args++);
    s32 index = evt_get_variable(script, *args++);

    set_message_msg(msg, index);
    return ApiStatus_DONE2;
}

ApiStatus SetMessageValue(Evt* script, s32 initialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 value = evt_get_variable(script, *ptrReadPos++);
    s32 index = evt_get_variable(script, *ptrReadPos);

    set_message_value(value, index);
    return ApiStatus_DONE2;
}
