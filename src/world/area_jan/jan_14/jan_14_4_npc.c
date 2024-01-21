#include "jan_14.h"

#include "world/common/enemy/JungleFuzzy.h"

// uses base fuzzy includes instead of JungleFuzzy!
#include "world/common/enemy/Fuzzy_Wander.inc.c"
#include "world/common/enemy/Fuzzy.inc.c"

EvtScript N(EVS_NpcIdle_JungleFuzzy) = {
    Label(0)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    IfGt(LVar1, 40)
        Wait(1)
        Goto(0)
    EndIf
    Wait(45)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Fuzzy_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Unused) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(RemoveNpc, NPC_SELF)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_JungleFuzzy) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JungleFuzzy)))
    Return
    End
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
