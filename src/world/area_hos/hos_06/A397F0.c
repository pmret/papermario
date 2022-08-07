#include "hos_06.h"
#include "hud_element.h"

extern ShopItemData D_802435EC_A3CACC[];
extern IconHudScriptPair gItemHudScripts[];

#include "world/common/StashVars.inc.c"

#define NAMESPACE dup2_hos_06
#include "world/common/GetItemName.inc.c"
#define NAMESPACE hos_06

#define NAMESPACE dup_hos_06
#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"
#define NAMESPACE hos_06

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_80240654_A39B34);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_802406A8_A39B88);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A397F0", func_802406E0_A39BC0);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

ApiStatus Merlow_GetPlayerStarPieces(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.starPieces);
    return ApiStatus_DONE2;
}

ApiStatus Merlow_SetBadgePurchased(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    evt_set_variable(NULL, GSWF(1771) + index, TRUE);
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
            if (!evt_get_variable(NULL, GSWF(1771) + i)) {
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
