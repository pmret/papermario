#include "end_01.h"

#include "world/common/atomic/ApplyTint.inc.c"

EvtScript N(EVS_TexPan_ShyGuyFloat_Sides) = {
    Call(EnableTexPanning, MODEL_omo1, TRUE)
    Call(EnableTexPanning, MODEL_omo4, TRUE)
    Call(EnableTexPanning, MODEL_omo6, TRUE)
    Set(LVar1, LVar0)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x1000)
        Call(SetTexPanOffset, TEX_PANNER_9, TEX_PANNER_AUX, LVar0, LVar0)
        Wait(LVar1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_ShyGuyFloat_Top) = {
    Call(EnableTexPanning, MODEL_omo8, TRUE)
    Call(EnableTexPanning, MODEL_omo13, TRUE)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x4000)
        Call(SetTexPanOffset, TEX_PANNER_8, TEX_PANNER_MAIN, LVar0, LVar0)
        Wait(6)
    EndLoop
    Return
    End
};

s32 N(ShyGuyFloat_InteriorModels)[] = {
    MODEL_omo7, MODEL_omo9, MODEL_omo10, MODEL_omo11,
    MODEL_omo12, MODEL_omo13, MODEL_omo14, 0xFFFF
};

EvtScript N(EVS_ShyGuyFloat_Open) = {
    Thread
        Call(MakeLerp, 0, -90, 30, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_h2, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 0, 90, 30, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_h3, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(N(SetModelTintMode), APPLY_TINT_MODELS, Ref(N(ShyGuyFloat_InteriorModels)), ENV_TINT_REMAP)
    Call(N(SetModelTintParams), ENV_TINT_REMAP, 255, 255, 255, 120, 120, 80, 0, 0, 0)
    Wait(30)
    Call(N(SetModelTintParams), ENV_TINT_REMAP, 255, 255, 255, 0, 0, 0, 0, 0, 0)
    Return
    End
};

EvtScript N(EVS_GeneralGuy) = {
    Set(LVar0, 270)
    Loop(0)
        IfEq(LVar0, 270)
            Set(LVar0, 90)
        Else
            Set(LVar0, 270)
        EndIf
        Call(SetNpcAnimation, NPC_GeneralGuy, ANIM_ParadeShyGuy_GeneralStill)
        Call(InterpNpcYaw, NPC_GeneralGuy, LVar0, 0)
        Wait(10)
        Call(SetNpcAnimation, NPC_GeneralGuy, ANIM_ParadeShyGuy_GeneralPoint)
        Wait(20)
    EndLoop
    Return
    End
};

EvtScript N(EVS_ShyGuy_BackupDancer) = {
    Set(LVar2, LVar0)
    Loop(0)
        Loop(3)
            Call(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_StackLand)
            Wait(10)
            Call(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_StackHold)
            Wait(10)
        EndLoop
        Call(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_StackPointUp)
        Wait(10)
        Call(MakeLerp, 0, 360, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, LVar2, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(10)
    EndLoop
    Return
    End
};

EvtScript N(EVS_GrooveGuy) = {
    Wait(30)
    Set(LVar2, LVar0)
    Set(LVar3, LVar1)
    Call(SetNpcJumpscale, LVar2, Float(0.5))
    Call(NpcJump0, LVar2, LVar3, 10, 20, 20)
    Wait(10)
    Loop(0)
        Loop(2)
            Call(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GrooveLeanLeft)
            Wait(5)
            Call(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GroovePivot)
            Wait(5)
            Call(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GrooveLeanRight)
            Wait(5)
            Call(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GroovePivot)
            Wait(5)
        EndLoop
        Call(MakeLerp, 0, 360, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, LVar2, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(10)
    EndLoop
    Return
    End
};

EvtScript N(EVS_ShyGuyFloat_Performers) = {
    ExecGetTID(N(EVS_GeneralGuy), LVar7)
    Set(LVar0, NPC_BackupDancer1)
    ExecGetTID(N(EVS_ShyGuy_BackupDancer), LVar8)
    Set(LVar0, NPC_BackupDancer2)
    ExecGetTID(N(EVS_ShyGuy_BackupDancer), LVar9)
    Set(LVar0, NPC_GrooveGuy1)
    Set(LVar1, -1508)
    ExecGetTID(N(EVS_GrooveGuy), LVarA)
    Set(LVar0, NPC_GrooveGuy2)
    Set(LVar1, -1468)
    ExecGetTID(N(EVS_GrooveGuy), LVarB)
    Set(LVar0, NPC_GrooveGuy3)
    Set(LVar1, -1428)
    ExecGetTID(N(EVS_GrooveGuy), LVarC)
    Set(LVar0, NPC_GrooveGuy4)
    Set(LVar1, -1388)
    ExecGetTID(N(EVS_GrooveGuy), LVarD)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_SHYGUY_DANCE + 600)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVar7)
    KillThread(LVar8)
    KillThread(LVar9)
    KillThread(LVarA)
    KillThread(LVarB)
    KillThread(LVarC)
    KillThread(LVarD)
    Return
    End
};

EvtScript N(EVS_ParadePhase_ShyGuyDancing) = {
    Set(LVar0, 4)
    ExecGetTID(N(EVS_TexPan_ShyGuyFloat_Sides), LVarA)
    ExecGetTID(N(EVS_TexPan_ShyGuyFloat_Top), LVarB)
    Wait(10)
    Call(NpcMoveTo, NPC_ShyGuyMarshall, -1648, 0, 50)
    Call(SetNpcAnimation, NPC_ShyGuyMarshall, ANIM_ParadeShyGuy_MarshallStill)
    Call(InterpNpcYaw, NPC_ShyGuyMarshall, 90, 0)
    Wait(10)
    Call(SetNpcAnimation, NPC_ShyGuyMarshall, ANIM_ParadeShyGuy_MarshallBeckon)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_SHYGUY_DANCE + 260)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Call(SetNpcAnimation, NPC_ShyGuyMarshall, ANIM_ParadeShyGuy_MarshallWalk)
        Call(NpcMoveTo, NPC_ShyGuyMarshall, -1748, 0, 50)
    EndThread
    Exec(N(EVS_ShyGuyFloat_Performers))
    KillThread(LVarA)
    Set(LVar0, 2)
    ExecGetTID(N(EVS_TexPan_ShyGuyFloat_Sides), LVarA)
    ExecWait(N(EVS_ShyGuyFloat_Open))
    KillThread(LVarA)
    Set(LVar0, 4)
    ExecGetTID(N(EVS_TexPan_ShyGuyFloat_Sides), LVarA)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_SHYGUY_DANCE + 600)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarA)
    KillThread(LVarB)
    Return
    End
};

