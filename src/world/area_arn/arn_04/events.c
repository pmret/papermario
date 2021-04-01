#include "arn_04.h"
#include "sprite/npc/paragoomba.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/cleft.h"

Script N(Exit1) = EXIT_WALK_SCRIPT(60, 0, "arn_02", 1);
Script N(Exit2) = EXIT_WALK_SCRIPT(60, 1, "dgb_00", 0);

Script N(ExitWalk) = SCRIPT({
    bind N(Exit1) to TRIGGER_FLOOR_ABOVE 1;
    bind N(Exit2) to TRIGGER_FLOOR_ABOVE 6;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_GUSTY_GULCH;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList));
    await N(makeEntities);
    spawn N(PlayMusic);
    SI_VAR(0) = N(ExitWalk);
    spawn EnterWalk;
    sleep 1;
});

s32 N(padding1)[] = { 0, 0, 0 };

NpcAISettings N(goombaAISettings) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 130.0f,
    .unk_10 = { .f = 0.0f },
    .unk_14 = 1,
    .chaseSpeed = 2.5f,
    .unk_1C = 180,
    .unk_20 = 3,
    .chaseRadius = 150.0f,
    .unk_28 = { .f = 0.0f },
    .unk_2C = 1,
};

Script N(goombaAI) = SCRIPT({
    N(func_80240B94_BE4344)(N(goombaAISettings));
});

NpcSettings N(goombaSettings) = {
    .height = 20,
    .radius = 23,
    .otherAI = NULL,
    .onInteract = NULL,
    .ai = &N(goombaAI),
    .onHit = EnemyNpcHit,
    .aux = NULL,
    .onDefeat = EnemyNpcDefeat,
    .flags = 0x00000000,
    .level = 12,
    .unk_2A = 0,
};

f32 N(D_802436DC_BE6E8C)[] = {
    4.5f, 3.5f, 2.6f, 2.0f, 
    1.5f, 20.0f, 
};

NpcAISettings N(paragoombaAISettings) = {
    .moveSpeed = 1.8f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 120.0f,
    .unk_10 = { .f = 0.0f },
    .unk_14 = 3,
    .chaseSpeed = 4.0f,
    .unk_1C = 5,
    .unk_20 = 1,
    .chaseRadius = 150.0f,
    .unk_28 = { .f = 0.0f },
    .unk_2C = 1,
};

Script N(paragoombaAI) = SCRIPT({
    SetSelfVar(0, 1);
    SetSelfVar(5, -850);
    SetSelfVar(6, 60);
    SetSelfVar(1, 700);
    N(func_8024219C_BE594C)(N(paragoombaAISettings));
});

NpcSettings N(paragoombaSettings) = {
    .height = 18,
    .radius = 20,
    .otherAI = NULL,
    .onInteract = NULL,
    .ai = &N(paragoombaAI),
    .onHit = EnemyNpcHit,
    .aux = NULL,
    .onDefeat = EnemyNpcDefeat,
    .flags = 0x00000000,
    .level = 12,
    .unk_2A = 1,
};

NpcAISettings N(cleftAISettings) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 120.0f,
    .unk_10 = { .f = 0.0f },
    .unk_14 = 3,
    .chaseSpeed = 8.5f,
    .unk_1C = 60,
    .unk_20 = 3,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 60.0f },
    .unk_2C = 1,
};

Script N(cleftAI) = SCRIPT({
    N(func_80243018_BE67C8)(N(cleftAISettings), 8);
});

NpcSettings N(cleftSettings) = {
    .height = 24,
    .radius = 24,
    .otherAI = NULL,
    .onInteract = NULL,
    .ai = &N(cleftAI),
    .onHit = EnemyNpcHit,
    .aux = NULL,
    .onDefeat = EnemyNpcDefeat,
    .flags = 0x00000000,
    .level = 15,
    .unk_2A = 0,
};

