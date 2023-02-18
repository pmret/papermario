#include "iwa_10.h"

#include "world/common/npc/TrainToad.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Dryite_Stationary.inc.c"

#include "world/common/complete/GiveReward.inc.c"

EvtScript N(EVS_NpcInteract_TrainToad_01) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, iwa_10_ENTRY_0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_CH2_0001)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_CH2_0002)
        EVT_CALL(ShowChoice, MSG_Choice_000C)
        EVT_CALL(EndSpeech, NPC_SELF, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0)
        EVT_IF_EQ(LVar0, 0)
            EVT_EXEC(N(EVS_DepartForToadTown))
        EVT_ELSE
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrainToad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TrainToad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrainToad_02) = {
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

EvtScript N(EVS_NpcInteract_Toadette_02) = {
    EVT_CALL(SpeakToPlayer, NPC_Toadette_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_000B)
    EVT_CALL(SpeakToPlayer, NPC_Toadette_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_000C)
    EVT_CALL(SpeakToPlayer, NPC_Toadette_04, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_000D)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette_02)))
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
            EVT_IF_EQ(AF_IWA_SpokeWIthDryite, FALSE)
                EVT_SET(LVar0, MSG_CH2_0005)
                EVT_SET(AF_IWA_SpokeWIthDryite, TRUE)
            EVT_ELSE
                EVT_SET(LVar0, MSG_CH2_0006)
                EVT_SET(AF_IWA_SpokeWIthDryite, TRUE)
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

EvtScript N(EVS_NpcInteract_Toadette_01) = {
    EVT_IF_LT(GB_IWA00_Whacka_HitCount, 8)
        EVT_SET(LVar0, MSG_CH2_0009)
    EVT_ELSE
        EVT_SET(LVar0, MSG_CH2_000A)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Green_Talk, ANIM_Toadette_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette_01)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_TrainToad)[] = {
    {
        .id = NPC_TrainToad_01,
        .pos = { -440.0f, 20.0f, 110.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TrainToad_01),
        .settings = &N(NpcSettings_TrainToad),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TRAIN_TOAD_WHITE_ANIMS,
        .tattle = MSG_NpcTattle_IWA_StationMaster,
    },
    {
        .id = NPC_TrainToad_02,
        .pos = { -425.0f, 70.0f, -20.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_TrainToad_02),
        .settings = &N(NpcSettings_TrainToad),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TRAIN_CONDUCTOR_ANIMS,
    },
};

NpcData N(NpcData_Toad) = {
    .id = NPC_Toad,
    .pos = { -254.0f, 20.0f, 165.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Toad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
    .tattle = MSG_NpcTattle_IWA_TravelAgent,
};

NpcData N(NpcData_Toadette)[] = {
    {
        .id = NPC_Toadette_02,
        .pos = { -562.0f, 0.0f, 384.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toadette_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidA,
    },
    {
        .id = NPC_Toadette_03,
        .pos = { -582.0f, 0.0f, 406.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toadette_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidB,
    },
    {
        .id = NPC_Toadette_04,
        .pos = { -524.0f, 0.0f, 411.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toadette_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidC,
    },
};

NpcData N(NpcData_Dryite)[] = {
    {
        .id = NPC_Dryite,
        .pos = { -344.0f, 0.0f, 379.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Dryite),
        .settings = &N(NpcSettings_Dryite),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = DRYITE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_IWA_StationLoiterer,
    },
    {
        .id = NPC_Toadette_01,
        .pos = { -760.0f, 0.0f, 160.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toadette_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOADETTE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_IWA_Conservationist,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TrainToad)),
    NPC_GROUP(N(NpcData_Toad)),
    NPC_GROUP(N(NpcData_Toadette)),
    NPC_GROUP(N(NpcData_Dryite)),
    NPC_GROUP(N(NpcData_Parakarry)),
    {}
};
