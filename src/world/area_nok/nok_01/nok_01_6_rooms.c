#include "nok_01.h"

API_CALLABLE(N(func_80242760_9C7B40)) {
    func_800E98EC();
    status_menu_ignore_changes();
    open_status_menu_long();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242790_9C7B70)) {
    func_800E9900();
    status_menu_respond_to_changes();
    close_status_menu();
    return ApiStatus_DONE2;
}

EvtScript N(D_8024FD30_9D5110) = {
    EVT_LABEL(9)
    EVT_CALL(MakeLerp, 10, -10, 30, EASING_COS_IN_OUT)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o287, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o201, LVar0, 1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(MakeLerp, -10, 10, 30, EASING_COS_IN_OUT)
    EVT_LABEL(11)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o287, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o201, LVar0, 1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_GOTO(9)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024FEA0_9D5280) = {
    EVT_LABEL(0)
    EVT_SET(LVar0, 35)
    EVT_LOOP(LVar0)
        EVT_SET(LVar1, LVar0)
        EVT_MUL(LVar1, 10)
        EVT_CALL(RotateModel, MODEL_o247, LVar1, 0, -1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024FF38_9D5318) = {
    EVT_CALL(RotateModel, MODEL_o200, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024FF68_9D5348) = {
    EVT_CALL(RotateModel, MODEL_o197, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o196, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o195, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o199, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o194, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o193, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o190, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o192, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80250078_9D5458) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_WAIT(20)
            EVT_SET(LVar0, 0)
            EVT_LOOP(18)
                EVT_ADD(LVar0, 5)
                EVT_EXEC_WAIT(N(D_8024FF68_9D5348))
            EVT_END_LOOP
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, 90)
            EVT_LOOP(18)
                EVT_SUB(LVar0, 5)
                EVT_EXEC_WAIT(N(D_8024FF68_9D5348))
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80250140_9D5520) = {
    EVT_CALL(RotateModel, MODEL_o226, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80250170_9D5550) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 45)
    EVT_CALL(TranslateModel, MODEL_o225, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o225, LVar0, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o224, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o223, LVar0, 0, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025021C_9D55FC) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_WAIT(20)
            EVT_CALL(N(func_80242760_9C7B40))
            EVT_SET(LVar0, 0)
            EVT_LOOP(18)
                EVT_ADD(LVar0, 5)
                EVT_EXEC_WAIT(N(D_80250170_9D5550))
            EVT_END_LOOP
        EVT_CASE_EQ(3)
            EVT_CALL(N(func_80242790_9C7B70))
            EVT_SET(LVar0, 90)
            EVT_LOOP(18)
                EVT_SUB(LVar0, 5)
                EVT_EXEC_WAIT(N(D_80250170_9D5550))
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802502FC_9D56DC) = {
    EVT_CALL(RotateModel, MODEL_o246, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025032C_9D570C) = {
    EVT_SETF(LVar1, LVar0)
    EVT_DIVF(LVar1, 2)
    EVT_CALL(RotateModel, MODEL_o243, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o244, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o242, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o245, LVar1, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802503DC_9D57BC) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar0, 0)
            EVT_LOOP(18)
                EVT_ADD(LVar0, 5)
                EVT_EXEC_WAIT(N(D_8025032C_9D570C))
            EVT_END_LOOP
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, 90)
            EVT_LOOP(18)
                EVT_SUB(LVar0, 5)
                EVT_EXEC_WAIT(N(D_8025032C_9D570C))
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80250498_9D5878) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 45)
    EVT_CALL(TranslateModel, MODEL_o246, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o246, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80250504_9D58E4) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_g111, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_g111, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80250568_9D5948) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_g114, 1)
        EVT_CASE_EQ(2)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_g114, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802505D8_9D59B8) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_g79, 1)
            EVT_CALL(N(func_80242804_9C7BE4), AB_NOK_0)
            EVT_EXEC(N(EVS_80242C38))
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
            EVT_CALL(N(func_80242858_9C7C38), AB_NOK_0)
            EVT_EXEC(N(EVS_80242DE0))
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_g79, 0)
            EVT_CALL(N(func_80242898_9C7C78))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80250698_9D5A78)[] = {
    NPC_Toad,
    -1
};

s32 N(D_802506A0_9D5A80)[] = {
    NPC_Koopa_06,
    -1
};

s32 N(D_802506A8_9D5A88)[] = {
    NPC_Koopa_05,
    NPC_Bombomb_01,
    NPC_Bombomb_02,
    -1
};

s32 N(D_802506B8_9D5A98)[] = {
    NPC_Koopa_05,
    -1
};

EvtScript N(EVS_802506C0) = {
    EVT_CALL(MakeDoorAdvanced, 512, EVT_PTR(N(D_8024FF38_9D5318)), EVT_PTR(N(D_80250078_9D5458)), 0, EVT_PTR(N(D_80250504_9D58E4)), COLLIDER_o200, COLLIDER_o284, MODEL_aka, EVT_PTR(N(D_80250698_9D5A78)))
    EVT_CALL(MakeDoorAdvanced, 0x00001200, EVT_PTR(N(D_80250140_9D5520)), EVT_PTR(N(D_8025021C_9D55FC)), 0, EVT_PTR(N(D_80250568_9D5948)), COLLIDER_o226, COLLIDER_o286, MODEL_ki, EVT_PTR(N(D_802506A0_9D5A80)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(MakeDoorAdvanced, 512, EVT_PTR(N(D_802502FC_9D56DC)), EVT_PTR(N(D_802503DC_9D57BC)), EVT_PTR(N(D_80250498_9D5878)), EVT_PTR(N(D_802505D8_9D59B8)), COLLIDER_o246, COLLIDER_o291, MODEL_ao, EVT_PTR(N(D_802506A8_9D5A88)))
    EVT_ELSE
        EVT_CALL(MakeDoorAdvanced, 512, EVT_PTR(N(D_802502FC_9D56DC)), EVT_PTR(N(D_802503DC_9D57BC)), EVT_PTR(N(D_80250498_9D5878)), EVT_PTR(N(D_802505D8_9D59B8)), COLLIDER_o246, COLLIDER_o291, MODEL_ao, EVT_PTR(N(D_802506B8_9D5A98)))
    EVT_END_IF
    EVT_CALL(N(func_802427C0_9C7BA0))
    EVT_SET(LVar0, 3)
    EVT_EXEC(N(D_80250504_9D58E4))
    EVT_EXEC(N(D_80250568_9D5948))
    EVT_EXEC(N(D_802505D8_9D59B8))
    EVT_EXEC(N(D_8024FD30_9D5110))
    EVT_EXEC(N(D_8024FEA0_9D5280))
    EVT_RETURN
    EVT_END
};
