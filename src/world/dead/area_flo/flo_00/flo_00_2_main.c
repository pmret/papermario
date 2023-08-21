#include "flo_00.h"
#include "effects.h"

#include "world/area_flo/common/FlowerSpawnRegion.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_LEFT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Wisterwood_Exit) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlayerMoveTo, 30, -170, 10)
    EVT_CALL(InterpPlayerYaw, 0, 0)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittn, SOUND_WOODEN_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, -100, 20, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g27, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(PlayerMoveTo, 0, -310, 30)
    EVT_CALL(func_802D2C14, 0)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_STAR_SPRIT_DEPARTED)
        EVT_SET(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
    EVT_END_IF
    EVT_CALL(MakeLerp, -100, 0, 30, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g27, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittn, SOUND_WOODEN_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(GotoMap, EVT_PTR("mac_01"), mac_01_ENTRY_5)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Wisterwood_Enter) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(InterpPlayerYaw, 180, 0)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittn, SOUND_WOODEN_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, -100, 30, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g27, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(PlayerMoveTo, 0, -135, 30)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(MakeLerp, -100, 0, 30, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g27, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittn, SOUND_WOODEN_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_flo_14_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_1, "flo_14", flo_14_ENTRY_0);
EvtScript N(EVS_ExitWalk_flo_23_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_2, "flo_23", flo_23_ENTRY_0);
EvtScript N(EVS_ExitWalk_flo_25_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_3, "flo_25", flo_25_ENTRY_0);
EvtScript N(EVS_ExitWalk_flo_16_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_4, "flo_16", flo_16_ENTRY_0);
EvtScript N(EVS_ExitWalk_flo_09_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_5, "flo_09", flo_09_ENTRY_0);
EvtScript N(EVS_ExitWalk_flo_08_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_6, "flo_08", flo_08_ENTRY_0);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_23_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_25_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_16_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_09_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_08_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_ELSE
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_NE(LVar0, flo_00_ENTRY_8)
            EVT_SET(AF_FLO_RidingBeanstalk, FALSE)
        EVT_END_IF
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(flo_00_ENTRY_0)
                EVT_THREAD
                    EVT_EXEC_WAIT(N(EVS_Wisterwood_Enter))
                    EVT_EXEC(N(EVS_BindExitTriggers))
                EVT_END_THREAD
            EVT_CASE_RANGE(flo_00_ENTRY_1, flo_00_ENTRY_6)
                EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
                EVT_EXEC(EnterWalk)
            EVT_CASE_EQ(flo_00_ENTRY_7)
                EVT_THREAD
                    EVT_EXEC_WAIT(N(EVS_Scene_BeanstalkGrewRemark))
                    EVT_EXEC(N(EVS_BindExitTriggers))
                EVT_END_THREAD
            EVT_CASE_EQ(flo_00_ENTRY_8)
                EVT_THREAD
                    EVT_EXEC_WAIT(N(EVS_Enter_Beanstalk))
                    EVT_EXEC(N(EVS_BindExitTriggers))
                EVT_END_THREAD
            EVT_CASE_EQ(flo_00_ENTRY_9)
                EVT_EXEC(N(EVS_Scene_SunReturns))
                EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
                EVT_EXEC(EnterWalk)
            EVT_CASE_EQ(flo_00_ENTRY_A)
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_CASE_EQ(flo_00_ENTRY_B)
                EVT_EXEC(N(EVS_Scene_Epilogue))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_Wisterwood)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittn, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(GF_MAP_FlowerFields, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_GREW_MAGIC_BEANSTALK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o351, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_SET(GF_MAC01_RowfBadgesChosen, FALSE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, flo_00_ENTRY_B)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EpilogueNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(ParentColliderToModel, COLLIDER_o240, MODEL_o142)
    EVT_EXEC(N(EVS_SetupBeanstalk))
    EVT_EXEC(N(EVS_SetupBeanPatch))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o129, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o363, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION(  150, -270,  410,  170,  0)
    EVT_FLOWER_SPAWN_REGION(  115, -450,  250, -270,  0)
    EVT_FLOWER_SPAWN_REGION( -330,  220,   45,  410,  0)
    EVT_FLOWER_SPAWN_REGION( -420, -260, -140,  160,  0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitse, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitsw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitnw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_NE(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, flo_00_ENTRY_A)
            EVT_WAIT(65)
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    // thread to manage wisterwood blinking
    EVT_THREAD
        EVT_CALL(EnableTexPanning, MODEL_o47, TRUE)
        EVT_SET(LVar0, 0)
        EVT_LABEL(0)
            EVT_CALL(RandInt, 300, LVar1)
            EVT_ADD(LVar1, 100)
            EVT_CALL(RandInt, 1, LVar2)
            EVT_ADD(LVar2, 1)
            EVT_WAIT(LVar1)
            EVT_LOOP(LVar2)
                EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, -0x8000, 0)
                EVT_WAIT(2)
                EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, -0x10000, 0)
                EVT_WAIT(2)
                EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, -0x18000, 0)
                EVT_CALL(RandInt, 5, LVar3)
                EVT_ADD(LVar3, 2)
                EVT_WAIT(LVar3)
                EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, -0x10000, 0)
                EVT_WAIT(2)
                EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, -0x8000, 0)
                EVT_WAIT(2)
                EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, 0, 0)
                EVT_CALL(RandInt, 5, LVar3)
                EVT_ADD(LVar3, 2)
                EVT_WAIT(LVar3)
            EVT_END_LOOP
            EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
