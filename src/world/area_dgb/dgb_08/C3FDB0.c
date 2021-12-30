#include "dgb_08.h"
#include "message_ids.h"
#include "sprite/npc/sentinel.h"
#include "sprite/npc/world_clubba.h"
#include "sprite/npc/world_tubba.h"

enum {
    NPC_WORLD_CLUBBA7,
    NPC_WORLD_CLUBBA0,
    NPC_WORLD_CLUBBA1,
    NPC_WORLD_CLUBBA2,
    NPC_WORLD_CLUBBA3,
    NPC_WORLD_CLUBBA4,
    NPC_WORLD_CLUBBA5,
    NPC_SENTINEL0,
    NPC_SENTINEL1,
    NPC_WORLD_TUBBA,
    NPC_WORLD_CLUBBA6 = 11,
};

EntryList N(entryList) = {
    { -575.0f,   0.0f, 180.0f, 90.0f },
    { -575.0f, 210.0f, 180.0f, 90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_08_tattle },
};

EvtSource N(80243CF0) = {
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

static s32 N(pad_3D88)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitDoubleDoor_80243D90) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 14)
    EVT_SET(EVT_VAR(2), 23)
    EVT_SET(EVT_VAR(3), 25)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 2)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_80243E44) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 1)
    EVT_SET(EVT_VAR(1), 18)
    EVT_SET(EVT_VAR(2), 18)
    EVT_SET(EVT_VAR(3), 20)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 4)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

const s32 N(pad_XXXX)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(enterDoubleDoor_80243EF8) = {
    EVT_CALL(UseDoorSounds, 3)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_VAR(2), 23)
            EVT_SET(EVT_VAR(3), 25)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(1)
            EVT_SET(EVT_VAR(2), 18)
            EVT_SET(EVT_VAR(3), 20)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-28)
            EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80246958)))
        EVT_CASE_LT(-16)
            EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_802469AC)))
        EVT_CASE_LT(60)
            EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_802469C4)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(802469E0))
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243D90), TRIGGER_WALL_PRESS_A, 14, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243E44), TRIGGER_WALL_PRESS_A, 18, 1, 0)
    EVT_EXEC(N(80243CF0))
    EVT_EXEC(N(enterDoubleDoor_80243EF8))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_40FC) = {
    0x00000000,
};

NpcAISettings N(npcAI_80244100) = {
    .moveSpeed = 4.5f,
    .alertRadius = 170.0f,
    .unk_10 = { .f = 90.0f },
    .unk_14 = 1,
    .chaseSpeed = 3.9f,
    .unk_1C = { .s = 180 },
    .unk_20 = 2,
    .chaseRadius = 170.0f,
    .unk_28 = { .f = 90.0f },
    .unk_2C = 1,
};

EvtSource N(80244130) = {
    EVT_CALL(N(func_80240B94_C40944), EVT_PTR(N(npcAI_80244100)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80244150) = {
    .height = 90,
    .radius = 65,
    .ai = &N(80244130),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_8024417C) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_802441A8) = {
    .height = 24,
    .radius = 24,
    .level = 13,
};

EvtSource N(802441D4) = {
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

s32 N(extraAnimationList_80244290)[] = {
    NPC_ANIM_world_clubba_Palette_00_Anim_0,
    NPC_ANIM_world_clubba_Palette_00_Anim_2,
    NPC_ANIM_world_clubba_Palette_00_Anim_3,
    NPC_ANIM_world_clubba_Palette_00_Anim_4,
    NPC_ANIM_world_clubba_Palette_00_Anim_C,
    NPC_ANIM_world_clubba_Palette_00_Anim_7,
    NPC_ANIM_world_clubba_Palette_00_Anim_8,
    NPC_ANIM_world_clubba_Palette_00_Anim_11,
    NPC_ANIM_world_clubba_Palette_00_Anim_12,
    ANIM_END,
};

s32 N(extraAnimationList_802442B8)[] = {
    NPC_ANIM_world_clubba_Palette_00_Anim_0,
    ANIM_END,
};

NpcAISettings N(npcAISettings_802442C0) = {
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

EvtSource N(npcAI_802442F0) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(N(func_802414AC_C4125C), EVT_PTR(N(npcAISettings_802442C0)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80244360) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_802442F0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

EvtSource N(npcAI_8024438C) = {
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

NpcSettings N(npcSettings_80244434) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_8024438C),
    .onDefeat = &N(802441D4),
    .level = 13,
    .unk_2A = 8,
};

f32 N(D_80244460_C44210)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

EvtSource N(80244478) = {
    EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_8000000 | NPC_FLAG_10000000 | NPC_FLAG_20000000)), TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT)), TRUE)
    EVT_RETURN
    EVT_END
};

