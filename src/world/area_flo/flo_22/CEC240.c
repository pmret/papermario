#include "flo_22.h"
#include "message_ids.h"
#include "sprite/npc/bzzap.h"
#include "sprite/npc/dayzee.h"

enum {
    NPC_BZZAP,
    NPC_DAYZEE,
};

EntryList N(entryList) = {
    { -230.0f, 0.0f, 0.0f, 90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_22_tattle },
};

EvtSource N(802402E0) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(exitWalk_80240350) = EXIT_WALK_SCRIPT(60,  0, "flo_03",  1);

EvtSource N(802403AC) = {
    EVT_BIND_TRIGGER(N(exitWalk_80240350), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80240DE4)))
    EVT_EXEC(N(80241F6C))
    EVT_EXEC(N(80241528))
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(802403AC)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC(N(80240E24))
    EVT_EXEC_WAIT(N(802402E0))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_80240000_CEC240))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_518)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80240520) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtSource N(idle_8024054C) = {
    EVT_SET(EVT_MAP_VAR(10), 0)
    EVT_LOOP(0)
        EVT_SWITCH(EVT_MAP_VAR(10))
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(1)
                EVT_CALL(SetPlayerAnimation, 65582)
                EVT_SET(EVT_MAP_VAR(10), 0)
                EVT_CALL(StartBattle)
        EVT_END_SWITCH
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_802405E4) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_THREAD
                EVT_WAIT_FRAMES(25)
                EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_2)), FALSE)
            EVT_END_THREAD
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(1)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_bzzap_Palette_00_Anim_1)
            EVT_CALL(SetNpcPos, NPC_SELF, 30, 60, 0)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
            EVT_CALL(NpcJump0, NPC_SELF, 30, 0, 0, 15)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80240740) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024054C)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802405E4)))
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80240778) = {
    EVT_SET(EVT_MAP_VAR(11), 0)
    EVT_LOOP(0)
        EVT_SWITCH(EVT_MAP_VAR(11))
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(1)
                EVT_CALL(SetPlayerAnimation, 65582)
                EVT_SET(EVT_MAP_VAR(11), 0)
                EVT_CALL(StartBattle)
        EVT_END_SWITCH
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_80240810) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_THREAD
                EVT_WAIT_FRAMES(25)
                EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_2)), FALSE)
            EVT_END_THREAD
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(1)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_dayzee_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FIXED(2.0))
            EVT_CALL(NpcJump0, NPC_SELF, 30, 0, 0, 15)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_dayzee_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FIXED(2.0))
            EVT_CALL(NpcJump0, NPC_SELF, 30, 0, 0, 15)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802409CC) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80240778)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80240810)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80240A04) = {
    .id = NPC_BZZAP,
    .settings = &N(npcSettings_80240520),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80240740),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_3,
        NPC_ANIM_bzzap_Palette_00_Anim_3,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_6,
        NPC_ANIM_bzzap_Palette_00_Anim_6,
        NPC_ANIM_bzzap_Palette_00_Anim_4,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
    },
};

StaticNpc N(npcGroup_80240BF4) = {
    .id = NPC_DAYZEE,
    .settings = &N(npcSettings_80240520),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_802409CC),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .animations = {
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_2,
        NPC_ANIM_dayzee_Palette_00_Anim_3,
        NPC_ANIM_dayzee_Palette_00_Anim_3,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_8,
        NPC_ANIM_dayzee_Palette_00_Anim_8,
        NPC_ANIM_dayzee_Palette_00_Anim_6,
        NPC_ANIM_dayzee_Palette_00_Anim_7,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80240DE4) = {
    NPC_GROUP(N(npcGroup_80240A04), BATTLE_ID(24, 23, 0, 3)),
    NPC_GROUP(N(npcGroup_80240BF4), BATTLE_ID(24, 15, 0, 2)),
    {},
};

static s32 N(pad_E08)[] = {
    0x00000000, 0x00000000,
};

s32 N(itemList_80240E10)[] = {
    ITEM_RED_BERRY,
    ITEM_BLUE_BERRY,
    ITEM_YELLOW_BERRY,
    ITEM_BUBBLE_BERRY,
    ITEM_NONE,
};

