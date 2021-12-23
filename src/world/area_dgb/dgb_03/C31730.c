#include "dgb_03.h"
#include "sprite/npc/world_clubba.h"
#include "message_ids.h"

extern Npc* wPartnerNpc;

enum {
    NPC_WORLD_CLUBBA0,
    NPC_WORLD_CLUBBA1,
    NPC_WORLD_CLUBBA2,
    NPC_WORLD_CLUBBA3,
    NPC_WORLD_CLUBBA4,
    NPC_WORLD_CLUBBA5,
};

EntryList N(entryList) = {
    { -343.0f,   0.0f,   80.0f,  90.0f },
    {  343.0f,   0.0f,   80.0f, 270.0f },
    { -220.0f,   0.0f, -170.0f, 180.0f },
    { -343.0f, 210.0f,   80.0f,  90.0f },
    {  343.0f, 210.0f,   80.0f, 270.0f },
    { -220.0f, 210.0f, -170.0f, 180.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_03_tattle },
};

EvtSource N(80242870) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2908)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitDoubleDoor_80242910) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 1)
    EVT_SET(EVT_VAR(1), 25)
    EVT_SET(EVT_VAR(2), 36)
    EVT_SET(EVT_VAR(3), 34)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_02"), 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_802429C4) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 4)
    EVT_SET(EVT_VAR(1), 21)
    EVT_SET(EVT_VAR(2), 46)
    EVT_SET(EVT_VAR(3), 44)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_09"), 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_80242A78) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 13)
    EVT_SET(EVT_VAR(2), 29)
    EVT_SET(EVT_VAR(3), 31)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_04"), 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitWalk_80242B2C) = EXIT_WALK_SCRIPT(26,  2, "dgb_13",  0);

EvtSource N(exitSingleDoor_80242B88) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(EVT_VAR(0), 2)
    EVT_SET(EVT_VAR(1), 33)
    EVT_SET(EVT_VAR(2), 49)
    EVT_SET(EVT_VAR(3), 1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_05"), 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_80242C3C) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 3)
    EVT_SET(EVT_VAR(1), 17)
    EVT_SET(EVT_VAR(2), 39)
    EVT_SET(EVT_VAR(3), 41)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_14"), 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(80242CF0) = {
    EVT_BIND_TRIGGER(N(exitWalk_80242B2C), TRIGGER_FLOOR_ABOVE, 35, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterDoubleDoor_80242D1C) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(EVT_VAR(2), 29)
            EVT_SET(EVT_VAR(3), 31)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80242CF0))
        EVT_CASE_EQ(1)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(EVT_VAR(2), 36)
            EVT_SET(EVT_VAR(3), 34)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80242CF0))
        EVT_CASE_EQ(2)
            EVT_CALL(UseDoorSounds, 0)
            EVT_SET(EVT_VAR(2), 49)
            EVT_SET(EVT_VAR(3), 1)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(80242CF0))
        EVT_CASE_EQ(3)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(EVT_VAR(2), 39)
            EVT_SET(EVT_VAR(3), 41)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80242CF0))
        EVT_CASE_EQ(4)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(EVT_VAR(2), 46)
            EVT_SET(EVT_VAR(3), 44)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80242CF0))
        EVT_CASE_EQ(5)
            EVT_SET(EVT_VAR(0), EVT_PTR(N(80242CF0)))
            EVT_EXEC(EnterWalkShort)
            EVT_WAIT_FRAMES(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(itemList_80242F28)[] = {
    ITEM_TUBBA_CASTLE_KEY,
    ITEM_NONE,
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_IF_LT(EVT_SAVE_VAR(0), -15)
        EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80244988)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80243608))
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80242910), TRIGGER_WALL_PRESS_A, 25, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802429C4), TRIGGER_WALL_PRESS_A, 21, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80242A78), TRIGGER_WALL_PRESS_A, 13, 1, 0)
    EVT_BIND_TRIGGER(N(exitSingleDoor_80242B88), TRIGGER_WALL_PRESS_A, 33, 1, 0)
    EVT_IF_EQ(EVT_SAVE_FLAG(1043), 0)
        EVT_BIND_PADLOCK(N(80243740), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(itemList_80242F28)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(N(exitDoubleDoor_80242C3C), TRIGGER_WALL_PRESS_A, 17, 1, 0)
    EVT_END_IF
    EVT_EXEC(N(80242870))
    EVT_EXEC(N(enterDoubleDoor_80242D1C))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_30D8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(802430E0) = {
    EVT_SET_GROUP(0)
    EVT_LOOP(20)
        EVT_CALL(GetCurrentPartner, EVT_VAR(10))
        EVT_IF_NE(EVT_VAR(10), 0)
            EVT_SET(EVT_VAR(8), -1)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(N(UnkFunc11), EVT_VAR(9))
        EVT_IF_EQ(EVT_VAR(0), 0)
            EVT_SET(EVT_VAR(8), -1)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SetPlayerActionState, 20)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetCurrentPartner, EVT_VAR(10))
    EVT_IF_NE(EVT_VAR(10), 0)
        EVT_SET(EVT_VAR(8), -1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 100, EVT_FIXED(0.6))
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_GE(EVT_VAR(6), EVT_VAR(7))
            EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_ELSE
            EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_END_IF
        EVT_CALL(SetPlayerActionState, 20)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_SET(EVT_VAR(1), EVT_VAR(0))
        EVT_SET(EVT_VAR(2), EVT_VAR(7))
        EVT_SUB(EVT_VAR(2), EVT_VAR(6))
        EVT_ADD(EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(MakeLerp, EVT_VAR(0), EVT_VAR(1), 100, 0)
        EVT_LOOP(0)
            EVT_CALL(SetPlayerActionState, 20)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(UnkFunc12))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetPlayerActionState, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, EVT_VAR(6), EVT_VAR(7), 100, 0)
    EVT_CALL(PlaySoundAtCollider, 27, 0x80000010, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 51, EVT_VAR(0), 0, 0)
        EVT_CALL(UpdateColliderTransform, 27)
        EVT_CALL(UpdateColliderTransform, 28)
        EVT_CALL(UpdateColliderTransform, 29)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(StopSound, 0x80000010)
    EVT_RETURN
    EVT_END
};

