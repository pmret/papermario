#include "dgb_09.h"
#include "message_ids.h"
#include "sprite/npc/sentinel.h"
#include "sprite/npc/world_clubba.h"

extern Npc* wPartnerNpc;

enum {
    NPC_WORLD_CLUBBA0,
    NPC_WORLD_CLUBBA1,
    NPC_WORLD_CLUBBA2,
    NPC_WORLD_CLUBBA3,
    NPC_SENTINEL,
};

EntryList N(entryList) = {
    { -567.0f, 0.0f, 180.0f,  90.0f },
    {  567.0f, 0.0f, 180.0f, 270.0f },
    { -450.0f, 0.0f,  90.0f, 180.0f },
    {  300.0f, 0.0f,  90.0f, 180.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_09_tattle },
};

EvtSource N(80243880) = SCRIPT({
    match EVT_STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        } else {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
    }
});

static s32 N(pad_3918)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitDoubleDoor_80243920) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    EVT_VAR(0) = 0;
    EVT_VAR(1) = 5;
    EVT_VAR(2) = 10;
    EVT_VAR(3) = 12;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_03", 4);
    sleep 100;
});

EvtSource N(exitDoubleDoor_802439D4) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    EVT_VAR(0) = 1;
    EVT_VAR(1) = 17;
    EVT_VAR(2) = 17;
    EVT_VAR(3) = 15;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_01", 3);
    sleep 100;
});

EvtSource N(exitSingleDoor_80243A88) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(0);
    EVT_VAR(0) = 2;
    EVT_VAR(1) = 9;
    EVT_VAR(2) = 20;
    EVT_VAR(3) = 1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("dgb_12", 0);
    sleep 100;
});

EvtSource N(exitWalk_80243B3C) = EXIT_WALK_SCRIPT(40,  3, "dgb_10",  0);

EvtSource N(80243B98) = SCRIPT({
    bind N(exitWalk_80243B3C) TRIGGER_FLOOR_ABOVE 11;
});

EvtSource N(enterWalk_80243BC4) = SCRIPT({
    GetEntryID(EVT_VAR(0));
    match EVT_VAR(0) {
        == 0 {
            UseDoorSounds(3);
            EVT_VAR(2) = 10;
            EVT_VAR(3) = 12;
            await EnterDoubleDoor;
            spawn N(80243B98);
        }
        == 1 {
            UseDoorSounds(3);
            EVT_VAR(2) = 17;
            EVT_VAR(3) = 15;
            await EnterDoubleDoor;
            spawn N(80243B98);
        }
        == 2 {
            UseDoorSounds(0);
            EVT_VAR(2) = 20;
            EVT_VAR(3) = 1;
            await EnterSingleDoor;
            spawn N(80243B98);
        }
        == 3 {
            EVT_VAR(0) = N(80243B98);
            spawn EnterWalk;
            sleep 1;
        }
    }
});

EvtSource N(main) = SCRIPT({
    EVT_WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    if (EVT_STORY_PROGRESS < STORY_CH3_STAR_SPIRIT_RESCUED) {
        MakeNpcs(1, N(npcGroupList_8024533C));
    }
    spawn N(80243F6C);
    bind N(exitDoubleDoor_80243920) TRIGGER_WALL_PRESS_A 5;
    bind N(exitDoubleDoor_802439D4) TRIGGER_WALL_PRESS_A 17;
    bind N(exitSingleDoor_80243A88) TRIGGER_WALL_PRESS_A 9;
    spawn N(80243880);
    spawn N(enterWalk_80243BC4);
});

static s32 N(pad_3E4C) = {
    0x00000000,
};

Vec4f N(triggerCoord_80243E50) = { 300.0f, 0.0f, 88.0f, 0.0f };

