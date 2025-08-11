#include "isk_07.h"
#include "sprite/player.h"

extern EvtScript N(EVS_OpenSarcophagus1);
extern EvtScript N(EVS_OpenSarcophagus2);
extern EvtScript N(EVS_OpenSarcophagus3);

EvtScript N(EVS_SetupSarcophagi) = {
    IfEq(GF_ISK07_OpenedSarcophagi, false)
        Set(AF_ISK07_OpeningSarcophagus1, false)
        Set(AF_ISK07_OpeningSarcophagus2, false)
        Set(AF_ISK07_OpeningSarcophagus3, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2039, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2040, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2041, COLLIDER_FLAGS_UPPER_MASK)
        Label(10)
            IfEq(GF_ISK07_OpenedSarcophagi, false)
                Wait(1)
                Goto(10)
            EndIf
        Call(PlaySound, SOUND_CHIME_BEGIN_AMBUSH)
        Call(DisablePlayerInput, true)
        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(1.0))
        Call(SetNpcYaw, NPC_Pokey_01, 105)
        Call(SetNpcFlagBits, NPC_Pokey_01, NPC_FLAG_INVISIBLE, false)
        Call(SetNpcFlagBits, NPC_Pokey_02, NPC_FLAG_INVISIBLE, false)
        Call(SetNpcFlagBits, NPC_Pokey_03, NPC_FLAG_INVISIBLE, false)
        Thread
            Wait(12)
            Call(InterpPlayerYaw, 109, 0)
            Wait(3)
            Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_SHOCK, 1, 1, 0)
            Call(SetPlayerAnimation, ANIM_MarioW2_Shocked)
            Wait(20)
            Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
        Call(UseSettingsFrom, CAM_DEFAULT, -151, -390, 576)
        Call(SetPanTarget, CAM_DEFAULT, -151, -390, 576)
        Wait(1)
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Exec(N(EVS_OpenSarcophagus1))
        Wait(15)
        Call(SetPanTarget, CAM_DEFAULT, 51, -390, 589)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Exec(N(EVS_OpenSarcophagus2))
        Wait(15)
        Call(SetPanTarget, CAM_DEFAULT, 239, -390, 515)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Exec(N(EVS_OpenSarcophagus3))
        Wait(15)
        Call(SetPanTarget, CAM_DEFAULT, 517, -390, 292)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Exec(N(EVS_ShutEntryDoor))
        Wait(30)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Call(PanToTarget, CAM_DEFAULT, 0, false)
        Set(AF_ISK07_MummiesReleased, true)
        Call(DisablePlayerInput, false)
    Else
        Set(AF_ISK07_OpeningSarcophagus1, true)
        Set(AF_ISK07_OpeningSarcophagus2, true)
        Set(AF_ISK07_OpeningSarcophagus3, true)
        Call(TranslateModel, MODEL_g323, 38, 0, 13)
        Call(RotateModel, MODEL_g323, 35, 0, 1, 0)
        Call(TranslateModel, MODEL_g327, 38, 0, 13)
        Call(RotateModel, MODEL_g327, 35, 0, 1, 0)
        Call(TranslateModel, MODEL_g331, 38, 0, 13)
        Call(RotateModel, MODEL_g331, 35, 0, 1, 0)
        Wait(5)
        Set(AF_ISK07_OpeningSarcophagus1, false)
        Set(AF_ISK07_OpeningSarcophagus2, false)
        Set(AF_ISK07_OpeningSarcophagus3, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2036, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2037, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2038, COLLIDER_FLAGS_UPPER_MASK)
        Set(AF_ISK07_MummiesReleased, true)
    EndIf
    Return
    End
};

EvtScript N(EVS_OpenSarcophagusAnim) = {
    Call(PlaySoundAtModel, LVar3, SOUND_SARCOPHAGUS_OPEN, SOUND_SPACE_DEFAULT)
    Call(TranslateModel, LVar3, 0, 0, 13)
    Wait(3)
    Call(MakeLerp, 0, 35, 9, EASING_COS_IN_OUT)
    Label(10)
        Call(UpdateLerp)
        Set(LVar2, LVar0)
        MulF(LVar2, Float(1.1))
        Call(TranslateModel, LVar3, LVar2, 0, 13)
        Call(RotateModel, LVar3, LVar0, 0, 1, 0)
        Wait(1)
        IfNe(LVar1, 0)
            Goto(10)
        EndIf
    Wait(3)
    Return
    End
};

EvtScript N(EVS_OpenSarcophagus1) = {
    Set(AF_ISK07_OpeningSarcophagus1, true)
    Set(LVar3, MODEL_g323)
    ExecWait(N(EVS_OpenSarcophagusAnim))
    Set(AF_ISK07_OpeningSarcophagus1, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2036, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2039, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_OpenSarcophagus2) = {
    Set(AF_ISK07_OpeningSarcophagus2, true)
    Set(LVar3, MODEL_g327)
    ExecWait(N(EVS_OpenSarcophagusAnim))
    Set(AF_ISK07_OpeningSarcophagus2, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2037, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2040, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_OpenSarcophagus3) = {
    Set(AF_ISK07_OpeningSarcophagus3, true)
    Set(LVar3, MODEL_g331)
    ExecWait(N(EVS_OpenSarcophagusAnim))
    Set(AF_ISK07_OpeningSarcophagus3, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2038, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2041, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};
