#include "common.h"
#include "npc.h"

typedef struct HudComplexStatusIcon {
	/* 0x000 */ s8 active;
	/* 0x001 */ s8 removing;
	/* 0x002 */ char unk_02[6];
	/* 0x008 */ s32 hudElemIndex;
	/* 0x00C */ s32 null;
} HudComplexStatusIcon;/* size = 0x10 */

typedef struct HudSimpleStatusIcon {
	/* 0x000 */ s8 active;
	/* 0x001 */ s8 removing;
	/* 0x004 */ s32 hudElemIndex;
} HudSimpleStatusIcon;/* size = 0x8 */

typedef struct HudStatusIcon {
	/* 0x000 */ s32 flags;
	/* 0x004 */ Vec3f worldPos;
	/* 0x010 */ f32 status1Radius;
	/* 0x014 */ f32 status1OffsetY;
	/* 0x018 */ f32 status2Radius;
	/* 0x01C */ f32 status2OffsetY;
	/* 0x020 */ f32 status3Radius;
	/* 0x024 */ f32 status3OffsetY;
	/* 0x028 */ f32 status4Radius;
	/* 0x02C */ f32 status4OffsetY;
	/* 0x030 */ f32 offsetY;
	/* 0x034 */ f32 null;
	/* 0x038 */ HudComplexStatusIcon status1;
	/* 0x048 */ HudComplexStatusIcon status2;
	/* 0x058 */ HudComplexStatusIcon status3;
	/* 0x068 */ HudComplexStatusIcon status4;
	/* 0x078 */ HudSimpleStatusIcon boostJump;
	/* 0x080 */ s32 prevIndexBoostJump;
	/* 0x084 */ HudSimpleStatusIcon boostHammer;
	/* 0x08C */ s32 prevIndexBoostHammer;
	/* 0x090 */ HudSimpleStatusIcon boostPartner;
	/* 0x098 */ HudSimpleStatusIcon surprise;
	/* 0x0A0 */ HudSimpleStatusIcon peril;
	/* 0x0A8 */ HudSimpleStatusIcon danger;
} HudStatusIcon;/* size = 0xB0 */

extern HudStatusIcon *D_800A0F44;

extern s32 D_800A0F40;
extern PopupMessage D_800A0BC0[32];
extern s16 D_80078160[];
extern s32 D_80078168[];

void update_merlee_message(PopupMessage* popup);
void draw_merlee_message(PopupMessage* popup);
void func_80045BC8(void);
void func_80045FB4(void);

void func_80045AC0(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        PopupMessage* popup = &D_800A0BC0[i];
        popup->active = FALSE;
        popup->message = NULL;
    }

    create_generic_entity_world(NULL, func_80045BC8);
    func_80045FB4();
}

void func_80045B10(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        PopupMessage* popup = &D_800A0BC0[i];
        if (popup->message != NULL) {
            heap_free(popup->message);
        }
        popup->active = FALSE;
    }
}

void update_merlee_messages(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        PopupMessage* popup = &D_800A0BC0[i];
        if (popup->active && popup->updateFunc != NULL) {
            popup->updateFunc(popup);
        }
    }
}

void func_80045BC8(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        PopupMessage* popup = &D_800A0BC0[i];
        if (popup->active && popup->unk_08 != NULL) {
            popup->unk_08(popup);
        }
    }
}

void draw_merlee_messages(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        PopupMessage* popup = &D_800A0BC0[i];
        if (popup->active && popup->drawFunc != NULL) {
            popup->drawFunc(popup);
        }
    }
}

PopupMessage* get_current_merlee_message(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        PopupMessage* popup = &D_800A0BC0[i];
        if (!popup->active) {
            popup->active = TRUE;
            return popup;
        }
    }

    return NULL;
}

void dispose_merlee_message(PopupMessage* popup) {
    if (popup->message != NULL) {
        heap_free(popup->message);
        popup->message = NULL;
    }
    popup->active = FALSE;
}

void show_merlee_message(s16 messageIndex, s16 duration) {
    PopupMessage* popup = get_current_merlee_message();

    if (popup != NULL) {
        popup->updateFunc = update_merlee_message;
        popup->drawFunc = draw_merlee_message;
        popup->unk_17 = 1;
        popup->unk_00 = 0;
        popup->unk_08 = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->unk_16 = 0;
        D_800A0F40 = 1;
    }
}

#ifdef NON_MATCHING // .rodata alignment, will match once all other functions in this file are matched
void update_merlee_message(PopupMessage* popup) {
    s32 closeMessage = FALSE;

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
            closeMessage = TRUE;
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

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_debuff);

void enable_status_1(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= 0x4;
}

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047928);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_static);

void enable_status_2(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= 0x8;
}

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047A30);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_transparent);

void enable_status_3(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= 0x10;
}

INCLUDE_ASM(s32, "20ec0_len_5040", func_80047B38);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_4);

void enable_status_4(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= 0x20;
}

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_boost_jump);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_boost_jump);

void enable_status_icon_boost_jump(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= 0x40;
}

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_boost_hammer);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_boost_hammer);

void enable_status_icon_boost_hammer(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= 0x80;
}

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_boost_partner);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_boost_partner);

void enable_status_icon_boost_partner(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= 0x100;
}

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_surprise);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_surprise);

void enable_status_icon_surprise(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= 0x200;
}

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_peril);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_peril);

void enable_status_icon_peril(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= 0x400;
}

INCLUDE_ASM(s32, "20ec0_len_5040", create_status_icon_danger);

INCLUDE_ASM(s32, "20ec0_len_5040", remove_status_icon_danger);

void enable_status_icon_danger(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= 0x800;
}
