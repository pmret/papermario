#include "hustle_drink.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_72619C)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    if (player->debuff != 0) {
        player->debuffDuration = 0;
        player->debuff = 0;
        remove_status_debuff(player->hudElementDataIndex);
    }
    if (player->staticStatus != 0) {
        player->staticDuration = 0;
        player->staticStatus = 0;
        remove_status_static(player->hudElementDataIndex);
    }
    if (player->stoneStatus != 0) {
        player->stoneDuration = 0;
        player->stoneStatus = 0;
    }
    if (player->transStatus != 0) {
        player->transDuration = 0;
        player->transStatus = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12C4_726224)(Evt* script, s32 isInitialCall) {
    gBattleStatus.hustleTurns = 2;

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x00000091)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_EXEC_WAIT(N(DrinkItem))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_SQUISH)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 25)
    EVT_CALL(func_802D7520, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 5)
    EVT_CALL(N(func_802A12C4_726224))
    EVT_CALL(N(func_802A123C_72619C))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 20)
    EVT_CALL(UseBattleCamPreset, 13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_369)
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.1), EVT_FIXED(1.0), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.2), EVT_FIXED(0.95), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.3), EVT_FIXED(0.9), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.35), EVT_FIXED(0.85), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.38), EVT_FIXED(0.8), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.4), EVT_FIXED(0.8), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.3), EVT_FIXED(0.85), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.2), EVT_FIXED(0.9), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.1), EVT_FIXED(0.95), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.1), EVT_FIXED(1.0), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.2), EVT_FIXED(0.95), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.3), EVT_FIXED(0.9), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.35), EVT_FIXED(0.85), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.38), EVT_FIXED(0.8), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.4), EVT_FIXED(0.8), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_208E)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(0.9), EVT_FIXED(1.3), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(0.9), EVT_FIXED(1.2), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(0.95), EVT_FIXED(1.1), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_END_THREAD
    EVT_LOOP(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_369)
        EVT_CALL(PlayEffect, 0x6, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, 0x6, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(4)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
