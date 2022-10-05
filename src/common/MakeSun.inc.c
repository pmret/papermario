#include "common.h"
#include "effects.h"

char* N(sunny_areas)[] = {
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

ApiStatus N(make_sun)(Evt* script, s32 isInitialCall) {
    s32 var1 = FALSE;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(sunny_areas)); i++) {
        if (strcmp(gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID].id, N(sunny_areas)[i]) == 0) {
            var1 = TRUE;
            break;
        }
    }

    fx_sun(var1, 0, 0, 0, 0, 0);

    return ApiStatus_DONE2;
}

EvtScript N(MakeSun) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(make_sun))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
