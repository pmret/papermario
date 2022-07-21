#include "dgb_15.h"
#include "message_ids.h"
#include "sprite/npc/world_tubba.h"
#include "entity.h"

enum {
    NPC_WORLD_TUBBA,
};

EntryList N(entryList) = {
    { -1290.0f, 0.0f, 180.0f, 90.0f },
    { 125.0f, 0.0f, 180.0f, 270.0f },
    { 0.0f, 0.0f, 88.0f, 180.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_15_tattle },
};

EvtScript N(802418E0) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-29)
            EVT_IF_EQ(EVT_SAVE_VAR(203), 15)
                EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
            EVT_ELSE
                EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_19B4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

s32 N(itemList_802419C0)[] = {
    ITEM_TUBBA_CASTLE_KEY,
    ITEM_NONE,
};

EvtScript N(exitDoubleDoor_802419C8) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 19)
    EVT_SET(EVT_VAR(2), 12)
    EVT_SET(EVT_VAR(3), 14)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_14"), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_80241A7C) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 1)
    EVT_SET(EVT_VAR(1), 10)
    EVT_SET(EVT_VAR(2), 19)
    EVT_SET(EVT_VAR(3), 17)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_17"), 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitSingleDoor_80241B30) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(EVT_VAR(0), 2)
    EVT_SET(EVT_VAR(1), 6)
    EVT_SET(EVT_VAR(2), 22)
    EVT_SET(EVT_VAR(3), 1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_16"), 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

const s32 N(pad_XXXX)[] = { 0, 0 };

EvtScript N(80241BE4) = {
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802419C8), TRIGGER_WALL_PRESS_A, 19, 1, 0)
    EVT_BIND_TRIGGER(N(exitSingleDoor_80241B30), TRIGGER_WALL_PRESS_A, 6, 1, 0)
    EVT_IF_EQ(EVT_SAVE_FLAG(1066), 0)
        EVT_BIND_PADLOCK(N(80242AD0), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(itemList_802419C0)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(N(exitDoubleDoor_80241A7C), TRIGGER_WALL_PRESS_A, 10, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(enterSingleDoor_80241C88) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(EVT_VAR(2), 12)
            EVT_SET(EVT_VAR(3), 14)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(1)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(EVT_VAR(2), 19)
            EVT_SET(EVT_VAR(3), 17)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(2)
            EVT_CALL(UseDoorSounds, 0)
            EVT_SET(EVT_VAR(2), 22)
            EVT_SET(EVT_VAR(3), 1)
            EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_END_SWITCH
    EVT_EXEC(N(80241BE4))
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_SET(EVT_AREA_FLAG(1), 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_IF_EQ(EVT_SAVE_FLAG(1068), 0)
        EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80242AB0)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(802418E0))
    EVT_EXEC(N(enterSingleDoor_80241C88))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1E94)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80241EA0) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_CALL(func_80045900, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetEnemyFlagBits, -1, 16, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(unk_missing_80241F5C)[] = {
    0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x0039000C, 0x00390007, 0x00390008, 0x00390011,
    0x00390012, 0xFFFFFFFF, 0x00390000, 0xFFFFFFFF,
};

s32 N(D_80241F8C_C5149C)[] = {
    0x3FC00000, 0x00000078, 0x0000001E, 0x42AA0000, 0x42820000, 0x00000005, 0x40600000, 0x0000005A,
    0x0000000C, 0x42DC0000, 0x42B40000, 0x00000003,
};

EvtScript N(80241FBC) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(N(WanderMeleeAI_Main), EVT_PTR(N(D_80241F8C_C5149C)))
    EVT_RETURN
    EVT_END
};

s32 N(unk_missing_8024202C)[] = {
    0x00000000, 0x00240022, 0x00000000, 0x00000000, N(80241FBC), 0x80077F70, 0x00000000, 0x8007809C,
    0x00000000, 0x00000000, 0x000D0000,
};

EvtScript N(80242058) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 4)
    EVT_CALL(SetSelfVar, 1, 32)
    EVT_CALL(SetSelfVar, 2, 50)
    EVT_CALL(SetSelfVar, 3, 32)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, 8389)
    EVT_CALL(N(MeleeHitbox_Main))
    EVT_RETURN
    EVT_END
};

s32 N(unk_missing_80242100)[] = {
    0x00000000, 0x000E0012, 0x00000000, 0x00000000, N(80242058), 0x00000000, 0x00000000, N(80241EA0),
    0x00000000, 0x00000000, 0x000D0008,
};

NpcSettings N(npcSettings_8024212C) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

s32 N(unk_missing_80242158)[] = {
    0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x000D0000,
};

