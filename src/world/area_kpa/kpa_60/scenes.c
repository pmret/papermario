#include "kpa_60.h"

EvtScript N(EVS_SetStarshipPosRot) = {
    Loop(0)
        Call(TranslateGroup, MODEL_g405, MV_Starship_PosX, MV_Starship_PosY, MV_Starship_PosZ)
        Call(RotateGroup, MODEL_g405, MV_Starship_Yaw, 0, 1, 0)
        Call(GetModelCenter, MODEL_o1638)
        Sub(LVar0, 10)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 20)
        Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

Vec3f N(FlightPath_Arrival)[] = {
    {  -58.0,  -166.0, -545.0 },
    { -116.0,   -50.0, -759.0 },
    { -120.0,   160.0, -970.0 },
};

EvtScript N(EVS_Scene_Arrival) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Set(MV_Starship_Yaw, 0)
    Set(MV_Starship_PosX, 0)
    Set(MV_Starship_PosY, 0)
    Set(MV_Starship_PosZ, 0)
    Exec(N(EVS_SetStarshipPosRot))
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 30, 16, 4096)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, -70, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, -70, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(PlaySound, SOUND_STARSHIP_FLY_AWAY)
    Call(LoadPath, 45, Ref(N(FlightPath_Arrival)), ARRAY_COUNT(N(FlightPath_Arrival)), EASING_LINEAR)
    Label(90)
        Call(GetNextPathPos)
        Set(MV_Starship_PosX, LVar1)
        Set(MV_Starship_PosY, LVar2)
        Set(MV_Starship_PosZ, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(90)
        EndIf
    Wait(20)
    IfEq(GF_StartedChapter8, FALSE)
        Wait(15)
        Set(GF_StartedChapter8, TRUE)
        Call(FadeOutMusic, 0, 1500)
        Call(GotoMapSpecial, Ref("kmr_22"), kmr_22_ENTRY_8, TRANSITION_BEGIN_OR_END_CHAPTER)
        Wait(100)
        Return
    EndIf
    Call(GotoMap, Ref("kpa_63"), kpa_63_ENTRY_1)
    Wait(100)
    Return
    End
};

Vec3f N(FlightPath_Departure)[] = {
    { -120.0,   160.0, -970.0 },
    { -116.0,   -50.0, -759.0 },
    {  -58.0,  -166.0, -545.0 },
    {    0.0,     0.0,    0.0 },
};

EvtScript N(EVS_Scene_Departure) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(InterpPlayerYaw, 180, 1)
    Call(SetNpcYaw, NPC_PARTNER, 270)
    Set(MV_Starship_Yaw, 180)
    Set(MV_Starship_PosX, -120)
    Set(MV_Starship_PosY, 160)
    Set(MV_Starship_PosZ, -970)
    Exec(N(EVS_SetStarshipPosRot))
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 30, 16, 4096)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, -70, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, -70, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Thread
        Call(PlaySound, SOUND_STARSHIP_FLY_TOWARD)
        Call(LoadPath, 45, Ref(N(FlightPath_Departure)), ARRAY_COUNT(N(FlightPath_Departure)), EASING_LINEAR)
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
    Wait(40)
    Call(GotoMap, Ref("hos_20"), hos_20_ENTRY_2)
    Wait(100)
    Return
    End
};
