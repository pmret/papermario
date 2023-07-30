#include "isk_10.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_ISK10_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

API_CALLABLE(N(MonitorPlayerLastFloor)) {
    s32 level = -1;

    if (gPlayerStatus.lastGoodPos.y > -600.0) {
        level = 0;
    }
    if (gPlayerStatus.lastGoodPos.y < -770.0) {
        level = 1;
    }
    if (level >= 0) {
        evt_set_variable(script, MV_LastFloorLevel, level);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_UseSpring) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_IF_EQ(MV_LastFloorLevel, 0)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.4))
        EVT_CALL(PlayerJump, -577, -780, -75, 15)
    EVT_ELSE
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.8))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, -520)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.4))
        EVT_CALL(PlayerJump, -561, -520, 23, 30)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.8))
    EVT_END_IF
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_MAKE_SUPER_BLOCK(-550, -720, 0, 0)
    EVT_THREAD
        EVT_CALL(N(MonitorPlayerLastFloor))
    EVT_END_THREAD
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), -516, -780, -71, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_PLAY_EFFECT(EFFECT_FLAME, 1, -510, -453, 43, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, 1, -510, -713, 43, EVT_FLOAT(0.3), LVar0)
    EVT_RETURN
    EVT_END
};