EvtSource N(80243470) = {
    EVT_IF_NE(EVT_SAVE_FLAG(1044), 0)
        EVT_GOTO(90)
    EVT_END_IF
    EVT_SET(EVT_VAR(6), 0)
    EVT_SET(EVT_VAR(7), 48)
    EVT_SET(EVT_VAR(8), 0)
    EVT_SET(EVT_VAR(9), 27)
    EVT_EXEC_WAIT(N(802430E0))
    EVT_LABEL(90)
    EVT_IF_NE(EVT_VAR(8), -1)
        EVT_SET(EVT_SAVE_FLAG(1045), 0)
        EVT_SET(EVT_SAVE_FLAG(1044), 1)
        EVT_UNBIND
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(8024353C) = {
    EVT_IF_NE(EVT_SAVE_FLAG(1044), 0)
        EVT_GOTO(90)
    EVT_END_IF
    EVT_SET(EVT_VAR(6), 0)
    EVT_SET(EVT_VAR(7), -48)
    EVT_SET(EVT_VAR(8), 0)
    EVT_SET(EVT_VAR(9), 28)
    EVT_EXEC_WAIT(N(802430E0))
    EVT_LABEL(90)
    EVT_IF_NE(EVT_VAR(8), -1)
        EVT_SET(EVT_SAVE_FLAG(1045), 1)
        EVT_SET(EVT_SAVE_FLAG(1044), 1)
        EVT_UNBIND
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(80243608) = {
    EVT_CALL(ParentColliderToModel, 27, 51)
    EVT_CALL(ParentColliderToModel, 28, 51)
    EVT_CALL(ParentColliderToModel, 29, 51)
    EVT_IF_EQ(EVT_SAVE_FLAG(1044), 0)
        EVT_BIND_TRIGGER(N(80243470), TRIGGER_WALL_PUSH, 27, 1, 0)
        EVT_BIND_TRIGGER(N(8024353C), TRIGGER_WALL_PUSH, 28, 1, 0)
    EVT_ELSE
        EVT_IF_EQ(EVT_SAVE_FLAG(1045), 0)
            EVT_SET(EVT_VAR(0), 48)
        EVT_ELSE
            EVT_SET(EVT_VAR(0), -48)
        EVT_END_IF
        EVT_CALL(TranslateModel, 51, EVT_VAR(0), 0, 0)
        EVT_CALL(UpdateColliderTransform, 27)
        EVT_CALL(UpdateColliderTransform, 28)
        EVT_CALL(UpdateColliderTransform, 29)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3738)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(80243740) = {
    EVT_SET_GROUP(0)
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
    EVT_SET(EVT_SAVE_FLAG(1043), 1)
    EVT_CALL(N(GetEntityPosition), EVT_MAP_VAR(0), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(PlaySoundAt, 0x269, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(0), EVT_MAP_VAR(0))
    EVT_CALL(N(SetEntityFlags100000))
    EVT_RESUME_GROUP(1)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtSource N(802438A8) = {
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80242C3C), TRIGGER_WALL_PRESS_A, 17, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1043), 0)
        EVT_CALL(MakeEntity, 0x802BCD68, -355, 218, 75, 80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(802438A8)))
        EVT_SET(EVT_MAP_VAR(0), EVT_VAR(0))
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 0, 75, 100, 17, EVT_SAVE_FLAG(1042))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3964)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80243970) = {
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

s32 N(unk_missing_80243A2C)[] = {
    0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x0039000C, 0x00390007, 0x00390008, 0x00390011,
    0x00390012, 0xFFFFFFFF,
};

s32 N(extraAnimationList_80243A54)[] = {
    NPC_ANIM_world_clubba_Palette_00_Anim_0,
    ANIM_END,
};

NpcAISettings N(npcAISettings_80243A5C) = {
    .moveSpeed = 1.5f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 85.0f,
    .unk_10 = { .f = 65.0f },
    .unk_14 = 5,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 90 },
    .unk_20 = 12,
    .chaseRadius = 110.0f,
    .unk_28 = { .f = 90.0f },
    .unk_2C = 3,
};

