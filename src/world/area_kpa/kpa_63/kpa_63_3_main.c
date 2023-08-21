#include "kpa_63.h"

EvtScript N(EVS_OpenHangerDoor) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tts, SOUND_AIRSHIP_DOCK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 100, 0, 20, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar5, LVar0)
        EVT_MULF(LVar5, EVT_FLOAT(0.01))
        EVT_CALL(ScaleGroup, MODEL_g75, LVar5, 1, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseHangerDoor) = {
    EVT_CALL(MakeLerp, 0, 100, 20, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar5, LVar0)
        EVT_MULF(LVar5, EVT_FLOAT(0.01))
        EVT_CALL(ScaleGroup, MODEL_g75, LVar5, 1, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tts, SOUND_AIRSHIP_DOCK_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_kpa_62_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC(N(EVS_OpenHangerDoor))
    EVT_WAIT(15)
    EVT_CALL(UseExitHeading, 60, kpa_63_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("kpa_62"), kpa_62_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kpa_62_3)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar0)
    EVT_IF_EQ(LVar0, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kpa_63_ENTRY_1)
        EVT_EXEC(N(EVS_Starship_Arrive))
        EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_ELSE
        EVT_EXEC(N(EVS_CloseHangerDoor))
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_SET(GF_MAP_BowsersCastle, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Starship_Depart)), TRIGGER_FLOOR_TOUCH, COLLIDER_o400, 1, 0)
    EVT_EXEC(N(EVS_SetupStarship))
    EVT_RETURN
    EVT_END
};
