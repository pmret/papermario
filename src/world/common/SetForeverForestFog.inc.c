#include "common.h"
#include "map.h"

ApiStatus N(SetForeverForestFog)(Evt* script, s32 isInitialCall) {
    enable_world_fog();
    set_world_fog_dist(990, 1000);
    set_world_fog_color(0, 0, 0, 255);
    enable_entity_fog();
    set_entity_fog_dist(990, 1000);
    set_entity_fog_color(0, 0, 0, 255);

    return ApiStatus_DONE2;
}
