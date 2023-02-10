#include "flo_16.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_FLO16_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_TetherCameraToPlayer) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_WAIT(2)
    EVT_CALL(GetPlayerPos, LVar7, LVar8, LVar9)
    EVT_EXEC_GET_TID(N(EVS_TetherCameraToPlayer), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_CALL(PlayerJump, 450, 180, -120, 30)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(IsPlayerPounding)) {
    script->varTable[0] = FALSE;
    if (gPlayerStatus.actionState == ACTION_STATE_SPIN_POUND || gPlayerStatus.actionState == ACTION_STATE_TORNADO_POUND) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MonitorCeilingPound) = {
    EVT_IF_EQ(AF_FLO16_FoundHiddenStarPiece, FALSE)
        EVT_CALL(N(IsPlayerPounding))
        EVT_IF_EQ(LVar0, 0)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar0)
            EVT_CASE_RANGE(620, 660)
                EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 640, 145, -100, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_FLO16_Item_StarPiece)
                EVT_SET(AF_FLO16_FoundHiddenStarPiece, TRUE)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_SET(AF_FLO16_FoundHiddenStarPiece, FALSE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_MonitorCeilingPound)), TRIGGER_FLOOR_TOUCH, COLLIDER_o214, 1, 0)
    EVT_MAKE_SUPER_BLOCK(350, 240, -100, 0)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 472, 100, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_RETURN
    EVT_END
};
