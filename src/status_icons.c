#include "common.h"
#include "npc.h"
#include "hud_element.h"

#define MAX_ICONS (64)

enum StatusIconFlag {
    STATUS_ICON_FLAG_USED             = 0x001,
    STATUS_ICON_FLAG_BATTLE           = 0x002,
    STATUS_ICON_FLAG_DEBUFF           = 0x004,
    STATUS_ICON_FLAG_STATIC           = 0x008,
    STATUS_ICON_FLAG_TRANSPARENT      = 0x010,
    STATUS_ICON_FLAG_STATUS_CHILL_OUT = 0x020,
    STATUS_ICON_FLAG_BOOST_JUMP       = 0x040,
    STATUS_ICON_FLAG_BOOST_HAMMER     = 0x080,
    STATUS_ICON_FLAG_BOOST_PARTNER    = 0x100,
    STATUS_ICON_FLAG_SURPRISE         = 0x200,
    STATUS_ICON_FLAG_PERIL            = 0x400,
    STATUS_ICON_FLAG_DANGER           = 0x800,
};

enum StatusIconTask {
    STATUS_ICON_TASK_NONE = 0,
    STATUS_ICON_TASK_LOAD = 1,
    STATUS_ICON_TASK_DRAW = 2,
};

typedef struct HudComplexStatusIcon {
    /* 0x0 */ s8 active;
    /* 0x1 */ s8 removing;
    /* 0x2 */ s8 activeTask;
    /* 0x3 */ s8 removingTask;
    /* 0x4 */ s8 unk_04;
    /* 0x5 */ s8 frameCounter;
    /* 0x8 */ s32 activeElementID;
    /* 0xC */ s32 removingElementID;
} HudComplexStatusIcon; // size = 0x10

typedef struct HudSimpleStatusIcon {
    /* 0x0 */ s8 active;
    /* 0x1 */ s8 removing;
    /* 0x4 */ s32 activeElementID;
} HudSimpleStatusIcon; // size = 0x8

typedef struct HudStatusIcon {
    /* 0x00 */ s32 flags;
    /* 0x04 */ Vec3f worldPos;
    /* 0x10 */ s32 status1Radius;
    /* 0x14 */ s32 status1OffsetY;
    /* 0x18 */ s32 status2Radius;
    /* 0x1C */ s32 status2OffsetY;
    /* 0x20 */ s32 status3Radius;
    /* 0x24 */ s32 status3OffsetY;
    /* 0x28 */ s32 status4Radius;
    /* 0x2C */ s32 status4OffsetY;
    /* 0x30 */ s32 offsetY;
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

extern s16 D_80078160[];
extern s16 D_80078164[];
extern s32 D_80078168[];

extern HudScript HudScript_Item_Present;

extern PopupMessage D_800A0BC0[32];
extern s32 D_800A0F40;
extern HudStatusIcon* D_800A0F44;

extern HudScript HudScript_AsleepBegin;
extern HudScript HudScript_AsleepEnd;
extern HudScript HudScript_ElectrifiedBegin;
extern HudScript HudScript_ElectrifiedEnd;
extern HudScript HudScript_ParalyzedBegin;
extern HudScript HudScript_ParalyzedEnd;
extern HudScript HudScript_DizzyEnd;
extern HudScript HudScript_PoisonedBegin;
extern HudScript HudScript_PoisonedEnd;
extern HudScript HudScript_DizzyBegin;
extern HudScript HudScript_FrozenBegin;
extern HudScript HudScript_FrozenEnd;
extern HudScript HudScript_WeakenedLoop;
extern HudScript HudScript_WeakenedBegin;
extern HudScript HudScript_WeakenedEnd;
extern HudScript HudScript_StoppedBegin;
extern HudScript HudScript_StoppedEnd;
extern HudScript HudScript_ShrunkBegin;
extern HudScript HudScript_ShrunkEnd;
extern HudScript HudScript_TransparentBegin;
extern HudScript HudScript_TransparentEnd;
extern HudScript HudScript_BoostJumpBegin;
extern HudScript HudScript_BoostJumpEnd;
extern HudScript HudScript_BoostHammerBegin;
extern HudScript HudScript_BoostHammerEnd;
extern HudScript HudScript_BoostPartner;
extern HudScript HudScript_Surprise;
extern HudScript HudScript_Peril;
extern HudScript HudScript_Danger;


void update_merlee_message(PopupMessage* popup);
void draw_merlee_message(PopupMessage* popup);
void func_80045BC8(void);
void init_all_status_icons(void);
void update_all_status_icons(PopupMessage* popup);
void draw_all_status_icons(PopupMessage* popup);

void func_80045AC0(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A0BC0); i++) {
        PopupMessage* popup = &D_800A0BC0[i];
        popup->active = FALSE;
        popup->message = NULL;
    }

    create_generic_entity_world(NULL, func_80045BC8);
    init_all_status_icons();
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

