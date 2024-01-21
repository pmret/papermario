#include "omo_03.h"

Vec3f N(FallPath)[] = {
    { -170.0,   400.0, -196.0 },
    { -100.0,   225.0, -196.0 },
    {  -70.0,    45.0, -193.0 },
};

Vec3f N(FirstBouncePath)[] = {
    {  -70.0,     0.0, -193.0 },
    {   -7.0,   100.0, -191.0 },
    {   54.0,    20.0, -189.0 },
};

Vec3f N(SecondBouncePath)[] = {
    {   54.0,     0.0, -189.0 },
    {   92.0,    55.0, -199.0 },
    {  131.0,     0.0, -210.0 },
};

EvtScript N(EVS_Scene_TrainDropped) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetCamProperties, CAM_DEFAULT, Float(90.0), 82, 24, 12, 580, Float(16.5), Float(-8.5))
    Call(TranslateGroup, MODEL_po, -170, 400, -196)
    Set(MV_DroppedTrainAngle, 30)
    Wait(45)
    Thread
        Call(MakeLerp, MV_DroppedTrainAngle, 40, 29, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_DroppedTrainAngle, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(LoadPath, 30, Ref(N(FallPath)), ARRAY_COUNT(N(FallPath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(TranslateGroup, MODEL_po, LVar1, LVar2, LVar3)
        Call(RotateGroup, MODEL_po, MV_DroppedTrainAngle, 0, 0, 1)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtModel, MODEL_p_8, SOUND_OMO_TOYBOX_TRAIN_DROP, SOUND_SPACE_DEFAULT)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(3.0))
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Idle)
        Call(SetNpcJumpscale, NPC_Conductor, Float(3.0))
        Call(GetNpcPos, NPC_Conductor, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Conductor, LVar0, LVar1, LVar2, 12)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_TrainToad, ANIM_TrainToad_Blue_Idle)
        Call(SetNpcJumpscale, NPC_TrainToad, Float(3.0))
        Call(GetNpcPos, NPC_TrainToad, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_TrainToad, LVar0, LVar1, LVar2, 15)
    EndThread
    Thread
        Call(MakeLerp, MV_DroppedTrainAngle, 18, 19, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_DroppedTrainAngle, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(LoadPath, 20, Ref(N(FirstBouncePath)), ARRAY_COUNT(N(FirstBouncePath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(TranslateGroup, MODEL_po, LVar1, LVar2, LVar3)
        Call(RotateGroup, MODEL_po, MV_DroppedTrainAngle, 0, 0, 1)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtModel, MODEL_p_8, SOUND_OMO_TOYBOX_TRAIN_DROP, SOUND_SPACE_DEFAULT)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 8, Float(2.0))
    EndThread
    Thread
        Call(GetNpcPos, NPC_Conductor, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Conductor, LVar0, LVar1, LVar2, 10)
    EndThread
    Thread
        Call(GetNpcPos, NPC_TrainToad, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_TrainToad, LVar0, LVar1, LVar2, 10)
    EndThread
    Thread
        Call(MakeLerp, MV_DroppedTrainAngle, 0, 14, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_DroppedTrainAngle, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(LoadPath, 15, Ref(N(SecondBouncePath)), ARRAY_COUNT(N(SecondBouncePath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(TranslateGroup, MODEL_po, LVar1, LVar2, LVar3)
        Call(RotateGroup, MODEL_po, MV_DroppedTrainAngle, 0, 0, 1)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtModel, MODEL_p_8, SOUND_OMO_TOYBOX_TRAIN_DROP, SOUND_SPACE_DEFAULT)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.0))
    EndThread
    Thread
        Call(GetNpcPos, NPC_Conductor, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Conductor, LVar0, LVar1, LVar2, 8)
    EndThread
    Thread
        Call(GetNpcPos, NPC_TrainToad, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_TrainToad, LVar0, LVar1, LVar2, 5)
        Loop(0)
            Call(InterpNpcYaw, NPC_TrainToad, 270, 0)
            Wait(25)
            Call(InterpNpcYaw, NPC_TrainToad, 90, 0)
            Wait(25)
        EndLoop
    EndThread
    Set(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
    Wait(75)
    Call(GotoMap, Ref("mac_04"), mac_04_ENTRY_3)
    Wait(100)
    Return
    End
};
