#include "dgb_14.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { 575.0f, 0.0f, 180.0f, 270.0f },
    { 575.0f, 210.0f, 180.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_14_tattle },
};

Script N(80240060) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        }
        else {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
    }
});

static s32 N(pad_F8)[] = {
    0x00000000, 0x00000000,
};

Script N(exitDoubleDoor_80240100) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 1;
    SI_VAR(1) = 14;
    SI_VAR(2) = 24;
    SI_VAR(3) = 22;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_03", 3);
    sleep 100;
});

Script N(exitDoubleDoor_802401B4) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 0;
    SI_VAR(1) = 18;
    SI_VAR(2) = 19;
    SI_VAR(3) = 17;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_15", 0);
    sleep 100;
});

Script N(enterDoubleDoor_80240268) = SCRIPT({
    UseDoorSounds(3);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(2) = 24;
            SI_VAR(3) = 22;
            await EnterDoubleDoor;
        }
        == 1 {
            DisablePlayerInput(TRUE);
            SI_VAR(2) = 19;
            SI_VAR(3) = 17;
            await EnterDoubleDoor;
            if (SI_AREA_FLAG(1) == 1) {
                sleep 5;
                SetPlayerAnimation(ANIM_8001D);
                sleep 20;
                SetPlayerAnimation(ANIM_10002);
            }
            DisablePlayerInput(FALSE);
        }
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    await N(makeEntities);
    spawn N(80240060);
    bind N(exitDoubleDoor_80240100) to TRIGGER_WALL_PRESS_A 14;
    bind N(exitDoubleDoor_802401B4) to TRIGGER_WALL_PRESS_A 18;
    spawn N(enterDoubleDoor_80240268);
});

static s32 N(pad_47C) = {
    0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA564, 500, 60, 75, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1065));
});
