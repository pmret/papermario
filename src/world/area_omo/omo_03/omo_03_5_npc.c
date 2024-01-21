#include "omo_03.h"

#include "world/common/npc/TrainToad.inc.c"
#include "world/common/npc/Parakarry.inc.c"

#include "world/common/enemy/ShyGuy_Stationary.inc.c"

EvtScript N(EVS_ItemPrompt_ToyTrain) = {
    Call(DisablePlayerInput, TRUE)
    IfLt(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
        Call(ShowKeyChoicePopup)
        Call(CloseChoicePopup)
        IfEq(LVar0, ITEM_TOY_TRAIN)
            Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0002)
        Else
            IfEq(AF_OMO_05, FALSE)
                Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0000)
                Set(AF_OMO_05, TRUE)
            Else
                Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0001)
                Set(AF_OMO_05, FALSE)
            EndIf
        EndIf
    Else
        IfEq(GF_OMO03_LearnedAboutTrainSwitches, FALSE)
            IfEq(AF_OMO_05, FALSE)
                Thread
                    Call(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                    Call(SetNpcJumpscale, NPC_Conductor, Float(1.0))
                    Call(GetNpcPos, NPC_Conductor, LVar0, LVar1, LVar2)
                    Loop(2)
                        Call(NpcJump1, NPC_Conductor, LVar0, LVar1, LVar2, 15)
                    EndLoop
                    Call(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                EndThread
                Wait(10)
                IfEq(MF_EitherSwitchPressed, FALSE)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0003)
                    Call(EndSpeech, NPC_Conductor, -1, -1, 0)
                Else
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0003)
                    Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0005)
                    Set(GF_OMO03_LearnedAboutTrainSwitches, TRUE)
                EndIf
                Set(AF_OMO_05, TRUE)
            Else
                Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0004)
                Set(GF_OMO03_LearnedAboutTrainSwitches, TRUE)
            EndIf
        Else
            IfEq(AF_OMO_06, FALSE)
                ExecWait(N(EVS_8024705C))
            Else
                ExecWait(N(EVS_80246108))
            EndIf
        EndIf
    EndIf
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

s32 N(ToyTrainList)[] = {
    ITEM_TOY_TRAIN,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_Conductor) = {
    BindPadlock(Ref(N(EVS_ItemPrompt_ToyTrain)), TRIGGER_FORCE_ACTIVATE, 0, Ref(N(ToyTrainList)), 0, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_Conductor) = {
    IfLt(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
        Call(SetNpcAnimation, NPC_SELF, ANIM_TrainToad_SadIdle)
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Conductor)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_TrainToad) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_GOT_STOREROOM_KEY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_SadTalk, ANIM_TrainToad_Blue_SadIdle, 0, MSG_CH4_0017)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_0018)
        CaseLt(STORY_CH4_RETURNED_TOY_TRAIN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_0019)
        CaseLt(STORY_CH4_GOT_FRYING_PAN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001A)
        CaseLt(STORY_CH4_GOT_TAYCE_TS_CAKE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001B)
        CaseLt(STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001C)
        CaseLt(STORY_CH4_PULLED_SWITCH_SWITCH)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001D)
        CaseLt(STORY_CH4_SOLVED_COLOR_PUZZLE)
            Call(FindKeyItem, ITEM_MYSTERY_NOTE, LVar0)
            IfEq(LVar0, -1)
                Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001E)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001F)
            EndIf
        CaseLt(STORY_CH4_WATT_JOINED_PARTY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_0020)
        CaseLt(STORY_CH4_DEFEATED_GENERAL_GUY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_0021)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_0022)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_TrainToad) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_TrainToad)))
    Return
    End
};

NpcData N(NpcData_TrainToads)[] = {
    {
        .id = NPC_Conductor,
        .pos = { 170.0f, 50.0f, -115.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Conductor),
        .settings = &N(NpcSettings_TrainToad),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TRAIN_CONDUCTOR_ANIMS,
        .tattle = MSG_NpcTattle_OMO_TrainConductor,
    },
    {
        .id = NPC_TrainToad,
        .pos = { 158.0f, 0.0f, 85.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TrainToad),
        .settings = &N(NpcSettings_TrainToad),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TRAIN_TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_OMO_TrainConductor,
    }
};

NpcData N(NpcData_Epilogue)[] = {
    {
        .id = NPC_Parakarry,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_Parakarry),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = PARAKARRY_ANIMS,
    },
    {
        .id = NPC_Watt,
        .pos = { 50.0f, 15.0f, 160.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldWatt_Idle,
            .walk   = ANIM_WorldWatt_Idle,
            .run    = ANIM_WorldWatt_Idle,
            .chase  = ANIM_WorldWatt_Idle,
            .anim_4 = ANIM_WorldWatt_Idle,
            .anim_5 = ANIM_WorldWatt_Idle,
            .death  = ANIM_WorldWatt_Idle,
            .hit    = ANIM_WorldWatt_Idle,
            .anim_8 = ANIM_WorldWatt_Idle,
            .anim_9 = ANIM_WorldWatt_Idle,
            .anim_A = ANIM_WorldWatt_Idle,
            .anim_B = ANIM_WorldWatt_Idle,
            .anim_C = ANIM_WorldWatt_Idle,
            .anim_D = ANIM_WorldWatt_Idle,
            .anim_E = ANIM_WorldWatt_Idle,
            .anim_F = ANIM_WorldWatt_Idle,
        },
    },
    {
        .id = NPC_ShyGuy_01,
        .pos = { 100.0f, 0.0f, 160.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_02,
        .pos = { 115.0f, 0.0f, 200.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_03,
        .pos = { 145.0f, 0.0f, 150.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TrainToads)),
    {}
};

NpcGroupList N(EpilogueNPCs) = {
    //@bug? only loads the first NPC from the group, cannot use macro here
    { .npcCount = 1, .npcs = &N(NpcData_TrainToads)[0] },
    NPC_GROUP(N(NpcData_Epilogue)),
    {}
};
