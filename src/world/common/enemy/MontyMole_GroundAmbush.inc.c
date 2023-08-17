#include "MontyMole.h"

EvtScript N(EVS_NpcAuxAI_MontyMole_GroundAmbush) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_MontyMole_GroundAmbush_Hole) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim12)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_MontyMole_GroundAmbush) = {
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

EvtScript N(EVS_NpcAI_MontyMole_GroundAmbush) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_IF_EQ(LVar0, 100)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
        EVT_LABEL(10)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IsPlayerWithin, LVar0, LVar2, 80, LVar3)
        EVT_IF_NE(LVar3, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_ADD(LVar2, 30)
        EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, FALSE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim0E)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar4, LVar5, LVar6)
        EVT_ADD(LVar5, 30)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, LVar4, LVar5, LVar6, 20)
        EVT_CALL(SetNpcPos, LVar0, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 0)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
        EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_MontyMole_GroundAmbush)))
        EVT_RETURN
        EVT_END
};

NpcSettings N(NpcSettings_MontyMole_GroundAmbush) = {
    .height = 24,
    .radius = 22,
    .level = ACTOR_LEVEL_MONTY_MOLE,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_GroundAmbush),
    .ai = &N(EVS_NpcAI_MontyMole_GroundAmbush),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_MontyMole_GroundAmbush_Hole) = {
    .height = 24,
    .radius = 22,
    .level = ACTOR_LEVEL_MONTY_MOLE,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_GroundAmbush_Hole),
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
