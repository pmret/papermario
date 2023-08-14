#include "omo_06.h"

#include "world/common/npc/TrainToad.inc.c"

EvtScript N(EVS_NpcInteract_Conductor) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(D_80244B10_DBC420))
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
        EVT_CASE_LT(STORY_CH4_GOT_FRYING_PAN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0023)
        EVT_CASE_LT(STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0024)
        EVT_CASE_LT(STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0025)
        EVT_CASE_LT(STORY_CH4_PULLED_SWITCH_SWITCH)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0026)
        EVT_CASE_LT(STORY_CH4_SOLVED_COLOR_PUZZLE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0027)
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0028)
        EVT_CASE_LT(STORY_CH4_DEFEATED_GENERAL_GUY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_0029)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Pink_Talk, ANIM_TrainToad_Pink_Idle, 0, MSG_CH4_002A)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrainToad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TrainToad)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcSettings_Toads)[] = {
    {
        .id = NPC_Conductor,
        .pos = { 50.0f, 50.0f, 45.0f },
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
        .pos = { 55.0f, 0.0f, 240.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TrainToad),
        .settings = &N(NpcSettings_TrainToad),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TRAIN_TOAD_PINK_ANIMS,
        .tattle = MSG_NpcTattle_OMO_TrainConductor,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcSettings_Toads)),
    {}
};
