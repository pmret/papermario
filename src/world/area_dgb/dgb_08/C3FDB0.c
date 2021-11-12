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

EvtSource N(80243CF0) = SCRIPT({
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

static s32 N(pad_3D88)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitDoubleDoor_80243D90) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    EVT_VAR(0) = 0;
    EVT_VAR(1) = 14;
    EVT_VAR(2) = 23;
    EVT_VAR(3) = 25;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_01", 2);
    sleep 100;
});

EvtSource N(exitDoubleDoor_80243E44) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    EVT_VAR(0) = 1;
    EVT_VAR(1) = 18;
    EVT_VAR(2) = 18;
    EVT_VAR(3) = 20;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_01", 4);
    sleep 100;
});

const s32 N(pad_XXXX)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(enterDoubleDoor_80243EF8) = SCRIPT({
    UseDoorSounds(3);
    GetEntryID(EVT_VAR(0));
    match EVT_VAR(0) {
        == 0 {
            EVT_VAR(2) = 23;
            EVT_VAR(3) = 25;
            await EnterDoubleDoor;
        }
        == 1 {
            EVT_VAR(2) = 18;
            EVT_VAR(3) = 20;
            await EnterDoubleDoor;
        }
    }
});

EvtSource N(main) = SCRIPT({
    EVT_WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    match EVT_STORY_PROGRESS {
        < STORY_CH3_TUBBA_SMASHED_THE_BRIDGES {
            MakeNpcs(1, N(npcGroupList_80246958));
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            MakeNpcs(1, N(npcGroupList_802469AC));
        }
        < STORY_CH6_RETURNED_TO_TOAD_TOWN {
            MakeNpcs(1, N(npcGroupList_802469C4));
        }
    }
    await N(802469E0);
    bind N(exitDoubleDoor_80243D90) TRIGGER_WALL_PRESS_A 14;
    bind N(exitDoubleDoor_80243E44) TRIGGER_WALL_PRESS_A 18;
    spawn N(80243CF0);
    spawn N(enterDoubleDoor_80243EF8);
});

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

EvtSource N(80244130) = SCRIPT({
    N(func_80240B94_C40944)(N(npcAI_80244100));
});

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

EvtSource N(802441D4) = SCRIPT({
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

EvtSource N(npcAI_802442F0) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(1, 5);
    SetSelfVar(2, 8);
    SetSelfVar(3, 12);
    N(func_802414AC_C4125C)(N(npcAISettings_802442C0));
});

NpcSettings N(npcSettings_80244360) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_802442F0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

EvtSource N(npcAI_8024438C) = SCRIPT({
    EnableNpcShadow(NPC_SELF, FALSE);
    SetSelfVar(0, 4);
    SetSelfVar(1, 32);
    SetSelfVar(2, 50);
    SetSelfVar(3, 32);
    SetSelfVar(4, 3);
    SetSelfVar(15, 8389);
    N(UnkFunc7)();
});

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

EvtSource N(80244478) = SCRIPT({
    SetSelfEnemyFlagBits(((0x00100000 | 0x01000000 | 0x02000000 | 0x04000000 | 0x08000000 | 0x10000000 | 0x20000000)), TRUE);
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT)), TRUE);
});

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

EvtSource N(npcAI_802444E4) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(5, -650);
    SetSelfVar(6, 30);
    SetSelfVar(1, 600);
    N(func_802438F0_C436A0)(N(npcAISettings_802444B4));
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

EvtSource N(8024490C) = SCRIPT({
    GetOwnerEncounterTrigger(EVT_VAR(0));
    match EVT_VAR(0) {
        == 1, 2, 4, 6 {
            GetSelfAnimationFromTable(7, EVT_VAR(0));
            await 0x800936DC;
        }
    }
});

EvtSource N(80244998) = SCRIPT({
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

EvtSource N(idle_80244A54) = SCRIPT({
    loop {
        GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        if (EVT_VAR(0) >= -350) {
            break loop;
        }
        sleep 1;
    }
    EVT_SAVE_VAR(203) = 8;
    EVT_STORY_PROGRESS = STORY_CH3_TUBBA_CHASED_MARIO_IN_HALL;
    PlaySoundAtCollider(18, 455, 0);
    MakeLerp(0, 80, 10, 0);
    loop {
        UpdateLerp();
        RotateModel(18, EVT_VAR(0), 0, -1, 0);
        RotateModel(20, EVT_VAR(0), 0, 1, 0);
        sleep 1;
        if (EVT_VAR(1) == 0) {
            break loop;
        }
    }
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM_world_tubba_Palette_00_Anim_A);
    SetNpcPos(NPC_SELF, -665, 210, 180);
    SetNpcYaw(NPC_SELF, 90);
    NpcMoveTo(NPC_SELF, -530, 180, 30);
    spawn {
        sleep 20;
        MakeLerp(80, 0, 10, 0);
        loop {
            UpdateLerp();
            RotateModel(18, EVT_VAR(0), 0, -1, 0);
            RotateModel(20, EVT_VAR(0), 0, 1, 0);
            sleep 1;
            if (EVT_VAR(1) == 0) {
                break loop;
            }
        }
        PlaySoundAtCollider(18, 456, 0);
    }
    NpcMoveTo(NPC_SELF, -500, 80, 10);
    BindNpcAI(NPC_SELF, N(npcAI_80244D7C));
});

EvtSource N(80244D08) = SCRIPT({
10:
    GetNpcPos(NPC_WORLD_TUBBA, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    if (EVT_VAR(1) > 0) {
        sleep 1;
        goto 10;
    }
    N(func_80243B98_C43948)();
});

EvtSource N(npcAI_80244D7C) = SCRIPT({
    N(func_80243C10_C439C0)();
    spawn N(80244D08);
    spawn {
        loop {
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_20F6, 4194304);
            ShakeCam(0, 0, 5, 2.0);
            sleep 5;
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_20F6, 4194304);
            ShakeCam(0, 0, 2, 1.0);
            sleep 8;
        }
    }
    N(func_80240B94_C40944)(N(npcAI_80244100));
});

