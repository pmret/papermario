#include "sam_01.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_8024053C_CF80AC);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240590_CF8100);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_802405C8_CF8138);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240664_CF81D4);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240700_CF8270);

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_8024083C_CF83AC);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240A60_CF85D0);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240ACC_CF863C);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240B2C_CF869C);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240C78_CF87E8);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240DEC_CF895C);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240E70_CF89E0);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241088_CF8BF8);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_8024113C_CF8CAC);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241170_CF8CE0);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_802411F0_CF8D60);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241208_CF8D78);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241224_CF8D94);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_802416F8_CF9268);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241764_CF92D4);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241A10_CF9580);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241A54_CF95C4);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241A80_CF95F0);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241B20_CF9690);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241C90_CF9800);

// Identical to GetItemName but since there is already one inclusion of it in this file,
// we can't include it again. This makes me think there is an undetected file boundary here,
// or there's something else about the area system we're not aware of
//#include "world/common/GetItemName.inc.c"
INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241D44_CF98B4);

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
