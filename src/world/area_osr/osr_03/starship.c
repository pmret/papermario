#include "osr_03.h"

EvtScript N(EVS_SetStarshipPosRot) = {
    Loop(0)
        Call(TranslateGroup, MODEL_g277, MV_Starship_PosX, MV_Starship_PosY, MV_Starship_PosZ)
        Call(RotateGroup, MODEL_g277, MV_Starship_Yaw, 0, 1, 0)
        Set(LVar0, MV_Starship_PosX)
        Set(LVar1, MV_Starship_PosY)
        Set(LVar2, MV_Starship_PosZ)
        Add(LVar1, 20)
        Add(LVar2, -10)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar2, 20)
        Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

Vec3f N(FlightPath)[] = {
    { -700.0,  -350.0, 1600.0 },
    { -700.0,  -470.0, 1600.0 },
    { -660.0,  -505.0, 1590.0 },
    { -565.0,  -520.0, 1615.0 },
    { -235.0,  -660.0, 1445.0 },
    { -110.0,  -715.0, 1300.0 },
    {   15.0,  -770.0, 1155.0 },
    {    0.0,  -770.0,  920.0 },
    {   20.0,  -600.0,  600.0 },
};

EvtScript N(EVS_Scene_Starship) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(TranslateGroup, MODEL_g277, -700, -350, 1600)
    Set(MV_Starship_Yaw, 50)
    Set(MV_Starship_PosX, -700)
    Set(MV_Starship_PosY, -350)
    Set(MV_Starship_PosZ, 1600)
    Exec(N(EVS_SetStarshipPosRot))
    Set(MV_CastleLiftDist, 0)
    Exec(N(EVS_AnimateSwingingChains))
    Exec(N(EVS_AnimateSpinningRing))
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 80, 16, 4096)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, -1, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, -1, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(-13.0), Float(18.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Thread
        Call(PlaySound, SOUND_STARSHIP_NEAR_FLYBY)
        Call(MakeLerp, 50, 10, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_Starship_Yaw, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 10, 115, 80, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_Starship_Yaw, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    ChildThread
        Loop(0)
            Call(FacePlayerTowardPoint, 0, 0, 0)
            Wait(1)
        EndLoop
    EndChildThread
    Thread
        Call(LoadPath, 120, Ref(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
        Label(90)
        Call(GetNextPathPos)
        Set(MV_Starship_PosX, LVar1)
        Set(MV_Starship_PosY, LVar2)
        Set(MV_Starship_PosZ, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(90)
        EndIf
    EndThread
    Wait(100)
    Call(GotoMap, Ref("kpa_60"), kpa_60_ENTRY_4)
    Wait(100)
    Return
    End
};
