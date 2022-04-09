#include "mac_02.h"

#define UNK_ALPHA_FUNC_NPC 12

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

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242A80_825D40);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242AD4_825D94);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242B0C_825DCC);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242BA8_825E68);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242C44_825F04);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242DBC_82607C);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242F60_826220);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80243040_826300);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80243088_826348);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_802430D0_826390);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80243380_826640);

INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_802433C4_826684);

#include "world/common/UnkMusicFunc.inc.c"
