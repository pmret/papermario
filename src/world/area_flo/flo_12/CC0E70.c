#include "flo_12.h"
#include "message_ids.h"
#include "sprite/npc/rosie.h"

enum {
    NPC_ROSIE0,
    NPC_ROSIE1,
};

static s32 N(D_802429E0)[112];

EntryList N(entryList) = {
    { 280.0f, 0.0f, 0.0f, 270.0f },
    { 280.0f, 0.0f, 0.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_12_tattle },
};

EvtScript N(80240750) = {
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_CALL(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(53)
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8024080C) = {
    EVT_CALL(PushSong, 137, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240830) = {
    EVT_CALL(FadeOutMusic, 0, 250)
    EVT_WAIT(10)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_86C) = {
    0x00000000,
};

EvtScript N(80240870) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LVarA, LocalVar(0))
    EVT_SET(LVarB, LocalVar(1))
    EVT_SET(LVarC, LocalVar(2))
    EVT_SET(LVarD, LocalVar(3))
    EVT_SET(LVarE, LocalVar(4))
    EVT_SUB(LVarC, LocalVar(0))
    EVT_SUB(LVarD, LocalVar(1))
    EVT_SETF(LocalVar(0), LVarC)
    EVT_DIVF(LocalVar(0), EVT_FLOAT(100.0))
    EVT_SETF(LVarF, EVT_FLOAT(100.0))
    EVT_DIVF(LVarF, LocalVar(0))
    EVT_ADD(LVarF, 11)
    EVT_SET(LocalVar(5), 200)
    EVT_DIV(LocalVar(5), LVarF)
    EVT_ADD(LocalVar(5), 1)
    EVT_LOOP(LocalVar(5))
        EVT_CALL(RandInt, LVarC, LocalVar(0))
        EVT_CALL(RandInt, LVarD, LocalVar(1))
        EVT_CALL(RandInt, 199, LocalVar(2))
        EVT_SET(LocalVar(3), 210)
        EVT_SUB(LocalVar(3), LocalVar(2))
        EVT_ADD(LocalVar(0), LVarA)
        EVT_ADD(LocalVar(1), LVarB)
        EVT_ADD(LocalVar(2), LVarE)
        EVT_CALL(PlayEffect, 0xD, LocalVar(0), LocalVar(2), LocalVar(1), LocalVar(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LVarF)
    EVT_LABEL(0)
    EVT_CALL(RandInt, LVarC, LocalVar(0))
    EVT_CALL(RandInt, LVarD, LocalVar(1))
    EVT_ADD(LocalVar(0), LVarA)
    EVT_ADD(LocalVar(1), LVarB)
    EVT_CALL(PlayEffect, 0xD, LocalVar(0), LVarE, LocalVar(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LVarF)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_80240B1C) = EXIT_WALK_SCRIPT(60,  0, "flo_11",  1);

EvtScript N(80240B78) = {
    EVT_BIND_TRIGGER(N(exitWalk_80240B1C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
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
    EVT_SET(AreaFlag(22), 0)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802429B8)))
    EVT_CALL(ModifyColliderFlags, 3, 11, 0x00000006)
    EVT_SET(LocalVar(0), -65)
    EVT_SET(LocalVar(1), -210)
    EVT_SET(LocalVar(2), 90)
    EVT_SET(LocalVar(3), -110)
    EVT_SET(LocalVar(4), 0)
    EVT_EXEC(N(80240870))
    EVT_SET(LocalVar(0), -200)
    EVT_SET(LocalVar(1), 130)
    EVT_SET(LocalVar(2), -80)
    EVT_SET(LocalVar(3), 170)
    EVT_SET(LocalVar(4), 0)
    EVT_EXEC(N(80240870))
    EVT_SET(LocalVar(0), -270)
    EVT_SET(LocalVar(1), -80)
    EVT_SET(LocalVar(2), -225)
    EVT_SET(LocalVar(3), 125)
    EVT_SET(LocalVar(4), 0)
    EVT_EXEC(N(80240870))
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_EXEC(N(802419F4))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
        EVT_SET(LocalVar(0), EVT_PTR(N(80240B78)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_EXEC_WAIT(N(80240750))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_80240000_CC0E30))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_E28)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80240E30) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

NpcSettings N(npcSettings_80240E5C) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "common/foliage.inc.c"

s32** N(varStash) = NULL;

