#include "dgb_03.h"
#include "sprite/npc/world_clubba.h"
#include "message_ids.h"

extern s16 D_8009A634;
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
    .main = N(main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = MSG_dgb_03_tattle,
};

Script N(80242870) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        }
        else {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
    }
});

static s32 N(pad_2908)[] = {
    0x00000000, 0x00000000,
};

Script N(exitDoubleDoor_80242910) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 1;
    SI_VAR(1) = 25;
    SI_VAR(2) = 36;
    SI_VAR(3) = 34;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_02", 0);
    sleep 100;
});

Script N(exitDoubleDoor_802429C4) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 4;
    SI_VAR(1) = 21;
    SI_VAR(2) = 46;
    SI_VAR(3) = 44;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_09", 0);
    sleep 100;
});

Script N(exitDoubleDoor_80242A78) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 0;
    SI_VAR(1) = 13;
    SI_VAR(2) = 29;
    SI_VAR(3) = 31;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_04", 0);
    sleep 100;
});

Script N(exitWalk_80242B2C) = EXIT_WALK_SCRIPT(26,  2, "dgb_13",  0);

Script N(exitSingleDoor_80242B88) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(0);
    SI_VAR(0) = 2;
    SI_VAR(1) = 33;
    SI_VAR(2) = 49;
    SI_VAR(3) = 1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("dgb_05", 0);
    sleep 100;
});

Script N(exitDoubleDoor_80242C3C) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 3;
    SI_VAR(1) = 17;
    SI_VAR(2) = 39;
    SI_VAR(3) = 41;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_14", 0);
    sleep 100;
});

Script N(80242CF0) = SCRIPT({
    bind N(exitWalk_80242B2C) to TRIGGER_FLOOR_ABOVE 35;
});

Script N(enterDoubleDoor_80242D1C) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            UseDoorSounds(3);
            SI_VAR(2) = 29;
            SI_VAR(3) = 31;
            await EnterDoubleDoor;
            spawn N(80242CF0);
        }
        == 1 {
            UseDoorSounds(3);
            SI_VAR(2) = 36;
            SI_VAR(3) = 34;
            await EnterDoubleDoor;
            spawn N(80242CF0);
        }
        == 2 {
            UseDoorSounds(0);
            SI_VAR(2) = 49;
            SI_VAR(3) = 1;
            await EnterSingleDoor;
            spawn N(80242CF0);
        }
        == 3 {
            UseDoorSounds(3);
            SI_VAR(2) = 39;
            SI_VAR(3) = 41;
            await EnterDoubleDoor;
            spawn N(80242CF0);
        }
        == 4 {
            UseDoorSounds(3);
            SI_VAR(2) = 46;
            SI_VAR(3) = 44;
            await EnterDoubleDoor;
            spawn N(80242CF0);
        }
        == 5 {
            SI_VAR(0) = N(80242CF0);
            spawn EnterWalkShort;
            sleep 1;
        }
    }
});

s32 N(itemList_80242F28)[] = {
    ITEM_CASTLE_KEY1,
    ITEM_NONE,
};

// *INDENT-OFF*
Script N(main) = {
    SI_CMD(ScriptOpcode_SET, SI_SAVE_VAR(425), 15),
    SI_CMD(ScriptOpcode_CALL, SetSpriteShading, -1),
    SI_CMD(ScriptOpcode_CALL, SetCamPerspective, 0, 3, 25, 16, 4096),
    SI_CMD(ScriptOpcode_CALL, SetCamBGColor, 0, 0, 0, 0),
    SI_CMD(ScriptOpcode_CALL, SetCamEnabled, 0, 1),
    SI_CMD(ScriptOpcode_IF_LT, SI_SAVE_VAR(0), -15),
        SI_CMD(ScriptOpcode_CALL, MakeNpcs, 1, N(npcGroupList_80244988)),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(makeEntities)),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80243608)),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_80242910), TRIGGER_WALL_PRESS_A, 25, 1, 0),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_802429C4), TRIGGER_WALL_PRESS_A, 21, 1, 0),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_80242A78), TRIGGER_WALL_PRESS_A, 13, 1, 0),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitSingleDoor_80242B88), TRIGGER_WALL_PRESS_A, 33, 1, 0),
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1043), 0),
        SI_CMD(ScriptOpcode_BIND_PADLOCK, N(80243740), TRIGGER_WALL_PRESS_A, 16384, N(itemList_80242F28), 0, 1),
    SI_CMD(ScriptOpcode_ELSE),
        SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_80242C3C), TRIGGER_WALL_PRESS_A, 17, 1, 0),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80242870)),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(enterDoubleDoor_80242D1C)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

