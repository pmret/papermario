#include "flo_12.h"
#include "message_ids.h"
#include "sprite/npc/rosie.h"

enum {
    NPC_ROSIE0,
    NPC_ROSIE1,
};

static N(D_802429E0)[112];

EntryList N(entryList) = {
    { 280.0f, 0.0f, 0.0f, 270.0f },
    { 280.0f, 0.0f, 0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_12_tattle },
};

EvtSource N(80240750) = SCRIPT({
    GetEntryID(EVT_VAR(0));
    if (EVT_VAR(0) == 1) {
        SetMusicTrack(0, SONG_SUNSHINE_RETURNS, 0, 8);
    } else {
        match EVT_STORY_PROGRESS {
            < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
                SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
            } else {
                SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
            }
        }
    }
});

EvtSource N(8024080C) = SCRIPT({
    PushSong(137, 3);
});

EvtSource N(80240830) = SCRIPT({
    FadeOutMusic(0, 250);
    sleep 10;
    PopSong();
});

static s32 N(pad_86C) = {
    0x00000000,
};

EvtSource N(80240870) = SCRIPT({
    group 11;
    EVT_VAR(10) = EVT_VAR(0);
    EVT_VAR(11) = EVT_VAR(1);
    EVT_VAR(12) = EVT_VAR(2);
    EVT_VAR(13) = EVT_VAR(3);
    EVT_VAR(14) = EVT_VAR(4);
    EVT_VAR(12) -= EVT_VAR(0);
    EVT_VAR(13) -= EVT_VAR(1);
    EVT_VAR(0) = (float) EVT_VAR(12);
    EVT_VAR(0) /= 100.0;
    EVT_VAR(15) = 100.0;
    EVT_VAR(15) /= (float) EVT_VAR(0);
    EVT_VAR(15) += 11;
    EVT_VAR(5) = 200;
    EVT_VAR(5) /= EVT_VAR(15);
    EVT_VAR(5) += 1;
    loop EVT_VAR(5) {
        RandInt(EVT_VAR(12), EVT_VAR(0));
        RandInt(EVT_VAR(13), EVT_VAR(1));
        RandInt(199, EVT_VAR(2));
        EVT_VAR(3) = 210;
        EVT_VAR(3) -= EVT_VAR(2);
        EVT_VAR(0) += EVT_VAR(10);
        EVT_VAR(1) += EVT_VAR(11);
        EVT_VAR(2) += EVT_VAR(14);
        PlayEffect(0xD, EVT_VAR(0), EVT_VAR(2), EVT_VAR(1), EVT_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    sleep EVT_VAR(15);
0:
    RandInt(EVT_VAR(12), EVT_VAR(0));
    RandInt(EVT_VAR(13), EVT_VAR(1));
    EVT_VAR(0) += EVT_VAR(10);
    EVT_VAR(1) += EVT_VAR(11);
    PlayEffect(0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep EVT_VAR(15);
    goto 0;
});

EvtSource N(exitWalk_80240B1C) = EXIT_WALK_SCRIPT(60,  0, "flo_11",  1);

EvtSource N(80240B78) = SCRIPT({
    bind N(exitWalk_80240B1C) TRIGGER_FLOOR_ABOVE 0;
});

EvtSource N(main) = SCRIPT({
    EVT_WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    EVT_AREA_FLAG(22) = 0;
    MakeNpcs(0, N(npcGroupList_802429B8));
    ModifyColliderFlags(3, 11, 0x00000006);
    EVT_VAR(0) = -65;
    EVT_VAR(1) = -210;
    EVT_VAR(2) = 90;
    EVT_VAR(3) = -110;
    EVT_VAR(4) = 0;
    spawn N(80240870);
    EVT_VAR(0) = -200;
    EVT_VAR(1) = 130;
    EVT_VAR(2) = -80;
    EVT_VAR(3) = 170;
    EVT_VAR(4) = 0;
    spawn N(80240870);
    EVT_VAR(0) = -270;
    EVT_VAR(1) = -80;
    EVT_VAR(2) = -225;
    EVT_VAR(3) = 125;
    EVT_VAR(4) = 0;
    spawn N(80240870);
    GetEntryID(EVT_VAR(0));
    if (EVT_VAR(0) == 1) {
        spawn N(802419F4);
    } else {
        ModifyColliderFlags(0, 1, 0x7FFFFE00);
        EVT_VAR(0) = N(80240B78);
        spawn EnterWalk;
    }
    await N(80240750);
    if (EVT_STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_CC0E30)();
    }
});

static s32 N(pad_E28)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80240E30) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

NpcSettings N(npcSettings_80240E5C) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "world/common/foliage.inc.c"

s32** N(D_802417EC_CC261C) = NULL;

EvtSource N(802417F0) = SCRIPT({
    ShowGotItem(EVT_VAR(0), 1, 0);
    return;
});

EvtSource N(80241820) = SCRIPT({
    ShowGotItem(EVT_VAR(0), 1, 16);
    return;
});

s32 N(D_80241850_CC2680) = {
    0x00000000,
};

s32 N(D_80241854_CC2684) = {
    0x00000000,
};

EvtSource N(80241858) = SCRIPT({
    EVT_VAR(9) = EVT_VAR(1);
    ShowKeyChoicePopup();
    EVT_VAR(10) = EVT_VAR(0);
    match EVT_VAR(0) {
        == 0 {}
        == -1 {}
        else {
            RemoveKeyItemAt(EVT_VAR(1));
            GetPlayerPos(EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
            N(AddPlayerHandsOffset)(EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
            EVT_VAR(0) |= (const)  0x50000;
            MakeItemEntity(EVT_VAR(0), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5), 1, 0);
            SetPlayerAnimation(0x60005);
            sleep 30;
            SetPlayerAnimation(ANIM_10002);
            RemoveItemEntity(EVT_VAR(0));
        }
    }
    N(func_80240614_CC1444)(EVT_VAR(10));
    CloseChoicePopup();
    unbind;
});

EvtSource N(8024199C) = SCRIPT({
    N(func_8024064C_CC147C)(EVT_VAR(0));
    bind_padlock N(80241858) 0x10 0 N(D_802429E0);
    N(func_802405C0_CC13F0)(EVT_VAR(0));
});

s32 N(D_802419EC_CC281C)[] = {
    0x0000001E, 0x00000000,
};

EvtSource N(802419F4) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    GetNpcPos(NPC_ROSIE0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetCamDistance(0, 350);
    SetCamPitch(0, 17.0, -9.5);
    SetCamPosA(0, 0, 0);
    SetCamPosB(0, 0, -50);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 20;
    SpeakToPlayer(NPC_ROSIE0, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x00C7));
    sleep 10;
    GotoMap("flo_03", 2);
    sleep 100;
});

