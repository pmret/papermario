#include "common.h"
#include "hud_element.h"

extern HudScript* TimesHudScript;
extern HudScript* SPIncrementHudScripts[];
extern HudScript* SPStarHudScripts[];
extern s32 D_800F7FE8[];

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

extern HudScript* SlashHudScript;

void status_menu_start_blinking_coins(void);

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
    playerData->merleeSpellType = MERLEE_SPELL_0;
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
    uiStatus->hidden = FALSE;
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
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusHeart);
    uiStatus->hpIconIndices[1] = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusFP);
    uiStatus->fpIconIndices[0] = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusFlower);
    uiStatus->fpIconIndices[1] = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusCoin);
    uiStatus->coinIconIndex = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_Item_CoinSparkleRandom);
    uiStatus->coinSparkleIconIndex = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusStarPoint);
    uiStatus->starpointsIconIndex = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusSPShine);
    uiStatus->starpointsShineIconIndex = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    newVar = hud_element_create(&HES_StatusTimes);
    iconIndex = newVar;
    uiStatus->iconIndex8 = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusTimes);
    uiStatus->iconIndex9 = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusTimes);
    uiStatus->iconIndexA = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusTimes);
    uiStatus->iconIndexB = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

    iconIndex = hud_element_create(&HES_StatusStar1);
    uiStatus->starIconIndex = iconIndex;
    hud_element_set_flags(iconIndex, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(iconIndex, HUD_ELEMENT_FLAG_FILTER_TEX);

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
    hud_element_clear_flags(iconID, HUD_ELEMENT_FLAG_DISABLED);
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
            hud_element_clear_flags(iconID, HUD_ELEMENT_FLAG_DISABLED);
            hud_element_draw_next(iconID);
        }
    }
}

void status_menu_draw_stat(s32 id, s32 x, s32 y, s32 currentValue, s32 maxValue) {
    s8 digits[4];
    s32 cond;
    s32 digit;
    s32 numDigits = 2;
    s32 localX;
    s32 localY;
    s32 i = 0;
    s32 baseX = x + 8;
    s32 baseY = y + 8;

    hud_element_set_script(id, SlashHudScript);
    hud_element_set_render_pos(id, baseX + 14, baseY + 1);
    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
    hud_element_draw_next(id);

    for (i = 0; i < numDigits; i++) {
        s32 num = currentValue % 10;
        digits[numDigits - i - 1] = num;
        currentValue /= 10;
    }

    localX = baseX;
    localY = baseY;
    cond = FALSE;
    for (i = 0; i < numDigits; i++, localX += 8) {
        digit = digits[i];
        if (digit != 0 || cond || i == numDigits - 1) {
            cond = TRUE;
            hud_element_set_script(id, DigitHudScripts[digit]);
            hud_element_set_render_pos(id, localX, localY);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            hud_element_draw_next(id);
        }
    }

    for (i = 0; i < numDigits; i++) {
        digits[numDigits - i - 1] = maxValue % 10;
        maxValue /= 10;
    }

    localX = baseX + 26;
    localY = baseY;
    cond = FALSE;
    for (i = 0; i < numDigits; i++, localX += 8) {
        digit = digits[i];
        if (digit != 0 || cond || i == numDigits - 1) {
            cond = TRUE;
            hud_element_set_script(id, DigitHudScripts[digit]);
            hud_element_set_render_pos(id, localX, localY);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            hud_element_draw_next(id);
        }
    }
}

