#include "common.h"

void clear_player_data(void) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    D_8010CD10 = 0;
    D_8010CD12 = 0;

    playerData->hammerLevel = -1;
    playerData->curHP = 10;
    playerData->curMaxHP = 10;
    playerData->hardMaxHP = 10;
    playerData->curFP = 5;
    playerData->curMaxFP = 5;
    playerData->hardMaxFP = 5;
    playerData->maxBP = 3;
    playerData->level = 1;
    playerData->bootsLevel = 0;
    playerData->hasActionCommands = 0;
    playerData->coins = 0;
    playerData->fortressKeyCount = 0;
    playerData->starPieces = 0;
    playerData->starPoints = 0;
    playerData->unk_11 = 0;
    playerData->unk_288 = 0;
    playerData->merleeSpellType = 0;
    playerData->merleeCastsLeft = 0;
    playerData->merleeTurnCount = -1;
    playerData->maxStarPower = 0;
    playerData->specialBarsFilled = 0;
    playerData->unk_292[0] = 0;
    playerData->currentPartner = 0;

    for (i = 0; i < ARRAY_COUNT(playerData->partners); i++) {
        playerData->partners[i].enabled = FALSE;
        playerData->partners[i].level = 0;
        playerData->partners[i].unk_02[0] = 0;
        playerData->partners[i].unk_02[1] = 0;
        playerData->partners[i].unk_02[2] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
        playerData->keyItems[i] = ITEM_NONE;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
        playerData->badges[i] = ITEM_NONE;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        playerData->invItems[i] = ITEM_NONE;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
        playerData->equippedBadges[i] = ITEM_NONE;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->storedItems); i++) {
        playerData->storedItems[i] = ITEM_NONE;
    }

    playerData->otherHitsTaken = 0;
    playerData->unk_296 = 0;
    playerData->hitsTaken = 0;
    playerData->hitsBlocked = 0;
    playerData->playerFirstStrikes = 0;
    playerData->enemyFirstStrikes = 0;
    playerData->powerBounces = 0;
    playerData->battlesCount = 0;
    playerData->unk_2A4[0] = 0;
    playerData->unk_2A4[1] = 0;
    playerData->unk_2A4[2] = 0;
    playerData->unk_2A4[3] = 0;
    playerData->unk_2AC = 0;
    playerData->unk_2B0 = 0;
    playerData->idleFrameCounter = 0;
    playerData->totalCoinsEarned = 0;
    playerData->frameCounter = 0;
    playerData->quizzesAnswered = 0;
    playerData->quizzesCorrect = 0;

    for (i = 0; i < ARRAY_COUNT(playerData->unk_2C4); i++) {
        playerData->unk_2C4[i] = 0;
        playerData->unk_2F4[i] = 0;
    }

    playerData->unk_328 = 0;
    playerData->starPiecesCollected = 0;
    playerData->jumpGamePlays = 0;
    playerData->jumpGameTotal = 0;
    playerData->jumpGameRecord = 0;
    playerData->smashGamePlays = 0;
    playerData->smashGameTotal = 0;
    playerData->smashGameRecord = 0;
}

PlayerData* get_player_data(void) {
    return &gPlayerData;
}

s32 add_item(s32 itemID) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    sort_items();

    for (i = 0; i < ARRAY_COUNT(gPlayerData.invItems); i++) {
        if (playerData->invItems[i] == ITEM_NONE) {
            break;
        }
    }

    if (i == ARRAY_COUNT(gPlayerData.invItems)) {
        return -1;
    }

    playerData->invItems[i] = itemID;
    return i;
}

s32 get_item_count(void) {
    PlayerData* playerData = &gPlayerData;
    s32 i = 0;
    s32 sum = 0;

    for (i; i < ARRAY_COUNT(gPlayerData.invItems); i++) {
        if (playerData->invItems[i] != ITEM_NONE) {
            sum++;
        }
    }

    return sum;
}

s32 get_item_empty_count(void) {
    return ARRAY_COUNT(gPlayerData.invItems) - get_item_count();
}

/// @returns the index of the given item in the player's inventory, or -1 if not found
s32 find_item(s32 itemID) {
    PlayerData* playerData = &gPlayerData;
    StaticItem* item = &gItemTable[itemID];
    s32 i;

    if ((item->typeFlags & 8) != 0) {
        for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
            if (playerData->keyItems[i] == itemID) {
                break;
            }
        }

        if (i >= ARRAY_COUNT(playerData->keyItems)) {
            return -1;
        }

        return i;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        if (playerData->invItems[i] == itemID) {
            break;
        }
    }

    if (i == ARRAY_COUNT(playerData->invItems)) {
        return -1;
    }

    return i;
}

