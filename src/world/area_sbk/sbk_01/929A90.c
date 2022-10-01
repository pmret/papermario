#include "sbk_01.h"
#include "message_ids.h"

#include "world/common/SpawnSunEffect.inc.c"

extern EvtScript N(main);
extern NpcGroupList N(npcGroupList_802407D8);

EntryList N(entryList) = {
    { -475.0f, 0.0f, 0.0f, 90.0f },
    { 475.0f, 0.0f, 0.0f, 270.0f },
    { 0.0f, 0.0f, -475.0f, 180.0f },
    { 0.0f, 0.0f, 475.0f, 0.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_01 },
};

EvtScript N(exitWalk_802400E0) = EVT_EXIT_WALK(60,  0, "sbk_00",  1);

EvtScript N(exitWalk_8024013C) = EVT_EXIT_WALK(60,  1, "sbk_02",  0);

EvtScript N(exitWalk_80240198) = EVT_EXIT_WALK(60,  3, "sbk_11",  2);

EvtScript N(802401F4) = {
    EVT_BIND_TRIGGER(N(exitWalk_802400E0), TRIGGER_FLOOR_ABOVE, 7, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024013C), TRIGGER_FLOOR_ABOVE, 3, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80240198), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 10)
    EVT_CALL(SetSpriteShading, -1)
    EVT_IF_EQ(GB_StoryProgress, -63)
        EVT_CALL(DisablePulseStone, 0)
    EVT_END_IF
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802407D8)))
    EVT_CALL(N(SpawnSunEffect))
    EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    EVT_SET(LVar0, EVT_PTR(N(802401F4)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};
