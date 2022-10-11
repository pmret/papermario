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
    .tattle = { MSG_MapTattle_flo_16 },
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

EvtScript N(exitWalk_80242A40) = EVT_EXIT_WALK(60,  0, "flo_00",  4);

EvtScript N(exitWalk_80242A9C) = EVT_EXIT_WALK(60,  1, "flo_17",  0);

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
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_LABEL(0)
        EVT_ADD(LVar0, 140)
        EVT_IF_GT(LVar0, 65536)
            EVT_ADD(LVar0, -65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        EVT_ADD(LVar1, -200)
        EVT_IF_LT(LVar1, 0)
            EVT_ADD(LVar1, 65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_EXEC(N(802451C4))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 5, 0x7FFFFE00)
    EVT_SET(LVar0, EVT_PTR(N(80242AF8)))
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
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SET(LVarD, LVar3)
    EVT_SET(LVarE, LVar4)
    EVT_SUB(LVarC, LVar0)
    EVT_SUB(LVarD, LVar1)
    EVT_SETF(LVar0, LVarC)
    EVT_DIVF(LVar0, EVT_FLOAT(100.0))
    EVT_SETF(LVarF, EVT_FLOAT(100.0))
    EVT_DIVF(LVarF, LVar0)
    EVT_ADD(LVarF, 11)
    EVT_SET(LVar5, 200)
    EVT_DIV(LVar5, LVarF)
    EVT_ADD(LVar5, 1)
    EVT_LOOP(LVar5)
        EVT_CALL(RandInt, LVarC, LVar0)
        EVT_CALL(RandInt, LVarD, LVar1)
        EVT_CALL(RandInt, 199, LVar2)
        EVT_SET(LVar3, 210)
        EVT_SUB(LVar3, LVar2)
        EVT_ADD(LVar0, LVarA)
        EVT_ADD(LVar1, LVarB)
        EVT_ADD(LVar2, LVarE)
        EVT_CALL(PlayEffect, 0xD, LVar0, LVar2, LVar1, LVar3, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LVarF)
    EVT_LABEL(0)
    EVT_CALL(RandInt, LVarC, LVar0)
    EVT_CALL(RandInt, LVarD, LVar1)
    EVT_ADD(LVar0, LVarA)
    EVT_ADD(LVar1, LVarB)
    EVT_CALL(PlayEffect, 0xD, LVar0, LVarE, LVar1, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LVarF)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024314C) = {
    EVT_SET(LVar9, LVar6)
    EVT_SET(LVar8, LVar5)
    EVT_SET(LVar7, LVar4)
    EVT_SET(LVar6, LVar3)
    EVT_SET(LVar5, LVar2)
    EVT_SET(LVar4, LVar1)
    EVT_SET(LVar3, LVar0)
    EVT_CALL(EnableModel, LVar6, 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(N(UnkFunc43))
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(EnableModel, LVar6, 1)
    EVT_END_THREAD
    EVT_IF_NE(LVarA, 0)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_SET(LVar0, LVar3)
            EVT_SET(LVar1, LVar4)
            EVT_SET(LVar2, LVar5)
            EVT_ADD(LVar1, 10)
            EVT_ADD(LVar2, 8)
            EVT_CALL(PlayEffect, 0x11, 4, LVar0, LVar1, LVar2, 15, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_SUB(LVar1, 10)
            EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 14, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAt, 0xF8, 0, LVar3, LVar4, LVar5)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, 2)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, LVar8, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, LVar9, LVar0, 1, 0, 0)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, LVar7, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024346C) = {
    EVT_CALL(ModifyColliderFlags, 3, 20, 0x00000006)
    EVT_SET(LVar0, -740)
    EVT_SET(LVar1, -140)
    EVT_SET(LVar2, -260)
    EVT_SET(LVar3, -55)
    EVT_SET(LVar4, 100)
    EVT_EXEC(N(80242EA0))
    EVT_SET(LVar0, 250)
    EVT_SET(LVar1, -140)
    EVT_SET(LVar2, 725)
    EVT_SET(LVar3, -55)
    EVT_SET(LVar4, 180)
    EVT_EXEC(N(80242EA0))
    EVT_CALL(GetModelCenter, 65)
    EVT_SET(LVar3, 65)
    EVT_SET(LVar4, 66)
    EVT_SET(LVar5, 67)
    EVT_SET(LVar6, 68)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 71)
    EVT_SET(LVar3, 71)
    EVT_SET(LVar4, 72)
    EVT_SET(LVar5, 73)
    EVT_SET(LVar6, 74)
    EVT_SET(LVarA, 174)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 79)
    EVT_SET(LVar3, 79)
    EVT_SET(LVar4, 80)
    EVT_SET(LVar5, 81)
    EVT_SET(LVar6, 82)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 85)
    EVT_SET(LVar3, 85)
    EVT_SET(LVar4, 86)
    EVT_SET(LVar5, 87)
    EVT_SET(LVar6, 88)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(8024314C))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_36FC) = {
    0x00000000,
};

#define SUPER_BLOCK_MAPVAR MapVar(0)
#define SUPER_BLOCK_GAMEFLAG GF_FLO16_SuperBlock
#include "world/common/atomic/SuperBlock.data.inc.c"

EvtScript N(80243D48) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamTarget, 0, LVar0, LVar1, LVar2)
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
    EVT_CALL(GetPlayerPos, LVar7, LVar8, LVar9)
    EVT_EXEC_GET_TID(N(80243D48), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
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
        EVT_IF_EQ(LVar0, 0)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar0)
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
    EVT_MAKE_SUPER_BLOCK(350, 240, -100, 0)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 472, 100, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(80243DB0)))
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/SuperBlock.inc.c"

#include "world/common/todo/UnkFunc44.inc.c"
