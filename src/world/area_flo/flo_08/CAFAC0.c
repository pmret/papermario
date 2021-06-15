#include "flo_08.h"
#include "message_ids.h"
#include "sprite/npc/dayzee.h"
#include "sprite/npc/gate_flower.h"

enum {
    NPC_GATE_FLOWER,
    NPC_DAYZEE0,
    NPC_DAYZEE1,
    NPC_DAYZEE2,
    NPC_DAYZEE3,
    NPC_DAYZEE4,
    NPC_DAYZEE5,
    NPC_DAYZEE6,
    NPC_DAYZEE7,
};

// BSS
static s32 N(D_802462C0_B4AA30)[91];
static s8 N(D_802462C4_pad);
static s32 N(D_80246428)[91];
static s32 N(D_8024659C);

// DATA
EntryList N(entryList) = {
    { -870.0f, 0.0f, 0.0f,  90.0f },
    {  570.0f, 0.0f, 0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_08_tattle },
};

Script N(80241F40) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
        } else {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
        }
    }
});

s32 N(D_80241FB0_CB0CF0)[] = {
    0x001D00F0, 0x001D00F1,
};

s16 N(D_80241FB8_CB0CF8)[] = {
    0x0001, 0x0002, 0x0003, 0x0004,
    0x0009, 0x0006, 0x0007, 0x0008
};

s32 N(D_80241FC8_CB0D08)[8][2] = {
    { 0x001D00E0, 0x001D00E1 }, { 0x001D00E2, 0x001D00E3 },
    { 0x001D00E4, 0x001D00E5 }, { 0x001D00E6, 0x001D00E7 },
    { 0x001D00E8, 0x001D00E9 }, { 0x001D00EA, 0x001D00EB },
    { 0x001D00EC, 0x001D00ED }, { 0x001D00EE, 0x001D00EF }
};

f32 N(D_80242008_CB0D48)[3] = {
    140.0f, 180.0f, 220.0f
};

Script N(80242014) = SCRIPT({
    sleep 10;
    PlaySound(0x212D);
    N(UnkFunc21)(SI_MAP_VAR(0));
    sleep 85;
    spawn {
        PlaySound(0x212E);
        N(UnkFunc23)(70, 70);
        sleep 27;
        PlaySound(SOUND_UNKNOWN_208E);
        N(UnkFunc23)(50, 50);
    }
    spawn {
        sleep 3;
        N(func_8024003C_CAED7C)(SI_MAP_VAR(0));
    }
    spawn {
        sleep 47;
        N(UnkFunc22)();
        N(UnkPartnerPosFunc)();
        sleep 5;
        N(UnkPartnerPosFunc2)();
        sleep 5;
        N(UnkPartnerPosFunc)();
    }
    sleep 3;
    N(func_80240600_CAF340)(SI_MAP_VAR(0));
    sleep 30;
});

