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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(90.0), 82, 24, 12, 580, EVT_FLOAT(16.5), EVT_FLOAT(-8.5))
    EVT_CALL(TranslateGroup, MODEL_po, -170, 400, -196)
    EVT_SET(MV_DroppedTrainAngle, 30)
    EVT_WAIT(45)
    EVT_THREAD
        EVT_CALL(MakeLerp, MV_DroppedTrainAngle, 40, 29, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_DroppedTrainAngle, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 30, EVT_PTR(N(FallPath)), ARRAY_COUNT(N(FallPath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(TranslateGroup, MODEL_po, LVar1, LVar2, LVar3)
        EVT_CALL(RotateGroup, MODEL_po, MV_DroppedTrainAngle, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtModel, MODEL_p_8, SOUND_OMO_TOYBOX_TRAIN_DROP, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Idle)
        EVT_CALL(SetNpcJumpscale, NPC_Conductor, EVT_FLOAT(3.0))
        EVT_CALL(GetNpcPos, NPC_Conductor, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Conductor, LVar0, LVar1, LVar2, 12)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_TrainToad, ANIM_TrainToad_Blue_Idle)
        EVT_CALL(SetNpcJumpscale, NPC_TrainToad, EVT_FLOAT(3.0))
        EVT_CALL(GetNpcPos, NPC_TrainToad, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_TrainToad, LVar0, LVar1, LVar2, 15)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, MV_DroppedTrainAngle, 18, 19, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_DroppedTrainAngle, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 20, EVT_PTR(N(FirstBouncePath)), ARRAY_COUNT(N(FirstBouncePath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(TranslateGroup, MODEL_po, LVar1, LVar2, LVar3)
        EVT_CALL(RotateGroup, MODEL_po, MV_DroppedTrainAngle, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtModel, MODEL_p_8, SOUND_OMO_TOYBOX_TRAIN_DROP, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 8, EVT_FLOAT(2.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Conductor, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Conductor, LVar0, LVar1, LVar2, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_TrainToad, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_TrainToad, LVar0, LVar1, LVar2, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, MV_DroppedTrainAngle, 0, 14, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_DroppedTrainAngle, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 15, EVT_PTR(N(SecondBouncePath)), ARRAY_COUNT(N(SecondBouncePath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(TranslateGroup, MODEL_po, LVar1, LVar2, LVar3)
        EVT_CALL(RotateGroup, MODEL_po, MV_DroppedTrainAngle, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtModel, MODEL_p_8, SOUND_OMO_TOYBOX_TRAIN_DROP, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Conductor, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Conductor, LVar0, LVar1, LVar2, 8)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_TrainToad, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_TrainToad, LVar0, LVar1, LVar2, 5)
        EVT_LOOP(0)
            EVT_CALL(InterpNpcYaw, NPC_TrainToad, 270, 0)
            EVT_WAIT(25)
            EVT_CALL(InterpNpcYaw, NPC_TrainToad, 90, 0)
            EVT_WAIT(25)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
    EVT_WAIT(75)
    EVT_CALL(GotoMap, EVT_PTR("mac_04"), mac_04_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
