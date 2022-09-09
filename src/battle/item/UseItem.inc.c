#include "common.h"

/// Provide arg `TRUE` on `LocalVar(1)` to disable refunding.
EvtScript N(UseItemWithEffect) = {
    EVT_IF_EQ(LocalVar(1), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208D)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GOT_ITEM)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(0), 18)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_ADD(LocalVar(1), 45)
        EVT_SET(LocalVar(3), LocalVar(1))
        EVT_ADD(LocalVar(3), 10)
        EVT_ADD(LocalVar(3), 2)
        EVT_CALL(PlayEffect, 0x33, 1, LocalVar(0), LocalVar(3), LocalVar(2), EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(MakeItemEntity, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 1, 0)
        EVT_SET(LocalVar(10), LocalVar(0))
        EVT_CALL(N(GiveRefund))
        EVT_WAIT(LocalVar(0))
        EVT_WAIT(15)
        EVT_CALL(N(GiveRefundCleanup))
        EVT_CALL(RemoveItemEntity, LocalVar(10))
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208D)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GOT_ITEM)
        EVT_WAIT(4)
        EVT_ADD(LocalVar(1), 45)
        EVT_SET(LocalVar(3), LocalVar(1))
        EVT_ADD(LocalVar(3), 10)
        EVT_ADD(LocalVar(3), 2)
        EVT_CALL(PlayEffect, 0x33, 1, LocalVar(0), LocalVar(3), LocalVar(2), EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(MakeItemEntity, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 1, 0)
        EVT_SET(LocalVar(10), LocalVar(0))
        EVT_WAIT(15)
        EVT_CALL(RemoveItemEntity, LocalVar(10))
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GOT_ITEM)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 45)
    EVT_CALL(MakeItemEntity, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 1, 0)
    EVT_SET(LocalVar(14), LocalVar(0))
    EVT_CALL(N(GiveRefund))
    EVT_WAIT(LocalVar(0))
    EVT_WAIT(15)
    EVT_CALL(N(GiveRefundCleanup))
    EVT_CALL(RemoveItemEntity, LocalVar(14))
    EVT_RETURN
    EVT_END
};

EvtScript N(PlayerGoHome) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EatItem) = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2095)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_EAT)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};

EvtScript N(DrinkItem) = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2095)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_DRINK)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};
