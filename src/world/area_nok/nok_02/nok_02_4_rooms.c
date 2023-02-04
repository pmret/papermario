#include "nok_02.h"
#include "effects.h"

API_CALLABLE(N(func_80240970_9D7990)) {
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    return ApiStatus_DONE2;
}

EvtScript N(D_80245F30_9DCF50) = {
    EVT_LABEL(0)
    EVT_SET(LVar0, 35)
    EVT_LOOP(LVar0)
        EVT_SET(LVar1, LVar0)
        EVT_MUL(LVar1, 10)
        EVT_CALL(RotateModel, MODEL_o184, LVar1, 0, -1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245FC8_9DCFE8) = {
    EVT_LOOP(0)
        EVT_IF_EQ(GF_Quizmo_TakingQuiz, FALSE)
            EVT_CALL(PlaySoundAt, SOUND_77, 0, 0, 0, -180)
        EVT_END_IF
        EVT_CALL(RandInt, 30, LVar5)
        EVT_ADD(LVar5, 30)
        EVT_WAIT(LVar5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246054_9DD074) = {
    EVT_SET_GROUP(EVT_GROUP_0A)
    EVT_EXEC_GET_TID(N(D_80245FC8_9DCFE8), MV_Unk_03)
    EVT_LABEL(0)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH1_PROMISED_TO_HELP_KOOPER, STORY_CH4_BEGAN_PEACH_MISSION)
            EVT_KILL_THREAD(MV_Unk_03)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_IF_EQ(GF_NOK02_ConfrontedBobombs, TRUE)
        EVT_KILL_THREAD(MV_Unk_03)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 30, LVar0)
    EVT_ADD(LVar0, 10)
    EVT_WAIT(LVar0)
    EVT_CALL(RandInt, 10, LVar0)
    EVT_ADD(LVar0, 5)
    EVT_IF_EQ(GF_Quizmo_TakingQuiz, FALSE)
        EVT_CALL(N(func_80240970_9D7990))
    EVT_END_IF
    EVT_LOOP(LVar0)
        EVT_IF_EQ(AF_NOK_12, TRUE)
            EVT_KILL_THREAD(MV_Unk_03)
            EVT_CALL(TranslateGroup, MODEL_kameki, 0, 0, 0)
            EVT_LABEL(10)
            EVT_IF_EQ(AF_NOK_12, TRUE)
                EVT_WAIT(1)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_EXEC_GET_TID(N(D_80245FC8_9DCFE8), MV_Unk_03)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(RandInt, 5, LVar1)
        EVT_ADD(LVar1, 1)
        EVT_MUL(LVar1, -1)
        EVT_CALL(TranslateGroup, MODEL_kameki, 0, LVar1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateGroup, MODEL_kameki, 0, LVar1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802462A0_9DD2C0) = {
    EVT_CALL(RotateModel, MODEL_o149, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802462D0_9DD2F0) = {
    EVT_MULF(LVar0, EVT_FLOAT(-0.5))
    EVT_CALL(RotateModel, MODEL_o151, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o152, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o153, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o150, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246370_9DD390) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 45)
    EVT_CALL(TranslateModel, MODEL_o149, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o149, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802463DC_9DD3FC) = {
    EVT_CALL(RotateGroup, MODEL_g41, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024640C_9DD42C) = {
    EVT_SET(LVar1, LVar0)
    EVT_SUB(LVar1, 90)
    EVT_MULF(LVar0, EVT_FLOAT(1.0))
    EVT_CALL(RotateModel, MODEL_o156, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o154, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o155, LVar0, 0, 0, 1)
    EVT_MULF(LVar1, EVT_FLOAT(0.5))
    EVT_CALL(RotateModel, MODEL_o151, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o152, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o153, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o150, LVar1, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024653C_9DD55C) = {
    EVT_CALL(RotateModel, MODEL_o185, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024656C_9DD58C) = {
    EVT_CALL(RotateModel, MODEL_o183, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024659C_9DD5BC) = {
    EVT_SET(LVar2, LVar0)
    EVT_SET(LVar1, LVar0)
    EVT_SUB(LVar1, 90)
    EVT_DIVF(LVar1, -90)
    EVT_MULF(LVar2, EVT_FLOAT(0.5))
    EVT_CALL(RotateModel, MODEL_o171, LVar2, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o181, LVar2, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o182, LVar2, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o180, LVar2, 0, 0, 1)
    EVT_IF_NE(LVar1, 0)
        EVT_CALL(ScaleModel, MODEL_o308, 1, LVar1, 1)
        EVT_CALL(ScaleModel, MODEL_o307, 1, LVar1, 1)
        EVT_CALL(EnableModel, MODEL_o308, TRUE)
        EVT_CALL(EnableModel, MODEL_o307, TRUE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o308, FALSE)
        EVT_CALL(EnableModel, MODEL_o307, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246724_9DD744) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_WAIT(20)
            EVT_SET(LVar0, 0)
            EVT_LOOP(18)
                EVT_ADD(LVar0, 5)
                EVT_EXEC_WAIT(N(D_8024659C_9DD5BC))
            EVT_END_LOOP
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, 90)
            EVT_LOOP(18)
                EVT_SUB(LVar0, 5)
                EVT_EXEC_WAIT(N(D_8024659C_9DD5BC))
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802467EC_9DD80C) = {
    EVT_CALL(RotateModel, MODEL_o226, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024681C_9DD83C) = {
    EVT_MULF(LVar0, EVT_FLOAT(0.5))
    EVT_CALL(RotateModel, MODEL_o225, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o224, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o223, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o222, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802468BC_9DD8DC) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 45)
    EVT_CALL(TranslateModel, MODEL_o226, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o226, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246928_9DD948) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(AF_NOK_12, TRUE)
            EVT_IF_LT(GB_StoryProgress, STORY_CH1_PROMISED_TO_HELP_KOOPER)
                EVT_EXEC_WAIT(N(EVS_8024A8EC))
                EVT_SET(LVar0, -1)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SetGroupEnabled, MODEL_g111, 1)
        EVT_CASE_EQ(1)
            EVT_EXEC(N(EVS_8024A908))
            EVT_SET(AF_NOK_10, TRUE)
        EVT_CASE_EQ(2)
            EVT_SET(AF_NOK_10, FALSE)
        EVT_CASE_EQ(3)
            EVT_SET(AF_NOK_12, FALSE)
            EVT_CALL(SetGroupEnabled, MODEL_g111, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246A2C_9DDA4C) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_g45, 1)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_g45, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246AA8_9DDAC8) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_g63, 1)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_g63, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80246B24_9DDB44)[] = {
    NPC_KoloradoWife_02,
    -1
};

s32 N(D_80246B2C_9DDB4C)[] = {
    -1
};

s32 N(D_80246B30_9DDB50)[] = {
    NPC_Fuzzy_01,
    NPC_Kooper_02,
    -1
};

s32 N(D_80246B3C_9DDB5C)[] = {
    NPC_Bombomb_01,
    NPC_Bombomb_02,
    -1
};

s32 N(D_80246B48_9DDB68)[] = {
    NPC_KoopaKoot,
    -1
};

EvtScript N(EVS_80246B50) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_802462A0_9DD2C0)), EVT_PTR(N(D_802462D0_9DD2F0)), EVT_PTR(N(D_80246370_9DD390)), EVT_PTR(N(D_80246A2C_9DDA4C)), COLLIDER_o310, COLLIDER_o313, MODEL_sakuji, EVT_PTR(N(D_80246B2C_9DDB4C)))
        EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_802463DC_9DD3FC)), EVT_PTR(N(D_8024640C_9DD42C)), 0, 0, COLLIDER_o314, COLLIDER_o317, MODEL_o271, 0)
    EVT_ELSE
        EVT_IF_EQ(GF_NOK11_Defeated_KentC, TRUE)
            EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_802462A0_9DD2C0)), EVT_PTR(N(D_802462D0_9DD2F0)), EVT_PTR(N(D_80246370_9DD390)), EVT_PTR(N(D_80246A2C_9DDA4C)), COLLIDER_o310, COLLIDER_o313, MODEL_sakuji, EVT_PTR(N(D_80246B2C_9DDB4C)))
            EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_802463DC_9DD3FC)), EVT_PTR(N(D_8024640C_9DD42C)), 0, 0, COLLIDER_o314, COLLIDER_o317, MODEL_o271, 0)
        EVT_ELSE
            EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_802462A0_9DD2C0)), EVT_PTR(N(D_802462D0_9DD2F0)), EVT_PTR(N(D_80246370_9DD390)), EVT_PTR(N(D_80246A2C_9DDA4C)), COLLIDER_o310, COLLIDER_o313, MODEL_sakuji, EVT_PTR(N(D_80246B24_9DDB44)))
            EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_802463DC_9DD3FC)), EVT_PTR(N(D_8024640C_9DD42C)), 0, 0, COLLIDER_o314, COLLIDER_o317, MODEL_o271, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(MakeDoorAdvanced, 512, EVT_PTR(N(D_8024653C_9DD55C)), EVT_PTR(N(D_80246724_9DD744)), 0, EVT_PTR(N(D_80246928_9DD948)), COLLIDER_o284, COLLIDER_o287, MODEL_kameki, EVT_PTR(N(D_80246B30_9DDB50)))
        EVT_CALL(MakeDoorAdvanced, 514, EVT_PTR(N(D_8024656C_9DD58C)), EVT_PTR(N(D_80246724_9DD744)), 0, EVT_PTR(N(D_80246928_9DD948)), COLLIDER_o302, COLLIDER_o299, MODEL_kameki, EVT_PTR(N(D_80246B30_9DDB50)))
    EVT_ELSE
        EVT_CALL(MakeDoorAdvanced, 512, EVT_PTR(N(D_8024653C_9DD55C)), EVT_PTR(N(D_80246724_9DD744)), 0, EVT_PTR(N(D_80246928_9DD948)), COLLIDER_o284, COLLIDER_o287, MODEL_kameki, EVT_PTR(N(D_80246B3C_9DDB5C)))
        EVT_CALL(MakeDoorAdvanced, 514, EVT_PTR(N(D_8024656C_9DD58C)), EVT_PTR(N(D_80246724_9DD744)), 0, EVT_PTR(N(D_80246928_9DD948)), COLLIDER_o302, COLLIDER_o299, MODEL_kameki, EVT_PTR(N(D_80246B3C_9DDB5C)))
    EVT_END_IF
    EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_802467EC_9DD80C)), EVT_PTR(N(D_8024681C_9DD83C)), EVT_PTR(N(D_802468BC_9DD8DC)), EVT_PTR(N(D_80246AA8_9DDAC8)), COLLIDER_o226, COLLIDER_o283, MODEL_mura, EVT_PTR(N(D_80246B48_9DDB68)))
    EVT_SET(LVar0, 3)
    EVT_EXEC(N(D_80246A2C_9DDA4C))
    EVT_EXEC(N(D_80246928_9DD948))
    EVT_EXEC(N(D_80246AA8_9DDAC8))
    EVT_EXEC(N(D_80245F30_9DCF50))
    EVT_EXEC(N(D_80246054_9DD074))
    EVT_RETURN
    EVT_END
};
