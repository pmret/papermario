#include "common.h"
#include "npc.h"

ApiStatus N(GetEntryPos)(Evt* script, s32 isInitialCall) {
    MapConfig* mapConfig = get_current_map_header();
    s32 index = evt_get_variable(script, EVT_VAR(0));

    evt_set_variable(script, EVT_VAR(1), ((Vec4f*)*mapConfig->entryList)[index].x);
    evt_set_variable(script, EVT_VAR(2), ((Vec4f*)*mapConfig->entryList)[index].y);
    evt_set_variable(script, EVT_VAR(3), ((Vec4f*)*mapConfig->entryList)[index].z);
    evt_set_variable(script, EVT_VAR(4), ((Vec4f*)*mapConfig->entryList)[index].yaw);
    return ApiStatus_DONE2;
}
