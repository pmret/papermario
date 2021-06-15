#include "flo_23.h"
#include "message_ids.h"
#include "sprite/npc/gate_flower.h"
#include "sprite/npc/spiny.h"

enum {
    NPC_SPINY0,
    NPC_SPINY1,
    NPC_GATE_FLOWER,
};

static s32 N(D_802426E0)[91];
static s8 N(D_8024284C_pad)[4];
static s32 N(D_80242850)[91];
static s32 N(D_802429BC);

EntryList N(entryList) = {
    {  470.0f, 0.0f, 0.0f, 270.0f },
    { -470.0f, 0.0f, 0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_23_tattle },
};

Script N(80240D30) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
        } else {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
        }
    }
});

Script N(80240DA0) = SCRIPT({
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

Script N(exitWalk_8024104C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  2);

Script N(exitWalk_802410A8) = EXIT_WALK_SCRIPT(60,  1, "flo_11",  0);

Script N(80241104) = SCRIPT({
    bind N(exitWalk_802410A8) to TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_8024104C) to TRIGGER_FLOOR_ABOVE 4;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80242568));
    await N(makeEntities);
    SI_VAR(0) = -290;
    SI_VAR(1) = -190;
    SI_VAR(2) = 480;
    SI_VAR(3) = -90;
    SI_VAR(4) = 0;
    spawn N(80240DA0);
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    SI_VAR(0) = N(80241104);
    spawn EnterWalk;
    await N(80240D30);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_CEE260)();
    }
});

static s32 N(pad_12D8)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_802412E0) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

s32 N(D_8024130C_CEF56C) = {
    0x00000000,
};

s32 N(D_80241310_CEF570) = {
    0x00000000,
};

Script N(80241314) = SCRIPT({
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
    N(func_802402C0_CEE520)(SI_VAR(10));
    func_802D6954();
    unbind;
});

Script N(80241448) = {
    SI_CMD(ScriptOpcode_CALL, N(func_802402F8_CEE558), SI_VAR(0)),
    SI_CMD(ScriptOpcode_BIND_PADLOCK, N(80241314), 0x10, 0, N(D_802426E0), 0, 1),
    SI_CMD(ScriptOpcode_CALL, N(func_8024026C_CEE4CC), SI_VAR(0)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};

NpcAISettings N(npcAISettings_80241498) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 60.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 3,
};

Script N(npcAI_802414C8) = SCRIPT({
    SetSelfVar(2, 3);
    SetSelfVar(3, 18);
    SetSelfVar(5, 3);
    SetSelfVar(7, 4);
    N(func_80240728_CEE988)(N(npcAISettings_80241498));
});