EvtSource N(80240E24) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x11, 0x00DB), 300, 120)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(80240E84) = {
    EVT_CALL(SetPlayerAnimation, 393230)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
        EVT_SET(EVT_VAR(6), 35)
        EVT_SET(EVT_VAR(5), 5)
        EVT_CALL(MakeItemEntity, EVT_VAR(8), EVT_VAR(2), EVT_VAR(6), 0, 1, 0)
        EVT_SET(EVT_VAR(7), EVT_VAR(0))
        EVT_CALL(MakeLerp, EVT_VAR(2), 35, 20, 5)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetItemPos, EVT_VAR(7), EVT_VAR(0), EVT_VAR(6), 0)
            EVT_ADD(EVT_VAR(6), EVT_VAR(5))
            EVT_ADD(EVT_VAR(5), -1)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(RemoveItemEntity, EVT_VAR(7))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAt, 0x302, 0, 35, 0, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_WAIT_FRAMES(10)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241028) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(ShowConsumableChoicePopup)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(EVT_VAR(8), EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(8))
        EVT_CASE_LE(-1)
        EVT_CASE_LE(0)
            EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x015C), 160, 40)
        EVT_CASE_EQ(158)
            EVT_EXEC_WAIT(N(80240E84))
            EVT_CALL(RemoveItemAt, EVT_VAR(1))
            EVT_IF_EQ(EVT_SAVE_FLAG(1395), 0)
                EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x00DD), 35, 35, 0)
                EVT_SET(EVT_SAVE_FLAG(1395), 1)
                EVT_CALL(MakeItemEntity, ITEM_FLOWER_SAVER_B, -35, 0, 0, 0, EVT_SAVE_FLAG(1392))
                EVT_SET(EVT_VAR(7), EVT_VAR(0))
                EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_2)), TRUE)
                EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_HAS_SHADOW)), FALSE)
                EVT_CALL(SetNpcPos, 0, 35, 0, 0)
                EVT_CALL(SetNpcJumpscale, 0, EVT_FIXED(1.0))
                EVT_THREAD
                    EVT_CALL(NpcJump0, 0, -53, 0, 0, 25)
                    EVT_CALL(NpcJump0, 0, -73, 0, 0, 15)
                    EVT_CALL(NpcJump0, 0, -83, 0, 0, 8)
                EVT_END_THREAD
                EVT_LOOP(53)
                    EVT_CALL(GetNpcPos, 0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
                    EVT_CALL(SetItemPos, EVT_VAR(7), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetNpcPos, 0, 0, -1000, 0)
                EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_2)), FALSE)
                EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_HAS_SHADOW)), TRUE)
            EVT_ELSE
                EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x00DE), 35, 35, 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(80240E84))
            EVT_CALL(RemoveItemAt, EVT_VAR(1))
            EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x00DC), 35, 35, 0)
            EVT_CALL(RandInt, 1, EVT_VAR(1))
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_CALL(SetNpcJumpscale, 0, EVT_FIXED(0.0))
                EVT_CALL(NpcFacePlayer, 0, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetNpcPos, 0, 30, 0, 0)
                EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_bzzap_Palette_00_Anim_1)
                EVT_CALL(NpcJump0, 0, 30, 60, 0, 20)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_bzzap_Palette_00_Anim_4)
                EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_ADD(EVT_VAR(1), 20)
                EVT_CALL(NpcJump0, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 5)
                EVT_SET(EVT_MAP_VAR(10), 1)
            EVT_ELSE
                EVT_CALL(SetNpcPos, 1, 30, 0, 0)
                EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_dayzee_Palette_00_Anim_E)
                EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_ADD(EVT_VAR(1), 20)
                EVT_CALL(SetNpcJumpscale, 1, EVT_FIXED(2.0))
                EVT_CALL(NpcJump0, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 20)
                EVT_SET(EVT_MAP_VAR(11), 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241528) = {
    EVT_BIND_PADLOCK(N(80241028), TRIGGER_WALL_PRESS_A, 9, EVT_PTR(N(itemList_80240E10)), 0, 1)
    EVT_IF_EQ(EVT_SAVE_FLAG(1395), 1)
        EVT_CALL(MakeItemEntity, ITEM_FLOWER_SAVER_B, -83, 0, 0, 0, EVT_SAVE_FLAG(1392))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1594)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

void playFX_82();

ApiStatus N(func_80240000_CEC240)(Evt* script, s32 isInitialCall) {
    playFX_82(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
