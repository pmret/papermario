#include "jan_03.h"

static char* N(exit_str_0) = "jan_02";
static char* N(exit_str_1) = "jan_05";
static char* N(exit_str_2) = "jan_22";
static char* N(exit_str_3) = "";

#define CHUCK_QUIZMO_NPC_ID 17

#include "world/common/atomic/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802405EC_B351BC);

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

static char* N(exit_str_4) = "tik_08";

#include "world/common/atomic/ToadHouse.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802419D8_B365A8);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241A2C_B365FC);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241A64_B36634);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241B00_B366D0);

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242EAC_B37A7C);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242EF0_B37AC0);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242F1C_B37AEC);
