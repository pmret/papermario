#include "common.h"

INCLUDE_ASM(s32, "pause/138CC0", pause_stats_draw_contents);

INCLUDE_ASM(s32, "pause/138CC0", pause_stats_init);

INCLUDE_ASM(s32, "pause/138CC0", pause_stats_handle_input);

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
        aVal = ~0x8000;
    } else {
        aVal = gItemTable[*a].badgeSortPriority;
    }

    if (*b == 0) {
        bVal = ~0x8000;
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

    if (badgeID == 0x7FFF) {
        return 0;
    }

    for (i = 0; i < ARRAY_COUNT(gPlayerData.equippedBadges); ++i, ++currentSlot) {
        if (badgeID == *currentSlot) {
            slotToRemove = currentSlot;
            result = 1;
            break;
        }
    }

    // Remove and shift array contents
    for (; i < ARRAY_COUNT(gPlayerData.equippedBadges)-1; ++i, ++currentSlot) {
        *currentSlot = *(currentSlot+1);
    }
    *currentSlot = 0;

    if (*slotToRemove == 0) {
        result = 2;
    }
    return result;
}

typedef s32 BadgeEquipResult;
enum BadgeEquipResults {
    EQUIP_RESULT_ALREADY_EQUIPPED,
    EQUIP_RESULT_NOT_ENOUGH_BP,
    EQUIP_RESULT_TOO_MANY_BADGES,
    EQUIP_RESULT_SUCCESS,
};

BadgeEquipResult pause_badges_try_equip(s16 badgeID) {
    PlayerData* playerData = &gPlayerData;
    s16 *badgeSlot = &playerData->equippedBadges[0];
    s32 i;
    s32 totalEquippedBP;

    if (badgeID == 0x7FFE) {
        badgeID = 0;
    }
    if (badgeID == 0x7FFF) {
        badgeID = 0;
    }
    if (badgeID == 0) {
        return EQUIP_RESULT_NOT_ENOUGH_BP;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); ++i, ++badgeSlot) {
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
    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); ++i, ++badgeSlot) {
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
            pause_draw_rect(x * 4, y * 4, (x + orbSize) * 4, (y + orbSize) * 4, 0, 0, 0x100, 0x400, 0x400);
            break;
        case 1:
            pause_draw_rect(x * 4, y * 4, (x + orbSize) * 4, (y + orbSize) * 4, 0, 0, 0, 0x400, 0x400);
            break;
        default:
            pause_draw_rect(x * 4, y * 4, (x + orbSize) * 4, (y + orbSize) * 4, 0, 0, 0x200, 0x400, 0x400);
            break;
    }
}

INCLUDE_ASM(s32, "pause/138CC0", pause_badges_draw_contents);

#ifdef NON_MATCHING
// Slight instruction ordering mismatch, but this code is definitely semantically equivalent
void pause_badges_load_badges(s32 onlyEquipped) {
    PlayerData* playerData = &gPlayerData;
    s32 i;
    s32 numItems = 0;
    PauseItemPage* page;
    s16* menuItemIDs;

    D_80270388 = 0;
    if (!onlyEquipped) {
        i = 0;
        menuItemIDs = gBadgeMenuItemIDs;
        // A move instruction is out of order right here, no impact on behavior
        for (; i < ARRAY_COUNT(playerData->badges); ++i) {
            s16 badgeItemID = playerData->badges[i];
            if (badgeItemID == 0) {
                continue;
            } else if (badgeItemID >= ITEM_PARTNER_ATTACK) {
                break;
            } else {
                *menuItemIDs = badgeItemID;
                ++menuItemIDs;
                ++numItems;
            }
        }
    } else {
        s16* equippedBadges;
        pause_badges_count_equipped();
        equippedBadges = playerData->equippedBadges;
        i = 0;
        menuItemIDs = gBadgeMenuItemIDs;
        for (; i < ARRAY_COUNT(playerData->equippedBadges); ++i, ++equippedBadges) {
            if (*equippedBadges != 0) {
                *menuItemIDs = *equippedBadges;
                ++menuItemIDs;
                numItems += 1;
            }
        }
    }
    if (numItems == 0) {
        gBadgeMenuItemIDs[0] = 0x7FFE;
        numItems = 1;
    }
    gBadgeMenuNumItems = numItems;
    for (i = numItems; i < ARRAY_COUNT(gBadgeMenuItemIDs); ++i) {
        gBadgeMenuItemIDs[i] = 0x7FFF;
    }

    gBadgeMenuSelectedIndex = 0;
    gBadgeMenuSelectedItemID = 0;
    D_8027037C = 0;
    D_80270394 = 0;
    gBadgeMenuCurrentPage = 0;

    page = &gBadgeMenuPages[0];
    i = 0;
   
    while (1) {
        s32 totalItems = gBadgeMenuNumItems;
        if (i >= totalItems / 8) {
            break;
        }

        page->listStart = i*8;
        page->numCols = 1;
        page->numRows = 8;
        page->enabled = 1;
        page->startIndex = i*8;
        page->count = 8;

        i += 1;
        page += 1;
    }

    if (((u16) gBadgeMenuNumItems & 7) != 0) {
        s16 count;
        s32 menuNumItems;
        page->listStart = i * 8;
        page->numCols = 1;
        page->enabled = 1;
        page->startIndex = i * 8;

        menuNumItems = gBadgeMenuNumItems;
        count = menuNumItems - (menuNumItems / 8 * 8);
        page->count = count;
        page->numRows = page->count;
        i += 1;
        page += 1;
    }

    while (i < ARRAY_COUNT(gBadgeMenuPages)) {
        page->enabled = 0;

        ++i;
        ++page;
    }

    gBadgeMenuTargetScrollPos = gBadgeMenuCurrentScrollPos = pause_badges_get_pos_y(0, 0);
}
#else
INCLUDE_ASM(void, "pause/138CC0", pause_badges_load_badges, s32 arg);
#endif

