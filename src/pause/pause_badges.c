#include "pause_common.h"

static s16 gPauseBadgesItemIds[128];
static s32 gPauseBadgesCurrentPage;
static s32 D_80270284;
static PauseItemPage gPauseBadgesPages[20];
static s32 gPauseBadgesSelectedIndex;
static s32 D_8027037C;
static s32 gPauseBadgesSelectedItem;
static s16 gPauseBadgesNumItems;
static s32 D_80270388;
static s32 gPauseBadgesCurrentScrollPos;
static s32 gPauseBadgesTargetScrollPos;
static s32 D_80270394;
static s32 gPauseBadgesLevel;
static s32 gPauseBadgesCurrentTab;
static s32 gPauseBadgesBShowNotEnoughBP;
static s32 D_802703A4; // unused
static s32 gPauseBadgesIconIDs[22];

// Fake "badge" for the None entry that appears on the equipped badges page when nothing is equipped
#define BADGE_NONE_STANDIN 0x7FFE
// Invalid badge ID filled in unused slots of gPauseBadgesItemIds
#define BADGE_INVALID 0x7FFF

void pause_badges_init(MenuPanel* panel);
void pause_badges_handle_input(MenuPanel* panel);
void pause_badges_update(MenuPanel* panel);
void pause_badges_cleanup(MenuPanel* panel);

HudScript* gBadgeMenuElements[] = {
    HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp,
    HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp,
    HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp,
    HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp,
    HudScript_StatBp, HudScript_ListPrevPage, HudScript_ListNextPage,
    HudScript_Dash, HudScript_LabelBpNeeded, HudScript_StatusStar1
};
MenuWindowBP gBadgeMenuWindowBPs[] = {
  { .windowID = WINDOW_ID_32,
    .unk_01 = 0,
    .pos = { .x = 3, .y = 16 },
    .width = 289,
    .height = 154,
    .unk_0A = { 1, 0},
    .fpDrawContents = &pause_badges_draw_contents,
    .tab = NULL,
    .parentID = WINDOW_ID_PAUSE_MAIN,
    .fpUpdate = { 2 },
    .unk_1C = 0,
    .style = &gPauseWS_16 }
};
MenuPanel gPausePanelBadges = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
    .numCols = 0,
    .numRows = 0,
    .numPages = 0,
    .gridData = NULL,
    .fpInit = &pause_badges_init,
    .fpHandleInput = &pause_badges_handle_input,
    .fpUpdate = &pause_badges_update,
    .fpCleanup = &pause_badges_cleanup
};

s32 pause_badges_comparator(s16* a, s16* b) {
    s16 aVal;
    s16 bVal;

    if (*a == 0) {
        aVal = BADGE_INVALID;
    } else {
        aVal = gItemTable[*a].badgeSortPriority;
    }

    if (*b == 0) {
        bVal = BADGE_INVALID;
    } else {
        bVal = gItemTable[*b].badgeSortPriority;
    }

    if (aVal == bVal) {
        return 0;
    } else if (aVal < bVal) {
        return -1;
    } else {
        return 1;
    }
}

s32 pause_badges_count_all(void) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    pause_sort_item_list(playerData->badges, ARRAY_COUNT(playerData->badges), pause_badges_comparator);

    for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
        if (playerData->badges[i] == 0) {
            break;
        }
    }

    return i;
}

s32 pause_badges_count_equipped(void) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    pause_sort_item_list(playerData->equippedBadges, ARRAY_COUNT(playerData->equippedBadges), &pause_badges_comparator);

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
        if (playerData->equippedBadges[i] == 0) {
            break;
        }
    }

    return i;
}

s32 pause_badges_get_pos_x(s32 page, s32 itemIndex) {
    return (itemIndex % BADGE_MENU_PAGE(page)->numCols) * 141;
}

s32 pause_badges_get_pos_y(s32 page, s32 itemIndex) {
    return ((page + 1) * 11) + (BADGE_MENU_PAGE(page)->listStart * 16) + ((itemIndex / BADGE_MENU_PAGE(
                page)->numCols) * 16);
}

s32 pause_badges_get_column(s32 page, s32 itemIdx) {
    return itemIdx % BADGE_MENU_PAGE(page)->numCols;
}

s32 pause_badges_get_row(s32 page, s32 itemIdx) {
    return BADGE_MENU_PAGE(page)->listStart + (itemIdx / BADGE_MENU_PAGE(page)->numCols);
}

s32 pause_badges_is_visible(s32 y) {
    if (y < gPauseBadgesCurrentScrollPos - 32) {
        return FALSE;
    } else {
        return y < gPauseBadgesCurrentScrollPos + 128;
    }
}

