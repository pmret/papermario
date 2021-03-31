#include "sbk_00.h"
#include "message_ids.h"

#include "world/common/SpawnSunEffect.inc.c"

Script N(Main);
s32 N(npcGroupList_80240768)[];

Vec4f N(entryList)[] = {
    { -475.0f, 0.0f, 0.0f, 90.0f },
    { 475.0f, 0.0f, 0.0f, 270.0f },
    { 0.0f, 0.0f, -475.0f, 180.0f },
    { 0.0f, 0.0f, 475.0f, 0.0f },
};

MapConfig N(config) = {
    .main = N(Main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = MSG_sbk_00_tattle,
};

Script N(ExitWalk_802400E0) = EXIT_WALK_SCRIPT(60, 1, "sbk_01", 0);
Script N(ExitWalk_8024013C) = EXIT_WALK_SCRIPT(60, 3, "sbk_10", 2);

Script N(Script_80240198) = SCRIPT({
    bind N(ExitWalk_802400E0) to TRIGGER_FLOOR_ABOVE 3;
    bind N(ExitWalk_8024013C) to TRIGGER_FLOOR_ABOVE 6;
});

Script N(Main) = SCRIPT({
    WORLD_LOCATION = LOCATION_DRY_DRY_DESERT;
    SetSpriteShading(-1);
    if (STORY_PROGRESS == STORY_CH2_GOT_PULSE_STONE) {
        DisablePulseStone(0);
    }
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SetCamLeadPlayer(0, 0);
    MakeNpcs(0, N(npcGroupList_80240768));
    await N(MakeEntities);
    N(SpawnSunEffect)();
    SetMusicTrack(0, SONG_DRY_DRY_DESERT, 0, 8);
    SI_VAR(0) = N(Script_80240198);
    spawn EnterWalk;
});
