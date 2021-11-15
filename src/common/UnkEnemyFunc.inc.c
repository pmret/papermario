#include "common.h"
#include "npc.h"

Actor* N(UnkEnemyFunc)(s32 arg0) {
    Actor* enemy = get_actor(ACTOR_ENEMY0);
    if (enemy != NULL && enemy->state.varTable[1] == arg0) {
        return enemy;
    }

    enemy = get_actor(ACTOR_ENEMY1);
    if (enemy != NULL && enemy->state.varTable[1] == arg0) {
        return enemy;
    }

    enemy = get_actor(ACTOR_ENEMY2);
    if (enemy != NULL && enemy->state.varTable[1] == arg0) {
        return enemy;
    }

    enemy = get_actor(ACTOR_ENEMY3);
    if (enemy != NULL && enemy->state.varTable[1] == arg0) {
        return enemy;
    }

    return NULL;
}
