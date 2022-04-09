#include "sam_01.h"
#include "effects.h"

#define UNK_ALPHA_FUNC_NPC 14

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_8024053C_CF80AC);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240590_CF8100);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_802405C8_CF8138);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240664_CF81D4);

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_WasCorrect);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"
#include "world/common/atomic/Quizmo_UnkA.inc.c"

/*
#include "world/common/atomic/Quizmo_UnkB.inc.c"
#include "world/common/atomic/Quizmo_UnkC.inc.c"
#include "world/common/atomic/Quizmo_UnkD.inc.c"
#include "world/common/atomic/Quizmo_UnkE.inc.c"
#include "world/common/atomic/Quizmo_UnkF.inc.c"
#include "world/common/atomic/Quizmo_UnkG.inc.c"
#include "world/common/atomic/Quizmo_UnkH.inc.c"
*/

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

/*
#include "world/common/atomic/Quizmo_UnkI.inc.c"
#include "world/common/atomic/Quizmo_UnkJ.inc.c"
*/

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_802416F8_CF9268);
INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241764_CF92D4);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241A10_CF9580);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241A54_CF95C4);

#include "common/GetItemEntityPosition.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80241B20_CF9690);

#define NAMESPACE dup_sam_01
#include "world/common/StashVars.inc.c"
#define NAMESPACE sam_01

#define NAMESPACE dup_sam_01
#include "world/common/GetItemName.inc.c"
#define NAMESPACE sam_01

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
