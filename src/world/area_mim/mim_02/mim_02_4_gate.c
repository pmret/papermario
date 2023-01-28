#include "mim_02.h"

#include "../common/SupportGates.inc.c"

#include "../common/AnimateGates.inc.c"

EvtScript N(EVS_UseGate_North) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, 0)
    EVT_SET(LVar8, 70)
    EVT_SET(LVar9, COLLIDER_monn)
    EVT_SET(LVarA, MODEL_monn)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_South) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, 0)
    EVT_SET(LVar8, -70)
    EVT_SET(LVar9, COLLIDER_mons)
    EVT_SET(LVarA, MODEL_mons)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_East) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, -70)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, COLLIDER_mone)
    EVT_SET(LVarA, MODEL_mone)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_West) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, 70)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, COLLIDER_monw)
    EVT_SET(LVarA, MODEL_monw)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGates) = {
    EVT_IF_EQ(GF_MIM_ChoosingPath, FALSE)
        EVT_SET(GF_MIM_ChoosingPath, TRUE)
        EVT_SET(AB_MIM_1, 2)
        EVT_SET(LVar1, 2)
        EVT_SET(LVar2, -10)
    EVT_ELSE
        EVT_SET(GF_MIM_ChoosingPath, FALSE)
        EVT_SET(AB_MIM_1, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 10)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetGateCameraZones))
    EVT_EXEC(N(EVS_InitializeGates))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate_North)), TRIGGER_WALL_PRESS_A, COLLIDER_monn, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate_South)), TRIGGER_WALL_PRESS_A, COLLIDER_mons, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate_East)), TRIGGER_WALL_PRESS_A, COLLIDER_mone, 1, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate_West)), TRIGGER_WALL_PRESS_A, COLLIDER_monw, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnableWestGate) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate_West)), TRIGGER_WALL_PRESS_A, COLLIDER_monw, 1, 0)
    EVT_RETURN
    EVT_END
};
