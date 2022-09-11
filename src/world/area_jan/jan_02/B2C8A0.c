#include "jan_02.h"

#define CHUCK_QUIZMO_NPC_ID 5

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_02/B2C8A0", func_802414EC_B2D95C);

INCLUDE_ASM(s32, "world/area_jan/jan_02/B2C8A0", func_80241540_B2D9B0);

INCLUDE_ASM(s32, "world/area_jan/jan_02/B2C8A0", func_80241578_B2D9E8);

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/SwitchToPartner.inc.c"
