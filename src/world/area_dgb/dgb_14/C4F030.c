#include "dgb_14.h"
#include "message_ids.h"
#include "entity.h"

EntryList N(entryList) = {
    { 575.0f, 0.0f, 180.0f, 270.0f },
    { 575.0f, 210.0f, 180.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_MapTattle_dgb_14 },
};

EvtScript N(80240060) = {
    EVT_SWITCH(GB_StoryProgress)
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

EvtScript N(exitDoubleDoor_80240100) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, 14)
    EVT_SET(LVar2, 24)
    EVT_SET(LVar3, 22)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_03"), 3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_802401B4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 18)
    EVT_SET(LVar2, 19)
    EVT_SET(LVar3, 17)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_15"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterDoubleDoor_80240268) = {
    EVT_CALL(UseDoorSounds, 3)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar2, 24)
            EVT_SET(LVar3, 22)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(1)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_SET(LVar2, 19)
            EVT_SET(LVar3, 17)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_IF_EQ(AreaFlag(1), 1)
                EVT_WAIT(5)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_8001D)
                EVT_WAIT(20)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_END_IF
            EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80240060))
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80240100), TRIGGER_WALL_PRESS_A, 14, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802401B4), TRIGGER_WALL_PRESS_A, 18, 1, 0)
    EVT_EXEC(N(enterDoubleDoor_80240268))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_47C) = {
    0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 500, 60, 75, 0, 163, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_DGB14_ItemBlock_MapleSyrup)
    EVT_RETURN
    EVT_END
};
