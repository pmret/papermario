#include "common.h"

INCLUDE_ASM(s32, "code_fa4c0_len_3bf0", func_802D5B10);

INCLUDE_ASM(s32, "code_fa4c0_len_3bf0", func_802D5C70);

ApiStatus FadeOutMusic(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = get_variable(script, *args++);
    s32* ptrNextPos = args++;

    return (bgm_set_song(itemID, -1, 0, get_variable(script, *ptrNextPos++), 8) != 0) * ApiStatus_DONE2;
}

ApiStatus SetMusicTrack(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 musicPlayer = get_variable(script, *args++);
    s32 songID = get_variable(script, *args++);
    s32 variation = get_variable(script, *args++);
    s16 volume = get_variable(script, *args++);

    return (bgm_set_song(musicPlayer, songID, variation, 0x1F4, volume) != 0) * ApiStatus_DONE2;
}

ApiStatus FadeInMusic(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s16 var4 = get_variable(script, *args++);
    s16 var5 = get_variable(script, *args++);

    return (func_8014A964(var0, var1, var2, var3, var4, var5) != 0) * ApiStatus_DONE2;
}

ApiStatus func_802D5EE0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    MusicSettings* musicPlayers = gMusicPlayers;

    (&musicPlayers[get_variable(script, *args++)])->flags |= 0x2;
    return ApiStatus_DONE2;
}

