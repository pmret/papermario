#include "end_01.h"

#include "world/common/atomic/ApplyTint.inc.c"

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
    MODEL_omo12, MODEL_omo13, MODEL_omo14, 0xFFFF
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
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_MODELS, EVT_PTR(N(ShyGuyFloat_InteriorModels)), ENV_TINT_REMAP)
    EVT_CALL(N(SetModelTintParams), ENV_TINT_REMAP, 255, 255, 255, 120, 120, 80, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(N(SetModelTintParams), ENV_TINT_REMAP, 255, 255, 255, 0, 0, 0, 0, 0, 0)
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
        EVT_CALL(SetNpcAnimation, NPC_GeneralGuy, ANIM_ParadeShyGuy_GeneralStill)
        EVT_CALL(InterpNpcYaw, NPC_GeneralGuy, LVar0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_GeneralGuy, ANIM_ParadeShyGuy_GeneralPoint)
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
    EVT_SET(LVar0, NPC_BackupDancer1)
    EVT_EXEC_GET_TID(N(EVS_ShyGuy_BackupDancer), LVar8)
    EVT_SET(LVar0, NPC_BackupDancer2)
    EVT_EXEC_GET_TID(N(EVS_ShyGuy_BackupDancer), LVar9)
    EVT_SET(LVar0, NPC_GrooveGuy1)
    EVT_SET(LVar1, -1508)
    EVT_EXEC_GET_TID(N(EVS_GrooveGuy), LVarA)
    EVT_SET(LVar0, NPC_GrooveGuy2)
    EVT_SET(LVar1, -1468)
    EVT_EXEC_GET_TID(N(EVS_GrooveGuy), LVarB)
    EVT_SET(LVar0, NPC_GrooveGuy3)
    EVT_SET(LVar1, -1428)
    EVT_EXEC_GET_TID(N(EVS_GrooveGuy), LVarC)
    EVT_SET(LVar0, NPC_GrooveGuy4)
    EVT_SET(LVar1, -1388)
    EVT_EXEC_GET_TID(N(EVS_GrooveGuy), LVarD)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_SHYGUY_DANCE + 600)
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
    EVT_CALL(NpcMoveTo, NPC_ShyGuyMarshall, -1648, 0, 50)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuyMarshall, ANIM_ParadeShyGuy_MarshallStill)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuyMarshall, 90, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuyMarshall, ANIM_ParadeShyGuy_MarshallBeckon)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_SHYGUY_DANCE + 260)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_ShyGuyMarshall, ANIM_ParadeShyGuy_MarshallWalk)
        EVT_CALL(NpcMoveTo, NPC_ShyGuyMarshall, -1748, 0, 50)
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
        EVT_IF_GT(LVar0, PARADE_PHASE_SHYGUY_DANCE + 600)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShyGuy_PauseFormation) = {
    EVT_CALL(GetNpcPos, NPC_ShyGuyFormation11, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_SETF(LVar1, LVar0)
    EVT_ADDF(LVar1, 30)
    EVT_SETF(LVar2, LVar0)
    EVT_ADDF(LVar2, 60)
    EVT_SETF(LVar3, LVar0)
    EVT_ADDF(LVar3, 90)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation11, LVar0, 0, -30)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation12, LVar0, 0, 0)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation13, LVar0, 0, 30)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation21, LVar1, 0, -30)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation22, LVar1, 0, 0)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation23, LVar1, 0, 30)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation31, LVar2, 0, -30)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation32, LVar2, 0, 0)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation33, LVar2, 0, 30)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation41, LVar3, 0, -30)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation42, LVar3, 0, 0)
    EVT_CALL(SetNpcPos, NPC_ShyGuyFormation43, LVar3, 0, 30)
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation12)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation13)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation21)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation22)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation23)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation31)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation32)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation33)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation41)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation42)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation43)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(AddScrollToNpcPos), NPC_ShyGuyFormation11)
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
    EVT_SET(LVar0, NPC_ShyGuyFormation11)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_ShyGuyFormation12)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_ShyGuyFormation13)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar1, 8)
    EVT_SET(LVar0, NPC_ShyGuyFormation21)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_ShyGuyFormation22)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_ShyGuyFormation23)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar1, 10)
    EVT_SET(LVar0, NPC_ShyGuyFormation31)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_ShyGuyFormation32)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_ShyGuyFormation33)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar1, 18)
    EVT_SET(LVar0, NPC_ShyGuyFormation41)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_ShyGuyFormation42)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    EVT_SET(LVar0, NPC_ShyGuyFormation43)
    EVT_EXEC(N(EVS_ShyGuy_MarchInFormation))
    // at a certain point, cause the formation to stop moving
    EVT_WAIT(90)
    EVT_EXEC_GET_TID(N(EVS_ShyGuy_PauseFormation), LVarA)
    EVT_WAIT(48)
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(130)
    // formation resumes moving
    EVT_CALL(GetNpcPos, NPC_Pratfaller, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_Pratfaller, LVar0, LVar2, 45)
    EVT_CALL(SetNpcRotationPivot, NPC_Pratfaller, 10)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 9)
            EVT_CALL(SetNpcRotation, NPC_Pratfaller, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcRotation, NPC_Pratfaller, 0, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Pratfaller, ANIM_ShyGuy_Red_Anim10)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_Pratfaller, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_Pratfaller, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -45)
    EVT_CALL(NpcJump0, NPC_Pratfaller, LVar0, LVar1, LVar2, 10)
    EVT_SET(LVar0, NPC_Pratfaller)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarA)
    EVT_WAIT(80)
    EVT_CALL(SetNpcRotationPivot, NPC_Pratfaller, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcAnimation, NPC_Pratfaller, ANIM_ShyGuy_Red_Anim01)
    EVT_CALL(GetNpcPos, NPC_Pratfaller, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -5)
    EVT_CALL(NpcJump0, NPC_Pratfaller, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_Pratfaller, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(GetNpcPos, NPC_Pratfaller, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_Pratfaller, LVar0, LVar2, 90)
    EVT_RETURN
    EVT_END
};
