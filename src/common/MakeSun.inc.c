#include "common.h"
#include "effects.h"
#include "gcc/string.h"

char* N(RightSunMaps)[] = {
    "flo_03",
    "flo_08",
    "flo_09",
    "flo_10",
    "flo_16",
    "flo_17",
    "flo_18",
    "flo_19",
    "flo_21",
    "flo_22",
    "flo_24",
};

API_CALLABLE(N(SpawnSunEffect)) {
    s32 direction = FX_SUN_FROM_LEFT;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(RightSunMaps)); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, N(RightSunMaps)[i]) == 0) {
            direction = FX_SUN_FROM_RIGHT;
            break;
        }
    }

    fx_sun(direction, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(MakeSun) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
