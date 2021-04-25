#include "dgb_06.h"
#include "sprite/npc/boo.h"
#include "message_ids.h"

enum {
    NPC_BOO,
};

EntryList N(entryList) = {
    { -575.0f,   0.0f,  175.0f, 90.0f },
    { -150.0f, 100.0f, -250.0f,  0.0f },
};

MapConfig N(config) = {
    .main = N(main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = MSG_dgb_06_tattle,
};

Script N(80240320) = SCRIPT({
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

static s32 N(pad_3B8)[] = {
    0x00000000, 0x00000000,
};

Script N(exitSingleDoor_802403C0) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(0);
    SI_VAR(0) = 0;
    SI_VAR(1) = 12;
    SI_VAR(2) = 5;
    SI_VAR(3) = -1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("dgb_04", 1);
    sleep 100;
});

Script N(enterSingleDoor_80240474) = SCRIPT({
    UseDoorSounds(0);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(2) = 5;
            SI_VAR(3) = -1;
            await EnterSingleDoor;
        }
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(589824);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(1, N(npcGroupList_80240B44));
    await N(makeEntities);
    if (SI_SAVE_FLAG(1047) == 0) {
        EnableGroup(28, 0);
    } else {
        EnableGroup(25, 0);
    }
    bind N(exitSingleDoor_802403C0) to TRIGGER_WALL_PRESS_A 12;
    spawn N(80240320);
    spawn N(enterSingleDoor_80240474);
});

s32** N(D_80240620_C3D6A0) = NULL;

Script N(80240624) = SCRIPT({
    group 0;
    func_802D5830(2);
    sleep 40;
    ShowGotItem(SI_VAR(0), 0, 0);
    func_802D5830(0);
    return;
});

Script N(8024068C) = SCRIPT({
    DisablePlayerInput(TRUE);
    SI_VAR(0) = SI_VAR(10);
    if (SI_VAR(10) != 0) {
        await N(80240624);
    }
    match SI_VAR(11) {
        == 0 {
            AddItem(SI_VAR(10), SI_VAR(0));
        }
        == 1 {
            AddKeyItem(SI_VAR(10));
        }
        == 2 {
            AddBadge(SI_VAR(10), SI_VAR(0));
        }
    }
    sleep 15;
    DisablePlayerInput(FALSE);
});

Script N(8024076C) = SCRIPT({
    SI_VAR(10) = 19;
    SI_VAR(11) = 1;
    SI_SAVE_FLAG(1048) = 1;
    await N(8024068C);
});

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EAE30, -300, 50, -200, 0, ITEM_NONE, MAKE_ENTITY_END);
    AssignFlag(SI_SAVE_FLAG(1048));
    AssignScript(N(8024076C));
    MakeEntity(0x802EA7E0, -125, 60, 175, 0, MAKE_ENTITY_END);
});

static s32 N(pad_834)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80240840) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

Script N(interact_8024086C) = SCRIPT({
    if (SI_AREA_FLAG(4) == 0) {
        SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00F0));
        SI_AREA_FLAG(4) = 1;
    } else {
        SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00F1));
        SI_AREA_FLAG(4) = 0;
    }
});

Script N(init_802408FC) = SCRIPT({
    if (STORY_PROGRESS >= STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER) {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
    BindNpcInteract(NPC_SELF, N(interact_8024086C));
});

StaticNpc N(npcGroup_80240954) = {
    .id = NPC_BOO,
    .settings = &N(npcSettings_80240840),
    .pos = { -300.0f, 10.0f, 150.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802408FC),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(boo, Palette_01, Anim_1),
        NPC_ANIM(boo, Palette_01, Anim_2),
        NPC_ANIM(boo, Palette_01, Anim_3),
        NPC_ANIM(boo, Palette_01, Anim_3),
        NPC_ANIM(boo, Palette_01, Anim_1),
        NPC_ANIM(boo, Palette_01, Anim_1),
        NPC_ANIM(boo, Palette_01, Anim_0),
        NPC_ANIM(boo, Palette_01, Anim_0),
        NPC_ANIM(boo, Palette_01, Anim_A),
        NPC_ANIM(boo, Palette_01, Anim_3),
        NPC_ANIM(boo, Palette_01, Anim_3),
        NPC_ANIM(boo, Palette_01, Anim_3),
        NPC_ANIM(boo, Palette_01, Anim_3),
        NPC_ANIM(boo, Palette_01, Anim_3),
        NPC_ANIM(boo, Palette_01, Anim_3),
        NPC_ANIM(boo, Palette_01, Anim_3),
    },
    .tattle = MESSAGE_ID(0x1A, 0x00B3),
};

NpcGroupList N(npcGroupList_80240B44) = {
    NPC_GROUP(N(npcGroup_80240954), BATTLE_ID(0, 0, 0, 0)),
    {},
};

ApiStatus N(func_80240000_C3D080)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80240620_C3D6A0) == NULL) {
        N(D_80240620_C3D6A0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80240620_C3D6A0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80240620_C3D6A0)[i];
        }
        heap_free(N(D_80240620_C3D6A0));
        N(D_80240620_C3D6A0) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
