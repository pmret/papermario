#include "kmr_20.h"

#include "world/common/atomic/Pipe.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_80240310_8EC130);

ApiStatus func_80240330_8EC150(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 0x3F);
    return ApiStatus_DONE2;
}

ApiStatus func_80240358_8EC178(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 0x7F);
    return ApiStatus_DONE2;
}

#include "common/foliage.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_802405BC_8EC3DC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_802406BC_8EC4DC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_802406C8_8EC4E8);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_80240B20_8EC940);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_80240B48_8EC968);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_80240B54_8EC974);

ApiStatus func_80240DA4_8ECBC4(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 1);
    return ApiStatus_DONE2;
}