static s32 N(pad_30D8)[] = {
    0x00000000, 0x00000000,
};

Script N(802430E0) = SCRIPT({
    group 0;
    loop 20 {
        GetCurrentPartner(SI_VAR(10));
        if (SI_VAR(10) != 0) {
            SI_VAR(8) = -1;
            return;
        }
        N(UnkFunc11)(SI_VAR(9));
        if (SI_VAR(0) == 0) {
            SI_VAR(8) = -1;
            return;
        } else {
            SetPlayerActionState(20);
        }
        sleep 1;
    }
    GetCurrentPartner(SI_VAR(10));
    if (SI_VAR(10) != 0) {
        SI_VAR(8) = -1;
        return;
    }
    DisablePlayerInput(TRUE);
    spawn {
        ShakeCam(0, 0, 100, 0.6005859375);
    }
    spawn {
        if (SI_VAR(6) >= SI_VAR(7)) {
            InterpPlayerYaw(270, 0);
        } else {
            InterpPlayerYaw(90, 0);
        }
        SetPlayerActionState(20);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) = SI_VAR(0);
        SI_VAR(2) = SI_VAR(7);
        SI_VAR(2) -= SI_VAR(6);
        SI_VAR(1) += SI_VAR(2);
        MakeLerp(SI_VAR(0), SI_VAR(1), 100, 0);
        loop {
            SetPlayerActionState(20);
            UpdateLerp();
            N(UnkFunc12)();
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        SetPlayerActionState(0);
        DisablePlayerInput(FALSE);
    }
    MakeLerp(SI_VAR(6), SI_VAR(7), 100, 0);
    PlaySoundAtCollider(27, 0x80000010, 0);
    loop {
        UpdateLerp();
        TranslateModel(51, SI_VAR(0), 0, 0);
        UpdateColliderTransform(27);
        UpdateColliderTransform(28);
        UpdateColliderTransform(29);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    StopSound(0x80000010);
});

Script N(80243470) = SCRIPT({
    if (SI_SAVE_FLAG(1044) != 0) {
        goto 90;
    }
    SI_VAR(6) = 0;
    SI_VAR(7) = 48;
    SI_VAR(8) = 0;
    SI_VAR(9) = 27;
    await N(802430E0);
90:
    if (SI_VAR(8) != -1) {
        SI_SAVE_FLAG(1045) = 0;
        SI_SAVE_FLAG(1044) = 1;
        unbind;
    }
});

Script N(8024353C) = SCRIPT({
    if (SI_SAVE_FLAG(1044) != 0) {
        goto 90;
    }
    SI_VAR(6) = 0;
    SI_VAR(7) = -48;
    SI_VAR(8) = 0;
    SI_VAR(9) = 28;
    await N(802430E0);
90:
    if (SI_VAR(8) != -1) {
        SI_SAVE_FLAG(1045) = 1;
        SI_SAVE_FLAG(1044) = 1;
        unbind;
    }
});

Script N(80243608) = SCRIPT({
    ParentColliderToModel(27, 51);
    ParentColliderToModel(28, 51);
    ParentColliderToModel(29, 51);
    if (SI_SAVE_FLAG(1044) == 0) {
        bind N(80243470) to TRIGGER_WALL_PUSH 27;
        bind N(8024353C) to TRIGGER_WALL_PUSH 28;
    } else {
        if (SI_SAVE_FLAG(1045) == 0) {
            SI_VAR(0) = 48;
        } else {
            SI_VAR(0) = -48;
        }
        TranslateModel(51, SI_VAR(0), 0, 0);
        UpdateColliderTransform(27);
        UpdateColliderTransform(28);
        UpdateColliderTransform(29);
    }
});

static s32 N(pad_3738)[] = {
    0x00000000, 0x00000000,
};

Script N(80243740) = SCRIPT({
    group 0;
    suspend group 1;
    func_802D6420();
    if (SI_VAR(0) == 0) {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00D8), 160, 40);
        func_802D6954();
        resume group 1;
        return;
    }
    if (SI_VAR(0) == -1) {
        func_802D6954();
        resume group 1;
        return;
    }
    FindKeyItem(19, SI_VAR(0));
    RemoveKeyItemAt(SI_VAR(0));
    func_802D6954();
    SI_SAVE_FLAG(1043) = 1;
    N(GetEntityPosition)(SI_MAP_VAR(0), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    PlaySoundAt(0x269, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) = SI_MAP_VAR(0);
    N(SetEntityFlags100000)();
    resume group 1;
    unbind;
});

