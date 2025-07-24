#include "iwa_10.h"

#include "world/common/npc/TrainToad.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Dryite_Stationary.inc.c"

#include "world/common/complete/GiveReward.inc.c"
#if VERSION_JP
#include "world/common/todo/SomeItemEntityFunc.inc.c"
#include "world/common/todo/IsItemBadge.inc.c"
#include "world/common/todo/UnkScriptJP00.inc.c"
#endif

EvtScript N(EVS_NpcInteract_TrainToad_01) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, iwa_10_ENTRY_0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_CH2_0001)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_CH2_0002)
        Call(ShowChoice, MSG_Choice_000C)
        Call(EndSpeech, NPC_SELF, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0)
        IfEq(LVar0, 0)
            Exec(N(EVS_DepartForToadTown))
        Else
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_TrainToad_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_TrainToad_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_TrainToad_02) = {
    Call(EnableNpcShadow, NPC_SELF, false)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, iwa_10_ENTRY_0)
        Call(SetNpcPos, NPC_SELF, -425, 70, -20)
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Else
        Call(SetNpcPos, NPC_SELF, -425, 70, -20)
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH2_0004)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad)))
    IfGe(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toadette_02) = {
    Call(SpeakToPlayer, NPC_Toadette_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_000B)
    Call(SpeakToPlayer, NPC_Toadette_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_000C)
    Call(SpeakToPlayer, NPC_Toadette_04, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_000D)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette_02)))
    IfLt(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    IfGe(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Dryite) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(AF_IWA_SpokeWIthDryite, false)
                Set(LVar0, MSG_CH2_0005)
                Set(AF_IWA_SpokeWIthDryite, true)
            Else
                Set(LVar0, MSG_CH2_0006)
                Set(AF_IWA_SpokeWIthDryite, true)
            EndIf
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_CH2_0007)
        CaseDefault
            Set(LVar0, MSG_CH2_0008)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Dryite) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Dryite)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toadette_01) = {
    IfLt(GB_IWA00_Whacka_HitCount, 8)
        Set(LVar0, MSG_CH2_0009)
    Else
        Set(LVar0, MSG_CH2_000A)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Green_Talk, ANIM_Toadette_Green_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette_01)))
    Return
    End
};

NpcData N(NpcData_TrainToad)[] = {
    {
        .id = NPC_TrainToad_01,
        .pos = { -440.0f, 20.0f, 110.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TrainToad_01),
        .settings = &N(NpcSettings_TrainToad),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
