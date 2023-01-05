#include "dgb_11.h"

EvtScript N(EVS_ExitDoor_dgb_02_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, dgb_11_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilits)
    EVT_SET(LVar2, MODEL_o109)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_02"), dgb_02_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dgb_11_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
            EVT_SET(LVar2, MODEL_o109)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_RETURN
        EVT_CASE_EQ(dgb_11_ENTRY_1)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 500, 0, -100)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 500, 0, -100)
            EVT_SET(LVar3, 1)
        EVT_CASE_EQ(dgb_11_ENTRY_2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 500, 75, -250)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 500, 75, -250)
            EVT_SET(LVar3, 75)
        EVT_CASE_EQ(dgb_11_ENTRY_3)
            EVT_CALL(SetZoneEnabled, ZONE_o203, FALSE)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 375, 0, -175)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 375, 0, -175)
            EVT_SET(AF_DGB_02, TRUE)
            EVT_SET(LVar3, 1)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 180, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LE(LVar1, LVar3)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_dgb_02_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilits, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
