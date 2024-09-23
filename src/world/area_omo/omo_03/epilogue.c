#include "omo_03.h"
#include "effects.h"

Vec3f N(FlightPath)[] = {
    { -100.0,   200.0,  130.0 },
    {  -70.0,    60.0,  140.0 },
    {  -40.0,    25.0,  150.0 },
    {  -10.0,    15.0,  160.0 },
};

EvtScript N(EVS_Scene_Epilogue) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(GetNpcPos, NPC_Watt, LVar0, LVar1, LVar2)
    Add(LVar1, 13)
    PlayEffect(EFFECT_STATIC_STATUS, 0, LVar0, LVar1, LVar2, Float(0.9), 5, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, 50, 0, 160)
    Call(SetPanTarget, CAM_DEFAULT, 50, 0, 160)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-7.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim11)
    Call(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim11)
    Call(SetNpcAnimation, NPC_ShyGuy_03, ANIM_ShyGuy_Red_Anim11)
    Wait(60)
    Call(SetNpcAnimation, NPC_Watt, ANIM_WorldWatt_Talk)
    Call(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim01)
    Call(SetNpcAnimation, NPC_ShyGuy_03, ANIM_ShyGuy_Red_Anim01)
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    Call(LoadPath, 60, Ref(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
    Label(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Parakarry, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim01)
    Call(SetNpcAnimation, NPC_Watt, ANIM_WorldWatt_Idle)
    Call(NpcFaceNpc, NPC_Watt, NPC_Parakarry, 0)
    Wait(10)
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Talk)
    Wait(60)
    Call(FadeOutMusic, 0, 1000)
    Call(GotoMap, Ref("jan_04"), jan_04_ENTRY_3)
    Wait(100)
    Return
    End
};
