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

EvtSource N(80240060) = {
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

static s32 N(pad_F8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitDoubleDoor_80240100) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 7)
    EVT_SET(EVT_VAR(2), 14)
    EVT_SET(EVT_VAR(3), 16)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_15"), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_802401B4) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 1)
    EVT_SET(EVT_VAR(1), 11)
    EVT_SET(EVT_VAR(2), 21)
    EVT_SET(EVT_VAR(3), 19)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 5)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(80240268) = {
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80240100), TRIGGER_WALL_PRESS_A, 7, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802401B4), TRIGGER_WALL_PRESS_A, 11, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterDoubleDoor_802402B0) = {
    EVT_CALL(GetLoadType, EVT_VAR(1))
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(80240268))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseDoorSounds, 3)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_VAR(2), 14)
            EVT_SET(EVT_VAR(3), 16)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(1)
            EVT_SET(EVT_VAR(2), 21)
            EVT_SET(EVT_VAR(3), 19)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_EXEC(N(80240268))
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
    EVT_EXEC(N(80240060))
    EVT_EXEC(N(enterDoubleDoor_802402B0))
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(D_802E9A18), -300, 60, 75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, 0x802EA7E0, -450, 60, 75, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
