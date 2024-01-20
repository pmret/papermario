#include "iwa_04.h"
#include "entity.h"

API_CALLABLE(N(MonitorPlayerAltitude)) {
    s32 status = -1;

    if (gPlayerStatus.lastGoodPos.y > -100.0) {
        status = 0;
    }
    if (gPlayerStatus.lastGoodPos.y < -240.0) {
        status = 1;
    }
    if (status >= 0) {
        evt_set_variable(script, MV_PlayerCliffLevel, status);
    }

    return ApiStatus_BLOCK;
}

EvtScript N(TetherCameraToPlayer) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_UseSpring) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    Wait(1)
    ExecGetTID(N(TetherCameraToPlayer), LVarA)
    IfEq(MV_PlayerCliffLevel, 0)
        Call(SetPlayerJumpscale, Float(1.4))
        Call(PlayerJump, -560, -250, 190, 15)
    Else
        Call(SetPlayerJumpscale, Float(0.7))
        Call(PlayerJump, -560, 0, 90, 40)
    EndIf
    KillThread(LVarA)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Thread
        Call(N(MonitorPlayerAltitude))
    EndThread
    Call(MakeEntity, Ref(Entity_ScriptSpring), -561, -250, 121, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring)))
    Call(MakeEntity, Ref(Entity_ArrowSign), -513, 0, -97, 0, 90, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_ArrowSign), 600, 0, 200, 0, 270, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_ArrowSign), 336, -140, 203, 0, 70, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_ArrowSign), 730, -250, -95, 0, 90, MAKE_ENTITY_END)
    Call(MakeItemEntity, ITEM_LETTER_CHAIN_GOOMPAPA_1, -275, -250, 150, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA04_Item_Letter10)
    Return
    End
};
