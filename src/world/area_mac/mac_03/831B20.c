#include "mac_03.h"
#include "effects.h"

#define CHUCK_QUIZMO_NPC_ID 23

#include "common/UnkFloatFunc.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241770_832F70);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_802417C4_832FC4);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_802417FC_832FFC);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241B14_833314);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241B58_833358);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241B84_833384);

INCLUDE_ASM(s32, "world/area_mac/mac_03/831B20", func_80241BD8_8333D8);
