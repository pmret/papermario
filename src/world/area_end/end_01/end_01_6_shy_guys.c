#include "end_01.h"

#include "world/common/atomic/UnkFunc27.inc.c"

API_CALLABLE(N(AddScrollToNpcPos));

extern EvtScript N(EVS_OffsetNpcScroll);

EvtScript N(EVS_TexPan_ShyGuyFloat_Sides) = {
    EVT_CALL(EnableTexPanning, MODEL_omo1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_omo4, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_omo6, TRUE)
    EVT_SET(LVar1, LVar0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x1000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_9, TEX_PANNER_AUX, LVar0, LVar0)
        EVT_WAIT(LVar1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_ShyGuyFloat_Top) = {
    EVT_CALL(EnableTexPanning, MODEL_omo8, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_omo13, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x4000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_8, TEX_PANNER_MAIN, LVar0, LVar0)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(ShyGuyFloat_InteriorModels)[] = {
    MODEL_omo7, MODEL_omo9, MODEL_omo10, MODEL_omo11,
    MODEL_omo12, MODEL_omo13, MODEL_omo14, 0x0000FFFF 
};

EvtScript N(EVS_ShyGuyFloat_Open) = {
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -90, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_h2, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_h3, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(N(UnkFunc27), 0, EVT_PTR(N(ShyGuyFloat_InteriorModels)), 3)
    EVT_CALL(N(UnkFunc26), 3, 255, 255, 255, 120, 120, 80, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(N(UnkFunc26), 3, 255, 255, 255, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GeneralGuy) = {
    EVT_SET(LVar0, 270)
    EVT_LOOP(0)
        EVT_IF_EQ(LVar0, 270)
            EVT_SET(LVar0, 90)
        EVT_ELSE
            EVT_SET(LVar0, 270)
        EVT_END_IF
        EVT_CALL(SetNpcAnimation, NPC_1D, ANIM_ParadeShyGuy_GeneralStill)
        EVT_CALL(InterpNpcYaw, NPC_1D, LVar0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_1D, ANIM_ParadeShyGuy_GeneralPoint)
        EVT_WAIT(20)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShyGuy_BackupDancer) = {
    EVT_SET(LVar2, LVar0)
    EVT_LOOP(0)
        EVT_LOOP(3)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_StackLand)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_StackHold)
            EVT_WAIT(10)
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_StackPointUp)
        EVT_WAIT(10)
        EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, LVar2, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GrooveGuy) = {
    EVT_WAIT(30)
    EVT_SET(LVar2, LVar0)
    EVT_SET(LVar3, LVar1)
    EVT_CALL(SetNpcJumpscale, LVar2, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, LVar2, LVar3, 10, 20, 20)
    EVT_WAIT(10)
    EVT_LOOP(0)
        EVT_LOOP(2)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GrooveLeanLeft)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GroovePivot)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GrooveLeanRight)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GroovePivot)
            EVT_WAIT(5)
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, LVar2, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShyGuyFloat_Performers) = {
    EVT_EXEC_GET_TID(N(EVS_GeneralGuy), LVar7)
    EVT_SET(LVar0, NPC_1E)
    EVT_EXEC_GET_TID(N(EVS_ShyGuy_BackupDancer), LVar8)
    EVT_SET(LVar0, NPC_1F)
    EVT_EXEC_GET_TID(N(EVS_ShyGuy_BackupDancer), LVar9)
    EVT_SET(LVar0, NPC_20)
    EVT_SET(LVar1, -1508)
    EVT_EXEC_GET_TID(N(EVS_GrooveGuy), LVarA)
    EVT_SET(LVar0, NPC_21)
    EVT_SET(LVar1, -1468)
    EVT_EXEC_GET_TID(N(EVS_GrooveGuy), LVarB)
    EVT_SET(LVar0, NPC_22)
    EVT_SET(LVar1, -1428)
    EVT_EXEC_GET_TID(N(EVS_GrooveGuy), LVarC)
    EVT_SET(LVar0, NPC_23)
    EVT_SET(LVar1, -1388)
    EVT_EXEC_GET_TID(N(EVS_GrooveGuy), LVarD)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -1178)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVar7)
    EVT_KILL_THREAD(LVar8)
    EVT_KILL_THREAD(LVar9)
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_KILL_THREAD(LVarD)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_ShyGuyDancing) = {
    EVT_SET(LVar0, 4)
    EVT_EXEC_GET_TID(N(EVS_TexPan_ShyGuyFloat_Sides), LVarA)
    EVT_EXEC_GET_TID(N(EVS_TexPan_ShyGuyFloat_Top), LVarB)
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_1C, -1648, 0, 50)
    EVT_CALL(SetNpcAnimation, NPC_1C, ANIM_ParadeShyGuy_MarshallStill)
    EVT_CALL(InterpNpcYaw, NPC_1C, 90, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_1C, ANIM_ParadeShyGuy_MarshallBeckon)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -1518)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_1C, ANIM_ParadeShyGuy_MarshallWalk)
        EVT_CALL(NpcMoveTo, NPC_1C, -1748, 0, 50)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_ShyGuyFloat_Performers))
    EVT_KILL_THREAD(LVarA)
    EVT_SET(LVar0, 2)
    EVT_EXEC_GET_TID(N(EVS_TexPan_ShyGuyFloat_Sides), LVarA)
    EVT_EXEC_WAIT(N(EVS_ShyGuyFloat_Open))
    EVT_KILL_THREAD(LVarA)
    EVT_SET(LVar0, 4)
    EVT_EXEC_GET_TID(N(EVS_TexPan_ShyGuyFloat_Sides), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -1178)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShyGuy_PauseFormation) = {
    EVT_CALL(GetNpcPos, NPC_26, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_SETF(LVar1, LVar0)
    EVT_ADDF(LVar1, 30)
    EVT_SETF(LVar2, LVar0)
    EVT_ADDF(LVar2, 60)
    EVT_SETF(LVar3, LVar0)
    EVT_ADDF(LVar3, 90)
    EVT_CALL(SetNpcPos, NPC_26, LVar0, 0, -30)
    EVT_CALL(SetNpcPos, NPC_27, LVar0, 0, 0)
    EVT_CALL(SetNpcPos, NPC_28, LVar0, 0, 30)
    EVT_CALL(SetNpcPos, NPC_29, LVar1, 0, -30)
    EVT_CALL(SetNpcPos, NPC_2A, LVar1, 0, 0)
    EVT_CALL(SetNpcPos, NPC_2B, LVar1, 0, 30)
    EVT_CALL(SetNpcPos, NPC_2C, LVar2, 0, -30)
    EVT_CALL(SetNpcPos, NPC_2D, LVar2, 0, 0)
    EVT_CALL(SetNpcPos, NPC_2E, LVar2, 0, 30)
    EVT_CALL(SetNpcPos, NPC_2F, LVar3, 0, -30)
    EVT_CALL(SetNpcPos, NPC_30, LVar3, 0, 0)
    EVT_CALL(SetNpcPos, NPC_31, LVar3, 0, 30)
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_27)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_28)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_29)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_2A)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_2B)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_2C)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_2D)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_2E)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_2F)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_30)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_31)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(AddScrollToNpcPos), NPC_26)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShyGuy_MarchInFormation) = {
    EVT_CALL(GetNpcPos, LVar0, LVar2, LVar3, LVar4)
    EVT_ADD(LVar2, -180)
    EVT_CALL(NpcMoveTo, LVar0, LVar2, LVar4, 90)
    EVT_SET(LVar2, LVar0)
    EVT_SET(LVar3, 28)
    EVT_SUB(LVar3, LVar1)
    EVT_ADD(LVar1, 10)
    EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_ShadeStill)
    EVT_WAIT(LVar1)
    EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_ShadePointUp)
    EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, LVar2, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(LVar3)
    EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_ShadeWalk)
    EVT_CALL(GetNpcPos, LVar2, LVar3, LVar4, LVar5)
    EVT_ADD(LVar3, -180)
    EVT_CALL(NpcMoveTo, LVar2, LVar3, LVar5, 90)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_ShyGuyFormation) = {
    EVT_SET(LVar1, 0)
    EVT_SET(LVar0, NPC_26)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_27)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_28)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar1, 8)
    EVT_SET(LVar0, NPC_29)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_2A)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_2B)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar1, 10)
    EVT_SET(LVar0, NPC_2C)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_2D)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_2E)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar1, 18)
    EVT_SET(LVar0, NPC_2F)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_30)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_31)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    // at a certain point, cause the formation to stop moving
    EVT_WAIT(90)
    EVT_EXEC_GET_TID(N(EVS_ShyGuy_PauseFormation), LVarA)
    EVT_WAIT(48)
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(130)
    // formation resumes moving
    EVT_CALL(GetNpcPos, NPC_32, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_32, LVar0, LVar2, 45)
    EVT_CALL(func_802CDE68, NPC_32, 10)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 9)
            EVT_CALL(SetNpcRotation, NPC_32, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcRotation, NPC_32, 0, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_32, ANIM_ShyGuy_Red_Anim10)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_32, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_32, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -45)
    EVT_CALL(NpcJump0, NPC_32, LVar0, LVar1, LVar2, 10)
    EVT_SET(LVar0, NPC_32)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarA)
    EVT_WAIT(80)
    EVT_CALL(func_802CDE68, NPC_32, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcAnimation, NPC_32, ANIM_ShyGuy_Red_Anim01)
    EVT_CALL(GetNpcPos, NPC_32, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -5)
    EVT_CALL(NpcJump0, NPC_32, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_32, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(GetNpcPos, NPC_32, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_32, LVar0, LVar2, 90)
    EVT_RETURN
    EVT_END
};