/// Bubbles up player inventory items such that all ITEM_NONE values are at the bottom.
void sort_items(void) {
    PlayerData* playerData = &gPlayerData;
    s32 j;
    s32 i;

    for (i = ARRAY_COUNT(playerData->invItems) - 2; i >= 0; i--) {
        if (playerData->invItems[i] != ITEM_NONE) {
            for (j = ARRAY_COUNT(playerData->invItems) - 1; i < j; j--) {
                if (playerData->invItems[j] == ITEM_NONE) {
                    playerData->invItems[j] = playerData->invItems[i];
                    playerData->invItems[i] = ITEM_NONE;
                    break;
                }
            }
        }
    }
}

s32 add_badge(s32 itemID) {
    PlayerData* playerData = &gPlayerData;
    StaticItem* item = &gItemTable[itemID];
    s32 i;

    if ((item->typeFlags & 0x40) == 0) {
        return add_item(itemID);
    }

    for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
        if (playerData->badges[i] == ITEM_NONE) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(playerData->badges)) {
        return 0;
    }

    playerData->badges[i] = itemID;
    return i;
}

s32 store_item(s32 itemID) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPlayerData.storedItems); i++) {
        if (playerData->storedItems[i] == ITEM_NONE) {
            break;
        }
    }

    if (i == ARRAY_COUNT(gPlayerData.storedItems)) {
        return -1;
    } else {
        playerData->storedItems[i] = itemID;
    }

    return i;
}

s32 get_stored_count(void) {
    PlayerData* playerData = &gPlayerData;
    s32 i = 0;
    s32 sum = 0;

    for (i; i < ARRAY_COUNT(gPlayerData.storedItems); i++) {
        if (playerData->storedItems[i] != ITEM_NONE) {
            sum++;
        }
    }

    return sum;
}

s32 get_stored_empty_count(void) {
    return ARRAY_COUNT(gPlayerData.storedItems) - get_stored_count();
}

void enforce_hpfp_limits(void) {
    PlayerData* playerData = &gPlayerData;
    PlayerData* playerData2 = &gPlayerData;

    playerData->curMaxHP = playerData->hardMaxHP + (is_ability_active(4) * 5);
    if (playerData->curMaxHP > 75) {
        playerData->curMaxHP = 75;
    }
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }

    playerData2->curMaxFP = playerData2->hardMaxFP + (is_ability_active(12) * 5);
    if (playerData2->curMaxFP > 75) {
        playerData2->curMaxFP = 75;
    }
    if (playerData2->curFP > playerData2->curMaxFP) {
        playerData2->curFP = playerData2->curMaxFP;
    }
}

