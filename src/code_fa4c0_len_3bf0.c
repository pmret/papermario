#include "common.h"

INCLUDE_ASM(code_fa4c0_len_3bf0, func_802D5B10);

s32 FadeOutMusic(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32* ptrNextPos = ptrReadPos++;

    return (set_music_track(itemID, -1, 0, get_variable(script, *ptrNextPos++), 8) != 0) * 2;
}

s32 SetMusicTrack(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 musicPlayer = get_variable(script, *ptrReadPos++);
    s32 songID = get_variable(script, *ptrReadPos++);
    s32 variation = get_variable(script, *ptrReadPos++);
    s16 volume = get_variable(script, *ptrReadPos++);

    return (set_music_track(musicPlayer, songID, variation, 0x1F4, volume) != 0) * 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, FadeInMusic);

s32 PlayAmbientSounds(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);

    return (play_ambient_sounds(soundID, 0xFA) != 0) * 2;
}

s32 PlaySound(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);

    play_sound(soundID);
    return 2;
}

s32 func_802D617C(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);
    s32 value2 = get_variable(script, *ptrReadPos++);

    _play_sound(soundID, value2 & 0xFF, 0, 0);
    return 2;
}

s32 PlaySoundAt(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);
    s32 value2 = get_variable(script, *ptrReadPos++);
    s32 x = get_variable(script, *ptrReadPos++);
    s32 y = get_variable(script, *ptrReadPos++);
    s32 z = get_variable(script, *ptrReadPos++);

    play_sound_at_position(soundID, value2, x, y, z);
    return 2;
}

s32 StopSound(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    stop_sound(get_variable(script, *ptrReadPos++));
    return 2;
}

s32 func_802D62E4(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    func_80149A6C(get_variable(script, *ptrReadPos++), 1);
    return 2;
}

s32 UseDoorSounds(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    gCurrentDoorSoundsSet = get_variable(script, *ptrReadPos++);
    return 2;
}

s32 func_802D6340(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    D_80151308 = get_variable(script, *ptrReadPos++);
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, PlaySoundAtF);

s32 RemoveKeyItemAt(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 index = get_variable(script, *ptrReadPos++);
    s16* ptrKeyItems = (s16 *) &gPlayerData.keyItems;

    ptrKeyItems[index] = 0;
    return 2;
}

s32 RemoveItemAt(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 index = get_variable(script, *ptrReadPos++);
    s16* ptrInvItems = (s16 *) &gPlayerData.invItems;

    ptrInvItems[index] = 0;
    sort_items();
    return 2;
}