void init_all_status_icons(void) {
    int i;
    HudStatusIcon* icons;
    PopupMessage* popup = get_current_merlee_message();

    if (popup != NULL) {
        popup->updateFunc = &update_all_status_icons;
        popup->unk_00 = 0;
        popup->unk_08 = NULL;
        popup->drawFunc = &draw_all_status_icons;
        popup->message = general_heap_malloc(64 * sizeof(HudStatusIcon));
        icons = D_800A0F44 = (HudStatusIcon*)(popup->message);
        ASSERT(icons != NULL);

        for (i = 0; i < MAX_ICONS; i++, icons++)
            icons->flags = 0;
    }
}

void update_all_status_icons(PopupMessage* popup) {
    HudStatusIcon* icon;
    int i;
    s32 elementID;

    for (i = 0, icon = D_800A0F44; i < MAX_ICONS; i++, icon++) {
        if (icon->flags == 0) {
            continue;
        }

        if (icon->status1.activeTask == STATUS_ICON_TASK_LOAD) {
            switch (icon->status1.active) {
                case STATUS_SLEEP:
                    elementID = icon->status1.activeElementID = create_hud_element(&HudScript_AsleepBegin);
                    break;
                case STATUS_PARALYZE:
                    elementID = icon->status1.activeElementID = create_hud_element(&HudScript_ParalyzedBegin);
                    break;
                case STATUS_DIZZY:
                    elementID = icon->status1.activeElementID = create_hud_element(&HudScript_DizzyBegin);
                    break;
                case STATUS_FEAR:
                    elementID = icon->status1.activeElementID = create_hud_element(&HudScript_WeakenedLoop);
                    break;
                case STATUS_STOP:
                    elementID = icon->status1.activeElementID = create_hud_element(&HudScript_StoppedBegin);
                    break;
                case STATUS_POISON:
                    elementID = icon->status1.activeElementID = create_hud_element(&HudScript_PoisonedBegin);
                    break;
                case STATUS_SHRINK:
                    elementID = icon->status1.activeElementID = create_hud_element(&HudScript_ShrunkBegin);
                    break;
                case STATUS_FROZEN:
                    elementID = icon->status1.activeElementID = create_hud_element(&HudScript_FrozenBegin);
                    break;
                default:
                    elementID = icon->status1.activeElementID = create_hud_element(&HudScript_Item_Present);
                    break;
            }
            set_hud_element_flags(elementID, 2);
            set_hud_element_flags(elementID, 0x80);
            icon->status1.activeTask = STATUS_ICON_TASK_DRAW;
        }

        switch (icon->status1.removingTask) {
            case STATUS_ICON_TASK_NONE:
                break;
            case STATUS_ICON_TASK_LOAD:
                switch (icon->status1.removing) {
                    case STATUS_SLEEP:
                        set_hud_element_anim(icon->status1.removingElementID, &HudScript_AsleepEnd);
                        break;
                    case STATUS_PARALYZE:
                        set_hud_element_anim(icon->status1.removingElementID, &HudScript_ParalyzedEnd);
                        break;
                    case STATUS_DIZZY:
                        set_hud_element_anim(icon->status1.removingElementID, &HudScript_DizzyEnd);
                        break;
                    case STATUS_FEAR:
                        set_hud_element_anim(icon->status1.removingElementID, &HudScript_WeakenedLoop);
                        break;
                    case STATUS_STOP:
                        set_hud_element_anim(icon->status1.removingElementID, &HudScript_StoppedEnd);
                        break;
                    case STATUS_POISON:
                        set_hud_element_anim(icon->status1.removingElementID, &HudScript_PoisonedEnd);
                        break;
                    case STATUS_SHRINK:
                        set_hud_element_anim(icon->status1.removingElementID, &HudScript_ShrunkEnd);
                        break;
                    case STATUS_FROZEN:
                        set_hud_element_anim(icon->status1.removingElementID, &HudScript_FrozenEnd);
                        break;
                    default:
                        set_hud_element_anim(icon->status1.removingElementID, &HudScript_Item_Present);
                        break;
                }

                icon->status1.frameCounter = 10;
                icon->status1.removingTask = STATUS_ICON_TASK_DRAW;
                break;

            case STATUS_ICON_TASK_DRAW:
                if (icon->status1.frameCounter != 0) {
                    icon->status1.frameCounter--;
                } else {
                    icon->status1.removing = 0;
                    free_hud_element(icon->status1.removingElementID);
                    icon->status1.removingTask = STATUS_ICON_TASK_NONE;
                }
                break;
        }

        if (icon->status2.activeTask == STATUS_ICON_TASK_LOAD) {
            switch (icon->status2.active) {
                case STATUS_STATIC:
                    elementID = icon->status2.activeElementID = create_hud_element(&HudScript_ElectrifiedBegin);
                    break;
                default:
                    elementID = icon->status2.activeElementID = create_hud_element(&HudScript_Item_Present);
                    break;
            }

            set_hud_element_flags(elementID, 2);
            set_hud_element_flags(elementID, 0x80);
            icon->status2.activeTask = STATUS_ICON_TASK_DRAW;
        }

        switch (icon->status2.removingTask) {
            case STATUS_ICON_TASK_NONE:
                break;
            case STATUS_ICON_TASK_LOAD:
                switch (icon->status2.removing) {
                    case STATUS_STATIC:
                        set_hud_element_anim(icon->status2.removingElementID, &HudScript_ElectrifiedEnd);
                        break;
                    default:
                        set_hud_element_anim(icon->status2.removingElementID, &HudScript_Item_Present);
                        break;
                }

                icon->status2.frameCounter = 20;
                icon->status2.removingTask = STATUS_ICON_TASK_DRAW;
                break;
            case STATUS_ICON_TASK_DRAW:
                if (icon->status2.frameCounter != 0) {
                    icon->status2.frameCounter--;
                } else {
                    icon->status2.removing = 0;
                    free_hud_element(icon->status2.removingElementID);
                    icon->status2.removingTask = STATUS_ICON_TASK_NONE;
                }
                break;
        }

        if (icon->status3.activeTask == STATUS_ICON_TASK_LOAD) {
            switch (icon->status3.active) {
                case STATUS_E:
                    elementID = icon->status3.activeElementID = create_hud_element(&HudScript_TransparentBegin);
                    break;
                default:
                    elementID = icon->status3.activeElementID = create_hud_element(&HudScript_Item_Present);
                    break;
            }

            set_hud_element_flags(elementID, 2);
            set_hud_element_flags(elementID, 0x80);
            icon->status3.activeTask = STATUS_ICON_TASK_DRAW;
        }

        switch (icon->status3.removingTask) {
            case STATUS_ICON_TASK_NONE:
                break;
            case STATUS_ICON_TASK_LOAD:
                switch (icon->status3.removing) {
                    case STATUS_E:
                        set_hud_element_anim(icon->status3.removingElementID, &HudScript_TransparentEnd);
                        break;
                    default:
                        set_hud_element_anim(icon->status3.removingElementID, &HudScript_Item_Present);
                        break;
                }

                icon->status3.frameCounter = 20;
                icon->status3.removingTask = STATUS_ICON_TASK_DRAW;
                break;
            case STATUS_ICON_TASK_DRAW:
                if (icon->status3.frameCounter != 0) {
                    icon->status3.frameCounter--;
                } else {
                    icon->status3.removing = 0;
                    free_hud_element(icon->status3.removingElementID);
                    icon->status3.removingTask = STATUS_ICON_TASK_NONE;
                }
                break;
        }

        if (icon->status4.activeTask == STATUS_ICON_TASK_LOAD) {
            elementID = icon->status4.activeElementID = create_hud_element(&HudScript_WeakenedBegin);
            set_hud_element_flags(elementID, 2);
            set_hud_element_flags(elementID, 0x80);
            icon->status4.activeTask = STATUS_ICON_TASK_DRAW;
        }

        switch (icon->status4.removingTask) {
            case STATUS_ICON_TASK_NONE:
                break;
            case STATUS_ICON_TASK_LOAD:
                set_hud_element_anim(icon->status4.removingElementID, &HudScript_WeakenedEnd);
                icon->status4.frameCounter = 20;
                icon->status4.removingTask = STATUS_ICON_TASK_DRAW;
                break;
            case STATUS_ICON_TASK_DRAW:
                if (icon->status4.frameCounter != 0) {
                    icon->status4.frameCounter--;
                } else {
                    icon->status4.removing = 0;
                    free_hud_element(icon->status4.removingElementID);
                    icon->status4.removingTask = STATUS_ICON_TASK_NONE;
                }
                break;
        }

        if (icon->boostJump.removing) {
            if (icon->boostJump.removing == 1) {
                s32 index = icon->prevIndexBoostJump;

                if (get_hud_element(index)->flags.as_word & 4) {
                    free_hud_element(index);
                    icon->boostJump.removing = 0;
                }
            }
        }

        if (icon->boostHammer.removing) {
            if (icon->boostHammer.removing == 1) {
                s32 index = icon->prevIndexBoostHammer;

                if (get_hud_element(index)->flags.as_word & 4) {
                    free_hud_element(index);
                    icon->boostHammer.removing = 0;
                }
            }
        }
    }
}