Script N(802438A8) = SCRIPT({
    bind N(exitDoubleDoor_80242C3C) to TRIGGER_WALL_PRESS_A 17;
});

Script N(makeEntities) = SCRIPT({
    if (SI_SAVE_FLAG(1043) == 0) {
        MakeEntity(0x802BCD68, -355, 218, 75, 80, MAKE_ENTITY_END);
        AssignScript(N(802438A8));
        SI_MAP_VAR(0) = SI_VAR(0);
    }
    MakeItemEntity(ITEM_STAR_PIECE, 0, 75, 100, 17, SI_SAVE_FLAG(1042));
});

static s32 N(pad_3964)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80243970) = SCRIPT({
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
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

s32 N(unk_missing_80243A2C)[] = {
    0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x0039000C, 0x00390007, 0x00390008, 0x00390011,
    0x00390012, 0xFFFFFFFF,
};

NpcAnimID N(extraAnimationList_80243A54)[] = {
    NPC_ANIM(world_clubba, Palette_00, Anim_0),
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

Script N(npcAI_80243A8C) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(1, 5);
    SetSelfVar(2, 8);
    SetSelfVar(3, 12);
    N(func_8024086C_C31D4C)(N(npcAISettings_80243A5C));
});

NpcSettings N(npcSettings_80243AFC) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_80243A8C),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
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

Script N(npcAI_80243B58) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(1, 5);
    SetSelfVar(2, 8);
    SetSelfVar(3, 12);
    N(func_802419B0_C32E90)(N(npcAISettings_80243B28));
});

NpcSettings N(npcSettings_80243BC8) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_80243B58),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
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

Script N(npcAI_80243C24) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(1, 10);
    SetSelfVar(2, 14);
    SetSelfVar(3, 18);
    N(func_80242480_C33960)(N(npcAISettings_80243BF4));
});

NpcSettings N(npcSettings_80243C94) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_80243C24),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 13,
};

Script N(npcAI_80243CC0) = SCRIPT({
    EnableNpcShadow(NPC_SELF, FALSE);
    SetSelfVar(0, 4);
    SetSelfVar(1, 32);
    SetSelfVar(2, 50);
    SetSelfVar(3, 32);
    SetSelfVar(4, 3);
    SetSelfVar(15, 8389);
    N(UnkFunc7)();
});

NpcSettings N(npcSettings_80243D68) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_80243CC0),
    .onDefeat = &N(80243970),
    .level = 13,
    .unk_2A = 8,
};

Script N(init_80243D94) = SCRIPT({
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 3) {
        SetNpcPos(NPC_SELF, -330, 210, -20);
    }
});

