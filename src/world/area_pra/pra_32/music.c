#include "pra_32.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GB_StoryProgress, STORY_CH7_DEFEATED_CRYSTAL_KING)
        Call(FadeOutMusic, 0, 500)
    Else
        Call(SetMusic, 0, SONG_CRYSTAL_PALACE, 0, VOL_LEVEL_FULL)
    EndIf
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Return
    End
};
