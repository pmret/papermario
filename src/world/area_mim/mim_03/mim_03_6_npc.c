#include "mim_03.h"

#include "world/common/npc/Oaklie.inc.c"

EvtScript N(EVS_NpcInteract_Oaklie) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_BOW_JOINED_PARTY)
            EVT_IF_EQ(AF_MIM03_Oaklie_DialogueToggle, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0009)
                EVT_SET(AF_MIM03_Oaklie_DialogueToggle, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000A)
                EVT_SET(AF_MIM03_Oaklie_DialogueToggle, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            EVT_IF_EQ(AF_MIM03_Oaklie_DialogueToggle, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000B)
                EVT_SET(AF_MIM03_Oaklie_DialogueToggle, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000C)
                EVT_SET(AF_MIM03_Oaklie_DialogueToggle, FALSE)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            EVT_IF_EQ(AF_MIM03_Oaklie_DialogueToggle, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000D)
                EVT_SET(AF_MIM03_Oaklie_DialogueToggle, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000E)
                EVT_SET(AF_MIM03_Oaklie_DialogueToggle, FALSE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Oaklie) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Oaklie)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Oaklie) = {
    .id = NPC_Oaklie,
    .pos = { 0.0f, 32.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Oaklie),
    .settings = &N(NpcSettings_Oaklie),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = OAKLIE_ANIMS,
    .tattle = MSG_NpcTattle_Oaklie,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Oaklie)),
    {}
};
