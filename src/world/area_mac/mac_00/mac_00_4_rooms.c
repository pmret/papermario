#include "mac_00.h"

EvtScript N(D_80245330_7F0040) = {
    EVT_CALL(RotateModel, MODEL_o210, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245360_7F0070) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-2.0))
    EVT_CALL(RotateModel, MODEL_o201, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o467, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o466, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-1.11))
    EVT_CALL(RotateModel, MODEL_o194, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o463, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o469, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o335, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-0.328125))
    EVT_CALL(RotateModel, MODEL_o198, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o460, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o461, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.21875))
    EVT_CALL(RotateModel, MODEL_o213, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o215, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245570_7F0280) = {
    EVT_CALL(RotateModel, MODEL_o210, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802455A0_7F02B0) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_intel_inn, 1)
            EVT_SET(MF_MusicMixTrigger1, TRUE)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_intel_inn, 0)
            EVT_SET(MF_MusicMixTrigger1, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245624_7F0334) = {
    EVT_CALL(RotateModel, MODEL_o121, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245654_7F0364) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_o370, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o371, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o373, LVar1, 1, 0, 0)
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_o396, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o397, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o155, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o146, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o398, LVar1, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245784_7F0494) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_shop_in, 1)
            EVT_CALL(EnableModel, MODEL_o375, FALSE)
        EVT_CASE_EQ(2)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_shop_in, 0)
            EVT_CALL(EnableModel, MODEL_o375, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024581C_7F052C) = {
    EVT_CALL(RotateModel, MODEL_o168, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024584C_7F055C) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateModel, MODEL_o159, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o169, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o164, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o162, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802458FC_7F060C) = {
    EVT_CALL(RotateModel, MODEL_o168, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024592C_7F063C) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_minka_inn, 1)
            EVT_SET(MF_MusicMixTrigger2, TRUE)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_minka_inn, 0)
            EVT_CALL(EnableMusicProximityMix, 0)
            EVT_SET(MF_MusicMixTrigger2, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802459C0_7F06D0) = {
    EVT_CALL(RotateModel, MODEL_o228, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802459F0_7F0700) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_o437, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o453, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o454, LVar1, 1, 0, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-0.671875))
    EVT_CALL(RotateModel, MODEL_o242, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o239, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o243, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o245, LVar1, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245B10_7F0820) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_BEGAN_PEACH_MISSION)
                    EVT_EXEC(N(EVS_8024BF20))
                    EVT_SET(LVar0, -1)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetGroupEnabled, MODEL_minka2_inn, 1)
            EVT_END_SWITCH
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_minka2_inn, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80245BBC_7F08CC)[] = {
    NPC_Luigi_01,
    -1
};

s32 N(D_80245BC4_7F08D4)[] = {
    NPC_Toad_01,
    NPC_ShyGuy_02,
    NPC_HarryT,
    -1
};

s32 N(D_80245BD4_7F08E4)[] = {
    NPC_Toad_03,
    NPC_Chan,
    NPC_Lee,
    -1
};

s32 N(D_80245BE4_7F08F4)[] = {
    NPC_Toad_10,
    NPC_ThreeSisters_05,
    NPC_ToadKid_01,
    NPC_ToadKid_02,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_80245330_7F0040)), EVT_PTR(N(D_80245360_7F0070)), EVT_PTR(N(D_80245570_7F0280)), EVT_PTR(N(D_802455A0_7F02B0)), COLLIDER_deilit3, COLLIDER_deilit3u, MODEL_intel_house, EVT_PTR(N(D_80245BBC_7F08CC)))
    EVT_CALL(MakeDoorAdvanced, 0x00001002, EVT_PTR(N(D_80245624_7F0334)), EVT_PTR(N(D_80245654_7F0364)), 0, EVT_PTR(N(D_80245784_7F0494)), COLLIDER_deilit5, COLLIDER_deilit5u, MODEL_omise, EVT_PTR(N(D_80245BC4_7F08D4)))
    EVT_CALL(MakeDoorAdvanced, 2, EVT_PTR(N(D_8024581C_7F052C)), EVT_PTR(N(D_8024584C_7F055C)), EVT_PTR(N(D_802458FC_7F060C)), EVT_PTR(N(D_8024592C_7F063C)), COLLIDER_deilit6, COLLIDER_deilit6u, MODEL_minka_1, EVT_PTR(N(D_80245BD4_7F08E4)))
    EVT_CALL(MakeDoorAdvanced, 2, EVT_PTR(N(D_802459C0_7F06D0)), EVT_PTR(N(D_802459F0_7F0700)), 0, EVT_PTR(N(D_80245B10_7F0820)), COLLIDER_deilit4, COLLIDER_deilit4u, MODEL_minka2, EVT_PTR(N(D_80245BE4_7F08F4)))
    EVT_SET(LVar0, 3)
    EVT_EXEC(N(D_802455A0_7F02B0))
    EVT_EXEC(N(D_80245B10_7F0820))
    EVT_EXEC(N(D_80245784_7F0494))
    EVT_EXEC(N(D_8024592C_7F063C))
    EVT_RETURN
    EVT_END
};
