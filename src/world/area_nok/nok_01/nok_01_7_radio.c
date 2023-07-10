#include "nok_01.h"
#include "sprite/player.h"

s16 N(StationMseqMapping)[] = {
    0, 2, 1, 4
};

API_CALLABLE(N(InitializeRadio)) {
    Bytecode* args = script->ptrReadPos;

    evt_get_variable(script, *args++);
    snd_load_ambient(AMBIENT_RADIO);
    snd_ambient_80055760(4);
    snd_ambient_set_volume(0, 250, 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetRadioVolumeMax)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    snd_ambient_play_only(N(StationMseqMapping)[idx]);
    snd_ambient_set_volume(N(StationMseqMapping)[idx], 1500, 127);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetRadioVolumeMute)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    snd_ambient_set_volume(N(StationMseqMapping)[idx], 1500, 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242898_9C7C78)) {
    snd_ambient_play_only(4);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802428B8_9C7C98)) {
    snd_ambient_stop_all(100);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetRadioStation)) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    snd_ambient_play_only(N(StationMseqMapping)[index]);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetTradeEventStartTime)) {
    gPlayerData.tradeEventStartTime = gPlayerData.frameCounter;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_InitiateTradingEvent) = {
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
                EVT_CALL(N(SetTradeEventStartTime))
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_IF_LT(GB_StoryProgress, STORY_CH3_BEGAN_PEACH_MISSION)
                EVT_CALL(SwitchMessage, MSG_CH1_002E)
            EVT_ELSE
                EVT_CALL(SwitchMessage, MSG_CH1_002B)
                EVT_SET(GF_TradingEvent2_Active, TRUE)
                EVT_CALL(N(SetTradeEventStartTime))
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_LT(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
                EVT_CALL(SwitchMessage, MSG_CH1_002E)
            EVT_ELSE
                EVT_CALL(SwitchMessage, MSG_CH1_002C)
                EVT_SET(GF_TradingEvent3_Active, TRUE)
                EVT_CALL(N(SetTradeEventStartTime))
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(SwitchMessage, MSG_CH1_002D)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_Radio) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(2)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_RideLaki)
    EVT_WAIT(7)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_ADD(AB_NOK_0, 1)
    EVT_IF_GE(AB_NOK_0, 4)
        EVT_SET(AB_NOK_0, 0)
    EVT_END_IF
    EVT_IF_NE(GF_MAC05_SimonGotMelody, TRUE)
        EVT_IF_EQ(AB_NOK_0, 2)
            EVT_ADD(AB_NOK_0, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(SetRadioStation), AB_NOK_0)
    EVT_SWITCH(AB_NOK_0)
        EVT_CASE_EQ(0) // island sounds
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_002F, 160, 40)
        EVT_CASE_EQ(1) // golden oldies
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_0030, 160, 40)
        EVT_CASE_EQ(2) // hot hits
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_0031, 160, 40)
        EVT_CASE_EQ(3) // information
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_0032, 160, 40)
            EVT_EXEC_WAIT(N(EVS_InitiateTradingEvent))
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupRadio) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_Radio)), TRIGGER_WALL_PRESS_A, COLLIDER_o235, 1, 0)
    EVT_RETURN
    EVT_END
};
