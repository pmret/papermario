#include "flo_22.h"

#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/complete/Bzzap.h"
#include "world/common/enemy/complete/CrazyDayzee.h"

EvtScript N(EVS_NpcIdle_Bzzap) = {
    EVT_SET(MV_Bzzap_State, 0)
    EVT_LOOP(0)
        EVT_SWITCH(MV_Bzzap_State)
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(1)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002E)
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
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, FALSE)
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
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002E)
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
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, FALSE)
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

StaticNpc N(NpcData_Bzzap) = {
    .id = NPC_Bzzap,
    .settings = &N(NpcSettings_Dummy),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(EVS_NpcInit_Bzzap),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Bzzap_Anim02,
        .walk   = ANIM_Bzzap_Anim02,
        .run    = ANIM_Bzzap_Anim03,
        .chase  = ANIM_Bzzap_Anim03,
        .anim_4 = ANIM_Bzzap_Anim01,
        .anim_5 = ANIM_Bzzap_Anim02,
        .death  = ANIM_Bzzap_Anim06,
        .hit    = ANIM_Bzzap_Anim06,
        .anim_8 = ANIM_Bzzap_Anim04,
        .anim_9 = ANIM_Bzzap_Anim02,
        .anim_A = ANIM_Bzzap_Anim01,
        .anim_B = ANIM_Bzzap_Anim01,
        .anim_C = ANIM_Bzzap_Anim01,
        .anim_D = ANIM_Bzzap_Anim01,
        .anim_E = ANIM_Bzzap_Anim01,
        .anim_F = ANIM_Bzzap_Anim01,
    },
};

StaticNpc N(NpcData_Dayzee) = {
    .id = NPC_Dayzee,
    .settings = &N(NpcSettings_Dummy),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(EVS_NpcInit_Dayzee),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 15,
        .itemDrops = {
            { ITEM_MAPLE_SYRUP, 6, 0 },
            { ITEM_HONEY_SYRUP, 4, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(4),
        .minCoinBonus = 0,
        .maxCoinBonus = 3,
    },
    .animations = {
        .idle   = ANIM_Dayzee_Anim01,
        .walk   = ANIM_Dayzee_Anim02,
        .run    = ANIM_Dayzee_Anim03,
        .chase  = ANIM_Dayzee_Anim03,
        .anim_4 = ANIM_Dayzee_Anim01,
        .anim_5 = ANIM_Dayzee_Anim01,
        .death  = ANIM_Dayzee_Anim08,
        .hit    = ANIM_Dayzee_Anim08,
        .anim_8 = ANIM_Dayzee_Anim06,
        .anim_9 = ANIM_Dayzee_Anim07,
        .anim_A = ANIM_Dayzee_Anim01,
        .anim_B = ANIM_Dayzee_Anim01,
        .anim_C = ANIM_Dayzee_Anim01,
        .anim_D = ANIM_Dayzee_Anim01,
        .anim_E = ANIM_Dayzee_Anim01,
        .anim_F = ANIM_Dayzee_Anim01,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bzzap), BTL_FLO_FORMATION_17, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Dayzee), BTL_FLO_FORMATION_0F, BTL_FLO_STAGE_01),
    {}
};