EvtSource N(80243E60) = SCRIPT({
    sleep 2;
    PlayEffect(0x42, 1, 25, 3, 1, 10, 30, 0, 0, 0, 0, 0, 0, 0);
    loop 10 {
        EnableModel(29, 0);
        EnableModel(25, 1);
        sleep 1;
        EnableModel(29, 1);
        EnableModel(25, 0);
        sleep 1;
    }
    ModifyColliderFlags(0, 13, 0x7FFFFE00);
    EVT_SAVE_FLAG(1051) = 1;
    unbind;
});

EvtSource N(80243F6C) = SCRIPT({
    if (EVT_SAVE_FLAG(1051) == 0) {
        bind N(80243E60) TRIGGER_POINT_BOMB N(triggerCoord_80243E50);
        EnableModel(29, 0);
    } else {
        EnableModel(25, 0);
        ModifyColliderFlags(0, 13, 0x7FFFFE00);
    }
});

static s32 N(pad_3FF8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(80244000) = SCRIPT({
    GetBattleOutcome(EVT_VAR(0));
    match EVT_VAR(0) {
        == 0 {
            RemoveNpc(NPC_SELF);
        }
        == 2 {
            SetNpcPos(NPC_SELF, 0, -1000, 0);
            func_80045900(1);
        }
        == 3 {
            SetEnemyFlagBits(-1, 16, 1);
            RemoveNpc(NPC_SELF);
        }
    }
});

s32 N(extraAnimationList_802440BC)[] = {
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

s32 N(extraAnimationList_802440E4)[] = {
    NPC_ANIM_world_clubba_Palette_00_Anim_0,
    ANIM_END,
};

NpcAISettings N(npcAISettings_802440EC) = {
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

EvtSource N(npcAI_8024411C) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(1, 5);
    SetSelfVar(2, 8);
    SetSelfVar(3, 12);
    N(func_8024061C_C471FC)(N(npcAISettings_802440EC));
});

NpcSettings N(npcSettings_8024418C) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_8024411C),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcAISettings N(npcAISettings_802441B8) = {
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

EvtSource N(npcAI_802441E8) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(1, 10);
    SetSelfVar(2, 14);
    SetSelfVar(3, 18);
    N(func_802410D4_C47CB4)(N(npcAISettings_802441B8));
});

NpcSettings N(npcSettings_80244258) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_802441E8),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

EvtSource N(npcAI_80244284) = SCRIPT({
    EnableNpcShadow(NPC_SELF, FALSE);
    SetSelfVar(0, 4);
    SetSelfVar(1, 32);
    SetSelfVar(2, 50);
    SetSelfVar(3, 32);
    SetSelfVar(4, 3);
    SetSelfVar(15, 8389);
    N(UnkFunc7)();
});

NpcSettings N(npcSettings_8024432C) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_80244284),
    .onDefeat = &N(80244000),
    .level = 13,
    .unk_2A = 8,
};

f32 N(D_80244358_C4AF38)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

EvtSource N(80244370) = SCRIPT({
    SetSelfEnemyFlagBits(((0x00100000 | 0x01000000 | 0x02000000 | 0x04000000 | 0x08000000 | 0x10000000 | 0x20000000)), TRUE);
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT)), TRUE);
});

