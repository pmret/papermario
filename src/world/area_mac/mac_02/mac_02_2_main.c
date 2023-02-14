#include "mac_02.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_mac_04_0) = EVT_EXIT_WALK(60, mac_02_ENTRY_0, "mac_04", mac_04_ENTRY_0);
EvtScript N(EVS_ExitWalk_mim_10_0) = EVT_EXIT_WALK(60, mac_02_ENTRY_1, "mim_10", mim_10_ENTRY_0);
EvtScript N(EVS_ExitWalk_mac_01_3) = EVT_EXIT_WALK(60, mac_02_ENTRY_2, "mac_01", mac_01_ENTRY_3);
EvtScript N(EVS_ExitWalk_mac_03_0) = EVT_EXIT_WALK(60, mac_02_ENTRY_3, "mac_03", mac_03_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_06_3) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_06"), tik_06_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_tik_15_1) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_15"), tik_15_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupPipe) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitVertical))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mim_10_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_01_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_SET(LVar0, mac_02_ENTRY_4)
    EVT_SET(LVar1, COLLIDER_deilip)
    EVT_SET(LVar2, EVT_PTR(N(EVS_GotoMap_tik_06_3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SetupPipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_SET(LVar0, mac_02_ENTRY_5)
    EVT_SET(LVar1, COLLIDER_deilid)
    EVT_SET(LVar2, EVT_PTR(N(EVS_GotoMap_tik_15_1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SetupPipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        EVT_SET(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
    EVT_END_IF
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(AF_MAC_16, FALSE)
    EVT_SET(AF_MAC_17, FALSE)
    EVT_SET(AF_MAC_18, FALSE)
    EVT_SET(AF_MAC_19, FALSE)
    EVT_SET(AF_MAC_1A, FALSE)
    EVT_SET(AF_MAC_1B, FALSE)
    EVT_SET(AF_MAC_1C, FALSE)
    EVT_SET(AF_MAC_1D, FALSE)
    EVT_SET(AF_MAC_1E, FALSE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup4)))
        EVT_CASE_LT(STORY_CH3_SAW_BOO_ENTER_FOREST)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup1)))
        EVT_CASE_LT(STORY_CH3_STAR_SPRIT_DEPARTED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup4)))
        EVT_CASE_LT(STORY_CH4_RETURNED_TOY_TRAIN)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup3)))
        EVT_CASE_DEFAULT
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup4)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
            EVT_CALL(EnableGroup, MODEL_st2, FALSE)
            EVT_CALL(EnableGroup, MODEL_st3, FALSE)
        EVT_CASE_LT(STORY_CH1_BEGAN_PEACH_MISSION)
            EVT_CALL(EnableGroup, MODEL_st1, FALSE)
            EVT_CALL(EnableGroup, MODEL_st3, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_st1, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_DEFAULT
            EVT_CALL(EnableGroup, MODEL_st1, FALSE)
            EVT_CALL(EnableGroup, MODEL_st2, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g47, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_CALL(EnableTexPanning, MODEL_hori, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  100,   40,  200,  -40)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_SetupRooms))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_LE(LVar0, mac_02_ENTRY_3)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
        EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
