#include "sam_11.h"
#include "effects.h"

#define CHUCK_QUIZMO_NPC_ID 17

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_WasCorrect);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#define NAMESPACE sam_11_Quizmo
#include "world/common/StashVars.inc.c"
#include "world/common/GetItemName.inc.c"
#define NAMESPACE sam_11

#include "world/common/atomic/Quizmo.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241864_D3BE34);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_802418B4_D3BE84);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241A6C_D3C03C);

#include "world/common/atomic/TexturePan.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241DAC_D3C37C);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241FB0_D3C580);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80241FE8_D3C5B8);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3ADA0", func_80242074_D3C644);
