#include "obk_02.h"

enum {
    REGION_INIT_LAST    = -2,
    REGION_INIT         = -1,
    REGION_UPPER_FLOOR  = 0,
    REGION_STAIRS       = 1,
    REGION_LOWER_FLOOR  = 2,
};

EvtScript N(EVS_ExitDoor_obk_01_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, obk_02_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tt1)
    EVT_SET(LVar2, MODEL_door1b)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_01"), obk_01_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_obk_03_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, obk_02_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_tt2)
    EVT_SET(LVar2, MODEL_door2)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_03"), obk_03_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_obk_06_1) = EVT_EXIT_WALK(60, obk_02_ENTRY_2, "obk_06", obk_06_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_01_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_03_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_obk_06_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(obk_02_ENTRY_0)
            EVT_SET(LVar2, MODEL_door1b)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC_WAIT(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(obk_02_ENTRY_1)
            EVT_SET(LVar2, MODEL_door2)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC_WAIT(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(obk_02_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Fog) = {
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_r1, TEX_PANNER_1)
        EVT_CALL(SetTexPanner, MODEL_r2, TEX_PANNER_1)
        EVT_CALL(SetTexPanner, MODEL_r3, TEX_PANNER_1)
        EVT_CALL(SetTexPanner, MODEL_r4, TEX_PANNER_1)
        EVT_CALL(SetTexPanner, MODEL_r5, TEX_PANNER_1)
        EVT_CALL(SetTexPanner, MODEL_r6, TEX_PANNER_1)
        EVT_LOOP(0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0x8000, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_m2, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_m3, TEX_PANNER_0)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 300)
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnStep_UpperFloor) = {
    EVT_SET(MV_CurrentMapRegion, REGION_UPPER_FLOOR)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnStep_Stairs) = {
    EVT_SET(MV_CurrentMapRegion, REGION_STAIRS)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnStep_LowerFloor) = {
    EVT_SET(MV_CurrentMapRegion, REGION_LOWER_FLOOR)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnableModels_LowerFloor) = {
    EVT_CALL(EnableGroup, MODEL_off_1, TRUE)
    EVT_CALL(EnableGroup, MODEL_bom, TRUE)
    EVT_CALL(EnableGroup, MODEL_tokei, TRUE)
    EVT_CALL(EnableGroup, MODEL_hikido, TRUE)
    EVT_IF_EQ(GF_OBK06_BombedWall, FALSE)
        EVT_CALL(EnableModel, MODEL_bomu_ato, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_bom_mae, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DisableModels_LowerFloor) = {
    EVT_CALL(EnableGroup, MODEL_off_1, FALSE)
    EVT_CALL(EnableGroup, MODEL_bom, FALSE)
    EVT_CALL(EnableGroup, MODEL_tokei, FALSE)
    EVT_CALL(EnableGroup, MODEL_hikido, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnableModels_UpperFloor) = {
    EVT_CALL(EnableGroup, MODEL_off_2, TRUE)
    EVT_CALL(EnableGroup, MODEL_shiyan, TRUE)
    EVT_CALL(EnableGroup, MODEL_door_1, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DisableModels_UpperFloor) = {
    EVT_CALL(EnableGroup, MODEL_off_2, FALSE)
    EVT_CALL(EnableGroup, MODEL_shiyan, FALSE)
    EVT_CALL(EnableGroup, MODEL_door_1, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageRegionVisibility) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnStep_UpperFloor)), TRIGGER_FLOOR_TOUCH, COLLIDER_o296, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnStep_Stairs)), TRIGGER_FLOOR_TOUCH, COLLIDER_o309, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnStep_LowerFloor)), TRIGGER_FLOOR_TOUCH, COLLIDER_o291, 1, 0)
    EVT_SET(MV_CurrentMapRegion, REGION_INIT)
    EVT_SET(MV_LastMapRegion, REGION_INIT_LAST)
    EVT_LOOP(0)
        EVT_IF_NE(MV_CurrentMapRegion, MV_LastMapRegion)
            EVT_SWITCH(MV_CurrentMapRegion)
                EVT_CASE_EQ(REGION_UPPER_FLOOR)
                    EVT_EXEC_WAIT(N(EVS_DisableModels_LowerFloor))
                    EVT_EXEC_WAIT(N(EVS_EnableModels_UpperFloor))
                EVT_CASE_EQ(REGION_STAIRS)
                    EVT_EXEC_WAIT(N(EVS_EnableModels_LowerFloor))
                    EVT_EXEC_WAIT(N(EVS_EnableModels_UpperFloor))
                EVT_CASE_EQ(REGION_LOWER_FLOOR)
                    EVT_EXEC_WAIT(N(EVS_EnableModels_LowerFloor))
                    EVT_EXEC_WAIT(N(EVS_DisableModels_UpperFloor))
            EVT_END_SWITCH
        EVT_END_IF
        EVT_SET(MV_LastMapRegion, MV_CurrentMapRegion)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOOS_MANSION)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_TexPan_Fog))
    EVT_EXEC(N(EVS_SetupBombableWall))
    EVT_EXEC(N(EVS_ClockDoNothing))
    EVT_EXEC(N(EVS_UpdateClock))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_ManageRegionVisibility))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_si, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};
