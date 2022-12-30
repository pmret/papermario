#include "kmr_20.h"

API_CALLABLE(N(func_80240330_8EC150)){
    au_ambience_set_volume(0, 1000, 63);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240358_8EC178)){
    au_ambience_set_volume(0, 1000, 127);
    return ApiStatus_DONE2;
}

EvtScript N(D_80243F80_8EFDA0) = {
    EVT_CALL(RotateGroup, MODEL_g14, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243FB0_8EFDD0) = {
    EVT_CALL(RotateGroup, MODEL_g60, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, MODEL_g34, LVar0, -1, 0, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(90)
            EVT_SET(MF_Unk_0C, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_2, FALSE)
            EVT_CALL(EnableGroup, MODEL_g60, FALSE)
            EVT_CALL(EnableGroup, MODEL_g34, FALSE)
        EVT_CASE_EQ(0)
            EVT_IF_EQ(MF_Unk_0C, TRUE)
                EVT_CALL(EnableGroup, MODEL_g72, TRUE)
                EVT_SET(MF_Unk_0C, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_2, TRUE)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(EnableGroup, MODEL_g60, TRUE)
            EVT_CALL(EnableGroup, MODEL_g34, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244100_8EFF20) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(N(func_80240330_8EC150))
            EVT_CALL(EnableGroup, MODEL_g20, TRUE)
            EVT_CALL(EnableGroup, MODEL_g21, TRUE)
            EVT_CALL(EnableGroup, MODEL_g49, TRUE)
            EVT_CALL(EnableModel, MODEL_g56, TRUE)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
        EVT_CASE_EQ(3)
            EVT_CALL(N(func_80240358_8EC178))
            EVT_CALL(EnableGroup, MODEL_g20, FALSE)
            EVT_CALL(EnableGroup, MODEL_g21, FALSE)
            EVT_CALL(EnableGroup, MODEL_g49, FALSE)
            EVT_CALL(EnableModel, MODEL_g56, FALSE)
            EVT_CALL(EnableGroup, MODEL_g72, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80244220_8F0040)[] = {
    NPC_Parakarry,
    -1
};

EvtScript N(EVS_80244228) = {
    EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_80243F80_8EFDA0)), EVT_PTR(N(D_80243FB0_8EFDD0)), 0, EVT_PTR(N(D_80244100_8EFF20)), COLLIDER_o246, COLLIDER_o245, MODEL_g62, EVT_PTR(N(D_80244220_8F0040)))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(kmr_20_ENTRY_2)
        EVT_CASE_OR_EQ(kmr_20_ENTRY_3)
            EVT_CALL(EnableGroup, MODEL_g20, TRUE)
            EVT_CALL(EnableGroup, MODEL_g21, TRUE)
            EVT_CALL(EnableGroup, MODEL_g49, TRUE)
            EVT_CALL(EnableModel, MODEL_g56, TRUE)
            EVT_CALL(EnableGroup, MODEL_g72, FALSE)
            EVT_CALL(N(func_80241C9C_8EDABC))
            EVT_CALL(RotateGroup, MODEL_g60, 90, 1, 0, 0)
            EVT_CALL(RotateGroup, MODEL_g34, 90, -1, 0, 0)
            EVT_CALL(EnableGroup, MODEL_g60, FALSE)
            EVT_CALL(EnableGroup, MODEL_g34, FALSE)
            EVT_CALL(N(func_80240330_8EC150))
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, 3)
            EVT_EXEC(N(D_80244100_8EFF20))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
