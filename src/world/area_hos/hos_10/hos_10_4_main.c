#include "hos_10.h"

EvtScript N(EVS_Main) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, hos_10_ENTRY_1)
        EVT_WAIT(75)
    EVT_END_IF
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_10_ENTRY_1)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Descent)))
        EVT_CASE_EQ(hos_10_ENTRY_2)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_FlyAway)))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_IF_NE(GB_StoryProgress, STORY_INTRO)
        EVT_CALL(EnableModel, MODEL_mario_o, FALSE)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_10_ENTRY_1)
            EVT_WAIT(50)
            EVT_EXEC(N(EVS_Scene_CastleDescending))
        EVT_CASE_EQ(hos_10_ENTRY_2)
            EVT_EXEC(N(EVS_Scene_SpiritsFlyingAway))
        EVT_CASE_EQ(hos_10_ENTRY_3)
            EVT_EXEC_WAIT(N(EVS_Scene_RisingAboveClouds))
        EVT_CASE_EQ(hos_10_ENTRY_4)
            EVT_EXEC_WAIT(N(EVS_Scene_UnusedWhiteScreen))
        EVT_CASE_EQ(hos_10_ENTRY_5)
            EVT_WAIT(30)
            EVT_EXEC(N(EVS_Scene_PreTitle))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
