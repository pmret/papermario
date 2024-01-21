#include "../area.h"

#define NAMESPACE A(dig_05_script)

#include "common/SetDemoBattleBeginDelay.inc.c"

EvtScript NAMESPACE = {
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 1)
    Wait(3)
    Call(SetCamViewport, CAM_BATTLE, 29, 20, 262, 177)
    Call(EnableBattleStatusBar, FALSE)
    Set(LVar0, 5)
    Call(N(SetDemoBattleBeginDelay))
    Call(WaitForState, BATTLE_STATE_PLAYER_MENU)
    Call(SetBattleState, BATTLE_STATE_NEXT_ENEMY)
    Return
    End
};
