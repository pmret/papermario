#include "flo_18.h"
#include "message_ids.h"
#include "sprite/npc/FlyingMagikoopa.h"
#include "sprite/npc/Lakitu.h"
#include "sprite/npc/Magikoopa.h"
#include "sprite/npc/WorldLakilester.h"
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
    .tattle = { MSG_MapTattle_flo_18 },
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
    EVT_IF_EQ(LVar5, 1)
        EVT_IF_EQ(LVar6, 1)
            EVT_IF_EQ(LVar7, 1)
                EVT_IF_EQ(LVar8, 1)
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

EvtScript N(exitWalk_8024095C) = EVT_EXIT_WALK(60,  0, "flo_17",  1);

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
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_8024669C)))
    EVT_EXEC(N(80247024))
    EVT_EXEC(N(802436BC))
    EVT_EXEC(N(802456D4))
    EVT_CALL(ModifyColliderFlags, 3, 8, 0x00000002)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(lavaResetList_802409E4)))
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
        EVT_SET(LVar0, 1)
        EVT_SET(LVar1, -140)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_802408C0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 2)
        EVT_SET(LVar1, -200)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_802408C0))
    EVT_END_THREAD
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 1, 0x7FFFFE00)
        EVT_SET(LVar0, EVT_PTR(N(802409B8)))
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
        EVT_CALL(PlayEffect, 0x5E, 0, EVT_FLOAT(-16.0), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(80.9), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(0.5), 6, 0, 0, 0, 0)
        EVT_CALL(N(func_80240340_CDC9E0))
        EVT_WAIT(4)
        EVT_CALL(PlayEffect, 0x5E, 0, EVT_FLOAT(80.9), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(-16.0), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(0.5), 6, 0, 0, 0, 0)
        EVT_CALL(N(func_80240340_CDC9E0))
        EVT_WAIT(4)
        EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVar0, 6)
    EVT_LOOP(5)
        EVT_CALL(PlayEffect, 0x5E, 0, EVT_FLOAT(-16.0), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(80.9), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(0.5), 6, 0, 0, 0, 0)
        EVT_CALL(N(func_80240340_CDC9E0))
        EVT_WAIT(LVar0)
        EVT_ADD(LVar0, 2)
        EVT_CALL(PlayEffect, 0x5E, 0, EVT_FLOAT(80.9), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(-16.0), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(0.5), 6, 0, 0, 0, 0)
        EVT_CALL(N(func_80240340_CDC9E0))
        EVT_WAIT(LVar0)
        EVT_ADD(LVar0, 2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80241094) = {
    EVT_CALL(EnableModel, LVarF, 1)
    EVT_SET(LVarE, 159)
    EVT_LOOP(LVarE)
        EVT_ADDF(LVar3, 0)
        EVT_ADDF(LVar4, EVT_FLOAT(0.0))
        EVT_SETF(LVar5, EVT_FLOAT(0.01))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_MULF(LVar6, EVT_FLOAT(1.01))
        EVT_ADDF(LVar7, EVT_FLOAT(0.01))
        EVT_SETF(LVar8, LVar6)
        EVT_CALL(N(CosInterpMinMax), LVarE, LVarA, EVT_FLOAT(0.0), EVT_FLOAT(0.203125), 15, 0, 0)
        EVT_ADDF(LVar8, LVarA)
        EVT_SETF(LVar9, LVar7)
        EVT_CALL(N(CosInterpMinMax), LVarE, LVarA, EVT_FLOAT(0.0), EVT_FLOAT(0.203125), 20, 0, 90)
        EVT_ADDF(LVar9, LVarA)
        EVT_SETF(LVarA, LVar0)
        EVT_MULF(LVarA, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, LVarF, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, LVarF, LVar8, LVar9, 1)
        EVT_CALL(RotateModel, LVarF, LVarA, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVarF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241284) = {
    EVT_SET(LVarE, 0)
    EVT_LABEL(0)
    EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_SETF(LVar0, EVT_FLOAT(132.0))
    EVT_SETF(LVar1, EVT_FLOAT(90.0))
    EVT_SETF(LVar2, EVT_FLOAT(-30.0))
    EVT_CALL(RandInt, 100, LVar3)
    EVT_ADDF(LVar3, -50)
    EVT_DIVF(LVar3, EVT_FLOAT(200.0))
    EVT_SETF(LVar4, EVT_FLOAT(1.0))
    EVT_SETF(LVar5, 0)
    EVT_SETF(LVar6, EVT_FLOAT(0.296875))
    EVT_SETF(LVar7, EVT_FLOAT(0.296875))
    EVT_SET(LVarF, LVarE)
    EVT_ADD(LVarF, 10000)
    EVT_EXEC(N(80241094))
    EVT_ADD(LVarE, 1)
    EVT_IF_GE(LVarE, 16)
        EVT_SET(LVarE, 0)
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
    EVT_SET(LVarF, 0)
    EVT_LOOP(12)
        EVT_CALL(RandInt, 80, LVar0)
        EVT_SUB(LVar0, 40)
        EVT_CALL(RandInt, 50, LVar1)
        EVT_CALL(RandInt, 50, LVar2)
        EVT_SUB(LVar2, 25)
        EVT_CALL(PlayEffect, 0x0, LVar0, LVar1, LVar2, 5, 10, 1, 1, 0, 0, 0, 0, 0, 0)
        EVT_ADD(LVarF, 1)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVarE, EVT_FLOAT(1.0), EVT_FLOAT(1.09375), 2, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVarD, EVT_FLOAT(1.09375), EVT_FLOAT(1.0), 2, 0, 0)
        EVT_SETF(LVar0, LVarE)
        EVT_SETF(LVar1, LVarD)
        EVT_SETF(LVar2, LVarE)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
            EVT_CALL(ScaleModel, 31, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, 32, LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
            EVT_CALL(ScaleModel, 19, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, 20, LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 1)
            EVT_CALL(ScaleModel, 21, LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 1)
                EVT_CALL(ScaleModel, 22, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, 23, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, 24, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, 25, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, 26, LVar0, LVar1, LVar2)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ScaleModel, 27, LVar0, LVar1, LVar2)
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 2)
                EVT_CALL(ScaleModel, 29, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, 41, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, 33, LVar0, LVar1, LVar2)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ScaleModel, 36, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, 37, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, 38, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, 39, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, 40, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, 34, LVar0, LVar1, LVar2)
        EVT_SUBF(LVar0, EVT_FLOAT(1.046875))
        EVT_MULF(LVar0, EVT_FLOAT(100.0))
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
            EVT_CALL(RotateModel, 31, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, 32, LVar0, 0, 0, 1)
        EVT_END_IF
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
            EVT_CALL(RotateModel, 19, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, 20, LVar0, 0, 0, 1)
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 1)
            EVT_CALL(RotateModel, 21, LVar0, 0, 0, 1)
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 1)
                EVT_CALL(RotateModel, 22, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, 23, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, 24, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, 25, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, 26, LVar0, 0, 0, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(RotateModel, 27, LVar0, 0, 0, 1)
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 2)
                EVT_CALL(RotateModel, 29, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, 41, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, 33, LVar0, 0, 0, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(RotateModel, 36, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, 37, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, 38, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, 39, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, 40, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, 34, LVar0, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SETF(LVar0, 1)
    EVT_SETF(LVar1, 1)
    EVT_SETF(LVar2, 1)
    EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
        EVT_CALL(ScaleModel, 31, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, 32, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
        EVT_CALL(ScaleModel, 19, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, 20, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_IF_LE(GB_FLO18_MachineDamage_Left, 1)
        EVT_CALL(ScaleModel, 21, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
        EVT_IF_LE(GB_FLO18_MachineDamage_Right, 1)
            EVT_CALL(ScaleModel, 22, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, 23, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, 24, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, 25, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, 26, LVar0, LVar1, LVar2)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ScaleModel, 27, LVar0, LVar1, LVar2)
    EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
        EVT_IF_LE(GB_FLO18_MachineDamage_Right, 2)
            EVT_CALL(ScaleModel, 29, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, 41, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, 33, LVar0, LVar1, LVar2)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ScaleModel, 36, LVar0, LVar1, LVar2)
    EVT_CALL(ScaleModel, 37, LVar0, LVar1, LVar2)
    EVT_CALL(ScaleModel, 38, LVar0, LVar1, LVar2)
    EVT_CALL(ScaleModel, 39, LVar0, LVar1, LVar2)
    EVT_CALL(ScaleModel, 40, LVar0, LVar1, LVar2)
    EVT_CALL(ScaleModel, 34, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SET(MapFlag(2), 0)
    EVT_RETURN
    EVT_END
};

#ifdef NON_EQUIVALENT
EvtScript N(80241ED4) = {
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar3, EVT_FLOAT(-1.0))
    EVT_SETF(LVar4, EVT_FLOAT(0.0))
    EVT_SETF(LVar5, EVT_FLOAT(3.0))
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtCollider, 19, 486, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.5))
        EVT_ADDF(LVar5, EVT_FLOAT(0.09375))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_LT(LVar1, -10)
            EVT_SETF(LVar1, EVT_FLOAT(-10.0))
            EVT_SETF(LVar3, EVT_FLOAT(0.0))
            EVT_SETF(LVar4, EVT_FLOAT(0.0))
            EVT_IF_GE(LVar2, 80)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(TranslateModel, 31, -78, 19, 2)
    EVT_CALL(TranslateModel, 32, -78, 19, 2)
    EVT_CALL(TranslateModel, 31, LVar0, LVar1, 0)
    EVT_CALL(TranslateModel, 32, LVar0, LVar1, 0)
    EVT_CALL(RotateModel, 31, LVar2, 0, 0, 1)
    EVT_CALL(RotateModel, 32, LVar2, 0, 0, 1)
    EVT_CALL(TranslateModel, 31, 78, -19, -2)
    EVT_CALL(TranslateModel, 32, 78, -19, -2)
    EVT_WAIT(1)
EVT_END_LOOP
EVT_LABEL(0)
EVT_WAIT(30)
EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 19, 0x7FFFFE00)
EVT_RETURN
EVT_END
};
#else
EvtScript N(80241ED4) = {
    EVT_CMD(EVT_OP_SETF, LVar0, 0),
    EVT_CMD(EVT_OP_SETF, LVar1, 0),
    EVT_CMD(EVT_OP_SETF, LVar2, 0),
    EVT_CMD(EVT_OP_SETF, LVar3, EVT_FLOAT(-1.0)),
    EVT_CMD(EVT_OP_SETF, LVar4, EVT_FLOAT(0.0)),
    EVT_CMD(EVT_OP_SETF, LVar5, EVT_FLOAT(3.0)),
    EVT_CMD(EVT_OP_THREAD),
        EVT_CMD(EVT_OP_WAIT_FRAMES, 10),
        EVT_CMD(EVT_OP_CALL, EVT_PTR(PlaySoundAtCollider), 19, 486, 0),
    EVT_CMD(EVT_OP_END_THREAD),
    EVT_CMD(EVT_OP_LOOP, 300),
        EVT_CMD(EVT_OP_ADDF, LVar4, EVT_FLOAT(-0.5)),
        EVT_CMD(EVT_OP_ADDF, LVar5, EVT_FLOAT(0.09375)),
        EVT_CMD(EVT_OP_ADDF, LVar0, LVar3),
        EVT_CMD(EVT_OP_ADDF, LVar1, LVar4),
        EVT_CMD(EVT_OP_ADDF, LVar2, LVar5),
        EVT_CMD(EVT_OP_IF_LT, LVar1, -10),
            EVT_CMD(EVT_OP_SETF, LVar1, EVT_FLOAT(-10.0)),
            EVT_CMD(EVT_OP_SETF, LVar3, EVT_FLOAT(0.0)),
            EVT_CMD(EVT_OP_SETF, LVar4, EVT_FLOAT(0.0)),
            EVT_CMD(EVT_OP_IF_GE, LVar2, 80),
                EVT_CMD(EVT_OP_GOTO, 0),
            EVT_CMD(EVT_OP_END_IF),
        EVT_CMD(EVT_OP_END_IF),
    EVT_CMD(EVT_OP_END_IF), // BUG: extraneous END_IF
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateModel), 31, -78, 19, 2),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateModel), 32, -78, 19, 2),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateModel), 31, LVar0, LVar1, 0),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateModel), 32, LVar0, LVar1, 0),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(RotateModel), 31, LVar2, 0, 0, 1),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(RotateModel), 32, LVar2, 0, 0, 1),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateModel), 31, 78, -19, -2),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateModel), 32, 78, -19, -2),
    EVT_CMD(EVT_OP_WAIT_FRAMES, 1),
