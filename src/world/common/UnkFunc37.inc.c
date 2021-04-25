#include "common.h"
#include "map.h"

s32 N(UnkFunc37)(s32 idx, s16 arg1) {
    if (!gPlayerData.partners[idx].enabled) {
        return -1;
    }

    if (gPlayerData.partners[idx].level <= arg1) {
        return gPlayerData.partners[idx].level;
    }

    return -1;
}