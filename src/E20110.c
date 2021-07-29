#include "common.h"

#define NAMESPACE E20110

extern s32 D_8010C958;

#include "common/UnkAngleFunc1.inc.c"

INCLUDE_ASM(s32, "E20110", func_802B70B4_E201C4);

INCLUDE_ASM(s32, "E20110", func_802B71E8_E202F8);

INCLUDE_ASM(s32, "E20110", func_802B7450_E20560);

INCLUDE_ASM(s32, "E20110", func_802B75E8_E206F8);

INCLUDE_ASM(s32, "E20110", func_802B7728_E20838);

void func_802B79C8_E20AD8(void) {
    func_802B75E8_E206F8();
    gPlayerStatusPtr->unk_C6 = -1;
    D_8010C958 = 0;
    gPlayerStatusPtr->unk_C8 = NULL;
    gPlayerStatusPtr->animFlags &= ~0x10;
    func_800EF3D4(0);
    repartner_set_tether_distance();
}