Script N(80242178) = SCRIPT({
    if (SI_SAVE_FLAG(1402) == 1) {
        return;
    }
    IsStartingConversation(SI_VAR(0));
    if (SI_VAR(0) == 1) {
        return;
    }
    N(UnkFunc40)();
    if (SI_VAR(0) == 1) {
        return;
    }
    func_802D585C(1, 2097152);
    N(SetOverrideFlags_40)();
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), TRUE);
    N(UnkFunc20)(SI_MAP_VAR(0), SI_VAR(9));
    FindKeyItem(ITEM_ULTRA_STONE, SI_VAR(12));
    N(UnkFunc38)();
    if (SI_VAR(0) == -1) {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DC), 160, 40);
        sleep 10;
        N(UnkFunc39)(SI_VAR(9));
        DisablePlayerInput(FALSE);
        EnablePartnerAI();
        func_802D585C(0, 2097152);
        N(UnkFunc17)();
        return;
    }
    if (SI_SAVE_FLAG(438) == 0) {
        SI_SAVE_FLAG(438) = 1;
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DA), 160, 40);
    } else {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DB), 160, 40);
    }
    N(func_802401CC_CAEF0C)();
    if (SI_VAR(0) == -1) {
        N(UnkFunc39)(SI_VAR(9));
        DisablePlayerInput(FALSE);
        EnablePartnerAI();
        func_802D585C(0, 2097152);
        N(UnkFunc17)();
        return;
    }
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(11) = SI_VAR(1);
    EnablePartnerAI();
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != SI_VAR(11)) {
        N(func_8024041C_CAF15C)(SI_VAR(11));
    } else {
        func_802CF56C(2);
    }
    sleep 10;
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DF), 160, 40);
    ShowChoice(MESSAGE_ID(0x1E, 0x000D));
    CloseMessage();
    if (SI_VAR(0) != 0) {
        N(UnkFunc39)(SI_VAR(9));
        DisablePlayerInput(FALSE);
        EnablePartnerAI();
        func_802D585C(0, 2097152);
        N(UnkFunc17)();
        return;
    }
    await N(80242014);
    N(UnkFunc18)(SI_VAR(11), SI_VAR(13));
    SI_SAVE_FLAG(1402) = 1;
    N(UnkFunc39)(SI_VAR(9));
    N(UnkFunc19)();
    if (SI_VAR(13) == 1) {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DD), 160, 40);
    } else {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DE), 160, 40);
    }
    DisablePlayerInput(FALSE);
    EnablePartnerAI();
    func_802D585C(0, 2097152);
    N(UnkFunc17)();
});

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA910, -780, 120, -110, 0, MAKE_ENTITY_END);
    SI_MAP_VAR(0) = SI_VAR(0);
    AssignBlockFlag(SI_SAVE_FLAG(1402));
    AssignScript(N(80242178));
    MakeItemEntity(ITEM_STAR_PIECE, 510, 0, -90, 17, SI_SAVE_FLAG(1381));
});

Script N(80242680) = SCRIPT({
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

Script N(exitWalk_8024292C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  6);

Script N(exitWalk_80242988) = EXIT_WALK_SCRIPT(60,  1, "flo_24",  0);

Script N(802429E4) = SCRIPT({
    bind N(exitWalk_8024292C) to TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_80242988) to TRIGGER_FLOOR_ABOVE 4;
});

s32 N(lavaResetList_80242A2C)[] = {
    0x00000009, 0xC4070000, 0x00000000, 0x42480000, 0x0000000A, 0x42700000, 0x00000000, 0x42480000,
    0x0000000F, 0x42700000, 0x00000000, 0x42480000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80244EC4));
    await N(makeEntities);
    spawn N(80245F5C);
    ModifyColliderFlags(3, 19, 0x00000002);
    spawn {
        ResetFromLava(N(lavaResetList_80242A2C));
    }
    EnableTexPanning(22, 1);
    EnableTexPanning(23, 1);
    EnableTexPanning(25, 1);
    EnableTexPanning(27, 1);
    EnableTexPanning(29, 1);
    EnableTexPanning(31, 1);
    EnableTexPanning(41, 1);
    EnableTexPanning(24, 1);
    EnableTexPanning(26, 1);
    EnableTexPanning(28, 1);
    EnableTexPanning(30, 1);
    EnableTexPanning(32, 1);
    spawn {
        SI_VAR(0) = 0;
        SI_VAR(1) = 0;
0:
        SI_VAR(0) += 140;
        if (SI_VAR(0) > 65536) {
            SI_VAR(0) += -65536;
        }
        SetTexPanOffset(1, 0, SI_VAR(0), 0);
        SI_VAR(1) += -200;
        if (SI_VAR(1) < 0) {
            SI_VAR(1) += 65536;
        }
        SetTexPanOffset(2, 0, SI_VAR(1), 0);
        sleep 1;
        goto 0;
    }
    ModifyColliderFlags(3, 21, 0x00000006);
    SI_VAR(0) = 140;
    SI_VAR(1) = -137;
    SI_VAR(2) = 340;
    SI_VAR(3) = -60;
    SI_VAR(4) = 0;
    spawn N(80242680);
    SI_VAR(0) = 450;
    SI_VAR(1) = -137;
    SI_VAR(2) = 590;
    SI_VAR(3) = -60;
    SI_VAR(4) = 0;
    spawn N(80242680);
    spawn N(80245914);
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    SI_VAR(0) = N(802429E4);
    spawn EnterWalk;
    await N(80241F40);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240D40_CAFA80)();
    }
});

