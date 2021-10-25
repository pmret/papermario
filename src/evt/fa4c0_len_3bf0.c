#include "common.h"

extern Bytecode D_802D9D34[0];
extern s32 D_802DB7D0;
extern s32 D_802DB7D8[10];
extern s32 D_802DB800[10];
s32 func_802D5B10();

s32 D_802D9D30 = 0;

EvtSource D_802D9D34 = {
    EVT_CALL(func_802D5B10)
    EVT_RETURN
    EVT_END
};

INCLUDE_ASM(s32, "evt/fa4c0_len_3bf0", func_802D5B10);

ApiStatus func_802D5C70(Evt* script) {
    s32 i;

    D_802DB7D0 = evt_get_variable(script, *script->ptrReadPos);

    for (i = 0; i < ARRAY_COUNT(D_802DB7D8); i++) {
        D_802DB7D8[i] = 0;
        D_802DB800[i] = 0;
    }

    start_script(&D_802D9D34, 1, 0);
    return ApiStatus_DONE2;
}

ApiStatus FadeOutMusic(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    s32* ptrNextPos = args++;

    return (bgm_set_song(itemID, -1, 0, evt_get_variable(script, *ptrNextPos++), 8) != 0) * ApiStatus_DONE2;
}

ApiStatus SetMusicTrack(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 musicPlayer = evt_get_variable(script, *args++);
    s32 songID = evt_get_variable(script, *args++);
    s32 variation = evt_get_variable(script, *args++);
    s16 volume = evt_get_variable(script, *args++);

    return (bgm_set_song(musicPlayer, songID, variation, 0x1F4, volume) != 0) * ApiStatus_DONE2;
}

ApiStatus FadeInMusic(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s16 var4 = evt_get_variable(script, *args++);
    s16 var5 = evt_get_variable(script, *args++);

    return (func_8014A964(var0, var1, var2, var3, var4, var5) != 0) * ApiStatus_DONE2;
}

ApiStatus func_802D5EE0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    MusicSettings* musicSettings = gMusicSettings;

    (&musicSettings[evt_get_variable(script, *args++)])->flags |= 0x2;
    return ApiStatus_DONE2;
}

