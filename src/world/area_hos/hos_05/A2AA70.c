#include "hos_05.h"

ApiStatus func_80240830_A2AA70(Evt* script, s32 isInitialCall) {
    gPlayerData.starBeamLevel = 1;
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    gPlayerData.specialBarsFilled = gPlayerData.maxStarPower * 256;
    sync_status_menu();
    return ApiStatus_DONE2;
}
