#include "kkj_13.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
        CaseGe(STORY_CH8_REACHED_PEACHS_CASTLE)
            IfEq(GF_KKJ13_BowserTaunts, FALSE)
                Thread
                    Wait(30)
                    Call(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
                EndThread
            Else
                Call(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
            EndIf
        CaseDefault
    EndSwitch
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Return
    End
};
