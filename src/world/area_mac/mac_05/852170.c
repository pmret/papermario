#include "mac_05.h"

static char* N(exit_str_0) = "mac_04";
static char* N(exit_str_1) = "kgr_01";

#define CHUCK_QUIZMO_NPC_ID 6

#include "world/common/atomic/TexturePan.inc.c"

#define NAMESPACE dup_mac_05
#include "world/common/UnkFloatFunc001.inc.c"
#define NAMESPACE mac_05

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_8024047C_8525EC);

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802425E0_854750);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242634_8547A4);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_8024266C_8547DC);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242708_854878);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242A90_854C00);

static char* N(exit_str_2) = "mac_06";

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242C78_854DE8);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242E84_854FF4);

#include "world/common/GetFloorCollider.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802430B4_855224);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802431B0_855320);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80243254_8553C4);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_8024335C_8554CC);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80243380_8554F0);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802433BC_85552C);
