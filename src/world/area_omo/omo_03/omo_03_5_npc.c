#include "omo_03.h"

#include "world/common/npc/TrainToad.inc.c"
#include "world/common/npc/Parakarry.inc.c"

#include "world/common/enemy/complete/ShyGuy_Stationary.inc.c"

EvtScript N(EVS_ItemPrompt_ToyTrain) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_CALL(CloseChoicePopup)
        EVT_IF_EQ(LVar0, ITEM_TOY_TRAIN)
            EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0002)
        EVT_ELSE
            EVT_IF_EQ(AF_OMO_05, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0000)
                EVT_SET(AF_OMO_05, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0001)
                EVT_SET(AF_OMO_05, FALSE)
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_IF_EQ(GF_OMO03_LearnedAboutTrainSwitches, FALSE)
            EVT_IF_EQ(AF_OMO_05, FALSE)
                EVT_THREAD
                    EVT_CALL(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_100, TRUE)
                    EVT_CALL(SetNpcJumpscale, NPC_Conductor, EVT_FLOAT(1.0))
                    EVT_CALL(GetNpcPos, NPC_Conductor, LVar0, LVar1, LVar2)
                    EVT_LOOP(2)
                        EVT_CALL(NpcJump1, NPC_Conductor, LVar0, LVar1, LVar2, 15)
                    EVT_END_LOOP
                    EVT_CALL(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_100, FALSE)
                EVT_END_THREAD
                EVT_WAIT(10)
                EVT_IF_EQ(MF_EitherSwitchPressed, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0003)
                    EVT_CALL(EndSpeech, NPC_Conductor, -1, -1, 0)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0003)
                    EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0005)
                    EVT_SET(GF_OMO03_LearnedAboutTrainSwitches, TRUE)
                EVT_END_IF
                EVT_SET(AF_OMO_05, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0004)
                EVT_SET(GF_OMO03_LearnedAboutTrainSwitches, TRUE)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(AF_OMO_06, FALSE)
                EVT_EXEC_WAIT(N(EVS_8024705C))
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_80246108))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

s32 N(ToyTrainList)[] = {
    ITEM_TOY_TRAIN,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_Conductor) = {
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_ToyTrain)), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(ToyTrainList)), 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Conductor) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TrainToad_SadIdle)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Conductor)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_TrainToad) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_GOT_STOREROOM_KEY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_SadTalk, ANIM_TrainToad_Blue_SadIdle, 0, MSG_CH4_0017)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_0018)
        EVT_CASE_LT(STORY_CH4_RETURNED_TOY_TRAIN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_0019)
        EVT_CASE_LT(STORY_CH4_GOT_FRYING_PAN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001A)
        EVT_CASE_LT(STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001B)
        EVT_CASE_LT(STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001C)
        EVT_CASE_LT(STORY_CH4_PULLED_SWITCH_SWITCH)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001D)
        EVT_CASE_LT(STORY_CH4_SOLVED_COLOR_PUZZLE)
            EVT_CALL(FindKeyItem, ITEM_MYSTERY_NOTE, LVar0)
            EVT_IF_EQ(LVar0, -1)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001E)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_001F)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_0020)
        EVT_CASE_LT(STORY_CH4_DEFEATED_GENERAL_GUY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_0021)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Blue_Talk, ANIM_TrainToad_Blue_Idle, 0, MSG_CH4_0022)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrainToad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TrainToad)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_TrainToads)[] = {
    {
        .id = NPC_Conductor,
        .settings = &N(NpcSettings_TrainToad),
        .pos = { 170.0f, 50.0f, -115.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_Conductor),
        .drops = NPC_NO_DROPS,
        .animations = TRAIN_CONDUCTOR_ANIMS,
        .tattle = MSG_NpcTattle_OMO_TrainConductor,
    },
    {
        .id = NPC_TrainToad,
        .settings = &N(NpcSettings_TrainToad),
        .pos = { 158.0f, 0.0f, 85.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_TrainToad),
        .drops = NPC_NO_DROPS,
        .animations = TRAIN_TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_OMO_TrainConductor,
    }
};

StaticNpc N(NpcData_Epilogue)[] = {
    {
        .id = NPC_Parakarry,
        .settings = &N(NpcSettings_Parakarry),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NPC_NO_DROPS,
        .animations = PARAKARRY_ANIMS,
    },
    {
        .id = NPC_Watt,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { 50.0f, 15.0f, 160.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NPC_NO_DROPS,
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
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { 100.0f, 0.0f, 160.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_02,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { 115.0f, 0.0f, 200.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_03,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { 145.0f, 0.0f, 150.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NPC_NO_DROPS,
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
