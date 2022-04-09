#include "mac_03.h"
#include "effects.h"

#define UNK_ALPHA_FUNC_NPC 23

#include "common/UnkFloatFunc.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_WasCorrect);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"
#include "world/common/atomic/Quizmo_UnkA.inc.c"
#include "world/common/atomic/Quizmo_UnkB.inc.c"
#include "world/common/atomic/Quizmo_UnkC.inc.c"
#include "world/common/atomic/Quizmo_UnkD.inc.c"
#include "world/common/atomic/Quizmo_UnkE.inc.c"
#include "world/common/atomic/Quizmo_UnkF.inc.c"
#include "world/common/atomic/Quizmo_UnkG.inc.c"
#include "world/common/atomic/Quizmo_UnkH.inc.c"
#include "world/common/GetGameStatus75.inc.c"
#include "world/common/SetCamVfov.inc.c"
#include "world/common/GetCamVfov.inc.c"
#include "world/common/UnkCameraFunc.inc.c"
#include "world/common/UnkRotatePlayer.inc.c"
#include "world/common/UnkPartnerFuncs.inc.c"
#include "world/common/atomic/Quizmo_UnkI.inc.c"
#include "world/common/atomic/Quizmo_UnkJ.inc.c"

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
