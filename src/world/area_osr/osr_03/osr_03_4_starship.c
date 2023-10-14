#include "osr_03.h"

EvtScript N(EVS_SetStarshipPosRot) = {
    EVT_LOOP(0)
        EVT_CALL(TranslateGroup, MODEL_g277, MV_Starship_PosX, MV_Starship_PosY, MV_Starship_PosZ)
        EVT_CALL(RotateGroup, MODEL_g277, MV_Starship_Yaw, 0, 1, 0)
        EVT_SET(LVar0, MV_Starship_PosX)
        EVT_SET(LVar1, MV_Starship_PosY)
        EVT_SET(LVar2, MV_Starship_PosZ)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, -10)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 20)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(TranslateGroup, MODEL_g277, -700, -350, 1600)
    EVT_SET(MV_Starship_Yaw, 50)
    EVT_SET(MV_Starship_PosX, -700)
    EVT_SET(MV_Starship_PosY, -350)
    EVT_SET(MV_Starship_PosZ, 1600)
    EVT_EXEC(N(EVS_SetStarshipPosRot))
    EVT_SET(MV_CastleLiftDist, 0)
    EVT_EXEC(N(EVS_AnimateSwingingChains))
    EVT_EXEC(N(EVS_AnimateSpinningRing))
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 80, 16, 4096)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, -1, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, -1, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-13.0), EVT_FLOAT(18.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_STARSHIP_NEAR_FLYBY)
        EVT_CALL(MakeLerp, 50, 10, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_Starship_Yaw, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 10, 115, 80, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_Starship_Yaw, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(FacePlayerTowardPoint, 0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_THREAD
        EVT_CALL(LoadPath, 120, EVT_PTR(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
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
    EVT_WAIT(100)
    EVT_CALL(GotoMap, EVT_PTR("kpa_60"), kpa_60_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
