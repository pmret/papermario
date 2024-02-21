#include "end_00.h"

EvtScript N(EVS_CaravanStopMarching) = {
    Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
    SetF(LVar1, LVar1)
    Loop(0)
        AddF(LVar1, Float(0.8702 / DT))
        Call(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        Wait(1)
    EndLoop
    Return
    End
};

// unused
EvtScript N(EVS_MoustafaStopMarching) = {
    Call(GetNpcPos, NPC_Moustafa, LVar0, LVar1, LVar2)
    SetF(LVar0, LVar0)
    Loop(0)
        AddF(LVar0, Float(0.8702 / DT))
        Call(SetNpcPos, NPC_Moustafa, LVar0, 0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_ParadePhase_Caravan) = {
    Call(SetNpcScale, NPC_Rhuff, Float(0.75), Float(0.75), Float(0.75))
    Thread
        Call(NpcMoveTo, NPC_Rowf, -1447, -2, 200 * DT)
        Set(LVar0, NPC_Rowf)
        ExecGetTID(N(EVS_CaravanStopMarching), LVarA)
        Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedIdle)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedTalk)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedCheer)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedIdle)
        Wait(60 * DT)
        Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedTalk)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedCheer)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedIdle)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_PackedWalk)
        KillThread(LVarA)
        Call(NpcMoveTo, NPC_Rowf, -785, -2, 300 * DT)
        Call(SetNpcPos, NPC_Rowf, 0, -500, 0)
    EndThread
    Thread
        Call(NpcMoveTo, NPC_Rhuff, -1412, -2, 200 * DT)
        Set(LVar0, NPC_Rhuff)
        ExecGetTID(N(EVS_CaravanStopMarching), LVarA)
        Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_PackedIdle)
        Wait(220 * DT)
        Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_PackedWalk)
        KillThread(LVarA)
        Call(NpcMoveTo, NPC_Rhuff, -750, -2, 300 * DT)
        Call(SetNpcPos, NPC_Rhuff, 0, -500, 0)
    EndThread
    Thread
        Call(NpcMoveTo, NPC_Moustafa, -1380, 2, 180 * DT)
        Set(LVar0, NPC_Moustafa)
        ExecGetTID(N(EVS_CaravanStopMarching), LVarA)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Idle)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Toss)
        Wait(20 * DT)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Shout)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Talk)
        Wait(30 * DT)
        Call(InterpNpcYaw, NPC_Moustafa, 90, 0)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Shout)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Talk)
        Wait(30 * DT)
        Call(InterpNpcYaw, NPC_Moustafa, 270, 0)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Shout)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Talk)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Toss)
        Wait(20 * DT)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Idle)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Run)
        KillThread(LVarA)
        Call(NpcMoveTo, NPC_Moustafa, -1360, 2, 180 * DT)
    EndThread
    Thread
        Wait(10 * DT)
        Call(NpcMoveTo, NPC_Mouser1, -1342, 2, 180 * DT)
        Set(LVar0, NPC_Mouser1)
        ExecGetTID(N(EVS_CaravanStopMarching), LVarA)
        Call(SetNpcAnimation, NPC_Mouser1, ANIM_Mouser_Blue_IdleOnlyBlink)
        Wait(110 * DT)
        Call(SetNpcAnimation, NPC_Mouser1, ANIM_Mouser_Blue_Whisper)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Mouser1, ANIM_Mouser_Blue_IdleOnlyBlink)
        Wait(90 * DT)
        Call(SetNpcAnimation, NPC_Mouser1, ANIM_Mouser_Blue_Run)
        KillThread(LVarA)
        Call(NpcMoveTo, NPC_Mouser1, -1330, 2, 180 * DT)
    EndThread
    Thread
        Wait(10)
        Call(NpcMoveTo, NPC_Mouser2, -1312, 2, 180 * DT)
        Set(LVar0, NPC_Mouser2)
        ExecGetTID(N(EVS_CaravanStopMarching), LVarA)
        Call(SetNpcAnimation, NPC_Mouser2, ANIM_Mouser_Blue_IdleOnlyBlink)
        Wait(230 * DT)
        Call(SetNpcAnimation, NPC_Mouser2, ANIM_Mouser_Blue_Run)
        KillThread(LVarA)
        Call(NpcMoveTo, NPC_Mouser2, -1300, 2, 180 * DT)
    EndThread
    // tutankoopa is chased around by chomp
    Thread
        Wait(240 * DT)
        Call(NpcMoveTo, NPC_Tutankoopa1, -1540, 30, 60 * DT)
        Wait(210 * DT)
        Call(SetNpcPos, NPC_Tutankoopa1, -1350, 0, 30 * DT)
        Call(SetNpcYaw, NPC_Tutankoopa1, 90)
        Call(NpcMoveTo, NPC_Tutankoopa1, -1110, 30, 30 * DT)
        Call(SetNpcAnimation, NPC_Tutankoopa1, ANIM_Tutankoopa_LevitateStill)
        Call(MakeLerp, 0, 90, 5, EASING_LINEAR)
        Loop(5)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Tutankoopa1, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(20 * DT)
        Call(ShowEmote, NPC_Tutankoopa1, EMOTE_ELLIPSIS, 0, 60 * DT, EMOTER_NPC, 0, 0, 0, 0)
        Wait(60 * DT)
        Call(MakeLerp, 90, 0, 5, EASING_LINEAR)
        Loop(5)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Tutankoopa1, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcAnimation, NPC_Tutankoopa1, ANIM_Tutankoopa_Idle)
        Call(InterpNpcYaw, NPC_Tutankoopa1, 270, 7)
        Wait(15 * DT)
        Call(InterpNpcYaw, NPC_Tutankoopa1, 90, 7)
        Wait(15 * DT)
        Call(InterpNpcYaw, NPC_Tutankoopa1, 270, 7)
        Wait(15 * DT)
        Call(SetNpcAnimation, NPC_Tutankoopa1, ANIM_Tutankoopa_Lift)
        Call(SetNpcJumpscale, NPC_Tutankoopa1, Float(1.0))
        Call(NpcJump0, NPC_Tutankoopa1, -1140, 0, 30, 15 * DT)
        Call(NpcJump0, NPC_Tutankoopa1, -1170, 0, 30, 15 * DT)
        Call(NpcJump0, NPC_Tutankoopa1, -1200, 0, 30, 15 * DT)
    EndThread
    Thread
        Wait(240 * DT)
        Call(NpcMoveTo, NPC_ChainChomp1, -1480, 30, 60 * DT)
        Wait(210 * DT)
        Call(SetNpcPos, NPC_ChainChomp1, -1410, 0, 30 * DT)
        Call(SetNpcYaw, NPC_ChainChomp1, 90)
        Call(NpcMoveTo, NPC_ChainChomp1, -690, 30, 90 * DT)
        Call(SetNpcPos, NPC_ChainChomp1, 0, -500, 0)
    EndThread
    Return
    End
};

