#include "flo_13.h"

EvtScript N(EVS_PlaySongForPlayerPos) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, -500)
        Goto(10)
    EndIf
    Label(0)
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            CaseDefault
                Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EndSwitch
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            IfLt(LVar0, -500)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Label(10)
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                Call(SetMusicTrack, 0, SONG_SUN_TOWER_CLOUDY, 0, 8)
            CaseDefault
                Call(SetMusicTrack, 0, SONG_SUN_TOWER_SUNNY, 0, 8)
        EndSwitch
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            IfGt(LVar0, -500)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetupMusic) = {
    Exec(N(EVS_PlaySongForPlayerPos))
    Return
    End
};

EvtScript N(EVS_PushPartnerSong) = {
    Call(SetMusicTrack, 0, SONG_NEW_PARTNER, 0, 8)
    Return
    End
};

EvtScript N(EVS_PopSong) = {
    Call(FadeOutMusic, 0, 500)
    Wait(15)
    Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
    Return
    End
};
