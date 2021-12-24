#include "flo_19.h"
#include "message_ids.h"

EntryList N(entryList) = {
    {   0.0f,    0.0f, 100.0f,  90.0f },
    { 460.0f,    0.0f,   0.0f, 270.0f },
    {   0.0f, -500.0f,   0.0f,   0.0f },
    {   0.0f,    0.0f,   0.0f,   0.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_19_tattle },
};

// Extraneous END_CASE_MULTI
#ifdef NON_EQUIVALENT
EvtSource N(802409C0) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
            EVT_CALL(SetMusicTrack, 0, SONG_CLOUDY_CLIMB, 0, 8)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(7)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(3)
            EVT_IF_NE(EVT_AREA_FLAG(44), 0)
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
EvtSource N(802409C0) = {
    EVT_CMD(EVT_OP_CALL, EVT_PTR(GetEntryID), EVT_VAR(0)),
    EVT_CMD(EVT_OP_SWITCH, EVT_VAR(0)),
        EVT_CMD(EVT_OP_CASE_OR_EQ, 0),
        EVT_CMD(EVT_OP_CASE_OR_EQ, 1),
            EVT_CMD(EVT_OP_CALL, EVT_PTR(SetMusicTrack), 0, SONG_CLOUDY_CLIMB, 0, 8),
        EVT_CMD(EVT_OP_END_CASE_GROUP),
        EVT_CMD(EVT_OP_CASE_OR_EQ, 2),
        EVT_CMD(EVT_OP_CASE_OR_EQ, 7),
        EVT_CMD(EVT_OP_END_CASE_GROUP),
        EVT_CMD(EVT_OP_CASE_EQ, 3),
            EVT_CMD(EVT_OP_IF_NE, EVT_AREA_FLAG(44), 0),
            EVT_CMD(EVT_OP_ELSE),
                EVT_CMD(EVT_OP_CALL, EVT_PTR(FadeOutMusic), 1, 3000),
                EVT_CMD(EVT_OP_CALL, EVT_PTR(FadeInMusic), 0, 50, 0, 3000, 0, 127),
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

EvtSource N(80240AC0) = {
    EVT_CALL(MakeItemEntity, ITEM_S_JUMP_CHG, -200, 160, -213, 17, EVT_SAVE_FLAG(1391))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_AF4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(updateTexturePan_80240B00) = {
    EVT_SET_GROUP(0)
    EVT_IF_EQ(EVT_VAR(5), 1)
        EVT_IF_EQ(EVT_VAR(6), 1)
            EVT_IF_EQ(EVT_VAR(7), 1)
                EVT_IF_EQ(EVT_VAR(8), 1)
                    EVT_CALL(N(UnkTexturePanFunc))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(UnkTexturePanFunc2))
    EVT_RETURN
    EVT_END
};

EvtSource N(exitWalk_80240B9C) = EXIT_WALK_SCRIPT(60,  1, "flo_21",  0);

EvtSource N(80240BF8) = {
    EVT_BIND_TRIGGER(N(exitWalk_80240B9C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 39)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_SET(EVT_SAVE_FLAG(1985), 1)
    EVT_EXEC_WAIT(N(80240AC0))
    EVT_CALL(ParentColliderToModel, 12, 86)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_EXEC(N(80242FD0))
    EVT_EXEC(N(80241780))
    EVT_CALL(ModifyColliderFlags, 3, 5, 0x00000007)
    EVT_CALL(EnableTexPanning, 17, 1)
    EVT_CALL(EnableTexPanning, 18, 1)
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 1)
        EVT_SET(EVT_VAR(1), -120)
        EVT_SET(EVT_VAR(2), 0)
        EVT_SET(EVT_VAR(3), 0)
        EVT_SET(EVT_VAR(4), 0)
        EVT_SET(EVT_VAR(5), 1)
        EVT_SET(EVT_VAR(6), 0)
        EVT_SET(EVT_VAR(7), 0)
        EVT_SET(EVT_VAR(8), 0)
        EVT_SET(EVT_VAR(9), 0)
        EVT_SET(EVT_VAR(10), 0)
        EVT_SET(EVT_VAR(11), 0)
        EVT_SET(EVT_VAR(12), 0)
        EVT_EXEC(N(updateTexturePan_80240B00))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 2)
        EVT_SET(EVT_VAR(1), -90)
        EVT_SET(EVT_VAR(2), 0)
        EVT_SET(EVT_VAR(3), 0)
        EVT_SET(EVT_VAR(4), 0)
        EVT_SET(EVT_VAR(5), 1)
        EVT_SET(EVT_VAR(6), 0)
        EVT_SET(EVT_VAR(7), 0)
        EVT_SET(EVT_VAR(8), 0)
        EVT_SET(EVT_VAR(9), 0)
        EVT_SET(EVT_VAR(10), 0)
        EVT_SET(EVT_VAR(11), 0)
        EVT_SET(EVT_VAR(12), 0)
        EVT_EXEC(N(updateTexturePan_80240B00))
    EVT_END_THREAD
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 3)
        EVT_SET(EVT_AREA_FLAG(44), 0)
    EVT_END_IF
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_EXEC(N(80240BF8))
        EVT_CASE_EQ(1)
            EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
            EVT_SET(EVT_VAR(0), EVT_PTR(N(80240BF8)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(2)
            EVT_EXEC(N(80242A2C))
            EVT_EXEC(N(80240BF8))
        EVT_CASE_EQ(3)
            EVT_EXEC(N(80241CC4))
            EVT_EXEC(N(80240BF8))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(802409C0))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_8024030C_CE39FC))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1044)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80241050) = {
    EVT_SET_GROUP(239)
    EVT_SET(EVT_VAR(15), 0)
    EVT_LABEL(0)
    EVT_SETF(EVT_VAR(0), EVT_FIXED(-215.4375))
    EVT_SETF(EVT_VAR(1), EVT_FIXED(128.59375))
    EVT_SETF(EVT_VAR(2), EVT_FIXED(-200.0))
    EVT_ADDF(EVT_VAR(1), EVT_MAP_VAR(12))
    EVT_CALL(TranslateGroup, 28, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SETF(EVT_VAR(0), EVT_FIXED(-79.86))
    EVT_CALL(N(func_80240340_CE3A30), EVT_VAR(15), EVT_VAR(1), EVT_FIXED(5.0), EVT_FIXED(136.765625), 300, 0, 0)
    EVT_SETF(EVT_VAR(2), EVT_FIXED(-200.0))
    EVT_ADDF(EVT_VAR(1), EVT_MAP_VAR(13))
    EVT_CALL(TranslateGroup, 32, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SETF(EVT_VAR(0), EVT_FIXED(-364.265625))
    EVT_CALL(N(func_80240340_CE3A30), EVT_VAR(15), EVT_VAR(1), EVT_FIXED(5.0), EVT_FIXED(106.765625), 300, 0, 0)
    EVT_SETF(EVT_VAR(2), EVT_FIXED(10.0))
    EVT_ADDF(EVT_VAR(1), EVT_MAP_VAR(14))
    EVT_CALL(TranslateGroup, 36, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SETF(EVT_VAR(0), EVT_FIXED(295.734375))
    EVT_CALL(N(func_80240340_CE3A30), EVT_VAR(15), EVT_VAR(1), EVT_FIXED(65.0), EVT_FIXED(86.984375), 200, 0, 0)
    EVT_SETF(EVT_VAR(2), EVT_FIXED(-80.0))
    EVT_ADDF(EVT_VAR(1), EVT_MAP_VAR(15))
    EVT_CALL(TranslateGroup, 40, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(N(func_80240340_CE3A30), EVT_VAR(15), EVT_VAR(2), EVT_FIXED(0.96875), EVT_FIXED(1.03125), 15, 0, 0)
    EVT_CALL(N(func_80240340_CE3A30), EVT_VAR(15), EVT_VAR(3), EVT_FIXED(1.03125), EVT_FIXED(0.96875), 15, 0, 0)
    EVT_SETF(EVT_VAR(0), EVT_MAP_VAR(12))
    EVT_SETF(EVT_VAR(1), EVT_MAP_VAR(12))
    EVT_MULF(EVT_VAR(0), EVT_FIXED(-0.02))
    EVT_MULF(EVT_VAR(1), EVT_FIXED(0.04))
    EVT_ADDF(EVT_VAR(0), EVT_VAR(2))
    EVT_ADDF(EVT_VAR(1), EVT_VAR(3))
    EVT_CALL(ScaleGroup, 28, EVT_VAR(0), EVT_VAR(1), 1)
    EVT_SETF(EVT_VAR(0), EVT_MAP_VAR(13))
    EVT_SETF(EVT_VAR(1), EVT_MAP_VAR(13))
    EVT_MULF(EVT_VAR(0), EVT_FIXED(-0.02))
    EVT_MULF(EVT_VAR(1), EVT_FIXED(0.04))
    EVT_ADDF(EVT_VAR(0), EVT_VAR(2))
    EVT_ADDF(EVT_VAR(1), EVT_VAR(3))
    EVT_CALL(ScaleGroup, 32, EVT_VAR(0), EVT_VAR(1), 1)
    EVT_SETF(EVT_VAR(0), EVT_MAP_VAR(14))
    EVT_SETF(EVT_VAR(1), EVT_MAP_VAR(14))
    EVT_MULF(EVT_VAR(0), EVT_FIXED(-0.02))
    EVT_MULF(EVT_VAR(1), EVT_FIXED(0.04))
    EVT_ADDF(EVT_VAR(0), EVT_VAR(2))
    EVT_ADDF(EVT_VAR(1), EVT_VAR(3))
    EVT_CALL(ScaleGroup, 36, EVT_VAR(0), EVT_VAR(1), 1)
    EVT_SETF(EVT_VAR(0), EVT_MAP_VAR(15))
    EVT_SETF(EVT_VAR(1), EVT_MAP_VAR(15))
    EVT_MULF(EVT_VAR(0), EVT_FIXED(-0.02))
    EVT_MULF(EVT_VAR(1), EVT_FIXED(0.04))
    EVT_ADDF(EVT_VAR(0), EVT_VAR(2))
    EVT_ADDF(EVT_VAR(1), EVT_VAR(3))
    EVT_CALL(ScaleGroup, 40, EVT_VAR(0), EVT_VAR(1), 1)
    EVT_CALL(UpdateColliderTransform, 8)
    EVT_CALL(UpdateColliderTransform, 9)
    EVT_CALL(UpdateColliderTransform, 7)
    EVT_CALL(UpdateColliderTransform, 10)
    EVT_ADD(EVT_VAR(15), 1)
    EVT_IF_GE(EVT_VAR(15), 1200)
        EVT_SET(EVT_VAR(15), 0)
    EVT_END_IF
    EVT_SETF(EVT_VAR(0), EVT_VAR(10))
    EVT_SETF(EVT_VAR(1), EVT_VAR(11))
    EVT_SETF(EVT_VAR(2), EVT_VAR(12))
    EVT_SETF(EVT_VAR(3), EVT_VAR(13))
    EVT_MULF(EVT_VAR(0), EVT_FIXED(-0.046875))
    EVT_MULF(EVT_VAR(1), EVT_FIXED(-0.09375))
    EVT_MULF(EVT_VAR(2), EVT_FIXED(-0.09375))
    EVT_MULF(EVT_VAR(3), EVT_FIXED(-0.09375))
    EVT_ADDF(EVT_MAP_VAR(12), EVT_VAR(0))
    EVT_ADDF(EVT_MAP_VAR(13), EVT_VAR(1))
    EVT_ADDF(EVT_MAP_VAR(14), EVT_VAR(2))
    EVT_ADDF(EVT_MAP_VAR(15), EVT_VAR(3))
    EVT_MULF(EVT_MAP_VAR(12), EVT_FIXED(0.84375))
    EVT_MULF(EVT_MAP_VAR(13), EVT_FIXED(0.84375))
    EVT_MULF(EVT_MAP_VAR(14), EVT_FIXED(0.84375))
    EVT_MULF(EVT_MAP_VAR(15), EVT_FIXED(0.84375))
    EVT_ADDF(EVT_VAR(10), EVT_MAP_VAR(12))
    EVT_ADDF(EVT_VAR(11), EVT_MAP_VAR(13))
    EVT_ADDF(EVT_VAR(12), EVT_MAP_VAR(14))
    EVT_ADDF(EVT_VAR(13), EVT_MAP_VAR(15))
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241650) = {
    EVT_THREAD
        EVT_ADDF(EVT_MAP_VAR(12), EVT_FIXED(-1.5))
        EVT_WAIT_FRAMES(1)
        EVT_ADDF(EVT_MAP_VAR(12), EVT_FIXED(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtSource N(8024169C) = {
    EVT_THREAD
        EVT_ADDF(EVT_MAP_VAR(13), EVT_FIXED(-1.5))
        EVT_WAIT_FRAMES(1)
        EVT_ADDF(EVT_MAP_VAR(13), EVT_FIXED(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtSource N(802416E8) = {
    EVT_THREAD
        EVT_ADDF(EVT_MAP_VAR(14), EVT_FIXED(-1.5))
        EVT_WAIT_FRAMES(1)
        EVT_ADDF(EVT_MAP_VAR(14), EVT_FIXED(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtSource N(80241734) = {
    EVT_THREAD
        EVT_ADDF(EVT_MAP_VAR(15), EVT_FIXED(-1.5))
        EVT_WAIT_FRAMES(1)
        EVT_ADDF(EVT_MAP_VAR(15), EVT_FIXED(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtSource N(80241780) = {
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
        EVT_SET(EVT_VAR(15), 0)
        EVT_LABEL(0)
        EVT_CALL(N(func_80240340_CE3A30), EVT_VAR(15), EVT_VAR(0), EVT_FIXED(0.96875), EVT_FIXED(1.03125), 15, 0, 0)
        EVT_CALL(N(func_80240340_CE3A30), EVT_VAR(15), EVT_VAR(1), EVT_FIXED(1.03125), EVT_FIXED(0.96875), 15, 0, 0)
        EVT_CALL(ScaleModel, 70, EVT_VAR(1), EVT_VAR(0), 1)
        EVT_CALL(ScaleModel, 60, EVT_VAR(1), EVT_VAR(0), 1)
        EVT_CALL(ScaleModel, 64, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(ScaleModel, 68, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(ScaleModel, 66, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(ScaleModel, 58, EVT_VAR(1), EVT_VAR(0), 1)
        EVT_CALL(ScaleModel, 62, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(ScaleModel, 72, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_ADD(EVT_VAR(15), 1)
        EVT_IF_GE(EVT_VAR(15), 30)
            EVT_SET(EVT_VAR(15), 0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1A68)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(80241A70) = {
    EVT_SET(EVT_VAR(0), 0)
    EVT_LABEL(10)
    EVT_CALL(N(func_80240784_CE3E74))
    EVT_ADD(EVT_VAR(0), 25)
    EVT_WAIT_FRAMES(1)
    EVT_IF_LT(EVT_VAR(0), 255)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(EVT_VAR(0), 255)
    EVT_CALL(N(func_80240784_CE3E74))
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241B10) = {
    EVT_SET(EVT_VAR(0), 255)
    EVT_LABEL(10)
    EVT_CALL(N(func_80240784_CE3E74))
    EVT_SUB(EVT_VAR(0), 25)
    EVT_WAIT_FRAMES(1)
    EVT_IF_GT(EVT_VAR(0), 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(EVT_VAR(0), 0)
    EVT_CALL(N(func_80240784_CE3E74))
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241BB0) = {
    EVT_CALL(TranslateGroup, 79, 0, EVT_VAR(0), 0)
    EVT_CALL(TranslateGroup, 92, 0, EVT_VAR(0), 0)
    EVT_SETF(EVT_VAR(1), EVT_VAR(0))
    EVT_MULF(EVT_VAR(1), EVT_FIXED(-12.0))
    EVT_CALL(RotateGroup, 79, EVT_VAR(1), 0, 1, 0)
    EVT_CALL(RotateGroup, 92, EVT_VAR(1), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241C58) = {
    EVT_CALL(TranslateGroup, 84, 0, EVT_VAR(0), 0)
    EVT_SETF(EVT_VAR(1), EVT_VAR(0))
    EVT_MULF(EVT_VAR(1), EVT_FIXED(-12.0))
    EVT_CALL(RotateGroup, 84, EVT_VAR(1), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241CC4) = {
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
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(11.0))
    EVT_CALL(SetCamPosA, 0, 0, 0)
    EVT_CALL(SetCamPosB, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(EnableGroup, 2, 0)
    EVT_CALL(EnableGroup, 13, 0)
    EVT_CALL(EnableGroup, 24, 0)
    EVT_CALL(EnableGroup, 41, 0)
    EVT_CALL(EnableGroup, 48, 0)
    EVT_CALL(EnableGroup, 57, 0)
    EVT_CALL(EnableGroup, 74, 0)
    EVT_SET(EVT_VAR(9), EVT_FIXED(45.0))
    EVT_SET(EVT_VAR(10), EVT_FIXED(28.0))
    EVT_SET(EVT_VAR(11), EVT_FIXED(5.0))
    EVT_SET(EVT_VAR(12), EVT_FIXED(60.0))
    EVT_SET(EVT_VAR(13), EVT_FIXED(28.0))
    EVT_SET(EVT_VAR(14), EVT_FIXED(10.0))
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x106)
        EVT_CALL(SetPlayerAnimation, ANIM_WALKING)
        EVT_SWITCH(EVT_AREA_FLAG(16))
            EVT_CASE_EQ(0)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CASE_EQ(1)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(TranslateModel, 86, EVT_FIXED(1.3134765625), EVT_FIXED(3.0), EVT_FIXED(-0.56640625))
    EVT_CALL(UpdateColliderTransform, 12)
    EVT_THREAD
        EVT_SET(EVT_AREA_FLAG(45), 0)
        EVT_CALL(SetPlayerAnimation, ANIM_WALKING)
        EVT_WAIT_FRAMES(200)
        EVT_EXEC_WAIT(N(80241A70))
        EVT_SET(EVT_AREA_FLAG(45), 1)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(EnableGroup, 2, 1)
        EVT_CALL(EnableGroup, 13, 1)
        EVT_CALL(EnableGroup, 24, 1)
        EVT_CALL(EnableGroup, 41, 1)
        EVT_CALL(EnableGroup, 48, 1)
        EVT_CALL(EnableGroup, 57, 1)
        EVT_CALL(EnableGroup, 74, 1)
        EVT_CALL(SetCamDistance, 0, 450)
        EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-6.0))
        EVT_CALL(SetCamPosA, 0, 0, 0)
        EVT_CALL(SetCamPosB, 0, 0, 0)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
        EVT_EXEC_WAIT(N(80241B10))
        EVT_WAIT_FRAMES(20)
        EVT_SET(EVT_AREA_FLAG(45), 0)
    EVT_END_THREAD
    EVT_SET(EVT_VAR(15), 0)
    EVT_LOOP(344)
        EVT_ADD(EVT_VAR(15), 1)
        EVT_CALL(N(UnkFloatFunc), EVT_VAR(15), EVT_VAR(0), -210, 0, 344, 0, 0)
        EVT_SETF(EVT_VAR(1), EVT_VAR(0))
        EVT_MULF(EVT_VAR(1), EVT_FIXED(-3.0))
        EVT_CALL(TranslateModel, 86, EVT_FIXED(1.3134765625), EVT_VAR(0), EVT_FIXED(-0.56640625))
        EVT_CALL(RotateModel, 86, EVT_VAR(1), 0, 1, 0)
        EVT_CALL(UpdateColliderTransform, 12)
        EVT_SETF(EVT_VAR(2), EVT_VAR(0))
        EVT_MULF(EVT_VAR(2), EVT_FIXED(-3.0))
        EVT_SETF(EVT_VAR(3), EVT_VAR(0))
        EVT_CALL(N(func_80240540_CE3C30))
        EVT_CALL(N(func_80240660_CE3D50))
        EVT_LABEL(11)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_AREA_FLAG(45), 1)
            EVT_GOTO(11)
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, 1, 13, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 1, 5, 0x7FFFFE00)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ClearPartnerMoveHistory, -4)
    EVT_CALL(SetPlayerJumpscale, EVT_FIXED(1.0))
    EVT_CALL(PlayerJump, 100, 0, 60, 20)
    EVT_CALL(SetPlayerActionState, 10)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT_FRAMES(5)
    EVT_SET(EVT_AREA_FLAG(44), 0)
    EVT_CALL(StopSound, 412)
    EVT_EXEC_WAIT(N(802409C0))
    EVT_CALL(ResetCam, 0, EVT_FIXED(1.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(802423F8) = {
    EVT_IF_EQ(EVT_AREA_FLAG(44), 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(func_802D2B6C)
        EVT_WAIT_FRAMES(15)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_SET(EVT_AREA_FLAG(44), 1)
        EVT_CALL(ModifyColliderFlags, 0, 13, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
        EVT_SET(EVT_VAR(9), EVT_FIXED(45.0))
        EVT_SET(EVT_VAR(10), EVT_FIXED(28.0))
        EVT_SET(EVT_VAR(11), EVT_FIXED(5.0))
        EVT_SET(EVT_VAR(12), EVT_FIXED(60.0))
        EVT_SET(EVT_VAR(13), EVT_FIXED(28.0))
        EVT_SET(EVT_VAR(14), EVT_FIXED(10.0))
        EVT_CALL(PlayerMoveTo, EVT_VAR(9), EVT_VAR(11), 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FIXED(0.0))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(12), EVT_VAR(13), EVT_VAR(14), 5)
        EVT_CALL(PlaySound, 0x19D)
        EVT_CALL(SetMusicTrack, 0, SONG_MAGIC_BEANSTALK, 1, 8)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x106)
        EVT_CALL(SetPlayerAnimation, ANIM_WALKING)
        EVT_CALL(N(func_802404D0_CE3BC0), EVT_VAR(3), EVT_VAR(4))
        EVT_SWITCH(EVT_VAR(4))
            EVT_CASE_LT(90)
                EVT_SET(EVT_AREA_FLAG(16), 0)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CASE_GE(270)
                EVT_SET(EVT_AREA_FLAG(16), 1)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_SWITCH
        EVT_CALL(TranslateModel, 86, EVT_FIXED(1.3134765625), EVT_FIXED(3.0), EVT_FIXED(-0.56640625))
        EVT_CALL(UpdateColliderTransform, 12)
        EVT_SET(EVT_MAP_VAR(10), 0)
        EVT_THREAD
            EVT_SET(EVT_AREA_FLAG(45), 0)
            EVT_WAIT_FRAMES(120)
            EVT_SET(EVT_AREA_FLAG(45), 1)
            EVT_WAIT_FRAMES(20)
            EVT_EXEC_WAIT(N(80241A70))
            EVT_WAIT_FRAMES(10)
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
            EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(7.0))
            EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_SET(EVT_AREA_FLAG(45), 0)
            EVT_EXEC_WAIT(N(80241B10))
        EVT_END_THREAD
        EVT_THREAD
            EVT_SET(EVT_VAR(15), 0)
            EVT_LOOP(344)
                EVT_ADD(EVT_VAR(15), 1)
                EVT_CALL(N(UnkFloatFunc), EVT_VAR(15), EVT_VAR(0), 0, -210, 344, 0, 0)
                EVT_SETF(EVT_VAR(1), EVT_VAR(0))
                EVT_MULF(EVT_VAR(1), EVT_FIXED(-3.0))
                EVT_CALL(TranslateModel, 86, EVT_FIXED(1.3134765625), EVT_VAR(0), EVT_FIXED(-0.56640625))
                EVT_CALL(RotateModel, 86, EVT_VAR(1), 0, 1, 0)
                EVT_CALL(UpdateColliderTransform, 12)
                EVT_SETF(EVT_VAR(2), EVT_VAR(0))
                EVT_MULF(EVT_VAR(2), EVT_FIXED(-3.0))
                EVT_SETF(EVT_VAR(3), EVT_VAR(0))
                EVT_CALL(N(func_80240540_CE3C30))
                EVT_CALL(N(func_80240660_CE3D50))
                EVT_IF_EQ(EVT_VAR(15), 300)
                    EVT_SET(EVT_MAP_VAR(10), 1)
                EVT_END_IF
                EVT_LABEL(11)
                EVT_WAIT_FRAMES(1)
                EVT_IF_EQ(EVT_AREA_FLAG(45), 1)
                    EVT_GOTO(11)
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_LABEL(10)
        EVT_IF_EQ(EVT_MAP_VAR(10), 0)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GotoMap, EVT_PTR("flo_00"), 8)
        EVT_WAIT_FRAMES(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(80242A2C) = {
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
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(-20.0), EVT_FIXED(8.5))
    EVT_CALL(SetCamPosA, 0, 0, 0)
    EVT_CALL(SetCamPosB, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_SET(EVT_VAR(15), 100)
    EVT_SET(EVT_MAP_VAR(11), EVT_VAR(15))
    EVT_SET(EVT_AREA_FLAG(40), 0)
    EVT_LOOP(400)
        EVT_IF_EQ(EVT_AREA_FLAG(40), 0)
            EVT_IF_GT(EVT_MAP_VAR(11), 400)
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
                EVT_CALL(SetCamPitch, 0, EVT_FIXED(45.0), EVT_FIXED(-3.0))
                EVT_CALL(SetCamPosA, 0, 0, 0)
                EVT_CALL(SetCamPosB, 0, 0, 0)
                EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
                EVT_CALL(PanToTarget, 0, 0, 1)
                EVT_SET(EVT_VAR(15), 150)
                EVT_THREAD
                    EVT_WAIT_FRAMES(5)
                    EVT_CALL(EnableGroup, 85, 1)
                    EVT_CALL(EnableGroup, 92, 1)
                    EVT_CALL(EnableModel, 86, 0)
                    EVT_WAIT_FRAMES(48)
                    EVT_CALL(PlayEffect, 0xA, 0, 22, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT_FRAMES(10)
                    EVT_CALL(PlayEffect, 0xA, 0, 22, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_END_THREAD
                EVT_SET(EVT_AREA_FLAG(40), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(EVT_VAR(15), 1)
        EVT_CALL(N(UnkFloatFunc), EVT_VAR(15), EVT_VAR(0), -350, 0, 400, 0, 0)
        EVT_SETF(EVT_MAP_VAR(11), EVT_VAR(15))
        EVT_MULF(EVT_MAP_VAR(11), EVT_FIXED(1.6))
        EVT_SETF(EVT_VAR(2), EVT_VAR(0))
        EVT_MULF(EVT_VAR(2), EVT_FIXED(1.0))
        EVT_SETF(EVT_VAR(0), EVT_VAR(2))
        EVT_EXEC(N(80241BB0))
        EVT_SETF(EVT_VAR(2), EVT_VAR(0))
        EVT_MULF(EVT_VAR(2), EVT_FIXED(1.0))
        EVT_SETF(EVT_VAR(0), EVT_VAR(2))
        EVT_EXEC(N(80241C58))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(15)
    EVT_SET(EVT_SAVE_VAR(0), 55)
    EVT_CALL(GotoMap, EVT_PTR("flo_00"), 7)
    EVT_RETURN
    EVT_END
};

EvtSource N(80242FD0) = {
    EVT_BIND_TRIGGER(N(802423F8), TRIGGER_FLOOR_TOUCH, 12, 1, 0)
    EVT_RETURN
    EVT_END
};

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

// It seems like playFX_82 was not properly defined for this file. Having a proper
// declaration makes it not match.
#ifdef AVOID_UB
void playFX_82(s32, f32, f32, f32, f32, s32);
#else
void playFX_82(s32, s32, s32, s32, s32, s32);
#endif

ApiStatus N(func_8024030C_CE39FC)(Evt* script, s32 isInitialCall) {
    playFX_82(1, 0, 0, 0, 0, 0);
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
