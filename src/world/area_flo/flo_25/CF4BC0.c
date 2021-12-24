#include "flo_25.h"

#include "world/common/foliage.inc.c"

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
            .spawnFlag = EVT_AREA_FLAG(33),
        },
        {
            .itemID = ITEM_YELLOW_BERRY,
            .pos = { -346, 72, -114 },
            .spawnMode = 0xC,
            .spawnFlag = EVT_AREA_FLAG(34),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_802446AC) = { -388.0f, 0.0f, -92.0f, 0.0f };

EvtSource N(802446BC) = {
    EVT_SET(EVT_AREA_FLAG(33), 0)
    EVT_SET(EVT_AREA_FLAG(34), 0)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 12, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_802446AC)), 1, 0)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_4734)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80244740) = {
    EVT_SET_GROUP(11)
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

EvtSource N(802449EC) = {
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

EvtSource N(80244D0C) = {
    EVT_CALL(GetModelCenter, 57)
    EVT_SET(EVT_VAR(3), 57)
    EVT_SET(EVT_VAR(4), 58)
    EVT_SET(EVT_VAR(5), 59)
    EVT_SET(EVT_VAR(6), 60)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(802449EC))
    EVT_CALL(GetModelCenter, 63)
    EVT_SET(EVT_VAR(3), 63)
    EVT_SET(EVT_VAR(4), 64)
    EVT_SET(EVT_VAR(5), 65)
    EVT_SET(EVT_VAR(6), 66)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(802449EC))
    EVT_CALL(GetModelCenter, 69)
    EVT_SET(EVT_VAR(3), 69)
    EVT_SET(EVT_VAR(4), 70)
    EVT_SET(EVT_VAR(5), 71)
    EVT_SET(EVT_VAR(6), 72)
    EVT_SET(EVT_VAR(10), 174)
    EVT_EXEC(N(802449EC))
    EVT_CALL(GetModelCenter, 75)
    EVT_SET(EVT_VAR(3), 75)
    EVT_SET(EVT_VAR(4), 76)
    EVT_SET(EVT_VAR(5), 77)
    EVT_SET(EVT_VAR(6), 78)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(802449EC))
    EVT_RETURN
    EVT_END
};
