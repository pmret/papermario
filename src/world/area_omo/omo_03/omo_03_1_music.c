#include "omo_03.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    EVT_ELSE
        EVT_CALL(GetEntryID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_RANGE(omo_03_ENTRY_2, omo_03_ENTRY_3)
                EVT_CALL(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
            EVT_CASE_EQ(omo_03_ENTRY_5)
                EVT_CALL(FadeInMusic, 0, SONG_SHY_GUY_TOYBOX, 0, 3000, 0, 127)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
