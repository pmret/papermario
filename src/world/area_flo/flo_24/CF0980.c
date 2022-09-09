#include "flo_24.h"
#include "message_ids.h"
#include "entity.h"

EntryList N(entryList) = {
    { -455.0f, 0.0f, 0.0f,  90.0f },
    {  455.0f, 0.0f, 0.0f, 270.0f },
    {  455.0f, 0.0f, 0.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_24_tattle },
};

EvtScript N(80240600) = {
    EVT_IF_LT(GB_StoryProgress, 53)
        EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, 49)
        EVT_CALL(PlaySound, 0x80000022)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80240690) = {
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

EvtScript N(exitWalk_8024093C) = EXIT_WALK_SCRIPT(60,  0, "flo_08",  1);

EvtScript N(exitWalk_80240998) = EXIT_WALK_SCRIPT(60,  1, "flo_10",  0);

EvtScript N(802409F4) = {
    EVT_BIND_TRIGGER(N(exitWalk_8024093C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80240998), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_CALL(MakeTransformGroup, 93)
    EVT_CALL(MakeTransformGroup, 100)
    EVT_EXEC(N(80241728))
    EVT_EXEC(N(80241ABC))
    EVT_CALL(ModifyColliderFlags, 3, 29, 0x00000004)
    EVT_CALL(ModifyColliderFlags, 3, 27, 0x00000004)
    EVT_CALL(ModifyColliderFlags, 3, 28, 0x00000004)
    EVT_CALL(ModifyColliderFlags, 0, 29, 0x00080000)
    EVT_CALL(ModifyColliderFlags, 0, 27, 0x00080000)
    EVT_CALL(ModifyColliderFlags, 0, 28, 0x00080000)
    EVT_CALL(ModifyColliderFlags, 3, 23, 0x00000001)
    EVT_SET(LocalVar(0), -480)
    EVT_SET(LocalVar(1), -350)
    EVT_SET(LocalVar(2), -65)
    EVT_SET(LocalVar(3), -260)
    EVT_SET(LocalVar(4), 0)
    EVT_EXEC(N(80240690))
    EVT_SET(LocalVar(0), 100)
    EVT_SET(LocalVar(1), -350)
    EVT_SET(LocalVar(2), 480)
    EVT_SET(LocalVar(3), -260)
    EVT_SET(LocalVar(4), 0)
    EVT_EXEC(N(80240690))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 2)
        EVT_EXEC(N(8024183C))
        EVT_EXEC(N(802409F4))
    EVT_ELSE
        EVT_SET(LocalVar(0), EVT_PTR(N(802409F4)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_EXEC_WAIT(N(80240600))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_80240000_CF0940))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_D38)[] = {
    0x00000000, 0x00000000,
};

#include "common/foliage.inc.c"

FoliageModelList N(tree1_Leaves) = {
    .count = 6,
    .models = { 20, 18, 21, 22, 23, 19 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 17 }
};

FoliageDropList N(tree1_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_BUBBLE_BERRY,
            .pos = { -38, 87, -156 },
            .spawnMode = 0xC,
            .spawnFlag = AreaFlag(31),
        },
        {
            .itemID = ITEM_BUBBLE_BERRY,
            .pos = { 39, 65, -208 },
            .spawnMode = 0xC,
            .spawnFlag = AreaFlag(32),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_80241718) = { 1.0f, 0.0f, -192.0f, 0.0f };

EvtScript N(80241728) = {
    EVT_SET(AreaFlag(31), 0)
    EVT_SET(AreaFlag(32), 0)
    EVT_SET(LocalVar(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 13, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80241718)), 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(updateTexturePan_802417A0) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_IF_EQ(LocalVar(5), 1)
        EVT_IF_EQ(LocalVar(6), 1)
            EVT_IF_EQ(LocalVar(7), 1)
                EVT_IF_EQ(LocalVar(8), 1)
                    EVT_CALL(N(UpdateTexturePanSmooth))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(UpdateTexturePanStepped))
    EVT_RETURN
    EVT_END
};

extern const char N(flo_10_name_hack)[];

