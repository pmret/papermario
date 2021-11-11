#include "flo_16.h"
#include "sprite/npc/tuff_puff.h"

enum {
    NPC_TUFF_PUFF0,
    NPC_TUFF_PUFF1,
};

f32 N(D_80244010_CD5E40)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80244028) = {
    .moveSpeed = 1.0f,
    .moveTime = 45,
    .waitTime = 60,
    .alertRadius = 100.0f,
    .unk_14 = 3,
    .chaseSpeed = 3.6f,
    .unk_1C = { .s = 10 },
    .unk_20 = 1,
    .chaseRadius = 120.0f,
    .unk_2C = 1,
};

EvtSource N(npcAI_80244058) = SCRIPT({
    SetSelfVar(0, 1);
    SetSelfVar(5, 0);
    SetSelfVar(6, 0);
    SetSelfVar(1, 600);
    N(func_80242754_CD4584)(N(npcAISettings_80244028));
});

NpcSettings N(npcSettings_802440C8) = {
    .height = 24,
    .radius = 28,
    .ai = &N(npcAI_80244058),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

StaticNpc N(npcGroup_802440F4) = {
    .id = NPC_TUFF_PUFF0,
    .settings = &N(npcSettings_802440C8),
    .pos = { 440.0f, 145.0f, 15.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 10,
    .itemDrops = {
        { ITEM_THUNDER_RAGE, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 440, 145, 15, 30, 0, -32767, 0, 485, 145, 55, 225, 95, 1 },
    .animations = {
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_6,
        NPC_ANIM_tuff_puff_Palette_00_Anim_6,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802442E4) = {
    .id = NPC_TUFF_PUFF1,
    .settings = &N(npcSettings_802440C8),
    .pos = { 600.0f, 145.0f, 15.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 10,
    .itemDrops = {
        { ITEM_THUNDER_RAGE, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 600, 145, 15, 30, 0, -32767, 0, 485, 145, 55, 225, 95, 1 },
    .animations = {
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_6,
        NPC_ANIM_tuff_puff_Palette_00_Anim_6,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_802444D4) = {
    NPC_GROUP(N(npcGroup_802440F4), BATTLE_ID(24, 36, 0, 6)),
    NPC_GROUP(N(npcGroup_802442E4), BATTLE_ID(24, 32, 0, 6)),
    {},
};

static s32 N(pad_44F8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(80244500) = SCRIPT({
    N(func_80242940_CD4770)();
    if (EVT_VAR(0) == 0) {
        return;
    }
    DisablePlayerInput(TRUE);
    if (EVT_AREA_FLAG(41) == 0) {
        EVT_VAR(5) = 0;
        EVT_VAR(6) = 50;
        EVT_VAR(7) = 0;
        EVT_VAR(8) = 180;
        EVT_AREA_FLAG(41) = 1;
    } else {
        EVT_VAR(5) = 50;
        EVT_VAR(6) = 0;
        EVT_VAR(7) = 180;
        EVT_VAR(8) = 0;
        EVT_AREA_FLAG(41) = 0;
    }
    sleep 15;
    PlaySound(0x204D);
    spawn {
        ShakeCam(0, 0, 30, 0.80078125);
        ShakeCam(0, 0, 5, 0.2001953125);
    }
    MakeLerp(EVT_VAR(5), EVT_VAR(6), 30, 0);
    loop {
        UpdateLerp();
        TranslateModel(94, 0, EVT_VAR(0), 0);
        TranslateGroup(97, 0, EVT_VAR(0), 0);
        TranslateModel(108, 0, EVT_VAR(0), 0);
        TranslateGroup(111, 0, EVT_VAR(0), 0);
        RotateGroup(97, EVT_VAR(7), 1, 0, 0);
        RotateGroup(111, EVT_VAR(7), 1, 0, 0);
        UpdateColliderTransform(26);
        UpdateColliderTransform(27);
        UpdateColliderTransform(32);
        UpdateColliderTransform(33);
        sleep 1;
        if (EVT_VAR(1) == 0) {
            break loop;
        }
    }
    DisablePlayerInput(FALSE);
    sleep 10;
    MakeLerp(EVT_VAR(7), EVT_VAR(8), 15, 0);
    loop {
        UpdateLerp();
        TranslateModel(94, 0, EVT_VAR(6), 0);
        TranslateGroup(97, 0, EVT_VAR(6), 0);
        TranslateModel(108, 0, EVT_VAR(6), 0);
        TranslateGroup(111, 0, EVT_VAR(6), 0);
        RotateGroup(97, EVT_VAR(0), 1, 0, 0);
        RotateGroup(111, EVT_VAR(0), 1, 0, 0);
        sleep 1;
        if (EVT_VAR(1) == 0) {
            break loop;
        }
    }
});

EvtSource N(802448FC) = SCRIPT({
    N(func_80242940_CD4770)();
    if (EVT_VAR(0) == 0) {
        return;
    }
    DisablePlayerInput(TRUE);
    if (EVT_AREA_FLAG(42) == 0) {
        EVT_VAR(5) = 0;
        EVT_VAR(6) = 50;
        EVT_VAR(7) = 0;
        EVT_VAR(8) = 180;
        EVT_AREA_FLAG(42) = 1;
    } else {
        EVT_VAR(5) = 50;
        EVT_VAR(6) = 0;
        EVT_VAR(7) = 180;
        EVT_VAR(8) = 0;
        EVT_AREA_FLAG(42) = 0;
    }
    sleep 15;
    PlaySound(0x204D);
    spawn {
        ShakeCam(0, 0, 30, 0.80078125);
        ShakeCam(0, 0, 5, 0.2001953125);
    }
    MakeLerp(EVT_VAR(5), EVT_VAR(6), 30, 0);
    loop {
        UpdateLerp();
        TranslateModel(101, 0, EVT_VAR(0), 0);
        TranslateGroup(104, 0, EVT_VAR(0), 0);
        TranslateModel(115, 0, EVT_VAR(0), 0);
        TranslateGroup(118, 0, EVT_VAR(0), 0);
        TranslateModel(129, 0, EVT_VAR(0), 0);
        TranslateGroup(132, 0, EVT_VAR(0), 0);
        RotateGroup(104, EVT_VAR(7), 1, 0, 0);
        RotateGroup(118, EVT_VAR(7), 1, 0, 0);
        RotateGroup(132, EVT_VAR(7), 1, 0, 0);
        UpdateColliderTransform(29);
        UpdateColliderTransform(30);
        UpdateColliderTransform(35);
        UpdateColliderTransform(36);
        UpdateColliderTransform(41);
        UpdateColliderTransform(42);
        sleep 1;
        if (EVT_VAR(1) == 0) {
            break loop;
        }
    }
    DisablePlayerInput(FALSE);
    sleep 10;
    MakeLerp(EVT_VAR(7), EVT_VAR(8), 15, 0);
    loop {
        UpdateLerp();
        TranslateModel(101, 0, EVT_VAR(6), 0);
        TranslateGroup(104, 0, EVT_VAR(6), 0);
        TranslateModel(115, 0, EVT_VAR(6), 0);
        TranslateGroup(118, 0, EVT_VAR(6), 0);
        TranslateModel(129, 0, EVT_VAR(6), 0);
        TranslateGroup(132, 0, EVT_VAR(6), 0);
        RotateGroup(104, EVT_VAR(0), 1, 0, 0);
        RotateGroup(118, EVT_VAR(0), 1, 0, 0);
        RotateGroup(132, EVT_VAR(0), 1, 0, 0);
        sleep 1;
        if (EVT_VAR(1) == 0) {
            break loop;
        }
    }
});

EvtSource N(80244DC8) = SCRIPT({
    N(func_80242940_CD4770)();
    if (EVT_VAR(0) == 0) {
        return;
    }
    DisablePlayerInput(TRUE);
    if (EVT_AREA_FLAG(43) == 0) {
        EVT_VAR(5) = 0;
        EVT_VAR(6) = -50;
        EVT_VAR(7) = 0;
        EVT_VAR(8) = 180;
        EVT_AREA_FLAG(43) = 1;
    } else {
        EVT_VAR(5) = -50;
        EVT_VAR(6) = 0;
        EVT_VAR(7) = 180;
        EVT_VAR(8) = 0;
        EVT_AREA_FLAG(43) = 0;
    }
    sleep 15;
    PlaySound(0x204D);
    spawn {
        ShakeCam(0, 0, 30, 0.80078125);
        ShakeCam(0, 0, 5, 0.2001953125);
    }
    MakeLerp(EVT_VAR(5), EVT_VAR(6), 30, 0);
    loop {
        UpdateLerp();
        TranslateModel(122, 0, EVT_VAR(0), 0);
        TranslateGroup(125, 0, EVT_VAR(0), 0);
        TranslateModel(136, 0, EVT_VAR(0), 0);
        TranslateGroup(139, 0, EVT_VAR(0), 0);
        RotateGroup(125, EVT_VAR(7), 1, 0, 0);
        RotateGroup(139, EVT_VAR(7), 1, 0, 0);
        UpdateColliderTransform(38);
        UpdateColliderTransform(39);
        UpdateColliderTransform(44);
        UpdateColliderTransform(45);
        sleep 1;
        if (EVT_VAR(1) == 0) {
            break loop;
        }
    }
    DisablePlayerInput(FALSE);
    sleep 10;
    MakeLerp(EVT_VAR(7), EVT_VAR(8), 15, 0);
    loop {
        UpdateLerp();
        TranslateModel(122, 0, EVT_VAR(6), 0);
        TranslateGroup(125, 0, EVT_VAR(6), 0);
        TranslateModel(136, 0, EVT_VAR(6), 0);
        TranslateGroup(139, 0, EVT_VAR(6), 0);
        RotateGroup(125, EVT_VAR(0), 1, 0, 0);
        RotateGroup(139, EVT_VAR(0), 1, 0, 0);
        sleep 1;
        if (EVT_VAR(1) == 0) {
            break loop;
        }
    }
});

EvtSource N(802451C4) = SCRIPT({
    EVT_AREA_FLAG(41) = 0;
    EVT_AREA_FLAG(42) = 0;
    EVT_AREA_FLAG(43) = 0;
    ParentColliderToModel(26, 94);
    ParentColliderToModel(27, 94);
    ParentColliderToModel(29, 101);
    ParentColliderToModel(30, 101);
    ParentColliderToModel(32, 108);
    ParentColliderToModel(33, 108);
    ParentColliderToModel(35, 115);
    ParentColliderToModel(36, 115);
    ParentColliderToModel(38, 122);
    ParentColliderToModel(39, 122);
    ParentColliderToModel(41, 129);
    ParentColliderToModel(42, 129);
    ParentColliderToModel(44, 136);
    ParentColliderToModel(45, 136);
    bind N(80244500) TRIGGER_FLOOR_TOUCH 26;
    bind N(802448FC) TRIGGER_FLOOR_TOUCH 29;
    bind N(80244500) TRIGGER_FLOOR_TOUCH 32;
    bind N(802448FC) TRIGGER_FLOOR_TOUCH 35;
    bind N(80244DC8) TRIGGER_FLOOR_TOUCH 38;
    bind N(802448FC) TRIGGER_FLOOR_TOUCH 41;
    bind N(80244DC8) TRIGGER_FLOOR_TOUCH 44;
});

#include "world/common/UnkNpcAIFunc23.inc.c"

#ifdef NON_EQUIVALENT
// second npc_raycast_down_sides call
void N(func_80241000_CD2E30)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[1] = aiSettings->unk_14;
                if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) &&
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0] = 10;
                    } else {
                        script->functionTemp[0] = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1]--;
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
            script->functionTemp[0] = 2;
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->waitTime <= 0) || (script->functionTemp[1] < 3)) {
                script->functionTemp[0] = 0;
            }
        }
    }
}
#else
INCLUDE_ASM(void, "world/area_flo/flo_16/CD2C80", flo_16_func_80241000_CD2E30, Evt* script,
            NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80241AA4_CD38D4)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80244010_CD5E40)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_8024215C_CD3F8C)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = evt_get_variable(script, *args);

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
            N(func_80241000_CD2E30)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241AA4_CD38D4)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkNpcAIFunc34.inc.c"

#include "world/common/UnkFunc45.inc.c"

ApiStatus N(func_80242754_CD4584)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = evt_get_variable(script, *args);

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
        script->functionTemp[0] = 0;
    }
    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80241000_CD2E30)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241AA4_CD38D4)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, aiSettings, territoryPtr);
        case 13:
            N(UnkNpcAIFunc34)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(UnkFunc45)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
