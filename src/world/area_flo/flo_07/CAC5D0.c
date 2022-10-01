#include "flo_07.h"
#include "message_ids.h"
#include "sprite/npc/Posie.h"

enum {
    NPC_POSIE,
};

EntryList N(entryList) = {
    { 375.0f, 0.0f, 0.0f, 270.0f },
    { 325.0f, 0.0f, 0.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_07 },
};

EvtScript N(802407A0) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(53)
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(PlaySound, 0x80000021)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024086C) = {
    EVT_CALL(PushSong, 137, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240890) = {
    EVT_CALL(FadeOutMusic, 0, 250)
    EVT_WAIT(10)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_8CC) = {
    0x00000000,
};

EvtScript N(updateTexturePan_802408D0) = {
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

EvtScript N(8024096C) = {
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

EvtScript N(exitWalk_80240C18) = EVT_EXIT_WALK(60,  0, "flo_25",  1);

EvtScript N(80240C74) = {
    EVT_BIND_TRIGGER(N(exitWalk_80240C18), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
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
    EVT_SET(AreaFlag(6), 0)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80242B0C)))
    EVT_EXEC_WAIT(N(802428C4))
    EVT_CALL(ModifyColliderFlags, 3, 6, 0x00000006)
    EVT_SET(LVar0, 297)
    EVT_SET(LVar1, -95)
    EVT_SET(LVar2, 383)
    EVT_SET(LVar3, -65)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(8024096C))
    EVT_SET(LVar0, 293)
    EVT_SET(LVar1, 71)
    EVT_SET(LVar2, 378)
    EVT_SET(LVar3, 113)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(8024096C))
    EVT_SET(LVar0, 21)
    EVT_SET(LVar1, -346)
    EVT_SET(LVar2, 147)
    EVT_SET(LVar3, -242)
    EVT_SET(LVar4, 20)
    EVT_EXEC(N(8024096C))
    EVT_SET(LVar0, -350)
    EVT_SET(LVar1, -190)
    EVT_SET(LVar2, -81)
    EVT_SET(LVar3, -106)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(8024096C))
    EVT_SET(LVar0, -380)
    EVT_SET(LVar1, 85)
    EVT_SET(LVar2, -95)
    EVT_SET(LVar3, 150)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(8024096C))
    EVT_CALL(EnableTexPanning, 51, 1)
    EVT_CALL(EnableTexPanning, 49, 1)
    EVT_CALL(EnableTexPanning, 50, 1)
    EVT_THREAD
        EVT_SET(LVar0, 2)
        EVT_SET(LVar1, -100)
        EVT_SET(LVar2, 100)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_802408D0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 3)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, -1200)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_802408D0))
    EVT_END_THREAD
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC(N(80241C14))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
        EVT_SET(LVar0, EVT_PTR(N(80240C74)))
        EVT_EXEC(EnterWalk)
        EVT_EXEC(N(802424F4))
    EVT_END_IF
    EVT_EXEC_WAIT(N(802407A0))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_CALL(N(func_80240344_CAC534))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1214)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80241220) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

#include "common/foliage.inc.c"

s32** N(varStash) = NULL;

EvtScript N(80241BB4) = {
    EVT_CALL(ShowGotItem, LVar0, 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(80241BE4) = {
    EVT_CALL(ShowGotItem, LVar0, 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(80241C14) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetNpcPos, 0, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(11.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_00C5)
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_10"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241D6C) = {
    EVT_LABEL(0)
    EVT_CALL(ShakeCam, 0, 0, 1, EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241DBC) = {
    EVT_IF_EQ(AreaFlag(6), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0068)
    EVT_THREAD
        EVT_CALL(SetCamDistance, 0, 300)
        EVT_CALL(SetCamPitch, 0, EVT_FLOAT(18.0), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(0.5))
        EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlaySound, 0x8000006B)
    EVT_EXEC_GET_TID(N(80241D6C), MapVar(0))
    EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_Strain, ANIM_Posie_Strain, 0, MSG_CH6_0069)
    EVT_KILL_THREAD(MapVar(0))
    EVT_CALL(SetCamDistance, 0, 350)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(18.0), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(8.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, LVar2)
    EVT_IF_LT(LVar0, -250)
        EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -225, 100, -25, 13, GF_FLO07_Item_CrystalBerry)
    EVT_ELSE
        EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -265, 100, 54, 13, GF_FLO07_Item_CrystalBerry)
        EVT_SET(GF_FLO07_CrystalBerryFellOnLeftSide, 1)
    EVT_END_IF
    EVT_CALL(PlaySound, 0x7BC)
    EVT_CALL(func_802D62E4, 956)
    EVT_SET(AreaFlag(6), 1)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_006A)
    EVT_SET(GB_StoryProgress, 47)
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80242044) = {
    EVT_EXEC_WAIT(N(8024086C))
    EVT_CALL(NpcFacePlayer, NPC_SELF, 1)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(45)
            EVT_IF_EQ(AreaFlag(5), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0070)
                EVT_SET(AreaFlag(5), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0071)
            EVT_END_IF
        EVT_CASE_LT(46)
            EVT_CALL(AdjustCam, 0, EVT_FLOAT(4.0), 0, EVT_FLOAT(350.0), EVT_FLOAT(18.0), EVT_FLOAT(-7.5))
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0065)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Posie_GiveItem)
            EVT_WAIT(20)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Posie_Still)
            EVT_SET(LVar0, 89)
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(80241BB4))
            EVT_CALL(AddKeyItem, ITEM_FERTILE_SOIL)
            EVT_SET(GB_StoryProgress, 46)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0066)
            EVT_IF_EQ(GF_FLO12_RosieRequestedSomethingBeautiful, 1)
                EVT_EXEC_WAIT(N(80241DBC))
            EVT_END_IF
            EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
        EVT_CASE_LT(47)
            EVT_IF_EQ(GF_FLO12_RosieRequestedSomethingBeautiful, 1)
                EVT_IF_EQ(AreaFlag(6), 0)
                    EVT_CALL(AdjustCam, 0, EVT_FLOAT(4.0), 0, EVT_FLOAT(350.0), EVT_FLOAT(18.0), EVT_FLOAT(-7.5))
                    EVT_EXEC_WAIT(N(80241DBC))
                    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0072)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0072)
            EVT_END_IF
        EVT_CASE_LT(53)
            EVT_IF_EQ(GF_FLO07_Item_CrystalBerry, 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0072)
            EVT_ELSE
                EVT_IF_LT(GB_StoryProgress, 48)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0073)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0074)
                EVT_END_IF
                EVT_CALL(ContinueSpeech, -1, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0075)
            EVT_END_IF
        EVT_CASE_LT(60)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0076)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0077)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(80240890))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80242428) = {
    EVT_IF_EQ(GB_StoryProgress, 47)
        EVT_IF_EQ(GF_FLO07_Item_CrystalBerry, 0)
            EVT_IF_EQ(GF_FLO07_CrystalBerryFellOnLeftSide, 0)
                EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -225, 0, -25, 17, GF_FLO07_Item_CrystalBerry)
            EVT_ELSE
                EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -265, 0, 54, 17, GF_FLO07_Item_CrystalBerry)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SET(AreaFlag(5), 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80242044)))
    EVT_RETURN
    EVT_END
};