StaticNpc N(Paragoomba) = {
    .settings = &N(paragoombaSettings),
    .pos = { -350.0f, 180.0f, 150.0f },
    .flags = 0x00000400,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 20,
    .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { -350, 180, 150, 30, 0, -32767, 0, -350, 180, 150, 150 },
    .animations = {
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_3),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_1),
        NPC_ANIM(paragoomba, Palette_02, Anim_6),
        NPC_ANIM(paragoomba, Palette_02, Anim_6),
        NPC_ANIM(paragoomba, Palette_02, Anim_5),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
        NPC_ANIM(paragoomba, Palette_02, Anim_4),
    },
    .unk_1E0 = { 0, 0, 0, 1, 0, 0, 0, 0 },
};

StaticNpc N(Goomba) = {
    .id = 1,
    .settings = &N(goombaSettings),
    .pos = { 360.0f, 208.0f, 100.0f },
    .flags = 0x00000400,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 20,
    .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 360, 208, 100, 30, 0, -32767, 0, 360, 208, 100, 150 },
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
    .unk_1E0 = { 0, 0, 0, 1, 0, 0, 0, 0 },
};

StaticNpc N(Cleft1) = {
    .id = 2,
    .settings = &N(cleftSettings),
    .pos = { 150.0f, 177.0f, 160.0f },
    .flags = 0x00000400,
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 3,
    .movement = { 150, 177, 160, 30, 0, -32767, 0, 150, 177, 160, 150 },
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
    .unk_1E0 = { 0, 0, 0, 1, 0, 0, 0, 0 },
};

StaticNpc N(Cleft2) = {
    .id = 3,
    .settings = &N(cleftSettings),
    .pos = { 550.0f, 230.0f, 125.0f },
    .flags = 0x00000400,
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 3,
    .movement = { 550, 230, 125, 30, 0, -32767, 0, 550, 230, 125, 150 },
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
    .unk_1E0 = { 0, 0, 0, 1, 0, 0, 0, 0 },
};

NpcGroupList N(npcGroupList) = {
    NPC_GROUP(N(Paragoomba), BATTLE_ID(14, 9, 0, 1)),
    NPC_GROUP(N(Goomba), BATTLE_ID(14, 3, 0, 1)),
    NPC_GROUP(N(Cleft1), BATTLE_ID(14, 12, 0, 1)),
    NPC_GROUP(N(Cleft2), BATTLE_ID(14, 14, 0, 1)),
    {}
};

s32 N(padding2)[] = { 0 };

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA564, 450, 285, 120, 0, ITEM_SUPER_SHROOM, ARGS_END);
    AssignBlockFlag(SI_SAVE_FLAG(1008));
    MakeEntity(0x802EA564, 720, 333, 75, 0, ITEM_COIN, ARGS_END);
    AssignBlockFlag(SI_SAVE_FLAG(1009));
    MakeEntity(0x802EA0E8, 600, 290, 200, 0, ARGS_END);
    AssignBlockFlag(SI_SAVE_FLAG(1010));
    MakeItemEntity(ITEM_STAR_PIECE, 540, 230, 13, 17, SI_SAVE_FLAG(1019));
});

s32 N(func_80240000_BE37B0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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
        ret = dist2D(posX, posZ, (*(enemy->territory->patrol.points + i)).x, enemy->territory->patrol.points[i].z);
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

void N(func_80240158_BE3908)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, z;
    s32 var;

    if (aiSettings->unk_14 >= 0) {
        if (script->functionTemp[1].s <= 0) {
            script->functionTemp[1].s = aiSettings->unk_14;
            if (func_800490B4(shape, enemy, aiSettings->alertRadius, aiSettings->unk_10.s, 0)) {
                fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
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

    if (npc->unk_8C == 0) {
        if (npc->moveSpeed < 4.0) {
            func_8003D660(npc, 0);
        } else {
            func_8003D660(npc, 1);
        }
        
        x = (*(enemy->territory->patrol.points + script->functionTemp[2].s)).x;
        z = (*(enemy->territory->patrol.points + script->functionTemp[2].s)).z;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, x, z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, x, z) <= npc->moveSpeed) {
            script->functionTemp[0].s = 2;
            script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->moveTime <= 0) || 
                (aiSettings->waitTime <= 0) || (script->functionTemp[1].s == 0)) {
                script->functionTemp[0].s = 4;
            }
            if (rand_int(10000) % 100 < aiSettings->moveTime) {
                script->functionTemp[0].s = 4;
            }
        }
    }
}

#include "world/common/UnkNpcAIFunc1.inc.c"

