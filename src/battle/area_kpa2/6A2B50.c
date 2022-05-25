#include "common.h"
#include "effects.h"
#include "sprite.h"

#define NAMESPACE b_area_kpa2

// typedef struct KpaStruct {
//     /* 0x00 */ s32 unk_00;
//     /* 0x04 */ s32 unk_04;
//     /* 0x08 */ s32 unk_08;
//     /* 0x0C */ s32 unk_0C;
//     /* 0x10 */ s32 unk_10;
//     /* 0x14 */ s32 unk_14;
// } KpaStruct; // size = 0x14

// extern KpaStruct D_80234810_6BBA10;

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

//#include "common/DisableRandomAbility.inc.c"
INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021CCFC_6A3EFC);

#include "common/CanPlayerLoseAction.inc.c"

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021CF54_6A4154);

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021CFC0_6A41C0);

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021D290_6A4490);

// const char* D_80234880_6BBA80 = "kpa_bt01_hit";
// const char* D_80234890_6BBA90 = "kpa_bt01_shape";
// const char* D_802348A0_6BBAA0 = "kpa_tex";
// const char* D_802348A8_6BBAA8 = "kpa_bg";
// const char* D_802348B0_6BBAB0 = "kkj_bt01_hit";
// const char* D_802348C0_6BBAC0 = "kkj_bt01_shape";
// const char* D_802348D0_6BBAD0 = "kkj_tex";
// const char* D_802348D8_6BBAD8 = "kpa_bg";
// const char* D_802348E0_6BBAE0 = "kkj_bt02_hit";
// const char* D_802348F0_6BBAF0 = "kkj_bt02_shape";
// const char* D_80234900_6BBB00 = "kkj_tex";
// const char* D_80234908_6BBB08 = "クッパ(ラストバトル３)";
// const char* D_80234920_6BBB20 = "クッパ(ラストバトル２)";
// const char* D_80234938_6BBB38 = "クッパ(ラストバトル１)";
// const char* D_80234950_6BBB50 = "クッパ(オープニング)";
// const char* D_80234968_6BBB68 = "クッパ";
// const char* D_80234970_6BBB70 = "kpa_03";
// const char* D_80234978_6BBB78 = "kpa_02";
// const char* D_80234980_6BBB80 = "kpa_01";
