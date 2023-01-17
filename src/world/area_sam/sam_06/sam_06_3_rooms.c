#include "sam_06.h"

EvtScript N(D_80243970_D23800) = {
    EVT_CALL(RotateModel, MODEL_khm_doa, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802439A0_D23830) = {
    EVT_CALL(RotateGroup, MODEL_khm_yane, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_khm_sita, LVar0, 0, 0, -1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupEnabled, MODEL_khm_sita, 0)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupEnabled, MODEL_khm_sita, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243A48_D238D8) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(AF_SAM_01, FALSE)
            EVT_CALL(SetGroupEnabled, MODEL_kh_naiso, 1)
        EVT_CASE_EQ(3)
            EVT_SET(AF_SAM_01, TRUE)
            EVT_CALL(SetGroupEnabled, MODEL_kh_naiso, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243ACC_D2395C) = {
    EVT_CALL(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243AFC_D2398C) = {
    EVT_CALL(RotateGroup, MODEL_km_yane, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_km_sita, LVar0, 0, 0, -1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupEnabled, MODEL_km_sita, 0)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupEnabled, MODEL_km_sita, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243BA4_D23A34) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(AF_SAM_01, FALSE)
            EVT_CALL(SetGroupEnabled, MODEL_k_naiso, 1)
            EVT_CALL(EnableModel, MODEL_k_naiso, TRUE)
        EVT_CASE_EQ(2)
            EVT_IF_LT(GB_StoryProgress, STORY_CH7_GOT_SNOWMAN_SCARF)
                EVT_CALL(DisablePlayerInput, TRUE)
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_SET(AF_SAM_01, TRUE)
            EVT_CALL(SetGroupEnabled, MODEL_k_naiso, 0)
            EVT_IF_LT(GB_StoryProgress, STORY_CH7_GOT_SNOWMAN_SCARF)
                EVT_EXEC_WAIT(N(EVS_80248CE4))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243C94_D23B24) = {
    EVT_CALL(RotateModel, MODEL_o122, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243CC4_D23B54) = {
    EVT_CALL(RotateGroup, MODEL_hm_yane, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_hm_sita, LVar0, 0, 0, -1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupEnabled, MODEL_hm_sita, 0)
        EVT_CALL(SetGroupEnabled, MODEL_hm_yane, 0)
        EVT_CALL(EnableModel, MODEL_h_yuki1, FALSE)
        EVT_CALL(EnableModel, MODEL_h_yuki2, FALSE)
        EVT_CALL(EnableModel, MODEL_hm_entotu, FALSE)
        EVT_CALL(EnableModel, MODEL_hm_ento2, FALSE)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupEnabled, MODEL_hm_sita, 1)
        EVT_CALL(SetGroupEnabled, MODEL_hm_yane, 1)
        EVT_CALL(EnableModel, MODEL_h_yuki1, TRUE)
        EVT_CALL(EnableModel, MODEL_h_yuki2, TRUE)
        EVT_CALL(EnableModel, MODEL_hm_entotu, TRUE)
        EVT_CALL(EnableModel, MODEL_hm_ento2, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243E34_D23CC4) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(AF_SAM_01, FALSE)
            EVT_CALL(SetGroupEnabled, MODEL_h_naiso, 1)
        EVT_CASE_EQ(3)
            EVT_SET(AF_SAM_01, TRUE)
            EVT_CALL(SetGroupEnabled, MODEL_h_naiso, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80243EB8_D23D48)[] = {
    NPC_ShiverToad_04,
    -1
};

s32 N(D_80243EC0_D23D50)[] = {
    NPC_Merle,
    -1
};

s32 N(D_80243EC8_D23D58)[] = {
    NPC_Ninji_04,
    NPC_Twink_04,
    NPC_Twink_05,
    NPC_Twink_06,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    EVT_CALL(SetGroupEnabled, MODEL_kh_naiso, 0)
    EVT_CALL(MakeDoorAdvanced, 2, EVT_PTR(N(D_80243970_D23800)), EVT_PTR(N(D_802439A0_D23830)), 0, EVT_PTR(N(D_80243A48_D238D8)), COLLIDER_kh_d1, COLLIDER_kh_d2, MODEL_kinohuse, EVT_PTR(N(D_80243EB8_D23D48)))
    EVT_CALL(SetGroupEnabled, MODEL_k_naiso, 0)
    EVT_CALL(MakeDoorAdvanced, 2, EVT_PTR(N(D_80243ACC_D2395C)), EVT_PTR(N(D_80243AFC_D2398C)), 0, EVT_PTR(N(D_80243BA4_D23A34)), COLLIDER_k_d1, COLLIDER_k_d2, MODEL_k, EVT_PTR(N(D_80243EC0_D23D50)))
    EVT_CALL(SetGroupEnabled, MODEL_h_naiso, 0)
    EVT_CALL(MakeDoorAdvanced, 2, EVT_PTR(N(D_80243C94_D23B24)), EVT_PTR(N(D_80243CC4_D23B54)), 0, EVT_PTR(N(D_80243E34_D23CC4)), COLLIDER_h_doa1, COLLIDER_h_doa2, MODEL_hakun, EVT_PTR(N(D_80243EC8_D23D58)))
    EVT_RETURN
    EVT_END
};
