#include "jan_03.h"
#include "effects.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_LEFT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_jan_02_1) = EVT_EXIT_WALK(60, jan_03_ENTRY_0, "jan_02", jan_02_ENTRY_1);
EvtScript N(EVS_ExitWalk_jan_05_0) = EVT_EXIT_WALK(60, jan_03_ENTRY_1, "jan_05", jan_05_ENTRY_0);
EvtScript N(EVS_ExitWalk_jan_22_0) = EVT_EXIT_WALK(60, jan_03_ENTRY_2, "jan_22", jan_22_ENTRY_0);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_22_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, jan_03_ENTRY_3)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
        EVT_IF_EQ(GF_JAN03_WarpPipe, FALSE)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
            EVT_WAIT(30)
            EVT_CALL(PlaySound, SOUND_GROW)
            EVT_SET(GF_JAN03_WarpPipe, TRUE)
            EVT_WAIT(30)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_IF
        EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC_WAIT(N(EVS_Pipe_EnterVertical))
        EVT_WAIT(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_YOSHIS_VILLAGE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(CrisisNPCs)))
        EVT_CASE_LT(STORY_CH5_ZIP_LINE_READY)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(ChapterNPCs)))
        EVT_CASE_EQ(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(ChapterNPCs)))
        EVT_CASE_GT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(AfterNPCs)))
        EVT_CASE_DEFAULT
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitnw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_LOOP_JAN_BEACH_WAVES)
    EVT_EXEC(N(EVS_SetupRooms))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_CALL(EnableTexPanning, MODEL_o121, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o371, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o119, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,  400,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP( -100,  200,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetModelFlags, MODEL_o189, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o186, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o192, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o195, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_EXEC(N(EVS_SetupShop))
    EVT_RETURN
    EVT_END
};
