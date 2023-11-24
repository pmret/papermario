#include "kmr_00.h"
#include "effects.h"
#include "model.h"
#include "sprite/player.h"

API_CALLABLE(N(func_80240000_8ABF90)) {
    Bytecode* args;
    static u8 oldPrimR, oldPrimG, oldPrimB;
    static u8 oldEnvR, oldEnvG, oldEnvB;
    static s32 newPrimR, newPrimG, newPrimB;
    static s32 newEnvR, newEnvG, newEnvB;
    static s32 duration, time;

    args = script->ptrReadPos;
    if (isInitialCall) {
        mdl_get_remap_tint_params(&oldPrimR, &oldPrimG, &oldPrimB, &oldEnvR, &oldEnvG, &oldEnvB);
        newPrimR = evt_get_variable(script, *args++);
        newPrimG = evt_get_variable(script, *args++);
        newPrimB = evt_get_variable(script, *args++);
        newEnvR = evt_get_variable(script, *args++);
        newEnvG = evt_get_variable(script, *args++);
        newEnvB = evt_get_variable(script, *args++);
        duration = evt_get_variable(script, *args++);
        time = 0;
    }

    if (duration > 0) {
        time++;
        mdl_set_remap_tint_params(
            (oldPrimR + ((newPrimR - oldPrimR) * time) / duration),
            (oldPrimG + ((newPrimG - oldPrimG) * time) / duration),
            (oldPrimB + ((newPrimB - oldPrimB) * time) / duration),
            (oldEnvR  + ( (newEnvR - oldEnvR)  * time) / duration),
            (oldEnvG  + ( (newEnvG - oldEnvG)  * time) / duration),
            (oldEnvB  + ( (newEnvB - oldEnvB)  * time) / duration));
        if (time >= duration) {
            return ApiStatus_DONE2;
        }
    } else {
        mdl_set_remap_tint_params(newPrimR, newPrimG, newPrimB, newEnvR, newEnvG, newEnvB);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80240388_8AC318)) {
    mdl_set_all_tint_type(ENV_TINT_REMAP);
    *gBackgroundTintModePtr = ENV_TINT_REMAP;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802403B8_8AC348)) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    fx_sparkles(var0, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802404A0_8AC430)) {
    fx_energy_orb_wave(4, 0.0f, 0.0f, 0.0f, 0.3f, 30);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802404E8_8AC478)) {
    s32 pitch = evt_get_variable(script, script->varTable[0]);
    gCameras[CAM_DEFAULT].controlSettings.boomPitch = pitch * 0.001f;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240530_8AC4C0)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Npc* npc = get_npc_unsafe(npcID);

    fx_sparkles(FX_SPARKLES_3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240584_8AC514)) {
    snd_ambient_pause(0, 2000);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802405A8_8AC538)) {
    snd_ambient_resume(0, 2000);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802405CC_8AC55C)) {
    snd_ambient_stop_slow(0, 1000);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802405F0_8AC580)) {
    enum {
        FUNC_STATE_0        = 0,
        FUNC_STATE_1        = 1,
        FUNC_STATE_2        = 2,
        FUNC_STATE_3        = 3
    };

#if VERSION_PAL
#define VAR_1 varTable[11]
#define VAR_2 varTable[12]
#else
#define VAR_1 functionTemp[3]
#define VAR_2 varTable[14]
#endif

    Bytecode* args = script->ptrReadPos;
    ApiStatus retVal = ApiStatus_BLOCK;
    Npc* npc;
    s32 var;

    if (isInitialCall) {
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->varTable[15] = evt_get_variable(script, *args++);
        script->functionTemp[0] = FUNC_STATE_0;
        script->VAR_1 = 0;
#if VERSION_PAL
        script->varTable[13] = 0;
        script->VAR_2 = 0;
        script->varTable[14] = 0;
#endif
    }

    npc = get_npc_unsafe(script->functionTemp[1]);
    switch (script->functionTemp[0]) {
        case FUNC_STATE_0:
            npc->pos.x = 0.0f;
            npc->pos.y = NPC_DISPOSE_POS_Y;
            npc->pos.z = -50.0f;
            npc->moveToPos.x = script->VAR_1 * 3;
            npc->moveToPos.y = 3.0f;
            if (script->VAR_1 >= script->varTable[15]) {
                npc->pos.y = 100.0f;
                add_vec2D_polar(&npc->pos.x, &npc->pos.z, 70.0f / DT, npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f);
                npc->pos.y += (-npc->pos.z + -50.0f + 70.0f / DT) * 0.15f;
                sfx_play_sound_at_position(SOUND_SEQ_STAR_SPIRIT_APPEAR, SOUND_SPACE_DEFAULT, npc->pos.x, npc->pos.y, npc->pos.z);
                fx_sparkles(FX_SPARKLES_0, npc->pos.x, npc->pos.y + 20.0f, npc->pos.z, 20.0f);
                script->functionTemp[0] = FUNC_STATE_1;
            }
            break;
        case FUNC_STATE_1:
            npc->pos.x = 0.0f;
            npc->pos.z = -50.0f;
            npc->pos.y = 100.0f;
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 70.0f / DT, npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f);
            npc->pos.y += (-npc->pos.z + -50.0f + 70.0f / DT) * 0.15f;
            if ((script->VAR_1 + script->functionTemp[2]) % 13 == 0) {
                fx_sparkles(FX_SPARKLES_3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
            }
            if (script->VAR_1 > 256) {
                script->functionTemp[0] = FUNC_STATE_2;
                script->VAR_2 = 0;
            }
            break;
        case FUNC_STATE_2:
            npc->pos.x = 0.0f;
            npc->pos.z = -50.0f;
            npc->pos.y = 100.0f - (script->VAR_2 * 0.3f);
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 70.0f / DT, npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f);
            npc->pos.y += (-npc->pos.z + -50.0f + 70.0f / DT) * 0.15f;
            if ((script->VAR_1 + script->functionTemp[2]) % 13 == 0) {
                fx_sparkles(FX_SPARKLES_3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
            }
            if (script->VAR_2++ > 180) {
                script->functionTemp[0] = FUNC_STATE_3;
                script->VAR_2 = 0;
            }

#if VERSION_PAL
            script->varTable[14] += 0x10000;
            script->VAR_2 = script->varTable[14] >> 16;
#endif
            break;
        case FUNC_STATE_3:
            npc->moveToPos.y -= 0.03f;
            npc->pos.x = 0.0f;
            npc->pos.z = -50.0f;
            npc->pos.y = 45.999996f;
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 70.0f / DT, npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f);
            npc->pos.y += (-npc->pos.z + -50.0f + 70.0f / DT) * 0.15f;
            if ((script->VAR_1 + script->functionTemp[2]) % 13 == 0) {
                fx_sparkles(FX_SPARKLES_3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
            }
            if (npc->moveToPos.y < 0.0f) {
#if VERSION_PAL
                var = evt_get_variable(NULL, MV_Unk_02);
                evt_set_variable(NULL, MV_Unk_02, var + 1);
#endif
                retVal = ApiStatus_DONE2;
            }
            break;
    }

#if VERSION_PAL
    script->varTable[13] += 0x10000;
    script->varTable[11] = script->varTable[13] >> 16;
#else
    script->functionTemp[3]++;
#endif

    npc->moveToPos.x += npc->moveToPos.y;
    return retVal;
}