static s32 N(pad_2EA8)[] = {
    0x00000000, 0x00000000,
};

NpcAISettings N(npcAISettings_80242EB0) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 3,
    .chaseSpeed = 2.4f,
    .unk_1C = { .s = 15 },
    .unk_20 = 1,
    .chaseRadius = 140.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 1,
};

Script N(npcAI_80242EE0) = SCRIPT({
    N(func_8024150C_CB024C)(N(npcAISettings_80242EB0));
});

Script N(80242F00) = SCRIPT({
0:
    GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 30;
    SI_VAR(2) -= 2;
    PlayEffect(0x11, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2), 30, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep 15;
    goto 0;
});

NpcSettings N(npcSettings_80242FB4) = {
    .height = 30,
    .radius = 24,
    .ai = &N(npcAI_80242EE0),
    .onHit = EnemyNpcHit,
    .aux = &N(80242F00),
    .onDefeat = EnemyNpcDefeat,
    .level = 100,
};

NpcSettings N(npcSettings_80242FE0) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

NpcAISettings N(npcAISettings_8024300C) = {
    .moveSpeed = 1.0f,
    .moveTime = 500,
    .waitTime = 10,
    .alertRadius = 50.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 3,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 40 },
    .unk_20 = 3,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 1,
};

Script N(npcAI_8024303C) = SCRIPT({
    DoBasicAI(N(npcAISettings_8024300C));
});