StaticNpc N(npcGroup_80243DE8)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_80243AFC),
        .pos = { 180.0f, 0.0f, -122.0f },
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_IGNORE_HEIGHT,
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
        .movement = { 180, 0, -122, 40, 0, -32767, 0, 0, 0, 75, 355, 255, 1, 1 },
        .animations = {
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_3),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_11),
            NPC_ANIM(world_clubba, Palette_00, Anim_12),
            NPC_ANIM(world_clubba, Palette_00, Anim_7),
            NPC_ANIM(world_clubba, Palette_00, Anim_8),
            NPC_ANIM(world_clubba, Palette_00, Anim_1),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
        },
        .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_80243D68),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_IGNORE_HEIGHT | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_3),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_11),
            NPC_ANIM(world_clubba, Palette_00, Anim_12),
            NPC_ANIM(world_clubba, Palette_00, Anim_7),
            NPC_ANIM(world_clubba, Palette_00, Anim_8),
            NPC_ANIM(world_clubba, Palette_00, Anim_1),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
        },
        .extraAnimations = &N(extraAnimationList_80243A54),
    },
};

StaticNpc N(npcGroup_802441C8)[] = {
    {
        .id = NPC_WORLD_CLUBBA2,
        .settings = &N(npcSettings_80243BC8),
        .pos = { -272.0f, 0.0f, -135.0f },
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_IGNORE_HEIGHT,
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
        .movement = { 2, -272, 0, -135, -171, 0, -135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 0, 0, 75, 355, 255, 1, 1 },
        .animations = {
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_3),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_11),
            NPC_ANIM(world_clubba, Palette_00, Anim_12),
            NPC_ANIM(world_clubba, Palette_00, Anim_7),
            NPC_ANIM(world_clubba, Palette_00, Anim_8),
            NPC_ANIM(world_clubba, Palette_00, Anim_1),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
        },
        .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
    },
    {
        .id = NPC_WORLD_CLUBBA3,
        .settings = &N(npcSettings_80243D68),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_IGNORE_HEIGHT | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_3),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_11),
            NPC_ANIM(world_clubba, Palette_00, Anim_12),
            NPC_ANIM(world_clubba, Palette_00, Anim_7),
            NPC_ANIM(world_clubba, Palette_00, Anim_8),
            NPC_ANIM(world_clubba, Palette_00, Anim_1),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
        },
        .extraAnimations = &N(extraAnimationList_80243A54),
    },
};

StaticNpc N(npcGroup_802445A8)[] = {
    {
        .id = NPC_WORLD_CLUBBA4,
        .settings = &N(npcSettings_80243C94),
        .pos = { -326.0f, 210.0f, 80.0f },
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_IGNORE_HEIGHT,
        .init = &N(init_80243D94),
        .yaw = 90,
        .dropFlags = 0x80,
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
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_3),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_11),
            NPC_ANIM(world_clubba, Palette_00, Anim_12),
            NPC_ANIM(world_clubba, Palette_00, Anim_7),
            NPC_ANIM(world_clubba, Palette_00, Anim_8),
            NPC_ANIM(world_clubba, Palette_00, Anim_1),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
        },
        .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
    },
    {
        .id = NPC_WORLD_CLUBBA5,
        .settings = &N(npcSettings_80243D68),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_IGNORE_HEIGHT | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_3),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_4),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_C),
            NPC_ANIM(world_clubba, Palette_00, Anim_11),
            NPC_ANIM(world_clubba, Palette_00, Anim_12),
            NPC_ANIM(world_clubba, Palette_00, Anim_7),
            NPC_ANIM(world_clubba, Palette_00, Anim_8),
            NPC_ANIM(world_clubba, Palette_00, Anim_1),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
            NPC_ANIM(world_clubba, Palette_00, Anim_2),
        },
        .extraAnimations = &N(extraAnimationList_80243A54),
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