const char N(dgb_01_name_hack)[];

EvtSource N(defeat_80244E58) = SCRIPT({
    N(UnkFunc1)();
    GotoMap(N(dgb_01_name_hack), 2);
    sleep 100;
});

EvtSource N(init_80244E94) = SCRIPT({
    if (EVT_STORY_PROGRESS < STORY_CH3_TUBBA_SMASHED_THE_BRIDGES) {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
        SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_4)), TRUE);
        return;
    }
    if (EVT_STORY_PROGRESS >= STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER) {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
        SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_4)), TRUE);
        return;
    }
    SetNpcScale(NPC_SELF, 1.25, 1.25, 1.25);
    BindNpcDefeat(NPC_SELF, N(defeat_80244E58));
    GetEntryID(EVT_VAR(0));
    match EVT_VAR(0) {
        == 0 {
            if (EVT_SAVE_VAR(203) != 8) {
                SetNpcPos(NPC_SELF, 0, -1000, 0);
                SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_4)), TRUE);
            } else {
                SetNpcPos(NPC_SELF, -130, 0, 200);
                BindNpcIdle(NPC_SELF, N(npcAI_80244D7C));
            }
        }
        == 1 {
            if (EVT_SAVE_VAR(203) != 8) {
                BindNpcIdle(NPC_SELF, N(idle_80244A54));
            } else {
                SetNpcPos(NPC_SELF, -130, 210, 80);
                BindNpcIdle(NPC_SELF, N(npcAI_80244D7C));
            }
        }
    }
});

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

EvtSource N(idle_80246210) = SCRIPT({
0:
    SetNpcAnimation(NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_7);
    sleep 30;
    loop 15 {
        N(func_80243C50_C43A00)();
        sleep 60;
    }
    SetNpcAnimation(NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_C);
    sleep 20;
    SetNpcAnimation(NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_7);
    sleep 30;
    loop 5 {
        N(func_80243C50_C43A00)();
        sleep 60;
    }
    SetNpcAnimation(NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_C);
    sleep 15;
    goto 0;
});

EvtSource N(interact_80246310) = SCRIPT({
    SetNpcAnimation(NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_8);
    PlaySoundAtNpc(NPC_SELF, 0x2F1, 0);
    sleep 10;
    SetNpcAnimation(NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_2);
    sleep 20;
    GetNpcYaw(-1, EVT_VAR(0));
    EVT_VAR(0) += 180;
    InterpNpcYaw(NPC_SELF, EVT_VAR(0), 0);
    sleep 10;
    GetNpcYaw(-1, EVT_VAR(0));
    EVT_VAR(0) += 180;
    InterpNpcYaw(NPC_SELF, EVT_VAR(0), 0);
    sleep 25;
    GetNpcYaw(-1, EVT_VAR(0));
    EVT_VAR(0) += 180;
    InterpNpcYaw(NPC_SELF, EVT_VAR(0), 0);
    sleep 15;
    NpcFacePlayer(NPC_SELF, 0);
    SpeakToPlayer(NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_5, NPC_ANIM_world_clubba_Palette_00_Anim_2, 0, MESSAGE_ID(0x0E, 0x00F2));
    sleep 10;
    SetNpcAnimation(NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_6);
    sleep 10;
    SetNpcAnimation(NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_7);
});

EvtSource N(init_802464C4) = SCRIPT({
    SetNpcCollisionSize(-1, 36, 30);
    SetNpcAnimation(NPC_SELF, NPC_ANIM_world_clubba_Palette_00_Anim_7);
    BindNpcInteract(NPC_SELF, N(interact_80246310));
    BindNpcIdle(NPC_SELF, N(idle_80246210));
});

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

EvtSource N(idle_80246718) = SCRIPT({

});

EvtSource N(init_80246728) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_80246718));
    SetNpcPos(NPC_SELF, 0, -1000, 0);
});

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

EvtSource N(802469E0) = SCRIPT({

});

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

#ifdef NON_MATCHING
// second npc_raycast_down_sides call
void N(func_80241910_C416C0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
INCLUDE_ASM(void, "world/area_dgb/dgb_08/C3FDB0", dgb_08_func_80241910_C416C0, Evt* script,
            NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

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
            N(func_80241910_C416C0)(script, aiSettings, territoryPtr);
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
            N(func_80241910_C416C0)(script, npcAISettings, territoryPtr);
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
