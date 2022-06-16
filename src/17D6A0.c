#include "common.h"
#include "effects.h"

// from 190B20.c
extern s16 bMsgHeights[];
extern s16 D_802835D8[];
extern s32 bMessages[];
extern s32 bActorMessages[];

extern PopupMessage* D_802838F8;
extern PopupMessage popupMessages[32];
extern s16 D_8029F64C;
extern s16 D_8029F640;
extern s16 D_8029F64A;
extern s16 D_8029F64E;
extern s16 D_8029F650;

void func_8024FB3C(PopupMessage* popup);
void btl_show_message_popup(PopupMessage* popup);

void func_8024EDC0(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        popup->active = FALSE;
        popup->message = NULL;
    }
}

void func_8024EDEC(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->message != NULL) {
            heap_free(popup->message);
            popup->message = NULL;
        }
        popup->active = FALSE;
    }
}

void func_8024EE48(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->updateFunc != NULL) {
            popup->updateFunc(popup);
        }
    }
}

void func_8024EEA8(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->unk_08 != NULL) {
            popup->unk_08(popup);
        }
    }
}

void btl_draw_popup_messages(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->drawFunc != NULL) {
            popup->drawFunc(popup);
        }
    }
}

PopupMessage* btl_create_popup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (!popup->active) {
            popup->active = TRUE;
            return popup;
        }
    }

    return NULL;
}

void free_popup(PopupMessage* popup) {
    if (popup->message != NULL) {
        heap_free(popup->message);
        popup->message = NULL;
    }
    popup->active = FALSE;
}

INCLUDE_ASM(s32, "17D6A0", func_8024EFE0);

void func_8024F394(void* data) {
    PopupMessage* popup = data;
    Message* message = popup->message;
    s32 found = FALSE;
    s32 i;

    for (i = 0; i < popup->messageIndex; i++, message++) {
        if (message->unk_00 != 0) {
            s32 modelIdx = message->unk_04;

            found = TRUE;
            if (message->unk_24 != 0) {
                message->unk_24--;
                if (message->unk_24 == 0) {
                    clear_entity_model_flags(modelIdx, MODEL_FLAGS_FLAG_20);
                }
                exec_entity_model_commandlist(modelIdx);
                break;
            } else {
                exec_entity_model_commandlist(modelIdx);
                if (message->unk_20 >= 0) {
                    message->unk_38 += message->unk_14;
                    message->unk_3C += message->unk_18;
                    message->unk_40 += message->unk_1C;
                }
                message->unk_30 = clamp_angle(180.0f - gCameras[CAM_BATTLE].currentYaw);
                message->unk_28 += message->unk_2C;
                message->unk_28 = clamp_angle(message->unk_28);
                message->unk_2C *= 0.8;
                if (message->unk_20 < 10) {
                    message->unk_08 *= 0.5;
                    message->unk_0C *= 0.5;
                    message->unk_10 *= 0.5;
                    message->unk_14 = message->unk_08;
                    message->unk_18 = message->unk_0C;
                    message->unk_1C = message->unk_10;
                }

                message->unk_20--;
                if (message->unk_20 < 0) {
                    message->unk_44--;
                    if (message->unk_44 < 0) {
                        free_entity_model_by_index(modelIdx);
                        message->unk_00 = 0;
                    }
                }
            }
        }
    }

    if (!found) {
        heap_free(popup->message);
        popup->message = NULL;
        free_popup(popup);
    }
}

