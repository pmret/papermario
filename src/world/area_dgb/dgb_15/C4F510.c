#include "dgb_15.h"
#include "message_ids.h"
#include "sprite/npc/world_tubba.h"

extern s16 gCurrentCamID;

enum {
    NPC_WORLD_TUBBA,
};

EntryList N(entryList) = {
    { -1290.0f, 0.0f, 180.0f, 90.0f },
    { 125.0f, 0.0f, 180.0f, 270.0f },
    { 0.0f, 0.0f, 88.0f, 180.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_15_tattle },
};

Script N(802418E0) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            if (SI_SAVE_VAR(203) == 15) {
                SetMusicTrack(0, SONG_TUBBA_BLUBBA_THEME, 0, 8);
            } else {
                SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
            }
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        }
        else {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
    }
});

static s32 N(pad_19B4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

s32 N(itemList_802419C0)[] = {
    ITEM_CASTLE_KEY1,
    ITEM_NONE,
};

Script N(exitDoubleDoor_802419C8) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 0;
    SI_VAR(1) = 19;
    SI_VAR(2) = 12;
    SI_VAR(3) = 14;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_14", 1);
    sleep 100;
});

Script N(exitDoubleDoor_80241A7C) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 1;
    SI_VAR(1) = 10;
    SI_VAR(2) = 19;
    SI_VAR(3) = 17;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_17", 0);
    sleep 100;
});

Script N(exitSingleDoor_80241B30) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(0);
    SI_VAR(0) = 2;
    SI_VAR(1) = 6;
    SI_VAR(2) = 22;
    SI_VAR(3) = 1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("dgb_16", 0);
    sleep 100;
});

const N(pad_XXXX)[] = { 0, 0 };

// *INDENT-OFF*
Script N(80241BE4) = {
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_802419C8), TRIGGER_WALL_PRESS_A, 19, 1, 0),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitSingleDoor_80241B30), TRIGGER_WALL_PRESS_A, 6, 1, 0),
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1066), 0),
        SI_CMD(ScriptOpcode_BIND_PADLOCK, N(80242AD0), TRIGGER_WALL_PRESS_A, 16384, N(itemList_802419C0), 0, 1),
    SI_CMD(ScriptOpcode_ELSE),
        SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_80241A7C), TRIGGER_WALL_PRESS_A, 10, 1, 0),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(enterSingleDoor_80241C88) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            UseDoorSounds(3);
            SI_VAR(2) = 12;
            SI_VAR(3) = 14;
            await EnterDoubleDoor;
        }
        == 1 {
            UseDoorSounds(3);
            SI_VAR(2) = 19;
            SI_VAR(3) = 17;
            await EnterDoubleDoor;
        }
        == 2 {
            UseDoorSounds(0);
            SI_VAR(2) = 22;
            SI_VAR(3) = 1;
            await EnterSingleDoor;
        }
    }
    spawn N(80241BE4);
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SI_AREA_FLAG(1) = 0;
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SetCamLeadPlayer(0, 0);
    if (SI_SAVE_FLAG(1068) == 0) {
        MakeNpcs(1, N(npcGroupList_80242AB0));
    }
    await N(makeEntities);
    spawn N(802418E0);
    spawn N(enterSingleDoor_80241C88);
});

static s32 N(pad_1E94)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80241EA0) = SCRIPT({
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

s32 N(unk_missing_80241F5C)[] = {
    0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x0039000C, 0x00390007, 0x00390008, 0x00390011,
    0x00390012, 0xFFFFFFFF, 0x00390000, 0xFFFFFFFF,
};

s32 N(D_80241F8C_C5149C)[] = {
    0x3FC00000, 0x00000078, 0x0000001E, 0x42AA0000, 0x42820000, 0x00000005, 0x40600000, 0x0000005A,
    0x0000000C, 0x42DC0000, 0x42B40000, 0x00000003,
};

Script N(80241FBC) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(1, 5);
    SetSelfVar(2, 8);
    SetSelfVar(3, 12);
    N(func_8024061C_C4FB2C)(N(D_80241F8C_C5149C));
});

s32 N(unk_missing_8024202C)[] = {
    0x00000000, 0x00240022, 0x00000000, 0x00000000, N(80241FBC), 0x80077F70, 0x00000000, 0x8007809C,
    0x00000000, 0x00000000, 0x000D0000,
};