s32 pause_badges_scroll_offset_y(s32 offset) {
    return offset - gPauseBadgesCurrentScrollPos;
}

s32 pause_badges_scroll_offset_x(s32 x) {
    return x;
}

s32 pause_badges_try_remove(s16 badgeID) {
    s16 *currentSlot = gPlayerData.equippedBadges;
    s16 *slotToRemove = currentSlot;
    s32 result = 0;
    s32 i;

    if (badgeID == BADGE_INVALID) {
        return 0;
    }

    for (i = 0; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++, currentSlot++) {
        if (badgeID == *currentSlot) {
            slotToRemove = currentSlot;
            result = 1;
            break;
        }
    }

    // Remove and shift array contents
    for (; i < ARRAY_COUNT(gPlayerData.equippedBadges) - 1; i++, currentSlot++) {
        *currentSlot = *(currentSlot + 1);
    }
    *currentSlot = 0;

    if (*slotToRemove == 0) {
        result = 2;
    }
    return result;
}

typedef enum BadgeEquipResult {
    EQUIP_RESULT_ALREADY_EQUIPPED,
    EQUIP_RESULT_NOT_ENOUGH_BP,
    EQUIP_RESULT_TOO_MANY_BADGES,
    EQUIP_RESULT_SUCCESS,
} BadgeEquipResult;

s32 pause_badges_try_equip(s16 badgeID) {
    PlayerData* playerData = &gPlayerData;
    s16 *badgeSlot = &playerData->equippedBadges[0];
    s32 i;
    s32 totalEquippedBP;

    if (badgeID == BADGE_NONE_STANDIN) {
        badgeID = 0;
    }
    if (badgeID == BADGE_INVALID) {
        badgeID = 0;
    }
    if (badgeID == 0) {
        return EQUIP_RESULT_NOT_ENOUGH_BP;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++, badgeSlot++) {
        if (*badgeSlot == badgeID) {
            return EQUIP_RESULT_ALREADY_EQUIPPED;
        }
    }

    totalEquippedBP = pause_get_total_equipped_bp_cost();
    if (badgeID != 0) {
        u8 moveID = gItemTable[badgeID].moveID;
        s32 requiredBP = totalEquippedBP + gMoveTable[moveID].costBP;

        if (playerData->maxBP < requiredBP) {
            return EQUIP_RESULT_NOT_ENOUGH_BP;
        }
    }

    badgeSlot = &playerData->equippedBadges[0];
    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++, badgeSlot++) {
        if (*badgeSlot == 0) {
            *badgeSlot = badgeID;
            break;
        }
    }
    if (i == ARRAY_COUNT(playerData->equippedBadges)) {
        return EQUIP_RESULT_TOO_MANY_BADGES;
    } else {
        return EQUIP_RESULT_SUCCESS;
    }
}

void pause_badges_draw_bp_orbs(s32 orbState, s32 x, s32 y) {
    s32 orbSize = 8;

    switch (orbState) {
        case 0:
            pause_draw_rect(x * 4, y * 4, (x + orbSize) * 4, (y + orbSize) * 4, 0, 0, 256, 1024, 1024);
            break;
        case 1:
            pause_draw_rect(x * 4, y * 4, (x + orbSize) * 4, (y + orbSize) * 4, 0, 0, 0, 1024, 1024);
            break;
        default:
            pause_draw_rect(x * 4, y * 4, (x + orbSize) * 4, (y + orbSize) * 4, 0, 0, 512, 1024, 1024);
            break;
    }
}