EvtScript N(80242184) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(GetNpcPos, 0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
        EVT_SUB(EVT_VAR(1), EVT_VAR(0))
        EVT_IF_LT(EVT_VAR(1), 150)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_SET(EVT_SAVE_FLAG(1067), 1)
    EVT_SET(EVT_AREA_FLAG(1), 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80242238) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_IF_GE(EVT_VAR(0), -1150)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
    EVT_WAIT_FRAMES(15)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, 0, -50, 0, 180)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(2.0))
        EVT_CALL(SetPanTarget, 0, -50, 0, 180)
        EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_END_THREAD
    EVT_SET(EVT_SAVE_VAR(203), 15)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, 88)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_tubba_Palette_00_Anim_9)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(NpcMoveTo, NPC_SELF, -53, 180, 60)
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_6)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_10, NPC_ANIM_world_tubba_Palette_00_Anim_6, 0, MESSAGE_ID(0x0E, 0x00F3))
    EVT_WAIT_FRAMES(15)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(2.0))
        EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
        EVT_CALL(PanToTarget, 0, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(npcAI_8024274C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(802424E8) = {
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(6), EVT_VAR(7), EVT_VAR(8))
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
        EVT_IF_NE(EVT_VAR(3), EVT_VAR(6))
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 65538)
            EVT_CALL(GetDist2D, EVT_VAR(10), EVT_VAR(0), EVT_VAR(2), EVT_VAR(3), EVT_VAR(5))
            EVT_SWITCH(EVT_VAR(10))
                EVT_CASE_LT(200)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(1.6))
                        EVT_WAIT_FRAMES(5)
                        EVT_CALL(ShakeCam, 0, 0, 2, EVT_FIXED(0.8))
                    EVT_END_THREAD
                EVT_CASE_LT(300)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(0.6))
                        EVT_WAIT_FRAMES(5)
                        EVT_CALL(ShakeCam, 0, 0, 2, EVT_FIXED(0.3))
                    EVT_END_THREAD
                EVT_CASE_GE(300)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(0.1))
                        EVT_WAIT_FRAMES(5)
                        EVT_CALL(ShakeCam, 0, 0, 2, EVT_FIXED(0.05))
                    EVT_END_THREAD
            EVT_END_SWITCH
            EVT_WAIT_FRAMES(12)
        EVT_ELSE
        EVT_END_IF
        EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(6), EVT_VAR(7), EVT_VAR(8))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

NpcAISettings N(npcAISettings_8024271C) = {
    .moveSpeed = 3.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .alertOffsetDist = 80.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 180,
    .chaseUpdateInterval = 2,
    .chaseRadius = 160.0f,
    .chaseOffsetDist = 80.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_8024274C) = {
    EVT_EXEC(N(80242184))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_GRAVITY)), TRUE)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_tubba_Palette_00_Anim_C)
    EVT_EXEC(N(802424E8))
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAISettings_8024271C)))
    EVT_RETURN
    EVT_END
};

extern const char N(dgb_14_name_hack)[];

EvtScript N(defeat_802427B0) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_14_name_hack)), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802427EC) = {
    EVT_IF_NE(EVT_SAVE_VAR(0), -32)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.25), EVT_FIXED(1.25), EVT_FIXED(1.25))
    EVT_IF_NE(EVT_SAVE_VAR(203), 15)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242238)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, -310, 0, 180)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_8024274C)))
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802427B0)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_802428C0) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_8024212C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_JUMPING | NPC_FLAG_40000 | NPC_FLAG_200000 | NPC_FLAG_NO_DROPS,
    .init = &N(init_802427EC),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 5,
    .itemDrops = {
        { ITEM_SUPER_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 2,
    .maxCoinBonus = 3,
    .movement = { 7, -500, 0, 200, -700, 0, 200, -900, 0, 200, -1000, 0, 200, -800, 0, 200, -600, 0, 200, -400, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, -500, 0, 200, 1000, 250, 1, 1 },
    .animations = {
        NPC_ANIM_world_tubba_Palette_00_Anim_6,
        NPC_ANIM_world_tubba_Palette_00_Anim_9,
        NPC_ANIM_world_tubba_Palette_00_Anim_C,
        NPC_ANIM_world_tubba_Palette_00_Anim_C,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
    },
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80242AB0) = {
    NPC_GROUP(N(npcGroup_802428C0), BATTLE_ID(15, 4, 0, 1)),
    {},
};

static s32 N(pad_2AC8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(80242AD0) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00D8), 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(EVT_VAR(0), -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_TUBBA_CASTLE_KEY, EVT_VAR(0))
    EVT_CALL(RemoveKeyItemAt, EVT_VAR(0))
    EVT_CALL(CloseChoicePopup)
    EVT_SET(EVT_SAVE_FLAG(1066), 1)
    EVT_CALL(N(GetEntityPosition), EVT_MAP_VAR(0), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(PlaySoundAt, 0x269, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(0), EVT_MAP_VAR(0))
    EVT_CALL(N(SetEntityFlags100000))
    EVT_RESUME_GROUP(1)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80242C38) = {
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80241A7C), TRIGGER_WALL_PRESS_A, 10, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1066), 0)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 130, 8, 175, -80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(80242C38)))
        EVT_SET(EVT_MAP_VAR(0), EVT_VAR(0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/WanderMeleeAI.inc.c"

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

#include "world/common/UnkFunc1.inc.c"

const char N(dgb_14_name_hack)[] = "dgb_14";