void N(func_802404C0_BE3C70)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if ((aiSettings->unk_14 >= 0) && func_800490B4(shape, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 0)) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        func_800494C0(npc, 0x2F4, 0x200000);
        if (!(enemy->npcSettings->unk_2A & 1)) {
            script->functionTemp[0].s = 12;
        } else {
            script->functionTemp[0].s = 10;
        }
    } else if (npc->unk_8C == 0) {
        npc->duration--;
        if (npc->duration == 0) {
            script->functionTemp[1].s--;
            if (script->functionTemp[1].s != 0) {
                if (!(enemy->npcSettings->unk_2A & 0x10)) {
                    npc->yaw = clamp_angle(npc->yaw + 180.0f);
                }
                npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            } else {
                script->functionTemp[0].s = 4;
            }
        }
    }
}

s32 N(func_8024067C_BE3E2C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

s32 N(func_8024094C_BE40FC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (!func_800490B4(shape, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 1)) {
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
        npc->currentAnim = enemy->animList[0];
        npc->duration = 25;
        script->functionTemp[0].s = 14;
    } else {
        func_8003D660(npc, 1);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (npc->duration > 0) {
            npc->duration--;
        } else {
            script->functionTemp[0].s = 12;
        }
    }
}

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

void N(func_80240AD4_BE4284)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    for (i = script->functionTemp[2].s; i < enemy->territory->patrol.numPoints; i++) {
        if (i[enemy->territory->patrol.points].y <= npc->pos.y) {
            script->functionTemp[2].s = i;
            break;
        }
    }

    npc->moveSpeed = aiSettings->moveSpeed;
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    script->functionTemp[0].s = 1;
}

