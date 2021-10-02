#include "common.h"

// Probably only used here, but could theoretically be used in the main menu too
typedef struct {
    s32 cursorX;
    s32 cursorY;
    s32 baseMsgID;
} StatsEntryData; // size = 0xC

extern HudElementAnim* gStatsMenuElements[12];
extern MenuWindowBP gStatsMenuWindowBPs[1];
extern StatsEntryData gStatsMenuEntries[11];

// Fake "badge" for the None entry that appears on the equipped badges page when nothing is equipped
#define BADGE_NONE_STANDIN 0x7FFE
// Invalid badge ID filled in unused slots of gBadgeMenuItemIDs
#define BADGE_INVALID 0x7FFF

INCLUDE_ASM(s32, "pause/138CC0", pause_stats_draw_contents);

void pause_stats_init(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gStatsMenuIconIDs); i++) {
        s32 iconID = create_hud_element(gStatsMenuElements[i]);

        gStatsMenuIconIDs[i] = iconID;
        set_hud_element_flags(iconID, 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(gStatsMenuWindowBPs); i++) {
        gStatsMenuWindowBPs[i].tab = panel;
    }

    setup_pause_menu_tab(gStatsMenuWindowBPs, ARRAY_COUNT(gStatsMenuWindowBPs));
    panel->initialized = TRUE;
}

void pause_stats_handle_input(MenuPanel* panel) {
    s32 initialSelection = panel->selected;
    s16 adjustedBootsLevel;
    s16 adjustedHammerLevel;
    s32 msgOffset;

    if (gPauseMenuHeldButtons & BUTTON_STICK_LEFT) {
        while (1) {
            panel->col--;
            if (panel->col < 0) {
                panel->col = 0;
                break;
            } else if (panel->selected != MENU_PANEL_SELECTED_GRID_DATA(panel)) {
                break;
            }
        }
    }

    if (gPauseMenuHeldButtons & BUTTON_STICK_RIGHT) {
        while (1) {
            panel->col++;
            if (panel->col >= panel->numCols) {
                panel->col = panel->numCols - 1;
                break;
            } else if (panel->selected != MENU_PANEL_SELECTED_GRID_DATA(panel)) {
                break;
            }
        }
    }

    if (gPauseMenuHeldButtons & BUTTON_STICK_UP) {
        while (1) {
            panel->row--;
            if (panel->row < 0) {
                panel->row = 0;
                break;
            } else if (panel->selected != MENU_PANEL_SELECTED_GRID_DATA(panel)) {
                break;
            }
        }
    }

    if (gPauseMenuHeldButtons & BUTTON_STICK_DOWN) {
        while (1) {
            panel->row++;
            if (panel->row >= panel->numRows) {
                panel->row = panel->numRows - 1;
                break;
            } else if (panel->selected != MENU_PANEL_SELECTED_GRID_DATA(panel)) {
                break;
            }
        }
    }

    panel->selected = MENU_PANEL_SELECTED_GRID_DATA(panel);
    if (panel->selected != initialSelection) {
        sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
    }

    msgOffset = 0;
    adjustedBootsLevel = gPlayerData.bootsLevel;
    adjustedHammerLevel = gPlayerData.hammerLevel;

    adjustedBootsLevel++;
    if (adjustedBootsLevel < 0) {
        adjustedBootsLevel = 0;
    }
    if (adjustedBootsLevel > 3) {
        adjustedBootsLevel = 3;
    }

    adjustedHammerLevel++;
    if (adjustedHammerLevel < 0) {
        adjustedHammerLevel = 0;
    }
    if (adjustedHammerLevel > 3) {
        adjustedHammerLevel = 3;
    }

    switch (gStatsMenuEntries[panel->selected].baseMsgID) {
        case 0x25:
            if (adjustedBootsLevel > 1) {
                msgOffset = adjustedBootsLevel - 1;
            }
            break;
        case 0x28:
            msgOffset = adjustedHammerLevel;
            break;
        case 0x2F:
            if (evt_get_variable(NULL, EVT_SAVE_FLAG_TUTORIAL_GOT_STAR_PIECE)) {
                msgOffset = 1;
            }
            break;
    }

    gPauseMenuCurrentDescMsg = pause_get_menu_msg(gStatsMenuEntries[panel->selected].baseMsgID + msgOffset);
    gPauseMenuCurrentDescIconScript = NULL;

    if (gPauseMenuPressedButtons & BUTTON_B) {
        sfx_play_sound(SOUND_MENU_BACK);
        gPauseMenuCurrentTab = 0;
    }
}