void draw_all_status_icons(PopupMessage* popup) {
    HudStatusIcon* icon;
    s32 elementId;
    f32 x, y, z;
    s32 screenX, screenY, screenZ;
    s32 isActiveDrawn, iconCounter;
    s32 offsetY;
    Camera* camera = &gCameras[gCurrentCameraID];
    int i;

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 12, 20, SCREEN_WIDTH - 12, SCREEN_HEIGHT - 20);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
    gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
    gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
    gDPSetTextureConvert(gMasterGfxPos++, G_TC_FILT);
    gDPSetCombineKey(gMasterGfxPos++, G_CK_NONE);
    gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);
    gDPNoOp(gMasterGfxPos++);
    gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
    gDPSetAlphaDither(gMasterGfxPos++, G_AD_DISABLE);
    gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);

    for (i = 0, icon = D_800A0F44; i < MAX_ICONS; i++, icon++) {
        if (icon->flags == 0) {
            continue;
        }

        iconCounter = 0;
        isActiveDrawn = 0;
        if (icon->status1.activeTask == STATUS_ICON_TASK_DRAW) {
            if (icon->flags & STATUS_ICON_FLAG_DEBUFF) {
                set_hud_element_flags(icon->status1.activeElementID, 2);
            } else if (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1) {
                clear_hud_element_flags(icon->status1.activeElementID, 2);

                x = icon->worldPos.x;
                y = icon->worldPos.y + icon->status1OffsetY;
                z = icon->worldPos.z;

                add_vec2D_polar(&x, &z, icon->status1Radius, clamp_angle(camera->currentYaw + 90));
                get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
                elementId = icon->status1.activeElementID;
                set_hud_element_render_pos(elementId, screenX - 8, screenY - 8);
                draw_hud_element_2(elementId);
                iconCounter = 1;
                isActiveDrawn = 1;
            }
        }

        if (icon->status1.removingTask == STATUS_ICON_TASK_DRAW && (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1)) {
            clear_hud_element_flags(icon->status1.removingElementID, 2);

            if (isActiveDrawn == 0) {
                iconCounter++;
            }

            x = icon->worldPos.x;
            y = icon->worldPos.y + icon->status1OffsetY;
            z = icon->worldPos.z;

            add_vec2D_polar(&x, &z, icon->status1Radius, clamp_angle(camera->currentYaw + 90));
            get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
            elementId = icon->status1.removingElementID;
            set_hud_element_render_pos(elementId, screenX - 8, screenY - 8);
            draw_hud_element_2(elementId);
        }

        isActiveDrawn = 0;
        if (icon->status2.activeTask == STATUS_ICON_TASK_DRAW) {
            if (icon->flags & STATUS_ICON_FLAG_STATIC) {
                set_hud_element_flags(icon->status2.activeElementID, 2);
            } else if (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1) {
                clear_hud_element_flags(icon->status2.activeElementID, 2);

                offsetY = 0;
                if (iconCounter == 0) {
                    offsetY = -17;
                }

                x = icon->worldPos.x;
                y = icon->worldPos.y + icon->status2OffsetY + offsetY;
                z = icon->worldPos.z;

                add_vec2D_polar(&x, &z, icon->status2Radius, clamp_angle(camera->currentYaw + 90));
                get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
                elementId = icon->status2.activeElementID;
                set_hud_element_render_pos(elementId, screenX - 8, screenY - 8);
                draw_hud_element_2(elementId);

                iconCounter++;
                isActiveDrawn = 1;
            }
        }

        if (icon->status2.removingTask == STATUS_ICON_TASK_DRAW && (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1)) {
            clear_hud_element_flags(icon->status2.removingElementID, 2);

            offsetY = 0;
            if (iconCounter == 0) {
                offsetY = -17;
            }
            if (isActiveDrawn == 0) {
                iconCounter++;
            }

            x = icon->worldPos.x;
            y = icon->worldPos.y + icon->status2OffsetY + offsetY;
            z = icon->worldPos.z;

            add_vec2D_polar(&x, &z, icon->status2Radius, clamp_angle(camera->currentYaw + 90));
            get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
            elementId = icon->status2.removingElementID;
            set_hud_element_render_pos(elementId, screenX - 8, screenY - 8);
            draw_hud_element_2(elementId);
        }

        isActiveDrawn = 0;
        if (icon->status3.activeTask == STATUS_ICON_TASK_DRAW) {
            if (icon->flags & STATUS_ICON_FLAG_TRANSPARENT) {
                set_hud_element_flags(icon->status3.activeElementID, 2);
            } else if (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1) {
                clear_hud_element_flags(icon->status3.activeElementID, 2);

                offsetY = 0;
                if (iconCounter == 1) {
                    offsetY = -17;
                } if (iconCounter == 0) {
                    offsetY = -34;
                }

                x = icon->worldPos.x;
                y = icon->worldPos.y + icon->status3OffsetY + offsetY;
                z = icon->worldPos.z;

                add_vec2D_polar(&x, &z, icon->status3Radius, clamp_angle(camera->currentYaw + 90));
                get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
                elementId = icon->status3.activeElementID;
                set_hud_element_render_pos(elementId, screenX - 8, screenY - 8);
                draw_hud_element_2(elementId);
                iconCounter++;
                isActiveDrawn = 1;
            }
        }

        if (icon->status3.removingTask == STATUS_ICON_TASK_DRAW && (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1)) {
            clear_hud_element_flags(icon->status3.removingElementID, 2);

            offsetY = 0;
            if (iconCounter == 1) {
                offsetY = -17;
            }
            if (iconCounter == 0) {
                offsetY = -34;
            }
            if (isActiveDrawn == 0) {
                iconCounter++;
            }

            x = icon->worldPos.x;
            y = icon->worldPos.y + icon->status3OffsetY + offsetY;
            z = icon->worldPos.z;

            add_vec2D_polar(&x, &z, icon->status3Radius, clamp_angle(camera->currentYaw + 90));
            get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
            elementId = icon->status3.removingElementID;
            set_hud_element_render_pos(elementId, screenX - 8, screenY - 8);
            draw_hud_element_2(elementId);
        }

        isActiveDrawn = 0;
        if (icon->status4.activeTask == STATUS_ICON_TASK_DRAW) {
            if (icon->flags & STATUS_ICON_FLAG_STATUS_CHILL_OUT) {
                set_hud_element_flags(icon->status4.activeElementID, 2);
            } else if (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1) {
                clear_hud_element_flags(icon->status4.activeElementID, 2);

                offsetY = 0;
                if (iconCounter == 2) {
                    offsetY = -17;
                }
                if (iconCounter == 1) {
                    offsetY = -34;
                }
                if (iconCounter == 0) {
                    offsetY = -51;
                }

                x = icon->worldPos.x;
                y = icon->worldPos.y + icon->status4OffsetY + offsetY;
                z = icon->worldPos.z;

                add_vec2D_polar(&x, &z, icon->status4Radius, clamp_angle(camera->currentYaw + 90));
                get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
                elementId = icon->status4.activeElementID;
                set_hud_element_render_pos(elementId, screenX - 8, screenY - 8);
                draw_hud_element_2(elementId);
                iconCounter++;
                isActiveDrawn = 1;
            }
        }

        if (icon->status4.removingTask == STATUS_ICON_TASK_DRAW && (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1)) {
            clear_hud_element_flags(icon->status4.removingElementID, 2);

            offsetY = 0;
            if (iconCounter == 2) {
                offsetY = -17;
            }
            if (iconCounter == 1) {
                offsetY = -34;
            }
            if (iconCounter == 0) {
                offsetY = -51;
            }
            if (isActiveDrawn == 0) {
                iconCounter++;
            }

            x = icon->worldPos.x;
            y = icon->worldPos.y + icon->status4OffsetY + offsetY;
            z = icon->worldPos.z;

            add_vec2D_polar(&x, &z, icon->status4Radius, clamp_angle(camera->currentYaw + 90));
            get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
            elementId = icon->status4.removingElementID;
            set_hud_element_render_pos(elementId, screenX - 8, screenY - 8);
            draw_hud_element_2(elementId);
        }

        do {
            if (icon->boostJump.active) {
                if (icon->flags & STATUS_ICON_FLAG_BOOST_JUMP) {
                    set_hud_element_flags(icon->boostJump.activeElementID, 2);
                } else if (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1) {
                    clear_hud_element_flags(icon->boostJump.activeElementID, 2);

                    x = icon->worldPos.x;
                    z = icon->worldPos.z;

                    get_screen_coords(gCurrentCameraID, x, icon->worldPos.y + icon->offsetY, z, &screenX, &screenY, &screenZ);
                    elementId = icon->boostJump.activeElementID;
                    set_hud_element_render_pos(elementId, screenX + 2, screenY - 12);
                    draw_hud_element_2(elementId);
                }
            }
        } while (0);

        if (icon->boostJump.removing) {
            clear_hud_element_flags(icon->prevIndexBoostJump, 2);

            x = icon->worldPos.x;
            z = icon->worldPos.z;

            get_screen_coords(gCurrentCameraID, x, icon->worldPos.y + icon->offsetY, z, &screenX, &screenY, &screenZ);
            elementId = icon->prevIndexBoostJump;
            set_hud_element_render_pos(elementId, screenX + 2, screenY - 12);
            draw_hud_element_2(elementId);
        }

        do {
            if (icon->boostHammer.active) {
                if (icon->flags & STATUS_ICON_FLAG_BOOST_HAMMER) {
                    set_hud_element_flags(icon->boostHammer.activeElementID, 2);
                } else if (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1) {
                    clear_hud_element_flags(icon->boostHammer.activeElementID, 2);

                    x = icon->worldPos.x;
                    z = icon->worldPos.z;

                    get_screen_coords(gCurrentCameraID, x, icon->worldPos.y + icon->offsetY, z, &screenX, &screenY, &screenZ);
                    elementId = icon->boostHammer.activeElementID;
                    set_hud_element_render_pos(elementId, screenX + 2, screenY - 12);
                    draw_hud_element_2(elementId);
                }
            }
        } while (0);

        if (icon->boostHammer.removing) {
            clear_hud_element_flags(icon->prevIndexBoostHammer, 2);

            x = icon->worldPos.x;
            z = icon->worldPos.z;

            get_screen_coords(gCurrentCameraID, x, icon->worldPos.y + icon->offsetY, z, &screenX, &screenY, &screenZ);
            elementId = icon->prevIndexBoostHammer;
            set_hud_element_render_pos(elementId, screenX + 2, screenY - 12);
            draw_hud_element_2(elementId);
        }

        do {
            if (icon->boostPartner.active) {
                if (icon->flags & STATUS_ICON_FLAG_BOOST_PARTNER) {
                    set_hud_element_flags(icon->boostPartner.activeElementID, 2);
                } else if (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1) {
                    clear_hud_element_flags(icon->boostPartner.activeElementID, 2);

                    x = icon->worldPos.x;
                    z = icon->worldPos.z;

                    get_screen_coords(gCurrentCameraID, x, icon->worldPos.y + icon->offsetY, z, &screenX, &screenY, &screenZ);
                    elementId = icon->boostPartner.activeElementID;
                    set_hud_element_render_pos(elementId, screenX + 2, screenY - 12);
                    draw_hud_element_2(elementId);
                }
            }
        } while (0);

        do {
            if (icon->surprise.active) {
                if (icon->flags & STATUS_ICON_FLAG_SURPRISE) {
                    set_hud_element_flags(icon->surprise.activeElementID, 2);
                } else if (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1) {
                    clear_hud_element_flags(icon->surprise.activeElementID, 2);

                    x = icon->worldPos.x;
                    z = icon->worldPos.z;

                    get_screen_coords(gCurrentCameraID, x, icon->worldPos.y + icon->offsetY, z, &screenX, &screenY, &screenZ);
                    elementId = icon->surprise.activeElementID;
                    set_hud_element_render_pos(elementId, screenX + 2, screenY - 15);
                    draw_hud_element_2(elementId);
                }
            }
        } while (0);

        do {
            if (icon->peril.active) {
                if (icon->flags & STATUS_ICON_FLAG_PERIL) {
                    set_hud_element_flags(icon->peril.activeElementID, 2);
                } else if (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1) {
                    clear_hud_element_flags(icon->peril.activeElementID, 2);

                    x = icon->worldPos.x;
                    z = icon->worldPos.z;

                    get_screen_coords(gCurrentCameraID, x, icon->worldPos.y + icon->offsetY, z, &screenX, &screenY, &screenZ);
                    elementId = icon->peril.activeElementID;
                    set_hud_element_render_pos(elementId, screenX + 2, screenY - 16);
                    draw_hud_element_2(elementId);
                }
            }
        } while (0);

        do {
            if (icon->danger.active) {
                if (icon->flags & STATUS_ICON_FLAG_DANGER) {
                    set_hud_element_flags(icon->danger.activeElementID, 2);
                } else if (icon->flags & STATUS_ICON_FLAG_BATTLE || gGameStatusPtr->isBattle != 1) {
                    clear_hud_element_flags(icon->danger.activeElementID, 2);

                    x = icon->worldPos.x;
                    z = icon->worldPos.z;

                    get_screen_coords(gCurrentCameraID, x, icon->worldPos.y + icon->offsetY, z, &screenX, &screenY, &screenZ);
                    elementId = icon->danger.activeElementID;
                    set_hud_element_render_pos(elementId, screenX + 2, screenY - 16);
                    draw_hud_element_2(elementId);
                }
            }
        } while (0);
    }
}