s32 N(func_80240B94_BE4344)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAI = (NpcAISettings*)get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.unk_30;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_34 = 65.0f;
    territory.unk_1C = 0;

    if (aiSettings != NULL || enemy->unk_B0 & 4) {
        script->functionTemp[0].s = NULL;
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
            N(func_80240000_BE37B0)(script, npcAI, territoryPtr);
        case 1:
            N(func_80240158_BE3908)(script, npcAI, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAI, territoryPtr);
        case 3:
            N(func_802404C0_BE3C70)(script, npcAI, territoryPtr);
            break;
        case 4:
            N(func_8024067C_BE3E2C)(script, npcAI, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAI, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAI, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAI, territoryPtr);
        case 13:
            N(func_8024094C_BE40FC)(script, npcAI, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAI, territoryPtr);
            break;
        case 15:
            N(func_80240AD4_BE4284)(script, npcAI, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return 0;
}

void N(func_80240E90_BE4640)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = aiSettings->moveTime / 2 + rand_int(aiSettings->moveTime / 2 + 1);
    if (is_point_within_region(enemy->territory->wander.unk_18, 
            enemy->territory->wander.point.x, enemy->territory->wander.point.z, 
            npc->pos.x, npc->pos.z, 
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    } else {
        npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    }
    npc->currentAnim = enemy->animList[1];
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
void N(func_80241040_BE47F0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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
                    func_800490B4(shape, enemy, aiSettings->alertRadius, aiSettings->unk_10.s, 0)) {
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

    if (is_point_within_region(enemy->territory->wander.unk_18, 
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
        if (npc->unk_8C == 0) {
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
INCLUDE_ASM(void, "world/area_arn/arn_04/BE37B0", arn_04_func_80241040_BE47F0,ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape);
#endif

#include "world/common/UnkNpcAIFunc1_copy.inc.c"

void N(func_80241728_BE4ED8)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f24 = (f32)enemy->varTable[3] / 100.0;
    f32 temp_f26 = temp_f24 + (f32)((f32)enemy->varTable[7] / 100.0);
    s32 var;

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (enemy->varTable[1] > 0) {
        f32 temp_f22 = (f32)enemy->varTable[1] / 100.0;
        f32 sin_degrees = sin_deg(enemy->varTable[2]);
        s32 phi_v0;

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
            npc->pos.y = posY + temp_f24 + (sin_degrees * temp_f22);
        } else {
            npc->pos.y = temp_f26 + (sin_degrees * temp_f22);
        }

        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) && func_800490B4(shape, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 1)) {
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
    } else {
        enemy->varTable[9]--;
    }

    if ((npc->unk_8C == 0) && (npc->duration <= 0)) {
        script->functionTemp[1].s--;
        if (script->functionTemp[1].s > 0) {
            if (!(enemy->npcSettings->unk_2A & 0x10)) {
                npc->yaw = clamp_angle(npc->yaw + 180.0f);
            }
            npc->duration = (rand_int(1000) % 11) + 5;
        } else {
            script->functionTemp[0].s = 0;
        }
    }
}

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80241AE4_BE5294)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_802436DC_BE6E8C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

void N(func_80241CE8_BE5498)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    s32 phi_v0;
    f32 phi_f20;
    f32 a = enemy->varTable[3];
    f32 b = enemy->varTable[7];

    npc->jumpVelocity += npc->jumpScale;
    temp_f20 = a / 100.0;
    temp_f22 = b / 100.0;
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    if (npc->jumpVelocity >= 0.0) {
        npc->pos.y += npc->jumpVelocity;
        npc->currentAnim = enemy->animList[9];
        enemy->unk_07 = 0;
        if (!(npc->flags & 8)) {
            posX = npc->pos.x;
            posY = npc->pos.y; 
            posZ = npc->pos.z; 
            posW = 1000.0f;
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
        } else {
            phi_v0 = FALSE;
        }
        if (phi_v0) {
            temp_f2 = posY + temp_f20;
            if (temp_f2 <= npc->pos.y) {
                npc->pos.y = temp_f2;
                script->functionTemp[0].s = 0;
            }
        } else if (npc->pos.y >= npc->moveToPos.y) {
            script->functionTemp[0].s = 0;
        }
    } else if (npc->jumpVelocity < 0.0) {
        npc->duration++;
        if (npc->duration >= aiSettings->unk_20) {
            npc->duration = 0;
            phi_f20 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
            temp_f0_2 = get_clamped_angle_diff(npc->yaw, phi_f20);
            if (aiSettings->unk_1C < fabsf(temp_f0_2)) {
                phi_f20 = npc->yaw;
                if (temp_f0_2 < 0.0f) {
                    phi_f20 += -aiSettings->unk_1C;
                } else {
                    phi_f20 += aiSettings->unk_1C;
                }
            }
            npc->yaw = clamp_angle(phi_f20);
        }

        if (npc->flags & 8) {
            if (npc->pos.y + npc->jumpVelocity < temp_f22) {
                npc->pos.y = temp_f22;
                npc->jumpVelocity = 0.0f;
            } else {
                npc->pos.y += npc->jumpVelocity;
            }
            return;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight; 
        posZ = npc->pos.z; 
        posW = (fabsf(npc->jumpVelocity) + npc->collisionHeight) + 10.0;
        if (func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            if (posW <= (npc->collisionHeight + fabsf(npc->jumpVelocity))) {
                npc->jumpVelocity = 0.0f;
                npc->pos.y = posY;
            } else {
                npc->pos.y += npc->jumpVelocity;
            }
            return;
        } else if (fabsf(npc->jumpVelocity) < ((npc->pos.y - temp_f22) + npc->collisionHeight)) {
            npc->pos.y = npc->pos.y + npc->jumpVelocity;
            return;
        }
        npc->jumpVelocity = 0.0f;
    }
}

void N(func_80242078_BE5828)(Npc *npc, Enemy *enemy, ScriptInstance *script, NpcAISettings *aiSettings) {
    f32 posX, posY, posZ, posW;
    s32 temp_a1;
    s32 temp_v1;
    s32 phi_v0;

    script->functionTemp[0].s = 0;
    npc->duration = 0;
    temp_v1 = npc->flags & ~0x200;
    npc->flags = (npc->flags & ~0x200) | 0x800;
    if (enemy->territory->wander.isFlying) {
        npc->flags = temp_v1 | 0x808;
    } else {
        npc->flags = npc->flags & ~8;
    }

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
    enemy->varTable[2] = 0;
    enemy->varTable[9] = 0;
    enemy->varTable[3] = ((posW * 100.0) + 0.5);
    enemy->varTable[7] = ((posY * 100.0) + 0.5);
    script->functionTemp[1].s = aiSettings->unk_14;
    enemy->unk_B0 |= 0x10;
}

s32 N(func_8024219C_BE594C)(ScriptInstance *script, NpcAISettings *aiSettings) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing shape;
    EnemyTerritoryThing* territoryPtr = &shape;
    NpcAISettings* aiSettings_var = get_variable(script, *args);

    shape.unk_00 = 0;
    shape.shape = enemy->territory->wander.unk_30;
    shape.pointX = enemy->territory->wander.detect.x;
    shape.pointZ = enemy->territory->wander.detect.z;
    shape.sizeX = enemy->territory->wander.detectSizeX;
    shape.sizeZ = enemy->territory->wander.detectSizeZ;
    shape.unk_34 = 120.0f;
    shape.unk_1C = 0;

    if (aiSettings != NULL) {
        N(func_80242078_BE5828)(npc, enemy, script, aiSettings_var);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return 0;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240E90_BE4640)(script, aiSettings_var, territoryPtr);
        case 1:
            N(func_80241040_BE47F0)(script, aiSettings_var, territoryPtr);
            return 0;
        case 2:
            N(UnkNpcAIFunc1_copy)(script, aiSettings_var, territoryPtr);
        case 3:
            N(func_80241728_BE4ED8)(script, aiSettings_var, territoryPtr);
            return 0;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings_var, territoryPtr);
        case 11:
            N(func_80241AE4_BE5294)(script, aiSettings_var, territoryPtr);
            return 0;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings_var, territoryPtr);
            return 0;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings_var, territoryPtr);
            return 0;
        case 14:
            N(func_80241CE8_BE5498)(script, aiSettings_var, territoryPtr);
            return 0;
    }

    return 0;
}

