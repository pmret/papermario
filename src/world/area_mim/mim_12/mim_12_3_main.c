#include "mim_12.h"

EvtScript N(EVS_ExitWalk_mim_11_1) = EVT_EXIT_WALK(60, mim_12_ENTRY_0, "mim_11", mim_11_ENTRY_1);
EvtScript N(EVS_ExitWalk_arn_07_2) = EVT_EXIT_WALK(60, mim_12_ENTRY_1, "arn_07", arn_07_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mim_11_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_arn_07_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_CALL(SetNpcPos, NPC_GateBoo_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_GateBoo_02, NPC_DISPOSE_LOCATION)
    EVT_SETF(LVar0, EVT_FLOAT(240.0))
    EVT_LOOP(20)
        EVT_SUBF(LVar0, EVT_FLOAT(12.0))
        EVT_CALL(SetNpcImgFXParams, NPC_GateBoo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_GateBoo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FOREVER_FOREST)
    EVT_CALL(SetSpriteShading, SHADING_MIM_12)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 1024)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_SetupForestGate))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
