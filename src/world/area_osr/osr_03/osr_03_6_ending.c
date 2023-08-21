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
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 210, EVT_FLOAT(2.0))
    EVT_CALL(MakeLerp, 200, 50, 65, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, 100)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 4, LVar0)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
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
    EVT_SET(LVar4, 20)
    EVT_SET(LVar5, 110)
    EVT_LOOP(0)
        EVT_USE_BUF(EVT_PTR(N(ExplosionPositions)))
        EVT_LOOP(8)
            EVT_CALL(PlaySoundWithVolume, SOUND_SEQ_FINALE_EXPLOSION, LVar5)
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(6.0), 30)
            EVT_WAIT(LVar4)
        EVT_END_LOOP
        EVT_ADD(LVar5, -10)
        EVT_IF_LT(LVar5, 10)
            EVT_SET(LVar5, 10)
        EVT_END_IF
        EVT_ADD(LVar4, -4)
        EVT_IF_LT(LVar4, 5)
            EVT_SET(LVar4, 5)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_CastleDestruction) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(SetPlayerPos, 0, 0, 0)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_SET(MV_CastleLiftDist, 0)
    EVT_EXEC(N(EVS_AnimateSwingingChains))
    EVT_EXEC(N(EVS_AnimateSpinningRing))
    EVT_EXEC(N(EVS_UpdateCamShaking))
    EVT_EXEC_GET_TID(N(EVS_PlayExplosionFX), LVar9)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 22, 16, 4096)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, TRUE)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -60, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-20.0), EVT_FLOAT(-4.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, -40)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-13.0), EVT_FLOAT(15.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.3))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_LOOP(6)
            EVT_CALL(RandInt, 20, LVar0)
            EVT_ADD(LVar0, 30)
            EVT_WAIT(LVar0)
            EVT_CALL(N(FlashScreenWhite))
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 220, 600, 90, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, LVar0)
        EVT_DIVF(LVar2, 10)
        EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, LVar2, 16, 4096)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 600, 1200, 250, EASING_CUBIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, LVar0)
        EVT_DIVF(LVar2, 10)
        EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, LVar2, 1, 4096)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVar9)
    EVT_WAIT(50)
    EVT_CALL(PlaySound, SOUND_KPA_LIGHT_RAYS)
    EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, 0, -430, 1920, 15, LVar9)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(N(BigExplosionRumble), 30, EVT_FLOAT(2.0))
        EVT_CALL(MakeLerp, 200, 100, 15, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, 100)
            EVT_CALL(N(BigExplosionRumble), 4, LVar0)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GotoMapSpecial, EVT_PTR("hos_10"), hos_10_ENTRY_1, TRANSITION_SLOW_FADE_TO_WHITE)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
