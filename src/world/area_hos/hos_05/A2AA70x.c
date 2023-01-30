#include "hos_05.h"

API_CALLABLE(N(func_80240830_A2AA70)) {
    gPlayerData.starBeamLevel = 1;
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    gPlayerData.specialBarsFilled = gPlayerData.maxStarPower * 256;
    sync_status_menu();
    return ApiStatus_DONE2;
}
