#include "flo_15.h"
#include "effects.h"

s32 N(ShakeCamParams)[] = {
    10, Float(0.6),
    13, Float(0.75),
    16, Float(0.9),
    19, Float(1.05),
    22, Float(1.2),
    25, Float(1.05),
    24, Float(0.9),
#if VERSION_JP
    22, Float(0.75),
    20, Float(0.6),
    10, Float(1.5),
#else
    25, Float(0.75),
    24, Float(0.6),
    10, Float(1.7),
#endif
};

EvtScript N(EVS_MonitorFallingStairs) = {
    IfEq(GF_FLO15_BombedRock, false)
        Label(0)
        IfEq(GF_FLO15_BombedRock, false)
            Wait(1)
            Goto(0)
        EndIf
        Call(DisablePlayerInput, true)
        Thread
            UseBuf(Ref(N(ShakeCamParams)))
            Loop(10)
                BufRead2(LVar1, LVar2)
                Call(ShakeCam, CAM_DEFAULT, 0, LVar1, LVar2)
            EndLoop
        EndThread
        Call(UseSettingsFrom, CAM_DEFAULT, -170, 0, 35)
        Call(SetPanTarget, CAM_DEFAULT, -170, 0, 35)
        Call(SetCamDistance, CAM_DEFAULT, 600)
        Call(SetCamPitch, CAM_DEFAULT, Float(25.0), Float(-9.0))
        Call(SetCamPosA, CAM_DEFAULT, Float(-50.0), Float(25.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.5))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Thread
            Wait(100)
            PlayEffect(EFFECT_LANDING_DUST, 4, -180, 0, -15, 0)
            PlayEffect(EFFECT_LANDING_DUST, 4, -190, 0, -35, 0)
        EndThread
        Thread
            Loop(6)
                Call(PlaySoundAtCollider, COLLIDER_o175, SOUND_FLO_STAIRS_LOWERING, SOUND_SPACE_DEFAULT)
                Wait(20)
            EndLoop
        EndThread
        Call(MakeLerp, 0, -50, 120, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g20, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g54, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g58, COLLIDER_FLAGS_UPPER_MASK)
        Wait(15)
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Call(DisablePlayerInput, false)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g54, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g58, COLLIDER_FLAGS_UPPER_MASK)
        Call(TranslateGroup, MODEL_g20, 0, -50, 0)
    EndIf
    Return
    End
};