void initialize_status_menu(void) {
    UiStatus* uiStatus = &gUIStatus;
    PlayerData* playerData = &gPlayerData;
    s32 iconIndex;
    s32 newVar;

    uiStatus->drawPosX = 12;
    D_8010CD10 = 0;
    D_8010CD12 = 0;
    uiStatus->drawPosY = -100;
    uiStatus->hidden = 0;
    uiStatus->showTimer = 210;
    uiStatus->unk_3B[0] = 0;
    uiStatus->ignoreChanges = 0;
    uiStatus->unk_45[0] = 0;
    uiStatus->unk_45[1] = 0;
    uiStatus->hpBlinking = 0;
    uiStatus->hpBlinkCounter = 0;
    uiStatus->hpBlinkTimer = 0;
    uiStatus->fpBlinking = 0;
    uiStatus->fpBlinkCounter = 0;
    uiStatus->fpBlinkTimer = 0;
    uiStatus->spBlinking = 0;
    uiStatus->spBlinkCounter = 0;
    uiStatus->coinsBlinking = 0;
    uiStatus->coinsBlinkCounter = 0;
    uiStatus->coinsBlinkTimer = 0;
    uiStatus->disabled = 0;
    uiStatus->starpointsBlinking = 0;
    uiStatus->displayHP = playerData->curHP;
    uiStatus->displayFP = playerData->curFP;
    uiStatus->displayCoins = playerData->coins;
    uiStatus->displayStarpoints = playerData->starPoints;
    uiStatus->displaySP = playerData->specialBarsFilled;
    uiStatus->starpointsBlinkCounter = 0;
    uiStatus->unk_6C[2] = -1;
    uiStatus->unk_3B[1] = 0;
    uiStatus->unk_57[0] = 0;
    uiStatus->unk_57[1] = 0;
    uiStatus->unk_57[2] = 0;
    uiStatus->unk_57[3] = 0;
    uiStatus->unk_6C[0] = 0;
    uiStatus->unk_6C[1] = 0;
    uiStatus->iconIndex12 = -1;

    close_status_menu();

    iconIndex = create_icon(&D_80108248);
    uiStatus->hpIconIndexes[0] = iconIndex;
    set_icon_flags(iconIndex, 0x80);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_80108518);
    uiStatus->hpIconIndexes[1] = iconIndex;
    set_icon_flags(iconIndex, 0x80);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_80108270);
    uiStatus->fpIconIndexes[0] = iconIndex;
    set_icon_flags(iconIndex, 0x80);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_80108538);
    uiStatus->fpIconIndexes[1] = iconIndex;
    set_icon_flags(iconIndex, 0x80);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_80108558);
    uiStatus->coinIconIndex = iconIndex;
    set_icon_flags(iconIndex, 0x80);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_80080FC4);
    uiStatus->coinIconIndex2 = iconIndex;
    set_icon_flags(iconIndex, 0x80);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_801086AC);
    uiStatus->starpointsIconIndex = iconIndex;
    set_icon_flags(iconIndex, 0x80);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_80104BEC);
    uiStatus->starpointsIconIndex2 = iconIndex;
    set_icon_flags(iconIndex, 0x80);
    clear_icon_flags(iconIndex, 0x8000);

    newVar = create_icon(&D_80108068);
    iconIndex = newVar;
    uiStatus->iconIndex8 = iconIndex;
    set_icon_flags(iconIndex, 0x82);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_80108068);
    uiStatus->iconIndex9 = iconIndex;
    set_icon_flags(iconIndex, 0x82);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_80108068);
    uiStatus->iconIndexA = iconIndex;
    set_icon_flags(iconIndex, 0x82);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_80108068);
    uiStatus->iconIndexB = iconIndex;
    set_icon_flags(iconIndex, 0x82);
    clear_icon_flags(iconIndex, 0x8000);

    iconIndex = create_icon(&D_801083D8);
    uiStatus->iconIndexC = iconIndex;
    set_icon_flags(iconIndex, 0x80);
    clear_icon_flags(iconIndex, 0x8000);

    func_800F0D5C();
}

INCLUDE_ASM(s32, "80850_len_3060", status_menu_draw_number);

INCLUDE_ASM(s32, "80850_len_3060", status_menu_draw_stat);

INCLUDE_ASM(s32, "80850_len_3060", update_status_menu);

void coin_counter_draw_content(UNK_TYPE arg0, s32 posX, s32 posY) {
    UiStatus* uiStatus = &gUIStatus;
    s32 iconIndex;

    if ((gPlayerData.coins != uiStatus->displayCoins) && ((gGameStatusPtr->frameCounter % 3) == 0)) {
        sfx_play_sound(0x211);
    }

    iconIndex = uiStatus->iconIndex10;
    set_icon_render_pos(iconIndex, posX + 27, posY + 11);
    draw_icon_0(iconIndex);

    iconIndex = uiStatus->iconIndex11;
    set_icon_render_pos(iconIndex, posX + 15, posY + 11);
    draw_icon_0(iconIndex);

    draw_number(uiStatus->displayCoins, posX + 58, posY + 4, 1, 10, 255, 3);
}

void update_coin_counter(void) {
    UiStatus* uiStatus = &gUIStatus;
    PlayerData* playerData = &gPlayerData;

    do {} while (0); // Needed to match

    if (uiStatus->unk_6C[1] != 0) {
        uiStatus->unk_6C[1] -= 1;
        if (((uiStatus->unk_6C[1] << 24) == 0) && (uiStatus->iconIndex12 >= 0)) {
            free_icon(uiStatus->iconIndex12);
            free_icon(uiStatus->iconIndex13);
            uiStatus->iconIndex12 = -1;
        }
        D_8010CD12 = 0;
    }

    if (uiStatus->unk_6C[0] != 0) {
        if ((uiStatus->displayCoins == playerData->coins) && (uiStatus->unk_6C[0] > 30)) {
            uiStatus->unk_6C[0] = 30;
        }

        if ((uiStatus->displayCoins == playerData->coins) || (uiStatus->unk_6C[0] <= 30)) {
            uiStatus->unk_6C[0] -= 1;
            if (uiStatus->unk_6C[0] == 0) {
                set_window_update(20, basic_hidden_window_update);
                uiStatus->unk_6C[1] = 15;
                D_8010CD10 = 0;
                D_8010CD12 = 1;
                uiStatus->iconIndex12 = uiStatus->iconIndex10;
                uiStatus->iconIndex13 = uiStatus->iconIndex11;
                uiStatus->displayCoins = playerData->coins;
                if (uiStatus->unk_6C[2] > -1) {
                    uiStatus->ignoreChanges = uiStatus->unk_6C[2];
                    uiStatus->unk_6C[2] = -1;
                }
            }
        }
    }
}

