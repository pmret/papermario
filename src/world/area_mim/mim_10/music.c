#include "mim_10.h"

EvtScript N(EVS_SetToadTownMusic) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 8)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetupMusic) = {
    IfEq(GB_StoryProgress, STORY_CH3_SAW_BOO_ENTER_FOREST)
        Exec(N(EVS_SetToadTownMusic))
        Return
    EndIf
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(N(EVS_SetToadTownMusic))
        Return
    EndIf
    Call(GetPlayerPos, LVar1, LVar2, LVar3)
    IfLt(LVar1, 0)
        Exec(N(EVS_SetToadTownMusic))
        Wait(30)
    Else
        Call(SetMusicTrack, 0, SONG_FOREVER_FOREST, 0, 8)
        Wait(15)
        Call(ClearAmbientSounds, 250)
        Wait(15)
        Goto(20)
    EndIf
    Label(10)
    Wait(1)
    Call(GetPlayerPos, LVar1, LVar2, LVar3)
    IfGe(LVar1, 100)
        Call(FadeOutMusic, 0, 1000)
        Wait(15)
        Wait(15)
        Call(SetMusicTrack, 0, SONG_FOREVER_FOREST, 0, 8)
        Wait(30)
        Goto(20)
    EndIf
    Goto(10)
    Label(20)
    Wait(1)
    Call(GetPlayerPos, LVar1, LVar2, LVar3)
    IfLt(LVar1, 0)
        Call(FadeOutMusic, 0, 1000)
        Wait(30)
        Exec(N(EVS_SetToadTownMusic))
        Wait(30)
        Goto(10)
    EndIf
    Goto(20)
    Return
    End
};
