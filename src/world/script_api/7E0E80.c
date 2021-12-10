#include "common.h"
#include "hud_element.h"
#include "model.h"

extern s32 MessagePlural;
extern s32 MessageSingular;
extern MessagePrintState* D_80286528;
extern MessagePrintState* D_80286538;

extern s32 D_80286520;
extern s32 D_80286524;
extern s32 D_80286530;
extern s32 D_80286534;
extern s8 D_8008F072[];
extern Evt* D_8028652C;
extern HudElementAnim* D_80080868;
extern s32 D_8014F150[64];

ApiStatus func_802803C8(Evt* script, s32 isInitialCall);
ApiStatus func_80280410(Evt* script, s32 isInitialCall);
ApiStatus ShowShopPurchaseDialog(Evt* script, s32 isInitialCall);
ApiStatus ShowShopOwnerDialog(Evt* script, s32 isInitialCall);

s32 ShopBeginSpeech[] = { 0x00000043, 0x00000006, SpeakToPlayer, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000000, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 ShopContinueSpeech[] = { 0x00000043, 0x00000006, ContinueSpeech, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000000, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 ShopResetSpeech[] = { 0x00000043, 0x00000005, EndSpeech, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000000, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 ShopEndSpeech[] = { 0x00000043, 0x00000005, EndSpeech, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 D_80283F58_7E4DD8[] = { 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000002, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000003, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000001, func_802803C8, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, func_80280410, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 BadgeShopInteract[] = { 0x00000043, 0x00000002, ShowShopPurchaseDialog, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000001, ShowShopOwnerDialog, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 shop_owner_begin_speech(s32 messageIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopMsgID = shop->owner->shopMsgIDs[messageIndex];
    Evt* script = start_script(&ShopBeginSpeech, 1, 0);

    script->varTable[0] = shopMsgID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_buy_dialog(s32 messageIndex, s32 itemName, s32 coinCost, s32 bpCost) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopMsgID = shop->owner->shopMsgIDs[messageIndex];
    Evt* script;
    s32 phi_a0;

    set_message_msg(itemName, 0);
    set_message_value(coinCost, 1);

    if (bpCost > 0) {
        set_message_value(bpCost, 2);
    } else {
        if (coinCost == 1) {
            phi_a0 = &MessageSingular;
        } else {
            phi_a0 = &MessagePlural;
        }
        set_message_msg(phi_a0, 2);
    }

    script = start_script(&ShopBeginSpeech, 1, 0);
    script->varTable[0] = shopMsgID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_continue_speech(s32 messageIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopMsgID = shop->owner->shopMsgIDs[messageIndex];
    Evt* script = start_script(&ShopContinueSpeech, 1, 0);

    script->varTable[0] = shopMsgID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->functionTemp[3] = script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_continue_speech_with_quantity(s32 messageIndex, s32 amount) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopMsgID = shop->owner->shopMsgIDs[messageIndex];
    s32 phi_a0;
    Evt* script;

    set_message_value(amount, 0);

    if (amount == 1) {
        phi_a0 = &MessageSingular;
    } else {
        phi_a0 = &MessagePlural;
    }

    set_message_msg(phi_a0, 1);

    script = start_script(&ShopContinueSpeech, 1, 0);
    script->varTable[0] = shopMsgID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->functionTemp[3] = script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_reset_speech(s32 messageIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopMsgID = shop->owner->shopMsgIDs[messageIndex];
    Evt* script = start_script(&ShopResetSpeech, 1, 0);

    script->varTable[0] = shopMsgID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->functionTemp[3] = script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_end_speech(void) {
    Shop* shop = gGameStatusPtr->mapShop;
    Evt* script = start_script(&ShopEndSpeech, 1, 0);

    script->varTable[0] = shop->owner->npcID;
    script->varTable[1] = shop->owner->talkAnim;
    script->functionTemp[3] = script->varTable[2] = shop->owner->idleAnim;

    return script->id;
}

ApiStatus func_802803C8(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    script->varTable[2] = FALSE;

    if (playerStatus->actionState == ACTION_STATE_BOUNCE ||
        playerStatus->actionState == ACTION_STATE_FALLING) {
        return ApiStatus_DONE2;
    }

    if ((playerStatus->flags & 0x100)) {
        return ApiStatus_DONE2;
    }

    script->varTable[2] = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus func_80280410(Evt* script, s32 isInitialCall) {
    static Evt* D_80286520;
    static s32 D_80286524;

    Shop* shop = gGameStatusPtr->mapShop;
    s32 currentItemSlot = evt_get_variable(script, *script->ptrReadPos);

    if (!(shop->flags & SHOP_FLAGS_8)) {
        shop->currentItemSlot = currentItemSlot;
        shop->flags |= SHOP_FLAGS_1;
        func_800E98EC();
        shop->unk_358 = 5;

        if (gGameStatusPtr->pressedButtons & 0x8000) {

            Evt* childScript;

            disable_player_input();
            disable_player_static_collisions();

            childScript = start_script(&BadgeShopInteract, 1, 0);
            childScript->varTable[0] = currentItemSlot;
            D_80286520 = childScript;
            D_80286524 = childScript->id;
            shop->flags |= SHOP_FLAGS_8;
            return ApiStatus_BLOCK;
        } else {
            return ApiStatus_DONE2;
        }
    } else if (does_script_exist(D_80286524)) {
        return ApiStatus_BLOCK;
    }

    shop->flags &= ~SHOP_FLAGS_8;
    enable_player_static_collisions();
    enable_player_input();
    return ApiStatus_DONE2;
}

ApiStatus ShowShopPurchaseDialog(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    GameStatus* gameStatus = gGameStatusPtr;
    s32 shopItemSlot = script->varTable[0];
    Shop* shop = gameStatus->mapShop;
    StaticInventoryItem* shopInventory = &shop->staticInventory[shopItemSlot];
    StaticItem* shopItem = &gItemTable[shopInventory->itemID];
    ShopOwner* shopOwner;
    Evt* shopOwnerScript;
    EvtSource* shopOwnerScriptSource;
    s32 bpCost;
    s32 args;

    shop->flags &= ~SHOP_FLAGS_1;
    func_800E9900();
    if (isInitialCall) {
        D_80286530 = 0;
        D_80286534 = 0;
        bpCost = -1;
        if (shopItem->typeFlags & ITEM_TYPE_FLAGS_40) {
            bpCost = D_8008F072[shopItem->moveID * 0x14];
        }
        script->functionTemp[1] = shop_owner_buy_dialog(0, shopItem->nameMsg, shopInventory->price, bpCost);
        script->functionTemp[0] = 0;
        increment_status_menu_disabled();
        func_800E9900();
        show_coin_counter();
    }
    
    switch (script->functionTemp[0]) {
        case 0:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                script->functionTemp[0] = 100;
                script->functionTemp[2] = 0;
                D_80286528 = msg_get_printer_for_msg(0x1E0001, &script->functionTemp[2]);
            }
            break;
        case 100:
            args = script->functionTemp[2];
            if (script->functionTemp[2] == 1) {
                if (D_80286528->currentOption == 0) {
                    if (playerData->coins < shopInventory->price) {
                        script->functionTemp[1] = shop_owner_continue_speech(1);
                        script->functionTemp[0] = args;
                    } else if ((shopInventory->itemID - 224) >= 117 && add_item(0) == -1) {
                        script->functionTemp[1] = shop_owner_continue_speech(2);
                        script->functionTemp[0] = 4;
                    } else {
                        playerData->coins = playerData->coins - shopInventory->price;
                        if ((shopInventory->itemID - 224) < 117) {
                            add_badge(shopInventory->itemID);
                            evt_set_variable(NULL, EVT_SAVE_FLAG(368), 1);
                        } else {
                            add_item(shopInventory->itemID);
                        }
                        script->functionTemp[1] = shop_owner_continue_speech(3);
                        script->functionTemp[0] = 5;
                    }
                } else {
                    script->functionTemp[1] = shop_owner_reset_speech(22);
                    script->functionTemp[0] = 6;
                }
            }
            break;
        case 1:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                D_80286534 = 0;
                D_80286530 = shopInventory->itemID;
                script->functionTemp[0] = 10;
            }
            break;
        case 4:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                D_80286534 = 5;
                D_80286530 = shopInventory->itemID;
                script->functionTemp[0] = 10;
            }
            break;
        case 5:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                D_80286534 = 1;
                D_80286530 = shopInventory->itemID;
                script->functionTemp[0] = 10;
            }
            break;
        case 6:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                D_80286534 = 3;
                D_80286530 = shopInventory->itemID;
                script->functionTemp[0] = 10;
            }
            break;
        case 10:
            shopOwner = shop->owner;
            D_8028652C = NULL;
            if (shopOwner != NULL) {
                shopOwnerScriptSource = shopOwner->unk_0C;
                if (shopOwnerScriptSource != NULL) {
                    shopOwnerScript = start_script(shopOwnerScriptSource, 1, 0);
                    D_8028652C = shopOwnerScript;
                    shopOwnerScript->varTable[2] = shopItemSlot;
                    shopOwnerScript->varTable[0] = D_80286534;
                    shopOwnerScript->varTable[1] = D_80286530;
                }
            }
            script->functionTemp[0] = 11;
            break;
        case 11:
            shopOwnerScript = D_8028652C;
            if (shopOwnerScript == 0 || does_script_exist(shopOwnerScript->id) == 0) {
                decrement_status_menu_disabled();
                func_800E96C8();
                return ApiStatus_DONE1;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

//dumb stuff
#ifdef NON_EQUIVALENT
extern s32 D_8008A680[337][2];

void shop_open_item_select_popup(s32 mode) {
    Shop* shop = gGameStatusPtr->mapShop;
    PopupMenu* menu = &shop->itemSelectMenu;
    s32 numItemSlots;
    s32 popupType;
    s32 i;
    s32 numEntries;

    switch (mode) {
        case 0:
            popupType = 5;
            numItemSlots = 10;
            break;
        case 1:
            popupType = 7;
            popupType = 6;
            numItemSlots = 10;
            break;
        default:
            popupType = 7;
            numItemSlots = 20;
            break;
    }

    numEntries = 0;

    for (i = 0; i < numItemSlots; i++) {
        s32 itemID;

        if (mode >= 0 && mode < 2) {
            itemID = gPlayerData.invItems[i];
        } else {
            itemID = gPlayerData.storedItems[i];
        }

        if (itemID != 0) {
            menu->ptrIcon[i] = D_8008A680[gItemTable[itemID].iconID][0];
            menu->userIndex[i] = i;
            menu->enabled[i] = TRUE;
            menu->nameMsg[i] = gItemTable[itemID].nameMsg;
            menu->descMsg[i] = gItemTable[itemID].itemMsg;
            menu->value[i] = shop_get_sell_price(itemID);
            numEntries++;
        }
    }

    menu->popupType = popupType;
    menu->numEntries = numEntries;
    menu->initialPos = 0;
    func_800F4FC4(menu);
    func_800E9894();
    func_800E98EC();
    open_status_menu_short();
}
#else
INCLUDE_ASM(s32, "world/script_api/7E0E80", shop_open_item_select_popup);
#endif

s32 shop_update_item_select_popup(s32* selectedIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    PopupMenu* menu = &shop->itemSelectMenu;
    s16 menuResult = shop->itemSelectMenu.result;

    if (menuResult == 0) {
        return 0;
    }

    hide_popup_menu();

    if (menuResult == 0xFF) {
        *selectedIndex = -1;
    } else {
        *selectedIndex = menu->userIndex[menuResult - 1];
    }

    return 1;
}

void shop_close_item_select_popup(void) {
    destroy_popup_menu();
    func_800E9900();
    func_800E98C4();
    close_status_menu();
}

s32 shop_get_sell_price(s32 itemID) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 numItems = shop->numSpecialPrices;
    StaticPriceItem* items = shop->staticPriceList;
    s32 i;

    if (shop) {
        i = 0;
    } // TODO fake match


    for (i = 0; i < numItems; i++) {
        if (items[i].itemID == itemID) {
            return items[i].sellPrice;
        }
    }

    return gItemTable[itemID].sellValue;
}

ApiStatus ShowShopOwnerDialog(Evt* script, s32 isInitialCall) {
    GameStatus* gameStatus = gGameStatusPtr;
    PlayerData* playerData = &gPlayerData;
    Shop* shop = gameStatus->mapShop;
    StaticItem* item;
    s32 temp_v1_2;

    if (isInitialCall) {
        script->functionTemp[1] = shop_owner_begin_speech(4);
        script->functionTemp[0] = 4;
    }

    switch (script->functionTemp[0]) {
        case 4:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                script->functionTemp[0] = 41;
                script->functionTemp[2] = 0;
                D_80286538 = msg_get_printer_for_msg(0x1E0003, &script->functionTemp[2]);
            }
            break;
        case 41:
            if (script->functionTemp[2] == 1) {
                switch (D_80286538->currentOption) {
                    case 0:
                        script->functionTemp[1] = shop_owner_continue_speech(5);
                        script->functionTemp[0] = 0;
                        break;
                    case 1:
                        if (get_item_count() == 0) {
                            script->functionTemp[1] = shop_owner_continue_speech(6);
                            script->functionTemp[0] = 9;
                        } else {
                            script->functionTemp[1] = shop_owner_continue_speech(7);
                            script->functionTemp[0] = 201;
                        }
                        break;
                    case 2:
                        if (get_item_count() == 0) {
                            script->functionTemp[1] = shop_owner_continue_speech(12);
                            script->functionTemp[0] = 9;
                            break;
                        }
                        if (get_stored_empty_count() == 0) {
                            script->functionTemp[1] = shop_owner_continue_speech(13);
                            script->functionTemp[0] = 9;
                            break;
                        }
                        script->functionTemp[1] = shop_owner_continue_speech_with_quantity(14, get_stored_empty_count());
                        script->functionTemp[0] = 501;
                        break;
                    case 3:
                        if (get_stored_count() == 0) {
                            script->functionTemp[1] = shop_owner_continue_speech(17);
                            script->functionTemp[0] = 9;
                            break;
                        }
                        if (get_item_empty_count() == 0) {
                            script->functionTemp[1] = shop_owner_continue_speech(18);
                            script->functionTemp[0] = 9;
                            break;
                        }
                        script->functionTemp[1] = shop_owner_continue_speech(19);
                        script->functionTemp[0] = 701;
                        break;
                    default:
                        script->functionTemp[1] = shop_owner_end_speech();
                        script->functionTemp[0] = 42;
                        break;
                }
            }
            break;
        case 201:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                shop_open_item_select_popup(0);
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            if (shop_update_item_select_popup(&shop->selectedStoreItemSlot) == 1) {
                script->functionTemp[0] = 21;
                script->functionTemp[1] = 15;
            }     
            break;
        case 21:
            if (script->functionTemp[1] <= 0) {
                shop_close_item_select_popup();
                if (shop->selectedStoreItemSlot >= 0) {
                    item = &gItemTable[playerData->invItems[shop->selectedStoreItemSlot]];
                    script->functionTemp[1] = shop_owner_buy_dialog(8, item->nameMsg, shop_get_sell_price(playerData->invItems[shop->selectedStoreItemSlot]), -1);
                    show_coin_counter();
                    script->functionTemp[0] = 3;
                } else {
                    script->functionTemp[1] = shop_owner_begin_speech(22);
                    script->functionTemp[0] = 9;
                }
            } else {
                script->functionTemp[1]--;
            }
            break;
        case 3:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                script->functionTemp[0] = 31;
                script->functionTemp[2] = 0;
                D_80286538 = msg_get_printer_for_msg(0x1E0002, &script->functionTemp[2]);
            }
            break;
        case 31:
            if (script->functionTemp[2] == 1) {
                if (D_80286538->currentOption == 0) {
                    add_coins(shop_get_sell_price(playerData->invItems[shop->selectedStoreItemSlot]));
                    playerData->invItems[shop->selectedStoreItemSlot] = 0;
                    if (get_item_count() == 0) {
                        script->functionTemp[1] = shop_owner_reset_speech(11);
                        script->functionTemp[0] = 9;
                        hide_coin_counter();
                    } else {
                        script->functionTemp[1] = shop_owner_reset_speech(10);
                        script->functionTemp[0] = 32;
                    }
                } else {
                    script->functionTemp[1] = shop_owner_reset_speech(9);
                    script->functionTemp[0] = 32;
                    hide_coin_counter();
                }
            }
            break;
        case 32:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                script->functionTemp[0] = 12;
                script->functionTemp[2] = 0;
                D_80286538 = msg_get_printer_for_msg(0x1E0004, &script->functionTemp[2]);
            }
            break;
        case 12:
            if (script->functionTemp[2] == 1) {
                if (D_80286538->currentOption == 0) {
                    script->functionTemp[1] = shop_owner_end_speech();
                    script->functionTemp[0] = 201;
                    func_800E96C8();
                } else {
                    func_800E96C8();
                    script->functionTemp[1] = shop_owner_reset_speech(22);
                    script->functionTemp[0] = 9;
                }
            }
            break;
        case 501:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                shop_open_item_select_popup(1);
                script->functionTemp[0] = 5;
            }
            break;
        case 5:
            if (shop_update_item_select_popup(&shop->selectedStoreItemSlot) == 1) {
                script->functionTemp[0] = 51;
                script->functionTemp[1] = 15;
            }
            break;
        case 51:
            if (script->functionTemp[1] <= 0) {
                shop_close_item_select_popup();
                if (shop->selectedStoreItemSlot >= 0) {
                    if (store_item(playerData->invItems[shop->selectedStoreItemSlot]) >= 0) {
                        playerData->invItems[shop->selectedStoreItemSlot] = 0;
                    }

                    if ((get_item_count() == 0) || (get_stored_empty_count() == 0)) {
                        script->functionTemp[1] = shop_owner_begin_speech(15);
                        script->functionTemp[0] = 9;
                    } else {
                        script->functionTemp[1] = shop_owner_begin_speech(16);
                        script->functionTemp[0] = 52;
                    }
                } else {
                    script->functionTemp[1] = shop_owner_begin_speech(22);
                    script->functionTemp[0] = 9;
                }
            } else { 
                script->functionTemp[1]--;
            }
            break;
        case 52:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                script->functionTemp[0] = 53;
                script->functionTemp[2] = 0;
                D_80286538 = msg_get_printer_for_msg(0x1E0005, &script->functionTemp[2]);
            }
            break;
        case 53:
            if (script->functionTemp[2] == 1) {
                if (D_80286538->currentOption == 0) {
                    script->functionTemp[1] = shop_owner_end_speech();
                    script->functionTemp[0] = 501;
                } else {
                    script->functionTemp[1] = shop_owner_reset_speech(22);
                    script->functionTemp[0] = 9;
                }
            }
            break;
        case 701:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                shop_open_item_select_popup(2);
                script->functionTemp[0] = 7;
            }
            break;
        case 7:
            if (shop_update_item_select_popup(&shop->selectedStoreItemSlot) == 1) {
                script->functionTemp[0] = 71;
                script->functionTemp[1] = 15;
            }
            break;
        case 71:
            if (script->functionTemp[1] > 0) {
                script->functionTemp[1]--;
            } else {
                shop_close_item_select_popup();
                if (shop->selectedStoreItemSlot >= 0) {
                    if (add_item(playerData->storedItems[shop->selectedStoreItemSlot]) >= 0) {
                        playerData->storedItems[shop->selectedStoreItemSlot] = 0;
                    }

                    if (get_item_empty_count() == 0 || get_stored_count() == 0) {
                        script->functionTemp[1] = shop_owner_begin_speech(20);
                        script->functionTemp[0] = 9;
                    } else {
                        script->functionTemp[1] = shop_owner_begin_speech(21);
                        script->functionTemp[0] = 72;
                    }
                } else {
                    script->functionTemp[1] = shop_owner_begin_speech(22);
                    script->functionTemp[0] = 9;
                }
            }
            break;
        case 72:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                script->functionTemp[0] = 73;
                script->functionTemp[2] = 0;
                D_80286538 = msg_get_printer_for_msg(0x1E0005, &script->functionTemp[2]);
            }
            break;
        case 73:
            if (script->functionTemp[2] == 1) {
                if (D_80286538->currentOption == 0) {
                    script->functionTemp[1] = shop_owner_end_speech();
                    script->functionTemp[0] = 701;
                } else {
                    script->functionTemp[1] = shop_owner_reset_speech(22);
                    script->functionTemp[0] = 9;
                }
            }
            break;
        case 0:
        case 9:
        case 42:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                script->functionTemp[0] = 0;
                script->functionTemp[0] = 10;
            }
            break;
        case 10:
            if (shop->owner != NULL) {
                if (shop->owner->unk_14 != 0) {
                    start_script(shop->owner->unk_14, 1, 0);
                }
            }
            open_status_menu_short();
            return ApiStatus_DONE1;
        default:
            break;
    }
    return ApiStatus_BLOCK;
}

