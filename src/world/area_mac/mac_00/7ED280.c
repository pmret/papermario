#include "mac_00.h"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80242570_7ED280);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_802426C8_7ED3D8);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80242A30_7ED740);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80242BEC_7ED8FC);

# include "world/common/NpcJumpFunc2.inc.c"

# include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"
// void func_80242D8C_7EDA9C(ScriptInstance* script, NpcAISettings* aiSettings) {
//     Enemy* enemy = script->owner1.enemy;
//     Npc* npc = get_npc_unsafe(enemy->npcID);
//     f32 tempAngle;
//     f32 angleDiff;

//     npc->duration = (aiSettings->unk_20 / 2) + rand_int(aiSettings->unk_20 / 2 + 1);
//     npc->currentAnim = enemy->animList[3];
//     npc->moveSpeed = aiSettings->chaseSpeed;

//     tempAngle = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
//     angleDiff = get_clamped_angle_diff(npc->yaw, tempAngle);

//     if (aiSettings->unk_1C < fabsf(angleDiff)) {
//         tempAngle = npc->yaw;

//         if (angleDiff < 0.0f) {
//             tempAngle += -aiSettings->unk_1C;
//         } else {
//             tempAngle += aiSettings->unk_1C;
//         }
//     }

//     npc->yaw = clamp_angle(tempAngle);
//     script->functionTemp[0].s = 13;
// }

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80242EBC_7EDBCC);

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243044_7EDD54);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243104_7EDE14);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243400_7EE110);

#define NAMESPACE dup_mac_00
#include "world/common/GetItemName.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/GetNpcCollisionHeight.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/SomeXYZFuncTodoRename.inc.c"
#define NAMESPACE mac_00

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243744_7EE454);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243798_7EE4A8);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_802437D0_7EE4E0);

#define NAMESPACE dup_mac_00
#include "world/common/SetManyVars.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/UnkYawFunc.inc.c"
#define NAMESPACE mac_00

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243AE8_7EE7F8);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243B2C_7EE83C);
