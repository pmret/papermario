#include "dead.h"
#include "common.h"

typedef struct UnkStructEE2040 {
    /* 0x00 */ s32* unk_00;
    /* 0x04 */ s32* unk_04;
    /* 0x08 */ s16 unk_08[2];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} UnkStructEE2040;

extern s32 D_80247BF0;
extern s32 D_80247DF0;
extern UnkStructEE2040 D_8024BB80;

// Dead version of LoadPartyImage?
ApiStatus func_80243680_EE2040(Evt* script, s32 isInitialCall) {
    s32 sp10;
    s32 temp_s0;

    temp_s0 = func_8005F238("party_pokopi", &sp10);
    func_80074070(temp_s0, &D_80247BF0);
    func_8002BF68(temp_s0);
    D_8024BB80.unk_00 = &D_80247DF0;
    D_8024BB80.unk_08[0] = 0x96;
    D_8024BB80.unk_08[1] = 0x69;
    D_8024BB80.unk_0C = 2;
    D_8024BB80.unk_04 = &D_80247BF0;
    D_8024BB80.unk_10 = 1;
    func_80130C64(&D_8024BB80);
    return ApiStatus_DONE2;
}