EvtSource N(npcAI_80243A8C) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(N(func_8024086C_C31D4C), EVT_PTR(N(npcAISettings_80243A5C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243AFC) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_80243A8C),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcAISettings N(npcAISettings_80243B28) = {
    .moveSpeed = 1.5f,
    .moveTime = 20,
    .waitTime = 30,
    .alertRadius = 85.0f,
    .unk_10 = { .f = 65.0f },
    .unk_14 = 5,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 90 },
    .unk_20 = 12,
    .chaseRadius = 110.0f,
    .unk_28 = { .f = 90.0f },
    .unk_2C = 3,
};

EvtSource N(npcAI_80243B58) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(N(func_802419B0_C32E90), EVT_PTR(N(npcAISettings_80243B28)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243BC8) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_80243B58),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcAISettings N(npcAISettings_80243BF4) = {
    .moveSpeed = 1.0f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .unk_10 = { .f = 40.0f },
    .unk_14 = 10,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 90 },
    .unk_20 = 15,
    .chaseRadius = 200.0f,
    .unk_28 = { .f = 160.0f },
    .unk_2C = 1,
};

EvtSource N(npcAI_80243C24) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 10)
    EVT_CALL(SetSelfVar, 2, 14)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(N(func_80242480_C33960), EVT_PTR(N(npcAISettings_80243BF4)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243C94) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_80243C24),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

EvtSource N(npcAI_80243CC0) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 4)
    EVT_CALL(SetSelfVar, 1, 32)
    EVT_CALL(SetSelfVar, 2, 50)
    EVT_CALL(SetSelfVar, 3, 32)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, 8389)
    EVT_CALL(N(UnkFunc7))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243D68) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_80243CC0),
    .onDefeat = &N(80243970),
    .level = 13,
    .unk_2A = 8,
};

EvtSource N(init_80243D94) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 3)
        EVT_CALL(SetNpcPos, NPC_SELF, -330, 210, -20)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80243DE8)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_80243AFC),
        .pos = { 180.0f, 0.0f, -122.0f },
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
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
        .movement = { 180, 0, -122, 40, 0, -32767, 0, 0, 0, 75, 355, 255, 1, 1 },
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_80243D68),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .extraAnimations = N(extraAnimationList_80243A54),
    },
};

StaticNpc N(npcGroup_802441C8)[] = {
    {
        .id = NPC_WORLD_CLUBBA2,
        .settings = &N(npcSettings_80243BC8),
        .pos = { -272.0f, 0.0f, -135.0f },
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
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
        .movement = { 2, -272, 0, -135, -171, 0, -135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 0, 0, 75, 355, 255, 1, 1 },
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
    },
    {
        .id = NPC_WORLD_CLUBBA3,
        .settings = &N(npcSettings_80243D68),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .extraAnimations = N(extraAnimationList_80243A54),
    },
};

StaticNpc N(npcGroup_802445A8)[] = {
    {
        .id = NPC_WORLD_CLUBBA4,
        .settings = &N(npcSettings_80243C94),
        .pos = { -326.0f, 210.0f, 80.0f },
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_80243D94),
        .yaw = 90,
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 2,
        .maxCoinBonus = 3,
        .movement = { -326, 210, 80, 0, 0, -32767, 0, 0, 0, 75, 355, 255, 1, 1 },
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
    },
    {
        .id = NPC_WORLD_CLUBBA5,
        .settings = &N(npcSettings_80243D68),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .extraAnimations = N(extraAnimationList_80243A54),
    },
};

