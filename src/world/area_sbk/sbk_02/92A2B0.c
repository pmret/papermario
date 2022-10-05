#include "sbk_02.h"
#include "effects.h"

static char* N(exit_str_0) = "sbk_01";
static char* N(exit_str_1) = "sbk_03";
static char* N(exit_str_2) = "sbk_12";
static char* N(exit_str_3) = "isk_01";
static char* N(exit_str_4) = "sbk_30";
static char* N(exit_str_5) = "";

void get_model_env_color_parameters(u8* arg0, u8* arg1, u8* arg2, u8* arg3, u8* arg4, u8* arg5);

s32 N(get_tattle)(void) {
    s32 tattle;
    if (evt_get_variable(NULL, GB_StoryProgress) > STORY_CH2_GOT_PULSE_STONE) {
        tattle = MSG_MapTattle_sbk_02_after;
    } else {
        tattle = MSG_MapTattle_sbk_02_before;
    }
    return tattle;
}

#include "world/common/atomic/UnkFunc27.inc.c"

API_CALLABLE(func_80240338_92A5E8) {
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, MapVar(0));
    
    effect->data.sun->targetAlpha = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80240364_92A614) {
    static u8 savedPrimR, savedPrimG, savedPrimB;
    static u8 savedEnvR, savedEnvG, savedEnvB;
    static s32 targetPrimR, targetPrimG, targetPrimB;
    static s32 targetEnvR, targetEnvG, targetEnvB;
    static s32 duration, elapsed;

    Bytecode* args = script->ptrReadPos;
    s32 blendPrimR, blendPrimG, blendPrimB;
    s32 blendEnvR, blendEnvG, blendEnvB;

    if (isInitialCall) {
        get_model_env_color_parameters(&savedPrimR, &savedPrimG, &savedPrimB, &savedEnvR, &savedEnvG, &savedEnvB);
        targetPrimR = evt_get_variable(script, *args++);
        targetPrimG = evt_get_variable(script, *args++);
        targetPrimB = evt_get_variable(script, *args++);
        targetEnvR = evt_get_variable(script, *args++);
        targetEnvG = evt_get_variable(script, *args++);
        targetEnvB = evt_get_variable(script, *args++);
        duration = evt_get_variable(script, *args++);
        elapsed = 0;
    }

    if (duration > 0) {
        elapsed++;
        blendPrimR = savedPrimR + ((targetPrimR - savedPrimR) * elapsed) / duration;
        blendPrimG = savedPrimG + ((targetPrimG - savedPrimG) * elapsed) / duration;
        blendPrimB = savedPrimB + ((targetPrimB - savedPrimB) * elapsed) / duration;
        blendEnvR = savedEnvR + ((targetEnvR - savedEnvR) * elapsed) / duration;
        blendEnvG = savedEnvG + ((targetEnvG - savedEnvG) * elapsed) / duration;
        blendEnvB = savedEnvB + ((targetEnvB - savedEnvB) * elapsed) / duration;

        set_model_env_color_parameters(blendPrimR, blendPrimG, blendPrimB, blendEnvR, blendEnvG, blendEnvB);
        if (elapsed >= duration) {
            return ApiStatus_DONE2;
        }
    } else {
        set_model_env_color_parameters(targetPrimR, targetPrimG, targetPrimB, targetEnvR, targetEnvG, targetEnvB);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
