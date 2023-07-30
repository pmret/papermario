#include "pause_common.h"
#include "message_ids.h"

extern Gfx PauseGfxOrbs[];

void pause_badges_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_badges_init(MenuPanel* panel);
void pause_badges_handle_input(MenuPanel* panel);
void pause_badges_update(MenuPanel* panel);
void pause_badges_cleanup(MenuPanel* panel);

static s16 gPauseBadgesItemIds[128];
static s32 gPauseBadgesCurrentPage;
#if !VERSION_IQUE
static s32 D_80270284;
#endif
static PauseItemPage gPauseBadgesPages[20];
static s32 gPauseBadgesSelectedIndex;
static s32 D_8027037C;
static s32 gPauseBadgesSelectedItem;
static s16 gPauseBadgesNumItems;
static s32 D_80270388;
static s32 gPauseBadgesCurrentScrollPos;
static s32 gPauseBadgesTargetScrollPos;
static s32 gPauseBadgesTargetScrollIndex;
static s32 gPauseBadgesLevel;
static s32 gPauseBadgesCurrentTab;
static s32 gPauseBadgesShowNotEnoughBP;
#if !VERSION_IQUE
static s32 D_802703A4;
#endif
static s32 gPauseBadgesIconIDs[22];

// Fake "badge" for the None entry that appears on the equipped badges page when nothing is equipped
#define BADGE_NONE_STANDIN 0x7FFE
// Invalid badge ID filled in unused slots of gPauseBadgesItemIds
#define BADGE_INVALID 0x7FFF

#if VERSION_IQUE
#define OFFSET_1_X 47
#define OFFSET_1_Y 82
#define OFFSET_2_X 10
#define OFFSET_3_X 73
#define OFFSET_3_Y 76
#else
#define OFFSET_1_X 43
#define OFFSET_1_Y 81
#define OFFSET_2_X 16
#define OFFSET_3_X 69
#define OFFSET_3_Y 74
#endif

HudScript* gPauseBadgesElements[][22] = {
    [LANGUAGE_DEFAULT] = {
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_ListPrevPage, &HES_ListNextPage,
        &HES_Dash, &HES_LabelBpNeeded, &HES_StatusStar1
    },
#if VERSION_PAL
    [LANGUAGE_DE] = {
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_ListPrevPage, &HES_ListNextPage,
        &HES_Dash, &HES_LabelBpNeeded_de, &HES_StatusStar1
    },
    [LANGUAGE_FR] = {
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_ListPrevPage, &HES_ListNextPage,
        &HES_Dash, &HES_LabelBpNeeded_fr, &HES_StatusStar1
    },
    [LANGUAGE_ES] = {
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
        &HES_StatBp, &HES_ListPrevPage, &HES_ListNextPage,
        &HES_Dash, &HES_LabelBpNeeded_es, &HES_StatusStar1
    },
#endif
};

#if VERSION_PAL
extern u8 D_PAL_80271B2C[];
#endif

