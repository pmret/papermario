#include "common.h"
#include "effects.h"

// from 190B20.c
extern s32 bMessages[];

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

INCLUDE_ASM(s32, "17D6A0", func_8024F394);

INCLUDE_ASM(s32, "17D6A0", func_8024F5AC);

INCLUDE_ASM(s32, "17D6A0", func_8024F768);

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

INCLUDE_ASM(s32, "17D6A0", func_80250818);

INCLUDE_ASM(s32, "17D6A0", btl_show_message_popup);

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
