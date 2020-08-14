#include "common.h"

INCLUDE_ASM(code_fa4c0_len_3bf0, func_802D5B10);

s32 FadeOutMusic(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32* ptrNextPos = ptrReadPos++;

    return (set_music_track(itemID, -1, 0, get_variable(script, *ptrNextPos++), 8) != 0) * 2;
}

s32 SetMusicTrack(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 musicPlayer = get_variable(script, *ptrReadPos++);
    s32 songID = get_variable(script, *ptrReadPos++);
    s32 variation = get_variable(script, *ptrReadPos++);
    s16 volume = get_variable(script, *ptrReadPos++);

    return (set_music_track(musicPlayer, songID, variation, 0x1F4, volume) != 0) * 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, FadeInMusic);

s32 PlayAmbientSounds(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);

    return (play_ambient_sounds(soundID, 0xFA) != 0) * 2;
}

s32 PlaySound(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);

    play_sound(soundID);
    return 2;
}

s32 func_802D617C(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);
    s32 value2 = get_variable(script, *ptrReadPos++);

    _play_sound(soundID, value2 & 0xFF, 0, 0);
    return 2;
}

s32 PlaySoundAt(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);
    s32 value2 = get_variable(script, *ptrReadPos++);
    s32 x = get_variable(script, *ptrReadPos++);
    s32 y = get_variable(script, *ptrReadPos++);
    s32 z = get_variable(script, *ptrReadPos++);

    play_sound_at_position(soundID, value2, x, y, z);
    return 2;
}

s32 StopSound(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    stop_sound(get_variable(script, *ptrReadPos++));
    return 2;
}

s32 func_802D62E4(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    func_80149A6C(get_variable(script, *ptrReadPos++), 1);
    return 2;
}

s32 UseDoorSounds(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    gCurrentDoorSoundsSet = get_variable(script, *ptrReadPos++);
    return 2;
}

s32 func_802D6340(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    D_80151308 = get_variable(script, *ptrReadPos++);
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, PlaySoundAtF);

s32 RemoveKeyItemAt(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 index = get_variable(script, *ptrReadPos++);
    s16* ptrTemp = D_8010F304;

    ptrTemp[index] = 0;
    return 2;
}

s32 RemoveItemAt(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 index = get_variable(script, *ptrReadPos++);
    s16* ptrTemp = D_8010F444;
    
    ptrTemp[index] = 0;
    sort_items();
    return 2;
}

s32 AddKeyItem(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 value = *ptrReadPos++;
    player_data* playerData = &gPlayerData;
    s32 itemID = get_variable(script, value);
    s32 i;

    if (itemID == FORTRESS_KEY) {
        playerData->fortressKeyCount++;
        return 2;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
        if (playerData->keyItems[i] == 0) {
            break;
        }
    }

    if (i < ARRAY_COUNT(playerData->keyItems)) {
        playerData->keyItems[i] = itemID;
    }
    return 2;
}

s32 func_802D6954(void) {
    func_800E01A4();
    disable_player_physics();
    func_800EF600();
    D_8009A650[0] &= ~0x40;
    return 2;
}

s32 HasKeyItem(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32 value = *ptrReadPos++;
    player_data* playerData = &gPlayerData;
    s32 i;
    
    for(i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
        if (playerData->keyItems[i] == itemID) {
            break;
        }
    }
    set_variable(script, value, i < ARRAY_COUNT(playerData->keyItems));
    return 2;
}

s32 FindKeyItem(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32 value = *ptrReadPos++;
    player_data* playerData = &gPlayerData;
    s32 i;
    s32 itemIndex;

    for(i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
        if (playerData->keyItems[i] == itemID) {
            break;
        }
    }

    itemIndex = -1;
    if (i != ARRAY_COUNT(playerData->keyItems)) {
        itemIndex = i;
    }

    set_variable(script, value, itemIndex);
    return 2;
}

s32 AddItem(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32* ptrNextPos = *ptrReadPos++;

    set_variable(script, ptrNextPos, add_item(itemID));
    return 2;
}

s32 func_802D6AF0(script_context* script, s32 initialCall) {
    set_variable(script, *script->ptrReadPos, 0);
    return 2;
}

