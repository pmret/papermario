#include "common.h"

extern s32 ShowMessageScreenOffsetX;
extern s32 ShowMessageScreenOffsetY;
extern s32 D_802DAE58[2]; // unused?
extern char D_802DAE60[0x400]; // unused?
extern MessagePrintState* gCurrentPrintContext;
extern s32 D_802DB264;
extern MessagePrintState* D_802DB268;

ApiStatus _show_message(Evt* script, s32 isInitialCall, s32 arg2);

enum {
    SHOW_MESSAGE_SPEAK_TO_PLAYER    = 0,
    SHOW_MESSAGE_END_SPEECH         = 1,
    SHOW_MESSAGE_CONTINUE_SPEECH    = 2,
    SHOW_MESSAGE_SPEAK_TO_NPC       = 3,
};

ApiStatus SpeakToPlayer(Evt* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, SHOW_MESSAGE_SPEAK_TO_PLAYER);
}

ApiStatus EndSpeech(Evt* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, SHOW_MESSAGE_END_SPEECH);
}

ApiStatus ContinueSpeech(Evt* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, SHOW_MESSAGE_CONTINUE_SPEECH);
}

ApiStatus SpeakToNpc(Evt* script, s32 isInitialCall) {
    return _show_message(script, isInitialCall, SHOW_MESSAGE_SPEAK_TO_NPC);
}

