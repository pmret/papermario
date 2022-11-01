#include "hos_06.h"
#include "hud_element.h"


#define NAMESPACE dup2_hos_06
#include "world/common/todo/StashVars.inc.c"
#define NAMESPACE hos_06

#define NAMESPACE dup_hos_06
#include "world/common/todo/GetItemName.inc.c"
#define NAMESPACE hos_06

#include "world/common/todo/SomeItemEntityFunc.inc.c"

#include "world/common/todo/IsItemBadge.inc.c"

extern IconHudScriptPair gItemHudScripts[];
extern s32 D_80245EEC_A3F3CC[5];

ApiStatus func_8024228C_A3B76C(Evt* script, s32 isInitialCall) {
    PopupMenu *menu;
    s32 numEntries;
    s32 index;
    s32 temp;
    s32 var1;
    s32 var2;
    s32 i;

    if (isInitialCall) {
        menu = heap_malloc(sizeof(*menu));
        script->functionTempPtr[2] = menu;
        temp = script->varTable[0];
        script->varTable[10] = script->varTable[0];

        if (temp == 0) {
            script->varTable[1] = GF_KKJ16_Item_PowerRush;
            script->varTable[2] = GF_KKJ_Stored_PowerRush;
            menu->popupType = POPUP_MENU_USEKEY;
        } else {
            script->varTable[1] = GF_KKJ_Stored_PowerRush;
            script->varTable[2] = GF_KKJ_Retrieved_PowerRush;
            menu->popupType = POPUP_MENU_TAKE_FROM_CHEST;
        }

        numEntries = 0;
        for (i = 0; i < ARRAY_COUNT(D_80245EEC_A3F3CC); i++) {
            var1 = evt_get_variable(NULL, script->varTable[1] + i);
            var2 = evt_get_variable(NULL, script->varTable[2] + i);
            if (var1 != 0 && var2 == 0) {
                ItemData* item = &gItemTable[D_80245EEC_A3F3CC[i]];
                IconHudScriptPair* itemHudScripts = &gItemHudScripts[item->hudElemID];
                menu->ptrIcon[numEntries] = itemHudScripts->enabled;
                menu->userIndex[numEntries] = i;
                menu->enabled[numEntries] = TRUE;
                menu->nameMsg[numEntries] = item->nameMsg;
                menu->descMsg[numEntries] = item->shortDescMsg;
                numEntries++;
            }
        }

        if (numEntries == 0) {
            script->varTable[0] = 0;
            return ApiStatus_DONE1;
        }

        menu->numEntries = numEntries;
        menu->initialPos = 0;
        create_popup_menu(menu);
        script->functionTemp[0] = 0;
    }

    menu = script->functionTempPtr[2];
    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = menu->result;
        if (script->functionTemp[1] == 0) {
            return ApiStatus_BLOCK;
        }
        hide_popup_menu();
    }

    script->functionTemp[0]++;
    if (script->functionTemp[0] < 15) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();

    temp = script->functionTemp[1];
    if (temp == 255) {
        script->varTable[0] = -1;
    } else {
        index = menu->userIndex[temp - 1];
        script->varTable[0] = D_80245EEC_A3F3CC[index];
        if (script->varTable[10] == 0) {
            evt_set_variable(NULL, script->varTable[2] + index, 1);
        }
        heap_free(script->functionTempPtr[2]);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802424CC_A3B9AC(Evt* script, s32 isInitialCall) {
    s32* ptr = D_80245EEC_A3F3CC;
    s32 found = FALSE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80245EEC_A3F3CC); i++) {
        s32 var = ptr[i];

        if (script->varTable[0] == var) {
            found = TRUE;
            break;
        }
    }

    if (found) {
        evt_set_variable(NULL, GF_KKJ_Retrieved_PowerRush + i, TRUE);
    }

    return ApiStatus_DONE2;
}

#include "world/common/todo/GetItemEmptyCount.inc.c"