s32 FindItem(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32 value = *ptrReadPos++;
    player_data* playerData = &gPlayerData;
    s32 i;
    s32 itemIndex;

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        if (playerData->invItems[i] == itemID) {
            break;
        }
    }

    itemIndex = -1;
    if (i != ARRAY_COUNT(playerData->invItems)) {
        itemIndex = i;
    }

    set_variable(script, value, itemIndex);
    return 2;
}

s32 RemoveItem(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32 value = *ptrReadPos++;
    player_data* playerData = &gPlayerData;
    s32 i;
    s32 itemIndex;

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        if (playerData->invItems[i] == itemID) {
            break;
        }
    }

    itemIndex = -1;
    if (i != ARRAY_COUNT(playerData->invItems)) {
        itemIndex = i;
    }

    if (itemIndex >= 0) {
        // This is `playerData->invItems[i]`, but we have to do weird
        // pointer math to get the output asm to exactly match :/
        *(playerData->invItems + i) = 0;
    }
    sort_items();

    set_variable(script, value, itemIndex);
    return 2;
}

s32 CountFortressKeys(script_context* script, s32 initialCall) {
    s32 outVar = *script->ptrReadPos;

    set_variable(script, outVar, get_fortress_key_count());
    return 2;
}

s32 RemoveFortressKeys(script_context* script, s32 initialCall) {
    s32 num = get_variable(script, *script->ptrReadPos);

    subtract_fortress_keys(num);
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, MakeItemEntity);

INCLUDE_ASM(code_fa4c0_len_3bf0, DropItemEntity);

INCLUDE_ASM(code_fa4c0_len_3bf0, DropItemEntityB);

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveItemEntity);

s32 AddBadge(script_context* script, s32 initialCall) {
  s32* ptrReadPos = script->ptrReadPos;
  s32 itemID = get_variable(script, *ptrReadPos++);
  s32* ptrNextPos = *ptrReadPos++;

  set_variable(script, ptrNextPos, add_badge(itemID));
  return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveBadge);

s32 SetItemPos(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    item_entity* ptrItemEntity;
    s32 itemEntityIndex;
    s32 x, y, z;

    itemEntityIndex = get_variable(script, *ptrReadPos++);
    x = get_variable(script, *ptrReadPos++);
    y = get_variable(script, *ptrReadPos++);
    z = get_variable(script, *ptrReadPos++);

    ptrItemEntity = get_item_entity(itemEntityIndex);
    ptrItemEntity->position[0] = x;
    ptrItemEntity->position[1] = y;
    ptrItemEntity->position[2] = z;
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, SetItemFlags);

s32 AddCoin(script_context* script, s32 initialCall) {
    script->varTable[0] = add_coins(get_variable(script, *script->ptrReadPos));
    return 2;
}

s32 AddStarPoints(script_context* script, s32 initialCall) {
    script->varTable[0] = add_star_points(get_variable(script, *script->ptrReadPos));
    return 2;
}

s32 AddStarPieces(script_context* script, s32 initialCall) {
    script->varTable[0] = add_star_pieces(get_variable(script, *script->ptrReadPos));
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, GetItemPower);

INCLUDE_ASM(code_fa4c0_len_3bf0, ShowGotItem);

INCLUDE_ASM(code_fa4c0_len_3bf0, func_802D7460);

INCLUDE_ASM(code_fa4c0_len_3bf0, func_802D74C0);

INCLUDE_ASM(code_fa4c0_len_3bf0, ShowEmote);

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveEffect);
/*
s32 RemoveEffect(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    remove_effect(get_variable(script, *ptrReadPos++));
    return 2;
}

s32 func_802D7B10(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 ptrValue = get_variable(script, *ptrReadPos++);
    *ptrValue = (*ptrValue | 0x10);
    return 2;
}

s32 func_802D7B44(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 ptrValue = get_variable(script, *ptrReadPos++);
    *((ptrValue + 0xC) + 0x14) = 10;
    return 2;
}

s32 func_802D7B74(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 ptrValue = get_variable(script, *ptrReadPos++);
    *((ptrValue + 0xC) + 0x30) = 5;
    return 2;
}
*/

INCLUDE_ASM(code_fa4c0_len_3bf0, ShowSleepBubble);

INCLUDE_ASM(code_fa4c0_len_3bf0, PlayEffect);
