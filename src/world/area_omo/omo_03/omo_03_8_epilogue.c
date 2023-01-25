#include "omo_03.h"
#include "effects.h"

Vec3f N(FlightPath)[] = {
    { -100.0,   200.0,  130.0 },
    {  -70.0,    60.0,  140.0 },
    {  -40.0,    25.0,  150.0 },
    {  -10.0,    15.0,  160.0 },
};

EvtScript N(EVS_Scene_Epilogue) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(GetNpcPos, NPC_Watt, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 13)
    EVT_PLAY_EFFECT(EFFECT_STATIC_STATUS, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.9), 5, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 50, 0, 160)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 50, 0, 160)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim11)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim11)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_03, ANIM_ShyGuy_Red_Anim11)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_Watt, ANIM_WorldWatt_Talk)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim01)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_03, ANIM_ShyGuy_Red_Anim01)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    EVT_CALL(LoadPath, 60, EVT_PTR(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Parakarry, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim01)
    EVT_CALL(SetNpcAnimation, NPC_Watt, ANIM_WorldWatt_Idle)
    EVT_CALL(NpcFaceNpc, NPC_Watt, NPC_Parakarry, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Talk)
    EVT_WAIT(60)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(GotoMap, EVT_PTR("jan_04"), jan_04_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
