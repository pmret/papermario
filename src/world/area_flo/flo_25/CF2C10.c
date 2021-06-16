#include "flo_25.h"
#include "message_ids.h"
#include "sprite/npc/bzzap.h"
#include "sprite/npc/gate_flower.h"
#include "sprite/npc/tuff_puff.h"

enum {
    NPC_GATE_FLOWER,
    NPC_TUFF_PUFF,
    NPC_BZZAP,
};

static s32 N(D_80244A20)[91];
static s8 N(D_8024510C_pad)[4];
static s32 N(D_80245110)[91];
static s32 N(D_8024527C);

EntryList N(entryList) = {
    {  620.0f, 0.0f, 0.0f, 270.0f },
    { -620.0f, 0.0f, 0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_25_tattle },
};

Script N(80242330) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
        } else {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
        }
    }
});

Script N(802423A0) = SCRIPT({
    group 11;
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(11) = SI_VAR(1);
    SI_VAR(12) = SI_VAR(2);
    SI_VAR(13) = SI_VAR(3);
    SI_VAR(14) = SI_VAR(4);
    SI_VAR(12) -= SI_VAR(0);
    SI_VAR(13) -= SI_VAR(1);
    SI_VAR(0) = (float) SI_VAR(12);
    SI_VAR(0) /= 100.0;
    SI_VAR(15) = 100.0;
    SI_VAR(15) /= (float) SI_VAR(0);
    SI_VAR(15) += 11;
    SI_VAR(5) = 200;
    SI_VAR(5) /= SI_VAR(15);
    SI_VAR(5) += 1;
    loop SI_VAR(5) {
        RandInt(SI_VAR(12), SI_VAR(0));
        RandInt(SI_VAR(13), SI_VAR(1));
        RandInt(199, SI_VAR(2));
        SI_VAR(3) = 210;
        SI_VAR(3) -= SI_VAR(2);
        SI_VAR(0) += SI_VAR(10);
        SI_VAR(1) += SI_VAR(11);
        SI_VAR(2) += SI_VAR(14);
        PlayEffect(0xD, SI_VAR(0), SI_VAR(2), SI_VAR(1), SI_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    sleep SI_VAR(15);
0:
    RandInt(SI_VAR(12), SI_VAR(0));
    RandInt(SI_VAR(13), SI_VAR(1));
    SI_VAR(0) += SI_VAR(10);
    SI_VAR(1) += SI_VAR(11);
    PlayEffect(0xD, SI_VAR(0), SI_VAR(14), SI_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep SI_VAR(15);
    goto 0;
});

Script N(exitWalk_8024264C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  3);

Script N(exitWalk_802426A8) = EXIT_WALK_SCRIPT(60,  1, "flo_07",  0);

Script N(80242704) = SCRIPT({
    bind N(exitWalk_802426A8) to TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_8024264C) to TRIGGER_FLOOR_ABOVE 4;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80243C5C));
    await N(makeEntities);
    spawn N(80244D0C);
    spawn N(802446BC);
    SI_VAR(0) = -270;
    SI_VAR(1) = -190;
    SI_VAR(2) = 640;
    SI_VAR(3) = -60;
    SI_VAR(4) = 60;
    spawn N(802423A0);
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    SI_VAR(0) = N(80242704);
    spawn EnterWalk;
    await N(80242330);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_CF2BD0)();
    }
});

NpcSettings N(npcSettings_802428F0) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

f32 N(D_8024291C_CF54EC)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80242934) = {
    .moveSpeed = 1.0f,
    .moveTime = 45,
    .waitTime = 60,
    .alertRadius = 100.0f,
    .unk_14 = 3,
    .chaseSpeed = 3.6f,
    .unk_1C = { .s = 10 },
    .unk_20 = 1,
    .chaseRadius = 120.0f,
    .unk_2C = 1,
};

Script N(npcAI_80242964) = SCRIPT({
    SetSelfVar(0, 1);
    SetSelfVar(5, 0);
    SetSelfVar(6, 0);
    SetSelfVar(1, 600);
    N(func_80241944_CF4514)(N(npcAISettings_80242934));
});

