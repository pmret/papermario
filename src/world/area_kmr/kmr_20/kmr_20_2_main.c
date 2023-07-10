#include "kmr_20.h"

#include "world/common/entity/Pipe.inc.c"

API_CALLABLE(N(func_80240310_8EC130)){
    set_map_transition_effect(TRANSITION_BEGIN_OR_END_GAME);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_GotoMap_mac_00_4) = {
    EVT_EXEC(N(EVS_FadeOutAmbientSounds))
    EVT_CALL(GotoMap, EVT_PTR("mac_00"), mac_00_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_mac_00_4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(LVarA, kmr_20_ENTRY_4)
    EVT_SET(LVarB, COLLIDER_o244)
    EVT_SET(LVarC, EVT_PTR(N(EVS_GotoMap_mac_00_4)))
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitVertical))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_mac_00_4)), TRIGGER_FLOOR_TOUCH, COLLIDER_o244, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MARIOS_HOUSE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kmr_20_ENTRY_2)
        EVT_SET(GB_StoryProgress, STORY_EPILOGUE)
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kmr_20_ENTRY_4)
        EVT_SET(MF_LuigiWaiting, FALSE)
        EVT_IF_EQ(GF_KMR20_ReunitedWithLuigi, FALSE)
            EVT_SET(GF_KMR20_ReunitedWithLuigi, TRUE)
            EVT_IF_LT(GB_StoryProgress, STORY_CH3_INVITED_TO_BOOS_MANSION)
                EVT_SET(MF_LuigiWaiting, TRUE)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SET(MF_Unk_0C, FALSE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_LT(LVar0, kmr_20_ENTRY_4)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(SceneNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(EnableGroup, MODEL_g100, FALSE)
    EVT_EXEC(N(EVS_SetupTrees))
    EVT_EXEC(N(EVS_SetupBushes))
    EVT_EXEC(N(EVS_SetupRooms))
    EVT_EXEC(N(EVS_Setup_Interactables))
    EVT_IF_LT(GB_StoryProgress, STORY_EPILOGUE)
        EVT_EXEC(N(EVS_SetupBed))
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kmr_20_ENTRY_0)
            EVT_CALL(N(func_80240310_8EC130))
            EVT_EXEC(N(EVS_Scene_BeginGame))
            EVT_WAIT(5)
        EVT_CASE_EQ(kmr_20_ENTRY_1)
            EVT_EXEC(N(EVS_Scene_SettingOff))
        EVT_CASE_EQ(kmr_20_ENTRY_2)
            EVT_WAIT(60)
            EVT_EXEC(N(EVS_Scene_BeginEpilogue))
        EVT_CASE_EQ(kmr_20_ENTRY_3)
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_EXEC(N(EVS_Scene_EpilogueGetLetter))
        EVT_CASE_EQ(kmr_20_ENTRY_4)
            EVT_SET(GF_MAP_MariosHouse, TRUE)
            EVT_IF_EQ(MF_LuigiWaiting, TRUE)
                EVT_EXEC(N(EVS_Scene_LuigiWaitingAround))
                EVT_THREAD
                    EVT_CALL(DisablePlayerPhysics, TRUE)
                    EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
                    EVT_LABEL(0)
                        EVT_IF_EQ(MF_ReadyForPlayerEntry, FALSE)
                            EVT_WAIT(1)
                            EVT_GOTO(0)
                        EVT_END_IF
                    EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
                    EVT_EXEC(N(EVS_Pipe_EnterVertical))
                EVT_END_THREAD
            EVT_ELSE
                EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
                EVT_EXEC(N(EVS_Pipe_EnterVertical))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
