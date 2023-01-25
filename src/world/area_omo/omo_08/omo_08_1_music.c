#include "omo_08.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    EVT_ELSE
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, omo_08_ENTRY_0)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
        EVT_ELSE
            EVT_CALL(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
