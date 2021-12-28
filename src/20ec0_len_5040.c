#include "common.h"
#include "npc.h"
#include "hud_element.h"

enum StatusIconFlag {
    STATUS_ICON_FLAG_DEBUFF        = 0x004,
    STATUS_ICON_FLAG_STATIC        = 0x008,
    STATUS_ICON_FLAG_TRANSPARENT   = 0x010,
    STATUS_ICON_FLAG_STATUS_4      = 0x020,
    STATUS_ICON_FLAG_BOOST_JUMP    = 0x040,
    STATUS_ICON_FLAG_BOOST_HAMMER  = 0x080,
    STATUS_ICON_FLAG_BOOST_PARTNER = 0x100,
    STATUS_ICON_FLAG_SURPRISE      = 0x200,
    STATUS_ICON_FLAG_PERIL         = 0x400,
    STATUS_ICON_FLAG_DANGER        = 0x800,
};

typedef struct HudComplexStatusIcon {
	/* 0x0 */ s8 active;
	/* 0x1 */ s8 removing;
	/* 0x2 */ s8 unk_02;
	/* 0x3 */ s8 unk_03;
	/* 0x4 */ s8 unk_04;
	/* 0x5 */ s8 unk_05;
	/* 0x8 */ s32 hudElemIndex;
	/* 0xC */ s32 unk_0C;
} HudComplexStatusIcon; // size = 0x10

typedef struct HudSimpleStatusIcon {
	/* 0x0 */ s8 active;
	/* 0x1 */ s8 removing;
	/* 0x4 */ s32 hudElemIndex;
} HudSimpleStatusIcon; // size = 0x8

typedef struct HudStatusIcon {
	/* 0x00 */ s32 flags;
	/* 0x04 */ Vec3f worldPos;
	/* 0x10 */ f32 status1Radius;
	/* 0x14 */ f32 status1OffsetY;
	/* 0x18 */ f32 status2Radius;
	/* 0x1C */ f32 status2OffsetY;
	/* 0x20 */ f32 status3Radius;
	/* 0x24 */ f32 status3OffsetY;
	/* 0x28 */ f32 status4Radius;
	/* 0x2C */ f32 status4OffsetY;
	/* 0x30 */ f32 offsetY;
	/* 0x34 */ f32 unk_34;
	/* 0x38 */ HudComplexStatusIcon status1;
	/* 0x48 */ HudComplexStatusIcon status2;
	/* 0x58 */ HudComplexStatusIcon status3;
	/* 0x68 */ HudComplexStatusIcon status4;
	/* 0x78 */ HudSimpleStatusIcon boostJump;
	/* 0x80 */ s32 prevIndexBoostJump;
	/* 0x84 */ HudSimpleStatusIcon boostHammer;
	/* 0x8C */ s32 prevIndexBoostHammer;
	/* 0x90 */ HudSimpleStatusIcon boostPartner;
	/* 0x98 */ HudSimpleStatusIcon surprise;
	/* 0xA0 */ HudSimpleStatusIcon peril;
	/* 0xA8 */ HudSimpleStatusIcon danger;
} HudStatusIcon; // size = 0xB0

extern HudStatusIcon *D_800A0F44;
extern HudElementAnim D_80108A14[];
extern HudElementAnim D_801089C4[];
extern HudElementAnim D_8010760C[];
extern HudElementAnim D_801075E0[];
extern HudElementAnim D_80107314[];
extern HudElementAnim D_8010701C[];
extern HudElementAnim D_8010717C[];
extern HudElementAnim D_80107474[];

extern s32 D_800A0F40;
extern PopupMessage D_800A0BC0[32];
extern s16 D_80078160[];
extern s16 D_80078164[];
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

// TODO remove once all other functions in this file are matched
const static f32 padding = 0.0f;

void draw_merlee_message_string(PopupMessage* popup, s32 posX, s32 posY) {
    s32 messageID = D_80078168[popup->messageIndex];

    posY += 6;
    posX += 15;

    posY += D_80078164[get_msg_lines(messageID) - 1];

    draw_msg(messageID, posX, posY, 255, 15, 0);
}

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