NpcAISettings N(npcAISettings_802444B4) = {
    .moveSpeed = 1.5f,
    .moveTime = 90,
    .waitTime = 30,
    .alertRadius = 240.0f,
    .unk_14 = 1,
    .chaseSpeed = 5.3f,
    .unk_1C = { .s = 180 },
    .unk_20 = 1,
    .chaseRadius = 240.0f,
    .unk_2C = 1,
};

const char N(dgb_00_name_hack)[];

EvtSource N(npcAI_802444E4) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(func_802438F0_C436A0), EVT_PTR(N(npcAISettings_802444B4)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(2)
    EVT_LABEL(20)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(4), EVT_VAR(2))
    EVT_CALL(GetPlayerActionState, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(func_802D2B6C)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_SET_GROUP(0)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 20)
    EVT_ADD(EVT_VAR(2), 2)
    EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(func_80045838, -1, 759, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_sentinel_Palette_00_Anim_8)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetPlayerAnimation, ANIM_80017)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(func_80045838, -1, 1838, 0)
    EVT_THREAD
        EVT_LOOP(100)
            EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 1)
            EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 1)
            EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x108)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(30)
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_00_name_hack)), 2)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024490C) = {
    EVT_CALL(GetOwnerEncounterTrigger, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(6)
            EVT_CALL(GetSelfAnimationFromTable, 7, EVT_VAR(0))
            EVT_EXEC_WAIT(0x800936DC)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(80244998) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802449FC) = {
    .height = 38,
    .radius = 32,
    .otherAI = &N(80244478),
    .ai = &N(npcAI_802444E4),
    .level = 99,
};

NpcSettings N(npcSettings_80244A28) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtSource N(idle_80244A54) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_IF_GE(EVT_VAR(0), -350)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_SET(EVT_SAVE_VAR(203), 8)
    EVT_SET(EVT_SAVE_VAR(0), -27)
    EVT_CALL(PlaySoundAtCollider, 18, 455, 0)
    EVT_CALL(MakeLerp, 0, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 18, EVT_VAR(0), 0, -1, 0)
        EVT_CALL(RotateModel, 20, EVT_VAR(0), 0, 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, 9, NPC_ANIM_world_tubba_Palette_00_Anim_A)
    EVT_CALL(SetNpcPos, NPC_SELF, -665, 210, 180)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_CALL(NpcMoveTo, NPC_SELF, -530, 180, 30)
    EVT_THREAD
        EVT_WAIT_FRAMES(20)
        EVT_CALL(MakeLerp, 80, 0, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 18, EVT_VAR(0), 0, -1, 0)
            EVT_CALL(RotateModel, 20, EVT_VAR(0), 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, 18, 456, 0)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_SELF, -500, 80, 10)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(npcAI_80244D7C)))
    EVT_RETURN
    EVT_END
};

EvtSource N(80244D08) = {
    EVT_LABEL(10)
    EVT_CALL(GetNpcPos, 9, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_IF_GT(EVT_VAR(1), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(N(func_80243B98_C43948))
    EVT_RETURN
    EVT_END
};

EvtSource N(npcAI_80244D7C) = {
    EVT_CALL(N(func_80243C10_C439C0))
    EVT_EXEC(N(80244D08))
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 4194304)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(2.0))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 4194304)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(N(func_80240B94_C40944), EVT_PTR(N(npcAI_80244100)))
    EVT_RETURN
    EVT_END
};

const char N(dgb_01_name_hack)[];