// BUG: missing END_SPAWN_THREADs
#ifdef NON_EQUIVALENT
EvtScript N(8024183C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(TranslateGroup, 100, 0, 45, 0)
    EVT_CALL(UseSettingsFrom, 0, 170, 0, 160)
    EVT_CALL(SetPanTarget, 0, 170, -90, 160)
    EVT_CALL(SetCamDistance, 0, 800)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(18.5), EVT_FIXED(-7.5))
    EVT_CALL(SetCamPosA, 0, EVT_FIXED(-300.0), EVT_FIXED(200.0))
    EVT_CALL(SetCamPosB, 0, EVT_FIXED(300.0), EVT_FIXED(-150.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(PlaySound, 0x80000050)
    EVT_THREAD
        EVT_CALL(MakeLerp, 80, 90, 10, 0)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 101, LocalVar(0), 1, 0, 0)
        EVT_CALL(RotateModel, 103, LocalVar(0), 1, 0, 0)
        EVT_IF_EQ(LocalVar(1), 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(MakeLerp, 45, 100, 150, 0)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateGroup, 100, 0, LocalVar(0), 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LocalVar(1), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(30)
            EVT_SET(GB_StoryProgress, 49)
            EVT_CALL(GotoMap, EVT_PTR(UNK_STR_80242280), 2)
            EVT_WAIT(100)
            EVT_RETURN
            EVT_END
};
#else
EvtScript N(8024183C) = {
    EVT_CMD(EVT_OP_CALL, EVT_PTR(DisablePlayerInput), 1),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateGroup), 100, 0, 45, 0),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(UseSettingsFrom), 0, 170, 0, 160),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetPanTarget), 0, 170, -90, 160),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetCamDistance), 0, 800),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetCamPitch), 0, EVT_FIXED(18.5), EVT_FIXED(-7.5)),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetCamPosA), 0, EVT_FIXED(-300.0), EVT_FIXED(200.0)),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetCamPosB), 0, EVT_FIXED(300.0), EVT_FIXED(-150.0)),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetCamSpeed), 0, EVT_FIXED(90.0)),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(PanToTarget), 0, 0, 1),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(PlaySound), 0x80000050),
    EVT_CMD(EVT_OP_THREAD),
        EVT_CMD(EVT_OP_CALL, EVT_PTR(MakeLerp), 80, 90, 10, 0),
        EVT_CMD(EVT_OP_LABEL, 0),
        EVT_CMD(EVT_OP_CALL, EVT_PTR(UpdateLerp)),
        EVT_CMD(EVT_OP_CALL, EVT_PTR(RotateModel), 101, LocalVar(0), 1, 0, 0),
        EVT_CMD(EVT_OP_CALL, EVT_PTR(RotateModel), 103, LocalVar(0), 1, 0, 0),
        EVT_CMD(EVT_OP_IF_EQ, LocalVar(1), 1),
            EVT_CMD(EVT_OP_WAIT_FRAMES, 1),
            EVT_CMD(EVT_OP_GOTO, 0),
        EVT_CMD(EVT_OP_END_IF),
        EVT_CMD(EVT_OP_THREAD),
            EVT_CMD(EVT_OP_CALL, EVT_PTR(MakeLerp), 45, 100, 150, 0),
            EVT_CMD(EVT_OP_LOOP, 0),
                EVT_CMD(EVT_OP_CALL, EVT_PTR(UpdateLerp)),
                EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateGroup), 100, 0, LocalVar(0), 0),
                EVT_CMD(EVT_OP_WAIT_FRAMES, 1),
                EVT_CMD(EVT_OP_IF_EQ, LocalVar(1), 0),
                    EVT_CMD(EVT_OP_BREAK_LOOP),
                EVT_CMD(EVT_OP_END_IF),
            EVT_CMD(EVT_OP_END_LOOP),
            EVT_CMD(EVT_OP_WAIT_FRAMES, 30),
            EVT_CMD(EVT_OP_SET, GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER),
            EVT_CMD(EVT_OP_CALL, EVT_PTR(GotoMap), EVT_PTR(N(flo_10_name_hack)), 2),
            EVT_CMD(EVT_OP_WAIT_FRAMES, 100),
            EVT_CMD(EVT_OP_RETURN),
            EVT_CMD(EVT_OP_END)
        };
#endif