void show_coin_counter(void) {
    UiStatus* uiStatus = &gUIStatus;
    s32 index;

    if ((D_8010CD10 != 0) || (D_8010CD12 != 0)) {
        set_window_update(0x14, 2);
        if (uiStatus->iconIndex12 > -1) {
            free_icon(uiStatus->iconIndex10);
            free_icon(uiStatus->iconIndex11);
            uiStatus->iconIndex12 = -1;
        }
        uiStatus->unk_6C[0] = 0;
        uiStatus->unk_6C[1] = 0;
        D_8010CD10 = 0;
        D_8010CD12 = 0;
    }

    if (uiStatus->unk_6C[0] == 0) {
        set_window_properties(0x14, 0x20, 0xa4, 0x40, 0x14, 0x15, coin_counter_draw_content, 0, -1);
        set_window_update(0x14, basic_window_update);
        index = create_icon(&D_80109270);
        uiStatus->iconIndex10 = index;
        set_icon_flags(index, 0x80);
        icon_set_tint(index, 0xff, 0xff, 0xff);
        index = create_icon(&D_80108558);
        uiStatus->iconIndex11 = index;
        set_icon_flags(index, 0x80);
        icon_set_tint(index, 0xff, 0xff, 0xff);
        uiStatus->unk_6C[0] = 0;

        if (uiStatus->unk_6C[2] < 0) {
            uiStatus->unk_6C[2] = uiStatus->ignoreChanges;
        }

        uiStatus->ignoreChanges = 1;
        D_8010CD10 = 1;
    }
}

void hide_coin_counter(void) {
    UiStatus* uiStatus = &gUIStatus;

    if ((D_8010CD10 != 0) && (uiStatus->unk_6C[0] == 0)) {
        uiStatus->unk_6C[0] = 60;
    }
}

void func_800E96C8(void) {
    UiStatus* uiStatus = &gUIStatus;

    if ((D_8010CD10 != 0) && (uiStatus->unk_6C[0] == 0)) {
        uiStatus->unk_6C[0] = 1;
    }
}

ApiStatus ShowCoinCounter(ScriptInstance* script, s32 isInitialCall) {
    if (get_variable(script, *script->ptrReadPos)) {
        show_coin_counter();
    } else {
        hide_coin_counter();
    }

    return ApiStatus_DONE2;
}

void draw_status_ui(void) {
    update_status_menu();
    update_coin_counter();
}

void open_status_menu_long(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->hidden) {
        uiStatus->showTimer = 210;
        uiStatus->hidden = 0;
        uiStatus->unk_3B[0] = 1;
    }
}

void open_status_menu_short(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->hidden) {
        uiStatus->showTimer = 105;
        uiStatus->hidden = 0;
        uiStatus->unk_3B[0] = 1;
    }
}

void close_status_menu(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->hidden != 1) {
        uiStatus->hidden = 1;
        uiStatus->showTimer = 0;
        uiStatus->unk_3B[0] = 1;
    }
}

void func_800E97E4(void) {
    UiStatus* uiStatus = &gUIStatus;

    uiStatus->drawPosY = -100;
    uiStatus->ignoreChanges = 0;
    uiStatus->showTimer = 0;
    uiStatus->hidden = 1;
    uiStatus->unk_3B[0] = 0;
    uiStatus->unk_3B[1] = 0;
}

void func_800E9810(void) {
    UiStatus* uiStatus = &gUIStatus;

    uiStatus->showTimer = 210;
    uiStatus->drawPosY = 0;
    uiStatus->ignoreChanges = 0;
    uiStatus->hidden = 0;
    uiStatus->unk_3B[0] = 1;
    uiStatus->unk_3B[1] = 0;
}

void func_800E983C(void) {
    gUIStatus.unk_45[0] = 0;
}

void func_800E984C(void) {
    gUIStatus.unk_45[0] = 1;
}

s32 func_800E9860(void) {
    UiStatus* uiStatus = &gUIStatus;

    s32 ret = 1 - uiStatus->unk_45[0];

    if (uiStatus->unk_45[1] != 0) {
        ret = 0;
    }
    if (uiStatus->ignoreChanges) {
        ret = 0;
    }
    return ret;
}

void func_800E9894(void) {
    gUIStatus.ignoreChanges = 1;
}

void func_800E98A8(void) {
    UiStatus* uiStatus = &gUIStatus;

    uiStatus->ignoreChanges = 1;
    uiStatus->drawPosY = 18;
}

