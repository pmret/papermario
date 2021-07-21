#include "sbk_01.h"
#include "message_ids.h"

#include "world/common/SpawnSunEffect.inc.c"

extern Script N(main);
extern NpcGroupList N(npcGroupList_802407D8);

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
    .tattle = { MSG_sbk_01_tattle },
};

Script N(exitWalk_802400E0) = EXIT_WALK_SCRIPT(60,  0, "sbk_00",  1);

Script N(exitWalk_8024013C) = EXIT_WALK_SCRIPT(60,  1, "sbk_02",  0);

Script N(exitWalk_80240198) = EXIT_WALK_SCRIPT(60,  3, "sbk_11",  2);

Script N(802401F4) = SCRIPT({
    bind N(exitWalk_802400E0) TRIGGER_FLOOR_ABOVE 7;
    bind N(exitWalk_8024013C) TRIGGER_FLOOR_ABOVE 3;
    bind N(exitWalk_80240198) TRIGGER_FLOOR_ABOVE 5;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_DRY_DRY_DESERT;
    SetSpriteShading(-1);
    if (STORY_PROGRESS == STORY_CH2_GOT_PULSE_STONE) {
        DisablePulseStone(0);
    }
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SetCamLeadPlayer(0, 0);
    MakeNpcs(0, N(npcGroupList_802407D8));
    N(SpawnSunEffect)();
    SetMusicTrack(0, SONG_DRY_DRY_DESERT, 0, 8);
    SI_VAR(0) = N(802401F4);
    spawn EnterWalk;
});