#ifdef NON_MATCHING
s32 N(func_80242388_BE5B38)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    PlayerStatus** playerStatus;
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = CAM(D_8009A634);
    f32 phi_f20;
    s32 phi_s0 = 0;

    if (func_800493EC(enemy, 0, aiSettings->alertRadius, aiSettings->unk_10.f)) {
        phi_s0 = 1;
    }
    phi_f20 = 270.0f;
    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        phi_f20 = 90.0f;
    }

    playerStatus = &gPlayerStatusPtr;
    if (fabsf(get_clamped_angle_diff(phi_f20, 
            atan2(npc->pos.x, npc->pos.z, 
                  (*playerStatus)->position.x, (*playerStatus)->position.z))) > 75.0) {
        phi_s0 = 0;
    }
    if (fabsf(npc->pos.y - (*playerStatus)->position.y) >= 40.0f) {
        phi_s0 = 0;
    }
    if (D_8010EBB0.unk_03 == 9) {
        phi_s0 = 0;
    }
    return phi_s0;
}
#else
INCLUDE_ASM(s32, "world/area_arn/arn_04/BE37B0", arn_04_func_80242388_BE5B38,ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape);
#endif

#include "world/common/UnkNpcAIFunc18.inc.c"

void N(func_8024255C_BE5D0C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (script->functionTemp[1].s <= 0) {
        script->functionTemp[1].s = aiSettings->unk_14;
        if (func_800490B4(shape, enemy, aiSettings->alertRadius * 0.85, aiSettings->unk_10.s, 0)) {
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

void N(func_80242858_BE6008)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    PlayerStatus** playerStatus;
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (func_800490B4(shape, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 0)) {
        playerStatus = &gPlayerStatusPtr;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z);
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

void N(func_80242A1C_BE61CC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    PlayerStatus** playerStatus = &gPlayerStatusPtr;

    npc->yaw = atan2(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z);
    if (npc->duration % 3 == 0) {
        fx_walk_normal(2, npc->pos.x, npc->pos.y, npc->pos.z + 2.0f, 0, 0);
    }

    npc->duration--;
    if (npc->duration <= 0) {
        playerStatus = &gPlayerStatusPtr;

        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->unk_07 = 1;
        npc->moveSpeed = aiSettings->chaseSpeed;
        npc->duration = dist2D(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z) / npc->moveSpeed + 0.9;
        if (npc->duration < 15) {
            npc->duration = 15;
        }
        script->functionTemp[0].s = 0x16;
    }
}

void N(func_80242BBC_BE636C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ;
    s32 phi_s1;

    func_8003D660(npc, 1);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    phi_s1 = 0;
    if (is_point_within_region(enemy->territory->wander.unk_30, 
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

void N(func_80242D0C_BE64BC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
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

void N(func_80242DB8_BE6568)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    PlayerStatus** playerStatus = &gPlayerStatusPtr;

    if (func_800490B4(shape, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z);
        script->functionTemp[0].s = 12;
    } else if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z) <= npc->moveSpeed) {
        npc->duration = 10;
        script->functionTemp[0].s = 50;
    } else if (npc->unk_8C == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

#include "world/common/UnkNpcAIFunc19.inc.c"

#include "world/common/UnkNpcAIFunc17.inc.c"

#include "world/common/UnkDurationCheck.inc.c"

s32 N(func_80243018_BE67C8)(ScriptInstance *script, NpcAISettings *aiSettings) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    NpcAISettings* npcAI = (NpcAISettings*)get_variable(script, *args++);
    EnemyTerritoryThing shape;
    EnemyTerritoryThing* shapePtr = &shape;
    u32 var;

    enemy->varTable[10] = get_variable(script, *args++);

    shape.unk_00 = 0;
    shape.shape = enemy->territory->wander.unk_30;
    shape.pointX = enemy->territory->wander.detect.x;
    shape.pointZ = enemy->territory->wander.detect.z;
    shape.sizeX = enemy->territory->wander.detectSizeX;
    shape.sizeZ = enemy->territory->wander.detectSizeZ;
    shape.unk_34 = 40.0f;
    shape.unk_1C = 0;

    if (aiSettings != NULL) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= 0x200;
            npc->flags &= ~0x8;
            
        } else {
            npc->flags &= ~0x200;
            npc->flags |= 0x8;
        }
    }

    if (enemy->unk_B0 & 4) { 
        if (enemy->unk_B4 != 0) {
            return 0;
        }
        enemy->unk_B0 &= ~4;
    }

    if ((u32)script->functionTemp[0].s - 12 < 3 && func_80242388_BE5B38(script, npcAI, shapePtr)) {
        script->functionTemp[0].s = 20;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(UnkNpcAIFunc18)(script, npcAI, shapePtr);
        case 1:
            N(func_8024255C_BE5D0C)(script, npcAI, shapePtr);
            if (script->functionTemp[0].s != 2) {
                return 0;
            }
        case 2:
            N(UnkNpcAIFunc21)(script, npcAI, shapePtr);
            if (script->functionTemp[0].s != 3) {
                return 0;
            }
        case 3:
            N(UnkNpcAIFunc20)(script, npcAI, shapePtr);
            if (script->functionTemp[0].s != 4) {
                return 0;
            }
        case 4:
            N(UnkNpcAIFunc22)(script, npcAI, shapePtr);
        case 5:
            N(func_80242858_BE6008)(script, npcAI, shapePtr);
            return 0;
        case 12:
            func_80049F7C(script, npcAI, shapePtr);
            if (script->functionTemp[0].s != 13) {
                return 0;
            }
        case 13:
            func_8004A124(script, npcAI, shapePtr);
            if (script->functionTemp[0].s != 14) {
                return 0;
            }
        case 14:
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[0].s = 40;
            }
            return 0;
        case 20:
            N(UnkNpcAIFunc16)(script, npcAI, shapePtr);
        case 21:
            N(func_80242A1C_BE61CC)(script, npcAI, shapePtr);
            return 0;
        case 22:
            N(func_80242BBC_BE636C)(script, npcAI, shapePtr);
            return 0;
        case 40:
            N(func_80242D0C_BE64BC)(script, npcAI, shapePtr);
            if (script->functionTemp[0].s != 41) {
                return 0;
            }
        case 41:
            N(func_80242DB8_BE6568)(script, npcAI, shapePtr);
            return 0;
        case 50:
            N(UnkNpcAIFunc19)(script, npcAI, shapePtr);
        case 51:
            N(UnkNpcAIFunc17)(script, npcAI, shapePtr);
            if (script->functionTemp[0].s != 52) {
                return 0;
            }
        case 52:
            N(UnkDurationCheck)(script, npcAI, shapePtr);
            return 0;
    }

    return 0;
}
