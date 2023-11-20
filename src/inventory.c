#include "common.h"
#include "hud_element.h"

#define FULLY_EXTENDED_Y  18
#define FULLY_RETRACTED_Y -100

enum BlinkModes {
    BLINK_OFF   = 0,
    BLINK_ON    = 1,
};

BSS b16 D_8010CD10;
BSS b16 D_8010CD12;
BSS char D_8010CD14[0xA];
BSS s32 D_8010CD20;
BSS char D_8010CD24[0xC];

SHIFT_BSS StatusBar gStatusBar;

extern HudScript* TimesHudScript;
extern HudScript* SPIncrementHudScripts[];
extern HudScript* SPStarHudScripts[];
extern s32 StatusBarSPIncrementOffsets[];

extern HudScript* DigitHudScripts[10];

extern HudScript HES_StatusHP;
extern HudScript HES_StatusHP_de;
extern HudScript HES_StatusHP_fr;
extern HudScript HES_StatusHP_es;
extern HudScript HES_StatusHeart;
extern HudScript HES_StatusFP;
extern HudScript HES_StatusFP_de;
extern HudScript HES_StatusFP_fr;
extern HudScript HES_StatusFP_es;
extern HudScript HES_StatusFlower;
extern HudScript HES_Item_CoinSparkleRandom;
extern HudScript HES_StatusStarPoint;
extern HudScript HES_StatusStar1;
extern HudScript HES_StatusTimes;
extern HudScript HES_StatusSPShine;
extern HudScript HES_StatusSPEmptyIncrement;
extern HudScript HES_StatusStarEmpty;

extern HudScript* SlashHudScript;

void status_bar_start_blinking_coins(void);
void status_bar_stop_blinking_coins(void);

void clear_player_data(void) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    D_8010CD10 = FALSE;
    D_8010CD12 = FALSE;

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
    playerData->hasActionCommands = FALSE;
    playerData->coins = 0;
    playerData->fortressKeyCount = 0;
    playerData->starPieces = 0;
    playerData->starPoints = 0;
    playerData->unused_011 = 0;
    playerData->unused_288 = 0;
    playerData->merleeSpellType = MERLEE_SPELL_NONE;
    playerData->merleeCastsLeft = 0;
    playerData->merleeTurnCount = -1;
    playerData->maxStarPower = 0;
    playerData->starPower = 0;
    playerData->starBeamLevel = 0;
    playerData->curPartner = 0;

    for (i = 0; i < ARRAY_COUNT(playerData->partners); i++) {
        playerData->partners[i].enabled = FALSE;
        playerData->partners[i].level = PARTNER_RANK_NORMAL;
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
    playerData->fleeAttempts = 0;
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

    if (item->typeFlags & ITEM_TYPE_FLAG_KEY) {
        // check key items
        for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
            if (playerData->keyItems[i] == itemID) {
                break;
            }
        }

        if (i >= ARRAY_COUNT(playerData->keyItems)) {
            return -1;
        }

        return i;
    } else {
        // check consumable items
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
}

/// Bubbles up player inventory items such that all ITEM_NONE values are at the bottom.
void sort_items(void) {
    PlayerData* playerData = &gPlayerData;
    s32 j;
    s32 i;

    for (i = ARRAY_COUNT(playerData->invItems) - 2; i >= 0; i--) {
        // leave ITEM_NONE at the end of the list alone
        if (playerData->invItems[i] == ITEM_NONE) {
            continue;
        }
        // swap any other ITEM_NONE to the end of the list
        for (j = ARRAY_COUNT(playerData->invItems) - 1; i < j; j--) {
            if (playerData->invItems[j] == ITEM_NONE) {
                playerData->invItems[j] = playerData->invItems[i];
                playerData->invItems[i] = ITEM_NONE;
                break;
            }
        }
    }
}

s32 add_badge(s32 itemID) {
    PlayerData* playerData = &gPlayerData;
    ItemData* item = &gItemTable[itemID];
    s32 i;

    if ((item->typeFlags & ITEM_TYPE_FLAG_BADGE) == 0) {
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

    for (; i < ARRAY_COUNT(gPlayerData.storedItems); i++) {
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

void initialize_status_bar(void) {
    StatusBar* statusBar = &gStatusBar;
    PlayerData* playerData = &gPlayerData;
    s32 iconIndex;

    statusBar->drawPosX = 12;
    D_8010CD10 = FALSE;
    D_8010CD12 = FALSE;
    statusBar->drawPosY = FULLY_RETRACTED_Y;
    statusBar->hidden = FALSE;
    statusBar->showTimer = 210;
    statusBar->unk_3B = FALSE;
    statusBar->ignoreChanges = FALSE;
    statusBar->openInputDisabled = FALSE;
    statusBar->alwaysShown = FALSE;
    statusBar->hpBlinking = BLINK_OFF;
    statusBar->hpBlinkCounter = 0;
    statusBar->hpBlinkTimer = 0;
    statusBar->fpBlinking = BLINK_OFF;
    statusBar->fpBlinkCounter = 0;
    statusBar->fpBlinkTimer = 0;
    statusBar->spBlinking = BLINK_OFF;
    statusBar->spBlinkCounter = 0;
    statusBar->coinsBlinking = BLINK_OFF;
    statusBar->coinsBlinkCounter = 0;
    statusBar->coinsBlinkTimer = 0;
    statusBar->disabled = 0;
    statusBar->starpointsBlinking = BLINK_OFF;
    statusBar->displayHP = playerData->curHP;
    statusBar->displayFP = playerData->curFP;
    statusBar->displayCoins = playerData->coins;
    statusBar->displayStarpoints = playerData->starPoints;
    statusBar->displayStarPower = playerData->starPower;
    statusBar->starpointsBlinkCounter = 0;
    statusBar->unk_6E = -1;
    statusBar->unk_3C = FALSE;
    statusBar->unk_57 = 0;
    statusBar->unk_58 = 0;
    statusBar->unk_59 = 0;
    statusBar->spBarsToBlink = 0;
    statusBar->coinCounterHideTime = 0;
    statusBar->unk_6D = 0;
    statusBar->iconIndex12 = -1;

    close_status_bar();

#if VERSION_PAL
    switch (gCurrentLanguage) {
        case LANGUAGE_EN:
            iconIndex = statusBar->hpIconHIDs[0] = hud_element_create(&HES_StatusHP);
            break;
        case LANGUAGE_DE:
            iconIndex = statusBar->hpIconHIDs[0] = hud_element_create(&HES_StatusHP_de);
            break;
        case LANGUAGE_FR:
            iconIndex = statusBar->hpIconHIDs[0] = hud_element_create(&HES_StatusHP_fr);
            break;
        case LANGUAGE_ES:
            iconIndex = statusBar->hpIconHIDs[0] = hud_element_create(&HES_StatusHP_es);
            break;
    }

    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);
#else
    statusBar->hpIconHIDs[0] = iconIndex = hud_element_create(&HES_StatusHP);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);
#endif

    statusBar->hpIconHIDs[1] = iconIndex = hud_element_create(&HES_StatusHeart);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

#if VERSION_PAL
    switch (gCurrentLanguage) {
        case LANGUAGE_EN:
            iconIndex = statusBar->fpIconHIDs[0] = hud_element_create(&HES_StatusFP);
            break;
        case LANGUAGE_DE:
            iconIndex = statusBar->fpIconHIDs[0] = hud_element_create(&HES_StatusFP_de);
            break;
        case LANGUAGE_FR:
            iconIndex = statusBar->fpIconHIDs[0] = hud_element_create(&HES_StatusFP_fr);
            break;
        case LANGUAGE_ES:
            iconIndex = statusBar->fpIconHIDs[0] = hud_element_create(&HES_StatusFP_es);
            break;
    }

    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);
#else
    statusBar->fpIconHIDs[0] = iconIndex = hud_element_create(&HES_StatusFP);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);