#ifdef NON_MATCHING
//regalloc issues
void update_status_menu(void) {
    UiStatus* uiStatus = &gUIStatus;
    PlayerData* playerData = &gPlayerData;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s8 new_var;
    s32 s0;
    s32 s02;
    s32 fp;
    s32 s5;
    s32 s6;
    s32 id;
    s32 s4;
    s32 s7;
    s32 s1;
    s32 v0;
    s32 temp;
s32 new_var2;
    s32 sp50;
    s32 sp54;
    s32 sp5C;
    s32 sp60;
    s32 something;

    if (gGameStatusPtr->creditsViewportMode >= 0 ||
        gGameStatusPtr->demoState != 0 ||
        (gGameStatusPtr->peachFlags & 1) ||
        evt_get_variable(NULL, GB_StoryProgress) >= STORY_EPILOGUE)
    {
        return;
    }

    if (gGameStatusPtr->isBattle == 0 && playerData->coins != uiStatus->displayCoins) {
        status_menu_start_blinking_coins();
    }

    s02 = playerData->coins - uiStatus->displayCoins;

    if (s02 < 0) {
        s02 = (s02 - 4) / 5;
    } else {
        s02 = (s02 + 4) / 5;
    }
    uiStatus->displayCoins += s02;

    if (uiStatus->displayHP != playerData->curHP && !uiStatus->ignoreChanges) {
        if (uiStatus->hidden) {
            uiStatus->showTimer = 70;
            uiStatus->hidden = FALSE;
            uiStatus->unk_3B[0] = 0;
        } else {
            uiStatus->showTimer = 70;
        }
    }

    if (uiStatus->displayFP != playerData->curFP && !uiStatus->ignoreChanges) {
        if (uiStatus->hidden) {
            uiStatus->showTimer = 70;
            uiStatus->hidden = FALSE;
            uiStatus->unk_3B[0] = 0;
        } else {
            uiStatus->showTimer = 70;
        }
    }

    if (uiStatus->displaySP != playerData->specialBarsFilled && !uiStatus->ignoreChanges) {
        if (uiStatus->hidden) {
            uiStatus->showTimer = 70;
            uiStatus->hidden = FALSE;
            uiStatus->unk_3B[0] = 0;
        } else {
            uiStatus->showTimer = 70;
        }
    }

    if (uiStatus->displayHP != playerData->curHP) {
        if (gGameStatusPtr->isBattle == 0 && playerData->curHP < uiStatus->displayHP) {
            status_menu_start_blinking_hp();
        }
        if (uiStatus->displayHP < playerData->curHP) {
            if (uiStatus->drawPosY >= 18) {
                if (gGameStatusPtr->frameCounter % 4 == 0) {
                    uiStatus->displayHP++;
                    sfx_play_sound(SOUND_213);
                }
            } else if (gGameStatusPtr->frameCounter % 4 == 0) {
                uiStatus->displayHP++;
            }
        } else if (gGameStatusPtr->frameCounter % 4 == 0) {
            uiStatus->displayHP--;
        }
    }

    if (uiStatus->displayFP != playerData->curFP) {
        if (gGameStatusPtr->isBattle == 0 && playerData->curFP < uiStatus->displayFP) {
            status_menu_start_blinking_fp();
        }
        if (uiStatus->displayFP < playerData->curFP) {
            if (uiStatus->drawPosY >= 18) {
                if (gGameStatusPtr->frameCounter % 4 == 0) {
                    uiStatus->displayFP++;
                    sfx_play_sound(SOUND_217);
                }
            } else if (gGameStatusPtr->frameCounter % 4 == 0) {
                uiStatus->displayFP++;
            }
        } else if (gGameStatusPtr->frameCounter % 4 == 0) {
            uiStatus->displayFP--;
        }
    }

    if (uiStatus->displaySP != playerData->specialBarsFilled) {
        if (uiStatus->displaySP < playerData->specialBarsFilled) {
            uiStatus->displaySP += 10;
            if (uiStatus->displaySP > playerData->specialBarsFilled) {
                uiStatus->displaySP = playerData->specialBarsFilled;
            }
        } else {
            uiStatus->displaySP -= 10;
            if (uiStatus->displaySP < playerData->specialBarsFilled) {
                uiStatus->displaySP = playerData->specialBarsFilled;
            }
        }
    }

    if (uiStatus->disabled) {
        return;
    }

    if (uiStatus->unk_45[1] && uiStatus->hidden && playerStatus->inputEnabledCounter == 0) {
        uiStatus->showTimer = 42;
        uiStatus->hidden = FALSE;
        uiStatus->unk_3B[0] = 0;
    }

    something = 174;

    switch (uiStatus->hidden) {
        case 0:
            uiStatus->drawPosY += 10;
            if (uiStatus->drawPosY >= 18) {
                uiStatus->drawPosY = 18;
                if (uiStatus->unk_3B[1] && uiStatus->unk_3B[0] && playerStatus->actionState != ACTION_STATE_IDLE) {
                    uiStatus->showTimer = 0;
                }
                if (uiStatus->showTimer != 0) {
                    uiStatus->showTimer--;
                } else {
                    if (!uiStatus->ignoreChanges) {
                        if (!uiStatus->unk_3B[0] || playerStatus->actionState != ACTION_STATE_IDLE) {
                            if (gGameStatusPtr->isBattle == 0) {
                                uiStatus->hidden = 1;
                                uiStatus->showTimer = 0;
                                uiStatus->unk_3B[1] = 0;
                            }
                        }
                    }
                }
            }
            break;
        case 1:
            uiStatus->drawPosY -= 5;
            if (uiStatus->drawPosY < -100) {
                uiStatus->drawPosY = -100;

                if (!uiStatus->ignoreChanges) {
                    if (playerStatus->actionState != ACTION_STATE_IDLE) {
                        uiStatus->showTimer = 0;
                    } else if (playerStatus->flags & (PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_INPUT_DISABLED)) {
                        uiStatus->showTimer = 0;
                    } else {
                        uiStatus->showTimer++;
                    }

                    if (uiStatus->showTimer >= 240 && gGameStatusPtr->isBattle == 0) {
                        uiStatus->showTimer = 210;
                        uiStatus->hidden = 0;
                        uiStatus->unk_3B[0] = 1;
                        uiStatus->unk_3B[1] = 1;
                    }
                }
            }
            break;
    }

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 12, 20, SCREEN_WIDTH - 12, SCREEN_HEIGHT - 20);
    fp = uiStatus->drawPosX;
    s5 = uiStatus->drawPosY;
    draw_box(0, WINDOW_STYLE_5, fp,       s5, 0, 174, 35, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    draw_box(0, WINDOW_STYLE_6, fp + 174, s5, 0, 122, 25, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

    if (uiStatus->hpBlinkTimer > 0) {
        uiStatus->hpBlinkTimer--;
        if (uiStatus->hpBlinkTimer == 0) {
            status_menu_stop_blinking_hp();
        }
    }

    s6 = 1;
    if (uiStatus->hpBlinking) {
        if (uiStatus->hpBlinkCounter > 8) {
            s6 = 0;
            if (uiStatus->hpBlinkCounter > 12) {
                uiStatus->hpBlinkCounter = 0;
                s6 = 1;
            }
        }
        uiStatus->hpBlinkCounter++;
    }

    if (s6) {
        id = uiStatus->hpIconIndices[0];
        hud_element_set_render_pos(id, uiStatus->drawPosX + 22, uiStatus->drawPosY + 13);
        hud_element_draw_next(id);

        id = uiStatus->hpIconIndices[1];
        hud_element_set_render_pos(id, uiStatus->drawPosX + 37, uiStatus->drawPosY + 13);
        hud_element_draw_next(id);

        status_menu_draw_stat(uiStatus->iconIndex8, uiStatus->drawPosX + 48, uiStatus->drawPosY + 8, uiStatus->displayHP, playerData->curMaxHP);
    }

    if (uiStatus->fpBlinkTimer > 0) {
        uiStatus->fpBlinkTimer--;
        if (uiStatus->fpBlinkTimer == 0) {
            status_menu_stop_blinking_fp();
        }
    }

    s6 = 1;
    if (uiStatus->fpBlinking) {
        if (uiStatus->fpBlinkCounter > 8) {
            s6 = 0;
            if (uiStatus->fpBlinkCounter > 12) {
                uiStatus->fpBlinkCounter = 0;
                s6 = 1;
            }
        }
        uiStatus->fpBlinkCounter++;
    }

    if (s6) {
        id = uiStatus->fpIconIndices[0];
        hud_element_set_render_pos(id, uiStatus->drawPosX + 110, uiStatus->drawPosY + 13);
        hud_element_draw_next(id);

        id = uiStatus->fpIconIndices[1];
        hud_element_set_render_pos(id, uiStatus->drawPosX + 125, uiStatus->drawPosY + 13);
        hud_element_draw_next(id);

        status_menu_draw_stat(uiStatus->iconIndex9, uiStatus->drawPosX + 136, uiStatus->drawPosY + 8, uiStatus->displayFP, playerData->curMaxFP);
    }

    if (playerData->level >= 27) {
        playerData->starPoints = 0;
    }

    s6 = 1;
    if (uiStatus->starpointsBlinking) {
        if (uiStatus->starpointsBlinkCounter > 8) {
            if (uiStatus->starpointsBlinkCounter <= 12) {
                s6 = 0;
            } else {
                uiStatus->starpointsBlinkCounter = 0;
            }
        }
        uiStatus->starpointsBlinkCounter++;
    }

    if (s6) {
        id = uiStatus->starpointsIconIndex;
        hud_element_set_render_pos(id, uiStatus->drawPosX + 195, uiStatus->drawPosY + 14);
        hud_element_draw_next(id);

        id = uiStatus->starpointsShineIconIndex;
        hud_element_set_render_pos(id, uiStatus->drawPosX + 195, uiStatus->drawPosY + 9);
        hud_element_draw_next(id);

        status_menu_draw_number(uiStatus->iconIndexA, uiStatus->drawPosX + 200, uiStatus->drawPosY + 8, playerData->starPoints, 2);
    }

    if (uiStatus->coinsBlinkTimer > 0) {
        uiStatus->coinsBlinkTimer--;
        if (uiStatus->coinsBlinkTimer == 0) {
            status_menu_stop_blinking_coins();
        }
    }

    s6 = 1;
    if (uiStatus->coinsBlinking) {
        if (uiStatus->coinsBlinkCounter > 8) {
            s6 = 0;
            if (uiStatus->coinsBlinkCounter > 12) {
                uiStatus->coinsBlinkCounter = 0;
                s6 = 1;
            }
        }
        uiStatus->coinsBlinkCounter++;
    }

    if (s6) {
        id = uiStatus->coinIconIndex;
        hud_element_set_render_pos(id, uiStatus->drawPosX + 244, uiStatus->drawPosY + 14);
        hud_element_draw_next(id);

        id = uiStatus->coinSparkleIconIndex;
        hud_element_set_render_pos(id, uiStatus->drawPosX + 244, uiStatus->drawPosY + 14);
        hud_element_draw_next(id);

        status_menu_draw_number(uiStatus->iconIndexB, uiStatus->drawPosX + 247, uiStatus->drawPosY + 8, uiStatus->displayCoins, 3);
    }

    id = uiStatus->starIconIndex;
    s6 = 1;

    if (uiStatus->spBlinking) {
        if (uiStatus->spBlinkCounter > 5) {
            if (uiStatus->spBlinkCounter <= 8) {
                s6 = 0;
            } else {
                uiStatus->spBlinkCounter = 0;
                s6 = 1;
            }
        }
        uiStatus->spBlinkCounter++;
    }

    fp = uiStatus->drawPosX + 20;
    s5 = uiStatus->drawPosY + 28;

    temp = uiStatus->displaySP / 256;
    s4 = uiStatus->displaySP % 256;
    s4 /= 32;
    s4 = s4 + temp * 8;
    if (uiStatus->unk_57 == 1) {
        temp = playerData->specialBarsFilled / 256;
        s4 = playerData->specialBarsFilled % 256;
        s4 = s4 / 32;
        s4 += temp * 8;
        func_800F0CB0(0, fp + s4 * 25 / 10, s5, 1.0f);
        uiStatus->unk_57 = 2;
    }

    sp54 = 0;
    if (uiStatus->unk_57 != 0) {
        if (uiStatus->unk_58 != 0) {
            uiStatus->unk_58--;
        } else {
            uiStatus->unk_57 = 0;
        }
        if ((uiStatus->unk_58 / 5) & 1) {
            sp54 = 1;
        }
        s7 = uiStatus->unk_59 % 8;
        s7 += uiStatus->unk_59 / 8 * 8;
    } else {
        s7 = s4;
    }

    s02 = 0;
    sp50 = 0;
    s1 = 0;

    if (uiStatus->spBlinking) {
        if (!s6) {
            if (sp50 < uiStatus->spBarsToBlink * 8) {
                while (TRUE) {
                    s02++;
                    s1++;
                    if (s02 >= uiStatus->spBarsToBlink) { break; } s02++; s1++;
                    if (s02 >= uiStatus->spBarsToBlink) { break; } s02++; s1++;
                    if (s02 >= uiStatus->spBarsToBlink) { break; } s02++; s1++;
                    if (s02 >= uiStatus->spBarsToBlink) { break; } s02++; s1++;
                    if (s02 >= uiStatus->spBarsToBlink) { break; } s02++; s1++;
                    if (s02 >= uiStatus->spBarsToBlink) { break; } s02++; s1++;
                    if (s02 >= uiStatus->spBarsToBlink) { break; } s02++; s1 = 0;
                    sp50++;
                    if (s02 >= uiStatus->spBarsToBlink) { break; }
                }
            }
        }
    }

    while (TRUE) {
        if (s02 >= s4 || s02 >= s7 && sp54 == 0) {
            break;
        }
        s02++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[0], s5 - 2);
        hud_element_draw_next(id);
        s1++;
        if (s02 >= s4 || s02 >= s7 && sp54 == 0) {
            break;
        }
        s02++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[1], s5 - 2);
        hud_element_draw_next(id);
        s1++;
        if (s02 >= s4 || s02 >= s7 && sp54 == 0) {
            break;
        }
        s02++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[2], s5 - 2);
        hud_element_draw_next(id);
        s1++;
        if (s02 >= s4 || s02 >= s7 && sp54 == 0) {
            break;
        }
        s02++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[3], s5 - 2);
        hud_element_draw_next(id);
        s1++;
        if (s02 >= s4 || s02 >= s7 && sp54 == 0) {
            break;
        }
        s02++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[4], s5 - 2);
        hud_element_draw_next(id);
        s1++;

        if (s02 >= s4 || s02 >= s7 && sp54 == 0) {
            break;
        }
        s02++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[5], s5 - 2);
        hud_element_draw_next(id);
        s1++;

        if (s02 >= s4 || s02 >= s7 && sp54 == 0) {
            break;
        }
        s02++;
        hud_element_set_script(id, SPIncrementHudScripts[sp50]);
        hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[6], s5 - 2);
        hud_element_draw_next(id);
        s1++;

        if (s02 >= s4 || s02 >= s7 && sp54 == 0) {
            break;
        }
        s02++;
        hud_element_set_script(id, SPStarHudScripts[sp50]);
        hud_element_set_render_pos(id, fp + 12 + sp50 * 20, s5);
        hud_element_draw_next(id);
        s1 = 0;
        sp50++;
        if (s02 >= s4 || s02 >= s7 && sp54 == 0) {
            break;
        }
    }
    new_var2 = s5;

    temp = playerData->maxStarPower;
    s4 = temp * 8;
    while (TRUE) {
        if (s02 >= s4) {
            break;
        }
        if (s1 == 0) {
            s02++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[s1], new_var2 - 2);
            hud_element_draw_next(id);
            if (s02 >= s4) {
                break;
            }
            s1 = 1;
        }
        if (s1 == 1) {
            s02++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[s1], new_var2 - 2);
            hud_element_draw_next(id);
            if (s02 >= s4) {
                break;
            }
            s1 = 2;
        }
        if (s1 == 2) {
            s02++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[s1], new_var2 - 2);
            hud_element_draw_next(id);
            if (s02 >= s4) {
                break;
            }
            s1 = 3;
        }
        if (s1 == 3) {
            s02++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[s1], new_var2 - 2);
            hud_element_draw_next(id);
            if (s02 >= s4) {
                break;
            }
            s1 = 4;
        }
        if (s1 == 4) {
            s02++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[s1], new_var2 - 2);
            hud_element_draw_next(id);
            if (s02 >= s4) {
                break;
            }
            s1 = 5;
        }
        if (s1 == 5) {
            s02++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[s1], new_var2 - 2);
            hud_element_draw_next(id);
            if (s02 >= s4) {
                break;
            }
            s1 = 6;
        }
        if (s1 == 6) {
            s02++;
            hud_element_set_script(id, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(id, fp + sp50 * 20 + D_800F7FE8[s1], new_var2 - 2);
            hud_element_draw_next(id);
            if (s02 >= s4) {
                break;
            }
            s1 = 7;
        }

        if (s1 == 7) {
            s02++;
            hud_element_set_script(id, &HES_StatusStarEmpty);
            hud_element_set_render_pos(id, fp + 12 + sp50 * 20, new_var2);
            hud_element_draw_next(id);
            if (s02 >= s4) {
                break;
            }
        }
        s1 = 0;
        sp50++;
    }

    func_800F0D80();
    func_800F102C();
}
#else
void update_status_menu(void);
INCLUDE_ASM(s32, "80850_len_3060", update_status_menu);
#endif

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
        hud_element_set_flags(index, HUD_ELEMENT_FLAG_80);
        hud_element_set_tint(index, 255, 255, 255);
        index = hud_element_create(&HES_StatusCoin);
        uiStatus->iconIndex11 = index;
        hud_element_set_flags(index, HUD_ELEMENT_FLAG_80);
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
        uiStatus->hidden = FALSE;
        uiStatus->unk_3B[0] = 1;
    }
}

void open_status_menu_short(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->hidden) {
        uiStatus->showTimer = 105;
        uiStatus->hidden = FALSE;
        uiStatus->unk_3B[0] = 1;
    }
}

void close_status_menu(void) {
    UiStatus* uiStatus = &gUIStatus;

    if (uiStatus->hidden != TRUE) {
        uiStatus->hidden = TRUE;
        uiStatus->showTimer = 0;
        uiStatus->unk_3B[0] = 1;
    }
}

void func_800E97E4(void) {
    UiStatus* uiStatus = &gUIStatus;

    uiStatus->drawPosY = -100;
    uiStatus->ignoreChanges = FALSE;
    uiStatus->showTimer = 0;
    uiStatus->hidden = TRUE;
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

    for (i = 0; i < ARRAY_COUNT(uiStatus->hpIconIndices); i++) {
        copy_world_hud_element_ref_to_battle(uiStatus->hpIconIndices[i], uiStatus->hpIconIndices[i]);
    }

    for (i = 0; i < ARRAY_COUNT(uiStatus->fpIconIndices); i++) {
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
