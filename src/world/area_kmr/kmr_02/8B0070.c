#include "kmr_02.h"

static char* N(exit_str_0) = "kmr_05";
static char* N(exit_str_1) = "kmr_00";
static char* N(exit_str_2) = "kmr_09";
static char* N(exit_str_3) = "";

#define UNK_ALPHA_FUNC_NPC 8

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

#include "world/common/UnkFunc25.inc.c"

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802402E0_8B0350);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240370_8B03E0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240390_8B0400);

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

#include "world/common/UnkQuizFunc.inc.c"

#include "world/common/UnkFunc31.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240A7C_8B0AEC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240B00_8B0B70);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240D18_8B0D88);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240DCC_8B0E3C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240E00_8B0E70);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240E80_8B0EF0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240E98_8B0F08);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240EB4_8B0F24);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241388_8B13F8);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802413F4_8B1464);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241424_8B1494);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802414D8_8B1548);

#include "world/common/NpcJumpFunc3.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13_2.inc.c"

#include "world/common/UnkNpcAIFunc11.inc.c"

#include "world/common/UnkNpcAIFunc10.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241964_8B19D4);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241A10_8B1A80);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241C18_8B1C88);

static char* N(exit_str_4) = "nok_02";
static char* N(exit_str_5) = "kmr_03";
static char* N(exit_str_6) = "\0\0\0\0";

#include "world/common/UnkFunc41.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242014_8B2084);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024226C_8B22DC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802422C0_8B2330);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802422F8_8B2368);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242394_8B2404);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802426A0_8B2710);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802426E4_8B2754);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242710_8B2780);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242734_8B27A4);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242788_8B27F8);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802427B0_8B2820);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802427CC_8B283C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802427EC_8B285C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024280C_8B287C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242860_8B28D0);

#include "world/common/SyncStatusMenu.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024295C_8B29CC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242BA8_8B2C18);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242BC0_8B2C30);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F08_8B2F78);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F28_8B2F98);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F7C_8B2FEC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80243034_8B30A4);
