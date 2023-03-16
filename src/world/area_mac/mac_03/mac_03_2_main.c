#include "mac_03.h"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_mac_02_3) = EVT_EXIT_WALK(60, mac_03_ENTRY_0, "mac_02", mac_02_ENTRY_3);

EvtScript N(EVS_GotoMap_mgm_00_0) = {
    EVT_CALL(GotoMap, EVT_PTR("mgm_00"), mgm_00_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_mgm_00_0) = EVT_EXIT_PIPE_VERTICAL(mac_02_ENTRY_2, COLLIDER_deilim, N(EVS_GotoMap_mgm_00_0));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_02_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_mgm_00_0)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilim, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(mac_03_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(mac_03_ENTRY_1)
            EVT_EXEC(N(EVS_ArriveFromMtRugged))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(mac_03_ENTRY_2)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(mac_03_ENTRY_3)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HidePlayroomPipe) = {
    EVT_IF_EQ(GF_MAC03_UnlockedPlayroom, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_dokan, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilim, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o241, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(GetClockHandAngles)) {
    if (script->varTable[15] > 720) {
        script->varTable[15] = 0;
    }
    script->varTable[0] = script->varTable[15] * 6;
    script->varTable[1] = script->varTable[15] / 2;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
#if VERSION_PAL
    EVT_CALL(GetLanguage, LVar0)
    EVT_CALL(SetModelTexVariant, MODEL_o110, LVar0)
#endif
    EVT_SET(AF_MAC_20, FALSE)
    EVT_SET(AF_MAC_21, FALSE)
    EVT_SET(AF_MAC_22, FALSE)
    EVT_SET(AF_MAC_23, FALSE)
    EVT_SET(AF_MAC_24, FALSE)
    EVT_SET(AF_MAC_25, FALSE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_EQ(LVar0, DEMO_STATE_NONE)
        EVT_EXEC(N(EVS_InitializeLilOinks))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_InitializeTrainScene))
    EVT_THREAD
        EVT_SET(LVarF, 0)
        EVT_LABEL(10)
            EVT_ADD(LVarF, 1)
            EVT_CALL(N(GetClockHandAngles))
            EVT_CALL(RotateModel, MODEL_o148, LVar0, 0, 0, -1)
            EVT_CALL(RotateModel, MODEL_o147, LVar1, 0, 0, -1)
            EVT_WAIT(10)
            EVT_GOTO(10)
    EVT_END_THREAD
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, DEMO_STATE_NONE)
        EVT_EXEC_WAIT(N(EVS_PlayDemoScene))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_HidePlayroomPipe))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_SET(GF_MAC01_RowfBadgesChosen, FALSE)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