void remove_all_status_icons(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    remove_status_debuff(iconID);
    remove_status_static(iconID);
    remove_status_transparent(iconID);
    remove_status_4(iconID);
    remove_status_icon_boost_jump(iconID);
    remove_status_icon_boost_hammer(iconID);
    remove_status_icon_boost_partner(iconID);
    remove_status_icon_surprise(iconID);
    remove_status_icon_peril(iconID);
    remove_status_icon_danger(iconID);
    statusIcon->flags = 0;
}

INCLUDE_ASM(s32, "20ec0_len_5040", set_status_icons_properties);

void func_800477F4(s32 iconID, f32 offsetY, f32 arg2) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->offsetY = offsetY;
    statusIcon->unk_34 = arg2;
}

void func_80047820(s32 iconID, s32 arg1) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags &= ~STATUS_ICON_FLAG_DEBUFF;
    if (statusIcon->status1.active != arg1) {
        remove_status_debuff(iconID);
        statusIcon->status1.active = arg1;
        statusIcon->status1.unk_02 = 1;
    }
}

void remove_status_debuff(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->status1.active && !statusIcon->status1.removing) {
        statusIcon->status1.removing = statusIcon->status1.active;
        statusIcon->status1.unk_03 = TRUE;
        statusIcon->status1.active = FALSE;
        statusIcon->status1.unk_02 = FALSE;
        statusIcon->status1.unk_05 = 10;
        statusIcon->status1.unk_0C = statusIcon->status1.hudElemIndex;
    }
}

void enable_status_1(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_DEBUFF;
}

void func_80047928(s32 iconID, s32 arg1) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags &= ~STATUS_ICON_FLAG_STATIC;
    if (statusIcon->status2.active != arg1) {
        remove_status_static(iconID);
        statusIcon->status2.active = arg1;
        statusIcon->status2.unk_02 = 1;
    }
}

void remove_status_static(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->status2.active && !statusIcon->status2.removing) {
        statusIcon->status2.removing = statusIcon->status2.active;
        statusIcon->status2.unk_03 = TRUE;
        statusIcon->status2.active = FALSE;
        statusIcon->status2.unk_02 = FALSE;
        statusIcon->status2.unk_05 = 10;
        statusIcon->status2.unk_0C = statusIcon->status2.hudElemIndex;
    }
}

void enable_status_2(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_STATIC;
}

void func_80047A30(s32 iconID, s32 arg1) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags &= ~STATUS_ICON_FLAG_TRANSPARENT;
    if (statusIcon->status3.active != arg1) {
        remove_status_transparent(iconID);
        statusIcon->status3.active = arg1;
        statusIcon->status3.unk_02 = 1;
    }
}

void remove_status_transparent(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->status3.active && !statusIcon->status3.removing) {
        statusIcon->status3.removing = statusIcon->status3.active;
        statusIcon->status3.unk_03 = TRUE;
        statusIcon->status3.active = FALSE;
        statusIcon->status3.unk_02 = FALSE;
        statusIcon->status3.unk_05 = 10;
        statusIcon->status3.unk_0C = statusIcon->status3.hudElemIndex;
    }
}

void enable_status_3(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_TRANSPARENT;
}

void func_80047B38(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags &= ~STATUS_ICON_FLAG_STATUS_4;
    if (!statusIcon->status4.active) {
        statusIcon->status4.active = TRUE;
        statusIcon->status4.unk_02 = TRUE;
    }
}

void remove_status_4(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->status4.active && !statusIcon->status4.removing) {
        statusIcon->status4.removing = statusIcon->status4.active;
        statusIcon->status4.unk_03 = TRUE;
        statusIcon->status4.active = FALSE;
        statusIcon->status4.unk_02 = FALSE;
        statusIcon->status4.unk_05 = 10;
        statusIcon->status4.unk_0C = statusIcon->status4.hudElemIndex;
    }
}

void enable_status_4(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_STATUS_4;
}

