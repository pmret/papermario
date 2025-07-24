#include "jan_23.h"

EvtScript N(EVS_ExitWalk_jan_19_1) = EVT_EXIT_WALK(60, jan_23_ENTRY_0, "jan_19", jan_19_ENTRY_1);

EvtScript N(EVS_ExitFall_jan_16_4) = {
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar1, 110)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, true)
    SetF(MV_Unk_05, 0)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, 8)
        Thread
            Call(DisablePartnerAI, 0)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
            IfEq(LVar0, 0)
                Call(GetPlayerPos, LVar2, LVar3, LVar4)
                Call(SetNpcJumpscale, NPC_PARTNER, Float(3.0))
                Call(NpcJump0, NPC_PARTNER, LVar2, LVar3, LVar4, 15)
            Else
                Wait(10)
            EndIf
            Call(GetNpcPos, NPC_PARTNER, LVar2, LVar3, LVar4)
            Call(MakeLerp, LVar3, -500, 15, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Add(LVar4, 2)
                Call(SetNpcPos, NPC_PARTNER, LVar2, LVar0, LVar4)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndThread
        Thread
            Call(GetPlayerActionState, LVar0)
            Switch(LVar0)
                CaseEq(ACTION_STATE_SPIN_JUMP)
                    Goto(11)
                CaseEq(ACTION_STATE_TORNADO_JUMP)
                    Label(11)
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 250, 100)
                    Call(SetPanTarget, CAM_DEFAULT, LVar0, -100, LVar2)
                    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                    Call(PanToTarget, CAM_DEFAULT, 0, true)
                    Set(MV_Unk_05, -1)
                CaseDefault
                    Wait(10)
            EndSwitch
            Call(DisablePlayerPhysics, true)
            Call(GetPlayerPos, LVar2, LVar3, LVar4)
            Call(MakeLerp, LVar3, -500, 15, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Add(LVar4, 2)
                Call(SetPlayerPos, LVar2, LVar0, LVar4)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(SetPlayerActionState, ACTION_STATE_LAND)
        EndThread
    EndIf
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar1, -100)
            BreakLoop
        EndIf
    EndLoop
    IfEq(MV_Unk_05, 0)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 250, 100)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndIf
    Wait(30)
    Call(GotoMap, Ref("jan_16"), jan_16_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_19_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Exec(N(EVS_ExitFall_jan_16_4))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    ExecWait(N(EVS_SetupMusic))
    Return
    End
};
