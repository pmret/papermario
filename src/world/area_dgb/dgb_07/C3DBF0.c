#include "dgb_07.h"
#include "message_ids.h"
#include "sprite/npc/world_clubba.h"

extern s16 gCurrentCamID;
extern Npc* wPartnerNpc;

enum {
    NPC_WORLD_CLUBBA0,
    NPC_WORLD_CLUBBA1,
};

EntryList N(entryList) = {
    { -450.0f,   0.0f,  -40.0f,   0.0f },
    {  250.0f, 190.0f, -250.0f, 180.0f },
};

MapConfig N(config) = {
    .main = N(main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = MSG_dgb_07_tattle,
};

Script N(80241490) = SCRIPT({
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

static s32 N(pad_1528)[] = {
    0x00000000, 0x00000000,
};

Script N(exitSingleDoor_80241530) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(0);
    SI_VAR(0) = 0;
    SI_VAR(1) = 6;
    SI_VAR(2) = 22;
    SI_VAR(3) = -1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("dgb_02", 2);
    sleep 100;
});

Script N(enterSingleDoor_802415E4) = SCRIPT({
    UseDoorSounds(0);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(2) = 22;
            SI_VAR(3) = -1;
            await EnterSingleDoor;
        }
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    if (STORY_PROGRESS < STORY_CH3_STAR_SPIRIT_RESCUED) {
        MakeNpcs(1, N(npcGroupList_80241E5C));
    }
    await N(makeEntities);
    bind N(exitSingleDoor_80241530) to TRIGGER_WALL_PRESS_A 6;
    spawn N(80241490);
    spawn N(enterSingleDoor_802415E4);
});

Script N(makeEntities) = SCRIPT({
    MakeItemEntity(ITEM_STAR_PIECE, -220, 75, -210, 17, SI_SAVE_FLAG(1050));
    MakeEntity(0x802EAED4, -370, 0, -200, 0, -1, MAKE_ENTITY_END);
    MakeEntity(0x802EAED4, -410, 0, -200, 0, -1, MAKE_ENTITY_END);
});

static s32 N(pad_17E4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(802417F0) = SCRIPT({
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

NpcAnimID N(extraAnimationList_802418AC)[] = {
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

NpcAnimID N(extraAnimationList_802418D4)[] = {
    NPC_ANIM(world_clubba, Palette_00, Anim_0),
    ANIM_END,
};

NpcAISettings N(npcAISettings_802418DC) = {
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

Script N(npcAI_8024190C) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(1, 10);
    SetSelfVar(2, 14);
    SetSelfVar(3, 18);
    N(func_80240E20_C3EA10)(N(npcAISettings_802418DC));
});

NpcSettings N(npcSettings_8024197C) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_8024190C),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 13,
};

Script N(npcAI_802419A8) = SCRIPT({
    EnableNpcShadow(NPC_SELF, FALSE);
    SetSelfVar(0, 4);
    SetSelfVar(1, 32);
    SetSelfVar(2, 50);
    SetSelfVar(3, 32);
    SetSelfVar(4, 3);
    SetSelfVar(15, 8389);
    N(UnkFunc7)();
});

NpcSettings N(npcSettings_80241A50) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_802419A8),
    .onDefeat = &N(802417F0),
    .level = 13,
    .unk_2A = 8,
};

StaticNpc N(npcGroup_80241A7C)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_8024197C),
        .pos = { -500.0f, 0.0f, -240.0f },
        .flags = NPC_FLAG_NO_Y_MOVEMENT,
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
        .movement = { -500, 0, -240, 40, 0, -32767, 0, -500, 0, -240, 200, 0, 0, 1 },
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
        .extraAnimations = &N(extraAnimationList_802418AC),
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_80241A50),
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
        .extraAnimations = &N(extraAnimationList_802418D4),
    },
};

NpcGroupList N(npcGroupList_80241E5C) = {
    NPC_GROUP(N(npcGroup_80241A7C), BATTLE_ID(15, 1, 0, 3)),
    {},
};

static const s32 N(pad_1E74)[] = {
    0x00000000, 0x00000000
};

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

s32 N(func_80240208_C3DDF8)(ScriptInstance *script) {
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

void N(func_8024061C_C3E20C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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

void N(func_802406A4_C3E294)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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

void N(func_8024095C_C3E54C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->duration = 1;
        enemy->varTable[7] = 40;
        script->functionTemp[0].s = 3;
    }
}

void N(func_802409C0_C3E5B0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle((npc->yaw + rand_int(180)) - 90.0f);
    npc->currentAnim = enemy->animList[0];
    script->functionTemp[1].s = (rand_int(1000) % 2) + 2;
    script->functionTemp[0].s = 4;
}

void N(func_80240A68_C3E658)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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

void N(func_80240BA0_C3E790)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80240C4C_C3E83C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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
    } else if (npc->turnAroundYawAdjustment == 0) {
        var = npc->yaw;
        func_8004A784(npc, 5.0f, &var, 0, 0, 0);
        npc->yaw = var;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

void N(func_80240DC4_C3E9B4)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    if (npc->turnAroundYawAdjustment == 0) {
        npc->duration--;
        if (npc->duration <= 0) {
            npc->duration = 0;
            script->functionTemp[0].s = 0;
        }
    }
}

ApiStatus N(func_80240E20_C3EA10)(ScriptInstance *script, s32 isInitialCall) {
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

    if (((u32)script->functionTemp[0].s - 10 < 20) && (enemy->varTable[0] == 0) && N(func_80240208_C3DDF8)(script)) {
        script->functionTemp[0].s = 30;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_8024061C_C3E20C)(script, npcAISettings, territoryPtr);
            break;
        case 1:
            N(func_802406A4_C3E294)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(func_8024095C_C3E54C)(script, npcAISettings, territoryPtr);
            break;
        case 3:
            N(func_802409C0_C3E5B0)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_80240A68_C3E658)(script, npcAISettings, territoryPtr);
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
            N(func_80240BA0_C3E790)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0].s != 41) {
                break;
            }
        case 41:
            N(func_80240C4C_C3E83C)(script, npcAISettings, territoryPtr);
            break;
        case 50:
            N(func_80240DC4_C3E9B4)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80241170_C3ED60)(ScriptInstance *script, s32 isInitialCall) {
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

    if ((script->functionTemp[0].s < 30) && (enemy->varTable[0] == 0) && N(func_80240208_C3DDF8)(script)) {
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