Script N(80242058) = SCRIPT({
    EnableNpcShadow(NPC_SELF, FALSE);
    SetSelfVar(0, 4);
    SetSelfVar(1, 32);
    SetSelfVar(2, 50);
    SetSelfVar(3, 32);
    SetSelfVar(4, 3);
    SetSelfVar(15, 8389);
    N(UnkFunc7)();
});

s32 N(unk_missing_80242100)[] = {
    0x00000000, 0x000E0012, 0x00000000, 0x00000000, N(80242058), 0x00000000, 0x00000000, N(80241EA0),
    0x00000000, 0x00000000, 0x000D0008,
};

NpcSettings N(npcSettings_8024212C) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

s32 N(unk_missing_80242158)[] = {
    0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x000D0000,
};

Script N(80242184) = SCRIPT({
    loop {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        GetNpcPos(NPC_WORLD_TUBBA, SI_VAR(1), SI_VAR(2), SI_VAR(3));
        SI_VAR(1) -= SI_VAR(0);
        if (SI_VAR(1) < 150) {
            break loop;
        }
        sleep 1;
    }
    SI_SAVE_FLAG(1067) = 1;
    SI_AREA_FLAG(1) = 1;
});

Script N(idle_80242238) = SCRIPT({
    loop {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        if (SI_VAR(0) >= -1150) {
            break loop;
        }
        sleep 1;
    }
    DisablePlayerInput(TRUE);
    SetMusicTrack(0, SONG_TUBBA_BLUBBA_THEME, 0, 8);
    sleep 15;
    spawn {
        UseSettingsFrom(0, -50, 0, 180);
        SetCamSpeed(0, 2.0);
        SetPanTarget(0, -50, 0, 180);
        PanToTarget(0, 0, 1);
    }
    SI_SAVE_VAR(203) = 15;
    SetNpcPos(NPC_SELF, 0, 0, 88);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_9));
    SetNpcYaw(NPC_SELF, 270);
    NpcMoveTo(NPC_SELF, -53, 180, 60);
    SetMusicTrack(0, SONG_TUBBA_BLUBBA_THEME, 0, 8);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_6));
    sleep 15;
    SpeakToPlayer(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_10), NPC_ANIM(world_tubba, Palette_00, Anim_6), 0, MESSAGE_ID(0x0E, 0x00F3));
    sleep 15;
    spawn {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetCamSpeed(0, 2.0);
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        WaitForCam(0, 1.0);
        PanToTarget(0, 0, 0);
        DisablePlayerInput(FALSE);
    }
    BindNpcAI(NPC_SELF, N(npcAI_8024274C));
});

Script N(802424E8) = SCRIPT({
    GetNpcPos(NPC_SELF, SI_VAR(6), SI_VAR(7), SI_VAR(8));
    loop {
        sleep 1;
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        GetNpcPos(NPC_SELF, SI_VAR(3), SI_VAR(4), SI_VAR(5));
        if (SI_VAR(3) != SI_VAR(6)) {
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_20F6, 65538);
            GetDist2D(SI_VAR(10), SI_VAR(0), SI_VAR(2), SI_VAR(3), SI_VAR(5));
            match SI_VAR(10) {
                < 200 {
                    spawn {
                        ShakeCam(0, 0, 5, 1.6005859375);
                        sleep 5;
                        ShakeCam(0, 0, 2, 0.80078125);
                    }
                }
                < 300 {
                    spawn {
                        ShakeCam(0, 0, 5, 0.6005859375);
                        sleep 5;
                        ShakeCam(0, 0, 2, 0.30078125);
                    }
                }
                >= 300 {
                    spawn {
                        ShakeCam(0, 0, 5, 0.1005859375);
                        sleep 5;
                        ShakeCam(0, 0, 2, 0.05078125);
                    }
                }
            }
            sleep 12;
        } else {
        }
        GetNpcPos(NPC_SELF, SI_VAR(6), SI_VAR(7), SI_VAR(8));
    }
});

NpcAISettings N(npcAISettings_8024271C) = {
    .moveSpeed = 3.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .unk_10 = { .f = 80.0f },
    .unk_14 = 1,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 180 },
    .unk_20 = 2,
    .chaseRadius = 160.0f,
    .unk_28 = { .f = 80.0f },
    .unk_2C = 1,
};

Script N(npcAI_8024274C) = SCRIPT({
    spawn N(80242184);
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_GRAVITY)), TRUE);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_C));
    spawn N(802424E8);
    N(func_80241464_C50974)(N(npcAISettings_8024271C));
});