void shop_draw_item_name(s32 arg0, s32 posX, s32 posY) {
    Shop* shop = gGameStatusPtr->mapShop;
    StaticInventoryItem* siItem = &shop->staticInventory[shop->currentItemSlot];
    StaticItem* shopItem = &gItemTable[siItem->itemID];

    draw_msg(shopItem->nameMsg, posX + 60 - (get_msg_width(shopItem->nameMsg, 0) >> 1), posY + 6, 255, 0, 0);
}

void shop_draw_item_desc(s32 arg0, s32 posX, s32 posY) {
    Shop* shop = gGameStatusPtr->mapShop;
    StaticInventoryItem* shopItem = &shop->staticInventory[shop->currentItemSlot];

    draw_msg(shopItem->unk_08, posX + 8, posY, 255, 0xA, 0);
}

extern void draw_shop_items();
// Problems with the struct iteration
#ifdef NON_EQUIVALENT
void draw_shop_items(void) {
    Shop* shop = gGameStatusPtr->mapShop;
    StaticInventoryItem* staticItems;
    Camera* camera;
    s32 i;
    s32 xTemp;
    s32 yTemp;
    s32 xOffset;
    f32 x, y, z, s;
    f32 inX, inY, inZ;
    ShopItemEntity* shopItemEntities;

    if (shop->flags & SHOP_FLAGS_1) {
        set_window_update(10, basic_window_update);
        set_window_update(11, basic_window_update);
    } else {
        set_window_update(10, basic_hidden_window_update);
        set_window_update(11, basic_hidden_window_update);
    }

    if (shop->flags & SHOP_FLAGS_1) {
        camera = &gCameras[gCurrentCameraID];
        staticItems = shop->staticInventory;
        shopItemEntities = gGameStatusPtr->shopItemEntities;

        for (i = 0; i < shop->numItems; i++) {
            inX = shopItemEntities[i].pos.x;
            inY = shopItemEntities[i].pos.y + 30.0f;
            inZ = shopItemEntities[i].pos.z;

            transform_point(camera->perspectiveMatrix, inX, inY, inZ, 1.0f, &x, &y, &z, &s);

            s = 1.0f / s;

            x *= s;
            y *= -s;
            z = (z * s + 1.0f) * 0.5;

            if (z > 0.0f && z < 1.0f) {
                xTemp = (((x * camera->viewportW) + camera->viewportW) * 0.5) + camera->viewportStartX;
                yTemp = (((y * camera->viewportH) + camera->viewportH) * 0.5) + camera->viewportStartY;

                if (staticItems[i].price < 100) {
                    xOffset = -4;
                } else {
                    xOffset = 0;
                }

                if (!(get_item_entity(shopItemEntities[i].index)->flags & 0x40)) {
                    draw_number(staticItems[i].price, xTemp + xOffset, yTemp, 1, 0, 255, 0);
                }

                if (i == shop->currentItemSlot) {
                    set_hud_element_render_pos(shop->costIconID, (xTemp + xOffset) - 6, yTemp + 5);
                    set_hud_element_scale(shop->costIconID, 0.7f);
                    draw_hud_element_clipped(shop->costIconID);
                }
            }
        }
    }

    if (shop->unk_358 > 0) {
        shop->unk_358--;
    } else {
        shop->flags &= ~SHOP_FLAGS_1;
        func_800E9900();
    }
}
#else
INCLUDE_ASM(s32, "world/script_api/7E0E80", draw_shop_items);
#endif

