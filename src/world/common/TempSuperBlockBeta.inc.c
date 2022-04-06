#include "common.h"
#include "hud_element.h"

extern s32 gPartnerPopupProperties[11][4];

ApiStatus N(TempSuperBlockBeta)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PopupMenu* popupMenu;
    s32 partnerID;
    s32 canUpgradePartner;
    s32 hasUltraStone;
    s32 entryIndex;
    s32 i;

    // create the 'partner upgrade' popup menu
    if (isInitialCall) {
        popupMenu = heap_malloc(0x330);
        script->functionTempPtr[2] = popupMenu;
        hasUltraStone = script->varTable[0xC] >= 0;

        // build the popup menu entries from unlocked partners
        entryIndex = 0;
        for (i = 0; i < 8; i++) { // ARRAY_COUNT(N(SuperBlockDataB))
            partnerID = N(SuperBlockDataB)[i]; // upgradeable partner IDs
            if (playerData->partners[partnerID].enabled) {
                popupMenu->userIndex[entryIndex] = partnerID;
                popupMenu->nameMsg[entryIndex] = gPartnerPopupProperties[partnerID][0];
                canUpgradePartner = N(UnkFunc37)(partnerID, hasUltraStone);
                if (canUpgradePartner >= 0) {
                    popupMenu->ptrIcon[entryIndex] = wPartnerHudScripts[partnerID];
                    popupMenu->enabled[entryIndex] = TRUE;
                    popupMenu->descMsg[entryIndex] = N(SuperBlockDataC)[i][canUpgradePartner];
                } else {
                    popupMenu->ptrIcon[entryIndex] = wDisabledPartnerHudScripts[partnerID];
                    popupMenu->enabled[entryIndex] = FALSE;
                    popupMenu->descMsg[entryIndex] = N(SuperBlockDataA)[hasUltraStone];
                }
                popupMenu->value[entryIndex] = playerData->partners[partnerID].level;
                entryIndex++;
            }
        }

        popupMenu->popupType = 4;
        popupMenu->numEntries = entryIndex;
        popupMenu->initialPos = 0;
        create_popup_menu(popupMenu);
        script->functionTemp[0] = 0;
    }

    // wait for player to close popup
    popupMenu = script->functionTempPtr[2];
    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = popupMenu->result;
        if (script->functionTemp[1] == 0) {
            return ApiStatus_BLOCK;
        }
        hide_popup_menu();
    }
    
    // wait for popup to hide
    script->functionTemp[0]++;
    if (script->functionTemp[0] < 0xF) {
        return ApiStatus_BLOCK;
    }
    destroy_popup_menu();
    
    if (script->functionTemp[1] != 0xFF) {
        script->varTable[0] = gPartnerPopupProperties[popupMenu->userIndex[script->functionTemp[1] - 1]][0];
        script->varTable[1] = popupMenu->userIndex[script->functionTemp[1] - 1];
    } else {
        script->varTable[0] = -1;
    }
        
    heap_free(script->functionTempPtr[2]);
    return ApiStatus_DONE2;
}
