#include "sbk_00.h"
#include "message_ids.h"

#include "world/common/SpawnSunEffect.inc.c"

EntryList N(entryList) = {
    { -475.0f, 0.0f, 0.0f, 90.0f },
    { 475.0f, 0.0f, 0.0f, 270.0f },
    { 0.0f, 0.0f, -475.0f, 180.0f },
    { 0.0f, 0.0f, 475.0f, 0.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_sbk_00_tattle },
};

EvtSource N(exitWalk_802400E0) = EXIT_WALK_SCRIPT(60,  1, "sbk_01",  0);

EvtSource N(exitWalk_8024013C) = EXIT_WALK_SCRIPT(60,  3, "sbk_10",  2);

EvtSource N(80240198) = {
    EVT_BIND_TRIGGER(N(exitWalk_802400E0), TRIGGER_FLOOR_ABOVE, 3, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024013C), TRIGGER_FLOOR_ABOVE, 6, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 10)
    EVT_CALL(SetSpriteShading, -1)
    EVT_IF_EQ(EVT_SAVE_VAR(0), -63)
        EVT_CALL(DisablePulseStone, 0)
    EVT_END_IF
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80240768)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_CALL(N(SpawnSunEffect))
    EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(80240198)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};
