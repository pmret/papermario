#include "arn_08.h"

#include "world/common/npc/TubbasHeart.inc.c"
#include "world/common/npc/Yakkey.inc.c"

EvtScript N(EVS_NpcIdle_TubbasHeart) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TubbasHeart) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WELL)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_ELSE
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TubbasHeart)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Yakkey) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_WHALE_MOUTH_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00BA)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00BB)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00BC)
        EVT_CASE_LT(STORY_CH8_OPENED_PATH_TO_STAR_WAY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00BD)
        EVT_CASE_GE(STORY_CH8_OPENED_PATH_TO_STAR_WAY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00BE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Yakkey) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_ELSE
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Yakkey)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_TubbasHeart) = {
    .id = NPC_TubbasHeart,
    .pos = { -23.0f, 75.0f, 31.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_TubbasHeart),
    .settings = &N(NpcSettings_TubbasHeart),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = TUBBAS_HEART_ANIMS,
};

NpcData N(NpcData_Yakkey) = {
    .id = NPC_Yakkey,
    .pos = { 38.0f, 0.0f, 97.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Yakkey),
    .settings = &N(NpcSettings_Yakkey),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = YAKKEY_ANIMS,
    .tattle = MSG_NpcTattle_Yakkey,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TubbasHeart)),
    NPC_GROUP(N(NpcData_Yakkey)),
    {}
};