void func_800E98C4(void) {
    gUIStatus.ignoreChanges = 0;
}

s32 func_800E98D4(void) {
    UiStatus* uiStatus = &gUIStatus;

    return uiStatus->unk_45[1] + uiStatus->ignoreChanges;
}

void func_800E98EC(void) {
    gUIStatus.unk_45[1] = 1;
}

void func_800E9900(void) {
    gUIStatus.unk_45[1] = 0;
}

s32 is_status_menu_visible(void) {
    return !gUIStatus.hidden;
}

void status_menu_start_blinking_hp(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (gGameStatusPtr->isBattle == 0) {
        uiStatus->hpBlinkTimer = 120;
    }

    if (uiStatus->hpBlinking != 1) {
        uiStatus->hpBlinking = 1;
        uiStatus->hpBlinkCounter = 0;
    }
}

void status_menu_stop_blinking_hp(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->hpBlinking != 0) {
        uiStatus->hpBlinking = 0;
        uiStatus->hpBlinkCounter = 0;
        uiStatus->hpBlinkTimer = 0;
    }
}

void status_menu_start_blinking_fp(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (gGameStatusPtr->isBattle == 0) {
        uiStatus->fpBlinkTimer = 120;
    }

    if (uiStatus->fpBlinking != 1) {
        uiStatus->fpBlinking = 1;
        uiStatus->fpBlinkCounter = 0;
    }
}

void status_menu_stop_blinking_fp(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->fpBlinking != 0) {
        uiStatus->fpBlinking = 0;
        uiStatus->fpBlinkCounter = 0;
    }
}

void status_menu_start_blinking_coins(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (gGameStatusPtr->isBattle == 0) {
        uiStatus->coinsBlinkTimer = 120;
    }

    if (uiStatus->coinsBlinking != 1) {
        uiStatus->coinsBlinking = 1;
        uiStatus->coinsBlinkCounter = 0;
    }
}

void status_menu_stop_blinking_coins(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->coinsBlinking != 0) {
        uiStatus->coinsBlinking = 0;
        uiStatus->coinsBlinkCounter = 0;
        uiStatus->coinsBlinkTimer = 0;
    }
}

void status_menu_start_blinking_sp(void) {
    PlayerData* playerData = &gPlayerData;
    UiStatus* uiStatus = &gUIStatus;

    uiStatus->spBarsToBlink = playerData->maxStarPower;
    if (uiStatus->spBlinking != 1) {
        uiStatus->spBlinking = 1;
        uiStatus->spBlinkCounter = 0;
    }
}

void status_menu_stop_blinking_sp(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->spBlinking != 0) {
        uiStatus->spBlinking = 0;
        uiStatus->spBlinkCounter = 0;
    }
}

void status_menu_start_blinking_sp_bars(s8 numBarsToBlink) {
    UiStatus* uiStatus = &gUIStatus;

    uiStatus->spBarsToBlink = numBarsToBlink;
    if (uiStatus->spBlinking != 1) {
        uiStatus->spBlinking = 1;
        uiStatus->spBlinkCounter = 0;
    }
}

void status_menu_start_blinking_starpoints(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->starpointsBlinking != 1) {
        uiStatus->starpointsBlinking = 1;
        uiStatus->starpointsBlinkCounter = 0;
    }
}

void status_menu_stop_blinking_starpoints(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->starpointsBlinking != 0) {
        uiStatus->starpointsBlinking = 0;
        uiStatus->starpointsBlinkCounter = 0;
    }
}

void decrement_status_menu_disabled(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->disabled > 0) {
        uiStatus->disabled--;
    }
}

void increment_status_menu_disabled(void) {
    UiStatus* uiStatus = &gUIStatus;

    uiStatus->disabled++;
}

void sync_status_menu(void) {
    PlayerData* playerData = &gPlayerData;
    UiStatus* uiStatus = &gUIStatus;

    uiStatus->displayHP = playerData->curHP;
    uiStatus->displayFP = playerData->curFP;
    uiStatus->displaySP = playerData->specialBarsFilled;
    uiStatus->displayCoins = playerData->coins;
    uiStatus->displayStarpoints = playerData->starPoints;
}

