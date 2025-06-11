#include "kzn_19.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            Call(GetEntryID, LVar0)
            IfEq(LVar0, kzn_19_ENTRY_1)
                Call(FadeOutMusic, 0, 500)
                Call(PlayAmbientSounds, AMBIENT_LAVA_1)
                Return
            EndIf
            EndIf //@bug extra endif
        CaseGe(STORY_CH5_MT_LAVA_LAVA_ERUPTING)
            Call(PlaySound, SOUND_LOOP_RUMBLE)
    EndSwitch
    Call(SetMusic, 0, SONG_MT_LAVALAVA, 0, VOL_LEVEL_FULL)
    Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    Return
    End
};