API_CALLABLE(N(func_80240BD8_8ACB68)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = evt_get_variable(script, *args);
        npc = get_npc_unsafe(script->functionTemp[1]);
        sfx_play_sound_at_position(SOUND_SEQ_STAR_SPIRIT_APPEAR, SOUND_SPACE_DEFAULT, npc->pos.x, npc->pos.y, npc->pos.z);
        fx_sparkles(FX_SPARKLES_0, npc->pos.x, npc->pos.y + 20.0f, npc->pos.z, 10.0f);
        script->functionTemp[0] = 3;
    }

    npc = get_npc_unsafe(script->functionTemp[1]);
    script->functionTemp[0]--;
    if (script->functionTemp[0] == -1) {
        npc->pos.y = NPC_DISPOSE_POS_Y;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#if VERSION_PAL
API_CALLABLE(N(func_PAL_80240D08)) {
    if (evt_get_variable(NULL, MV_Unk_02) == 7) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#endif

EvtScript N(EVS_Scene_MarioRevived) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_WAKE_UP)
        EVT_CALL(EnableModel, MODEL_reef_1, FALSE)
        EVT_CALL(EnableModel, MODEL_reef_2, FALSE)
        EVT_CALL(EnableModel, MODEL_reef_3, FALSE)
        EVT_CALL(EnableModel, MODEL_reef_4, FALSE)
        EVT_CALL(EnableModel, MODEL_moku1, FALSE)
        EVT_CALL(EnableModel, MODEL_moku2, FALSE)
        EVT_CALL(EnableModel, MODEL_ha1, FALSE)
        EVT_CALL(EnableModel, MODEL_ha2, FALSE)
        EVT_CALL(EnableModel, MODEL_ha2_1, FALSE)
        EVT_CALL(EnableModel, MODEL_ha2_2, FALSE)
        EVT_CALL(EnableModel, MODEL_ha2_3, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_SETF(MV_Unk_01, EVT_FLOAT(0.0))
    EVT_CALL(N(func_80240388_8AC318))
    EVT_CALL(N(func_80240000_8ABF90), 255, 255, 255, 60, 60, 60, 0)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(PlayAmbientSounds, AMBIENT_BIRDS)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(6.0), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -540)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 15, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(func_802D4D14, 180)
    EVT_CALL(SetPlayerPos, 0, 2, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Fallen)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.7 / DT))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -350)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_SETF(LVar0, 0)
        EVT_SETF(LVar1, 0)
        EVT_LOOP(90 * DT)
            EVT_CALL(TranslateModel, MODEL_reef_3, LVar0, 0, 0)
            EVT_CALL(TranslateModel, MODEL_reef_4, LVar1, 0, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(-0.66 / DT))
