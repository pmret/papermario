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
    EVT_EXEC_WAIT(N(EVS_StarPower_WishForSpirit))
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, ACTOR_PLAYER)
        EVT_CALL(PlaySound, SOUND_STAR_POWER_RECOVERY)
        EVT_CALL(N(RestoreStarPowerFromPlayer))
        EVT_WAIT(30)
        EVT_CALL(N(FadeBackgroundLighten))
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(RESTORE_NOT_FULL)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_RECHARGED, 60)
            EVT_CASE_EQ(RESTORE_ALREADY_FULL)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_MAXED, 60)
            EVT_CASE_EQ(RESTORE_NOW_FULL)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_FILLED, 60)
        EVT_END_SWITCH
        EVT_CALL(WaitForMessageBoxDone)
        EVT_CALL(PlayerYieldTurn)
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_ELSE
        EVT_CALL(PlaySound, SOUND_STAR_POWER_RECOVERY)
        EVT_CALL(N(RestoreStarPowerFromPartner))
        EVT_WAIT(30)
        EVT_CALL(N(FadeBackgroundLighten))
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(RESTORE_NOT_FULL)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_RECHARGED, 60)
            EVT_CASE_EQ(RESTORE_ALREADY_FULL)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_MAXED, 60)
            EVT_CASE_EQ(RESTORE_NOW_FULL)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_FILLED, 60)
        EVT_END_SWITCH
        EVT_CALL(WaitForMessageBoxDone)
        EVT_CALL(PartnerYieldTurn)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
        EVT_CALL(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_RETURN)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(N(SetPartnerWishAnim), PARTNER_WISH_ANIM_IDLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
