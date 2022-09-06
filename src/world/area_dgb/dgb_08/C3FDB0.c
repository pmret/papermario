#include "dgb_08.h"
#include "message_ids.h"
#include "sprite.h"
#include "world/partners.h"
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

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_08_tattle },
};

EvtScript N(80243CF0) = {
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

EvtScript N(exitDoubleDoor_80243D90) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
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

EvtScript N(exitDoubleDoor_80243E44) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
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

EvtScript N(enterDoubleDoor_80243EF8) = {
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

EvtScript N(main) = {
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
    .alertOffsetDist = 90.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.9f,
    .chaseTurnRate= 180,
    .chaseUpdateInterval = 2,
    .chaseRadius = 170.0f,
    .chaseOffsetDist = 90.0f,
    .unk_AI_2C = 1,
};

EvtScript N(80244130) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAI_80244100)))
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

EvtScript N(802441D4) = {
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
    .alertOffsetDist = 65.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 90,
    .chaseUpdateInterval = 12,
    .chaseRadius = 110.0f,
    .chaseOffsetDist = 90.0f,
    .unk_AI_2C = 3,
};

EvtScript N(npcAI_802442F0) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(N(WanderMeleeAI_Main), EVT_PTR(N(npcAISettings_802442C0)))
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

EvtScript N(npcAI_8024438C) = {
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

NpcSettings N(npcSettings_80244434) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_8024438C),
    .onDefeat = &N(802441D4),
    .level = 13,
    .unk_2A = 8,
};

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

EvtScript N(80244478) = {
    EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_8000000 | NPC_FLAG_10000000 | NPC_FLAG_20000000)), TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING)), TRUE)
    EVT_RETURN
    EVT_END
};

NpcAISettings N(npcAISettings_802444B4) = {
    .moveSpeed = 1.5f,
    .moveTime = 90,
    .waitTime = 30,
    .alertRadius = 240.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 5.3f,
    .chaseTurnRate= 180,
    .chaseUpdateInterval = 1,
    .chaseRadius = 240.0f,
    .unk_AI_2C = 1,
};

extern const char N(dgb_00_name_hack)[];

EvtScript N(npcAI_802444E4) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(SentinelAI_Main), EVT_PTR(N(npcAISettings_802444B4)))
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
    EVT_SET_GROUP(EVT_GROUP_00)
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

EvtScript N(8024490C) = {
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

EvtScript N(80244998) = {
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

EvtScript N(idle_80244A54) = {
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

EvtScript N(80244D08) = {
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

EvtScript N(npcAI_80244D7C) = {
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
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAI_80244100)))
    EVT_RETURN
    EVT_END
};

extern const char N(dgb_01_name_hack)[];

EvtScript N(defeat_80244E58) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_01_name_hack)), 2)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80244E94) = {
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
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
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
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
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
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
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

EvtScript N(idle_80246210) = {
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

EvtScript N(interact_80246310) = {
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

EvtScript N(init_802464C4) = {
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
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_200000 | NPC_FLAG_400000,
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

EvtScript N(idle_80246718) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80246728) = {
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

EvtScript N(802469E0) = {
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

#include "world/common/enemy/WanderMeleeAI.inc.c"

#define AI_SENTINEL_FIRST_NPC 7
#define AI_SENTINEL_LAST_NPC  9
#include "world/common/enemy/SentinelAI.inc.c"

#include "world/common/UnkFunc1.inc.c"

ApiStatus N(func_80243B98_C43948)(Evt* script, s32 isInitialCall) {
    if (get_enemy_safe(9) != 0) {
        Enemy* enemy = get_enemy(9);
        enemy->territory->wander.point.x = 2;
        enemy->territory->wander.point.y = -450;
        enemy->territory->wander.point.z = 0;
        enemy->territory->wander.wanderSizeX = 175;
        enemy->territory->wander.wanderSizeZ = 300;
        enemy->territory->wander.moveSpeedOverride = 0;
        enemy->territory->wander.wanderShape = 175;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80243C10_C439C0)(Evt* script, s32 isInitialCall) {
    if (get_enemy_safe(9)) {
        Enemy* enemy = get_enemy(9);
        enemy->aiFlags |= 0x80;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80243C50_C43A00)(Evt* script, s32 isInitialCall) {
    ai_enemy_play_sound(get_npc_unsafe(script->owner1.enemy->npcID), SOUND_32F, 0);
    return ApiStatus_DONE2;
}

const char N(dgb_00_name_hack)[] = "dgb_00";
const char N(dgb_01_name_hack)[] = "dgb_01";
