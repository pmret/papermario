#include "common.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_dig_dig_05_script

#include "common/SetDemoBattleBeginDelay.inc.c"

EvtScript NAMESPACE = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT(3)
    EVT_CALL(SetCamViewport, CAM_BATTLE, 29, 20, 262, 177)
    EVT_CALL(func_802535B4, 0)
    EVT_SET(LVar0, 5)
    EVT_CALL(N(SetDemoBattleBeginDelay))
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_CALL(SetBattleState, BATTLE_STATE_NEXT_ENEMY)
    EVT_RETURN
    EVT_END
};