EVT_CMD(EVT_OP_END_LOOP),
EVT_CMD(EVT_OP_LABEL, 0),
EVT_CMD(EVT_OP_WAIT_FRAMES, 30),
EVT_CMD(EVT_OP_CALL, EVT_PTR(ModifyColliderFlags), 0, 19, 0x7FFFFE00),
EVT_CMD(EVT_OP_RETURN),
EVT_CMD(EVT_OP_END)
};
#endif

EvtScript N(80242174) = {
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar3, EVT_FLOAT(0.0))
    EVT_SETF(LVar4, EVT_FLOAT(0.0))
    EVT_SETF(LVar5, EVT_FLOAT(-5.0))
    EVT_THREAD
        EVT_WAIT(12)
        EVT_CALL(PlaySoundAtCollider, 21, 487, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.5))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_LT(LVar2, -45)
            EVT_SET(LVar5, 5)
        EVT_END_IF
        EVT_IF_GT(LVar2, 0)
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 5)
        EVT_END_IF
        EVT_IF_LT(LVar1, -25)
            EVT_SET(LVar4, 0)
            EVT_SET(LVar1, -25)
        EVT_END_IF
        EVT_IF_GT(LVar0, 90)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(TranslateModel, 19, 50, 28, 27)
        EVT_CALL(TranslateModel, 20, 50, 28, 27)
        EVT_CALL(TranslateModel, 19, 0, LVar1, 1)
        EVT_CALL(TranslateModel, 20, 0, LVar1, 1)
        EVT_CALL(RotateModel, 19, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, 20, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, 19, LVar2, 0, 0, 1)
        EVT_CALL(RotateModel, 20, LVar2, 0, 0, 1)
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
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar5, EVT_FLOAT(0.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, 23, 487, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar5, EVT_FLOAT(0.5))
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_GE(LVar2, 80)
            EVT_SETF(LVar2, 80)
            EVT_MULF(LVar5, EVT_FLOAT(-0.5))
            EVT_IF_EQ(LVar5, 0)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(TranslateModel, 21, -55, 5, 16)
        EVT_CALL(TranslateModel, 21, LVar0, LVar1, 0)
        EVT_CALL(RotateModel, 21, LVar2, 0, 0, 1)
        EVT_CALL(TranslateModel, 21, 55, -5, -16)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242620) = {
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar5, EVT_FLOAT(0.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, 22, 487, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar5, EVT_FLOAT(0.5))
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_GE(LVar2, 80)
            EVT_SETF(LVar2, 80)
            EVT_MULF(LVar5, EVT_FLOAT(-0.5))
            EVT_IF_EQ(LVar5, 0)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(TranslateModel, 24, 60, 0, 16)
        EVT_CALL(RotateModel, 24, LVar2, 0, 0, -1)
        EVT_CALL(TranslateModel, 24, -60, 0, -16)
        EVT_CALL(TranslateModel, 22, 0, 0, 27)
        EVT_CALL(TranslateModel, 23, 0, 0, 27)
        EVT_CALL(RotateModel, 22, LVar2, 1, 0, 0)
        EVT_CALL(RotateModel, 23, LVar2, 1, 0, 0)
        EVT_CALL(TranslateModel, 22, 0, 0, -27)
        EVT_CALL(TranslateModel, 23, 0, 0, -27)
        EVT_CALL(TranslateModel, 25, 0, 0, -41)
        EVT_CALL(TranslateModel, 26, 0, 0, -41)
        EVT_CALL(RotateModel, 25, LVar2, -1, 0, 0)
        EVT_CALL(RotateModel, 26, LVar2, -1, 0, 0)
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
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar3, EVT_FLOAT(-1.0))
    EVT_SETF(LVar4, EVT_FLOAT(0.0))
    EVT_SETF(LVar5, EVT_FLOAT(3.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, 18, 486, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.5))
        EVT_ADDF(LVar5, EVT_FLOAT(0.09375))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_LT(LVar1, -25)
            EVT_SETF(LVar1, EVT_FLOAT(-25.0))
            EVT_SETF(LVar3, EVT_FLOAT(0.0))
            EVT_SETF(LVar4, EVT_FLOAT(0.0))
            EVT_IF_GE(LVar2, 80)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(TranslateModel, 29, 124, 17, 3)
    EVT_CALL(TranslateModel, 29, LVar0, LVar1, 0)
    EVT_CALL(RotateModel, 29, LVar2, 0, 0, -1)
    EVT_CALL(TranslateModel, 29, -124, -17, -3)
    EVT_WAIT(1)