void reset_status_menu(void) {
    PlayerData* playerData = &gPlayerData;
    UiStatus* uiStatus = &gUIStatus;
    s32 i;

    uiStatus->drawPosX = 12;
    uiStatus->drawPosY = -100;
    uiStatus->hidden = 0;
    uiStatus->showTimer = 210;
    uiStatus->unk_3B[0] = 0;
    uiStatus->ignoreChanges = 0;
    uiStatus->unk_45[0] = 0;
    uiStatus->unk_45[1] = 0;
    uiStatus->hpBlinking = 0;
    uiStatus->hpBlinkCounter = 0;
    uiStatus->hpBlinkTimer = 0;
    uiStatus->fpBlinking = 0;
    uiStatus->fpBlinkCounter = 0;
    uiStatus->fpBlinkTimer = 0;
    uiStatus->coinsBlinking = 0;
    uiStatus->coinsBlinkCounter = 0;
    uiStatus->coinsBlinkTimer = 0;
    uiStatus->spBlinking = 0;
    uiStatus->spBlinkCounter = 0;
    uiStatus->disabled = 0;
    uiStatus->starpointsBlinking = 0;
    uiStatus->starpointsBlinkCounter = 0;
    uiStatus->unk_6C[2] = -1;
    uiStatus->displayHP = playerData->curHP;
    uiStatus->displayFP = playerData->curFP;
    uiStatus->displayCoins = playerData->coins;
    uiStatus->displayStarpoints = playerData->starPoints;
    uiStatus->displaySP = playerData->specialBarsFilled;
    uiStatus->unk_3B[1] = 0;

    for (i = 0; i < 2; i++) {
        func_801452B4(uiStatus->hpIconIndexes[i], uiStatus->hpIconIndexes[i]);
    }

    for (i = 0; i < 2; i++) {
        func_801452B4(uiStatus->fpIconIndexes[i], uiStatus->fpIconIndexes[i]);
    }

    func_801452B4(uiStatus->coinIconIndex, uiStatus->coinIconIndex);
    func_801452B4(uiStatus->coinIconIndex2, uiStatus->coinIconIndex2);
    func_801452B4(uiStatus->starpointsIconIndex, uiStatus->starpointsIconIndex);
    func_801452B4(uiStatus->starpointsIconIndex2, uiStatus->starpointsIconIndex2);
    func_801452B4(uiStatus->iconIndex8, uiStatus->iconIndex8);
    func_801452B4(uiStatus->iconIndex9, uiStatus->iconIndex9);
    func_801452B4(uiStatus->iconIndexA, uiStatus->iconIndexA);
    func_801452B4(uiStatus->iconIndexB, uiStatus->iconIndexB);
    func_801452B4(uiStatus->iconIndexC, uiStatus->iconIndexC);
}