EvtSource N(defeat_80244E58) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_01_name_hack)), 2)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80244E94) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), -28)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_4)), TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(EVT_SAVE_VAR(0), -26)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_4)), TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.25), EVT_FIXED(1.25), EVT_FIXED(1.25))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80244E58)))
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_IF_NE(EVT_SAVE_VAR(203), 8)
                EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_4)), TRUE)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, -130, 0, 200)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_80244D7C)))
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_IF_NE(EVT_SAVE_VAR(203), 8)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80244A54)))
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, -130, 210, 80)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_80244D7C)))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_802450A0) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_8024417C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_40000 | NPC_FLAG_200000 | NPC_FLAG_NO_DROPS,
    .init = &N(init_80244E94),
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
    .movement = { 10, -400, 210, 80, -100, 210, 80, 100, 210, 80, 400, 210, 80, 820, 100, 80, 820, 100, 260, 400, 0, 260, 100, 0, 200, -100, 0, 175, -450, 0, 175, -32767, 150, 0, 175, 1450, 200, 1 },
    .animations = {
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_A,
        NPC_ANIM_world_tubba_Palette_00_Anim_D,
        NPC_ANIM_world_tubba_Palette_00_Anim_D,
        NPC_ANIM_world_tubba_Palette_00_Anim_19,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80245290)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_80244360),
        .pos = { -250.0f, 0.0f, 135.0f },
        .flags = NPC_FLAG_LOCK_ANIMS,
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
        .movement = { -250, 0, 135, 30, 0, -32767, 0, -250, 0, 135, 250, 0, 0, 1 },
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
        .extraAnimations = N(extraAnimationList_80244290),
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_80244434),
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
        .extraAnimations = N(extraAnimationList_802442B8),
    },
};

StaticNpc N(npcGroup_80245670)[] = {
    {
        .id = NPC_WORLD_CLUBBA2,
        .settings = &N(npcSettings_80244360),
        .pos = { 220.0f, 0.0f, 155.0f },
        .flags = NPC_FLAG_LOCK_ANIMS,
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
        .movement = { 220, 0, 155, 30, 0, -32767, 0, 220, 0, 155, 250, 0, 0, 1 },
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
        .extraAnimations = N(extraAnimationList_80244290),
    },
    {
        .id = NPC_WORLD_CLUBBA3,
        .settings = &N(npcSettings_80244434),
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
        .extraAnimations = N(extraAnimationList_802442B8),
    },
};

StaticNpc N(npcGroup_80245A50)[] = {
    {
        .id = NPC_WORLD_CLUBBA4,
        .settings = &N(npcSettings_80244360),
        .pos = { 825.0f, 100.0f, 200.0f },
        .flags = NPC_FLAG_LOCK_ANIMS,
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
        .movement = { 825, 100, 200, 25, 0, -32767, 0, 825, 100, 200, 150, 0, 0, 1 },
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
        .extraAnimations = N(extraAnimationList_80244290),
    },
    {
        .id = NPC_WORLD_CLUBBA5,
        .settings = &N(npcSettings_80244434),
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
        .extraAnimations = N(extraAnimationList_802442B8),
    },
};

StaticNpc N(npcGroup_80245E30) = {
    .id = NPC_SENTINEL0,
    .settings = &N(npcSettings_802449FC),
    .pos = { 75.0f, 310.0f, 85.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 75, 310, 85, 30, 0, -32767, 0, 75, 0, 85, 250, 55, 1, 1 },
    .animations = {
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_2,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_5,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_8,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
    },
};

