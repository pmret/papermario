#include "kmr_20.h"

API_CALLABLE(N(FadeOutAmbientSounds)){
    snd_ambient_stop_slow(0, 500);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(FadeOutMusic, 0, 500)
        EndCaseGroup
        CaseGe(STORY_EPILOGUE)
            Call(FadeOutMusic, 0, 500)
        EndCaseGroup
        CaseDefault
            Call(SetMusic, 0, SONG_MARIO_BROS_HOUSE, 0, VOL_LEVEL_FULL)
    EndSwitch
    Thread
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseEq(kmr_20_ENTRY_0)
                Wait(300)
                Call(PlayAmbientSounds, AMBIENT_BIRDS)
            CaseDefault
                Call(PlayAmbientSounds, AMBIENT_BIRDS)
        EndSwitch
    EndThread
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusic, 0, SONG_TAKING_REST, 0, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_FadeOutAmbientSounds) = {
    Call(N(FadeOutAmbientSounds))
    Return
    End
};