#ifdef NON_MATCHING
// uses a jumptable, which we need .rodata support for.
// Somewhat close. Needs work.
/*
s32 is_ability_active(s32 arg0) {
    s32 iVar2;
    u32 uVar3;
    s32 iVar5;
    s32 piVar6;
    s32 i;
    s32 local_20[6];
    s32 badge;
    player_data* playerData = &gPlayerData;
    s32 iVar7 = 0;
    u32 uVar4;

    iVar5 = 0;
    //iVar7 = 0;

    for (i = 5; i >= 0; i--) {
        local_20[i] = 0;
    }

    if ((gGameStatusPtr->unk_7E & 1) == 0) {
        iVar2 = 0;
        iVar7 = 0;
        piVar6 = 0;
        for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
            s32 index = i;
            badge = playerData->equippedBadges[index];
            if (playerData->equippedBadges[index] != 0) {
                uVar4 = gItemTable[badge].moveID;
            }
            switch (arg0) {
                case 0:
                    uVar3 = 0x4c;
                    break;
                default:
                    continue;
                case 2:
                    uVar3 = 0x40;
                    break;
                case 3:
                    uVar3 = 0x4d;
                    break;
                case 4:
                    uVar3 = 0x52;
                    break;
                case 5:
                    uVar3 = 0x35;
                    break;
                case 6:
                    if (uVar4 == 0x53) {
                        iVar7++;
                    }
                    if (playerData->hasActionCommands != 0) {
                        iVar7++;
                    }
                    continue;
                case 7:
                    uVar3 = 0x41;
                    break;
                case 8:
                    uVar3 = 0x42;
                    break;
                case 9:
                    uVar3 = 0x5a;
                    break;
                case 10:
                    uVar3 = 0x3c;
                    break;
                case 0xb:
                    uVar3 = 0x4e;
                    break;
                case 0xc:
                    uVar3 = 0x5b;
                    break;
                case 0xd:
                    uVar3 = 0x3d;
                    break;
                case 0xe:
                    uVar3 = 0x43;
                    break;
                case 0xf:
                    if (uVar4 == 0x54) {
                        local_20[piVar6] = 1;
                        piVar6++;
                        iVar5++;
                        iVar7 = -1;
                    }
                    if (uVar4 == 0x55) {
                        local_20[piVar6] = 2;
                        piVar6++;
                        iVar5++;
                        iVar7 = -1;
                    }
                    if (uVar4 == 0x56) {
                        local_20[piVar6] = 3;
                        piVar6++;
                        iVar5++;
                        iVar7 = -1;
                    }
                    if (uVar4 == 0x57) {
                        local_20[piVar6] = 4;
                        piVar6++;
                        iVar5++;
                        iVar7 = -1;
                    }
                    if (uVar4 == 0x58) {
                        local_20[piVar6] = 5;
                        piVar6++;
                        iVar5++;
                        iVar7 = -1;
                    }
                    if (uVar4 == 0x59) {
                        local_20[piVar6] = 6;
                        piVar6++;
                        iVar5++;
                        iVar7 = -1;
                    }
                    continue;
                case 0x10:
                    uVar3 = 0x5c;
                    break;
                case 0x11:
                    uVar3 = 0x5d;
                    break;
                case 0x12:
                    uVar3 = 0x5e;
                    break;
                case 0x13:
                    uVar3 = 0x44;
                    break;
                case 0x14:
                    uVar3 = 0x5f;
                    break;
                case 0x15:
                    uVar3 = 0x60;
                    break;
                case 0x16:
                    uVar3 = 0x4f;
                    break;
                case 0x17:
                    uVar3 = 0x61;
                    break;
                case 0x18:
                    uVar3 = 0x62;
                    break;
                case 0x19:
                    uVar3 = 99;
                    break;
                case 0x1b:
                    uVar3 = 0x45;
                    break;
                case 0x1c:
                    uVar3 = 0x3b;
                    break;
                case 0x1d:
                    uVar3 = 0x6e;
                    break;
                case 0x1e:
                    uVar3 = 100;
                    break;
                case 0x1f:
                    uVar3 = 0x65;
                    break;
                case 0x20:
                    uVar3 = 0x46;
                    break;
                case 0x21:
                    uVar3 = 0x47;
                    break;
                case 0x22:
                    uVar3 = 0x3e;
                    break;
                case 0x23:
                    uVar3 = 0x48;
                    break;
                case 0x24:
                    uVar3 = 0x66;
                    break;
                case 0x25:
                    uVar3 = 0x49;
                    break;
                case 0x26:
                    uVar3 = 0x67;
                    break;
                case 0x27:
                    uVar3 = 0x6d;
                    break;
                case 0x28:
                    uVar3 = 0x6a;
                    break;
                case 0x29:
                    uVar3 = 0x6c;
                    break;
                case 0x2a:
                    uVar3 = 0x50;
                    break;
                case 0x1a:
                    uVar3 = 0x38;
                    break;
                case 0x2b:
                    uVar3 = 0x68;
                    break;
                case 0x2c:
                    uVar3 = 0x69;
                    break;
                case 0x2d:
                    uVar3 = 0x6b;
                    break;
                case 0x2e:
                    uVar3 = 0x6f;
                    break;
                case 0x2f:
                    uVar3 = 0x70;
                    break;
                case 0x30:
                    uVar3 = 0x71;
                    break;
                case 0x31:
                    uVar3 = 0x72;
                    break;
                case 0x32:
                    uVar3 = 0x73;
                    break;
                case 0x33:
                    uVar3 = 0x33;
                    break;
                case 0x34:
                    uVar3 = 0x74;
                    break;
                case 0x35:
                    uVar3 = 0x75;
                    break;
                case 0x36:
                    uVar3 = 0x76;
                    break;
                case 0x37:
                    uVar3 = 0x4a;
            }
            if (uVar4 == uVar3) {
                iVar7++;
            }
        }
        if (iVar7 < 0) {
            iVar7 = local_20[rand_int(iVar5 - 1)];
        }
        return iVar7;
    }
}
*/
#else
INCLUDE_ASM(s32, "80850_len_3060", is_ability_active, s32 arg0);
#endif

s32 is_partner_ability_active(void) {
    return 0;
}

s32 add_coins(s32 amt) {
    PlayerData* playerData = &gPlayerData;
    s16 newCoins = playerData->coins + amt;

    playerData->coins = newCoins;
    if (newCoins > 999) {
        playerData->coins = 999;
    }
    if (playerData->coins < 0) {
        playerData->coins = 0;
    }

    if (amt > 0) {
        playerData->totalCoinsEarned += amt;
        if (playerData->totalCoinsEarned > 99999) {
            playerData->totalCoinsEarned = 99999;
        }
    }
    return playerData->coins;
}