void pause_badges_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 j, i;
    s32 sp58;
    s32 sp5C;
    s32 sp60;
    s32 sp64;
    s32 sp68;
    s32 sp6C;
    s32 sp70;
    s32 sp74;
    PauseItemPage* sp78;
    s32 sp7C;
    s32 sp80;
    s32 sp84;
    s32 sp88;
    s32 sp8C;
    s32 sp94;
    s32 x1, y1, x2, y2;
    s16 badgeID;
    s32 s5, s2, s4;
    s32 posX, posY, offsetX, offsetY, posX1, posY1;
    s32 s5_2;
    s32 costBP;
    s32 orbY, orbX;
    s32 bpAmount;
    s32 maxBP;
    s32 new_var;
    s32 yOffset;
    s32 numCols;
    int new_var4;
    s32 q;
    f32 new_var3;
    s32 var4;
    s32 s6, s7, s8;
    s32 r1, g1, b1;
    s32 w, w2, w3;
    s32* currentTab;
    s32 r;
    s32 el;
    s32 msg;
    s32 dx, dy;
    s32 opacity1;
    s32 qwer;
    s32 k, l;
    s16* equippedBadges;

    s32 possX;
    s32 badgeID2;
    HudScript* anim;
    s32 c;

    s32* iconIDs;
    PlayerData* playerData = &gPlayerData;

    PauseItemPage* page = &gPauseBadgesPages[gPauseBadgesCurrentPage];

    sp70 = 0;
    sp74 = 0;
    sp64 = 1;
    sp6C = gPlayerData.maxBP - pause_get_total_equipped_bp_cost();
    sp60 = gPauseBadgesSelectedIndex / page->numCols;
    sp5C = gPauseBadgesSelectedIndex % page->numCols;

    draw_box(4, &gPauseWS_15, baseX + 84, baseY, 0, width - 84, height, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 320, 240, 0);
    set_hud_element_render_pos(gPauseBadgesIconIDs[20], baseX + 241, baseY + 11);
    sp68 = 10;
    draw_hud_element_3(gPauseBadgesIconIDs[20]);
    x1 = baseX + 1;
    y1 = baseY + 14;
    x2 = baseX + width - 1;
    y2 = baseY + height - 9;

    if (x1 <= 0) {
        x1 = 1;
    }
    if (y1 <= 0) {
        y1 = 1;
    }

    if (x2 <= 0 || y2 <= 0 || x1 >= 319 || y1 >= 239) {
        return;
    }

    if (x2 >= 319) {
        x2 = 319;
    }
    if (y2 >= 239) {
        y2 = 239;
    }
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);


    sp58 = 0;
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 20; j++) {
            iconIDs = gPauseBadgesIconIDs;
            sp7C = baseX + 119;
            sp80 = baseY + 17;

            sp78 = &gPauseBadgesPages[j];
            if (!sp78->enabled) {
                break;
            }

            pause_badges_get_pos_y(j, 0);

            for (k = 0; k < sp78->count; k++) {
                badgeID = gPauseBadgesItemIds[sp78->startIndex + k];
                sp84 = FALSE;
                s5 = FALSE;
                equippedBadges = gPlayerData.equippedBadges;
                sp8C = FALSE;
                if (badgeID == BADGE_INVALID) {
                    continue;
                }

                posX = pause_badges_get_pos_x(j, k);
                posY = pause_badges_get_pos_y(j, k);

                sp88 = badgeID == BADGE_NONE_STANDIN;

                for (l = 0; l < 64; equippedBadges++, l++) {
                    if (badgeID == *equippedBadges) {
                        sp84 = TRUE;
                        break;
                    }
                }

                if (gPauseMenuCurrentTab == 2 &&
                    gPauseBadgesLevel == 1 &&
                    pause_badges_get_column(j, k) == sp5C &&
                    pause_badges_get_row(j, k) == sp60) {
                    badgeID2 = badgeID;
                    s5 = TRUE;
                    if (!sp88) {
                        sp70 = gMoveTable[gItemTable[badgeID2].moveID].costBP;
                        if (!sp84 && sp6C >= sp70) {
                            sp74 = TRUE;
                        }
                    }
                }
                if (!sp88 && sp6C < gMoveTable[gItemTable[badgeID].moveID].costBP) {
                    sp8C = TRUE;
                }

                s2 = 0;
                s4 = 0;
                if (s5) {
                    s2 = -1;
                    s4 = -1;
                }

                if (i == 0) {
                    sp64 = 1;
                    sp68 = 10;

                    if (s5) {
                        sp64 = 9;
                    }

                    if (sp84) {
                        draw_box(4, &gPauseWS_14, sp7C + pause_badges_scroll_offset_x(posX) - 20,
                                baseY + pause_badges_scroll_offset_y(posY) + 17, 0, 200, 13, 255, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 320, 240, 0);
                    } else if (sp8C) {
                        sp68 = 11;
                    }
                }

                if (!pause_badges_is_visible(posY)) {
                    continue;
                }

                if (i == 0) {
                    if (sp88) {
                        draw_msg(pause_get_menu_msg(0x45), sp7C + pause_badges_scroll_offset_x(posX) + s2,
                                sp80 + pause_badges_scroll_offset_y(posY) + s4, 0xFF, sp68, sp64);
                    } else {
                        if (gItemTable[badgeID].nameMsg) {
                            if (gItemTable[badgeID].nameMsg > 0) {
                                draw_msg(gItemTable[badgeID].nameMsg, sp7C + pause_badges_scroll_offset_x(posX) + s2,
                                        sp80 + pause_badges_scroll_offset_y(posY) + s4, 0xFF, sp68, sp64);
                            }
                        }
                        draw_number(gMoveTable[gItemTable[badgeID].moveID].costBP, baseX + 235 + pause_badges_scroll_offset_x(posX),
                                    baseY + 17 + pause_badges_scroll_offset_y(posY), 1, sp68, 0xFF, 3);
                    }
                }

                if (i == 1) {

                    el = iconIDs[sp58];
                    clear_hud_element_flags(el, 0x20000000);
                    set_hud_element_flags(el, 0x8000);
                    if (sp88) {
                        el = gPauseBadgesIconIDs[21];
                    } else {
                        if (s5) {
                            set_hud_element_flags(el, 0x20000000);
                            gPauseCurrentDescIconScript = gItemHudScripts[gItemTable[badgeID].iconID].enabled;
                        }

                        if (!sp84 && sp8C) {
                            set_hud_element_anim(el, gItemHudScripts[gItemTable[badgeID].iconID].disabled);
                        } else {
                            set_hud_element_anim(el, gItemHudScripts[gItemTable[badgeID].iconID].enabled);
                        }

                        set_hud_element_scale(el, 0.670816f);
                    }

                    set_hud_element_render_pos(el, baseX + 0x6B + pause_badges_scroll_offset_x(posX) + s2,
                                                baseY + 0x17 + pause_badges_scroll_offset_y(posY) + s4);
                    if (sp58 == 0) {
                        draw_hud_element_3(el);
                    } else {
                        draw_hud_element_2(el);
                    }

                    sp58++;
                }

                if (i == 2 && !sp88) {
                    costBP = gMoveTable[gItemTable[badgeID].moveID].costBP;
                    s5_2 = 1;
                    if (costBP < 11) {
                        s5_2 = 4;
                    }

                    r1 = 0x00;
                    g1 = 0xFF;
                    b1 = 0x64;

                    gSPDisplayList(gMasterGfxPos++, gPauseDLOrbs);
                    gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);

                    if (sp84 == 0) {
                        for (l = 0; l < costBP; l++) {
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0xE3, 0xE3, 0xE3, 0xFF);
                            orbX = baseX + 0xEB + pause_badges_scroll_offset_x(posX) + 1 + (l % 5) * 6;
                            orbY = baseY + 17 + pause_badges_scroll_offset_y(posY) + s5_2;
                            if (costBP >= 5) {
                                orbY += l / 5 * 6 - 3;
                            }
                            pause_badges_draw_bp_orbs(0, orbX, orbY);
                        }



                        gDPPipeSync(gMasterGfxPos++);
                        gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                        gDPSetPrimColor(gMasterGfxPos++, 0, 0, r1, g1, b1, 0x80);

                        for (l = 0; l < costBP; l++) {
                            if (l < sp6C) {
                                orbX = baseX + 0xEB + pause_badges_scroll_offset_x(posX) + 1 + (l % 5) * 6;
                                orbY = baseY + 17 + pause_badges_scroll_offset_y(posY) + s5_2;
                                if (costBP >= 5) {
                                    orbY += l / 5 * 6 - 3;
                                }
                                pause_badges_draw_bp_orbs(1, orbX, orbY);
                            }
                        }
                    } else {
                        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0x00, 0xFF, 0x64, 0xFF);
                        for (l = 0; l < costBP; l++) {
                            orbX = baseX + 0xEB + pause_badges_scroll_offset_x(posX) + 1 + (l % 5) * 6;
                            orbY = baseY + 17 + pause_badges_scroll_offset_y(posY) + s5_2;
                            if (costBP >= 5) {
                                orbY += l / 5 * 6 - 3;
                            }
                            pause_badges_draw_bp_orbs(2, orbX, orbY);
                        }
                        gDPPipeSync(gMasterGfxPos++);
                    }
                }
            }
        }
    }

    //END OF LOOP HERE
    x1 = baseX + 1;
    y1 = baseY + 1;
    x2 = baseX + width - 1;
    y2 = baseY + height - 1;
    gDPPipeSync(gMasterGfxPos++);

    if (x1 <= 0) {
        x1 = 1;
    }
    if (y1 <= 0) {
        y1 = 1;
    }

    if (x2 <= 0 || y2 <= 0 || x1 >= 319 || y1 >= 239) {
        return;
    }

    if (x2 >= 319) {
        x2 = 319;
    }
    if (y2 >= 239) {
        y2 = 239;
    }

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

    if (gPauseMenuCurrentTab == 2 && gPauseBadgesLevel == 1) {
        if (gPauseBadgesCurrentPage > 0) {
            set_hud_element_render_pos(gPauseBadgesIconIDs[17], baseX + 278, baseY + 14);
            draw_hud_element_3(gPauseBadgesIconIDs[17]);
        }

        if (gPauseBadgesPages[gPauseBadgesCurrentPage + 1].enabled) {
            set_hud_element_render_pos(gPauseBadgesIconIDs[18], baseX + 278, baseY + 146);
            draw_hud_element_3(gPauseBadgesIconIDs[18]);
        }
    }

    set_hud_element_render_pos(gPauseBadgesIconIDs[16], baseX + 43, baseY + 81);
    draw_hud_element_3(gPauseBadgesIconIDs[16]);
    draw_msg(pause_get_menu_msg(70), baseX + 16, baseY + 74, 0xFF, 0xA, 1);
    draw_number(playerData->maxBP, baseX + 69, baseY + 74, 1, 0xA, 0xFF, 3);
    bpAmount = playerData->maxBP - pause_get_total_equipped_bp_cost();
    yOffset = 0;
    possX = (playerData->maxBP - 1) / 10 * 8;
    if (bpAmount < 10) {
        yOffset = -4;
    }
    pause_draw_menu_label(7, baseX + 12, baseY + 0x64 + possX);
    draw_number(bpAmount, baseX + 0x49 + yOffset, baseY + 0x64 + possX, 1, 0xA, 0xFF, 3);

    s6 = 0;
    s7 = 0xff;
    s8 = 0x64;
    qwer = playerData->maxBP;
    gSPDisplayList(gMasterGfxPos++, gPauseDLOrbs);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
    for (c = 0; c < qwer; c++) {
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0xE3, 0xE3, 0xE3, 0xFF);
        pause_badges_draw_bp_orbs(0, baseX + 11 +(c % 10) * 6, baseY + 92 + (c / 10) * 8);
    }

    gDPPipeSync(gMasterGfxPos++);
    if (sp74) {
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, s6, s7, s8, 0xFF);
        for (c = 0; c < sp6C - sp70; c++) {
            pause_badges_draw_bp_orbs(2, baseX + 11 +(c % 10) * 6, baseY + 92 + (c / 10) * 8);
        }

        gDPPipeSync(gMasterGfxPos++);
        new_var3 = (sin_deg(gGameStatusPtr->frameCounter * 15) + 1.0f) * 0.2 + 0.5;
        gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);

        var4 = new_var3 * 255.0f;
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, s6, s7, s8, var4);

        for (c = sp6C - sp70; c < sp6C; c++) {
            pause_badges_draw_bp_orbs(2, baseX + 11 +(c % 10) * 6, baseY + 92 + (c / 10) * 8);
        }
        gDPPipeSync(gMasterGfxPos++);
    } else {
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, s6, s7, s8, 0xFF);
        for (c = 0; c < sp6C; c++) {
            pause_badges_draw_bp_orbs(2, baseX + 11 + (c % 10) * 6, baseY + 92 + (c / 10) * 8);
        }
        gDPPipeSync(gMasterGfxPos++);
    }

    draw_box(4, &gPauseWS_13, gPauseBadgesCurrentTab == 0 ? baseX + 9 : baseX, baseY + 7, 0,
         0x5B, 0x22, 0xFF, gPauseBadgesCurrentTab == 1 ? 0x80 : 0x00, 0, 0,
         0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);


    msg = pause_get_menu_msg(0x47);
    dx = baseX + 10;
    if (gPauseBadgesCurrentTab == 0) {
        dx = baseX + 19;
    }
    opacity1 = 0xFF;
    dy = baseY + 0x11;
    if (gPauseBadgesCurrentTab == 1) {
        opacity1 = 0xBF;
    }
    draw_msg(msg, dx, dy, opacity1, 0, 1);
    //draw_msg(pause_get_menu_msg(0x47), gPauseBadgesCurrentTab == 0 ? baseX + 19 : baseX + 10, baseY + 0x11,
      //           gPauseBadgesCurrentTab == 1 ? 0xBF : 0xFF, 0, 1);

    draw_box(4, &gPauseWS_13, gPauseBadgesCurrentTab == 1 ? baseX + 9 : baseX, baseY + 0x25, 0, 0x5B, 0x22, 0xFF,
            gPauseBadgesCurrentTab == 0 ? 0x80 : 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);


    msg = pause_get_menu_msg(0x48);
    dx = baseX + 12;
    if (gPauseBadgesCurrentTab == 1) {
        dx = baseX + 21;
    }
    dy = baseY + 0x2A;
    opacity1 = 0xFF;
    if (gPauseBadgesCurrentTab == 0) {
        opacity1 = 0xBF;
    }
    draw_msg(msg, dx, dy, opacity1, 0, 1);

    msg = pause_get_menu_msg(0x49);
    dx = baseX + 0x1A;
    if (gPauseBadgesCurrentTab == 1) {
        dx = baseX + 0x23;
    }
    dy = baseY + 0x34;
    opacity1 = 0xFF;
    if (gPauseBadgesCurrentTab == 0) {
        opacity1 = 0xBF;
    }
    draw_msg(msg, dx, dy, opacity1, 0, 1);

    if (gPauseMenuCurrentTab == 2) {
         if (gPauseBadgesLevel == 0) {
             pause_set_cursor_pos(32, baseX + 0xA , baseY + 0x1A + gPauseBadgesCurrentTab * 32);
         } else {
             posX1 = pause_badges_get_pos_x(gPauseBadgesCurrentPage, gPauseBadgesSelectedIndex - gPauseBadgesPages[gPauseBadgesCurrentPage].listStart * gPauseBadgesPages[gPauseBadgesCurrentPage].numCols);
             posY1 = pause_badges_get_pos_y(gPauseBadgesCurrentPage, gPauseBadgesSelectedIndex - gPauseBadgesPages[gPauseBadgesCurrentPage].listStart * gPauseBadgesPages[gPauseBadgesCurrentPage].numCols);
             offsetX = pause_badges_scroll_offset_x(posX1);
             offsetY = pause_badges_scroll_offset_y(posY1);
             if (offsetY < 0) {
                 offsetY = 0;
             } else if (offsetY > 112) {
                 offsetY = 112;
             }

             if (gPauseBadgesCurrentScrollPos != gPauseBadgesTargetScrollPos) {
                 pause_set_cursor_pos_immediate(0x20, baseX + 0x5D + offsetX, baseY + 0x17 + offsetY);
             } else {
                 pause_set_cursor_pos(0x20, baseX + 0x5D + offsetX, baseY + 0x17 + offsetY);
             }
         }
    }

    if (gPauseBadgesBShowNotEnoughBP != 0) {
        pause_set_cursor_opacity(0);
        if (gPauseBadgesBShowNotEnoughBP == 1) {
            draw_box(4, &gPauseWS_13, baseX + 0x43, baseY + 0x3C, 0, 0x89, 0x1A, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);
            draw_msg(pause_get_menu_msg(0x4A), baseX + 0x56, baseY + 0x42, 0xFF, 0, 1);
        } else {
            draw_box(4, &gPauseWS_13, baseX + 0x43, baseY + 0x3C, 0, 0xAD, 0x1A, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);
            draw_msg(pause_get_menu_msg(0x4B), baseX + 0x5A, baseY + 0x42, 0xFF, 0, 1);
        }
    }
}