s32 _show_message(Evt* script, s32 isInitialCall, s32 mode) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 screenX, screenY, screenZ;
    Npc* speakerNpc;
    Npc* targetNpc;
    f32 reverseAngle;
    f32 angle;
    f32* listenerYaw;
    s32 speakerNpcID;
    s32 targetNpcID;
    s32 msgID;
    s32 animID;
    s32 ret;

    targetNpc = NULL;

    if (isInitialCall) {
        D_802DB264 = 0;
        speakerNpcID = evt_get_variable(script, *args++);
        script->varTable[13] = evt_get_variable(script, *args++);
        script->varTable[14] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        ShowMessageScreenOffsetY = 0;
        ShowMessageScreenOffsetX = 0;

        if (script->functionTemp[1] & SPEECH_FLAG_HAS_OFFSET) {
            ShowMessageScreenOffsetX = evt_get_variable(script, *args++);
            ShowMessageScreenOffsetY = evt_get_variable(script, *args++);
        }

        switch (mode) {
            case SHOW_MESSAGE_SPEAK_TO_PLAYER:
                msgID = evt_get_variable(script, *args++);
                gCurrentPrintContext = msg_get_printer_for_msg(msgID, &D_802DB264);
                break;
            case SHOW_MESSAGE_END_SPEECH:
                close_message(gCurrentPrintContext);
                break;
            case SHOW_MESSAGE_CONTINUE_SPEECH:
                msgID = evt_get_variable(script, *args++);
                msg_printer_load_msg(msgID, gCurrentPrintContext);
                break;
            case SHOW_MESSAGE_SPEAK_TO_NPC:
                targetNpcID = evt_get_variable(script, *args++);
                msgID = evt_get_variable(script, *args++);
                targetNpc = resolve_npc(script, targetNpcID);
                gCurrentPrintContext = msg_get_printer_for_msg(msgID, &D_802DB264);
                break;
        }

        if (speakerNpcID == NPC_PLAYER) {
            get_screen_coords(gCurrentCameraID, playerStatus->pos.x,
                              playerStatus->pos.y + playerStatus->colliderHeight, playerStatus->pos.z,
                              &screenX, &screenY, &screenZ);
            script->functionTemp[3] = playerStatus->anim;
            speakerNpc = (Npc*) NPC_PLAYER;
            script->varTable[15] = playerStatus->targetYaw;
        } else {
            speakerNpc = resolve_npc(script, speakerNpcID);
            get_screen_coords(gCurrentCameraID, speakerNpc->pos.x, speakerNpc->pos.y + speakerNpc->collisionHeight, speakerNpc->pos.z,
                              &screenX, &screenY, &screenZ);
            script->functionTemp[3] = speakerNpc->curAnim;
            script->varTable[15] = speakerNpc->yaw;
        }

        msg_printer_set_origin_pos(gCurrentPrintContext,
            screenX + ShowMessageScreenOffsetX,
            screenY + ShowMessageScreenOffsetY);
        script->varTablePtr[12] = speakerNpc;

        if (speakerNpc != (Npc*) NPC_PLAYER) {
            if (mode == SHOW_MESSAGE_SPEAK_TO_NPC) {
                listenerYaw = &targetNpc->yaw;
                angle = atan2(speakerNpc->pos.x, speakerNpc->pos.z, targetNpc->pos.x, targetNpc->pos.z);
            } else {
                listenerYaw = &playerStatus->targetYaw;
                angle = atan2(speakerNpc->pos.x, speakerNpc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            }

            reverseAngle = clamp_angle(angle + 180.0f);
            switch (script->functionTemp[1] & SPEECH_ORIENTATION_MASK) {
                case SPEECH_FACE_EACH_OTHER:
                    speakerNpc->yaw = angle;
                    *listenerYaw = reverseAngle;
                    break;
                case SPEECH_FACE_LIKE_LISTENER:
                    speakerNpc->yaw = reverseAngle;
                    *listenerYaw = reverseAngle;
                    break;
                case SPEECH_FACE_LIKE_SPEAKER:
                    speakerNpc->yaw = angle;
                    *listenerYaw = angle;
                    break;
                case SPEECH_FACE_AWAY_FROM:
                    speakerNpc->yaw = reverseAngle;
                    *listenerYaw = angle;
                    break;
                case SPEECH_FACE_SPEAKER_ONLY:
                    speakerNpc->yaw = angle;
                    break;
                case 5:
                    break;
            }
        }
    }

    speakerNpc = script->varTablePtr[12];
    if (speakerNpc != (Npc*) NPC_PLAYER) {
        get_screen_coords(gCurrentCameraID, speakerNpc->pos.x, speakerNpc->pos.y + speakerNpc->collisionHeight, speakerNpc->pos.z, &screenX, &screenY, &screenZ);
        animID = script->varTable[13];
        if (animID != -1) {
            if (!(gCurrentPrintContext->stateFlags & MSG_STATE_FLAG_80)) {
                animID = script->varTable[14];
            }
            set_npc_animation(speakerNpc, animID);
        }
    } else {
        get_screen_coords(gCurrentCameraID, playerStatus->pos.x, playerStatus->pos.y + playerStatus->colliderHeight, playerStatus->pos.z, &screenX, &screenY, &screenZ);
        if (script->varTable[13] != -1) {
            if (gCurrentPrintContext->stateFlags & MSG_STATE_FLAG_80) {
                playerStatus->anim = script->varTable[13];
            } else {
                playerStatus->anim = script->varTable[14];
            }
        }
    }

    if (!(script->functionTemp[1] & SPEECH_FLAG_200)) {
        msg_printer_set_origin_pos(gCurrentPrintContext, screenX + ShowMessageScreenOffsetX, screenY + ShowMessageScreenOffsetY);
    }

    if (gCurrentPrintContext->stateFlags & MSG_STATE_FLAG_40) {
        return TRUE;
    }

    if (D_802DB264 != 1) {
        return FALSE;
    }

    if (script->varTable[13] != -1) {
        if (speakerNpc != (Npc*) NPC_PLAYER) {
            set_npc_animation(speakerNpc, script->functionTemp[3]);
        } else {
            playerStatus->anim = script->functionTemp[3];
        }
    }
    if (script->functionTemp[1] & SPEECH_FLAG_10) {
        speakerNpc->yaw = script->varTable[0xF];
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

    if (gCurrentPrintContext->stateFlags & MSG_STATE_FLAG_40) {
        return ApiStatus_DONE1;
    }

    if (D_802DB264 != 1) {
        return ApiStatus_BLOCK;
    }

    script->varTable[0] = gCurrentPrintContext->curOption;
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

    if (gCurrentPrintContext->stateFlags & MSG_STATE_FLAG_40) {
        return ApiStatus_DONE1;
    }

    if (D_802DB264 != 1) {
        return ApiStatus_BLOCK;
    }

    script->varTable[0] = gCurrentPrintContext->curOption;
    return ApiStatus_DONE1;
}

ApiStatus CloseMessage(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        close_message(gCurrentPrintContext);
    }

    if (gCurrentPrintContext->stateFlags & MSG_STATE_FLAG_40) {
        return ApiStatus_DONE1;
    } else if (D_802DB264 != 1) {
        return ApiStatus_BLOCK;
    } else {
        script->varTable[0] = gCurrentPrintContext->curOption;
        return ApiStatus_DONE1;
    }
}

ApiStatus SwitchMessage(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        msg_printer_load_msg(evt_get_variable(script, *args), gCurrentPrintContext);
    }

    if (gCurrentPrintContext->stateFlags & MSG_STATE_FLAG_40) {
        return ApiStatus_DONE1;
    } else if (D_802DB264 != 1) {
        return ApiStatus_BLOCK;
    } else {
        script->varTable[0] = gCurrentPrintContext->curOption;
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
    script->varTable[0] = gCurrentPrintContext->curOption = (*temp802DB268)->curOption;

    if ((*temp802DB268)->stateFlags & MSG_STATE_FLAG_40) {
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

ApiStatus SetMessageText(Evt* script, s32 isInitialCall) {
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
