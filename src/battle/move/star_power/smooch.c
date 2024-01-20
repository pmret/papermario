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
    ExecWait(N(EVS_StarPower_WishForSpirit))
    SetConst(LVar0, ANIM_BattleMisstar_Still)
    ExecWait(N(EVS_StarPower_SpiritSummoned))
    Wait(16)
    Thread
        Wait(10)
        Call(SetNpcRotation, NPC_BTL_SPIRIT, 0, 180, 0)
        Wait(1)
        Call(SetNpcRotation, NPC_BTL_SPIRIT, 0, 150, 0)
        Wait(1)
        Call(SetNpcRotation, NPC_BTL_SPIRIT, 0, 120, 0)
        Wait(1)
        Call(SetNpcRotation, NPC_BTL_SPIRIT, 0, 90, 0)
        Wait(1)
        Call(SetNpcRotation, NPC_BTL_SPIRIT, 0, 60, 0)
        Wait(1)
        Call(SetNpcRotation, NPC_BTL_SPIRIT, 0, 30, 0)
        Wait(1)
        Call(SetNpcRotation, NPC_BTL_SPIRIT, 0, 0, 0)
    EndThread
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    Add(LVar0, 30)
    Call(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 20, 0, EASING_COS_IN_OUT)
    Wait(15)
    Call(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleMisstar_Idle)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 15)
    Add(LVar1, 15)
    Add(LVar2, -5)
    Call(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 10, 0, EASING_COS_IN_OUT)
    Call(PlaySound, SOUND_SMOOCH)
    Thread
        PlayEffect(EFFECT_RECOVER, 2, LVar0, LVar1, LVar2, 1, 0)
        Wait(2)
        UseBuf(Ref(N(RecoverEffectPositions)))
        Loop(ARRAY_COUNT(N(RecoverEffectPositions)))
            BufRead2(LVar5, LVar6)
            Set(LVar3, LVar0)
            Set(LVar4, LVar1)
            Add(LVar3, LVar5)
            Add(LVar4, LVar6)
            PlayEffect(EFFECT_RECOVER, 2, LVar3, LVar4, LVar2, 1, 0)
            Wait(2)
        EndLoop
    EndThread
    Thread
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 15)
        Add(LVar0, 5)
        Call(N(SpawnStarSparkleFX), LVar0, LVar1, LVar2)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Add(LVar0, 25)
        Call(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 10, 0, EASING_COS_IN_OUT)
    EndThread
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_FallBack)
    Wait(12)
    Thread
        ExecWait(N(EVS_StarPower_SpiritDeparts))
    EndThread
    Thread
        Loop(2)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(1.0), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.2), Float(0.95), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.9), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.35), Float(0.85), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.38), Float(0.8), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.4), Float(0.8), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.85), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.2), Float(0.9), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.95), Float(1.0))
            Wait(1)
        EndLoop
        Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(1.0), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.2), Float(0.95), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.9), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.35), Float(0.85), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.38), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.4), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(0.9), Float(1.3), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(0.9), Float(1.2), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(0.95), Float(1.1), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
        Wait(1)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EndThread
    Loop(10)
        Wait(3)
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 0)
    Add(LVar1, 35)
    Call(N(SpawnRecoverFX), LVar0, LVar1, LVar2, 20)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 20)
    Call(N(AddHP), 20)
    Thread
        Call(N(FadeBackgroundLighten))
    EndThread
    Call(PlayerYieldTurn)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
    Call(SetActorSpeed, ACTOR_PLAYER, Float(1.0))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(func_80273444, 20, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(4)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Return
    End
};
