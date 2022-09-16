#include "common.h"
#include "npc.h"
#include "effects.h"

#ifdef _DEAD_H_
#include "dead_structs.h"
#endif

ApiStatus N(PiranhaPlantAI_Main)(Evt* script, s32 isInitialCall) {
    DeadEnemy* enemy = (DeadEnemy*) script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    MobileAISettings* settings = (MobileAISettings*) evt_get_variable(script, *script->ptrReadPos);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 200.0f;
    territory.detectFlags = 0;

    // Dead Func that doesn't seem to have an alive counterpart, probably because of the
    // difference in the Enemy and DeadEnemy struct.
    func_8004D8E0(enemy);
    if (enemy->flags & ENEMY_FLAGS_100000) {
        enemy->unk_114 = 10.0f;
        enemy->unk_118 = 0.7f;
    }

    if (isInitialCall || enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[ENEMY_ANIM_IDLE];
        enemy->varTable[0] = 0;

        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(PiranhaPlantAI_00)(script, settings, territoryPtr);
            /* fallthrough */
        case 1:
            N(PiranhaPlantAI_01)(script, settings, territoryPtr);
            break;
        case 10:
            func_80240DC4_EA16C4(script, settings, territoryPtr);
            if (script->functionTemp[0] != 11) {
                break;
            }
        case 11:
            N(PiranhaPlantAI_11)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 12) {
                break;
            }
        case 12:
            N(PiranhaPlantAI_12)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                break;
            }
        case 13:
            N(PiranhaPlantAI_13)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 14) {
                break;
            }
        case 14:
            N(PiranhaPlantAI_14)(script, settings, territoryPtr);
            break;
        case 99:
            basic_ai_suspend(script);
            break;
    }

    return ApiStatus_BLOCK;
}
