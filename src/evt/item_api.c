#include "common.h"
#include "pause/pause_common.h"
#include "hud_element.h"
#include "world/partners.h"

extern PopupMenu D_802DB830;

API_CALLABLE(ShowKeyChoicePopup) {
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

API_CALLABLE(ShowConsumableChoicePopup) {
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

API_CALLABLE(RemoveKeyItemAt) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s16* ptrKeyItems = gPlayerData.keyItems;

    ptrKeyItems[index] = ITEM_NONE;
    return ApiStatus_DONE2;
}

API_CALLABLE(RemoveItemAt) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s16* ptrInvItems = gPlayerData.invItems;

    ptrInvItems[index] = ITEM_NONE;
    sort_items();
    return ApiStatus_DONE2;
}

API_CALLABLE(AddKeyItem) {
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

API_CALLABLE(CloseChoicePopup) {
    enable_player_input();
    enable_player_static_collisions();
    partner_enable_input();
    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
    return ApiStatus_DONE2;
}

API_CALLABLE(HasKeyItem) {
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

API_CALLABLE(FindKeyItem) {
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

API_CALLABLE(AddItem) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    Bytecode outItemIdx = *args++;

    evt_set_variable(script, outItemIdx, add_item(itemID));
    return ApiStatus_DONE2;
}

API_CALLABLE(ClearVariable) {
    evt_set_variable(script, *script->ptrReadPos, 0);
    return ApiStatus_DONE2;
}

API_CALLABLE(FindItem) {
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

API_CALLABLE(RemoveItem) {
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

API_CALLABLE(CountFortessKeys) {
    s32 outVar = *script->ptrReadPos;

    evt_set_variable(script, outVar, get_fortress_key_count());
    return ApiStatus_DONE2;
}

API_CALLABLE(RemoveFortressKeys) {
    s32 num = evt_get_variable(script, *script->ptrReadPos);

    subtract_fortress_keys(num);
    return ApiStatus_DONE2;
}

API_CALLABLE(MakeItemEntity) {
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

API_CALLABLE(DropItemEntity) {
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

API_CALLABLE(DropResizableItemEntity) {
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

API_CALLABLE(RemoveItemEntity) {
    Bytecode* args = script->ptrReadPos;
    s32 itemEntityIndex = evt_get_variable(script, *args++);

    remove_item_entity_by_index(itemEntityIndex);
    return ApiStatus_DONE2;
}

API_CALLABLE(AddBadge) {
    Bytecode* args = script->ptrReadPos;
    s32 badgeID = evt_get_variable(script, *args++);
    Bytecode outBadgeIdx = *args++;

    evt_set_variable(script, outBadgeIdx, add_badge(badgeID));
    return ApiStatus_DONE2;
}

API_CALLABLE(RemoveBadge) {
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

API_CALLABLE(SetItemPos) {
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

API_CALLABLE(SetItemFlags) {
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

API_CALLABLE(SetItemAlpha) {
    Bytecode* args = script->ptrReadPos;
    s32 itemEntityIndex = evt_get_variable(script, *args++);
    s32 alpha = evt_get_variable(script, *args++);
    ItemEntity* itemEntity = get_item_entity(itemEntityIndex);

    itemEntity->alpha = alpha;
    return ApiStatus_DONE2;
}

API_CALLABLE(AddCoin) {
    script->varTable[0] = add_coins(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

API_CALLABLE(AddStarPoints) {
    script->varTable[0] = add_star_points(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

API_CALLABLE(AddStarPieces) {
    script->varTable[0] = add_star_pieces(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

API_CALLABLE(GetItemPower) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = evt_get_variable(script, *args++);
    Bytecode out1 = *args++;
    Bytecode out2 = *args++;

    evt_set_variable(script, out1, (&gItemTable[itemIdx])->potencyA);
    evt_set_variable(script, out2, (&gItemTable[itemIdx])->potencyB);
    return ApiStatus_DONE2;
}

API_CALLABLE(ShowGotItem) {
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
