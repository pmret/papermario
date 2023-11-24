#include "kzn_06.h"
#include "model.h"

#include "../common/LavaGlowLighting.inc.c"

API_CALLABLE(N(AdjustFog)) {
    Bytecode* args = script->ptrReadPos;
    ModelIDList* modelIDs;
    ModelIDList* iterList;
    s32 colR, colG, colB;
    s32 duration;
    s32 mode;
    s32 i;

    modelIDs = (ModelIDList*) evt_get_variable(script, *args++);
    colR = evt_get_variable(script, *args++);
    colG = evt_get_variable(script, *args++);
    colB = evt_get_variable(script, *args++);
    duration = evt_get_variable(script, *args++);
    mode = evt_get_variable(script, *args++);
    iterList = modelIDs;

    if (isInitialCall) {
        for (i = 0; i < iterList->count; i++) {
            s32 treeIndex = get_model_list_index_from_tree_index(iterList->list[i]);
            Model* mdl = get_model_from_list_index(treeIndex);
            set_mdl_custom_gfx_set(mdl, CUSTOM_GFX_NONE, ENV_TINT_REMAP);
            if (mode) {
                mdl->flags &= ~MODEL_FLAG_HIDDEN;
            }
        }
        script->functionTemp[0] = duration;
    }

    if (mode) {
        mdl_set_shroud_tint_params(colR, colG, colB,
            (script->functionTemp[0] * 255) / duration);
    } else {
        mdl_set_shroud_tint_params(colR, colG, colB,
            255 - ((script->functionTemp[0] * 255) / duration));
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] < 0) {
        for (i = 0; i < iterList->count; i++) {
            s32 treeIndex = get_model_list_index_from_tree_index(iterList->list[i]);
            Model* mdl = get_model_from_list_index(treeIndex);
            set_mdl_custom_gfx_set(mdl, CUSTOM_GFX_NONE, ENV_TINT_NONE);
            if (!mode) {
                mdl->flags |= MODEL_FLAG_HIDDEN;
            }
        }
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80240A44_C6D364)) {
    snd_ambient_mute(0, TRUE);
    return ApiStatus_DONE2;
}

ModelIDList N(LavaModels) = {
    .count = 1,
    .list = { MODEL_g41 }
};

 //@bug modelID 0x12 when it should be 12
ModelIDList N(InvalidLavaModels) = {
    .count = 1,
    .list = { MODEL_o238 }
};

EvtScript N(EVS_8024137C) = {
    EVT_LABEL(0)
        EVT_CALL(N(AdjustFog), EVT_PTR(N(InvalidLavaModels)), 0, 0, 255, 60, 1)
        EVT_WAIT(30)
        EVT_CALL(N(AdjustFog), EVT_PTR(N(InvalidLavaModels)), 0, 0, 255, 60, 0)
        EVT_WAIT(30)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LowerMainLavaLevel) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(3)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(N(func_80240A44_C6D364))
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
            EVT_ADDF(MV_GlowIntensity, EVT_FLOAT(-0.015625))
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
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_yougan1, COLLIDER_FLAGS_UPPER_MASK)
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
        EVT_SETF(MV_GlowIntensity, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_yougan1, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableGroup, MODEL_i_on, FALSE)
        EVT_CALL(TranslateGroup, MODEL_you, 0, -14, -2)
        EVT_CALL(TranslateModel, MODEL_yougan, 0, -25, -50)
        EVT_CALL(TranslateModel, MODEL_spot, 0, -25, 0)
        EVT_CALL(TranslateModel, MODEL_o349, 0, -25, -40)
        EVT_SETF(MV_GlowIntensity, EVT_FLOAT(0.5))
    EVT_END_IF
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(N(ApplyLavaGlowLighting), LAVA_GLOW_MODE_1, NULL)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(ClearLavaGlowLighting), EVT_PTR(N(LavaModels)))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