NpcGroupList N(npcGroupList_80244988) = {
    NPC_GROUP(N(npcGroup_80243DE8), BATTLE_ID(15, 1, 0, 2)),
    NPC_GROUP(N(npcGroup_802441C8), BATTLE_ID(15, 1, 0, 2)),
    NPC_GROUP(N(npcGroup_802445A8), BATTLE_ID(15, 3, 0, 1)),
    {},
};

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

ApiStatus N(func_8024086C_C31D4C)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->functionTemp[0] < 30) && (enemy->varTable[0] == 0) && N(UnkNpcAIFunc26)(script)) {
        script->functionTemp[0] = 30;
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_800495A0(script, npcAISettings, territoryPtr);
        case 1:
            func_800496B8(script, npcAISettings, territoryPtr);
            break;
        case 2:
            base_UnkNpcAIFunc1(script, npcAISettings, territoryPtr);
        case 3:
            func_80049C04(script, npcAISettings, territoryPtr);
            break;
        case 10:
            func_80049E3C(script, npcAISettings, territoryPtr);
        case 11:
            func_80049ECC(script, npcAISettings, territoryPtr);
            break;
        case 12:
            func_80049F7C(script, npcAISettings, territoryPtr);
        case 13:
            func_8004A124(script, npcAISettings, territoryPtr);
            break;
        case 14:
            func_8004A3E8(script, npcAISettings, territoryPtr);
            break;
        case 30:
            N(UnkNpcAIFunc6)(script);
        case 31:
            N(UnkNpcAIFunc7)(script);
            if (script->functionTemp[0] != 32) {
                break;
            }
        case 32:
            N(UnkNpcAIFunc8)(script);
            if (script->functionTemp[0] != 33) {
                break;
            }
        case 33:
            N(UnkNpcAIFunc5)(script);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_802416B4_C32B94)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc24)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(UnkNpcAIFunc25)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(UnkFunc15)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 15:
            N(UnkFunc16)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_802419B0_C32E90)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->functionTemp[0] < 30) && (enemy->varTable[0] == 0) && N(UnkNpcAIFunc26)(script)) {
        script->functionTemp[0] = 30;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc24)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(UnkNpcAIFunc25)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(UnkFunc15)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 30:
            N(UnkNpcAIFunc6)(script);
        case 31:
            N(UnkNpcAIFunc7)(script);
            if (script->functionTemp[0] != 32) {
                break;
            }
        case 32:
            N(UnkNpcAIFunc8)(script);
            if (script->functionTemp[0] != 33) {
                break;
            }
        case 33:
            N(UnkNpcAIFunc5)(script);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}

void N(func_80241C7C_C3315C)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (npc->duration == 1) {
        npc->currentAnim.w = enemy->animList[12];
    } else if (npc->duration <= 0) {
        npc->currentAnim.w = enemy->animList[10];
        npc->duration = 0;
        script->functionTemp[0] = 1;
    }
}

void N(func_80241D04_C331E4)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    PlayerData* playerData = get_player_data();
    s32 phi_s2 = FALSE;
    s32 var;
    f32 posX, posZ;

    if (func_800490B4(territory, enemy, 80.0f, 0.0f, 0)) {
        if ((gPlayerStatusPtr->actionState ==  2) || (gPlayerStatusPtr->actionState == 26) ||
            (gPlayerStatusPtr->actionState ==  3) || (gPlayerStatusPtr->actionState == 14) ||
            (gPlayerStatusPtr->actionState == 16) || (gPlayerStatusPtr->actionState == 11) ||
            (gPlayerStatusPtr->actionState == 10) || (gPlayerStatusPtr->actionState == 18) ||
            (gPlayerStatusPtr->actionState == 19) || (gPlayerStatusPtr->actionState == 37)) {
            phi_s2 = TRUE;
        }

        if (playerData->currentPartner == 2) {
            if (gPartnerActionStatus.actionState.b[0] == playerData->currentPartner) {
                phi_s2 = TRUE;
            }
        }
    }

    if (((playerData->currentPartner == 1) && (gPartnerActionStatus.actionState.b[0] != 0)) ||
        ((playerData->currentPartner == 3) && (gPartnerActionStatus.actionState.b[0] == 2))) {
        posX = npc->pos.x;
        posZ = npc->pos.z;
        add_vec2D_polar(&posX, &posZ, 0.0f, npc->yaw);
        if (dist2D(posX, posZ, wPartnerNpc->pos.x, wPartnerNpc->pos.z) <= 80.0f) {
            phi_s2 = TRUE;
        }
    }

    if (phi_s2) {
        ai_enemy_play_sound(npc, 0xB000000E, 0);
        npc->currentAnim.w = enemy->animList[11];
        npc->duration = 10;
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
        ai_enemy_play_sound(npc, 0x2F4, 0x200000);
        script->functionTemp[0] = 2;
    }

    npc->duration++;
    if (npc->duration == 27) {
        ai_enemy_play_sound(npc, 0xB000000C, 0);
    } else if (npc->duration == 57) {
        ai_enemy_play_sound(npc, 0xB000000D, 0);
    } else if (npc->duration == 59) {
        npc->currentAnim.w = enemy->animList[12];
    } else if (npc->duration == 60) {
        npc->currentAnim.w = enemy->animList[10];
        npc->duration = 0;
    }
}