void func_8024F5AC(void* data) {
    PopupMessage* popup = data;
    Message* message = popup->message;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Matrix4f spD8;
    Matrix4f sp118;
    Matrix4f sp158;
    Matrix4f sp198;
    Matrix4f sp1D8;
    Mtx sp218;
    s32 i;

    for (i = 0; i < popup->messageIndex; i++, message++) {
        if (message->unk_00 != 0) {
            if (message->unk_24 != 0) {
                break;
            } else {
                s32 modelIdx = message->unk_04;

                guTranslateF(sp18, message->unk_38, message->unk_3C, message->unk_40);
                guRotateF(sp58, 0.0f, 1.0f, 0.0f, 0.0f);
                guRotateF(sp98, message->unk_30, 0.0f, 1.0f, 0.0f);
                guRotateF(spD8, message->unk_28, 0.0f, 0.0f, 1.0f);
                guScaleF(sp1D8, message->unk_34, message->unk_34, message->unk_34);
                guMtxCatF(spD8, sp58, sp158);
                guMtxCatF(sp158, sp98, sp118);
                guMtxCatF(sp1D8, sp118, sp158);
                guMtxCatF(sp158, sp18, sp198);
                guMtxF2L(sp198, &sp218);
                draw_entity_model_A(modelIdx, &sp218);
            }
        }
    }
}

void func_8024F768(void* data) {
    Message* message = data;
    s32 var_a3 = message->unk_44;

    if (var_a3 > 0xA) {
        var_a3 = 0xA;
    }
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, (var_a3 * 255) / 10);
}

void func_8024F7C8(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];

        if (popup->active && (popup->active & 0x10)) {
            Message* message = popup->message;
            s32 j;

            for (j = 0; j < popup->messageIndex; j++, message++) {
                if (message->unk_00 != 0) {
                    message->unk_24 = 0;
                    message->unk_20 = 1;
                    message->unk_44 = 20;
                }
            }
        }
    }
}

ApiStatus func_8024F84C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 arg4 = evt_get_variable(script, *args++);
    s32 arg5 = evt_get_variable(script, *args++);
    s32 arg6 = evt_get_variable(script, *args++);

    func_8024EFE0(x, y, z, arg4, arg5, arg6);
    return ApiStatus_DONE2;
}

ApiStatus func_8024F940(Evt* script, s32 isInitialCall) {
    func_8024F7C8();
    return ApiStatus_DONE2;
}

void btl_show_battle_message(s32 messageIndex, s32 duration) {
    PopupMessage* popup = btl_create_popup();

    if (popup != NULL) {
        popup->updateFunc = func_8024FB3C;
        popup->drawFunc = btl_show_message_popup;
        popup->unk_00 = 0;
        popup->unk_08 = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->unk_16 = 0;
        popup->unk_17 = 1;
        popup->message = NULL;
        D_8029F640 = 0;
        D_802838F8 = popup;
        D_8029F64A = 0;
        D_8029F64C = 0;
        D_8029F64E = 0;
        D_8029F650 = 0;
    }
}

void btl_show_variable_battle_message(s32 messageIndex, s32 duration, s32 varValue) {
    PopupMessage* popup = btl_create_popup();

    if (popup != NULL) {
        popup->updateFunc = func_8024FB3C;
        popup->drawFunc = btl_show_message_popup;
        popup->unk_00 = 0;
        popup->unk_08 = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->unk_16 = 0;
        popup->unk_17 = 1;
        popup->message = NULL;
        D_8029F640 = varValue;
        D_802838F8 = popup;
        D_8029F64A = 0;
        D_8029F64C = 0;
        D_8029F64E = 0;
        D_8029F650 = 0;
    }
}

s32 btl_is_popup_displayed(void) {
    return D_802838F8 != NULL;
}

#ifdef NON_MATCHING // requires data migration
void btl_set_popup_duration(s32 duration) {
    PopupMessage* popup = D_802838F8;

    if (D_8029F64A != NULL && popup != NULL) {
        popup->duration = duration;
    }
}
#else
INCLUDE_ASM(void, "17D6A0", btl_set_popup_duration);
#endif

void func_8024FAE8(void) {
    D_8029F64C = 1;
}

void func_8024FAFC(void) {
    D_8029F64C = 0;
}

void close_action_command_instruction_popup(void) {
    PopupMessage* popup = D_802838F8;

    if (popup != NULL && popup->messageIndex < 67 && popup->messageIndex >= 46) {
        popup->duration = 0;
    }
}

INCLUDE_ASM(s32, "17D6A0", func_8024FB3C);

void func_80250818(void);
INCLUDE_ASM(s32, "17D6A0", func_80250818);

