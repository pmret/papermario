#include "common.h"
#include "pause/pause_common.h"
#include "hud_element.h"
#include "world/partners.h"

ApiStatus PollMusicEvents(Evt* script, s32 isInitialCall);

extern MusicEvent* MusicEventList;
extern s32 D_802DB7D4; // unused?
extern Evt* RunningMusicEvents[10];
extern s32 RunningMusicEventIDs[10];
extern s32 D_802DB828[2]; // unused?
extern PopupMenu D_802DB830;

s32 MusicEventPollCount = 0;

static EvtScript EVS_MusicEventMonitor = {
    EVT_CALL(PollMusicEvents)
    EVT_RETURN
    EVT_END
};

ApiStatus PollMusicEvents(Evt* script, s32 isInitialCall) {
    MusicEventTrigger* list;
    s32 musicEventID, scriptSelector;
    u32 count;
    s32 i;

    bgm_poll_music_events(&list, &count);

    for (i = 0; i < count; i++, list++) {
        MusicEvent* cur = MusicEventList;
        musicEventID = (*list & 0xFF0000) >> 0x10;
        scriptSelector = *list & 0xFF;
        while (cur->musicEventID != -1) {
            if (cur->musicEventID == musicEventID) {
                break;
            }
            cur++;
        }
        // @bug? can cur ever be NULL here?
        // condition should probably be if (cur->musicEventID != -1)
        if (cur != NULL) {
            EvtScript* newSource = cur->scripts[scriptSelector];
            if (RunningMusicEvents[musicEventID] != NULL) {
                kill_script_by_ID(RunningMusicEventIDs[musicEventID]);
            }
            if (newSource != NULL) {
                Evt* newEvt = start_script(newSource, EVT_PRIORITY_1, 0);
                RunningMusicEvents[musicEventID] = newEvt;
                RunningMusicEventIDs[musicEventID] = newEvt->id;
            }
        }
    }
    bgm_flush_music_events();
    MusicEventPollCount++;
    return ApiStatus_BLOCK;
}

ApiStatus RegisterMusicEvents(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 i;

    // expects a list of MusicEvent, terminated by -1 0 0 0 0
    MusicEventList = (MusicEvent*) evt_get_variable(script, *args++);

    for (i = 0; i < ARRAY_COUNT(RunningMusicEvents); i++) {
        RunningMusicEvents[i] = NULL;
        RunningMusicEventIDs[i] = 0;
    }

    start_script(&EVS_MusicEventMonitor, EVT_PRIORITY_1, 0);
    return ApiStatus_DONE2;
}

