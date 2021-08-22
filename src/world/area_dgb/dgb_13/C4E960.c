#include "dgb_13.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -450.0f, 0.0f, -40.0f, 0.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_13_tattle },
};

EvtSource N(80240050) = SCRIPT({
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

static s32 N(pad_E8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitWalk_802400F0) = EXIT_WALK_SCRIPT(26,  0, "dgb_03",  5);

EvtSource N(8024014C) = SCRIPT({
    bind N(exitWalk_802400F0) TRIGGER_FLOOR_ABOVE 5;
});

EvtSource N(main) = SCRIPT({
    SI_WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    await N(80240270);
    ModifyColliderFlags(0, 6, 0x7FFFFE00);
    await N(80240680);
    spawn N(80240050);
    SI_VAR(0) = N(8024014C);
    spawn EnterWalk;
    sleep 1;
});

EvtSource N(80240270) = SCRIPT({
    MakeItemEntity(ITEM_MEGA_RUSH, -910, 50, -206, 17, SI_SAVE_FLAG(1058));
    MakeItemEntity(ITEM_COIN, -530, 55, -190, 17, SI_SAVE_FLAG(1059));
    MakeItemEntity(ITEM_COIN, -510, 55, -175, 17, SI_SAVE_FLAG(1060));
    MakeItemEntity(ITEM_COIN, -510, 55, -205, 17, SI_SAVE_FLAG(1061));
    MakeItemEntity(ITEM_COIN, -490, 55, -160, 17, SI_SAVE_FLAG(1062));
    MakeItemEntity(ITEM_COIN, -490, 55, -190, 17, SI_SAVE_FLAG(1063));
    MakeItemEntity(ITEM_COIN, -490, 55, -220, 17, SI_SAVE_FLAG(1064));
});

static s32 N(pad_37C) = {
    0x00000000,
};

EvtSource N(80240380) = SCRIPT({
    MakeLerp(0, 30, 15, 0);
    loop {
        UpdateLerp();
        TranslateGroup(47, 0, 0, SI_VAR(0));
        UpdateColliderTransform(13);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
});

EvtSource N(80240424) = SCRIPT({
    MakeLerp(30, 0, 15, 0);
    loop {
        UpdateLerp();
        TranslateGroup(47, 0, 0, SI_VAR(0));
        UpdateColliderTransform(13);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
});

EvtSource N(802404C8) = SCRIPT({
    MakeLerp(0, 30, 15, 0);
    loop {
        UpdateLerp();
        TranslateGroup(53, 0, 0, SI_VAR(0));
        UpdateColliderTransform(17);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
});

EvtSource N(8024056C) = SCRIPT({
    MakeLerp(30, 0, 15, 0);
    loop {
        UpdateLerp();
        TranslateGroup(53, 0, 0, SI_VAR(0));
        UpdateColliderTransform(17);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
});

EvtSource N(80240610) = SCRIPT({
    if (SI_MAP_VAR(0) == 0) {
        await N(80240380);
        SI_MAP_VAR(0) = 1;
    } else {
        await N(80240424);
        SI_MAP_VAR(0) = 0;
    }
    unbind;
});

EvtSource N(80240680) = SCRIPT({
    ParentColliderToModel(13, 44);
    bind N(80240610) TRIGGER_WALL_PRESS_A 13;
});
