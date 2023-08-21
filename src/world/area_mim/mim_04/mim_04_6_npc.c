#include "mim_04.h"

#include "world/common/enemy/ForestFuzzy_Wander.inc.c"

#include "world/common/npc/Bubulb.inc.c"

#include "world/common/complete/GiveReward.inc.c"

EvtScript N(EVS_NpcInteract_Bubulb) = {
    EVT_IF_EQ(GF_MIM04_Gift_MagicalSeed3, FALSE)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Green_PopUp)
        EVT_WAIT(45)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Green_Idle)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 45, 26)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH3_000F)
        EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_SEED3)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH3_0010)
        EVT_SET(GF_MIM04_Gift_MagicalSeed3, TRUE)
        EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MIM_Bubulb_Revealed)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
                EVT_SET(LVar0, MSG_CH3_0011)
                EVT_SET(LVar1, MSG_CH3_0012)
            EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
                EVT_SET(LVar0, MSG_CH3_0013)
                EVT_SET(LVar1, MSG_CH3_0014)
            EVT_CASE_DEFAULT
                EVT_SET(LVar0, MSG_CH3_0015)
                EVT_SET(LVar1, MSG_CH3_0016)
        EVT_END_SWITCH
        EVT_IF_EQ(AF_MIM04_Bubulb_DialogueToggle, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, LVar0)
            EVT_SET(AF_MIM04_Bubulb_DialogueToggle, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, LVar1)
            EVT_SET(AF_MIM04_Bubulb_DialogueToggle, FALSE)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb)))
    EVT_IF_EQ(GF_MIM04_Gift_MagicalSeed3, FALSE)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 25, 25)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Green_BuriedIdle)
        EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MIM_Bubulb_Hidden)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Fuzzy) = {
    .id = NPC_Fuzzy,
    .pos = { 240.0f, 0.0f, -240.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 240, 0, -240 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 240, 0, -240 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_ForestFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = FOREST_FUZZY_DROPS,
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Bubulb) = {
    .id = NPC_Bubulb,
    .pos = { 0.0f, 32.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bubulb),
    .settings = &N(NpcSettings_Bubulb),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = BUBULB_GREEN_ANIMS,
    .tattle = MSG_NpcTattle_MIM_Bubulb_Revealed,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Fuzzy), BTL_MIM_FORMATION_04, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_Bubulb)),
    {}
};