#if VERSION_PAL
            EVT_ADDF(LVar1, EVT_FLOAT(0.79296875)) // 0.66 / DT rounds slightly off
#else
            EVT_ADDF(LVar1, EVT_FLOAT(0.66 / DT))
#endif
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_SETF(LVar0, 0)
        EVT_SETF(LVar1, 0)
        EVT_LOOP(120 * DT)
            EVT_CALL(TranslateModel, MODEL_reef_1, LVar0, 0, 0)
            EVT_CALL(TranslateModel, MODEL_reef_2, LVar1, 0, 0)
            EVT_CALL(TranslateModel, MODEL_moku2, LVar1, 0, 0)
            EVT_CALL(TranslateModel, MODEL_ha2_1, LVar1, 0, 0)
            EVT_CALL(TranslateModel, MODEL_ha2_2, LVar1, 0, 0)
            EVT_CALL(TranslateModel, MODEL_ha2_3, LVar1, 0, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(-0.75 / DT))
            EVT_ADDF(LVar1, EVT_FLOAT(0.75 / DT))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_SETF(LVar0, 0)
        EVT_SETF(LVar1, 0)
        EVT_LOOP(120 * DT)
            EVT_CALL(TranslateModel, MODEL_moku1, LVar0, 0, 0)
            EVT_CALL(TranslateModel, MODEL_ha1, LVar0, 0, 0)
            EVT_CALL(TranslateModel, MODEL_ha2, LVar0, 0, 0)
            EVT_CALL(RotateModel, MODEL_moku1, LVar1, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_ha1, LVar1, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_ha2, LVar1, 0, 1, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(-0.2 / DT))
            EVT_ADDF(LVar1, EVT_FLOAT(-0.4 / DT))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(140 * DT)
    EVT_CALL(N(func_80240584_8AC514))
    EVT_WAIT(30 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 0, 8)
    EVT_THREAD
        EVT_CALL(N(func_80240000_8ABF90), 50, 50, 50, 0, 0, 0, 50 * DT)
    EVT_END_THREAD
    EVT_WAIT(90 * DT)
    EVT_CALL(func_802D4D88)
#if VERSION_PAL
    EVT_SET(MV_Unk_02, 0)
#endif
    EVT_THREAD
        EVT_CALL(N(func_802405F0_8AC580), 1, 0, 180)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802405F0_8AC580), 2, 1, 30)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802405F0_8AC580), 3, 2, 90)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802405F0_8AC580), 4, 3, 150)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802405F0_8AC580), 5, 4, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802405F0_8AC580), 6, 5, 60)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802405F0_8AC580), 7, 6, 120)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(330 * DT)
        EVT_CALL(MakeLerp, 6000, 12000, 120 * DT, EASING_LINEAR)
        EVT_LABEL(25)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(func_802404E8_8AC478))
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(25)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(550 * DT)
#if VERSION_PAL
    EVT_WAIT(15 * DT)
    EVT_CALL(N(func_PAL_80240D08))
#endif
    EVT_CALL(GetNpcPos, NPC_Kalmar, LVar6, LVar7, LVar8)
    EVT_CALL(GetNpcPos, NPC_Mamar, LVar9, LVarA, LVarB)
#if !VERSION_PAL
    EVT_WAIT(15)
