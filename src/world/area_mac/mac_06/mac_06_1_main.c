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
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SET(LVarC, 0)
    EVT_LABEL(0)
        EVT_IF_GE(LVarC, 60)
            EVT_SET(LVarC, 0)
        EVT_END_IF
        EVT_CALL(N(GetWaveAmplitude), LVarC, LVar0, EVT_FLOAT(-1.0), EVT_FLOAT(1.0), 30, 0, 0)
        EVT_CALL(ScaleGroup, MODEL_g34, 1, LVar0, 1)
        EVT_ADD(LVarC, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_FlyingGull))
    EVT_EXEC(N(EVS_WhaleMain))
    EVT_CALL(SetMusicTrack, 0, SONG_RIDING_THE_WHALE, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_BEACH)
    EVT_EXEC(N(EVS_AnimateWaves))
    EVT_CALL(SetTexPanner, MODEL_o214, TEX_PANNER_1)
    EVT_CALL(N(SpawnSunEffect))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mac_06_ENTRY_0)
        EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  400,  150,  200,  -60)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
            EVT_EXEC(N(EVS_UpdateTexturePan))
        EVT_END_THREAD
    EVT_ELSE
        EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -400, -150, -200,   60)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
            EVT_EXEC(N(EVS_UpdateTexturePan))
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
