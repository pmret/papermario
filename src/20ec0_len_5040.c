#include "common.h"
#include "map.h"

extern s32 D_800A0F40;
extern PopupMessage D_800A0BC0[32];

void update_merlee_message(PopupMessage* popup);
void draw_merlee_message(PopupMessage* popup);
void func_80045BC8(void);
void func_80045FB4(void);

extern s16 D_80078160[];
extern s32 D_80078168[];

void func_80045AC0(void) {
    PopupMessage* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        popup = &D_800A0BC0[i];
        popup->active = 0;
        popup->message = 0;
    }
    
    create_generic_entity_world(NULL, func_80045BC8);
    func_80045FB4();
}

void func_80045B10(void) {
    PopupMessage* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        popup = &D_800A0BC0[i];
        if (popup->message != NULL) {
            heap_free(popup->message);
        }
        popup->active = 0;
    }
}

void update_merlee_messages(void) {
    PopupMessage* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        popup = &D_800A0BC0[i];
        if (popup->active && popup->unk_04 != NULL) {
            popup->unk_04(popup);
        }
    }
}

void func_80045BC8(void) {
    PopupMessage* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        popup = &D_800A0BC0[i];
        if (popup->active && popup->unk_08 != NULL) {
            popup->unk_08(popup);
        }
    }
}

void draw_merlee_messages(void) {
    PopupMessage* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        popup = &D_800A0BC0[i];
        if (popup->active && popup->drawFunc != NULL) {
            popup->drawFunc(popup);
        }
    }
}

PopupMessage* get_current_merlee_message(void) {
    PopupMessage* popup;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        popup = &D_800A0BC0[i];
        if (!popup->active) {
            popup->active = TRUE;
            return popup;
        }
    }

    return NULL;
}

void dispose_merlee_message(PopupMessage* message) {
    if (message->message != NULL) {
        heap_free(message->message);
        message->message = NULL;
    }
    message->active = 0;
}

void show_merlee_message(s16 messageIndex, s16 duration) {
    PopupMessage* temp_v0;

    temp_v0 = get_current_merlee_message();
    if (temp_v0 != 0) {
        temp_v0->unk_04 = update_merlee_message;
        temp_v0->drawFunc = draw_merlee_message;
        temp_v0->unk_17 = 1;
        temp_v0->unk_00 = 0;
        temp_v0->unk_08 = NULL;
        temp_v0->messageIndex = messageIndex;
        temp_v0->duration = duration;
        temp_v0->unk_16 = 0;
        D_800A0F40 = 1;
    }
}

#ifdef NON_MATCHING // .rodata alignment, will match once all other functions in this file are matched
void update_merlee_message(PopupMessage* popup) {
    s32 closeMessage = 0;
    switch (popup->unk_16) {
        case 0:
            popup->unk_16 = 1;
            break;
        case 1:
            popup->unk_16 = 2;
            break;
        case 2:
            if (gGameStatusPtr->pressedButtons & 0xC000) {
                popup->duration = 0;
            }
            if (popup->duration != 0) {
                popup->duration--;
            } else {
                popup->unk_16 = 3;
            }
            break;
        case 3:
            popup->unk_16 = 4;
            break;
        case 4:
            closeMessage = 1;
            break;
    }
    if (closeMessage) {
        set_window_update(9, 2);
        D_800A0F40 = 0;
        dispose_merlee_message(popup);
    }
}
#else
INCLUDE_ASM(s32, "20ec0_len_5040", update_merlee_message);
#endif

void draw_merlee_message_string(PopupMessage* popup);
INCLUDE_ASM(s32, "20ec0_len_5040", draw_merlee_message_string);

void draw_merlee_message(PopupMessage* popup) {
    s32 messageID;
    s32 xPos;
    s32 width;

    if (popup->unk_17 != 0) {
        popup->unk_17 = 0;
        messageID = D_80078168[popup->messageIndex];
        width = get_msg_width(messageID, 0) + 30;
        xPos = 160 - (width / 2);
        set_window_properties(9, xPos, 80, width, D_80078160[get_msg_lines(messageID) - 1], 0, draw_merlee_message_string, popup, -1);
        set_window_update(9, 1);
    }
}

s32 is_merlee_message_done(void) {
    return D_800A0F40;
}

INCLUDE_ASM(s32, "20ec0_len_5040", func_80045FB4);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80046030);

INCLUDE_ASM(s32, "20ec0_len_5040", draw_all_status_icons);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_set);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_all_status_icons);

INCLUDE_ASM(s32, "20ec0_len_5040", set_status_icons_properties);

INCLUDE_ASM(s32, "20ec0_len_5040", func_800477F4);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047820);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_1);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_1);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047928);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_2);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_2);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047A30);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_3);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_3);

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047B38);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_4);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_4);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_boost_jump);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_boost_jump);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_boost_jump);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_boost_hammer);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_boost_hammer);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_boost_hammer);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_boost_partner);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_boost_partner);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_boost_partner);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_surprise);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_surprise);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_surprise);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_peril);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_peril);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_peril);

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_danger);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_danger);

INCLUDE_ASM(s32, "20ec0_len_5040", enable_status_icon_danger);