#endif
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -200)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_LeanLeft)
        EVT_CALL(NpcFlyTo, NPC_Kalmar, 20, 10, -5, 25 * DT, -10, EASING_QUADRATIC_OUT)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_LeanLeftAlt)
        EVT_WAIT(35 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_LeanRight)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(3)
            EVT_CALL(N(func_80240530_8AC4C0), NPC_Kalmar)
            EVT_WAIT(6 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(N(func_80240530_8AC4C0), NPC_Mamar)
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_LeanLeft)
        EVT_CALL(NpcFlyTo, NPC_Mamar, -20, 10, -5, 25 * DT, -10, EASING_QUADRATIC_OUT)
        EVT_WAIT(5 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_LeanLeftAlt)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_LeanRight)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(3)
            EVT_CALL(N(func_80240530_8AC4C0), NPC_Mamar)
            EVT_WAIT(6 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(35 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, 5, MSG_CH0_0000)
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kalmar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, 5, MSG_CH0_0001)
    EVT_WAIT(3)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_LeanLeftAlt)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_LeanRight)
        EVT_WAIT(10 * DT)
        EVT_CALL(NpcFlyTo, NPC_Kalmar, LVar6, LVar7, LVar8, 15 * DT, -10, EASING_CUBIC_OUT)
        EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(40 * DT)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, -350)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_LOOP(3)
            EVT_CALL(N(func_80240530_8AC4C0), NPC_Kalmar)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_LeanLeftAlt)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_LeanRight)
        EVT_WAIT(10 * DT)
        EVT_CALL(NpcFlyTo, NPC_Mamar, LVar9, LVarA, LVarB, 15 * DT, -10, EASING_CUBIC_OUT)
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(40 * DT)
        EVT_LOOP(3)
            EVT_CALL(N(func_80240530_8AC4C0), NPC_Mamar)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(90 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Wave, 5, MSG_CH0_0002)
    EVT_WAIT(15 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Leap)
        EVT_CALL(SetNpcJumpscale, NPC_Eldstar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Eldstar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Eldstar, LVar6, LVar7, LVar8, 5 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Idle)
        EVT_CALL(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
        EVT_CALL(N(func_802403B8_8AC348), 0, 0, 0, 3, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Leap)
        EVT_CALL(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Mamar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Mamar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Mamar, LVar6, LVar7, LVar8, 5 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(21)
        EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Leap)
        EVT_CALL(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Skolar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Skolar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Skolar, LVar6, LVar7, LVar8, 5 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(22)
        EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Leap)
        EVT_CALL(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Muskular, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Muskular, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Muskular, LVar6, LVar7, LVar8, 5 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Leap)
        EVT_CALL(SetNpcFlagBits, NPC_Misstar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Misstar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Misstar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Misstar, LVar6, LVar7, LVar8, 5 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(21)
        EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Leap)
        EVT_CALL(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Klevar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Klevar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Klevar, LVar6, LVar7, LVar8, 5 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(22)
        EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Leap)
        EVT_CALL(SetNpcFlagBits, NPC_Kalmar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcJumpscale, NPC_Kalmar, EVT_FLOAT(3.2))
        EVT_CALL(GetNpcPos, NPC_Kalmar, LVar6, LVar7, LVar8)
        EVT_CALL(NpcJump0, NPC_Kalmar, LVar6, LVar7, LVar8, 5 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Idle)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_WAIT(45 * DT)
        EVT_CALL(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
        EVT_CALL(N(func_802404A0_8AC430))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(func_802403B8_8AC348), 0, 10, 10, 3, 10)
    EVT_WAIT(6 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(func_802403B8_8AC348), 0, 0, 10, 3, 15)
    EVT_WAIT(6 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(func_802403B8_8AC348), 0, -10, 10, 3, 20)
    EVT_WAIT(6 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(func_802403B8_8AC348), 0, 10, 10, 3, 25)
    EVT_WAIT(6 * DT)
    EVT_LOOP(3)
        EVT_CALL(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
        EVT_CALL(N(func_802403B8_8AC348), 0, 0, 10, 3, 30)
        EVT_WAIT(6 * DT)
        EVT_CALL(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
        EVT_CALL(N(func_802403B8_8AC348), 0, -10, 10, 3, 30)
        EVT_WAIT(6 * DT)
        EVT_CALL(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
        EVT_CALL(N(func_802403B8_8AC348), 0, 10, 10, 3, 30)
        EVT_WAIT(6 * DT)
    EVT_END_LOOP
    EVT_WAIT(40 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Wave, 5, MSG_CH0_0003)
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(N(func_80240BD8_8ACB68), NPC_Misstar)
        EVT_WAIT(2)
        EVT_CALL(N(func_80240BD8_8ACB68), NPC_Mamar)
        EVT_WAIT(2)
        EVT_CALL(N(func_80240BD8_8ACB68), NPC_Klevar)
        EVT_WAIT(2)
        EVT_CALL(N(func_80240BD8_8ACB68), NPC_Skolar)
        EVT_WAIT(2)
        EVT_CALL(N(func_80240BD8_8ACB68), NPC_Kalmar)
        EVT_WAIT(2)
        EVT_CALL(N(func_80240BD8_8ACB68), NPC_Muskular)
        EVT_WAIT(2)
        EVT_CALL(N(func_80240BD8_8ACB68), NPC_Eldstar)
    EVT_END_THREAD
    EVT_CALL(FadeOutMusic, 0, 5000 * DT)
    EVT_THREAD
        EVT_WAIT(90 * DT)
        EVT_CALL(N(func_802405A8_8AC538))
    EVT_END_THREAD
    EVT_WAIT(60 * DT)
    EVT_CALL(N(func_80240000_8ABF90), 255, 255, 255, 0, 0, 0, 50 * DT)
    EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Goombaria, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Walk)
    EVT_CALL(SetNpcPos, NPC_Goombaria, 300, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 110, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Stand)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, 90, 1)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, 270, 1)
    EVT_WAIT(15 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, 90, 1)
    EVT_WAIT(18 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, 270, 1)
    EVT_WAIT(10 * DT)
    EVT_WAIT(6 * DT)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -12)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(GetNpcPos, NPC_Goombaria, LVar3, LVar4, LVar5)
    EVT_ADD(LVar3, -20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_WAIT(25 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LeanOver)
    EVT_CALL(PlaySoundAtNpc, NPC_Goombaria, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Goombaria, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(25 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Stand)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Stand, 5, MSG_CH0_0004)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 1)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 30, -10, 0)
    EVT_WAIT(2)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Inspect)
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Inspect, ANIM_Goombaria_Inspect, 5, MSG_CH0_0005)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Talk)
    EVT_CALL(NpcJump0, NPC_Goombaria, 30, 0, -10, 4)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LeanOver)
    EVT_CALL(NpcJump0, NPC_Goombaria, 30, 0, -10, 4)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Stand, 5, MSG_CH0_0006)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(6.0))
    EVT_CALL(NpcMoveTo, NPC_Goombaria, -30, -5, 0)
    EVT_CALL(NpcFacePlayer, NPC_Goombaria, 5)
    EVT_CALL(SetNpcJumpscale, NPC_Goombaria, EVT_FLOAT(4.0))
    EVT_CALL(NpcJump0, NPC_Goombaria, -29, 0, 5, 4)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(6.0))
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 34, 5, 0)
    EVT_CALL(NpcFacePlayer, NPC_Goombaria, 5)
    EVT_CALL(SetNpcJumpscale, NPC_Goombaria, EVT_FLOAT(4.0))
    EVT_CALL(NpcJump0, NPC_Goombaria, 33, 0, 5, 4)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(6.0))
    EVT_CALL(NpcMoveTo, NPC_Goombaria, -30, 5, 0)
    EVT_CALL(NpcFacePlayer, NPC_Goombaria, 5)
    EVT_CALL(SetNpcJumpscale, NPC_Goombaria, EVT_FLOAT(4.0))
    EVT_CALL(NpcJump0, NPC_Goombaria, -29, 0, 5, 4)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(6.0))
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 34, 5, 0)
    EVT_CALL(NpcFacePlayer, NPC_Goombaria, 5)
    EVT_CALL(SetNpcJumpscale, NPC_Goombaria, EVT_FLOAT(4.0))
    EVT_CALL(NpcJump0, NPC_Goombaria, 33, 0, 5, 4)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Stand, 5, MSG_CH0_0007)
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(4.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Goombaria, 450, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Stand, 5, MSG_CH0_0008)
    EVT_WAIT(30 * DT)
    EVT_SET(GB_StoryProgress, STORY_CH0_WAKE_UP)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(N(func_802405CC_8AC55C))
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_02"), kmr_02_ENTRY_5, TRANSITION_MARIO_BLACK)
    EVT_RETURN
    EVT_END
};