NpcAISettings N(npcAISettings_802443AC) = {
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

EvtSource N(npcAI_802443DC) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(5, -650);
    SetSelfVar(6, 30);
    SetSelfVar(1, 600);
    N(func_80243578_C4A158)(N(npcAISettings_802443AC));
    DisablePlayerInput(TRUE);
    sleep 2;
20:
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    GetNpcPos(NPC_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
    SetNpcPos(NPC_SELF, EVT_VAR(0), EVT_VAR(4), EVT_VAR(2));
    GetPlayerActionState(EVT_VAR(0));
    if (EVT_VAR(0) != 0) {
        sleep 1;
        goto 20;
    }
    DisablePlayerPhysics(TRUE);
    func_802D2B6C();
    DisablePartnerAI(0);
    group 0;
    SetTimeFreezeMode(1);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(1) += 20;
    EVT_VAR(2) += 2;
    SetNpcPos(NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    func_80045838(-1, 759, 0);
    SetNpcAnimation(NPC_SELF, NPC_ANIM_sentinel_Palette_00_Anim_8);
    sleep 10;
    SetPlayerAnimation(ANIM_80017);
    sleep 10;
    func_80045838(-1, 1838, 0);
    spawn {
        loop 100 {
            GetNpcPos(NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            EVT_VAR(1) += 1;
            SetNpcPos(NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            EVT_VAR(1) += 1;
            SetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            sleep 1;
        }
    }
    spawn {
        SetNpcAnimation(NPC_PARTNER, 0x108);
        GetNpcPos(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        NpcJump0(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10);
        GetNpcPos(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        NpcJump0(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10);
        GetNpcPos(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        NpcJump0(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10);
        GetNpcPos(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        NpcJump0(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10);
    }
    sleep 30;
    GotoMap(N(dgb_00_name_hack), 2);
    sleep 100;
});

EvtSource N(80244804) = SCRIPT({
    GetOwnerEncounterTrigger(EVT_VAR(0));
    match EVT_VAR(0) {
        == 1, 2, 4, 6 {
            GetSelfAnimationFromTable(7, EVT_VAR(0));
            await 0x800936DC;
        }
    }
});

EvtSource N(80244890) = SCRIPT({
    GetBattleOutcome(EVT_VAR(0));
    match EVT_VAR(0) {
        == 0 {
            DoNpcDefeat();
        }
        == 1 {}
        == 2 {
        }
    }
});

NpcSettings N(npcSettings_802448F4) = {
    .height = 38,
    .radius = 32,
    .otherAI = &N(80244370),
    .ai = &N(npcAI_802443DC),
    .level = 99,
};

StaticNpc N(npcGroup_80244920)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_8024418C),
        .pos = { -350.0f, 0.0f, 180.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .yaw = 270,
        .dropFlags = 0x80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 2,
        .maxCoinBonus = 3,
        .movement = { -350, 0, 180, 40, 0, -32767, 0, 0, 0, 50, 600, 250, 1, 1 },
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
        .extraAnimations = N(extraAnimationList_802440BC),
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_8024432C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .dropFlags = 0x80,
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
        .extraAnimations = N(extraAnimationList_802440E4),
    },
};

EvtSource N(init_80244D00) = SCRIPT({
    GetEntryID(EVT_VAR(0));
    if (EVT_VAR(0) == 3) {
        SetNpcPos(NPC_SELF, 240, 0, 88);
        InterpNpcYaw(NPC_SELF, 270, 0);
    }
});

StaticNpc N(npcGroup_80244D6C)[] = {
    {
        .id = NPC_WORLD_CLUBBA2,
        .settings = &N(npcSettings_80244258),
        .pos = { 310.0f, 0.0f, 88.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_80244D00),
        .yaw = 270,
        .dropFlags = 0x80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 2,
        .maxCoinBonus = 3,
        .movement = { 310, 0, 88, 40, 0, -32767, 0, 0, 0, 50, 600, 250, 1, 1 },
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
        .extraAnimations = N(extraAnimationList_802440BC),
    },
    {
        .id = NPC_WORLD_CLUBBA3,
        .settings = &N(npcSettings_8024432C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .dropFlags = 0x80,
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
        .extraAnimations = N(extraAnimationList_802440E4),
    },
};

StaticNpc N(npcGroup_8024514C) = {
    .id = NPC_SENTINEL,
    .settings = &N(npcSettings_802448F4),
    .pos = { -20.0f, 100.0f, 180.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { -20, 100, 180, 40, 0, -32767, 0, -20, 100, 180, 250, 0, 0, 1 },
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

NpcGroupList N(npcGroupList_8024533C) = {
    NPC_GROUP(N(npcGroup_80244920), BATTLE_ID(15, 3, 0, 1)),
    NPC_GROUP(N(npcGroup_80244D6C), BATTLE_ID(15, 1, 0, 1)),
    NPC_GROUP(N(npcGroup_8024514C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

ApiStatus N(func_8024061C_C471FC)(Evt* script, s32 isInitialCall) {
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

void N(func_802408D0_C474B0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80240958_C47538)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80240C10_C477F0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->duration = 1;
        enemy->varTable[7] = 40;
        script->functionTemp[0] = 3;
    }
}

void N(func_80240C74_C47854)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle((npc->yaw + rand_int(180)) - 90.0f);
    npc->currentAnim.w = enemy->animList[0];
    script->functionTemp[1] = (rand_int(1000) % 2) + 2;
    script->functionTemp[0] = 4;
}

void N(func_80240D1C_C478FC)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80240E54_C47A34)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80240F00_C47AE0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80241078_C47C58)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

ApiStatus N(func_802410D4_C47CB4)(Evt* script, s32 isInitialCall) {
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
            N(func_802408D0_C474B0)(script, npcAISettings, territoryPtr);
            break;
        case 1:
            N(func_80240958_C47538)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(func_80240C10_C477F0)(script, npcAISettings, territoryPtr);
            break;
        case 3:
            N(func_80240C74_C47854)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_80240D1C_C478FC)(script, npcAISettings, territoryPtr);
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
            N(func_80240E54_C47A34)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 41) {
                break;
            }
        case 41:
            N(func_80240F00_C47AE0)(script, npcAISettings, territoryPtr);
            break;
        case 50:
            N(func_80241078_C47C58)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}

#include "world/common/UnkNpcAIFunc23.inc.c"

#ifdef NON_EQUIVALENT
// second npc_raycast_down_sides call
void N(func_802415D4_C481B4)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f24;
    f32 posX, posY, posZ, posW;
    s32 var;
    f32 temp_f0;
    f32 phi_f4;
    s32 phi_v0;
    s32 phi_s4 = 0;

    f32 a = enemy->varTable[7];
    f32 temp_f2  = a / 100.0;
    f32 b = enemy->varTable[3];
    f32 temp_f26 = b / 100.0;
    f32 c = enemy->varTable[4];
    f32 temp_f20 = c / 100.0;
    f32 d = enemy->varTable[1];
    f32 temp_f22 = d / 100.0;

    enemy->varTable[4] = npc->pos.y * 100.0;
    temp_f24 = temp_f26 + temp_f2;

    if ((enemy->varTable[0] & 0x11) == 1) {
        if (npc->flags & 8) {
            if (temp_f22 < (temp_f24 - npc->pos.y)) {
                enemy->varTable[0] |= 0x10;
            }
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
            if (temp_f22 < (temp_f26 - posW)) {
                enemy->varTable[0] |= 0x10;
            }
        }
    }

    if ((enemy->varTable[0] & 0x11) == 0x11) {
        f64 test;
        if (npc->flags & 8) {
            phi_f4 = temp_f24;
            test = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            npc->pos.y = test;
        } else {
            posX = npc->pos.x;
            posY = temp_f20;
            posZ = npc->pos.z;
            posW = 1000.0f;
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
            phi_f4 = posY;
            phi_f4 += temp_f26;
            d = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            test = d;
            npc->pos.y = test;
            //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        }
        //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);

        if (fabsf(phi_f4 - npc->pos.y) < 1.0) {
            npc->pos.y = phi_f4;
            enemy->varTable[0] &= ~0x10;
        }
    } else if (enemy->varTable[1] > 0) {
        temp_f0 = sin_deg(enemy->varTable[2]);
        if (npc->flags & 8) {
            phi_v0 = FALSE;
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            phi_v0 = npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
        }
        if (phi_v0) {
            npc->pos.y = posY + temp_f26 + (temp_f0 * temp_f22);
        } else {
            npc->pos.y = temp_f24 + (temp_f0 * temp_f22);
        }
        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if (aiSettings->unk_14 >= 0) {
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[1] = aiSettings->unk_14;
                if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) &&
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0] = 10;
                    } else {
                        script->functionTemp[0] = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1]--;
        }
    } else {
        enemy->varTable[9]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape,
                               enemy->territory->wander.point.x, enemy->territory->wander.point.z,
                               npc->pos.x, npc->pos.z,
                               enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        posW = dist2D(enemy->territory->wander.point.x, enemy->territory->wander.point.z, npc->pos.x, npc->pos.z);
        if (npc->moveSpeed < posW) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
            phi_s4 = 1;
        }
    }

    if (enemy->territory->wander.wanderSizeX | enemy->territory->wander.wanderSizeZ | phi_s4) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        } else {
            return;
        }
    }

    enemy->varTable[4] = npc->pos.y * 100.0;
    if (aiSettings->moveTime > 0) {
        if ((npc->duration <= 0) || (--npc->duration <= 0)) {
            script->functionTemp[0] = 2;
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->waitTime <= 0) || (script->functionTemp[1] < 3)) {
                script->functionTemp[0] = 0;
            }
        }
    }
}
#else
INCLUDE_ASM(void, "world/area_dgb/dgb_09/C46BE0", dgb_09_func_802415D4_C481B4, Evt* script,
            NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80242078_C48C58)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80244358_C4AF38)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_80242730_C49310)(Evt* script, s32 isInitialCall) {
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
            N(func_802415D4_C481B4)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80242078_C48C58)(script, aiSettings, territoryPtr);
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