NpcSettings N(npcSettings_80241538) = {
    .height = 21,
    .radius = 22,
    .ai = &N(npcAI_802414C8),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

Script N(interact_80241564) = SCRIPT({
    DisablePlayerInput(TRUE);
    if (SI_SAVE_FLAG(1365) == 0) {
        GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetCamDistance(0, 350);
        SetCamPitch(0, 18.5, -7.5);
        SetCamSpeed(0, 4.0);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_2), NPC_ANIM(gate_flower, Palette_00, Anim_1), 0,
                      MESSAGE_ID(0x11, 0x0049));
        SetPlayerAnimation(ANIM_THINKING);
        N(func_80240C9C_CEEEFC)();
        SI_VAR(0) = N(D_80242850);
        SI_VAR(1) = 2;
        await N(80241448);
        match SI_VAR(0) {
            <= 0 {
                SetPlayerAnimation(ANIM_STAND_STILL);
                SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_2), NPC_ANIM(gate_flower, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x004A));
            } else {
                SI_VAR(8) = SI_VAR(0);
                N(func_80240C2C_CEEE8C)(SI_VAR(0));
                MakeItemEntity(SI_VAR(8), 385, 20, -34, 1, 0);
                SI_VAR(7) = SI_VAR(0);
                PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2095, 0);
                SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_3));
                sleep 20;
                RemoveItemEntity(SI_VAR(7));
                match SI_VAR(8) {
                    == 158 {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_4), NPC_ANIM(gate_flower, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x004D));
                        PlaySoundAtNpc(NPC_SELF, 0x21C, 0);
                        EndSpeech(-1, NPC_ANIM(gate_flower, Palette_00, Anim_9), NPC_ANIM(gate_flower, Palette_00, Anim_8), 0);
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_7));
                        PlaySoundAtCollider(13, 457, 0);
                        ModifyColliderFlags(0, 13, 0x7FFFFE00);
                        MakeLerp(0, 100, 30, 1);
                        loop {
                            UpdateLerp();
                            SI_VAR(8) = (float) SI_VAR(0);
                            SI_VAR(9) = (float) SI_VAR(0);
                            SI_VAR(8) *= 0.5;
                            SI_VAR(9) *= 1.2001953125;
                            RotateModel(59, SI_VAR(8), 0, -1, 0);
                            RotateModel(60, SI_VAR(8), 0, -1, 0);
                            RotateModel(61, SI_VAR(8), 0, -1, 0);
                            RotateModel(55, SI_VAR(9), 0, 1, 0);
                            RotateModel(56, SI_VAR(9), 0, 1, 0);
                            RotateModel(57, SI_VAR(9), 0, 1, 0);
                            sleep 1;
                            if (SI_VAR(1) != 1) {
                                break loop;
                            }
                        }
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_5));
                        SI_SAVE_FLAG(1365) = 1;
                    }
                    == 159 {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_4), NPC_ANIM(gate_flower, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x004C));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_1));
                    }
                    == 160 {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_4), NPC_ANIM(gate_flower, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x004C));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_1));
                    } else {
                        SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_4), NPC_ANIM(gate_flower, Palette_00, Anim_1), 0,
                                      MESSAGE_ID(0x11, 0x004B));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_6));
                        PlaySoundAtNpc(NPC_SELF, 0x2096, 0);
                        MakeItemEntity(SI_VAR(8), 375, 20, 0, 1, 0);
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
                                SI_VAR(2) += 380.0;
                                SI_VAR(3) += 15.0;
                                SI_VAR(4) += -30.0;
                                N(func_80240B68_CEEDC8)(SI_VAR(7), SI_VAR(2), SI_VAR(3), SI_VAR(4));
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
                                SI_VAR(4) = 1.0;
                                SI_VAR(2) *= (float) SI_VAR(0);
                                SI_VAR(3) *= (float) SI_VAR(0);
                                SI_VAR(4) *= (float) SI_VAR(0);
                                SI_VAR(2) += 390.0;
                                SI_VAR(3) += 15.0;
                                SI_VAR(4) += -30.0;
                                N(func_80240B68_CEEDC8)(SI_VAR(7), SI_VAR(2), SI_VAR(3), SI_VAR(4));
                                sleep 1;
                                if (SI_VAR(1) != 1) {
                                    break loop;
                                }
                            }
                        }
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_1));
                        RemoveItemEntity(SI_VAR(7));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_1));
                        EndSpeech(-1, NPC_ANIM(gate_flower, Palette_00, Anim_2), NPC_ANIM(gate_flower, Palette_00, Anim_1), 0);
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
            SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_9), NPC_ANIM(gate_flower, Palette_00, Anim_8), 0,
                          MESSAGE_ID(0x11, 0x004E));
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_9), NPC_ANIM(gate_flower, Palette_00, Anim_8), 0,
                          MESSAGE_ID(0x11, 0x004F));
        }
    }
    DisablePlayerInput(FALSE);
    unbind;
});

Script N(init_80241E70) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80241564));
    if (SI_SAVE_FLAG(1365) == 1) {
        SetNpcAnimation(NPC_SELF, NPC_ANIM(gate_flower, Palette_00, Anim_5));
        ModifyColliderFlags(0, 13, 0x7FFFFE00);
        RotateModel(59, 50, 0, -1, 0);
        RotateModel(60, 50, 0, -1, 0);
        RotateModel(61, 50, 0, -1, 0);
        RotateModel(55, 120, 0, 1, 0);
        RotateModel(56, 120, 0, 1, 0);
        RotateModel(57, 120, 0, 1, 0);
    }
});

StaticNpc N(npcGroup_80241F98) = {
    .id = NPC_GATE_FLOWER,
    .settings = &N(npcSettings_802412E0),
    .pos = { 385.0f, 0.0f, -35.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_80241E70),
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
        NPC_ANIM(gate_flower, Palette_00, Anim_1),
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DC),
};

StaticNpc N(npcGroup_80242188) = {
    .id = NPC_SPINY0,
    .settings = &N(npcSettings_80241538),
    .pos = { 80.0f, 0.0f, 0.0f },
    .flags = NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 80, 0, 0, 30, 0, -32767, 0, 80, 0, 0, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
};

