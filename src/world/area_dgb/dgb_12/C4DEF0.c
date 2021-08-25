#include "dgb_12.h"
#include "message_ids.h"
#include "common.h"

EntryList N(entryList) = {
    { -500.0f, 0.0f, -40.0f, 0.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_12_tattle },
};

EvtSource N(80240310) = SCRIPT({
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

static s32 N(pad_3A8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitSingleDoor_802403B0) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(0);
    SI_VAR(0) = 0;
    SI_VAR(1) = 8;
    SI_VAR(2) = 14;
    SI_VAR(3) = -1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("dgb_09", 2);
    sleep 100;
});

EvtSource N(enterSingleDoor_80240464) = SCRIPT({
    UseDoorSounds(0);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(2) = 14;
            SI_VAR(3) = -1;
            await EnterSingleDoor;
        }
    }
});

EvtSource N(main) = SCRIPT({
    SI_WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    await N(makeEntities);
    spawn N(802405E0);
    spawn N(80240310);
    bind N(exitSingleDoor_802403B0) TRIGGER_WALL_PRESS_A 8;
    spawn N(enterSingleDoor_80240464);
});

s32 N(lavaResetList_802405C0)[] = {
    0x00000005, 0xC3FB8000, 0x00000000, 0xC27C0000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(802405E0) = SCRIPT({
    group 239;
    ModifyColliderFlags(3, 12, 0x00000002);
    ModifyColliderFlags(3, 0, 0x00000002);
    ModifyColliderFlags(3, 14, 0x00000002);
    spawn {
        ResetFromLava(N(lavaResetList_802405C0));
    }
    sleep 50;
    TranslateModel(19, 0, 0, 0);
    ParentColliderToModel(12, 19);
    loop {
        spawn {
            sleep 2;
            ModifyColliderFlags(0, 0, 0x7FFFFE00);
        }
        MakeLerp(0, -35, 15, 0);
        loop {
            UpdateLerp();
            TranslateModel(19, 0, SI_VAR(0), 0);
            UpdateColliderTransform(12);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        sleep 60;
        PlaySoundAtCollider(0, 8339, 0);
        spawn {
            ModifyColliderFlags(1, 0, 0x7FFFFE00);
        }
        MakeLerp(-35, 0, 4, 0);
        loop {
            UpdateLerp();
            TranslateModel(19, 0, SI_VAR(0), 0);
            UpdateColliderTransform(12);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        sleep 35;
    }
});

static s32 N(pad_868)[] = {
    0x00000000, 0x00000000,
};

#include "world/common/StashVars.inc.c"

EvtSource N(80240874) = SCRIPT({
    group 0;
    SetTimeFreezeMode(TIME_FREEZE_FULL);
    sleep 40;
    ShowGotItem(SI_VAR(0), 0, 0);
    SetTimeFreezeMode(TIME_FREEZE_NORMAL);
    return;
});

EvtSource N(802408DC) = SCRIPT({
    DisablePlayerInput(TRUE);
    SI_VAR(0) = SI_VAR(10);
    if (SI_VAR(10) != 0) {
        await N(80240874);
    }
    match SI_VAR(11) {
        == 0 {
            AddItem(SI_VAR(10), SI_VAR(0));
        }
        == 1 {
            AddKeyItem(SI_VAR(10));
        }
        == 2 {
            AddBadge(SI_VAR(10), SI_VAR(0));
        }
    }
    sleep 15;
    DisablePlayerInput(FALSE);
});

EvtSource N(802409BC) = SCRIPT({
    SI_VAR(10) = 19;
    SI_VAR(11) = 1;
    SI_SAVE_FLAG(1057) = 1;
    await N(802408DC);
});

EvtSource N(makeEntities) = SCRIPT({
    MakeEntity(0x802EAE30, -225, 0, -245, 0, ITEM_NONE, MAKE_ENTITY_END);
    AssignFlag(SI_SAVE_FLAG(1057));
    AssignScript(N(802409BC));
});

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
