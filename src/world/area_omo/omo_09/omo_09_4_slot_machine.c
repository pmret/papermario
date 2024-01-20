#include "omo_09.h"
#include "model.h"

enum SlotMatchResult {
    SLOT_MATCH_NONE     = 0,
    SLOT_MATCH_TWO      = 2,
    SLOT_MATCH_THREE    = 3,
};

enum SlotSymbol {
    SYM_SHYGUY          = 1,
    SYM_COIN            = 2,
    SYM_STAR            = 3,
};

enum SlotMachineProgress {
    SLOT_PROGRESS_HIT_ONE       = 2,
    SLOT_PROGRESS_HIT_TWO       = 4,
    SLOT_PROGRESS_HIT_THREE     = 6,
    SLOT_PROGRESS_DISPENSE      = 7,
};

EvtScript N(EVS_SetCam_ViewReels) = {
    Wait(8)
    Call(N(DisableCameraLeadingPlayer))
    Call(UseSettingsFrom, CAM_DEFAULT, 535, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 535, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Return
    End
};

EvtScript N(EVS_SetCam_ViewPayout) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 535, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 535, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-30.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

s32 N(HitBlockRecoilOffsets)[] = {
    3, 0, -3, 0,
    2, 0, -2, 0,
    1, 0, -1, 0,
};

EvtScript N(EVS_HitBlockRecoil) = {
    UseBuf(Ref(N(HitBlockRecoilOffsets)))
    Loop(12)
        BufRead1(LVar1)
        Call(TranslateModel, LVar0, 0, LVar1, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_HitBlock_SlotStart) = {
    IfEq(MF_HitStartBlock, FALSE)
        Thread
            Wait(15)
            Call(PlaySoundAtCollider, COLLIDER_s1, SOUND_LOOP_OMO_SLOT_MACHINE, SOUND_SPACE_DEFAULT)
        EndThread
        Set(MF_HitStartBlock, TRUE)
        Set(AF_OMO09_StartBlock_DontBlink, TRUE)
        Call(EnableModel, MODEL_s1, TRUE)
        Call(EnableModel, MODEL_s2, FALSE)
        Set(LVar0, MODEL_s1)
        ExecWait(N(EVS_HitBlockRecoil))
        Call(EnableModel, MODEL_s1, FALSE)
        Call(EnableModel, MODEL_s2, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_HitBlock_SlotWheel1) = {
    IfEq(MF_Block1_Hit, FALSE)
        Set(MF_Block1_Hit, TRUE)
        Add(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
        Set(MV_ProgressOnHitBlock1, MV_SlotMachineProgress)
        IfEq(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_THREE)
            Exec(N(EVS_SetCam_ViewReels))
            Set(MV_SlotMachineProgress, SLOT_PROGRESS_DISPENSE)
        EndIf
        Set(AF_OMO09_Block1_DontBlink, TRUE)
        Call(EnableModel, MODEL_h1, TRUE)
        Call(EnableModel, MODEL_h1_a, FALSE)
        Set(LVar0, MODEL_h1)
        ExecWait(N(EVS_HitBlockRecoil))
        Call(EnableModel, MODEL_h1, FALSE)
        Call(EnableModel, MODEL_h1_a, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_HitBlock_SlotWheel2) = {
    IfEq(MF_Block2_Hit, FALSE)
        Set(MF_Block2_Hit, TRUE)
        Add(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
        Set(MV_ProgressOnHitBlock2, MV_SlotMachineProgress)
        IfEq(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_THREE)
            Exec(N(EVS_SetCam_ViewReels))
            Set(MV_SlotMachineProgress, SLOT_PROGRESS_DISPENSE)
        EndIf
        Set(AF_OMO09_Block2_DontBlink, TRUE)
        Call(EnableModel, MODEL_h2, TRUE)
        Call(EnableModel, MODEL_h2_a, FALSE)
        Set(LVar0, MODEL_h2)
        ExecWait(N(EVS_HitBlockRecoil))
        Call(EnableModel, MODEL_h2, FALSE)
        Call(EnableModel, MODEL_h2_a, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_HitBlock_SlotWheel3) = {
    IfEq(MF_Block3_Hit, FALSE)
        Set(MF_Block3_Hit, TRUE)
        Add(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
        Set(MV_ProgressOnHitBlock3, MV_SlotMachineProgress)
        IfEq(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_THREE)
            Exec(N(EVS_SetCam_ViewReels))
            Set(MV_SlotMachineProgress, SLOT_PROGRESS_DISPENSE)
        EndIf
        Set(AF_OMO09_Block3_DontBlink, TRUE)
        Call(EnableModel, MODEL_h3, TRUE)
        Call(EnableModel, MODEL_h3_a, FALSE)
        Set(LVar0, MODEL_h3)
        ExecWait(N(EVS_HitBlockRecoil))
        Call(EnableModel, MODEL_h3, FALSE)
        Call(EnableModel, MODEL_h3_a, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_UpdateActiveBlock1) = {
    Set(MF_Block1_Active, TRUE)
    Set(LVar2, MV_SlotWheel1_Angle)
    Add(LVar2, 360)
    Set(LVar5, 0)
    Set(LVar9, 0)
    Call(MakeLerp, MV_SlotWheel1_Angle, LVar2, 50, EASING_QUADRATIC_IN)
    Label(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o864, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o865, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o866, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o867, LVar0, 1, 0, 0)
        Set(LVar8, LVar0)
        Sub(LVar8, LVar9)
        Set(LVar9, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(RandInt, 7, LVar7)
    Mul(LVar7, 45)
    Add(LVar7, 2520)
    Set(LVar6, LVar7)
    Div(LVar6, LVar8)
    Set(LVar3, LVar2)
    Add(LVar3, LVar7)
    Call(MakeLerp, LVar2, LVar3, LVar6, EASING_LINEAR)
    Label(5)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o864, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o865, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o866, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o867, LVar0, 1, 0, 0)
        IfEq(MF_Block1_Hit, TRUE)
            Set(LVar9, LVar0)
            Mod(LVar9, 45)
            IfEq(LVar9, 0)
                Sub(MV_ProgressOnHitBlock1, 1)
                IfEq(MV_ProgressOnHitBlock1, 0)
                    Goto(10)
                EndIf
            EndIf
        Else
            IfEq(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                Set(MF_Block1_Hit, TRUE)
                Add(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
                Set(MV_ProgressOnHitBlock1, MV_SlotMachineProgress)
            EndIf
        EndIf
        Wait(1)
        Goto(5)
    Label(10)
    IfEq(MF_Block1_Hit, TRUE)
        Set(LVar3, LVar0)
    EndIf
    Set(LVar4, LVar3)
    Add(LVar4, 1080)
    Call(MakeLerp, LVar3, LVar4, 40, EASING_QUADRATIC_OUT)
    Label(2)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o864, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o865, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o866, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o867, LVar0, 1, 0, 0)
        IfNe(LVar3, LVar0)
            Wait(1)
        EndIf
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Set(MF_Block1_Hit, TRUE)
    Set(MF_Block1_Active, FALSE)
    Set(MV_SlotWheel1_Angle, LVar4)
    IfEq(AB_OMO09_IsPlayerNearSlotMachine, TRUE)
        Call(PlaySoundAtCollider, COLLIDER_h1, SOUND_DING, SOUND_SPACE_DEFAULT)
    EndIf
    Return
    End
};

EvtScript N(EVS_UpdateActiveBlock2) = {
    Set(MF_Block2_Active, TRUE)
    Set(LVar2, MV_SlotWheel2_Angle)
    Add(LVar2, 360)
    Set(LVar5, 0)
    Set(LVar9, 0)
    Call(MakeLerp, MV_SlotWheel2_Angle, LVar2, 50, EASING_QUADRATIC_IN)
    Label(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o868, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o869, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o870, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o871, LVar0, 1, 0, 0)
        Set(LVar8, LVar0)
        Sub(LVar8, LVar9)
        Set(LVar9, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(RandInt, 7, LVar7)
    Mul(LVar7, 45)
    Add(LVar7, 3240)
    Set(LVar6, LVar7)
    Div(LVar6, LVar8)
    Set(LVar3, LVar2)
    Add(LVar3, LVar7)
    Call(MakeLerp, LVar2, LVar3, LVar6, EASING_LINEAR)
    Label(5)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o868, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o869, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o870, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o871, LVar0, 1, 0, 0)
        IfEq(MF_Block2_Hit, TRUE)
            Set(LVar9, LVar0)
            Mod(LVar9, 45)
            IfEq(LVar9, 0)
                Sub(MV_ProgressOnHitBlock2, 1)
                IfEq(MV_ProgressOnHitBlock2, 0)
                    Goto(10)
                EndIf
            EndIf
        Else
            IfEq(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                Set(MF_Block2_Hit, TRUE)
                Add(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
                Set(MV_ProgressOnHitBlock2, MV_SlotMachineProgress)
            EndIf
        EndIf
        Wait(1)
        Goto(5)
    Label(10)
    IfEq(MF_Block2_Hit, TRUE)
        Set(LVar3, LVar0)
    EndIf
    Set(LVar4, LVar3)
    Add(LVar4, 1080)
    Call(MakeLerp, LVar3, LVar4, 40, EASING_QUADRATIC_OUT)
    Label(2)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o868, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o869, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o870, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o871, LVar0, 1, 0, 0)
        IfNe(LVar3, LVar0)
            Wait(1)
        EndIf
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Set(MF_Block2_Hit, TRUE)
    Set(MF_Block2_Active, FALSE)
    Set(MV_SlotWheel2_Angle, LVar4)
    IfEq(AB_OMO09_IsPlayerNearSlotMachine, TRUE)
        Call(PlaySoundAtCollider, COLLIDER_h2, SOUND_DING, SOUND_SPACE_DEFAULT)
    EndIf
    Return
    End
};

EvtScript N(EVS_UpdateActiveBlock3) = {
    Set(MF_Block3_Active, TRUE)
    Set(LVar2, MV_SlotWheel3_Angle)
    Add(LVar2, 360)
    Set(LVar5, 0)
    Set(LVar9, 0)
    Call(MakeLerp, MV_SlotWheel3_Angle, LVar2, 50, EASING_QUADRATIC_IN)
    Label(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o872, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o873, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o874, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o875, LVar0, 1, 0, 0)
        Set(LVar8, LVar0)
        Sub(LVar8, LVar9)
        Set(LVar9, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(RandInt, 7, LVar7)
    Mul(LVar7, 45)
    Add(LVar7, 3960)
    Set(LVar6, LVar7)
    Div(LVar6, LVar8)
    Set(LVar3, LVar2)
    Add(LVar3, LVar7)
    Call(MakeLerp, LVar2, LVar3, LVar6, EASING_LINEAR)
    Label(5)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o872, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o873, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o874, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o875, LVar0, 1, 0, 0)
        IfEq(MF_Block3_Hit, TRUE)
            Set(LVar9, LVar0)
            Mod(LVar9, 45)
            IfEq(LVar9, 0)
                Sub(MV_ProgressOnHitBlock3, 1)
                IfEq(MV_ProgressOnHitBlock3, 0)
                    Goto(10)
                EndIf
            EndIf
        Else
            IfEq(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                Set(MF_Block3_Hit, TRUE)
                Add(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
                Set(MV_ProgressOnHitBlock3, MV_SlotMachineProgress)
            EndIf
        EndIf
        Wait(1)
        Goto(5)
    Label(10)
    IfEq(MF_Block3_Hit, TRUE)
        Set(LVar3, LVar0)
    EndIf
    Set(LVar4, LVar3)
    Add(LVar4, 1080)
    Call(MakeLerp, LVar3, LVar4, 40, EASING_QUADRATIC_OUT)
    Label(2)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o872, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o873, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o874, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o875, LVar0, 1, 0, 0)
        IfNe(LVar3, LVar0)
            Wait(1)
        EndIf
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Set(MF_Block3_Hit, TRUE)
    Set(MF_Block3_Active, FALSE)
    Set(MV_SlotWheel3_Angle, LVar4)
    IfEq(AB_OMO09_IsPlayerNearSlotMachine, TRUE)
        Call(PlaySoundAtCollider, COLLIDER_h3, SOUND_DING, SOUND_SPACE_DEFAULT)
    EndIf
    Return
    End
};

//TODO these should be a 3x8 array
s32 N(ReelContents)[] = {
    SYM_SHYGUY, SYM_STAR, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN,
    SYM_SHYGUY, SYM_STAR, SYM_SHYGUY, SYM_COIN, SYM_STAR,   SYM_COIN, SYM_SHYGUY, SYM_COIN,
    SYM_SHYGUY, SYM_STAR, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN,
};

// returns the SlotMatchResult on LVarA and SlotSymbol on LVarB (only valid if SlotMatchResult != SLOT_MATCH_NONE)
API_CALLABLE(N(CheckSlotsResult)) {
    Bytecode* args = script->ptrReadPos;
    s32 angleReel1 = evt_get_variable(script, *args++);
    s32 angleReel2 = evt_get_variable(script, *args++);
    s32 angleReel3 = evt_get_variable(script, *args++);
    s32 results[3];
    s32 a, b;
    s32 i, j;

    // get results from completed reels
    if (angleReel1 != -1) {
        results[0] = N(ReelContents)[(angleReel1 % 360) / 45];
    } else {
        results[0] = 0;
    }
    if (angleReel2 != -1) {
        results[1] = N(ReelContents)[((angleReel2 % 360) / 45) + 8];
    } else {
        results[1] = 0;
    }
    if (angleReel3 != -1) {
        results[2] = N(ReelContents)[((angleReel3 % 360) / 45) + 16];
    } else {
        results[2] = 0;
    }

    // sort and categorize resulting matches
    for (i = 0; i < ARRAY_COUNT(results) - 1; i++) {
        for (j = 1; j < ARRAY_COUNT(results); j++) {
            a = results[i];
            b = results[j];
            if (b < a) {
                results[i] = b;
                results[j] = a;
            }
        }
    }
    if (results[1] == results[0]) {
        if (results[1] == results[2]) {
            script->varTable[10] = SLOT_MATCH_THREE;
        } else {
            script->varTable[10] = SLOT_MATCH_TWO;
        }
    } else if (results[1] == results[2]) {
        script->varTable[10] = SLOT_MATCH_TWO;
    } else {
        script->varTable[10] = SLOT_MATCH_NONE;
    }
    script->varTable[11] = results[1];
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Block1_UpdateBlinking) = {
    Set(AF_OMO09_Block1_DontBlink, FALSE)
    Set(LVar0, 0)
    Label(0)
        IfEq(LVar0, 0)
            Call(EnableModel, MODEL_h1, TRUE)
            Call(EnableModel, MODEL_h1_a, FALSE)
            Set(LVar0, 1)
        Else
            Call(EnableModel, MODEL_h1, FALSE)
            Call(EnableModel, MODEL_h1_a, TRUE)
            Set(LVar0, 0)
        EndIf
        Loop(10)
            Wait(1)
            IfEq(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                Set(AF_OMO09_Block1_DontBlink, TRUE)
                BreakLoop
            EndIf
        EndLoop
        IfEq(AF_OMO09_Block1_DontBlink, FALSE)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_Block2_UpdateBlinking) = {
    Set(AF_OMO09_Block2_DontBlink, FALSE)
    Set(LVar0, 0)
    Label(0)
        IfEq(LVar0, 0)
            Call(EnableModel, MODEL_h2, TRUE)
            Call(EnableModel, MODEL_h2_a, FALSE)
            Set(LVar0, 1)
        Else
            Call(EnableModel, MODEL_h2, FALSE)
            Call(EnableModel, MODEL_h2_a, TRUE)
            Set(LVar0, 0)
        EndIf
        Loop(10)
            Wait(1)
            IfEq(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                Set(AF_OMO09_Block2_DontBlink, TRUE)
                BreakLoop
            EndIf
        EndLoop
        IfEq(AF_OMO09_Block2_DontBlink, FALSE)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_Block3_UpdateBlinking) = {
    Set(AF_OMO09_Block3_DontBlink, FALSE)
    Set(LVar0, 0)
    Label(0)
        IfEq(LVar0, 0)
            Call(EnableModel, MODEL_h3, TRUE)
            Call(EnableModel, MODEL_h3_a, FALSE)
            Set(LVar0, 1)
        Else
            Call(EnableModel, MODEL_h3, FALSE)
            Call(EnableModel, MODEL_h3_a, TRUE)
            Set(LVar0, 0)
        EndIf
        Loop(10)
            Wait(1)
            IfEq(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                Set(AF_OMO09_Block3_DontBlink, TRUE)
                BreakLoop
            EndIf
        EndLoop
        IfEq(AF_OMO09_Block3_DontBlink, FALSE)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_StartBlock_UpdateBlinking) = {
    Set(AF_OMO09_StartBlock_DontBlink, FALSE)
    Set(LVar0, 0)
    Label(0)
        IfEq(LVar0, 0)
            Call(EnableModel, MODEL_s1, TRUE)
            Call(EnableModel, MODEL_s2, FALSE)
            Set(LVar0, 1)
        Else
            Call(EnableModel, MODEL_s1, FALSE)
            Call(EnableModel, MODEL_s2, TRUE)
            Set(LVar0, 0)
        EndIf
        Wait(10)
        IfEq(AF_OMO09_StartBlock_DontBlink, FALSE)
            Goto(0)
        EndIf
    Set(AB_OMO09_IsPlayerNearSlotMachine, TRUE)
    Exec(N(EVS_Block1_UpdateBlinking))
    Exec(N(EVS_Block2_UpdateBlinking))
    Exec(N(EVS_Block3_UpdateBlinking))
    Return
    End
};

EvtScript N(EVS_SlotMachine_MainUpdate) = {
    Label(0)
    Set(MF_AnimateSlotLights, FALSE)
    Label(1)
        Wait(1)
        IfEq(MF_HitStartBlock, FALSE)
            Goto(1)
        EndIf
    Set(MF_Block1_Hit, FALSE)
    Set(MF_Block2_Hit, FALSE)
    Set(MF_Block3_Hit, FALSE)
    Set(MV_ProgressOnHitBlock1, 0)
    Set(MV_ProgressOnHitBlock2, 0)
    Set(MV_ProgressOnHitBlock3, 0)
    Set(MV_SlotMachineProgress, 0)
    Exec(N(EVS_UpdateActiveBlock1))
    Exec(N(EVS_UpdateActiveBlock2))
    Exec(N(EVS_UpdateActiveBlock3))
    Wait(3)
    Set(LVar0, 0)
    Set(LVar2, 0)
    Label(2)
        Call(IsPlayerWithin, 525, 0, 500, AB_OMO09_IsPlayerNearSlotMachine)
        IfEq(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
            Call(StopSound, SOUND_LOOP_OMO_SLOT_MACHINE)
            Wait(100)
            Goto(99)
        EndIf
        // how many blocks have been hit?
        Set(LVar1, MF_Block1_Active)
        Add(LVar1, MF_Block2_Active)
        Add(LVar1, MF_Block3_Active)
        IfEq(LVar2, 0)
            Set(LVarA, SLOT_MATCH_NONE)
            IfEq(MF_Block1_Active, FALSE)
                IfEq(MF_Block2_Active, FALSE)
                    Set(LVar2, 1)
                    Call(N(CheckSlotsResult), MV_SlotWheel1_Angle, MV_SlotWheel2_Angle, -1)
                EndIf
                IfEq(MF_Block3_Active, FALSE)
                    Set(LVar2, 1)
                    Call(N(CheckSlotsResult), MV_SlotWheel1_Angle, -1, MV_SlotWheel3_Angle)
                EndIf
            EndIf
            IfEq(MF_Block2_Active, FALSE)
                IfEq(MF_Block3_Active, FALSE)
                    Set(LVar2, 1)
                    Call(N(CheckSlotsResult), -1, MV_SlotWheel2_Angle, MV_SlotWheel3_Angle)
                EndIf
            EndIf
            IfNe(LVarA, SLOT_MATCH_NONE)
                // partial match after two blocks hit
                Set(MF_AnimateSlotLights, TRUE)
                Call(PlaySoundAtCollider, COLLIDER_o881, SOUND_LRAW_OMO_SLOT_MACHINE | SOUND_ID_TRIGGER_CHANGE_VOLUME, SOUND_SPACE_DEFAULT)
            EndIf
        EndIf
        Wait(1)
        // wait until all blocks are hit
        IfNe(LVar1, 0)
            Goto(2)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Call(StopSound, SOUND_LOOP_OMO_SLOT_MACHINE)
    Wait(20)
    Call(N(CheckSlotsResult), MV_SlotWheel1_Angle, MV_SlotWheel2_Angle, MV_SlotWheel3_Angle)
    IfNe(LVarA, 0)
        Set(MF_AnimateSlotLights, TRUE)
    EndIf
    Set(MV_ResetCamSpeed, Float(90.0))
    // dispense rewards
    Switch(LVarB)
        CaseEq(SYM_SHYGUY)
            Switch(LVarA)
                CaseEq(SLOT_MATCH_THREE)
                    ExecWait(N(EVS_SetCam_ViewPayout))
                    Thread
                        Call(SetNpcPos, NPC_ShyGuy_Jackpot1, 485, 130, -50)
                        Call(SetNpcJumpscale, NPC_ShyGuy_Jackpot1, Float(0.8))
                        Call(NpcJump0, NPC_ShyGuy_Jackpot1, 460, 0, 50, 30)
                        Call(SetNpcFlagBits, NPC_ShyGuy_Jackpot1, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EndThread
                    Thread
                        Call(SetNpcPos, NPC_ShyGuy_Jackpot2, 510, 130, -50)
                        Call(SetNpcJumpscale, NPC_ShyGuy_Jackpot2, Float(0.8))
                        Call(NpcJump0, NPC_ShyGuy_Jackpot2, 497, 0, 50, 30)
                        Call(SetNpcFlagBits, NPC_ShyGuy_Jackpot2, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EndThread
                    Thread
                        Call(SetNpcPos, NPC_ShyGuy_Jackpot3, 535, 130, -50)
                        Call(SetNpcJumpscale, NPC_ShyGuy_Jackpot3, Float(0.8))
                        Call(NpcJump0, NPC_ShyGuy_Jackpot3, 535, 0, 50, 30)
                        Call(SetNpcFlagBits, NPC_ShyGuy_Jackpot3, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EndThread
                    Thread
                        Call(SetNpcPos, NPC_ShyGuy_Jackpot4, 560, 130, -50)
                        Call(SetNpcJumpscale, NPC_ShyGuy_Jackpot4, Float(0.8))
                        Call(NpcJump0, NPC_ShyGuy_Jackpot4, 573, 0, 50, 30)
                        Call(SetNpcFlagBits, NPC_ShyGuy_Jackpot4, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EndThread
                    Thread
                        Call(SetNpcPos, NPC_ShyGuy_Jackpot5, 585, 130, -50)
                        Call(SetNpcJumpscale, NPC_ShyGuy_Jackpot5, Float(0.8))
                        Call(NpcJump0, NPC_ShyGuy_Jackpot5, 610, 0, 50, 30)
                        Call(SetNpcFlagBits, NPC_ShyGuy_Jackpot5, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EndThread
                    Wait(20)
                CaseEq(SLOT_MATCH_TWO)
                    ExecWait(N(EVS_SetCam_ViewPayout))
                    Thread
                        Call(SetNpcPos, NPC_ShyGuy_Jackpot2, 510, 130, -50)
                        Call(SetNpcJumpscale, NPC_ShyGuy_Jackpot2, Float(0.8))
                        Call(NpcJump0, NPC_ShyGuy_Jackpot2, 497, 0, 50, 30)
                        Call(SetNpcFlagBits, NPC_ShyGuy_Jackpot2, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EndThread
                    Thread
                        Call(SetNpcPos, NPC_ShyGuy_Jackpot4, 560, 130, -50)
                        Call(SetNpcJumpscale, NPC_ShyGuy_Jackpot4, Float(0.8))
                        Call(NpcJump0, NPC_ShyGuy_Jackpot4, 573, 0, 50, 30)
                        Call(SetNpcFlagBits, NPC_ShyGuy_Jackpot4, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EndThread
                    Wait(20)
                CaseDefault
                    Set(MV_ResetCamSpeed, Float(2.0))
            EndSwitch
        CaseEq(SYM_COIN)
            Switch(LVarA)
                CaseEq(SLOT_MATCH_THREE)
                    ExecWait(N(EVS_SetCam_ViewPayout))
                    Thread
                        Loop(2)
                            Set(LVar1, 480)
                            Loop(5)
                                Add(LVar1, 20)
                                Call(MakeItemEntity, ITEM_COIN, LVar1, 150, 50, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
                                Wait(3)
                            EndLoop
                        EndLoop
                    EndThread
                    Wait(30)
                CaseEq(SLOT_MATCH_TWO)
                    ExecWait(N(EVS_SetCam_ViewPayout))
                    Call(MakeItemEntity, ITEM_COIN, 535, 150, 50, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
                    Wait(30)
                CaseDefault
                    Set(MV_ResetCamSpeed, Float(2.0))
            EndSwitch
        CaseEq(SYM_STAR)
            Switch(LVarA)
                CaseEq(SLOT_MATCH_THREE)
                    ExecWait(N(EVS_SetCam_ViewPayout))
                    Thread
                        Loop(2)
                            Set(LVar1, 480)
                            Loop(5)
                                Add(LVar1, 20)
                                Call(MakeItemEntity, ITEM_MUSHROOM, LVar1, 150, 50, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
                                Wait(3)
                            EndLoop
                        EndLoop
                    EndThread
                    Wait(30)
                CaseEq(SLOT_MATCH_TWO)
                    ExecWait(N(EVS_SetCam_ViewPayout))
                    Call(MakeItemEntity, ITEM_MUSHROOM, 535, 150, 50, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
                    Wait(30)
                CaseDefault
                    Set(MV_ResetCamSpeed, Float(2.0))
            EndSwitch
    EndSwitch
    Call(N(EnableCameraLeadingPlayer))
    Call(ResetCam, CAM_DEFAULT, MV_ResetCamSpeed)
    Call(DisablePlayerInput, FALSE)
    Loop(0)
        Set(LVar0, 0)
        Set(LVar4, -1)
        Loop(5)
            Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            IfGe(LVar2, 0)
                Set(LVar4, 0)
            EndIf
            Add(LVar0, 1)
        EndLoop
        IfNe(LVar4, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Wait(50)
    Label(99)
    Set(MF_HitStartBlock, FALSE)
    Set(MF_Block1_Hit, TRUE)
    Set(MF_Block2_Hit, TRUE)
    Set(MF_Block3_Hit, TRUE)
    Set(MF_Block1_Active, FALSE)
    Set(MF_Block2_Active, FALSE)
    Set(MF_Block3_Active, FALSE)
    Set(MF_AnimateSlotLights, FALSE)
    Set(AF_OMO09_Block1_DontBlink, FALSE)
    Set(AF_OMO09_Block2_DontBlink, FALSE)
    Set(AF_OMO09_Block3_DontBlink, FALSE)
    Call(EnableModel, MODEL_s1, TRUE)
    Call(EnableModel, MODEL_s2, FALSE)
    Exec(N(EVS_StartBlock_UpdateBlinking))
    Call(EnableModel, MODEL_h1, TRUE)
    Call(EnableModel, MODEL_h1_a, FALSE)
    Call(EnableModel, MODEL_h2, TRUE)
    Call(EnableModel, MODEL_h2_a, FALSE)
    Call(EnableModel, MODEL_h3, TRUE)
    Call(EnableModel, MODEL_h3_a, FALSE)
    Goto(0)
    Return
    End
};

s32 N(SlotMachineBlocks)[] = {
    MODEL_s1,
    MODEL_h1,
    MODEL_h2,
    MODEL_h3,
};

API_CALLABLE(N(UpdateSlotMachineBlockShadows)) {
    s32 (*shadowIDs)[4];
    Shadow* shadow;
    Model* model;
    f32 x, y, z;
    f32 rotX, rotZ;
    f32 scale;
    u32 i;

    if (isInitialCall) {

        script->functionTempPtr[0] = shadowIDs = heap_malloc(sizeof(*shadowIDs));
        for (i = 0; i < ARRAY_COUNT(N(SlotMachineBlocks)); i++) {
            model = get_model_from_list_index(get_model_list_index_from_tree_index(N(SlotMachineBlocks)[i]));
            (*shadowIDs)[i] = create_shadow_type(SHADOW_VARYING_SQUARE, model->center.x, model->center.y - 100.0f, model->center.z);
        }
    }

    shadowIDs = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(N(SlotMachineBlocks)); i++) {
        shadow = get_shadow_by_index((*shadowIDs)[i]);
        model = get_model_from_list_index(get_model_list_index_from_tree_index(N(SlotMachineBlocks)[i]));
        x = model->center.x;
        y = model->center.y;
        z = model->center.z;
        scale = 1000.0f;
        entity_raycast_down(&x, &y, &z, &rotX, &rotZ, &scale);
        set_standard_shadow_scale(shadow, scale);
        shadow->pos.x = x;
        shadow->pos.y = y;
        shadow->pos.z = z;
        shadow->rot.x = rotX;
        shadow->rot.y = 0.0f;
        shadow->rot.z = rotZ;
        shadow->scale.x *= 1.3f;
        shadow->scale.z *= 1.3f;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_SetupSlotMachine) = {
    Call(ParentColliderToModel, COLLIDER_s1, MODEL_s1)
    Call(ParentColliderToModel, COLLIDER_h1, MODEL_h1)
    Call(ParentColliderToModel, COLLIDER_h2, MODEL_h2)
    Call(ParentColliderToModel, COLLIDER_h3, MODEL_h3)
    BindTrigger(Ref(N(EVS_HitBlock_SlotStart)), TRIGGER_CEILING_TOUCH, COLLIDER_s1, 1, 0)
    BindTrigger(Ref(N(EVS_HitBlock_SlotWheel1)), TRIGGER_CEILING_TOUCH, COLLIDER_h1, 1, 0)
    BindTrigger(Ref(N(EVS_HitBlock_SlotWheel2)), TRIGGER_CEILING_TOUCH, COLLIDER_h2, 1, 0)
    BindTrigger(Ref(N(EVS_HitBlock_SlotWheel3)), TRIGGER_CEILING_TOUCH, COLLIDER_h3, 1, 0)
    Call(RandInt, 7, MV_SlotWheel1_Angle)
    Mul(MV_SlotWheel1_Angle, 45)
    Call(RotateModel, MODEL_o864, MV_SlotWheel1_Angle, 1, 0, 0)
    Call(RotateModel, MODEL_o865, MV_SlotWheel1_Angle, 1, 0, 0)
    Call(RotateModel, MODEL_o866, MV_SlotWheel1_Angle, 1, 0, 0)
    Call(RotateModel, MODEL_o867, MV_SlotWheel1_Angle, 1, 0, 0)
    Call(RandInt, 7, MV_SlotWheel2_Angle)
    Mul(MV_SlotWheel2_Angle, 45)
    Call(RotateModel, MODEL_o868, MV_SlotWheel2_Angle, 1, 0, 0)
    Call(RotateModel, MODEL_o869, MV_SlotWheel2_Angle, 1, 0, 0)
    Call(RotateModel, MODEL_o870, MV_SlotWheel2_Angle, 1, 0, 0)
    Call(RotateModel, MODEL_o871, MV_SlotWheel2_Angle, 1, 0, 0)
    Call(RandInt, 7, MV_SlotWheel3_Angle)
    Mul(MV_SlotWheel3_Angle, 45)
    Call(RotateModel, MODEL_o872, MV_SlotWheel3_Angle, 1, 0, 0)
    Call(RotateModel, MODEL_o873, MV_SlotWheel3_Angle, 1, 0, 0)
    Call(RotateModel, MODEL_o874, MV_SlotWheel3_Angle, 1, 0, 0)
    Call(RotateModel, MODEL_o875, MV_SlotWheel3_Angle, 1, 0, 0)
    Set(MF_HitStartBlock, FALSE)
    Set(MF_Block1_Hit, TRUE)
    Set(MF_Block2_Hit, TRUE)
    Set(MF_Block3_Hit, TRUE)
    Set(MF_Block1_Active, FALSE)
    Set(MF_Block2_Active, FALSE)
    Set(MF_Block3_Active, FALSE)
    Set(MF_AnimateSlotLights, FALSE)
    Call(EnableTexPanning, MODEL_o888, TRUE)
    Call(EnableTexPanning, MODEL_o876, TRUE)
    Call(EnableTexPanning, MODEL_o884, TRUE)
    Thread
        Set(LVar1, 0)
        Loop(0)
            IfEq(MF_AnimateSlotLights, TRUE)
                Add(LVar1, -1110)
            EndIf
            Call(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVar1)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(N(UpdateSlotMachineBlockShadows))
    EndThread
    Call(EnableModel, MODEL_s1, TRUE)
    Call(EnableModel, MODEL_s2, FALSE)
    Exec(N(EVS_StartBlock_UpdateBlinking))
    Call(EnableModel, MODEL_h1, TRUE)
    Call(EnableModel, MODEL_h1_a, FALSE)
    Call(EnableModel, MODEL_h2, TRUE)
    Call(EnableModel, MODEL_h2_a, FALSE)
    Call(EnableModel, MODEL_h3, TRUE)
    Call(EnableModel, MODEL_h3_a, FALSE)
    Exec(N(EVS_SlotMachine_MainUpdate))
    Return
    End
};
