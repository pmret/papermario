#include "kmr_20.h"

extern s32 D_8025B2A8;

#include "world/common/entity/Pipe.inc.c"

ApiStatus func_80240310_8EC130(Evt* script, s32 isInitialCall) {
    set_map_transition_effect(4);
    return ApiStatus_DONE2;
}

ApiStatus func_80240330_8EC150(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 63);
    return ApiStatus_DONE2;
}

ApiStatus func_80240358_8EC178(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 127);
    return ApiStatus_DONE2;
}

#include "common/foliage.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_802405BC_8EC3DC);

ApiStatus func_802406BC_8EC4DC(Evt* script, s32 isInitialCall) {
    script->functionTemp[3] = 0;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_802406C8_8EC4E8);

ApiStatus func_80240B20_8EC940(Evt* script, s32 isInitialCall) {
    free_worker(D_8025B2A8);
    return ApiStatus_DONE2;
}

ApiStatus func_80240B48_8EC968(Evt* script, s32 isInitialCall) {
    script->functionTemp[3] = 0;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_80240B54_8EC974);

ApiStatus func_80240DA4_8ECBC4(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 1);
    return ApiStatus_DONE2;
}
