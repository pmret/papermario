#include "common.h"
#include "sprite/player.h"

/// Provide arg `TRUE` on `LVar1` to disable refunding.
EvtScript N(UseItemWithEffect) = {
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_USE_ITEM)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 18)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_ADD(LVar1, 45)
        EVT_SET(LVar3, LVar1)
        EVT_ADD(LVar3, 10)
        EVT_ADD(LVar3, 2)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 30, 0)
        EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(LVarA, LVar0)
        EVT_CALL(N(GiveRefund))
        EVT_WAIT(LVar0)
        EVT_WAIT(15)
        EVT_CALL(N(GiveRefundCleanup))
        EVT_CALL(RemoveItemEntity, LVarA)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_USE_ITEM)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        EVT_WAIT(4)
        EVT_ADD(LVar1, 45)
        EVT_SET(LVar3, LVar1)
        EVT_ADD(LVar3, 10)
        EVT_ADD(LVar3, 2)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 30, 0)
        EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(LVarA, LVar0)
        EVT_WAIT(15)
        EVT_CALL(RemoveItemEntity, LVarA)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(UseItem) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -85, 1, 0)
    EVT_CALL(SetBattleCamOffsetZ, 41)
    EVT_CALL(SetBattleCamZoom, 248)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 45)
    EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVarE, LVar0)
    EVT_CALL(N(GiveRefund))
    EVT_WAIT(LVar0)
    EVT_WAIT(15)
    EVT_CALL(N(GiveRefundCleanup))
    EVT_CALL(RemoveItemEntity, LVarE)
    EVT_RETURN
    EVT_END
};

EvtScript N(PlayerGoHome) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EatItem) = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_EAT_OR_DRINK)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Eat)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};

EvtScript N(DrinkItem) = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_EAT_OR_DRINK)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Drink)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};
