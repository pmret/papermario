#include "end_00.h"
#include "effects.h"

Vec3f N(CrystalsFlyInPath)[] = {
    { 2050.0,   100.0,    0.0 },
    { 1900.0,    80.0,    0.0 },
    { 1820.0,    70.0,    0.0 },
    { 1800.0,    60.0,    0.0 },
    { 1840.0,    50.0,    0.0 },
};

Vec3f N(CrystalsFlyOutPath)[] = {
    { 1840.0,    50.0,    0.0 },
    { 1880.0,    60.0,    0.0 },
    { 1860.0,    70.0,    0.0 },
    { 1760.0,   100.0,    0.0 },
    { 1660.0,   170.0,    0.0 },
};

EvtScript N(EVS_ParadePhase_CrystalKing) = {
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_CRYSTAL_KING + 300)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_TrueCrystalKing, ANIM_CrystalKing_Anim09)
    Set(LVar0, 77)
    ExecGetTID(N(EVS_OffsetNpcScroll), LVarA)
    Wait(10 * DT)
    Call(InterpNpcYaw, NPC_TrueCrystalKing, 90, 7)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_TrueCrystalKing, ANIM_CrystalKing_Anim10)
    Call(SetNpcAnimation, NPC_FakeCrystalKing, ANIM_CrystalKing_Anim10)
    Set(LVar0, 78)
    ExecGetTID(N(EVS_OffsetNpcScroll), LVarB)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_FakeCrystalKing, ANIM_CrystalKing_Anim1C)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_TrueCrystalKing, ANIM_CrystalKing_Anim19)
    Wait(10 * DT)
    KillThread(LVarA)
    Call(GetNpcPos, NPC_TrueCrystalKing, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
    Call(SetNpcPos, NPC_TrueCrystalKing, 1800, 0, 0)
    Call(SetNpcYaw, NPC_TrueCrystalKing, 270)
    Call(SetNpcAnimation, NPC_TrueCrystalKing, ANIM_CrystalKing_Anim0E)
    Call(SetNpcPos, NPC_Duplighost1, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_Duplighost1, Float(0.5))
    Add(LVar0, -40)
    Call(NpcJump1, NPC_Duplighost1, LVar0, LVar1, LVar2, 20 * DT)
    Call(SetNpcAnimation, NPC_Duplighost1, ANIM_Duplighost_Anim02)
    Set(LVar0, 75)
    ExecGetTID(N(EVS_OffsetNpcScroll), LVarA)
    KillThread(LVarB)
    Call(SetNpcAnimation, NPC_FakeCrystalKing, ANIM_CrystalKing_Anim0F)
    Call(GetNpcPos, NPC_FakeCrystalKing, LVar0, LVar1, LVar2)
    Add(LVar0, -80)
    Call(NpcMoveTo, NPC_FakeCrystalKing, LVar0, LVar2, 40 * DT)
    Set(LVar0, 78)
    ExecGetTID(N(EVS_OffsetNpcScroll), LVarB)
    Thread
        Call(SetNpcAnimation, NPC_FakeCrystalKing, ANIM_CrystalKing_Anim10)
        Wait(60 * DT)
        Call(SetNpcAnimation, NPC_FakeCrystalKing, ANIM_CrystalKing_Anim09)
    EndThread
    Thread
        Wait(10 * DT)
        Loop(4)
            Call(SetNpcAnimation, NPC_Duplighost1, ANIM_Duplighost_Anim00)
            Wait(10 * DT)
            Call(SetNpcAnimation, NPC_Duplighost1, ANIM_Duplighost_Anim07)
            Wait(10 * DT)
        EndLoop
        Call(SetNpcAnimation, NPC_Duplighost1, ANIM_Duplighost_Anim02)
    EndThread
    Wait(100 * DT)
    Call(InterpNpcYaw, NPC_FakeCrystalKing, 90, 7)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_FakeCrystalKing, ANIM_CrystalKing_Anim10)
    Call(SetNpcAnimation, NPC_TrueCrystalKing, ANIM_CrystalKing_Anim10)
    Set(LVar0, 77)
    ExecGetTID(N(EVS_OffsetNpcScroll), LVarC)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_TrueCrystalKing, ANIM_CrystalKing_Anim1C)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_FakeCrystalKing, ANIM_CrystalKing_Anim19)
    Wait(10 * DT)
    KillThread(LVarB)
    Call(GetNpcPos, NPC_FakeCrystalKing, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
    Call(SetNpcPos, NPC_FakeCrystalKing, 0, -500, 0)
    Call(SetNpcPos, NPC_Duplighost2, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_Duplighost2, Float(0.5))
    Add(LVar0, -40)
    Call(NpcJump1, NPC_Duplighost2, LVar0, LVar1, LVar2, 20 * DT)
    Call(SetNpcAnimation, NPC_Duplighost2, ANIM_Duplighost_Anim02)
    Set(LVar0, 76)
    ExecGetTID(N(EVS_OffsetNpcScroll), LVarB)
    KillThread(LVarC)
    Call(SetNpcAnimation, NPC_TrueCrystalKing, ANIM_CrystalKing_Anim0F)
    Call(GetNpcPos, NPC_TrueCrystalKing, LVar0, LVar1, LVar2)
    Add(LVar0, -80)
    Call(NpcMoveTo, NPC_TrueCrystalKing, LVar0, LVar2, 40 * DT)
    Set(LVar0, 77)
    ExecGetTID(N(EVS_OffsetNpcScroll), LVarC)
    Thread
        Loop(6)
            Call(SetNpcAnimation, NPC_TrueCrystalKing, ANIM_CrystalKing_Anim10)
            Wait(10 * DT)
            Call(SetNpcAnimation, NPC_TrueCrystalKing, ANIM_CrystalKing_Anim11)
            Wait(10 * DT)
        EndLoop
    EndThread
    Thread
        Wait(10 * DT)
        Loop(4)
            Call(SetNpcAnimation, NPC_Duplighost1, ANIM_Duplighost_Anim00)
            Call(SetNpcAnimation, NPC_Duplighost2, ANIM_Duplighost_Anim00)
            Wait(10 * DT)
            Call(SetNpcAnimation, NPC_Duplighost1, ANIM_Duplighost_Anim07)
            Call(SetNpcAnimation, NPC_Duplighost2, ANIM_Duplighost_Anim07)
            Wait(10 * DT)
        EndLoop
        Call(SetNpcAnimation, NPC_Duplighost1, ANIM_Duplighost_Anim02)
        Call(SetNpcAnimation, NPC_Duplighost2, ANIM_Duplighost_Anim02)
    EndThread
    Wait(60 * DT)
    Thread
        Call(LoadPath, 50 * DT, Ref(N(CrystalsFlyInPath)), ARRAY_COUNT(N(CrystalsFlyInPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Set(LVar4, LVar1)
            Add(LVar4, -30)
            Set(LVar5, LVar1)
            Add(LVar5, 30)
            Set(LVar6, LVar2)
            Add(LVar6, -25)
            Call(SetNpcPos, NPC_CrystalBit1, LVar5, LVar6, LVar3)
            Call(SetNpcPos, NPC_CrystalBit2, LVar1, LVar2, LVar3)
            Call(SetNpcPos, NPC_CrystalBit3, LVar4, LVar6, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(50 * DT)
    KillThread(LVarC)
    Thread
        Call(SetNpcAnimation, NPC_TrueCrystalKing, ANIM_CrystalKing_Anim19)
        Call(LoadPath, 50 * DT, Ref(N(CrystalsFlyOutPath)), ARRAY_COUNT(N(CrystalsFlyInPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Set(LVar4, LVar1)
            Add(LVar4, -30)
            Set(LVar5, LVar1)
            Add(LVar5, 30)
            Set(LVar6, LVar2)
            Add(LVar6, -25)
            Call(SetNpcPos, NPC_CrystalBit1, LVar5, LVar6, LVar3)
            Call(SetNpcPos, NPC_CrystalBit2, LVar1, LVar2, LVar3)
            Call(SetNpcPos, NPC_CrystalBit3, LVar4, LVar6, LVar3)
            Add(LVar2, -50)
            Call(SetNpcPos, NPC_TrueCrystalKing, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(SetNpcAnimation, NPC_Duplighost1, ANIM_Duplighost_Anim02)
    Call(SetNpcAnimation, NPC_Duplighost2, ANIM_Duplighost_Anim02)
    Loop(50 * DT)
        Call(NpcFaceNpc, NPC_Duplighost1, NPC_TrueCrystalKing, 0)
        Call(NpcFaceNpc, NPC_Duplighost2, NPC_TrueCrystalKing, 0)
        Wait(1)
    EndLoop
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Duplighost1, ANIM_Duplighost_Anim03)
    Call(SetNpcAnimation, NPC_Duplighost2, ANIM_Duplighost_Anim03)
    KillThread(LVarA)
    KillThread(LVarB)
    Return
    End
};
