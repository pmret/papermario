#include "end_01.h"
#include "effects.h"

EvtScript N(EVS_TexPan_FlowerFloat_Base) = {
    Call(EnableTexPanning, MODEL_flo1, true)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x2000)
        Call(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar0, 0)
        Wait(8)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_FlowerFloat_WisterwoodBody) = {
    Call(EnableTexPanning, MODEL_flo2, true)
    Call(EnableTexPanning, MODEL_flo4, true)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x400)
        Call(SetTexPanOffset, TEX_PANNER_A, TEX_PANNER_AUX, LVar0, LVar0)
        Wait(4)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_FlowerFloat_WisterwoodBlink) = {
    Call(EnableTexPanning, MODEL_flo3, true)
    Call(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0x8000, 0)
    Loop(0)
        Call(RandInt, 30, LVar0)
        Add(LVar0, 10)
        Wait(LVar0)
        Call(RandInt, 1, LVar0)
        Add(LVar0, 1)
        Loop(LVar0)
            Call(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, 0)
            Call(RandInt, 5, LVar1)
            Add(LVar1, 2)
            Wait(LVar1)
            Call(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0x8000, 0)
            Call(RandInt, 5, LVar1)
            Add(LVar1, 2)
            Wait(LVar1)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Amayze_Dayzees) = {
    Call(GetNpcPos, NPC_AmayzeDayzee1, LVar0, LVar1, LVar2)
    Add(LVar1, 30)
    Sub(LVar2, 2)
    Call(GetNpcPos, NPC_AmayzeDayzee2, LVar3, LVar4, LVar5)
    Add(LVar4, 30)
    Sub(LVar5, 2)
    Loop(0)
        PlayEffect(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 30)
        PlayEffect(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 30)
        Wait(15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Sun) = {
    Thread
        Call(SetNpcPos, NPC_SunSad, -2185, 130, -30)
        Call(NpcFlyTo, NPC_SunSad, -2185, 50, -30, 10 * DT, 0, EASING_LINEAR)
        Call(NpcFlyTo, NPC_SunSad, -2045, 50, -30, 70 * DT, 0, EASING_LINEAR)
        Call(SetNpcAnimation, NPC_SunSad, ANIM_Sun_TalkPleased)
        Call(NpcFlyTo, NPC_SunSad, -1645, 50, -30, 200 * DT, 0, EASING_LINEAR)
        Call(SetNpcPos, NPC_SunSad, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcPos, NPC_SunHappy, -2185, 130, -30)
        Call(NpcFlyTo, NPC_SunHappy, -2185, 50, -30, 10 * DT, 0, EASING_LINEAR)
        Call(NpcFlyTo, NPC_SunHappy, -2045, 50, -30, 70 * DT, 0, EASING_LINEAR)
        Call(SetNpcAnimation, NPC_SunHappy, ANIM_Sun_FireTalkPleased)
        Call(NpcFlyTo, NPC_SunHappy, -1645, 50, -30, 200 * DT, 0, EASING_LINEAR)
        Call(SetNpcPos, NPC_SunHappy, 0, -500, 0)
    EndThread
    Return
    End
};

EvtScript N(EVS_Bubulbs) = {
    Call(GetNpcPos, NPC_Bubulb1, LVar0, LVar1, LVar2)
    Set(LVar3, LVar0)
    Add(LVar3, -120)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, LVar3)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, 0, 360, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_Bubulb1, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_Bubulb2, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(GetNpcPos, NPC_Bubulb1, LVar0, LVar1, LVar2)
    Set(LVar3, LVar0)
    Add(LVar3, 100)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, LVar3)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, 0, 360, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_Bubulb1, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_Bubulb2, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_ParadePhase_Wizards) = {
    ExecGetTID(N(EVS_Amayze_Dayzees), LVarD)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_WIZARDS + 100)
            BreakLoop
        EndIf
    EndLoop
    Wait(1)
    ExecGetTID(N(EVS_TexPan_FlowerFloat_Base), LVarA)
    Exec(N(EVS_Bubulbs))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_WIZARDS + 365)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_Merle, ANIM_ParadeWizard_Merle_MerleRelease)
    Call(SetNpcAnimation, NPC_Merlee, ANIM_ParadeWizard_Merle_MerleeRelease)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_ParadeWizard_Merle_MerlonRelease)
    Call(SetNpcAnimation, NPC_Merluvlee, ANIM_ParadeWizard_Merle_MerluvleeRelease)
    Call(SetNpcAnimation, NPC_Merlow, ANIM_ParadeWizard_Merle_MerlowRelease)
    Call(SetNpcAnimation, NPC_Merlar, ANIM_ParadeWizard_Merle_MerlarRelease)
    Call(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 6, LVar0, LVar1, LVar2, 1, 20, 0, 0, 0, 0, 0, 0, 0)
    Wait(30)
    Exec(N(EVS_Sun))
    ExecGetTID(N(EVS_TexPan_FlowerFloat_WisterwoodBody), LVarB)
    ExecGetTID(N(EVS_TexPan_FlowerFloat_WisterwoodBlink), LVarC)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_SHYGUY_DANCE)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarD)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_WIZARDS + 600)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarA)
    KillThread(LVarB)
    KillThread(LVarC)
    Return
    End
};
