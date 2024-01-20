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
    IfGe(GB_StoryProgress, STORY_CH0_WAKE_UP)
        Call(EnableModel, MODEL_reef_1, FALSE)
        Call(EnableModel, MODEL_reef_2, FALSE)
        Call(EnableModel, MODEL_reef_3, FALSE)
        Call(EnableModel, MODEL_reef_4, FALSE)
        Call(EnableModel, MODEL_moku1, FALSE)
        Call(EnableModel, MODEL_moku2, FALSE)
        Call(EnableModel, MODEL_ha1, FALSE)
        Call(EnableModel, MODEL_ha2, FALSE)
        Call(EnableModel, MODEL_ha2_1, FALSE)
        Call(EnableModel, MODEL_ha2_2, FALSE)
        Call(EnableModel, MODEL_ha2_3, FALSE)
        Return
    EndIf
    SetF(MV_Unk_01, Float(0.0))
    Call(N(func_80240388_8AC318))
    Call(N(func_80240000_8ABF90), 255, 255, 255, 60, 60, 60, 0)
    Call(FadeOutMusic, 0, 500)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    Call(InterpPlayerYaw, 90, 0)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(PlayAmbientSounds, AMBIENT_BIRDS)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(6.0), Float(-7.5))
    Call(SetCamDistance, CAM_DEFAULT, -540)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetPanTarget, CAM_DEFAULT, 0, 15, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(func_802D4D14, 180)
    Call(SetPlayerPos, 0, 2, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_Fallen)
    Wait(60 * DT)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.7 / DT))
    Call(SetCamDistance, CAM_DEFAULT, -350)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Wait(2)
        SetF(LVar0, 0)
        SetF(LVar1, 0)
        Loop(90 * DT)
            Call(TranslateModel, MODEL_reef_3, LVar0, 0, 0)
            Call(TranslateModel, MODEL_reef_4, LVar1, 0, 0)
            AddF(LVar0, Float(-0.66 / DT))
#if VERSION_PAL
            AddF(LVar1, Float(0.79296875)) // 0.66 / DT rounds slightly off
#else
            AddF(LVar1, Float(0.66 / DT))
#endif
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(20 * DT)
        SetF(LVar0, 0)
        SetF(LVar1, 0)
        Loop(120 * DT)
            Call(TranslateModel, MODEL_reef_1, LVar0, 0, 0)
            Call(TranslateModel, MODEL_reef_2, LVar1, 0, 0)
            Call(TranslateModel, MODEL_moku2, LVar1, 0, 0)
            Call(TranslateModel, MODEL_ha2_1, LVar1, 0, 0)
            Call(TranslateModel, MODEL_ha2_2, LVar1, 0, 0)
            Call(TranslateModel, MODEL_ha2_3, LVar1, 0, 0)
            AddF(LVar0, Float(-0.75 / DT))
            AddF(LVar1, Float(0.75 / DT))
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(10 * DT)
        SetF(LVar0, 0)
        SetF(LVar1, 0)
        Loop(120 * DT)
            Call(TranslateModel, MODEL_moku1, LVar0, 0, 0)
            Call(TranslateModel, MODEL_ha1, LVar0, 0, 0)
            Call(TranslateModel, MODEL_ha2, LVar0, 0, 0)
            Call(RotateModel, MODEL_moku1, LVar1, 0, 1, 0)
            Call(RotateModel, MODEL_ha1, LVar1, 0, 1, 0)
            Call(RotateModel, MODEL_ha2, LVar1, 0, 1, 0)
            AddF(LVar0, Float(-0.2 / DT))
            AddF(LVar1, Float(-0.4 / DT))
            Wait(1)
        EndLoop
    EndThread
    Wait(140 * DT)
    Call(N(func_80240584_8AC514))
    Wait(30 * DT)
    Call(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 0, 8)
    Thread
        Call(N(func_80240000_8ABF90), 50, 50, 50, 0, 0, 0, 50 * DT)
    EndThread
    Wait(90 * DT)
    Call(func_802D4D88)
#if VERSION_PAL
    Set(MV_Unk_02, 0)