s32 create_status_icon_set(void) {
    s32 i;
    HudStatusIcon* icon;

    for (icon = D_800A0F44, i = 0; i < MAX_ICONS; icon++, i++) {
        if (icon->flags == 0) {
            break;
        }
    }

    ASSERT(i < MAX_ICONS);

    icon->flags = STATUS_ICON_FLAG_USED;
    if (gGameStatusPtr->isBattle) {
        icon->flags = STATUS_ICON_FLAG_BATTLE | STATUS_ICON_FLAG_USED;
    }

    icon->worldPos.x = 0;
    icon->worldPos.y = 0;
    icon->worldPos.z = 0;

    icon->status1Radius = 0;
    icon->status1OffsetY = 0;
    icon->status2Radius = 0;
    icon->status2OffsetY = 0;
    icon->status3Radius = 0;
    icon->status3OffsetY = 0;
    icon->status4Radius = 0;
    icon->status4OffsetY = 0;
    icon->status1.active = 0;
    icon->status1.removing = 0;
    icon->status1.activeTask = 0;
    icon->status1.removingTask = 0;
    icon->status2.active = 0;
    icon->status2.removing = 0;
    icon->status2.activeTask = 0;
    icon->status2.removingTask = 0;
    icon->status3.active = 0;
    icon->status3.removing = 0;
    icon->status3.activeTask = 0;
    icon->status3.removingTask = 0;
    icon->status4.active = 0;
    icon->status4.removing = 0;
    icon->status4.activeTask = 0;
    icon->status4.removingTask = 0;
    icon->boostJump.active = 0;
    icon->boostJump.removing = 0;
    icon->boostHammer.active = 0;
    icon->boostHammer.removing = 0;
    icon->boostPartner.active = 0;
    icon->surprise.active = 0;
    icon->peril.active = 0;
    icon->danger.active = 0;

    return i;
}

