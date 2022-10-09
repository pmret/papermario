#include "iwa_10.h"

extern EvtScript N(EVS_DepartForToadTown);
extern StaticNpc N(NpcData_Parakarry);

EvtScript N(EVS_NpcAuxAI_TrainStationToad_01) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_TrainStationToad_01) = {
    .height = 32,
    .radius = 24,
    .level = 99,
    .otherAI = &N(EVS_NpcAuxAI_TrainStationToad_01),
};

NpcSettings N(NpcSettings_Toad) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Unused) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

NpcSettings N(NpcSettings_Dryite) = {
    .height = 26,
    .radius = 23,
    .level = 99,
};

#include "world/common/complete/GiveReward.inc.c"

EvtScript N(EVS_NpcInteract_TrainStationToad_01) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, iwa_10_ENTRY_0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainStationToad_White_Talk, ANIM_TrainStationToad_White_Idle, 0, MSG_CH2_0001)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainStationToad_White_Talk, ANIM_TrainStationToad_White_Idle, 0, MSG_CH2_0002)
        EVT_CALL(ShowChoice, MSG_Choice_000C)
        EVT_CALL(EndSpeech, NPC_SELF, ANIM_TrainStationToad_White_Talk, ANIM_TrainStationToad_White_Idle, 0)
        EVT_IF_EQ(LVar0, 0)
            EVT_EXEC(N(EVS_DepartForToadTown))
        EVT_ELSE
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrainStationToad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TrainStationToad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrainStationToad_02) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, iwa_10_ENTRY_0)
        EVT_CALL(SetNpcPos, NPC_SELF, -425, 70, -20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, -425, 70, -20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH2_0004)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ThreeSisters_02) = {
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_000B)
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_000C)
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters_04, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_000D)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters_02)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_IWA_02, FALSE)
                EVT_SET(LVar0, MSG_CH2_0005)
                EVT_SET(AF_IWA_02, TRUE)
            EVT_ELSE
                EVT_SET(LVar0, MSG_CH2_0006)
                EVT_SET(AF_IWA_02, TRUE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_CH2_0007)
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, MSG_CH2_0008)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ThreeSisters_01) = {
    EVT_IF_LT(GB_IWA00_Whacka_HitCount, 8)
        EVT_SET(LVar0, MSG_CH2_0009)
    EVT_ELSE
        EVT_SET(LVar0, MSG_CH2_000A)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Green_Talk, ANIM_Toadette_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters_01)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_TrainConductorToad)[] = {
    {
        .id = NPC_TrainStationToad_01,
        .settings = &N(NpcSettings_TrainStationToad_01),
        .pos = { -440.0f, 20.0f, 110.0f },
        .yaw = 90,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(EVS_NpcInit_TrainStationToad_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_TrainStationToad_White_Idle,
            .walk   = ANIM_TrainStationToad_White_Idle,
            .run    = ANIM_TrainStationToad_White_Idle,
            .chase  = ANIM_TrainStationToad_White_Idle,
            .anim_4 = ANIM_TrainStationToad_White_Idle,
            .anim_5 = ANIM_TrainStationToad_White_Idle,
            .death  = ANIM_TrainStationToad_White_Idle,
            .hit    = ANIM_TrainStationToad_White_Idle,
            .anim_8 = ANIM_TrainStationToad_White_Idle,
            .anim_9 = ANIM_TrainStationToad_White_Idle,
            .anim_A = ANIM_TrainStationToad_White_Idle,
            .anim_B = ANIM_TrainStationToad_White_Idle,
            .anim_C = ANIM_TrainStationToad_White_Idle,
            .anim_D = ANIM_TrainStationToad_White_Idle,
            .anim_E = ANIM_TrainStationToad_White_Idle,
            .anim_F = ANIM_TrainStationToad_White_Idle,
        },
        .tattle = MSG_NpcTattle_IWA_StationMaster,
    },
    {
        .id = NPC_TrainStationToad_02,
        .settings = &N(NpcSettings_TrainStationToad_01),
        .pos = { -425.0f, 70.0f, -20.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(EVS_NpcInit_TrainStationToad_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_TrainStationToad_Idle,
            .walk   = ANIM_TrainStationToad_Walk,
            .run    = ANIM_TrainStationToad_Idle,
            .chase  = ANIM_TrainStationToad_Idle,
            .anim_4 = ANIM_TrainStationToad_Idle,
            .anim_5 = ANIM_TrainStationToad_Idle,
            .death  = ANIM_TrainStationToad_Idle,
            .hit    = ANIM_TrainStationToad_Idle,
            .anim_8 = ANIM_TrainStationToad_Idle,
            .anim_9 = ANIM_TrainStationToad_Idle,
            .anim_A = ANIM_TrainStationToad_Idle,
            .anim_B = ANIM_TrainStationToad_Idle,
            .anim_C = ANIM_TrainStationToad_Idle,
            .anim_D = ANIM_TrainStationToad_Idle,
            .anim_E = ANIM_TrainStationToad_Idle,
            .anim_F = ANIM_TrainStationToad_Idle,
        },
    },
};

StaticNpc N(NpcData_Toad) = {
    .id = NPC_Toad,
    .settings = &N(NpcSettings_Toad),
    .pos = { -254.0f, 20.0f, 165.0f },
    .yaw = 270,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(EVS_NpcInit_Toad),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Toad_Red_Idle,
        .walk   = ANIM_Toad_Red_Walk,
        .run    = ANIM_Toad_Red_Run,
        .chase  = ANIM_Toad_Red_Run,
        .anim_4 = ANIM_Toad_Red_Idle,
        .anim_5 = ANIM_Toad_Red_Idle,
        .death  = ANIM_Toad_Red_Disappointed,
        .hit    = ANIM_Toad_Red_Disappointed,
        .anim_8 = ANIM_Toad_Red_Run,
        .anim_9 = ANIM_Toad_Red_Run,
        .anim_A = ANIM_Toad_Red_Run,
        .anim_B = ANIM_Toad_Red_Run,
        .anim_C = ANIM_Toad_Red_Run,
        .anim_D = ANIM_Toad_Red_Run,
        .anim_E = ANIM_Toad_Red_Run,
        .anim_F = ANIM_Toad_Red_Run,
    },
    .tattle = MSG_NpcTattle_IWA_TravelAgent,
};

