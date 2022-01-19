#include "arn_04.h"
#include "sprite/npc/paragoomba.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/cleft.h"
#include "effects.h"

EvtScript N(exitWalk_80243480) = EXIT_WALK_SCRIPT(60,  0, "arn_02",  1);

EvtScript N(exitWalk_802434DC) = EXIT_WALK_SCRIPT(60,  1, "dgb_00",  0);

EvtScript N(80243538) = {
    EVT_BIND_TRIGGER(N(exitWalk_80243480), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_802434DC), TRIGGER_FLOOR_ABOVE, 6, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 34)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244000)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(802433D0))
    EVT_SET(EVT_VAR(0), EVT_PTR(N(80243538)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

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

EvtScript N(npcAI_80243690) = {
    EVT_CALL(N(UnkNpcAIMainFunc), EVT_PTR(N(npcAISettings_80243660)))
    EVT_RETURN
    EVT_END
};

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

EvtScript N(npcAI_80243724) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, -850)
    EVT_CALL(SetSelfVar, 6, 60)
    EVT_CALL(SetSelfVar, 1, 700)
    EVT_CALL(N(func_8024219C_BE594C), EVT_PTR(N(npcAISettings_802436F4)))
    EVT_RETURN
    EVT_END
};

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

EvtScript N(npcAI_802437F0) = {
    EVT_CALL(N(func_80243018_BE67C8), EVT_PTR(N(npcAISettings_802437C0)), 8)
    EVT_RETURN
    EVT_END
};

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
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 20,
    { ITEM_DRIED_SHROOM, 10, 0 },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { -350, 180, 150, 30, 0, -32767, 0, -350, 180, 150, 150 },
    .animations = {
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_walk,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_pain,
        NPC_ANIM_paragoomba_hyper_pain,
        NPC_ANIM_paragoomba_hyper_attack,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243A30) = {
    .id = 1,
    .settings = &N(npcSettings_802436B0),
    .pos = { 360.0f, 208.0f, 100.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 20,
    { ITEM_DRIED_SHROOM, 10, 0 },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 360, 208, 100, 30, 0, -32767, 0, 360, 208, 100, 150 },
    .animations = {
        NPC_ANIM_goomba_hyper_idle,
        NPC_ANIM_goomba_hyper_walk,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_idle,
        NPC_ANIM_goomba_hyper_idle,
        NPC_ANIM_goomba_hyper_pain,
        NPC_ANIM_goomba_hyper_pain,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243C20) = {
    .id = 2,
    .settings = &N(npcSettings_80243814),
    .pos = { 150.0f, 177.0f, 160.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 3,
    .movement = { 150, 177, 160, 30, 0, -32767, 0, 150, 177, 160, 150 },
    .animations = {
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_walk,
        NPC_ANIM_cleft_hyper_run,
        NPC_ANIM_cleft_hyper_run,
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_skid,
        NPC_ANIM_cleft_hyper_skid,
        NPC_ANIM_cleft_hyper_rock,
        NPC_ANIM_cleft_hyper_rock_darken,
        NPC_ANIM_cleft_hyper_from_rock,
        NPC_ANIM_cleft_hyper_into_rock,
        NPC_ANIM_cleft_hyper_charge_still,
        NPC_ANIM_cleft_hyper_charge,
        NPC_ANIM_cleft_hyper_rock_lighten,
        NPC_ANIM_cleft_hyper_still,
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243E10) = {
    .id = 3,
    .settings = &N(npcSettings_80243814),
    .pos = { 550.0f, 230.0f, 125.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 3,
    .movement = { 550, 230, 125, 30, 0, -32767, 0, 550, 230, 125, 150 },
    .animations = {
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_walk,
        NPC_ANIM_cleft_hyper_run,
        NPC_ANIM_cleft_hyper_run,
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_skid,
        NPC_ANIM_cleft_hyper_skid,
        NPC_ANIM_cleft_hyper_rock,
        NPC_ANIM_cleft_hyper_rock_darken,
        NPC_ANIM_cleft_hyper_from_rock,
        NPC_ANIM_cleft_hyper_into_rock,
        NPC_ANIM_cleft_hyper_charge_still,
        NPC_ANIM_cleft_hyper_charge,
        NPC_ANIM_cleft_hyper_rock_lighten,
        NPC_ANIM_cleft_hyper_still,
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

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EA564, 450, 285, 120, 0, 140, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1008))
    EVT_CALL(MakeEntity, 0x802EA564, 720, 333, 75, 0, 343, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1009))
    EVT_CALL(MakeEntity, 0x802EA0E8, 600, 290, 200, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1010))
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 540, 230, 13, 17, EVT_SAVE_FLAG(1019))
    EVT_RETURN
    EVT_END
};

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

