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
    Label(0)
        Call(N(AdjustFog), Ref(N(InvalidLavaModels)), 0, 0, 255, 60, 1)
        Wait(30)
        Call(N(AdjustFog), Ref(N(InvalidLavaModels)), 0, 0, 255, 60, 0)
        Wait(30)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_LowerMainLavaLevel) = {
    Call(DisablePlayerInput, TRUE)
    Wait(3)
    Call(DisablePlayerPhysics, TRUE)
    Call(N(func_80240A44_C6D364))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -20)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(600.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(5.0), Float(8.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(15)
    Thread
        Loop(40)
            AddF(MV_GlowIntensity, Float(-0.015625))
            Wait(3)
        EndLoop
    EndThread
    Call(MakeLerp, 0, -25, 100, EASING_QUADRATIC_OUT)
    SetF(LVar2, Float(0.0))
    SetF(LVar3, Float(0.0))
    Set(LVar4, 0)
    Label(0)
    Call(UpdateLerp)
    Call(TranslateModel, MODEL_yougan, 0, LVar0, LVar3)
    Call(TranslateModel, MODEL_spot, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o349, 0, LVar0, LVar2)
    IfGt(LVar4, 20)
        IfGt(LVar2, -75)
            SubF(LVar2, Float(0.5))
            SubF(LVar3, Float(0.55))
        EndIf
    EndIf
    Add(LVar4, 1)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Wait(45)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_yougan1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, 1, COLLIDER_yougan, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableGroup, MODEL_i_on, FALSE)
    Call(EnableGroup, MODEL_i_off, TRUE)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MonitorPushBlockPuzzle) = {
    // wait for grid pos (11,0) to be occupied
    Label(10)
    Call(GetPushBlock, 0, 11, 0, LVar2)
    IfEq(LVar2, PUSH_GRID_EMPTY)
        Wait(1)
        Goto(10)
    EndIf
    // begin the scene
    Call(DisablePlayerInput, TRUE)
    Wait(40)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Loop(20)
            SubF(LVar0, Float(0.7))
            SubF(LVar1, Float(0.1))
            Call(TranslateGroup, MODEL_you, 0, LVar0, LVar1)
            Wait(2)
        EndLoop
    EndThread
    ExecWait(N(EVS_LowerMainLavaLevel))
    Set(GB_StoryProgress, STORY_CH5_LAVA_STREAM_BLOCKED)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupLavaPuzzle) = {
    IfLt(GB_StoryProgress, STORY_CH5_LAVA_STREAM_BLOCKED)
        Call(EnableGroup, MODEL_i_off, FALSE)
        Exec(N(EVS_MonitorPushBlockPuzzle))
        SetF(MV_GlowIntensity, Float(1.0))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_yougan1, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableGroup, MODEL_i_on, FALSE)
        Call(TranslateGroup, MODEL_you, 0, -14, -2)
        Call(TranslateModel, MODEL_yougan, 0, -25, -50)
        Call(TranslateModel, MODEL_spot, 0, -25, 0)
        Call(TranslateModel, MODEL_o349, 0, -25, -40)
        SetF(MV_GlowIntensity, Float(0.5))
    EndIf
    Thread
        SetGroup(EVT_GROUP_00)
        Call(N(ApplyLavaGlowLighting), LAVA_GLOW_MODE_1, NULL)
    EndThread
    Thread
        Call(N(ClearLavaGlowLighting), Ref(N(LavaModels)))
    EndThread
    Return
    End
};
