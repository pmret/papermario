#include "flo_18.h"
#include "message_ids.h"
#include "sprite/npc/flying_magikoopa.h"
#include "sprite/npc/lakitu.h"
#include "sprite/npc/magikoopa.h"
#include "sprite/npc/world_lakilester.h"
#include "effects.h"

enum {
    NPC_LAKITU0,
    NPC_LAKITU1,
    NPC_LAKITU2,
    NPC_MAGIKOOPA,
    NPC_FLYING_MAGIKOOPA,
};

EntryList N(entryList) = {
    { -320.0f, 0.0f,  0.0f,  90.0f },
    {   36.0f, 0.0f, 40.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_18_tattle },
};

EvtScript N(80240830) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_PUFF_PUFF_MACHINE, 0, 8)
            EVT_CALL(PlaySoundAtCollider, 20, 0x80000025, 0)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_8B8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(updateTexturePan_802408C0) = {
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

EvtScript N(exitWalk_8024095C) = EXIT_WALK_SCRIPT(60,  0, "flo_17",  1);

EvtScript N(802409B8) = {
    EVT_BIND_TRIGGER(N(exitWalk_8024095C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(lavaResetList_802409E4)[] = {
    0x0000000B, 0xC3480000, 0x00000000, 0x42F00000, 0x0000000C, 0x00000000, 0x00000000, 0x42F00000,
    0x0000000D, 0x432A0000, 0x00000000, 0x42F00000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_ADDR(N(npcGroupList_8024669C)))
    EVT_EXEC(N(80247024))
    EVT_EXEC(N(802436BC))
    EVT_EXEC(N(802456D4))
    EVT_CALL(ModifyColliderFlags, 3, 8, 0x00000002)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_ADDR(N(lavaResetList_802409E4)))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, 9, 1)
    EVT_CALL(EnableTexPanning, 11, 1)
    EVT_CALL(EnableTexPanning, 12, 1)
    EVT_CALL(EnableTexPanning, 13, 1)
    EVT_CALL(EnableTexPanning, 14, 1)
    EVT_CALL(EnableTexPanning, 15, 1)
    EVT_CALL(EnableTexPanning, 7, 1)
    EVT_CALL(EnableTexPanning, 8, 1)
    EVT_CALL(EnableTexPanning, 10, 1)
    EVT_CALL(EnableTexPanning, 16, 1)
    EVT_CALL(EnableTexPanning, 17, 1)
    EVT_THREAD
        EVT_SET(LocalVar(0), 1)
        EVT_SET(LocalVar(1), -140)
        EVT_SET(LocalVar(2), 0)
        EVT_SET(LocalVar(3), 0)
        EVT_SET(LocalVar(4), 0)
        EVT_SET(LocalVar(5), 1)
        EVT_SET(LocalVar(6), 0)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LocalVar(10), 0)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_EXEC(N(updateTexturePan_802408C0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(0), 2)
        EVT_SET(LocalVar(1), -200)
        EVT_SET(LocalVar(2), 0)
        EVT_SET(LocalVar(3), 0)
        EVT_SET(LocalVar(4), 0)
        EVT_SET(LocalVar(5), 1)
        EVT_SET(LocalVar(6), 0)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LocalVar(10), 0)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_EXEC(N(updateTexturePan_802408C0))
    EVT_END_THREAD
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
        EVT_SET(LocalVar(0), EVT_ADDR(N(802409B8)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
        EVT_EXEC(N(80244058))
        EVT_EXEC(N(802409B8))
    EVT_END_IF
    EVT_EXEC_WAIT(N(80240830))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_8024030C_CDC9AC))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_E88)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(80240E90) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_LOOP(0)
        EVT_CALL(PlayEffect, 0x5E, 0, EVT_FIXED(-16.0), EVT_FIXED(102.0), EVT_FIXED(-4.1), EVT_FIXED(80.9), EVT_FIXED(102.0), EVT_FIXED(-4.1), EVT_FIXED(0.5), 6, 0, 0, 0, 0)
        EVT_CALL(N(func_80240340_CDC9E0))
        EVT_WAIT(4)
        EVT_CALL(PlayEffect, 0x5E, 0, EVT_FIXED(80.9), EVT_FIXED(102.0), EVT_FIXED(-4.1), EVT_FIXED(-16.0), EVT_FIXED(102.0), EVT_FIXED(-4.1), EVT_FIXED(0.5), 6, 0, 0, 0, 0)
        EVT_CALL(N(func_80240340_CDC9E0))
        EVT_WAIT(4)
        EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LocalVar(0), 6)
    EVT_LOOP(5)
        EVT_CALL(PlayEffect, 0x5E, 0, EVT_FIXED(-16.0), EVT_FIXED(102.0), EVT_FIXED(-4.1), EVT_FIXED(80.9), EVT_FIXED(102.0), EVT_FIXED(-4.1), EVT_FIXED(0.5), 6, 0, 0, 0, 0)
        EVT_CALL(N(func_80240340_CDC9E0))
        EVT_WAIT(LocalVar(0))
        EVT_ADD(LocalVar(0), 2)
        EVT_CALL(PlayEffect, 0x5E, 0, EVT_FIXED(80.9), EVT_FIXED(102.0), EVT_FIXED(-4.1), EVT_FIXED(-16.0), EVT_FIXED(102.0), EVT_FIXED(-4.1), EVT_FIXED(0.5), 6, 0, 0, 0, 0)
        EVT_CALL(N(func_80240340_CDC9E0))
        EVT_WAIT(LocalVar(0))
        EVT_ADD(LocalVar(0), 2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80241094) = {
    EVT_CALL(EnableModel, LocalVar(15), 1)
    EVT_SET(LocalVar(14), 159)
    EVT_LOOP(LocalVar(14))
        EVT_ADDF(LocalVar(3), 0)
        EVT_ADDF(LocalVar(4), EVT_FIXED(0.0))
        EVT_SETF(LocalVar(5), EVT_FIXED(0.01))
        EVT_ADDF(LocalVar(0), LocalVar(3))
        EVT_ADDF(LocalVar(1), LocalVar(4))
        EVT_ADDF(LocalVar(2), LocalVar(5))
        EVT_MULF(LocalVar(6), EVT_FIXED(1.01))
        EVT_ADDF(LocalVar(7), EVT_FIXED(0.01))
        EVT_SETF(LocalVar(8), LocalVar(6))
        EVT_CALL(N(UnkFloatFunc), LocalVar(14), LocalVar(10), EVT_FIXED(0.0), EVT_FIXED(0.203125), 15, 0, 0)
        EVT_ADDF(LocalVar(8), LocalVar(10))
        EVT_SETF(LocalVar(9), LocalVar(7))
        EVT_CALL(N(UnkFloatFunc), LocalVar(14), LocalVar(10), EVT_FIXED(0.0), EVT_FIXED(0.203125), 20, 0, 90)
        EVT_ADDF(LocalVar(9), LocalVar(10))
        EVT_SETF(LocalVar(10), LocalVar(0))
        EVT_MULF(LocalVar(10), EVT_FIXED(10.0))
        EVT_CALL(TranslateModel, LocalVar(15), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(ScaleModel, LocalVar(15), LocalVar(8), LocalVar(9), 1)
        EVT_CALL(RotateModel, LocalVar(15), LocalVar(10), 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LocalVar(15), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241284) = {
    EVT_SET(LocalVar(14), 0)
    EVT_LABEL(0)
    EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_SETF(LocalVar(0), EVT_FIXED(132.0))
    EVT_SETF(LocalVar(1), EVT_FIXED(90.0))
    EVT_SETF(LocalVar(2), EVT_FIXED(-30.0))
    EVT_CALL(RandInt, 100, LocalVar(3))
    EVT_ADDF(LocalVar(3), -50)
    EVT_DIVF(LocalVar(3), EVT_FIXED(200.0))
    EVT_SETF(LocalVar(4), EVT_FIXED(1.0))
    EVT_SETF(LocalVar(5), 0)
    EVT_SETF(LocalVar(6), EVT_FIXED(0.296875))
    EVT_SETF(LocalVar(7), EVT_FIXED(0.296875))
    EVT_SET(LocalVar(15), LocalVar(14))
    EVT_ADD(LocalVar(15), 10000)
    EVT_EXEC(N(80241094))
    EVT_ADD(LocalVar(14), 1)
    EVT_IF_GE(LocalVar(14), 16)
        EVT_SET(LocalVar(14), 0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802413F0) = {
    EVT_IF_EQ(MapFlag(2), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MapFlag(2), 1)
    EVT_SET(LocalVar(15), 0)
    EVT_LOOP(12)
        EVT_CALL(RandInt, 80, LocalVar(0))
        EVT_SUB(LocalVar(0), 40)
        EVT_CALL(RandInt, 50, LocalVar(1))
        EVT_CALL(RandInt, 50, LocalVar(2))
        EVT_SUB(LocalVar(2), 25)
        EVT_CALL(PlayEffect, 0x0, LocalVar(0), LocalVar(1), LocalVar(2), 5, 10, 1, 1, 0, 0, 0, 0, 0, 0)
        EVT_ADD(LocalVar(15), 1)
        EVT_CALL(N(UnkFloatFunc), LocalVar(15), LocalVar(14), EVT_FIXED(1.0), EVT_FIXED(1.09375), 2, 0, 0)
        EVT_CALL(N(UnkFloatFunc), LocalVar(15), LocalVar(13), EVT_FIXED(1.09375), EVT_FIXED(1.0), 2, 0, 0)
        EVT_SETF(LocalVar(0), LocalVar(14))
        EVT_SETF(LocalVar(1), LocalVar(13))
        EVT_SETF(LocalVar(2), LocalVar(14))
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
            EVT_CALL(ScaleModel, 31, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(ScaleModel, 32, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_END_IF
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
            EVT_CALL(ScaleModel, 19, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(ScaleModel, 20, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 1)
            EVT_CALL(ScaleModel, 21, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 1)
                EVT_CALL(ScaleModel, 22, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(ScaleModel, 23, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(ScaleModel, 24, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(ScaleModel, 25, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(ScaleModel, 26, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ScaleModel, 27, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 2)
                EVT_CALL(ScaleModel, 29, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(ScaleModel, 41, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(ScaleModel, 33, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ScaleModel, 36, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(ScaleModel, 37, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(ScaleModel, 38, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(ScaleModel, 39, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(ScaleModel, 40, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(ScaleModel, 34, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_SUBF(LocalVar(0), EVT_FIXED(1.046875))
        EVT_MULF(LocalVar(0), EVT_FIXED(100.0))
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
            EVT_CALL(RotateModel, 31, LocalVar(0), 0, 0, 1)
            EVT_CALL(RotateModel, 32, LocalVar(0), 0, 0, 1)
        EVT_END_IF
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
            EVT_CALL(RotateModel, 19, LocalVar(0), 0, 0, 1)
            EVT_CALL(RotateModel, 20, LocalVar(0), 0, 0, 1)
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 1)
            EVT_CALL(RotateModel, 21, LocalVar(0), 0, 0, 1)
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 1)
                EVT_CALL(RotateModel, 22, LocalVar(0), 0, 0, 1)
                EVT_CALL(RotateModel, 23, LocalVar(0), 0, 0, 1)
                EVT_CALL(RotateModel, 24, LocalVar(0), 0, 0, 1)
                EVT_CALL(RotateModel, 25, LocalVar(0), 0, 0, 1)
                EVT_CALL(RotateModel, 26, LocalVar(0), 0, 0, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(RotateModel, 27, LocalVar(0), 0, 0, 1)
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 2)
                EVT_CALL(RotateModel, 29, LocalVar(0), 0, 0, 1)
                EVT_CALL(RotateModel, 41, LocalVar(0), 0, 0, 1)
                EVT_CALL(RotateModel, 33, LocalVar(0), 0, 0, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(RotateModel, 36, LocalVar(0), 0, 0, 1)
        EVT_CALL(RotateModel, 37, LocalVar(0), 0, 0, 1)
        EVT_CALL(RotateModel, 38, LocalVar(0), 0, 0, 1)
        EVT_CALL(RotateModel, 39, LocalVar(0), 0, 0, 1)
        EVT_CALL(RotateModel, 40, LocalVar(0), 0, 0, 1)
        EVT_CALL(RotateModel, 34, LocalVar(0), 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SETF(LocalVar(0), 1)
    EVT_SETF(LocalVar(1), 1)
    EVT_SETF(LocalVar(2), 1)
    EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
        EVT_CALL(ScaleModel, 31, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(ScaleModel, 32, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_END_IF
    EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
        EVT_CALL(ScaleModel, 19, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(ScaleModel, 20, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_END_IF
    EVT_IF_LE(GB_FLO18_MachineDamage_Left, 1)
        EVT_CALL(ScaleModel, 21, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_END_IF
    EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
        EVT_IF_LE(GB_FLO18_MachineDamage_Right, 1)
            EVT_CALL(ScaleModel, 22, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(ScaleModel, 23, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(ScaleModel, 24, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(ScaleModel, 25, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(ScaleModel, 26, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ScaleModel, 27, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
        EVT_IF_LE(GB_FLO18_MachineDamage_Right, 2)
            EVT_CALL(ScaleModel, 29, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(ScaleModel, 41, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(ScaleModel, 33, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ScaleModel, 36, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ScaleModel, 37, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ScaleModel, 38, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ScaleModel, 39, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ScaleModel, 40, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ScaleModel, 34, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_WAIT(1)
    EVT_SET(MapFlag(2), 0)
    EVT_RETURN
    EVT_END
};

#ifdef NON_EQUIVALENT
EvtScript N(80241ED4) = {
    EVT_SETF(LocalVar(0), 0)
    EVT_SETF(LocalVar(1), 0)
    EVT_SETF(LocalVar(2), 0)
    EVT_SETF(LocalVar(3), EVT_FIXED(-1.0))
    EVT_SETF(LocalVar(4), EVT_FIXED(0.0))
    EVT_SETF(LocalVar(5), EVT_FIXED(3.0))
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtCollider, 19, 486, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LocalVar(4), EVT_FIXED(-0.5))
        EVT_ADDF(LocalVar(5), EVT_FIXED(0.09375))
        EVT_ADDF(LocalVar(0), LocalVar(3))
        EVT_ADDF(LocalVar(1), LocalVar(4))
        EVT_ADDF(LocalVar(2), LocalVar(5))
        EVT_IF_LT(LocalVar(1), -10)
            EVT_SETF(LocalVar(1), EVT_FIXED(-10.0))
            EVT_SETF(LocalVar(3), EVT_FIXED(0.0))
            EVT_SETF(LocalVar(4), EVT_FIXED(0.0))
            EVT_IF_GE(LocalVar(2), 80)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(TranslateModel, 31, -78, 19, 2)
    EVT_CALL(TranslateModel, 32, -78, 19, 2)
    EVT_CALL(TranslateModel, 31, LocalVar(0), LocalVar(1), 0)
    EVT_CALL(TranslateModel, 32, LocalVar(0), LocalVar(1), 0)
    EVT_CALL(RotateModel, 31, LocalVar(2), 0, 0, 1)
    EVT_CALL(RotateModel, 32, LocalVar(2), 0, 0, 1)
    EVT_CALL(TranslateModel, 31, 78, -19, -2)
    EVT_CALL(TranslateModel, 32, 78, -19, -2)
    EVT_WAIT(1)
EVT_END_LOOP
EVT_LABEL(0)
EVT_WAIT(30)
EVT_CALL(ModifyColliderFlags, 0, 19, 0x7FFFFE00)
EVT_RETURN
EVT_END
};
#else
EvtScript N(80241ED4) = {
    EVT_CMD(EVT_OP_SETF, LocalVar(0), 0),
    EVT_CMD(EVT_OP_SETF, LocalVar(1), 0),
    EVT_CMD(EVT_OP_SETF, LocalVar(2), 0),
    EVT_CMD(EVT_OP_SETF, LocalVar(3), EVT_FIXED(-1.0)),
    EVT_CMD(EVT_OP_SETF, LocalVar(4), EVT_FIXED(0.0)),
    EVT_CMD(EVT_OP_SETF, LocalVar(5), EVT_FIXED(3.0)),
    EVT_CMD(EVT_OP_THREAD),
        EVT_CMD(EVT_OP_WAIT_FRAMES, 10),
        EVT_CMD(EVT_OP_CALL, EVT_ADDR(PlaySoundAtCollider), 19, 486, 0),
    EVT_CMD(EVT_OP_END_THREAD),
    EVT_CMD(EVT_OP_LOOP, 300),
        EVT_CMD(EVT_OP_ADDF, LocalVar(4), EVT_FIXED(-0.5)),
        EVT_CMD(EVT_OP_ADDF, LocalVar(5), EVT_FIXED(0.09375)),
        EVT_CMD(EVT_OP_ADDF, LocalVar(0), LocalVar(3)),
        EVT_CMD(EVT_OP_ADDF, LocalVar(1), LocalVar(4)),
        EVT_CMD(EVT_OP_ADDF, LocalVar(2), LocalVar(5)),
        EVT_CMD(EVT_OP_IF_LT, LocalVar(1), -10),
            EVT_CMD(EVT_OP_SETF, LocalVar(1), EVT_FIXED(-10.0)),
            EVT_CMD(EVT_OP_SETF, LocalVar(3), EVT_FIXED(0.0)),
            EVT_CMD(EVT_OP_SETF, LocalVar(4), EVT_FIXED(0.0)),
            EVT_CMD(EVT_OP_IF_GE, LocalVar(2), 80),
                EVT_CMD(EVT_OP_GOTO, 0),
            EVT_CMD(EVT_OP_END_IF),
        EVT_CMD(EVT_OP_END_IF),
    EVT_CMD(EVT_OP_END_IF), // BUG: extraneous END_IF
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(TranslateModel), 31, -78, 19, 2),
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(TranslateModel), 32, -78, 19, 2),
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(TranslateModel), 31, LocalVar(0), LocalVar(1), 0),
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(TranslateModel), 32, LocalVar(0), LocalVar(1), 0),
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(RotateModel), 31, LocalVar(2), 0, 0, 1),
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(RotateModel), 32, LocalVar(2), 0, 0, 1),
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(TranslateModel), 31, 78, -19, -2),
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(TranslateModel), 32, 78, -19, -2),
    EVT_CMD(EVT_OP_WAIT_FRAMES, 1),
EVT_CMD(EVT_OP_END_LOOP),
EVT_CMD(EVT_OP_LABEL, 0),
EVT_CMD(EVT_OP_WAIT_FRAMES, 30),
EVT_CMD(EVT_OP_CALL, EVT_ADDR(ModifyColliderFlags), 0, 19, 0x7FFFFE00),
EVT_CMD(EVT_OP_RETURN),
EVT_CMD(EVT_OP_END)
};
#endif

EvtScript N(80242174) = {
    EVT_SETF(LocalVar(0), 0)
    EVT_SETF(LocalVar(1), 0)
    EVT_SETF(LocalVar(2), 0)
    EVT_SETF(LocalVar(3), EVT_FIXED(0.0))
    EVT_SETF(LocalVar(4), EVT_FIXED(0.0))
    EVT_SETF(LocalVar(5), EVT_FIXED(-5.0))
    EVT_THREAD
        EVT_WAIT(12)
        EVT_CALL(PlaySoundAtCollider, 21, 487, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LocalVar(4), EVT_FIXED(-0.5))
        EVT_ADDF(LocalVar(0), LocalVar(3))
        EVT_ADDF(LocalVar(1), LocalVar(4))
        EVT_ADDF(LocalVar(2), LocalVar(5))
        EVT_IF_LT(LocalVar(2), -45)
            EVT_SET(LocalVar(5), 5)
        EVT_END_IF
        EVT_IF_GT(LocalVar(2), 0)
            EVT_SET(LocalVar(2), 0)
            EVT_SET(LocalVar(3), 5)
        EVT_END_IF
        EVT_IF_LT(LocalVar(1), -25)
            EVT_SET(LocalVar(4), 0)
            EVT_SET(LocalVar(1), -25)
        EVT_END_IF
        EVT_IF_GT(LocalVar(0), 90)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(TranslateModel, 19, 50, 28, 27)
        EVT_CALL(TranslateModel, 20, 50, 28, 27)
        EVT_CALL(TranslateModel, 19, 0, LocalVar(1), 1)
        EVT_CALL(TranslateModel, 20, 0, LocalVar(1), 1)
        EVT_CALL(RotateModel, 19, LocalVar(0), 1, 0, 0)
        EVT_CALL(RotateModel, 20, LocalVar(0), 1, 0, 0)
        EVT_CALL(RotateModel, 19, LocalVar(2), 0, 0, 1)
        EVT_CALL(RotateModel, 20, LocalVar(2), 0, 0, 1)
        EVT_CALL(TranslateModel, 19, -50, -28, -27)
        EVT_CALL(TranslateModel, 20, -50, -28, -27)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242474) = {
    EVT_SETF(LocalVar(2), 0)
    EVT_SETF(LocalVar(1), 0)
    EVT_SETF(LocalVar(0), 0)
    EVT_SETF(LocalVar(5), EVT_FIXED(0.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, 23, 487, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LocalVar(5), EVT_FIXED(0.5))
        EVT_ADDF(LocalVar(2), LocalVar(5))
        EVT_IF_GE(LocalVar(2), 80)
            EVT_SETF(LocalVar(2), 80)
            EVT_MULF(LocalVar(5), EVT_FIXED(-0.5))
            EVT_IF_EQ(LocalVar(5), 0)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(TranslateModel, 21, -55, 5, 16)
        EVT_CALL(TranslateModel, 21, LocalVar(0), LocalVar(1), 0)
        EVT_CALL(RotateModel, 21, LocalVar(2), 0, 0, 1)
        EVT_CALL(TranslateModel, 21, 55, -5, -16)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242620) = {
    EVT_SETF(LocalVar(2), 0)
    EVT_SETF(LocalVar(1), 0)
    EVT_SETF(LocalVar(0), 0)
    EVT_SETF(LocalVar(5), EVT_FIXED(0.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, 22, 487, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LocalVar(5), EVT_FIXED(0.5))
        EVT_ADDF(LocalVar(2), LocalVar(5))
        EVT_IF_GE(LocalVar(2), 80)
            EVT_SETF(LocalVar(2), 80)
            EVT_MULF(LocalVar(5), EVT_FIXED(-0.5))
            EVT_IF_EQ(LocalVar(5), 0)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(TranslateModel, 24, 60, 0, 16)
        EVT_CALL(RotateModel, 24, LocalVar(2), 0, 0, -1)
        EVT_CALL(TranslateModel, 24, -60, 0, -16)
        EVT_CALL(TranslateModel, 22, 0, 0, 27)
        EVT_CALL(TranslateModel, 23, 0, 0, 27)
        EVT_CALL(RotateModel, 22, LocalVar(2), 1, 0, 0)
        EVT_CALL(RotateModel, 23, LocalVar(2), 1, 0, 0)
        EVT_CALL(TranslateModel, 22, 0, 0, -27)
        EVT_CALL(TranslateModel, 23, 0, 0, -27)
        EVT_CALL(TranslateModel, 25, 0, 0, -41)
        EVT_CALL(TranslateModel, 26, 0, 0, -41)
        EVT_CALL(RotateModel, 25, LocalVar(2), -1, 0, 0)
        EVT_CALL(RotateModel, 26, LocalVar(2), -1, 0, 0)
        EVT_CALL(TranslateModel, 25, 0, 0, 41)
        EVT_CALL(TranslateModel, 26, 0, 0, 41)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

#ifdef NON_EQUIVALENT
EvtScript N(80242910) = {
    EVT_SETF(LocalVar(0), 0)
    EVT_SETF(LocalVar(1), 0)
    EVT_SETF(LocalVar(2), 0)
    EVT_SETF(LocalVar(3), EVT_FIXED(-1.0))
    EVT_SETF(LocalVar(4), EVT_FIXED(0.0))
    EVT_SETF(LocalVar(5), EVT_FIXED(3.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, 18, 486, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LocalVar(4), EVT_FIXED(-0.5))
        EVT_ADDF(LocalVar(5), EVT_FIXED(0.09375))
        EVT_ADDF(LocalVar(0), LocalVar(3))
        EVT_ADDF(LocalVar(1), LocalVar(4))
        EVT_ADDF(LocalVar(2), LocalVar(5))
        EVT_IF_LT(LocalVar(1), -25)
            EVT_SETF(LocalVar(1), EVT_FIXED(-25.0))
            EVT_SETF(LocalVar(3), EVT_FIXED(0.0))
            EVT_SETF(LocalVar(4), EVT_FIXED(0.0))
            EVT_IF_GE(LocalVar(2), 80)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(TranslateModel, 29, 124, 17, 3)
    EVT_CALL(TranslateModel, 29, LocalVar(0), LocalVar(1), 0)
    EVT_CALL(RotateModel, 29, LocalVar(2), 0, 0, -1)
    EVT_CALL(TranslateModel, 29, -124, -17, -3)
    EVT_WAIT(1)
EVT_END_LOOP
EVT_LABEL(0)
EVT_RETURN
EVT_END
};
#else
EvtScript N(80242910) = {
    EVT_CMD(EVT_OP_SETF, LocalVar(0), 0),
    EVT_CMD(EVT_OP_SETF, LocalVar(1), 0),
    EVT_CMD(EVT_OP_SETF, LocalVar(2), 0),
    EVT_CMD(EVT_OP_SETF, LocalVar(3), EVT_FIXED(-1.0)),
    EVT_CMD(EVT_OP_SETF, LocalVar(4), EVT_FIXED(0.0)),
    EVT_CMD(EVT_OP_SETF, LocalVar(5), EVT_FIXED(3.0)),
    EVT_CMD(EVT_OP_THREAD),
        EVT_CMD(EVT_OP_WAIT_FRAMES, 15),
        EVT_CMD(EVT_OP_CALL, EVT_ADDR(PlaySoundAtCollider), 18, 486, 0),
    EVT_CMD(EVT_OP_END_THREAD),
    EVT_CMD(EVT_OP_LOOP, 300),
        EVT_CMD(EVT_OP_ADDF, LocalVar(4), EVT_FIXED(-0.5)),
        EVT_CMD(EVT_OP_ADDF, LocalVar(5), EVT_FIXED(0.09375)),
        EVT_CMD(EVT_OP_ADDF, LocalVar(0), LocalVar(3)),
        EVT_CMD(EVT_OP_ADDF, LocalVar(1), LocalVar(4)),
        EVT_CMD(EVT_OP_ADDF, LocalVar(2), LocalVar(5)),
        EVT_CMD(EVT_OP_IF_LT, LocalVar(1), -25),
            EVT_CMD(EVT_OP_SETF, LocalVar(1), EVT_FIXED(-25.0)),
            EVT_CMD(EVT_OP_SETF, LocalVar(3), EVT_FIXED(0.0)),
            EVT_CMD(EVT_OP_SETF, LocalVar(4), EVT_FIXED(0.0)),
            EVT_CMD(EVT_OP_IF_GE, LocalVar(2), 80),
                EVT_CMD(EVT_OP_GOTO, 0),
            EVT_CMD(EVT_OP_END_IF),
        EVT_CMD(EVT_OP_END_IF),
    EVT_CMD(EVT_OP_END_IF), // BUG: extraneous END_IF
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(TranslateModel), 29, 124, 17, 3),
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(TranslateModel), 29, LocalVar(0), LocalVar(1), 0),
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(RotateModel), 29, LocalVar(2), 0, 0, -1),
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(TranslateModel), 29, -124, -17, -3),
    EVT_CMD(EVT_OP_WAIT_FRAMES, 1),
EVT_CMD(EVT_OP_END_LOOP),
EVT_CMD(EVT_OP_LABEL, 0),
EVT_CMD(EVT_OP_RETURN),
EVT_CMD(EVT_OP_END)
};
#endif

EvtScript N(80242B18) = {
    EVT_CALL(ModifyColliderFlags, 0, 18, 0x7FFFFE00)
    EVT_SETF(LocalVar(0), 0)
    EVT_SETF(LocalVar(1), 0)
    EVT_SETF(LocalVar(2), 0)
    EVT_SETF(LocalVar(3), EVT_FIXED(3.0))
    EVT_SETF(LocalVar(4), EVT_FIXED(1.0))
    EVT_SETF(LocalVar(5), EVT_FIXED(5.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, 20, 486, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LocalVar(4), EVT_FIXED(-0.5))
        EVT_ADDF(LocalVar(0), LocalVar(3))
        EVT_ADDF(LocalVar(1), LocalVar(4))
        EVT_ADDF(LocalVar(2), LocalVar(5))
        EVT_IF_LE(LocalVar(1), -40)
            EVT_SETF(LocalVar(1), -40)
            EVT_MULF(LocalVar(4), EVT_FIXED(-0.5))
            EVT_IF_LE(LocalVar(4), 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_GE(LocalVar(2), 60)
            EVT_SETF(LocalVar(2), 60)
            EVT_SETF(LocalVar(5), 0)
        EVT_END_IF
        EVT_CALL(TranslateModel, 41, -34, 50, 10)
        EVT_CALL(TranslateModel, 33, -34, 50, 10)
        EVT_CALL(TranslateModel, 41, 0, LocalVar(1), LocalVar(0))
        EVT_CALL(RotateModel, 41, LocalVar(2), 0, 0, 1)
        EVT_CALL(TranslateModel, 33, 0, LocalVar(1), LocalVar(0))
        EVT_CALL(RotateModel, 33, LocalVar(2), 0, 0, 1)
        EVT_CALL(TranslateModel, 41, 34, -50, -10)
        EVT_CALL(TranslateModel, 33, 34, -50, -10)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(1)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_80242DC8)[] = {
    0x00000000, 0x00000000, 0x0000001B, 0x00000050, 0x00000023, 0x0000001B, 0x0000003C, 0x0000000A,
    0x0000001B, 0x0000001E, 0x00000000, 0x0000001B, 0x00000050, 0x00000023, 0x0000001B, 0x0000001E,
    0x00000000, 0x0000001B, 0x00000055, 0x00000000, 0x0000001B, 0x00000050, 0x00000023, 0x0000001B,
};

EvtScript N(80242E28) = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_IF_LT(LocalVar(0), -210)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySound, 0x1E5)
    EVT_EXEC_WAIT(N(802413F0))
    EVT_SET(LocalVar(0), LocalVar(10))
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_SET(MapFlag(1), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(MapFlag(3), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MapFlag(3), 1)
    EVT_IF_GT(LocalVar(0), 2)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LocalVar(0), 2)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_LABEL(11)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
            EVT_SET(GB_FLO18_MachineDamage_Left, 1)
            EVT_EXEC(N(80241ED4))
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
            EVT_SET(GB_FLO18_MachineDamage_Right, 1)
            EVT_EXEC(N(80242174))
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 1)
            EVT_SET(GB_FLO18_MachineDamage_Left, 2)
            EVT_EXEC(N(80242474))
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 2)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 1)
            EVT_SET(GB_FLO18_MachineDamage_Right, 2)
            EVT_EXEC(N(80242620))
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 2)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 2)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(UseSettingsFrom, 0, 40, 0, 0)
            EVT_CALL(SetPanTarget, 0, 40, 0, 0)
            EVT_CALL(SetCamSpeed, 0, EVT_FIXED(1.5))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_SET(GB_FLO18_MachineDamage_Right, 3)
            EVT_EXEC_WAIT(N(802413F0))
            EVT_EXEC_WAIT(N(802413F0))
            EVT_EXEC_WAIT(N(802413F0))
            EVT_WAIT(30)
            EVT_CALL(GetModelCenter, 27)
            EVT_CALL(PlayEffect, 0x1D, 0, LocalVar(0), 50, LocalVar(2), 100, 20, 0, 30, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x1D, 0, LocalVar(0), 30, LocalVar(2), 120, 20, 0, 30, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x1D, 0, LocalVar(0), 10, LocalVar(2), 100, 20, 0, 30, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_THREAD
                EVT_SET(LocalVar(3), 6)
                EVT_USE_BUF(EVT_ADDR(N(intTable_80242DC8)))
                EVT_LOOP(8)
                    EVT_BUF_READ3(LocalVar(0), LocalVar(1), LocalVar(2))
                    EVT_CALL(PlaySoundAt, 0x190, 0, LocalVar(0), LocalVar(1), LocalVar(2))
                    EVT_CALL(PlayEffect, 0x27, 0, LocalVar(0), LocalVar(1), LocalVar(2), 1, 6, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT(2)
                    EVT_ADD(LocalVar(1), 5)
                    EVT_CALL(PlaySoundAt, 0x190, 0, LocalVar(0), LocalVar(1), LocalVar(2))
                    EVT_CALL(PlayEffect, 0x27, 0, LocalVar(0), LocalVar(1), LocalVar(2), 2, 15, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT(LocalVar(3))
                    EVT_ADD(LocalVar(3), 1)
                EVT_END_LOOP
                EVT_SETF(LocalVar(4), EVT_FIXED(2.0))
                EVT_LOOP(2)
                    EVT_USE_BUF(EVT_ADDR(N(intTable_80242DC8)))
                    EVT_LOOP(8)
                        EVT_BUF_READ3(LocalVar(0), LocalVar(1), LocalVar(2))
                        EVT_CALL(PlaySoundAt, 0x190, 0, LocalVar(0), LocalVar(1), LocalVar(2))
                        EVT_CALL(PlayEffect, 0x27, 0, LocalVar(0), LocalVar(1), LocalVar(2), 1, 25, 0, 0, 0, 0, 0, 0, 0)
                        EVT_WAIT(LocalVar(3))
                        EVT_ADD(LocalVar(3), LocalVar(4))
                        EVT_ADDF(LocalVar(4), EVT_FIXED(0.5))
                    EVT_END_LOOP
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(PlaySoundAt, 0x1A0, 0, 70, 40, 10)
            EVT_CALL(PlayEffect, 0x24, 0, 70, 40, 10, EVT_FIXED(3.0), 30, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(ShakeCam, 0, 0, 20, EVT_FIXED(1.0))
            EVT_CALL(PlaySoundAt, 0x1A0, 0, 0, 30, 30)
            EVT_CALL(PlayEffect, 0x24, 0, 0, 30, 30, EVT_FIXED(4.0), 40, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(ShakeCam, 0, 0, 20, EVT_FIXED(2.0))
            EVT_EXEC_WAIT(N(80242910))
            EVT_CALL(PlaySoundAtCollider, 20, 1169, 0)
            EVT_CALL(FadeOutMusic, 0, 1000)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_WAIT(30)
            EVT_EXEC_WAIT(N(80242B18))
            EVT_SET(GB_StoryProgress, 53)
            EVT_CALL(GotoMap, EVT_ADDR("flo_15"), 1)
            EVT_WAIT(70)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(0)
    EVT_SET(MapFlag(3), 0)
    EVT_RETURN
    EVT_END
};

Vec4f N(triggerCoord_8024367C) = { 5.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_8024368C) = { -5.0f, 0.0f, -20.0f, 0.0f };

Vec4f N(triggerCoord_8024369C) = { 50.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_802436AC) = { 105.0f, 0.0f, -10.0, 0.0f };

EvtScript N(802436BC) = {
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(EnableModel, 49, 0)
        EVT_CALL(ModifyColliderFlags, 0, 19, 0x7FFFFE00)
        EVT_CALL(EnableModel, 31, 0)
        EVT_CALL(EnableModel, 32, 0)
        EVT_CALL(EnableModel, 19, 0)
        EVT_CALL(EnableModel, 20, 0)
        EVT_CALL(EnableModel, 21, 0)
        EVT_CALL(EnableModel, 22, 0)
        EVT_CALL(EnableModel, 23, 0)
        EVT_CALL(EnableModel, 24, 0)
        EVT_CALL(EnableModel, 25, 0)
        EVT_CALL(EnableModel, 26, 0)
        EVT_CALL(EnableModel, 29, 0)
        EVT_CALL(EnableModel, 41, 0)
        EVT_CALL(EnableModel, 33, 0)
        EVT_CALL(ModifyColliderFlags, 0, 18, 0x7FFFFE00)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(80240E90))
    EVT_CALL(EnableModel, 49, 0)
    EVT_IF_GE(GB_FLO18_MachineDamage_Left, 1)
        EVT_CALL(ModifyColliderFlags, 0, 19, 0x7FFFFE00)
        EVT_CALL(EnableModel, 31, 0)
        EVT_CALL(EnableModel, 32, 0)
    EVT_END_IF
    EVT_IF_GE(GB_FLO18_MachineDamage_Right, 1)
        EVT_CALL(EnableModel, 19, 0)
        EVT_CALL(EnableModel, 20, 0)
    EVT_END_IF
    EVT_IF_GE(GB_FLO18_MachineDamage_Left, 2)
        EVT_CALL(EnableModel, 21, 0)
    EVT_END_IF
    EVT_IF_GE(GB_FLO18_MachineDamage_Right, 2)
        EVT_CALL(EnableModel, 22, 0)
        EVT_CALL(EnableModel, 23, 0)
        EVT_CALL(EnableModel, 24, 0)
        EVT_CALL(EnableModel, 25, 0)
        EVT_CALL(EnableModel, 26, 0)
    EVT_END_IF
    EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
        EVT_CALL(EnableModel, 29, 0)
        EVT_CALL(EnableModel, 41, 0)
        EVT_CALL(EnableModel, 33, 0)
        EVT_CALL(ModifyColliderFlags, 0, 18, 0x7FFFFE00)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LocalVar(0), 0)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_WALL_HAMMER, 23, 1, 0)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_POINT_BOMB, EVT_ADDR(N(triggerCoord_8024367C)), 1, 0)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_POINT_BOMB, EVT_ADDR(N(triggerCoord_8024368C)), 1, 0)
    EVT_SET(LocalVar(0), 1)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_WALL_HAMMER, 22, 1, 0)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_POINT_BOMB, EVT_ADDR(N(triggerCoord_8024369C)), 1, 0)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_POINT_BOMB, EVT_ADDR(N(triggerCoord_802436AC)), 1, 0)
    EVT_SET(LocalVar(0), 3)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_WALL_HAMMER, 19, 1, 0)
    EVT_SET(LocalVar(0), 4)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_WALL_HAMMER, 18, 1, 0)
    EVT_SET(LocalVar(0), 0)
    EVT_LOOP(16)
        EVT_SET(LocalVar(1), LocalVar(0))
        EVT_ADD(LocalVar(1), 10000)
        EVT_ADD(LocalVar(0), 1)
        EVT_CALL(CloneModel, 49, LocalVar(1))
        EVT_CALL(EnableModel, LocalVar(1), 0)
    EVT_END_LOOP
    EVT_EXEC(N(80241284))
    EVT_CALL(EnableTexPanning, 36, 1)
    EVT_CALL(EnableTexPanning, 37, 1)
    EVT_CALL(EnableTexPanning, 38, 1)
    EVT_CALL(EnableTexPanning, 39, 1)
    EVT_CALL(EnableTexPanning, 40, 1)
    EVT_CALL(EnableTexPanning, 41, 1)
    EVT_THREAD
        EVT_SETF(LocalVar(14), EVT_FIXED(1.0))
        EVT_LABEL(0)
        EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
            EVT_MULF(LocalVar(14), EVT_FIXED(0.953125))
        EVT_END_IF
        EVT_ADDF(LocalVar(15), LocalVar(14))
        EVT_IF_EQ(LocalVar(15), 1080)
            EVT_SETF(LocalVar(15), 0)
        EVT_END_IF
        EVT_SET(LocalVar(0), LocalVar(15))
        EVT_DIV(LocalVar(0), 9)
        EVT_MOD(LocalVar(0), 4)
        EVT_MUL(LocalVar(0), 16384)
        EVT_SET(LocalVar(1), LocalVar(15))
        EVT_DIV(LocalVar(1), 4)
        EVT_MOD(LocalVar(1), 2)
        EVT_MUL(LocalVar(1), 16384)
        EVT_SET(LocalVar(2), LocalVar(15))
        EVT_DIV(LocalVar(2), 5)
        EVT_MOD(LocalVar(2), 2)
        EVT_MUL(LocalVar(2), 16384)
        EVT_SET(LocalVar(3), LocalVar(15))
        EVT_DIV(LocalVar(3), 6)
        EVT_MOD(LocalVar(3), 2)
        EVT_MUL(LocalVar(3), 16384)
        EVT_SET(LocalVar(4), LocalVar(15))
        EVT_DIV(LocalVar(4), 2)
        EVT_MOD(LocalVar(4), 2)
        EVT_MUL(LocalVar(4), 32768)
        EVT_SET(LocalVar(5), LocalVar(15))
        EVT_DIV(LocalVar(5), 8)
        EVT_MOD(LocalVar(5), 2)
        EVT_MUL(LocalVar(5), 16384)
        EVT_CALL(SetTexPanOffset, 12, 0, LocalVar(0), 0)
        EVT_CALL(SetTexPanOffset, 13, 0, LocalVar(1), 0)
        EVT_CALL(SetTexPanOffset, 14, 0, LocalVar(2), 0)
        EVT_CALL(SetTexPanOffset, 15, 0, LocalVar(3), 0)
        EVT_CALL(SetTexPanOffset, 11, 0, LocalVar(4), 0)
        EVT_CALL(SetTexPanOffset, 10, 0, LocalVar(5), 0)
        EVT_CALL(SetTexPanOffset, 9, 0, LocalVar(5), 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243F10) = {
    .height = 32,
    .radius = 24,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 20,
};

NpcSettings N(npcSettings_80243F3C) = {
    .height = 34,
    .radius = 24,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 26,
};

Vec3f N(vectorList_80243F68)[] = {
    { -55.0, 15.0, 35.0 }, { -155.0, 35.0, 35.0 },
    { -255.0, 75.0, 35.0 }, { -355.0, 155.0, 35.0 },
    { -455.0, 315.0, 35.0 },
};

Vec3f N(vectorList_80243FA4)[] = {
    { -20.0, 15.0, 30.0 }, { -120.0, 35.0, 30.0 },
    { -220.0, 75.0, 30.0 }, { -320.0, 155.0, 30.0 },
    { -420.0, 315.0, 30.0 },
};

Vec3f N(vectorList_80243FE0)[] = {
    { 65.0, 15.0, 30.0 }, { -35.0, 35.0, 30.0 },
    { -135.0, 75.0, 30.0 }, { -235.0, 155.0, 30.0 },
    { -335.0, 315.0, 30.0 },
};

Vec3f N(vectorList_8024401C)[] = {
    { 120.0, 15.0, 30.0 }, { 20.0, 35.0, 30.0 },
    { -80.0, 75.0, 30.0 }, { -180.0, 155.0, 30.0 },
    { -280.0, 315.0, 30.0 },
};

EvtScript N(80244058) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerPos, 30, 0, 50)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 65, 0, 50)
    EVT_WAIT(30)
    EVT_CALL(AdjustCam, 0, EVT_FIXED(8.0), 0, 300, EVT_FIXED(19.0), EVT_FIXED(-8.5))
    EVT_CALL(GetCurrentPartnerID, LocalVar(0))
    EVT_CALL(BringPartnerOut, 8)
    EVT_IF_NE(LocalVar(0), 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FIXED(0.0))
        EVT_CALL(GetPlayerPos, LocalVar(1), LocalVar(2), LocalVar(3))
        EVT_ADD(LocalVar(1), 20)
        EVT_ADD(LocalVar(2), 20)
        EVT_ADD(LocalVar(3), 20)
        EVT_CALL(NpcJump0, NPC_PARTNER, LocalVar(1), LocalVar(2), LocalVar(3), 30)
    EVT_END_IF
    EVT_CALL(PlayerFaceNpc, -4, 0)
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00C9))
    EVT_CALL(SetPlayerAnimation, ANIM_NOD_YES)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_WAIT(20)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PutPartnerAway)
    EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80244270) = {
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, 4, 0x19E, 0)
        EVT_CALL(SetNpcFlagBits, 4, ((NPC_FLAG_100)), TRUE)
        EVT_CALL(InterpNpcYaw, 4, 270, 0)
        EVT_CALL(LoadPath, 60, EVT_ADDR(N(vectorList_80243F68)), 5, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 4, LocalVar(1), LocalVar(2), LocalVar(3))
            EVT_WAIT(1)
            EVT_IF_NE(LocalVar(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, 0, 0x19F, 0)
        EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_100)), TRUE)
        EVT_CALL(InterpNpcYaw, 0, 270, 0)
        EVT_CALL(LoadPath, 60, EVT_ADDR(N(vectorList_80243FA4)), 5, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 0, LocalVar(1), LocalVar(2), LocalVar(3))
            EVT_WAIT(1)
            EVT_IF_NE(LocalVar(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), TRUE)
        EVT_CALL(InterpNpcYaw, 1, 270, 0)
        EVT_CALL(LoadPath, 70, EVT_ADDR(N(vectorList_80243FE0)), 5, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 1, LocalVar(1), LocalVar(2), LocalVar(3))
            EVT_WAIT(1)
            EVT_IF_NE(LocalVar(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, 2, 0x19F, 0)
    EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(InterpNpcYaw, 2, 270, 0)
    EVT_CALL(LoadPath, 80, EVT_ADDR(N(vectorList_8024401C)), 5, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, 2, LocalVar(1), LocalVar(2), LocalVar(3))
        EVT_WAIT(1)
        EVT_IF_NE(LocalVar(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802445D4) = {
    EVT_WAIT(5)
    EVT_CALL(IsPlayerWithin, 40, 0, 200, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_SET(LocalVar(3), 45)
    EVT_ELSE
        EVT_SET(LocalVar(3), 25)
    EVT_END_IF
    EVT_SET(LocalVar(4), LocalVar(3))
    EVT_ADD(LocalVar(4), -5)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_IF_GT(LocalVar(2), -61)
        EVT_CHILD_THREAD
            EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(NpcMoveTo, 0, LocalVar(0), 55, LocalVar(3))
        EVT_END_CHILD_THREAD
        EVT_CHILD_THREAD
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(NpcMoveTo, 1, LocalVar(0), 55, LocalVar(3))
        EVT_END_CHILD_THREAD
        EVT_CHILD_THREAD
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(NpcMoveTo, 2, LocalVar(0), 55, LocalVar(3))
        EVT_END_CHILD_THREAD
        EVT_WAIT(LocalVar(4))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80244774) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetNpcPos, NPC_PARTNER, 65, LocalVar(1), 80)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 270)
    EVT_CALL(AdjustCam, 0, EVT_FIXED(8.0), 0, 450, EVT_FIXED(17.0), EVT_FIXED(-6.0))
    EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_flying_magikoopa_Palette_02_Anim_9, NPC_ANIM_flying_magikoopa_Palette_02_Anim_1, 0, MESSAGE_ID(0x11, 0x00BB))
    EVT_WAIT(20)
    EVT_EXEC(N(80244270))
    EVT_WAIT(80)
    EVT_CALL(AdjustCam, 0, EVT_FIXED(8.0), 0, 300, EVT_FIXED(19.0), EVT_FIXED(-8.5))
    EVT_CALL(GetCurrentPartnerID, LocalVar(0))
    EVT_CALL(BringPartnerOut, 8)
    EVT_IF_NE(LocalVar(0), 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FIXED(0.0))
        EVT_CALL(GetPlayerPos, LocalVar(1), LocalVar(2), LocalVar(3))
        EVT_ADD(LocalVar(1), 20)
        EVT_ADD(LocalVar(2), 20)
        EVT_ADD(LocalVar(3), 20)
        EVT_CALL(NpcJump0, NPC_PARTNER, LocalVar(1), LocalVar(2), LocalVar(3), 30)
    EVT_END_IF
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00C1))
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(20)
    EVT_CALL(PutPartnerAway)
    EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
    EVT_SET(GB_StoryProgress, 52)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(AwaitPlayerApproach, -250, 0, 50)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetCurrentPartnerID, LocalVar(0))
    EVT_CALL(BringPartnerOut, 8)
    EVT_IF_NE(LocalVar(0), 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FIXED(0.0))
        EVT_CALL(GetPlayerPos, LocalVar(1), LocalVar(2), LocalVar(3))
        EVT_ADD(LocalVar(1), 20)
        EVT_ADD(LocalVar(2), 20)
        EVT_ADD(LocalVar(3), 20)
        EVT_CALL(NpcJump0, NPC_PARTNER, LocalVar(1), LocalVar(2), LocalVar(3), 30)
    EVT_END_IF
    EVT_CALL(PlayerFaceNpc, -4, 0)
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00C2))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PutPartnerAway)
    EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80244B3C) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LocalVar(0))
        EVT_IF_NE(LocalVar(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(UseSettingsFrom, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetCamDistance, 0, 1000)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-6.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_80244C84) = {
    EVT_CALL(GetBattleOutcome, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(GetSelfNpcID, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 3)
                EVT_CALL(SetNpcPos, 3, 0, -1000, 0)
                EVT_CALL(SetNpcPos, 4, -55, 15, 35)
                EVT_CALL(GetNpcYaw, 3, LocalVar(0))
                EVT_CALL(SetNpcYaw, 4, 90)
                EVT_CALL(InterpPlayerYaw, 180, 0)
                EVT_CALL(SetPlayerPos, 30, 0, 80)
                EVT_CALL(SetNpcYaw, 0, 90)
                EVT_CALL(SetNpcPos, 0, -20, 15, 30)
                EVT_CALL(SetNpcYaw, 1, 270)
                EVT_CALL(SetNpcPos, 1, 65, 15, 30)
                EVT_CALL(SetNpcYaw, 2, 270)
                EVT_CALL(SetNpcPos, 2, 120, 15, 30)
                EVT_EXEC(N(80244774))
            EVT_END_IF
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80244E2C) = {
    EVT_SWITCH(MapVar(10))
        EVT_CASE_EQ(0)
            EVT_CALL(NpcFacePlayer, 3, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(NpcFacePlayer, 0, 1)
        EVT_CASE_EQ(2)
            EVT_CALL(NpcFacePlayer, 1, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(NpcFacePlayer, 2, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80244ED0) = {
    EVT_SWITCH(MapVar(10))
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 16, MESSAGE_ID(0x11, 0x00B9))
            EVT_CALL(InterpNpcYaw, 3, 90, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00BF))
            EVT_CALL(InterpNpcYaw, 0, 90, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00BF))
            EVT_CALL(InterpNpcYaw, 1, 270, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00BF))
            EVT_CALL(InterpNpcYaw, 2, 270, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80245004) = {
    EVT_SWITCH(MapVar(10))
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 16, MESSAGE_ID(0x11, 0x00BA))
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00C0))
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00C0))
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00C0))
    EVT_END_SWITCH
    EVT_CALL(SetNpcVar, 3, 0, 1)
    EVT_WAIT(5)
    EVT_EXEC(N(802445D4))
    EVT_RETURN
    EVT_END
};

