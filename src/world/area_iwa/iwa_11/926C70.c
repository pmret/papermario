#include "iwa_11.h"

extern s32 D_80242148_928B38[14][7];

s32 func_80240280_926C70(Evt* script, s32 isInitialCall) {
    s32 value = script->varTable[0];
    s32 index, i;
    
    for (i = 0; i < 14; i++) {
        if (value < D_80242148_928B38[i][0]) {
            break;
        }
    }
    index = i - 1;
    
    for (i = 0; i < 6; i++) {
        script->varTable[i + 5] = D_80242148_928B38[index][i + 1];
    }
    
    return ApiStatus_DONE2;
}