ApiStatus func_802D5F28(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    func_8014AA54(get_variable(script, *args++), get_variable(script, *args++), (s16)get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802D5FA4(ScriptInstance* script, s32 isInitialCall) {
    func_8014AB0C(0, (s16)get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_802D5FD8(ScriptInstance* script, s32 isInitialCall) {
    bgm_pop_song();
    return ApiStatus_DONE2;
}

ApiStatus func_802D5FF8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    bgm_push_song(get_variable(script, *args++), get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802D6050(ScriptInstance* script, s32 isInitialCall) {
    bgm_pop_battle_song();
    return ApiStatus_DONE2;
}

ApiStatus func_802D6070(ScriptInstance* script, s32 isInitialCall) {
    bgm_push_battle_song();
    return ApiStatus_DONE2;
}

ApiStatus func_802D6090(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    bgm_set_battle_song(get_variable(script, *args++), get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus ClearAmbientSounds(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 flags = get_variable(script, *args++);

    return (play_ambient_sounds(-1, flags) != 0) * ApiStatus_DONE2;
}

ApiStatus PlayAmbientSounds(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = get_variable(script, *args++);

    return (play_ambient_sounds(soundID, 0xFA) != 0) * ApiStatus_DONE2;
}

ApiStatus PlaySound(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = get_variable(script, *args++);

    sfx_play_sound(soundID);
    return ApiStatus_DONE2;
}

ApiStatus func_802D617C(ScriptInstance* script, s32 initialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = get_variable(script, *args++);
    s32 value2 = get_variable(script, *args++);

    sfx_play_sound_with_params(soundID, value2 & 0xFF, 0, 0);
    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAt(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = get_variable(script, *args++);
    s32 value2 = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s32 z = get_variable(script, *args++);

    sfx_play_sound_at_position(soundID, value2, x, y, z);
    return ApiStatus_DONE2;
}

ApiStatus StopSound(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    sfx_stop_sound(get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802D62E4(ScriptInstance* script, s32 initialCall) {
    Bytecode* args = script->ptrReadPos;

    func_80149A6C(get_variable(script, *args++), 1);
    return ApiStatus_DONE2;
}

ApiStatus UseDoorSounds(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gCurrentDoorSoundsSet = get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802D6340(ScriptInstance* script, s32 initialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80151308 = get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtF(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode soundID = *args++;
    u16 value2 = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    sfx_play_sound_at_position(soundID, value2, x, y, z);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_fa4c0_len_3bf0", func_802D6420);

INCLUDE_ASM(s32, "code_fa4c0_len_3bf0", func_802D663C);

ApiStatus RemoveKeyItemAt(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s16* ptrKeyItems = (s16*) &gPlayerData.keyItems;

    ptrKeyItems[index] = 0;
    return ApiStatus_DONE2;
}

ApiStatus RemoveItemAt(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s16* ptrInvItems = (s16*) &gPlayerData.invItems;

    ptrInvItems[index] = 0;
    sort_items();
    return ApiStatus_DONE2;
}

ApiStatus AddKeyItem(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 value = *args++;
    PlayerData* playerData = &gPlayerData;
    s32 itemID = get_variable(script, value);
    s32 i;

    if (itemID == ITEM_FORTRESS_KEY) {
        playerData->fortressKeyCount++;
        return ApiStatus_DONE2;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
        if (playerData->keyItems[i] == 0) {
            break;
        }
    }

    if (i < ARRAY_COUNT(playerData->keyItems)) {
        playerData->keyItems[i] = itemID;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802D6954(ScriptInstance* script, s32 isInitialCall) {
    enable_player_input();
    enable_player_static_collisions();
    func_800EF600();
    OVERRIDE_FLAG_UNSET(0x40);
    return ApiStatus_DONE2;
}

ApiStatus HasKeyItem(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = get_variable(script, *args++);
    s32 value = *args++;
    PlayerData* playerData = &gPlayerData;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
        if (playerData->keyItems[i] == itemID) {
            break;
        }
    }
    set_variable(script, value, i < ARRAY_COUNT(playerData->keyItems));
    return ApiStatus_DONE2;
}

ApiStatus FindKeyItem(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = get_variable(script, *args++);
    s32 value = *args++;
    PlayerData* playerData = &gPlayerData;
    s32 i;
    s32 itemIndex;

    for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
        if (playerData->keyItems[i] == itemID) {
            break;
        }
    }

    itemIndex = -1;
    if (i != ARRAY_COUNT(playerData->keyItems)) {
        itemIndex = i;
    }

    set_variable(script, value, itemIndex);
    return ApiStatus_DONE2;
}

ApiStatus AddItem(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = get_variable(script, *args++);
    Bytecode outItemIdx = *args++;

    set_variable(script, outItemIdx, add_item(itemID));
    return ApiStatus_DONE2;
}

ApiStatus func_802D6AF0(ScriptInstance* script, s32 initialCall) {
    set_variable(script, *script->ptrReadPos, 0);
    return ApiStatus_DONE2;
}

ApiStatus FindItem(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = get_variable(script, *args++);
    s32 value = *args++;
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
    return ApiStatus_DONE2;
}

ApiStatus RemoveItem(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = get_variable(script, *args++);
    s32 value = *args++;
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
    return ApiStatus_DONE2;
}

ApiStatus CountFortressKeys(ScriptInstance* script, s32 isInitialCall) {
    s32 outVar = *script->ptrReadPos;

    set_variable(script, outVar, get_fortress_key_count());
    return ApiStatus_DONE2;
}

ApiStatus RemoveFortressKeys(ScriptInstance* script, s32 isInitialCall) {
    s32 num = get_variable(script, *script->ptrReadPos);

    subtract_fortress_keys(num);
    return ApiStatus_DONE2;
}

ApiStatus MakeItemEntity(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s32 z = get_variable(script, *args++);
    s32 itemSpawnMode = get_variable(script, *args++);
    s32 pickupVar = get_variable_index(script, *args++);

    script->varTable[0] = make_item_entity_nodelay(itemID, x, y, z, itemSpawnMode, pickupVar);
    return ApiStatus_DONE2;
}

ApiStatus DropItemEntity(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s32 z = get_variable(script, *args++);
    s32 itemSpawnMode = get_variable(script, *args++);
    s32 pickupVar = get_variable(script, *args++);

    script->varTable[0] = make_item_entity_nodelay(itemID, x, y, z, itemSpawnMode, pickupVar);
    return ApiStatus_DONE2;
}

ApiStatus DropItemEntityB(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s32 z = get_variable(script, *args++);
    s32 itemSpawnMode = get_variable(script, *args++);
    s32 pickupVar = get_variable_index(script, *args++);

    script->varTable[0] = make_item_entity_nodelay(itemID, x, y, z, itemSpawnMode, pickupVar);
    set_item_entity_flags(script->varTable[0], 0x4000);
    return ApiStatus_DONE2;
}

ApiStatus RemoveItemEntity(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemEntityIndex = get_variable(script, *args++);

    remove_item_entity_by_index(itemEntityIndex);
    return ApiStatus_DONE2;
}

ApiStatus AddBadge(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 badgeID = get_variable(script, *args++);
    Bytecode outBadgeIdx = *args++;

    set_variable(script, outBadgeIdx, add_badge(badgeID));
    return ApiStatus_DONE2;
}

ApiStatus RemoveBadge(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerData* playerData = &gPlayerData;
    s32 badge = get_variable(script, *args++);
    s32 i;

    for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
        if (playerData->badges[i] == badge) {
            playerData->badges[i] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
        if (playerData->equippedBadges[i] == badge) {
            playerData->equippedBadges[i] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus SetItemPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ItemEntity* ptrItemEntity;
    s32 itemEntityIndex;
    s32 x, y, z;

    itemEntityIndex = get_variable(script, *args++);
    x = get_variable(script, *args++);
    y = get_variable(script, *args++);
    z = get_variable(script, *args++);

    ptrItemEntity = (ItemEntity*) get_item_entity(itemEntityIndex);
    ptrItemEntity->position.x = x;
    ptrItemEntity->position.y = y;
    ptrItemEntity->position.z = z;
    return ApiStatus_DONE2;
}

ApiStatus SetItemFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemEntityIndex = get_variable(script, *args++);
    s32 flagBits = *args++;
    s32 var2 = get_variable(script, *args++);
    ItemEntity* itemEntity = get_item_entity(itemEntityIndex);

    if (var2 != 0) {
        itemEntity->flags |= flagBits;
    } else {
        itemEntity->flags &= ~flagBits;
    }
    return ApiStatus_DONE2;
}
;
ApiStatus func_802D721C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemEntityIndex = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    ItemEntity* itemEntity = get_item_entity(itemEntityIndex);

    itemEntity->unk_2F = var2;
    return ApiStatus_DONE2;
}

ApiStatus AddCoin(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = add_coins(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus AddStarPoints(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = add_star_points(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus AddStarPieces(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = add_star_pieces(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus GetItemPower(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = get_variable(script, *args++);
    Bytecode out1 = *args++;
    Bytecode out2 = *args++;

    set_variable(script, out1, (&gItemTable[itemIdx])->potencyA);
    set_variable(script, out2, (&gItemTable[itemIdx])->potencyB);
    return ApiStatus_DONE2;
}

ApiStatus ShowGotItem(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            script->functionTemp[1].s = init_got_item(get_variable(script, *args++), get_variable(script, *args++), *args++);
            script->functionTemp[0].s = 1;
            break;
        case 1:
            if (get_item_entity(script->functionTemp[1].s) == NULL) {
                return ApiStatus_DONE2;
            }
    }
    return ApiStatus_BLOCK;
}
