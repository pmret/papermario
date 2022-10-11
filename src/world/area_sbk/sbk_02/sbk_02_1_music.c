#include "sbk_02.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(sbk_02_ENTRY_6)
        EVT_CASE_OR_EQ(sbk_02_ENTRY_7)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
