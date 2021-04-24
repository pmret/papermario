#include "arn_02.h"
#include "sprite/npc/cleft.h"
#include "sprite/npc/goomba.h"

Script N(exitWalk_802410F0) = EXIT_WALK_SCRIPT(60,  0, "arn_05",  1);

Script N(exitWalk_8024114C) = EXIT_WALK_SCRIPT(60,  1, "arn_04",  0);

Script N(802411A8) = SCRIPT({
    bind N(exitWalk_802410F0) to TRIGGER_FLOOR_ABOVE 1;
    bind N(exitWalk_8024114C) to TRIGGER_FLOOR_ABOVE 6;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_GUSTY_GULCH;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80241A9C));
    await N(makeEntities);
    spawn N(80241040);
    SI_VAR(0) = N(802411A8);
    spawn EnterWalk;
    sleep 1;
});

static s32 N(pad_12C4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeItemEntity(ITEM_DIZZY_DIAL, -248, 193, 45, 17, SI_SAVE_FLAG(1005));
    MakeItemEntity(ITEM_LETTER07, 536, 260, 227, 17, SI_SAVE_FLAG(1006));
    MakeEntity(0x802EA564, -350, 172, 170, 0, ITEM_COIN, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1002));
    MakeEntity(0x802EA564, 225, 265, 30, 0, ITEM_COIN, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1003));
    MakeEntity(0x802EA564, 275, 265, 150, 0, ITEM_REPEL_GEL, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1004));
});

NpcAISettings N(npcAISettings_802413D0) = {
    .moveSpeed = 1.8f,
    .moveTime = 40,
    .waitTime = 15,
    .alertRadius = 150.0f,
    .unk_14 = 2,
    .chaseSpeed = 3.3f,
    .unk_1C = { .s = 70 },
    .unk_20 = 1,
    .chaseRadius = 180.0f,
    .unk_2C = 1,
};

Script N(npcAI_80241400) = SCRIPT({
    DoBasicAI(N(npcAISettings_802413D0));
});

NpcSettings N(npcSettings_80241420) = {
    .height = 20,
    .radius = 23,
    .ai = &N(npcAI_80241400),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
};

NpcAISettings N(npcAISettings_8024144C) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 120.0f,
    .unk_14 = 3,
    .chaseSpeed = 8.5f,
    .unk_1C = { .s = 60 },
    .unk_20 = 3,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 60.0f },
    .unk_2C = 1,
};

Script N(npcAI_8024147C) = SCRIPT({
    N(func_80240C90_BDDE40)(N(npcAISettings_8024144C), 8);
});

NpcSettings N(npcSettings_802414A0) = {
    .height = 24,
    .radius = 24,
    .ai = &N(npcAI_8024147C),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 15,
};