NpcSettings N(npcSettings_8024305C) = {
    .height = 30,
    .radius = 24,
    .ai = &N(npcAI_8024303C),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

s32 N(D_80243088_CB1DC8) = FALSE;

s32 N(D_8024308C_CB1DCC) = {
    0x00000000,
};

Script N(80243090) = SCRIPT({
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
    N(func_802419C4_CB0704)(SI_VAR(10));
    func_802D6954();
    unbind;
});

Script N(802431C4) = {
    SI_CMD(ScriptOpcode_CALL, N(func_802419FC_CB073C), SI_VAR(0)),
    SI_CMD(ScriptOpcode_BIND_PADLOCK, N(80243090), 0x10, 0, N(D_802462C0_B4AA30), 0, 1),
    SI_CMD(ScriptOpcode_CALL, N(func_80241970_CB06B0), SI_VAR(0)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};

Script N(interact_80243214) = SCRIPT({
    DisablePlayerInput(TRUE);
    if (SI_SAVE_FLAG(1364) == 0) {
        GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetCamDistance(0, 350);
        SetCamPitch(0, 18.5, -7.5);
        SetCamSpeed(0, 4.0);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_2), NPC_ANIM(gate_flower, Palette_02, Anim_1), 0,
                      MESSAGE_ID(0x11, 0x0042));
        SetPlayerAnimation(ANIM_THINKING);
        N(func_80241BCC_CB090C)();
        SI_VAR(0) = 0x80246430;
        SI_VAR(1) = 0;
        await N(802431C4);
        match SI_VAR(0) {
            <= 0 {
                SetPlayerAnimation(ANIM_STAND_STILL);
                SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_2), NPC_ANIM(gate_flower, Palette_02, Anim_1), 0, MESSAGE_ID(0x11, 0x0043));
            } else {
                SI_VAR(8) = SI_VAR(0);
                N(func_80241B5C_CB089C)(SI_VAR(0));
                MakeItemEntity(SI_VAR(8), -695, 20, -29, 1, 0);
                SI_VAR(7) = SI_VAR(0);
                PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2095, 0);
                SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_3));
                sleep 20;
                RemoveItemEntity(SI_VAR(7));
                match SI_VAR(8) {
                    == 160 {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_4), NPC_ANIM(gate_flower, Palette_02, Anim_1), 0, MESSAGE_ID(0x11, 0x0046));
                        PlaySoundAtNpc(NPC_SELF, 0x21C, 0);
                        EndSpeech(-1, NPC_ANIM(gate_flower, Palette_02, Anim_9), NPC_ANIM(gate_flower, Palette_02, Anim_8), 0);
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_7));
                        PlaySoundAtCollider(17, 457, 0);
                        ModifyColliderFlags(0, 17, 0x7FFFFE00);
                        MakeLerp(0, 100, 30, 1);
                        loop {
                            UpdateLerp();
                            SI_VAR(8) = (float) SI_VAR(0);
                            SI_VAR(9) = (float) SI_VAR(0);
                            SI_VAR(8) *= 0.5;
                            SI_VAR(9) *= 1.2001953125;
                            RotateModel(103, SI_VAR(8), 0, 1, 0);
                            RotateModel(104, SI_VAR(8), 0, 1, 0);
                            RotateModel(105, SI_VAR(8), 0, 1, 0);
                            RotateModel(99, SI_VAR(9), 0, -1, 0);
                            RotateModel(100, SI_VAR(9), 0, -1, 0);
                            RotateModel(101, SI_VAR(9), 0, -1, 0);
                            sleep 1;
                            if (SI_VAR(1) != 1) {
                                break loop;
                            }
                        }
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_5));
                        SI_SAVE_FLAG(1364) = 1;
                    }
                    == 159 {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_4), NPC_ANIM(gate_flower, Palette_02, Anim_1), 0, MESSAGE_ID(0x11, 0x0045));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_1));
                    }
                    == 158 {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_4), NPC_ANIM(gate_flower, Palette_02, Anim_1), 0, MESSAGE_ID(0x11, 0x0045));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_1));
                    } else {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_4), NPC_ANIM(gate_flower, Palette_02, Anim_1), 0,
                                      MESSAGE_ID(0x11, 0x0044));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_6));
                        PlaySoundAtNpc(NPC_SELF, 0x2096, 0);
                        MakeItemEntity(SI_VAR(8), 125, 20, 0, 1, 0);
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
                                SI_VAR(2) += -700.0;
                                SI_VAR(3) += 15.0;
                                SI_VAR(4) += -25.0;
                                N(func_80241A98_CB07D8)(SI_VAR(7), SI_VAR(2), SI_VAR(3), SI_VAR(4));
                                sleep 1;
                                if (SI_VAR(1) == 0) {
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
                                SI_VAR(2) += -690.0;
                                SI_VAR(3) += 15.0;
                                SI_VAR(4) += -25.0;
                                N(func_80241A98_CB07D8)(SI_VAR(7), SI_VAR(2), SI_VAR(3), SI_VAR(4));
                                sleep 1;
                                if (SI_VAR(1) == 0) {
                                    break loop;
                                }
                            }
                        }
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_1));
                        RemoveItemEntity(SI_VAR(7));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_1));
                        EndSpeech(-1, NPC_ANIM(gate_flower, Palette_02, Anim_2), NPC_ANIM(gate_flower, Palette_02, Anim_1), 0);
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
            SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_9), NPC_ANIM(gate_flower, Palette_02, Anim_8), 0,
                          MESSAGE_ID(0x11, 0x0047));
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_9), NPC_ANIM(gate_flower, Palette_02, Anim_8), 0,
                          MESSAGE_ID(0x11, 0x0048));
        }
    }
    DisablePlayerInput(FALSE);
    unbind;
});

Script N(init_80243B20) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80243214));
    if (SI_SAVE_FLAG(1364) == 1) {
        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_02, Anim_5));
        ModifyColliderFlags(0, 17, 0x7FFFFE00);
        RotateModel(103, 50, 0, 1, 0);
        RotateModel(104, 50, 0, 1, 0);
        RotateModel(105, 50, 0, 1, 0);
        RotateModel(99, 120, 0, -1, 0);
        RotateModel(100, 120, 0, -1, 0);
        RotateModel(101, 120, 0, -1, 0);
    }
});

StaticNpc N(npcGroup_80243C48) = {
    .id = NPC_GATE_FLOWER,
    .settings = &N(npcSettings_80242FE0),
    .pos = { -695.0f, 0.0f, -30.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_80243B20),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
        NPC_ANIM(gate_flower, Palette_02, Anim_1),
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DB),
};