#include "world/common/UnkNpcAIMainFunc.inc.c"

#include "world/common/UnkNpcAIFunc23.inc.c"

#include "world/common/UnkNpcAIFunc35.inc.c"

#include "world/common/UnkNpcAIFunc1_copy.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80241AE4_BE5294)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_802436DC_BE6E8C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_8024219C_BE594C)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings =(NpcAISettings*) evt_get_variable(script, *args);

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

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
        case 1:
            N(UnkNpcAIFunc35)(script, aiSettings, territoryPtr);
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

s32 N(func_80242388_BE5B38)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];
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
    if (gPartnerActionStatus.actionState.b[3]  == 9) {
        ret = FALSE;
    }
    return ret;
}

#include "world/common/UnkNpcAIFunc18.inc.c"

void N(func_8024255C_BE5D0C)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = aiSettings->unk_14;
        if (func_800490B4(territory, enemy, aiSettings->alertRadius * 0.85, aiSettings->unk_10.f, 0)) {
            npc->currentAnim.w = enemy->animList[9];
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
            ai_enemy_play_sound(npc, 0x2F4, 0x200000);
            npc->duration = 12;
            script->functionTemp[0] = 2;
        }
    }

    script->functionTemp[1]--;
}

#include "world/common/UnkNpcAIFunc21.inc.c"

#include "world/common/UnkNpcAIFunc20.inc.c"

#include "world/common/UnkNpcAIFunc22.inc.c"

#include "world/common/UnkFunc8.inc.c"

#include "world/common/UnkNpcAIFunc16.inc.c"

void N(func_80242A1C_BE61CC)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
        script->functionTemp[0] = 0x16;
    }
}

#include "world/common/UnkFunc10.inc.c"

void N(func_80242D0C_BE64BC)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

#include "world/common/UnkFunc9.inc.c"

#include "world/common/UnkNpcAIFunc19.inc.c"

#include "world/common/UnkNpcAIFunc17.inc.c"

#include "world/common/UnkDurationCheck.inc.c"

ApiStatus N(func_80243018_BE67C8)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    u32 var;

    enemy->varTable[10] = evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 40.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
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

    if ((u32)script->functionTemp[0] - 12 < 3 && N(func_80242388_BE5B38)(script, aiSettings, territoryPtr)) {
        script->functionTemp[0] = 20;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc18)(script, aiSettings, territoryPtr);
        case 1:
            N(func_8024255C_BE5D0C)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 2) {
                return ApiStatus_BLOCK;
            }
        case 2:
            N(UnkNpcAIFunc21)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 3) {
                return ApiStatus_BLOCK;
            }
        case 3:
            N(UnkNpcAIFunc20)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 4) {
                return ApiStatus_BLOCK;
            }
        case 4:
            N(UnkNpcAIFunc22)(script, aiSettings, territoryPtr);
        case 5:
            N(UnkFunc8)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 12:
            func_80049F7C(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                return ApiStatus_BLOCK;
            }
        case 13:
            func_8004A124(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 14) {
                return ApiStatus_BLOCK;
            }
        case 14:
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[0] = 40;
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
            if (script->functionTemp[0] != 41) {
                return ApiStatus_BLOCK;
            }
        case 41:
            N(UnkFunc9)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 50:
            N(UnkNpcAIFunc19)(script, aiSettings, territoryPtr);
        case 51:
            N(UnkNpcAIFunc17)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 52) {
                return ApiStatus_BLOCK;
            }
        case 52:
            N(UnkDurationCheck)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}
