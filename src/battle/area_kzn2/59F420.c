#include "common.h"

#define NAMESPACE b_area_kzn2

INCLUDE_ASM(s32, "battle/area_kzn2/59F420", func_80218D40_59F420);

typedef struct {
    u8 unknown_0x0[0x4 - 0x0];
    f32 unknown_0x4;
} Unk1;

typedef struct {
    u8 unknown_0x0[0xc - 0x0];
    Unk1 * unk1;
} Unk2;

ApiStatus func_80218D90_59F470(Evt * evt, s32 isInitialCall) {
    s32* args;
    Unk2 * unk2;
    Unk1 * unk1;
    
    args = evt->ptrReadPos;

    unk2 = (Unk2 *) evt_get_variable(evt, *args++);
    unk1 = unk2->unk1;
    unk1->unknown_0x4 = (f32) evt_get_variable(evt, *args++);
    return 2;
}

