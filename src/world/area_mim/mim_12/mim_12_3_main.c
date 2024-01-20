#include "mim_12.h"

EvtScript N(EVS_ExitWalk_mim_11_1) = EVT_EXIT_WALK(60, mim_12_ENTRY_0, "mim_11", mim_11_ENTRY_1);
EvtScript N(EVS_ExitWalk_arn_07_2) = EVT_EXIT_WALK(60, mim_12_ENTRY_1, "arn_07", arn_07_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_mim_11_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_arn_07_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Call(SetNpcPos, NPC_GateBoo_01, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_GateBoo_02, NPC_DISPOSE_LOCATION)
    SetF(LVar0, Float(240.0))
    Loop(20)
        SubF(LVar0, Float(12.0))
        Call(SetNpcImgFXParams, NPC_GateBoo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_GateBoo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Wait(10)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FOREVER_FOREST)
    Call(SetSpriteShading, SHADING_MIM_12)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 1024)
    Call(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_SetupForestGate))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