void remove_all_status_icons(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    remove_status_debuff(iconID);
    remove_status_static(iconID);
    remove_status_transparent(iconID);
    remove_status_chill_out(iconID);
    remove_status_icon_boost_jump(iconID);
    remove_status_icon_boost_hammer(iconID);
    remove_status_icon_boost_partner(iconID);
    remove_status_icon_surprise(iconID);
    remove_status_icon_peril(iconID);
    remove_status_icon_danger(iconID);
    statusIcon->flags = 0;
}

void set_status_icons_properties(s32 iconID, f32 x, f32 y, f32 z, s32 arg, s32 arg2, s32 radius, s32 offsetY) {
    HudStatusIcon* icon = &D_800A0F44[iconID];

    icon->worldPos.x = x;
    icon->worldPos.y = y;
    icon->worldPos.z = z;
    icon->status1Radius = radius + 17;
    icon->status1OffsetY = offsetY;
    icon->status2Radius = radius + 17;
    icon->status2OffsetY = offsetY + 17;
    icon->status3Radius = radius + 17;
    icon->status3OffsetY = offsetY + 34;
    icon->status4Radius = radius + 17;
    icon->status4OffsetY = offsetY + 51;
}

void set_status_icons_offset(s32 iconID, s32 offsetY, f32 arg2) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->offsetY = offsetY;
    statusIcon->unk_34 = arg2;
}

