#include "arn_02.h"
#include "sprite/npc/cleft.h"
#include "sprite/npc/goomba.h"

Script N(Exit1) = EXIT_WALK_SCRIPT(60, 0, "arn_05", 1);
Script N(Exit2) = EXIT_WALK_SCRIPT(60, 1, "arn_04", 0);

Script N(BindExits) = SCRIPT({
    bind N(Exit1) to TriggerFlag_FLOOR_ABOVE 1;
    bind N(Exit2) to TriggerFlag_FLOOR_ABOVE 6;
});

Script N(Main) = SCRIPT({
    SI_SAVE_VAR(425) = 34;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList));
    await N(MakeEntities);
    spawn N(PlayMusic);
    SI_VAR(0) = N(BindExits);
    spawn EnterWalk;
    sleep 1;
});

s32 N(padding2)[] = { 0, 0, 0 };

Script N(MakeEntities) = SCRIPT({
    MakeItemEntity(ItemId_DIZZY_DIAL, 0xFFFFFF08, 193, 45, 17, SI_SAVE_FLAG(1005));
    MakeItemEntity(ItemId_LETTER07, 536, 260, 227, 17, SI_SAVE_FLAG(1006));
    MakeEntity(0x802EA564, 0xFFFFFEA2, 172, 170, 0, ItemId_COIN, 0x80000000);
    AssignBlockFlag(SI_SAVE_FLAG(1002));
    MakeEntity(0x802EA564, 225, 265, 30, 0, ItemId_COIN, 0x80000000);
    AssignBlockFlag(SI_SAVE_FLAG(1003));
    MakeEntity(0x802EA564, 275, 265, 150, 0, ItemId_REPEL_GEL, 0x80000000);
    AssignBlockFlag(SI_SAVE_FLAG(1004));
});

NpcAISettings N(goombaAISettings) = {
    .moveSpeed = 1.8f, 
    .moveTime = 40, 
    .waitTime = 15, 
    .alertRadius = 150.0f, 
    .unk_10 = { .f = 0.0f }, 
    .unk_14 = 2, 
    .chaseSpeed = 3.3f, 
    .unk_1C = 70, 
    .unk_20 = 1, 
    .chaseRadius = 180.0f, 
    .unk_28 = { .f = 0.0f }, 
    .unk_2C = TRUE,
};

Script N(GoombaAI) = SCRIPT({
    DoBasicAI(N(goombaAISettings));
});

NpcSettings N(goombaNpcSettings) = {
    .unk_00 = { 0x00, 0x00, 0x00, 0x00 }, 
    .height = 20,
    .radius = 23, 
    .otherAI = NULL, 
    .onInteract = NULL,
    .ai = N(GoombaAI),
    .onHit = EnemyNpcHit, 
    .aux = NULL, 
    .onDefeat = EnemyNpcDefeat, 
    .flags = 0x00000000, 
    .unk_24 = { 0x00, 0x00, 0x00, 0x00 }, 
    .level = 12,
    .unk_2A = 0x0000,
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
    .unk_2C = TRUE,
};

Script N(CleftAI) = SCRIPT({
    func_80240C90_BDDE40(N(cleftAISettings), 8);
});

NpcSettings N(cleftNpcSettings) = {
    .unk_00 = { 0x00, 0x00, 0x00, 0x00 }, 
    .height = 24,
    .radius = 24, 
    .otherAI = NULL, 
    .onInteract = NULL,
    .ai = N(CleftAI),
    .onHit = EnemyNpcHit, 
    .aux = NULL, 
    .onDefeat = EnemyNpcDefeat, 
    .flags = 0x00000000, 
    .unk_24 = { 0x00, 0x00, 0x00, 0x00 }, 
    .level = 15,
    .unk_2A = 0x0000,
};

StaticNpc N(CleftNPC1) = {
    .id = 0,
    .settings = &N(cleftNpcSettings),
    .pos = { -196.0f, 130.0f, 104.0f },
    .flags = 0x00000400,
    .init = NULL,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 0,
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
    .unk_1E0 = { 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0 },
    .extraAnimations = NULL,
    .tattle = 0,
};

StaticNpc N(CleftNPC2) = {
    .id = 1,
    .settings = &N(cleftNpcSettings),
    .pos = { 641.0f, 268.0f, 202.0f },
    .flags = 0x00000400,
    .init = NULL,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 0,
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
    .unk_1E0 = { 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0 },
    .extraAnimations = NULL,
    .tattle = 0,
};

