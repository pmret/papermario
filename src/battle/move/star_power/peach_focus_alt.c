#include "common.h"
#include "script_api/battle.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_peach_focus_alt

#include "battle/common/move/StarPowerSupport.inc.c"

API_CALLABLE(N(RestoreStarPower)) {
    PlayerData* playerData = &gPlayerData;
    PlayerData* playerData2 = &gPlayerData;

    if (is_ability_active(ABILITY_DEEP_FOCUS)) {
        playerData->starPower += SP_PER_SEG * 4;
    }
    if (is_ability_active(ABILITY_SUPER_FOCUS)) {
        playerData->starPower += SP_PER_BAR;
    }

    playerData->starPower += SP_PER_SEG * 4;

    if (playerData2->starPower >= playerData2->maxStarPower * SP_PER_BAR) {
        playerData2->starPower = playerData2->maxStarPower * SP_PER_BAR;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UsePower) = {
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_WISH)
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach2_SpreadArms)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 16)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayerRunToGoal, 0)
    Wait(8)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(N(SpawnStarSparkleFX), LVar0, LVar1, LVar2)
    Call(N(FadeBackgroundDarken))
    Wait(20)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach3_Pray)
    Wait(10)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(N(SpawnWishSparkleFX), LVar0, LVar1, LVar2)
    Wait(30)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach2_Curious)
    Call(N(RestoreStarPower))
    Wait(10)
    Call(N(FadeBackgroundLighten))
    Wait(15)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Idle)
    Return
    End
};
