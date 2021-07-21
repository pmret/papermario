#include "common.h"

#define NAMESPACE b_area_flo2

extern char* D_80232D48_5E93D8[11];
extern char* D_802331E8_5E9878[11];
extern char* D_80233678_5E9D08[11];
extern char* D_80233F98_5EA628[11];
extern char* D_802353E0_5EBA70[11];
extern char* D_802354C0_5EBB50[11];
extern char* D_80233B18_5EA1A8[11];
extern char* D_80234448_5EAAD8[11];
extern char* D_80234758_5EADE8[11];
extern char* D_802350D4_5EB764[11];

#define NAMESPACE dup_b_area_flo2
#include "common/UnkFloatFunc.inc.c"
#define NAMESPACE b_area_flo2

ApiStatus func_80218DD0_5CF460(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_80232D48_5E93D8); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80232D48_5E93D8[i]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80218E90_5CF520(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_802331E8_5E9878); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_802331E8_5E9878[i]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80218F50_5CF5E0(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_80233678_5E9D08); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80233678_5E9D08[i]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80219010_5CF6A0(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_80233B18_5EA1A8); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80233B18_5EA1A8[i]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_802190D0_5CF760(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_80233F98_5EA628); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80233F98_5EA628[i]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80219190_5CF820(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_80234448_5EAAD8); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80234448_5EAAD8[i]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80219250_5CF8E0(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_80234758_5EADE8); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_80234758_5EADE8[i]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

#define NAMESPACE dup2_b_area_flo2
#include "common/UnkFloatFunc.inc.c"
#define NAMESPACE b_area_flo2

#define NAMESPACE dup3_b_area_flo2
#include "common/UnkFloatFunc.inc.c"
#define NAMESPACE b_area_flo2

ApiStatus func_80219630_5CFCC0(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_802350D4_5EB764); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_802350D4_5EB764[i]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_802196F0_5CFD80(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_802353E0_5EBA70); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_802353E0_5EBA70[i]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_802197B0_5CFE40(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_802354C0_5EBB50); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, D_802354C0_5EBB50[i]) == 0) {
            var1 = 1;
            break;
        }
    }

    playFX_82(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}
