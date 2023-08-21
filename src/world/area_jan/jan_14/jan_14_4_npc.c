#include "jan_14.h"

#include "world/common/enemy/JungleFuzzy.h"

// uses base fuzzy includes instead of JungleFuzzy!
#include "world/common/enemy/Fuzzy_Wander.inc.c"
#include "world/common/enemy/Fuzzy.inc.c"

EvtScript N(EVS_NpcIdle_JungleFuzzy) = {
    EVT_LABEL(0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar1, 40)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(45)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Fuzzy_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Unused) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JungleFuzzy) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JungleFuzzy)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_JungleFuzzy_01) = {
    .id = NPC_JungleFuzzy_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_JungleFuzzy),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_JungleFuzzy_02) = {
    .id = NPC_JungleFuzzy_02,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_JungleFuzzy),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_JungleFuzzy_01), BTL_JAN_FORMATION_0A, BTL_JAN_STAGE_04),
    NPC_GROUP(N(NpcData_JungleFuzzy_02), BTL_JAN_FORMATION_0B, BTL_JAN_STAGE_04),
    {}
};