void pause_badges_init(MenuPanel *panel) {
    s32 i;

    (void)pause_badges_count_all();
    gBadgeMenuLevel = 0;
    gBadgeMenuCurrentTab = 0;
    gBadgeMenuBShowNotEnoughBP = 0;

    pause_badges_load_badges(0);
    if (gBadgeMenuItemIDs[0] == 0x7FFE) {
        panel->initialized = 0;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(gBadgeMenuIconIDs); ++i) {
        s32 iconID = create_hud_element(gBadgeMenuElements[i]);
        gBadgeMenuIconIDs[i] = iconID;
        set_hud_element_flags(iconID, 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(gBadgeMenuWindowBPs); ++i) {
        gBadgeMenuWindowBPs[i].tab = panel;
    }
    setup_pause_menu_tab(gBadgeMenuWindowBPs, ARRAY_COUNT(gBadgeMenuWindowBPs));
    panel->initialized = 1;
}

void pause_badges_handle_input(void) {
    s32 selectedIndex = gBadgeMenuSelectedIndex;
    s32 numCols = gBadgeMenuPages[gBadgeMenuCurrentPage].numCols;

    s32 selectedCol = selectedIndex % numCols;
    s32 selectedRow = selectedIndex / numCols;

    if (gPauseMenuPressedButtons & BUTTON_A) {
        s16 badgeID;
        if (gBadgeMenuBShowNotEnoughBP != 0) {
            gBadgeMenuBShowNotEnoughBP = 0;
            return;
        }
        if (gBadgeMenuLevel == 0) {
            if (gBadgeMenuItemIDs[selectedIndex] == 0x7FFE) {
                sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                return;
            }
            gBadgeMenuLevel = 1;
            sfx_play_sound(SOUND_MENU_NEXT);
            return;
        }
        badgeID = gBadgeMenuItemIDs[selectedIndex];
        switch (pause_badges_try_equip(badgeID)) {
            case EQUIP_RESULT_ALREADY_EQUIPPED:
                sfx_play_sound(SOUND_MENU_BADGE_UNEQUIP);
                pause_badges_try_remove(badgeID);
                return;
            case EQUIP_RESULT_NOT_ENOUGH_BP:
                sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                gBadgeMenuBShowNotEnoughBP = 1;
                return;
            case EQUIP_RESULT_TOO_MANY_BADGES:
                sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                gBadgeMenuBShowNotEnoughBP = 2;
                return;
            case EQUIP_RESULT_SUCCESS:
                sfx_play_sound(SOUND_MENU_BADGE_EQUIP);
                return;
            default:
                return;
        }
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
                    if (selectedRow < (s32) gBadgeMenuPages[gBadgeMenuCurrentPage].listStart) {
                        gBadgeMenuCurrentPage -= 1;
                    }
                } else {
                    // Z button press
                    gBadgeMenuCurrentPage -= 1;
                    if (gBadgeMenuCurrentPage < 0) {
                        gBadgeMenuCurrentPage = 0;
                    }
                    selectedRow = (s32) gBadgeMenuPages[gBadgeMenuCurrentPage].listStart;
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
                        if (gBadgeMenuPages[gBadgeMenuCurrentPage].enabled == 0) {
                            gBadgeMenuCurrentPage -= 1;
                            selectedRow -= 1;
                        }
                    }
                } else {
                    // R button press
                    PauseItemPage* newPage = &gBadgeMenuPages[++gBadgeMenuCurrentPage];

                    if (newPage->enabled == 0) {
                        gBadgeMenuCurrentPage -= 1;
                    } else {
                        selectedRow = (s32) newPage->listStart;
                    }
                }
            }

            newPageNumCols = gBadgeMenuPages[gBadgeMenuCurrentPage].numCols;
            if (gBadgeMenuItemIDs[selectedRow * newPageNumCols] != 0x7FFE) {
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
        if (((itemID != 0x7FFE) && (itemID != 0x7FFF) && (itemID != 0))) {
            gPauseMenuCurrentDescMsg = gItemTable[itemID].menuMsg;
        } else {
            gPauseMenuCurrentDescMsg = 0;
            gPauseMenuCurrentDescIconScript = NULL;
        }
    } else {
        gPauseMenuCurrentDescMsg = pause_get_menu_msg(gBadgeMenuCurrentTab == 0 ? 0x4C : 0x4D);
        gPauseMenuCurrentDescIconScript = NULL;
    }

    if ((gPauseMenuPressedButtons & BUTTON_B) != 0) {
        if (gBadgeMenuLevel == 0) {
            sfx_play_sound(SOUND_MENU_BACK);
            gPauseMenuCurrentTab = 0;
        } else {
            sfx_play_sound(SOUND_MENU_BACK);
            gBadgeMenuLevel = 0;
            enforce_hpfp_limits();
            if (gBadgeMenuCurrentTab == 1) {
                pause_badges_load_badges(1);
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
    for (i = 0; i < ARRAY_COUNT(gBadgeMenuIconIDs); ++i) {
        free_hud_element(gBadgeMenuIconIDs[i]);
    }
}
