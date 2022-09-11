#include "dgb_12.h"
#include "message_ids.h"
#include "common.h"
#include "entity.h"

EntryList N(entryList) = {
    { -500.0f, 0.0f, -40.0f, 0.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_MapTattle_dgb_12 },
};

EvtScript N(80240310) = {
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

static s32 N(pad_3A8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitSingleDoor_802403B0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 8)
    EVT_SET(LVar2, 14)
    EVT_SET(LVar3, -1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_09"), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterSingleDoor_80240464) = {
    EVT_CALL(UseDoorSounds, 0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar2, 14)
            EVT_SET(LVar3, -1)
            EVT_EXEC_WAIT(EnterSingleDoor)
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

EvtScript N(802405E0) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_CALL(ModifyColliderFlags, 3, 12, 0x00000002)
    EVT_CALL(ModifyColliderFlags, 3, 0, 0x00000002)
    EVT_CALL(ModifyColliderFlags, 3, 14, 0x00000002)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(lavaResetList_802405C0)))
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(TranslateModel, 19, 0, 0, 0)
    EVT_CALL(ParentColliderToModel, 12, 19)
    EVT_LOOP(0)
        EVT_THREAD
            EVT_WAIT(2)
            EVT_CALL(ModifyColliderFlags, 0, 0, 0x7FFFFE00)
        EVT_END_THREAD
        EVT_CALL(MakeLerp, 0, -35, 15, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, 19, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, 12)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(60)
        EVT_CALL(PlaySoundAtCollider, 0, 8339, 0)
        EVT_THREAD
            EVT_CALL(ModifyColliderFlags, 1, 0, 0x7FFFFE00)
        EVT_END_THREAD
        EVT_CALL(MakeLerp, -35, 0, 4, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, 19, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, 12)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(35)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

static s32 N(pad_868)[] = {
    0x00000000, 0x00000000,
};

#define CHEST_ITEM  19
#define CHEST_FLAG  1057
#include "world/common/atomic/Chest.inc.c"

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, &Entity_Chest, -225, 0, -245, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_DGB12_Chest_CastleKey1)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_Chest_Interact)))
    EVT_RETURN
    EVT_END
};