const char N(dgb_14_name_hack)[];

Script N(defeat_802427B0) = SCRIPT({
    N(UnkFunc1)();
    GotoMap(N(dgb_14_name_hack), 1);
    sleep 100;
});

Script N(init_802427EC) = SCRIPT({
    if (STORY_PROGRESS != STORY_CH3_ARRIVED_AT_TUBBAS_MANOR) {
        RemoveNpc(NPC_SELF);
        return;
    }
    SetNpcScale(NPC_SELF, 1.25, 1.25, 1.25);
    if (SI_SAVE_VAR(203) != 15) {
        BindNpcIdle(NPC_SELF, N(idle_80242238));
    } else {
        SetNpcPos(NPC_SELF, -310, 0, 180);
        BindNpcIdle(NPC_SELF, N(npcAI_8024274C));
    }
    BindNpcDefeat(NPC_SELF, N(defeat_802427B0));
});

StaticNpc N(npcGroup_802428C0) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_8024212C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_200000 | NPC_FLAG_NO_DROPS,
    .init = &N(init_802427EC),
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
    .movement = { 7, -500, 0, 200, -700, 0, 200, -900, 0, 200, -1000, 0, 200, -800, 0, 200, -600, 0, 200, -400, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, -500, 0, 200, 1000, 250, 1, 1 },
    .animations = {
        NPC_ANIM(world_tubba, Palette_00, Anim_6),
        NPC_ANIM(world_tubba, Palette_00, Anim_9),
        NPC_ANIM(world_tubba, Palette_00, Anim_C),
        NPC_ANIM(world_tubba, Palette_00, Anim_C),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
    },
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80242AB0) = {
    NPC_GROUP(N(npcGroup_802428C0), BATTLE_ID(15, 4, 0, 1)),
    {},
};

static s32 N(pad_2AC8)[] = {
    0x00000000, 0x00000000,
};

Script N(80242AD0) = SCRIPT({
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
    SI_SAVE_FLAG(1066) = 1;
    N(GetEntityPosition)(SI_MAP_VAR(0), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    PlaySoundAt(0x269, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) = SI_MAP_VAR(0);
    N(SetEntityFlags100000)();
    resume group 1;
    unbind;
});

Script N(80242C38) = SCRIPT({
    bind N(exitDoubleDoor_80241A7C) to TRIGGER_WALL_PRESS_A 10;
});

Script N(makeEntities) = SCRIPT({
    if (SI_SAVE_FLAG(1066) == 0) {
        MakeEntity(0x802BCD68, 130, 8, 175, -80, MAKE_ENTITY_END);
        AssignScript(N(80242C38));
        SI_MAP_VAR(0) = SI_VAR(0);
    }
});

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

s32 N(func_80240208_C4F718)(ScriptInstance *script) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = CAM(gCurrentCamID);
    Enemy* enemy2 = get_enemy(enemy->npcID + 1);
    f32 phi_f20;
    s32 ret = TRUE;

    if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) > enemy2->varTable[2]) {
        ret = FALSE;
    }

    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        phi_f20 = 90.0f;
    } else {
        phi_f20 = 270.0f;
    }

    if (fabsf(get_clamped_angle_diff(phi_f20, atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z))) > enemy2->varTable[3]) {
        ret = FALSE;
    }

    if ((2.0 * npc->collisionHeight) <= fabsf(npc->pos.y - gPlayerStatusPtr->position.y)) {
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

ApiStatus N(func_8024061C_C4FB2C)(ScriptInstance *script, s32 isInitialCall) {
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
    territory.unk_18 = 65.0f;
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

    if ((script->functionTemp[0].s < 30) && (enemy->varTable[0] == 0) && N(func_80240208_C4F718)(script)) {
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

ApiStatus N(func_802408D0_C4FDE0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
    return ApiStatus_DONE1;
}

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

ApiStatus N(func_80240F4C_C5045C)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
    return ApiStatus_DONE1;
}

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_80241464_C50974)(ScriptInstance* script, s32 isInitialCall) {
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
    territory.unk_18 = 65.0f;
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
            N(func_802408D0_C4FDE0)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_80240F4C_C5045C)(script, npcAISettings, territoryPtr);
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

#include "world/common/UnkFunc1.inc.c"

const char N(dgb_14_name_hack)[] = "dgb_14";
