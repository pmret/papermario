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

EvtSource N(802400D0) = {
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

static s32 N(pad_168)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitSingleDoor_80240170) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 11)
    EVT_SET(EVT_VAR(2), 21)
    EVT_SET(EVT_VAR(3), -1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_02"), 3)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterSingleDoor_80240224) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(UseDoorSounds, 0)
            EVT_SET(EVT_VAR(2), 21)
            EVT_SET(EVT_VAR(3), -1)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_CALL(UseSettingsFrom, 0, 500, 0, -100)
            EVT_CALL(SetPanTarget, 0, 500, 0, -100)
            EVT_SET(EVT_VAR(3), 1)
        EVT_CASE_EQ(2)
            EVT_CALL(UseSettingsFrom, 0, 500, 75, -250)
            EVT_CALL(SetPanTarget, 0, 500, 75, -250)
            EVT_SET(EVT_VAR(3), 75)
        EVT_CASE_EQ(3)
            EVT_CALL(SetZoneEnabled, 5, 0)
            EVT_CALL(UseSettingsFrom, 0, 375, 0, -175)
            EVT_CALL(SetPanTarget, 0, 375, 0, -175)
            EVT_SET(EVT_AREA_FLAG(2), 1)
            EVT_SET(EVT_VAR(3), 1)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 180, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_IF_LE(EVT_VAR(1), EVT_VAR(3))
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
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
    EVT_EXEC(N(802400D0))
    EVT_BIND_TRIGGER(N(exitSingleDoor_80240170), TRIGGER_WALL_PRESS_A, 11, 1, 0)
    EVT_EXEC(N(enterSingleDoor_80240224))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_56C) = {
    0x00000000,
};

EvtSource N(80240570) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_IF_GE(EVT_VAR(1), EVT_VAR(3))
        EVT_SET(EVT_VAR(1), EVT_VAR(3))
    EVT_END_IF
    EVT_CALL(SetCamTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80240600) = {
    EVT_CALL(PlayerJump, 375, 270, -250, 20)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024062C) = {
    EVT_IF_EQ(EVT_AREA_FLAG(3), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_AREA_FLAG(3), 1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetZoneEnabled, 5, 0)
    EVT_IF_EQ(EVT_AREA_FLAG(2), 0)
        EVT_IF_EQ(EVT_SAVE_FLAG(1054), 0)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(SetPlayerActionState, 3)
            EVT_WAIT_FRAMES(1)
            EVT_SET(EVT_VAR(3), 500)
            EVT_EXEC_GET_TID(N(80240570), EVT_VAR(10))
            EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.7))
            EVT_EXEC_GET_TID(N(80240600), EVT_VAR(11))
            EVT_LOOP(0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_IF_GE(EVT_VAR(1), 165)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPlayerPos, EVT_VAR(0), 165, EVT_VAR(2))
            EVT_KILL_THREAD(EVT_VAR(11))
            EVT_CALL(SetPlayerAnimation, 524309)
            EVT_CALL(ShakeCam, 0, 0, 20, EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetPlayerAnimation, ANIM_10002)
            EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.0))
            EVT_CALL(PlayerJump1, 375, 25, -250, 10)
            EVT_CALL(N(func_80240000_C4D3E0))
            EVT_CALL(PlaySoundAtPlayer, 8326, 0)
            EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.7))
            EVT_CALL(PlayerJump, 375, 0, -175, 15)
            EVT_KILL_THREAD(EVT_VAR(10))
            EVT_CALL(SetPlayerActionState, 0)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(SetZoneEnabled, 5, 1)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(EVT_AREA_FLAG(3), 0)
        EVT_ELSE
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(SetPlayerActionState, 3)
            EVT_WAIT_FRAMES(1)
            EVT_THREAD
                EVT_WAIT_FRAMES(8)
                EVT_CALL(GotoMap, EVT_PTR("dgb_10"), 1)
                EVT_WAIT_FRAMES(100)
            EVT_END_THREAD
            EVT_SET(EVT_VAR(3), 500)
            EVT_EXEC_GET_TID(N(80240570), EVT_VAR(10))
            EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.7))
            EVT_CALL(PlayerJump, 375, 270, -250, 20)
            EVT_SET(EVT_AREA_FLAG(3), 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SetPlayerActionState, 3)
        EVT_WAIT_FRAMES(1)
        EVT_SET(EVT_VAR(3), 25)
        EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.7))
        EVT_CALL(PlayerJump, 375, 0, -175, 15)
        EVT_SET(EVT_AREA_FLAG(2), 0)
        EVT_KILL_THREAD(EVT_VAR(10))
        EVT_CALL(SetPlayerActionState, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetZoneEnabled, 5, 1)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_SET(EVT_AREA_FLAG(3), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_D_DOWN_JUMP, 250, 75, -100, 17, EVT_SAVE_FLAG(1055))
    EVT_CALL(MakeEntity, 0x802EAA30, 375, 0, -250, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(8024062C)))
    EVT_SET(EVT_MAP_VAR(0), EVT_VAR(0))
    EVT_RETURN
    EVT_END
};

ApiStatus N(func_80240000_C4D3E0)(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(evt_get_variable(NULL, 0xFD050F80));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, &D_000001E4);

    return ApiStatus_DONE2;
}
