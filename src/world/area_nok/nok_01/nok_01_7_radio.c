#include "nok_01.h"

s16 N(D_80250810_9D5BF0)[] = {
    0, 2, 1, 4
};

API_CALLABLE(N(func_802427C0_9C7BA0)) {
    Bytecode* args = script->ptrReadPos;

    evt_get_variable(script, *args++);
    snd_ambient_80055448(16);
    snd_ambient_80055760(4);
    au_ambience_set_volume(0, 250, 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242804_9C7BE4)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    snd_ambient_80055848(N(D_80250810_9D5BF0)[idx]);
    au_ambience_set_volume(N(D_80250810_9D5BF0)[idx], 1500, 127);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242858_9C7C38)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    au_ambience_set_volume(N(D_80250810_9D5BF0)[idx], 1500, 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242898_9C7C78)) {
    snd_ambient_80055848(4);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802428B8_9C7C98)) {
    snd_ambient_800557CC(100);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802428D8_9C7CB8)) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    snd_ambient_80055848(N(D_80250810_9D5BF0)[index]);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242910_9C7CF0)) {
    gPlayerData.tradeEventStartTime = gPlayerData.frameCounter;
    return ApiStatus_DONE2;
}

EvtScript N(D_80250818_9D5BF8) = {
    EVT_SWITCH(GB_TradingEvent_Count)
        EVT_CASE_EQ(0)
            EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
                EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
                    EVT_CALL(SwitchMessage, MSG_CH1_0028)
                EVT_ELSE
                    EVT_CALL(SwitchMessage, MSG_CH1_0029)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SwitchMessage, MSG_CH1_002A)
                EVT_SET(GF_TradingEvent1_Active, TRUE)
                EVT_CALL(N(func_80242910_9C7CF0))
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_IF_LT(GB_StoryProgress, STORY_CH3_BEGAN_PEACH_MISSION)
                EVT_CALL(SwitchMessage, MSG_CH1_002E)
            EVT_ELSE
                EVT_CALL(SwitchMessage, MSG_CH1_002B)
                EVT_SET(GF_TradingEvent2_Active, TRUE)
                EVT_CALL(N(func_80242910_9C7CF0))
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_LT(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
                EVT_CALL(SwitchMessage, MSG_CH1_002E)
            EVT_ELSE
                EVT_CALL(SwitchMessage, MSG_CH1_002C)
                EVT_SET(GF_TradingEvent3_Active, TRUE)
                EVT_CALL(N(func_80242910_9C7CF0))
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(SwitchMessage, MSG_CH1_002D)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802509C0_9D5DA0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(2)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_8000E)
    EVT_WAIT(7)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_ADD(AB_NOK_0, 1)
    EVT_IF_GE(AB_NOK_0, 4)
        EVT_SET(AB_NOK_0, 0)
    EVT_END_IF
    EVT_IF_NE(GF_MAC05_SimonGotMelody, TRUE)
        EVT_IF_EQ(AB_NOK_0, 2)
            EVT_ADD(AB_NOK_0, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(func_802428D8_9C7CB8), AB_NOK_0)
    EVT_SWITCH(AB_NOK_0)
        EVT_CASE_EQ(0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_002F, 160, 40)
        EVT_CASE_EQ(1)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_0030, 160, 40)
        EVT_CASE_EQ(2)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_0031, 160, 40)
        EVT_CASE_EQ(3)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_0032, 160, 40)
            EVT_EXEC_WAIT(N(D_80250818_9D5BF8))
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80250B70) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(D_802509C0_9D5DA0)), TRIGGER_WALL_PRESS_A, COLLIDER_o235, 1, 0)
    EVT_RETURN
    EVT_END
};