#endif
    Thread
        Call(N(func_802405F0_8AC580), 1, 0, 180)
    EndThread
    Thread
        Call(N(func_802405F0_8AC580), 2, 1, 30)
    EndThread
    Thread
        Call(N(func_802405F0_8AC580), 3, 2, 90)
    EndThread
    Thread
        Call(N(func_802405F0_8AC580), 4, 3, 150)
    EndThread
    Thread
        Call(N(func_802405F0_8AC580), 5, 4, 0)
    EndThread
    Thread
        Call(N(func_802405F0_8AC580), 6, 5, 60)
    EndThread
    Thread
        Call(N(func_802405F0_8AC580), 7, 6, 120)
    EndThread
    Thread
        Wait(330 * DT)
        Call(MakeLerp, 6000, 12000, 120 * DT, EASING_LINEAR)
        Label(25)
        Call(UpdateLerp)
        Call(N(func_802404E8_8AC478))
        Wait(1)
        IfNe(LVar1, 0)
            Goto(25)
        EndIf
    EndThread
    Wait(550 * DT)
#if VERSION_PAL
    Wait(15 * DT)
    Call(N(func_PAL_80240D08))
#endif
    Call(GetNpcPos, NPC_Kalmar, LVar6, LVar7, LVar8)
    Call(GetNpcPos, NPC_Mamar, LVar9, LVarA, LVarB)
#if !VERSION_PAL
    Wait(15)