StaticNpc N(npcGroup_80246020) = {
    .id = NPC_SENTINEL1,
    .settings = &N(npcSettings_802449FC),
    .pos = { -451.0f, 310.0f, 81.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { -451, 310, 81, 30, 0, -32767, 0, -310, 0, 175, 250, 145, 1, 1 },
    .animations = {
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_2,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_5,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_8,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
    },
};

EvtSource N(idle_80246210) = {
    EVT_LABEL(0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_7)
    EVT_WAIT_FRAMES(30)
    EVT_LOOP(15)
        EVT_CALL(N(func_80243C50_C43A00))
        EVT_WAIT_FRAMES(60)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_C)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_7)
    EVT_WAIT_FRAMES(30)
    EVT_LOOP(5)
        EVT_CALL(N(func_80243C50_C43A00))
        EVT_WAIT_FRAMES(60)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_C)
    EVT_WAIT_FRAMES(15)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80246310) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_8)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2F1, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_2)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(GetNpcYaw, -1, EVT_VAR(0))
    EVT_ADD(EVT_VAR(0), 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, EVT_VAR(0), 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetNpcYaw, -1, EVT_VAR(0))
    EVT_ADD(EVT_VAR(0), 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, EVT_VAR(0), 0)
    EVT_WAIT_FRAMES(25)
    EVT_CALL(GetNpcYaw, -1, EVT_VAR(0))
    EVT_ADD(EVT_VAR(0), 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, EVT_VAR(0), 0)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_5, NPC_ANIM_world_clubba_Palette_00_Anim_2, 0, MESSAGE_ID(0x0E, 0x00F2))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_6)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_7)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802464C4) = {
    EVT_CALL(SetNpcCollisionSize, -1, 36, 30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_7)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80246310)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80246210)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80246528) = {
    .id = NPC_WORLD_CLUBBA6,
    .settings = &N(npcSettings_80244A28),
    .pos = { 426.0f, 0.0f, 38.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000 | NPC_FLAG_400000,
    .init = &N(init_802464C4),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
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
    .tattle = MESSAGE_ID(0x1A, 0x00B6),
};

EvtSource N(idle_80246718) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80246728) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80246718)))
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80246768) = {
    .id = NPC_WORLD_CLUBBA7,
    .settings = &N(npcSettings_80244360),
    .pos = { -250.0f, 0.0f, 135.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80246728),
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
    .movement = { -250, 0, 135, 30, 0, -32767, 0, -250, 0, 135, 250, 0, 0, 1 },
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
    .extraAnimations = N(extraAnimationList_80244290),
};

NpcGroupList N(npcGroupList_80246958) = {
    NPC_GROUP(N(npcGroup_80246768), BATTLE_ID(15, 2, 0, 3)),
    NPC_GROUP(N(npcGroup_80245290), BATTLE_ID(15, 2, 0, 3)),
    NPC_GROUP(N(npcGroup_80245670), BATTLE_ID(15, 2, 0, 3)),
    NPC_GROUP(N(npcGroup_80245A50), BATTLE_ID(15, 3, 0, 3)),
    NPC_GROUP(N(npcGroup_80245E30), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246020), BATTLE_ID(0, 0, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_802469AC) = {
    NPC_GROUP(N(npcGroup_802450A0), BATTLE_ID(15, 4, 0, 1)),
    {},
};

NpcGroupList N(npcGroupList_802469C4) = {
    NPC_GROUP(N(npcGroup_80246528), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_69DC) = {
    0x00000000,
};

EvtSource N(802469E0) = {
    EVT_RETURN
    EVT_END
};

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

ApiStatus N(func_80240B94_C40944)(Evt* script, s32 isInitialCall) {
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

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

ApiStatus N(func_802414AC_C4125C)(Evt* script, s32 isInitialCall) {
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

#include "world/common/UnkNpcAIFunc23.inc.c"

#include "world/common/UnkNpcAIFunc35.inc.c"

#include "world/common/UnkNpcAIFunc1_copy.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_802423B4_C42164)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80244460_C44210)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_80242A6C_C4281C)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = evt_get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
        case 1:
            N(UnkNpcAIFunc35)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1_copy)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_802423B4_C42164)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}

void N(func_80242C58_C42A08)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f0;
    f32 phi_f20;

    npc->duration--;
    if (npc->duration <= 0) {
        npc->flags &= ~0x00200000;
        npc->duration = aiSettings->unk_20 / 2 + rand_int(aiSettings->unk_20 / 2 + 1);
        npc->currentAnim.w = enemy->animList[8];
        npc->moveSpeed = aiSettings->chaseSpeed;
        phi_f20 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        temp_f0 = get_clamped_angle_diff(npc->yaw, phi_f20);
        if (aiSettings->unk_1C.s < fabsf(temp_f0)) {
            phi_f20 = npc->yaw;
            if (temp_f0 < 0.0f) {
                phi_f20 += -aiSettings->unk_1C.s;
            } else {
                phi_f20 += aiSettings->unk_1C.s;
            }
        }
        npc->yaw = clamp_angle(phi_f20);
        script->functionTemp[0] = 13;
    }
}

