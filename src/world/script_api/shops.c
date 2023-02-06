#include "common.h"
#include "message_ids.h"
#include "hud_element.h"
#include "model.h"
#include "pause/pause_common.h"

extern u8 MessagePlural[];
extern u8 MessageSingular[];
extern HudScript* HES_Item_Coin;

API_CALLABLE(func_802803C8);
API_CALLABLE(func_80280410);
API_CALLABLE(ShowShopPurchaseDialog);
API_CALLABLE(ShowShopOwnerDialog);

EvtScript ShopBeginSpeech = {
    EVT_CALL(SpeakToPlayer, LVar1, LVar2, LVar3, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript ShopContinueSpeech = {
    EVT_CALL(ContinueSpeech, LVar1, LVar2, LVar3, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript ShopResetSpeech = {
    EVT_CALL(EndSpeech, LVar1, LVar2, LVar3, 0)
    EVT_CALL(SpeakToPlayer, LVar1, LVar2, LVar3, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript ShopEndSpeech = {
    EVT_CALL(EndSpeech, LVar0, LVar1, LVar2, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_80283F58_7E4DD8 = {
    EVT_CALL(GetPartnerInUse, LVar1)
    EVT_IF_EQ(LVar1, PARTNER_NONE)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LVar1, PARTNER_KOOPER)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LVar1, PARTNER_BOMBETTE)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(10)
    EVT_CALL(func_802803C8)
    EVT_IF_EQ(LVar2, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(func_80280410, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript BadgeShopInteract = {
    EVT_CALL(ShowShopPurchaseDialog, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript ItemShopInteract = {
    EVT_CALL(ShowShopOwnerDialog)
    EVT_RETURN
    EVT_END
};

s32 shop_owner_begin_speech(s32 messageIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopMsgID = shop->owner->shopMsgIDs[messageIndex];
    Evt* script = start_script(&ShopBeginSpeech, EVT_PRIORITY_1, 0);

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
    u8* suffix;

    set_message_msg(itemName, 0);
    set_message_value(coinCost, 1);

    if (bpCost > 0) {
        set_message_value(bpCost, 2);
    } else {
        if (coinCost == 1) {
            suffix = MessageSingular;
        } else {
            suffix = MessagePlural;
        }
        set_message_msg((s32) suffix, 2);
    }

    script = start_script(&ShopBeginSpeech, EVT_PRIORITY_1, 0);
    script->varTable[0] = shopMsgID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_continue_speech(s32 messageIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopMsgID = shop->owner->shopMsgIDs[messageIndex];
    Evt* script = start_script(&ShopContinueSpeech, EVT_PRIORITY_1, 0);

    script->varTable[0] = shopMsgID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->functionTemp[3] = script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_continue_speech_with_quantity(s32 messageIndex, s32 amount) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopMsgID = shop->owner->shopMsgIDs[messageIndex];
    u8* suffixMsg;
    Evt* script;

    set_message_value(amount, 0);

    if (amount == 1) {
        suffixMsg = MessageSingular;
    } else {
        suffixMsg = MessagePlural;
    }

    set_message_msg((s32) suffixMsg, 1);

    script = start_script(&ShopContinueSpeech, EVT_PRIORITY_1, 0);
    script->varTable[0] = shopMsgID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->functionTemp[3] = script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_reset_speech(s32 messageIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopMsgID = shop->owner->shopMsgIDs[messageIndex];
    Evt* script = start_script(&ShopResetSpeech, EVT_PRIORITY_1, 0);

    script->varTable[0] = shopMsgID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->functionTemp[3] = script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_end_speech(void) {
    Shop* shop = gGameStatusPtr->mapShop;
    Evt* script = start_script(&ShopEndSpeech, EVT_PRIORITY_1, 0);

    script->varTable[0] = shop->owner->npcID;
    script->varTable[1] = shop->owner->talkAnim;
    script->functionTemp[3] = script->varTable[2] = shop->owner->idleAnim;

    return script->id;
}

API_CALLABLE(func_802803C8) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    script->varTable[2] = FALSE;

    if (playerStatus->actionState == ACTION_STATE_BOUNCE ||
        playerStatus->actionState == ACTION_STATE_FALLING) {
        return ApiStatus_DONE2;
    }

    if ((playerStatus->flags & PS_FLAG_PAUSE_DISABLED)) {
        return ApiStatus_DONE2;
    }

    script->varTable[2] = TRUE;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80280410) {
    static Evt* D_80286520;
    static s32 D_80286524;

    Shop* shop = gGameStatusPtr->mapShop;
    s32 currentItemSlot = evt_get_variable(script, *script->ptrReadPos);

    if (!(shop->flags & SHOP_FLAG_8)) {
        shop->currentItemSlot = currentItemSlot;
        shop->flags |= SHOP_FLAG_1;
        func_800E98EC();
        shop->unk_358 = 5;

        if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {

            Evt* childScript;

            disable_player_input();
            disable_player_static_collisions();

            childScript = start_script(&BadgeShopInteract, EVT_PRIORITY_1, 0);
            childScript->varTable[0] = currentItemSlot;
            D_80286520 = childScript;
            D_80286524 = childScript->id;
            shop->flags |= SHOP_FLAG_8;
            return ApiStatus_BLOCK;
        } else {
            return ApiStatus_DONE2;
        }
    } else if (does_script_exist(D_80286524)) {
        return ApiStatus_BLOCK;
    }

    shop->flags &= ~SHOP_FLAG_8;
    enable_player_static_collisions();
    enable_player_input();
    return ApiStatus_DONE2;
}

enum PurchaseDialogState {
    PURCHASE_DIALOG_STATE_INIT              = 0,
    PURCHASE_DIALOG_STATE_NOT_ENOUGH_COINS  = 1,
    PURCHASE_DIALOG_STATE_NOT_ENOUGH_ROOM   = 4,
    PURCHASE_DIALOG_STATE_ACCEPTED          = 5,
    PURCHASE_DIALOG_STATE_CANCEL            = 6,
    PURCHASE_DIALOG_STATE_EXEC_CALLBACK     = 10,
    PURCHASE_DIALOG_STATE_AWAIT_CALLBACK    = 11,
    PURCHASE_DIALOG_STATE_WAIT_FOR_SPEECH   = 100,
};

API_CALLABLE(ShowShopPurchaseDialog) {
    PlayerData* playerData = &gPlayerData;
    s32 shopItemSlot = script->varTable[0];
    Shop* shop = gGameStatusPtr->mapShop;
    ShopItemData* shopInventory = &shop->staticInventory[shopItemSlot];
    ItemData* shopItem = &gItemTable[shopInventory->itemID];
    s32 bpCost;

    static MessagePrintState* D_80286528;
    static Evt* wShopBuyCallbackScript;
    static s32 wShopSelectedItem;
    static s32 wShopBuyResult;

    // functionTemp[0] is PurchaseDialogState
    // functionTemp[1] is speech script ID
    // functionTemp[2] is speech printer isClosed writeback

    shop->flags &= ~SHOP_FLAG_1;
    func_800E9900();

    if (isInitialCall) {
        wShopSelectedItem = ITEM_NONE;
        wShopBuyResult = SHOP_BUY_RESULT_NOT_ENOUGH_COINS;
        bpCost = -1;
        if (shopItem->typeFlags & ITEM_TYPE_FLAG_BADGE) {
            bpCost = gMoveTable[shopItem->moveID].costBP;
        }
        script->functionTemp[1] = shop_owner_buy_dialog(SHOP_MSG_BUY_CONFIRM, shopItem->nameMsg, shopInventory->price, bpCost);
        script->functionTemp[0] = PURCHASE_DIALOG_STATE_INIT;
        increment_status_menu_disabled();
        func_800E9900();
        show_coin_counter();
    }

    switch (script->functionTemp[0]) {
        case PURCHASE_DIALOG_STATE_INIT:
            if (!does_script_exist(script->functionTemp[1])) {
                script->functionTemp[0] = PURCHASE_DIALOG_STATE_WAIT_FOR_SPEECH;
                script->functionTemp[2] = FALSE;
                D_80286528 = msg_get_printer_for_msg(MSG_Choice_0001, &script->functionTemp[2]);
            }
            break;
        case PURCHASE_DIALOG_STATE_WAIT_FOR_SPEECH:
            if (script->functionTemp[2] == TRUE) {
                if (D_80286528->currentOption == 0) {
                    if (playerData->coins < shopInventory->price) {
                        script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_NOT_ENOUGH_COINS);
                        script->functionTemp[0] = PURCHASE_DIALOG_STATE_NOT_ENOUGH_COINS;
                    } else if (!IS_BADGE(shopInventory->itemID) && add_item(ITEM_NONE) == -1) {
                        script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_NOT_ENOUGH_ROOM);
                        script->functionTemp[0] = PURCHASE_DIALOG_STATE_NOT_ENOUGH_ROOM;
                    } else {
                        playerData->coins -= shopInventory->price;
                        if (IS_BADGE(shopInventory->itemID)) {
                            add_badge(shopInventory->itemID);
                            evt_set_variable(NULL, GF_MAC01_BoughtBadgeFromRowf, TRUE);
                        } else {
                            add_item(shopInventory->itemID);
                        }
                        script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_BUY_THANK_YOU);
                        script->functionTemp[0] = PURCHASE_DIALOG_STATE_ACCEPTED;
                    }
                } else {
                    script->functionTemp[1] = shop_owner_reset_speech(SHOP_MSG_FAREWELL);
                    script->functionTemp[0] = PURCHASE_DIALOG_STATE_CANCEL;
                }
            }
            break;
        case PURCHASE_DIALOG_STATE_NOT_ENOUGH_COINS:
            if (!does_script_exist(script->functionTemp[1])) {
                wShopBuyResult = SHOP_BUY_RESULT_NOT_ENOUGH_COINS;
                wShopSelectedItem = shopInventory->itemID;
                script->functionTemp[0] = PURCHASE_DIALOG_STATE_EXEC_CALLBACK;
            }
            break;
        case PURCHASE_DIALOG_STATE_NOT_ENOUGH_ROOM:
            if (!does_script_exist(script->functionTemp[1])) {
                wShopBuyResult = SHOP_BUY_RESULT_NOT_ENOUGH_ROOM;
                wShopSelectedItem = shopInventory->itemID;
                script->functionTemp[0] = PURCHASE_DIALOG_STATE_EXEC_CALLBACK;
            }
            break;
        case PURCHASE_DIALOG_STATE_ACCEPTED:
            if (!does_script_exist(script->functionTemp[1])) {
                wShopBuyResult = SHOP_BUY_RESULT_OK;
                wShopSelectedItem = shopInventory->itemID;
                script->functionTemp[0] = PURCHASE_DIALOG_STATE_EXEC_CALLBACK;
            }
            break;
        case PURCHASE_DIALOG_STATE_CANCEL:
            if (!does_script_exist(script->functionTemp[1])) {
                wShopBuyResult = SHOP_BUY_RESULT_CANCEL;
                wShopSelectedItem = shopInventory->itemID;
                script->functionTemp[0] = PURCHASE_DIALOG_STATE_EXEC_CALLBACK;
            }
            break;
        case PURCHASE_DIALOG_STATE_EXEC_CALLBACK:
            wShopBuyCallbackScript = NULL;
            if (shop->owner != NULL) {
                if (shop->owner->onBuyEvt != NULL) {
                    wShopBuyCallbackScript = start_script(shop->owner->onBuyEvt, EVT_PRIORITY_1, 0);
                    wShopBuyCallbackScript->varTable[0] = wShopBuyResult;
                    wShopBuyCallbackScript->varTable[1] = wShopSelectedItem;
                    wShopBuyCallbackScript->varTable[2] = shopItemSlot;
                }
            }
            script->functionTemp[0] = PURCHASE_DIALOG_STATE_AWAIT_CALLBACK;
            break;
        case PURCHASE_DIALOG_STATE_AWAIT_CALLBACK:
            if (wShopBuyCallbackScript != NULL && does_script_exist(wShopBuyCallbackScript->id)) {
                break;
            }
            decrement_status_menu_disabled();
            hide_coin_counter_immediately();
            return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

void func_800F4FC4(PopupMenu* popup);

// almost
#ifdef NON_EQUIVALENT
void shop_open_item_select_popup(s32 mode) {
    PopupMenu* menu = &gGameStatusPtr->mapShop->itemSelectMenu;
    s32 numItemSlots;
    s32 popupType;
    s32 enabled;
    s32 numEntries;
    s32 itemID;
    s32 i;

    switch (mode) {
        case 0:
            popupType = POPUP_MENU_SELL_ITEM;
            numItemSlots = 10;
            break;
        case 1:
            popupType = POPUP_MENU_CHECK_ITEM;
            numItemSlots = 10;
            break;
        default:
            popupType = POPUP_MENU_CLAIM_ITEM;
            numItemSlots = 32;
            break;
    }

    enabled = TRUE;
    numEntries = 0;

    for (i = 0; i < numItemSlots; i++) {
        do {
            switch (mode) {
                case 0:
                case 1:
                    itemID = gPlayerData.invItems[i];
                    break;
                default:
                    itemID = gPlayerData.storedItems[i];
                    break;
            }

            if (itemID != ITEM_NONE) {
                menu->ptrIcon[numEntries] = gItemHudScripts[gItemTable[itemID].hudElemID].enabled;
                menu->userIndex[numEntries] = i;
                menu->enabled[numEntries] = enabled;
                menu->nameMsg[numEntries] = gItemTable[itemID].nameMsg;
                menu->descMsg[numEntries] = gItemTable[itemID].shortDescMsg;
                menu->value[numEntries] = shop_get_sell_price(itemID);
                numEntries++;
            }
        } while (0); // TODO required to match
    }

    menu->popupType = popupType;
    menu->numEntries = numEntries;
    menu->initialPos = 0;
    func_800F4FC4(menu);
    status_menu_ignore_changes();
    func_800E98EC();
    open_status_menu_short();
}
#else
INCLUDE_ASM(s32, "world/script_api/shops", shop_open_item_select_popup);
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
    status_menu_respond_to_changes();
    close_status_menu();
}

s32 shop_get_sell_price(s32 itemID) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 numItems = shop->numSpecialPrices;
    ShopSellPriceData* items = shop->staticPriceList;
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

API_CALLABLE(ShowShopOwnerDialog) {
    GameStatus* gameStatus = gGameStatusPtr;
    PlayerData* playerData = &gPlayerData;
    Shop* shop = gameStatus->mapShop;

    static MessagePrintState* D_80286538;

    enum {
        DIALOG_STATE_DONE_INSTRUCTIONS          = 0,
        DIALOG_STATE_AWAIT_GREETING             = 4,
        DIALOG_STATE_AWAIT_MAIN_MENU            = 41,
        DIALOG_STATE_CLOSED_MAIN_MENU           = 42,
        DIALOG_STATE_CLOSED_SUBMENU             = 9,
        DIALOG_STATE_DONE                       = 10,
        // selling
        DIALOG_STATE_INIT_SELL_CHOICE           = 201,
        DIALOG_STATE_AWAIT_SELL_CHOICE          = 2,
        DIALOG_STATE_INIT_SELL_CONFIRM          = 21,
        DIALOG_STATE_AWAIT_SELL_CONFIRM         = 3,
        DIALOG_STATE_HANDLE_SELL_CHOICE         = 31,
        DIALOG_STATE_INIT_SELL_MORE_CHOICE      = 32,
        DIALOG_STATE_AWAIT_SELL_MORE_CHOICE     = 12,
        // checking
        DIALOG_STATE_INIT_CHECK_CHOICE          = 501,
        DIALOG_STATE_AWAIT_CHECK_CHOICE         = 5,
        DIALOG_STATE_HANDLE_CHECK_CHOICE        = 51,
        DIALOG_STATE_INIT_CHECK_MORE_CHOICE     = 52,
        DIALOG_STATE_AWAIT_CHECK_MORE_CHOICE    = 53,
        // claiming
        DIALOG_STATE_INIT_CLAIM_CHOICE          = 701,
        DIALOG_STATE_AWAIT_CLAIM_CHOICE         = 7,
        DIALOG_STATE_HANDLE_CLAIM_CHOICE        = 71,
        DIALOG_STATE_INIT_CLAIM_MORE_CHOICE     = 72,
        DIALOG_STATE_AWAIT_CLAIM_MORE_CHOICE    = 73,
    };

    if (isInitialCall) {
        script->functionTemp[1] = shop_owner_begin_speech(SHOP_MSG_GREETING);
        script->functionTemp[0] = DIALOG_STATE_AWAIT_GREETING;
    }

    switch (script->functionTemp[0]) {
        case DIALOG_STATE_AWAIT_GREETING:
            if (!does_script_exist(script->functionTemp[1])) {
                script->functionTemp[0] = DIALOG_STATE_AWAIT_MAIN_MENU;
                script->functionTemp[2] = 0;
                D_80286538 = msg_get_printer_for_msg(MSG_Choice_0003, &script->functionTemp[2]);
            }
            break;
        case DIALOG_STATE_AWAIT_MAIN_MENU:
            if (script->functionTemp[2] == 1) {
                switch (D_80286538->currentOption) {
                    case 0:
                        script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_INSTRUCTIONS);
                        script->functionTemp[0] = DIALOG_STATE_DONE_INSTRUCTIONS;
                        break;
                    case 1:
                        if (get_item_count() == 0) {
                            script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_NOTHING_TO_SELL);
                            script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                        } else {
                            script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_SELL_WHICH);
                            script->functionTemp[0] = DIALOG_STATE_INIT_SELL_CHOICE;
                        }
                        break;
                    case 2:
                        if (get_item_count() == 0) {
                            script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_NOTHING_TO_CHECK);
                            script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                            break;
                        }
                        if (get_stored_empty_count() == 0) {
                            script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_NO_CHECK_ROOM);
                            script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                            break;
                        }
                        script->functionTemp[1] = shop_owner_continue_speech_with_quantity(SHOP_MSG_CHECK_WHICH, get_stored_empty_count());
                        script->functionTemp[0] = DIALOG_STATE_INIT_CHECK_CHOICE;
                        break;
                    case 3:
                        if (get_stored_count() == 0) {
                            script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_NOTHING_TO_CLAIM);
                            script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                            break;
                        }
                        if (get_item_empty_count() == 0) {
                            script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_NO_CLAIM_ROOM);
                            script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                            break;
                        }
                        script->functionTemp[1] = shop_owner_continue_speech(SHOP_MSG_CLAIM_WHICH);
                        script->functionTemp[0] = DIALOG_STATE_INIT_CLAIM_CHOICE;
                        break;
                    default:
                        script->functionTemp[1] = shop_owner_end_speech();
                        script->functionTemp[0] = DIALOG_STATE_CLOSED_MAIN_MENU;
                        break;
                }
            }
            break;
        case DIALOG_STATE_INIT_SELL_CHOICE:
            if (!does_script_exist(script->functionTemp[1])) {
                shop_open_item_select_popup(0);
                script->functionTemp[0] = DIALOG_STATE_AWAIT_SELL_CHOICE;
            }
            break;
        case DIALOG_STATE_AWAIT_SELL_CHOICE:
            if (shop_update_item_select_popup(&shop->selectedStoreItemSlot) == 1) {
                script->functionTemp[0] = DIALOG_STATE_INIT_SELL_CONFIRM;
                script->functionTemp[1] = 15;
            }
            break;
        case DIALOG_STATE_INIT_SELL_CONFIRM:
            if (script->functionTemp[1] > 0) {
                script->functionTemp[1]--;
                break;
            }
            shop_close_item_select_popup();
            if (shop->selectedStoreItemSlot >= 0) {
                ItemData* itemData = &gItemTable[playerData->invItems[shop->selectedStoreItemSlot]];
                script->functionTemp[1] = shop_owner_buy_dialog(SHOP_MSG_SELL_CONFIRM, itemData->nameMsg, shop_get_sell_price(playerData->invItems[shop->selectedStoreItemSlot]), -1);
                show_coin_counter();
                script->functionTemp[0] = DIALOG_STATE_AWAIT_SELL_CONFIRM;
            } else {
                script->functionTemp[1] = shop_owner_begin_speech(SHOP_MSG_FAREWELL);
                script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
            }
            break;
        case DIALOG_STATE_AWAIT_SELL_CONFIRM:
            if (!does_script_exist(script->functionTemp[1])) {
                script->functionTemp[0] = DIALOG_STATE_HANDLE_SELL_CHOICE;
                script->functionTemp[2] = 0;
                D_80286538 = msg_get_printer_for_msg(MSG_Choice_0002, &script->functionTemp[2]);
            }
            break;
        case DIALOG_STATE_HANDLE_SELL_CHOICE:
            if (script->functionTemp[2] == 1) {
                if (D_80286538->currentOption == 0) {
                    add_coins(shop_get_sell_price(playerData->invItems[shop->selectedStoreItemSlot]));
                    playerData->invItems[shop->selectedStoreItemSlot] = 0;
                    if (get_item_count() == 0) {
                        script->functionTemp[1] = shop_owner_reset_speech(SHOP_MSG_SELL_THANKS);
                        script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                        hide_coin_counter();
                    } else {
                        script->functionTemp[1] = shop_owner_reset_speech(SHOP_MSG_SELL_MORE);
                        script->functionTemp[0] = DIALOG_STATE_INIT_SELL_MORE_CHOICE;
                    }
                } else {
                    script->functionTemp[1] = shop_owner_reset_speech(SHOP_MSG_SELL_CANCEL);
                    script->functionTemp[0] = DIALOG_STATE_INIT_SELL_MORE_CHOICE;
                    hide_coin_counter();
                }
            }
            break;
        case DIALOG_STATE_INIT_SELL_MORE_CHOICE:
            if (!does_script_exist(script->functionTemp[1])) {
                script->functionTemp[0] = DIALOG_STATE_AWAIT_SELL_MORE_CHOICE;
                script->functionTemp[2] = 0;
                D_80286538 = msg_get_printer_for_msg(MSG_Choice_0004, &script->functionTemp[2]);
            }
            break;
        case DIALOG_STATE_AWAIT_SELL_MORE_CHOICE:
            if (script->functionTemp[2] == 1) {
                if (D_80286538->currentOption == 0) {
                    script->functionTemp[1] = shop_owner_end_speech();
                    script->functionTemp[0] = DIALOG_STATE_INIT_SELL_CHOICE;
                    hide_coin_counter_immediately();
                } else {
                    hide_coin_counter_immediately();
                    script->functionTemp[1] = shop_owner_reset_speech(22);
                    script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                }
            }
            break;
        case DIALOG_STATE_INIT_CHECK_CHOICE:
            if (does_script_exist(script->functionTemp[1]) == 0) {
                shop_open_item_select_popup(1);
                script->functionTemp[0] = DIALOG_STATE_AWAIT_CHECK_CHOICE;
            }
            break;
        case DIALOG_STATE_AWAIT_CHECK_CHOICE:
            if (shop_update_item_select_popup(&shop->selectedStoreItemSlot) == 1) {
                script->functionTemp[0] = DIALOG_STATE_HANDLE_CHECK_CHOICE;
                script->functionTemp[1] = 15;
            }
            break;
        case DIALOG_STATE_HANDLE_CHECK_CHOICE:
            if (script->functionTemp[1] > 0) {
                script->functionTemp[1]--;
                break;
            }
            shop_close_item_select_popup();
            if (shop->selectedStoreItemSlot >= 0) {
                if (store_item(playerData->invItems[shop->selectedStoreItemSlot]) >= 0) {
                    playerData->invItems[shop->selectedStoreItemSlot] = 0;
                }

                if ((get_item_count() == 0) || (get_stored_empty_count() == 0)) {
                    script->functionTemp[1] = shop_owner_begin_speech(SHOP_MSG_CHECK_ACCEPTED);
                    script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                } else {
                    script->functionTemp[1] = shop_owner_begin_speech(SHOP_MSG_CHECK_MORE);
                    script->functionTemp[0] = DIALOG_STATE_INIT_CHECK_MORE_CHOICE;
                }
            } else {
                script->functionTemp[1] = shop_owner_begin_speech(SHOP_MSG_FAREWELL);
                script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
            }
            break;
        case DIALOG_STATE_INIT_CHECK_MORE_CHOICE:
            if (!does_script_exist(script->functionTemp[1])) {
                script->functionTemp[0] = DIALOG_STATE_AWAIT_CHECK_MORE_CHOICE;
                script->functionTemp[2] = 0;
                D_80286538 = msg_get_printer_for_msg(MSG_Choice_0005, &script->functionTemp[2]);
            }
            break;
        case DIALOG_STATE_AWAIT_CHECK_MORE_CHOICE:
            if (script->functionTemp[2] == 1) {
                if (D_80286538->currentOption == 0) {
                    script->functionTemp[1] = shop_owner_end_speech();
                    script->functionTemp[0] = DIALOG_STATE_INIT_CHECK_CHOICE;
                } else {
                    script->functionTemp[1] = shop_owner_reset_speech(SHOP_MSG_FAREWELL);
                    script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                }
            }
            break;
        case DIALOG_STATE_INIT_CLAIM_CHOICE:
            if (!does_script_exist(script->functionTemp[1])) {
                shop_open_item_select_popup(2);
                script->functionTemp[0] = DIALOG_STATE_AWAIT_CLAIM_CHOICE;
            }
            break;
        case DIALOG_STATE_AWAIT_CLAIM_CHOICE:
            if (shop_update_item_select_popup(&shop->selectedStoreItemSlot) == 1) {
                script->functionTemp[0] = DIALOG_STATE_HANDLE_CLAIM_CHOICE;
                script->functionTemp[1] = 15;
            }
            break;
        case DIALOG_STATE_HANDLE_CLAIM_CHOICE:
            if (script->functionTemp[1] > 0) {
                script->functionTemp[1]--;
                break;
            }
            shop_close_item_select_popup();
            if (shop->selectedStoreItemSlot >= 0) {
                if (add_item(playerData->storedItems[shop->selectedStoreItemSlot]) >= 0) {
                    playerData->storedItems[shop->selectedStoreItemSlot] = 0;
                }

                if (get_item_empty_count() == 0 || get_stored_count() == 0) {
                    script->functionTemp[1] = shop_owner_begin_speech(SHOP_MSG_CLAIM_ACCEPTED);
                    script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                } else {
                    script->functionTemp[1] = shop_owner_begin_speech(SHOP_MSG_CLAIM_MORE);
                    script->functionTemp[0] = DIALOG_STATE_INIT_CLAIM_MORE_CHOICE;
                }
            } else {
                script->functionTemp[1] = shop_owner_begin_speech(SHOP_MSG_FAREWELL);
                script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
            }
            break;
        case DIALOG_STATE_INIT_CLAIM_MORE_CHOICE:
            if (!does_script_exist(script->functionTemp[1])) {
                script->functionTemp[0] = DIALOG_STATE_AWAIT_CLAIM_MORE_CHOICE;
                script->functionTemp[2] = 0;
                D_80286538 = msg_get_printer_for_msg(MSG_Choice_0005, &script->functionTemp[2]);
            }
            break;
        case DIALOG_STATE_AWAIT_CLAIM_MORE_CHOICE:
            if (script->functionTemp[2] == 1) {
                if (D_80286538->currentOption == 0) {
                    script->functionTemp[1] = shop_owner_end_speech();
                    script->functionTemp[0] = DIALOG_STATE_INIT_CLAIM_CHOICE;
                } else {
                    script->functionTemp[1] = shop_owner_reset_speech(SHOP_MSG_FAREWELL);
                    script->functionTemp[0] = DIALOG_STATE_CLOSED_SUBMENU;
                }
            }
            break;
        case DIALOG_STATE_DONE_INSTRUCTIONS:
        case DIALOG_STATE_CLOSED_SUBMENU:
        case DIALOG_STATE_CLOSED_MAIN_MENU:
            if (!does_script_exist(script->functionTemp[1])) {
                script->functionTemp[0] = DIALOG_STATE_DONE;
            }
            break;
        case DIALOG_STATE_DONE:
            if (shop->owner != NULL) {
                if (shop->owner->onTalkEvt != 0) {
                    start_script(shop->owner->onTalkEvt, EVT_PRIORITY_1, 0);
                }
            }
            open_status_menu_short();
            return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

void shop_draw_item_name(s32 arg0, s32 posX, s32 posY) {
    Shop* shop = gGameStatusPtr->mapShop;
    ShopItemData* siItem = &shop->staticInventory[shop->currentItemSlot];
    ItemData* shopItem = &gItemTable[siItem->itemID];

    draw_msg(shopItem->nameMsg, posX + 60 - (get_msg_width(shopItem->nameMsg, 0) >> 1), posY + 6, 255, MSG_PAL_WHITE, 0);
}

void shop_draw_item_desc(s32 arg0, s32 posX, s32 posY) {
    Shop* shop = gGameStatusPtr->mapShop;
    ShopItemData* shopItem = &shop->staticInventory[shop->currentItemSlot];

    draw_msg(shopItem->descMsg, posX + 8, posY, 255, MSG_PAL_STANDARD, 0);
}

void draw_shop_items(void) {
    Shop* shop = gGameStatusPtr->mapShop;
    ShopItemData* itemData;
    Camera* camera;
    s32 i;
    s32 xTemp;
    s32 yTemp;
    s32 xOffset;
    f32 x, y, z, s;
    f32 inX, inY, inZ;
    ShopItemEntity* shopItemEntities;

    if (shop->flags & SHOP_FLAG_1) {
        set_window_update(WINDOW_ID_10, (s32) basic_window_update);
        set_window_update(WINDOW_ID_11, (s32) basic_window_update);
    } else {
        set_window_update(WINDOW_ID_10, (s32) basic_hidden_window_update);
        set_window_update(WINDOW_ID_11, (s32) basic_hidden_window_update);
    }

    if (shop->flags & SHOP_FLAG_1) {
        camera = &gCameras[gCurrentCameraID];
        itemData = shop->staticInventory;
        shopItemEntities = gGameStatusPtr->shopItemEntities;

        for (i = 0; i < shop->numItems; i++, itemData++, shopItemEntities++) {
            inX = shopItemEntities->pos.x;
            inY = shopItemEntities->pos.y + 30.0f;
            inZ = shopItemEntities->pos.z;

            transform_point(camera->perspectiveMatrix, inX, inY, inZ, 1.0f, &x, &y, &z, &s);

            s = 1.0f / s;

            x *= s;
            y *= -s;
            z = (z * s + 1.0f) * 0.5;

            if (z > 0.0f && z < 1.0f) {
                xTemp = (((x * camera->viewportW) + camera->viewportW) * 0.5) + camera->viewportStartX;
                yTemp = (((y * camera->viewportH) + camera->viewportH) * 0.5) + camera->viewportStartY;

                if (itemData->price < 100) {
                    xOffset = -4;
                } else {
                    xOffset = 0;
                }

                if (!(get_item_entity(shopItemEntities->index)->flags & ITEM_ENTITY_FLAG_HIDDEN)) {
                    draw_number(itemData->price, xTemp + xOffset, yTemp, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, 255, 0);
                }

                if (i == shop->currentItemSlot) {
                    hud_element_set_render_pos(shop->costIconID, (xTemp + xOffset) - 6, yTemp + 5);
                    hud_element_set_scale(shop->costIconID, 0.7f);
                    hud_element_draw_clipped(shop->costIconID);
                }
            }
        }
    }

    if (shop->unk_358 > 0) {
        shop->unk_358--;
    } else {
        shop->flags &= ~SHOP_FLAG_1;
        func_800E9900();
    }
}

// This should be equivalent to the original code but there is some funny business with
// the evt_get_variable's at the beginning that makes absolutely no sense.
#ifdef NON_MATCHING
API_CALLABLE(MakeShop) {
    Bytecode* args = script->ptrReadPos;
    ShopItemLocation* itemDataPositions;
    ShopItemData* inventory;
    ShopSellPriceData* prices;
    s32 inventoryItemFlags;
    Shop* shop;
    Model* model;
    s32 numShopItems;
    f32 centerX;
    f32 centerY;
    f32 centerZ;
    f32 sizeX;
    f32 sizeY;
    f32 sizeZ;

    itemDataPositions = evt_get_variable(script, *args++);
    inventory = evt_get_variable(script, *args++);
    prices = evt_get_variable(script, *args++);
    inventoryItemFlags = evt_get_variable(script, *args++);

    shop = heap_malloc(sizeof(*shop));

    gGameStatusPtr->mapShop = shop;
    shop->itemDataPositions = itemDataPositions;
    shop->staticInventory = inventory;
    shop->staticPriceList = prices;
    shop->inventoryItemFlags = inventoryItemFlags;

    numShopItems = 0;
    while (inventory->itemID != 0) {
        numShopItems++;
        inventory++;
    }
    shop->numItems = numShopItems;

    numShopItems = 0;
    if (prices != NULL) {
        while (prices->itemID != 0) {
            numShopItems++;
            prices++;
        }
    }
    shop->numSpecialPrices = numShopItems;

    if (shop->numItems > 0) {
        gGameStatusPtr->shopItemEntities = heap_malloc(sizeof(ShopItemEntity) * shop->numItems);
    }

    inventory = shop->staticInventory;
    itemDataPositions = shop->itemDataPositions;
    numShopItems = 0;
    while (inventory->itemID != 0) {
        get_model_center_and_size(itemDataPositions->posModelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
        centerY += 6;
        gGameStatusPtr->shopItemEntities[numShopItems].pos.x = centerX;
        gGameStatusPtr->shopItemEntities[numShopItems].pos.y = centerY;
        gGameStatusPtr->shopItemEntities[numShopItems].pos.z = centerZ;
        model = get_model_from_list_index(get_model_list_index_from_tree_index(itemDataPositions->posModelID));
        model->flags |= MODEL_FLAG_FLAG_4;
        gGameStatusPtr->shopItemEntities[numShopItems].index =
            make_item_entity_nodelay(inventory->itemID | shop->inventoryItemFlags, centerX, centerY, centerZ, 1, 0);
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[numShopItems].index, 0x4000);
        bind_trigger_1(D_80283F58_7E4DD8, 0x80, itemDataPositions->triggerColliderID, numShopItems, 0, 3);
        bind_trigger_1(D_80283F58_7E4DD8, 0x800, itemDataPositions->triggerColliderID, numShopItems, 0, 3);
        itemDataPositions++;
        inventory++;
        numShopItems++;
    }

    shop->costIconID = hud_element_create(&HES_Item_Coin);
    hud_element_set_flags(shop->costIconID, HUD_ELEMENT_FLAG_80);
    hud_element_clear_flags(shop->costIconID, HUD_ELEMENT_FLAG_FILTER_TEX);
    get_worker(create_worker_frontUI(NULL, draw_shop_items));
    set_window_properties(WINDOW_ID_10, 100, 66, 120, 28, 0, shop_draw_item_name, NULL, -1);
    set_window_properties(WINDOW_ID_11, 32, 184, 256, 32, 1, shop_draw_item_desc, NULL, -1);
    gWindowStyles[10].defaultStyleID = WINDOW_STYLE_9;
    gWindowStyles[11].defaultStyleID = WINDOW_STYLE_3;
    shop->currentItemSlot = 0;
    shop->selectedStoreItemSlot = 0;
    shop->flags = SHOP_FLAG_0;
    shop->owner = NULL;

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "world/script_api/shops", MakeShop, Evt* script, s32 isInitialCall);
#endif

API_CALLABLE(MakeShopOwner) {
    Shop* mapShop = gGameStatusPtr->mapShop;

    mapShop->owner = (ShopOwner*) evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
