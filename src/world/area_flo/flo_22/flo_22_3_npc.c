#include "flo_22.h"
#include "sprite/player.h"

#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Bzzap.h"
#include "world/common/enemy/CrazyDayzee.h"

EvtScript N(EVS_NpcIdle_Bzzap) = {
    EVT_SET(MV_Bzzap_State, 0)
    EVT_LOOP(0)
        EVT_SWITCH(MV_Bzzap_State)
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(1)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_FallBack)
                EVT_SET(MV_Bzzap_State, 0)
                EVT_CALL(StartBattle)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Bzzap) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_THREAD
                EVT_WAIT(25)
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
            EVT_END_THREAD
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bzzap_Anim01)
            EVT_CALL(SetNpcPos, NPC_SELF, 30, 60, 0)
            EVT_WAIT(10)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
            EVT_CALL(NpcJump0, NPC_SELF, 30, 0, 0, 15)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bzzap) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Bzzap)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Bzzap)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Dayzee) = {
    EVT_SET(MV_Dayzee_State, 0)
    EVT_LOOP(0)
        EVT_SWITCH(MV_Dayzee_State)
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(1)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_FallBack)
                EVT_SET(MV_Dayzee_State, 0)
                EVT_CALL(StartBattle)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Dayzee) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_THREAD
                EVT_WAIT(25)
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
            EVT_END_THREAD
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dayzee_Anim01)
            EVT_WAIT(10)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
            EVT_CALL(NpcJump0, NPC_SELF, 30, 0, 0, 15)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dayzee_Anim01)
            EVT_WAIT(10)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
            EVT_CALL(NpcJump0, NPC_SELF, 30, 0, 0, 15)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dayzee) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Dayzee)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Dayzee)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Bzzap) = {
    .id = NPC_Bzzap,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bzzap),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = BZZAP_ANIMS,
};

NpcData N(NpcData_Dayzee) = {
    .id = NPC_Dayzee,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Dayzee),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = CRAZY_DAYZEE_DROPS,
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bzzap), BTL_FLO_FORMATION_17, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Dayzee), BTL_FLO_FORMATION_0F, BTL_FLO_STAGE_01),
    {}
};
