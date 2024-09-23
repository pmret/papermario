#include "common.h"
#include "sprite/player.h"

/// Provide arg `TRUE` on `LVar1` to disable refunding.
EvtScript N(UseItemWithEffect) = {
    IfEq(LVar1, 0)
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_WISH)
        Wait(10)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_USE_ITEM)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 18)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlayerRunToGoal, 0)
        Add(LVar1, 45)
        Set(LVar3, LVar1)
        Add(LVar3, 10)
        Add(LVar3, 2)
        PlayEffect(EFFECT_RADIAL_SHIMMER, 1, LVar0, LVar3, LVar2, Float(1.0), 30, 0)
        Call(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(LVarA, LVar0)
        Call(N(GiveRefund))
        Wait(LVar0)
        Wait(15)
        Call(N(GiveRefundCleanup))
        Call(RemoveItemEntity, LVarA)
    Else
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_USE_ITEM)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        Wait(4)
        Add(LVar1, 45)
        Set(LVar3, LVar1)
        Add(LVar3, 10)
        Add(LVar3, 2)
        PlayEffect(EFFECT_RADIAL_SHIMMER, 1, LVar0, LVar3, LVar2, Float(1.0), 30, 0)
        Call(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(LVarA, LVar0)
        Wait(15)
        Call(RemoveItemEntity, LVarA)
    EndIf
    Return
    End
};

EvtScript N(UseItem) = {
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, -85, 1, 0)
    Call(SetBattleCamOffsetY, 41)
    Call(SetBattleCamDist, 248)
    Call(MoveBattleCamOver, 30)
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 45)
    Call(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVarE, LVar0)
    Call(N(GiveRefund))
    Wait(LVar0)
    Wait(15)
    Call(N(GiveRefundCleanup))
    Call(RemoveItemEntity, LVarE)
    Return
    End
};

EvtScript N(PlayerGoHome) = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript N(EatItem) = {
    Thread
        Loop(4)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_EAT_OR_DRINK)
            Wait(10)
        EndLoop
    EndThread
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Eat)
    Wait(45)
    Return
    End
};

EvtScript N(DrinkItem) = {
    Thread
        Loop(4)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_EAT_OR_DRINK)
            Wait(10)
        EndLoop
    EndThread
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Drink)
    Wait(45)
    Return
    End
};
