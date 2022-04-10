#include "nok_02.h"

#define CHUCK_QUIZMO_NPC_ID 19

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

#include "world/common/UnkNpcAIMainFunc.inc.c"

static char* N(exit_str_0) = "nok_02";
static char* N(exit_str_1) = "obk_09";

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_80242BD0_9D9BF0);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_80242C24_9D9C44);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_80242C5C_9D9C7C);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_80242F74_9D9F94);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_80242FB8_9D9FD8);

#include "world/common/SwitchToPartner.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_80243010_9DA030);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_802430CC_9DA0EC);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_80243214_9DA234);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_80243294_9DA2B4);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_8024351C_9DA53C);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_80243754_9DA774);
