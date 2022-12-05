#include "common.h"
#include "hud_element.h"

extern HudScript* TimesHudScript;
extern HudScript* SPIncrementHudScripts[];
extern HudScript* SPStarHudScripts[];
extern s32 D_800F7FE8;
extern s32 D_800F7FEC;
extern s32 D_800F7FF0;
extern s32 D_800F7FF4;
extern s32 D_800F7FF8;
extern s32 D_800F7FFC;
extern s32 D_800F8000[];

extern s16 D_8010CD10;
extern s16 D_8010CD12;

extern HudScript* DigitHudScripts[10];

extern HudScript HES_StatusHP;
extern HudScript HES_StatusHeart;
extern HudScript HES_StatusFP;
extern HudScript HES_StatusFlower;
extern HudScript HES_Item_CoinSparkleRandom;
extern HudScript HES_StatusStarPoint;
extern HudScript HES_StatusStar1;
extern HudScript HES_StatusTimes;
extern HudScript HES_StatusSPShine;
extern HudScript HES_StatusSPEmptyIncrement;
extern HudScript HES_StatusStarEmpty;

extern HudScript SlashHudScript;

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
    playerData->starBeamLevel = 0;
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

    playerData->actionCommandAttempts = 0;
    playerData->actionCommandSuccesses = 0;
    playerData->hitsTaken = 0;
    playerData->hitsBlocked = 0;
    playerData->playerFirstStrikes = 0;
    playerData->enemyFirstStrikes = 0;
    playerData->powerBounces = 0;
    playerData->battlesCount = 0;
    playerData->battlesWon = 0;
    playerData->unk_2A6 = 0;
    playerData->battlesFled = 0;
    playerData->trainingsDone = 0;
    playerData->walkingStepsTaken = 0;
    playerData->runningStepsTaken = 0;
    playerData->idleFrameCounter = 0;
    playerData->totalCoinsEarned = 0;
    playerData->frameCounter = 0;
    playerData->quizzesAnswered = 0;
    playerData->quizzesCorrect = 0;

    for (i = 0; i < ARRAY_COUNT(playerData->partnerUnlockedTime); i++) {
        playerData->partnerUnlockedTime[i] = 0;
        playerData->partnerUsedTime[i] = 0;
    }

    playerData->droTreeHintTime = 0;
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
    ItemData* item = &gItemTable[itemID];
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
    ItemData* item = &gItemTable[itemID];
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

    playerData->curMaxHP = playerData->hardMaxHP + (is_ability_active(ABILITY_HP_PLUS) * 5);
    if (playerData->curMaxHP > 75) {
        playerData->curMaxHP = 75;
    }
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }

    playerData->curMaxFP = playerData->hardMaxFP + (is_ability_active(ABILITY_FP_PLUS) * 5);
    if (playerData->curMaxFP > 75) {
        playerData->curMaxFP = 75;
    }
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
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
    uiStatus->ignoreChanges = FALSE;
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
    uiStatus->unk_57 = 0;
    uiStatus->unk_58 = 0;
    uiStatus->unk_59 = 0;
    uiStatus->spBarsToBlink = 0;
    uiStatus->unk_6C[0] = 0;
    uiStatus->unk_6C[1] = 0;
    uiStatus->iconIndex12 = -1;

    close_status_menu();

    iconIndex = hud_element_create(&HES_StatusHP);
    uiStatus->hpIconIndices[0] = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusHeart);
    uiStatus->hpIconIndices[1] = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusFP);
    uiStatus->fpIconIndices[0] = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusFlower);
    uiStatus->fpIconIndices[1] = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusCoin);
    uiStatus->coinIconIndex = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_Item_CoinSparkleRandom);
    uiStatus->coinSparkleIconIndex = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusStarPoint);
    uiStatus->starpointsIconIndex = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusSPShine);
    uiStatus->starpointsShineIconIndex = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    newVar = hud_element_create(&HES_StatusTimes);
    iconIndex = newVar;
    uiStatus->iconIndex8 = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusTimes);
    uiStatus->iconIndex9 = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusTimes);
    uiStatus->iconIndexA = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusTimes);
    uiStatus->iconIndexB = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusStar1);
    uiStatus->starIconIndex = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAGS_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAGS_FILTER_TEX);

    func_800F0D5C();
}