s32 N(func_80240458_C31938)(ScriptInstance *script) {
    PlayerStatus** playerStatus = &gPlayerStatusPtr;
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = CAM2(D_8009A634);
    Enemy* enemy2 = get_enemy(enemy->npcID + 1);
    f32 phi_f20;
    s32 ret = TRUE;

    if (dist2D(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z) > enemy2->varTable[2]) {
        ret = FALSE;
    }

    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        phi_f20 = 90.0f;
    } else {
        phi_f20 = 270.0f;
    }

    if (fabsf(get_clamped_angle_diff(phi_f20, atan2(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z))) > enemy2->varTable[3]) {
        ret = FALSE;
    }

    if ((2.0 * npc->collisionHeight) <= fabsf(npc->pos.y - (*playerStatus)->position.y)) {
        ret = FALSE;
    }

    if (D_8010EBB0.unk_03 == 9) {
        ret = FALSE;
    }

    if (D_8010EBB0.unk_03 == 7) {
        ret = FALSE;
    }

    return ret;
}

#include "world/common/UnkFunc7.inc.c"

ApiStatus N(func_8024086C_C31D4C)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_34 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            enemy->unk_B0 &= ~4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->functionTemp[0].s < 30) && (enemy->varTable[0] == 0) && N(func_80240458_C31938)(script)) {
        script->functionTemp[0].s = 30;
    }

    switch (script->functionTemp[0].s) {
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
            if (script->functionTemp[0].s != 32) {
                break;
            }
        case 32:
            N(UnkNpcAIFunc8)(script);
            if (script->functionTemp[0].s != 33) {
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

ApiStatus N(func_80240B20_C32000)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    f32 ret;
    f32 max;
    f32 posX;
    f32 posZ;
    s32 i;
    s32 j;

    script->functionTemp[1].s = 0;
    max = 32767.0f;
    posX = npc->pos.x;
    posZ = npc->pos.z;
    script->functionTemp[2].s = 0;

    for (i = 0, j = 0; i < enemy->territory->patrol.numPoints; i++, j++) {
        ret = dist2D(posX, posZ, i[enemy->territory->patrol.points].x, i[enemy->territory->patrol.points].z);
        if (ret < max) {
            max = ret;
            script->functionTemp[2].s = j;
        }
    }

    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }

    script->functionTemp[0].s = 1;
    return 1;
}

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

ApiStatus N(func_8024119C_C3267C)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2].s = 0;
    }
    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[0].s = 1;
    return 1;
}

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_802416B4_C32B94)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_34 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0].s = 12;
            enemy->flags &= 0xBFFFFFFF;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240B20_C32000)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_8024119C_C3267C)(script, npcAISettings, territoryPtr);
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

ApiStatus N(func_802419B0_C32E90)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_34 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            enemy->unk_B0 &= ~4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->functionTemp[0].s < 30) && (enemy->varTable[0] == 0) && N(func_80240458_C31938)(script)) {
        script->functionTemp[0].s = 30;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240B20_C32000)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_8024119C_C3267C)(script, npcAISettings, territoryPtr);
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
            if (script->functionTemp[0].s != 32) {
                break;
            }
        case 32:
            N(UnkNpcAIFunc8)(script);
            if (script->functionTemp[0].s != 33) {
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

void N(func_80241C7C_C3315C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (npc->duration == 1) {
        npc->currentAnim = enemy->animList[12];
    } else if (npc->duration <= 0) {
        npc->currentAnim = enemy->animList[10];
        npc->duration = 0;
        script->functionTemp[0].s = 1;
    }
}

void N(func_80241D04_C331E4)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
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
            if (D_8010EBB0.unk_00 == playerData->currentPartner) {
                phi_s2 = TRUE;
            }
        }
    }

    if (((playerData->currentPartner == 1) && (D_8010EBB0.unk_00 != 0)) || 
        ((playerData->currentPartner == 3) && (D_8010EBB0.unk_00 == 2))) {
        posX = npc->pos.x;
        posZ = npc->pos.z;
        add_vec2D_polar(&posX, &posZ, 0.0f, npc->yaw);
        if (dist2D(posX, posZ, wPartnerNpc->pos.x, wPartnerNpc->pos.z) <= 80.0f) {
            phi_s2 = TRUE;
        }
    }

    if (phi_s2) {
        func_800494C0(npc, 0xB000000E, 0);
        npc->currentAnim = enemy->animList[11];
        npc->duration = 10;
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
        func_800494C0(npc, 0x2F4, 0x200000);
        script->functionTemp[0].s = 2;
    }

    npc->duration++;
    if (npc->duration == 27) {
        func_800494C0(npc, 0xB000000C, 0);
    } else if (npc->duration == 57) {
        func_800494C0(npc, 0xB000000D, 0);
    } else if (npc->duration == 59) {
        npc->currentAnim = enemy->animList[12];
    } else if (npc->duration == 60) {
        npc->currentAnim = enemy->animList[10];
        npc->duration = 0;
    }
}

