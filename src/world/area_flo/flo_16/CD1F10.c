#include "flo_16.h"
#include "message_ids.h"
#include "entity.h"

EntryList N(entryList) = {
    { -720.0f,   0.0f, 0.0f,  90.0f },
    {  710.0f, 100.0f, 0.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_16_tattle },
};

EvtScript N(802429D0) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_80242A40) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  4);

EvtScript N(exitWalk_80242A9C) = EXIT_WALK_SCRIPT(60,  1, "flo_17",  0);

EvtScript N(80242AF8) = {
    EVT_BIND_TRIGGER(N(exitWalk_80242A40), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80242A9C), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(lavaResetList_80242B40)[] = {
    0x0000000A, 0xC39B0000, 0x00000000, 0x00000000, 0x0000000B, 0x43988000, 0x42C80000, 0x00000000,
    0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802444D4)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(8024346C))
    EVT_CALL(ModifyColliderFlags, 3, 9, 0x00000002)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(lavaResetList_80242B40)))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, 16, 1)
    EVT_CALL(EnableTexPanning, 17, 1)
    EVT_CALL(EnableTexPanning, 18, 1)
    EVT_CALL(EnableTexPanning, 20, 1)
    EVT_CALL(EnableTexPanning, 22, 1)
    EVT_CALL(EnableTexPanning, 24, 1)
    EVT_CALL(EnableTexPanning, 19, 1)
    EVT_CALL(EnableTexPanning, 21, 1)
    EVT_CALL(EnableTexPanning, 23, 1)
    EVT_CALL(EnableTexPanning, 25, 1)
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_SET(LocalVar(1), 0)
        EVT_LABEL(0)
        EVT_ADD(LocalVar(0), 140)
        EVT_IF_GT(LocalVar(0), 65536)
            EVT_ADD(LocalVar(0), -65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 1, 0, LocalVar(0), 0)
        EVT_ADD(LocalVar(1), -200)
        EVT_IF_LT(LocalVar(1), 0)
            EVT_ADD(LocalVar(1), 65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 2, 0, LocalVar(1), 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_EXEC(N(802451C4))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(LocalVar(0), EVT_PTR(N(80242AF8)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(802429D0))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_80240000_CD1E30))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80242EA0) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_SET(LocalVar(11), LocalVar(1))
    EVT_SET(LocalVar(12), LocalVar(2))
    EVT_SET(LocalVar(13), LocalVar(3))
    EVT_SET(LocalVar(14), LocalVar(4))
    EVT_SUB(LocalVar(12), LocalVar(0))
    EVT_SUB(LocalVar(13), LocalVar(1))
    EVT_SETF(LocalVar(0), LocalVar(12))
    EVT_DIVF(LocalVar(0), EVT_FIXED(100.0))
    EVT_SETF(LocalVar(15), EVT_FIXED(100.0))
    EVT_DIVF(LocalVar(15), LocalVar(0))
    EVT_ADD(LocalVar(15), 11)
    EVT_SET(LocalVar(5), 200)
    EVT_DIV(LocalVar(5), LocalVar(15))
    EVT_ADD(LocalVar(5), 1)
    EVT_LOOP(LocalVar(5))
        EVT_CALL(RandInt, LocalVar(12), LocalVar(0))
        EVT_CALL(RandInt, LocalVar(13), LocalVar(1))
        EVT_CALL(RandInt, 199, LocalVar(2))
        EVT_SET(LocalVar(3), 210)
        EVT_SUB(LocalVar(3), LocalVar(2))
        EVT_ADD(LocalVar(0), LocalVar(10))
        EVT_ADD(LocalVar(1), LocalVar(11))
        EVT_ADD(LocalVar(2), LocalVar(14))
        EVT_CALL(PlayEffect, 0xD, LocalVar(0), LocalVar(2), LocalVar(1), LocalVar(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LocalVar(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, LocalVar(12), LocalVar(0))
    EVT_CALL(RandInt, LocalVar(13), LocalVar(1))
    EVT_ADD(LocalVar(0), LocalVar(10))
    EVT_ADD(LocalVar(1), LocalVar(11))
    EVT_CALL(PlayEffect, 0xD, LocalVar(0), LocalVar(14), LocalVar(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LocalVar(15))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024314C) = {
    EVT_SET(LocalVar(9), LocalVar(6))
    EVT_SET(LocalVar(8), LocalVar(5))
    EVT_SET(LocalVar(7), LocalVar(4))
    EVT_SET(LocalVar(6), LocalVar(3))
    EVT_SET(LocalVar(5), LocalVar(2))
    EVT_SET(LocalVar(4), LocalVar(1))
    EVT_SET(LocalVar(3), LocalVar(0))
    EVT_CALL(EnableModel, LocalVar(6), 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(N(UnkFunc43))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(EnableModel, LocalVar(6), 1)
    EVT_END_THREAD
    EVT_IF_NE(LocalVar(10), 0)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_SET(LocalVar(0), LocalVar(3))
            EVT_SET(LocalVar(1), LocalVar(4))
            EVT_SET(LocalVar(2), LocalVar(5))
            EVT_ADD(LocalVar(1), 10)
            EVT_ADD(LocalVar(2), 8)
            EVT_CALL(PlayEffect, 0x11, 4, LocalVar(0), LocalVar(1), LocalVar(2), 15, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_SUB(LocalVar(1), 10)
            EVT_CALL(MakeItemEntity, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 14, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAt, 0xF8, 0, LocalVar(3), LocalVar(4), LocalVar(5))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, 2)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, LocalVar(8), LocalVar(0), 1, 0, 0)
    EVT_CALL(RotateModel, LocalVar(9), LocalVar(0), 1, 0, 0)
    EVT_IF_EQ(LocalVar(1), 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, LocalVar(7), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024346C) = {
    EVT_CALL(ModifyColliderFlags, 3, 20, 0x00000006)
    EVT_SET(LocalVar(0), -740)
    EVT_SET(LocalVar(1), -140)
    EVT_SET(LocalVar(2), -260)
    EVT_SET(LocalVar(3), -55)
    EVT_SET(LocalVar(4), 100)
    EVT_EXEC(N(80242EA0))
    EVT_SET(LocalVar(0), 250)
    EVT_SET(LocalVar(1), -140)
    EVT_SET(LocalVar(2), 725)
    EVT_SET(LocalVar(3), -55)
    EVT_SET(LocalVar(4), 180)
    EVT_EXEC(N(80242EA0))
    EVT_CALL(GetModelCenter, 65)
    EVT_SET(LocalVar(3), 65)
    EVT_SET(LocalVar(4), 66)
    EVT_SET(LocalVar(5), 67)
    EVT_SET(LocalVar(6), 68)
    EVT_SET(LocalVar(10), 0)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 71)
    EVT_SET(LocalVar(3), 71)
    EVT_SET(LocalVar(4), 72)
    EVT_SET(LocalVar(5), 73)
    EVT_SET(LocalVar(6), 74)
    EVT_SET(LocalVar(10), 174)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 79)
    EVT_SET(LocalVar(3), 79)
    EVT_SET(LocalVar(4), 80)
    EVT_SET(LocalVar(5), 81)
    EVT_SET(LocalVar(6), 82)
    EVT_SET(LocalVar(10), 0)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 85)
    EVT_SET(LocalVar(3), 85)
    EVT_SET(LocalVar(4), 86)
    EVT_SET(LocalVar(5), 87)
    EVT_SET(LocalVar(6), 88)
    EVT_SET(LocalVar(10), 0)
    EVT_EXEC(N(8024314C))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_36FC) = {
    0x00000000,
};