void status_menu_draw_number(s32 iconID, s32 x, s32 y, s32 value, s32 numDigits) {
    s8 digits[4];
    s32 i;
    s32 x2, y2;
    s32 keepDrawing;
    s32 digit;

    hud_element_set_script(iconID, TimesHudScript);
    x2 = x + 8;
    y2 = y + 8;
    hud_element_set_render_pos(iconID, x2, y2 - 1);
    hud_element_clear_flags(iconID, HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_draw_next(iconID);

    // Write each digit of the input number into the digits array
    for (i = 0; i < numDigits; i++) {
        digit = value % 10;
        digits[(numDigits - i) - 1] = digit;
        value /= 10;
    }

    x2 += 13;
    keepDrawing = FALSE;

    for (i = 0; i < numDigits; i++, x2 += 8) {
        digit = digits[i];

        // Once we have encountered our first non-zero digit, we need to keep drawing the remaining digits
        if (digit != 0 || keepDrawing || (i == numDigits - 1)) {
            keepDrawing = TRUE;
            hud_element_set_script(iconID, DigitHudScripts[digit]);
            hud_element_set_render_pos(iconID, x2, y2);
            hud_element_clear_flags(iconID, HUD_ELEMENT_FLAGS_DISABLED);
            hud_element_draw_next(iconID);
        }
    }
}

// close but some ordering / reg issues
#ifdef NON_MATCHING
void status_menu_draw_stat(s32 id, s32 x, s32 y, s32 arg3, s32 arg4) {
    s8 digits[4];
    s32 sp18;
    s32 sp1C;
    s32 cond;
    s32 digit;
    s32 numDigits;
    s32 localX;
    s32 localY;
    s32 i;

    numDigits = 2;

    sp18 = x + 8;
    sp1C = y + 8;
    i = 0;
    hud_element_set_script(id, SlashHudScript);
    hud_element_set_render_pos(id, x + 22, y + 9);
    hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_draw_next(id);


    for (; i < numDigits; i++) {
        s32 num = arg3 % 10;

        digits[numDigits - i - 1] = num;
        arg3 /= 10;
    }

    localX = sp18;
    localY = sp1C;
    cond = FALSE;
    for (i = 0; i < numDigits; i++) {
        digit = digits[i];
        if (digit != 0 || cond || i == numDigits - 1) {
            cond = TRUE;
            hud_element_set_script(id, DigitHudScripts[digit]);
            hud_element_set_render_pos(id, localX + (i * 8), localY);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
            hud_element_draw_next(id);
        }
    }

    for (i = 0; i < numDigits; i++) {
        digits[numDigits - i - 1] = arg4 % 10;
        arg4 /= 10;
    }

    localX = sp18 + 26;
    localY = sp1C;
    cond = FALSE;
    for (i = 0; i < numDigits; i++) {
        digit = digits[i];
        if (digit != 0 || cond || i == numDigits - 1) {
            cond = TRUE;
            hud_element_set_script(id, DigitHudScripts[digit]);
            hud_element_set_render_pos(id, localX + (i * 8), localY);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
            hud_element_draw_next(id);
        }
    }
}
#else
INCLUDE_ASM(s32, "80850_len_3060", status_menu_draw_stat);
#endif

void update_status_menu(void);
INCLUDE_ASM(s32, "80850_len_3060", update_status_menu);

void coin_counter_draw_content(UNK_TYPE arg0, s32 posX, s32 posY) {
    UiStatus* uiStatus = &gUIStatus;
    s32 iconIndex;

    if ((gPlayerData.coins != uiStatus->displayCoins) && ((gGameStatusPtr->frameCounter % 3) == 0)) {
        sfx_play_sound(SOUND_211);
    }

    iconIndex = uiStatus->iconIndex10;
    hud_element_set_render_pos(iconIndex, posX + 27, posY + 11);
    hud_element_draw_clipped(iconIndex);

    iconIndex = uiStatus->iconIndex11;
    hud_element_set_render_pos(iconIndex, posX + 15, posY + 11);
    hud_element_draw_clipped(iconIndex);

    draw_number(uiStatus->displayCoins, posX + 58, posY + 4, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, 255, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
}

void update_coin_counter(void) {
    UiStatus* uiStatus = &gUIStatus;
    PlayerData* playerData = &gPlayerData;

    do {} while (0); // Needed to match

    if (uiStatus->unk_6C[1] != 0) {
        uiStatus->unk_6C[1] -= 1;
        if (((uiStatus->unk_6C[1] << 24) == 0) && (uiStatus->iconIndex12 >= 0)) {
            hud_element_free(uiStatus->iconIndex12);
            hud_element_free(uiStatus->iconIndex13);
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
                set_window_update(WINDOW_ID_20, (s32)basic_hidden_window_update);
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
        set_window_update(WINDOW_ID_20, WINDOW_UPDATE_HIDE);
        if (uiStatus->iconIndex12 > -1) {
            hud_element_free(uiStatus->iconIndex10);
            hud_element_free(uiStatus->iconIndex11);
            uiStatus->iconIndex12 = -1;
        }
        uiStatus->unk_6C[0] = 0;
        uiStatus->unk_6C[1] = 0;
        D_8010CD10 = 0;
        D_8010CD12 = 0;
    }

    if (uiStatus->unk_6C[0] == 0) {
        set_window_properties(WINDOW_ID_20, 32, 164, 64, 20, 0x15, coin_counter_draw_content, 0, -1);
        set_window_update(WINDOW_ID_20, (s32)basic_window_update);
        index = hud_element_create(&HES_MenuTimes);
        uiStatus->iconIndex10 = index;
        hud_element_set_flags(index, HUD_ELEMENT_FLAGS_80);
        hud_element_set_tint(index, 255, 255, 255);
        index = hud_element_create(&HES_StatusCoin);
        uiStatus->iconIndex11 = index;
        hud_element_set_flags(index, HUD_ELEMENT_FLAGS_80);
        hud_element_set_tint(index, 255, 255, 255);
        uiStatus->unk_6C[0] = 0;

        if (uiStatus->unk_6C[2] < 0) {
            uiStatus->unk_6C[2] = uiStatus->ignoreChanges;
        }

        uiStatus->ignoreChanges = TRUE;
        D_8010CD10 = 1;
    }
}

void hide_coin_counter(void) {
    UiStatus* uiStatus = &gUIStatus;

    if ((D_8010CD10 != 0) && (uiStatus->unk_6C[0] == 0)) {
        uiStatus->unk_6C[0] = 60;
    }
}

void hide_coin_counter_immediately(void) {
    UiStatus* uiStatus = &gUIStatus;

    if ((D_8010CD10 != 0) && (uiStatus->unk_6C[0] == 0)) {
        uiStatus->unk_6C[0] = 1;
    }
}

ApiStatus ShowCoinCounter(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(script, *script->ptrReadPos)) {
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
    uiStatus->ignoreChanges = FALSE;
    uiStatus->showTimer = 0;
    uiStatus->hidden = 1;
    uiStatus->unk_3B[0] = 0;
    uiStatus->unk_3B[1] = 0;
}

void func_800E9810(void) {
    UiStatus* uiStatus = &gUIStatus;

    uiStatus->showTimer = 210;
    uiStatus->drawPosY = 0;
    uiStatus->ignoreChanges = FALSE;
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

void status_menu_ignore_changes(void) {
    gUIStatus.ignoreChanges = TRUE;
}

void func_800E98A8(void) {
    UiStatus* uiStatus = &gUIStatus;

    uiStatus->ignoreChanges = TRUE;
    uiStatus->drawPosY = 18;
}

void status_menu_respond_to_changes(void) {
    gUIStatus.ignoreChanges = FALSE;
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
    uiStatus->ignoreChanges = FALSE;
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
        copy_world_hud_element_ref_to_battle(uiStatus->hpIconIndices[i], uiStatus->hpIconIndices[i]);
    }

    for (i = 0; i < 2; i++) {
        copy_world_hud_element_ref_to_battle(uiStatus->fpIconIndices[i], uiStatus->fpIconIndices[i]);
    }

    copy_world_hud_element_ref_to_battle(uiStatus->coinIconIndex, uiStatus->coinIconIndex);
    copy_world_hud_element_ref_to_battle(uiStatus->coinSparkleIconIndex, uiStatus->coinSparkleIconIndex);
    copy_world_hud_element_ref_to_battle(uiStatus->starpointsIconIndex, uiStatus->starpointsIconIndex);
    copy_world_hud_element_ref_to_battle(uiStatus->starpointsShineIconIndex, uiStatus->starpointsShineIconIndex);
    copy_world_hud_element_ref_to_battle(uiStatus->iconIndex8, uiStatus->iconIndex8);
    copy_world_hud_element_ref_to_battle(uiStatus->iconIndex9, uiStatus->iconIndex9);
    copy_world_hud_element_ref_to_battle(uiStatus->iconIndexA, uiStatus->iconIndexA);
    copy_world_hud_element_ref_to_battle(uiStatus->iconIndexB, uiStatus->iconIndexB);
    copy_world_hud_element_ref_to_battle(uiStatus->starIconIndex, uiStatus->starIconIndex);
}

// Weird order of loading stuff
#ifdef NON_EQUIVALENT
s32 is_ability_active(s32 ability) {
    PlayerData* playerData = &gPlayerData;
    s32 attackFXArray[6];
    s32 abilityMoveID;
    s32 ret;
    s32 attackFXIndex;
    s32 i;
    s32 badgeMoveID;
    u8* moveID;

    ret = 0;
    attackFXIndex = 0;

    for (i = 0; i < ARRAY_COUNT(attackFXArray); i++) {
        attackFXArray[i] = 0;
    }

    if (gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_IS_PEACH) {
        return 0;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
        badgeMoveID = playerData->equippedBadges[i];

        if (badgeMoveID != 0) {
            moveID = &gItemTable[badgeMoveID].moveID;
            badgeMoveID = *moveID;
        }

        switch (ability) {
            case ABILITY_DODGE_MASTER:
                abilityMoveID = 0x4c;
                break;
            case ABILITY_SPIKE_SHIELD:
                abilityMoveID = 0x40;
                break;
            case ABILITY_FIRST_ATTACK:
                abilityMoveID = 0x4d;
                break;
            case ABILITY_HP_PLUS:
                abilityMoveID = 0x52;
                break;
            case ABILITY_DOUBLE_DIP:
                abilityMoveID = 0x35;
                break;
            case ABILITY_MYSTERY_SCROLL:
                if (badgeMoveID == 0x53) {
                    ret++;
                }
                if (playerData->hasActionCommands) {
                    ret++;
                }
                continue;
            case ABILITY_FIRE_SHIELD:
                abilityMoveID = 0x41;
                break;
            case ABILITY_PRETTY_LUCKY:
                abilityMoveID = 0x42;
                break;
            case ABILITY_HP_DRAIN:
                abilityMoveID = 0x5a;
                break;
            case ABILITY_ALL_OR_NOTHING:
                abilityMoveID = 0x3c;
                break;
            case ABILITY_SLOW_GO:
                abilityMoveID = 0x4e;
                break;
            case ABILITY_FP_PLUS:
                abilityMoveID = 0x5b;
                break;
            case ABILITY_ICE_POWER:
                abilityMoveID = 0x3d;
                break;
            case ABILITY_FEELING_FINE:
                abilityMoveID = 0x43;
                break;
            case ABILITY_ATTACK_FX:
                if (badgeMoveID == 0x54) {
                    attackFXArray[attackFXIndex++] = 1;
                    ret = -1;
                }
                if (badgeMoveID == 0x55) {
                    attackFXArray[attackFXIndex++] = 2;
                    ret = -1;
                }
                if (badgeMoveID == 0x56) {
                    attackFXArray[attackFXIndex++] = 3;
                    ret = -1;
                }
                if (badgeMoveID == 0x57) {
                    attackFXArray[attackFXIndex++] = 4;
                    ret = -1;
                }
                if (badgeMoveID == 0x58) {
                    attackFXArray[attackFXIndex++] = 5;
                    ret = -1;
                }
                if (badgeMoveID == 0x59) {
                    attackFXArray[attackFXIndex++] = 6;
                    ret = -1;
                }
                continue;
            case ABILITY_MONEY_MONEY:
                abilityMoveID = 0x5c;
                break;
            case ABILITY_CHILL_OUT:
                abilityMoveID = 0x5d;
                break;
            case ABILITY_HAPPY_HEART:
                abilityMoveID = 0x5e;
                break;
            case ABILITY_ZAP_TAP:
                abilityMoveID = 0x44;
                break;
            case ABILITY_MEGA_RUSH:
                abilityMoveID = 0x5f;
                break;
            case ABILITY_BERSERKER:
                abilityMoveID = 0x60;
                break;
            case ABILITY_RIGHT_ON:
                abilityMoveID = 0x4f;
                break;
            case ABILITY_RUNAWAY_PAY:
                abilityMoveID = 0x61;
                break;
            case ABILITY_FLOWER_SAVER:
                abilityMoveID = 0x62;
                break;
            case ABILITY_PAY_OFF:
                abilityMoveID = 99;
                break;
            case ABILITY_DEFEND_PLUS:
                abilityMoveID = 0x45;
                break;
            case ABILITY_POWER_PLUS:
                abilityMoveID = 0x3b;
                break;
            case ABILITY_REFUND:
                abilityMoveID = 0x6e;
                break;
            case ABILITY_POWER_RUSH:
                abilityMoveID = 100;
                break;
            case ABILITY_CRAZY_HEART:
                abilityMoveID = 0x65;
                break;
            case ABILITY_LAST_STAND:
                abilityMoveID = 0x46;
                break;
            case ABILITY_CLOSE_CALL:
                abilityMoveID = 0x47;
                break;
            case ABILITY_P_UP_D_DOWN:
                abilityMoveID = 0x3e;
                break;
            case ABILITY_LUCKY_DAY:
                abilityMoveID = 0x48;
                break;
            case ABILITY_MEGA_HP_DRAIN:
                abilityMoveID = 0x66;
                break;
            case ABILITY_P_DOWN_D_UP:
                abilityMoveID = 0x49;
                break;
            case ABILITY_FLOWER_FANATIC:
                abilityMoveID = 0x67;
                break;
            case ABILITY_SPEEDY_SPIN:
                abilityMoveID = 0x6d;
                break;
            case ABILITY_SPIN_ATTACK:
                abilityMoveID = 0x6a;
                break;
            case ABILITY_I_SPY:
                abilityMoveID = 0x6c;
                break;
            case ABILITY_BUMP_ATTACK:
                abilityMoveID = 0x50;
                break;
            case ABILITY_QUICK_CHANGE:
                abilityMoveID = 0x38;
                break;
            case ABILITY_HEART_FINDER:
                abilityMoveID = 0x68;
                break;
            case ABILITY_FLOWER_FINDER:
                abilityMoveID = 0x69;
                break;
            case ABILITY_DIZZY_ATTACK:
                abilityMoveID = 0x6b;
                break;
            case ABILITY_FINAL_GOOMPA:
                abilityMoveID = 0x6f;
                break;
            case ABILITY_FINAL_BOMBOMB:
                abilityMoveID = 0x70;
                break;
            case ABILITY_DEEP_FOCUS:
                abilityMoveID = 0x71;
                break;
            case ABILITY_SUPER_FOCUS:
                abilityMoveID = 0x72;
                break;
            case ABILITY_KAIDEN:
                abilityMoveID = 0x73;
                break;
            case ABILITY_DAMAGE_DODGE:
                abilityMoveID = 0x33;
                break;
            case ABILITY_HAPPY_FLOWER:
                abilityMoveID = 0x74;
                break;
            case ABILITY_GROUP_FOCUS:
                abilityMoveID = 0x75;
                break;
            case ABILITY_PEEKABOO:
                abilityMoveID = 0x76;
                break;
            case ABILITY_HEALTHY_HEALTHY:
                abilityMoveID = 0x4a;
                break;
            default:
                do { } while (0);
                continue;
        }
        if (badgeMoveID == abilityMoveID) {
            ret++;
        }
    }

    if (ret < 0) {
        ret = attackFXArray[rand_int(attackFXIndex - 1)];
    }
    return ret;
}
#else
INCLUDE_ASM(s32, "80850_len_3060", is_ability_active);
#endif

s32 is_partner_ability_active(s32 ability) {
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

s32 add_star_points(s32 amt) {
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

s32 add_star_pieces(s32 amt) {
    PlayerData* playerData = &gPlayerData;
    s32 newSP = playerData->starPieces;

    newSP += amt;
    if (newSP > MAX_STAR_PIECES) {
        newSP = MAX_STAR_PIECES;
    }
    if (newSP < 0) {
        newSP = 0;
    }
    playerData->starPieces = newSP;

    if (amt > 0) {
        playerData->starPiecesCollected += amt;
    }

    return playerData->starPieces;
}

void increment_max_SP(void) {
    gPlayerData.maxStarPower++;
    gPlayerData.specialBarsFilled = gPlayerData.maxStarPower * 256;
}

void set_max_SP(s8 newMaxSP) {
    gPlayerData.maxStarPower = newMaxSP;
    gPlayerData.specialBarsFilled = newMaxSP * 256;
}

void add_SP(s32 amt) {
    // TODO cleanup
    PlayerData* playerData = &gPlayerData;
    UiStatus* uiStatus = &gUIStatus;
    s32 phi_v1;
    s32 maxPower;

    uiStatus->unk_57 = 1;
    uiStatus->unk_58 = 60;

    phi_v1 = playerData->specialBarsFilled;
    if (playerData->specialBarsFilled < 0) {
        phi_v1 = playerData->specialBarsFilled + 31;
    }
    uiStatus->unk_59 = phi_v1 >> 5;

    playerData->specialBarsFilled += amt;

    maxPower = playerData->maxStarPower << 8;
    if (playerData->specialBarsFilled > maxPower) {
        playerData->specialBarsFilled = maxPower;
    }

    gUIStatus.displaySP = gPlayerData.specialBarsFilled;
}

s32 recover_fp(s32 amt) {
    PlayerData* playerData = &gPlayerData;
    s32 newFP = playerData->curFP;
    s32 ret;

    if (amt == -2) {
        playerData->curMaxFP++;
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
        playerData->curMaxHP++;
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
    return gPlayerData.curMaxHP == gPlayerData.curHP;
}

s8 has_full_fp(void) {
    return gPlayerData.curMaxFP == gPlayerData.curFP;
}

s8 add_fortress_keys(s32 amt) {
    gPlayerData.fortressKeyCount += amt;
    return gPlayerData.fortressKeyCount;
}

s32 subtract_fortress_keys(s32 amt) {
    PlayerData* playerData = &gPlayerData;

    playerData->fortressKeyCount -= amt;
    if (playerData->fortressKeyCount < 0) {
        playerData->fortressKeyCount = 0;
    }

    return playerData->fortressKeyCount;
}

s32 get_fortress_key_count(void) {
    return gPlayerData.fortressKeyCount;
}
