#include "hos_06.h"
#include "hud_element.h"

extern ShopItemData D_802435EC_A3CACC[];
extern IconHudScriptPair gItemHudScripts[];

#include "world/common/todo/StashVars.inc.c"

#define NAMESPACE dup2_hos_06
#include "world/common/todo/GetItemName.inc.c"
#define NAMESPACE hos_06

#define NAMESPACE dup_hos_06
#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"
#define NAMESPACE hos_06

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240654_A39B34);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 hos_06_D_80246260[];

ApiStatus func_802406E0_A39BC0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            hos_06_D_80246260[i] = ptr[i];
        }
        hos_06_D_80246260[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            hos_06_D_80246260[i] = i + 16;
            hos_06_D_80246260[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

ApiStatus Merlow_GetPlayerStarPieces(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.starPieces);
    return ApiStatus_DONE2;
}

ApiStatus Merlow_SetBadgePurchased(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    evt_set_variable(NULL, GF_HOS06_MerlowBadge_00 + index, TRUE);
    return ApiStatus_DONE2;
}

ApiStatus Merlow_ShopBadgesPopup(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PopupMenu* menu;
    s32 selected, menuPos, i;

    if (isInitialCall) {
        script->functionTempPtr[2] = heap_malloc(sizeof(*menu));
        menu = script->functionTempPtr[2];
        menuPos = 0;
        for (i = 0; i < 15; i++) {
            if (!evt_get_variable(NULL, GF_HOS06_MerlowBadge_00 + i)) {
                ItemData* item = &gItemTable[D_802435EC_A3CACC[i].itemID];
                IconHudScriptPair* itemHudScripts = &gItemHudScripts[item->hudElemID];
                menu->userIndex[menuPos] = i;
                menu->nameMsg[menuPos] = item->nameMsg;
                menu->ptrIcon[menuPos] = itemHudScripts->enabled;
                menu->enabled[menuPos] = playerData->starPieces >= D_802435EC_A3CACC[i].price;
                if (playerData->starPieces < D_802435EC_A3CACC[i].price) {
                    menu->ptrIcon[menuPos] = itemHudScripts->disabled;
                    menu->enabled[menuPos] = FALSE;
                }
                menu->descMsg[menuPos] = D_802435EC_A3CACC[i].descMsg;
                menu->value[menuPos] = D_802435EC_A3CACC[i].price;
                menuPos++;
            }
        }
        menu->popupType = POPUP_MENU_TRADE_FOR_BADGE;
        menu->numEntries = menuPos;
        menu->initialPos = 0;
        create_popup_menu(menu);
        script->functionTemp[0] = 0;
    }

    menu = script->functionTempPtr[2];
    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = menu->result;
        if (script->functionTemp[1] != 0) {
            hide_popup_menu();
        } else {
            return ApiStatus_BLOCK;
        }
    }
    script->functionTemp[0]++;
    if (script->functionTemp[0] < 20) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();
    selected = script->functionTemp[1];
    if (selected != 0xFF) {
        ShopItemData* selectedItem;
        i = menu->userIndex[selected - 1];
        selectedItem = &D_802435EC_A3CACC[i];
        script->varTable[0] = selectedItem->itemID;
        script->varTable[1] = selectedItem->price;
        script->varTable[2] = i;
        script->varTable[4] = gItemTable[selectedItem->itemID].nameMsg;
        script->varTable[5] = gMoveTable[gItemTable[selectedItem->itemID].moveID].costBP;
    } else {
        script->varTable[0] = -1;
    }

    heap_free(script->functionTempPtr[2]);
    return ApiStatus_DONE2;
}
