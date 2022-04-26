#include "dead.h"
#include "common.h"
#include "dead_structs.h"

// Copy of kzn_17 (C85DC0.c)

#define NAMESPACE EA0C10

const char ascii_EA6D70[] = "kzn_11";
const char ascii_EA6D78[] = "kzn_18";
extern s32 D_802466D0[];

void func_8004D8E0(DeadEnemy*);
void func_80240DC4_EA16C4(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory);

#include "world/common/enemy/state/MeleeHitbox_30.inc.c"

#include "world/common/enemy/state/MeleeHitbox_31.inc.c"

#include "world/common/enemy/state/MeleeHitbox_32.inc.c"

#include "world/common/enemy/state/MeleeHitbox_33.inc.c"

#include "world/common/enemy/state/MeleeHitbox_CanSeePlayer.inc.c"

// Similar to MeleeHitbox_Main
ApiStatus func_802406CC_EA0FCC(Evt* script, s32 isInitialCall) {
    DeadEnemy* enemy = (DeadEnemy*) script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Enemy* enemy2;
    Npc* npc2;
    f32 posX, posZ;

    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.0001f;
    enemy->unk_118 = 0.0001f;

    if (isInitialCall || enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->flags |= NPC_FLAG_2 | NPC_FLAG_100;
        enemy->flags |= ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000;
        npc->pos.x = 0.0f;
        npc->pos.y = -1000.0f;
        npc->pos.z = 0.0f;
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            enemy2 = get_enemy(enemy->npcID - 1);
            npc2 = get_npc_unsafe(enemy2->npcID);
            enemy->unk_07 = 1;
            if (enemy2->varTable[0] == 3) {
                if (enemy->varTable[15] != 0) {
                    ai_enemy_play_sound(npc2, enemy->varTable[15], 0);
                }
                posX = npc2->pos.x;
                posZ = npc2->pos.z;
                add_vec2D_polar(&posX, &posZ, enemy->varTable[1], 270.0f - npc2->renderYaw);

                npc->pos.x = posX;
                enemy->unk_10.x = npc->pos.x;

                npc->pos.y = npc2->pos.y + enemy->varTable[0];
                enemy->unk_10.y = npc->pos.y;

                npc->pos.z = posZ;
                enemy->unk_10.z = npc->pos.z;

                npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                enemy->flags &= ~(ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000);
                npc->duration = 0;
                script->functionTemp[0] = 1;
            }
            break;
        case 1:
            enemy2 = get_enemy(enemy->npcID - 1);
            get_npc_unsafe(enemy2->npcID);
            npc->duration++;
            if (npc->duration >= enemy->varTable[4]) {
                enemy->unk_07 = 0;
            }
            if (enemy2->varTable[0] == 4) {
                enemy->flags |= ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000;
                npc->pos.x = 0.0f;
                npc->pos.y = -1000.0f;
                npc->pos.z = 0.0f;
                enemy->unk_07 = 1;
                script->functionTemp[0] = 0;
            }
            break;
    }

    if (enemy->unk_07 != 0) {
        enemy->unk_114 = 7.0f;
        enemy->unk_118 = 1.0f;
    }

    return ApiStatus_BLOCK;
}

// Similar to WanderMeleeAI_Main
ApiStatus func_8024097C_EA127C(Evt* script, s32 isInitialCall) {
    DeadEnemy* enemy = (DeadEnemy*) script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 65.0f;
    territory.unk_1C = 0;

    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.0001f;
    enemy->unk_118 = 0.0001f;

    if (isInitialCall || enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | NPC_FLAG_GRAVITY) & ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags = (npc->flags & ~NPC_FLAG_GRAVITY) | NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
        enemy->varTable[0] = 0;
    }

    if (script->functionTemp[0] < 30 && enemy->varTable[0] == 0 && N(MeleeHitbox_CanSeePlayer)(script)) {
        script->functionTemp[0] = 30;
    }

    switch (script->functionTemp[0]) {
        case 0:
            basic_ai_wander_init(script, npcAISettings, territoryPtr);
            // fallthrough
        case 1:
            basic_ai_wander(script, npcAISettings, territoryPtr);
            break;
        case 2:
            basic_ai_loiter_init(script, npcAISettings, territoryPtr);
            // fallthrough
        case 3:
            basic_ai_loiter(script, npcAISettings, territoryPtr);
            break;
        case 10:
            basic_ai_found_player_jump_init(script, npcAISettings, territoryPtr);
            // fallthrough
        case 11:
            basic_ai_found_player_jump(script, npcAISettings, territoryPtr);
            break;
        case 12:
            basic_ai_chase_init(script, npcAISettings, territoryPtr);
            // fallthrough
        case 13:
            basic_ai_chase(script, npcAISettings, territoryPtr);
            break;
        case 14:
            basic_ai_lose_player(script, npcAISettings, territoryPtr);
            break;
        case 30:
            N(MeleeHitbox_30)(script);
            // fallthrough
        case 31:
            N(MeleeHitbox_31)(script);
            if (script->functionTemp[0] != 32) {
                break;
            }
        case 32:
            N(MeleeHitbox_32)(script);
            if (script->functionTemp[0] != 33) {
                break;
            }
        case 33:
            N(MeleeHitbox_33)(script);
            break;
        case 99:
            basic_ai_suspend(script);
            break;
    }

    return ApiStatus_BLOCK;
}

#include "world/common/enemy/state/PiranhaPlantAI_00.inc.c"

#include "world/common/enemy/state/PiranhaPlantAI_01.inc.c"

// sqrtf issue - Would be PiranhaPlantAI_10
INCLUDE_ASM(s32, "EA0C10", func_80240DC4_EA16C4);

#include "world/common/enemy/state/PiranhaPlantAI_11.inc.c"

#include "world/common/enemy/state/PiranhaPlantAI_12.inc.c"

#include "world/common/enemy/state/PiranhaPlantAI_13.inc.c"

#include "world/common/enemy/state/PiranhaPlantAI_14.inc.c"

#include "world/common/enemy/Dead_PiranhaPlantAI_Main.inc.c"

#include "world/common/enemy/UnkAI_StateHandlers_A.inc.c"

#include "world/common/enemy/Dead_LungeAI_Main.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

// Requires data migration
#ifdef NON_MATCHING
ApiStatus func_802429C0_EA32C0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        D_802441B8_EA4AB8 = FALSE;
    }

    if (D_802441B8_EA4AB8) {
        D_802441B8_EA4AB8 = FALSE;
        evt_set_variable(script, *args++, D_802441BC_EA4ABC);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "EA0C10", func_802429C0_EA32C0);
#endif

// Requires data migration
#ifdef NON_MATCHING
ApiStatus func_80242A14_EA3314(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_802441BC_EA4ABC = dead_evt_get_variable(script, *args++);
    D_802441B8_EA4AB8 = TRUE;

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "EA0C10", func_80242A14_EA3314);
#endif

ApiStatus func_80242A4C_EA334C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802466D0[i] = ptr[i];
        }
        D_802466D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802466D0[i] = i + 16;
            D_802466D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

// Requires data migration
#ifdef NON_MATCHING
ApiStatus func_80242D64_EA3664(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    D_80246894 = npc->currentAnim.w;
    npc->currentAnim.w = script->varTable[4];

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "EA0C10", func_80242D64_EA3664);
#endif

// Requires data migration
#ifdef NON_MATCHING
ApiStatus func_80242DA8_EA36A8(Evt* script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim.w = D_80246894;

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "EA0C10", func_80242DA8_EA36A8);
#endif