EvtScript N(802424F4) = {
    EVT_IF_NE(AreaByte(3), 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(10)
        EVT_IF_LT(AreaByte(3), 5)
            EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_006E)
            EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
            EVT_CALL(PlayerMoveTo, 410, LVar3, 10)
            EVT_ADD(AreaByte(3), 1)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_006F)
            EVT_SET(AreaByte(3), 0)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

extern const char N(flo_25_name_hack)[];

EvtScript N(tree1_Callback) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_LT(GB_StoryProgress, 47)
        EVT_CALL(NpcFacePlayer, 0, 1)
        EVT_WAIT(10)
        EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_Confused, ANIM_Posie_Idle, 0, MSG_CH6_0067)
        EVT_IF_EQ(GB_StoryProgress, 46)
            EVT_IF_EQ(GF_FLO12_RosieRequestedSomethingBeautiful, 1)
                EVT_CALL(UseSettingsFrom, 0, -250, 0, 0)
                EVT_CALL(SetPanTarget, 0, -250, 0, 0)
                EVT_CALL(SetCamDistance, 0, 350)
                EVT_CALL(PanToTarget, 0, 0, 1)
                EVT_EXEC_WAIT(N(80241DBC))
                EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_IF_EQ(GF_FLO07_Item_CrystalBerry, 0)
            EVT_CALL(NpcFacePlayer, 0, 1)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_Confused, ANIM_Posie_Idle, 0, MSG_CH6_0067)
        EVT_ELSE
            EVT_ADD(AreaByte(2), 1)
            EVT_SWITCH(AreaByte(2))
                EVT_CASE_LT(2)
                    EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_TalkAngry, ANIM_Posie_Idle, 0, MSG_CH6_006B)
                EVT_CASE_LT(5)
                    EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_TalkAngry, ANIM_Posie_Idle, 0, MSG_CH6_006C)
                EVT_CASE_GE(5)
                    EVT_CALL(SpeakToPlayer, 0, ANIM_Posie_TalkAngry, ANIM_Posie_Idle, 0, MSG_CH6_006D)
                    EVT_SET(AreaByte(3), 1)
                    EVT_CALL(GotoMap, EVT_PTR(N(flo_25_name_hack)), 1)
                    EVT_WAIT(100)
            EVT_END_SWITCH
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

FoliageModelList N(tree1_Leaves) = {
    .count = 3,
    .models = { 19, 20, 21 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 18 }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .callback = &N(tree1_Callback),
};

Vec4f N(triggerCoord_802428B4) = { -309.0f, 0.0f, 31.0f, 0.0f };

EvtScript N(802428C4) = {
    EVT_SET(LVar0, EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 4, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_802428B4)), 1, 0)
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_8024291C) = {
    .id = NPC_POSIE,
    .settings = &N(npcSettings_80241220),
    .pos = { -260.0f, 0.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80242428),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
        ANIM_Posie_Idle,
    },
    .tattle = MSG_NpcTattle_Posie,
};

NpcGroupList N(npcGroupList_80242B0C) = {
    NPC_GROUP(N(npcGroup_8024291C)),
    {},
};

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

const char N(flo_25_name_hack)[] = "flo_25";