void create_status_debuff(s32 iconID, s32 statusID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags &= ~STATUS_ICON_FLAG_DEBUFF;
    if (statusIcon->status1.active != statusID) {
        remove_status_debuff(iconID);
        statusIcon->status1.active = statusID;
        statusIcon->status1.activeTask = STATUS_ICON_TASK_LOAD;
    }
}

void remove_status_debuff(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->status1.active && !statusIcon->status1.removing) {
        statusIcon->status1.removing = statusIcon->status1.active;
        statusIcon->status1.removingTask = STATUS_ICON_TASK_LOAD;
        statusIcon->status1.active = STATUS_END;
        statusIcon->status1.activeTask = STATUS_ICON_TASK_NONE;
        statusIcon->status1.frameCounter = 10;
        statusIcon->status1.removingElementID = statusIcon->status1.activeElementID;
    }
}

void enable_status_debuff(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_DEBUFF;
}

void create_status_static(s32 iconID, s32 statusID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags &= ~STATUS_ICON_FLAG_STATIC;
    if (statusIcon->status2.active != statusID) {
        remove_status_static(iconID);
        statusIcon->status2.active = statusID;
        statusIcon->status2.activeTask = 1;
    }
}

void remove_status_static(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->status2.active && !statusIcon->status2.removing) {
        statusIcon->status2.removing = statusIcon->status2.active;
        statusIcon->status2.removingTask = TRUE;
        statusIcon->status2.active = FALSE;
        statusIcon->status2.activeTask = FALSE;
        statusIcon->status2.frameCounter = 10;
        statusIcon->status2.removingElementID = statusIcon->status2.activeElementID;
    }
}

