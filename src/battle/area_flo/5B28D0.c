#include "common.h"

#define NAMESPACE b_area_flo

extern char* D_80233564_5CCA14[];
extern char* D_80233870_5CCD20[];
extern char* D_80233950_5CCE00[];
extern char* D_80231678_5CAB28[];
extern char* D_80231B08_5CAFB8[];
extern char* D_802328D8_5CBD88[];
extern char* D_80232BE8_5CC098[];
extern char* D_802311D8_5CA688[];
extern char* D_80231FA8_5CB458[];
extern char* D_80232428_5CB8D8[];

ApiStatus func_80219420_5B28D0(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 counter;

    for (counter = 0; counter < 11; counter++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_802311D8_5CA688[counter]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_802194E0_5B2990(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 counter;

    for (counter = 0; counter < 11; counter++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80231678_5CAB28[counter]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_802195A0_5B2A50(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 counter;

    for (counter = 0; counter < 11; counter++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80231B08_5CAFB8[counter]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80219660_5B2B10(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 counter;

    for (counter = 0; counter < 11; counter++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80231FA8_5CB458[counter]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80219720_5B2BD0(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 counter;

    for (counter = 0; counter < 11; counter++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_802311D8_5CA688[counter]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_802197E0_5B2C90(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 counter;

    for (counter = 0; counter < 11; counter++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_802328D8_5CBD88[counter]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_802198A0_5B2D50(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 counter;

    for (counter = 0; counter < 11; counter++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80232BE8_5CC098[counter]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

#define NAMESPACE dup_b_area_flo
#include "common/UnkFloatFunc.inc.c"
#define NAMESPACE b_area_flo

#define NAMESPACE dup2_b_area_flo
#include "common/UnkFloatFunc.inc.c"
#define NAMESPACE b_area_flo

ApiStatus func_80219C80_5B3130(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 counter;

    for (counter = 0; counter < 11; counter++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80233564_5CCA14[counter]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80219D40_5B31F0(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 counter;

    for (counter = 0; counter < 11; counter++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80233870_5CCD20[counter]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80219E00_5B32B0(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 counter;

    for (counter = 0; counter < 11; counter++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80232428_5CB8D8[counter]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}