EvtScript N(802417F0) = {
    EVT_CALL(ShowGotItem, LocalVar(0), 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(80241820) = {
    EVT_CALL(ShowGotItem, LocalVar(0), 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

s32 N(D_80241850_CC2680) = {
    0x00000000,
};

s32 N(D_80241854_CC2684) = {
    0x00000000,
};

EvtScript N(80241858) = {
    EVT_SET(LocalVar(9), LocalVar(1))
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVarA, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, LocalVar(1))
            EVT_CALL(GetPlayerPos, LocalVar(3), LocalVar(4), LocalVar(5))
            EVT_CALL(N(AddPlayerHandsOffset), LocalVar(3), LocalVar(4), LocalVar(5))
            EVT_BITWISE_OR_CONST(LocalVar(0), 0x50000)
            EVT_CALL(MakeItemEntity, LocalVar(0), LocalVar(3), LocalVar(4), LocalVar(5), 1, 0)
            EVT_CALL(SetPlayerAnimation, 393221)
            EVT_WAIT(30)
            EVT_CALL(SetPlayerAnimation, ANIM_10002)
            EVT_CALL(RemoveItemEntity, LocalVar(0))
    EVT_END_SWITCH
    EVT_CALL(N(func_80240614_CC1444), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(8024199C) = {
    EVT_CALL(N(func_8024064C_CC147C), LocalVar(0))
    EVT_BIND_PADLOCK(N(80241858), 0x10, 0, EVT_PTR(N(D_802429E0)), 0, 1)
    EVT_CALL(N(func_802405C0_CC13F0), LocalVar(0))
    EVT_RETURN
    EVT_END
};

s32 N(D_802419EC_CC281C)[] = {
    0x0000001E, 0x00000000,
};

EvtScript N(802419F4) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetNpcPos, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(UseSettingsFrom, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetCamDistance, 0, 350)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-9.5))
    EVT_CALL(SetCamPosA, 0, 0, 0)
    EVT_CALL(SetCamPosB, 0, 0, -50)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x00C7))
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_03"), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241B6C) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(PlayerMoveTo, -5, 20, 20)
    EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_100)), FALSE)
    EVT_CALL(PlayerFaceNpc, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241BE4) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(PlayerMoveTo, -5, 20, 20)
    EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_100)), FALSE)
    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), FALSE)
    EVT_CALL(PlayerFaceNpc, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80241C8C) = {
    EVT_EXEC_WAIT(N(8024080C))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(47)
            EVT_SWITCH(GF_FLO12_Met_Rosie)
                EVT_CASE_EQ(0)
                    EVT_EXEC(N(80241B6C))
                    EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                    EVT_ADD(LocalVar(0), 30)
                    EVT_CALL(SetCamProperties, 0, EVT_FLOAT(4.0), LocalVar(0), LocalVar(1), LocalVar(2), 325, EVT_FLOAT(19.0), EVT_FLOAT(-9.5))
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_3, NPC_ANIM_rosie_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x008C))
                    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x0011))
                    EVT_WAIT(10)
                    EVT_SWITCH(LocalVar(0))
                        EVT_CASE_EQ(0)
                            EVT_CALL(ContinueSpeech, -1, NPC_ANIM_rosie_Palette_00_Anim_3, NPC_ANIM_rosie_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x008D))
                        EVT_CASE_EQ(1)
                            EVT_CALL(ContinueSpeech, -1, NPC_ANIM_rosie_Palette_00_Anim_3, NPC_ANIM_rosie_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x008E))
                    EVT_END_SWITCH
                    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), FALSE)
                    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_5)
                    EVT_WAIT(10)
                    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_2)
                    EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, -33, 14, 19, 1, 1380)
                    EVT_WAIT(10)
                    EVT_SWITCH(GF_FLO10_LilyRequestedWaterStone)
                        EVT_CASE_EQ(0)
                            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_4, 5, MESSAGE_ID(0x11, 0x008F))
                        EVT_CASE_EQ(1)
                            EVT_CALL(SetPlayerAnimation, 393218)
                            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_4, 5, MESSAGE_ID(0x11, 0x008F))
                            EVT_CALL(SetPlayerAnimation, 393221)
                            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0091))
                            EVT_CALL(SetPlayerAnimation, ANIM_PRAY)
                            EVT_WAIT(40)
                            EVT_CALL(SetPlayerAnimation, ANIM_10002)
                            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0092))
                            EVT_SET(GF_FLO12_RosieRequestedSomethingBeautiful, 1)
                    EVT_END_SWITCH
                    EVT_SET(GF_FLO12_Met_Rosie, 1)
                EVT_CASE_EQ(1)
                    EVT_SWITCH(GF_FLO12_RosieRequestedSomethingBeautiful)
                        EVT_CASE_EQ(0)
                            EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, 1)
                                EVT_EXEC(N(80241BE4))
                                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_4, 5, MESSAGE_ID(0x11, 0x0090))
                                EVT_CALL(SetPlayerAnimation, 393221)
                                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0091))
                                EVT_CALL(SetPlayerAnimation, ANIM_PRAY)
                                EVT_WAIT(40)
                                EVT_CALL(SetPlayerAnimation, ANIM_10002)
                                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0092))
                                EVT_SET(GF_FLO12_RosieRequestedSomethingBeautiful, 1)
                            EVT_ELSE
                                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_4, 5, MESSAGE_ID(0x11, 0x0090))
                            EVT_END_IF
                        EVT_CASE_EQ(1)
                            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0093))
                    EVT_END_SWITCH
            EVT_END_SWITCH
        EVT_CASE_LT(48)
            EVT_CALL(FindKeyItem, ITEM_CRYSTAL_BERRY, LocalVar(0))
            EVT_IF_NE(LocalVar(0), -1)
                EVT_EXEC(N(80241BE4))
                EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_ADD(LocalVar(0), 30)
                EVT_CALL(SetCamProperties, 0, EVT_FLOAT(4.0), LocalVar(0), LocalVar(1), LocalVar(2), 325, EVT_FLOAT(19.0), EVT_FLOAT(-9.5))
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0094))
            EVT_SET(LocalVar(0), EVT_PTR(N(D_802419EC_CC281C)))
            EVT_SET(LocalVar(1), 0)
            EVT_EXEC_WAIT(N(8024199C))
            EVT_SWITCH(LocalVar(0))
                EVT_CASE_LE(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0093))
                EVT_CASE_DEFAULT
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0095))
                    EVT_CALL(RemoveItemEntity, LocalVar(7))
                    EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -33, 14, 19, 1, 1380)
                    EVT_SET(LocalVar(0), 87)
                    EVT_SET(LocalVar(1), 1)
                    EVT_EXEC_WAIT(N(802417F0))
                    EVT_CALL(AddKeyItem, ITEM_WATER_STONE)
                    EVT_WAIT(10)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0096))
                    EVT_SET(AreaFlag(22), 1)
                    EVT_SET(GB_StoryProgress, 48)
            EVT_END_SWITCH
        EVT_CASE_LT(53)
            EVT_SWITCH(AreaFlag(22))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0097))
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0096))
            EVT_END_SWITCH
        EVT_CASE_LT(60)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0098))
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0099))
    EVT_END_SWITCH
    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
    EVT_EXEC_WAIT(N(80240830))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802423D0) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241C8C)))
    EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 35)
    EVT_CALL(SetNpcPos, 1, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_2)), TRUE)
    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_HAS_SHADOW)), TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(47)
            EVT_IF_EQ(GF_FLO12_Met_Rosie, 1)
                EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), FALSE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_2)
                EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, -33, 14, 19, 1, 1380)
                EVT_SET(LVarA, LocalVar(0))
            EVT_END_IF
        EVT_CASE_LT(48)
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_2)
            EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, -33, 14, 19, 1, 1380)
            EVT_SET(LVarA, LocalVar(0))
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_2)
            EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -33, 14, 19, 1, 1380)
            EVT_SET(LVarA, LocalVar(0))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_802425D8)[] = {
    {
        .id = NPC_ROSIE0,
        .settings = &N(npcSettings_80240E30),
        .pos = { -70.0f, 0.0f, 20.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_400000,
        .init = &N(init_802423D0),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E0),
    },
    {
        .id = NPC_ROSIE1,
        .settings = &N(npcSettings_80240E5C),
        .pos = { -70.0f, 0.0f, 20.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_GRAVITY,
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
        },
    },
};

NpcGroupList N(npcGroupList_802429B8) = {
    NPC_GROUP(N(npcGroup_802425D8)),
    {},
};

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_802405C0_CC13F0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80241850_CC2680) = FALSE;
    }

    if (N(D_80241850_CC2680)) {
        N(D_80241850_CC2680) = FALSE;
        evt_set_variable(script, *args, N(D_80241854_CC2684));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80240614_CC1444)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241854_CC2684) = evt_get_variable(script, *args);
    N(D_80241850_CC2680) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024064C_CC147C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*)evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_802429E0)[i] = ptr[i];
        }
        N(D_802429E0)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_802429E0)[i] = i + 16;
            N(D_802429E0)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
