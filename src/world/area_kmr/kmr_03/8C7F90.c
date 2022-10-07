#include "kmr_03.h"
#include "message_ids.h"
#include "../../partners.h"

#include "world/common/util/ChangeNpcToPartner.inc.c"

#include "world/common/CheckPartnerFlags1000.inc.c"

EntryList N(entryList) = {
    { -340.0f, 0.0f, 348.0f, 48.0f },
    { 480.0f, 0.0f, 0.0f, 270.0f },
    { -310.0f, 20.0f, -80.0f, 135.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_03 },
};

EvtScript N(802406C0) = {
    EVT_CALL(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, 8)
    EVT_RETURN
    EVT_END
};