void pause_badges_load_badges(s32 onlyEquipped) {
    PlayerData* playerData = &gPlayerData;
    s32 numItems = 0;
    PauseItemPage* page;
    s32 i;

    D_80270388 = 0;
    if (!onlyEquipped) {
        for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
            s16 badgeItemID = playerData->badges[i];

            if (badgeItemID == 0) {
                continue;
            } else if (badgeItemID > ITEM_LAST_BADGE) {
                break;
            } else {
                gPauseBadgesItemIds[numItems] = badgeItemID;
                numItems += 1;
            }
        }
    } else {
        s16* equippedBadges;

        // This is just called to sort equippedBadges, the count is discarded
        pause_badges_count_equipped();

        equippedBadges = playerData->equippedBadges;
        for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
            // This can be written more clearly as equippedBadges[i],
            // but that causes some instruction reordering
            s16 badgeItemID = *equippedBadges;

            if (badgeItemID != 0) {
                gPauseBadgesItemIds[numItems] = badgeItemID;
                numItems += 1;
            }
            equippedBadges++;
        }
    }
    if (numItems == 0) {
        gPauseBadgesItemIds[0] = BADGE_NONE_STANDIN;
        numItems = 1;
    }
    gPauseBadgesNumItems = numItems;
    for (i = numItems; i < ARRAY_COUNT(gPauseBadgesItemIds); i++) {
        gPauseBadgesItemIds[i] = BADGE_INVALID;
    }

    gPauseBadgesSelectedIndex = 0;
    gPauseBadgesSelectedItem = 0;
    D_8027037C = 0;
    D_80270394 = 0;
    gPauseBadgesCurrentPage = 0;

    page = &gPauseBadgesPages[0];
    i = 0;

    for (i = 0; i < gPauseBadgesNumItems / 8; i++, page++) {
        page->listStart = i * 8;
        page->numCols = 1;
        page->numRows = 8;
        page->enabled = TRUE;
        page->startIndex = i * 8;
        page->count = 8;
    }

    if ((gPauseBadgesNumItems % 8) != 0) {
        s16 count;
        s32 menuNumItems;

        page->listStart = i * 8;
        page->numCols = 1;
        page->enabled = TRUE;
        page->startIndex = i * 8;

        menuNumItems = gPauseBadgesNumItems;
        count = menuNumItems - (menuNumItems / 8 * 8);
        page->count = count;
        page->numRows = page->count;
        i++;
        page++;
    }

    while (i < ARRAY_COUNT(gPauseBadgesPages)) {
        page->enabled = FALSE;

        i++;
        page++;
    }

    gPauseBadgesTargetScrollPos = gPauseBadgesCurrentScrollPos = pause_badges_get_pos_y(0, 0);
}

