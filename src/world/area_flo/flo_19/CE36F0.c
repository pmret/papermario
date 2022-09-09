#include "flo_19.h"
#include "message_ids.h"

EntryList N(entryList) = {
    {   0.0f,    0.0f, 100.0f,  90.0f },
    { 460.0f,    0.0f,   0.0f, 270.0f },
    {   0.0f, -500.0f,   0.0f,   0.0f },
    {   0.0f,    0.0f,   0.0f,   0.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_19_tattle },
};

// Extraneous END_CASE_MULTI
#ifdef NON_EQUIVALENT
EvtScript N(802409C0) = {
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
            EVT_CALL(SetMusicTrack, 0, SONG_CLOUDY_CLIMB, 0, 8)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(7)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(3)
            EVT_IF_NE(AreaFlag(44), 0)
            EVT_ELSE
                EVT_CALL(FadeOutMusic, 1, 3000)
                EVT_CALL(FadeInMusic, 0, 50, 0, 3000, 0, 127)
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
#else
EvtScript N(802409C0) = {
    EVT_CMD(EVT_OP_CALL, EVT_ADDR(GetEntryID), LocalVar(0)),
    EVT_CMD(EVT_OP_SWITCH, LocalVar(0)),
        EVT_CMD(EVT_OP_CASE_OR_EQ, 0),
        EVT_CMD(EVT_OP_CASE_OR_EQ, 1),
            EVT_CMD(EVT_OP_CALL, EVT_ADDR(SetMusicTrack), 0, SONG_CLOUDY_CLIMB, 0, 8),
        EVT_CMD(EVT_OP_END_CASE_GROUP),
        EVT_CMD(EVT_OP_CASE_OR_EQ, 2),
        EVT_CMD(EVT_OP_CASE_OR_EQ, 7),
        EVT_CMD(EVT_OP_END_CASE_GROUP),
        EVT_CMD(EVT_OP_CASE_EQ, 3),
            EVT_CMD(EVT_OP_IF_NE, AreaFlag(44), 0),
            EVT_CMD(EVT_OP_ELSE),
                EVT_CMD(EVT_OP_CALL, EVT_ADDR(FadeOutMusic), 1, 3000),
                EVT_CMD(EVT_OP_CALL, EVT_ADDR(FadeInMusic), 0, 50, 0, 3000, 0, 127),
            EVT_CMD(EVT_OP_END_IF),
        EVT_CMD(EVT_OP_END_CASE_GROUP),
    EVT_CMD(EVT_OP_END_SWITCH),
    EVT_CMD(EVT_OP_RETURN),
    EVT_CMD(EVT_OP_END)
};
#endif

static s32 N(pad_ABC) = {
    0x00000000,
};

EvtScript N(80240AC0) = {
    EVT_CALL(MakeItemEntity, ITEM_S_JUMP_CHG, -200, 160, -213, 17, GF_FLO19_Item_SJumpChg)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_AF4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(updateTexturePan_80240B00) = {
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

EvtScript N(exitWalk_80240B9C) = EXIT_WALK_SCRIPT(60,  1, "flo_21",  0);

EvtScript N(80240BF8) = {
    EVT_BIND_TRIGGER(N(exitWalk_80240B9C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 39)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_SET(GF_MAP_CloudyClimb, 1)
    EVT_EXEC_WAIT(N(80240AC0))
    EVT_CALL(ParentColliderToModel, 12, 86)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_EXEC(N(80242FD0))
    EVT_EXEC(N(80241780))
    EVT_CALL(ModifyColliderFlags, 3, 5, 0x00000007)
    EVT_CALL(EnableTexPanning, 17, 1)
    EVT_CALL(EnableTexPanning, 18, 1)
    EVT_THREAD
        EVT_SET(LocalVar(0), 1)
        EVT_SET(LocalVar(1), -120)
        EVT_SET(LocalVar(2), 0)
        EVT_SET(LocalVar(3), 0)
        EVT_SET(LocalVar(4), 0)
        EVT_SET(LocalVar(5), 1)
        EVT_SET(LocalVar(6), 0)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80240B00))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(0), 2)
        EVT_SET(LocalVar(1), -90)
        EVT_SET(LocalVar(2), 0)
        EVT_SET(LocalVar(3), 0)
        EVT_SET(LocalVar(4), 0)
        EVT_SET(LocalVar(5), 1)
        EVT_SET(LocalVar(6), 0)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80240B00))
    EVT_END_THREAD
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_IF_NE(LocalVar(0), 3)
        EVT_SET(AreaFlag(44), 0)
    EVT_END_IF
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_EXEC(N(80240BF8))
        EVT_CASE_EQ(1)
            EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
            EVT_SET(LocalVar(0), EVT_ADDR(N(80240BF8)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(2)
            EVT_EXEC(N(80242A2C))
            EVT_EXEC(N(80240BF8))
        EVT_CASE_EQ(3)
            EVT_EXEC(N(80241CC4))
            EVT_EXEC(N(80240BF8))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(802409C0))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_8024030C_CE39FC))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1044)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80241050) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_SET(LVarF, 0)
    EVT_LABEL(0)
    EVT_SETF(LocalVar(0), EVT_FLOAT(-215.4375))
    EVT_SETF(LocalVar(1), EVT_FLOAT(128.59375))
    EVT_SETF(LocalVar(2), EVT_FLOAT(-200.0))
    EVT_ADDF(LocalVar(1), MapVar(12))
    EVT_CALL(TranslateGroup, 28, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SETF(LocalVar(0), EVT_FLOAT(-79.86))
    EVT_CALL(N(func_80240340_CE3A30), LVarF, LocalVar(1), EVT_FLOAT(5.0), EVT_FLOAT(136.765625), 300, 0, 0)
    EVT_SETF(LocalVar(2), EVT_FLOAT(-200.0))
    EVT_ADDF(LocalVar(1), MapVar(13))
    EVT_CALL(TranslateGroup, 32, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SETF(LocalVar(0), EVT_FLOAT(-364.265625))
    EVT_CALL(N(func_80240340_CE3A30), LVarF, LocalVar(1), EVT_FLOAT(5.0), EVT_FLOAT(106.765625), 300, 0, 0)
    EVT_SETF(LocalVar(2), EVT_FLOAT(10.0))
    EVT_ADDF(LocalVar(1), MapVar(14))
    EVT_CALL(TranslateGroup, 36, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SETF(LocalVar(0), EVT_FLOAT(295.734375))
    EVT_CALL(N(func_80240340_CE3A30), LVarF, LocalVar(1), EVT_FLOAT(65.0), EVT_FLOAT(86.984375), 200, 0, 0)
    EVT_SETF(LocalVar(2), EVT_FLOAT(-80.0))
    EVT_ADDF(LocalVar(1), MapVar(15))
    EVT_CALL(TranslateGroup, 40, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(N(func_80240340_CE3A30), LVarF, LocalVar(2), EVT_FLOAT(0.96875), EVT_FLOAT(1.03125), 15, 0, 0)
    EVT_CALL(N(func_80240340_CE3A30), LVarF, LocalVar(3), EVT_FLOAT(1.03125), EVT_FLOAT(0.96875), 15, 0, 0)
    EVT_SETF(LocalVar(0), MapVar(12))
    EVT_SETF(LocalVar(1), MapVar(12))
    EVT_MULF(LocalVar(0), EVT_FLOAT(-0.02))
    EVT_MULF(LocalVar(1), EVT_FLOAT(0.04))
    EVT_ADDF(LocalVar(0), LocalVar(2))
    EVT_ADDF(LocalVar(1), LocalVar(3))
    EVT_CALL(ScaleGroup, 28, LocalVar(0), LocalVar(1), 1)
    EVT_SETF(LocalVar(0), MapVar(13))
    EVT_SETF(LocalVar(1), MapVar(13))
    EVT_MULF(LocalVar(0), EVT_FLOAT(-0.02))
    EVT_MULF(LocalVar(1), EVT_FLOAT(0.04))
    EVT_ADDF(LocalVar(0), LocalVar(2))
    EVT_ADDF(LocalVar(1), LocalVar(3))
    EVT_CALL(ScaleGroup, 32, LocalVar(0), LocalVar(1), 1)
    EVT_SETF(LocalVar(0), MapVar(14))
    EVT_SETF(LocalVar(1), MapVar(14))
    EVT_MULF(LocalVar(0), EVT_FLOAT(-0.02))
    EVT_MULF(LocalVar(1), EVT_FLOAT(0.04))
    EVT_ADDF(LocalVar(0), LocalVar(2))
    EVT_ADDF(LocalVar(1), LocalVar(3))
    EVT_CALL(ScaleGroup, 36, LocalVar(0), LocalVar(1), 1)
    EVT_SETF(LocalVar(0), MapVar(15))
    EVT_SETF(LocalVar(1), MapVar(15))
    EVT_MULF(LocalVar(0), EVT_FLOAT(-0.02))
    EVT_MULF(LocalVar(1), EVT_FLOAT(0.04))
    EVT_ADDF(LocalVar(0), LocalVar(2))
    EVT_ADDF(LocalVar(1), LocalVar(3))
    EVT_CALL(ScaleGroup, 40, LocalVar(0), LocalVar(1), 1)
    EVT_CALL(UpdateColliderTransform, 8)
    EVT_CALL(UpdateColliderTransform, 9)
    EVT_CALL(UpdateColliderTransform, 7)
    EVT_CALL(UpdateColliderTransform, 10)
    EVT_ADD(LVarF, 1)
    EVT_IF_GE(LVarF, 1200)
        EVT_SET(LVarF, 0)
    EVT_END_IF
    EVT_SETF(LocalVar(0), LVarA)
    EVT_SETF(LocalVar(1), LVarB)
    EVT_SETF(LocalVar(2), LVarC)
    EVT_SETF(LocalVar(3), LVarD)
    EVT_MULF(LocalVar(0), EVT_FLOAT(-0.046875))
    EVT_MULF(LocalVar(1), EVT_FLOAT(-0.09375))
    EVT_MULF(LocalVar(2), EVT_FLOAT(-0.09375))
    EVT_MULF(LocalVar(3), EVT_FLOAT(-0.09375))
    EVT_ADDF(MapVar(12), LocalVar(0))
    EVT_ADDF(MapVar(13), LocalVar(1))
    EVT_ADDF(MapVar(14), LocalVar(2))
    EVT_ADDF(MapVar(15), LocalVar(3))
    EVT_MULF(MapVar(12), EVT_FLOAT(0.84375))
    EVT_MULF(MapVar(13), EVT_FLOAT(0.84375))
    EVT_MULF(MapVar(14), EVT_FLOAT(0.84375))
    EVT_MULF(MapVar(15), EVT_FLOAT(0.84375))
    EVT_ADDF(LVarA, MapVar(12))
    EVT_ADDF(LVarB, MapVar(13))
    EVT_ADDF(LVarC, MapVar(14))
    EVT_ADDF(LVarD, MapVar(15))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241650) = {
    EVT_THREAD
        EVT_ADDF(MapVar(12), EVT_FLOAT(-1.5))
        EVT_WAIT(1)
        EVT_ADDF(MapVar(12), EVT_FLOAT(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(8024169C) = {
    EVT_THREAD
        EVT_ADDF(MapVar(13), EVT_FLOAT(-1.5))
        EVT_WAIT(1)
        EVT_ADDF(MapVar(13), EVT_FLOAT(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(802416E8) = {
    EVT_THREAD
        EVT_ADDF(MapVar(14), EVT_FLOAT(-1.5))
        EVT_WAIT(1)
        EVT_ADDF(MapVar(14), EVT_FLOAT(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(80241734) = {
    EVT_THREAD
        EVT_ADDF(MapVar(15), EVT_FLOAT(-1.5))
        EVT_WAIT(1)
        EVT_ADDF(MapVar(15), EVT_FLOAT(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(80241780) = {
    EVT_CALL(ParentColliderToModel, 8, 28)
    EVT_CALL(ParentColliderToModel, 9, 32)
    EVT_CALL(ParentColliderToModel, 7, 36)
    EVT_CALL(ParentColliderToModel, 10, 40)
    EVT_CALL(SetModelFlags, 28, 256, 1)
    EVT_CALL(SetModelFlags, 32, 256, 1)
    EVT_CALL(SetModelFlags, 36, 256, 1)
    EVT_CALL(SetModelFlags, 40, 256, 1)
    EVT_EXEC(N(80241050))
    EVT_BIND_TRIGGER(N(80241650), TRIGGER_FLOOR_TOUCH, 8, 1, 0)
    EVT_BIND_TRIGGER(N(8024169C), TRIGGER_FLOOR_TOUCH, 9, 1, 0)
    EVT_BIND_TRIGGER(N(802416E8), TRIGGER_FLOOR_TOUCH, 7, 1, 0)
    EVT_BIND_TRIGGER(N(80241734), TRIGGER_FLOOR_TOUCH, 10, 1, 0)
    EVT_THREAD
        EVT_SET(LVarF, 0)
        EVT_LABEL(0)
        EVT_CALL(N(func_80240340_CE3A30), LVarF, LocalVar(0), EVT_FLOAT(0.96875), EVT_FLOAT(1.03125), 15, 0, 0)
        EVT_CALL(N(func_80240340_CE3A30), LVarF, LocalVar(1), EVT_FLOAT(1.03125), EVT_FLOAT(0.96875), 15, 0, 0)
        EVT_CALL(ScaleModel, 70, LocalVar(1), LocalVar(0), 1)
        EVT_CALL(ScaleModel, 60, LocalVar(1), LocalVar(0), 1)
        EVT_CALL(ScaleModel, 64, LocalVar(0), LocalVar(1), 1)
        EVT_CALL(ScaleModel, 68, LocalVar(0), LocalVar(1), 1)
        EVT_CALL(ScaleModel, 66, LocalVar(0), LocalVar(1), 1)
        EVT_CALL(ScaleModel, 58, LocalVar(1), LocalVar(0), 1)
        EVT_CALL(ScaleModel, 62, LocalVar(0), LocalVar(1), 1)
        EVT_CALL(ScaleModel, 72, LocalVar(0), LocalVar(1), 1)
        EVT_ADD(LVarF, 1)
        EVT_IF_GE(LVarF, 30)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1A68)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(80241A70) = {
    EVT_SET(LocalVar(0), 0)
    EVT_LABEL(10)
    EVT_CALL(N(func_80240784_CE3E74))
    EVT_ADD(LocalVar(0), 25)
    EVT_WAIT(1)
    EVT_IF_LT(LocalVar(0), 255)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LocalVar(0), 255)
    EVT_CALL(N(func_80240784_CE3E74))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241B10) = {
    EVT_SET(LocalVar(0), 255)
    EVT_LABEL(10)
    EVT_CALL(N(func_80240784_CE3E74))
    EVT_SUB(LocalVar(0), 25)
    EVT_WAIT(1)
    EVT_IF_GT(LocalVar(0), 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LocalVar(0), 0)
    EVT_CALL(N(func_80240784_CE3E74))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241BB0) = {
    EVT_CALL(TranslateGroup, 79, 0, LocalVar(0), 0)
    EVT_CALL(TranslateGroup, 92, 0, LocalVar(0), 0)
    EVT_SETF(LocalVar(1), LocalVar(0))
    EVT_MULF(LocalVar(1), EVT_FLOAT(-12.0))
    EVT_CALL(RotateGroup, 79, LocalVar(1), 0, 1, 0)
    EVT_CALL(RotateGroup, 92, LocalVar(1), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241C58) = {
    EVT_CALL(TranslateGroup, 84, 0, LocalVar(0), 0)
    EVT_SETF(LocalVar(1), LocalVar(0))
    EVT_MULF(LocalVar(1), EVT_FLOAT(-12.0))
    EVT_CALL(RotateGroup, 84, LocalVar(1), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241CC4) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerActionState, 10)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(ModifyColliderFlags, 0, 13, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_CALL(SetCamType, 0, 1, 0)
    EVT_CALL(UseSettingsFrom, 0, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 0, 0, 0)
    EVT_CALL(SetCamDistance, 0, 350)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(11.0))
    EVT_CALL(SetCamPosA, 0, 0, 0)
    EVT_CALL(SetCamPosB, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(EnableGroup, 2, 0)
    EVT_CALL(EnableGroup, 13, 0)
    EVT_CALL(EnableGroup, 24, 0)
    EVT_CALL(EnableGroup, 41, 0)
    EVT_CALL(EnableGroup, 48, 0)
    EVT_CALL(EnableGroup, 57, 0)
    EVT_CALL(EnableGroup, 74, 0)
    EVT_SET(LocalVar(9), EVT_FLOAT(45.0))
    EVT_SET(LVarA, EVT_FLOAT(28.0))
    EVT_SET(LVarB, EVT_FLOAT(5.0))
    EVT_SET(LVarC, EVT_FLOAT(60.0))
    EVT_SET(LVarD, EVT_FLOAT(28.0))
    EVT_SET(LVarE, EVT_FLOAT(10.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x106)
        EVT_CALL(SetPlayerAnimation, ANIM_WALKING)
        EVT_SWITCH(AreaFlag(16))
            EVT_CASE_EQ(0)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CASE_EQ(1)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(TranslateModel, 86, EVT_FLOAT(1.3134765625), EVT_FLOAT(3.0), EVT_FLOAT(-0.56640625))
    EVT_CALL(UpdateColliderTransform, 12)
    EVT_THREAD
        EVT_SET(AreaFlag(45), 0)
        EVT_CALL(SetPlayerAnimation, ANIM_WALKING)
        EVT_WAIT(200)
        EVT_EXEC_WAIT(N(80241A70))
        EVT_SET(AreaFlag(45), 1)
        EVT_WAIT(10)
        EVT_CALL(EnableGroup, 2, 1)
        EVT_CALL(EnableGroup, 13, 1)
        EVT_CALL(EnableGroup, 24, 1)
        EVT_CALL(EnableGroup, 41, 1)
        EVT_CALL(EnableGroup, 48, 1)
        EVT_CALL(EnableGroup, 57, 1)
        EVT_CALL(EnableGroup, 74, 1)
        EVT_CALL(SetCamDistance, 0, 450)
        EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
        EVT_CALL(SetCamPosA, 0, 0, 0)
        EVT_CALL(SetCamPosB, 0, 0, 0)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
        EVT_EXEC_WAIT(N(80241B10))
        EVT_WAIT(20)
        EVT_SET(AreaFlag(45), 0)
    EVT_END_THREAD
    EVT_SET(LVarF, 0)
    EVT_LOOP(344)
        EVT_ADD(LVarF, 1)
        EVT_CALL(N(UnkFloatFunc), LVarF, LocalVar(0), -210, 0, 344, 0, 0)
        EVT_SETF(LocalVar(1), LocalVar(0))
        EVT_MULF(LocalVar(1), EVT_FLOAT(-3.0))
        EVT_CALL(TranslateModel, 86, EVT_FLOAT(1.3134765625), LocalVar(0), EVT_FLOAT(-0.56640625))
        EVT_CALL(RotateModel, 86, LocalVar(1), 0, 1, 0)
        EVT_CALL(UpdateColliderTransform, 12)
        EVT_SETF(LocalVar(2), LocalVar(0))
        EVT_MULF(LocalVar(2), EVT_FLOAT(-3.0))
        EVT_SETF(LocalVar(3), LocalVar(0))
        EVT_CALL(N(func_80240540_CE3C30))
        EVT_CALL(N(func_80240660_CE3D50))
        EVT_LABEL(11)
        EVT_WAIT(1)
        EVT_IF_EQ(AreaFlag(45), 1)
            EVT_GOTO(11)
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, 1, 13, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 1, 5, 0x7FFFFE00)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ClearPartnerMoveHistory, -4)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, 100, 0, 60, 20)
    EVT_CALL(SetPlayerActionState, 10)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(5)
    EVT_SET(AreaFlag(44), 0)
    EVT_CALL(StopSound, 412)
    EVT_EXEC_WAIT(N(802409C0))
    EVT_CALL(ResetCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802423F8) = {
    EVT_IF_EQ(AreaFlag(44), 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(func_802D2B6C)
        EVT_WAIT(15)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_SET(AreaFlag(44), 1)
        EVT_CALL(ModifyColliderFlags, 0, 13, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
        EVT_SET(LocalVar(9), EVT_FLOAT(45.0))
        EVT_SET(LVarA, EVT_FLOAT(28.0))
        EVT_SET(LVarB, EVT_FLOAT(5.0))
        EVT_SET(LVarC, EVT_FLOAT(60.0))
        EVT_SET(LVarD, EVT_FLOAT(28.0))
        EVT_SET(LVarE, EVT_FLOAT(10.0))
        EVT_CALL(PlayerMoveTo, LocalVar(9), LVarB, 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_PARTNER, LVarC, LVarD, LVarE, 5)
        EVT_CALL(PlaySound, 0x19D)
        EVT_CALL(SetMusicTrack, 0, SONG_MAGIC_BEANSTALK, 1, 8)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x106)
        EVT_CALL(SetPlayerAnimation, ANIM_WALKING)
        EVT_CALL(N(func_802404D0_CE3BC0), LocalVar(3), LocalVar(4))
        EVT_SWITCH(LocalVar(4))
            EVT_CASE_LT(90)
                EVT_SET(AreaFlag(16), 0)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CASE_GE(270)
                EVT_SET(AreaFlag(16), 1)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_SWITCH
        EVT_CALL(TranslateModel, 86, EVT_FLOAT(1.3134765625), EVT_FLOAT(3.0), EVT_FLOAT(-0.56640625))
        EVT_CALL(UpdateColliderTransform, 12)
        EVT_SET(MapVar(10), 0)
        EVT_THREAD
            EVT_SET(AreaFlag(45), 0)
            EVT_WAIT(120)
            EVT_SET(AreaFlag(45), 1)
            EVT_WAIT(20)
            EVT_EXEC_WAIT(N(80241A70))
            EVT_WAIT(10)
            EVT_CALL(EnableGroup, 2, 0)
            EVT_CALL(EnableGroup, 13, 0)
            EVT_CALL(EnableGroup, 24, 0)
            EVT_CALL(EnableGroup, 41, 0)
            EVT_CALL(EnableGroup, 48, 0)
            EVT_CALL(EnableGroup, 57, 0)
            EVT_CALL(EnableGroup, 74, 0)
            EVT_CALL(SetCamType, 0, 1, 0)
            EVT_CALL(UseSettingsFrom, 0, 0, 0, 0)
            EVT_CALL(SetPanTarget, 0, 0, 0, 0)
            EVT_CALL(SetCamDistance, 0, 350)
            EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(7.0))
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_SET(AreaFlag(45), 0)
            EVT_EXEC_WAIT(N(80241B10))
        EVT_END_THREAD
        EVT_THREAD
            EVT_SET(LVarF, 0)
            EVT_LOOP(344)
                EVT_ADD(LVarF, 1)
                EVT_CALL(N(UnkFloatFunc), LVarF, LocalVar(0), 0, -210, 344, 0, 0)
                EVT_SETF(LocalVar(1), LocalVar(0))
                EVT_MULF(LocalVar(1), EVT_FLOAT(-3.0))
                EVT_CALL(TranslateModel, 86, EVT_FLOAT(1.3134765625), LocalVar(0), EVT_FLOAT(-0.56640625))
                EVT_CALL(RotateModel, 86, LocalVar(1), 0, 1, 0)
                EVT_CALL(UpdateColliderTransform, 12)
                EVT_SETF(LocalVar(2), LocalVar(0))
                EVT_MULF(LocalVar(2), EVT_FLOAT(-3.0))
                EVT_SETF(LocalVar(3), LocalVar(0))
                EVT_CALL(N(func_80240540_CE3C30))
                EVT_CALL(N(func_80240660_CE3D50))
                EVT_IF_EQ(LVarF, 300)
                    EVT_SET(MapVar(10), 1)
                EVT_END_IF
                EVT_LABEL(11)
                EVT_WAIT(1)
                EVT_IF_EQ(AreaFlag(45), 1)
                    EVT_GOTO(11)
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_LABEL(10)
        EVT_IF_EQ(MapVar(10), 0)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GotoMap, EVT_ADDR("flo_00"), 8)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80242A2C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, 10)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE)
    EVT_CALL(EnableModel, 86, 0)
    EVT_CALL(EnableGroup, 2, 0)
    EVT_CALL(EnableGroup, 13, 0)
    EVT_CALL(EnableGroup, 24, 0)
    EVT_CALL(EnableGroup, 41, 0)
    EVT_CALL(EnableGroup, 48, 0)
    EVT_CALL(EnableGroup, 57, 0)
    EVT_CALL(EnableGroup, 74, 0)
    EVT_CALL(SetCamType, 0, 1, 0)
    EVT_CALL(UseSettingsFrom, 0, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 0, 0, 0)
    EVT_CALL(SetCamDistance, 0, 800)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(-20.0), EVT_FLOAT(8.5))
    EVT_CALL(SetCamPosA, 0, 0, 0)
    EVT_CALL(SetCamPosB, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_SET(LVarF, 100)
    EVT_SET(MapVar(11), LVarF)
    EVT_SET(AreaFlag(40), 0)
    EVT_LOOP(400)
        EVT_IF_EQ(AreaFlag(40), 0)
            EVT_IF_GT(MapVar(11), 400)
                EVT_CALL(EnableGroup, 85, 0)
                EVT_CALL(EnableGroup, 92, 0)
                EVT_CALL(EnableGroup, 2, 1)
                EVT_CALL(EnableGroup, 13, 1)
                EVT_CALL(EnableGroup, 24, 1)
                EVT_CALL(EnableGroup, 41, 1)
                EVT_CALL(EnableGroup, 48, 1)
                EVT_CALL(EnableGroup, 57, 1)
                EVT_CALL(EnableGroup, 74, 1)
                EVT_CALL(SetCamDistance, 0, 1000)
                EVT_CALL(SetCamPitch, 0, EVT_FLOAT(45.0), EVT_FLOAT(-3.0))
                EVT_CALL(SetCamPosA, 0, 0, 0)
                EVT_CALL(SetCamPosB, 0, 0, 0)
                EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
                EVT_CALL(PanToTarget, 0, 0, 1)
                EVT_SET(LVarF, 150)
                EVT_THREAD
                    EVT_WAIT(5)
                    EVT_CALL(EnableGroup, 85, 1)
                    EVT_CALL(EnableGroup, 92, 1)
                    EVT_CALL(EnableModel, 86, 0)
                    EVT_WAIT(48)
                    EVT_CALL(PlayEffect, 0xA, 0, 22, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT(10)
                    EVT_CALL(PlayEffect, 0xA, 0, 22, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_END_THREAD
                EVT_SET(AreaFlag(40), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(LVarF, 1)
        EVT_CALL(N(UnkFloatFunc), LVarF, LocalVar(0), -350, 0, 400, 0, 0)
        EVT_SETF(MapVar(11), LVarF)
        EVT_MULF(MapVar(11), EVT_FLOAT(1.6))
        EVT_SETF(LocalVar(2), LocalVar(0))
        EVT_MULF(LocalVar(2), EVT_FLOAT(1.0))
        EVT_SETF(LocalVar(0), LocalVar(2))
        EVT_EXEC(N(80241BB0))
        EVT_SETF(LocalVar(2), LocalVar(0))
        EVT_MULF(LocalVar(2), EVT_FLOAT(1.0))
        EVT_SETF(LocalVar(0), LocalVar(2))
        EVT_EXEC(N(80241C58))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(15)
    EVT_SET(GB_StoryProgress, 55)
    EVT_CALL(GotoMap, EVT_ADDR("flo_00"), 7)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242FD0) = {
    EVT_BIND_TRIGGER(N(802423F8), TRIGGER_FLOOR_TOUCH, 12, 1, 0)
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/TexturePan.inc.c"

// It seems like fx_sun was not properly defined for this file. Having a proper
// declaration makes it not match.
#ifdef AVOID_UB
void fx_sun(s32, f32, f32, f32, f32, s32);
#else
void fx_sun(s32, s32, s32, s32, s32, s32);
#endif

ApiStatus N(func_8024030C_CE39FC)(Evt* script, s32 isInitialCall) {
    fx_sun(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

// Identical to UnkFloatFunc except for the presence of the fabsf
ApiStatus N(func_80240340_CE3A30)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a1 = *args++;
    s32 var0 = evt_get_variable(script, a1);
    s32 a2 = *args++;
    f32 var1 = evt_get_float_variable(script, *args++);
    f32 var2 = evt_get_float_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);
    f32 temp = (evt_get_float_variable(script, *args++) / 180.0f) * PI;
    f32 diff = fabsf(var2 - var1) / 2;

    if (var4 != 0 && var3 < var0) {
        var0 = var3;
        evt_set_variable(script, a1, var3);
    }

    evt_set_float_variable(script, a2, (var1 + diff) - (diff * cos_rad(((var0 * PI) / var3) + temp)));

    return ApiStatus_DONE2;
}

ApiStatus N(func_802404D0_CE3BC0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;
    s32 var2 = *args++;

    evt_set_variable(script, var1, gPlayerStatus.spriteFacingAngle);
    evt_set_variable(script, var2, gPlayerStatus.targetYaw);

    return ApiStatus_DONE2;
}

ApiStatus N(func_80240540_CE3C30)(Evt* script, s32 isInitialCall) {
    f32 temp_f20 = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(0.0f, 0.0f, script->varTable[9], script->varTable[11]);
    f32 temp_f22 = clamp_angle(atan2(0.0f, 0.0f, script->varTable[9], script->varTable[11]) - temp_f20);

    temp_f20 = sin_deg(temp_f22);
    gPlayerStatus.position.x = (dist * temp_f20) + 0.0f;
    gPlayerStatus.position.y = evt_get_variable(NULL, script->varTable[10]) + evt_get_variable(NULL, script->varTable[3]);
    temp_f20 = cos_deg(temp_f22);
    gPlayerStatus.position.z = 0.0f - (dist * temp_f20);

    return ApiStatus_DONE2;
}

ApiStatus N(func_80240660_CE3D50)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_by_index(0);
    f32 temp_f20 = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(0.0f, 0.0f, script->varTable[12], script->varTable[14]);
    f32 clamped = clamp_angle(atan2(0.0f, 0.0f, script->varTable[12], script->varTable[14]) - temp_f20);

    temp_f20 = sin_deg(clamped);
    npc->pos.x = (dist * temp_f20) + 0.0f;
    npc->pos.y = evt_get_variable(NULL, script->varTable[13]) + evt_get_variable(NULL, script->varTable[3]);
    temp_f20 = cos_deg(clamped);
    npc->pos.z = 0.0f - (dist * temp_f20);

    return ApiStatus_DONE2;
}

ApiStatus N(func_80240784_CE3E74)(Evt* script, s32 isInitialCall) {
    set_screen_overlay_params_back(1, script->varTable[0]);
    return ApiStatus_DONE2;
}

#include "common/UnkFloatFunc.inc.c"