#define SUPER_BLOCK_MAPVAR MapVar(0)
#define SUPER_BLOCK_GAMEFLAG GF_FLO16_SuperBlock
#include "world/common/atomic/SuperBlockData.inc.c"

EvtScript N(80243D48) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetCamTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243DB0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, 6)
    EVT_WAIT(2)
    EVT_CALL(GetPlayerPos, LocalVar(7), LocalVar(8), LocalVar(9))
    EVT_EXEC_GET_TID(N(80243D48), LocalVar(10))
    EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.7))
    EVT_CALL(PlayerJump, 450, 180, -120, 30)
    EVT_CALL(SetPlayerActionState, 0)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243E80) = {
    EVT_IF_EQ(AreaFlag(39), 0)
        EVT_CALL(N(UnkFunc44))
        EVT_IF_EQ(LocalVar(0), 0)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_SWITCH(LocalVar(0))
            EVT_CASE_RANGE(620, 660)
                EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 640, 145, -100, 13, GF_FLO16_Item_StarPiece)
                EVT_SET(AreaFlag(39), 1)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_SET(AreaFlag(39), 0)
    EVT_BIND_TRIGGER(N(80243E80), TRIGGER_FLOOR_TOUCH, 20, 1, 0)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SuperBlock), 350, 240, -100, 0, MAKE_ENTITY_END)
    EVT_SETUP_SUPER_BLOCK(SUPER_BLOCK_MAPVAR, SUPER_BLOCK_GAMEFLAG)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 472, 100, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(80243DB0)))
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/SuperBlock.inc.c"

#include "world/common/UnkFunc44.inc.c"
