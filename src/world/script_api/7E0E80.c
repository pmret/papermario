#include "common.h"

extern s32 MessagePlural;
extern s32 MessageSingular;

extern s32 D_80286520;
extern s32 D_80286524;

ApiStatus func_802803C8(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_80280410(ScriptInstance* script, s32 isInitialCall);
ApiStatus ShowShopPurchaseDialog(ScriptInstance* script, s32 isInitialCall);
ApiStatus ShowShopOwnerDialog(ScriptInstance* script, s32 isInitialCall);

s32 D_80283E80_7E4D00[] = { 0x00000043, 0x00000006, SpeakToPlayer, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000000, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 D_80283EB0_7E4D30[] = { 0x00000043, 0x00000006, ContinueSpeech, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000000, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 D_80283EE0_7E4D60[] = { 0x00000043, 0x00000005, EndSpeech, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000000, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 D_80283F2C_7E4DAC[] = { 0x00000043, 0x00000005, EndSpeech, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 D_80283F58_7E4DD8[] = { 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000002, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000003, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000001, func_802803C8, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, func_80280410, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 D_80284034_7E4EB4[] = { 0x00000043, 0x00000002, ShowShopPurchaseDialog, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000001, ShowShopOwnerDialog, 0x00000002, 0x00000000, 0x00000001, 0x00000000, };

s32 shop_owner_begin_speech(s32 messageIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopStringID = shop->owner->shopStringIDs[messageIndex];
    ScriptInstance* script = start_script(&D_80283E80_7E4D00, 1, 0);

    script->varTable[0] = shopStringID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_buy_dialog(s32 messageIndex, s32 itemName, s32 coinCost, s32 bpCost) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopStringID = shop->owner->shopStringIDs[messageIndex];
    ScriptInstance *script;
    s32 phi_a0;

    set_message_string(itemName, 0);
    set_message_value(coinCost, 1);

    if (bpCost > 0) {
        set_message_value(bpCost, 2);
    } else {
        if (coinCost == 1) {
            phi_a0 = &MessageSingular;
        } else {
            phi_a0 = &MessagePlural;
        }
        set_message_string(phi_a0, 2);
    }

    script = start_script(&D_80283E80_7E4D00, 1, 0);
    script->varTable[0] = shopStringID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_continue_speech(s32 messageIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopStringID = shop->owner->shopStringIDs[messageIndex];
    ScriptInstance* script = start_script(&D_80283EB0_7E4D30, 1, 0);

    script->varTable[0] = shopStringID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->functionTemp[3].s = script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_continue_speech_with_quantity(s32 messageIndex, s32 amount) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopStringID = shop->owner->shopStringIDs[messageIndex];
    s32 phi_a0;
    ScriptInstance* script;

    set_message_value(amount, 0);

    if (amount == 1) {
        phi_a0 = &MessageSingular;
    } else {
        phi_a0 = &MessagePlural;
    }

    set_message_string(phi_a0, 1);

    script = start_script(&D_80283EB0_7E4D30, 1, 0);
    script->varTable[0] = shopStringID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->functionTemp[3].s = script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_reset_speech(s32 messageIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    s32 shopStringID = shop->owner->shopStringIDs[messageIndex];
    ScriptInstance* script = start_script(&D_80283EE0_7E4D60, 1, 0);

    script->varTable[0] = shopStringID;
    script->varTable[1] = shop->owner->npcID;
    script->varTable[2] = shop->owner->talkAnim;
    script->functionTemp[3].s = script->varTable[3] = shop->owner->idleAnim;

    return script->id;
}

s32 shop_owner_end_speech(void) {
    Shop* shop = gGameStatusPtr->mapShop;
    ScriptInstance* script = start_script(&D_80283F2C_7E4DAC, 1, 0);

    script->varTable[0] = shop->owner->npcID;
    script->varTable[1] = shop->owner->talkAnim;
    script->functionTemp[3].s = script->varTable[2] = shop->owner->idleAnim;

    return script->id;
}

ApiStatus func_802803C8(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus func_80280410(ScriptInstance* script, s32 isInitialCall) {
    static ScriptInstance* D_80286520;
    static s32 D_80286524;

    Shop* shop = gGameStatusPtr->mapShop;
    s32 currentItemSlot = get_variable(script, *script->ptrReadPos);

    if (!(shop->flags & 8)) {
        shop->currentItemSlot = currentItemSlot;
        shop->flags |= 1;
        func_800E98EC();
        shop->unk_358 = 5;

        if (gGameStatusPtr->pressedButtons & 0x8000) {

            ScriptInstance* childScript;

            disable_player_input();
            disable_player_static_collisions();

            childScript = start_script(&D_80284034_7E4EB4, 1, 0);
            childScript->varTable[0] = currentItemSlot;
            D_80286520 = childScript;
            D_80286524 = childScript->id;
            shop->flags |= 8;
            return ApiStatus_BLOCK;
        } else {
            return ApiStatus_DONE2;
        }
    } else if (does_script_exist(D_80286524)) {
        return ApiStatus_BLOCK;
    }

    shop->flags &= ~0x8;
    enable_player_static_collisions();
    enable_player_input();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(ApiStatus, "world/script_api/7E0E80", ShowShopPurchaseDialog, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "world/script_api/7E0E80", shop_open_item_select_popup);
// extern s32 D_8008A680[337][2];

// void shop_open_item_select_popup(s32 mode) {
//     Shop* shop = gGameStatusPtr->mapShop;
//     PopupMenu* menu = &shop->itemSelectMenu;
//     s32 numItemSlots;
//     s32 popupType;
//     s32 i;
//     s32 numEntries;

//     switch (mode) {
//         case 0:
//             numItemSlots = 10;
//             popupType = 5;
//             break;
//         case 1:
//             numItemSlots = 10;
//             popupType = 6;
//             break;
//         default:
//             numItemSlots = 32;
//             popupType = 7;
//     }

//     numEntries = 0;

//     for (i = 0; i < numItemSlots; i++) {
//         s32 itemID;

//         if (mode < 2) {
//             itemID = gPlayerData.invItems[i];
//         } else {
//             itemID = gPlayerData.storedItems[i];
//         }

//         if (itemID != 0) {
//             menu->ptrIcon[i] = D_8008A680[gItemTable[itemID].iconID][0];
//             menu->userIndex[i] = i;
//             menu->enabled[i] = TRUE;
//             menu->nameString[i] = gItemTable[itemID].nameString;
//             menu->descString[i] = gItemTable[itemID].itemString;
//             menu->value[i] = shop_get_sell_price(itemID);
//             numEntries++;
//         }
//     }

//     menu->popupType = popupType;
//     menu->numEntries = numEntries;
//     menu->initialPos = 0;
//     func_800F4FC4(menu);
//     func_800E9894();
//     func_800E98EC();
//     open_status_menu_short();
// }

s32 shop_update_item_select_popup(s32* selectedIndex) {
    Shop* shop = gGameStatusPtr->mapShop;
    PopupMenu* menu = &shop->itemSelectMenu;
    s16 menuResult = shop->itemSelectMenu.result;

    if (menuResult == 0) {
        return 0;
    }

    func_800F13B0();

    if (menuResult == 0xFF) {
        *selectedIndex = -1;
    } else {
        *selectedIndex = menu->userIndex[menuResult - 1];
    }

    return 1;
}

void shop_close_item_select_popup(void) {
    func_800F1538();
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

INCLUDE_ASM(ApiStatus, "world/script_api/7E0E80", ShowShopOwnerDialog, ScriptInstance* script, s32 isInitialCall);

void shop_draw_item_name(s32 arg0, s32 posX, s32 posY) {
    Shop* shop = gGameStatusPtr->mapShop;
    StaticInventoryItem* siItem = &shop->staticInventory[shop->currentItemSlot];
    StaticItem* item = &gItemTable[siItem->unk_00];

    draw_msg(item->nameString, posX + 60 - (get_string_width(item->nameString, 0) >> 1), posY + 6, 255, 0, 0);
}

void shop_draw_item_desc(s32 arg0, s32 posX, s32 posY) {
    Shop* shop = gGameStatusPtr->mapShop;
    StaticInventoryItem* item = &shop->staticInventory[shop->currentItemSlot];

    draw_msg(item->unk_08, posX + 8, posY, 255, 0xA, 0);
}

INCLUDE_ASM(s32, "world/script_api/7E0E80", shop_draw_items);
// void shop_draw_items(void) {
//     Shop* shop = gGameStatusPtr->mapShop;
//     s32* shopItemData;
//     Camera* camera;
//     s32 i;

//     f32 temp_f0;
//     f32 temp_f0_2;
//     f32 temp_f0_3;
//     f32 temp_f6;
//     s32 temp_s1;
//     s32 temp_s3;
//     s32 temp_s7;
//     s32 temp_v0;
//     UnkFunc phi_s0;
//     s32 *phi_s4;
//     char *phi_s6;
//     s32 *phi_fp;
//     s32 phi_s0_2;


//     if (shop->flags & 1) {
//         phi_s0 = basic_window_update;
//     } else {
//         phi_s0 = basic_hidden_window_update;
//     }

//     set_window_update(10, phi_s0);
//     set_window_update(11, phi_s0);

//     if (shop->flags & 1) {
//         shopItemData = gGameStatusPtr->shopItemEntities;
//         camera = &gCameras[gCurrentCameraID];

//         phi_s4 = shopItemData + 0xC;
//         phi_s6 = shop->staticInventory->unk_04;
//         phi_fp = shopItemData;

//         for (i = 0; i < shop->numItems; i++) {
//             transform_point(camera->perspectiveMatrix, phi_s4->unk-8, phi_s4->unk-4 + 30.0f, phi_s4->unk0, 1.0f, &subroutine_argA, &subroutine_argB, &subroutine_argC, &subroutine_argD);
//             temp_f6 = 1.0f / subroutine_argD;
//             temp_f0 = (f32) ((f64) ((subroutine_argC * temp_f6) + 1.0f) * 0.5);
//             if ((temp_f0 > 0.0f) && (temp_f0 < 1.0f)) {
//                 temp_f0_2 = (f32) camera->viewportW;
//                 temp_f0_3 = (f32) camera->viewportH;
//                 temp_s1 = (s32) (((f64) ((subroutine_argA * temp_f6 * temp_f0_2) + temp_f0_2) * 0.5) + (f64) camera->viewportStartX);
//                 temp_s3 = (s32) (((f64) ((subroutine_argB * -temp_f6 * temp_f0_3) + temp_f0_3) * 0.5) + (f64) camera->viewportStartY);
//                 phi_s0_2 = 0;
//                 if (*phi_s6 < 0x64) {
//                     phi_s0_2 = -4;
//                 }
//                 if ((get_item_entity(*phi_fp)->flags & 0x40) == 0) {
//                     draw_number(*phi_s6, temp_s1 + phi_s0_2, temp_s3, 1, 0, 0xFF, 0);
//                 }
//                 if (i == shop->currentItemSlot) {
//                     set_icon_render_pos((MenuIcon *) shop->costIconID, (temp_s1 + phi_s0_2) - 6, temp_s3 + 5);
//                     func_80144C20(shop->costIconID, 0x3F333333);
//                     draw_icon_0(shop->costIconID);
//                 }
//             }
//         }
//             phi_s4 = phi_s4 + 0x10;
//             phi_s6 = phi_s6 + 0xC;
//             phi_fp = phi_fp + 0x10;
//         }
//     }
//     temp_v0 = shop->unk_358;
//     if (temp_v0 > 0) {
//         shop->unk_358 = temp_v0 - 1;
//         return;
//     }
//     shop->flags = (u16) shop->flags & 0xFFFE;
//     func_800E9900();
// }

INCLUDE_ASM(ApiStatus, "world/script_api/7E0E80", MakeShop, ScriptInstance* script, s32 isInitialCall);

ApiStatus MakeShopOwner(ScriptInstance* script, s32 isInitialCall) {
    Shop* mapShop = gGameStatusPtr->mapShop;

    mapShop->owner = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
