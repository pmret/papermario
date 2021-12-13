#include "common.h"

/// Provide arg `TRUE` on `EVT_VAR(1)` to disable refunding.
EvtSource N(UseItemWithEffect) = {
    EVT_IF_EQ(EVT_VAR(1), 0)
        EVT_CALL(UseBattleCamPreset, 69)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208D)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GOT_ITEM)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), 18)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FIXED(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_ADD(EVT_VAR(1), 45)
        EVT_SET(EVT_VAR(3), EVT_VAR(1))
        EVT_ADD(EVT_VAR(3), 10)
        EVT_ADD(EVT_VAR(3), 2)
        EVT_CALL(PlayEffect, 0x33, 1, EVT_VAR(0), EVT_VAR(3), EVT_VAR(2), EVT_FIXED(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(MakeItemEntity, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 0)
        EVT_SET(EVT_VAR(10), EVT_VAR(0))
        EVT_CALL(N(GiveRefund))
        EVT_WAIT_FRAMES(EVT_VAR(0))
        EVT_WAIT_FRAMES(15)
        EVT_CALL(N(GiveRefundCleanup))
        EVT_CALL(RemoveItemEntity, EVT_VAR(10))
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208D)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GOT_ITEM)
        EVT_WAIT_FRAMES(4)
        EVT_ADD(EVT_VAR(1), 45)
        EVT_SET(EVT_VAR(3), EVT_VAR(1))
        EVT_ADD(EVT_VAR(3), 10)
        EVT_ADD(EVT_VAR(3), 2)
        EVT_CALL(PlayEffect, 0x33, 1, EVT_VAR(0), EVT_VAR(3), EVT_VAR(2), EVT_FIXED(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(MakeItemEntity, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 0)
        EVT_SET(EVT_VAR(10), EVT_VAR(0))
        EVT_WAIT_FRAMES(15)
        EVT_CALL(RemoveItemEntity, EVT_VAR(10))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(UseItem) = {
    EVT_CALL(UseBattleCamPreset, 19)
    EVT_CALL(SetBattleCamTarget, -85, 1, 0)
    EVT_CALL(SetBattleCamOffsetZ, 41)
    EVT_CALL(SetBattleCamZoom, 248)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GOT_ITEM)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 45)
    EVT_CALL(MakeItemEntity, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 0)
    EVT_SET(EVT_VAR(14), EVT_VAR(0))
    EVT_CALL(N(GiveRefund))
    EVT_WAIT_FRAMES(EVT_VAR(0))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(N(GiveRefundCleanup))
    EVT_CALL(RemoveItemEntity, EVT_VAR(14))
    EVT_RETURN
    EVT_END
};

EvtSource N(PlayerGoHome) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FIXED(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(EatItem) = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2095)
            EVT_WAIT_FRAMES(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_EAT)
    EVT_WAIT_FRAMES(45)
    EVT_RETURN
    EVT_END
};

EvtSource N(DrinkItem) = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2095)
            EVT_WAIT_FRAMES(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_DRINK)
    EVT_WAIT_FRAMES(45)
    EVT_RETURN
    EVT_END
};
