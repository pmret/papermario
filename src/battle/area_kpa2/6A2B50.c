#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_kpa2

typedef struct KpaStruct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} KpaStruct; // size = 0x14

extern f32 D_80234828_6BBA28; //f64?
extern KpaStruct D_80234810_6BBA10;

#include "common/StartRumbleWithParams.inc.c"

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021B9A8_6A2BA8);

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021BC60_6A2E60);

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnfadeBackgroundToBlack.inc.c"

#include "common/RemoveChillOut.inc.c"

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021C14C_6A334C);

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021C520_6A3720);

#include "common/GetJumpHammerCharge.inc.c"

#include "common/GetPlayerHpPercent.inc.c"

#include "common/ItemEntityJumpToPos.inc.c"

#define NAMESPACE dup2_b_area_kpa2
#include "common/GetItemEntityPosition.inc.c"
#define NAMESPACE b_area_kpa2

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021CCFC_6A3EFC);

#include "common/CanPlayerLoseAction.inc.c"

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021CF54_6A4154);

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021CFC0_6A41C0);

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021D290_6A4490);