StaticNpc N(npcGroup_80242378) = {
    .id = NPC_SPINY1,
    .settings = &N(npcSettings_80241538),
    .pos = { -320.0f, 0.0f, 0.0f },
    .flags = NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { -320, 0, 0, 30, 0, -32767, 0, -320, 0, 0, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
};

NpcGroupList N(npcGroupList_80242568) = {
    NPC_GROUP(N(npcGroup_80242188), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80242378), BATTLE_ID(24, 13, 0, 3)),
    NPC_GROUP(N(npcGroup_80241F98), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_2598)[] = {
    0x00000000, 0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA0C4, 100, 60, 5, 0, MAKE_ENTITY_END);
    MakeEntity(0x802EA588, 100, 145, 0, 0, ITEM_SHOOTING_STAR, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1409));
    MakeEntity(0x802EA588, 25, 60, 0, 0, ITEM_COIN, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1408));
    MakeEntity(0x802EAA54, -50, 0, 0, 90, ITEM_LETTER07, MAKE_ENTITY_END);
});

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_8024026C_CEE4CC)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024130C_CEF56C) = FALSE;
    }

    if (N(D_8024130C_CEF56C)) {
        N(D_8024130C_CEF56C) = FALSE;
        set_variable(script, *args, N(D_80241310_CEF570));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_802402C0_CEE520)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241310_CEF570) = get_variable(script, *args);
    N(D_8024130C_CEF56C) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(func_802402F8_CEE558)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_802426E0)[i] = ptr[i];
        }
        N(D_802426E0)[i] = 0;
    } else {
        for (i = 0; i <= 90; i++) {
            N(D_802426E0)[i] = i + 128;
            N(D_802426E0)[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/set_script_owner_npc_anim.inc.c"

void N(func_80240410_CEE670)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if ((npc->duration <= 0) || (--npc->duration <= 0)) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc->currentAnim.w = enemy->animList[9];
            npc->moveSpeed = aiSettings->chaseSpeed;
            if ((enemy->varTable[7] == 5) || (enemy->varTable[7] == 0) || (enemy->varTable[7] == 1)) {
                npc->collisionHeight = enemy->varTable[6] / 2;
            }
            npc->duration = (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                    gPlayerStatusPtr->position.z) / npc->moveSpeed) + 0.8;
            if (npc->duration < enemy->varTable[3]) {
                npc->duration = enemy->varTable[3];
            }
            enemy->varTable[4] = npc->duration;
            script->functionTemp[0].s = 14;
        }
    }
}

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

ApiStatus N(func_80240728_CEE988)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);
    s32 var;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->varTable[8] = 0;
        enemy->unk_B5 = 0;
        enemy->unk_B0 |= 8;
    }

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        enemy->unk_07 = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        npc->collisionHeight = enemy->varTable[6];
        enemy->varTable[9] = 0;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0x28, &var);
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0].s = 12;
            enemy->flags &= ~0x40000000;
        }
    }

    if (enemy->varTable[9] > 0) {
        enemy->varTable[9]--;
        if (enemy->varTable[9] == 0) {
            if ((npc->currentAnim.w + 0xFFAAFFD2) < 2) {
                npc->currentAnim.w = 0x55000C;
            }
        } else {
            return ApiStatus_BLOCK;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            func_800495A0(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];

        case 1:
            func_800496B8(script, aiSettings, territoryPtr);
            break;

        case 2:
            base_UnkNpcAIFunc1(script, aiSettings, territoryPtr);
            if (enemy->varTable[7] == 6) {
                if (rand_int(100) < 0x21) {
                    if (enemy->varTable[8] != 0) {
                        enemy->varTable[8] = 0;
                        enemy->unk_B5 = 0;
                        npc->currentAnim.w = 0x55002F;
                    } else {
                        enemy->varTable[8] = 1;
                        enemy->unk_B5 = 1;
                        npc->currentAnim.w = 0x55002E;
                    }
                    enemy->varTable[9] = 7;
                    return ApiStatus_BLOCK;
                }
            }

        case 3:
            func_80049C04(script, aiSettings, territoryPtr);
            break;

        case 12:
            N(set_script_owner_npc_anim)(script, aiSettings, territoryPtr);

        case 13:
            N(func_80240410_CEE670)(script, aiSettings, territoryPtr);
            break;

        case 14:
            N(UnkNpcAIFunc12)(script, aiSettings, territoryPtr);
            break;

        case 15:
            N(set_script_owner_npc_col_height)(script, aiSettings, territoryPtr);
            break;

        case 99:
            func_8004A73C(script);
            break;

    }

    if (enemy->varTable[7] == 6) {
        if (enemy->varTable[8] != 0) {
            enemy->unk_B5 = 1;
        } else {
            enemy->unk_B5 = 0;
        }
        if (enemy->varTable[8] != 0) {
            switch (npc->currentAnim.w + 0xFFAAFFFC) {
                case 0:
                case 8:
                case 10:
                case 12:
                case 14:
                case 18:
                case 20:
                    npc->currentAnim.w++;
                    break;
            }
        }
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80240B68_CEEDC8)(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus N(func_80240C2C_CEEE8C)(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus N(func_80240C9C_CEEEFC)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i <= 90; i++) {
        N(D_80242850)[i] = 128 + i;
    }

    N(D_802429BC) = 0;
    return ApiStatus_DONE2;
}
