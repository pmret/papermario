#include "sbk_34.h"

NpcSettings N(NpcSettings_Nomadimouse) = {
    .height = 22,
    .radius = 25,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_Nomadimouse)[] = {
    ITEM_LETTER_TO_NOMADIMOUSE,
    ITEM_NONE
};

EvtScript N(EVS_Nomadimouse_LetterDelivery) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Nomadimouse, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle,
        ITEM_LETTER_TO_NOMADIMOUSE, ITEM_NONE,
        MSG_CH2_005B, MSG_CH2_005C, MSG_CH2_005D, MSG_CH2_005E,
        EVT_PTR(N(LetterList_Nomadimouse)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_Nomadimouse) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Nomadimouse) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
            EVT_IF_EQ(GF_SBK34_Met_Nomadimouse, FALSE)
                EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), 0, EVT_FLOAT(250.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle, 0, MSG_CH2_0056)
                EVT_SET(GF_SBK34_Met_Nomadimouse, TRUE)
                EVT_CALL(ResetCam, CAM_DEFAULT, 4)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle, 0, MSG_CH2_0057)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
            EVT_IF_EQ(GF_SBK34_Met_Nomadimouse, FALSE)
                EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), 0, EVT_FLOAT(250.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle, 0, MSG_CH2_0058)
                EVT_SET(GF_SBK34_Met_Nomadimouse, TRUE)
                EVT_CALL(ResetCam, CAM_DEFAULT, 4)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle, 0, MSG_CH2_0059)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Nomadimouse_Talk, ANIM_Nomadimouse_Idle, 0, MSG_CH2_005A)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_Nomadimouse_LetterDelivery))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Nomadimouse))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Nomadimouse) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Nomadimouse)))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Nomadimouse_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Sack) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Nomadimouse_Sack)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Nomadimouse)[] = {
    {
        .id = NPC_Nomadimouse,
        .pos = { 114.0f, 0.0f, -50.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Nomadimouse),
        .settings = &N(NpcSettings_Nomadimouse),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Nomadimouse_Idle,
            .walk   = ANIM_Nomadimouse_Idle,
            .run    = ANIM_Nomadimouse_Idle,
            .chase  = ANIM_Nomadimouse_Idle,
            .anim_4 = ANIM_Nomadimouse_Idle,
            .anim_5 = ANIM_Nomadimouse_Idle,
            .death  = ANIM_Nomadimouse_Idle,
            .hit    = ANIM_Nomadimouse_Idle,
            .anim_8 = ANIM_Nomadimouse_Idle,
            .anim_9 = ANIM_Nomadimouse_Idle,
            .anim_A = ANIM_Nomadimouse_Idle,
            .anim_B = ANIM_Nomadimouse_Idle,
            .anim_C = ANIM_Nomadimouse_Idle,
            .anim_D = ANIM_Nomadimouse_Idle,
            .anim_E = ANIM_Nomadimouse_Idle,
            .anim_F = ANIM_Nomadimouse_Idle,
        },
        .tattle = MSG_NpcTattle_SBK_Nomadimouse,
    },
    {
        .id = NPC_Sack,
        .pos = { 134.0f, 0.0f, -50.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Sack),
        .settings = &N(NpcSettings_Nomadimouse),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Nomadimouse_Idle,
            .walk   = ANIM_Nomadimouse_Idle,
            .run    = ANIM_Nomadimouse_Idle,
            .chase  = ANIM_Nomadimouse_Idle,
            .anim_4 = ANIM_Nomadimouse_Idle,
            .anim_5 = ANIM_Nomadimouse_Idle,
            .death  = ANIM_Nomadimouse_Idle,
            .hit    = ANIM_Nomadimouse_Idle,
            .anim_8 = ANIM_Nomadimouse_Idle,
            .anim_9 = ANIM_Nomadimouse_Idle,
            .anim_A = ANIM_Nomadimouse_Idle,
            .anim_B = ANIM_Nomadimouse_Idle,
            .anim_C = ANIM_Nomadimouse_Idle,
            .anim_D = ANIM_Nomadimouse_Idle,
            .anim_E = ANIM_Nomadimouse_Idle,
            .anim_F = ANIM_Nomadimouse_Idle,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Nomadimouse)),
    {}
};
