#include "dgb_03.h"
#include "sprite/npc/world_clubba.h"
#include "message_ids.h"
#include "entity.h"

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

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_03_tattle },
};

EvtScript N(80242870) = {
    EVT_SWITCH(GB_StoryProgress)
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

EvtScript N(exitDoubleDoor_80242910) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, 25)
    EVT_SET(LVar2, 36)
    EVT_SET(LVar3, 34)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_02"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_802429C4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 4)
    EVT_SET(LVar1, 21)
    EVT_SET(LVar2, 46)
    EVT_SET(LVar3, 44)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_09"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_80242A78) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 13)
    EVT_SET(LVar2, 29)
    EVT_SET(LVar3, 31)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_04"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_80242B2C) = EXIT_WALK_SCRIPT(26,  2, "dgb_13",  0);

EvtScript N(exitSingleDoor_80242B88) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(LVar0, 2)
    EVT_SET(LVar1, 33)
    EVT_SET(LVar2, 49)
    EVT_SET(LVar3, 1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_05"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_80242C3C) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 3)
    EVT_SET(LVar1, 17)
    EVT_SET(LVar2, 39)
    EVT_SET(LVar3, 41)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_14"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242CF0) = {
    EVT_BIND_TRIGGER(N(exitWalk_80242B2C), TRIGGER_FLOOR_ABOVE, 35, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterDoubleDoor_80242D1C) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(LVar2, 29)
            EVT_SET(LVar3, 31)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80242CF0))
        EVT_CASE_EQ(1)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(LVar2, 36)
            EVT_SET(LVar3, 34)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80242CF0))
        EVT_CASE_EQ(2)
            EVT_CALL(UseDoorSounds, 0)
            EVT_SET(LVar2, 49)
            EVT_SET(LVar3, 1)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(80242CF0))
        EVT_CASE_EQ(3)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(LVar2, 39)
            EVT_SET(LVar3, 41)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80242CF0))
        EVT_CASE_EQ(4)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(LVar2, 46)
            EVT_SET(LVar3, 44)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80242CF0))
        EVT_CASE_EQ(5)
            EVT_SET(LVar0, EVT_PTR(N(80242CF0)))
            EVT_EXEC(EnterWalkShort)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(itemList_80242F28)[] = {
    ITEM_TUBBA_CASTLE_KEY,
    ITEM_NONE,
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_IF_LT(GB_StoryProgress, -15)
        EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80244988)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80243608))
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80242910), TRIGGER_WALL_PRESS_A, 25, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802429C4), TRIGGER_WALL_PRESS_A, 21, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80242A78), TRIGGER_WALL_PRESS_A, 13, 1, 0)
    EVT_BIND_TRIGGER(N(exitSingleDoor_80242B88), TRIGGER_WALL_PRESS_A, 33, 1, 0)
    EVT_IF_EQ(GF_DGB03_UnlockedThirdFloor, 0)
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

EvtScript N(802430E0) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_LOOP(20)
        EVT_CALL(GetCurrentPartner, LVarA)
        EVT_IF_NE(LVarA, 0)
            EVT_SET(LVar8, -1)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(N(UnkFunc11), LVar9)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(LVar8, -1)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SetPlayerActionState, 20)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetCurrentPartner, LVarA)
    EVT_IF_NE(LVarA, 0)
        EVT_SET(LVar8, -1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 100, EVT_FLOAT(0.6))
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_GE(LVar6, LVar7)
            EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_ELSE
            EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_END_IF
        EVT_CALL(SetPlayerActionState, 20)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, LVar0)
        EVT_SET(LVar2, LVar7)
        EVT_SUB(LVar2, LVar6)
        EVT_ADD(LVar1, LVar2)
        EVT_CALL(MakeLerp, LVar0, LVar1, 100, 0)
        EVT_LOOP(0)
            EVT_CALL(SetPlayerActionState, 20)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(UnkFunc12))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetPlayerActionState, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, LVar6, LVar7, 100, 0)
    EVT_CALL(PlaySoundAtCollider, 27, 0x80000010, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 51, LVar0, 0, 0)
        EVT_CALL(UpdateColliderTransform, 27)
        EVT_CALL(UpdateColliderTransform, 28)
        EVT_CALL(UpdateColliderTransform, 29)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(StopSound, 0x80000010)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243470) = {
    EVT_IF_NE(GF_DGB03_PushedClock, 0)
        EVT_GOTO(90)
    EVT_END_IF
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, 48)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, 27)
    EVT_EXEC_WAIT(N(802430E0))
    EVT_LABEL(90)
    EVT_IF_NE(LVar8, -1)
        EVT_SET(GF_DGB03_PushedClockLeft, 0)
        EVT_SET(GF_DGB03_PushedClock, 1)
        EVT_UNBIND
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8024353C) = {
    EVT_IF_NE(GF_DGB03_PushedClock, 0)
        EVT_GOTO(90)
    EVT_END_IF
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, -48)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, 28)
    EVT_EXEC_WAIT(N(802430E0))
    EVT_LABEL(90)
    EVT_IF_NE(LVar8, -1)
        EVT_SET(GF_DGB03_PushedClockLeft, 1)
        EVT_SET(GF_DGB03_PushedClock, 1)
        EVT_UNBIND
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80243608) = {
    EVT_CALL(ParentColliderToModel, 27, 51)
    EVT_CALL(ParentColliderToModel, 28, 51)
    EVT_CALL(ParentColliderToModel, 29, 51)
    EVT_IF_EQ(GF_DGB03_PushedClock, 0)
        EVT_BIND_TRIGGER(N(80243470), TRIGGER_WALL_PUSH, 27, 1, 0)
        EVT_BIND_TRIGGER(N(8024353C), TRIGGER_WALL_PUSH, 28, 1, 0)
    EVT_ELSE
        EVT_IF_EQ(GF_DGB03_PushedClockLeft, 0)
            EVT_SET(LVar0, 48)
        EVT_ELSE
            EVT_SET(LVar0, -48)
        EVT_END_IF
        EVT_CALL(TranslateModel, 51, LVar0, 0, 0)
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

EvtScript N(80243740) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00D8), 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_TUBBA_CASTLE_KEY, LVar0)
    EVT_CALL(RemoveKeyItemAt, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_DGB03_UnlockedThirdFloor, 1)
    EVT_CALL(N(GetEntityPosition), MapVar(0), LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, 0x269, 0, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MapVar(0))
    EVT_CALL(N(SetEntityFlags100000))
    EVT_RESUME_GROUP(1)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(802438A8) = {
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80242C3C), TRIGGER_WALL_PRESS_A, 17, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_IF_EQ(GF_DGB03_UnlockedThirdFloor, 0)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), -355, 218, 75, 80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(802438A8)))
        EVT_SET(MapVar(0), LVar0)
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 0, 75, 100, 17, GF_DGB03_Item_StarPiece)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3964)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80243970) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
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
    ANIM_LIST_END,
};

