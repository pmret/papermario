#include "arn_04.h"
#include "sprite/npc/paragoomba.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/cleft.h"

Script N(exitWalk_80243480) = EXIT_WALK_SCRIPT(60,  0, "arn_02",  1);

Script N(exitWalk_802434DC) = EXIT_WALK_SCRIPT(60,  1, "dgb_00",  0);

Script N(80243538) = SCRIPT({
    bind N(exitWalk_80243480) to TRIGGER_FLOOR_ABOVE 1;
    bind N(exitWalk_802434DC) to TRIGGER_FLOOR_ABOVE 6;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_GUSTY_GULCH;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80244000));
    await N(makeEntities);
    spawn N(802433D0);
    SI_VAR(0) = N(80243538);
    spawn EnterWalk;
    sleep 1;
});

static s32 N(pad_3654)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

NpcAISettings N(npcAISettings_80243660) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 130.0f,
    .unk_14 = 1,
    .chaseSpeed = 2.5f,
    .unk_1C = { .s = 180 },
    .unk_20 = 3,
    .chaseRadius = 150.0f,
    .unk_2C = 1,
};

Script N(npcAI_80243690) = SCRIPT({
    N(func_80240B94_BE4344)(N(npcAISettings_80243660));
});

NpcSettings N(npcSettings_802436B0) = {
    .height = 20,
    .radius = 23,
    .ai = &N(npcAI_80243690),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
};

f32 N(D_802436DC_BE6E8C)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_802436F4) = {
    .moveSpeed = 1.8f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 120.0f,
    .unk_14 = 3,
    .chaseSpeed = 4.0f,
    .unk_1C = { .s = 5 },
    .unk_20 = 1,
    .chaseRadius = 150.0f,
    .unk_2C = 1,
};

Script N(npcAI_80243724) = SCRIPT({
    SetSelfVar(0, 1);
    SetSelfVar(5, -850);
    SetSelfVar(6, 60);
    SetSelfVar(1, 700);
    N(func_8024219C_BE594C)(N(npcAISettings_802436F4));
});

NpcSettings N(npcSettings_80243794) = {
    .height = 18,
    .radius = 20,
    .ai = &N(npcAI_80243724),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
    .unk_2A = 1,
};

