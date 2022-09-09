#include "flo_25.h"

#include "common/foliage.inc.c"

FoliageModelList N(tree1_Leaves) = {
    .count = 3,
    .models = { 22, 23, 24 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 21 }
};

FoliageDropList N(tree1_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_YELLOW_BERRY,
            .pos = { -432, 84, -44 },
            .spawnMode = 0xC,
            .spawnFlag = AreaFlag(33),
        },
        {
            .itemID = ITEM_YELLOW_BERRY,
            .pos = { -346, 72, -114 },
            .spawnMode = 0xC,
            .spawnFlag = AreaFlag(34),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_802446AC) = { -388.0f, 0.0f, -92.0f, 0.0f };

EvtScript N(802446BC) = {
    EVT_SET(AreaFlag(33), 0)
    EVT_SET(AreaFlag(34), 0)
    EVT_SET(LocalVar(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 12, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_802446AC)), 1, 0)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_4734)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80244740) = {
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

EvtScript N(802449EC) = {
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

EvtScript N(80244D0C) = {
    EVT_CALL(GetModelCenter, 57)
    EVT_SET(LocalVar(3), 57)
    EVT_SET(LocalVar(4), 58)
    EVT_SET(LocalVar(5), 59)
    EVT_SET(LocalVar(6), 60)
    EVT_SET(LocalVar(10), 0)
    EVT_EXEC(N(802449EC))
    EVT_CALL(GetModelCenter, 63)
    EVT_SET(LocalVar(3), 63)
    EVT_SET(LocalVar(4), 64)
    EVT_SET(LocalVar(5), 65)
    EVT_SET(LocalVar(6), 66)
    EVT_SET(LocalVar(10), 0)
    EVT_EXEC(N(802449EC))
    EVT_CALL(GetModelCenter, 69)
    EVT_SET(LocalVar(3), 69)
    EVT_SET(LocalVar(4), 70)
    EVT_SET(LocalVar(5), 71)
    EVT_SET(LocalVar(6), 72)
    EVT_SET(LocalVar(10), 174)
    EVT_EXEC(N(802449EC))
    EVT_CALL(GetModelCenter, 75)
    EVT_SET(LocalVar(3), 75)
    EVT_SET(LocalVar(4), 76)
    EVT_SET(LocalVar(5), 77)
    EVT_SET(LocalVar(6), 78)
    EVT_SET(LocalVar(10), 0)
    EVT_EXEC(N(802449EC))
    EVT_RETURN
    EVT_END
};