StaticNpc N(npcGroup_80243E38) = {
    .id = NPC_DAYZEE0,
    .settings = &N(npcSettings_8024305C),
    .pos = { 205.0f, 0.0f, -80.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { 205, 0, -80, 30, 0, -32767, 0, 205, 0, -80, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_2),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_6),
        NPC_ANIM(dayzee, Palette_00, Anim_7),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244028) = {
    .id = NPC_DAYZEE1,
    .settings = &N(npcSettings_8024305C),
    .pos = { 275.0f, 0.0f, -115.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 270,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { 275, 0, -115, 30, 0, -32767, 0, 275, 0, -115, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_2),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_6),
        NPC_ANIM(dayzee, Palette_00, Anim_7),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244218) = {
    .id = NPC_DAYZEE2,
    .settings = &N(npcSettings_8024305C),
    .pos = { -230.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { -230, 60, -110, 30, 0, -32767, 0, -230, 60, -110, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_2),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_6),
        NPC_ANIM(dayzee, Palette_00, Anim_7),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244408) = {
    .id = NPC_DAYZEE3,
    .settings = &N(npcSettings_8024305C),
    .pos = { -330.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 270,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { -330, 60, -110, 30, 0, -32767, 0, -330, 60, -110, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_2),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_6),
        NPC_ANIM(dayzee, Palette_00, Anim_7),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802445F8) = {
    .id = NPC_DAYZEE4,
    .settings = &N(npcSettings_8024305C),
    .pos = { -430.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { -430, 60, -110, 30, 0, -32767, 0, -430, 60, -110, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_2),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_6),
        NPC_ANIM(dayzee, Palette_00, Anim_7),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802447E8) = {
    .id = NPC_DAYZEE5,
    .settings = &N(npcSettings_8024305C),
    .pos = { -530.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 270,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { -530, 60, -110, 30, 0, -32767, 0, -530, 60, -110, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_2),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_6),
        NPC_ANIM(dayzee, Palette_00, Anim_7),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802449D8) = {
    .id = NPC_DAYZEE6,
    .settings = &N(npcSettings_8024305C),
    .pos = { -630.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { -630, 60, -110, 30, 0, -32767, 0, -630, 60, -110, 150, 0, 0, 1 },
    .animations = {
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_2),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_6),
        NPC_ANIM(dayzee, Palette_00, Anim_7),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

Script N(init_80244BC8) = SCRIPT({
    spawn {
        sleep 2;
        GetNpcPointer(2, SI_VAR(0));
        if (SI_VAR(0) == 0) {
            RemoveNpc(NPC_SELF);
            return;
        }
        RandInt(100, SI_VAR(0));
        if (SI_VAR(0) < 30) {
            SetNpcFlagBits(NPC_DAYZEE1, ((0x00000002 | NPC_FLAG_4)), TRUE);
            SetNpcPos(NPC_DAYZEE1, 0, -1000, 0);
        } else {
            SetNpcFlagBits(NPC_SELF, ((0x00000002 | NPC_FLAG_4)), TRUE);
            SetNpcPos(NPC_SELF, 0, -1000, 0);
        }
    }
});

StaticNpc N(npcGroup_80244CD4) = {
    .id = NPC_DAYZEE7,
    .settings = &N(npcSettings_80242FB4),
    .pos = { 240.0f, 0.0f, -90.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .init = &N(init_80244BC8),
    .yaw = 270,
    .dropFlags = 0x80,
    .itemDropChance = 20,
    .itemDrops = {
        { ITEM_HONEY_SYRUP, 24, 0 },
        { ITEM_MAPLE_SYRUP, 25, 0 },
        { ITEM_JAMMIN_JELLY, 1, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(6),
    .minCoinBonus = 5,
    .maxCoinBonus = 8,
    .movement = { 240, 0, -90, 30, 0, -32767, 0, 240, 0, -90, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(dayzee, Palette_01, Anim_1),
        NPC_ANIM(dayzee, Palette_01, Anim_2),
        NPC_ANIM(dayzee, Palette_01, Anim_3),
        NPC_ANIM(dayzee, Palette_01, Anim_3),
        NPC_ANIM(dayzee, Palette_01, Anim_1),
        NPC_ANIM(dayzee, Palette_01, Anim_1),
        NPC_ANIM(dayzee, Palette_01, Anim_8),
        NPC_ANIM(dayzee, Palette_01, Anim_8),
        NPC_ANIM(dayzee, Palette_01, Anim_6),
        NPC_ANIM(dayzee, Palette_01, Anim_7),
        NPC_ANIM(dayzee, Palette_01, Anim_1),
        NPC_ANIM(dayzee, Palette_01, Anim_1),
        NPC_ANIM(dayzee, Palette_01, Anim_1),
        NPC_ANIM(dayzee, Palette_01, Anim_1),
        NPC_ANIM(dayzee, Palette_01, Anim_1),
        NPC_ANIM(dayzee, Palette_01, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80244EC4) = {
    NPC_GROUP(N(npcGroup_80243C48), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243E38), BATTLE_ID(24, 20, 0, 1)),
    NPC_GROUP(N(npcGroup_80244028), BATTLE_ID(24, 15, 0, 1)),
    NPC_GROUP(N(npcGroup_80244218), BATTLE_ID(24, 15, 0, 2)),
    NPC_GROUP(N(npcGroup_80244408), BATTLE_ID(24, 15, 0, 2)),
    NPC_GROUP(N(npcGroup_802445F8), BATTLE_ID(24, 15, 0, 2)),
    NPC_GROUP(N(npcGroup_802447E8), BATTLE_ID(24, 15, 0, 2)),
    NPC_GROUP(N(npcGroup_802449D8), BATTLE_ID(24, 18, 0, 2)),
    NPC_GROUP(N(npcGroup_80244CD4), BATTLE_ID(24, 28, 0, 1)),
    {},
};

static s32 N(pad_4F3C) = {
    0x00000000,
};

void N(func_80240D80_CAFAC0)(ScriptInstance* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    f32 temp_f0;
    f32 temp_f20;
    f64 temp_f2;
    f32 phi_f22;
    f32 phi_f24;
    f32 phi_f26;
    s32 phi_s3;

    f32 subroutine_arg8;
    f32 subroutine_arg9;
    f32 subroutine_argA;
    f32 subroutine_argB;
    f32 subroutine_argC;
    f32 subroutine_argD;
    f32 subroutine_argE;
    f32 subroutine_argF;
    f32 subroutine_arg10;

    npc->duration = npcAISettings->unk_20 / 2 + rand_int(npcAISettings->unk_20 / 2 + 1);
    npc->currentAnim.w = enemy->animList[3];
    npc->moveSpeed = npcAISettings->chaseSpeed;
    phi_s3 = FALSE;

    temp_f20 = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                 gPlayerStatusPtr->position.z) + 180.0f);
    temp_f0 = get_clamped_angle_diff(npc->yaw, temp_f20);
    if (npcAISettings->unk_1C.s < fabsf(temp_f0)) {
        temp_f20 = npc->yaw;
        if (temp_f0 < 0.0f) {
            temp_f20 += -npcAISettings->unk_1C.s;
        } else {
            temp_f20 += npcAISettings->unk_1C.s;
        }
    }

    npc->yaw = clamp_angle(temp_f20);

    subroutine_arg8 = npc->pos.x;
    subroutine_arg9 = npc->pos.y;
    subroutine_argA = npc->pos.z;

    temp_f20 = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                 gPlayerStatusPtr->position.z) + 180.0f);
    phi_f22 = 0.0f;
    phi_f24 = 0.0f;
    phi_f26 = 0.0f;

    if (func_800DDCEC(npc->unk_80, &subroutine_arg8, &subroutine_arg9, &subroutine_argA, npc->moveSpeed * 4.5, temp_f20,
                      npc->collisionHeight, npc->collisionRadius) != 0) {
        phi_f22 = dist2D(npc->pos.x, npc->pos.z, subroutine_arg8, subroutine_argA);

        subroutine_argB = npc->pos.x;
        subroutine_argC = npc->pos.y;
        subroutine_argD = npc->pos.z;

        if (func_800DDCEC(npc->unk_80, &subroutine_argB, &subroutine_argC, &subroutine_argD, npc->moveSpeed * 4.5,
                          clamp_angle(temp_f20 + 35.0f), npc->collisionHeight, npc->collisionRadius) != 0) {
            phi_f24 = dist2D(npc->pos.x, npc->pos.z, subroutine_argB, subroutine_argD);
        }

        subroutine_argE = npc->pos.x;
        subroutine_argF = npc->pos.y;
        subroutine_arg10 = npc->pos.z;

        if (func_800DDCEC(npc->unk_80, &subroutine_argE, &subroutine_argF, &subroutine_arg10, npc->moveSpeed * 4.5,
                          clamp_angle(temp_f20 - 35.0f), npc->collisionHeight, npc->collisionRadius) != 0) {
            phi_f26 = dist2D(npc->pos.x, npc->pos.z, subroutine_argE, subroutine_arg10);
        }

        dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);

        if ((phi_f22 < npc->moveSpeed * 1.5) && (phi_f24 < npc->moveSpeed * 1.5) && (phi_f26 < npc->moveSpeed * 1.5) &&
            (func_800490B4(territory, enemy, npcAISettings->alertRadius, npcAISettings->unk_10.f, 0) != 0)) {
            phi_s3 = TRUE;
        }

        if (!phi_s3) {
            if ((phi_f24 < phi_f22) && (phi_f26 < phi_f24)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_arg8, subroutine_argA);
            } else if ((phi_f24 < phi_f22) && (phi_f24 < phi_f26)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_arg8, subroutine_argA);
            } else if ((phi_f22 < phi_f24) && (phi_f26 < phi_f22)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argB, subroutine_argD);
            } else if ((phi_f26 < phi_f24) && (phi_f22 < phi_f26)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argB, subroutine_argD);
            } else if ((phi_f22 < phi_f26) && (phi_f24 < phi_f22)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argE, subroutine_arg10);
            } else if ((phi_f24 < phi_f26) && (phi_f22 < phi_f24)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argE, subroutine_arg10);
            }

            temp_f0 = get_clamped_angle_diff(npc->yaw, temp_f20);
            if (npcAISettings->unk_1C.s < fabsf(temp_f0)) {
                temp_f20 = npc->yaw;
                if (temp_f0 < 0.0f) {
                    temp_f20 += -npcAISettings->unk_1C.s;
                } else {
                    temp_f20 += npcAISettings->unk_1C.s;
                }
            }
            npc->yaw = clamp_angle(temp_f20);
        }
    }
    if (phi_s3) {
        npc->duration = 0xA;
        npc->currentAnim.w = enemy->animList[8];
    }
    script->functionTemp[0].s = 0xD;
}

