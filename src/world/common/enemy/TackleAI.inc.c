// TackleAI
// used by Koopas, Koopatrols, Spinys, Buzzy Beetles

#include "common.h"
#include "npc.h"
#include "effects.h"
#include "sprite/npc/bony_beetle.h"

// prerequisites
#include "world/common/enemy/States_TackleAI.inc.c"

ApiStatus N(TackleAI_Main)(Evt* script, s32 isInitialCall) {
    #ifdef _DEAD_H_
    DeadEnemy* enemy = (DeadEnemy*)script->owner1.enemy;
    #else
    Enemy* enemy = script->owner1.enemy;
    #endif
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 100.0f;
    territory.detectFlags = 0;

    #ifdef _DEAD_H_
    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.01f;
    enemy->unk_118 = 0.01f;
    #endif

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->varTable[8] = 0;
        enemy->unk_B5 = 0;
        enemy->aiFlags |= ENEMY_AI_FLAGS_8;
    }

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->AI_TEMP_STATE = 0;
        npc->duration = 0;
        enemy->unk_07 = 0;
        npc->currentAnim = enemy->animList[ENEMY_ANIM_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;
        npc->collisionHeight = enemy->varTable[6];
        enemy->varTable[9] = 0;

        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }

        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            s32 emoteTemp;

            script->AI_TEMP_STATE = 99;
            script->functionTemp[1] = 0;
            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 40, &emoteTemp);
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->AI_TEMP_STATE = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    if (enemy->varTable[9] > 0) {
        enemy->varTable[9]--;
        if (enemy->varTable[9] == 0) {
            if (npc->currentAnim == NPC_ANIM_bony_beetle_Palette_00_Anim_2E ||
                npc->currentAnim == NPC_ANIM_bony_beetle_Palette_00_Anim_2F)
            {
                npc->currentAnim = NPC_ANIM_bony_beetle_Palette_00_Anim_C;
            }
        } else {
            return ApiStatus_BLOCK;
        }
    }

    switch (script->AI_TEMP_STATE) {
        case 0:
            basic_ai_wander_init(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
        case 1:
            basic_ai_wander(script, aiSettings, territoryPtr);
            break;
        case 2:
            basic_ai_loiter_init(script, aiSettings, territoryPtr);
            if (enemy->varTable[7] == 6) {
                if (rand_int(100) < 33) {
                    if (enemy->varTable[8] != 0) {
                        enemy->varTable[8] = 0;
                        enemy->unk_B5 = 0;
                        npc->currentAnim = NPC_ANIM_bony_beetle_Palette_00_Anim_2F;
                    } else {
                        enemy->varTable[8] = 1;
                        enemy->unk_B5 = 1;
                        npc->currentAnim = NPC_ANIM_bony_beetle_Palette_00_Anim_2E;
                    }
                    enemy->varTable[9] = 7;
                    return ApiStatus_BLOCK;
                }
            }
        case 3:
            basic_ai_loiter(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(set_script_owner_npc_anim)(script, aiSettings, territoryPtr);
        case 13:
            N(UnkDistFunc)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcAIFunc12)(script, aiSettings, territoryPtr);
            break;
        case 15:
            N(set_script_owner_npc_col_height)(script, aiSettings, territoryPtr);
            break;
        case 99:
            basic_ai_suspend(script);
            break;
    }

    if (enemy->varTable[7] == 6) {
        if (enemy->varTable[8] != 0) {
            enemy->unk_B5 = 1;
        } else {
            enemy->unk_B5 = 0;
        }
        if (enemy->varTable[8] != 0) {
            switch (npc->currentAnim) {
                case NPC_ANIM_bony_beetle_Palette_00_Anim_4:
                case NPC_ANIM_bony_beetle_Palette_00_Anim_C:
                case NPC_ANIM_bony_beetle_Palette_00_Anim_E:
                case NPC_ANIM_bony_beetle_Palette_00_Anim_10:
                case NPC_ANIM_bony_beetle_Palette_00_Anim_12:
                case NPC_ANIM_bony_beetle_Palette_00_Anim_16:
                case NPC_ANIM_bony_beetle_Palette_00_Anim_18:
                    npc->currentAnim++;
                    break;
            }
        }
    }

    return ApiStatus_BLOCK;
}