EvtScript N(80241ABC) = {
    EVT_IF_LT(GB_StoryProgress, 49)
        EVT_CALL(EnableGroup, 94, 0)
        EVT_CALL(ModifyColliderFlags, 0, 30, 0x7FFFFE00)
    EVT_ELSE
        EVT_CALL(EnableGroup, 65, 0)
    EVT_END_IF
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_IF_NE(LocalVar(0), 2)
        EVT_CALL(EnableGroup, 105, 0)
    EVT_END_IF
    EVT_CALL(EnableTexPanning, 89, 1)
    EVT_CALL(EnableTexPanning, 97, 1)
    EVT_CALL(EnableTexPanning, 90, 1)
    EVT_CALL(EnableTexPanning, 98, 1)
    EVT_CALL(EnableTexPanning, 91, 1)
    EVT_CALL(EnableTexPanning, 92, 1)
    EVT_CALL(EnableTexPanning, 101, 1)
    EVT_CALL(EnableTexPanning, 103, 1)
    EVT_CALL(EnableTexPanning, 99, 1)
    EVT_THREAD
        EVT_SET(LocalVar(0), 1)
        EVT_SET(LocalVar(1), 140)
        EVT_SET(LocalVar(2), -80)
        EVT_SET(LocalVar(3), -70)
        EVT_SET(LocalVar(4), 100)
        EVT_SET(LocalVar(5), 1)
        EVT_SET(LocalVar(6), 1)
        EVT_SET(LocalVar(7), 1)
        EVT_SET(LocalVar(8), 1)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LocalVar(10), 0)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_EXEC(N(updateTexturePan_802417A0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(0), 2)
        EVT_SET(LocalVar(1), -70)
        EVT_SET(LocalVar(2), 100)
        EVT_SET(LocalVar(3), 100)
        EVT_SET(LocalVar(4), -40)
        EVT_SET(LocalVar(5), 1)
        EVT_SET(LocalVar(6), 1)
        EVT_SET(LocalVar(7), 1)
        EVT_SET(LocalVar(8), 1)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LocalVar(10), 0)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_EXEC(N(updateTexturePan_802417A0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(0), 3)
        EVT_SET(LocalVar(1), 0)
        EVT_SET(LocalVar(2), -800)
        EVT_SET(LocalVar(3), 0)
        EVT_SET(LocalVar(4), 0)
        EVT_SET(LocalVar(5), 0)
        EVT_SET(LocalVar(6), 1)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LocalVar(10), 0)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_EXEC(N(updateTexturePan_802417A0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(0), 4)
        EVT_SET(LocalVar(1), 0)
        EVT_SET(LocalVar(2), -800)
        EVT_SET(LocalVar(3), -200)
        EVT_SET(LocalVar(4), 100)
        EVT_SET(LocalVar(5), 0)
        EVT_SET(LocalVar(6), 1)
        EVT_SET(LocalVar(7), 1)
        EVT_SET(LocalVar(8), 1)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LocalVar(10), 0)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_EXEC(N(updateTexturePan_802417A0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(0), 5)
        EVT_SET(LocalVar(1), 0)
        EVT_SET(LocalVar(2), -2500)
        EVT_SET(LocalVar(3), 0)
        EVT_SET(LocalVar(4), 0)
        EVT_SET(LocalVar(5), 0)
        EVT_SET(LocalVar(6), 1)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LocalVar(10), 0)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_EXEC(N(updateTexturePan_802417A0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(0), 6)
        EVT_SET(LocalVar(1), 0)
        EVT_SET(LocalVar(2), -2500)
        EVT_SET(LocalVar(3), -200)
        EVT_SET(LocalVar(4), 100)
        EVT_SET(LocalVar(5), 1)
        EVT_SET(LocalVar(6), 1)
        EVT_SET(LocalVar(7), 1)
        EVT_SET(LocalVar(8), 1)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LocalVar(10), 0)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_EXEC(N(updateTexturePan_802417A0))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

static s32 N(pad_21A4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -325, 60, -140, 0, 154, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO24_ItemBlock_DizzyDial)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 325, 60, -140, 0, 163, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO24_HiddenItem_MapleSyrup)
    EVT_CALL(MakeEntity, &Entity_HiddenPanel, 335, 0, -160, 0, 8, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_FLO24_HiddenPanel)
    EVT_RETURN
    EVT_END
};

const char N(flo_10_name_hack)[] = "flo_10";
