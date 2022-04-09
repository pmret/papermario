#include "sam_11.h"
#include "effects.h"

#define UNK_ALPHA_FUNC_NPC 17

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

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80240F40_D3B510);
INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241158_D3B728);
INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_8024120C_D3B7DC);
INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241240_D3B810);
INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802412C0_D3B890);
INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802412D8_D3B8A8);
INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802412F4_D3B8C4);

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

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802417C8_D3BD98);
INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241834_D3BE04);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241864_D3BE34);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802418B4_D3BE84);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241A6C_D3C03C);

#include "world/common/atomic/TexturePan.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241DAC_D3C37C);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241FB0_D3C580);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241FE8_D3C5B8);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80242074_D3C644);