void N(func_8024291C_C494FC)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80242A74_C49654)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80242B78_C49758)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    do { enemy->varTable[0] |= 0x100; npc->pos.x = gPlayerStatusPtr->position.x; } while (0);
    npc->pos.z = gPlayerStatusPtr->position.z;
    if (!(enemy->varTable[0] & 0x1000)) {
        enemy->varTable[0] |= 0x1000;
    }
    sfx_play_sound_at_position(0x80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    npc->duration = 0;
    script->functionTemp[0] = 15;
}

void N(func_80242C1C_C497FC)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80242EB8_C49A98)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80242F70_C49B50)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_802430F0_C49CD0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = 30;
    }
}

void N(func_80243138_C49D18)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_802431B8_C49D98)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    npc->flags &= ~0x00200000;
    npc->moveSpeed = 2.0 * aiSettings->moveSpeed;
    enemy->varTable[2] = 0;
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[1] = 0x1E;
}

void N(func_80243260_C49E40)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

ApiStatus N(func_80243578_C4A158)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = evt_get_variable(script, *args);

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
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
            func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
        case 1:
            N(func_802415D4_C481B4)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] == 12) {
                npc->duration = 6;
            }
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] == 12) {
                npc->duration = 6;
            }
            break;
        case 12:
            N(func_8024291C_C494FC)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                break;
            }
        case 13:
            N(func_80242A74_C49654)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_80242B78_C49758)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 15) {
                break;
            }
        case 15:
            N(func_80242C1C_C497FC)(script, aiSettings, territoryPtr);
            break;
        case 16:
            N(func_80242EB8_C49A98)(script, aiSettings, territoryPtr);
        case 17:
            N(func_80242F70_C49B50)(script, aiSettings, territoryPtr);
            break;
        case 18:
            N(func_802430F0_C49CD0)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(func_80243138_C49D18)(script, aiSettings, territoryPtr);
            break;
        case 30:
            N(func_802431B8_C49D98)(script, aiSettings, territoryPtr);
        case 31:
            N(func_80243260_C49E40)(script, aiSettings, territoryPtr);
    }

    return (script->functionTemp[0] == 100) * ApiStatus_DONE2;
}

const char N(dgb_00_name_hack)[] = "dgb_00";