#endif

    statusBar->fpIconHIDs[1] = iconIndex = hud_element_create(&HES_StatusFlower);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    statusBar->coinIconHID = iconIndex = hud_element_create(&HES_StatusCoin);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    statusBar->coinSparkleHID = iconIndex = hud_element_create(&HES_Item_CoinSparkleRandom);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    statusBar->spIconHID = iconIndex = hud_element_create(&HES_StatusStarPoint);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    statusBar->spShineHID = iconIndex = hud_element_create(&HES_StatusSPShine);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    statusBar->hpTimesHID = iconIndex = hud_element_create(&HES_StatusTimes);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    statusBar->fpTimesHID = iconIndex = hud_element_create(&HES_StatusTimes);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    statusBar->spTimesHID = iconIndex = hud_element_create(&HES_StatusTimes);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    statusBar->coinTimesHID = iconIndex = hud_element_create(&HES_StatusTimes);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    statusBar->starIconHID = iconIndex = hud_element_create(&HES_StatusStar1);
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    func_800F0D5C();
}

void status_bar_draw_number(s32 iconID, s32 startX, s32 startY, s32 value, s32 numDigits) {
    s8 digits[4];
    s32 drawX, drawY;
    b32 keepDrawing;
    s32 digit;
    s32 i;
    
    hud_element_set_script(iconID, TimesHudScript);
    drawX = startX + 8;
    drawY = startY + 8;
    hud_element_set_render_pos(iconID, drawX, drawY - 1);
    hud_element_clear_flags(iconID, HUD_ELEMENT_FLAG_DISABLED);
    hud_element_draw_next(iconID);

    // Write each digit of the input number into the digits array
    for (i = 0; i < numDigits; i++) {
        digit = value % 10;
        digits[(numDigits - i) - 1] = digit;
        value /= 10;
    }

    drawX += 13;
    keepDrawing = FALSE;

    for (i = 0; i < numDigits; i++, drawX += 8) {
        digit = digits[i];

        // Once we have encountered our first non-zero digit, we need to keep drawing the remaining digits
        if (digit != 0 || keepDrawing || (i == numDigits - 1)) {
            keepDrawing = TRUE;
            hud_element_set_script(iconID, DigitHudScripts[digit]);
            hud_element_set_render_pos(iconID, drawX, drawY);
            hud_element_clear_flags(iconID, HUD_ELEMENT_FLAG_DISABLED);
            hud_element_draw_next(iconID);
        }
    }
}

void status_bar_draw_stat(s32 id, s32 startX, s32 startY, s32 currentValue, s32 maxValue) {
    s8 digits[4];
    b32 keepDrawing;
    s32 digit;
    s32 numDigits = 2;
    s32 drawX;
    s32 drawY;
    s32 i = 0;
    s32 baseX = startX + 8;
    s32 baseY = startY + 8;

    hud_element_set_script(id, SlashHudScript);
    hud_element_set_render_pos(id, baseX + 14, baseY + 1);
    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
    hud_element_draw_next(id);

    for (i = 0; i < numDigits; i++) {
        s32 num = currentValue % 10;
        digits[numDigits - i - 1] = num;
        currentValue /= 10;
    }

    drawX = baseX;
    drawY = baseY;
    keepDrawing = FALSE;
    for (i = 0; i < numDigits; i++, drawX += 8) {
        digit = digits[i];
        if (digit != 0 || keepDrawing || i == numDigits - 1) {
            keepDrawing = TRUE;
            hud_element_set_script(id, DigitHudScripts[digit]);
            hud_element_set_render_pos(id, drawX, drawY);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            hud_element_draw_next(id);
        }
    }

    for (i = 0; i < numDigits; i++) {
        digits[numDigits - i - 1] = maxValue % 10;
        maxValue /= 10;
    }

    drawX = baseX + 26;
    drawY = baseY;
    keepDrawing = FALSE;
    for (i = 0; i < numDigits; i++, drawX += 8) {
        digit = digits[i];
        if (digit != 0 || keepDrawing || i == numDigits - 1) {
            keepDrawing = TRUE;
            hud_element_set_script(id, DigitHudScripts[digit]);
            hud_element_set_render_pos(id, drawX, drawY);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            hud_element_draw_next(id);
        }
    }
}

