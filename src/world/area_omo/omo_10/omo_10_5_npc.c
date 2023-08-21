#include "omo_10.h"

#include "world/common/npc/TrainToad.inc.c"

EvtScript N(EVS_NpcInteract_Conductor) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(D_802444A0_DDBE50))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Conductor) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Conductor)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_TrainToad) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Red_Talk, ANIM_TrainToad_Red_Idle, 0, MSG_CH4_0031)
        EVT_CASE_LT(STORY_CH4_DEFEATED_GENERAL_GUY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Red_Talk, ANIM_TrainToad_Red_Idle, 0, MSG_CH4_0032)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Red_Talk, ANIM_TrainToad_Red_Idle, 0, MSG_CH4_0033)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrainToad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TrainToad)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Toads)[] = {
    {
        .id = NPC_Conductor,
        .pos = { 10.0f, 50.0f, -105.0f },
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
        .pos = { -50.0f, 0.0f, 80.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TrainToad),
        .settings = &N(NpcSettings_TrainToad),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TRAIN_TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_OMO_TrainConductor,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toads)),
    {}
};
