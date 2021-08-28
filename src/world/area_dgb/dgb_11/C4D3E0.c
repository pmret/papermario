#include "dgb_11.h"
#include "message_ids.h"

extern s32 D_000001E4;

EntryList N(entryList) = {
    { 450.0f,   0.0f,  -40.0f,   0.0f },
    { 500.0f, 180.0f, -100.0f, 180.0f },
    { 500.0f, 180.0f, -250.0f, 180.0f },
    { 375.0f, 180.0f, -250.0f, 180.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_11_tattle },
};

EvtSource N(802400D0) = SCRIPT({
    match EVT_STORY_PROGRESS {
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

static s32 N(pad_168)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitSingleDoor_80240170) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(0);
    EVT_VAR(0) = 0;
    EVT_VAR(1) = 11;
    EVT_VAR(2) = 21;
    EVT_VAR(3) = -1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("dgb_02", 3);
    sleep 100;
});

EvtSource N(enterSingleDoor_80240224) = SCRIPT({
    GetEntryID(EVT_VAR(0));
    match EVT_VAR(0) {
        == 0 {
            UseDoorSounds(0);
            EVT_VAR(2) = 21;
            EVT_VAR(3) = -1;
            await EnterSingleDoor;
            return;
        }
        == 1 {
            UseSettingsFrom(0, 500, 0, -100);
            SetPanTarget(0, 500, 0, -100);
            EVT_VAR(3) = 1;
        }
        == 2 {
            UseSettingsFrom(0, 500, 75, -250);
            SetPanTarget(0, 500, 75, -250);
            EVT_VAR(3) = 75;
        }
        == 3 {
            SetZoneEnabled(5, 0);
            UseSettingsFrom(0, 375, 0, -175);
            SetPanTarget(0, 375, 0, -175);
            EVT_AREA_FLAG(2) = 1;
            EVT_VAR(3) = 1;
        }
    }
    DisablePlayerInput(TRUE);
    InterpPlayerYaw(180, 0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    loop {
        GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        if (EVT_VAR(1) <= EVT_VAR(3)) {
            break loop;
        }
        sleep 1;
    }
    PanToTarget(0, 0, 0);
    DisablePlayerInput(FALSE);
});

EvtSource N(main) = SCRIPT({
    EVT_WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    await N(makeEntities);
    spawn N(802400D0);
    bind N(exitSingleDoor_80240170) TRIGGER_WALL_PRESS_A 11;
    spawn N(enterSingleDoor_80240224);
});

static s32 N(pad_56C) = {
    0x00000000,
};

EvtSource N(80240570) = SCRIPT({
0:
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    if (EVT_VAR(1) >= EVT_VAR(3)) {
        EVT_VAR(1) = EVT_VAR(3);
    }
    SetCamTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    sleep 1;
    goto 0;
});

EvtSource N(80240600) = SCRIPT({
    PlayerJump(375, 270, -250, 20);
});

EvtSource N(8024062C) = SCRIPT({
    if (EVT_AREA_FLAG(3) == 1) {
        return;
    }
    EVT_AREA_FLAG(3) = 1;
    DisablePlayerInput(TRUE);
    SetZoneEnabled(5, 0);
    if (EVT_AREA_FLAG(2) == 0) {
        if (EVT_SAVE_FLAG(1054) == 0) {
            DisablePlayerPhysics(TRUE);
            SetPlayerActionState(3);
            sleep 1;
            EVT_VAR(3) = 500;
            EVT_VAR(10) = spawn N(80240570);
            SetPlayerJumpscale(0.7001953125);
            EVT_VAR(11) = spawn N(80240600);
            loop {
                sleep 1;
                GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                if (EVT_VAR(1) >= 165) {
                    break loop;
                }
            }
            GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            SetPlayerPos(EVT_VAR(0), 165, EVT_VAR(2));
            kill EVT_VAR(11);
            SetPlayerAnimation(0x80015);
            ShakeCam(0, 0, 20, 1.0);
            sleep 10;
            SetPlayerAnimation(ANIM_10002);
            SetPlayerJumpscale(0.0);
            PlayerJump1(375, 25, -250, 10);
            N(func_80240000_C4D3E0)();
            PlaySoundAtPlayer(8326, 0);
            SetPlayerJumpscale(0.7001953125);
            PlayerJump(375, 0, -175, 15);
            kill EVT_VAR(10);
            SetPlayerActionState(0);
            sleep 2;
            SetZoneEnabled(5, 1);
            DisablePlayerPhysics(FALSE);
            DisablePlayerInput(FALSE);
            EVT_AREA_FLAG(3) = 0;
        } else {
            DisablePlayerPhysics(TRUE);
            SetPlayerActionState(3);
            sleep 1;
            spawn {
                sleep 8;
                GotoMap("dgb_10", 1);
                sleep 100;
            }
            EVT_VAR(3) = 500;
            EVT_VAR(10) = spawn N(80240570);
            SetPlayerJumpscale(0.7001953125);
            PlayerJump(375, 270, -250, 20);
            EVT_AREA_FLAG(3) = 0;
        }
    } else {
        SetPlayerActionState(3);
        sleep 1;
        EVT_VAR(3) = 25;
        SetPlayerJumpscale(0.7001953125);
        PlayerJump(375, 0, -175, 15);
        EVT_AREA_FLAG(2) = 0;
        kill EVT_VAR(10);
        SetPlayerActionState(0);
        sleep 2;
        SetZoneEnabled(5, 1);
        DisablePlayerInput(FALSE);
        EVT_AREA_FLAG(3) = 0;
    }
});

EvtSource N(makeEntities) = SCRIPT({
    MakeItemEntity(ITEM_D_DOWN_JUMP, 250, 75, -100, 17, EVT_SAVE_FLAG(1055));
    MakeEntity(0x802EAA30, 375, 0, -250, 0, MAKE_ENTITY_END);
    AssignScript(N(8024062C));
    EVT_MAP_VAR(0) = EVT_VAR(0);
});

ApiStatus N(func_80240000_C4D3E0)(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(get_variable(NULL, 0xFD050F80));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, &D_000001E4);

    return ApiStatus_DONE2;
}
