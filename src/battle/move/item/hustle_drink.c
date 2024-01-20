#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_hustle_drink

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_72619C)) {
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
    if (player->transparentStatus != 0) {
        player->transparentDuration = 0;
        player->transparentStatus = 0;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A12C4_726224)) {
    gBattleStatus.hustleTurns = 2;

    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_HUSTLE_DRINK)
    ExecWait(N(UseItemWithEffect))
    ExecWait(N(DrinkItem))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Squish)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 5)
    Call(N(func_802A12C4_726224))
    Call(N(func_802A123C_72619C))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_13)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HUSTLE_WHISTLE)
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
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_GROW)
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
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HUSTLE_WHISTLE)
        PlayEffect(EFFECT_LANDING_DUST, 0, LVar0, LVar1, LVar2, 0, 0)
        PlayEffect(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 0, 0)
        Wait(4)
    EndLoop
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Wait(20)
    ExecWait(N(PlayerGoHome))
    Return
    End
};
