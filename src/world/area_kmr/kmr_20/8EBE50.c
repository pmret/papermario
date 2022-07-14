#include "kmr_20.h"

#include "world/common/atomic/Pipe.inc.c"

 func_80240310_8EC130(void) {
    set_map_transition_effect(4);
    return 2;
}

 func_80240330_8EC150(void) {
    func_8005566C(0, 0x3E8, 0x3F);
    return 2;
}

func_80240358_8EC178(void) {
    func_8005566C(0, 0x3E8, 0x7F);
    return 2;
}

#include "common/foliage.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_802405BC_8EC3DC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_802406BC_8EC4DC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_802406C8_8EC4E8);

extern s32 D_8025B2A8;

 func_80240B20_8EC940(void) {
    free_generic_entity(D_8025B2A8);
    return 2;
}

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_80240B48_8EC968);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_80240B54_8EC974);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EBE50", func_80240DA4_8ECBC4);
