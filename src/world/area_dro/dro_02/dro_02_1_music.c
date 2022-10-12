#include "dro_02.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(dro_02_ENTRY_2)
        EVT_CASE_OR_EQ(dro_02_ENTRY_3)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_OUTPOST, 0, 8)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayRestMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayMoustafaMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_MOUSTAFA_THEME, 0, 8)
    EVT_RETURN
    EVT_END
};