void pause_stats_cleanup(void) {
    s32* iconIDs = gStatsMenuIconIDs;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gStatsMenuIconIDs); i++) {
        free_hud_element(iconIDs[i]);
    }
}

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
    if (y < gBadgeMenuCurrentScrollPos - 32) {
        return FALSE;
    } else {
        return y < gBadgeMenuCurrentScrollPos + 128;
    }
}

s32 pause_badges_scroll_offset_y(s32 offset) {
    return offset - gBadgeMenuCurrentScrollPos;
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

INCLUDE_ASM(s32, "pause/138CC0", pause_badges_draw_contents);

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
                gBadgeMenuItemIDs[numItems] = badgeItemID;
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
                gBadgeMenuItemIDs[numItems] = badgeItemID;
                numItems += 1;
            }
            equippedBadges++;
        }
    }
    if (numItems == 0) {
        gBadgeMenuItemIDs[0] = BADGE_NONE_STANDIN;
        numItems = 1;
    }
    gBadgeMenuNumItems = numItems;
    for (i = numItems; i < ARRAY_COUNT(gBadgeMenuItemIDs); i++) {
        gBadgeMenuItemIDs[i] = BADGE_INVALID;
    }

    gBadgeMenuSelectedIndex = 0;
    gBadgeMenuSelectedItemID = 0;
    D_8027037C = 0;
    D_80270394 = 0;
    gBadgeMenuCurrentPage = 0;

    page = &gBadgeMenuPages[0];
    i = 0;
   
    for (i = 0; i < gBadgeMenuNumItems / 8; i++, page++) {
        page->listStart = i * 8;
        page->numCols = 1;
        page->numRows = 8;
        page->enabled = TRUE;
        page->startIndex = i * 8;
        page->count = 8;
    }

    if ((gBadgeMenuNumItems % 8) != 0) {
        s16 count;
        s32 menuNumItems;

        page->listStart = i * 8;
        page->numCols = 1;
        page->enabled = TRUE;
        page->startIndex = i * 8;

        menuNumItems = gBadgeMenuNumItems;
        count = menuNumItems - (menuNumItems / 8 * 8);
        page->count = count;
        page->numRows = page->count;
        i++;
        page++;
    }

    while (i < ARRAY_COUNT(gBadgeMenuPages)) {
        page->enabled = FALSE;

        i++;
        page++;
    }

    gBadgeMenuTargetScrollPos = gBadgeMenuCurrentScrollPos = pause_badges_get_pos_y(0, 0);
}

