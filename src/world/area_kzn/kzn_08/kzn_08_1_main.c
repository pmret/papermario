#include "kzn_08.h"
#include "world/entrances.h"
#include "model.h"

// header and utility includes

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(DefaultNpcs);
extern EvtScript N(EVS_802455A0);
extern API_FUNC(kzn_08_LavaBlockageFunc1);
extern API_FUNC(kzn_08_LavaBlockageFunc2);

void set_model_fog_color_parameters(u8, u8, u8, u8, u8, u8, u8, s32, s32);
void disable_world_fog(void);

EntryList N(Entrances) = {
    { -315.0,    0.0,   85.0,   90.0 },  /* kzn_08_ENTRY_0 */
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_08 },
};

#include "world/common/atomic/LavaBlockage.data.inc.c"
#include "world/common/atomic/LavaBlockage.inc.c"

#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"

ApiStatus func_80240718_C71B98(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 dist = evt_get_variable(script, *args++);

    if (dist != 0) {
        enable_world_fog();
        set_world_fog_dist(995 - dist, 1000);
    } else {
        disable_world_fog();
        set_world_fog_dist(995, 1000);
    }
    set_world_fog_color(0, 0, 0, 0);

    return ApiStatus_DONE2;
}

EvtScript N(D_80244210_C75690) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_3)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP( -200,    0,  600, -400)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024432C_C757AC) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_4)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP( 500,    0,    0, -400)
        TEX_PAN_PARAMS_FREQ(   1,    0,    0,    1)
        TEX_PAN_PARAMS_INIT(   0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

ModelIDList N(D_80244448_C758C8) = {
    .count = 1,
    .list = { MODEL_yougan }
};

EvtScript N(EVS_ExitWalk_kzn_06) = EVT_EXIT_WALK_FIXED(60, kzn_08_ENTRY_0, "kzn_06",  kzn_06_ENTRY_2);

EvtScript N(D_802444B8_C75938) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_06), TRIGGER_FLOOR_TOUCH, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802444E4_C75964) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_yougan1, TEX_PANNER_0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(   0, -800,   0,   0)
        TEX_PAN_PARAMS_FREQ(   0,    1,   0,   0)
        TEX_PAN_PARAMS_INIT(   0,    0,   0,   0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244600_C75A80) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_yougan, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o640, TEX_PANNER_1)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( 800,   0, 1600,   0)
        TEX_PAN_PARAMS_FREQ(   1,   0,    1,   0)
        TEX_PAN_PARAMS_INIT(   0,   0,    0,   0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o468, .pos = { -230.0, 0.0, 100.0 }},
    { .colliderID = COLLIDER_o470, .pos = { -230.0, 0.0, 100.0 }},
    { .colliderID = COLLIDER_o322, .pos = {  -10.0, 0.0, 100.0 }},
    { .colliderID = COLLIDER_o446, .pos = {  -10.0, 0.0, 100.0 }},
    { .colliderID = COLLIDER_o454, .pos = {  -90.0, 0.0, -45.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_80244790) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(MakeLerp, 1, 100, 200, EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_DIVF(LVar0, EVT_FLOAT(10.0))
    EVT_CALL(ScaleModel, MODEL_yougan1, LVar0, EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_MULF(LVar0, EVT_FLOAT(-5.0))
    EVT_ADDF(LVar0, EVT_FLOAT(100.0))
    EVT_SET(MapVar(0), LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(MakeLerp, 0, 35, 100, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, MODEL_yougan, 0, LVar0, 0)
    EVT_MULF(LVar0, EVT_FLOAT(-1.25))
    EVT_ADDF(LVar0, EVT_FLOAT(50.0))
    EVT_SET(MapVar(0), LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS,  COLLIDER_yougan_atari, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yougan_atari, SURFACE_TYPE_LAVA)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_08)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNpcs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
    EVT_SET(LVar0, N(D_802444B8_C75938))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_802455A0))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yougan_atari, SURFACE_TYPE_LAVA)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_CALL(ScaleModel, MODEL_yougan1, EVT_FLOAT(10.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(TranslateModel, MODEL_yougan, 0, 40, 0)
    EVT_SET(MapVar(0), 0)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(kzn_08_LavaBlockageFunc1, 2, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(kzn_08_LavaBlockageFunc2, EVT_PTR(N(D_80244448_C758C8)))
    EVT_END_THREAD
    EVT_EXEC(N(D_802444E4_C75964))
    EVT_EXEC(N(D_80244600_C75A80))
    EVT_SET(LVar0, 27)
    EVT_EXEC(N(D_80244210_C75690))
    EVT_SET(LVar0, 28)
    EVT_EXEC(N(D_8024432C_C757AC))
    EVT_RETURN
    EVT_END
};