s8 add_star_points(s32 amt) {
    PlayerData* playerData = &gPlayerData;
    s8 newSP = playerData->starPoints + amt;

    // TODO: probably a macro!
    playerData->starPoints = newSP;
    if (newSP > 100) {
        playerData->starPoints = 100;
    }

    // TODO: probably a macro!
    newSP = playerData->starPoints;
    if (newSP < 0) {
        playerData->starPoints = 0;
    }
    return gPlayerData.starPoints;
}

u8 add_star_pieces(s32 amt) {
    PlayerData* playerData = &gPlayerData;
    PlayerData* playerData2 = &gPlayerData;
    s32 newSP = playerData->starPieces;

    newSP += amt;
    if (newSP > 222) {
        newSP = 222;
    }
    if (newSP < 0) {
        newSP = 0;
    }
    playerData->starPieces = newSP;

    if (amt > 0) {
        playerData->starPiecesCollected += amt;
    }

    return playerData2->starPieces;
}

void increment_max_SP() {
    PlayerData* playerData = &gPlayerData;

    playerData->maxStarPower++;
    playerData->specialBarsFilled = playerData->maxStarPower * 256;
}

void set_max_SP(s8 newMaxSP) {
    PlayerData* playerData = &gPlayerData;

    playerData->maxStarPower = newMaxSP;
    playerData->specialBarsFilled = newMaxSP * 256;
}

void add_SP(s32 amt) {
    // TODO cleanup
    PlayerData* playerData = &gPlayerData;
    PlayerData* playerData2 = &gPlayerData;
    UiStatus* uiStatus = &gUIStatus;
    UiStatus* uiStatus2 = &gUIStatus;
    s32 phi_v1;
    s32 blah;

    uiStatus->unk_57[0] = 1;
    uiStatus->unk_57[1] = 60;

    phi_v1 = playerData->specialBarsFilled;
    if (phi_v1 < 0) {
        phi_v1 = playerData->specialBarsFilled + 31;
    }
    uiStatus->unk_57[2] = phi_v1 >> 5;

    playerData->specialBarsFilled += amt;

    blah = playerData->maxStarPower << 8;
    if (playerData->specialBarsFilled > blah) {
        playerData->specialBarsFilled = blah;
    }

    uiStatus2->displaySP = playerData2->specialBarsFilled;
}

s32 recover_fp(s32 amt) {
    PlayerData* playerData = &gPlayerData;
    s32 newFP = playerData->curFP;
    s32 ret;

    if (amt == -2) {
        playerData->curMaxFP += 1;
        playerData->curFP = playerData->curMaxFP;
        return playerData->curMaxFP;
    }

    if (amt > 0) {
        newFP += amt;
    }
    if ((amt == -1) || (ret = newFP, (playerData->curMaxFP < newFP))) {
        ret = playerData->curMaxFP;
    }

    playerData->curFP = ret;
    return ret;
}

s32 recover_hp(s32 amt) {
    PlayerData* playerData = &gPlayerData;
    s32 newHP = playerData->curHP;
    s32 ret;

    if (amt == -2) {
        playerData->curMaxHP += 1;
        playerData->curHP = playerData->curMaxHP;
        return playerData->curMaxHP;
    }

    if (amt > 0) {
        newHP += amt;
    }
    if ((amt == -1) || (ret = newHP, (playerData->curMaxHP < newHP))) {
        ret = playerData->curMaxHP;
    }

    playerData->curHP = ret;
    return ret;
}

void subtract_hp(s32 amt) {
    PlayerData* playerData = &gPlayerData;
    s32 newHP = playerData->curHP;

    if (amt > 0) {
        newHP -= amt;
    }
    if (amt < 0 || newHP < 1) {
        newHP = 1;
    }
    playerData->curHP = newHP;
}

s8 has_full_hp(void) {
    PlayerData* playerData = &gPlayerData;

    return playerData->curMaxHP == playerData->curHP;
}

s8 has_full_fp(void) {
    PlayerData* playerData = &gPlayerData;

    return playerData->curMaxFP == playerData->curFP;
}

s8 add_fortress_keys(s32 amt) {
    PlayerData* playerData = &gPlayerData;

    playerData->fortressKeyCount += amt;
    return playerData->fortressKeyCount;
}

s8 subtract_fortress_keys(s8 amt) {
    PlayerData* playerData = &gPlayerData;

    playerData->fortressKeyCount -= amt;
    if (playerData->fortressKeyCount < 0) {
        playerData->fortressKeyCount = 0;
    }

    return playerData->fortressKeyCount;
}

s8 get_fortress_key_count(void) {
    return gPlayerData.fortressKeyCount;
}