// This should be equivalent to the original code but there is some funny business with
// the evt_get_variable's at the beginning that makes absolutely no sense.
#ifdef NON_MATCHING
s32 MakeShop(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ShopItemLocation* staticItemPositions = evt_get_variable(script, *args++);
    StaticInventoryItem* inventory = evt_get_variable(script, *args++);
    StaticPriceItem* prices = evt_get_variable(script, *args++);
    s32 inventoryItemFlags = evt_get_variable(script, *args++);
    Shop* shop = heap_malloc(sizeof(Shop));
    Model* model;
    s32 numShopItems;
    f32 centerX;
    f32 centerY;
    f32 centerZ;
    f32 sizeX;
    f32 sizeY;
    f32 sizeZ;
    s32 items;
    
    gGameStatusPtr->mapShop = shop;
    shop->staticItemPositions = staticItemPositions;
    shop->staticInventory = inventory;
    shop->staticPriceList = prices;
    shop->inventoryItemFlags = inventoryItemFlags;
    
    numShopItems = 0;
    items = inventory->itemID;
    while (items != 0) {
        numShopItems++;
        inventory++;
        items = inventory->itemID;
    }
    shop->numItems = numShopItems;
    
    numShopItems = 0;
    if (prices != NULL) {
        items = prices->itemID;
        while (items != 0) {
            numShopItems++;
            prices++;
            items = prices->itemID;
        }
    }
    shop->numSpecialPrices = numShopItems;
    
    if (shop->numItems > 0) {
        gGameStatusPtr->shopItemEntities = heap_malloc(sizeof(ShopItemEntity) * shop->numItems);
    }
    
    inventory = shop->staticInventory;
    staticItemPositions = shop->staticItemPositions;
    numShopItems = 0;
    while (inventory->itemID != 0) {
        get_model_center_and_size(staticItemPositions->posModelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
        centerY += 6;
        gGameStatusPtr->shopItemEntities[numShopItems].pos.x = centerX;
        gGameStatusPtr->shopItemEntities[numShopItems].pos.y = centerY;
        gGameStatusPtr->shopItemEntities[numShopItems].pos.z = centerZ;
        model = get_model_from_list_index(get_model_list_index_from_tree_index(staticItemPositions->posModelID));
        model->flags |= MODEL_FLAGS_FLAG_4;
        gGameStatusPtr->shopItemEntities[numShopItems].index = make_item_entity_nodelay(inventory->itemID | shop->inventoryItemFlags, centerX, centerY, centerZ, 1, 0);
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[numShopItems].index, 0x4000);
        bind_trigger_1(D_80283F58_7E4DD8, 0x80, staticItemPositions->triggerColliderID, numShopItems, 0, 3);
        bind_trigger_1(D_80283F58_7E4DD8, 0x800, staticItemPositions->triggerColliderID, numShopItems, 0, 3);
        staticItemPositions++;
        inventory++;
        numShopItems++;
    }

    shop->costIconID = create_hud_element(&D_80080868);
    set_hud_element_flags(shop->costIconID, 0x80);
    clear_hud_element_flags(shop->costIconID, 0x8000);
    get_generic_entity(create_generic_entity_frontUI(NULL, draw_shop_items));
    set_window_properties(0xA, 100, 66, 120, 28, 0, shop_draw_item_name, NULL, -1);
    set_window_properties(0xB, 32, 184, 256, 32, 1, shop_draw_item_desc, NULL, -1);
    D_8014F150[10] = 9;
    D_8014F150[11] = 3;
    shop->currentItemSlot = 0;
    shop->selectedStoreItemSlot = 0;
    shop->flags = SHOP_FLAGS_0;
    shop->owner = NULL;

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "world/script_api/7E0E80", MakeShop, Evt* script, s32 isInitialCall);
#endif

ApiStatus MakeShopOwner(Evt* script, s32 isInitialCall) {
    Shop* mapShop = gGameStatusPtr->mapShop;

    mapShop->owner = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
