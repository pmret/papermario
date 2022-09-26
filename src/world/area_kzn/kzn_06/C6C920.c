#include "kzn_06.h"
#include "world/entrances.h"
#include "entity.h"
#include "model.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupLavaPuzzle);
extern s32 N(push_block_handle_fall)(Entity* block, Evt* source);
extern API_FUNC(N(AdjustFog));
extern API_FUNC(func_80240A44_C6D364);
extern API_FUNC(N(LavaBlockageFunc1));
extern API_FUNC(N(LavaBlockageFunc2));

EntryList N(Entrances) = {
    {  385.0,  115.0,   55.0,  270.0 },  /* N(ENTRY_0) */
    { -385.0,   75.0,   68.0,   90.0 },  /* N(ENTRY_1) */
    {  400.0,    5.0,  175.0,  270.0 },  /* N(ENTRY_2) */
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_06 },
};

#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"

EvtScript N(EVS_ExitWalk_kzn_05) = EXIT_WALK_SCRIPT(60, kzn_06_ENTRY_0, "kzn_05",  kzn_05_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_08) = EXIT_WALK_SCRIPT(60, kzn_06_ENTRY_2, "kzn_08",  kzn_08_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_07) = EXIT_WALK_SCRIPT(60, kzn_06_ENTRY_1, "kzn_07\0\0\0",  kzn_07_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_05), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_08), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_07), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartTexPanners) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_yo1, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o349, TEX_PANNER_0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(   0, -400,   0,   0)
        TEX_PAN_PARAMS_FREQ(   0,    1,   0,   0)
        TEX_PAN_PARAMS_INIT(   0,    0,   0,   0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_yougan, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_spot, TEX_PANNER_1)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( 400,   0, 800,   0)
        TEX_PAN_PARAMS_FREQ(   1,   0,   1,   0)
        TEX_PAN_PARAMS_INIT(   0,   0,   0,   0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o250, .pos = {   10.0, 145.0, -35.0 }},
    { .colliderID = COLLIDER_o468, .pos = { -150.0, 145.0, -35.0 }},
    { .colliderID = COLLIDER_o394, .pos = { -210.0,  75.0, 100.0 }},
    { .colliderID = COLLIDER_o440, .pos = {   60.0,  75.0, 100.0 }},
    { .colliderID = COLLIDER_o437, .pos = {   60.0,  75.0, 100.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_06)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_SET(GF_KZN06_Visited, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_LAVA_STREAM_BLOCKED)
        EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA2)
    EVT_ELSE
        EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
    EVT_END_IF
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yougan, SURFACE_TYPE_LAVA)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yougan1, SURFACE_TYPE_LAVA)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_StartTexPanners))
    EVT_EXEC(N(EVS_SetupLavaPuzzle))
    EVT_RETURN
    EVT_END
};

// data split? begin entity setup

f32 N(PushBlockFallCurve)[] = {
    0.02, 0.02, 0.04, 0.08, 0.11, 0.20, 0.30, 0.31, 
    0.42, 0.46, 0.50, 0.53, 0.56, 0.59, 0.62, 0.65, 
    0.68, 0.71, 0.74, 0.77, 0.80, 0.83, 0.86, 0.89, 
    0.92, 0.95, 0.98, 1.00, 
};

