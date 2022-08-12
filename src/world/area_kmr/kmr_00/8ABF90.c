#include "kmr_00.h"
#include "effects.h"

static char* N(exit_str_0) = "kmr_02";
static char* N(exit_str_1) = "kmr_02\0";

extern s16 D_80242D60_8AECF0[8];

void set_model_env_color_parameters(u8 primR, u8 primG, u8 primB, u8 envR, u8 envG, u8 envB);
void get_model_env_color_parameters(u8* primR, u8* primG, u8* primB, u8* envR, u8* envG, u8* envB);

ApiStatus func_80240000_8ABF90(Evt* script, s32 isInitialCall) {
    Bytecode* args;
    static u8 oldPrimR, oldPrimG, oldPrimB;
    static u8 oldEnvR, oldEnvG, oldEnvB;
    static s32 newPrimR, newPrimG, newPrimB;
    static s32 newEnvR, newEnvG, newEnvB;
    static s32 duration, time;

    args = script->ptrReadPos;
    if (isInitialCall) {
        get_model_env_color_parameters(&oldPrimR, &oldPrimG, &oldPrimB, &oldEnvR, &oldEnvG, &oldEnvB);
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
        set_model_env_color_parameters(
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
        set_model_env_color_parameters(newPrimR, newPrimG, newPrimB, newEnvR, newEnvG, newEnvB);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80240388_8AC318(Evt* script, s32 isInitialCall) {
    mdl_set_all_fog_mode(3);
    *D_801512F0 = 3;
    return ApiStatus_DONE2;
}

ApiStatus func_802403B8_8AC348(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    fx_sparkles(var0, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

ApiStatus func_802404A0_8AC430(Evt* script, s32 isInitialCall) {
    fx_energy_orb_wave(4, 0.0f, 0.0f, 0.0f, 0.3f, 30);
    return ApiStatus_DONE2;
}

ApiStatus func_802404E8_8AC478(Evt* script, s32 isInitialCall) {
    s32 pitch = evt_get_variable(script, script->varTable[0]);
    gCameras[CAM_DEFAULT].controlSettings.boomPitch = pitch * 0.001f;
    return ApiStatus_DONE2;
}

ApiStatus func_80240530_8AC4C0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Npc* npc = get_npc_unsafe(npcID);

    fx_sparkles(3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80240584_8AC514(Evt* script, s32 isInitialCall) {
    snd_ambient_8005553C(0, 2000);
    return ApiStatus_DONE2;
}

ApiStatus func_802405A8_8AC538(Evt* script, s32 isInitialCall) {
    snd_ambient_80055590(0, 2000);
    return ApiStatus_DONE2;
}

ApiStatus func_802405CC_8AC55C(Evt* script, s32 isInitialCall) {
    snd_ambient_slow_fade_out(0, 1000);
    return ApiStatus_DONE2;
}

ApiStatus func_802405F0_8AC580(Evt* script, s32 isInitialCall) {
    enum {
        FUNC_STATE_0        = 0,
        FUNC_STATE_1        = 1,
        FUNC_STATE_2        = 2,
        FUNC_STATE_3        = 3
    };

    Bytecode* args = script->ptrReadPos;
    ApiStatus retVal = ApiStatus_BLOCK;
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->varTable[15] = evt_get_variable(script, *args++);
        script->functionTemp[0] = FUNC_STATE_0;
        script->functionTemp[3] = 0;
    }

    npc = get_npc_unsafe(script->functionTemp[1]);
    switch (script->functionTemp[0]) {
        case FUNC_STATE_0:
            npc->pos.x = 0.0f;
            npc->pos.y = -1000.0f;
            npc->pos.z = -50.0f;
            npc->moveToPos.x = script->functionTemp[3] * 3;
            npc->moveToPos.y = 3.0f;
            if (script->functionTemp[3] >= script->varTable[15]) {
                npc->pos.y = 100.0f;
                add_vec2D_polar(&npc->pos.x, &npc->pos.z, 70.0f, npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f);
                npc->pos.y += (-npc->pos.z + -50.0f + 70.0f) * 0.15f;
                sfx_play_sound_at_position(0xB000001E, 0, npc->pos.x, npc->pos.y, npc->pos.z);
                fx_sparkles(0, npc->pos.x, npc->pos.y + 20.0f, npc->pos.z, 20.0f);
                script->functionTemp[0] = FUNC_STATE_1;
            }
            break;
        case FUNC_STATE_1:
            npc->pos.x = 0.0f;
            npc->pos.z = -50.0f;
            npc->pos.y = 100.0f;
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 70.0f, npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f);
            npc->pos.y += (-npc->pos.z + -50.0f + 70.0f) * 0.15f;
            if ((script->functionTemp[3] + script->functionTemp[2]) ==
                (((script->functionTemp[3] + script->functionTemp[2]) / 13) * 13)) {
                fx_sparkles(3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
            }
            if (script->functionTemp[3] > 256) {
                script->functionTemp[0] = FUNC_STATE_2;
                script->varTable[14] = 0;
            }
            break;
        case FUNC_STATE_2:
            npc->pos.x = 0.0f;
            npc->pos.z = -50.0f;
            npc->pos.y = 100.0f - (script->varTable[14] * 0.3f);
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 70.0f, npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f);
            npc->pos.y += (-npc->pos.z + -50.0f + 70.0f) * 0.15f;
            if ((script->functionTemp[3] + script->functionTemp[2]) ==
                (((script->functionTemp[3] + script->functionTemp[2]) / 13) * 13)) {
                fx_sparkles(3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
            }
            if (script->varTable[14]++ > 180) {
                script->functionTemp[0] = FUNC_STATE_3;
                script->varTable[14] = 0;
            }
            break;
        case FUNC_STATE_3:
            npc->moveToPos.y -= 0.03f;
            npc->pos.x = 0.0f;
            npc->pos.z = -50.0f;
            npc->pos.y = 45.999996f;
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 70.0f, npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f);
            npc->pos.y += (-npc->pos.z + -50.0f + 70.0f) * 0.15f;
            if ((script->functionTemp[3] + script->functionTemp[2]) ==
                (((script->functionTemp[3] + script->functionTemp[2]) / 13) * 13)) {
                fx_sparkles(3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
            }
            if (npc->moveToPos.y < 0.0f) {
                retVal = ApiStatus_DONE2;
            }
            break;
    }
    script->functionTemp[3]++;
    npc->moveToPos.x += npc->moveToPos.y;
    return retVal;
}

ApiStatus func_80240BD8_8ACB68(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = evt_get_variable(script, *args);
        npc = get_npc_unsafe(script->functionTemp[1]);
        sfx_play_sound_at_position(SOUND_B000001E, 0, npc->pos.x, npc->pos.y, npc->pos.z);
        fx_sparkles(0, npc->pos.x, npc->pos.y + 20.0f, npc->pos.z, 10.0f);
        script->functionTemp[0] = 3;
    }

    npc = get_npc_unsafe(script->functionTemp[1]);
    script->functionTemp[0]--;
    if (script->functionTemp[0] == -1) {
        npc->pos.y = -1000.0f;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80240CB0_8ACC40(Evt* script, s32 isInitialCall) {
    s32 retVal;
    if (isInitialCall) {
        script->functionTemp[1] = 0;
        script->functionTempPtr[2] = get_npc_safe(script->owner2.npcID);
        script->functionTemp[3] = D_80242D60_8AECF0[script->owner2.npcID - 1];
    }
    if (script->functionTemp[3] == 0) {
        Npc* npc = script->functionTempPtr[2];
        npc->verticalRenderOffset = sin_deg(script->functionTempF[1]) * 1.5f;
        script->functionTempF[1] = clamp_angle(script->functionTempF[1] + 18.0f);
        retVal = ApiStatus_BLOCK;
    } else {
        script->functionTemp[3]--;
        retVal = ApiStatus_BLOCK;
    }
    return retVal;
}
