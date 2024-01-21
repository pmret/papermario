#include "common.h"
#include "script_api/battle.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_focus

#include "battle/common/move/StarPowerSupport.inc.c"

enum {
    RESTORE_NOT_FULL        = 0,
    RESTORE_ALREADY_FULL    = 1,
    RESTORE_NOW_FULL        = 2,
};

API_CALLABLE(N(RestoreStarPowerFromPlayer)) {
    PlayerData* playerData = &gPlayerData;
    s32 deepFocusSP;
    s32 superFocusSP;

    script->varTable[0] = RESTORE_NOT_FULL;

    if (playerData->starPower >= playerData->maxStarPower * SP_PER_BAR) {
        script->varTable[0] = RESTORE_ALREADY_FULL;
        return ApiStatus_DONE2;
    }

    deepFocusSP = is_ability_active(ABILITY_DEEP_FOCUS) * SP_PER_SEG * 2;
    superFocusSP = is_ability_active(ABILITY_SUPER_FOCUS) * SP_PER_SEG * 4;

    add_star_power(deepFocusSP + superFocusSP + SP_PER_SEG * 4);

    if (playerData->starPower == playerData->maxStarPower * SP_PER_BAR) {
        script->varTable[0] = RESTORE_NOW_FULL;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(RestoreStarPowerFromPartner)) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[0] = RESTORE_NOT_FULL;

    if (playerData->starPower >= playerData->maxStarPower * SP_PER_BAR) {
        script->varTable[0] = RESTORE_ALREADY_FULL;
        return ApiStatus_DONE2;
    }

    add_star_power(SP_PER_SEG * 4);

    if (playerData->starPower == playerData->maxStarPower * SP_PER_BAR) {
        script->varTable[0] = RESTORE_NOW_FULL;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UsePower) = {
    ExecWait(N(EVS_StarPower_WishForSpirit))
    Call(EnableBattleStatusBar, TRUE)
    Call(GetOwnerID, LVarA)
    IfEq(LVarA, ACTOR_PLAYER)
        Call(PlaySound, SOUND_STAR_POWER_RECOVERY)
        Call(N(RestoreStarPowerFromPlayer))
        Wait(30)
        Call(N(FadeBackgroundLighten))
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Switch(LVar0)
            CaseEq(RESTORE_NOT_FULL)
                Call(ShowMessageBox, BTL_MSG_STAR_POWER_RECHARGED, 60)
            CaseEq(RESTORE_ALREADY_FULL)
                Call(ShowMessageBox, BTL_MSG_STAR_POWER_MAXED, 60)
            CaseEq(RESTORE_NOW_FULL)
                Call(ShowMessageBox, BTL_MSG_STAR_POWER_FILLED, 60)
        EndSwitch
        Call(WaitForMessageBoxDone)
        Call(PlayerYieldTurn)
        Call(SetGoalToHome, ACTOR_PLAYER)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
        Call(PlayerRunToGoal, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Else
        Call(PlaySound, SOUND_STAR_POWER_RECOVERY)
        Call(N(RestoreStarPowerFromPartner))
        Wait(30)
        Call(N(FadeBackgroundLighten))
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Switch(LVar0)
            CaseEq(RESTORE_NOT_FULL)
                Call(ShowMessageBox, BTL_MSG_STAR_POWER_RECHARGED, 60)
            CaseEq(RESTORE_ALREADY_FULL)
                Call(ShowMessageBox, BTL_MSG_STAR_POWER_MAXED, 60)
            CaseEq(RESTORE_NOW_FULL)
                Call(ShowMessageBox, BTL_MSG_STAR_POWER_FILLED, 60)
        EndSwitch
        Call(WaitForMessageBoxDone)
        Call(PartnerYieldTurn)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(8.0))
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_RETURN)
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Call(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_IDLE)
    EndIf
    Return
    End
};
