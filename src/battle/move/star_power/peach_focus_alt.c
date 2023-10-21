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
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach2_SpreadArms)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 16)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_WAIT(8)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(N(SpawnStarSparkleFX), LVar0, LVar1, LVar2)
    EVT_CALL(N(FadeBackgroundDarken))
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach3_Pray)
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(N(SpawnWishSparkleFX), LVar0, LVar1, LVar2)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach2_Curious)
    EVT_CALL(N(RestoreStarPower))
    EVT_WAIT(10)
    EVT_CALL(N(FadeBackgroundLighten))
    EVT_WAIT(15)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Idle)
    EVT_RETURN
    EVT_END
};