void create_status_icon_boost_jump(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];
    s32 hudElement;

    statusIcon->flags &= ~STATUS_ICON_FLAG_BOOST_JUMP;
    if (!statusIcon->boostJump.active) {
        statusIcon->boostJump.active = TRUE;
        hudElement = create_hud_element(D_8010701C);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->boostJump.hudElemIndex = hudElement;
    }
}

void remove_status_icon_boost_jump(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->boostJump.active) {
        s32 hudElemIndex = statusIcon->boostJump.hudElemIndex;
        statusIcon->boostJump.active = FALSE;
        statusIcon->boostJump.removing = TRUE;
        statusIcon->prevIndexBoostJump = hudElemIndex;
        set_hud_element_anim(hudElemIndex, &D_8010717C[0]);
    }
}

void enable_status_icon_boost_jump(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_BOOST_JUMP;
}

void create_status_icon_boost_hammer(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];
    s32 hudElement;

    statusIcon->flags &= ~STATUS_ICON_FLAG_BOOST_HAMMER;
    if (!statusIcon->boostHammer.active) {
        statusIcon->boostHammer.active = TRUE;
        hudElement = create_hud_element(D_80107314);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->boostHammer.hudElemIndex = hudElement;
    }
}

void remove_status_icon_boost_hammer(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->boostHammer.active) {
        s32 hudElemIndex = statusIcon->boostHammer.hudElemIndex;
        statusIcon->boostHammer.active = FALSE;
        statusIcon->boostHammer.removing = FALSE;
        statusIcon->prevIndexBoostHammer = hudElemIndex;
        set_hud_element_anim(hudElemIndex, &D_80107474[0]);
    }
}

void enable_status_icon_boost_hammer(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_BOOST_HAMMER;
}

void create_status_icon_boost_partner(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];
    s32 hudElement;

    statusIcon->flags &= ~STATUS_ICON_FLAG_BOOST_PARTNER;
    if (!statusIcon->boostPartner.active) {
        statusIcon->boostPartner.active = TRUE;
        hudElement = create_hud_element(D_801075E0);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->boostPartner.hudElemIndex = hudElement;
    }
}

void remove_status_icon_boost_partner(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->boostPartner.active) {
        statusIcon->boostPartner.active = FALSE;
        free_hud_element(statusIcon->boostPartner.hudElemIndex);
    }
}

void enable_status_icon_boost_partner(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_BOOST_PARTNER;
}

void create_status_icon_surprise(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];
    s32 hudElement;

    statusIcon->flags &= ~STATUS_ICON_FLAG_SURPRISE;
    if (!statusIcon->surprise.active) {
        statusIcon->surprise.active = TRUE;
        hudElement = create_hud_element(D_8010760C);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->surprise.hudElemIndex = hudElement;
    }
}

void remove_status_icon_surprise(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->surprise.active) {
        statusIcon->surprise.active = FALSE;
        free_hud_element(statusIcon->surprise.hudElemIndex);
    }
}

void enable_status_icon_surprise(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_SURPRISE;
}

void create_status_icon_peril(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];
    s32 hudElement;

    statusIcon->flags &= ~STATUS_ICON_FLAG_PERIL;
    if (!statusIcon->peril.active) {
        statusIcon->peril.active = TRUE;
        hudElement = create_hud_element(D_801089C4);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->peril.hudElemIndex = hudElement;
    }
}

void remove_status_icon_peril(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->peril.active) {
        statusIcon->peril.active = FALSE;
        free_hud_element(statusIcon->peril.hudElemIndex);
    }
}

void enable_status_icon_peril(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_PERIL;
}

void create_status_icon_danger(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];
    s32 hudElement;

    statusIcon->flags &= ~STATUS_ICON_FLAG_DANGER;
    if (!statusIcon->danger.active) {
        statusIcon->danger.active = TRUE;
        hudElement = create_hud_element(D_80108A14);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->danger.hudElemIndex = hudElement;
    }
}

void remove_status_icon_danger(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->danger.active) {
        statusIcon->danger.active = FALSE;
        free_hud_element(statusIcon->danger.hudElemIndex);
    }
}

void enable_status_icon_danger(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_DANGER;
}
