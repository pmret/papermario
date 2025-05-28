#include "nok_01.h"
#include "sprite/player.h"

s16 N(StationMseqMapping)[] = {
    0, 2, 1, 4
};

API_CALLABLE(N(InitializeRadio)) {
    Bytecode* args = script->ptrReadPos;

    evt_get_variable(script, *args++);
    snd_load_ambient(AMBIENT_RADIO);
    snd_ambient_radio_setup(4);
    snd_ambient_set_volume(0, 250, 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetRadioVolumeMax)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    snd_ambient_radio_select(N(StationMseqMapping)[idx]);
    snd_ambient_set_volume(N(StationMseqMapping)[idx], 1500, 127);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetRadioVolumeMute)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    snd_ambient_set_volume(N(StationMseqMapping)[idx], 1500, 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(MuteAllRadioStations)) {
    snd_ambient_radio_select(4);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(StopAllRadioStations)) {
    snd_ambient_radio_stop(100);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetRadioStation)) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    snd_ambient_radio_select(N(StationMseqMapping)[index]);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetTradeEventStartTime)) {
    gPlayerData.tradeEventStartTime = gPlayerData.frameCounter;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_InitiateTradingEvent) = {
    Switch(GB_TradingEvent_Count)
        CaseEq(0)
            IfLt(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
                IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
                    Call(SwitchMessage, MSG_CH1_0028)
                Else
                    Call(SwitchMessage, MSG_CH1_0029)
                EndIf
            Else
                Call(SwitchMessage, MSG_CH1_002A)
                Set(GF_TradingEvent1_Active, TRUE)
                Call(N(SetTradeEventStartTime))
            EndIf
        CaseEq(1)
            IfLt(GB_StoryProgress, STORY_CH3_BEGAN_PEACH_MISSION)
                Call(SwitchMessage, MSG_CH1_002E)
            Else
                Call(SwitchMessage, MSG_CH1_002B)
                Set(GF_TradingEvent2_Active, TRUE)
                Call(N(SetTradeEventStartTime))
            EndIf
        CaseEq(2)
            IfLt(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
                Call(SwitchMessage, MSG_CH1_002E)
            Else
                Call(SwitchMessage, MSG_CH1_002C)
                Set(GF_TradingEvent3_Active, TRUE)
                Call(N(SetTradeEventStartTime))
            EndIf
        CaseEq(3)
            Call(SwitchMessage, MSG_CH1_002D)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Interact_Radio) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(2)
    Call(SetPlayerAnimation, ANIM_MarioW2_RideLaki)
    Wait(7)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Add(AB_NOK_0, 1)
    IfGe(AB_NOK_0, 4)
        Set(AB_NOK_0, 0)
    EndIf
    IfNe(GF_MAC05_SimonGotMelody, TRUE)
        IfEq(AB_NOK_0, 2)
            Add(AB_NOK_0, 1)
        EndIf
    EndIf
    Call(N(SetRadioStation), AB_NOK_0)
    Switch(AB_NOK_0)
        CaseEq(0) // island sounds
            Call(ShowMessageAtScreenPos, MSG_CH1_002F, 160, 40)
        CaseEq(1) // golden oldies
            Call(ShowMessageAtScreenPos, MSG_CH1_0030, 160, 40)
        CaseEq(2) // hot hits
            Call(ShowMessageAtScreenPos, MSG_CH1_0031, 160, 40)
        CaseEq(3) // information
            Call(ShowMessageAtScreenPos, MSG_CH1_0032, 160, 40)
            ExecWait(N(EVS_InitiateTradingEvent))
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupRadio) = {
    BindTrigger(Ref(N(EVS_Interact_Radio)), TRIGGER_WALL_PRESS_A, COLLIDER_o235, 1, 0)
    Return
    End
};