NpcAISettings N(npcAISettings_802437C0) = {
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

Script N(npcAI_802437F0) = SCRIPT({
    N(func_80243018_BE67C8)(N(npcAISettings_802437C0), 8);
});

NpcSettings N(npcSettings_80243814) = {
    .height = 24,
    .radius = 24,
    .ai = &N(npcAI_802437F0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 15,
};

StaticNpc N(npcGroup_80243840) = {
    .id = 0,
    .settings = &N(npcSettings_80243794),
    .pos = { -350.0f, 180.0f, 150.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 20,
    { ITEM_DRIED_SHROOM, 10, 0 },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { -350, 180, 150, 30, 0, -32767, 0, -350, 180, 150, 150 },
    .animations = {
        NPC_ANIM(paragoomba, hyper, idle),
        NPC_ANIM(paragoomba, hyper, walk),
        NPC_ANIM(paragoomba, hyper, run),
        NPC_ANIM(paragoomba, hyper, run),
        NPC_ANIM(paragoomba, hyper, idle),
        NPC_ANIM(paragoomba, hyper, idle),
        NPC_ANIM(paragoomba, hyper, pain),
        NPC_ANIM(paragoomba, hyper, pain),
        NPC_ANIM(paragoomba, hyper, attack),
        NPC_ANIM(paragoomba, hyper, run),
        NPC_ANIM(paragoomba, hyper, run),
        NPC_ANIM(paragoomba, hyper, run),
        NPC_ANIM(paragoomba, hyper, run),
        NPC_ANIM(paragoomba, hyper, run),
        NPC_ANIM(paragoomba, hyper, run),
        NPC_ANIM(paragoomba, hyper, run),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243A30) = {
    .id = 1,
    .settings = &N(npcSettings_802436B0),
    .pos = { 360.0f, 208.0f, 100.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 20,
    { ITEM_DRIED_SHROOM, 10, 0 },
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
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243C20) = {
    .id = 2,
    .settings = &N(npcSettings_80243814),
    .pos = { 150.0f, 177.0f, 160.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 3,
    .movement = { 150, 177, 160, 30, 0, -32767, 0, 150, 177, 160, 150 },
    .animations = {
        NPC_ANIM(cleft, hyper, idle),
        NPC_ANIM(cleft, hyper, walk),
        NPC_ANIM(cleft, hyper, run),
        NPC_ANIM(cleft, hyper, run),
        NPC_ANIM(cleft, hyper, idle),
        NPC_ANIM(cleft, hyper, idle),
        NPC_ANIM(cleft, hyper, skid),
        NPC_ANIM(cleft, hyper, skid),
        NPC_ANIM(cleft, hyper, rock),
        NPC_ANIM(cleft, hyper, rock_darken),
        NPC_ANIM(cleft, hyper, from_rock),
        NPC_ANIM(cleft, hyper, into_rock),
        NPC_ANIM(cleft, hyper, charge_still),
        NPC_ANIM(cleft, hyper, charge),
        NPC_ANIM(cleft, hyper, rock_lighten),
        NPC_ANIM(cleft, hyper, still),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243E10) = {
    .id = 3,
    .settings = &N(npcSettings_80243814),
    .pos = { 550.0f, 230.0f, 125.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 3,
    .movement = { 550, 230, 125, 30, 0, -32767, 0, 550, 230, 125, 150 },
    .animations = {
        NPC_ANIM(cleft, hyper, idle),
        NPC_ANIM(cleft, hyper, walk),
        NPC_ANIM(cleft, hyper, run),
        NPC_ANIM(cleft, hyper, run),
        NPC_ANIM(cleft, hyper, idle),
        NPC_ANIM(cleft, hyper, idle),
        NPC_ANIM(cleft, hyper, skid),
        NPC_ANIM(cleft, hyper, skid),
        NPC_ANIM(cleft, hyper, rock),
        NPC_ANIM(cleft, hyper, rock_darken),
        NPC_ANIM(cleft, hyper, from_rock),
        NPC_ANIM(cleft, hyper, into_rock),
        NPC_ANIM(cleft, hyper, charge_still),
        NPC_ANIM(cleft, hyper, charge),
        NPC_ANIM(cleft, hyper, rock_lighten),
        NPC_ANIM(cleft, hyper, still),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80244000) = {
    NPC_GROUP(N(npcGroup_80243840), BATTLE_ID(14, 9, 0, 1)),
    NPC_GROUP(N(npcGroup_80243A30), BATTLE_ID(14, 3, 0, 1)),
    NPC_GROUP(N(npcGroup_80243C20), BATTLE_ID(14, 12, 0, 1)),
    NPC_GROUP(N(npcGroup_80243E10), BATTLE_ID(14, 14, 0, 1)),
    {},
};

static s32 N(pad_403C)[] = {
    0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA564, 450, 285, 120, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1008));
    MakeEntity(0x802EA564, 720, 333, 75, 0, ITEM_COIN, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1009));
    MakeEntity(0x802EA0E8, 600, 290, 200, 0, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1010));
    MakeItemEntity(ITEM_STAR_PIECE, 540, 230, 13, 17, SI_SAVE_FLAG(1019));
});

void N(func_80240000_BE37B0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
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

    npc->currentAnim.w = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }

    script->functionTemp[0].s = 1;
}

void N(func_80240158_BE3908)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, z;
    s32 var;

    if (aiSettings->unk_14 >= 0) {
        if (script->functionTemp[1].s <= 0) {
            script->functionTemp[1].s = aiSettings->unk_14;
            if (func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
                ai_enemy_play_sound(npc, 0x2F4, 0x200000);
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

    if (npc->turnAroundYawAdjustment == 0) {
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

void N(func_802404C0_BE3C70)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if ((aiSettings->unk_14 >= 0) && func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        ai_enemy_play_sound(npc, 0x2F4, 0x200000);
        if (!(enemy->npcSettings->unk_2A & 1)) {
            script->functionTemp[0].s = 12;
        } else {
            script->functionTemp[0].s = 10;
        }
    } else if (npc->turnAroundYawAdjustment == 0) {
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

void N(func_8024067C_BE3E2C)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2].s = 0;
    }
    npc->currentAnim.w = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[0].s = 1;
}

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_80240B94_BE4344)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)get_variable(script, *args++);
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
        npc->currentAnim.w = enemy->animList[0];
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
            enemy->flags &= ~0x40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240000_BE37B0)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80240158_BE3908)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_802404C0_BE3C70)(script, aiSettings, territoryPtr);
            break;
        case 4:
            N(func_8024067C_BE3E2C)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, aiSettings, territoryPtr);
        case 13:
            N(UnkFunc15)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, aiSettings, territoryPtr);
            break;
        case 15:
            N(UnkFunc16)(script, aiSettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return ApiStatus_BLOCK;
}

#include "world/common/UnkNpcAIFunc23.inc.c"

