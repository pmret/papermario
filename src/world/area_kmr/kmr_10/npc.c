#include "kmr_10.h"

#include "world/common/npc/Toad_Stationary.inc.c"

EvtScript N(EVS_NpcInit_Toad) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

NpcData N(NpcData_Toad) = {
    .id = NPC_Dummy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Toad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toad)),
    {}
};
