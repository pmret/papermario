#include "tik_09.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_CloseGates) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(PlaySound, SOUND_CHIME_BEGIN_AMBUSH)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o59, SOUND_26B, SOUND_SPACE_MODE_0)
    EVT_CALL(MakeLerp, 60, 0, 25, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_ew_kousi, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_ee_kousi, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o59, SOUND_26C, SOUND_SPACE_MODE_0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o58, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o59, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(1)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_tik_10_0) = EVT_EXIT_WALK(60, tik_09_ENTRY_0, "tik_10", tik_10_ENTRY_0);
EvtScript N(EVS_ExitWalk_tik_08_0) = EVT_EXIT_WALK(60, tik_09_ENTRY_1, "tik_08", tik_08_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_10_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_08_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, tik_09_ENTRY_2)
        EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC_WAIT(EnterWalk)
        EVT_IF_EQ(GF_TIK09_Defeated_Ambush, FALSE)
            EVT_EXEC_WAIT(N(EVS_CloseGates))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

#include "../common/Flotsam.inc.c"

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_TIK_09)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_80000035)
    EVT_CALL(PlaySoundAtF, SOUND_80000036, SOUND_SPACE_MODE_1, -190, -20, -120)
    EVT_CALL(PlaySoundAtF, SOUND_80000037, SOUND_SPACE_MODE_1, 50, -20, -120)
    EVT_CALL(PlaySoundAtF, SOUND_80000038, SOUND_SPACE_MODE_1, 290, -20, -120)
    EVT_EXEC(N(EVS_SetupDrips))
    EVT_CALL(EnableTexPanning, MODEL_nagare, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o84, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o85, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o86, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   70,  100,  100,  130)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_taki, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(  -50, -900,  -70,-1200)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_takib, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(    0,-1400,-2600,  -60)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_nagare2, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o87, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o88, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o89, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_6)
        TEX_PAN_PARAMS_STEP(  200,  400,  250,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetRenderMode, MODEL_o90, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(SetRenderMode, MODEL_nagab, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_THREAD
        EVT_SET(LVar2, MODEL_bin)
        EVT_EXEC(N(EVS_Flotsam_Bobbing))
        EVT_WAIT(5)
        EVT_SET(LVar2, MODEL_kan1)
        EVT_EXEC(N(EVS_Flotsam_Bobbing))
        EVT_WAIT(5)
        EVT_SET(LVar2, MODEL_kan2)
        EVT_EXEC(N(EVS_Flotsam_Bobbing))
    EVT_END_THREAD
    EVT_CALL(TranslateModel, MODEL_ew_kousi, 0, 60, 0)
    EVT_CALL(TranslateModel, MODEL_ee_kousi, 0, 60, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o58, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o59, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
