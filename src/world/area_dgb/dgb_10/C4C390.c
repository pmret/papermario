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

EvtSource N(80240250) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2E8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitWalk_802402F0) = EXIT_WALK_SCRIPT(40,  0, "dgb_09",  3);

EvtSource N(8024034C) = {
    EVT_BIND_TRIGGER(N(exitWalk_802402F0), TRIGGER_FLOOR_ABOVE, 8, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterWalk_80240378) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_VAR(0), EVT_PTR(N(8024034C)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT_FRAMES(1)
        EVT_CASE_EQ(1)
            EVT_CALL(UseSettingsFrom, 0, 375, 0, -188)
            EVT_CALL(SetPanTarget, 0, 375, 0, -188)
            EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(SetPlayerActionState, 3)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.7))
            EVT_CALL(PlayerJump, 375, 0, -188, 20)
            EVT_CALL(PanToTarget, 0, 0, 0)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CALL(SetPlayerActionState, 0)
            EVT_EXEC(N(8024034C))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80240E68))
    EVT_EXEC(N(80240250))
    EVT_CALL(ModifyColliderFlags, 0, 9, 0x7FFFFE00)
    EVT_CALL(EnableModel, 6, 0)
    EVT_CALL(EnableModel, 12, 0)
    EVT_CALL(EnableModel, 18, 0)
    EVT_CALL(ModifyColliderFlags, 0, 12, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 13, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 14, 0x7FFFFE00)
    EVT_EXEC(N(enterWalk_80240378))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_66C) = {
    0x00000000,
};