void N(func_80241364_CB00A4)(ScriptInstance* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (func_800490B4(territory, enemy, npcAISettings->chaseRadius, npcAISettings->unk_28.f, 1) == 0) {
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 25;
        script->functionTemp[0].s = 14;
    } else {
        if (npc->currentAnim.w != enemy->animList[8]) {
            if (npc->moveSpeed < 4.0) {
                func_8003D660(npc, 0);
            } else {
                func_8003D660(npc, 1);
            }
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        }
        if (npc->duration > 0) {
            npc->duration--;
            return;
        } else {
            script->functionTemp[0].s = 12;
        }
    }
}

void N(func_802414C8_CB0208)(ScriptInstance* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        script->functionTemp[0].s = NULL;
    }
}

ApiStatus N(func_8024150C_CB024C)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
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
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
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
            N(func_80240D80_CAFAC0)(script, npcAISettings, territoryPtr);
        case 13:
            N(func_80241364_CB00A4)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(func_802414C8_CB0208)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_80241970_CB06B0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80243088_CB1DC8) = FALSE;
    }

    if (N(D_80243088_CB1DC8)) {
        N(D_80243088_CB1DC8) = FALSE;
        set_variable(script, *args, N(D_8024308C_CB1DCC));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_802419C4_CB0704)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_8024308C_CB1DCC) = get_variable(script, *args);
    N(D_80243088_CB1DC8) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(func_802419FC_CB073C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_802462C0_B4AA30)[i] = ptr[i];
        }
        N(D_802462C0_B4AA30)[i] = 0;
    } else {
        for (i = 0; i <= 90; i++) {
            N(D_802462C0_B4AA30)[i] = i + 128;
            N(D_802462C0_B4AA30)[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241A98_CB07D8)(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus N(func_80241B5C_CB089C)(ScriptInstance* script, s32 isInitialCall) {
    s32 itemId = get_variable(script, *script->ptrReadPos);
    StaticItem* item = &gItemTable[itemId];

    if (itemId == ITEM_YUMMY_MEAL) {
        script->varTable[9].s = 2;
    } else if (item->typeFlags & 0x80) {
        script->varTable[9].s = 1;
    } else {
        script->varTable[9].s = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80241BCC_CB090C)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i <= 90; i++) {
        N(D_80246428)[i] = 128 + i;
    }

    N(D_8024659C) = 0;
    return ApiStatus_DONE2;
}

#include "world/common/foliage.inc.c"

FoliageModelList N(tree1_Leaves) = {
    .count = 1,
    .models = { 46 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 45 }
};

FoliageDropList N(tree1_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_BLUE_BERRY,
            .pos = { 340, 102, -89 },
            .spawnMode = 0xC,
            .spawnFlag = SI_AREA_FLAG(29),
        },
        {
            .itemID = ITEM_BLUE_BERRY,
            .pos = { 440, 102, -89 },
            .spawnMode = 0xC,
            .spawnFlag = SI_AREA_FLAG(30),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_80245904) = { 391.0f, 0.0f, -102.0f, 0.0f };

Script N(80245914) = SCRIPT({
    SI_AREA_FLAG(29) = 0;
    SI_AREA_FLAG(30) = 0;
    SI_VAR(0) = N(tree1);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 22;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_80245904);
});

static s32 N(pad_598C) = {
    0x00000000,
};

Script N(80245990) = SCRIPT({
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

Script N(80245C3C) = SCRIPT({
    SI_VAR(9) = SI_VAR(6);
    SI_VAR(8) = SI_VAR(5);
    SI_VAR(7) = SI_VAR(4);
    SI_VAR(6) = SI_VAR(3);
    SI_VAR(5) = SI_VAR(2);
    SI_VAR(4) = SI_VAR(1);
    SI_VAR(3) = SI_VAR(0);
    EnableModel(SI_VAR(6), 0);
0:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    N(UnkFunc43)();
    if (SI_VAR(0) == 0) {
        sleep 1;
        goto 0;
    }
    spawn {
        sleep 5;
        EnableModel(SI_VAR(6), 1);
    }
    if (SI_VAR(10) != 0) {
        spawn {
            sleep 5;
            SI_VAR(0) = SI_VAR(3);
            SI_VAR(1) = SI_VAR(4);
            SI_VAR(2) = SI_VAR(5);
            SI_VAR(1) += 10;
            SI_VAR(2) += 8;
            PlayEffect(0x11, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 15, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 15;
            SI_VAR(1) -= 10;
            MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 14, 0);
        }
    }
    spawn {
        sleep 10;
        PlaySoundAt(0xF8, 0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    }
    MakeLerp(0, 180, 20, 2);
1:
    UpdateLerp();
    RotateModel(SI_VAR(8), SI_VAR(0), 1, 0, 0);
    RotateModel(SI_VAR(9), SI_VAR(0), 1, 0, 0);
    if (SI_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
    EnableModel(SI_VAR(7), 0);
});

Script N(80245F5C) = SCRIPT({
    GetModelCenter(60);
    SI_VAR(3) = 60;
    SI_VAR(4) = 61;
    SI_VAR(5) = 62;
    SI_VAR(6) = 63;
    SI_VAR(10) = 0;
    spawn N(80245C3C);
    GetModelCenter(54);
    SI_VAR(3) = 54;
    SI_VAR(4) = 55;
    SI_VAR(5) = 56;
    SI_VAR(6) = 57;
    SI_VAR(10) = 0;
    spawn N(80245C3C);
    GetModelCenter(48);
    SI_VAR(3) = 48;
    SI_VAR(4) = 49;
    SI_VAR(5) = 50;
    SI_VAR(6) = 51;
    SI_VAR(10) = 0;
    spawn N(80245C3C);
    GetModelCenter(67);
    SI_VAR(3) = 67;
    SI_VAR(4) = 66;
    SI_VAR(5) = 68;
    SI_VAR(6) = 69;
    SI_VAR(10) = 174;
    spawn N(80245C3C);
});
