#include "sbk_00.h"

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
    .tattle = 0x190060,
};

Script N(ExitWalk_802400E0) = SCRIPT({
    group 27;
    UseExitHeading(60, 1);
    spawn ExitWalk;
    GotoMap("sbk_01", 0);
    sleep 100;
});

Script N(ExitWalk_8024013C) = SCRIPT({
    group 27;
    UseExitHeading(60, 3);
    spawn ExitWalk;
    GotoMap("sbk_10", 2);
    sleep 100;
});

Script N(Script_80240198) = SCRIPT({
    bind N(ExitWalk_802400E0) to 524288 3;
    bind N(ExitWalk_8024013C) to 524288 6;
});

Script N(Main) = SCRIPT({
    SI_SAVE_VAR(425) = 10;
    SetSpriteShading(-1);
    if (SI_SAVE_VAR(0) == STORY_CH2_GOT_PULSE_STONE) {
        DisablePulseStone(0);
    }
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SetCamLeadPlayer(0, 0);
    MakeNpcs(0, N(npcGroupList_80240768));
    await N(MakeEntities);
    N(SpawnSunEffect)();
    SetMusicTrack(0, Song_DRY_DRY_DESERT, 0, 8);
    SI_VAR(0) = N(Script_80240198);
    spawn EnterWalk;
});