void btl_show_message_popup(PopupMessage* popup) {
    s32 numLines;
    s32 posX;
    s32 posY = 80;
    s32 width;
    s32 msgWidth;
    s32 height;

    switch (popup->messageIndex) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 67:
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 80:
        case 82:
        case 83:
        case 84:
            if (popup->unk_17 != 0) {
                s32 messageID;

                popup->unk_17 = 0;
                messageID = bMessages[popup->messageIndex];
                msgWidth = get_msg_width(messageID, 0) + 30;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(9, 1);
            }
            break;
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
            if (popup->unk_17 != 0) {
                popup->unk_17 = 0;
                msgWidth = get_msg_width(bMessages[popup->messageIndex], 0) + 55;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                height = 40;
                set_window_properties(9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(9, 1);
            }
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
            if (popup->unk_17 != 0) {
                s32 messageID;

                popup->unk_17 = 0;
                messageID = bMessages[popup->messageIndex];
                set_message_value(D_8029F640, 0);
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(9, 1);
            }
            break;
        case 81:
            if (popup->unk_17 != 0) {
                s32 messageID;

                popup->unk_17 = 0;
                messageID = bMessages[popup->messageIndex];
                set_message_msg(bActorMessages[D_8029F640], 0);
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(9, posX, posY, width, height, 0, func_80250818, popup, -1);
                set_window_update(9, 1);
            }
            break;
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
            if (popup->unk_17 != 0) {
                s32 messageID;

                popup->unk_17 = 0;
                messageID = bMessages[popup->messageIndex];
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                posY = 192;
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                if (popup->messageIndex == 0x3B) {
                    posY = 120;
                    D_8029F64C = 1;
                }
                D_8029F64E = posY;
                D_8029F650 = D_802835D8[numLines];

                posY = D_8029F64E + D_8029F650;
                set_window_properties(9, posX, posY, width, height, 0, func_80250818, popup, -1);
                if (popup->messageIndex == 0x3B) {
                    set_window_update(9, 1);
                } else {
                    set_window_update(9, 8);
                }
            }
            break;
    }
}

ApiStatus ShowMessageBox(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 messageIndex = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    btl_show_battle_message(messageIndex, duration);
    return ApiStatus_DONE2;
}

ApiStatus ShowVariableMessageBox(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 messageIndex = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    s32 varValue = evt_get_variable(script, *args++);

    btl_show_variable_battle_message(messageIndex, duration, varValue);
    return ApiStatus_DONE2;
}

ApiStatus IsMessageBoxDisplayed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, btl_is_popup_displayed());
    return ApiStatus_DONE2;
}

ApiStatus WaitForMessageBoxDone(Evt* script, s32 isInitialCall) {
    return !btl_is_popup_displayed() * ApiStatus_DONE2;
}

ApiStatus ForceCloseMessageBox(Evt* script, s32 isInitialCall) {
    if (D_802838F8 != NULL) {
        D_802838F8->duration = 0;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetMessageBoxDuration(Evt* script, s32 isInitialCall) {
    btl_set_popup_duration(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_80251434(Evt* script, s32 isInitialCall) {
    func_8024FAE8();
    return ApiStatus_DONE2;
}

ApiStatus func_80251454(Evt* script, s32 isInitialCall) {
    func_8024FAFC();
    return ApiStatus_DONE2;
}

void func_80251474(Actor* actor) {
    ActorPart* part = actor->partsTable;

    while (part != NULL) {
        if (!(part->flags & ACTOR_PART_FLAG_INVISIBLE) &&
            part->idleAnimations != NULL &&
            !(part->flags & ACTOR_PART_FLAG_40000000))
        {
            f32 x = part->currentPos.x;
            f32 y = part->currentPos.y + (actor->size.y / 10);
            f32 z = part->currentPos.z;
            s32 f1 = (part->size.x + (part->size.x / 4)) * actor->scalingFactor;
            s32 f2 = (part->size.y - 2) * actor->scalingFactor;

            if (actor->flags & 0x8000) {
                y -= actor->size.y / 2;
            }

            fx_flashing_box_shockwave(0, x, y, z, f1, f2);
        }
        part = part->nextPart;
    }
}
