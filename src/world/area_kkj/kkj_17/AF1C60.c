#include "kkj_17.h"
#include "hud_element.h"

extern s32 D_8024092C_AF258C[5];
extern IconHudScriptPair gItemHudScripts[];

static char* N(exit_str_0) = "kkj_11";
static char* N(exit_str_1) = "";

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/SomeItemEntityFunc.inc.c"

#include "world/common/todo/IsItemBadge.inc.c"

ApiStatus func_802402BC_AF1F1C(Evt* script, s32 isInitialCall) {
    PopupMenu *menu;
    s32 menuIdx;
    s32 index;
    s32 var1;
    s32 var2;
    s32 i;

    if (isInitialCall) {
        menu = heap_malloc(sizeof(*menu));
        script->functionTempPtr[2] = menu;
        script->varTable[10] = script->varTable[0];

        if (script->varTable[0] == 0) {
            script->varTable[1] = GF_KKJ16_Item_PowerRush;
            script->varTable[2] = GF_KKJ_Stored_PowerRush;
            menu->popupType = POPUP_MENU_USEKEY;
        } else {
            script->varTable[1] = GF_KKJ_Stored_PowerRush;
            script->varTable[2] = GF_KKJ_Retrieved_PowerRush;
            menu->popupType = POPUP_MENU_TAKE_FROM_CHEST;
        }

        menuIdx = 0;
        for (i = 0; i < ARRAY_COUNT(D_8024092C_AF258C); i++) {
            var1 = evt_get_variable(NULL, script->varTable[1] + i);
            var2 = evt_get_variable(NULL, script->varTable[2] + i);
            if ((var1 != 0) && (var2 == 0)) {
                ItemData* item = &gItemTable[D_8024092C_AF258C[i]];
                IconHudScriptPair* itemHudScripts = &gItemHudScripts[item->hudElemID];
                menu->ptrIcon[menuIdx] = itemHudScripts->enabled;
                menu->userIndex[menuIdx] = i;
                menu->enabled[menuIdx] = TRUE;
                menu->nameMsg[menuIdx] = item->nameMsg;
                menu->descMsg[menuIdx] = item->shortDescMsg;
                menuIdx++;
            }
        }

        if (menuIdx == 0) {
            script->varTable[0] = 0;
            return ApiStatus_DONE1;
        }

        menu->numEntries = menuIdx;
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

    if (script->functionTemp[1] == 255) {
        script->varTable[0] = -1;
    } else {
        index = menu->userIndex[script->functionTemp[1] - 1];
        script->varTable[0] = D_8024092C_AF258C[index];
        if (script->varTable[10] == 0) {
            evt_set_variable(NULL, script->varTable[2] + index, 1);
        }
        heap_free(script->functionTempPtr[2]);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80240500_AF2160(Evt* script, s32 isInitialCall) {
    s32* ptr = D_8024092C_AF258C;
    s32 found = FALSE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024092C_AF258C); i++) {
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