NpcSettings N(npcSettings_802429D4) = {
    .height = 24,
    .radius = 28,
    .ai = &N(npcAI_80242964),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

NpcAISettings N(npcAISettings_80242A00) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 5,
    .alertRadius = 80.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 2,
    .chaseSpeed = 4.5f,
    .unk_1C = { .s = 6 },
    .unk_20 = 1,
    .chaseRadius = 90.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 1,
};

Script N(npcAI_80242A30) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(5, -630);
    SetSelfVar(6, 50);
    SetSelfVar(1, 200);
    N(func_8024134C_CF3F1C)(N(npcAISettings_80242A00));
});

NpcSettings N(npcSettings_80242AA0) = {
    .height = 26,
    .radius = 24,
    .ai = &N(npcAI_80242A30),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

s32 N(D_80242ACC_CF569C) = {
    0x00000000,
};

s32 N(D_80242AD0_CF56A0) = {
    0x00000000,
};

Script N(80242AD4) = SCRIPT({
    SI_VAR(9) = SI_VAR(1);
    func_802D663C();
    SI_VAR(10) = SI_VAR(0);
    match SI_VAR(0) {
        == 0 {}
        == -1 {}
        else {
            RemoveItemAt(SI_VAR(1));
            GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            N(AddPlayerHandsOffset)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            MakeItemEntity(SI_VAR(0), SI_VAR(3), SI_VAR(4), SI_VAR(5), 1, 0);
            SetPlayerAnimation(0x60005);
            sleep 30;
            SetPlayerAnimation(ANIM_10002);
            RemoveItemEntity(SI_VAR(0));
        }
    }
    N(func_80241DAC_CF497C)(SI_VAR(10));
    func_802D6954();
    unbind;
});

Script N(80242C08) = {
    SI_CMD(ScriptOpcode_CALL, N(func_80241DE4_CF49B4), SI_VAR(0)),
    SI_CMD(ScriptOpcode_BIND_PADLOCK, N(80242AD4), 0x10, 0, N(D_80244A20), 0, 1),
    SI_CMD(ScriptOpcode_CALL, N(func_80241D58_CF4928), SI_VAR(0)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};

Script N(interact_80242C58) = SCRIPT({
    DisablePlayerInput(TRUE);
    if (SI_SAVE_FLAG(1363) == 0) {
        GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetCamDistance(0, 350);
        SetCamPitch(0, 18.5, -7.5);
        SetCamSpeed(0, 4.0);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_2), NPC_ANIM(gate_flower, Palette_01, Anim_1), 0,
                      MESSAGE_ID(0x11, 0x003B));
        SetPlayerAnimation(ANIM_THINKING);
        N(func_80241FB4_CF4B84)();
        SI_VAR(0) = 0x80245110;
        SI_VAR(1) = 0;
        await N(80242C08);
        match SI_VAR(0) {
            <= 0 {
                SetPlayerAnimation(ANIM_STAND_STILL);
                SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_2), NPC_ANIM(gate_flower, Palette_01, Anim_1), 0, MESSAGE_ID(0x11, 0x003C));
            } else {
                SI_VAR(8) = SI_VAR(0);
                N(func_80241F44_CF4B14)(SI_VAR(0));
                MakeItemEntity(SI_VAR(8), 505, 20, -24, 1, 0);
                SI_VAR(7) = SI_VAR(0);
                PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2095, 0);
                SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_3));
                sleep 20;
                RemoveItemEntity(SI_VAR(7));
                match SI_VAR(8) {
                    == 159 {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_4), NPC_ANIM(gate_flower, Palette_01, Anim_1), 0, MESSAGE_ID(0x11, 0x003F));
                        PlaySoundAtNpc(NPC_SELF, 0x21C, 0);
                        EndSpeech(-1, NPC_ANIM(gate_flower, Palette_01, Anim_9), NPC_ANIM(gate_flower, Palette_01, Anim_8), 0);
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_7));
                        PlaySoundAtCollider(14, 457, 0);
                        ModifyColliderFlags(0, 14, 0x7FFFFE00);
                        MakeLerp(0, 100, 30, 1);
                        loop {
                            UpdateLerp();
                            SI_VAR(8) = (float) SI_VAR(0);
                            SI_VAR(9) = (float) SI_VAR(0);
                            SI_VAR(8) *= 0.5;
                            SI_VAR(9) *= 1.2001953125;
                            RotateModel(86, SI_VAR(8), 0, -1, 0);
                            RotateModel(87, SI_VAR(8), 0, -1, 0);
                            RotateModel(88, SI_VAR(8), 0, -1, 0);
                            RotateModel(82, SI_VAR(9), 0, 1, 0);
                            RotateModel(83, SI_VAR(9), 0, 1, 0);
                            RotateModel(84, SI_VAR(9), 0, 1, 0);
                            sleep 1;
                            if (SI_VAR(1) != 1) {
                                break loop;
                            }
                        }
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_5));
                        SI_SAVE_FLAG(1363) = 1;
                    }
                    == 160 {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_4), NPC_ANIM(gate_flower, Palette_01, Anim_1), 0, MESSAGE_ID(0x11, 0x003E));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_1));
                    }
                    == 158 {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_4), NPC_ANIM(gate_flower, Palette_01, Anim_1), 0, MESSAGE_ID(0x11, 0x003E));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_1));
                    } else {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_4), NPC_ANIM(gate_flower, Palette_01, Anim_1), 0,
                                      MESSAGE_ID(0x11, 0x003D));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_6));
                        PlaySoundAtNpc(NPC_SELF, 0x2096, 0);
                        MakeItemEntity(SI_VAR(8), -125, 20, 0, 1, 0);
                        SI_VAR(7) = SI_VAR(0);
                        sleep 5;
                        GetAngleToPlayer(-1, SI_VAR(0));
                        if (SI_VAR(0) < 180) {
                            MakeLerp(0, 100, 7, 0);
                            loop {
                                UpdateLerp();
                                SI_VAR(2) = -0.5;
                                SI_VAR(3) = -0.19921875;
                                SI_VAR(4) = 0.900390625;
                                SI_VAR(2) *= (float) SI_VAR(0);
                                SI_VAR(3) *= (float) SI_VAR(0);
                                SI_VAR(4) *= (float) SI_VAR(0);
                                SI_VAR(2) += 500.0;
                                SI_VAR(3) += 15.0;
                                SI_VAR(4) += -20.0;
                                N(func_80241E80_CF4A50)(SI_VAR(7), SI_VAR(2), SI_VAR(3), SI_VAR(4));
                                sleep 1;
                                if (SI_VAR(1) != 1) {
                                    break loop;
                                }
                            }
                        } else {
                            MakeLerp(0, 100, 7, 0);
                            loop {
                                UpdateLerp();
                                SI_VAR(2) = 0.5;
                                SI_VAR(3) = -0.19921875;
                                SI_VAR(4) = 0.900390625;
                                SI_VAR(2) *= (float) SI_VAR(0);
                                SI_VAR(3) *= (float) SI_VAR(0);
                                SI_VAR(4) *= (float) SI_VAR(0);
                                SI_VAR(2) += 510.0;
                                SI_VAR(3) += 15.0;
                                SI_VAR(4) += -20.0;
                                N(func_80241E80_CF4A50)(SI_VAR(7), SI_VAR(2), SI_VAR(3), SI_VAR(4));
                                sleep 1;
                                if (SI_VAR(1) != 1) {
                                    break loop;
                                }
                            }
                        }
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_1));
                        RemoveItemEntity(SI_VAR(7));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_1));
                        EndSpeech(-1, NPC_ANIM(gate_flower, Palette_01, Anim_2), NPC_ANIM(gate_flower, Palette_01, Anim_1), 0);
                    }
                }
            }
        }
        spawn {
            ResetCam(0, 6.0);
        }
        sleep 10;
    } else {
        if (STORY_PROGRESS < STORY_CH6_STAR_SPIRIT_RESCUED) {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_9), NPC_ANIM(gate_flower, Palette_01, Anim_8), 0,
                          MESSAGE_ID(0x11, 0x0040));
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_9), NPC_ANIM(gate_flower, Palette_01, Anim_8), 0,
                          MESSAGE_ID(0x11, 0x0041));
        }
    }
    DisablePlayerInput(FALSE);
    unbind;
});

