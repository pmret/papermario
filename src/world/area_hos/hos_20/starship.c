#include "hos_20.h"

API_CALLABLE(N(CheckForSkipInput)) {
    script->varTable[8] = false;
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        script->varTable[8] = true;
    }
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_B) {
        script->varTable[8] = true;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateStarship) = {
    Thread
        Set(LVar4, 185)
        Set(LVar5, 50)
        Loop(0)
            Set(LVar3, LVar4)
            Set(LVar4, LVar5)
            Set(LVar5, LVar3)
            Call(MakeLerp, LVar3, LVar4, 30, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                DivF(LVar0, 10)
                Call(SetCamPitch, CAM_DEFAULT, LVar0, Float(-3.0))
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndThread
    Set(LVar4, -20)
    Set(LVar5, 80)
    Call(GetEntryID, LVar8)
    Loop(0)
        Set(LVar3, LVar4)
        Set(LVar4, LVar5)
        Set(LVar5, LVar3)
        Call(MakeLerp, LVar3, LVar4, 30, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            MulF(LVar2, Float(0.1))
            Call(TranslateGroup, MODEL_ry, MV_Starship_PosX, LVar2, 0)
            Call(RotateGroup, MODEL_ry, MV_Starship_Yaw, 0, 1, 0)
            Call(GetModelCenter, MODEL_ry3)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            IfNe(LVar8, hos_20_ENTRY_2)
                Add(LVar0, -10)
            Else
                Add(LVar0, 10)
            EndIf
            Add(LVar2, 5)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Starship_Flight1) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(InterpPlayerYaw, 135, 0)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-3.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Set(MV_Starship_PosX, -300)
    Set(MV_Starship_Yaw, 0)
    Exec(N(EVS_AnimateStarship))
    Wait(1)
    Call(PlaySound, SOUND_STARSHIP_ENGINE_LOOP)
    IfLt(GB_StoryProgress, STORY_UNUSED_0000005D)
        Call(MakeLerp, -300, 0, 120, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_Starship_PosX, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(100)
        Call(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
        Call(GotoMap, Ref("hos_00"), hos_00_ENTRY_3)
    Else
        Thread
            Call(MakeLerp, -300, 0, 120, EASING_QUADRATIC_OUT)
            Loop(0)
                Call(UpdateLerp)
                Set(MV_Starship_PosX, LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Wait(75)
            Call(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
            Call(PlaySound, SOUND_STARSHIP_BOOST)
            Call(MakeLerp, 0, 300, 60, EASING_CUBIC_IN)
            Loop(0)
                Call(UpdateLerp)
                Set(MV_Starship_PosX, LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Wait(20)
        EndThread
        Wait(60)
        Loop(215)
            Wait(1)
            Call(N(CheckForSkipInput))
            IfEq(LVar8, true)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
        Call(GotoMap, Ref("kpa_60"), kpa_60_ENTRY_4)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Starship_Flight2) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(InterpPlayerYaw, 135, 0)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-3.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(PlaySound, SOUND_STARSHIP_ENGINE_LOOP)
    Set(MV_Starship_PosX, 0)
    Set(MV_Starship_Yaw, 0)
    Exec(N(EVS_AnimateStarship))
    Wait(100)
    Call(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
    Call(PlaySound, SOUND_STARSHIP_BOOST)
    Call(MakeLerp, 0, 300, 60, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Set(MV_Starship_PosX, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(20)
    Call(GotoMap, Ref("osr_03"), osr_03_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Starship_Return) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(InterpPlayerYaw, 225, 0)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(SetNpcYaw, NPC_PARTNER, 270)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-3.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Set(MV_Starship_PosX, 300)
    Set(MV_Starship_Yaw, 180)
    Exec(N(EVS_AnimateStarship))
    Wait(2)
    Call(PlaySound, SOUND_STARSHIP_ENGINE_LOOP)
    Thread
        Call(MakeLerp, 300, 0, 120, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_Starship_PosX, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(75)
        Call(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
        Call(PlaySound, SOUND_STARSHIP_BOOST)
        Call(MakeLerp, 0, -300, 60, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_Starship_PosX, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(20)
    EndThread
    Wait(60)
    Loop(215)
        Wait(1)
        Call(N(CheckForSkipInput))
        IfEq(LVar8, true)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
    Call(GotoMap, Ref("hos_05"), hos_05_ENTRY_1)
    Wait(100)
    Return
    End
};
