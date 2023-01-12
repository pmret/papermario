#include "mim_12.h"

#include "world/common/npc/Boo.inc.c"

EvtScript N(EVS_NpcInit_GateBoo_01) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GateBoo_02) = {
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_GateBoos)[] = {
    {
        .id = NPC_GateBoo_01,
        .settings = &N(NpcSettings_Boo),
        .pos = { -68.0f, 65.0f, -56.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_GateBoo_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = NORMAL_BOO_ANIMS,
    },
    {
        .id = NPC_GateBoo_02,
        .settings = &N(NpcSettings_Boo),
        .pos = { -125.0f, 65.0f, 60.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_GateBoo_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = NORMAL_BOO_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GateBoos)),
    {}
};