void enable_status_2(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_STATIC;
}

void create_status_transparent(s32 iconID, s32 statusID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags &= ~STATUS_ICON_FLAG_TRANSPARENT;
    if (statusIcon->status3.active != statusID) {
        remove_status_transparent(iconID);
        statusIcon->status3.active = statusID;
        statusIcon->status3.activeTask = 1;
    }
}

void remove_status_transparent(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->status3.active && !statusIcon->status3.removing) {
        statusIcon->status3.removing = statusIcon->status3.active;
        statusIcon->status3.removingTask = TRUE;
        statusIcon->status3.active = FALSE;
        statusIcon->status3.activeTask = FALSE;
        statusIcon->status3.frameCounter = 10;
        statusIcon->status3.removingElementID = statusIcon->status3.activeElementID;
    }
}

void enable_status_transparent(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_TRANSPARENT;
}

void create_status_chill_out(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags &= ~STATUS_ICON_FLAG_STATUS_CHILL_OUT;
    if (!statusIcon->status4.active) {
        statusIcon->status4.active = TRUE;
        statusIcon->status4.activeTask = TRUE;
    }
}

void remove_status_chill_out(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->status4.active && !statusIcon->status4.removing) {
        statusIcon->status4.removing = statusIcon->status4.active;
        statusIcon->status4.removingTask = TRUE;
        statusIcon->status4.active = FALSE;
        statusIcon->status4.activeTask = FALSE;
        statusIcon->status4.frameCounter = 10;
        statusIcon->status4.removingElementID = statusIcon->status4.activeElementID;
    }
}

