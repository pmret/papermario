#include "iwa_11.h"

#include "world/common/npc/TrainToad.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Dryite_Stationary.inc.c"

EvtScript N(EVS_NpcInit_TrainToad) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, iwa_11_ENTRY_0)
        EVT_CALL(SetNpcPos, NPC_SELF, -425, 70, -20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, -425, 70, -20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_TrainToad) = {
    .id = NPC_TrainToad,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_TrainToad),
    .settings = &N(NpcSettings_TrainToad),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = TRAIN_CONDUCTOR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TrainToad)),
    {}
};
