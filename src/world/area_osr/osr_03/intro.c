#include "osr_03.h"
#include "sprite/player.h"

API_CALLABLE(N(MakeCastleChainAngle)) {
    Bytecode* args = script->ptrReadPos;
    s32 angle = evt_get_variable(script, *args);

    evt_set_variable(script, *args++, sin_deg(angle) * 20.0f);
    return ApiStatus_DONE2;
}

Vec3f N(UnusedFallingPath1)[] = {
    { -100.0,    70.0,  873.0 },
    { -328.0,   -10.0,  900.0 },
    { -406.0,   -90.0,  958.0 },
    { -485.0,  -170.0, 1010.0 },
    { -618.0,  -230.0, 1075.0 },
};

EvtScript N(EVS_UnusedFalling1) = {
    Call(LoadPath, 90, Ref(N(UnusedFallingPath1)), ARRAY_COUNT(N(UnusedFallingPath1)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetPlayerPos, LVar1, LVar2, LVar3)
        Wait(1)
        IfNe(LVar0, 1)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

Vec3f N(UnusedFallingPath2)[] = {
    { -1380.0,  -2950.0, 2300.0 },
    { -1325.0,  -3030.0, 2327.0 },
    { -1257.0,  -3050.0, 2306.0 },
    { -1225.0,  -3000.0, 2318.0 },
    { -1268.0,  -3000.0, 2306.0 },
    { -1325.0,  -3057.0, 2297.0 },
    { -1387.0,  -3134.0, 2324.0 },
    { -1433.0,  -3181.0, 2352.0 },
};

EvtScript N(EVS_UnusedFalling2) = {
    Call(LoadPath, 135, Ref(N(UnusedFallingPath2)), ARRAY_COUNT(N(UnusedFallingPath2)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetPlayerPos, LVar1, LVar2, LVar3)
        Wait(1)
        IfNe(LVar0, 1)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_AnimateSwingingChains) = {
    Loop(0)
        Call(MakeLerp, 90, -90, 30 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            Call(N(MakeCastleChainAngle), LVar0)
            Call(RotateGroup, MODEL_ku_ta, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(2)
            Call(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            Call(RotateGroup, MODEL_ku_ta, -20, 0, 0, 1)
            Wait(1)
        EndLoop
        Call(MakeLerp, -90, 90, 30 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            Call(N(MakeCastleChainAngle), LVar0)
            Call(RotateGroup, MODEL_ku_ta, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(2)
            Call(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            Call(RotateGroup, MODEL_ku_ta, 20, 0, 0, 1)
            Wait(1)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_AnimateSpinningRing) = {
    Loop(0)
        Call(MakeLerp, 45, -45, 60 * DT, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_wa, 0, MV_CastleLiftDist, 0)
            Call(RotateGroup, MODEL_wa, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, -45, 45, 60 * DT, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_wa, 0, MV_CastleLiftDist, 0)
            Call(RotateGroup, MODEL_wa, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_AnimateCastle) = {
    Set(MV_CastleLiftDist, 0)
    Exec(N(EVS_AnimateSwingingChains))
    Exec(N(EVS_AnimateSpinningRing))
    Call(MakeLerp, -800, 4500, 400 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Set(MV_CastleLiftDist, LVar0)
        Call(TranslateGroup, MODEL_g439, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_kao, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_yoru, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_80241190) = {
    Call(MakeLerp, 0, -5000, 300, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o1464, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_80241224) = {
    Call(MakeLerp, 0, -5000, 300, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o1502, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_802412B8) = {
    Call(MakeLerp, 0, -5000, 300, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o1465, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_8024134C) = {
    Call(MakeLerp, 0, -5000, 300, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o1503, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(MV_Scene_CastleAscending) = {
    Call(SetMusicTrack, 0, SONG_BOWSER_ATTACKS, 0, 8)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerPos, 0, 0, 2000)
    Call(EnableGroup, MODEL_hiru, FALSE)
    Call(EnableGroup, MODEL_niwa, FALSE)
    Call(EnableGroup, MODEL_jimidori, FALSE)
    Call(EnableGroup, MODEL_ki1, FALSE)
    Call(EnableGroup, MODEL_jimen, FALSE)
    Call(EnableGroup, MODEL_kemuri, FALSE)
    Call(EnableGroup, MODEL_obj, FALSE)
    Call(EnableGroup, MODEL_g277, FALSE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 80, 16, 4096)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, -1, 0)
    Call(SetCamType, CAM_DEFAULT, 1, TRUE)
    Call(SetPanTarget, CAM_DEFAULT, -150, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(-13.0), Float(18.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Exec(N(EVS_AnimateCastle))
    Wait(1)
    Call(SetPanTarget, CAM_DEFAULT, -50, 200, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(1000.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.75))
    Wait(180 * DT)
    Call(GotoMap, Ref("kkj_13"), kkj_13_ENTRY_2)
    Wait(100 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

Vec3f N(FlightPath_TossedOut)[] = {
    { -300.0,     0.0,  300.0 },
    { -500.0,    25.0,  900.0 },
    { -720.0,  -650.0, 1500.0 },
};

EvtScript N(MV_Scene_PlayerTossedOut) = {
    Call(FadeOutMusic, 0, 500)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_UsePower)
    Call(EnableGroup, MODEL_hiru, FALSE)
    Call(EnableGroup, MODEL_niwa, FALSE)
    Call(EnableGroup, MODEL_jimidori, FALSE)
    Call(EnableGroup, MODEL_kumo, FALSE)
    Call(EnableGroup, MODEL_ki1, FALSE)
    Call(EnableGroup, MODEL_jimen, FALSE)
    Call(EnableGroup, MODEL_kemuri, FALSE)
    Call(EnableGroup, MODEL_obj, FALSE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 80, 16, 4096)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, -1, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, -1, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(-13.0), Float(18.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Set(MV_CastleLiftDist, 0)
    Exec(N(EVS_AnimateSwingingChains))
    Exec(N(EVS_AnimateSpinningRing))
    ChildThread
        Set(LVar0, 0)
        Loop(0)
            Add(LVar0, 45)
            Call(InterpPlayerYaw, LVar0, 0)
            Wait(1)
        EndLoop
    EndChildThread
    Call(LoadPath, 90 * DT, Ref(N(FlightPath_TossedOut)), ARRAY_COUNT(N(FlightPath_TossedOut)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetPlayerPos, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(GotoMap, Ref("kkj_13"), kkj_13_ENTRY_3)
    Wait(100)
    Return
    End
};

// alternate scene for the player being tossed out the window, where they flutter down like a piece of paper
EvtScript N(EVS_Scene_UnusedTossOut) = {
    Call(FadeOutMusic, 0, 500)
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_Hurt)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    Call(EnableGroup, MODEL_hiru, FALSE)
    Call(EnableGroup, MODEL_niwa, FALSE)
    Call(EnableGroup, MODEL_jimidori, FALSE)
    Call(EnableGroup, MODEL_kumo, FALSE)
    Call(EnableGroup, MODEL_ki1, FALSE)
    Call(EnableGroup, MODEL_jimen, FALSE)
    Call(EnableGroup, MODEL_kemuri, FALSE)
    Call(EnableGroup, MODEL_obj, FALSE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 6000)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -400, -1500, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(3500.0))
    Call(SetCamPosA, CAM_DEFAULT, -300, -160)
    Call(SetCamPosB, CAM_DEFAULT, 300, 80)
    Call(SetCamPitch, CAM_DEFAULT, Float(-30.0), Float(0.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(DisablePlayerPhysics, TRUE)
    Wait(15)
    ExecWait(N(EVS_UnusedFalling2))
    Wait(60)
    Call(GotoMap, Ref("hos_10"), hos_10_ENTRY_5)
    Wait(100)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
