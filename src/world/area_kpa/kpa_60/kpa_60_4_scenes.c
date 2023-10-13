#include "kpa_60.h"

EvtScript N(EVS_SetStarshipPosRot) = {
    EVT_LOOP(0)
        EVT_CALL(TranslateGroup, MODEL_g405, MV_Starship_PosX, MV_Starship_PosY, MV_Starship_PosZ)
        EVT_CALL(RotateGroup, MODEL_g405, MV_Starship_Yaw, 0, 1, 0)
        EVT_CALL(GetModelCenter, MODEL_o1638)
        EVT_SUB(LVar0, 10)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 20)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

Vec3f N(FlightPath_Arrival)[] = {
    {  -58.0,  -166.0, -545.0 },
    { -116.0,   -50.0, -759.0 },
    { -120.0,   160.0, -970.0 },
};

EvtScript N(EVS_Scene_Arrival) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_SET(MV_Starship_Yaw, 0)
    EVT_SET(MV_Starship_PosX, 0)
    EVT_SET(MV_Starship_PosY, 0)
    EVT_SET(MV_Starship_PosZ, 0)
    EVT_EXEC(N(EVS_SetStarshipPosRot))
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 30, 16, 4096)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, -70, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, -70, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(PlaySound, SOUND_STARSHIP_FLY_AWAY)
    EVT_CALL(LoadPath, 45, EVT_PTR(N(FlightPath_Arrival)), ARRAY_COUNT(N(FlightPath_Arrival)), EASING_LINEAR)
    EVT_LABEL(90)
        EVT_CALL(GetNextPathPos)
        EVT_SET(MV_Starship_PosX, LVar1)
        EVT_SET(MV_Starship_PosY, LVar2)
        EVT_SET(MV_Starship_PosZ, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(90)
        EVT_END_IF
    EVT_WAIT(20)
    EVT_IF_EQ(GF_StartedChapter8, FALSE)
        EVT_WAIT(15)
        EVT_SET(GF_StartedChapter8, TRUE)
        EVT_CALL(FadeOutMusic, 0, 1500)
        EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_22"), kmr_22_ENTRY_8, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_WAIT(100)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("kpa_63"), kpa_63_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

Vec3f N(FlightPath_Departure)[] = {
    { -120.0,   160.0, -970.0 },
    { -116.0,   -50.0, -759.0 },
    {  -58.0,  -166.0, -545.0 },
    {    0.0,     0.0,    0.0 },
};

EvtScript N(EVS_Scene_Departure) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(InterpPlayerYaw, 180, 1)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 270)
    EVT_SET(MV_Starship_Yaw, 180)
    EVT_SET(MV_Starship_PosX, -120)
    EVT_SET(MV_Starship_PosY, 160)
    EVT_SET(MV_Starship_PosZ, -970)
    EVT_EXEC(N(EVS_SetStarshipPosRot))
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 30, 16, 4096)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, -70, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, -70, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_STARSHIP_FLY_TOWARD)
        EVT_CALL(LoadPath, 45, EVT_PTR(N(FlightPath_Departure)), ARRAY_COUNT(N(FlightPath_Departure)), EASING_LINEAR)
        EVT_LABEL(90)
            EVT_CALL(GetNextPathPos)
            EVT_SET(MV_Starship_PosX, LVar1)
            EVT_SET(MV_Starship_PosY, LVar2)
            EVT_SET(MV_Starship_PosZ, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(90)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(GotoMap, EVT_PTR("hos_20"), hos_20_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