EvtScript N(EVS_OnBreakBlock) = {
    EVT_SET(GF_KZN06_Hammer3Block, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 325, 205, -30, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KZN06_HiddenItem_LifeShroom)
    EVT_IF_EQ(GF_KZN06_Hammer3Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block_TallHitbox), 385, 5, 180, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlock)))
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_LAVA_STREAM_BLOCKED)
        EVT_CALL(CreatePushBlockGrid, 0, 12, 1, -330, 145, -90, 0)
        EVT_CALL(SetPushBlockFallEffect, 0, EVT_PTR(N(push_block_handle_fall)))
        EVT_CALL(SetPushBlock, 0, 4, 0, 1)
        EVT_CALL(SetPushBlock, 0, 6, 0, 1)
        EVT_CALL(SetPushBlock, 0, 8, 0, 1)
    EVT_ELSE
        EVT_CALL(CreatePushBlockGrid, 0, 12, 1, -330, 120, -90, 0)
        EVT_CALL(SetPushBlock, 0, 9, 0, 1)
        EVT_CALL(SetPushBlock, 0, 10, 0, 1)
        EVT_CALL(SetPushBlock, 0, 11, 0, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// data split?

#include "world/common/atomic/LavaBlockage.data.inc.c"

ModelIDList D_80241374_C6DC94 = {
    .count = 1,
    .list = { MODEL_g41 }
};

ModelIDList D_80241378_C6DC98 = {
    .count = 1,
    .list = { MODEL_o238 }
};

EvtScript N(EVS_8024137C) = {
    EVT_LABEL(0)
    EVT_CALL(N(AdjustFog), EVT_PTR(D_80241378_C6DC98), 0, 0, 255, 60, 1)
    EVT_WAIT(30)
    EVT_CALL(N(AdjustFog), EVT_PTR(D_80241378_C6DC98), 0, 0, 255, 60, 0)
    EVT_WAIT(30)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LowerMainLavaLevel) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(3)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(func_80240A44_C6D364)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -20)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(600.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(5.0), EVT_FLOAT(8.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(15)
    EVT_THREAD
        EVT_LOOP(40)
            EVT_ADDF(MapVar(0), EVT_FLOAT(-0.015625))
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, -25, 100, EASING_QUADRATIC_OUT)
    EVT_SETF(LVar2, EVT_FLOAT(0.0))
    EVT_SETF(LVar3, EVT_FLOAT(0.0))
    EVT_SET(LVar4, 0)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, MODEL_yougan, 0, LVar0, LVar3)
    EVT_CALL(TranslateModel, MODEL_spot, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o349, 0, LVar0, LVar2)
    EVT_IF_GT(LVar4, 20)
        EVT_IF_GT(LVar2, -75)
            EVT_SUBF(LVar2, EVT_FLOAT(0.5))
            EVT_SUBF(LVar3, EVT_FLOAT(0.55))
        EVT_END_IF
    EVT_END_IF
    EVT_ADD(LVar4, 1)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(45)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(ModifyColliderFlags, 0, COLLIDER_yougan1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, 1, COLLIDER_yougan, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableGroup, MODEL_i_on, FALSE)
    EVT_CALL(EnableGroup, MODEL_i_off, TRUE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MonitorPushBlockPuzzle) = {
    // wait for grid pos (11,0) to be occupied
    EVT_LABEL(10)
    EVT_CALL(GetPushBlock, 0, 11, 0, LVar2)
    EVT_IF_EQ(LVar2, PUSH_GRID_EMPTY)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    // begin the scene
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(20)
            EVT_SUBF(LVar0, EVT_FLOAT(0.7))
            EVT_SUBF(LVar1, EVT_FLOAT(0.1))
            EVT_CALL(TranslateGroup, MODEL_you, 0, LVar0, LVar1)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC_WAIT(N(EVS_LowerMainLavaLevel))
    EVT_SET(GB_StoryProgress, STORY_CH5_LAVA_STREAM_BLOCKED)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupLavaPuzzle) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_LAVA_STREAM_BLOCKED)
        EVT_CALL(EnableGroup, MODEL_i_off, FALSE)
        EVT_EXEC(N(EVS_MonitorPushBlockPuzzle))
        EVT_SETF(MapVar(0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, COLLIDER_yougan1, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableGroup, MODEL_i_on, FALSE)
        EVT_CALL(TranslateGroup, MODEL_you, 0, -14, -2)
        EVT_CALL(TranslateModel, MODEL_yougan, 0, -25, -50)
        EVT_CALL(TranslateModel, MODEL_spot, 0, -25, 0)
        EVT_CALL(TranslateModel, MODEL_o349, 0, -25, -40)
        EVT_SETF(MapVar(0), EVT_FLOAT(0.5))
    EVT_END_IF
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(N(LavaBlockageFunc1), 1, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(LavaBlockageFunc2), EVT_PTR(D_80241374_C6DC94))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
