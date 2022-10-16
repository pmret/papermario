#include "kmr_10.h"

#include "world/common/npc/Toad_Stationary.inc.c"

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Toad) = {
    .id = NPC_Dummy,
    .settings = &N(NpcSettings_Toad_Stationary),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_4000 | NPC_FLAG_200000,
    .init = &N(EVS_NpcInit_Toad),
    .drops = TOAD_DROPS,
    .animations = TOAD_RED_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toad)),
    {}
};