ApiStatus func_802D5F28(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    func_8014AA54(evt_get_variable(script, *args++), evt_get_variable(script, *args++), (s16)evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802D5FA4(Evt* script, s32 isInitialCall) {
    func_8014AB0C(0, (s16)evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus PopSong(Evt* script, s32 isInitialCall) {
    bgm_pop_song();
    return ApiStatus_DONE2;
}

ApiStatus PushSong(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    bgm_push_song(evt_get_variable(script, *args++), evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus PopBattleSong(Evt* script, s32 isInitialCall) {
    bgm_pop_battle_song();
    return ApiStatus_DONE2;
}

ApiStatus PushBattleSong(Evt* script, s32 isInitialCall) {
    bgm_push_battle_song();
    return ApiStatus_DONE2;
}

ApiStatus SetBattleSong(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    bgm_set_battle_song(evt_get_variable(script, *args++), evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus ClearAmbientSounds(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 flags = evt_get_variable(script, *args++);

    return (play_ambient_sounds(-1, flags) != 0) * ApiStatus_DONE2;
}

ApiStatus PlayAmbientSounds(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);

    return (play_ambient_sounds(soundID, 0xFA) != 0) * ApiStatus_DONE2;
}

ApiStatus PlaySound(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);

    sfx_play_sound(soundID);
    return ApiStatus_DONE2;
}

ApiStatus PlaySoundWithVolume(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);
    s32 value2 = evt_get_variable(script, *args++);

    sfx_play_sound_with_params(soundID, value2 & 0xFF, 0, 0);
    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAt(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);
    s32 value2 = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    sfx_play_sound_at_position(soundID, value2, x, y, z);
    return ApiStatus_DONE2;
}

ApiStatus StopSound(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    sfx_stop_sound(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802D62E4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    func_80149A6C(evt_get_variable(script, *args++), 1);
    return ApiStatus_DONE2;
}

ApiStatus UseDoorSounds(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gCurrentDoorSoundsSet = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus UseAdvancedDoorSounds(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80151308 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtF(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode soundID = *args++;
    u16 value2 = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    sfx_play_sound_at_position(soundID, value2, x, y, z);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(ApiStatus, "evt/fa4c0_len_3bf0", ShowKeyChoicePopup, Evt* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "evt/fa4c0_len_3bf0", ShowConsumableChoicePopup, Evt* script, s32 isInitialCall);

// TODO: probably a split here (sound_api, item_api)

ApiStatus RemoveKeyItemAt(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s16* ptrKeyItems = &gPlayerData.keyItems;

    ptrKeyItems[index] = ITEM_NONE;
    return ApiStatus_DONE2;
}

ApiStatus RemoveItemAt(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s16* ptrInvItems = &gPlayerData.invItems;

    ptrInvItems[index] = ITEM_NONE;
    sort_items();
    return ApiStatus_DONE2;
}

ApiStatus AddKeyItem(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 value = *args++;
    PlayerData* playerData = &gPlayerData;
    s32 itemID = evt_get_variable(script, value);
    s32 i;

    if (itemID == ITEM_FORTRESS_KEY) {
        playerData->fortressKeyCount++;
        return ApiStatus_DONE2;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
        if (playerData->keyItems[i] == ITEM_NONE) {
            break;
        }
    }

    if (i < ARRAY_COUNT(playerData->keyItems)) {
        playerData->keyItems[i] = itemID;
    }
    return ApiStatus_DONE2;
}

ApiStatus CloseChoicePopup(Evt* script, s32 isInitialCall) {
    enable_player_input();
    enable_player_static_collisions();
    partner_enable_input();
    gOverrideFlags &= ~0x40;
    return ApiStatus_DONE2;
}

ApiStatus HasKeyItem(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    s32 value = *args++;
    PlayerData* playerData = &gPlayerData;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
        if (playerData->keyItems[i] == itemID) {
            break;
        }
    }
    evt_set_variable(script, value, i < ARRAY_COUNT(playerData->keyItems));
    return ApiStatus_DONE2;
}

ApiStatus FindKeyItem(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
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

    evt_set_variable(script, value, itemIndex);
    return ApiStatus_DONE2;
}

ApiStatus AddItem(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    Bytecode outItemIdx = *args++;

    evt_set_variable(script, outItemIdx, add_item(itemID));
    return ApiStatus_DONE2;
}

ApiStatus ClearVariable(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, 0);
    return ApiStatus_DONE2;
}

ApiStatus FindItem(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
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

    evt_set_variable(script, value, itemIndex);
    return ApiStatus_DONE2;
}

ApiStatus RemoveItem(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
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
        *(playerData->invItems + i) = ITEM_NONE;
    }
    sort_items();

    evt_set_variable(script, value, itemIndex);
    return ApiStatus_DONE2;
}

ApiStatus CountFortessKeys(Evt* script, s32 isInitialCall) {
    s32 outVar = *script->ptrReadPos;

    evt_set_variable(script, outVar, get_fortress_key_count());
    return ApiStatus_DONE2;
}

ApiStatus RemoveFortressKeys(Evt* script, s32 isInitialCall) {
    s32 num = evt_get_variable(script, *script->ptrReadPos);

    subtract_fortress_keys(num);
    return ApiStatus_DONE2;
}

ApiStatus MakeItemEntity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 itemSpawnMode = evt_get_variable(script, *args++);
    s32 pickupVar = evt_get_variable_index(script, *args++);

    script->varTable[0] = make_item_entity_nodelay(itemID, x, y, z, itemSpawnMode, pickupVar);
    return ApiStatus_DONE2;
}

ApiStatus DropItemEntity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 itemSpawnMode = evt_get_variable(script, *args++);
    s32 pickupVar = evt_get_variable(script, *args++);

    script->varTable[0] = make_item_entity_nodelay(itemID, x, y, z, itemSpawnMode, pickupVar);
    return ApiStatus_DONE2;
}

ApiStatus DropItemEntityB(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 itemSpawnMode = evt_get_variable(script, *args++);
    s32 pickupVar = evt_get_variable_index(script, *args++);

    script->varTable[0] = make_item_entity_nodelay(itemID, x, y, z, itemSpawnMode, pickupVar);
    set_item_entity_flags(script->varTable[0], 0x4000);
    return ApiStatus_DONE2;
}

ApiStatus RemoveItemEntity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemEntityIndex = evt_get_variable(script, *args++);

    remove_item_entity_by_index(itemEntityIndex);
    return ApiStatus_DONE2;
}

ApiStatus AddBadge(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 badgeID = evt_get_variable(script, *args++);
    Bytecode outBadgeIdx = *args++;

    evt_set_variable(script, outBadgeIdx, add_badge(badgeID));
    return ApiStatus_DONE2;
}

ApiStatus RemoveBadge(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerData* playerData = &gPlayerData;
    s32 badge = evt_get_variable(script, *args++);
    s32 i;

    for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
        if (playerData->badges[i] == badge) {
            playerData->badges[i] = ITEM_NONE;
        }
    }

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
        if (playerData->equippedBadges[i] == badge) {
            playerData->equippedBadges[i] = ITEM_NONE;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus SetItemPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ItemEntity* ptrItemEntity;
    s32 itemEntityIndex;
    s32 x, y, z;

    itemEntityIndex = evt_get_variable(script, *args++);
    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);

    ptrItemEntity = (ItemEntity*) get_item_entity(itemEntityIndex);
    ptrItemEntity->position.x = x;
    ptrItemEntity->position.y = y;
    ptrItemEntity->position.z = z;
    return ApiStatus_DONE2;
}

ApiStatus SetItemFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemEntityIndex = evt_get_variable(script, *args++);
    s32 flagBits = *args++;
    s32 var2 = evt_get_variable(script, *args++);
    ItemEntity* itemEntity = get_item_entity(itemEntityIndex);

    if (var2 != 0) {
        itemEntity->flags |= flagBits;
    } else {
        itemEntity->flags &= ~flagBits;
    }
    return ApiStatus_DONE2;
}
;
ApiStatus SetItemAlpha(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemEntityIndex = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    ItemEntity* itemEntity = get_item_entity(itemEntityIndex);

    itemEntity->unk_2F = var2;
    return ApiStatus_DONE2;
}

ApiStatus AddCoin(Evt* script, s32 isInitialCall) {
    script->varTable[0] = add_coins(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus AddStarPoints(Evt* script, s32 isInitialCall) {
    script->varTable[0] = add_star_points(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus AddStarPieces(Evt* script, s32 isInitialCall) {
    script->varTable[0] = add_star_pieces(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus GetItemPower(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = evt_get_variable(script, *args++);
    Bytecode out1 = *args++;
    Bytecode out2 = *args++;

    evt_set_variable(script, out1, (&gItemTable[itemIdx])->potencyA);
    evt_set_variable(script, out2, (&gItemTable[itemIdx])->potencyB);
    return ApiStatus_DONE2;
}

ApiStatus ShowGotItem(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            script->functionTemp[1] = init_got_item(evt_get_variable(script, *args++), evt_get_variable(script, *args++), *args++);
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (get_item_entity(script->functionTemp[1]) == NULL) {
                return ApiStatus_DONE2;
            }
    }
    return ApiStatus_BLOCK;
}