void N(func_80242DB0_C42B60)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                   gPlayerStatusPtr->position.z) <= (npc->moveSpeed * 2.5)) {
            npc->duration = 0;
            script->functionTemp[0] = 14;
        } else {
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags |= 0x200000;
                script->functionTemp[0] = 12;
            }
        }
    } else {
        script->functionTemp[0] = 16;
    }

}

void N(func_80242EB4_C42C64)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    for (i = 7; i < 9; i++) {
        if ((i != npc->npcID) && (get_enemy(i)->varTable[0] & 0x100)) {
            return;
        }
    }

    enemy->varTable[0] |= 0x100;
    npc->pos.x = gPlayerStatusPtr->position.x;
    npc->pos.z = gPlayerStatusPtr->position.z;
    if (!(enemy->varTable[0] & 0x1000)) {
        enemy->varTable[0] |= 0x1000;
    }
    sfx_play_sound_at_position(0x80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    npc->duration = 0;
    script->functionTemp[0] = 15;
}

void N(func_80242F94_C42D44)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    s32 temp_f8_2;

    sfx_adjust_env_sound_pos(0x80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    if (!func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        enemy->varTable[0] &= ~0x100;
        npc->rotation.y = 0.0f;
        npc->flags &= ~0x00200000;
        script->functionTemp[0] = 16;
    } else {
        PlayerStatus** playerStatus = &gPlayerStatusPtr;

        npc->pos.x = gPlayerStatusPtr->position.x;
        npc->pos.z = gPlayerStatusPtr->position.z + 2.0f;
        npc->rotation.y += 25.0f;
        if (npc->rotation.y > 360.0) {
            npc->rotation.y -= 360.0;
        }
        temp_f8_2 = 255.0f - (cosine((s32)npc->rotation.y % 180) * 56.0f);
        func_802DE894(npc->spriteInstanceID, 6, temp_f8_2, temp_f8_2, temp_f8_2, 255, 0);

        posX = gPlayerStatusPtr->position.x;
        posY = gPlayerStatusPtr->position.y;
        posZ = gPlayerStatusPtr->position.z;
        posW = 1000.0f;
        npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
        if (fabsf(npc->pos.y - posY) > 24.0) {
            npc->pos.y -= 1.8;
        } else {
            npc->rotation.y = 0.0f;
            npc->flags &= ~0x00200000;
            if (gPartnerActionStatus.actionState.b[3]  != 9) {
                disable_player_input();
                partner_disable_input();
                npc->duration = 0;
                script->functionTemp[0] = 20;
            } else {
                script->functionTemp[0] = 16;
            }
        }
    }
}

void N(func_80243230_C42FE0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
    if (enemy->varTable[0] & 0x1000) {
        sfx_stop_sound(0x80000011);
        enemy->varTable[0] &= ~0x1000;
    }
    npc->currentAnim.w = enemy->animList[9];
    npc->duration = 20;
    script->functionTemp[0] = 17;
}

void N(func_802432E8_C43098)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 tmp = enemy->varTable[3];
    f32 temp_f20 = tmp / 100.0;
    s32 var;

    npc->pos.y += 2.5;
    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
    if (!(npc->pos.y < (posY + temp_f20))) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc->pos.y = posY + temp_f20;
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &var);
        npc->duration = 10;
        script->functionTemp[0] = 18;
    }
}

void N(filemenu_update_show_options_right_C43218)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = 30;
    }
}

void N(func_802434B0_C43260)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration++;
    if (npc->duration >= 3) {
        if (gPartnerActionStatus.actionState.b[3]  != 9) {
            npc->duration = 0;
            script->functionTemp[0] = 100;
        } else {
            enable_player_input();
            partner_enable_input();
            script->functionTemp[0] = 16;
        }
    }
}

void N(func_80243530_C432E0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    npc->flags &= ~0x00200000;
    npc->moveSpeed = 2.0 * aiSettings->moveSpeed;
    enemy->varTable[2] = 0;
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[1] = 0x1E;
}

