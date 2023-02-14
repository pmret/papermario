#include "trd_09.h"

extern EvtScript N(EVS_PlayDemoScene);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DemoNPCs);
extern NpcGroupList N(DefaultNPCs);

EvtScript N(EVS_ExitDoors_trd_01_3) = EVT_EXIT_DOUBLE_DOOR(trd_09_ENTRY_0, "trd_01", trd_01_ENTRY_3,
    COLLIDER_tt5, MODEL_o67, MODEL_o63);
EvtScript N(EVS_ExitDoors_trd_10_0) = EVT_EXIT_DOUBLE_DOOR(trd_09_ENTRY_1, "trd_10", trd_10_ENTRY_0,
    COLLIDER_tt4, MODEL_o60, MODEL_o65);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_01_3)), TRIGGER_WALL_PRESS_A, COLLIDER_tt5, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_10_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt4, 1, 0)
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
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(trd_09_ENTRY_0)
            EVT_SET(LVar2, MODEL_o67)
            EVT_SET(LVar3, MODEL_o63)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(trd_09_ENTRY_1)
            EVT_SET(LVar2, MODEL_o60)
            EVT_SET(LVar3, MODEL_o65)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, DEMO_STATE_NONE)
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DemoNPCs)))
        EVT_EXEC_WAIT(N(EVS_MakeEntities))
        EVT_EXEC_WAIT(N(EVS_PlayDemoScene))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LE(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_IF
    EVT_IF_EQ(GF_TRD09_Defeated_BillBlasters, TRUE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o85, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
