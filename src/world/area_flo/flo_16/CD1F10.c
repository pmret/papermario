#include "flo_16.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -720.0f,   0.0f, 0.0f,  90.0f },
    {  710.0f, 100.0f, 0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_16_tattle },
};

EvtScript N(802429D0) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
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
    EVT_SET(EVT_SAVE_VAR(425), 38)
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
        EVT_SET(EVT_VAR(0), 0)
        EVT_SET(EVT_VAR(1), 0)
        EVT_LABEL(0)
        EVT_ADD(EVT_VAR(0), 140)
        EVT_IF_GT(EVT_VAR(0), 65536)
            EVT_ADD(EVT_VAR(0), -65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 1, 0, EVT_VAR(0), 0)
        EVT_ADD(EVT_VAR(1), -200)
        EVT_IF_LT(EVT_VAR(1), 0)
            EVT_ADD(EVT_VAR(1), 65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 2, 0, EVT_VAR(1), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_EXEC(N(802451C4))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(80242AF8)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(802429D0))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_80240000_CD1E30))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80242EA0) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SET(EVT_VAR(11), EVT_VAR(1))
    EVT_SET(EVT_VAR(12), EVT_VAR(2))
    EVT_SET(EVT_VAR(13), EVT_VAR(3))
    EVT_SET(EVT_VAR(14), EVT_VAR(4))
    EVT_SUB(EVT_VAR(12), EVT_VAR(0))
    EVT_SUB(EVT_VAR(13), EVT_VAR(1))
    EVT_SETF(EVT_VAR(0), EVT_VAR(12))
    EVT_DIVF(EVT_VAR(0), EVT_FIXED(100.0))
    EVT_SETF(EVT_VAR(15), EVT_FIXED(100.0))
    EVT_DIVF(EVT_VAR(15), EVT_VAR(0))
    EVT_ADD(EVT_VAR(15), 11)
    EVT_SET(EVT_VAR(5), 200)
    EVT_DIV(EVT_VAR(5), EVT_VAR(15))
    EVT_ADD(EVT_VAR(5), 1)
    EVT_LOOP(EVT_VAR(5))
        EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
        EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
        EVT_CALL(RandInt, 199, EVT_VAR(2))
        EVT_SET(EVT_VAR(3), 210)
        EVT_SUB(EVT_VAR(3), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), EVT_VAR(10))
        EVT_ADD(EVT_VAR(1), EVT_VAR(11))
        EVT_ADD(EVT_VAR(2), EVT_VAR(14))
        EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(2), EVT_VAR(1), EVT_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
    EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
    EVT_ADD(EVT_VAR(0), EVT_VAR(10))
    EVT_ADD(EVT_VAR(1), EVT_VAR(11))
    EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024314C) = {
    EVT_SET(EVT_VAR(9), EVT_VAR(6))
    EVT_SET(EVT_VAR(8), EVT_VAR(5))
    EVT_SET(EVT_VAR(7), EVT_VAR(4))
    EVT_SET(EVT_VAR(6), EVT_VAR(3))
    EVT_SET(EVT_VAR(5), EVT_VAR(2))
    EVT_SET(EVT_VAR(4), EVT_VAR(1))
    EVT_SET(EVT_VAR(3), EVT_VAR(0))
    EVT_CALL(EnableModel, EVT_VAR(6), 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(N(UnkFunc43))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(EnableModel, EVT_VAR(6), 1)
    EVT_END_THREAD
    EVT_IF_NE(EVT_VAR(10), 0)
        EVT_THREAD
            EVT_WAIT_FRAMES(5)
            EVT_SET(EVT_VAR(0), EVT_VAR(3))
            EVT_SET(EVT_VAR(1), EVT_VAR(4))
            EVT_SET(EVT_VAR(2), EVT_VAR(5))
            EVT_ADD(EVT_VAR(1), 10)
            EVT_ADD(EVT_VAR(2), 8)
            EVT_CALL(PlayEffect, 0x11, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 15, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
            EVT_SUB(EVT_VAR(1), 10)
            EVT_CALL(MakeItemEntity, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 14, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlaySoundAt, 0xF8, 0, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, 2)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, EVT_VAR(8), EVT_VAR(0), 1, 0, 0)
    EVT_CALL(RotateModel, EVT_VAR(9), EVT_VAR(0), 1, 0, 0)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, EVT_VAR(7), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024346C) = {
    EVT_CALL(ModifyColliderFlags, 3, 20, 0x00000006)
    EVT_SET(EVT_VAR(0), -740)
    EVT_SET(EVT_VAR(1), -140)
    EVT_SET(EVT_VAR(2), -260)
    EVT_SET(EVT_VAR(3), -55)
    EVT_SET(EVT_VAR(4), 100)
    EVT_EXEC(N(80242EA0))
    EVT_SET(EVT_VAR(0), 250)
    EVT_SET(EVT_VAR(1), -140)
    EVT_SET(EVT_VAR(2), 725)
    EVT_SET(EVT_VAR(3), -55)
    EVT_SET(EVT_VAR(4), 180)
    EVT_EXEC(N(80242EA0))
    EVT_CALL(GetModelCenter, 65)
    EVT_SET(EVT_VAR(3), 65)
    EVT_SET(EVT_VAR(4), 66)
    EVT_SET(EVT_VAR(5), 67)
    EVT_SET(EVT_VAR(6), 68)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 71)
    EVT_SET(EVT_VAR(3), 71)
    EVT_SET(EVT_VAR(4), 72)
    EVT_SET(EVT_VAR(5), 73)
    EVT_SET(EVT_VAR(6), 74)
    EVT_SET(EVT_VAR(10), 174)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 79)
    EVT_SET(EVT_VAR(3), 79)
    EVT_SET(EVT_VAR(4), 80)
    EVT_SET(EVT_VAR(5), 81)
    EVT_SET(EVT_VAR(6), 82)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 85)
    EVT_SET(EVT_VAR(3), 85)
    EVT_SET(EVT_VAR(4), 86)
    EVT_SET(EVT_VAR(5), 87)
    EVT_SET(EVT_VAR(6), 88)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(8024314C))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_36FC) = {
    0x00000000,
};

