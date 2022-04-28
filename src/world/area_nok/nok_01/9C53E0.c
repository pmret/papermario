#include "nok_01.h"

static char* N(exit_str_0) = "nok_13";
static char* N(exit_str_1) = "nok_02";

#define CHUCK_QUIZMO_NPC_ID 15

#include "world/common/enemy/UnkAI_4.inc.c"

#include "world/common/atomic/ToadHouse.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242028_9C7408);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_8024207C_9C745C);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802420B4_9C7494);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_8024243C_9C781C);

#include "common/UnkFloatFunc.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802426A4_9C7A84);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242760_9C7B40);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242790_9C7B70);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802427C0_9C7BA0);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242804_9C7BE4);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242858_9C7C38);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242898_9C7C78);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802428B8_9C7C98);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802428D8_9C7CB8);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242910_9C7CF0);