Script N(init_80243564) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80242C58));
    if (SI_SAVE_FLAG(1363) == 1) {
        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_01, Anim_5));
        ModifyColliderFlags(0, 14, 0x7FFFFE00);
        RotateModel(86, 50, 0, -1, 0);
        RotateModel(87, 50, 0, -1, 0);
        RotateModel(88, 50, 0, -1, 0);
        RotateModel(82, 120, 0, 1, 0);
        RotateModel(83, 120, 0, 1, 0);
        RotateModel(84, 120, 0, 1, 0);
    }
});

StaticNpc N(npcGroup_8024368C) = {
    .id = NPC_GATE_FLOWER,
    .settings = &N(npcSettings_802428F0),
    .pos = { 505.0f, 0.0f, -25.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_80243564),
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
        NPC_ANIM(gate_flower, Palette_01, Anim_1),
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DA),
};

StaticNpc N(npcGroup_8024387C) = {
    .id = NPC_TUFF_PUFF,
    .settings = &N(npcSettings_802429D4),
    .pos = { -200.0f, 45.0f, 0.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 10,
    .itemDrops = {
        { ITEM_THUNDER_RAGE, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { -200, 45, 0, 30, 0, -32767, 0, -200, 45, 0, 200 },
    .animations = {
        NPC_ANIM(tuff_puff, Palette_00, Anim_0),
        NPC_ANIM(tuff_puff, Palette_00, Anim_0),
        NPC_ANIM(tuff_puff, Palette_00, Anim_5),
        NPC_ANIM(tuff_puff, Palette_00, Anim_5),
        NPC_ANIM(tuff_puff, Palette_00, Anim_0),
        NPC_ANIM(tuff_puff, Palette_00, Anim_0),
        NPC_ANIM(tuff_puff, Palette_00, Anim_6),
        NPC_ANIM(tuff_puff, Palette_00, Anim_6),
        NPC_ANIM(tuff_puff, Palette_00, Anim_5),
        NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        NPC_ANIM(tuff_puff, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243A6C) = {
    .id = NPC_BZZAP,
    .settings = &N(npcSettings_80242AA0),
    .pos = { 150.0f, 55.0f, 0.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 4,
    .movement = { 150, 50, 0, 30, 0, -32767, 0, 150, 50, 0, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_3),
        NPC_ANIM(bzzap, Palette_00, Anim_3),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_6),
        NPC_ANIM(bzzap, Palette_00, Anim_6),
        NPC_ANIM(bzzap, Palette_00, Anim_4),
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80243C5C) = {
    NPC_GROUP(N(npcGroup_8024387C), BATTLE_ID(24, 34, 0, 6)),
    NPC_GROUP(N(npcGroup_80243A6C), BATTLE_ID(24, 26, 0, 2)),
    NPC_GROUP(N(npcGroup_8024368C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_3C8C) = {
    0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EAB04, -390, 0, 0, 0, ITEM_MAP, MAKE_ENTITY_END);
    AssignPanelFlag(SI_SAVE_FLAG(1407));
});

static s32 N(pad_3CD8)[] = {
    0x00000000, 0x00000000,
};

void N(func_80240040_CF2C10)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = aiSettings->moveTime / 2 + rand_int(aiSettings->moveTime / 2 + 1);
    if (is_point_within_region(enemy->territory->wander.wanderShape,
                               enemy->territory->wander.point.x, enemy->territory->wander.point.z,
                               npc->pos.x, npc->pos.z,
                               enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    } else {
        npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    }
    npc->currentAnim.w = enemy->animList[1];
    script->functionTemp[1].s = 0;
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[0].s = 1;
}

#ifdef NON_MATCHING
// second func_800DCB7C call
void N(func_80241040_BE47F0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
            func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
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
            func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
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
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
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
            if (script->functionTemp[1].s <= 0) {
                script->functionTemp[1].s = aiSettings->unk_14;
                if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) &&
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    func_800494C0(npc, 0x2F4, 0x200000);
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0].s = 10;
                    } else {
                        script->functionTemp[0].s = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1].s--;
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
            script->functionTemp[0].s = 2;
            script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->waitTime <= 0) || (script->functionTemp[1].s < 3)) {
                script->functionTemp[0].s = 0;
            }
        }
    }
}
#else
INCLUDE_ASM(void, "world/area_flo/flo_25/CF2C10", flo_25_func_802401F0_CF2DC0, ScriptInstance* script,
            NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80240C94_CF3864)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_8024291C_CF54EC)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_8024134C_CF3F1C)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

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

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240040_CF2C10)(script, aiSettings, territoryPtr);
        case 1:
            N(func_802401F0_CF2DC0)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80240C94_CF3864)(script, aiSettings, territoryPtr);
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