void update_status_bar(void) {
    StatusBar* statusBar = &gStatusBar;
    PlayerData* playerData = &gPlayerData;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 sp50;
    s32 sp54;
    s32 i;
    s32 x;
    s32 y;
    s32 showStat;
    s32 id;
    s32 limit;
    s32 s7;
    s32 s1;
    s32 spBars;
    s32 maxStarPower;

    if (gGameStatusPtr->introPart >= INTRO_PART_0
        || gGameStatusPtr->demoState != DEMO_STATE_NONE
        || (gGameStatusPtr->peachFlags & PEACH_FLAG_IS_PEACH)
        || evt_get_variable(NULL, GB_StoryProgress) >= STORY_EPILOGUE
    ) {
        return;
    }

    if (!gGameStatusPtr->isBattle && playerData->coins != statusBar->displayCoins) {
        status_bar_start_blinking_coins();
    }

    // update coin counter (+1 coin per frame for each 5-coin delta)
    i = playerData->coins - statusBar->displayCoins;
    if (i < 0) {
        i = (i - 4) / 5;
    } else {
        i = (i + 4) / 5;
    }
    statusBar->displayCoins += i;

    // show the status bar if HP has changed
    if (statusBar->displayHP != playerData->curHP && !statusBar->ignoreChanges) {
        if (statusBar->hidden) {
            statusBar->showTimer = 70;
            statusBar->hidden = FALSE;
            statusBar->unk_3B = FALSE;
        } else {
            statusBar->showTimer = 70;
        }
    }

    // show the status bar if FP has changed
    if (statusBar->displayFP != playerData->curFP && !statusBar->ignoreChanges) {
        if (statusBar->hidden) {
            statusBar->showTimer = 70;
            statusBar->hidden = FALSE;
            statusBar->unk_3B = FALSE;
        } else {
            statusBar->showTimer = 70;
        }
    }

    // show the status bar if star power has changed
    if (statusBar->displayStarPower != playerData->starPower && !statusBar->ignoreChanges) {
        if (statusBar->hidden) {
            statusBar->showTimer = 70;
            statusBar->hidden = FALSE;
            statusBar->unk_3B = FALSE;
        } else {
            statusBar->showTimer = 70;
        }
    }

    // sync displayed HP toward true HP
    if (statusBar->displayHP != playerData->curHP) {
        if (!gGameStatusPtr->isBattle && playerData->curHP < statusBar->displayHP) {
            status_bar_start_blinking_hp();
        }
        if (statusBar->displayHP < playerData->curHP) {
            if (statusBar->drawPosY >= FULLY_EXTENDED_Y) {
                if (gGameStatusPtr->frameCounter % 4 == 0) {
                    statusBar->displayHP++;
                    sfx_play_sound(SOUND_HEART_PICKUP);
                }
            } else if (gGameStatusPtr->frameCounter % 4 == 0) {
                statusBar->displayHP++;
            }
        } else if (gGameStatusPtr->frameCounter % 4 == 0) {
            statusBar->displayHP--;
        }
    }

    // sync displayed FP toward true FP
    if (statusBar->displayFP != playerData->curFP) {
        if (!gGameStatusPtr->isBattle && playerData->curFP < statusBar->displayFP) {
            status_bar_start_blinking_fp();
        }
        if (statusBar->displayFP < playerData->curFP) {
            if (statusBar->drawPosY >= FULLY_EXTENDED_Y) {
                if (gGameStatusPtr->frameCounter % 4 == 0) {
                    statusBar->displayFP++;
                    sfx_play_sound(SOUND_FLOWER_PICKUP);
                }
            } else if (gGameStatusPtr->frameCounter % 4 == 0) {
                statusBar->displayFP++;
            }
        } else if (gGameStatusPtr->frameCounter % 4 == 0) {
            statusBar->displayFP--;
        }
    }

    // sync displayed star power toward true star power
    if (statusBar->displayStarPower != playerData->starPower) {
        if (statusBar->displayStarPower < playerData->starPower) {
            statusBar->displayStarPower += 10;
            if (statusBar->displayStarPower > playerData->starPower) {
                statusBar->displayStarPower = playerData->starPower;
            }
        } else {
            statusBar->displayStarPower -= 10;
            if (statusBar->displayStarPower < playerData->starPower) {
                statusBar->displayStarPower = playerData->starPower;
            }
        }
    }

    if (statusBar->disabled) {
        return;
    }

    if (statusBar->alwaysShown && statusBar->hidden && playerStatus->inputDisabledCount == 0) {
        statusBar->showTimer = 42;
        statusBar->hidden = FALSE;
        statusBar->unk_3B = FALSE;
    }

    switch (statusBar->hidden) {
        case FALSE:
            statusBar->drawPosY += 10;
            if (statusBar->drawPosY >= FULLY_EXTENDED_Y) {
                statusBar->drawPosY = FULLY_EXTENDED_Y;
                if (statusBar->unk_3C && statusBar->unk_3B && playerStatus->actionState != ACTION_STATE_IDLE) {
                    statusBar->showTimer = 0;
                }
                if (statusBar->showTimer != 0) {
                    statusBar->showTimer--;
                } else {
                    if (!statusBar->ignoreChanges) {
                        if (!statusBar->unk_3B || playerStatus->actionState != ACTION_STATE_IDLE) {
                            if (!gGameStatusPtr->isBattle) {
                                statusBar->hidden = TRUE;
                                statusBar->showTimer = 0;
                                statusBar->unk_3C = FALSE;
                            }
                        }
                    }
                }
            }
            break;
        case TRUE:
            statusBar->drawPosY -= 5;
            if (statusBar->drawPosY < FULLY_RETRACTED_Y) {
                statusBar->drawPosY = FULLY_RETRACTED_Y;
                if (!statusBar->ignoreChanges) {
                    if (playerStatus->actionState != ACTION_STATE_IDLE) {
                        statusBar->showTimer = 0;
                    } else if (playerStatus->flags & (PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_INPUT_DISABLED)) {
                        statusBar->showTimer = 0;
                    } else {
                        statusBar->showTimer++;
                    }

                    if (statusBar->showTimer >= 240 && !gGameStatusPtr->isBattle) {
                        statusBar->showTimer = 210;
                        statusBar->hidden = FALSE;
                        statusBar->unk_3B = TRUE;
                        statusBar->unk_3C = TRUE;
                    }
                }
            }
            break;
    }

    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 12, 20, SCREEN_WIDTH - 12, SCREEN_HEIGHT - 20);
    x = statusBar->drawPosX;
    y = statusBar->drawPosY;
    draw_box(0, WINDOW_STYLE_5, x,       y, 0, 174, 35, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    draw_box(0, WINDOW_STYLE_6, x + 174, y, 0, 122, 25, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

    if (statusBar->hpBlinkTimer > 0) {
        statusBar->hpBlinkTimer--;
        if (statusBar->hpBlinkTimer == 0) {
            status_bar_stop_blinking_hp();
        }
    }

    showStat = TRUE;
    if (statusBar->hpBlinking != BLINK_OFF) {
        if (statusBar->hpBlinkCounter > 8) {
            showStat = FALSE;
            if (statusBar->hpBlinkCounter > 12) {
                statusBar->hpBlinkCounter = 0;
                showStat = TRUE;
            }
        }
        statusBar->hpBlinkCounter++;
    }

    if (showStat) {
        id = statusBar->hpIconHIDs[0];
        x = statusBar->drawPosX + 22;
        y = statusBar->drawPosY + 13;
        hud_element_set_render_pos(id, x, y);
        hud_element_draw_next(id);

        id = statusBar->hpIconHIDs[1];
        x = statusBar->drawPosX + 37;
        y = statusBar->drawPosY + 13;
        hud_element_set_render_pos(id, x, y);
        hud_element_draw_next(id);

        x = statusBar->drawPosX + 48;
        y = statusBar->drawPosY + 8;
        status_bar_draw_stat(statusBar->hpTimesHID, x, y, statusBar->displayHP, playerData->curMaxHP);
    }

    if (statusBar->fpBlinkTimer > 0) {
        statusBar->fpBlinkTimer--;
        if (statusBar->fpBlinkTimer == 0) {
            status_bar_stop_blinking_fp();
        }
    }

    showStat = TRUE;
    if (statusBar->fpBlinking != BLINK_OFF) {
        if (statusBar->fpBlinkCounter > 8) {
            showStat = FALSE;
            if (statusBar->fpBlinkCounter > 12) {
                statusBar->fpBlinkCounter = 0;
                showStat = TRUE;
            }
        }
        statusBar->fpBlinkCounter++;
    }

    if (showStat) {
        id = statusBar->fpIconHIDs[0];
        x = statusBar->drawPosX + 110;
        y = statusBar->drawPosY + 13;
        hud_element_set_render_pos(id, x, y);
        hud_element_draw_next(id);

        id = statusBar->fpIconHIDs[1];
        x = statusBar->drawPosX + 125;
        y = statusBar->drawPosY + 13;
        hud_element_set_render_pos(id, x, y);
        hud_element_draw_next(id);

        x = statusBar->drawPosX + 136;
        y = statusBar->drawPosY + 8;
        status_bar_draw_stat(statusBar->fpTimesHID, x, y, statusBar->displayFP, playerData->curMaxFP);
    }

    if (playerData->level >= 27) {
        playerData->starPoints = 0;
    }

    showStat = TRUE;
    if (statusBar->starpointsBlinking != BLINK_OFF) {
        if (statusBar->starpointsBlinkCounter > 8) {
            if (statusBar->starpointsBlinkCounter <= 12) {
                showStat = FALSE;
            } else {
                statusBar->starpointsBlinkCounter = 0;
            }
        }
        statusBar->starpointsBlinkCounter++;
    }

    if (showStat) {
        id = statusBar->spIconHID;
        x = statusBar->drawPosX + 195;
        y = statusBar->drawPosY + 14;
        hud_element_set_render_pos(id, x, y);
        hud_element_draw_next(id);

        id = statusBar->spShineHID;
        x = statusBar->drawPosX + 195;
        y = statusBar->drawPosY + 9;
        hud_element_set_render_pos(id, x, y);
        hud_element_draw_next(id);

        x = statusBar->drawPosX + 200;
        y = statusBar->drawPosY + 8;
        status_bar_draw_number(statusBar->spTimesHID, x, y, playerData->starPoints, 2);
    }

    if (statusBar->coinsBlinkTimer > 0) {
        statusBar->coinsBlinkTimer--;
        if (statusBar->coinsBlinkTimer == 0) {
            status_bar_stop_blinking_coins();
        }
    }

    showStat = TRUE;
    if (statusBar->coinsBlinking != BLINK_OFF) {
        if (statusBar->coinsBlinkCounter > 8) {
            showStat = FALSE;
            if (statusBar->coinsBlinkCounter > 12) {
                statusBar->coinsBlinkCounter = 0;
                showStat = TRUE;
            }
        }
        statusBar->coinsBlinkCounter++;
    }

    if (showStat) {
        id = statusBar->coinIconHID;
        x = statusBar->drawPosX + 244;
        y = statusBar->drawPosY + 14;
        hud_element_set_render_pos(id, x, y);
        hud_element_draw_next(id);

        id = statusBar->coinSparkleHID;
        x = statusBar->drawPosX + 244;
        y = statusBar->drawPosY + 14;
        hud_element_set_render_pos(id, x, y);
        hud_element_draw_next(id);

        x = statusBar->drawPosX + 247;
        y = statusBar->drawPosY + 8;
        status_bar_draw_number(statusBar->coinTimesHID, x, y, statusBar->displayCoins, 3);
    }

    id = statusBar->starIconHID;
    showStat = TRUE;
    if (statusBar->spBlinking != BLINK_OFF) {
        if (statusBar->spBlinkCounter > 5) {
            if (statusBar->spBlinkCounter <= 8) {
                showStat = FALSE;
            } else {
                statusBar->spBlinkCounter = 0;
                showStat = TRUE;
            }
        }
        statusBar->spBlinkCounter++;
    }

    x = statusBar->drawPosX + 20;
    y = statusBar->drawPosY + 28;

    spBars = statusBar->displayStarPower / SP_PER_BAR;
    limit = statusBar->displayStarPower % SP_PER_BAR;
    limit /= 32;
    limit += spBars * 8;
    if (statusBar->unk_57 == 1) {
        spBars = playerData->starPower / SP_PER_BAR;
        limit = playerData->starPower % SP_PER_BAR;
        limit = limit / 32;
        limit += spBars * 8;
        func_800F0CB0(0, x + limit * 25 / 10, y, 1.0f);
        statusBar->unk_57 = 2;
    }

    sp54 = FALSE;
    if (statusBar->unk_57 != 0) {
        if (statusBar->unk_58 != 0) {
            statusBar->unk_58--;
        } else {
            statusBar->unk_57 = 0;
        }
        if ((statusBar->unk_58 / 5) & 1) {
            sp54 = TRUE;
        }
        maxStarPower = statusBar->unk_59; // required to match
        s7 = statusBar->unk_59 % 8;
        s7 += statusBar->unk_59 / 8 * 8;
    } else {
        s7 = limit;
    }

    i = 0;
    sp50 = 0;
    s1 = 0;

    if (statusBar->spBlinking != BLINK_OFF) {
        if (!showStat) {
            s32 limit = statusBar->spBarsToBlink * 8;
            do {} while (0);
            if (sp50 < limit) {
                while (TRUE) {
                    i++; s1++; if (i >= limit) { break; }
                    i++; s1++; if (i >= limit) { break; }
                    i++; s1++; if (i >= limit) { break; }
                    i++; s1++; if (i >= limit) { break; }
                    i++; s1++; if (i >= limit) { break; }
                    i++; s1++; if (i >= limit) { break; }
                    i++; s1++; if (i >= limit) { break; }
                    i++;
                    s1 = 0;
                    sp50++;
                    if (i >= limit) {
                        break;
                    }
                }
            }
        }
    }

    while (TRUE) {
        if (i >= limit || i >= s7 && !sp54) {
            break;
        }
        i++;

        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[0], y - 2);
        hud_element_draw_next(id);

        s1++;
        if (i >= limit || i >= s7 && !sp54) {
            break;
        }
        i++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);

        hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[1], y - 2);
        hud_element_draw_next(id);
        s1++;
        if (i >= limit || i >= s7 && !sp54) {
            break;
        }
        i++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[2], y - 2);
        hud_element_draw_next(id);
        s1++;
        if (i >= limit || i >= s7 && !sp54) {
            break;
        }
        i++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[3], y - 2);
        hud_element_draw_next(id);
        s1++;
        if (i >= limit || i >= s7 && !sp54) {
            break;
        }
        i++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[4], y - 2);
        hud_element_draw_next(id);
        s1++;

        if (i >= limit || i >= s7 && !sp54) {
            break;
        }
        i++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[5], y - 2);
        hud_element_draw_next(id);
        s1++;

        if (i >= limit || i >= s7 && !sp54) {
            break;
        }
        i++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[6], y - 2);
        hud_element_draw_next(id);
        s1++;

        if (i >= limit || i >= s7 && !sp54) {
            break;
        }
        i++;
        hud_element_set_script(id, SPStarHudScripts[sp50]);
        hud_element_set_render_pos(id, x + 12 + sp50 * 20, y);
        hud_element_draw_next(id);

        s1 = 0;
        sp50++;
        if (i >= limit || i >= s7 && !sp54) {
            break;
        }
    }

    maxStarPower = playerData->maxStarPower;
    limit = maxStarPower * 8;
    while (TRUE) {
        if (i >= limit) {
            break;
        }
        if (s1 == 0) {
            i++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[s1], y - 2);
            hud_element_draw_next(id);
            if (i >= limit) {
                break;
            }
            s1 = 1;
        }
        if (s1 == 1) {
            i++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[s1], y - 2);
            hud_element_draw_next(id);
            if (i >= limit) {
                break;
            }
            s1 = 2;
        }
        if (s1 == 2) {
            i++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[s1], y - 2);
            hud_element_draw_next(id);
            if (i >= limit) {
                break;
            }
            s1 = 3;
        }
        if (s1 == 3) {
            i++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[s1], y - 2);
            hud_element_draw_next(id);
            if (i >= limit) {
                break;
            }
            s1 = 4;
        }
        if (s1 == 4) {
            i++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[s1], y - 2);
            hud_element_draw_next(id);
            if (i >= limit) {
                break;
            }
            s1 = 5;
        }
        if (s1 == 5) {
            i++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[s1], y - 2);
            hud_element_draw_next(id);
            if (i >= limit) {
                break;
            }
            s1 = 6;
        }
        if (s1 == 6) {
            i++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, x + sp50 * 20 + StatusBarSPIncrementOffsets[s1], y - 2);
            hud_element_draw_next(id);
            if (i >= limit) {
                break;
            }
            s1 = 7;
        }

        if (s1 == 7) {
            i++;
            hud_element_set_script(id, &HES_StatusStarEmpty);
            hud_element_set_render_pos(id, x + 12 + sp50 * 20, y);
            hud_element_draw_next(id);
            if (i >= limit) {
                break;
            }
        }
        s1 = 0;
        sp50++;
    }

    func_800F0D80();
    func_800F102C();
}

