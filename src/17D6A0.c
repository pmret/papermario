#include "common.h"
#include "effects.h"

struct BattlePopup;
typedef void (*BattlePopupCallback)(struct BattlePopup* popup);
typedef struct BattlePopup {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ BattlePopupCallback unk_04;
    /* 0x08 */ BattlePopupCallback unk_08;
    /* 0x0C */ BattlePopupCallback drawFunc;
    /* 0x10 */ s16 active;
    /* 0x12 */ s16 messageIndex;
    /* 0x14 */ s16 duration;
    /* 0x16 */ s8 unk_16;
    /* 0x17 */ s8 unk_17;
    /* 0x18 */ s32* message;
} BattlePopup; // size = 0x1C

extern BattlePopup BattlePopups[32];
extern BattlePopup* D_802838F8;
extern s16 D_8029F64C;
extern s16 D_8029F640;
extern s16 D_8029F64A;
extern s16 D_8029F64E;
extern s16 D_8029F650;
extern void func_8024FB3C(BattlePopup* popup);
void btl_show_message_popup(BattlePopup* popup);

void func_8024EDC0(void) {
    BattlePopup* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(BattlePopups); i++) {
        popup = &BattlePopups[i];
        popup->active = 0;
        popup->message = NULL;
    }
}

void func_8024EDEC(void) {
    BattlePopup* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(BattlePopups); i++) {
        popup = &BattlePopups[i];
        if (popup->message != NULL) {
            heap_free(popup->message);
            popup->message = NULL;
        }
        popup->active = 0;
    }
}

void func_8024EE48(void) {
    BattlePopup* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(BattlePopups); i++) {
        popup = &BattlePopups[i];
        if (popup->active != 0 && popup->unk_04 != NULL) {
            popup->unk_04(popup);
        }
    }
}

void func_8024EEA8(void) {
    BattlePopup* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(BattlePopups); i++) {
        popup = &BattlePopups[i];
        if (popup->active != 0 && popup->unk_08 != NULL) {
            popup->unk_08(popup);
        }
    }
}

void btl_draw_popup_messages(void) {
    BattlePopup* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(BattlePopups); i++) {
        popup = &BattlePopups[i];
        if (popup->active != 0 && popup->drawFunc != NULL) {
            popup->drawFunc(popup);
        }
    }
}

BattlePopup* btl_create_popup(void) {
    BattlePopup* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(BattlePopups); i++) {
        popup = &BattlePopups[i];
        if (popup->active == 0) {
            popup->active = 1;
            return popup;
        }
    }

    return NULL;
}

void free_popup(BattlePopup* popup) {
    if (popup->message != NULL) {
        heap_free(popup->message);
        popup->message = NULL;
    }
    popup->active = 0;
}

void func_8024EFE0(f32 x, f32 y, f32 z, s32, s32, s32);
INCLUDE_ASM(s32, "17D6A0", func_8024EFE0);

INCLUDE_ASM(s32, "17D6A0", func_8024F394);

INCLUDE_ASM(s32, "17D6A0", func_8024F5AC);

INCLUDE_ASM(s32, "17D6A0", func_8024F768);

void func_8024F7C8(void);
INCLUDE_ASM(s32, "17D6A0", func_8024F7C8);

s32 func_8024F84C(Evt* script, s32 isInitialCall) {
    s32 arg5;
    s32 arg4;
    s32 z;
    s32 y;
    s32 x;
    Bytecode* args;

    args = script->ptrReadPos;
    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);
    arg4 = evt_get_variable(script, *args++);
    arg5 = evt_get_variable(script, *args++);
    func_8024EFE0(x, y, z, arg4, arg5, evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_8024F940(Evt* script, s32 isInitialCall) {
    func_8024F7C8();
    return ApiStatus_DONE2;
}

void btl_show_battle_message(s32 messageIndex, s32 duration) {
    BattlePopup* popup = btl_create_popup();
    if (popup != NULL) {
        popup->unk_04 = &func_8024FB3C;
        popup->drawFunc = &btl_show_message_popup;
        popup->unk_00 = 0;
        popup->unk_08 = 0;
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
    BattlePopup* popup = btl_create_popup();
    if (popup != NULL) {
        popup->unk_04 = &func_8024FB3C;
        popup->drawFunc = &btl_show_message_popup;
        popup->unk_00 = 0;
        popup->unk_08 = 0;
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
    BattlePopup* popup = D_802838F8;
    if (D_8029F64A != NULL && popup != NULL) {
        popup->duration = duration;
    }
}
#else
void btl_set_popup_duration(s32 duration);
INCLUDE_ASM(void, "17D6A0", btl_set_popup_duration);
#endif

void func_8024FAE8(void) {
    D_8029F64C = 1;
}

void func_8024FAFC(void) {
    D_8029F64C = 0;
}

void close_action_command_instruction_popup(void) {
    BattlePopup* popup = D_802838F8;
    if (popup != NULL) {
        if (popup->messageIndex >= 67) {
            return;
        }
        if (popup->messageIndex < 46) {
            return;
        }
        popup->duration = 0;
    }
}

INCLUDE_ASM(s32, "17D6A0", func_8024FB3C);

INCLUDE_ASM(s32, "17D6A0", func_80250818);

INCLUDE_ASM(s32, "17D6A0", btl_show_message_popup);

ApiStatus ShowMessageBox(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    btl_show_battle_message(evt_get_variable(script, *args++), evt_get_variable(script, *args++));
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

INCLUDE_ASM(s32, "17D6A0", func_80251474);