void N(func_80241FBC_C3349C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->duration = 1;
        enemy->varTable[7] = 40;
        script->functionTemp[0].s = 3;
    }
}

void N(func_80242020_C33500)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle((npc->yaw + rand_int(180)) - 90.0f);
    npc->currentAnim = enemy->animList[0];
    script->functionTemp[1].s = (rand_int(1000) % 2) + 2;
    script->functionTemp[0].s = 4;
}

void N(func_802420C8_C335A8)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->functionTemp[0].s = 12;
        return;
    }

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[1].s--;
        if (script->functionTemp[1].s > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            return;
        }

        var = enemy->varTable[7];
        if (var == 40) {
            npc->duration = 20;
            script->functionTemp[0].s = var;
        } else if (var == 50) {
            npc->duration = 25;
            script->functionTemp[0].s = var;
        }
    }
}

void N(func_80242200_C336E0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim = enemy->animList[1];
        if (enemy->territory->wander.moveSpeedOverride < 0) {
            npc->moveSpeed = aiSettings->moveSpeed;
        } else {
            npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
        }
        script->functionTemp[0].s = 0x29;
    }
}

void N(func_802422AC_C3378C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    f32 var;

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->functionTemp[0].s = 12;
    } else if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z) <= npc->moveSpeed) {
        npc->currentAnim = enemy->animList[0];
        npc->duration = 15;
        enemy->varTable[7] = 50;
        script->functionTemp[0].s = 3;
    } else if (npc->unk_8C == 0) {
        var = npc->yaw;
        func_8004A784(npc, 5.0f, &var, 0, 0, 0);
        npc->yaw = var;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

void N(func_80242424_C33904)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    if (npc->unk_8C == 0) {
        npc->duration--;
        if (npc->duration <= 0) {
            npc->duration = 0;
            script->functionTemp[0].s = 0;
        }
    }
}

ApiStatus N(func_80242480_C33960)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_34 = 40.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0].s = 0;
        npc->duration = 30;
        npc->currentAnim = enemy->animList[10];
        npc->flags &= ~0x800;
        enemy->varTable[0] = 0;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 40;
            npc->currentAnim = enemy->animList[0];
        }
        enemy->unk_B0 &= ~4;
    }

    if (((u32)script->functionTemp[0].s - 10 < 20) && (enemy->varTable[0] == 0) && N(func_80240458_C31938)(script)) {
        script->functionTemp[0].s = 30;
    }

    switch (script->functionTemp[0].s) {
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
            if (script->functionTemp[0].s != 13) {
                break;
            }
        case 13:
            func_8004A124(script, npcAISettings, territoryPtr);
            break;
        case 14:
            func_8004A3E8(script, npcAISettings, territoryPtr);
            npc->duration = 15;
            enemy->varTable[7] = 40;
            script->functionTemp[0].s = 3;
            break;
        case 30:
            N(UnkNpcAIFunc6)(script);
            if (script->functionTemp[0].s != 31) {
                break;
            }
        case 31:
            N(UnkNpcAIFunc7)(script);
            if (script->functionTemp[0].s != 32) {
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
            if (script->functionTemp[0].s != 41) {
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