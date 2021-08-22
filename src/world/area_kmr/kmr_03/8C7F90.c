#include "kmr_03.h"
#include "message_ids.h"
#include "../../partners.h"

#include "world/common/UnkFunc41.inc.c"

#include "world/common/CheckPartnerFlags1000.inc.c"

EntryList N(entryList) = {
    { -340.0f, 0.0f, 348.0f, 48.0f },
    { 480.0f, 0.0f, 0.0f, 270.0f },
    { -310.0f, 20.0f, -80.0f, 135.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_kmr_03_tattle },
};

EvtSource N(802406C0) = SCRIPT({
    SetMusicTrack(0, SONG_PLEASANT_PATH, 0, 8);
});