StaticNpc N(NpcData_ThreeSisters)[] = {
    {
        .id = NPC_ThreeSisters_02,
        .settings = &N(NpcSettings_Toad),
        .pos = { -562.0f, 0.0f, 384.0f },
        .yaw = 90,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(EVS_NpcInit_ThreeSisters_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toadette_Pink_Idle,
            .walk   = ANIM_Toadette_Pink_Walk,
            .run    = ANIM_Toadette_Pink_Run,
            .chase  = ANIM_Toadette_Pink_Run,
            .anim_4 = ANIM_Toadette_Pink_Idle,
            .anim_5 = ANIM_Toadette_Pink_Idle,
            .death  = ANIM_Toadette_Pink_Disappointed,
            .hit    = ANIM_Toadette_Pink_Disappointed,
            .anim_8 = ANIM_Toadette_Pink_Run,
            .anim_9 = ANIM_Toadette_Pink_Run,
            .anim_A = ANIM_Toadette_Pink_Run,
            .anim_B = ANIM_Toadette_Pink_Run,
            .anim_C = ANIM_Toadette_Pink_Run,
            .anim_D = ANIM_Toadette_Pink_Run,
            .anim_E = ANIM_Toadette_Pink_Run,
            .anim_F = ANIM_Toadette_Pink_Run,
        },
        .tattle = MSG_NpcTattle_TravelingMaidA,
    },
    {
        .id = NPC_ThreeSisters_03,
        .settings = &N(NpcSettings_Toad),
        .pos = { -582.0f, 0.0f, 406.0f },
        .yaw = 90,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(EVS_NpcInit_ThreeSisters_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toadette_Pink_Idle,
            .walk   = ANIM_Toadette_Pink_Walk,
            .run    = ANIM_Toadette_Pink_Run,
            .chase  = ANIM_Toadette_Pink_Run,
            .anim_4 = ANIM_Toadette_Pink_Idle,
            .anim_5 = ANIM_Toadette_Pink_Idle,
            .death  = ANIM_Toadette_Pink_Disappointed,
            .hit    = ANIM_Toadette_Pink_Disappointed,
            .anim_8 = ANIM_Toadette_Pink_Run,
            .anim_9 = ANIM_Toadette_Pink_Run,
            .anim_A = ANIM_Toadette_Pink_Run,
            .anim_B = ANIM_Toadette_Pink_Run,
            .anim_C = ANIM_Toadette_Pink_Run,
            .anim_D = ANIM_Toadette_Pink_Run,
            .anim_E = ANIM_Toadette_Pink_Run,
            .anim_F = ANIM_Toadette_Pink_Run,
        },
        .tattle = MSG_NpcTattle_TravelingMaidB,
    },
    {
        .id = NPC_ThreeSisters_04,
        .settings = &N(NpcSettings_Toad),
        .pos = { -524.0f, 0.0f, 411.0f },
        .yaw = 270,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(EVS_NpcInit_ThreeSisters_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toadette_Pink_Idle,
            .walk   = ANIM_Toadette_Pink_Walk,
            .run    = ANIM_Toadette_Pink_Run,
            .chase  = ANIM_Toadette_Pink_Run,
            .anim_4 = ANIM_Toadette_Pink_Idle,
            .anim_5 = ANIM_Toadette_Pink_Idle,
            .death  = ANIM_Toadette_Pink_Disappointed,
            .hit    = ANIM_Toadette_Pink_Disappointed,
            .anim_8 = ANIM_Toadette_Pink_Run,
            .anim_9 = ANIM_Toadette_Pink_Run,
            .anim_A = ANIM_Toadette_Pink_Run,
            .anim_B = ANIM_Toadette_Pink_Run,
            .anim_C = ANIM_Toadette_Pink_Run,
            .anim_D = ANIM_Toadette_Pink_Run,
            .anim_E = ANIM_Toadette_Pink_Run,
            .anim_F = ANIM_Toadette_Pink_Run,
        },
        .tattle = MSG_NpcTattle_TravelingMaidC,
    },
};