EvtSource N(80241B6C) = SCRIPT({
    sleep 10;
    SetNpcFlagBits(NPC_ROSIE0, ((NPC_FLAG_100)), TRUE);
    PlayerMoveTo(-5, 20, 20);
    SetNpcFlagBits(NPC_ROSIE0, ((NPC_FLAG_100)), FALSE);
    PlayerFaceNpc(0, 1);
});

EvtSource N(80241BE4) = SCRIPT({
    sleep 10;
    SetNpcFlagBits(NPC_ROSIE0, ((NPC_FLAG_100)), TRUE);
    SetNpcFlagBits(NPC_ROSIE1, ((NPC_FLAG_100)), TRUE);
    PlayerMoveTo(-5, 20, 20);
    SetNpcFlagBits(NPC_ROSIE0, ((NPC_FLAG_100)), FALSE);
    SetNpcFlagBits(NPC_ROSIE1, ((NPC_FLAG_100)), FALSE);
    PlayerFaceNpc(0, 1);
});

EvtSource N(interact_80241C8C) = SCRIPT({
    await N(8024080C);
    match EVT_STORY_PROGRESS {
        < STORY_CH6_GOT_CRYSTAL_BERRY {
            match EVT_SAVE_FLAG(1378) {
                == 0 {
                    spawn N(80241B6C);
                    GetNpcPos(NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                    EVT_VAR(0) += 30;
                    SetCamProperties(0, 4.0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 325, 19.0, -9.5);
                    SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_3, NPC_ANIM_rosie_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x008C));
                    ShowChoice(MESSAGE_ID(0x1E, 0x0011));
                    sleep 10;
                    match EVT_VAR(0) {
                        == 0 {
                            ContinueSpeech(-1, NPC_ANIM_rosie_Palette_00_Anim_3, NPC_ANIM_rosie_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x008D));
                        }
                        == 1 {
                            ContinueSpeech(-1, NPC_ANIM_rosie_Palette_00_Anim_3, NPC_ANIM_rosie_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x008E));
                        }
                    }
                    SetNpcFlagBits(NPC_ROSIE1, ((NPC_FLAG_100)), FALSE);
                    SetNpcAnimation(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_5);
                    sleep 10;
                    SetNpcAnimation(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_2);
                    MakeItemEntity(ITEM_WATER_STONE, -33, 14, 19, 1, 1380);
                    sleep 10;
                    match EVT_SAVE_FLAG(1375) {
                        == 0 {
                            SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_4, 5, MESSAGE_ID(0x11, 0x008F));
                        }
                        == 1 {
                            SetPlayerAnimation(0x60002);
                            SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_4, 5, MESSAGE_ID(0x11, 0x008F));
                            SetPlayerAnimation(0x60005);
                            SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0091));
                            SetPlayerAnimation(ANIM_PRAY);
                            sleep 40;
                            SetPlayerAnimation(ANIM_10002);
                            SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0092));
                            EVT_SAVE_FLAG(1379) = 1;
                        }
                    }
                    EVT_SAVE_FLAG(1378) = 1;
                }
                == 1 {
                    match EVT_SAVE_FLAG(1379) {
                        == 0 {
                            if (EVT_SAVE_FLAG(1375) == 1) {
                                spawn N(80241BE4);
                                SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_4, 5, MESSAGE_ID(0x11,
                                              0x0090));
                                SetPlayerAnimation(0x60005);
                                SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11,
                                              0x0091));
                                SetPlayerAnimation(ANIM_PRAY);
                                sleep 40;
                                SetPlayerAnimation(ANIM_10002);
                                SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11,
                                              0x0092));
                                EVT_SAVE_FLAG(1379) = 1;
                            } else {
                                SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_4, 5, MESSAGE_ID(0x11,
                                              0x0090));
                            }
                        }
                        == 1 {
                            SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0093));
                        }
                    }
                }
            }
        }
        < 48 {
            FindKeyItem(ITEM_CRYSTAL_BERRY, EVT_VAR(0));
            if (EVT_VAR(0) != -1) {
                spawn N(80241BE4);
                GetNpcPos(NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                EVT_VAR(0) += 30;
                SetCamProperties(0, 4.0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 325, 19.0, -9.5);
            }
            SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0094));
            EVT_VAR(0) = N(D_802419EC_CC281C);
            EVT_VAR(1) = 0;
            await N(8024199C);
            match EVT_VAR(0) {
                <= 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0093));
                } else {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11,
                                  0x0095));
                    RemoveItemEntity(EVT_VAR(7));
                    MakeItemEntity(ITEM_CRYSTAL_BERRY, -33, 14, 19, 1, 1380);
                    EVT_VAR(0) = 87;
                    EVT_VAR(1) = 1;
                    await N(802417F0);
                    AddKeyItem(ITEM_WATER_STONE);
                    sleep 10;
                    SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11,
                                  0x0096));
                    EVT_AREA_FLAG(22) = 1;
                    EVT_STORY_PROGRESS = STORY_CH6_GOT_WATER_STONE;
                }
            }
        }
        < 53 {
            match EVT_AREA_FLAG(22) {
                == 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0097));
                }
                == 1 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0096));
                }
            }
        }
        < 60 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11, 0x0098));
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_4, NPC_ANIM_rosie_Palette_00_Anim_2, 5, MESSAGE_ID(0x11,
                          0x0099));
        }
    }
    ResetCam(0, 4.0);
    await N(80240830);
});