EvtSource N(80240670) = {
    EVT_USE_BUF(EVT_VAR(0))
    EVT_MALLOC_ARRAY(6, EVT_VAR(10))
    EVT_BUF_READ1(EVT_VAR(0))
    EVT_SET(EVT_ARRAY(0), EVT_VAR(0))
    EVT_BUF_READ1(EVT_VAR(0))
    EVT_SET(EVT_ARRAY(1), EVT_VAR(0))
    EVT_BUF_READ1(EVT_VAR(0))
    EVT_SET(EVT_ARRAY(2), EVT_VAR(0))
    EVT_BUF_READ1(EVT_VAR(0))
    EVT_SET(EVT_ARRAY(3), EVT_VAR(0))
    EVT_BUF_READ1(EVT_VAR(0))
    EVT_SET(EVT_ARRAY(4), EVT_VAR(0))
    EVT_BUF_READ1(EVT_VAR(0))
    EVT_SET(EVT_ARRAY(5), EVT_VAR(0))
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_BIND_TRIGGER(N(80240770), TRIGGER_FLOOR_TOUCH, EVT_ARRAY(0), 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80240770) = {
    EVT_USE_ARRAY(EVT_VAR(0))
    EVT_CALL(N(func_80240000_C4C390))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_LOOP(5)
        EVT_CALL(ModifyColliderFlags, 1, EVT_ARRAY(0), 0x7FFFFE00)
        EVT_CALL(EnableModel, EVT_ARRAY(1), 1)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(ModifyColliderFlags, 0, EVT_ARRAY(0), 0x7FFFFE00)
        EVT_CALL(EnableModel, EVT_ARRAY(1), 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_IF_NE(EVT_ARRAY(5), 0)
        EVT_EXEC_WAIT(EVT_ARRAY(5))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(80240860) = {
    EVT_USE_BUF(EVT_VAR(0))
    EVT_MALLOC_ARRAY(6, EVT_VAR(9))
    EVT_BUF_READ1(EVT_VAR(1))
    EVT_SET(EVT_ARRAY(0), EVT_VAR(1))
    EVT_BUF_READ1(EVT_VAR(1))
    EVT_SET(EVT_ARRAY(1), EVT_VAR(1))
    EVT_BUF_READ1(EVT_VAR(1))
    EVT_SET(EVT_ARRAY(2), EVT_VAR(1))
    EVT_BUF_READ1(EVT_VAR(1))
    EVT_SET(EVT_ARRAY(3), EVT_VAR(1))
    EVT_BUF_READ1(EVT_VAR(1))
    EVT_SET(EVT_ARRAY(4), EVT_VAR(1))
    EVT_BUF_READ1(EVT_VAR(1))
    EVT_SET(EVT_ARRAY(5), EVT_VAR(1))
    EVT_CALL(ParentColliderToModel, EVT_ARRAY(1), EVT_ARRAY(0))
    EVT_LABEL(0)
    EVT_LABEL(1)
    EVT_CALL(GetPlayerActionState, EVT_VAR(10))
    EVT_IF_EQ(EVT_VAR(10), 13)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_IF_EQ(EVT_VAR(10), 15)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_LABEL(2)
    EVT_CALL(GetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_WAIT_FRAMES(1)
    EVT_IF_NE(EVT_VAR(2), EVT_ARRAY(3))
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(N(func_802400A0_C4C430))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_EXEC_WAIT(N(80240AF4))
    EVT_END_IF
    EVT_IF_EQ(EVT_VAR(0), 2)
        EVT_EXEC_WAIT(N(80240CB8))
    EVT_END_IF
    EVT_LABEL(3)
    EVT_CALL(GetPlayerActionState, EVT_VAR(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(0), 13)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_IF_EQ(EVT_VAR(0), 15)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80240AF4) = {
    EVT_USE_ARRAY(EVT_VAR(9))
    EVT_CALL(GetPlayerPos, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
    EVT_CALL(MakeLerp, 0, 5, 3, 1)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, EVT_ARRAY(0), 0, EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(5), EVT_VAR(3))
    EVT_ADD(EVT_VAR(5), EVT_VAR(0))
    EVT_CALL(SetPlayerPos, EVT_VAR(2), EVT_VAR(5), EVT_VAR(4))
    EVT_CALL(UpdateColliderTransform, EVT_ARRAY(1))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(MakeLerp, 5, 0, 3, 1)
    EVT_LABEL(3)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, EVT_ARRAY(0), 0, EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(5), EVT_VAR(3))
    EVT_ADD(EVT_VAR(5), EVT_VAR(0))
    EVT_CALL(SetPlayerPos, EVT_VAR(2), EVT_VAR(5), EVT_VAR(4))
    EVT_CALL(UpdateColliderTransform, EVT_ARRAY(1))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(80240CB8) = {
    EVT_USE_ARRAY(EVT_VAR(9))
    EVT_CALL(MakeItemEntity, EVT_ARRAY(5), EVT_ARRAY(2), EVT_ARRAY(3), EVT_ARRAY(4), 3, 0)
    EVT_SET(EVT_VAR(2), 0)
    EVT_CALL(MakeLerp, 0, 150, 19, 4)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, EVT_ARRAY(0), 0, EVT_VAR(0), 0)
    EVT_ADD(EVT_VAR(2), 45)
    EVT_CALL(RotateModel, EVT_ARRAY(0), EVT_VAR(2), 1, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(MakeLerp, 150, 0, 19, 4)
    EVT_LABEL(3)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, EVT_ARRAY(0), 0, EVT_VAR(0), 0)
    EVT_ADD(EVT_VAR(2), 45)
    EVT_CALL(RotateModel, EVT_ARRAY(0), EVT_VAR(2), 1, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(80240E68) = {
    EVT_CALL(N(func_8024013C_C4C4CC))
    EVT_CALL(func_802CA988, 0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_CALL(N(func_802401C0_C4C550))
    EVT_CALL(func_802D2B6C)
    EVT_CALL(GotoMap, EVT_PTR("dgb_11"), EVT_VAR(0))
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_EDC) = {
    0x00000000,
};

EvtSource N(80240EE0) = {
    EVT_SET(EVT_SAVE_FLAG(1052), 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(80240F00) = {
    EVT_SET(EVT_SAVE_FLAG(1053), 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(80240F20) = {
    EVT_SET(EVT_SAVE_FLAG(1054), 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1052), 0)
        EVT_CALL(MakeEntity, 0x802BCE84, 500, 0, -100, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(80240EE0)))
    EVT_END_IF
    EVT_IF_EQ(EVT_SAVE_FLAG(1053), 0)
        EVT_CALL(MakeEntity, 0x802BCE84, 500, 0, -250, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(80240F00)))
    EVT_END_IF
    EVT_IF_EQ(EVT_SAVE_FLAG(1054), 0)
        EVT_CALL(MakeEntity, 0x802BCE84, 375, 0, -250, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(80240F20)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

ApiStatus N(func_80240000_C4C390)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(func_802400A0_C4C430)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(func_8024013C_C4C4CC)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(func_802401C0_C4C550)(Evt* script, s32 isInitialCall) {
    if (gPlayerStatus.position.y > -60.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}
