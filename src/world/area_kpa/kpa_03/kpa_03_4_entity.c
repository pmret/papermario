#include "kpa_03.h"
#include "entity.h"

API_CALLABLE(N(MonitorPlayerAltitude)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPos.y >= 0) {
        evt_set_variable(script, MV_PlayerHeightLevel, 0);
    }
    if (playerStatus->lastGoodPos.y <= -280) {
        evt_set_variable(script, MV_PlayerHeightLevel, 1);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_TetherCamToPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGe(LVar1, LVar3)
            Set(LVar1, LVar3)
        EndIf
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UseSpring) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    IfEq(MV_PlayerHeightLevel, 0)
        Set(LVar3, -275)
        ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
        Call(SetPlayerJumpscale, Float(0.7))
        Call(PlayerJump, -507, -288, -159, 20)
    Else
        Set(LVar3, 0)
        ExecGetTID(N(EVS_TetherCamToPlayer), LVarA)
        Call(SetPlayerJumpscale, Float(1.1))
        Call(PlayerJump, -500, 0, -150, 40)
    EndIf
    KillThread(LVarA)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Wait(4)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Thread
        Call(N(MonitorPlayerAltitude))
    EndThread
    Call(MakeEntity, Ref(Entity_ScriptSpring), -400, -300, -150, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring)))
    Call(MakeEntity, Ref(Entity_YellowBlock), 620, -65, -200, 0, ITEM_SHOOTING_STAR, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KPA03_ItemBlock_ShootingStar)
    Return
    End
};