void pause_badges_init(MenuPanel* panel) {
    s32 i;

    // This sorts the badge list and then discards the count
    pause_badges_count_all();

    gPauseBadgesLevel = 0;
    gPauseBadgesCurrentTab = 0;
    gPauseBadgesBShowNotEnoughBP = 0;

    pause_badges_load_badges(FALSE);
    if (gPauseBadgesItemIds[0] == BADGE_NONE_STANDIN) {
        panel->initialized = FALSE;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(gPauseBadgesIconIDs); i++) {
        s32 iconID = create_hud_element(gBadgeMenuElements[i]);

        gPauseBadgesIconIDs[i] = iconID;
        set_hud_element_flags(iconID, 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(gBadgeMenuWindowBPs); i++) {
        gBadgeMenuWindowBPs[i].tab = panel;
    }
    setup_pause_menu_tab(gBadgeMenuWindowBPs, ARRAY_COUNT(gBadgeMenuWindowBPs));
    panel->initialized = TRUE;
}

void pause_badges_handle_input(MenuPanel* panel) {
    s32 selectedIndex = gPauseBadgesSelectedIndex;
    s32 numCols = gPauseBadgesPages[gPauseBadgesCurrentPage].numCols;

    s32 selectedCol = selectedIndex % numCols;
    s32 selectedRow = selectedIndex / numCols;

    if (gPausePressedButtons & BUTTON_A) {
        s16 badgeID;

        if (gPauseBadgesBShowNotEnoughBP != 0) {
            gPauseBadgesBShowNotEnoughBP = 0;
        } else if (gPauseBadgesLevel == 0) {
            if (gPauseBadgesItemIds[selectedIndex] == BADGE_NONE_STANDIN) {
                sfx_play_sound(SOUND_MENU_BADGE_ERROR);
            } else {
                gPauseBadgesLevel = 1;
                sfx_play_sound(SOUND_MENU_NEXT);
            }
        } else {
            badgeID = gPauseBadgesItemIds[selectedIndex];
            switch (pause_badges_try_equip(badgeID)) {
                case EQUIP_RESULT_ALREADY_EQUIPPED:
                    sfx_play_sound(SOUND_MENU_BADGE_UNEQUIP);
                    pause_badges_try_remove(badgeID);
                    break;
                case EQUIP_RESULT_NOT_ENOUGH_BP:
                    sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                    gPauseBadgesBShowNotEnoughBP = 1;
                    break;
                case EQUIP_RESULT_TOO_MANY_BADGES:
                    sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                    gPauseBadgesBShowNotEnoughBP = 2;
                    break;
                case EQUIP_RESULT_SUCCESS:
                    sfx_play_sound(SOUND_MENU_BADGE_EQUIP);
                    break;
            }
        }
        return;
    }

    if ((gPausePressedButtons != 0) || (gPauseHeldButtons != 0)) {
        gPauseBadgesBShowNotEnoughBP = 0;
    }

    if (gPauseBadgesNumItems != 0) {
        if (gPauseBadgesLevel == 0) {
            s32 oldTab = gPauseBadgesCurrentTab;

            if (gPauseHeldButtons & (BUTTON_STICK_UP | BUTTON_STICK_DOWN)) {
                gPauseBadgesCurrentTab ^= 1;
            }
            if (oldTab != gPauseBadgesCurrentTab) {
                sfx_play_sound(SOUND_MENU_CHANGE_TAB);
                pause_badges_load_badges(gPauseBadgesCurrentTab);
            }
        } else {
            s32 heldButtons = gPauseHeldButtons;
            s32 heldButtons2;
            u8 newPageNumCols;

            if (heldButtons & (BUTTON_STICK_UP | BUTTON_Z)) {
                if (heldButtons & BUTTON_STICK_UP) {
                    selectedRow -= 1;
                    if (selectedRow < 0) {
                        selectedRow = 0;
                    }
                    if (selectedRow < gPauseBadgesPages[gPauseBadgesCurrentPage].listStart) {
                        gPauseBadgesCurrentPage -= 1;
                    }
                } else {
                    // Z button press
                    gPauseBadgesCurrentPage -= 1;
                    if (gPauseBadgesCurrentPage < 0) {
                        gPauseBadgesCurrentPage = 0;
                    }
                    selectedRow = gPauseBadgesPages[gPauseBadgesCurrentPage].listStart;
                }
            }

            // Need to re-read button state here for strange regalloc reasons
            heldButtons2 = gPauseHeldButtons;
            if (heldButtons2 & (BUTTON_STICK_DOWN | BUTTON_R)) {
                if (heldButtons2 & BUTTON_STICK_DOWN) {
                    PauseItemPage* page = &gPauseBadgesPages[gPauseBadgesCurrentPage];

                    selectedRow += 1;
                    if (selectedRow >= (page->listStart + page->numRows)) {
                        gPauseBadgesCurrentPage += 1;
                        if (!gPauseBadgesPages[gPauseBadgesCurrentPage].enabled) {
                            gPauseBadgesCurrentPage -= 1;
                            selectedRow -= 1;
                        }
                    }
                } else {
                    // R button press
                    PauseItemPage* newPage;

                    gPauseBadgesCurrentPage++;
                    newPage = &gPauseBadgesPages[gPauseBadgesCurrentPage];

                    if (!newPage->enabled) {
                        gPauseBadgesCurrentPage -= 1;
                    } else {
                        selectedRow = newPage->listStart;
                    }
                }
            }

            newPageNumCols = gPauseBadgesPages[gPauseBadgesCurrentPage].numCols;
            if (gPauseBadgesItemIds[selectedRow * newPageNumCols] != BADGE_NONE_STANDIN) {
                if (gPauseHeldButtons & BUTTON_STICK_LEFT) {
                    selectedCol -= 1;
                    if (selectedCol < 0) {
                        selectedCol = newPageNumCols - 1;
                    }
                } else if (gPauseHeldButtons & BUTTON_STICK_RIGHT) {
                    selectedCol += 1;
                    if (selectedCol >= newPageNumCols) {
                        selectedCol = 0;
                    }
                }
            } else {
                selectedCol = 0;
            }
            gPauseBadgesSelectedIndex = selectedCol + (selectedRow * gPauseBadgesPages[gPauseBadgesCurrentPage].numCols);
            if (gPauseBadgesSelectedIndex != selectedIndex) {
                sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
            }
            gPauseBadgesSelectedItem = gPauseBadgesItemIds[gPauseBadgesSelectedIndex];
        }
    }

    if (gPauseBadgesLevel == 1) {
        s32 itemID = gPauseBadgesSelectedItem;

        if (((itemID != BADGE_NONE_STANDIN) && (itemID != BADGE_INVALID) && (itemID != 0))) {
            gPauseCurrentDescMsg = gItemTable[itemID].menuMsg;
        } else {
            gPauseCurrentDescMsg = 0;
            gPauseCurrentDescIconScript = NULL;
        }
    } else {
        gPauseCurrentDescMsg = pause_get_menu_msg(gPauseBadgesCurrentTab == 0 ? 0x4C : 0x4D);
        gPauseCurrentDescIconScript = NULL;
    }

    if (gPausePressedButtons & BUTTON_B) {
        if (gPauseBadgesLevel == 0) {
            sfx_play_sound(SOUND_MENU_BACK);
            gPauseMenuCurrentTab = 0;
        } else {
            sfx_play_sound(SOUND_MENU_BACK);
            gPauseBadgesLevel = 0;
            enforce_hpfp_limits();
            if (gPauseBadgesCurrentTab == 1) {
                pause_badges_load_badges(TRUE);
            }
        }
    }
}

void pause_badges_update(MenuPanel* panel) {
    PauseItemPage* menuPages = gPauseBadgesPages;
    PauseItemPage* currentMenuPage = &menuPages[gPauseBadgesCurrentPage];
    s32 temp = (gPauseBadgesSelectedIndex / currentMenuPage->numCols) - currentMenuPage->listStart;

    if ((temp < 2) || currentMenuPage->numRows < 9) {
        D_80270394 = 0;
    } else if (temp >= currentMenuPage->numRows - 2) {
        D_80270394 = currentMenuPage->numRows - 8;
    } else {
        s32* unkSym = &D_80270394;

        if (temp - *unkSym >= 7) {
            *unkSym = temp - 6;
        } else if (temp - *unkSym <= 0) {
            *unkSym = temp - 1;
        }
    }

    gPauseBadgesTargetScrollPos = pause_badges_get_pos_y(gPauseBadgesCurrentPage, D_80270394 * currentMenuPage->numCols);
    gPauseBadgesCurrentScrollPos += pause_interp_vertical_scroll(gPauseBadgesTargetScrollPos - gPauseBadgesCurrentScrollPos);
}

void pause_badges_cleanup(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseBadgesIconIDs); i++) {
        free_hud_element(gPauseBadgesIconIDs[i]);
    }
}
