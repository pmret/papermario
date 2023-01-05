#include "dgb_00.h"

s32 N(map_init)(void) {
    sprintf(wMapShapeName, "arn_20_shape");
    sprintf(wMapHitName, "arn_20_hit");
    sprintf(wMapTexName, "arn_tex");
    return FALSE;
}

EvtScript N(EVS_ExitWalk_arn_04_1) = EVT_EXIT_WALK(60, dgb_00_ENTRY_0, "arn_04", arn_04_ENTRY_1);

EvtScript N(EVS_ExitDoors_dgb_01_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_00_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deiliwt)
    EVT_SET(LVar2, MODEL_d1)
    EVT_SET(LVar3, MODEL_d2)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), dgb_01_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_arn_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliwt, 1, 0)
        EVT_CASE_LT(STORY_CH3_ESCAPED_TUBBAS_MANOR)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_EXEC(N(EVS_TubbaTaunting))
            EVT_EXEC_WAIT(N(EVS_SetBoosBracingDoor))
        EVT_CASE_DEFAULT
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliwt, 1, 0)
    EVT_END_SWITCH
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
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dgb_00_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(dgb_00_ENTRY_1)
            EVT_IF_GE(GB_StoryProgress, STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
                EVT_IF_LT(GB_StoryProgress, STORY_CH3_ESCAPED_TUBBAS_MANOR)
                    EVT_EXEC(N(EVS_BindExitTriggers))
                    EVT_THREAD
                        EVT_EXEC_WAIT(N(EVS_Scene_BoosApproachManor))
                        EVT_EXEC_WAIT(N(EVS_Scene_EscapeFromTubba))
                    EVT_END_THREAD
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_d1)
            EVT_SET(LVar3, MODEL_d2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(dgb_00_ENTRY_2)
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_EXEC(N(EVS_Scene_ThrownOutBySentinel))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    EVT_SET(GF_MAP_TubbasManor, TRUE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, dgb_00_ENTRY_2)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(BooNPCs)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