#endif
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(SetCamDistance, CAM_DEFAULT, -200)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_LeanLeft)
        Call(NpcFlyTo, NPC_Kalmar, 20, 10, -5, 25 * DT, -10, EASING_QUADRATIC_OUT)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_LeanLeftAlt)
        Wait(35 * DT)
        Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_LeanRight)
    EndThread
    Thread
        Loop(3)
            Call(N(func_80240530_8AC4C0), NPC_Kalmar)
            Wait(6 * DT)
        EndLoop
    EndThread
    Wait(10 * DT)
    Thread
        Call(N(func_80240530_8AC4C0), NPC_Mamar)
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_LeanLeft)
        Call(NpcFlyTo, NPC_Mamar, -20, 10, -5, 25 * DT, -10, EASING_QUADRATIC_OUT)
        Wait(5 * DT)
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_LeanLeftAlt)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_LeanRight)
    EndThread
    Thread
        Loop(3)
            Call(N(func_80240530_8AC4C0), NPC_Mamar)
            Wait(6 * DT)
        EndLoop
    EndThread
    Wait(35 * DT)
    Call(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, 5, MSG_CH0_0000)
    Wait(15 * DT)
    Call(SpeakToPlayer, NPC_Kalmar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, 5, MSG_CH0_0001)
    Wait(3)
    Thread
        Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_LeanLeftAlt)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_LeanRight)
        Wait(10 * DT)
        Call(NpcFlyTo, NPC_Kalmar, LVar6, LVar7, LVar8, 15 * DT, -10, EASING_CUBIC_OUT)
        Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Idle)
    EndThread
    Thread
        Wait(40 * DT)
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
        Call(SetCamDistance, CAM_DEFAULT, -350)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Loop(3)
            Call(N(func_80240530_8AC4C0), NPC_Kalmar)
            Wait(4)
        EndLoop
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_LeanLeftAlt)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_LeanRight)
        Wait(10 * DT)
        Call(NpcFlyTo, NPC_Mamar, LVar9, LVarA, LVarB, 15 * DT, -10, EASING_CUBIC_OUT)
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Idle)
    EndThread
    Thread
        Wait(40 * DT)
        Loop(3)
            Call(N(func_80240530_8AC4C0), NPC_Mamar)
            Wait(4)
        EndLoop
    EndThread
    Wait(90 * DT)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Wave, 5, MSG_CH0_0002)
    Wait(15 * DT)
    Thread
        Call(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Leap)
        Call(SetNpcJumpscale, NPC_Eldstar, Float(3.2))
        Call(GetNpcPos, NPC_Eldstar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Eldstar, LVar6, LVar7, LVar8, 5 * DT)
        Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Idle)
        Call(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
        Call(N(func_802403B8_8AC348), 0, 0, 0, 3, 10)
    EndThread
    Thread
        Wait(20)
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Leap)
        Call(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Mamar, Float(3.2))
        Call(GetNpcPos, NPC_Mamar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Mamar, LVar6, LVar7, LVar8, 5 * DT)
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Idle)
    EndThread
    Thread
        Wait(21)
        Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Leap)
        Call(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Skolar, Float(3.2))
        Call(GetNpcPos, NPC_Skolar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Skolar, LVar6, LVar7, LVar8, 5 * DT)
        Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Idle)
    EndThread
    Thread
        Wait(22)
        Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Leap)
        Call(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Muskular, Float(3.2))
        Call(GetNpcPos, NPC_Muskular, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Muskular, LVar6, LVar7, LVar8, 5 * DT)
        Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Idle)
    EndThread
    Thread
        Wait(20)
        Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Leap)
        Call(SetNpcFlagBits, NPC_Misstar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Misstar, Float(3.2))
        Call(GetNpcPos, NPC_Misstar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Misstar, LVar6, LVar7, LVar8, 5 * DT)
        Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Idle)
    EndThread
    Thread
        Wait(21)
        Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Leap)
        Call(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Klevar, Float(3.2))
        Call(GetNpcPos, NPC_Klevar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Klevar, LVar6, LVar7, LVar8, 5 * DT)
        Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Idle)
    EndThread
    Thread
        Wait(22)
        Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Leap)
        Call(SetNpcFlagBits, NPC_Kalmar, NPC_FLAG_TOUCHES_GROUND, FALSE)
        Call(SetNpcJumpscale, NPC_Kalmar, Float(3.2))
        Call(GetNpcPos, NPC_Kalmar, LVar6, LVar7, LVar8)
        Call(NpcJump0, NPC_Kalmar, LVar6, LVar7, LVar8, 5 * DT)
        Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Idle)
    EndThread
    Wait(30 * DT)
    Thread
        Wait(45 * DT)
        Call(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
        Call(N(func_802404A0_8AC430))
    EndThread
    Call(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
    Call(N(func_802403B8_8AC348), 0, 10, 10, 3, 10)
    Wait(6 * DT)
    Call(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
    Call(N(func_802403B8_8AC348), 0, 0, 10, 3, 15)
    Wait(6 * DT)
    Call(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
    Call(N(func_802403B8_8AC348), 0, -10, 10, 3, 20)
    Wait(6 * DT)
    Call(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
    Call(N(func_802403B8_8AC348), 0, 10, 10, 3, 25)
    Wait(6 * DT)
    Loop(3)
        Call(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
        Call(N(func_802403B8_8AC348), 0, 0, 10, 3, 30)
        Wait(6 * DT)
        Call(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
        Call(N(func_802403B8_8AC348), 0, -10, 10, 3, 30)
        Wait(6 * DT)
        Call(PlaySoundAtPlayer, SOUND_SEQ_STAR_SPIRIT_CAST, SOUND_SPACE_DEFAULT)
        Call(N(func_802403B8_8AC348), 0, 10, 10, 3, 30)
        Wait(6 * DT)
    EndLoop
    Wait(40 * DT)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Wave, 5, MSG_CH0_0003)
    Thread
        Wait(15 * DT)
        Call(N(func_80240BD8_8ACB68), NPC_Misstar)
        Wait(2)
        Call(N(func_80240BD8_8ACB68), NPC_Mamar)
        Wait(2)
        Call(N(func_80240BD8_8ACB68), NPC_Klevar)
        Wait(2)
        Call(N(func_80240BD8_8ACB68), NPC_Skolar)
        Wait(2)
        Call(N(func_80240BD8_8ACB68), NPC_Kalmar)
        Wait(2)
        Call(N(func_80240BD8_8ACB68), NPC_Muskular)
        Wait(2)
        Call(N(func_80240BD8_8ACB68), NPC_Eldstar)
    EndThread
    Call(FadeOutMusic, 0, 5000 * DT)
    Thread
        Wait(90 * DT)
        Call(N(func_802405A8_8AC538))
    EndThread
    Wait(60 * DT)
    Call(N(func_80240000_8ABF90), 255, 255, 255, 0, 0, 0, 50 * DT)
    Call(SetNpcSpeed, NPC_Goombaria, Float(3.0 / DT))
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(EnableNpcShadow, NPC_Goombaria, TRUE)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Walk)
    Call(SetNpcPos, NPC_Goombaria, 300, 0, 0)
    Call(NpcMoveTo, NPC_Goombaria, 110, 0, 0)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Stand)
    Call(InterpNpcYaw, NPC_Goombaria, 90, 1)
    Wait(10 * DT)
    Call(InterpNpcYaw, NPC_Goombaria, 270, 1)
    Wait(15 * DT)
    Call(InterpNpcYaw, NPC_Goombaria, 90, 1)
    Wait(18 * DT)
    Call(InterpNpcYaw, NPC_Goombaria, 270, 1)
    Wait(10 * DT)
    Wait(6 * DT)
    Call(SetCamDistance, CAM_DEFAULT, 200)
    Call(SetCamPitch, CAM_DEFAULT, 15, -12)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(GetNpcPos, NPC_Goombaria, LVar3, LVar4, LVar5)
    Add(LVar3, -20)
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Wait(25 * DT)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LeanOver)
    Call(PlaySoundAtNpc, NPC_Goombaria, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Goombaria, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25 * DT)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Stand)
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Stand, 5, MSG_CH0_0004)
    Call(SetCamSpeed, CAM_DEFAULT, 1)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetNpcSpeed, NPC_Goombaria, Float(3.0 / DT))
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    Call(NpcMoveTo, NPC_Goombaria, 30, -10, 0)
    Wait(2)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Inspect)
    Wait(15 * DT)
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Inspect, ANIM_Goombaria_Inspect, 5, MSG_CH0_0005)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Talk)
    Call(NpcJump0, NPC_Goombaria, 30, 0, -10, 4)
    Wait(5 * DT)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LeanOver)
    Call(NpcJump0, NPC_Goombaria, 30, 0, -10, 4)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Stand, 5, MSG_CH0_0006)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    Call(SetNpcSpeed, NPC_Goombaria, Float(6.0))
    Call(NpcMoveTo, NPC_Goombaria, -30, -5, 0)
    Call(NpcFacePlayer, NPC_Goombaria, 5)
    Call(SetNpcJumpscale, NPC_Goombaria, Float(4.0))
    Call(NpcJump0, NPC_Goombaria, -29, 0, 5, 4)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    Call(SetNpcSpeed, NPC_Goombaria, Float(6.0))
    Call(NpcMoveTo, NPC_Goombaria, 34, 5, 0)
    Call(NpcFacePlayer, NPC_Goombaria, 5)
    Call(SetNpcJumpscale, NPC_Goombaria, Float(4.0))
    Call(NpcJump0, NPC_Goombaria, 33, 0, 5, 4)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    Call(SetNpcSpeed, NPC_Goombaria, Float(6.0))
    Call(NpcMoveTo, NPC_Goombaria, -30, 5, 0)
    Call(NpcFacePlayer, NPC_Goombaria, 5)
    Call(SetNpcJumpscale, NPC_Goombaria, Float(4.0))
    Call(NpcJump0, NPC_Goombaria, -29, 0, 5, 4)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    Call(SetNpcSpeed, NPC_Goombaria, Float(6.0))
    Call(NpcMoveTo, NPC_Goombaria, 34, 5, 0)
    Call(NpcFacePlayer, NPC_Goombaria, 5)
    Call(SetNpcJumpscale, NPC_Goombaria, Float(4.0))
    Call(NpcJump0, NPC_Goombaria, 33, 0, 5, 4)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Stand, 5, MSG_CH0_0007)
    Wait(20 * DT)
    Thread
        Call(SetNpcSpeed, NPC_Goombaria, Float(4.0 / DT))
        Call(NpcMoveTo, NPC_Goombaria, 450, 0, 0)
    EndThread
    Wait(15 * DT)
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Stand, 5, MSG_CH0_0008)
    Wait(30 * DT)
    Set(GB_StoryProgress, STORY_CH0_WAKE_UP)
    Call(DisablePlayerPhysics, FALSE)
    Call(N(func_802405CC_8AC55C))
    Call(GotoMapSpecial, Ref("kmr_02"), kmr_02_ENTRY_5, TRANSITION_MARIO_BLACK)
    Return
    End
};
