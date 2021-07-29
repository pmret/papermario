#include "dgb_10.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { 300.0f, 0.0f, -50.0f, 0.0f },
    { 375.0f, 0.0f, -240.0f, 0.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_10_tattle },
};

Script N(80240250) = SCRIPT({
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

static s32 N(pad_2E8)[] = {
    0x00000000, 0x00000000,
};

Script N(exitWalk_802402F0) = EXIT_WALK_SCRIPT(40,  0, "dgb_09",  3);

Script N(8024034C) = SCRIPT({
    bind N(exitWalk_802402F0) TRIGGER_FLOOR_ABOVE 8;
});

Script N(enterWalk_80240378) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(0) = N(8024034C);
            spawn EnterWalk;
            sleep 1;
        }
        == 1 {
            UseSettingsFrom(0, 375, 0, -188);
            SetPanTarget(0, 375, 0, -188);
            SetCamSpeed(0, 90.0);
            PanToTarget(0, 0, 1);
            DisablePlayerInput(TRUE);
            DisablePlayerPhysics(TRUE);
            SetPlayerActionState(3);
            sleep 1;
            SetPlayerJumpscale(0.7001953125);
            PlayerJump(375, 0, -188, 20);
            PanToTarget(0, 0, 0);
            DisablePlayerPhysics(FALSE);
            DisablePlayerInput(FALSE);
            SetPlayerActionState(0);
            spawn N(8024034C);
        }
    }
});

Script N(main) = SCRIPT({
    SI_WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    await N(makeEntities);
    spawn N(80240E68);
    spawn N(80240250);
    ModifyColliderFlags(0, 9, 0x7FFFFE00);
    EnableModel(6, 0);
    EnableModel(12, 0);
    EnableModel(18, 0);
    ModifyColliderFlags(0, 12, 0x7FFFFE00);
    ModifyColliderFlags(0, 13, 0x7FFFFE00);
    ModifyColliderFlags(0, 14, 0x7FFFFE00);
    spawn N(enterWalk_80240378);
});

static s32 N(pad_66C) = {
    0x00000000,
};

Script N(80240670) = SCRIPT({
    buf_use SI_VAR(0);
    arr_new 6 SI_VAR(10);
    buf_read SI_VAR(0);
    SI_ARRAY(0) = SI_VAR(0);
    buf_read SI_VAR(0);
    SI_ARRAY(1) = SI_VAR(0);
    buf_read SI_VAR(0);
    SI_ARRAY(2) = SI_VAR(0);
    buf_read SI_VAR(0);
    SI_ARRAY(3) = SI_VAR(0);
    buf_read SI_VAR(0);
    SI_ARRAY(4) = SI_VAR(0);
    buf_read SI_VAR(0);
    SI_ARRAY(5) = SI_VAR(0);
    SI_VAR(0) = SI_VAR(10);
    bind N(80240770) TRIGGER_FLOOR_TOUCH 0xF4ACD480; // TODO: what is this id? see also below TODO
});

Script N(80240770) = SCRIPT({
    arr_use SI_VAR(0);
    N(func_80240000_C4C390)();
    if (SI_VAR(0) == 0) {
        return;
    }
    loop 5 {
        ModifyColliderFlags(1, SI_ARRAY(0), 0x7FFFFE00);
        EnableModel(SI_ARRAY(1), 1);
        sleep 1;
        ModifyColliderFlags(0, SI_ARRAY(0), 0x7FFFFE00);
        EnableModel(SI_ARRAY(1), 0);
        sleep 1;
    }
    if (SI_ARRAY(5) != 0) {
        await 0xF4ACD485; // TODO: what is this?
    }
});

Script N(80240860) = SCRIPT({
    buf_use SI_VAR(0);
    arr_new 6 SI_VAR(9);
    buf_read SI_VAR(1);
    SI_ARRAY(0) = SI_VAR(1);
    buf_read SI_VAR(1);
    SI_ARRAY(1) = SI_VAR(1);
    buf_read SI_VAR(1);
    SI_ARRAY(2) = SI_VAR(1);
    buf_read SI_VAR(1);
    SI_ARRAY(3) = SI_VAR(1);
    buf_read SI_VAR(1);
    SI_ARRAY(4) = SI_VAR(1);
    buf_read SI_VAR(1);
    SI_ARRAY(5) = SI_VAR(1);
    ParentColliderToModel(SI_ARRAY(1), SI_ARRAY(0));
0:
1:
    GetPlayerActionState(SI_VAR(10));
    if (SI_VAR(10) == 13) {
        goto 2;
    }
    if (SI_VAR(10) == 15) {
        goto 2;
    }
    sleep 1;
    goto 0;
2:
    GetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    sleep 1;
    if (SI_VAR(2) != SI_ARRAY(3)) {
        goto 2;
    }
    N(func_802400A0_C4C430)();
    if (SI_VAR(0) == 1) {
        await N(80240AF4);
    }
    if (SI_VAR(0) == 2) {
        await N(80240CB8);
    }
3:
    GetPlayerActionState(SI_VAR(0));
    sleep 1;
    if (SI_VAR(0) == 13) {
        goto 3;
    }
    if (SI_VAR(0) == 15) {
        goto 3;
    }
    goto 0;
});

