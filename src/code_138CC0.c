#include "common.h"

INCLUDE_ASM(s32, "code_138CC0", pause_stats_draw_contents);

INCLUDE_ASM(s32, "code_138CC0", pause_stats_init);

INCLUDE_ASM(s32, "code_138CC0", pause_stats_handle_input);

void pause_stats_cleanup(void) {
    s32* iconIDs = gStatsMenuIconIDs;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gStatsMenuIconIDs); i++) {
        free_icon(iconIDs[i]);
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

INCLUDE_ASM(s32, "code_138CC0", pause_badges_try_remove);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_try_equip);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_draw_bp_orbs);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_draw_contents);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_load_badges);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_init);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_handle_input);

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

INCLUDE_ASM(s32, "code_138CC0", pause_badges_cleanup);
