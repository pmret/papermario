#include "mac_01.h"

typedef struct UnkMac01 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} UnkMac01; // size = 0xC

extern UnkMac01 D_802485E8_808E68[26];

ApiStatus func_80240E80_801700(Evt* script, s32 isInitialCall) {
    s32 idx = evt_get_variable(script, GameByte(349));

    script->varTable[0] = D_802485E8_808E68[idx].unk_00;
    script->varTable[1] = D_802485E8_808E68[idx].unk_04;
    return ApiStatus_DONE2;
}

ApiStatus func_80240ED8_801758(Evt* script, s32 isInitialCall) {
    s32 temp_a0 = evt_get_variable(script, GameByte(0));
    UnkMac01* it;
    s32 i;

    it = &D_802485E8_808E68[ARRAY_COUNT(D_802485E8_808E68) - 1];

    for (i = ARRAY_COUNT(D_802485E8_808E68) - 1; i >= 0; i--, it--) {
        if (temp_a0 >= it->unk_08) {
            break;
        }
    }
    evt_set_variable(script, GameByte(349), i);
    return ApiStatus_DONE2;
}
