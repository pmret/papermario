#include "jan_02.h"

#define UNK_ALPHA_FUNC_NPC 5

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

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_02/B2C8A0", func_802414EC_B2D95C);

INCLUDE_ASM(s32, "world/area_jan/jan_02/B2C8A0", func_80241540_B2D9B0);

INCLUDE_ASM(s32, "world/area_jan/jan_02/B2C8A0", func_80241578_B2D9E8);

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

#include "world/common/SwitchToPartner.inc.c"