EvtScript N(EVS_ShyGuy_PauseFormation) = {
    Call(GetNpcPos, NPC_ShyGuyFormation11, LVar0, LVar1, LVar2)
    SetF(LVar0, LVar0)
    SetF(LVar1, LVar0)
    AddF(LVar1, 30)
    SetF(LVar2, LVar0)
    AddF(LVar2, 60)
    SetF(LVar3, LVar0)
    AddF(LVar3, 90)
    Call(SetNpcPos, NPC_ShyGuyFormation11, LVar0, 0, -30)
    Call(SetNpcPos, NPC_ShyGuyFormation12, LVar0, 0, 0)
    Call(SetNpcPos, NPC_ShyGuyFormation13, LVar0, 0, 30)
    Call(SetNpcPos, NPC_ShyGuyFormation21, LVar1, 0, -30)
    Call(SetNpcPos, NPC_ShyGuyFormation22, LVar1, 0, 0)
    Call(SetNpcPos, NPC_ShyGuyFormation23, LVar1, 0, 30)
    Call(SetNpcPos, NPC_ShyGuyFormation31, LVar2, 0, -30)
    Call(SetNpcPos, NPC_ShyGuyFormation32, LVar2, 0, 0)
    Call(SetNpcPos, NPC_ShyGuyFormation33, LVar2, 0, 30)
    Call(SetNpcPos, NPC_ShyGuyFormation41, LVar3, 0, -30)
    Call(SetNpcPos, NPC_ShyGuyFormation42, LVar3, 0, 0)
    Call(SetNpcPos, NPC_ShyGuyFormation43, LVar3, 0, 30)
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation12)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation13)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation21)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation22)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation23)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation31)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation32)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation33)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation41)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation42)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation43)
    EndChildThread
    Call(N(AddScrollToNpcPos), NPC_ShyGuyFormation11)
    Return
    End
};

