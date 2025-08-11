#include "mim_11.h"

EvtScript N(D_80242560_BB95D0) = {
    Wait(30 * DT)
    Call(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_h_mon1, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_h_mon2, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetPlayerSpeed, Float(2.0 / DT))
    Call(PlayerMoveTo, -101, 17, 0)
    Wait(30 * DT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    Call(MakeLerp, 80, 0, 8, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_h_mon1, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_h_mon2, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    Call(ShakeCam, CAM_DEFAULT, 0, 15, Float(1.5))
    Wait(20 * DT)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(SetCamType, CAM_DEFAULT, 0, true)
    Call(SetCamPitch, CAM_DEFAULT, Float(19.5), Float(-14.9))
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPosA, CAM_DEFAULT, -133, 52)
    Call(SetCamPosB, CAM_DEFAULT, 23, -109)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 23, 0, -109)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetMusic, 0, SONG_BOOS_MANSION, 0, VOL_LEVEL_FULL)
    Call(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_VANISH_A, SOUND_SPACE_DEFAULT)
    SetF(LVar0, Float(0.0))
    Loop(90 * DT)
        AddF(LVar0, Float(2.6667 / DT))
        Call(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Talk, ANIM_Bootler_Idle, 0, MSG_CH3_0028)
    Call(SetMusic, 0, SONG_BOOS_MANSION, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Wait(10 * DT)
    Call(SetCamPitch, CAM_DEFAULT, Float(0.0), Float(-25.0))
    Call(SetCamDistance, CAM_DEFAULT, 550)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(ShowMessageAtScreenPos, MSG_CH3_0029, 160, 40)
    Wait(30 * DT)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(19.5), Float(-14.9))
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Talk, ANIM_Bootler_Idle, 0, MSG_CH3_002A)
    Call(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_APPEAR_A, SOUND_SPACE_DEFAULT)
    SetF(LVar0, Float(240.0))
    Loop(90 * DT)
        SubF(LVar0, Float(2.6667 / DT))
        Call(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(RemoveNpc, NPC_Bootler)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Return
    End
};

EvtScript N(D_80242B90_BB9C00) = {
    Call(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    Thread
        Call(MakeLerp, 0, 80, 30, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_h_mon1, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_h_mon2, LVar0, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(20)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 80)
    Sub(LVar2, 80)
    Call(PlayerMoveTo, LVar0, LVar2, 30)
    Wait(10)
    Call(MakeLerp, 80, 0, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_h_mon1, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_h_mon2, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(D_80242DC8_BB9E38) = {
    Call(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    Thread
        Call(MakeLerp, 0, 80, 30, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_h_mon1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_h_mon2, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(20)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -80)
    Sub(LVar2, -80)
    Call(PlayerMoveTo, LVar0, LVar2, 20)
    Call(MakeLerp, 80, 0, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_h_mon1, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_h_mon2, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(D_80242FF4_BBA064) = {
    Call(DisablePlayerInput, true)
    Call(InterruptUsePartner)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_OPENED_BOOS_MANSION_GATE)
            Set(GB_StoryProgress, STORY_CH3_OPENED_BOOS_MANSION_GATE)
            Set(AF_MIM_01, true)
            ExecWait(N(D_80242560_BB95D0))
        CaseGe(STORY_CH3_OPENED_BOOS_MANSION_GATE)
            IfEq(AF_MIM_01, false)
                ExecWait(N(D_80242B90_BB9C00))
                Set(AF_MIM_01, true)
            Else
                ExecWait(N(D_80242DC8_BB9E38))
                Set(AF_MIM_01, false)
            EndIf
    EndSwitch
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(D_802430E0_BBA150) = {
    BindTrigger(Ref(N(D_80242FF4_BBA064)), TRIGGER_WALL_PRESS_A, COLLIDER_mon, 1, 0)
    Return
    End
};
