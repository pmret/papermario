#include "flo_08.h"

extern s32 wPartnerHudScripts[];
extern s32 wDisabledPartnerHudScripts[];
extern s32 gPartnerPopupProperties[11][4];

#include "world/common/atomic/SuperBlock.inc.c"

#ifdef NON_EQUIVALENT
typedef struct {
    s32 unk_00[8];
    char unk_20[0x64];
    s32 unk_84[8];
    char unk_A4[0x64];
    s32 unk_108[8];
    char unk_128[0x64];
    s32 unk_18C[8];
    char unk_1AC[0x64];
    s32 unk_210[8];
    char unk_230[0x64];
    s32 unk_294[8];
    char unk_2B4[0x64];
    s32 unk_318;
    char unk_31C[8];
    s32 unk_324;
    s32 unk_328;
    s16 unk_32C;
} N(UnkStruct);

ApiStatus N(func_802401CC_CAEF0C)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    N(UnkStruct)* ptr;
    s32 i;
    s32 partnerLevel;
    s32 var, partnerActiveCount;
    s32 idx;

    if (isInitialCall) {
        script->functionTemp[2] = heap_malloc(0x330);
        ptr = script->functionTemp[2];

        partnerActiveCount = 0;
        var = script->varTable[12] >= 0;

        for (i = 0; i < 8; i++) {
            idx = N(SuperBlockDataB)[i];

            if (playerData->partners[idx].enabled) {
                ptr->unk_108[i] = idx;
                ptr->unk_84[i] = *gPartnerPopupProperties[idx];
                partnerLevel = N(UnkFunc37)(idx, var);
                if (partnerLevel >= 0) {
                    ptr->unk_00[i] = wPartnerHudScripts[idx];
                    ptr->unk_18C[i] = 1;
                    ptr->unk_294[i] = N(SuperBlockDataC)[i][partnerLevel];
                } else {
                    ptr->unk_00[i] = wDisabledPartnerHudScripts[idx];
                    ptr->unk_18C[i] = 0;
                    ptr->unk_294[i] = N(SuperBlockDataA)[var];
                }
                ptr->unk_210[i] = playerData->partners[idx].level;
                partnerActiveCount++;
            }
        }

        ptr->unk_318 = 4;
        ptr->unk_324 = partnerActiveCount;
        ptr->unk_328 = 0;
        create_popup_menu(ptr);
        script->functionTemp[0] = 0;
    }

    ptr = script->functionTemp[2];
    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = ptr->unk_32C;
        if (script->functionTemp[1] != 0) {
            hide_popup_menu();
        } else {
            return ApiStatus_BLOCK;
        }
    }

    script->functionTemp[0]++;

    if (script->functionTemp[0] < 15) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();
    if (script->functionTemp[1] != 0xFF) {
        script->varTable[0] = gPartnerPopupProperties[ptr->unk_108[script->functionTemp[1] - 1]][0];
        script->varTable[1] = ptr->unk_108[script->functionTemp[1] - 1];
    } else {
        script->varTable[0] = -1;
    }

    heap_free(script->functionTemp[2]);

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "world/area_flo/flo_08/CAED40", flo_08_func_802401CC_CAEF0C, Evt* script,
            s32 isInitialCall);
#endif

#include "world/common/atomic/SuperBlockB.inc.c"