#include "world/common/UnkNpcAIFunc13.inc.c"

void N(func_80241668_CF4238)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    s32 flag;
    f32 temp_f6;

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1) == 0) {
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 30;
        script->functionTemp[0].s = 20;
        enemy->varTable[9] = 30;
        return;
    }

    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    flag = 0;
    if (!(npc->flags & 8)) {
        x = npc->pos.x;
        y = npc->pos.y + npc->collisionHeight;
        z = npc->pos.z;
        w = npc->collisionHeight + 3.0;
        if ((func_800DCB7C(npc->unk_80, &x, &y, &z, &w) != 0) && (w < npc->collisionHeight)) {
            flag = 1;
        }
    }

    if (flag) {
        npc->pos.y = y + 1.0;
    } else {
        temp_f6 = npc->pos.y - (gPlayerStatusPtr->position.y + 6.0);
        if ((temp_f6 < 0.0) || (temp_f6 > 4.0)) {
            temp_f6 = -temp_f6;
            npc->pos.y += temp_f6 * 0.06;
        }
    }
    if (npc->duration > 0) {
        npc->duration--;
        return;
    }
    script->functionTemp[0].s = 12;
}

#include "world/common/UnkFunc45.inc.c"

ApiStatus N(func_80241944_CF4514)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

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
        script->functionTemp[0].s = 0;
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240040_CF2C10)(script, aiSettings, territoryPtr);
        case 1:
            N(func_802401F0_CF2DC0)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80240C94_CF3864)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, aiSettings, territoryPtr);
        case 13:
            N(func_80241668_CF4238)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(UnkFunc45)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_80241D58_CF4928)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80242ACC_CF569C) = FALSE;
    }

    if (N(D_80242ACC_CF569C)) {
        N(D_80242ACC_CF569C) = FALSE;
        set_variable(script, *args, N(D_80242AD0_CF56A0));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80241DAC_CF497C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80242AD0_CF56A0) = get_variable(script, *args);
    N(D_80242ACC_CF569C) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241DE4_CF49B4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i <= 90; i++) {
            N(D_80244A20)[i] = i + 128;
            N(D_80244A20)[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241E80_CF4A50)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    ItemEntity* item = get_item_entity(itemIdx);

    item->position.x = var1;
    item->position.y = var2;
    item->position.z = var3;

    return ApiStatus_DONE2;
}

ApiStatus N(func_80241F44_CF4B14)(ScriptInstance* script, s32 isInitialCall) {
    s32 itemId = get_variable(script, *script->ptrReadPos);
    StaticItem* item = &gItemTable[itemId];

    if (itemId == ITEM_YUMMY_MEAL) {
        script->varTable[9] = 2;
    } else if (item->typeFlags & 0x80) {
        script->varTable[9] = 1;
    } else {
        script->varTable[9] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80241FB4_CF4B84)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i <= 90; i++) {
        N(D_80245110)[i] = 128 + i;
    }

    N(D_8024527C) = 0;
    return ApiStatus_DONE2;
}
