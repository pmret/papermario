#include "obk_07.h"

#include "world/common/npc/Boo.inc.c"

#define TRAFFIC_BOO_START_Y 80.0f
#define TRAFFIC_BOO_START_Z -300.0f
#include "../common/TrafficBoos.inc.c"

EvtScript N(EVS_NpcInit_TrafficBoo1) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrafficBoo)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_TrafficBoo1) = {
    .id = NPC_TrafficBoo1,
    .pos = { 523.0f, -139.0f, 193.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_TrafficBoo1),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

EvtScript N(EVS_NpcInit_TrafficBoo2) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrafficBoo)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_TrafficBoo2) = {
    .id = NPC_TrafficBoo2,
    .pos = { 473.0f, -122.0f, 247.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_TrafficBoo2),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

EvtScript N(EVS_NpcInit_GuardBoo) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_WEIGHT)
        EVT_SET(MV_GuardDeparted, TRUE)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_SetupGuardBoo))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_GuardBoo) = {
    .id = NPC_GuardBoo,
    .pos = { 168.0f, 0.0f, -161.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_GuardBoo),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
    .tattle = MSG_NpcTattle_OBK_GuardingChest,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TrafficBoo1)),
    NPC_GROUP(N(NpcData_TrafficBoo2)),
    NPC_GROUP(N(NpcData_GuardBoo)),
    {}
};