EvtSource N(init_802423D0) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80241C8C));
    GetNpcPos(NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 35;
    SetNpcPos(NPC_ROSIE1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetNpcFlagBits(NPC_ROSIE1, ((0x00000002)), TRUE);
    SetNpcFlagBits(NPC_ROSIE1, ((NPC_FLAG_HAS_SHADOW)), TRUE);
    match EVT_STORY_PROGRESS {
        < STORY_CH6_GOT_CRYSTAL_BERRY {
            if (EVT_SAVE_FLAG(1378) == 1) {
                SetNpcFlagBits(NPC_ROSIE1, ((NPC_FLAG_100)), FALSE);
                SetNpcAnimation(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_2);
                MakeItemEntity(ITEM_WATER_STONE, -33, 14, 19, 1, 1380);
                EVT_VAR(10) = EVT_VAR(0);
            }
        }
        < STORY_CH6_GOT_WATER_STONE {
            SetNpcFlagBits(NPC_ROSIE1, ((NPC_FLAG_100)), FALSE);
            SetNpcAnimation(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_2);
            MakeItemEntity(ITEM_WATER_STONE, -33, 14, 19, 1, 1380);
            EVT_VAR(10) = EVT_VAR(0);
        } else {
            SetNpcFlagBits(NPC_ROSIE1, ((NPC_FLAG_100)), FALSE);
            SetNpcAnimation(NPC_SELF, NPC_ANIM_rosie_Palette_00_Anim_2);
            MakeItemEntity(ITEM_CRYSTAL_BERRY, -33, 14, 19, 1, 1380);
            EVT_VAR(10) = EVT_VAR(0);
        }
    }
});

