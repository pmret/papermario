#include "mac_06.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(GetWaveAmplitude)) {
    Bytecode* args = script->ptrReadPos;
    s32 timeVar = *args++;
    s32 time = evt_get_variable(script, timeVar);
    s32 outVar = *args++;
    f32 min = evt_get_float_variable(script, *args++);
    f32 max = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++); // period if looping
    s32 onlyOnce = evt_get_variable(script, *args++); // 1 = only once, 0 = loop
    f32 phaseOffset = evt_get_float_variable(script, *args++); // degrees
    f32 diff = (max - min) / 2;

    if (onlyOnce && duration < time) {
        time = duration;
        evt_set_variable(script, timeVar, duration);
    }

    evt_set_float_variable(script, outVar,
        // average value
        (min + diff)
        // modify
        - diff * cos_deg(((time * 180.0f) / duration) + phaseOffset));
    return ApiStatus_DONE2;
}

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_AnimateWaves) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Set(LVarC, 0)
    Label(0)
        IfGe(LVarC, 60)
            Set(LVarC, 0)
        EndIf
        Call(N(GetWaveAmplitude), LVarC, LVar0, Float(-1.0), Float(1.0), 30, 0, 0)
        Call(ScaleGroup, MODEL_g34, 1, LVar0, 1)
        Add(LVarC, 1)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    Exec(N(EVS_FlyingGull))
    Exec(N(EVS_WhaleMain))
    Call(SetMusic, 0, SONG_RIDING_THE_WHALE, 0, VOL_LEVEL_FULL)
    Call(PlayAmbientSounds, AMBIENT_SEA)
    Exec(N(EVS_AnimateWaves))
    Call(SetTexPanner, MODEL_o214, TEX_PANNER_1)
    Call(N(SpawnSunEffect))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_06_ENTRY_0)
        Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  400,  150,  200,  -60)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
            Exec(N(EVS_UpdateTexturePan))
        EndThread
    Else
        Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -400, -150, -200,   60)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
            Exec(N(EVS_UpdateTexturePan))
        EndThread
    EndIf
    Return
    End
};