StaticNpc N(GoombaNPC) = {
    .id = 2,
    .settings = &N(goombaNpcSettings),
    .pos = { 333.0f, 215.0f, 85.0f },
    .flags = 0x00000400,
    .init = NULL,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 20,
    .itemDrops = {
        { ItemId_DRIED_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 0,
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
    .unk_1E0 = { 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0 },
    .extraAnimations = NULL,
    .tattle = 0,
};

NpcGroupList N(npcGroupList) = {
    NPC_GROUP(N(CleftNPC1), BATTLE_ID(14, 10, 0, 1)),
    NPC_GROUP(N(CleftNPC2), BATTLE_ID(14, 13, 0, 1)),
    NPC_GROUP(N(GoombaNPC), BATTLE_ID(14,  3, 0, 1)),
    {},
};

// gCameras loading after the offset calculation instead of before
#ifdef NON_MATCHING 
s32 func_80240000_BDD1B0(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
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
INCLUDE_ASM(s32, "world/area_arn/arn_02/BDD1B0", func_80240000_BDD1B0, ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape);
#endif

#include "world/common/UnkNpcAIFunc18.inc.c"

void func_802401D4_BDD384(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (script->functionTemp[1].s <= 0) {
        script->functionTemp[1].s = aiSettings->unk_14;
        if (func_800490B4(shape, enemy, aiSettings->alertRadius * 0.85, aiSettings->unk_10.s, 0)) {
            npc->currentAnim = enemy->animList[9];
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
            func_800494C0(npc, 0x2F4, 0x200000);
            npc->duration = 0xC;
            script->functionTemp[0].s = 2;
        }
    }

    script->functionTemp[1].s--;
}

#include "world/common/UnkNpcAIFunc21.inc.c"

#include "world/common/UnkNpcAIFunc20.inc.c"

#include "world/common/UnkNpcAIFunc22.inc.c"

void func_802404D0_BDD680(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    PlayerStatus** playerStatus;
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (func_800490B4(shape, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 0)) {
        playerStatus = &gPlayerStatusPtr;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z);
        script->functionTemp[0].s = 0xC;
    } else {
        npc->duration--;
        if (npc->duration <= 0) {
            script->functionTemp[1].s--;
            if (script->functionTemp[1].s > 0) {
                npc->yaw = clamp_angle(npc->yaw + 180.0f);
                npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            } else {
                fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xC, &var);
                npc->duration = 0xF;
                script->functionTemp[0].s = 0x28;
            }
        }
    }
}

#include "world/common/UnkNpcAIFunc16.inc.c"

void func_80240694_BDD844(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
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

void func_80240834_BDD9E4(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ;
    s32 phi_s1;

    func_8003D660(npc, 1);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    phi_s1 = 0;
    if (is_point_within_region(enemy->territory->shape, 
            enemy->territory->pointX, enemy->territory->pointZ, 
            npc->pos.x, npc->pos.z, enemy->territory->sizeX, 
            enemy->territory->sizeZ)) {
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

void func_80240984_BDDB34(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim = enemy->animList[1];
        if (enemy->territory->unk_14 < 0) {
            npc->moveSpeed = aiSettings->moveSpeed;
        } else {
            npc->moveSpeed = enemy->territory->unk_14 / 32767.0;
        }
        script->functionTemp[0].s = 0x29;
    }
}

void func_80240A30_BDDBE0(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    PlayerStatus** playerStatus = &gPlayerStatusPtr;

    if (func_800490B4(shape, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z);
        script->functionTemp[0].s = 12;
    } else if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->unk_00.x, enemy->territory->unk_00.z) <= npc->moveSpeed) {
        npc->duration = 10;
        script->functionTemp[0].s = 50;
    } else if (npc->unk_8C == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->unk_00.x, enemy->territory->unk_00.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

#include "world/common/UnkNpcAIFunc19.inc.c"

#include "world/common/UnkNpcAIFunc17.inc.c"

#include "world/common/UnkDurationCheck.inc.c"

s32 func_80240C90_BDDE40(ScriptInstance *script, NpcAISettings *aiSettings) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    NpcAISettings* npcAI = (NpcAISettings*)get_variable(script, *args++);
    EnemyTerritoryThing shape;
    EnemyTerritoryThing* shapePtr = &shape;
    u32 var;

    enemy->varTable[10] = get_variable(script, *args++);

    shape.unk_00 = 0;
    shape.shape = enemy->territory->shape;
    shape.pointX = enemy->territory->pointX;
    shape.pointZ = enemy->territory->pointZ;
    shape.sizeX = enemy->territory->sizeX;
    shape.sizeZ = enemy->territory->sizeZ;
    shape.unk_34 = 40.0f;
    shape.unk_1C = 0;

    if (aiSettings != NULL) {
        script->functionTemp[0].s = NULL;
        npc->duration = 0;
        npc->flags &= ~0x800;
        if (enemy->territory->unk_34 == 0) {
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

    if ((u32)script->functionTemp[0].s - 12 < 3 && func_80240000_BDD1B0(script, npcAI, shapePtr)) {
        script->functionTemp[0].s = 20;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(UnkNpcAIFunc18)(script, npcAI, shapePtr);
        case 1:
            func_802401D4_BDD384(script, npcAI, shapePtr);
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
            func_802404D0_BDD680(script, npcAI, shapePtr);
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
            func_80240694_BDD844(script, npcAI, shapePtr);
            return 0;
        case 22:
            func_80240834_BDD9E4(script, npcAI, shapePtr);
            return 0;
        case 40:
            func_80240984_BDDB34(script, npcAI, shapePtr);
            if (script->functionTemp[0].s != 41) {
                return 0;
            }
        case 41:
            func_80240A30_BDDBE0(script, npcAI, shapePtr);
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
