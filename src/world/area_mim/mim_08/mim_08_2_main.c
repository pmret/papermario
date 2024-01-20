#include "mim_08.h"

#include "../common/SetForeverForestFog.inc.c"

API_CALLABLE(N(GetPlayerDistFromMapCenter)) {
    script->varTable[0] = get_xz_dist_to_player(0.0f, 0.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_n) = EVT_EXIT_WALK(60, mim_08_ENTRY_0, "mim_01", mim_01_ENTRY_1);
EvtScript N(EVS_ExitWalk_w) = EVT_EXIT_WALK(60, mim_08_ENTRY_1, "mim_05", mim_05_ENTRY_3);
EvtScript N(EVS_ExitWalk_s) = EVT_EXIT_WALK(60, mim_08_ENTRY_2, "mim_01", mim_01_ENTRY_1);
EvtScript N(EVS_ExitWalk_e) = EVT_EXIT_WALK(60, mim_08_ENTRY_3, "mim_01", mim_01_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_n)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_w)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_s)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_e)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(D_802431F0_BB0B30) = {
    Loop(6)
        Set(LVar0, 2)
        Call(TranslateModel, MODEL_o507, LVar0, 0, LVar0)
        Call(TranslateModel, MODEL_o508, LVar0, 0, LVar0)
        Wait(1)
        Set(LVar0, -2)
        Call(TranslateModel, MODEL_o507, LVar0, 0, LVar0)
        Call(TranslateModel, MODEL_o508, LVar0, 0, LVar0)
        Wait(1)
    EndLoop
    Set(LVar0, 0)
    Call(TranslateModel, MODEL_o507, LVar0, 0, LVar0)
    Call(TranslateModel, MODEL_o508, LVar0, 0, LVar0)
    Wait(1)
    Set(MV_Unk_00, 1)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FOREVER_FOREST)
    Call(SetSpriteShading, SHADING_MIM_08)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 650)
    Call(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Set(AB_MIM_2, GB_MIM_CurrentMapID)
    Call(GetMapID, GB_MIM_CurrentMapID)
    ExecWait(N(EVS_SetupGates))
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Exec(N(EVS_SetupMusic))
    BindTrigger(Ref(N(D_802431F0_BB0B30)), TRIGGER_WALL_HAMMER, COLLIDER_o473, 1, 0)
    Call(N(SetForeverForestFog))
    Thread
        Label(0)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(N(GetPlayerDistFromMapCenter))
        IfLt(LVar0, 350)
            Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Else
            Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
        EndIf
        Goto(0)
    EndThread
    Return
    End
};
