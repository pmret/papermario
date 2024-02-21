#include "end_00.h"
#include "effects.h"

extern EvtScript N(EVS_SetNpcShadowScale);

EvtScript N(EVS_HoldPosition_Yoshis) = {
    Call(GetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
    SetF(LVar0, LVar0)
    SetF(LVar3, LVar0)
    SubF(LVar3, 40)
    SetF(LVar4, LVar0)
    SubF(LVar4, 80)
    SetF(LVar5, LVar0)
    SubF(LVar5, 120)
    SetF(LVar6, LVar0)
    SubF(LVar6, 160)
    Call(SetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_YoshiKidBlue, LVar3, LVar1, LVar2)
    Call(SetNpcPos, NPC_YoshiKidPurple, LVar4, LVar1, LVar2)
    Call(SetNpcPos, NPC_YoshiKidYellow, LVar5, LVar1, LVar2)
    Call(SetNpcPos, NPC_YoshiKidRed, LVar6, LVar1, LVar2)
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_YoshiKidBlue)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_YoshiKidPurple)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_YoshiKidYellow)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_YoshiKidRed)
    EndChildThread
    Call(N(AddScrollToNpcPos), NPC_YoshiKidGreen)
    Return
    End
};

EvtScript N(EVS_HoldPosition_Puffs) = {
    Call(GetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
    SetF(LVar0, LVar0)
    SetF(LVar3, LVar0)
    AddF(LVar3, 80)
    SetF(LVar4, LVar0)
    SubF(LVar4, 80)
    Call(SetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_HuffNPuffFace, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_HuffNPuffArms, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_RuffPuff1, LVar3, 60, 0)
    Call(SetNpcPos, NPC_RuffPuff2, LVar4, 60, 0)
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_HuffNPuffFace)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_HuffNPuffArms)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_RuffPuff1)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_RuffPuff2)
    EndChildThread
    Call(N(AddScrollToNpcPos), NPC_HuffNPuffBody)
    Return
    End
};

EvtScript N(EVS_Puffs_Surprise) = {
    Call(SetNpcAnimation, NPC_HuffNPuffBody, ANIM_HuffNPuff_Anim26)
    Call(SetNpcAnimation, NPC_HuffNPuffFace, ANIM_HuffNPuff_Anim27)
    Call(SetNpcAnimation, NPC_HuffNPuffArms, ANIM_HuffNPuff_Anim28)
    Call(SetNpcAnimation, NPC_RuffPuff1, ANIM_RuffPuff_Blush)
    Call(SetNpcAnimation, NPC_RuffPuff2, ANIM_RuffPuff_Blush)
    Return
    End
};

EvtScript N(EVS_Puffs_Hurt) = {
    Call(SetNpcAnimation, NPC_HuffNPuffBody, ANIM_HuffNPuff_Anim07)
    Call(SetNpcAnimation, NPC_HuffNPuffFace, ANIM_HuffNPuff_Anim08)
    Call(SetNpcAnimation, NPC_HuffNPuffArms, ANIM_HuffNPuff_Anim09)
    Call(SetNpcAnimation, NPC_RuffPuff1, ANIM_RuffPuff_Hurt)
    Call(SetNpcAnimation, NPC_RuffPuff2, ANIM_RuffPuff_Hurt)
    Return
    End
};