#ifdef NON_MATCHING
// second npc_raycast_down_sides call
void N(func_80241040_BE47F0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
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
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
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
            phi_v0 = npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
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
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    ai_enemy_play_sound(npc, 0x2F4, 0x200000);
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

    if (is_point_within_region(enemy->territory->wander.wanderShape,
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
        if (npc->turnAroundYawAdjustment == 0) {
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
INCLUDE_ASM(void, "world/area_arn/arn_04/events", arn_04_func_80241040_BE47F0, ScriptInstance* script,
            NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1_copy.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80241AE4_BE5294)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_802436DC_BE6E8C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_8024219C_BE594C)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80241040_BE47F0)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 2:
            N(UnkNpcAIFunc1_copy)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241AE4_BE5294)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}

s32 N(func_80242388_BE5B38)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = CAM(gCurrentCamID);
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

void N(func_8024255C_BE5D0C)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (script->functionTemp[1].s <= 0) {
        script->functionTemp[1].s = aiSettings->unk_14;
        if (func_800490B4(territory, enemy, aiSettings->alertRadius * 0.85, aiSettings->unk_10.f, 0)) {
            npc->currentAnim.w = enemy->animList[9];
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
            ai_enemy_play_sound(npc, 0x2F4, 0x200000);
            npc->duration = 12;
            script->functionTemp[0].s = 2;
        }
    }

    script->functionTemp[1].s--;
}

#include "world/common/UnkNpcAIFunc21.inc.c"

#include "world/common/UnkNpcAIFunc20.inc.c"

#include "world/common/UnkNpcAIFunc22.inc.c"

#include "world/common/UnkFunc8.inc.c"

#include "world/common/UnkNpcAIFunc16.inc.c"

void N(func_80242A1C_BE61CC)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    if (npc->duration % 3 == 0) {
        fx_walk(2, npc->pos.x, npc->pos.y, npc->pos.z + 2.0f, 0, 0);
    }

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->unk_07 = 1;
        npc->moveSpeed = aiSettings->chaseSpeed;
        npc->duration = dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                               gPlayerStatusPtr->position.z) / npc->moveSpeed + 0.9;
        if (npc->duration < 15) {
            npc->duration = 15;
        }
        script->functionTemp[0].s = 0x16;
    }
}

#include "world/common/UnkFunc10.inc.c"

void N(func_80242D0C_BE64BC)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
        script->functionTemp[0].s = 0x29;
    }
}

#include "world/common/UnkFunc9.inc.c"

#include "world/common/UnkNpcAIFunc19.inc.c"

#include "world/common/UnkNpcAIFunc17.inc.c"

#include "world/common/UnkDurationCheck.inc.c"

ApiStatus N(func_80243018_BE67C8)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    NpcAISettings* aiSettings = (NpcAISettings*)get_variable(script, *args++);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    u32 var;

    enemy->varTable[10] = get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 40.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
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
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    if ((u32)script->functionTemp[0].s - 12 < 3 && N(func_80242388_BE5B38)(script, aiSettings, territoryPtr)) {
        script->functionTemp[0].s = 20;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(UnkNpcAIFunc18)(script, aiSettings, territoryPtr);
        case 1:
            N(func_8024255C_BE5D0C)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0].s != 2) {
                return ApiStatus_BLOCK;
            }
        case 2:
            N(UnkNpcAIFunc21)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0].s != 3) {
                return ApiStatus_BLOCK;
            }
        case 3:
            N(UnkNpcAIFunc20)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0].s != 4) {
                return ApiStatus_BLOCK;
            }
        case 4:
            N(UnkNpcAIFunc22)(script, aiSettings, territoryPtr);
        case 5:
            N(UnkFunc8)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 12:
            func_80049F7C(script, aiSettings, territoryPtr);
            if (script->functionTemp[0].s != 13) {
                return ApiStatus_BLOCK;
            }
        case 13:
            func_8004A124(script, aiSettings, territoryPtr);
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
            N(UnkNpcAIFunc16)(script, aiSettings, territoryPtr);
        case 21:
            N(func_80242A1C_BE61CC)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 22:
            N(UnkFunc10)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 40:
            N(func_80242D0C_BE64BC)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0].s != 41) {
                return ApiStatus_BLOCK;
            }
        case 41:
            N(UnkFunc9)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 50:
            N(UnkNpcAIFunc19)(script, aiSettings, territoryPtr);
        case 51:
            N(UnkNpcAIFunc17)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0].s != 52) {
                return ApiStatus_BLOCK;
            }
        case 52:
            N(UnkDurationCheck)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}