EVT_END_LOOP
EVT_LABEL(0)
EVT_RETURN
EVT_END
};
#else
EvtScript N(80242910) = {
    EVT_CMD(EVT_OP_SETF, LVar0, 0),
    EVT_CMD(EVT_OP_SETF, LVar1, 0),
    EVT_CMD(EVT_OP_SETF, LVar2, 0),
    EVT_CMD(EVT_OP_SETF, LVar3, EVT_FLOAT(-1.0)),
    EVT_CMD(EVT_OP_SETF, LVar4, EVT_FLOAT(0.0)),
    EVT_CMD(EVT_OP_SETF, LVar5, EVT_FLOAT(3.0)),
    EVT_CMD(EVT_OP_THREAD),
        EVT_CMD(EVT_OP_WAIT_FRAMES, 15),
        EVT_CMD(EVT_OP_CALL, EVT_PTR(PlaySoundAtCollider), 18, 486, 0),
    EVT_CMD(EVT_OP_END_THREAD),
    EVT_CMD(EVT_OP_LOOP, 300),
        EVT_CMD(EVT_OP_ADDF, LVar4, EVT_FLOAT(-0.5)),
        EVT_CMD(EVT_OP_ADDF, LVar5, EVT_FLOAT(0.09375)),
        EVT_CMD(EVT_OP_ADDF, LVar0, LVar3),
        EVT_CMD(EVT_OP_ADDF, LVar1, LVar4),
        EVT_CMD(EVT_OP_ADDF, LVar2, LVar5),
        EVT_CMD(EVT_OP_IF_LT, LVar1, -25),
            EVT_CMD(EVT_OP_SETF, LVar1, EVT_FLOAT(-25.0)),
            EVT_CMD(EVT_OP_SETF, LVar3, EVT_FLOAT(0.0)),
            EVT_CMD(EVT_OP_SETF, LVar4, EVT_FLOAT(0.0)),
            EVT_CMD(EVT_OP_IF_GE, LVar2, 80),
                EVT_CMD(EVT_OP_GOTO, 0),
            EVT_CMD(EVT_OP_END_IF),
        EVT_CMD(EVT_OP_END_IF),
    EVT_CMD(EVT_OP_END_IF), // BUG: extraneous END_IF
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateModel), 29, 124, 17, 3),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateModel), 29, LVar0, LVar1, 0),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(RotateModel), 29, LVar2, 0, 0, -1),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateModel), 29, -124, -17, -3),
    EVT_CMD(EVT_OP_WAIT_FRAMES, 1),