void N(func_802435D8_C43388)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX = npc->pos.x;
    f32 posY = npc->pos.y;
    f32 posZ = npc->pos.z;
    f32 posW = 1000.0f;
    f32 temp_f26 = (f32)enemy->varTable[3] / 100.0;
    f32 temp_f24 = temp_f26 + (f32)((f32)enemy->varTable[7] / 100.0);
    f32 temp_f22 = (f32)enemy->varTable[1] / 100.0;
    f32 temp_f20 = sin_deg(enemy->varTable[2]);
    s32 var;
    s32 var2;

    if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
        npc->pos.y = posY + temp_f26 + (temp_f20 * temp_f22);
    } else {
        npc->pos.y = temp_f24 + (temp_f20 * temp_f22);
    }

    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 12);
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = aiSettings->unk_14;
        if (func_800490B4(territory, enemy, aiSettings->alertRadius * 0.5, aiSettings->unk_10.f * 0.5, 0)) {
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
            ai_enemy_play_sound(npc, 0x2F4, 0x200000);
            npc->moveToPos.y = npc->pos.y;
            script->functionTemp[0] = 12;
            return;
        }
    }

    script->functionTemp[1]--;
    if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        posW = dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        if (posW <= (2.0f * npc->moveSpeed)) {
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            script->functionTemp[0] = 2;
        }
    }
}

ApiStatus N(func_802438F0_C436A0)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = evt_get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 125.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        N(UnkFunc5)(npc, enemy, script, npcAISettings);
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, npcAISettings, territoryPtr);
            func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
        case 1:
            N(UnkNpcAIFunc35)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] == 12) {
                npc->duration = 6;
            }
            break;
        case 2:
            N(UnkNpcAIFunc1_copy)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] == 12) {
                npc->duration = 6;
            }
            break;
        case 12:
            N(func_80242C58_C42A08)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                break;
            }
        case 13:
            N(func_80242DB0_C42B60)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(func_80242EB4_C42C64)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 15) {
                break;
            }
        case 15:
            N(func_80242F94_C42D44)(script, npcAISettings, territoryPtr);
            break;
        case 16:
            N(func_80243230_C42FE0)(script, npcAISettings, territoryPtr);
        case 17:
            N(func_802432E8_C43098)(script, npcAISettings, territoryPtr);
            break;
        case 18:
            N(filemenu_update_show_options_right_C43218)(script, npcAISettings, territoryPtr);
            break;
        case 20:
            N(func_802434B0_C43260)(script, npcAISettings, territoryPtr);
            break;
        case 30:
            N(func_80243530_C432E0)(script, npcAISettings, territoryPtr);
        case 31:
            N(func_802435D8_C43388)(script, npcAISettings, territoryPtr);
    }

    return (script->functionTemp[0] == 100) * ApiStatus_DONE2;
}

#include "world/common/UnkFunc1.inc.c"

ApiStatus N(func_80243B98_C43948)(Evt* script, s32 isInitialCall) {
    if (get_enemy_safe(9) != 0) {
        Enemy* enemy = get_enemy(9);
        enemy->territory->wander.point.x = 2;
        enemy->territory->wander.point.y = -0x1C2;
        enemy->territory->wander.point.z = 0;
        enemy->territory->wander.wanderSizeX = 0xAF;
        enemy->territory->wander.wanderSizeZ = 0x12C;
        enemy->territory->wander.moveSpeedOverride = 0;
        enemy->territory->wander.wanderShape = 0xAF;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80243C10_C439C0)(Evt* script, s32 isInitialCall) {
    if (get_enemy_safe(9)) {
        Enemy* enemy = get_enemy(9);
        enemy->unk_B0 |= 0x80;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80243C50_C43A00)(Evt* script, s32 isInitialCall) {
    ai_enemy_play_sound(get_npc_unsafe(script->owner1.enemy->npcID), 0x32F, 0);
    return ApiStatus_DONE2;
}

const char N(dgb_00_name_hack)[] = "dgb_00";
const char N(dgb_01_name_hack)[] = "dgb_01";
