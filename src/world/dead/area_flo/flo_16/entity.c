#include "flo_16.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_FLO16_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_TetherCameraToPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UseSpring) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    Wait(2)
    Call(GetPlayerPos, LVar7, LVar8, LVar9)
    ExecGetTID(N(EVS_TetherCameraToPlayer), LVarA)
    Call(SetPlayerJumpscale, Float(0.7))
    Call(PlayerJump, 450, 180, -120, 30)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(DisablePlayerPhysics, false)
    Call(DisablePlayerInput, false)
    Return
    End
};

API_CALLABLE(N(IsPlayerPounding)) {
    script->varTable[0] = false;
    if (gPlayerStatus.actionState == ACTION_STATE_SPIN_POUND || gPlayerStatus.actionState == ACTION_STATE_TORNADO_POUND) {
        script->varTable[0] = true;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MonitorCeilingPound) = {
    IfEq(AF_FLO16_FoundHiddenStarPiece, false)
        Call(N(IsPlayerPounding))
        IfEq(LVar0, 0)
            Return
        EndIf
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Switch(LVar0)
            CaseRange(620, 660)
                Call(MakeItemEntity, ITEM_STAR_PIECE, 640, 145, -100, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_FLO16_Item_StarPiece)
                Set(AF_FLO16_FoundHiddenStarPiece, true)
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Set(AF_FLO16_FoundHiddenStarPiece, false)
    BindTrigger(Ref(N(EVS_MonitorCeilingPound)), TRIGGER_FLOOR_TOUCH, COLLIDER_o214, 1, 0)
    EVT_MAKE_SUPER_BLOCK(350, 240, -100, 0)
    Call(MakeEntity, Ref(Entity_ScriptSpring), 472, 100, -100, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring)))
    Return
    End
};
