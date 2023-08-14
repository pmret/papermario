#include "sam_12.h"

#include "world/common/npc/Merlar.inc.c"

EvtScript N(EVS_NpcInit_Merlar) = {
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Merlar)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Merlar)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Merlar) = {
    .id = NPC_Merlar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 180,
    .init = &N(EVS_NpcInit_Merlar),
    .settings = &N(NpcSettings_Merlar),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = MERLAR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Merlar), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    {}
};