MenuWindowBP gPauseBadgesWindowBPs[] = {
    {
        .windowID = WINDOW_ID_PAUSE_BADGES,
        .unk_01 = 0,
        .pos = { .x = 3, .y = 16 },
        .width = 289,
        .height = 154,
        .priority = WINDOW_PRIORITY_1,
        .fpDrawContents = &pause_badges_draw_contents,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_MAIN,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_16 }
    }
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
        aVal = gItemTable[*a].sortValue;
    }

    if (*b == 0) {
        bVal = BADGE_INVALID;
    } else {
        bVal = gItemTable[*b].sortValue;
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
    s32 pageIndex, i;
    s32 badgeIndex;
    s32 currentBadgeRow;
    s32 currentBadgeColumn;
    s32 style;
    s32 palette;
    s32 bpAvailable;
    s32 costBP;
    s32 canBeEquipped;
    PauseItemPage* page;
    s32 badgeListX;
    s32 badgeListY;
    s32 isEquipped;
    s32 isNone;
    s32 cannotBeEquipped;
    s32 x1, y1, x2, y2;
    s16 badgeID;
    s32 isSelected;
    s32 badgeEntryOffsetX, badgeEntryOffsetY;
    s32 posX, posY, cursorOffsetX, cursorOffsetY, selectedPosX, selectedPosY;
    s32 orbOffsetY;
    s32 numOrbs;
    s32 orbY, orbX;
    s32 bpAmount;
    s32 bpAvailOffsetX;
    s32 bpAvailOffsetY;
    f32 orbBlinkValue;
    s32 orbBlinkOpacity;
    s32 orbColorR, orbColorG, orbColorB;
    s32 orbColorR1, orbColorG1, orbColorB1;
    s32 badgeIconElement;
    s32 msg;
    s32 msgX, msgY;
    s32 msgOpacity;
    s32 maxBP;
    s32 itemIndex, j;
    s16* equippedBadges;
    s32 itemID;
    s32 orbIndex;
    s32* iconIDs;
    PlayerData* playerData = &gPlayerData;
    PauseItemPage* currentPage = &gPauseBadgesPages[gPauseBadgesCurrentPage];
    s32 bpAmountX;
    s32 msg2;

    costBP = 0;
    canBeEquipped = FALSE;
    style = DRAW_MSG_STYLE_MENU;
    bpAvailable = gPlayerData.maxBP - pause_get_total_equipped_bp_cost();
    currentBadgeColumn = gPauseBadgesSelectedIndex / currentPage->numCols;
    currentBadgeRow = gPauseBadgesSelectedIndex % currentPage->numCols;

    draw_box(DRAW_FLAG_NO_CLIP, &gPauseWS_15, baseX + 84, baseY, 0, width - 84, height, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    hud_element_set_render_pos(gPauseBadgesIconIDs[20], baseX + 241, baseY + 11);
    palette = MSG_PAL_STANDARD;
    hud_element_draw_without_clipping(gPauseBadgesIconIDs[20]);

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

    if (x2 <= 0 || y2 <= 0 || x1 >= SCREEN_WIDTH - 1 || y1 >= SCREEN_HEIGHT - 1) {
        return;
    }

    if (x2 >= SCREEN_WIDTH - 1) {
        x2 = SCREEN_WIDTH - 1;
    }
    if (y2 >= SCREEN_HEIGHT - 1) {
        y2 = SCREEN_HEIGHT - 1;
    }
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

    badgeIndex = 0;
    for (i = 0; i < 3; i++) {
        for (pageIndex = 0; pageIndex < 20; pageIndex++) {
            iconIDs = gPauseBadgesIconIDs;
            badgeListX = baseX + 119;
            badgeListY = baseY + 17;

            page = &gPauseBadgesPages[pageIndex];
            if (!page->enabled) {
                break;
            }

            pause_badges_get_pos_y(pageIndex, 0);

            for (itemIndex = 0; itemIndex < page->count; itemIndex++) {
                badgeID = gPauseBadgesItemIds[page->startIndex + itemIndex];
                isEquipped = FALSE;
                isSelected = FALSE;
                equippedBadges = gPlayerData.equippedBadges;
                cannotBeEquipped = FALSE;
                if (badgeID == BADGE_INVALID) {
                    continue;
                }

                posX = pause_badges_get_pos_x(pageIndex, itemIndex);
                posY = pause_badges_get_pos_y(pageIndex, itemIndex);
                isNone = badgeID == BADGE_NONE_STANDIN;

                for (j = 0; j < 64; equippedBadges++, j++) {
                    if (badgeID == *equippedBadges) {
                        isEquipped = TRUE;
                        break;
                    }
                }

                if (gPauseMenuCurrentTab == 2 &&
                    gPauseBadgesLevel == 1 &&
                    pause_badges_get_column(pageIndex, itemIndex) == currentBadgeRow &&
                    pause_badges_get_row(pageIndex, itemIndex) == currentBadgeColumn) {
                    itemID = badgeID;
                    isSelected = TRUE;
                    if (!isNone) {
                        costBP = gMoveTable[gItemTable[itemID].moveID].costBP;
                        if (!isEquipped && bpAvailable >= costBP) {
                            canBeEquipped = TRUE;
                        }
                    }
                }

                if (!isNone && bpAvailable < gMoveTable[gItemTable[badgeID].moveID].costBP) {
                    cannotBeEquipped = TRUE;
                }

                badgeEntryOffsetX = 0;
                badgeEntryOffsetY = 0;
                if (isSelected) {
                    badgeEntryOffsetX = -1;
                    badgeEntryOffsetY = -1;
                }

                if (i == 0) {
                    style = DRAW_MSG_STYLE_MENU;
                    palette = MSG_PAL_STANDARD;
                    if (isSelected) {
                        style = DRAW_MSG_STYLE_MENU | DRAW_MSG_STYLE_DROP_SHADOW;
                    }

                    if (isEquipped) {
                        draw_box(DRAW_FLAG_NO_CLIP, &gPauseWS_14, badgeListX + pause_badges_scroll_offset_x(posX) - 20,
                                baseY + pause_badges_scroll_offset_y(posY) + 17, 0, 200, 13, 255, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
                    } else if (cannotBeEquipped) {
                        palette = MSG_PAL_0B;
                    }
                }

                if (!pause_badges_is_visible(posY)) {
                    continue;
                }

                if (i == 0) {
                    if (isNone) {
                        draw_msg(pause_get_menu_msg(PAUSE_MSG_NO_BADGE), badgeListX + pause_badges_scroll_offset_x(posX) + badgeEntryOffsetX,
                                badgeListY + pause_badges_scroll_offset_y(posY) + badgeEntryOffsetY, 255, palette, style);
                    } else {
                        if (gItemTable[badgeID].nameMsg) {
                            if (gItemTable[badgeID].nameMsg > 0) {
                                draw_msg(gItemTable[badgeID].nameMsg, badgeListX + pause_badges_scroll_offset_x(posX) + badgeEntryOffsetX,
                                        badgeListY + pause_badges_scroll_offset_y(posY) + badgeEntryOffsetY, 255, palette, style);
                            }
                        }
                        draw_number(gMoveTable[gItemTable[badgeID].moveID].costBP, baseX + 235 + pause_badges_scroll_offset_x(posX),
                                    baseY + 17 + pause_badges_scroll_offset_y(posY), DRAW_NUMBER_CHARSET_THIN, palette, 255, DRAW_NUMBER_STYLE_ALIGN_RIGHT | DRAW_NUMBER_STYLE_MONOSPACE);
                    }
                }

                if (i == 1) {
                    badgeIconElement = iconIDs[badgeIndex];
                    hud_element_clear_flags(badgeIconElement, HUD_ELEMENT_FLAG_DROP_SHADOW);
                    hud_element_set_flags(badgeIconElement, HUD_ELEMENT_FLAG_FILTER_TEX);
                    if (isNone) {
                        badgeIconElement = gPauseBadgesIconIDs[21];
                    } else {
                        if (isSelected) {
                            hud_element_set_flags(badgeIconElement, HUD_ELEMENT_FLAG_DROP_SHADOW);
                            gPauseCurrentDescIconScript = gItemHudScripts[gItemTable[badgeID].hudElemID].enabled;
                        }

                        if (!isEquipped && cannotBeEquipped) {
                            hud_element_set_script(badgeIconElement, gItemHudScripts[gItemTable[badgeID].hudElemID].disabled);
                        } else {
                            hud_element_set_script(badgeIconElement, gItemHudScripts[gItemTable[badgeID].hudElemID].enabled);
                        }

                        hud_element_set_scale(badgeIconElement, 0.670816f);
                    }

                    hud_element_set_render_pos(badgeIconElement, baseX + 107 + pause_badges_scroll_offset_x(posX) + badgeEntryOffsetX,
                                                baseY + 23 + pause_badges_scroll_offset_y(posY) + badgeEntryOffsetY);
                    if (badgeIndex == 0) {
                        hud_element_draw_without_clipping(badgeIconElement);
                    } else {
                        hud_element_draw_next(badgeIconElement);
                    }

                    badgeIndex++;
                }

                if (i == 2 && !isNone) {
                    numOrbs = gMoveTable[gItemTable[badgeID].moveID].costBP;
                    orbOffsetY = 1;
                    if (numOrbs < 11) {
                        orbOffsetY = 4;
                    }

                    orbColorR1 = 0;
                    orbColorG1 = 255;
                    orbColorB1 = 100;

                    gSPDisplayList(gMainGfxPos++, PauseGfxOrbs);
                    gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);

                    if (isEquipped == 0) {
                        for (j = 0; j < numOrbs; j++) {
                            gDPSetPrimColor(gMainGfxPos++, 0, 0, 227, 227, 227, 255);
                            orbX = baseX + 235 + pause_badges_scroll_offset_x(posX) + 1 + (j % 5) * 6;
                            orbY = baseY + 17 + pause_badges_scroll_offset_y(posY) + orbOffsetY;
                            if (numOrbs >= 5) {
                                orbY += j / 5 * 6 - 3;
                            }
                            pause_badges_draw_bp_orbs(0, orbX, orbY);
                        }

                        gDPPipeSync(gMainGfxPos++);
                        gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                        gDPSetPrimColor(gMainGfxPos++, 0, 0, orbColorR1, orbColorG1, orbColorB1, 128);

                        for (j = 0; j < numOrbs; j++) {
                            if (j < bpAvailable) {
                                orbX = baseX + 235 + pause_badges_scroll_offset_x(posX) + 1 + (j % 5) * 6;
                                orbY = baseY + 17 + pause_badges_scroll_offset_y(posY) + orbOffsetY;
                                if (numOrbs >= 5) {
                                    orbY += j / 5 * 6 - 3;
                                }
                                pause_badges_draw_bp_orbs(1, orbX, orbY);
                            }
                        }
                    } else {
                        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 255, 100, 255);
                        for (j = 0; j < numOrbs; j++) {
                            orbX = baseX + 235 + pause_badges_scroll_offset_x(posX) + 1 + (j % 5) * 6;
                            orbY = baseY + 17 + pause_badges_scroll_offset_y(posY) + orbOffsetY;
                            if (numOrbs >= 5) {
                                orbY += j / 5 * 6 - 3;
                            }
                            pause_badges_draw_bp_orbs(2, orbX, orbY);
                        }
                        gDPPipeSync(gMainGfxPos++);
                    }
                }
            }
        }
    }

    x1 = baseX + 1;
    y1 = baseY + 1;
    x2 = baseX + width - 1;
    y2 = baseY + height - 1;
    gDPPipeSync(gMainGfxPos++);

    if (x1 <= 0) {
        x1 = 1;
    }
    if (y1 <= 0) {
        y1 = 1;
    }

    if (x2 <= 0 || y2 <= 0 || x1 >= SCREEN_WIDTH - 1 || y1 >= SCREEN_HEIGHT - 1) {
        return;
    }

    if (x2 >= SCREEN_WIDTH - 1) {
        x2 = SCREEN_WIDTH - 1;
    }
    if (y2 >= SCREEN_HEIGHT - 1) {
        y2 = SCREEN_HEIGHT - 1;
    }

    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

    if (gPauseMenuCurrentTab == 2 && gPauseBadgesLevel == 1) {
        if (gPauseBadgesCurrentPage > 0) {
            hud_element_set_render_pos(gPauseBadgesIconIDs[17], baseX + 278, baseY + 14);
            hud_element_draw_without_clipping(gPauseBadgesIconIDs[17]);
        }

        if (gPauseBadgesPages[gPauseBadgesCurrentPage + 1].enabled) {
            hud_element_set_render_pos(gPauseBadgesIconIDs[18], baseX + 278, baseY + 146);
            hud_element_draw_without_clipping(gPauseBadgesIconIDs[18]);
        }
    }

    hud_element_set_render_pos(gPauseBadgesIconIDs[16], baseX + OFFSET_1_X, baseY + OFFSET_1_Y);
    hud_element_draw_without_clipping(gPauseBadgesIconIDs[16]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_BADGE_BP), baseX + OFFSET_2_X, baseY + 74, 255, MSG_PAL_STANDARD, DRAW_MSG_STYLE_MENU);
    draw_number(playerData->maxBP, baseX + OFFSET_3_X, baseY + OFFSET_3_Y, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, 255, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
    bpAmount = playerData->maxBP - pause_get_total_equipped_bp_cost();
    bpAvailOffsetX = 0;
    bpAvailOffsetY = (playerData->maxBP - 1) / 10 * 8;
    if (bpAmount < 10) {
        bpAvailOffsetX = -4;
    }
    pause_draw_menu_label(PAUSE_LBL_AVAILABLE, baseX + 12, baseY + 100 + bpAvailOffsetY);

#if VERSION_PAL
    bpAmountX = baseX + (73 + bpAvailOffsetX);
    if (gCurrentLanguage == LANGUAGE_ES) {
        bpAmountX += 8;
    }
#else
    bpAmountX = baseX + 73 + bpAvailOffsetX;
#endif

    draw_number(bpAmount, bpAmountX, baseY + 100 + bpAvailOffsetY, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, 255,
                DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);

    orbColorR = 0;
    orbColorG = 255;
    orbColorB = 100;
    maxBP = playerData->maxBP;
    gSPDisplayList(gMainGfxPos++, PauseGfxOrbs);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
    for (orbIndex = 0; orbIndex < maxBP; orbIndex++) {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 227, 227, 227, 255);
        pause_badges_draw_bp_orbs(0, baseX + 11 + (orbIndex % 10) * 6, baseY + 92 + (orbIndex / 10) * 8);
    }

    gDPPipeSync(gMainGfxPos++);
    if (canBeEquipped) {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, orbColorR, orbColorG, orbColorB, 255);
        for (orbIndex = 0; orbIndex < bpAvailable - costBP; orbIndex++) {
            pause_badges_draw_bp_orbs(2, baseX + 11 +(orbIndex % 10) * 6, baseY + 92 + (orbIndex / 10) * 8);
        }

        gDPPipeSync(gMainGfxPos++);
        orbBlinkValue = (sin_deg(gGameStatusPtr->frameCounter * 15) + 1.0f) * 0.2 + 0.5;
        gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);

        orbBlinkOpacity = orbBlinkValue * 255.0f;
        gDPSetPrimColor(gMainGfxPos++, 0, 0, orbColorR, orbColorG, orbColorB, orbBlinkOpacity);

        for (orbIndex = bpAvailable - costBP; orbIndex < bpAvailable; orbIndex++) {
            pause_badges_draw_bp_orbs(2, baseX + 11 +(orbIndex % 10) * 6, baseY + 92 + (orbIndex / 10) * 8);
        }
        gDPPipeSync(gMainGfxPos++);
    } else {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, orbColorR, orbColorG, orbColorB, 255);
        for (orbIndex = 0; orbIndex < bpAvailable; orbIndex++) {
            pause_badges_draw_bp_orbs(2, baseX + 11 + (orbIndex % 10) * 6, baseY + 92 + (orbIndex / 10) * 8);
        }
        gDPPipeSync(gMainGfxPos++);
    }

    draw_box(DRAW_FLAG_NO_CLIP, &gPauseWS_13, gPauseBadgesCurrentTab == 0 ? baseX + 9 : baseX, baseY + 7, 0,
         91, 34, 255, gPauseBadgesCurrentTab == 1 ? 128 : 0, 0, 0,
         0, 0, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

#if VERSION_PAL
    if (gCurrentLanguage < 2) {
        msg2 = pause_get_menu_msg(PAUSE_MSG_ALL_BADGES);
        msgX = baseX + 10;
        if (gPauseBadgesCurrentTab == 0) {
            msgX = baseX + 19;
        }
        msgOpacity = 255;
        msgY = baseY + 17;
        if (gPauseBadgesCurrentTab == 1) {
            msgOpacity = 191;
        }
        draw_msg(msg2, msgX, msgY, msgOpacity, 0, 1);
    } else {
        msg2 = pause_get_menu_msg(PAUSE_MSG_ALL_BADGES);
        msgX = baseX + 12;
        if (gPauseBadgesCurrentTab == 0) {
            msgX = baseX + 21;
        }
        draw_msg(msg2, msgX, baseY + 12, gPauseBadgesCurrentTab == 1 ? 191 : 255, 0, 1);

        msg = pause_get_menu_msg(PAUSE_MSG_PAL_42);
        msgX = baseX + 24;
        if (gCurrentLanguage == 2) {
            msgX = baseX + 26;
        }
        if (gPauseBadgesCurrentTab == 0) {
            msgX += 9;
        }
        msgY = baseY + 22;
        msgOpacity = 255;
        if (gPauseBadgesCurrentTab == 1) {
            msgOpacity = 191;
        }
        draw_msg(msg, msgX, msgY, msgOpacity, 0, 1);
    }

    draw_box(4, &gPauseWS_13, gPauseBadgesCurrentTab == 1 ? baseX + 9 : baseX, baseY + 37, 0, 91, 34, 255,
             gPauseBadgesCurrentTab != 0 ? 0 : 128, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

    msg2 = pause_get_menu_msg(PAUSE_MSG_ACTIVE);
    msgX = baseX + 12;
    if (gPauseBadgesCurrentTab == 1) {
        msgX = baseX + 21;
    }
    draw_msg(msg2, msgX, baseY + 42, gPauseBadgesCurrentTab == 0 ? 191 : 255, 0, 1);

    draw_msg(pause_get_menu_msg(PAUSE_MSG_BADGES), (gPauseBadgesCurrentTab == 1) ? baseX + D_PAL_80271B2C[gCurrentLanguage] + 9 :baseX + D_PAL_80271B2C[gCurrentLanguage], baseY + 52, gPauseBadgesCurrentTab == 0 ? 191 : 255, 0, 1);
#else
    msg = pause_get_menu_msg(PAUSE_MSG_ALL_BADGES);
    msgX = baseX + 10;
    if (gPauseBadgesCurrentTab == 0) {
        msgX = baseX + 19;
    }
    msgOpacity = 255;
    msgY = baseY + 17;
    if (gPauseBadgesCurrentTab == 1) {
        msgOpacity = 191;
    }
    draw_msg(msg, msgX, msgY, msgOpacity, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);

    draw_box(DRAW_FLAG_NO_CLIP, &gPauseWS_13, gPauseBadgesCurrentTab == 1 ? baseX + 9 : baseX, baseY + 37, 0, 91, 34, 255,
            gPauseBadgesCurrentTab == 0 ? 128 : 0, 0, 0, 0, 0, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    msg = pause_get_menu_msg(PAUSE_MSG_ACTIVE);
    msgX = baseX + 12;
    if (gPauseBadgesCurrentTab == 1) {
        msgX = baseX + 21;
    }
    msgY = baseY + 42;
    msgOpacity = 255;
    if (gPauseBadgesCurrentTab == 0) {
        msgOpacity = 191;
    }
    draw_msg(msg, msgX, msgY, msgOpacity, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);

    msg = pause_get_menu_msg(PAUSE_MSG_BADGES);
    msgX = baseX + 26;
    if (gPauseBadgesCurrentTab == 1) {
        msgX = baseX + 35;
    }
    msgY = baseY + 52;
    msgOpacity = 255;
    if (gPauseBadgesCurrentTab == 0) {
        msgOpacity = 191;
    }
    draw_msg(msg, msgX, msgY, msgOpacity, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
#endif

    if (gPauseMenuCurrentTab == 2) {
         if (gPauseBadgesLevel == 0) {
             pause_set_cursor_pos(32, baseX + 10, baseY + 26 + gPauseBadgesCurrentTab * 32);
         } else {
             selectedPosX = pause_badges_get_pos_x(gPauseBadgesCurrentPage, gPauseBadgesSelectedIndex - gPauseBadgesPages[gPauseBadgesCurrentPage].listStart * gPauseBadgesPages[gPauseBadgesCurrentPage].numCols);
             selectedPosY = pause_badges_get_pos_y(gPauseBadgesCurrentPage, gPauseBadgesSelectedIndex - gPauseBadgesPages[gPauseBadgesCurrentPage].listStart * gPauseBadgesPages[gPauseBadgesCurrentPage].numCols);
             cursorOffsetX = pause_badges_scroll_offset_x(selectedPosX);
             cursorOffsetY = pause_badges_scroll_offset_y(selectedPosY);
             if (cursorOffsetY < 0) {
                 cursorOffsetY = 0;
             } else if (cursorOffsetY > 112) {
                 cursorOffsetY = 112;
             }

             if (gPauseBadgesCurrentScrollPos != gPauseBadgesTargetScrollPos) {
                 pause_set_cursor_pos_immediate(WINDOW_ID_PAUSE_BADGES, baseX + 93 + cursorOffsetX, baseY + 23 + cursorOffsetY);
             } else {
                 pause_set_cursor_pos(WINDOW_ID_PAUSE_BADGES, baseX + 93 + cursorOffsetX, baseY + 23 + cursorOffsetY);
             }
         }
    }

    if (gPauseBadgesShowNotEnoughBP != 0) {
        pause_set_cursor_opacity(0);
        if (gPauseBadgesShowNotEnoughBP == 1) {
#if VERSION_PAL
            s32 wid = get_msg_width(pause_get_menu_msg(PAUSE_MSG_NOT_ENOUGH_BP), 0);

            draw_box(DRAW_FLAG_NO_CLIP, &gPauseWS_13, baseX + (256 - wid) / 2, baseY + 60, 0, wid + 36, 26, 255,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
            draw_msg(pause_get_menu_msg(PAUSE_MSG_NOT_ENOUGH_BP), baseX + (292 - wid) / 2, baseY + 66, 255,
                     MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
#else
            draw_box(DRAW_FLAG_NO_CLIP, &gPauseWS_13, baseX + 67, baseY + 60, 0, 137, 26, 255,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
            draw_msg(pause_get_menu_msg(PAUSE_MSG_NOT_ENOUGH_BP), baseX + 86, baseY + 66, 255,
                     MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
#endif
        } else {
            draw_box(DRAW_FLAG_NO_CLIP, &gPauseWS_13, baseX + 67, baseY + 60, 0, 173, 26, 255,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
            draw_msg(pause_get_menu_msg(PAUSE_MSG_DONT_WEAR_MORE), baseX + 90, baseY + 66, 255,
                     MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
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
    gPauseBadgesTargetScrollIndex = 0;
    gPauseBadgesCurrentPage = 0;

    page = &gPauseBadgesPages[0];
    for (i = 0; i < gPauseBadgesNumItems / 8; i++, page++) {
        page->listStart = i * 8;
        page->numCols = 1;
        page->numRows = 8;
        page->enabled = TRUE;
        page->startIndex = i * 8;
        page->count = 8;
    }

    if ((gPauseBadgesNumItems % 8) != 0) {
        page->listStart = i * 8;
        page->numCols = 1;
        page->enabled = TRUE;
        page->startIndex = i * 8;
        page->count = gPauseBadgesNumItems % 8;
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
    gPauseBadgesShowNotEnoughBP = 0;

    pause_badges_load_badges(FALSE);
    if (gPauseBadgesItemIds[0] == BADGE_NONE_STANDIN) {
        panel->initialized = FALSE;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(gPauseBadgesIconIDs); i++) {
        s32 iconID = hud_element_create(gPauseBadgesElements[gCurrentLanguage][i]);

        gPauseBadgesIconIDs[i] = iconID;
        hud_element_set_flags(iconID, HUD_ELEMENT_FLAG_80);
    }

    for (i = 0; i < ARRAY_COUNT(gPauseBadgesWindowBPs); i++) {
        gPauseBadgesWindowBPs[i].tab = panel;
    }
    setup_pause_menu_tab(gPauseBadgesWindowBPs, ARRAY_COUNT(gPauseBadgesWindowBPs));
    panel->initialized = TRUE;
}

void pause_badges_handle_input(MenuPanel* panel) {
    s32 selectedIndex = gPauseBadgesSelectedIndex;
    s32 numCols = gPauseBadgesPages[gPauseBadgesCurrentPage].numCols;

    s32 selectedCol = selectedIndex % numCols;
    s32 selectedRow = selectedIndex / numCols;

    if (gPausePressedButtons & BUTTON_A) {
        s16 badgeID;

        if (gPauseBadgesShowNotEnoughBP != 0) {
            gPauseBadgesShowNotEnoughBP = 0;
        } else if (gPauseBadgesLevel == 0) {
            if (gPauseBadgesItemIds[selectedIndex] == BADGE_NONE_STANDIN) {
                sfx_play_sound(SOUND_MENU_ERROR);
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
                    sfx_play_sound(SOUND_MENU_ERROR);
                    gPauseBadgesShowNotEnoughBP = 1;
                    break;
                case EQUIP_RESULT_TOO_MANY_BADGES:
                    sfx_play_sound(SOUND_MENU_ERROR);
                    gPauseBadgesShowNotEnoughBP = 2;
                    break;
                case EQUIP_RESULT_SUCCESS:
                    sfx_play_sound(SOUND_MENU_BADGE_EQUIP);
                    break;
            }
        }
        return;
    }

    if ((gPausePressedButtons != 0) || (gPauseHeldButtons != 0)) {
        gPauseBadgesShowNotEnoughBP = 0;
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
            gPauseCurrentDescMsg = gItemTable[itemID].fullDescMsg;
        } else {
            gPauseCurrentDescMsg = MSG_NONE;
            gPauseCurrentDescIconScript = NULL;
        }
    } else {
        gPauseCurrentDescMsg = pause_get_menu_msg(gPauseBadgesCurrentTab == 0 ? PAUSE_MSG_BAGDE_DESC_ALL : PAUSE_MSG_BAGDE_DESC_ACTIVE);
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
    s32 itemIndex = (gPauseBadgesSelectedIndex / currentMenuPage->numCols) - currentMenuPage->listStart;

    if (itemIndex < 2 || currentMenuPage->numRows < 9) {
        gPauseBadgesTargetScrollIndex = 0;
    } else if (itemIndex >= currentMenuPage->numRows - 2) {
        gPauseBadgesTargetScrollIndex = currentMenuPage->numRows - 8;
    } else {
        if (itemIndex - gPauseBadgesTargetScrollIndex >= 7) {
            gPauseBadgesTargetScrollIndex = itemIndex - 6;
        } else if (itemIndex - gPauseBadgesTargetScrollIndex <= 0) {
            gPauseBadgesTargetScrollIndex = itemIndex - 1;
        }
    }

    gPauseBadgesTargetScrollPos = pause_badges_get_pos_y(gPauseBadgesCurrentPage, gPauseBadgesTargetScrollIndex * currentMenuPage->numCols);
    gPauseBadgesCurrentScrollPos += pause_interp_vertical_scroll(gPauseBadgesTargetScrollPos - gPauseBadgesCurrentScrollPos);
}

void pause_badges_cleanup(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseBadgesIconIDs); i++) {
        hud_element_free(gPauseBadgesIconIDs[i]);
    }
}
