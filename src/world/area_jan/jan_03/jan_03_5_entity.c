#include "jan_03.h"
#include "entity.h"
#include "sprite/player.h"

EvtScript N(EVS_GotoMap_tik_08_4) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_08"), tik_08_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};


API_CALLABLE(N(GiveInitialSpringBoost)) {
    f32 x = gPlayerStatus.curSpeed * 5.0f * sin_deg(gPlayerStatus.targetYaw);
    f32 z = gPlayerStatus.curSpeed * 5.0f * -cos_deg(gPlayerStatus.targetYaw);

    script->varTable[0] = gPlayerStatus.pos.x + x;
    script->varTable[1] = gPlayerStatus.pos.z + z;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_TetherCamToPlayer) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring) = {
    EVT_CALL(N(GiveInitialSpringBoost))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayer), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.1))
    EVT_CALL(PlayerJump, -556, 300, -195, 15)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(FacePlayerTowardPoint, -630, -50, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Fall)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump2, -601, 376, -105, 30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_JAN03_WarpPipe, FALSE)
        EVT_IF_EQ(GF_TIK08_WarpPipe, TRUE)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_NE(LVar0, jan_03_ENTRY_3)
                EVT_SET(GF_JAN03_WarpPipe, TRUE)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueWarpPipe), -540, 0, 195, 30, jan_03_ENTRY_3, EVT_PTR(N(EVS_GotoMap_tik_08_4)), EVT_INDEX_OF_GAME_FLAG(GF_JAN03_WarpPipe), MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 100, 60, -25, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), -556, 0, -195, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_RETURN
    EVT_END
};