Vec3f N(BuzzarFlightPath)[] = {
    { -805.0,   100.0,  -80.0 },
    { -675.0,   100.0, -230.0 },
    { -805.0,   100.0, -280.0 },
    { -935.0,   100.0, -230.0 },
    { -805.0,   100.0,  -80.0 },
};

EvtScript N(EVS_ParadePhase_BuzzarNest) = {
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_BUZZAR + 175)
            BreakLoop
        EndIf
    EndLoop
    Wait(200 * DT)
    Call(ShowEmote, NPC_Buzzar, EMOTE_SHOCK, 45, 30, EMOTER_NPC, 0, 0, 0, 0)
    Wait(40 * DT)
    Call(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim03)
    Call(NpcFlyTo, NPC_Buzzar, -855, 100, -180, 60 * DT, 0, EASING_LINEAR)
    Call(SetNpcAnimation, NPC_VultureChick1, ANIM_ParadeChick_EggTremble)
    Call(SetNpcAnimation, NPC_VultureChick2, ANIM_ParadeChick_EggTremble)
    Call(SetNpcAnimation, NPC_VultureChick3, ANIM_ParadeChick_EggTremble)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_VultureChick1, ANIM_ParadeChick_BreakEgg)
    Call(SetNpcAnimation, NPC_VultureChick2, ANIM_ParadeChick_BreakEggFwd)
    Call(SetNpcAnimation, NPC_VultureChick3, ANIM_ParadeChick_BreakEgg)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_VultureChick1, ANIM_ParadeChick_Chirp)
    Call(SetNpcAnimation, NPC_VultureChick2, ANIM_ParadeChick_ChirpFwd)
    Call(SetNpcAnimation, NPC_VultureChick3, ANIM_ParadeChick_Chirp)
    Wait(30 * DT)
    Call(InterpNpcYaw, NPC_Buzzar, 90, 0)
    Call(NpcFlyTo, NPC_Buzzar, -805, 100, -80, 30 * DT, 0, EASING_LINEAR)
    Thread
        Loop(6)
            Wait(20 * DT)
            Call(InterpNpcYaw, NPC_Buzzar, 270, 0)
            Wait(40 * DT)
            Call(InterpNpcYaw, NPC_Buzzar, 90, 0)
            Wait(20 * DT)
        EndLoop
    EndThread
    Thread
        Loop(6)
            Call(LoadPath, 80 * DT, Ref(N(BuzzarFlightPath)), ARRAY_COUNT(N(BuzzarFlightPath)), EASING_LINEAR)
            Loop(0)
                Call(GetNextPathPos)
                Call(SetNpcPos, NPC_Buzzar, LVar1, LVar2, LVar3)
                Wait(1)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndThread
    Return
    End
};