EvtScript N(80245108) = {
    EVT_IF_GE(GB_StoryProgress, 52)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(AdjustCam, 0, EVT_FIXED(8.0), 0, 300, EVT_FIXED(17.0), EVT_FIXED(-6.0))
    EVT_EXEC_WAIT(N(80244E2C))
    EVT_SWITCH(AreaByte(7))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(80244ED0))
            EVT_ADD(AreaByte(7), 1)
            EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(80245004))
    EVT_END_SWITCH
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80245228) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 0)
        EVT_EXEC_WAIT(N(80245108))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8024527C) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 1)
        EVT_EXEC_WAIT(N(80245108))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802452D0) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 2)
        EVT_EXEC_WAIT(N(80245108))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80245324) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 3)
        EVT_EXEC_WAIT(N(80245108))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80245378) = {
    EVT_IF_GE(GB_StoryProgress, 52)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(8.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-6.0))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_EXEC_WAIT(N(80244E2C))
    EVT_IF_EQ(AreaByte(7), 0)
        EVT_EXEC_WAIT(N(80244ED0))
        EVT_ADD(AreaByte(7), 1)
        EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
    EVT_ELSE
        EVT_EXEC_WAIT(N(80245004))
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802454D4) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 0)
        EVT_CALL(GetNpcPos, 3, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_EXEC_WAIT(N(80245378))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80245544) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 1)
        EVT_CALL(GetNpcPos, 0, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_EXEC_WAIT(N(80245378))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802455B4) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 2)
        EVT_CALL(GetNpcPos, 1, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_EXEC_WAIT(N(80245378))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80245624) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 3)
        EVT_CALL(GetNpcPos, 2, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_EXEC_WAIT(N(80245378))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec4f N(triggerCoord_80245694) = { 5.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_802456A4) = { -5.0f, 0.0f, -20.0f, 0.0f };

Vec4f N(triggerCoord_802456B4) = { 50.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_802456C4) = { 105.0f, 0.0f, -10.0, 0.0f };

EvtScript N(802456D4) = {
    EVT_SET(MapVar(10), -1)
    EVT_BIND_TRIGGER(N(80245228), TRIGGER_WALL_HAMMER, 23, 1, 0)
    EVT_BIND_TRIGGER(N(80245228), TRIGGER_WALL_HAMMER, 19, 1, 0)
    EVT_BIND_TRIGGER(N(802454D4), TRIGGER_POINT_BOMB, EVT_ADDR(N(triggerCoord_802456A4)), 1, 0)
    EVT_BIND_TRIGGER(N(80245544), TRIGGER_POINT_BOMB, EVT_ADDR(N(triggerCoord_80245694)), 1, 0)
    EVT_BIND_TRIGGER(N(802452D0), TRIGGER_WALL_HAMMER, 22, 1, 0)
    EVT_BIND_TRIGGER(N(802455B4), TRIGGER_POINT_BOMB, EVT_ADDR(N(triggerCoord_802456B4)), 1, 0)
    EVT_BIND_TRIGGER(N(80245324), TRIGGER_WALL_HAMMER, 18, 1, 0)
    EVT_BIND_TRIGGER(N(80245624), TRIGGER_POINT_BOMB, EVT_ADDR(N(triggerCoord_802456C4)), 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802457D4) = {
    EVT_SWITCH(AreaByte(6))
        EVT_CASE_EQ(0)
            EVT_CALL(GetSelfNpcID, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 3)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 5, MESSAGE_ID(0x11, 0x00B6))
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00BC))
            EVT_END_IF
            EVT_ADD(AreaByte(6), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(GetSelfNpcID, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 3)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 5, MESSAGE_ID(0x11, 0x00B7))
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00BD))
            EVT_END_IF
            EVT_ADD(AreaByte(6), 1)
        EVT_CASE_EQ(2)
            EVT_CALL(AdjustCam, 0, EVT_FIXED(8.0), 0, 300, EVT_FIXED(19.0), EVT_FIXED(-9.0))
            EVT_CALL(GetSelfNpcID, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 3)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 5, MESSAGE_ID(0x11, 0x00B8))
                EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                EVT_WAIT(15)
                EVT_CALL(EndSpeech, -1, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 0)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00BE))
                EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                EVT_WAIT(15)
                EVT_CALL(EndSpeech, -1, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 0)
            EVT_END_IF
            EVT_CALL(SetNpcVar, 3, 0, 1)
            EVT_WAIT(5)
            EVT_EXEC(N(802445D4))
            EVT_CALL(BindNpcInteract, 0, 0)
            EVT_CALL(BindNpcInteract, 1, 0)
            EVT_CALL(BindNpcInteract, 2, 0)
            EVT_CALL(BindNpcInteract, 3, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245AA8) = {
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_ADDR(N(idle_80244B3C)))
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_802457D4)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_ADDR(N(defeat_80244C84)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245B30) = {
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_ADDR(N(defeat_80244C84)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245B90) = {
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_802457D4)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_ADDR(N(defeat_80244C84)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245C04) = {
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_802457D4)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_ADDR(N(defeat_80244C84)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245C78) = {
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_802457D4)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_ADDR(N(defeat_80244C84)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80245CEC)[] = {
    {
        .id = NPC_LAKITU0,
        .settings = &N(npcSettings_80243F10),
        .pos = { 0.0f, 15.0f, 60.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000 | NPC_FLAG_400000,
        .init = &N(init_80245B90),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 25,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 2, 0 },
            { ITEM_MAPLE_SYRUP, 2, 0 },
            { ITEM_THUNDER_RAGE, 2, 0 },
            { ITEM_STOP_WATCH, 2, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(3),
            .maxCoinBonus = 2,
        },
	.animations = {
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_2,
            NPC_ANIM_lakitu_Palette_00_Anim_3,
            NPC_ANIM_lakitu_Palette_00_Anim_3,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_4,
            NPC_ANIM_lakitu_Palette_00_Anim_4,
            NPC_ANIM_lakitu_Palette_00_Anim_3,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E4),
    },
    {
        .id = NPC_LAKITU1,
        .settings = &N(npcSettings_80243F10),
        .pos = { 65.0f, 15.0f, 60.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000 | NPC_FLAG_400000,
        .init = &N(init_80245C04),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 25,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 2, 0 },
            { ITEM_MAPLE_SYRUP, 2, 0 },
            { ITEM_THUNDER_RAGE, 2, 0 },
            { ITEM_STOP_WATCH, 2, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(3),
            .maxCoinBonus = 2,
        },
	.animations = {
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_2,
            NPC_ANIM_lakitu_Palette_00_Anim_3,
            NPC_ANIM_lakitu_Palette_00_Anim_3,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_4,
            NPC_ANIM_lakitu_Palette_00_Anim_4,
            NPC_ANIM_lakitu_Palette_00_Anim_3,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E4),
    },
    {
        .id = NPC_LAKITU2,
        .settings = &N(npcSettings_80243F10),
        .pos = { 135.0f, 15.0f, 35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000 | NPC_FLAG_400000,
        .init = &N(init_80245C78),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 25,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 2, 0 },
            { ITEM_MAPLE_SYRUP, 2, 0 },
            { ITEM_THUNDER_RAGE, 2, 0 },
            { ITEM_STOP_WATCH, 2, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(3),
            .maxCoinBonus = 2,
        },
	.animations = {
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_2,
            NPC_ANIM_lakitu_Palette_00_Anim_3,
            NPC_ANIM_lakitu_Palette_00_Anim_3,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_4,
            NPC_ANIM_lakitu_Palette_00_Anim_4,
            NPC_ANIM_lakitu_Palette_00_Anim_3,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
            NPC_ANIM_lakitu_Palette_00_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E4),
    },
    {
        .id = NPC_MAGIKOOPA,
        .settings = &N(npcSettings_80243F3C),
        .pos = { -60.0f, 0.0f, 50.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000 | NPC_FLAG_400000,
        .init = &N(init_80245AA8),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 25,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 2, 0 },
            { ITEM_MAPLE_SYRUP, 2, 0 },
            { ITEM_THUNDER_RAGE, 2, 0 },
            { ITEM_STOP_WATCH, 2, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(3),
            .maxCoinBonus = 2,
        },
	.animations = {
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_4,
            NPC_ANIM_magikoopa_Palette_02_Anim_4,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E4),
    },
    {
        .id = NPC_FLYING_MAGIKOOPA,
        .settings = &N(npcSettings_80243F3C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000 | NPC_FLAG_400000,
        .init = &N(init_80245B30),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 25,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 2, 0 },
            { ITEM_MAPLE_SYRUP, 2, 0 },
            { ITEM_THUNDER_RAGE, 2, 0 },
            { ITEM_STOP_WATCH, 2, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(3),
            .maxCoinBonus = 2,
        },
	.animations = {
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_4,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_4,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E4),
    },
};

NpcGroupList N(npcGroupList_8024669C) = {
    NPC_GROUP(N(npcGroup_80245CEC), 0x180B, 0x06),
    {},
};

static s32 N(pad_66B4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

#include "world/common/atomic/TexturePan.inc.c"

// It seems like fx_sun was not properly defined for this file. Having a proper
// declaration makes it not match.

#ifdef AVOID_UB
void fx_sun_undeclared(s32, f32, f32, f32, f32, s32);
#else
void fx_sun_undeclared(s32, s32, s32, s32, s32, s32);
#endif

ApiStatus N(func_8024030C_CDC9AC)(Evt* script, s32 isInitialCall) {
    fx_sun_undeclared(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240340_CDC9E0)(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) script->varTable[15];

    effect->data.lightning->unk_30 = 69;
    effect->data.lightning->unk_34 = 255;
    effect->data.lightning->unk_38 = 217;
    effect->data.lightning->unk_40 = 176;
    effect->data.lightning->unk_44 = 254;
    effect->data.lightning->unk_48 = 124;
    return ApiStatus_DONE2;
}

#include "common/UnkFloatFunc.inc.c"
