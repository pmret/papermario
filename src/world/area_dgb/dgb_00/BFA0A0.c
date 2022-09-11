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

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_dgb_00 },
};

EvtScript N(80240110) = {
    EVT_SWITCH(GB_StoryProgress)
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

EvtScript N(exitWalk_802401C0) = EXIT_WALK_SCRIPT(60,  0, "arn_04",  1);

EvtScript N(exitDoubleDoor_8024021C) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, 18)
    EVT_SET(LVar2, 5)
    EVT_SET(LVar3, 7)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(802402D0) = {
    EVT_BIND_TRIGGER(N(exitWalk_802401C0), TRIGGER_FLOOR_ABOVE, 15, 1, 0)
    EVT_SWITCH(GB_StoryProgress)
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

EvtScript N(enterDoubleDoor_8024038C) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(802402D0))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar0, EVT_PTR(N(802402D0)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(1)
            EVT_IF_GE(GB_StoryProgress, -28)
                EVT_IF_LT(GB_StoryProgress, -25)
                    EVT_EXEC(N(802402D0))
                    EVT_THREAD
                        EVT_EXEC_WAIT(N(8024103C))
                        EVT_EXEC_WAIT(N(802413F4))
                    EVT_END_THREAD
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(LVar2, 5)
            EVT_SET(LVar3, 7)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(802402D0))
        EVT_CASE_EQ(2)
            EVT_EXEC(N(802402D0))
            EVT_EXEC(N(80242B84))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 15)
    EVT_SET(GF_MAP_TubbasManor, 1)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, 2)
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
