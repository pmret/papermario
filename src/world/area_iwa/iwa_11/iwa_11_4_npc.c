#include "iwa_11.h"

#include "world/common/npc/TrainConductorToad.inc.c"

NpcSettings N(NpcSettings_Unused1) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Unused2) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

NpcSettings N(NpcSettings_Unused3) = {
    .height = 26,
    .radius = 23,
    .level = 99,
};

EvtScript N(EVS_NpcInit_TrainConductorToad) = {
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

StaticNpc N(NpcData_TrainConductorToad) = {
    .id = NPC_TrainConductorToad,
    .settings = &N(NpcSettings_TrainConductorToad),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(EVS_NpcInit_TrainConductorToad),
    .drops = TRAIN_CONDUCTOR_DROPS,
    .animations = TRAIN_CONDUCTOR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TrainConductorToad)),
    {}
};
