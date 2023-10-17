#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleMisstar.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_smooch

#include "battle/common/move/StarPowerSupport.inc.c"

#include "common/AddHP.inc.c"

API_CALLABLE(N(SpawnRecoverFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_recover(0, x, y, z, duration);

    return ApiStatus_DONE2;
}

Vec2i N(RecoverEffectPositions)[] = {
    {  15,  15 },
    { -33,  27 },
    { -22, -26 },
    {  10, -35 },
    {  35,   0 },
};

EvtScript N(EVS_UsePower) = {
    EVT_EXEC_WAIT(N(EVS_StarPower_WishForSpirit))
    EVT_SET_CONST(LVar0, ANIM_BattleMisstar_Still)
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritSummoned))
    EVT_WAIT(16)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 180, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 150, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 120, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 90, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 60, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 30, 0)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_ADD(LVar0, 30)
    EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 20, 0, EASING_COS_IN_OUT)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleMisstar_Idle)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 15)
    EVT_ADD(LVar1, 15)
    EVT_ADD(LVar2, -5)
    EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 10, 0, EASING_COS_IN_OUT)
    EVT_CALL(PlaySound, SOUND_SMOOCH)
    EVT_THREAD
        EVT_PLAY_EFFECT(EFFECT_RECOVER, 2, LVar0, LVar1, LVar2, 1, 0)
        EVT_WAIT(2)
        EVT_USE_BUF(EVT_PTR(N(RecoverEffectPositions)))
        EVT_LOOP(ARRAY_COUNT(N(RecoverEffectPositions)))
            EVT_BUF_READ2(LVar5, LVar6)
            EVT_SET(LVar3, LVar0)
            EVT_SET(LVar4, LVar1)
            EVT_ADD(LVar3, LVar5)
            EVT_ADD(LVar4, LVar6)
            EVT_PLAY_EFFECT(EFFECT_RECOVER, 2, LVar3, LVar4, LVar2, 1, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_ADD(LVar0, 5)
        EVT_CALL(N(SpawnStarSparkleFX), LVar0, LVar1, LVar2)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar0, 25)
        EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 10, 0, EASING_COS_IN_OUT)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_FallBack)
    EVT_WAIT(12)
    EVT_THREAD
        EVT_EXEC_WAIT(N(EVS_StarPower_SpiritDeparts))
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2), EVT_FLOAT(0.95), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.35), EVT_FLOAT(0.85), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.38), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.4), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.85), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.95), EVT_FLOAT(1.0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2), EVT_FLOAT(0.95), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.35), EVT_FLOAT(0.85), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.38), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.4), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.95), EVT_FLOAT(1.1), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_LOOP(10)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 0)
    EVT_ADD(LVar1, 35)
    EVT_CALL(N(SpawnRecoverFX), LVar0, LVar1, LVar2, 20)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 20)
    EVT_CALL(N(AddHP), 20)
    EVT_THREAD
        EVT_CALL(N(FadeBackgroundLighten))
    EVT_END_THREAD
    EVT_CALL(PlayerYieldTurn)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(4)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};