StaticNpc N(npcGroup_802414CC) = {
    .id = 0,
    .settings = &N(npcSettings_802414A0),
    .pos = { -196.0f, 130.0f, 104.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 3,
    .movement = { -196, 130, 104, 50, 30, -32767, 1, -196, 130, 104, 120 },
    .animations = {
        NPC_ANIM(cleft, Palette_01, Anim_2),
        NPC_ANIM(cleft, Palette_01, Anim_6),
        NPC_ANIM(cleft, Palette_01, Anim_7),
        NPC_ANIM(cleft, Palette_01, Anim_7),
        NPC_ANIM(cleft, Palette_01, Anim_2),
        NPC_ANIM(cleft, Palette_01, Anim_2),
        NPC_ANIM(cleft, Palette_01, Anim_8),
        NPC_ANIM(cleft, Palette_01, Anim_8),
        NPC_ANIM(cleft, Palette_01, Anim_14),
        NPC_ANIM(cleft, Palette_01, Anim_17),
        NPC_ANIM(cleft, Palette_01, Anim_13),
        NPC_ANIM(cleft, Palette_01, Anim_15),
        NPC_ANIM(cleft, Palette_01, Anim_10),
        NPC_ANIM(cleft, Palette_01, Anim_11),
        NPC_ANIM(cleft, Palette_01, Anim_16),
        NPC_ANIM(cleft, Palette_01, Anim_0),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802416BC) = {
    .id = 1,
    .settings = &N(npcSettings_802414A0),
    .pos = { 641.0f, 268.0f, 202.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 3,
    .movement = { 641, 268, 202, 50, 30, -32767, 1, 641, 268, 202, 120 },
    .animations = {
        NPC_ANIM(cleft, Palette_01, Anim_2),
        NPC_ANIM(cleft, Palette_01, Anim_6),
        NPC_ANIM(cleft, Palette_01, Anim_7),
        NPC_ANIM(cleft, Palette_01, Anim_7),
        NPC_ANIM(cleft, Palette_01, Anim_2),
        NPC_ANIM(cleft, Palette_01, Anim_2),
        NPC_ANIM(cleft, Palette_01, Anim_8),
        NPC_ANIM(cleft, Palette_01, Anim_8),
        NPC_ANIM(cleft, Palette_01, Anim_14),
        NPC_ANIM(cleft, Palette_01, Anim_17),
        NPC_ANIM(cleft, Palette_01, Anim_13),
        NPC_ANIM(cleft, Palette_01, Anim_15),
        NPC_ANIM(cleft, Palette_01, Anim_10),
        NPC_ANIM(cleft, Palette_01, Anim_11),
        NPC_ANIM(cleft, Palette_01, Anim_16),
        NPC_ANIM(cleft, Palette_01, Anim_0),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802418AC) = {
    .id = 2,
    .settings = &N(npcSettings_80241420),
    .pos = { 333.0f, 215.0f, 85.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 20,
        { ITEM_DRIED_SHROOM, 10, 0 },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 333, 215, 85, 40, 30, -32767, 1, 360, 215, 150, 120, 137, 1 },
    .animations = {
        NPC_ANIM(goomba, hyper, idle),
        NPC_ANIM(goomba, hyper, walk),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, idle),
        NPC_ANIM(goomba, hyper, idle),
        NPC_ANIM(goomba, hyper, pain),
        NPC_ANIM(goomba, hyper, pain),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80241A9C) = {
    NPC_GROUP(N(npcGroup_802414CC), BATTLE_ID(14, 10, 0, 1)),
    NPC_GROUP(N(npcGroup_802416BC), BATTLE_ID(14, 13, 0, 1)),
    NPC_GROUP(N(npcGroup_802418AC), BATTLE_ID(14, 3, 0, 1)),
    {},
};

s32 N(func_80240000_BDD1B0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    PlayerStatus** playerStatus;
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = CAM2(gCurrentCamID);
    f32 phi_f20;
    s32 ret = FALSE;

    if (func_800493EC(enemy, 0, aiSettings->alertRadius, aiSettings->unk_10.f)) {
        ret = TRUE;
    }
    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        phi_f20 = 90.0f;
    } else {
        phi_f20 = 270.0f;
    }

    playerStatus = &gPlayerStatusPtr;
    if (fabsf(get_clamped_angle_diff(phi_f20,
            atan2(npc->pos.x, npc->pos.z,
                  gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z))) > 75.0) {
        ret = FALSE;
    }
    if (fabsf(npc->pos.y - gPlayerStatusPtr->position.y) >= 40.0f) {
        ret = FALSE;
    }
    if (D_8010EBB0.unk_03 == 9) {
        ret = FALSE;
    }
    return ret;
}

#include "world/common/UnkNpcAIFunc18.inc.c"

void N(func_802401D4_BDD384)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (script->functionTemp[1].s <= 0) {
        script->functionTemp[1].s = aiSettings->unk_14;
        if (func_800490B4(territory, enemy, aiSettings->alertRadius * 0.85, aiSettings->unk_10.f, 0)) {
            npc->currentAnim = enemy->animList[9];
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
            func_800494C0(npc, 0x2F4, 0x200000);
            npc->duration = 12;
            script->functionTemp[0].s = 2;
        }
    }

    script->functionTemp[1].s--;
}

#include "world/common/UnkNpcAIFunc21.inc.c"

#include "world/common/UnkNpcAIFunc20.inc.c"

#include "world/common/UnkNpcAIFunc22.inc.c"

void N(func_802404D0_BDD680)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->functionTemp[0].s = 12;
    } else {
        npc->duration--;
        if (npc->duration <= 0) {
            script->functionTemp[1].s--;
            if (script->functionTemp[1].s > 0) {
                npc->yaw = clamp_angle(npc->yaw + 180.0f);
                npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            } else {
                fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                npc->duration = 15;
                script->functionTemp[0].s = 0x28;
            }
        }
    }
}

