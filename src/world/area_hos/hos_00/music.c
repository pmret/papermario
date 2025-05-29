#include "hos_00.h"

EvtScript N(EVS_PlayToadTownSong) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusic, 0, SONG_SHY_GUY_INVASION, 0, VOL_LEVEL_6)
        CaseDefault
            Call(SetMusic, 0, SONG_TOAD_TOWN, 0, VOL_LEVEL_6)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PlayMusicByPosition) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_00_ENTRY_0)
            Exec(N(EVS_PlayToadTownSong))
        EndCaseGroup
        CaseOrEq(hos_00_ENTRY_1)
        CaseOrEq(hos_00_ENTRY_2)
            Call(SetMusic, 0, SONG_SHOOTING_STAR_SUMMIT, 0, VOL_LEVEL_FULL)
        EndCaseGroup
    EndSwitch
    IfNe(LVar0, 0)
        Goto(20)
    EndIf
    Label(10)
        Wait(1)
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        IfGt(LVar1, 210)
            Call(FadeOutMusic, 0, 833)
            Wait(25)
            Call(SetMusic, 0, SONG_SHOOTING_STAR_SUMMIT, 0, VOL_LEVEL_FULL)
            Wait(30)
            Goto(20)
        EndIf
        Goto(10)
    Label(20)
        Wait(1)
        IfEq(GB_StoryProgress, STORY_CH0_BEGAN_PEACH_MISSION)
            Goto(20)
        EndIf
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        IfLt(LVar1, -55)
            Call(FadeOutMusic, 0, 833)
            Wait(25)
            Exec(N(EVS_PlayToadTownSong))
            Wait(30)
            Goto(10)
        EndIf
        Goto(20)
    Return
    End
};

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, hos_00_ENTRY_3)
        Call(SetMusic, 0, SONG_STARSHIP_THEME, 0, VOL_LEVEL_FULL)
    Else
        Exec(N(EVS_PlayMusicByPosition))
    EndIf
    Return
    End
};

EvtScript N(EVS_PlayKammyKoopaSong) = {
    Call(SetMusic, 0, SONG_KAMMY_KOOPA_THEME, 0, VOL_LEVEL_FULL)
    Return
    End
};
