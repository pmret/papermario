#include "mac_04.h"

s32 set_background_color_blend(s32, s32, s32, s32);

API_CALLABLE(N(func_802401C0_842D90)) {
    func_8011B950(0x9E, -1, 1, 1);
    set_background_color_blend(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    return ApiStatus_DONE2;
}

EvtScript N(D_802426B0_845280) = {
    EVT_CALL(RotateModel, MODEL_msdoor, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802426E0_8452B0) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_my1, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_my2, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_my3, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_my4, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_my5, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_mk1, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_mk2, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_mk3, LVar1, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242800_8453D0) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(EnableGroup, MODEL_mise_in, TRUE)
            EVT_EXEC(N(EVS_80248B08))
        EVT_CASE_EQ(3)
            EVT_CALL(EnableGroup, MODEL_mise_in, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242870_845440) = {
    EVT_CALL(RotateModel, MODEL_rndoor, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802428A0_845470) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_rnk1, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_rnk2, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_rnk3, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_rnk4, LVar1, 1, 0, 0)
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_rnk5, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_rnk6, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242990_845560) = {
    EVT_CALL(RotateModel, MODEL_rndoor, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802429C0_845590) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(EnableGroup, MODEL_rin_in, TRUE)
        EVT_CASE_EQ(3)
            EVT_CALL(EnableGroup, MODEL_rin_in, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242A24_8455F4) = {
    EVT_CALL(RotateModel, MODEL_skd, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242A54_845624) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.78125))
    EVT_CALL(TranslateModel, MODEL_skk1, 0, 0, LVar1)
    EVT_CALL(TranslateModel, MODEL_skk2, 0, 0, LVar1)
    EVT_CALL(TranslateModel, MODEL_skk3, 0, 0, LVar1)
    EVT_CALL(TranslateModel, MODEL_skk4, 0, 0, LVar1)
    EVT_CALL(TranslateModel, MODEL_skk5, 0, 0, LVar1)
    EVT_CALL(TranslateModel, MODEL_skk6, 0, 0, LVar1)
    EVT_CALL(TranslateModel, MODEL_skk7, 0, 0, LVar1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242B48_845718) = {
    EVT_CALL(RotateModel, MODEL_skd, LVar0, 0, 0, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242B78_845748) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242BA8_845778) = {
    EVT_CALL(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242BD8_8457A8) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_hk1, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_hk2, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_hk3, LVar1, 0, 0, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242C58_845828) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(EnableGroup, MODEL_heiho_in, TRUE)
            EVT_SET(MF_Unk_0A, TRUE)
        EVT_CASE_EQ(1)
            EVT_EXEC(N(D_80248798_84B368))
        EVT_CASE_EQ(3)
            EVT_CALL(EnableGroup, MODEL_heiho_in, FALSE)
            EVT_CALL(EnableGroup, MODEL_hi_soto, TRUE)
            EVT_SET(MF_Unk_0A, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242D08_8458D8) = {
    EVT_CALL(RotateModel, MODEL_hkai1, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_hkai2, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242D58_845928) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_hk4, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_hk5, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_hk6, LVar1, 0, 0, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242DD8_8459A8) = {
    EVT_RETURN
    EVT_END
};

s32 N(D_80242DE8_8459B8)[] = {
    NPC_HarryT,
    NPC_ShyGuy_02,
    -1
};

s32 N(D_80242DF4_8459C4)[] = {
    NPC_ThreeSisters_01,
    NPC_ThreeSisters_02,
    -1
};

s32 N(D_80242E00_8459D0)[] = {
    NPC_ShyGuy_01,
    -1
};

EvtScript N(D_80242E08_8459D8) = {
    EVT_CALL(MakeDoorAdvanced, 2, EVT_PTR(N(D_80242D08_8458D8)), EVT_PTR(N(D_80242D58_845928)), 0, EVT_PTR(N(D_80242DD8_8459A8)), COLLIDER_deilit_hk, COLLIDER_deilit_hku, MODEL_o13, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242E48_845A18) = {
    EVT_CALL(MakeDoorAdvanced, 0x00002002, EVT_PTR(N(D_80242A24_8455F4)), EVT_PTR(N(D_80242A54_845624)), EVT_PTR(N(D_80242B48_845718)), EVT_PTR(N(D_80242B78_845748)), COLLIDER_deilit_sku, COLLIDER_deilit_sk, MODEL_o13, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80242E88) = {
    EVT_CALL(MakeDoorAdvanced, 0x00001002, EVT_PTR(N(D_802426B0_845280)), EVT_PTR(N(D_802426E0_8452B0)), 0, EVT_PTR(N(D_80242800_8453D0)), COLLIDER_deilit_m, COLLIDER_deilit_mu, MODEL_mise, EVT_PTR(N(D_80242DE8_8459B8)))
    EVT_CALL(MakeDoorAdvanced, 2, EVT_PTR(N(D_80242870_845440)), EVT_PTR(N(D_802428A0_845470)), EVT_PTR(N(D_80242990_845560)), EVT_PTR(N(D_802429C0_845590)), COLLIDER_deilit_r, COLLIDER_deilit_ru, MODEL_rinjin, EVT_PTR(N(D_80242DF4_8459C4)))
    EVT_CALL(MakeDoorAdvanced, 2, EVT_PTR(N(D_80242BA8_845778)), EVT_PTR(N(D_80242BD8_8457A8)), 0, EVT_PTR(N(D_80242C58_845828)), COLLIDER_deilit_h, COLLIDER_deilit_hu, MODEL_heiho_house, EVT_PTR(N(D_80242E00_8459D0)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
        EVT_EXEC_WAIT(N(D_80242E48_845A18))
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_FOUND_HIDDEN_DOOR)
        EVT_EXEC_WAIT(N(D_80242E08_8459D8))
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_RANGE(mac_04_ENTRY_2, mac_04_ENTRY_3)
            EVT_CALL(SetGroupEnabled, MODEL_heiho_in, 1)
            EVT_CALL(N(func_802401C0_842D90))
            EVT_SET(LVar0, 90)
            EVT_CALL(RotateModel, MODEL_hk1, LVar0, 0, 0, -1)
            EVT_CALL(RotateModel, MODEL_hk2, LVar0, 0, 0, -1)
            EVT_CALL(RotateModel, MODEL_hk3, LVar0, 0, 0, -1)
            EVT_CALL(RotateModel, MODEL_hk4, LVar0, 0, 0, -1)
            EVT_CALL(RotateModel, MODEL_hk5, LVar0, 0, 0, -1)
            EVT_CALL(RotateModel, MODEL_hk6, LVar0, 0, 0, -1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, 3)
            EVT_EXEC(N(D_80242800_8453D0))
            EVT_EXEC(N(D_802429C0_845590))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
