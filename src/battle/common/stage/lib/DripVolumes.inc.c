#include "common.h"
#include "model.h"

#ifndef DROPLET_MODEL
#error  DROPLET_MODEL must be defined for DripVolumes
#define DROPLET_MODEL 0
#endif

API_CALLABLE(N(CheckDripCollisionWithActors)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(evt_get_variable(script, *args++)));
    f32 xDiff, yDiff, zDiff, temp;
    Actor* actor;
    s32 i;

    script->varTable[2] = 0;

    actor = battleStatus->playerActor;
    if (actor != NULL) {
        xDiff = actor->curPos.x - model->center.x;
        yDiff = actor->curPos.y + actor->size.y - 1.5f - model->center.y;
        zDiff = actor->curPos.z - model->center.z;
        temp = sqrtf(SQ(xDiff) + SQ(zDiff));

        if (yDiff > 0.0f && yDiff < actor->size.y && temp < actor->size.x * 0.5f) {
            script->varTable[2] = 1;
            return ApiStatus_DONE2;
        }
    }

    actor = battleStatus->partnerActor;
    if (actor != NULL) {
        xDiff = actor->curPos.x - model->center.x;
        yDiff = actor->curPos.y + actor->size.y - 1.5f - model->center.y;
        zDiff = actor->curPos.z - model->center.z;
        temp = sqrtf(SQ(xDiff) + SQ(zDiff));

        if (yDiff > 0.0f && yDiff < actor->size.y && temp < actor->size.x * 0.5f) {
            script->varTable[2] = 1;
            return ApiStatus_DONE2;
        }
    }

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        ActorPart* part;

        actor = battleStatus->enemyActors[i];

        if (actor != NULL && !(actor->flags & ACTOR_FLAG_INVISIBLE)) {
            xDiff = actor->curPos.x - model->center.x;
            yDiff = actor->curPos.y + actor->size.y - 1.5f - model->center.y;
            zDiff = actor->curPos.z - model->center.z;
            temp = sqrtf(SQ(xDiff) + SQ(zDiff));

            if (yDiff > 0.0f && yDiff < actor->size.y && temp < actor->size.x * 0.5f) {
                script->varTable[2] = 1;
                return ApiStatus_DONE2;
            }

            for (part = actor->partsTable; part != NULL; part = part->nextPart) {
                if (!(part->flags & ACTOR_PART_FLAG_INVISIBLE)) {
                    if (part->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION) {
                        xDiff = part->curPos.x - model->center.x;
                        yDiff = part->curPos.y + part->size.y - 1.5f - model->center.y;
                        zDiff = part->curPos.z - model->center.z;
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

EvtScript N(EVS_UpdateDripSplash) = {
    EVT_SET(LVar1, ArrayVar(5))
    EVT_ADD(LVar1, 1)
    EVT_SET(LVar2, ArrayVar(0))
    EVT_SET(LVar3, ArrayVar(1))
    EVT_SET(LVar4, ArrayVar(5))
    EVT_ADD(LVar4, 2)
    EVT_SET(LVar5, ArrayVar(0))
    EVT_SET(LVar6, ArrayVar(1))
    EVT_SET(LVar7, ArrayVar(5))
    EVT_ADD(LVar7, 3)
    EVT_SET(LVar8, ArrayVar(0))
    EVT_SET(LVar9, ArrayVar(1))
    EVT_SET(LVarA, ArrayVar(5))
    EVT_ADD(LVarA, 4)
    EVT_SET(LVarB, ArrayVar(0))
    EVT_SET(LVarC, ArrayVar(1))
    EVT_CALL(EnableModel, LVar1, TRUE)
    EVT_CALL(EnableModel, LVar4, TRUE)
    EVT_CALL(EnableModel, LVar7, TRUE)
    EVT_CALL(EnableModel, LVarA, TRUE)
    EVT_LOOP(5)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar3, 1)
        EVT_CALL(TranslateModel, LVar1, LVar2, LVar0, LVar3)
        EVT_CALL(ScaleModel, LVar1, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVar5, -1)
        EVT_ADD(LVar6, 1)
        EVT_CALL(TranslateModel, LVar4, LVar5, LVar0, LVar6)
        EVT_CALL(ScaleModel, LVar4, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVar8, 1)
        EVT_ADD(LVar9, -1)
        EVT_CALL(TranslateModel, LVar7, LVar8, LVar0, LVar9)
        EVT_CALL(ScaleModel, LVar7, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVarB, -1)
        EVT_ADD(LVarC, -1)
        EVT_CALL(TranslateModel, LVarA, LVarB, LVar0, LVarC)
        EVT_CALL(ScaleModel, LVarA, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(5)
        EVT_ADD(LVar0, -1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar3, 1)
        EVT_CALL(TranslateModel, LVar1, LVar2, LVar0, LVar3)
        EVT_CALL(ScaleModel, LVar1, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVar5, -1)
        EVT_ADD(LVar6, 1)
        EVT_CALL(TranslateModel, LVar4, LVar5, LVar0, LVar6)
        EVT_CALL(ScaleModel, LVar4, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVar8, 1)
        EVT_ADD(LVar9, -1)
        EVT_CALL(TranslateModel, LVar7, LVar8, LVar0, LVar9)
        EVT_CALL(ScaleModel, LVar7, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVarB, -1)
        EVT_ADD(LVarC, -1)
        EVT_CALL(TranslateModel, LVarA, LVarB, LVar0, LVarC)
        EVT_CALL(ScaleModel, LVarA, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVar1, FALSE)
    EVT_CALL(EnableModel, LVar4, FALSE)
    EVT_CALL(EnableModel, LVar7, FALSE)
    EVT_CALL(EnableModel, LVarA, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateDripVolume) = {
    EVT_SET_GROUP(0)
    EVT_USE_ARRAY(LVarA)
    EVT_SET(LVar5, ArrayVar(5))
    EVT_LOOP(5)
        EVT_CALL(CloneModel, DROPLET_MODEL, LVar5)
        EVT_CALL(TranslateModel, LVar5, ArrayVar(0), ArrayVar(2), ArrayVar(1))
        EVT_ADD(LVar5, 1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_CALL(RandInt, 200, LVar0)
    EVT_ADD(LVar0, 50)
    EVT_WAIT(LVar0)
    EVT_CALL(EnableModel, ArrayVar(5), TRUE)
    EVT_CALL(MakeLerp, ArrayVar(2), ArrayVar(3), ArrayVar(4), EASING_QUADRATIC_IN)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, ArrayVar(5), ArrayVar(0), LVar0, ArrayVar(1))
    EVT_WAIT(1)
    EVT_CALL(N(CheckDripCollisionWithActors), ArrayVar(5))
    EVT_IF_EQ(LVar2, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_CALL(EnableModel, ArrayVar(5), FALSE)
    EVT_EXEC_WAIT(N(EVS_UpdateDripSplash))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CreateDripVolumes) = {
    EVT_SET(LVarF, CLONED_MODEL(0))
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ1(LVar1)
    EVT_LOOP(LVar1)
        EVT_BUF_READ4(LVar2, LVar3, LVar4, LVar5)
        EVT_BUF_READ3(LVar6, LVar7, LVar8)
        EVT_BUF_READ1(LVar9)
        EVT_LOOP(LVar9)
            EVT_MALLOC_ARRAY(6, LVarA)
            EVT_USE_ARRAY(LVarA)
            EVT_CALL(RandInt, LVar4, LVarB)
            EVT_CALL(RandInt, LVar5, LVarC)
            EVT_SET(LVarD, LVar2)
            EVT_SET(LVarE, LVar3)
            EVT_ADD(LVarD, LVarB)
            EVT_ADD(LVarE, LVarC)
            EVT_SET(ArrayVar(0), LVarD)
            EVT_SET(ArrayVar(1), LVarE)
            EVT_SET(ArrayVar(2), LVar6)
            EVT_SET(ArrayVar(3), LVar7)
            EVT_SET(ArrayVar(4), LVar8)
            EVT_SET(ArrayVar(5), LVarF)
            EVT_CHILD_THREAD
                EVT_EXEC(N(EVS_UpdateDripVolume))
            EVT_END_CHILD_THREAD
            EVT_ADD(LVarF, 5)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_CALL(EnableModel, DROPLET_MODEL, FALSE)
    EVT_RETURN
    EVT_END
};

typedef struct DripVolume {
    /* 0x00 */ Vec2i minPos;
    /* 0x08 */ Vec2i maxPos;
    /* 0x10 */ s32 startY;
    /* 0x14 */ s32 endY;
    /* 0x18 */ s32 duration;
    /* 0x1C */ s32 density;
} DripVolume;

typedef struct DripVolumeList {
    /* 0x00 */ s32 count;
    /* 0x04 */ DripVolume volumes[VLA];
} DripVolumeList; // size = variable