ApiStatus FadeOutMusic(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 musicPlayer = evt_get_variable(script, *args++);
    s32 fadeTime = evt_get_variable(script, *args++);

    if (bgm_set_song(musicPlayer, -1, 0, fadeTime, 8)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus SetMusicTrack(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 musicPlayer = evt_get_variable(script, *args++);
    s32 songID = evt_get_variable(script, *args++);
    s32 variation = evt_get_variable(script, *args++);
    s16 volume = evt_get_variable(script, *args++);

    if (bgm_set_song(musicPlayer, songID, variation, 500, volume)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus FadeInMusic(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 musicPlayer = evt_get_variable(script, *args++);
    s32 songID = evt_get_variable(script, *args++);
    s32 variation = evt_get_variable(script, *args++);
    s32 fadeTime = evt_get_variable(script, *args++);
    s16 fadeStartVolume = evt_get_variable(script, *args++);
    s16 fadeEndVolume = evt_get_variable(script, *args++);

    if (func_8014A964(musicPlayer, songID, variation, fadeTime, fadeStartVolume, fadeEndVolume)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus EnableMusicProximityMix(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 playerIndex = evt_get_variable(script, *args++);

    gMusicSettings[playerIndex].flags |= MUSIC_SETTINGS_FLAG_ENABLE_PROXIMITY_MIX;
    return ApiStatus_DONE2;
}

ApiStatus AdjustMusicProximityMix(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 playerIndex = evt_get_variable(script, *args++);
    s32 mix = evt_get_variable(script, *args++);
    s32 state = evt_get_variable(script, *args++);

    bgm_adjust_proximity(playerIndex, mix, state);
    return ApiStatus_DONE2;
}

ApiStatus SetMusicTrackVolumes(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s16 trackVolSet = evt_get_variable(script, *args++);

    bgm_set_track_volumes(0, trackVolSet);
    return ApiStatus_DONE2;
}

ApiStatus PopSong(Evt* script, s32 isInitialCall) {
    bgm_pop_song();
    return ApiStatus_DONE2;
}

ApiStatus PushSong(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 songID = evt_get_variable(script, *args++);
    s32 variation = evt_get_variable(script, *args++);

    bgm_push_song(songID, variation);
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
    s32 songID = evt_get_variable(script, *args++);
    s32 variation = evt_get_variable(script, *args++);

    bgm_set_battle_song(songID, variation);
    return ApiStatus_DONE2;
}

ApiStatus ClearAmbientSounds(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 time = evt_get_variable(script, *args++);

    if (play_ambient_sounds(-1, time)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus PlayAmbientSounds(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);

    if (play_ambient_sounds(soundID, 250)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
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
    s32 volume = evt_get_variable(script, *args++);

    sfx_play_sound_with_params(soundID, volume, 0, 0);
    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAt(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);
    s32 flags = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    sfx_play_sound_at_position(soundID, flags, x, y, z);
    return ApiStatus_DONE2;
}

ApiStatus StopSound(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);

    sfx_stop_sound(soundID);
    return ApiStatus_DONE2;
}

ApiStatus func_802D62E4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);

    snd_stop_tracking_env_sound_pos(soundID, TRUE);
    return ApiStatus_DONE2;
}

ApiStatus UseDoorSounds(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gCurrentDoorSounds = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus UseRoomDoorSounds(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gCurrentRoomDoorSounds = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtF(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode soundID = *args++;
    u16 spatializationFlags = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    sfx_play_sound_at_position(soundID, spatializationFlags, x, y, z);
    return ApiStatus_DONE2;
}

ApiStatus ShowKeyChoicePopup(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PopupMenu* menu = &D_802DB830;
    Trigger* trigger = script->owner2.trigger;
    s32 numEntries;
    s32 t; // TODO required in both places to match
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    t = script->functionTemp[0];
    switch (t) {
        case 0:
            disable_player_input();
            disable_player_static_collisions();
            partner_disable_input();
            close_status_bar();
            numEntries = 0;

            gOverrideFlags |= GLOBAL_OVERRIDES_40;

            for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
                s16 invItem = playerData->keyItems[i];

                if (invItem != ITEM_NONE) {
                    s32 found = FALSE;
                    s32* itemIt = trigger->itemList;

                    while (*itemIt > 0) {
                        if (invItem == *itemIt) {
                            found = TRUE;
                            break;
                        }
                        itemIt++;
                    }

                    if (found) {
                        ItemData* item = &gItemTable[playerData->keyItems[i]];

                        menu->ptrIcon[numEntries] = gItemHudScripts[item->hudElemID].enabled;
                        menu->userIndex[numEntries] = i;
                        menu->enabled[numEntries] = TRUE;
                        menu->nameMsg[numEntries] = item->nameMsg;
                        menu->descMsg[numEntries] = item->shortDescMsg;
                        numEntries++;
                    }
                }
            }

            if (numEntries == 0) {
                script->varTable[0] = 0;
                return ApiStatus_DONE1;
            }
            menu->popupType = POPUP_MENU_USEKEY;
            menu->numEntries = numEntries;
            menu->initialPos = 0;
            create_standard_popup_menu(menu);
            script->functionTemp[1] = 0;
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (script->functionTemp[1] == 0) {
                script->functionTemp[2] = menu->result;
                if (script->functionTemp[2] == 0) {
                    break;
                }
                hide_popup_menu();
            }

            script->functionTemp[1]++;
            if (script->functionTemp[1] >= 15) {
                destroy_popup_menu();

                if (script->functionTemp[2] == 0xFF) {
                    script->varTable[0] = -1;
                    return ApiStatus_DONE1;
                } else {
                    t = menu->userIndex[script->functionTemp[2] - 1];

                    script->varTable[1] = t;
                    script->varTable[0] = playerData->keyItems[t];
                    return ApiStatus_DONE1;
                }
            }
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus ShowConsumableChoicePopup(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PopupMenu* menu = &D_802DB830;
    Trigger* trigger = script->owner2.trigger;
    s32 numEntries;
    s32 t; // TODO required in both places to match
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    t = script->functionTemp[0];
    switch (t) {
        case 0:
            disable_player_input();
            disable_player_static_collisions();
            partner_disable_input();
            close_status_bar();
            numEntries = 0;

            gOverrideFlags |= GLOBAL_OVERRIDES_40;

            for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
                s16 invItem = playerData->invItems[i];

                if (invItem != ITEM_NONE) {
                    s32 found = FALSE;
                    s32* itemIt = trigger->itemList;

                    while (*itemIt > 0) {
                        if (invItem == *itemIt) {
                            found = TRUE;
                            break;
                        }
                        itemIt++;
                    }

                    if (found) {
                        ItemData* item = &gItemTable[playerData->invItems[i]];

                        menu->ptrIcon[numEntries] = gItemHudScripts[item->hudElemID].enabled;
                        menu->userIndex[numEntries] = i;
                        menu->enabled[numEntries] = TRUE;
                        menu->nameMsg[numEntries] = item->nameMsg;
                        menu->descMsg[numEntries] = item->shortDescMsg;
                        numEntries++;
                    }
                }
            }

            if (numEntries == 0) {
                script->varTable[0] = 0;
                return ApiStatus_DONE1;
            }
            menu->popupType = POPUP_MENU_USEKEY;
            menu->numEntries = numEntries;
            menu->initialPos = 0;
            create_standard_popup_menu(menu);
            script->functionTemp[1] = 0;
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (script->functionTemp[1] == 0) {
                script->functionTemp[2] = menu->result;
                if (script->functionTemp[2] == 0) {
                    break;
                }
                hide_popup_menu();
            }

            script->functionTemp[1]++;
            if (script->functionTemp[1] >= 15) {
                destroy_popup_menu();

                if (script->functionTemp[2] == 0xFF) {
                    script->varTable[0] = -1;
                    return ApiStatus_DONE1;
                } else {
                    t = menu->userIndex[script->functionTemp[2] - 1];

                    script->varTable[1] = t;
                    script->varTable[0] = playerData->invItems[t];
                    return ApiStatus_DONE1;
                }
            }
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus RemoveKeyItemAt(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s16* ptrKeyItems = gPlayerData.keyItems;

    ptrKeyItems[index] = ITEM_NONE;
    return ApiStatus_DONE2;
}

ApiStatus RemoveItemAt(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s16* ptrInvItems = gPlayerData.invItems;

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

    if (itemID == ITEM_KOOPA_FORTRESS_KEY) {
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
    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
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

ApiStatus DropResizableItemEntity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 itemSpawnMode = evt_get_variable(script, *args++);
    s32 pickupVar = evt_get_variable_index(script, *args++);

    script->varTable[0] = make_item_entity_nodelay(itemID, x, y, z, itemSpawnMode, pickupVar);
    set_item_entity_flags(script->varTable[0], ITEM_ENTITY_RESIZABLE);
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
    ptrItemEntity->pos.x = x;
    ptrItemEntity->pos.y = y;
    ptrItemEntity->pos.z = z;
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

ApiStatus SetItemAlpha(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemEntityIndex = evt_get_variable(script, *args++);
    s32 alpha = evt_get_variable(script, *args++);
    ItemEntity* itemEntity = get_item_entity(itemEntityIndex);

    itemEntity->alpha = alpha;
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
    s32 itemID, category, pickupMsgFlags;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            itemID = evt_get_variable(script, *args++);
            category = evt_get_variable(script, *args++);
            pickupMsgFlags = *args++;
            script->functionTemp[1] = make_item_entity_at_player(itemID, category, pickupMsgFlags);
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (get_item_entity(script->functionTemp[1]) == NULL) {
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}