EvtScript N(EVS_ShyGuy_MarchInFormation) = {
    Call(GetNpcPos, LVar0, LVar2, LVar3, LVar4)
    Add(LVar2, -180)
    Call(NpcMoveTo, LVar0, LVar2, LVar4, 90)
    Set(LVar2, LVar0)
    Set(LVar3, 28)
    Sub(LVar3, LVar1)
    Add(LVar1, 10)
    Call(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_ShadeStill)
    Wait(LVar1)
    Call(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_ShadePointUp)
    Call(MakeLerp, 0, 360, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, LVar2, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(LVar3)
    Call(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_ShadeWalk)
    Call(GetNpcPos, LVar2, LVar3, LVar4, LVar5)
    Add(LVar3, -180)
    Call(NpcMoveTo, LVar2, LVar3, LVar5, 90)
    Return
    End
};

EvtScript N(EVS_ParadePhase_ShyGuyFormation) = {
    Set(LVar1, 0)
    Set(LVar0, NPC_ShyGuyFormation11)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar0, NPC_ShyGuyFormation12)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar0, NPC_ShyGuyFormation13)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar1, 8)
    Set(LVar0, NPC_ShyGuyFormation21)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar0, NPC_ShyGuyFormation22)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar0, NPC_ShyGuyFormation23)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar1, 10)
    Set(LVar0, NPC_ShyGuyFormation31)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar0, NPC_ShyGuyFormation32)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar0, NPC_ShyGuyFormation33)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar1, 18)
    Set(LVar0, NPC_ShyGuyFormation41)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar0, NPC_ShyGuyFormation42)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    Set(LVar0, NPC_ShyGuyFormation43)
    Exec(N(EVS_ShyGuy_MarchInFormation))
    // at a certain point, cause the formation to stop moving
    Wait(90)
    ExecGetTID(N(EVS_ShyGuy_PauseFormation), LVarA)
    Wait(48)
    KillThread(LVarA)
    Wait(130)
    // formation resumes moving
    Call(GetNpcPos, NPC_Pratfaller, LVar0, LVar1, LVar2)
    Add(LVar0, -180)
    Call(NpcMoveTo, NPC_Pratfaller, LVar0, LVar2, 45)
    Call(SetNpcRotationPivot, NPC_Pratfaller, 10)
    Thread
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 9)
            Call(SetNpcRotation, NPC_Pratfaller, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetNpcRotation, NPC_Pratfaller, 0, 0, 0)
        Call(SetNpcAnimation, NPC_Pratfaller, ANIM_ShyGuy_Red_Anim10)
    EndThread
    Call(SetNpcJumpscale, NPC_Pratfaller, Float(1.0))
    Call(GetNpcPos, NPC_Pratfaller, LVar0, LVar1, LVar2)
    Add(LVar0, -45)
    Call(NpcJump0, NPC_Pratfaller, LVar0, LVar1, LVar2, 10)
    Set(LVar0, NPC_Pratfaller)
    ExecGetTID(N(EVS_OffsetNpcScroll), LVarA)
    Wait(80)
    Call(SetNpcRotationPivot, NPC_Pratfaller, 0)
    KillThread(LVarA)
    Call(SetNpcAnimation, NPC_Pratfaller, ANIM_ShyGuy_Red_Anim01)
    Call(GetNpcPos, NPC_Pratfaller, LVar0, LVar1, LVar2)
    Add(LVar0, -5)
    Call(NpcJump0, NPC_Pratfaller, LVar0, LVar1, LVar2, 10)
    Call(SetNpcAnimation, NPC_Pratfaller, ANIM_ShyGuy_Red_Anim04)
    Call(GetNpcPos, NPC_Pratfaller, LVar0, LVar1, LVar2)
    Add(LVar0, -180)
    Call(NpcMoveTo, NPC_Pratfaller, LVar0, LVar2, 90)
    Return
    End
};