EvtScript N(EVS_Puffs_Retreat) = {
    Call(GetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
    Set(LVar3, LVar0)
    Add(LVar3, 80)
    Set(LVar4, LVar0)
    Add(LVar4, -80)
    Loop(10)
        Add(LVar0, -2)
        Call(SetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_HuffNPuffFace, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_HuffNPuffArms, LVar0, LVar1, LVar2)
        Add(LVar3, -2)
        Call(SetNpcPos, NPC_RuffPuff1, LVar3, 60, 0)
        Add(LVar4, -2)
        Call(SetNpcPos, NPC_RuffPuff2, LVar4, 60, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_GourmetGuy_Enter) = {
    Loop(0)
        Wait(1)
        Call(GetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
        IfGt(LVar0, 1060)
            BreakLoop
        EndIf
    EndLoop
    Call(GetNpcPos, NPC_RuffPuff2, LVar0, LVar1, LVar2)
    Call(SetNpcSpeed, NPC_GourmetGuy, Float(1.0))
    Call(NpcMoveTo, NPC_GourmetGuy, LVar0, -20, 0)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    Call(N(AddScrollToNpcPos), NPC_GourmetGuy)
    Return
    End
};

EvtScript N(EVS_HoldPosition_GourmetGuy) = {
    Call(N(AddScrollToNpcPos), NPC_GourmetGuy)
    Return
    End
};

EvtScript N(EVS_YoshiKids) = {
    Wait(20 * DT)
    Call(SetNpcJumpscale, NPC_YoshiKidGreen, Float(1.0))
    Call(NpcJump0, NPC_YoshiKidGreen, 680, 0, 0, 20 * DT)
    Call(NpcJump0, NPC_YoshiKidGreen, 740, 0, 0, 10 * DT)
    Call(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_Idle)
    Loop(2)
        Call(InterpNpcYaw, NPC_YoshiKidGreen, 270, 7 * DT)
        Wait(10 * DT)
        Call(InterpNpcYaw, NPC_YoshiKidGreen, 90, 7 * DT)
        Wait(10 * DT)
    EndLoop
    Call(InterpNpcYaw, NPC_YoshiKidGreen, 270, 7 * DT)
    Wait(10 * DT)
    Thread
        Call(GetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_YoshiKidGreen, LVar0, LVar1, LVar2, 7)
        Call(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_Run)
        Call(NpcMoveTo, NPC_YoshiKidGreen, 980, 0, 60 * DT)
        Call(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_LookUp)
    EndThread
    Thread
        Call(SetNpcPos, NPC_YoshiKidBlue, 660, 0, 0)
        Call(NpcMoveTo, NPC_YoshiKidBlue, 940, 0, 70 * DT)
        Call(SetNpcAnimation, NPC_YoshiKidBlue, ANIM_YoshiKid_Blue_LookUp)
    EndThread
    Thread
        Wait(10 * DT)
        Call(SetNpcPos, NPC_YoshiKidPurple, 660, 0, 0)
        Call(NpcMoveTo, NPC_YoshiKidPurple, 900, 0, 60 * DT)
        Call(SetNpcAnimation, NPC_YoshiKidPurple, ANIM_YoshiKid_Purple_LookUp)
    EndThread
    Thread
        Wait(20 * DT)
        Call(SetNpcPos, NPC_YoshiKidYellow, 660, 0, 0)
        Call(NpcMoveTo, NPC_YoshiKidYellow, 860, 0, 50 * DT)
        Call(SetNpcAnimation, NPC_YoshiKidYellow, ANIM_YoshiKid_Yellow_LookUp)
    EndThread
    Thread
        Wait(30 * DT)
        Call(SetNpcPos, NPC_YoshiKidRed, 660, 0, 0)
        Call(NpcMoveTo, NPC_YoshiKidRed, 820, 0, 40 * DT)
        Call(SetNpcAnimation, NPC_YoshiKidRed, ANIM_YoshiKid_Red_LookUp)
    EndThread
    Wait(70 * DT)
    ExecGetTID(N(EVS_HoldPosition_Yoshis), LVarA)
    Loop(0)
        Wait(1)
        Call(GetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
        IfGt(LVar0, 0x00000424)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_Idle)
    Call(SetNpcAnimation, NPC_YoshiKidBlue, ANIM_YoshiKid_Blue_Idle)
    Call(SetNpcAnimation, NPC_YoshiKidPurple, ANIM_YoshiKid_Purple_Idle)
    Call(SetNpcAnimation, NPC_YoshiKidYellow, ANIM_YoshiKid_Yellow_Idle)
    Call(SetNpcAnimation, NPC_YoshiKidRed, ANIM_YoshiKid_Red_Idle)
    Call(InterpNpcYaw, NPC_YoshiKidGreen, 270, 0)
    Wait(5 * DT)
    Loop(3)
        Call(InterpNpcYaw, NPC_YoshiKidPurple, 270, 0)
        Wait(5 * DT)
        Call(InterpNpcYaw, NPC_YoshiKidBlue, 270, 0)
        Wait(5 * DT)
        Call(InterpNpcYaw, NPC_YoshiKidYellow, 270, 0)
        Wait(5 * DT)
        Call(InterpNpcYaw, NPC_YoshiKidPurple, 90, 0)
        Wait(5 * DT)
        Call(InterpNpcYaw, NPC_YoshiKidBlue, 90, 0)
        Wait(5 * DT)
        Call(InterpNpcYaw, NPC_YoshiKidYellow, 90, 0)
        Wait(5 * DT)
    EndLoop
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_HUFF_PUFF + 310)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcYaw, NPC_YoshiKidGreen, 270)
    Call(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_EatMiss)
    Call(SetNpcYaw, NPC_YoshiKidBlue, 270)
    Call(SetNpcAnimation, NPC_YoshiKidBlue, ANIM_YoshiKid_Blue_EatMiss)
    Call(SetNpcYaw, NPC_YoshiKidPurple, 90)
    Call(SetNpcAnimation, NPC_YoshiKidPurple, ANIM_YoshiKid_Purple_EatMiss)
    Call(SetNpcYaw, NPC_YoshiKidYellow, 90)
    Call(SetNpcAnimation, NPC_YoshiKidYellow, ANIM_YoshiKid_Yellow_EatMiss)
    Call(SetNpcYaw, NPC_YoshiKidRed, 90)
    Call(SetNpcAnimation, NPC_YoshiKidRed, ANIM_YoshiKid_Red_EatMiss)
    Wait(10 * DT)
    Exec(N(EVS_Puffs_Hurt))
    Thread
        Call(GetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2)
        Call(GetNpcPos, NPC_RuffPuff1, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2)
        Call(GetNpcPos, NPC_RuffPuff2, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2)
        Call(MakeLerp, 750, 375, 5, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            DivF(LVar2, 1000)
            Call(SetNpcScale, NPC_HuffNPuffBody, LVar2, LVar2, 1)
            Call(SetNpcScale, NPC_HuffNPuffFace, LVar2, LVar2, 1)
            Call(SetNpcScale, NPC_HuffNPuffArms, LVar2, LVar2, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 100, 50, 5, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            DivF(LVar2, 100)
            Call(SetNpcScale, NPC_RuffPuff1, LVar2, LVar2, 1)
            Call(SetNpcScale, NPC_RuffPuff2, LVar2, LVar2, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 600, 300, 5, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            DivF(LVar2, 100)
            Set(LVar0, 69)
            Exec(N(EVS_SetNpcShadowScale))
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(40 * DT)
    Call(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_Exhale)
    Call(SetNpcAnimation, NPC_YoshiKidBlue, ANIM_YoshiKid_Blue_Exhale)
    Call(SetNpcAnimation, NPC_YoshiKidPurple, ANIM_YoshiKid_Purple_Exhale)
    Call(SetNpcAnimation, NPC_YoshiKidYellow, ANIM_YoshiKid_Yellow_Exhale)
    Call(SetNpcAnimation, NPC_YoshiKidRed, ANIM_YoshiKid_Red_Exhale)
    Wait(50 * DT)
    KillThread(LVarA)
    Thread
        Call(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_Run)
        Call(GetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
        Add(LVar0, 300)
        Call(NpcMoveTo, NPC_YoshiKidGreen, LVar0, LVar2, 75 * DT)
        Call(SetNpcPos, NPC_YoshiKidGreen, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_YoshiKidBlue, ANIM_YoshiKid_Blue_Run)
        Call(GetNpcPos, NPC_YoshiKidBlue, LVar0, LVar1, LVar2)
        Add(LVar0, 300)
        Call(NpcMoveTo, NPC_YoshiKidBlue, LVar0, LVar2, 75 * DT)
        Call(SetNpcPos, NPC_YoshiKidBlue, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_YoshiKidPurple, ANIM_YoshiKid_Purple_Run)
        Call(GetNpcPos, NPC_YoshiKidPurple, LVar0, LVar1, LVar2)
        Add(LVar0, 300)
        Call(NpcMoveTo, NPC_YoshiKidPurple, LVar0, LVar2, 75 * DT)
        Call(SetNpcPos, NPC_YoshiKidPurple, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_YoshiKidYellow, ANIM_YoshiKid_Yellow_Run)
        Call(GetNpcPos, NPC_YoshiKidYellow, LVar0, LVar1, LVar2)
        Add(LVar0, 300)
        Call(NpcMoveTo, NPC_YoshiKidYellow, LVar0, LVar2, 75 * DT)
        Call(SetNpcPos, NPC_YoshiKidYellow, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_YoshiKidRed, ANIM_YoshiKid_Red_Run)
        Call(GetNpcPos, NPC_YoshiKidRed, LVar0, LVar1, LVar2)
        Add(LVar0, 300)
        Call(NpcMoveTo, NPC_YoshiKidRed, LVar0, LVar2, 75 * DT)
        Call(SetNpcPos, NPC_YoshiKidRed, 0, -500, 0)
    EndThread
    Return
    End
};

EvtScript N(EVS_ParadePhase_HuffNPuff) = {
    Thread
        Loop(0)
            Wait(1)
            Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
            IfGt(LVar0, PARADE_PHASE_HUFF_PUFF + 50)
                BreakLoop
            EndIf
        EndLoop
        Wait(10 * DT)
        Call(SetNpcFlagBits, NPC_HuffNPuffBody, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcFlagBits, NPC_HuffNPuffFace, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcFlagBits, NPC_HuffNPuffArms, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcFlagBits, NPC_RuffPuff1, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcFlagBits, NPC_RuffPuff2, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcScale, NPC_HuffNPuffBody, Float(0.75), Float(0.75), 1)
        Call(SetNpcScale, NPC_HuffNPuffFace, Float(0.75), Float(0.75), 1)
        Call(SetNpcScale, NPC_HuffNPuffArms, Float(0.75), Float(0.75), 1)
        Call(EnableNpcShadow, NPC_HuffNPuffFace, FALSE)
        Call(EnableNpcShadow, NPC_HuffNPuffArms, FALSE)
    EndThread
    Exec(N(EVS_YoshiKids))
    ExecGetTID(N(EVS_GourmetGuy_Enter), LVarB)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_HUFF_PUFF + 310)
            BreakLoop
        EndIf
    EndLoop
    ExecGetTID(N(EVS_HoldPosition_Puffs), LVarA)
    Wait(10 * DT)
    KillThread(LVarB)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Leap)
    Call(GetNpcPos, NPC_GourmetGuy, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_GourmetGuy, LVar0, LVar1, LVar2, 10)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_TalkSurprise)
    ExecGetTID(N(EVS_HoldPosition_GourmetGuy), LVarB)
    Wait(130 * DT)
    Exec(N(EVS_Puffs_Surprise))
    Wait(30 * DT)
    Call(InterpNpcYaw, NPC_HuffNPuffBody, 90, 0)
    Call(InterpNpcYaw, NPC_HuffNPuffFace, 90, 0)
    Call(InterpNpcYaw, NPC_HuffNPuffArms, 90, 0)
    Call(InterpNpcYaw, NPC_RuffPuff1, 90, 0)
    Call(InterpNpcYaw, NPC_RuffPuff2, 90, 0)
    Wait(30 * DT)
    Thread
        Call(MakeLerp, 0, 90, 3, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_GourmetGuy, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Still)
        Call(MakeLerp, 270, 360, 3, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_GourmetGuy, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    EndThread
    Wait(6)
    Loop(2)
        Exec(N(EVS_Puffs_Hurt))
        KillThread(LVarA)
        ExecWait(N(EVS_Puffs_Retreat))
        Exec(N(EVS_Puffs_Surprise))
        ExecGetTID(N(EVS_HoldPosition_Puffs), LVarA)
        Wait(10 * DT)
        KillThread(LVarB)
        Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
        Call(GetNpcPos, NPC_GourmetGuy, LVar0, LVar1, LVar2)
        Add(LVar0, -20)
        Call(NpcMoveTo, NPC_GourmetGuy, LVar0, LVar2, 10)
        Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
        ExecGetTID(N(EVS_HoldPosition_GourmetGuy), LVarB)
        Wait(10 * DT)
    EndLoop
    KillThread(LVarA)
    Thread
        Call(GetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_HuffNPuffBody, LVar0, LVar1, LVar2, 10 * DT)
        Add(LVar0, -200)
        Call(NpcMoveTo, NPC_HuffNPuffBody, LVar0, LVar2, 50 * DT)
    EndThread
    Thread
        Call(GetNpcPos, NPC_HuffNPuffFace, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_HuffNPuffFace, LVar0, LVar1, LVar2, 10 * DT)
        Add(LVar0, -200)
        Call(NpcMoveTo, NPC_HuffNPuffFace, LVar0, LVar2, 50 * DT)
    EndThread
    Thread
        Call(GetNpcPos, NPC_HuffNPuffArms, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_HuffNPuffArms, LVar0, LVar1, LVar2, 10 * DT)
        Add(LVar0, -200)
        Call(NpcMoveTo, NPC_HuffNPuffArms, LVar0, LVar2, 50 * DT)
    EndThread
    Thread
        Call(GetNpcPos, NPC_RuffPuff1, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_RuffPuff1, LVar0, LVar1, LVar2, 10 * DT)
        Add(LVar0, -200)
        Call(NpcMoveTo, NPC_RuffPuff1, LVar0, LVar2, 50 * DT)
    EndThread
    Thread
        Call(GetNpcPos, NPC_RuffPuff2, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_RuffPuff2, LVar0, LVar1, LVar2, 10 * DT)
        Add(LVar0, -200)
        Call(NpcMoveTo, NPC_RuffPuff2, LVar0, LVar2, 50 * DT)
    EndThread
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Inspect)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    KillThread(LVarB)
    Call(GetNpcPos, NPC_GourmetGuy, LVar0, LVar1, LVar2)
    Add(LVar0, -300)
    Call(NpcMoveTo, NPC_GourmetGuy, LVar0, LVar2, 50 * DT)
    Return
    End
};
