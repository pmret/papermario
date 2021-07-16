#include "dgb_02.h"
#include "sprite/npc/world_clubba.h"
#include "message_ids.h"

extern s16 gCurrentCamID;
extern Npc* wPartnerNpc;

enum {
    NPC_WORLD_CLUBBA0 = 10,
    NPC_WORLD_CLUBBA1,
    NPC_WORLD_CLUBBA2 = 30,
    NPC_WORLD_CLUBBA3,
};

EntryList N(entryList) = {
    { -567.0f, 0.0f, 180.0f,  90.0f },
    {  567.0f, 0.0f, 180.0f, 270.0f },
    { -450.0f, 0.0f,  88.0f, 180.0f },
    {  450.0f, 0.0f,  88.0f, 180.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = 0x1900C2,
};

Script N(802414B0) = SCRIPT({
    match STORY_PROGRESS {
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

static s32 N(pad_1548)[] = {
    0x00000000, 0x00000000,
};

Script N(exitDoubleDoor_80241550) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 0;
    SI_VAR(1) = 5;
    SI_VAR(2) = 11;
    SI_VAR(3) = 13;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_03", 1);
    sleep 100;
});

Script N(exitDoubleDoor_80241604) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 1;
    SI_VAR(1) = 17;
    SI_VAR(2) = 18;
    SI_VAR(3) = 16;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_01", 1);
    sleep 100;
});

Script N(exitSingleDoor_802416B8) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(0);
    SI_VAR(0) = 2;
    SI_VAR(1) = 9;
    SI_VAR(2) = 21;
    SI_VAR(3) = 1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("dgb_07", 0);
    sleep 100;
});

Script N(exitSingleDoor_8024176C) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(0);
    SI_VAR(0) = 3;
    SI_VAR(1) = 13;
    SI_VAR(2) = 23;
    SI_VAR(3) = 1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("dgb_11", 0);
    sleep 100;
});

Script N(enterSingleDoor_80241820) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            UseDoorSounds(3);
            SI_VAR(2) = 11;
            SI_VAR(3) = 13;
            await EnterDoubleDoor;
        }
        == 1 {
            UseDoorSounds(3);
            SI_VAR(2) = 18;
            SI_VAR(3) = 16;
            await EnterDoubleDoor;
        }
        == 2 {
            UseDoorSounds(0);
            SI_VAR(2) = 21;
            SI_VAR(3) = 1;
            await EnterSingleDoor;
        }
        == 3 {
            UseDoorSounds(0);
            SI_VAR(2) = 23;
            SI_VAR(3) = 1;
            await EnterSingleDoor;
        }
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    if (STORY_PROGRESS < STORY_CH3_STAR_SPIRIT_RESCUED) {
        MakeNpcs(1, N(npcGroupList_802425C8));
    }
    bind N(exitDoubleDoor_80241550) to TRIGGER_WALL_PRESS_A 5;
    bind N(exitDoubleDoor_80241604) to TRIGGER_WALL_PRESS_A 17;
    bind N(exitSingleDoor_802416B8) to TRIGGER_WALL_PRESS_A 9;
    bind N(exitSingleDoor_8024176C) to TRIGGER_WALL_PRESS_A 13;
    spawn N(802414B0);
    spawn N(enterSingleDoor_80241820);
});

static s32 N(pad_1AA8)[] = {
    0x00000000, 0x00000000,
};

Script N(80241AB0) = SCRIPT({
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

NpcAnimID N(extraAnimationList_80241B6C)[] = {
    NPC_ANIM(world_clubba, Palette_00, Anim_0),
    NPC_ANIM(world_clubba, Palette_00, Anim_2),
    NPC_ANIM(world_clubba, Palette_00, Anim_3),
    NPC_ANIM(world_clubba, Palette_00, Anim_4),
    NPC_ANIM(world_clubba, Palette_00, Anim_C),
    NPC_ANIM(world_clubba, Palette_00, Anim_7),
    NPC_ANIM(world_clubba, Palette_00, Anim_8),
    NPC_ANIM(world_clubba, Palette_00, Anim_11),
    NPC_ANIM(world_clubba, Palette_00, Anim_12),
    ANIM_END,
};

NpcAnimID N(extraAnimationList_80241B94)[] = {
    NPC_ANIM(world_clubba, Palette_00, Anim_0),
    ANIM_END,
};

NpcAISettings N(npcAISettings_80241B9C) = {
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

Script N(npcAI_80241BCC) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(1, 5);
    SetSelfVar(2, 8);
    SetSelfVar(3, 12);
    N(func_8024061C_C2F1BC)(N(npcAISettings_80241B9C));
});

NpcSettings N(npcSettings_80241C3C) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_80241BCC),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcAISettings N(npcAISettings_80241C68) = {
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

Script N(npcAI_80241C98) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(1, 10);
    SetSelfVar(2, 14);
    SetSelfVar(3, 18);
    N(func_802410D4_C2FC74)(N(npcAISettings_80241C68));
});

