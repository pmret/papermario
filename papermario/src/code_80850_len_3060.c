#include "common.h"

void clear_player_data(void) {
    player_data* playerData = &gPlayerData;
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
    playerData->unk_292 = 0;
    playerData->currentPartner = 0;

    for(i = 0; i < ARRAY_COUNT(playerData->partners); i++) {
        playerData->partners[i].enabled = 0;
        playerData->partners[i].level = 0;
        playerData->partners[i].unk_2 = 0;
        playerData->partners[i].unk_4 = 0;
        playerData->partners[i].unk_6 = 0;
    }

    for(i = ARRAY_COUNT(playerData->keyItems) - 1; i >= 0; i--){
        playerData->keyItems[i] = 0;
    }

    for(i = ARRAY_COUNT(playerData->badges) - 1; i >= 0; i--) {
        playerData->badges[i] = 0;
    }

    for(i = ARRAY_COUNT(playerData->invItems) - 1; i >= 0; i--) {
        playerData->invItems[i] = 0;
    }

    for(i = ARRAY_COUNT(playerData->equippedBadges) - 1; i >= 0; i--) {
        playerData->equippedBadges[i] = 0;
    }

    for(i = ARRAY_COUNT(playerData->storedItems) - 1; i >= 0; i--) {
        playerData->storedItems[i] = 0;
    }

    playerData->otherHitsTaken = 0;
    playerData->unk_296 = 0;
    playerData->hitsTaken = 0;
    playerData->hitsBlocked = 0;
    playerData->playerFirstStrikes = 0;
    playerData->enemyFirstStrikes = 0;
    playerData->powerBounces = 0;
    playerData->battlesCount = 0;
    playerData->unk_2A4 = 0;
    playerData->unk_2A6 = 0;
    playerData->unk_2A8 = 0;
    playerData->unk_2AA = 0;
    playerData->unk_2AC = 0;
    playerData->unk_2B0 = 0;
    playerData->idleFrameCounter = 0;
    playerData->totalCoinsEarned = 0;
    playerData->frameCounter = 0;
    playerData->quizzesAnswered = 0;
    playerData->quizzesCorrect = 0;

    for(i = 0; i < ARRAY_COUNT(playerData->unk_2C4); i++) {
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

player_data* get_player_data(void) {
    return &gPlayerData;
}

s32 add_item(s32 itemID) {
    player_data* playerData = &gPlayerData;
    s32 i;

    sort_items();

    for(i = 0; i < ARRAY_COUNT(gPlayerData.invItems); i++) {
        if (playerData->invItems[i] == 0) {
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
    player_data *playerData = &gPlayerData;
    s32 i = 0;
    s32 sum = 0;

    for (i; i < ARRAY_COUNT(gPlayerData.invItems); i++) {
        if (playerData->invItems[i] != 0) {
            sum++;
        }
    }
    
    return sum;
}

s32 get_item_empty_count(void) {
    return ARRAY_COUNT(gPlayerData.invItems) - get_item_count();
}

INCLUDE_ASM(code_80850_len_3060, find_item);

INCLUDE_ASM(code_80850_len_3060, sort_items);

INCLUDE_ASM(code_80850_len_3060, add_badge);

s32 store_item(s32 itemID) {
    player_data *playerData = &gPlayerData;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPlayerData.storedItems); i++) {
        if (playerData->storedItems[i] == 0) {
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
    player_data *playerData = &gPlayerData;
    s32 i = 0;
    s32 sum = 0;

    for (i; i < ARRAY_COUNT(gPlayerData.storedItems); i++) {
        if (playerData->storedItems[i] != 0) {
            sum++;
        }
    }
    
    return sum;
}

s32 get_stored_empty_count(void) {
    return ARRAY_COUNT(gPlayerData.storedItems) - get_stored_count();
}

INCLUDE_ASM(code_80850_len_3060, enforce_hpfp_limits);

INCLUDE_ASM(code_80850_len_3060, initialize_status_menu);

INCLUDE_ASM(code_80850_len_3060, status_menu_draw_number);

INCLUDE_ASM(code_80850_len_3060, status_menu_draw_stat);

INCLUDE_ASM(code_80850_len_3060, update_status_menu);

INCLUDE_ASM(code_80850_len_3060, coin_counter_draw_content);

INCLUDE_ASM(code_80850_len_3060, update_coin_counter);

INCLUDE_ASM(code_80850_len_3060, show_coin_counter);

INCLUDE_ASM(code_80850_len_3060, hide_coin_counter);

INCLUDE_ASM(code_80850_len_3060, func_800E96C8);

s32 ShowCoinCounter(ScriptContext* script) {
    if (get_variable(script, *script->ptrReadPos)) {
        show_coin_counter();
    } else {
        hide_coin_counter();
    }
    return 2;
}


INCLUDE_ASM(code_80850_len_3060, func_800E973C);

void open_status_menu_long(void) {
    ui_status* uiStatus = &gUIStatus;

    if (uiStatus->hidden) {
        uiStatus->showTimer = 210;
        uiStatus->hidden = 0;
        uiStatus->unk_3B = 1;
    }
}


void open_status_menu_short(void) {
    ui_status* uiStatus = &gUIStatus;

    if (uiStatus->hidden) {
        uiStatus->showTimer = 105;
        uiStatus->hidden = 0;
        uiStatus->unk_3B = 1;
    }
}

INCLUDE_ASM(code_80850_len_3060, func_800E97B8);

INCLUDE_ASM(code_80850_len_3060, func_800E97E4);

INCLUDE_ASM(code_80850_len_3060, func_800E9810);

INCLUDE_ASM(code_80850_len_3060, func_800E983C);

INCLUDE_ASM(code_80850_len_3060, func_800E984C);

INCLUDE_ASM(code_80850_len_3060, func_800E9860);

INCLUDE_ASM(code_80850_len_3060, func_800E9894);

INCLUDE_ASM(code_80850_len_3060, func_800E98C4);

s32 func_800E98D4(void) {
    ui_status* uiStatus = &gUIStatus;

    return uiStatus->unk_46 + uiStatus->ignoreChanges;
}


INCLUDE_ASM(code_80850_len_3060, func_800E98EC);

void func_800E9900(void) {
    gUIStatus.unk_46 = 0;
}


s32 is_status_menu_visible(void) {
    return !gUIStatus.hidden;
}

void status_menu_start_blinking_hp(void) {
    game_status* gameStatus = (*gGameStatusPtr);
    ui_status* uiStatus = &gUIStatus;
    ui_status* uiStatus2 = &gUIStatus;

    if (gameStatus->unk_70 == 0) {
        uiStatus->hpBlinkTimer = 120;
    }

    if (uiStatus2->hpBlinking != 1) {
        uiStatus2->hpBlinking = 1;
        uiStatus2->hpBlinkCounter = 0;
    }
}

void status_menu_stop_blinking_hp(void) {
    ui_status* uiStatus = &gUIStatus;

    if (uiStatus->hpBlinking != 0) {
        uiStatus->hpBlinking = 0;
        uiStatus->hpBlinkCounter = 0;
        uiStatus->hpBlinkTimer = 0;
    }
}

void status_menu_start_blinking_fp(void) {
    game_status* gameStatus = (*gGameStatusPtr);
    ui_status* uiStatus = &gUIStatus;
    ui_status* uiStatus2 = &gUIStatus;

    if (gameStatus->unk_70 == 0) {
        uiStatus->fpBlinkTimer = 120;
    }

    if (uiStatus2->fpBlinking != 1) {
        uiStatus2->fpBlinking = 1;
        uiStatus2->fpBlinkCounter = 0;
    }
}

void status_menu_stop_blinking_fp(void) {
    ui_status* uiStatus = &gUIStatus;

    if (uiStatus->fpBlinking != 0) {
        uiStatus->fpBlinking = 0;
        uiStatus->fpBlinkCounter = 0;
    }
}

void status_menu_start_blinking_coins(void) {
    game_status* gameStatus = (*gGameStatusPtr);
    ui_status* uiStatus = &gUIStatus;
    ui_status* uiStatus2 = &gUIStatus;

    if (gameStatus->unk_70 == 0) {
        uiStatus->coinsBlinkTimer = 120;
    }

    if (uiStatus2->coinsBlinking != 1) {
        uiStatus2->coinsBlinking = 1;
        uiStatus2->coinsBlinkCounter = 0;
    }
}

void status_menu_stop_blinking_coins(void) {
    ui_status* uiStatus = &gUIStatus;

    if (uiStatus->coinsBlinking != 0) {
        uiStatus->coinsBlinking = 0;
        uiStatus->coinsBlinkCounter = 0;
        uiStatus->coinsBlinkTimer = 0;
    }
}

void status_menu_start_blinking_sp(void) {
    player_data *playerData = &gPlayerData;
    ui_status* uiStatus = &gUIStatus;

    uiStatus->spBarsToBlink = playerData->maxStarPower;
    if (uiStatus->spBlinking != 1) {
        uiStatus->spBlinking = 1;
        uiStatus->spBlinkCounter = 0;
    }
}

void status_menu_stop_blinking_sp(void) {
    ui_status* uiStatus = &gUIStatus;

    if (uiStatus->spBlinking != 0) {
        uiStatus->spBlinking = 0;
        uiStatus->spBlinkCounter = 0;
    }
}

void status_menu_start_blinking_sp_bars(s8 numBarsToBlink) {
    ui_status* uiStatus = &gUIStatus;

    uiStatus->spBarsToBlink = numBarsToBlink;
    if (uiStatus->spBlinking != 1) {
        uiStatus->spBlinking = 1;
        uiStatus->spBlinkCounter = 0;
    }
}

void status_menu_start_blinking_starpoints(void) {
    ui_status* uiStatus = &gUIStatus;

    if (uiStatus->starpointsBlinking != 1) {
        uiStatus->starpointsBlinking = 1;
        uiStatus->starpointsBlinkCounter = 0;
    }
}

void status_menu_stop_blinking_starpoints(void) {
    ui_status* uiStatus = &gUIStatus;

    if (uiStatus->starpointsBlinking != 0) {
        uiStatus->starpointsBlinking = 0;
        uiStatus->starpointsBlinkCounter = 0;
    }
}

void decrement_status_menu_disabled(void) {
    ui_status* uiStatus = &gUIStatus;

    if (uiStatus->disabled > 0) {
        uiStatus->disabled--;
    }
}

void increment_status_menu_disabled(void) {
    ui_status* uiStatus = &gUIStatus;

    uiStatus->disabled++;
}

void sync_status_menu(void) {
    player_data *playerData = &gPlayerData;
    ui_status* uiStatus = &gUIStatus;

    uiStatus->displayHP = playerData->curHP;
    uiStatus->displayFP = playerData->curFP;
    uiStatus->displaySP = playerData->specialBarsFilled;
    uiStatus->displayCoins = playerData->coins;
    uiStatus->displayStarpoints = playerData->starPoints;
}

INCLUDE_ASM(code_80850_len_3060, reset_status_menu);

// uses a jumptable, which we need .rodata support for.
INCLUDE_ASM(code_80850_len_3060, is_ability_active);

s32 is_partner_ability_active(void) {
    return 0;
}

s16 add_coins(s32 amt) {
    player_data *playerData = &gPlayerData;
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
    player_data *playerData = &gPlayerData;
    player_data *playerData2 = &gPlayerData;
    s8 newSP = playerData->starPoints + amt;

    //TODO: probably a macro!
    playerData2->starPoints = newSP;
    if (newSP > 100) {
       playerData2->starPoints = 100;
    }

    //TODO: probably a macro!
    newSP = playerData2->starPoints;
    if (newSP < 0) {
       playerData2->starPoints = 0;
    }
    return gPlayerData.starPoints;
}

u8 add_star_pieces(s32 amt) {
    player_data *playerData = &gPlayerData;
    player_data *playerData2 = &gPlayerData;
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
    player_data* playerData = &gPlayerData;

    playerData->maxStarPower++;
    playerData->specialBarsFilled = playerData->maxStarPower * 256;
}

void set_max_SP(s8 newMaxSP) {
    player_data* playerData = &gPlayerData;

    playerData->maxStarPower = newMaxSP;
    playerData->specialBarsFilled = newMaxSP * 256;
}

INCLUDE_ASM(code_80850_len_3060, add_SP);

s32 recover_fp(s32 amt) {
    player_data* playerData = &gPlayerData;
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
    player_data* playerData = &gPlayerData;
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
    player_data* playerData = &gPlayerData;
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
    player_data* playerData = &gPlayerData;

    return playerData->curMaxHP == playerData->curHP;
}

s8 has_full_fp(void) {
    player_data* playerData = &gPlayerData;

    return playerData->curMaxFP == playerData->curFP;
}

s8 add_fortress_keys(s32 amt) {
    player_data* playerData = &gPlayerData;

    playerData->fortressKeyCount += amt;
    return playerData->fortressKeyCount;
}

s8 subtract_fortress_keys(s8 amt) {
    player_data* playerData = &gPlayerData;
    player_data* playerData2 = &gPlayerData; // required to match

    playerData->fortressKeyCount -= amt;
    if (playerData->fortressKeyCount < 0) {
        playerData->fortressKeyCount = 0;
    }

    return playerData2->fortressKeyCount; // required to use playerData2 here to match
}

s8 get_fortress_key_count(void) {
    return gPlayerData.fortressKeyCount;
}
