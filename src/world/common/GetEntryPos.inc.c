#include "common.h"
#include "map.h"

ApiStatus M(GetEntryPos)(ScriptInstance* script, s32 isInitialCall) {
    MapConfig* mapConfig = get_current_map_header();
    s32 index = get_variable(script, SI_VAR(0));

    set_variable(script, SI_VAR(1), ((Vec4f*)*mapConfig->entryList)[index].x);
    set_variable(script, SI_VAR(2), ((Vec4f*)*mapConfig->entryList)[index].y);
    set_variable(script, SI_VAR(3), ((Vec4f*)*mapConfig->entryList)[index].z);
    set_variable(script, SI_VAR(4), ((Vec4f*)*mapConfig->entryList)[index].yaw);
    return ApiStatus_DONE2;
}
