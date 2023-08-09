#include "hos_03.h"

EvtScript N(EVS_ExitWalk_hos_02_1) = EVT_EXIT_WALK(60, hos_03_ENTRY_0, "hos_02", hos_02_ENTRY_1);
EvtScript N(EVS_ExitWalk_hos_04_0) = EVT_EXIT_WALK(60, hos_03_ENTRY_1, "hos_04", hos_04_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/GetFloorCollider.inc.c"

EvtScript N(EVS_ControlUpperVisibility) = {
    EVT_LABEL(0)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(COLLIDER_o18)
                EVT_GOTO(10)
            EVT_CASE_EQ(COLLIDER_o218)
                EVT_GOTO(10)
            EVT_CASE_EQ(COLLIDER_o224)
                EVT_GOTO(10)
            EVT_CASE_EQ(COLLIDER_o7)
                EVT_GOTO(10)
            EVT_CASE_EQ(COLLIDER_o234)
                EVT_GOTO(10)
            EVT_CASE_EQ(COLLIDER_o235)
                EVT_LABEL(10)
                EVT_CALL(EnableGroup, MODEL_g50, FALSE)
                EVT_CALL(EnableGroup, MODEL_g39, FALSE)
                EVT_WAIT(1)
                EVT_LABEL(15)
                    EVT_CALL(N(GetFloorCollider), LVar1)
                    EVT_IF_EQ(LVar1, -1)
                        EVT_WAIT(1)
                        EVT_GOTO(15)
                    EVT_END_IF
                EVT_IF_EQ(LVar0, LVar1)
                    EVT_WAIT(1)
                    EVT_GOTO(15)
                EVT_END_IF
                EVT_CALL(EnableGroup, MODEL_g50, TRUE) // house
                EVT_CALL(EnableGroup, MODEL_g39, TRUE) // shop
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_STAR_HAVEN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_IF_EQ(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        EVT_SET(GB_StoryProgress, STORY_CH8_REACHED_STAR_HAVEN)
    EVT_END_IF
    EVT_SET(GF_MAP_StarHaven, TRUE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupAurora))
    EVT_CALL(UseRoomDoorSounds, DOOR_SOUNDS_UNUSED)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_LOOP_STAR_SANCTUARY_FAR)
    EVT_EXEC(N(EVS_SetupRooms))
    EVT_EXEC(N(EVS_SetupShop))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_ControlUpperVisibility))
    EVT_RETURN
    EVT_END
};