#define SUPER_BLOCK_MAPVAR EVT_MAP_VAR(0)
#define SUPER_BLOCK_GAMEFLAG EVT_SAVE_FLAG(1403)
#include "world/common/atomic/SuperBlockData.inc.c"

EvtScript N(80243D48) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243DB0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, 6)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(GetPlayerPos, EVT_VAR(7), EVT_VAR(8), EVT_VAR(9))
    EVT_EXEC_GET_TID(N(80243D48), EVT_VAR(10))
    EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.7))
    EVT_CALL(PlayerJump, 450, 180, -120, 30)
    EVT_CALL(SetPlayerActionState, 0)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243E80) = {
    EVT_IF_EQ(EVT_AREA_FLAG(39), 0)
        EVT_CALL(N(UnkFunc44))
        EVT_IF_EQ(EVT_VAR(0), 0)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_SWITCH(EVT_VAR(0))
            EVT_CASE_RANGE(620, 660)
                EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 640, 145, -100, 13, EVT_SAVE_FLAG(1388))
                EVT_SET(EVT_AREA_FLAG(39), 1)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_SET(EVT_AREA_FLAG(39), 0)
    EVT_BIND_TRIGGER(N(80243E80), TRIGGER_FLOOR_TOUCH, 20, 1, 0)
    EVT_CALL(MakeEntity, 0x802EA910, 350, 240, -100, 0, MAKE_ENTITY_END)
    EVT_SETUP_SUPER_BLOCK(SUPER_BLOCK_MAPVAR, SUPER_BLOCK_GAMEFLAG)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 472, 100, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(80243DB0)))
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/SuperBlock.inc.c"

#include "world/common/UnkFunc44.inc.c"