NpcSettings N(npcSettings_80241D08) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_80241C98),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

Script N(npcAI_80241D34) = SCRIPT({
    EnableNpcShadow(NPC_SELF, FALSE);
    SetSelfVar(0, 4);
    SetSelfVar(1, 32);
    SetSelfVar(2, 50);
    SetSelfVar(3, 32);
    SetSelfVar(4, 3);
    SetSelfVar(15, 8389);
    N(UnkFunc7)();
});

NpcSettings N(npcSettings_80241DDC) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_80241D34),
    .onDefeat = &N(80241AB0),
    .level = 13,
    .unk_2A = 8,
};

StaticNpc N(npcGroup_80241E08)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_80241C3C),
        .pos = { -200.0f, 0.0f, 180.0f },
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
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
        .movement = { -200, 0, 180, 40, 0, -32767, 0, -200, 0, 175, 250, 90, 1, 1 },
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
        .extraAnimations = N(extraAnimationList_80241B6C),
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_80241DDC),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_DROPS,
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
        .extraAnimations = N(extraAnimationList_80241B94),
    },
};

StaticNpc N(npcGroup_802421E8)[] = {
    {
        .id = NPC_WORLD_CLUBBA2,
        .settings = &N(npcSettings_80241D08),
        .pos = { 375.0f, 0.0f, 100.0f },
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
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
        .movement = { 375, 0, 100, 40, 0, -32767, 0, 320, 0, 175, 250, 90, 0, 1 },
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
        .settings = &N(npcSettings_80241DDC),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_DROPS,
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
        .extraAnimations = N(extraAnimationList_80241B94),
    },
};

NpcGroupList N(npcGroupList_802425C8) = {
    NPC_GROUP(N(npcGroup_80241E08), BATTLE_ID(15, 2, 0, 1)),
    NPC_GROUP(N(npcGroup_802421E8), BATTLE_ID(15, 1, 0, 1)),
    {},
};

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

s32 N(func_80240208_C2EDA8)(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
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

    if (fabsf(get_clamped_angle_diff(phi_f20, atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                     gPlayerStatusPtr->position.z))) > enemy2->varTable[3]) {
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

ApiStatus N(func_8024061C_C2F1BC)(ScriptInstance* script, s32 isInitialCall) {
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

    if ((script->functionTemp[0] < 30) && (enemy->varTable[0] == 0) && N(func_80240208_C2EDA8)(script)) {
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

void N(func_802408D0_C2F470)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80240958_C2F4F8)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80240C10_C2F7B0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->duration = 1;
        enemy->varTable[7] = 40;
        script->functionTemp[0] = 3;
    }
}

void N(func_80240C74_C2F814)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle((npc->yaw + rand_int(180)) - 90.0f);
    npc->currentAnim.w = enemy->animList[0];
    script->functionTemp[1] = (rand_int(1000) % 2) + 2;
    script->functionTemp[0] = 4;
}

void N(func_80240D1C_C2F8BC)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80240E54_C2F9F4)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80240F00_C2FAA0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80241078_C2FC18)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

ApiStatus N(func_802410D4_C2FC74)(ScriptInstance* script, s32 isInitialCall) {
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

    if (((u32)script->functionTemp[0] - 10 < 20) && (enemy->varTable[0] == 0) && N(func_80240208_C2EDA8)(script)) {
        script->functionTemp[0] = 30;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(func_802408D0_C2F470)(script, npcAISettings, territoryPtr);
            break;
        case 1:
            N(func_80240958_C2F4F8)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(func_80240C10_C2F7B0)(script, npcAISettings, territoryPtr);
            break;
        case 3:
            N(func_80240C74_C2F814)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_80240D1C_C2F8BC)(script, npcAISettings, territoryPtr);
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
            N(func_80240E54_C2F9F4)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0] != 41) {
                break;
            }
        case 41:
            N(func_80240F00_C2FAA0)(script, npcAISettings, territoryPtr);
            break;
        case 50:
            N(func_80241078_C2FC18)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return 0;
}