StaticNpc N(npcGroup_802425D8)[] = {
    {
        .id = NPC_ROSIE0,
        .settings = &N(npcSettings_80240E30),
        .pos = { -70.0f, 0.0f, 20.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_400000,
        .init = &N(init_802423D0),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E0),
    },
    {
        .id = NPC_ROSIE1,
        .settings = &N(npcSettings_80240E5C),
        .pos = { -70.0f, 0.0f, 20.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_GRAVITY,
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
            NPC_ANIM_rosie_Palette_00_Anim_1,
        },
    },
};

NpcGroupList N(npcGroupList_802429B8) = {
    NPC_GROUP(N(npcGroup_802425D8), BATTLE_ID(0, 0, 0, 0)),
    {},
};

ApiStatus N(func_8024027C_CC10AC)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802417EC_CC261C) == NULL) {
        N(D_802417EC_CC261C) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802417EC_CC261C)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802417EC_CC261C)[i];
        }
        heap_free(N(D_802417EC_CC261C));
        N(D_802417EC_CC261C) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_802405C0_CC13F0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80241850_CC2680) = FALSE;
    }

    if (N(D_80241850_CC2680)) {
        N(D_80241850_CC2680) = FALSE;
        evt_set_variable(script, *args, N(D_80241854_CC2684));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80240614_CC1444)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241854_CC2684) = evt_get_variable(script, *args);
    N(D_80241850_CC2680) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024064C_CC147C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_802429E0)[i] = ptr[i];
        }
        N(D_802429E0)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_802429E0)[i] = i + 16;
            N(D_802429E0)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