EVT_CMD(EVT_OP_END_LOOP),
EVT_CMD(EVT_OP_LABEL, 0),
EVT_CMD(EVT_OP_RETURN),
EVT_CMD(EVT_OP_END)
};
#endif

EvtScript N(80242B18) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 18, 0x7FFFFE00)
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar3, EVT_FLOAT(3.0))
    EVT_SETF(LVar4, EVT_FLOAT(1.0))
    EVT_SETF(LVar5, EVT_FLOAT(5.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, 20, 486, 0)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.5))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_LE(LVar1, -40)
            EVT_SETF(LVar1, -40)
            EVT_MULF(LVar4, EVT_FLOAT(-0.5))
            EVT_IF_LE(LVar4, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_GE(LVar2, 60)
            EVT_SETF(LVar2, 60)
            EVT_SETF(LVar5, 0)
        EVT_END_IF
        EVT_CALL(TranslateModel, 41, -34, 50, 10)
        EVT_CALL(TranslateModel, 33, -34, 50, 10)
        EVT_CALL(TranslateModel, 41, 0, LVar1, LVar0)
        EVT_CALL(RotateModel, 41, LVar2, 0, 0, 1)
        EVT_CALL(TranslateModel, 33, 0, LVar1, LVar0)
        EVT_CALL(RotateModel, 33, LVar2, 0, 0, 1)
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
    EVT_SET(LVarA, LVar0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, -210)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySound, 0x1E5)
    EVT_EXEC_WAIT(N(802413F0))
    EVT_SET(LVar0, LVarA)
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_SET(MapFlag(1), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(MapFlag(3), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MapFlag(3), 1)
    EVT_IF_GT(LVar0, 2)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 2)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
        EVT_LABEL(11)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
            EVT_SET(GB_FLO18_MachineDamage_Left, 1)
            EVT_EXEC(N(80241ED4))
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVar0, 1)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
            EVT_SET(GB_FLO18_MachineDamage_Right, 1)
            EVT_EXEC(N(80242174))
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
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
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.5))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_SET(GB_FLO18_MachineDamage_Right, 3)
            EVT_EXEC_WAIT(N(802413F0))
            EVT_EXEC_WAIT(N(802413F0))
            EVT_EXEC_WAIT(N(802413F0))
            EVT_WAIT(30)
            EVT_CALL(GetModelCenter, 27)
            EVT_CALL(PlayEffect, 0x1D, 0, LVar0, 50, LVar2, 100, 20, 0, 30, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x1D, 0, LVar0, 30, LVar2, 120, 20, 0, 30, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x1D, 0, LVar0, 10, LVar2, 100, 20, 0, 30, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_THREAD
                EVT_SET(LVar3, 6)
                EVT_USE_BUF(EVT_PTR(N(intTable_80242DC8)))
                EVT_LOOP(8)
                    EVT_BUF_READ3(LVar0, LVar1, LVar2)
                    EVT_CALL(PlaySoundAt, 0x190, 0, LVar0, LVar1, LVar2)
                    EVT_CALL(PlayEffect, 0x27, 0, LVar0, LVar1, LVar2, 1, 6, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT(2)
                    EVT_ADD(LVar1, 5)
                    EVT_CALL(PlaySoundAt, 0x190, 0, LVar0, LVar1, LVar2)
                    EVT_CALL(PlayEffect, 0x27, 0, LVar0, LVar1, LVar2, 2, 15, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT(LVar3)
                    EVT_ADD(LVar3, 1)
                EVT_END_LOOP
                EVT_SETF(LVar4, EVT_FLOAT(2.0))
                EVT_LOOP(2)
                    EVT_USE_BUF(EVT_PTR(N(intTable_80242DC8)))
                    EVT_LOOP(8)
                        EVT_BUF_READ3(LVar0, LVar1, LVar2)
                        EVT_CALL(PlaySoundAt, 0x190, 0, LVar0, LVar1, LVar2)
                        EVT_CALL(PlayEffect, 0x27, 0, LVar0, LVar1, LVar2, 1, 25, 0, 0, 0, 0, 0, 0, 0)
                        EVT_WAIT(LVar3)
                        EVT_ADD(LVar3, LVar4)
                        EVT_ADDF(LVar4, EVT_FLOAT(0.5))
                    EVT_END_LOOP
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(PlaySoundAt, 0x1A0, 0, 70, 40, 10)
            EVT_CALL(PlayEffect, 0x24, 0, 70, 40, 10, EVT_FLOAT(3.0), 30, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(ShakeCam, 0, 0, 20, EVT_FLOAT(1.0))
            EVT_CALL(PlaySoundAt, 0x1A0, 0, 0, 30, 30)
            EVT_CALL(PlayEffect, 0x24, 0, 0, 30, 30, EVT_FLOAT(4.0), 40, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(ShakeCam, 0, 0, 20, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(N(80242910))
            EVT_CALL(PlaySoundAtCollider, 20, 1169, 0)
            EVT_CALL(FadeOutMusic, 0, 1000)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_WAIT(30)
            EVT_EXEC_WAIT(N(80242B18))
            EVT_SET(GB_StoryProgress, 53)
            EVT_CALL(GotoMap, EVT_PTR("flo_15"), 1)
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
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 19, 0x7FFFFE00)
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
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 18, 0x7FFFFE00)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(80240E90))
    EVT_CALL(EnableModel, 49, 0)
    EVT_IF_GE(GB_FLO18_MachineDamage_Left, 1)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 19, 0x7FFFFE00)
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
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 18, 0x7FFFFE00)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, 0)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_WALL_HAMMER, 23, 1, 0)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_8024367C)), 1, 0)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_8024368C)), 1, 0)
    EVT_SET(LVar0, 1)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_WALL_HAMMER, 22, 1, 0)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_8024369C)), 1, 0)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_802436AC)), 1, 0)
    EVT_SET(LVar0, 3)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_WALL_HAMMER, 19, 1, 0)
    EVT_SET(LVar0, 4)
    EVT_BIND_TRIGGER(N(80242E28), TRIGGER_WALL_HAMMER, 18, 1, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(16)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, 10000)
        EVT_ADD(LVar0, 1)
        EVT_CALL(CloneModel, 49, LVar1)
        EVT_CALL(EnableModel, LVar1, 0)
    EVT_END_LOOP
    EVT_EXEC(N(80241284))
    EVT_CALL(EnableTexPanning, 36, 1)
    EVT_CALL(EnableTexPanning, 37, 1)
    EVT_CALL(EnableTexPanning, 38, 1)
    EVT_CALL(EnableTexPanning, 39, 1)
    EVT_CALL(EnableTexPanning, 40, 1)
    EVT_CALL(EnableTexPanning, 41, 1)
    EVT_THREAD
        EVT_SETF(LVarE, EVT_FLOAT(1.0))
        EVT_LABEL(0)
        EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
            EVT_MULF(LVarE, EVT_FLOAT(0.953125))
        EVT_END_IF
        EVT_ADDF(LVarF, LVarE)
        EVT_IF_EQ(LVarF, 1080)
            EVT_SETF(LVarF, 0)
        EVT_END_IF
        EVT_SET(LVar0, LVarF)
        EVT_DIV(LVar0, 9)
        EVT_MOD(LVar0, 4)
        EVT_MUL(LVar0, 16384)
        EVT_SET(LVar1, LVarF)
        EVT_DIV(LVar1, 4)
        EVT_MOD(LVar1, 2)
        EVT_MUL(LVar1, 16384)
        EVT_SET(LVar2, LVarF)
        EVT_DIV(LVar2, 5)
        EVT_MOD(LVar2, 2)
        EVT_MUL(LVar2, 16384)
        EVT_SET(LVar3, LVarF)
        EVT_DIV(LVar3, 6)
        EVT_MOD(LVar3, 2)
        EVT_MUL(LVar3, 16384)
        EVT_SET(LVar4, LVarF)
        EVT_DIV(LVar4, 2)
        EVT_MOD(LVar4, 2)
        EVT_MUL(LVar4, 32768)
        EVT_SET(LVar5, LVarF)
        EVT_DIV(LVar5, 8)
        EVT_MOD(LVar5, 2)
        EVT_MUL(LVar5, 16384)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar1, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar2, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_F, TEX_PANNER_MAIN, LVar3, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, LVar4, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_A, TEX_PANNER_MAIN, LVar5, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_9, TEX_PANNER_MAIN, LVar5, 0)
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
    EVT_CALL(AdjustCam, 0, EVT_FLOAT(8.0), 0, 300, EVT_FLOAT(19.0), EVT_FLOAT(-8.5))
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_CALL(BringPartnerOut, 8)
    EVT_IF_NE(LVar0, 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, 20)
        EVT_ADD(LVar3, 20)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 30)
    EVT_END_IF
    EVT_CALL(PlayerFaceNpc, -4, 0)
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5, MSG_CH6_00C9)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_NodYes)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_WAIT(20)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PutPartnerAway)
    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80244270) = {
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, 4, 0x19E, 0)
        EVT_CALL(SetNpcFlagBits, 4, ((NPC_FLAG_100)), TRUE)
        EVT_CALL(InterpNpcYaw, 4, 270, 0)
        EVT_CALL(LoadPath, 60, EVT_PTR(N(vectorList_80243F68)), 5, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 4, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_NE(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, 0, 0x19F, 0)
        EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_100)), TRUE)
        EVT_CALL(InterpNpcYaw, 0, 270, 0)
        EVT_CALL(LoadPath, 60, EVT_PTR(N(vectorList_80243FA4)), 5, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 0, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_NE(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), TRUE)
        EVT_CALL(InterpNpcYaw, 1, 270, 0)
        EVT_CALL(LoadPath, 70, EVT_PTR(N(vectorList_80243FE0)), 5, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 1, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_NE(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, 2, 0x19F, 0)
    EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(InterpNpcYaw, 2, 270, 0)
    EVT_CALL(LoadPath, 80, EVT_PTR(N(vectorList_8024401C)), 5, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, 2, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_NE(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802445D4) = {
    EVT_WAIT(5)
    EVT_CALL(IsPlayerWithin, 40, 0, 200, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_SET(LVar3, 45)
    EVT_ELSE
        EVT_SET(LVar3, 25)
    EVT_END_IF
    EVT_SET(LVar4, LVar3)
    EVT_ADD(LVar4, -5)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar2, -61)
        EVT_CHILD_THREAD
            EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(NpcMoveTo, 0, LVar0, 55, LVar3)
        EVT_END_CHILD_THREAD
        EVT_CHILD_THREAD
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(NpcMoveTo, 1, LVar0, 55, LVar3)
        EVT_END_CHILD_THREAD
        EVT_CHILD_THREAD
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(NpcMoveTo, 2, LVar0, 55, LVar3)
        EVT_END_CHILD_THREAD
        EVT_WAIT(LVar4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80244774) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 65, LVar1, 80)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 270)
    EVT_CALL(AdjustCam, 0, EVT_FLOAT(8.0), 0, 450, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
    EVT_CALL(SpeakToPlayer, 4, ANIM_FlyingMagikoopa_Yellow_Anim09, ANIM_FlyingMagikoopa_Yellow_Anim01, 0, MSG_CH6_00BB)
    EVT_WAIT(20)
    EVT_EXEC(N(80244270))
    EVT_WAIT(80)
    EVT_CALL(AdjustCam, 0, EVT_FLOAT(8.0), 0, 300, EVT_FLOAT(19.0), EVT_FLOAT(-8.5))
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_CALL(BringPartnerOut, 8)
    EVT_IF_NE(LVar0, 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, 20)
        EVT_ADD(LVar3, 20)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 30)
    EVT_END_IF
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5, MSG_CH6_00C1)
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(20)
    EVT_CALL(PutPartnerAway)
    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
    EVT_SET(GB_StoryProgress, 52)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(AwaitPlayerApproach, -250, 0, 50)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_CALL(BringPartnerOut, 8)
    EVT_IF_NE(LVar0, 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, 20)
        EVT_ADD(LVar3, 20)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 30)
    EVT_END_IF
    EVT_CALL(PlayerFaceNpc, -4, 0)
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5, MSG_CH6_00C2)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PutPartnerAway)
    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80244B3C) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 1000)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_80244C84) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_IF_EQ(LVar0, 3)
                EVT_CALL(SetNpcPos, 3, 0, -1000, 0)
                EVT_CALL(SetNpcPos, 4, -55, 15, 35)
                EVT_CALL(GetNpcYaw, 3, LVar0)
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
            EVT_CALL(SpeakToPlayer, 3, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 16, MSG_CH6_00B9)
            EVT_CALL(InterpNpcYaw, 3, 90, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, 0, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00BF)
            EVT_CALL(InterpNpcYaw, 0, 90, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, 1, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00BF)
            EVT_CALL(InterpNpcYaw, 1, 270, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, 2, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00BF)
            EVT_CALL(InterpNpcYaw, 2, 270, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80245004) = {
    EVT_SWITCH(MapVar(10))
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, 3, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 16, MSG_CH6_00BA)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, 0, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00C0)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, 1, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00C0)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, 2, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 16, MSG_CH6_00C0)
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
    EVT_CALL(AdjustCam, 0, EVT_FLOAT(8.0), 0, 300, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
    EVT_EXEC_WAIT(N(80244E2C))
    EVT_SWITCH(AreaByte(7))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(80244ED0))
            EVT_ADD(AreaByte(7), 1)
            EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
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
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(8.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(80244E2C))
    EVT_IF_EQ(AreaByte(7), 0)
        EVT_EXEC_WAIT(N(80244ED0))
        EVT_ADD(AreaByte(7), 1)
        EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
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
        EVT_CALL(GetNpcPos, 3, LVar0, LVar1, LVar2)
        EVT_EXEC_WAIT(N(80245378))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80245544) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 1)
        EVT_CALL(GetNpcPos, 0, LVar0, LVar1, LVar2)
        EVT_EXEC_WAIT(N(80245378))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802455B4) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 2)
        EVT_CALL(GetNpcPos, 1, LVar0, LVar1, LVar2)
        EVT_EXEC_WAIT(N(80245378))
        EVT_SET(MapVar(10), -1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80245624) = {
    EVT_IF_EQ(MapVar(10), -1)
        EVT_SET(MapVar(10), 3)
        EVT_CALL(GetNpcPos, 2, LVar0, LVar1, LVar2)
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
    EVT_BIND_TRIGGER(N(802454D4), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_802456A4)), 1, 0)
    EVT_BIND_TRIGGER(N(80245544), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80245694)), 1, 0)
    EVT_BIND_TRIGGER(N(802452D0), TRIGGER_WALL_HAMMER, 22, 1, 0)
    EVT_BIND_TRIGGER(N(802455B4), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_802456B4)), 1, 0)
    EVT_BIND_TRIGGER(N(80245324), TRIGGER_WALL_HAMMER, 18, 1, 0)
    EVT_BIND_TRIGGER(N(80245624), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_802456C4)), 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802457D4) = {
    EVT_SWITCH(AreaByte(6))
        EVT_CASE_EQ(0)
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_IF_EQ(LVar0, 3)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 5, MSG_CH6_00B6)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 5, MSG_CH6_00BC)
            EVT_END_IF
            EVT_ADD(AreaByte(6), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_IF_EQ(LVar0, 3)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 5, MSG_CH6_00B7)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 5, MSG_CH6_00BD)
            EVT_END_IF
            EVT_ADD(AreaByte(6), 1)
        EVT_CASE_EQ(2)
            EVT_CALL(AdjustCam, 0, EVT_FLOAT(8.0), 0, 300, EVT_FLOAT(19.0), EVT_FLOAT(-9.0))
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_IF_EQ(LVar0, 3)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 5, MSG_CH6_00B8)
                EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                EVT_WAIT(15)
                EVT_CALL(EndSpeech, -1, ANIM_Magikoopa_Yellow_Anim02, ANIM_Magikoopa_Yellow_Anim01, 0)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 5, MSG_CH6_00BE)
                EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                EVT_WAIT(15)
                EVT_CALL(EndSpeech, -1, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 0)
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
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80244B3C)))
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802457D4)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80244C84)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245B30) = {
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80244C84)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245B90) = {
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802457D4)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80244C84)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245C04) = {
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802457D4)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80244C84)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245C78) = {
    EVT_IF_LT(GB_StoryProgress, 52)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802457D4)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80244C84)))
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
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim02,
            ANIM_Lakitu_Anim03,
            ANIM_Lakitu_Anim03,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim04,
            ANIM_Lakitu_Anim04,
            ANIM_Lakitu_Anim03,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
        },
        .tattle = MSG_NpcTattle_PuffPuffOperator,
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
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim02,
            ANIM_Lakitu_Anim03,
            ANIM_Lakitu_Anim03,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim04,
            ANIM_Lakitu_Anim04,
            ANIM_Lakitu_Anim03,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
        },
        .tattle = MSG_NpcTattle_PuffPuffOperator,
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
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim02,
            ANIM_Lakitu_Anim03,
            ANIM_Lakitu_Anim03,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim04,
            ANIM_Lakitu_Anim04,
            ANIM_Lakitu_Anim03,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
            ANIM_Lakitu_Anim01,
        },
        .tattle = MSG_NpcTattle_PuffPuffOperator,
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
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim04,
            ANIM_Magikoopa_Yellow_Anim04,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
            ANIM_Magikoopa_Yellow_Anim01,
        },
        .tattle = MSG_NpcTattle_PuffPuffOperator,
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
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim04,
            ANIM_FlyingMagikoopa_Yellow_Anim04,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
            ANIM_FlyingMagikoopa_Yellow_Anim01,
        },
        .tattle = MSG_NpcTattle_PuffPuffOperator,
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

ApiStatus N(func_8024030C_CDC9AC)(Evt* script, s32 isInitialCall) {
    fx_sun_undeclared(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240340_CDC9E0)(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) script->varTable[15];

    effect->data.any[12] = 69;
    effect->data.any[13] = 255;
    effect->data.any[14] = 217;
    effect->data.any[16] = 176;
    effect->data.any[17] = 254;
    effect->data.any[18] = 124;
    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"