MobileAISettings N(npcAISettings_80243A5C) = {
    .moveSpeed = 1.5f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 85.0f,
    .alertOffsetDist = 65.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 90,
    .chaseUpdateInterval = 12,
    .chaseRadius = 110.0f,
    .chaseOffsetDist = 90.0f,
    .unk_AI_2C = 3,
};

EvtScript N(npcAI_80243A8C) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(N(WanderMeleeAI_Main), EVT_PTR(N(npcAISettings_80243A5C)))
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

MobileAISettings N(npcAISettings_80243B28) = {
    .moveSpeed = 1.5f,
    .moveTime = 20,
    .waitTime = 30,
    .alertRadius = 85.0f,
    .alertOffsetDist = 65.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 90,
    .chaseUpdateInterval = 12,
    .chaseRadius = 110.0f,
    .chaseOffsetDist = 90.0f,
    .unk_AI_2C = 3,
};

EvtScript N(npcAI_80243B58) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(N(ClubbaPatrolAI_Main), EVT_PTR(N(npcAISettings_80243B28)))
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

MobileAISettings N(npcAISettings_80243BF4) = {
    .moveSpeed = 1.0f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 90,
    .chaseUpdateInterval = 15,
    .chaseRadius = 200.0f,
    .chaseOffsetDist = 160.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80243C24) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 10)
    EVT_CALL(SetSelfVar, 2, 14)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(N(ClubbaNappingAI_Main), EVT_PTR(N(npcAISettings_80243BF4)))
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

EvtScript N(npcAI_80243CC0) = {
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

NpcSettings N(npcSettings_80243D68) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_80243CC0),
    .onDefeat = &N(80243970),
    .level = 13,
    .actionFlags = 8,
};

EvtScript N(init_80243D94) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, 3)
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
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(3),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 2,
            .maxCoinBonus = 3,
        },
	.territory = { .temp = { 180, 0, -122, 40, 0, -32767, 0, 0, 0, 75, 355, 255, 1, 1 }},
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
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_80243D68),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(3),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 2,
            .maxCoinBonus = 3,
        },
	.territory = { .temp = { 2, -272, 0, -135, -171, 0, -135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 0, 0, 75, 355, 255, 1, 1 }},
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
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_WORLD_CLUBBA3,
        .settings = &N(npcSettings_80243D68),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_80243D94),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(3),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 2,
            .maxCoinBonus = 3,
        },
	.territory = { .temp = { -326, 210, 80, 0, 0, -32767, 0, 0, 0, 75, 355, 255, 1, 1 }},
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
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_WORLD_CLUBBA5,
        .settings = &N(npcSettings_80243D68),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
    NPC_GROUP(N(npcGroup_80243DE8), 0x0F01, 0x01),
    NPC_GROUP(N(npcGroup_802441C8), 0x0F01, 0x01),
    NPC_GROUP(N(npcGroup_802445A8), 0x0F03, 0x00),
    {},
};

#include "world/common/enemy/WanderMeleeAI.inc.c"

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

#include "world/common/enemy/ClubbaPatrolAI.inc.c"

#include "world/common/enemy/ClubbaNappingAI.inc.c"
