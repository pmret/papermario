#include "dgb_00.h"
#include "message_ids.h"

ApiStatus N(func_80240000_BFA0A0)(ScriptInstance* script, s32 isInitialCall) {
    sprintf(&mapShapeName, "arn_20_shape");
    sprintf(&mapHitName, "arn_20_hit");
    sprintf(&mapTexName, "arn_tex");
    return ApiStatus_BLOCK;
}

EntryList N(entryList) = {
    { -733.0f, 0.0f, -8.0f, 90.0f },
    { 250.0f, 10.0f, -100.0f, 225.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_dgb_00_tattle },
};

Script N(80240110) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        } else {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
        }
    }
    ClearAmbientSounds(250);
});

static s32 N(pad_1B8)[] = {
    0x00000000, 0x00000000,
};

Script N(exitWalk_802401C0) = EXIT_WALK_SCRIPT(60,  0, "arn_04",  1);

Script N(exitDoubleDoor_8024021C) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 1;
    SI_VAR(1) = 18;
    SI_VAR(2) = 5;
    SI_VAR(3) = 7;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_01", 0);
    sleep 100;
});

Script N(802402D0) = SCRIPT({
    bind N(exitWalk_802401C0) to TRIGGER_FLOOR_ABOVE 15;
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_SMASHED_THE_BRIDGES {
            bind N(exitDoubleDoor_8024021C) to TRIGGER_WALL_PRESS_A 18;
        }
        < STORY_CH3_ESCAPED_TUBBAS_MANOR {}
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            spawn N(80240F50);
            await N(80241AA0);
        } else {
            bind N(exitDoubleDoor_8024021C) to TRIGGER_WALL_PRESS_A 18;
        }
    }
});

Script N(enterDoubleDoor_8024038C) = SCRIPT({
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) == 1) {
        spawn EnterSavePoint;
        spawn N(802402D0);
        return;
    }
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(0) = N(802402D0);
            spawn EnterWalk;
            sleep 1;
        }
        == 1 {
            if (STORY_PROGRESS >= STORY_CH3_TUBBA_SMASHED_THE_BRIDGES) {
                if (STORY_PROGRESS < STORY_CH3_ESCAPED_TUBBAS_MANOR) {
                    spawn N(802402D0);
                    spawn {
                        await N(8024103C);
                        await N(802413F4);
                    }
                    return;
                }
            }
            UseDoorSounds(3);
            SI_VAR(2) = 5;
            SI_VAR(3) = 7;
            await EnterDoubleDoor;
            spawn N(802402D0);
        }
        == 2 {
            spawn N(802402D0);
            spawn N(80242B84);
        }
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SI_SAVE_FLAG(1978) = 1;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 2) {
        MakeNpcs(0, N(npcGroupList_80243740));
    } else {
        MakeNpcs(0, N(npcGroupList_802436EC));
    }
    await N(makeEntities);
    spawn N(80240110);
    spawn N(enterDoubleDoor_8024038C);
});
