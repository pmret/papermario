#include "MontyMole.h"

EvtScript N(EVS_NpcAuxAI_MontyMole_WallAmbush) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Sub(LVar2, 50)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_MontyMole_WallAmbush_Hole) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Sub(LVar2, 50)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim13)
    Return
    End
};

MobileAISettings N(AISettings_MontyMole_WallAmbush) = {
    .moveSpeed = 1.8f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 90.0f,
    .alertOffsetDist = 70.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 25,
    .chaseRadius = 120.0f,
    .chaseOffsetDist = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_MontyMole_WallAmbush) = {
    Call(func_800445D4, LVar0)
    IfEq(LVar0, 100)
        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
        Label(10)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Add(LVar2, 130)
        Call(IsPlayerWithin, LVar0, LVar2, 80, LVar3)
        IfNe(LVar3, 1)
            Wait(1)
            Goto(10)
        EndIf
        Call(GetSelfNpcID, LVar0)
        Add(LVar0, 1)
        Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        Add(LVar2, 30)
        Add(LVar3, 50)
        Call(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        Wait(1)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, FALSE)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
        Call(EnableNpcShadow, NPC_SELF, TRUE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim0E)
        Call(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        Sub(LVar2, 30)
        Add(LVar3, 80)
        Call(SetNpcJumpscale, NPC_SELF, Float(0.7))
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, LVar1, LVar2, LVar3, 20)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 0)
        Call(NpcFacePlayer, NPC_SELF, 0)
        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
    EndIf
    Call(BasicAI_Main, Ref(N(AISettings_MontyMole_WallAmbush)))
    Return
    End
};

EvtScript N(EVS_NpcAI_MontyMole_WallAmbush_Hole_Unused) = {
    Return
    End
};

NpcSettings N(NpcSettings_MontyMole_WallAmbush) = {
    .height = 24,
    .radius = 22,
    .level = ACTOR_LEVEL_MONTY_MOLE,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_WallAmbush),
    .ai = &N(EVS_NpcAI_MontyMole_WallAmbush),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_MontyMole_WallAmbush_Hole) = {
    .height = 24,
    .radius = 22,
    .level = ACTOR_LEVEL_MONTY_MOLE,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_WallAmbush_Hole),
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
