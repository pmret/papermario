#include "obk_05.h"

#include "world/common/npc/Boo.inc.c"

#define TRAFFIC_BOO_START_Y 40.0f
#define TRAFFIC_BOO_START_Z -430.0f
#include "../TrafficBoos.inc.c"

EvtScript N(EVS_NpcInit_TrafficBoo1) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrafficBoo)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrafficBoo2) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrafficBoo)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Boo_01)[] = {
    {
        .id = NPC_Boo_01,
        .settings = &N(NpcSettings_Boo),
        .pos = { 523.0f, -139.0f, 193.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TrafficBoo1),
        .drops = BOO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_02,
        .settings = &N(NpcSettings_Boo),
        .pos = { 473.0f, -122.0f, 247.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TrafficBoo2),
        .drops = BOO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Boo_01)),
    {}
};
