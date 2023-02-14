#include "common.h"
#include "model.h"

API_CALLABLE(N(UnkFunc56)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(evt_get_variable(script, *args++)));
    f32 xDiff, yDiff, zDiff, temp;
    Actor* actor;
    s32 i;

    script->varTable[2] = 0;

    actor = battleStatus->playerActor;
    if (actor != NULL) {
        xDiff = actor->currentPos.x - model->center.x;
        yDiff = actor->currentPos.y + actor->size.y - 1.5f - model->center.y;
        zDiff = actor->currentPos.z - model->center.z;
        temp = sqrtf(SQ(xDiff) + SQ(zDiff));

        if (yDiff > 0.0f && yDiff < actor->size.y && temp < actor->size.x * 0.5f) {
            script->varTable[2] = 1;
            return ApiStatus_DONE2;
        }
    }

    actor = battleStatus->partnerActor;
    if (actor != NULL) {
        xDiff = actor->currentPos.x - model->center.x;
        yDiff = actor->currentPos.y + actor->size.y - 1.5f - model->center.y;
        zDiff = actor->currentPos.z - model->center.z;
        temp = sqrtf(SQ(xDiff) + SQ(zDiff));

        if (yDiff > 0.0f && yDiff < actor->size.y && temp < actor->size.x * 0.5f) {
            script->varTable[2] = 1;
            return ApiStatus_DONE2;
        }
    }

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        ActorPart* part;

        actor = battleStatus->enemyActors[i];

        if (actor != NULL && !(actor->flags & ACTOR_FLAG_DISABLED)) {
            xDiff = actor->currentPos.x - model->center.x;
            yDiff = actor->currentPos.y + actor->size.y - 1.5f - model->center.y;
            zDiff = actor->currentPos.z - model->center.z;
            temp = sqrtf(SQ(xDiff) + SQ(zDiff));

            if (yDiff > 0.0f && yDiff < actor->size.y && temp < actor->size.x * 0.5f) {
                script->varTable[2] = 1;
                return ApiStatus_DONE2;
            }

            for (part = actor->partsTable; part != NULL; part = part->nextPart) {
                if (!(part->flags & ACTOR_PART_FLAG_INVISIBLE)) {
                    if (part->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION) {
                        xDiff = part->currentPos.x - model->center.x;
                        yDiff = part->currentPos.y + part->size.y - 1.5f - model->center.y;
                        zDiff = part->currentPos.z - model->center.z;
                        temp = sqrtf(SQ(xDiff) + SQ(zDiff));

                        if (yDiff > 0.0f && yDiff < part->size.y && temp < part->size.x * 0.5f) {
                            script->varTable[2] = 1;
                            return ApiStatus_DONE2;
                        }
                    }
                }
            }
        }
    }
    return ApiStatus_DONE2;
}
