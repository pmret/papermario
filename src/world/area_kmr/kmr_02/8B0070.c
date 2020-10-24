#include "kmr_02.h"

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240034_8B00A4);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802400F0_8B0160);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802401D0_8B0240);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024023C_8B02AC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802402E0_8B0350);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240370_8B03E0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240390_8B0400);

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802404A8_8B0518);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802404BC_8B052C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802404CC_8B053C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802406F0_8B0760);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024073C_8B07AC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024075C_8B07CC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802407BC_8B082C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240908_8B0978);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240A7C_8B0AEC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240B00_8B0B70);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240D18_8B0D88);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240DCC_8B0E3C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240E00_8B0E70);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240E80_8B0EF0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240E98_8B0F08);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240EB4_8B0F24);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240ECC_8B0F3C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240EFC_8B0F6C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240F70_8B0FE0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241010_8B1080);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802411AC_8B121C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241210_8B1280);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802412A0_8B1310);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241388_8B13F8);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802413F4_8B1464);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241424_8B1494);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802414D8_8B1548);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802415F8_8B1668);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241658_8B16C8);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802416D0_8B1740);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241800_8B1870);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024191C_8B198C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241964_8B19D4);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241A10_8B1A80);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241C18_8B1C88);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80241E90_8B1F00);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242014_8B2084);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024226C_8B22DC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802422C0_8B2330);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802422F8_8B2368);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242394_8B2404);

#include "world/common/SetManyVars.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242514_8B2584);

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

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024293C_8B29AC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024295C_8B29CC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242BA8_8B2C18);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242BC0_8B2C30);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F08_8B2F78);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F28_8B2F98);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F7C_8B2FEC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80243034_8B30A4);
