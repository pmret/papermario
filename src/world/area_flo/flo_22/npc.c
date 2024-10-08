#include "flo_22.h"
#include "sprite/player.h"

#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Bzzap.h"
#include "world/common/enemy/CrazyDayzee.h"

EvtScript N(EVS_NpcIdle_Bzzap) = {
    Set(MV_Bzzap_State, 0)
    Loop(0)
        Switch(MV_Bzzap_State)
            CaseEq(0)
            CaseEq(1)
                Call(SetPlayerAnimation, ANIM_Mario1_FallBack)
                Set(MV_Bzzap_State, 0)
                Call(StartBattle)
        EndSwitch
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Bzzap) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Thread
                Wait(25)
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
            EndThread
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Bzzap_Anim01)
            Call(SetNpcPos, NPC_SELF, 30, 60, 0)
            Wait(10)
            Call(SetNpcJumpscale, NPC_SELF, 0)
            Call(NpcJump0, NPC_SELF, 30, 0, 0, 15)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Bzzap) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Bzzap)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Bzzap)))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Dayzee) = {
    Set(MV_Dayzee_State, 0)
    Loop(0)
        Switch(MV_Dayzee_State)
            CaseEq(0)
            CaseEq(1)
                Call(SetPlayerAnimation, ANIM_Mario1_FallBack)
                Set(MV_Dayzee_State, 0)
                Call(StartBattle)
        EndSwitch
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Dayzee) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Thread
                Wait(25)
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
            EndThread
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Dayzee_Anim01)
            Wait(10)
            Call(SetNpcJumpscale, NPC_SELF, Float(2.0))
            Call(NpcJump0, NPC_SELF, 30, 0, 0, 15)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Dayzee_Anim01)
            Wait(10)
            Call(SetNpcJumpscale, NPC_SELF, Float(2.0))
            Call(NpcJump0, NPC_SELF, 30, 0, 0, 15)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Dayzee) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Dayzee)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Dayzee)))
    Return
    End
};

NpcData N(NpcData_Bzzap) = {
    .id = NPC_Bzzap,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bzzap),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = BZZAP_ANIMS,
};

NpcData N(NpcData_Dayzee) = {
    .id = NPC_Dayzee,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Dayzee),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = CRAZY_DAYZEE_DROPS,
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bzzap), BTL_FLO_FORMATION_17, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Dayzee), BTL_FLO_FORMATION_0F, BTL_FLO_STAGE_01),
    {}
};
