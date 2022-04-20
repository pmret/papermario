#include "hos_03.h"

#define CHUCK_QUIZMO_NPC_ID 7

#include "world/common/atomic/enemy/FlyingAI.inc.c"

#include "world/common/atomic/ToadHouse.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"