void coin_counter_draw_content(UNK_TYPE arg0, s32 posX, s32 posY) {
    StatusBar* statusBar = &gStatusBar;
    s32 iconIndex;

    if ((gPlayerData.coins != statusBar->displayCoins) && ((gGameStatusPtr->frameCounter % 3) == 0)) {
        sfx_play_sound(SOUND_COIN_PICKUP);
    }

    iconIndex = statusBar->coinCountTimesHID;
    hud_element_set_render_pos(iconIndex, posX + 27, posY + 11);
    hud_element_draw_clipped(iconIndex);

    iconIndex = statusBar->coinCountIconHID;
    hud_element_set_render_pos(iconIndex, posX + 15, posY + 11);
    hud_element_draw_clipped(iconIndex);

    draw_number(statusBar->displayCoins, posX + 58, posY + 4, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, 255, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
}

void update_coin_counter(void) {
    StatusBar* statusBar = &gStatusBar;
    PlayerData* playerData = &gPlayerData;

    do {} while (0); // Needed to match

    if (statusBar->unk_6D != 0) {
        statusBar->unk_6D--;
        if ((statusBar->unk_6D == 0) && (statusBar->iconIndex12 > -1)) {
            hud_element_free(statusBar->iconIndex12);
            hud_element_free(statusBar->iconIndex13);
            statusBar->iconIndex12 = -1;
        }
        D_8010CD12 = FALSE;
    }

    if (statusBar->coinCounterHideTime == 0) {
        return;
    }

    if ((statusBar->displayCoins == playerData->coins) && (statusBar->coinCounterHideTime > 30)) {
        statusBar->coinCounterHideTime = 30;
    }

    if ((statusBar->displayCoins == playerData->coins) || (statusBar->coinCounterHideTime <= 30)) {
        statusBar->coinCounterHideTime--;
        if (statusBar->coinCounterHideTime == 0) {
            set_window_update(WINDOW_ID_CURRENCY_COUNTER, (s32)basic_hidden_window_update);
            statusBar->unk_6D = 15;
            D_8010CD10 = FALSE;
            D_8010CD12 = TRUE;
            statusBar->iconIndex12 = statusBar->coinCountTimesHID;
            statusBar->iconIndex13 = statusBar->coinCountIconHID;
            statusBar->displayCoins = playerData->coins;
            if (statusBar->unk_6E > -1) {
                statusBar->ignoreChanges = statusBar->unk_6E;
                statusBar->unk_6E = -1;
            }
        }
    }
}

void show_coin_counter(void) {
    StatusBar* statusBar = &gStatusBar;
    s32 index;

    if (D_8010CD10 || D_8010CD12) {
        set_window_update(WINDOW_ID_CURRENCY_COUNTER, WINDOW_UPDATE_HIDE);
        if (statusBar->iconIndex12 > -1) {
            hud_element_free(statusBar->coinCountTimesHID);
            hud_element_free(statusBar->coinCountIconHID);
            statusBar->iconIndex12 = -1;
        }
        statusBar->coinCounterHideTime = 0;
        statusBar->unk_6D = 0;
        D_8010CD10 = FALSE;
        D_8010CD12 = FALSE;
    }

    if (statusBar->coinCounterHideTime == 0) {
        set_window_properties(WINDOW_ID_CURRENCY_COUNTER, 32, 164, 64, 20, WINDOW_PRIORITY_21, coin_counter_draw_content, 0, -1);
        set_window_update(WINDOW_ID_CURRENCY_COUNTER, (s32)basic_window_update);
        statusBar->coinCountTimesHID = index = hud_element_create(&HES_MenuTimes);
        hud_element_set_flags(index, HUD_ELEMENT_FLAG_80);
        hud_element_set_tint(index, 255, 255, 255);
        statusBar->coinCountIconHID = index = hud_element_create(&HES_StatusCoin);
        hud_element_set_flags(index, HUD_ELEMENT_FLAG_80);
        hud_element_set_tint(index, 255, 255, 255);
        statusBar->coinCounterHideTime = 0;

        if (statusBar->unk_6E < 0) {
            statusBar->unk_6E = statusBar->ignoreChanges;
        }

        statusBar->ignoreChanges = TRUE;
        D_8010CD10 = TRUE;
    }
}

void hide_coin_counter(void) {
    StatusBar* statusBar = &gStatusBar;

    if (D_8010CD10 && (statusBar->coinCounterHideTime == 0)) {
        statusBar->coinCounterHideTime = 60;
    }
}

void hide_coin_counter_immediately(void) {
    StatusBar* statusBar = &gStatusBar;

    if (D_8010CD10 && (statusBar->coinCounterHideTime == 0)) {
        statusBar->coinCounterHideTime = 1;
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
    update_status_bar();
    update_coin_counter();
}

void open_status_bar_slowly(void) {
    StatusBar* statusBar = &gStatusBar;

    if (statusBar->hidden) {
        statusBar->showTimer = 210;
        statusBar->hidden = FALSE;
        statusBar->unk_3B = TRUE;
    }
}

void open_status_bar_quickly(void) {
    StatusBar* statusBar = &gStatusBar;

    if (statusBar->hidden) {
        statusBar->showTimer = 105;
        statusBar->hidden = FALSE;
        statusBar->unk_3B = TRUE;
    }
}

void close_status_bar(void) {
    StatusBar* statusBar = &gStatusBar;

    if (statusBar->hidden != TRUE) {
        statusBar->hidden = TRUE;
        statusBar->showTimer = 0;
        statusBar->unk_3B = TRUE;
    }
}

void setup_status_bar_for_world(void) {
    StatusBar* statusBar = &gStatusBar;

    statusBar->drawPosY = FULLY_RETRACTED_Y;
    statusBar->ignoreChanges = FALSE;
    statusBar->showTimer = 0;
    statusBar->hidden = TRUE;
    statusBar->unk_3B = FALSE;
    statusBar->unk_3C = FALSE;
}

void setup_status_bar_for_battle(void) {
    StatusBar* statusBar = &gStatusBar;

    statusBar->drawPosY = 0;
    statusBar->ignoreChanges = FALSE;
    statusBar->showTimer = 210;
    statusBar->hidden = FALSE;
    statusBar->unk_3B = TRUE;
    statusBar->unk_3C = FALSE;
}

void enable_status_bar_input(void) {
    gStatusBar.openInputDisabled = FALSE;
}

void disable_status_bar_input(void) {
    gStatusBar.openInputDisabled = TRUE;
}

// determine whether the player can open or close the status bar via button press
b32 can_control_status_bar(void) {
    StatusBar* statusBar = &gStatusBar;

    s32 ret = 1 - statusBar->openInputDisabled;

    if (statusBar->alwaysShown) {
        ret = FALSE;
    }
    if (statusBar->ignoreChanges) {
        ret = FALSE;
    }
    return ret;
}

void status_bar_ignore_changes(void) {
    gStatusBar.ignoreChanges = TRUE;
}

void status_bar_show_and_ignore_changes(void) {
    StatusBar* statusBar = &gStatusBar;

    statusBar->ignoreChanges = TRUE;
    statusBar->drawPosY = FULLY_EXTENDED_Y;
}

void status_bar_respond_to_changes(void) {
    gStatusBar.ignoreChanges = FALSE;
}

s32 status_bar_is_ignoring_changes(void) {
    StatusBar* statusBar = &gStatusBar;

    return statusBar->alwaysShown + statusBar->ignoreChanges;
}

void status_bar_always_show_on(void) {
    gStatusBar.alwaysShown = TRUE;
}

void status_bar_always_show_off(void) {
    gStatusBar.alwaysShown = FALSE;
}

s32 is_status_bar_visible(void) {
    return !gStatusBar.hidden;
}

void status_bar_start_blinking_hp(void) {
    StatusBar* statusBar = &gStatusBar;

    if (!gGameStatusPtr->isBattle) {
        statusBar->hpBlinkTimer = 120;
    }

    if (statusBar->hpBlinking != BLINK_ON) {
        statusBar->hpBlinking = BLINK_ON;
        statusBar->hpBlinkCounter = 0;
    }
}

void status_bar_stop_blinking_hp(void) {
    StatusBar* statusBar = &gStatusBar;

    if (statusBar->hpBlinking != BLINK_OFF) {
        statusBar->hpBlinking = BLINK_OFF;
        statusBar->hpBlinkCounter = 0;
        statusBar->hpBlinkTimer = 0;
    }
}

void status_bar_start_blinking_fp(void) {
    StatusBar* statusBar = &gStatusBar;

    if (!gGameStatusPtr->isBattle) {
        statusBar->fpBlinkTimer = 120;
    }

    if (statusBar->fpBlinking != BLINK_ON) {
        statusBar->fpBlinking = BLINK_ON;
        statusBar->fpBlinkCounter = 0;
    }
}

void status_bar_stop_blinking_fp(void) {
    StatusBar* statusBar = &gStatusBar;

    if (statusBar->fpBlinking != BLINK_OFF) {
        statusBar->fpBlinking = BLINK_OFF;
        statusBar->fpBlinkCounter = 0;
    }
}

void status_bar_start_blinking_coins(void) {
    StatusBar* statusBar = &gStatusBar;

    if (!gGameStatusPtr->isBattle) {
        statusBar->coinsBlinkTimer = 120;
    }

    if (statusBar->coinsBlinking != BLINK_ON) {
        statusBar->coinsBlinking = BLINK_ON;
        statusBar->coinsBlinkCounter = 0;
    }
}

void status_bar_stop_blinking_coins(void) {
    StatusBar* statusBar = &gStatusBar;

    if (statusBar->coinsBlinking != BLINK_OFF) {
        statusBar->coinsBlinking = BLINK_OFF;
        statusBar->coinsBlinkCounter = 0;
        statusBar->coinsBlinkTimer = 0;
    }
}

void status_bar_start_blinking_sp(void) {
    PlayerData* playerData = &gPlayerData;
    StatusBar* statusBar = &gStatusBar;

    statusBar->spBarsToBlink = playerData->maxStarPower;
    if (statusBar->spBlinking != BLINK_ON) {
        statusBar->spBlinking = BLINK_ON;
        statusBar->spBlinkCounter = 0;
    }
}

void status_bar_stop_blinking_sp(void) {
    StatusBar* statusBar = &gStatusBar;

    if (statusBar->spBlinking != BLINK_OFF) {
        statusBar->spBlinking = BLINK_OFF;
        statusBar->spBlinkCounter = 0;
    }
}

void status_bar_start_blinking_sp_bars(s32 numBarsToBlink) {
    StatusBar* statusBar = &gStatusBar;

    statusBar->spBarsToBlink = numBarsToBlink;
    if (statusBar->spBlinking != BLINK_ON) {
        statusBar->spBlinking = BLINK_ON;
        statusBar->spBlinkCounter = 0;
    }
}

void status_bar_start_blinking_starpoints(void) {
    StatusBar* statusBar = &gStatusBar;

    if (statusBar->starpointsBlinking != BLINK_ON) {
        statusBar->starpointsBlinking = BLINK_ON;
        statusBar->starpointsBlinkCounter = 0;
    }
}

void status_bar_stop_blinking_starpoints(void) {
    StatusBar* statusBar = &gStatusBar;

    if (statusBar->starpointsBlinking != BLINK_OFF) {
        statusBar->starpointsBlinking = BLINK_OFF;
        statusBar->starpointsBlinkCounter = 0;
    }
}

void decrement_status_bar_disabled(void) {
    StatusBar* statusBar = &gStatusBar;

    if (statusBar->disabled > 0) {
        statusBar->disabled--;
    }
}

void increment_status_bar_disabled(void) {
    StatusBar* statusBar = &gStatusBar;

    statusBar->disabled++;
}

void sync_status_bar(void) {
    PlayerData* playerData = &gPlayerData;
    StatusBar* statusBar = &gStatusBar;

    statusBar->displayHP = playerData->curHP;
    statusBar->displayFP = playerData->curFP;
    statusBar->displayStarPower = playerData->starPower;
    statusBar->displayCoins = playerData->coins;
    statusBar->displayStarpoints = playerData->starPoints;
}

void reset_status_bar(void) {
    PlayerData* playerData = &gPlayerData;
    StatusBar* statusBar = &gStatusBar;
    s32 i;

    statusBar->drawPosX = 12;
    statusBar->drawPosY = FULLY_RETRACTED_Y;
    statusBar->hidden = 0;
    statusBar->showTimer = 210;
    statusBar->unk_3B = FALSE;
    statusBar->ignoreChanges = FALSE;
    statusBar->openInputDisabled = FALSE;
    statusBar->alwaysShown = FALSE;
    statusBar->hpBlinking = BLINK_OFF;
    statusBar->hpBlinkCounter = 0;
    statusBar->hpBlinkTimer = 0;
    statusBar->fpBlinking = BLINK_OFF;
    statusBar->fpBlinkCounter = 0;
    statusBar->fpBlinkTimer = 0;
    statusBar->coinsBlinking = BLINK_OFF;
    statusBar->coinsBlinkCounter = 0;
    statusBar->coinsBlinkTimer = 0;
    statusBar->spBlinking = BLINK_OFF;
    statusBar->spBlinkCounter = 0;
    statusBar->disabled = 0;
    statusBar->starpointsBlinking = BLINK_OFF;
    statusBar->starpointsBlinkCounter = 0;
    statusBar->unk_6E = -1;
    statusBar->displayHP = playerData->curHP;
    statusBar->displayFP = playerData->curFP;
    statusBar->displayCoins = playerData->coins;
    statusBar->displayStarpoints = playerData->starPoints;
    statusBar->displayStarPower = playerData->starPower;
    statusBar->unk_3C = FALSE;

    for (i = 0; i < ARRAY_COUNT(statusBar->hpIconHIDs); i++) {
        copy_world_hud_element_ref_to_battle(statusBar->hpIconHIDs[i], statusBar->hpIconHIDs[i]);
    }

    for (i = 0; i < ARRAY_COUNT(statusBar->fpIconHIDs); i++) {
        copy_world_hud_element_ref_to_battle(statusBar->fpIconHIDs[i], statusBar->fpIconHIDs[i]);
    }

    copy_world_hud_element_ref_to_battle(statusBar->coinIconHID, statusBar->coinIconHID);
    copy_world_hud_element_ref_to_battle(statusBar->coinSparkleHID, statusBar->coinSparkleHID);
    copy_world_hud_element_ref_to_battle(statusBar->spIconHID, statusBar->spIconHID);
    copy_world_hud_element_ref_to_battle(statusBar->spShineHID, statusBar->spShineHID);
    copy_world_hud_element_ref_to_battle(statusBar->hpTimesHID, statusBar->hpTimesHID);
    copy_world_hud_element_ref_to_battle(statusBar->fpTimesHID, statusBar->fpTimesHID);
    copy_world_hud_element_ref_to_battle(statusBar->spTimesHID, statusBar->spTimesHID);
    copy_world_hud_element_ref_to_battle(statusBar->coinTimesHID, statusBar->coinTimesHID);
    copy_world_hud_element_ref_to_battle(statusBar->starIconHID, statusBar->starIconHID);
}

s32 is_ability_active(s32 ability) {
    PlayerData* playerData = &gPlayerData;
    s32 attackFXArray[6];
    s32 ret;
    s32 attackFXIndex;
    s32 badgeMoveID;
    u8* moveID;
    s32 i;

    ret = 0;
    attackFXIndex = 0;

    for (i = 0; i < ARRAY_COUNT(attackFXArray); i++) {
        attackFXArray[i] = 0;
    }

    if (gGameStatusPtr->peachFlags & PEACH_FLAG_IS_PEACH) {
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
                if (badgeMoveID == MOVE_DODGE_MASTER) {
                    ret++;
                }
                break;
            case ABILITY_SPIKE_SHIELD:
                if (badgeMoveID == MOVE_SPIKE_SHIELD) {
                    ret++;
                }
                break;
            case ABILITY_FIRST_ATTACK:
                if (badgeMoveID == MOVE_FIRST_ATTACK) {
                    ret++;
                }
                break;
            case ABILITY_HP_PLUS:
                if (badgeMoveID == MOVE_HP_PLUS) {
                    ret++;
                }
                break;
            case ABILITY_DOUBLE_DIP:
                if (badgeMoveID == MOVE_DOUBLE_DIP) {
                    ret++;
                }
                break;
            case ABILITY_MYSTERY_SCROLL:
                if (badgeMoveID == MOVE_MYSTERY_SCROLL) {
                    ret++;
                }
                if (playerData->hasActionCommands) {
                    ret++;
                }
                break;
            case ABILITY_FIRE_SHIELD:
                if (badgeMoveID == MOVE_FIRE_SHIELD) {
                    ret++;
                }
                break;
            case ABILITY_PRETTY_LUCKY:
                if (badgeMoveID == MOVE_PRETTY_LUCKY) {
                    ret++;
                }
                break;
            case ABILITY_HP_DRAIN:
                if (badgeMoveID == MOVE_HP_DRAIN) {
                    ret++;
                }
                break;
            case ABILITY_ALL_OR_NOTHING:
                if (badgeMoveID == MOVE_ALLOR_NOTHING) {
                    ret++;
                }
                break;
            case ABILITY_SLOW_GO:
                if (badgeMoveID == MOVE_SLOW_GO) {
                    ret++;
                }
                break;
            case ABILITY_FP_PLUS:
                if (badgeMoveID == MOVE_FP_PLUS) {
                    ret++;
                }
                break;
            case ABILITY_ICE_POWER:
                if (badgeMoveID == MOVE_ICE_POWER) {
                    ret++;
                }
                break;
            case ABILITY_FEELING_FINE:
                if (badgeMoveID == MOVE_FEELING_FINE) {
                    ret++;
                }
                break;
            case ABILITY_ATTACK_FX:
                if (badgeMoveID == MOVE_ATTACK_FX_A) {
                    attackFXArray[attackFXIndex++] = 1;
                    ret = -1;
                }
                if (badgeMoveID == MOVE_ATTACK_FX_D) {
                    attackFXArray[attackFXIndex++] = 2;
                    ret = -1;
                }
                if (badgeMoveID == MOVE_ATTACK_FX_B) {
                    attackFXArray[attackFXIndex++] = 3;
                    ret = -1;
                }
                if (badgeMoveID == MOVE_ATTACK_FX_E) {
                    attackFXArray[attackFXIndex++] = 4;
                    ret = -1;
                }
                if (badgeMoveID == MOVE_ATTACK_FX_C) {
                    attackFXArray[attackFXIndex++] = 5;
                    ret = -1;
                }
                if (badgeMoveID == MOVE_ATTACK_FX_F) {
                    attackFXArray[attackFXIndex++] = 6;
                    ret = -1;
                }
                break;
            case ABILITY_MONEY_MONEY:
                if (badgeMoveID == MOVE_MONEY_MONEY) {
                    ret++;
                }
                break;
            case ABILITY_CHILL_OUT:
                if (badgeMoveID == MOVE_CHILL_OUT_BADGE) {
                    ret++;
                }
                break;
            case ABILITY_HAPPY_HEART:
                if (badgeMoveID == MOVE_HAPPY_HEART) {
                    ret++;
                }
                break;
            case ABILITY_ZAP_TAP:
                if (badgeMoveID == MOVE_ZAP_TAP) {
                    ret++;
                }
                break;
            case ABILITY_MEGA_RUSH:
                if (badgeMoveID == MOVE_MEGA_RUSH) {
                    ret++;
                }
                break;
            case ABILITY_BERSERKER:
                if (badgeMoveID == MOVE_BERSERKER) {
                    ret++;
                }
                break;
            case ABILITY_RIGHT_ON:
                if (badgeMoveID == MOVE_RIGHT_ON) {
                    ret++;
                }
                break;
            case ABILITY_RUNAWAY_PAY:
                if (badgeMoveID == MOVE_RUNAWAY_PAY) {
                    ret++;
                }
                break;
            case ABILITY_FLOWER_SAVER:
                if (badgeMoveID == MOVE_FLOWER_SAVER) {
                    ret++;
                }
                break;
            case ABILITY_PAY_OFF:
                if (badgeMoveID == MOVE_PAY_OFF) {
                    ret++;
                }
                break;
            case ABILITY_DEFEND_PLUS:
                if (badgeMoveID == MOVE_DEFEND_PLUS) {
                    ret++;
                }
                break;
            case ABILITY_POWER_PLUS:
                if (badgeMoveID == MOVE_POWER_PLUS) {
                    ret++;
                }
                break;
            case ABILITY_REFUND:
                if (badgeMoveID == MOVE_REFUND) {
                    ret++;
                }
                break;
            case ABILITY_POWER_RUSH:
                if (badgeMoveID == MOVE_POWER_RUSH) {
                    ret++;
                }
                break;
            case ABILITY_CRAZY_HEART:
                if (badgeMoveID == MOVE_CRAZY_HEART) {
                    ret++;
                }
                break;
            case ABILITY_LAST_STAND:
                if (badgeMoveID == MOVE_LAST_STAND) {
                    ret++;
                }
                break;
            case ABILITY_CLOSE_CALL:
                if (badgeMoveID == MOVE_CLOSE_CALL) {
                    ret++;
                }
                break;
            case ABILITY_P_UP_D_DOWN:
                if (badgeMoveID == MOVE_P_UP_D_DOWN) {
                    ret++;
                }
                break;
            case ABILITY_LUCKY_DAY:
                if (badgeMoveID == MOVE_LUCKY_DAY) {
                    ret++;
                }
                break;
            case ABILITY_MEGA_HP_DRAIN:
                if (badgeMoveID == MOVE_MEGA_HP_DRAIN) {
                    ret++;
                }
                break;
            case ABILITY_P_DOWN_D_UP:
                if (badgeMoveID == MOVE_P_DOWN_D_UP) {
                    ret++;
                }
                break;
            case ABILITY_FLOWER_FANATIC:
                if (badgeMoveID == MOVE_FLOWER_FANATIC) {
                    ret++;
                }
                break;
            case ABILITY_SPEEDY_SPIN:
                if (badgeMoveID == MOVE_SPEEDY_SPIN) {
                    ret++;
                }
                break;
            case ABILITY_SPIN_ATTACK:
                if (badgeMoveID == MOVE_SPIN_ATTACK) {
                    ret++;
                }
                break;
            case ABILITY_I_SPY:
                if (badgeMoveID == MOVE_I_SPY) {
                    ret++;
                }
                break;
            case ABILITY_BUMP_ATTACK:
                if (badgeMoveID == MOVE_BUMP_ATTACK) {
                    ret++;
                }
                break;
            case ABILITY_QUICK_CHANGE:
                if (badgeMoveID == MOVE_QUICK_CHANGE) {
                    ret++;
                }
                break;
            case ABILITY_HEART_FINDER:
                if (badgeMoveID == MOVE_HEART_FINDER) {
                    ret++;
                }
                break;
            case ABILITY_FLOWER_FINDER:
                if (badgeMoveID == MOVE_FLOWER_FINDER) {
                    ret++;
                }
                break;
            case ABILITY_DIZZY_ATTACK:
                if (badgeMoveID == MOVE_DIZZY_ATTACK) {
                    ret++;
                }
                break;
            case ABILITY_FINAL_GOOMPA:
                if (badgeMoveID == MOVE_UNUSED_FINAL_GOOMPA) {
                    ret++;
                }
                break;
            case ABILITY_FINAL_BOBOMB:
                if (badgeMoveID == MOVE_UNUSED_FINAL_BOBOMB) {
                    ret++;
                }
                break;
            case ABILITY_DEEP_FOCUS:
                if (badgeMoveID == MOVE_DEEP_FOCUS) {
                    ret++;
                }
                break;
            case ABILITY_SUPER_FOCUS:
                if (badgeMoveID == MOVE_SUPER_FOCUS) {
                    ret++;
                }
                break;
            case ABILITY_KAIDEN:
                if (badgeMoveID == MOVE_KAIDEN) {
                    ret++;
                }
                break;
            case ABILITY_DAMAGE_DODGE:
                if (badgeMoveID == MOVE_DAMAGE_DODGE) {
                    ret++;
                }
                break;
            case ABILITY_HAPPY_FLOWER:
                if (badgeMoveID == MOVE_HAPPY_FLOWER) {
                    ret++;
                }
                break;
            case ABILITY_GROUP_FOCUS:
                if (badgeMoveID == MOVE_GROUP_FOCUS) {
                    ret++;
                }
                break;
            case ABILITY_PEEKABOO:
                if (badgeMoveID == MOVE_PEEKABOO) {
                    ret++;
                }
                break;
            case ABILITY_HEALTHY_HEALTHY:
                if (badgeMoveID == MOVE_HEALTHY_HEALTHY) {
                    ret++;
                }
                break;
        }
    }

    if (ret < 0) {
        ret = attackFXArray[rand_int(attackFXIndex - 1)];
    }
    return ret;
}

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

void increment_max_star_power(void) {
    gPlayerData.maxStarPower++;
    gPlayerData.starPower = gPlayerData.maxStarPower * SP_PER_BAR;
}

void set_max_star_power(s8 newMax) {
    gPlayerData.maxStarPower = newMax;
    gPlayerData.starPower = newMax * SP_PER_BAR;
}

void add_star_power(s32 amt) {
    // TODO cleanup
    PlayerData* playerData = &gPlayerData;
    StatusBar* statusBar = &gStatusBar;
    s32 phi_v1;
    s32 maxPower;

    statusBar->unk_57 = 1;
    statusBar->unk_58 = 60;

    phi_v1 = playerData->starPower;
    if (playerData->starPower < 0) {
        phi_v1 = playerData->starPower + 31;
    }
    statusBar->unk_59 = phi_v1 >> 5; // same as / SP_PER_SEG

    playerData->starPower += amt;

    maxPower = playerData->maxStarPower * SP_PER_BAR;
    if (playerData->starPower > maxPower) {
        playerData->starPower = maxPower;
    }

    gStatusBar.displayStarPower = gPlayerData.starPower;
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
