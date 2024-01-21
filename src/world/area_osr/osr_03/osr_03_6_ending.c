#include "osr_03.h"
#include "effects.h"

API_CALLABLE(N(FlashScreenWhite)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
        script->functionTemp[2] = 0;
    }
    switch (script->functionTemp[2]) {
        case 0: // fading in
            set_screen_overlay_color(SCREEN_LAYER_FRONT, 208, 208, 208);
            set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, script->functionTemp[1]);
            if (script->functionTemp[1] == 255) {
                script->functionTemp[2] = 1;
                break;
            }
            script->functionTemp[1] += 64;
            if (script->functionTemp[1] < 256) {
                break;
            }
            script->functionTemp[1] = 255;
            break;
        case 1: // fading out
            set_screen_overlay_color(SCREEN_LAYER_FRONT, 208, 208, 208);
            set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, script->functionTemp[1]);
            if (script->functionTemp[1] == 0) {
                return ApiStatus_DONE2;
            }
            script->functionTemp[1] -= 64;
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[1] = 0;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(BigExplosionRumble)) {
    Bytecode* args = script->ptrReadPos;
    f32 frequency;
    s32 duration;

    if (isInitialCall) {
        duration = evt_get_variable(script, *args++);
        frequency = 2.0f * evt_get_float_variable(script, *args++);
        script->functionTemp[0] = duration;
        if (frequency > 10.0f) {
            frequency = 10.0f;
        }

        start_rumble((u8) ((frequency / 10.0f) * 256.0f), (duration & 0xFFFF) * 2);
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0)
    {
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_UpdateCamShaking) = {
    Call(ShakeCam, CAM_DEFAULT, 0, 210, Float(2.0))
    Call(MakeLerp, 200, 50, 65, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        DivF(LVar0, 100)
        Call(ShakeCam, CAM_DEFAULT, 0, 4, LVar0)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

s32 N(ExplosionPositions)[] = {
    -520,  -280,  270,
     230,  -150,  300,
    -500,  -200,  190,
    -420,  -230, -170,
    -400,  -400,  450,
       0,  -720,  620,
    -270,  -700,  470,
     320,  -460,  530,
};

EvtScript N(EVS_PlayExplosionFX) = {
    Set(LVar4, 20)
    Set(LVar5, 110)
    Loop(0)
        UseBuf(Ref(N(ExplosionPositions)))
        Loop(8)
            Call(PlaySoundWithVolume, SOUND_SEQ_FINALE_EXPLOSION, LVar5)
            BufRead3(LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_RING_BLAST, 0, LVar0, LVar1, LVar2, Float(6.0), 30)
            Wait(LVar4)
        EndLoop
        Add(LVar5, -10)
        IfLt(LVar5, 10)
            Set(LVar5, 10)
        EndIf
        Add(LVar4, -4)
        IfLt(LVar4, 5)
            Set(LVar4, 5)
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_CastleDestruction) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(SetPlayerPos, 0, 0, 0)
    Call(DisablePlayerPhysics, TRUE)
    Set(MV_CastleLiftDist, 0)
    Exec(N(EVS_AnimateSwingingChains))
    Exec(N(EVS_AnimateSpinningRing))
    Exec(N(EVS_UpdateCamShaking))
    ExecGetTID(N(EVS_PlayExplosionFX), LVar9)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 22, 16, 4096)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamType, CAM_DEFAULT, 1, TRUE)
    Call(SetPanTarget, CAM_DEFAULT, -60, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(-20.0), Float(-4.0))
    Call(SetCamPosA, CAM_DEFAULT, 0, -40)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(20)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(-13.0), Float(15.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.3))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Loop(6)
            Call(RandInt, 20, LVar0)
            Add(LVar0, 30)
            Wait(LVar0)
            Call(N(FlashScreenWhite))
        EndLoop
    EndThread
    Call(MakeLerp, 220, 600, 90, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar2, LVar0)
        DivF(LVar2, 10)
        Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, LVar2, 16, 4096)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, 600, 1200, 250, EASING_CUBIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar2, LVar0)
        DivF(LVar2, 10)
        Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, LVar2, 1, 4096)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVar9)
    Wait(50)
    Call(PlaySound, SOUND_KPA_LIGHT_RAYS)
    PlayEffect(EFFECT_LIGHT_RAYS, 2, 0, -430, 1920, 15, LVar9)
    Wait(30)
    Thread
        Call(N(BigExplosionRumble), 30, Float(2.0))
        Call(MakeLerp, 200, 100, 15, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, 100)
            Call(N(BigExplosionRumble), 4, LVar0)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(GotoMapSpecial, Ref("hos_10"), hos_10_ENTRY_1, TRANSITION_SLOW_FADE_TO_WHITE)
    Wait(100)
    Return
    End
};
