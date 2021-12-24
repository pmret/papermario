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

EvtSource N(80240310) = {
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

static s32 N(pad_3A8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitSingleDoor_802403B0) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 8)
    EVT_SET(EVT_VAR(2), 14)
    EVT_SET(EVT_VAR(3), -1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_09"), 2)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterSingleDoor_80240464) = {
    EVT_CALL(UseDoorSounds, 0)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_VAR(2), 14)
            EVT_SET(EVT_VAR(3), -1)
            EVT_EXEC_WAIT(EnterSingleDoor)
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
    EVT_EXEC(N(802405E0))
    EVT_EXEC(N(80240310))
    EVT_BIND_TRIGGER(N(exitSingleDoor_802403B0), TRIGGER_WALL_PRESS_A, 8, 1, 0)
    EVT_EXEC(N(enterSingleDoor_80240464))
    EVT_RETURN
    EVT_END
};

s32 N(lavaResetList_802405C0)[] = {
    0x00000005, 0xC3FB8000, 0x00000000, 0xC27C0000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(802405E0) = {
    EVT_SET_GROUP(239)
    EVT_CALL(ModifyColliderFlags, 3, 12, 0x00000002)
    EVT_CALL(ModifyColliderFlags, 3, 0, 0x00000002)
    EVT_CALL(ModifyColliderFlags, 3, 14, 0x00000002)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(lavaResetList_802405C0)))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(50)
    EVT_CALL(TranslateModel, 19, 0, 0, 0)
    EVT_CALL(ParentColliderToModel, 12, 19)
    EVT_LOOP(0)
        EVT_THREAD
            EVT_WAIT_FRAMES(2)
            EVT_CALL(ModifyColliderFlags, 0, 0, 0x7FFFFE00)
        EVT_END_THREAD
        EVT_CALL(MakeLerp, 0, -35, 15, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, 19, 0, EVT_VAR(0), 0)
            EVT_CALL(UpdateColliderTransform, 12)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT_FRAMES(60)
        EVT_CALL(PlaySoundAtCollider, 0, 8339, 0)
        EVT_THREAD
            EVT_CALL(ModifyColliderFlags, 1, 0, 0x7FFFFE00)
        EVT_END_THREAD
        EVT_CALL(MakeLerp, -35, 0, 4, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, 19, 0, EVT_VAR(0), 0)
            EVT_CALL(UpdateColliderTransform, 12)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT_FRAMES(35)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

static s32 N(pad_868)[] = {
    0x00000000, 0x00000000,
};

#include "world/common/StashVars.inc.c"

EvtSource N(80240874) = {
    EVT_SET_GROUP(0)
    EVT_CALL(SetTimeFreezeMode, 2)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(ShowGotItem, EVT_VAR(0), 0, 0)
    EVT_CALL(SetTimeFreezeMode, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(802408DC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_IF_NE(EVT_VAR(10), 0)
        EVT_EXEC_WAIT(N(80240874))
    EVT_END_IF
    EVT_SWITCH(EVT_VAR(11))
        EVT_CASE_EQ(0)
            EVT_CALL(AddItem, EVT_VAR(10), EVT_VAR(0))
        EVT_CASE_EQ(1)
            EVT_CALL(AddKeyItem, EVT_VAR(10))
        EVT_CASE_EQ(2)
            EVT_CALL(AddBadge, EVT_VAR(10), EVT_VAR(0))
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(15)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(802409BC) = {
    EVT_SET(EVT_VAR(10), 19)
    EVT_SET(EVT_VAR(11), 1)
    EVT_SET(EVT_SAVE_FLAG(1057), 1)
    EVT_EXEC_WAIT(N(802408DC))
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EAE30, -225, 0, -245, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignFlag, EVT_SAVE_FLAG(1057))
    EVT_CALL(AssignScript, EVT_PTR(N(802409BC)))
    EVT_RETURN
    EVT_END
};

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