Script N(80240AF4) = SCRIPT({
    arr_use SI_VAR(9);
    GetPlayerPos(SI_VAR(2), SI_VAR(3), SI_VAR(4));
    MakeLerp(0, 5, 3, 1);
2:
    UpdateLerp();
    TranslateModel(SI_ARRAY(0), 0, SI_VAR(0), 0);
    SI_VAR(5) = SI_VAR(3);
    SI_VAR(5) += SI_VAR(0);
    SetPlayerPos(SI_VAR(2), SI_VAR(5), SI_VAR(4));
    UpdateColliderTransform(SI_ARRAY(1));
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 2;
    }
    MakeLerp(5, 0, 3, 1);
3:
    UpdateLerp();
    TranslateModel(SI_ARRAY(0), 0, SI_VAR(0), 0);
    SI_VAR(5) = SI_VAR(3);
    SI_VAR(5) += SI_VAR(0);
    SetPlayerPos(SI_VAR(2), SI_VAR(5), SI_VAR(4));
    UpdateColliderTransform(SI_ARRAY(1));
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 3;
    }
});

Script N(80240CB8) = SCRIPT({
    arr_use SI_VAR(9);
    MakeItemEntity(SI_ARRAY(5), SI_ARRAY(2), SI_ARRAY(3), SI_ARRAY(4), 3, 0);
    SI_VAR(2) = 0;
    MakeLerp(0, 150, 19, 4);
2:
    UpdateLerp();
    TranslateModel(SI_ARRAY(0), 0, SI_VAR(0), 0);
    SI_VAR(2) += 45;
    RotateModel(SI_ARRAY(0), SI_VAR(2), 1, 0, 0);
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 2;
    }
    MakeLerp(150, 0, 19, 4);
3:
    UpdateLerp();
    TranslateModel(SI_ARRAY(0), 0, SI_VAR(0), 0);
    SI_VAR(2) += 45;
    RotateModel(SI_ARRAY(0), SI_VAR(2), 1, 0, 0);
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 3;
    }
});

Script N(80240E68) = SCRIPT({
    N(func_8024013C_C4C4CC)();
    func_802CA988(0, SI_VAR(2), SI_VAR(3), SI_VAR(4), SI_VAR(5));
    N(func_802401C0_C4C550)();
    func_802D2B6C();
    GotoMap("dgb_11", SI_VAR(0));
    sleep 100;
});

static s32 N(pad_EDC) = {
    0x00000000,
};

Script N(80240EE0) = SCRIPT({
    SI_SAVE_FLAG(1052) = 1;
});

Script N(80240F00) = SCRIPT({
    SI_SAVE_FLAG(1053) = 1;
});

Script N(80240F20) = SCRIPT({
    SI_SAVE_FLAG(1054) = 1;
});

Script N(makeEntities) = SCRIPT({
    if (SI_SAVE_FLAG(1052) == 0) {
        MakeEntity(0x802BCE84, 500, 0, -100, 0, MAKE_ENTITY_END);
        AssignScript(N(80240EE0));
    }
    if (SI_SAVE_FLAG(1053) == 0) {
        MakeEntity(0x802BCE84, 500, 0, -250, 0, MAKE_ENTITY_END);
        AssignScript(N(80240F00));
    }
    if (SI_SAVE_FLAG(1054) == 0) {
        MakeEntity(0x802BCE84, 375, 0, -250, 0, MAKE_ENTITY_END);
        AssignScript(N(80240F20));
    }
});

ApiStatus N(func_80240000_C4C390)(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32* array = script->array;
    f32 distance = dist2D(playerStatus->position.x, playerStatus->position.z, array[2], array[3]);

    script->varTable[0] = 1;
    if ((playerStatus->actionState != 14) && (playerStatus->actionState != 16)) {
        script->varTable[0] = 0;
    }
    if (script->array[4] <= distance) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802400A0_C4C430)(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 distance;
    s32* array = script->array;

    distance = dist2D(playerStatus->position.x, playerStatus->position.z, array[2], array[4]);
    script->varTable[0] = 0;
    if (distance < 112.5f) {
        script->varTable[0] = 2;
    }
    if (distance < 37.5f) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_8024013C_C4C4CC)(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 var;

    if (playerStatus->position.y >= 0.0f) {
        return 0;
    }

    if (playerStatus->position.x < 440.0f) {
        var = 3;
    } else if (playerStatus->position.z < -170.0f) {
        var = 2;
    } else {
        var = 1;
    }
    script->varTable[0] = var;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802401C0_C4C550)(ScriptInstance* script, s32 isInitialCall) {
    if (gPlayerStatus.position.y > -60.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}
