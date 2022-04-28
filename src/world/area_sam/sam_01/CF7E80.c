#include "sam_01.h"
#include "effects.h"

#define CHUCK_QUIZMO_NPC_ID 14

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_8024053C_CF80AC);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240590_CF8100);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_802405C8_CF8138);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240664_CF81D4);

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/LetterDelivery.inc.c"

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
