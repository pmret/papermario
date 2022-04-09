#include "sam_02.h"
#include "effects.h"

#define UNK_ALPHA_FUNC_NPC 8

#include "world/common/atomic/ToadHouse.inc.c"

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

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_8024129C_D069CC);
INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_802414B4_D06BE4);
INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80241568_D06C98);
INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_8024159C_D06CCC);
INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_8024161C_D06D4C);
INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80241634_D06D64);
INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80241650_D06D80);

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

INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80241B24_D07254);
INCLUDE_ASM(s32, "world/area_sam/sam_02/D05F60", func_80241B90_D072C0);