void pause_badges_init(MenuPanel* panel) {
    s32 i;

    // This sorts the badge list and then discards the count
    pause_badges_count_all();

    gBadgeMenuLevel = 0;
    gBadgeMenuCurrentTab = 0;
    gBadgeMenuBShowNotEnoughBP = 0;

    pause_badges_load_badges(FALSE);
    if (gBadgeMenuItemIDs[0] == BADGE_NONE_STANDIN) {
        panel->initialized = FALSE;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(gBadgeMenuIconIDs); i++) {
        s32 iconID = create_hud_element(gBadgeMenuElements[i]);

        gBadgeMenuIconIDs[i] = iconID;
        set_hud_element_flags(iconID, 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(gBadgeMenuWindowBPs); i++) {
        gBadgeMenuWindowBPs[i].tab = panel;
    }
    setup_pause_menu_tab(gBadgeMenuWindowBPs, ARRAY_COUNT(gBadgeMenuWindowBPs));
    panel->initialized = TRUE;
}

void pause_badges_handle_input(MenuPanel* panel) {
    s32 selectedIndex = gBadgeMenuSelectedIndex;
    s32 numCols = gBadgeMenuPages[gBadgeMenuCurrentPage].numCols;

    s32 selectedCol = selectedIndex % numCols;
    s32 selectedRow = selectedIndex / numCols;

    if (gPauseMenuPressedButtons & BUTTON_A) {
        s16 badgeID;

        if (gBadgeMenuBShowNotEnoughBP != 0) {
            gBadgeMenuBShowNotEnoughBP = 0;
        } else if (gBadgeMenuLevel == 0) {
            if (gBadgeMenuItemIDs[selectedIndex] == BADGE_NONE_STANDIN) {
                sfx_play_sound(SOUND_MENU_BADGE_ERROR);
            } else {
                gBadgeMenuLevel = 1;
                sfx_play_sound(SOUND_MENU_NEXT);
            }
        } else {
            badgeID = gBadgeMenuItemIDs[selectedIndex];
            switch (pause_badges_try_equip(badgeID)) {
                case EQUIP_RESULT_ALREADY_EQUIPPED:
                    sfx_play_sound(SOUND_MENU_BADGE_UNEQUIP);
                    pause_badges_try_remove(badgeID);
                    break;
                case EQUIP_RESULT_NOT_ENOUGH_BP:
                    sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                    gBadgeMenuBShowNotEnoughBP = 1;
                    break;
                case EQUIP_RESULT_TOO_MANY_BADGES:
                    sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                    gBadgeMenuBShowNotEnoughBP = 2;
                    break;
                case EQUIP_RESULT_SUCCESS:
                    sfx_play_sound(SOUND_MENU_BADGE_EQUIP);
                    break;
            }
        }
        return;
    }

    if ((gPauseMenuPressedButtons != 0) || (gPauseMenuHeldButtons != 0)) {
        gBadgeMenuBShowNotEnoughBP = 0;
    }

    if (gBadgeMenuNumItems != 0) {
        if (gBadgeMenuLevel == 0) {
            s32 oldTab = gBadgeMenuCurrentTab;

            if (gPauseMenuHeldButtons & (BUTTON_STICK_UP | BUTTON_STICK_DOWN)) {
                gBadgeMenuCurrentTab ^= 1;
            }
            if (oldTab != gBadgeMenuCurrentTab) {
                sfx_play_sound(SOUND_MENU_CHANGE_TAB);
                pause_badges_load_badges(gBadgeMenuCurrentTab);
            }
        } else {
            s32 heldButtons = gPauseMenuHeldButtons;
            s32 heldButtons2;
            u8 newPageNumCols;

            if (heldButtons & (BUTTON_STICK_UP | BUTTON_Z)) {
                if (heldButtons & BUTTON_STICK_UP) {
                    selectedRow -= 1;
                    if (selectedRow < 0) {
                        selectedRow = 0;
                    }
                    if (selectedRow < gBadgeMenuPages[gBadgeMenuCurrentPage].listStart) {
                        gBadgeMenuCurrentPage -= 1;
                    }
                } else {
                    // Z button press
                    gBadgeMenuCurrentPage -= 1;
                    if (gBadgeMenuCurrentPage < 0) {
                        gBadgeMenuCurrentPage = 0;
                    }
                    selectedRow = gBadgeMenuPages[gBadgeMenuCurrentPage].listStart;
                }
            }

            // Need to re-read button state here for strange regalloc reasons
            heldButtons2 = gPauseMenuHeldButtons;
            if (heldButtons2 & (BUTTON_STICK_DOWN | BUTTON_R)) {
                if (heldButtons2 & BUTTON_STICK_DOWN) {
                    PauseItemPage* page = &gBadgeMenuPages[gBadgeMenuCurrentPage];

                    selectedRow += 1;
                    if (selectedRow >= (page->listStart + page->numRows)) {
                        gBadgeMenuCurrentPage += 1;
                        if (!gBadgeMenuPages[gBadgeMenuCurrentPage].enabled) {
                            gBadgeMenuCurrentPage -= 1;
                            selectedRow -= 1;
                        }
                    }
                } else {
                    // R button press
                    PauseItemPage* newPage;

                    gBadgeMenuCurrentPage++;
                    newPage = &gBadgeMenuPages[gBadgeMenuCurrentPage];

                    if (!newPage->enabled) {
                        gBadgeMenuCurrentPage -= 1;
                    } else {
                        selectedRow = newPage->listStart;
                    }
                }
            }

            newPageNumCols = gBadgeMenuPages[gBadgeMenuCurrentPage].numCols;
            if (gBadgeMenuItemIDs[selectedRow * newPageNumCols] != BADGE_NONE_STANDIN) {
                if (gPauseMenuHeldButtons & BUTTON_STICK_LEFT) {
                    selectedCol -= 1;
                    if (selectedCol < 0) {
                        selectedCol = newPageNumCols - 1;
                    }
                } else if (gPauseMenuHeldButtons & BUTTON_STICK_RIGHT) {
                    selectedCol += 1;
                    if (selectedCol >= newPageNumCols) {
                        selectedCol = 0;
                    }
                }
            } else {
                selectedCol = 0;
            }
            gBadgeMenuSelectedIndex = selectedCol + (selectedRow * gBadgeMenuPages[gBadgeMenuCurrentPage].numCols);
            if (gBadgeMenuSelectedIndex != selectedIndex) {
                sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
            }
            gBadgeMenuSelectedItemID = gBadgeMenuItemIDs[gBadgeMenuSelectedIndex];
        }
    }

    if (gBadgeMenuLevel == 1) {
        s32 itemID = gBadgeMenuSelectedItemID;

        if (((itemID != BADGE_NONE_STANDIN) && (itemID != BADGE_INVALID) && (itemID != 0))) {
            gPauseMenuCurrentDescMsg = gItemTable[itemID].menuMsg;
        } else {
            gPauseMenuCurrentDescMsg = 0;
            gPauseMenuCurrentDescIconScript = NULL;
        }
    } else {
        gPauseMenuCurrentDescMsg = pause_get_menu_msg(gBadgeMenuCurrentTab == 0 ? 0x4C : 0x4D);
        gPauseMenuCurrentDescIconScript = NULL;
    }

    if (gPauseMenuPressedButtons & BUTTON_B) {
        if (gBadgeMenuLevel == 0) {
            sfx_play_sound(SOUND_MENU_BACK);
            gPauseMenuCurrentTab = 0;
        } else {
            sfx_play_sound(SOUND_MENU_BACK);
            gBadgeMenuLevel = 0;
            enforce_hpfp_limits();
            if (gBadgeMenuCurrentTab == 1) {
                pause_badges_load_badges(TRUE);
            }
        }
    }
}

void pause_badges_update(void) {
    PauseItemPage* menuPages = gBadgeMenuPages;
    PauseItemPage* currentMenuPage = &menuPages[gBadgeMenuCurrentPage];
    s32 temp = (gBadgeMenuSelectedIndex / currentMenuPage->numCols) - currentMenuPage->listStart;
    s32* currentScrollPos;

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

    currentScrollPos = &gBadgeMenuCurrentScrollPos;
    gBadgeMenuTargetScrollPos = pause_badges_get_pos_y(gBadgeMenuCurrentPage, D_80270394 * currentMenuPage->numCols);
    *currentScrollPos += pause_interp_vertical_scroll(gBadgeMenuTargetScrollPos - *currentScrollPos);
}

void pause_badges_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gBadgeMenuIconIDs); i++) {
        free_hud_element(gBadgeMenuIconIDs[i]);
    }
}