StaticNpc N(NpcData_Dryite)[] = {
    {
        .id = NPC_Dryite,
        .settings = &N(NpcSettings_Dryite),
        .pos = { -344.0f, 0.0f, 379.0f },
        .yaw = 270,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(EVS_NpcInit_Dryite),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Dryite_Green_Idle,
            .walk   = ANIM_Dryite_Green_Walk,
            .run    = ANIM_Dryite_Green_Run,
            .chase  = ANIM_Dryite_Green_Run,
            .anim_4 = ANIM_Dryite_Green_Idle,
            .anim_5 = ANIM_Dryite_Green_Idle,
            .death  = ANIM_Dryite_Green_Still,
            .hit    = ANIM_Dryite_Green_Still,
            .anim_8 = ANIM_Dryite_Green_Idle,
            .anim_9 = ANIM_Dryite_Green_Idle,
            .anim_A = ANIM_Dryite_Green_Idle,
            .anim_B = ANIM_Dryite_Green_Idle,
            .anim_C = ANIM_Dryite_Green_Idle,
            .anim_D = ANIM_Dryite_Green_Idle,
            .anim_E = ANIM_Dryite_Green_Idle,
            .anim_F = ANIM_Dryite_Green_Idle,
        },
        .tattle = MSG_NpcTattle_IWA_StationLoiterer,
    },
    {
        .id = NPC_ThreeSisters_01,
        .settings = &N(NpcSettings_Toad),
        .pos = { -760.0f, 0.0f, 160.0f },
        .yaw = 90,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(EVS_NpcInit_ThreeSisters_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toadette_Green_Idle,
            .walk   = ANIM_Toadette_Green_Walk,
            .run    = ANIM_Toadette_Green_Run,
            .chase  = ANIM_Toadette_Green_Run,
            .anim_4 = ANIM_Toadette_Green_Idle,
            .anim_5 = ANIM_Toadette_Green_Idle,
            .death  = ANIM_Toadette_Green_Disappointed,
            .hit    = ANIM_Toadette_Green_Disappointed,
            .anim_8 = ANIM_Toadette_Green_Run,
            .anim_9 = ANIM_Toadette_Green_Run,
            .anim_A = ANIM_Toadette_Green_Run,
            .anim_B = ANIM_Toadette_Green_Run,
            .anim_C = ANIM_Toadette_Green_Run,
            .anim_D = ANIM_Toadette_Green_Run,
            .anim_E = ANIM_Toadette_Green_Run,
            .anim_F = ANIM_Toadette_Green_Run,
        },
        .tattle = MSG_NpcTattle_IWA_Conservationist,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TrainConductorToad)),
    NPC_GROUP(N(NpcData_Toad)),
    NPC_GROUP(N(NpcData_ThreeSisters)),
    NPC_GROUP(N(NpcData_Dryite)),
    NPC_GROUP(N(NpcData_Parakarry)),
    {}
};
