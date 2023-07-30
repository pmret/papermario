#ifndef _AI_TACKLE_STATES_INC_
#define _AI_TACKLE_STATES_INC_ 0

#include "common.h"
#include "npc.h"

// used with KoopaPatrolAI, TackleAI, SpinyAI
// all functions only used here

void N(set_script_owner_npc_anim)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_PRE];
    npc->duration = enemy->varTable[2];
    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
    script->AI_TEMP_STATE = 13;
}


ApiStatus N(UnkDistFunc)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if ((npc->duration <= 0) || (--npc->duration <= 0)) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_HIT];
            npc->moveSpeed = aiSettings->chaseSpeed;
            if ((enemy->varTable[7] == 5) || (enemy->varTable[7] == 0) || (enemy->varTable[7] == 1)) {
                npc->collisionHeight = enemy->varTable[6] / 2;
            }
            npc->duration = (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x,
                                    gPlayerStatusPtr->pos.z) / npc->moveSpeed) + 0.8;
            if (npc->duration < enemy->varTable[3]) {
                npc->duration = enemy->varTable[3];
            }
            enemy->varTable[4] = npc->duration;
            script->functionTemp[0] = 14;
        }
    }
}

void N(UnkNpcAIFunc12)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp;
    f32 f1;
    f32 f2;
    f32 f3;

    if (npc->duration == enemy->varTable[4] - 1) {
        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->hitboxIsActive = TRUE;
    }

    f1 = npc->pos.x;
    f2 = npc->pos.y;
    f3 = npc->pos.z;

    temp = npc_test_move_simple_with_slipping(npc->collisionChannel, &f1, &f2, &f3, npc->moveSpeed, npc->yaw, npc->collisionHeight, npc->collisionDiameter);
    if (temp == 0) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }

    if ((npc->duration <= 0) || (--npc->duration <= 0) || (temp != 0)) {
        enemy->hitboxIsActive = FALSE;
        npc->curAnim = enemy->animList[10];
        npc->duration = 0;
        script->functionTemp[0] = 15;
    }
}

void N(set_script_owner_npc_col_height)(Evt* script, MobileAISettings* aiSettings,
                                        EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration++;
    if (npc->duration == 3) {
        npc->collisionHeight = enemy->varTable[6];
    }

    if (npc->duration < enemy->varTable[5]) {
        return;
    }

    npc->collisionHeight = enemy->varTable[6];
    script->functionTemp[0] = 0;
}

#endif