void N(func_80241FBC_C3349C)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->duration = 1;
        enemy->varTable[7] = 40;
        script->functionTemp[0] = 3;
    }
}

void N(func_80242020_C33500)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle((npc->yaw + rand_int(180)) - 90.0f);
    npc->currentAnim.w = enemy->animList[0];
    script->functionTemp[1] = (rand_int(1000) % 2) + 2;
    script->functionTemp[0] = 4;
}

void N(func_802420C8_C335A8)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->functionTemp[0] = 12;
        return;
    }

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            return;
        }

        var = enemy->varTable[7];
        if (var == 40) {
            npc->duration = 20;
            script->functionTemp[0] = var;
        } else if (var == 50) {
            npc->duration = 25;
            script->functionTemp[0] = var;
        }
    }
}

void N(func_80242200_C336E0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim.w = enemy->animList[1];
        if (enemy->territory->wander.moveSpeedOverride < 0) {
            npc->moveSpeed = aiSettings->moveSpeed;
        } else {
            npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
        }
        script->functionTemp[0] = 0x29;
    }
}

void N(func_802422AC_C3378C)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 var;

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->functionTemp[0] = 12;
    } else if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x,
                      enemy->territory->wander.point.z) <= npc->moveSpeed) {
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 15;
        enemy->varTable[7] = 50;
        script->functionTemp[0] = 3;
    } else if (npc->turnAroundYawAdjustment == 0) {
        var = npc->yaw;
        func_8004A784(npc, 5.0f, &var, 0, 0, 0);
        npc->yaw = var;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

void N(func_80242424_C33904)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->turnAroundYawAdjustment == 0) {
        npc->duration--;
        if (npc->duration <= 0) {
            npc->duration = 0;
            script->functionTemp[0] = 0;
        }
    }
}

ApiStatus N(func_80242480_C33960)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 40.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 30;
        npc->currentAnim.w = enemy->animList[10];
        npc->flags &= ~0x800;
        enemy->varTable[0] = 0;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 40;
            npc->currentAnim.w = enemy->animList[0];
        }
        enemy->unk_B0 &= ~4;
    }

    if (((u32)script->functionTemp[0] - 10 < 20) && (enemy->varTable[0] == 0) && N(UnkNpcAIFunc26)(script)) {
        script->functionTemp[0] = 30;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(func_80241C7C_C3315C)(script, npcAISettings, territoryPtr);
            break;
        case 1:
            N(func_80241D04_C331E4)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(func_80241FBC_C3349C)(script, npcAISettings, territoryPtr);
            break;
        case 3:
            N(func_80242020_C33500)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_802420C8_C335A8)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            func_80049F7C(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                break;
            }
        case 13:
            func_8004A124(script, npcAISettings, territoryPtr);
            break;
        case 14:
            func_8004A3E8(script, npcAISettings, territoryPtr);
            npc->duration = 15;
            enemy->varTable[7] = 40;
            script->functionTemp[0] = 3;
            break;
        case 30:
            N(UnkNpcAIFunc6)(script);
            if (script->functionTemp[0] != 31) {
                break;
            }
        case 31:
            N(UnkNpcAIFunc7)(script);
            if (script->functionTemp[0] != 32) {
                break;
            }
        case 32:
            N(UnkNpcAIFunc8)(script);
            break;
        case 33:
            N(UnkNpcAIFunc5)(script);
            break;
        case 40:
            N(func_80242200_C336E0)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 41) {
                break;
            }
        case 41:
            N(func_802422AC_C3378C)(script, npcAISettings, territoryPtr);
            break;
        case 50:
            N(func_80242424_C33904)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}
