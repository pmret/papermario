#include "dgb_17.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -570.0f, 0.0f, 180.0f, 90.0f },
    { -180.0f, 0.0f, 180.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_17_tattle },
};

EvtSource N(80240060) = SCRIPT({
    match SI_STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        } else {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
    }
});

static s32 N(pad_F8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitDoubleDoor_80240100) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 0;
    SI_VAR(1) = 7;
    SI_VAR(2) = 14;
    SI_VAR(3) = 16;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_15", 1);
    sleep 100;
});

EvtSource N(exitDoubleDoor_802401B4) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 1;
    SI_VAR(1) = 11;
    SI_VAR(2) = 21;
    SI_VAR(3) = 19;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_01", 5);
    sleep 100;
});

EvtSource N(80240268) = SCRIPT({
    bind N(exitDoubleDoor_80240100) TRIGGER_WALL_PRESS_A 7;
    bind N(exitDoubleDoor_802401B4) TRIGGER_WALL_PRESS_A 11;
});

EvtSource N(enterDoubleDoor_802402B0) = SCRIPT({
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) == 1) {
        spawn EnterSavePoint;
        spawn N(80240268);
        return;
    }
    UseDoorSounds(3);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(2) = 14;
            SI_VAR(3) = 16;
            await EnterDoubleDoor;
        }
        == 1 {
            SI_VAR(2) = 21;
            SI_VAR(3) = 19;
            await EnterDoubleDoor;
        }
    }
    spawn N(80240268);
});

EvtSource N(main) = SCRIPT({
    SI_WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    await N(makeEntities);
    spawn N(80240060);
    spawn N(enterDoubleDoor_802402B0);
});

EvtSource N(makeEntities) = SCRIPT({
    MakeEntity(0x802E9A18, -300, 60, 75, 0, MAKE_ENTITY_END);
    MakeEntity(0x802EA7E0, -450, 60, 75, 0, MAKE_ENTITY_END);
});