#include "world/common/UnkNpcAIFunc16.inc.c"

void N(func_80240694_BDD844)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    if (npc->duration % 3 == 0) {
        fx_walk_normal(2, npc->pos.x, npc->pos.y, npc->pos.z + 2.0f, 0, 0);
    }

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->unk_07 = 1;
        npc->moveSpeed = aiSettings->chaseSpeed;
        npc->duration = dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) / npc->moveSpeed + 0.9;
        if (npc->duration < 15) {
            npc->duration = 15;
        }
        script->functionTemp[0].s = 0x16;
    }
}

void N(func_80240834_BDD9E4)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ;
    s32 phi_s1;

    func_8003D660(npc, 1);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    phi_s1 = 0;
    if (is_point_within_region(enemy->territory->wander.detectShape,
            enemy->territory->wander.detect.x, enemy->territory->wander.detect.z,
            npc->pos.x, npc->pos.z, enemy->territory->wander.detectSizeX,
            enemy->territory->wander.detectSizeZ)) {
        phi_s1 = 1;
    }

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;

    if (func_800DDC44(npc->unk_80, &posX, &posY, &posZ,
            1.0f, npc->yaw, npc->collisionHeight, npc->collisionRadius)) {
        phi_s1 = 1;
    }

    npc->duration--;
    if (npc->duration <= 0) {
        phi_s1 = 1;
    }
    if (phi_s1) {
        script->functionTemp[0].s = 4;
        enemy->unk_07 = 0;
    }
}

void N(func_80240984_BDDB34)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

void N(func_80240A30_BDDBE0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->functionTemp[0].s = 12;
    } else if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z) <= npc->moveSpeed) {
        npc->duration = 10;
        script->functionTemp[0].s = 50;
    } else if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

#include "world/common/UnkNpcAIFunc19.inc.c"

#include "world/common/UnkNpcAIFunc17.inc.c"

#include "world/common/UnkDurationCheck.inc.c"

s32 N(func_80240C90_BDDE40)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;

    enemy->varTable[10] = get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_34 = 40.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
    }

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    if ((u32)script->functionTemp[0].s - 12 < 3 && N(func_80240000_BDD1B0)(script, npcAISettings, territoryPtr)) {
        script->functionTemp[0].s = 20;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(UnkNpcAIFunc18)(script, npcAISettings, territoryPtr);
        case 1:
            N(func_802401D4_BDD384)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0].s != 2) {
                return ApiStatus_BLOCK;
            }
        case 2:
            N(UnkNpcAIFunc21)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0].s != 3) {
                return ApiStatus_BLOCK;
            }
        case 3:
            N(UnkNpcAIFunc20)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0].s != 4) {
                return ApiStatus_BLOCK;
            }
        case 4:
            N(UnkNpcAIFunc22)(script, npcAISettings, territoryPtr);
        case 5:
            N(func_802404D0_BDD680)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 12:
            func_80049F7C(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0].s != 13) {
                return ApiStatus_BLOCK;
            }
        case 13:
            func_8004A124(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0].s != 14) {
                return ApiStatus_BLOCK;
            }
        case 14:
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[0].s = 40;
            }
            return ApiStatus_BLOCK;
        case 20:
            N(UnkNpcAIFunc16)(script, npcAISettings, territoryPtr);
        case 21:
            N(func_80240694_BDD844)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 22:
            N(func_80240834_BDD9E4)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 40:
            N(func_80240984_BDDB34)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0].s != 41) {
                return ApiStatus_BLOCK;
            }
        case 41:
            N(func_80240A30_BDDBE0)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 50:
            N(UnkNpcAIFunc19)(script, npcAISettings, territoryPtr);
        case 51:
            N(UnkNpcAIFunc17)(script, npcAISettings, territoryPtr);
            if (script->functionTemp[0].s != 52) {
                return ApiStatus_BLOCK;
            }
        case 52:
            N(UnkDurationCheck)(script, npcAISettings, territoryPtr);
            return ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}
