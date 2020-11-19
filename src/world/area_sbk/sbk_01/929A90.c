#include "sbk_01.h"

#include "world/common/SpawnSunEffect.inc.c"

Script M(Main);
s32 M(npcGroupList_802407D8)[];

Vec4f M(entryList)[] = {
    { -475.0f, 0.0f, 0.0f, 90.0f },
    { 475.0f, 0.0f, 0.0f, 270.0f },
    { 0.0f, 0.0f, -475.0f, 180.0f },
    { 0.0f, 0.0f, 475.0f, 0.0f },
};

MapConfig M(config) = {
    .main = M(Main),
    .entryList = M(entryList),
    .entryCount = ARRAY_COUNT(M(entryList)),
    .background = &gBackgroundImage,
    .tattle = 0x190061,
};

Script M(ExitWalk_802400E0) = SCRIPT({
    group 27
    UseExitHeading(60, 0)
    spawn ExitWalk
    GotoMap("sbk_00", 1)
    sleep 100
});

Script M(ExitWalk_8024013C) = SCRIPT({
    group 27
    UseExitHeading(60, 1)
    spawn ExitWalk
    GotoMap("sbk_02", 0)
    sleep 100
});

Script M(ExitWalk_80240198) = SCRIPT({
    group 27
    UseExitHeading(60, 3)
    spawn ExitWalk
    GotoMap("sbk_11", 2)
    sleep 100
});

Script M(Script_802401F4) = SCRIPT({
    bind M(ExitWalk_802400E0) to 524288 7
    bind M(ExitWalk_8024013C) to 524288 3
    bind M(ExitWalk_80240198) to 524288 5
});

Script M(Main) = SCRIPT({
    SI_SAVE_VAR(425) = 10
    SetSpriteShading(-1)
    if SI_SAVE_VAR(0) == 0xFFFFFFC1 {
        DisablePulseStone(0)
    }
    SetCamPerspective(0, 3, 25, 16, 4096)
    SetCamBGColor(0, 0, 0, 0)
    SetCamEnabled(0, 1)
    SetCamLeadPlayer(0, 0)
    MakeNpcs(0, M(npcGroupList_802407D8))
    SpawnSunEffect()
    SetMusicTrack(0, 23, 0, 8)
    SI_VAR(0) = M(Script_802401F4)
    spawn EnterWalk
});