void enable_status_chill_out(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_STATUS_CHILL_OUT;
}

void create_status_icon_boost_jump(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];
    s32 hudElement;

    statusIcon->flags &= ~STATUS_ICON_FLAG_BOOST_JUMP;
    if (!statusIcon->boostJump.active) {
        statusIcon->boostJump.active = TRUE;
        hudElement = create_hud_element(&HudScript_BoostJumpBegin);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->boostJump.activeElementID = hudElement;
    }
}

void remove_status_icon_boost_jump(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->boostJump.active) {
        s32 hudElemIndex = statusIcon->boostJump.activeElementID;
        statusIcon->boostJump.active = FALSE;
        statusIcon->boostJump.removing = TRUE;
        statusIcon->prevIndexBoostJump = hudElemIndex;
        set_hud_element_anim(hudElemIndex, &HudScript_BoostJumpEnd);
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
        hudElement = create_hud_element(&HudScript_BoostHammerBegin);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->boostHammer.activeElementID = hudElement;
    }
}

void remove_status_icon_boost_hammer(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->boostHammer.active) {
        s32 hudElemIndex = statusIcon->boostHammer.activeElementID;
        statusIcon->boostHammer.active = FALSE;
        statusIcon->boostHammer.removing = FALSE;
        statusIcon->prevIndexBoostHammer = hudElemIndex;
        set_hud_element_anim(hudElemIndex, &HudScript_BoostHammerEnd);
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
        hudElement = create_hud_element(&HudScript_BoostPartner);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->boostPartner.activeElementID = hudElement;
    }
}

void remove_status_icon_boost_partner(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->boostPartner.active) {
        statusIcon->boostPartner.active = FALSE;
        free_hud_element(statusIcon->boostPartner.activeElementID);
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
        hudElement = create_hud_element(&HudScript_Surprise);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->surprise.activeElementID = hudElement;
    }
}

void remove_status_icon_surprise(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->surprise.active) {
        statusIcon->surprise.active = FALSE;
        free_hud_element(statusIcon->surprise.activeElementID);
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
        hudElement = create_hud_element(&HudScript_Peril);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->peril.activeElementID = hudElement;
    }
}

void remove_status_icon_peril(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->peril.active) {
        statusIcon->peril.active = FALSE;
        free_hud_element(statusIcon->peril.activeElementID);
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
        hudElement = create_hud_element(&HudScript_Danger);
        set_hud_element_flags(hudElement, 2);
        set_hud_element_flags(hudElement, 0x80);
        statusIcon->danger.activeElementID = hudElement;
    }
}

void remove_status_icon_danger(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    if (statusIcon->danger.active) {
        statusIcon->danger.active = FALSE;
        free_hud_element(statusIcon->danger.activeElementID);
    }
}

void enable_status_icon_danger(s32 iconID) {
    HudStatusIcon* statusIcon = &D_800A0F44[iconID];

    statusIcon->flags |= STATUS_ICON_FLAG_DANGER;
}

const f32 status_icons_rodata_alignment = 0.0f;