s32 AddKeyItem(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 value = *ptrReadPos++;
    PlayerData* playerData = &gPlayerData;
    s32 itemID = get_variable(script, value);
    s32 i;

    if (itemID == ItemId_FORTRESS_KEY) {
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

s32 HasKeyItem(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32 value = *ptrReadPos++;
    PlayerData* playerData = &gPlayerData;
    s32 i;

    for(i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
        if (playerData->keyItems[i] == itemID) {
            break;
        }
    }
    set_variable(script, value, i < ARRAY_COUNT(playerData->keyItems));
    return 2;
}

s32 FindKeyItem(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32 value = *ptrReadPos++;
    PlayerData* playerData = &gPlayerData;
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

s32 AddItem(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32* ptrNextPos = (s32 *) *ptrReadPos++;

    set_variable(script, ptrNextPos, add_item(itemID));
    return 2;
}

s32 func_802D6AF0(ScriptInstance* script, s32 initialCall) {
    set_variable(script, *script->ptrReadPos, 0);
    return 2;
}

s32 FindItem(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32 value = *ptrReadPos++;
    PlayerData* playerData = &gPlayerData;
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

s32 RemoveItem(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32 value = *ptrReadPos++;
    PlayerData* playerData = &gPlayerData;
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

s32 CountFortressKeys(ScriptInstance* script, s32 initialCall) {
    s32 outVar = *script->ptrReadPos;

    set_variable(script, outVar, get_fortress_key_count());
    return 2;
}

s32 RemoveFortressKeys(ScriptInstance* script, s32 initialCall) {
    s32 num = get_variable(script, *script->ptrReadPos);

    subtract_fortress_keys(num);
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, MakeItemEntity);

INCLUDE_ASM(code_fa4c0_len_3bf0, DropItemEntity);

INCLUDE_ASM(code_fa4c0_len_3bf0, DropItemEntityB);
/*
// Close to working
s32 DropItemEntityB(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32 x = get_variable(script, *ptrReadPos++);
    s32 y = get_variable(script, *ptrReadPos++);
    s32 z = get_variable(script, *ptrReadPos++);
    s32 itemSpawnMode = get_variable(script, *ptrReadPos++);
    s32 pickupFlag = get_variable(script, *ptrReadPos++);

    script->varTable[0] = make_item_entity_nodelay(itemID, x, y, z);
    set_item_entity_flags(script, 0x4000);
    return 2;
}
*/

s32 RemoveItemEntity(ScriptInstance* script, s32 initialCall) {
  s32* ptrReadPos = script->ptrReadPos;
  s32 itemEntityIndex = get_variable(script, *ptrReadPos++);

  remove_item_entity_by_index(itemEntityIndex);
  return 2;
}

s32 AddBadge(ScriptInstance* script, s32 initialCall) {
  s32* ptrReadPos = script->ptrReadPos;
  s32 itemID = get_variable(script, *ptrReadPos++);
  s32* ptrNextPos = (s32 *) *ptrReadPos++;

  set_variable(script, ptrNextPos, add_badge(itemID));
  return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveBadge);

s32 SetItemPos(ScriptInstance* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    ItemEntity* ptrItemEntity;
    s32 itemEntityIndex;
    s32 x, y, z;

    itemEntityIndex = get_variable(script, *ptrReadPos++);
    x = get_variable(script, *ptrReadPos++);
    y = get_variable(script, *ptrReadPos++);
    z = get_variable(script, *ptrReadPos++);

    ptrItemEntity = (ItemEntity *) get_item_entity(itemEntityIndex);
    ptrItemEntity->position.x = x;
    ptrItemEntity->position.y = y;
    ptrItemEntity->position.z = z;
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, SetItemFlags);

s32 AddCoin(ScriptInstance* script, s32 initialCall) {
    script->varTable[0] = add_coins(get_variable(script, *script->ptrReadPos));
    return 2;
}

s32 AddStarPoints(ScriptInstance* script, s32 initialCall) {
    script->varTable[0] = add_star_points(get_variable(script, *script->ptrReadPos));
    return 2;
}

s32 AddStarPieces(ScriptInstance* script, s32 initialCall) {
    script->varTable[0] = add_star_pieces(get_variable(script, *script->ptrReadPos));
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, GetItemPower);
/*
// Close to working
s32 GetItemPower(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32* ptrNextPos = ptrReadPos++;
    item_table_entry* item = &gItemTable[itemID];


    set_variable(script, ptrNextPos++, item->potencyA);
    set_variable(script, ptrNextPos++, item->potencyB);
    return 2;
}
*/

INCLUDE_ASM(code_fa4c0_len_3bf0, ShowGotItem);

INCLUDE_ASM(code_fa4c0_len_3bf0, func_802D7460);

INCLUDE_ASM(code_fa4c0_len_3bf0, func_802D74C0);

INCLUDE_ASM(code_fa4c0_len_3bf0, ShowEmote);

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveEffect);
/*
// Works
s32 RemoveEffect(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    remove_effect(get_variable(script, *ptrReadPos++));
    return 2;
}

// Works
s32 func_802D7B10(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32* ptrValue = get_variable(script, *ptrReadPos++);

    *ptrValue |= 0x10;
    return 2;
}

// Works
s32 func_802D7B44(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32* ptrValue = get_variable(script, *ptrReadPos++);
    s32* ptrTemp = ptrValue[3];

    ptrTemp[5] = 10;
    return 2;
}

// Works
s32 func_802D7B74(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32* ptrValue = get_variable(script, *ptrReadPos++);
    s32* ptrTemp = ptrValue[3];

    ptrTemp[11] = 5;
    return 2;
}

// More functions still in RemoveEffect.s but the ones above are matching properly
*/

INCLUDE_ASM(code_fa4c0_len_3bf0, ShowSleepBubble);

INCLUDE_ASM(code_fa4c0_len_3bf0, PlayEffect);
