#include "dgb_00.h"
#include "message_ids.h"

ApiStatus N(func_80240000_BFA0A0)(Evt* script, s32 isInitialCall) {
    sprintf(&wMapShapeName, "arn_20_shape");
    sprintf(&wMapHitName, "arn_20_hit");
    sprintf(&wMapTexName, "arn_tex");
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

EvtSource N(80240110) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1B8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitWalk_802401C0) = EXIT_WALK_SCRIPT(60,  0, "arn_04",  1);

EvtSource N(exitDoubleDoor_8024021C) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 1)
    EVT_SET(EVT_VAR(1), 18)
    EVT_SET(EVT_VAR(2), 5)
    EVT_SET(EVT_VAR(3), 7)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(802402D0) = {
    EVT_BIND_TRIGGER(N(exitWalk_802401C0), TRIGGER_FLOOR_ABOVE, 15, 1, 0)
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-28)
            EVT_BIND_TRIGGER(N(exitDoubleDoor_8024021C), TRIGGER_WALL_PRESS_A, 18, 1, 0)
        EVT_CASE_LT(-25)
        EVT_CASE_LT(-16)
            EVT_EXEC(N(80240F50))
            EVT_EXEC_WAIT(N(80241AA0))
        EVT_CASE_DEFAULT
            EVT_BIND_TRIGGER(N(exitDoubleDoor_8024021C), TRIGGER_WALL_PRESS_A, 18, 1, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(enterDoubleDoor_8024038C) = {
    EVT_CALL(GetLoadType, EVT_VAR(1))
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(802402D0))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_VAR(0), EVT_PTR(N(802402D0)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT_FRAMES(1)
        EVT_CASE_EQ(1)
            EVT_IF_GE(EVT_SAVE_VAR(0), -28)
                EVT_IF_LT(EVT_SAVE_VAR(0), -25)
                    EVT_EXEC(N(802402D0))
                    EVT_THREAD
                        EVT_EXEC_WAIT(N(8024103C))
                        EVT_EXEC_WAIT(N(802413F4))
                    EVT_END_THREAD
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(EVT_VAR(2), 5)
            EVT_SET(EVT_VAR(3), 7)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(802402D0))
        EVT_CASE_EQ(2)
            EVT_EXEC(N(802402D0))
            EVT_EXEC(N(80242B84))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 15)
    EVT_SET(EVT_SAVE_FLAG(1978), 1)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 2)
        EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80243740)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802436EC)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80240110))
    EVT_EXEC(N(enterDoubleDoor_8024038C))
    EVT_RETURN
    EVT_END
};
