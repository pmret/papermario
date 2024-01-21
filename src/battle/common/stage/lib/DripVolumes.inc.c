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
    Set(LVar1, ArrayVar(5))
    Add(LVar1, 1)
    Set(LVar2, ArrayVar(0))
    Set(LVar3, ArrayVar(1))
    Set(LVar4, ArrayVar(5))
    Add(LVar4, 2)
    Set(LVar5, ArrayVar(0))
    Set(LVar6, ArrayVar(1))
    Set(LVar7, ArrayVar(5))
    Add(LVar7, 3)
    Set(LVar8, ArrayVar(0))
    Set(LVar9, ArrayVar(1))
    Set(LVarA, ArrayVar(5))
    Add(LVarA, 4)
    Set(LVarB, ArrayVar(0))
    Set(LVarC, ArrayVar(1))
    Call(EnableModel, LVar1, TRUE)
    Call(EnableModel, LVar4, TRUE)
    Call(EnableModel, LVar7, TRUE)
    Call(EnableModel, LVarA, TRUE)
    Loop(5)
        Add(LVar0, 1)
        Add(LVar2, 1)
        Add(LVar3, 1)
        Call(TranslateModel, LVar1, LVar2, LVar0, LVar3)
        Call(ScaleModel, LVar1, Float(0.5), Float(0.5), Float(0.5))
        Add(LVar5, -1)
        Add(LVar6, 1)
        Call(TranslateModel, LVar4, LVar5, LVar0, LVar6)
        Call(ScaleModel, LVar4, Float(0.5), Float(0.5), Float(0.5))
        Add(LVar8, 1)
        Add(LVar9, -1)
        Call(TranslateModel, LVar7, LVar8, LVar0, LVar9)
        Call(ScaleModel, LVar7, Float(0.5), Float(0.5), Float(0.5))
        Add(LVarB, -1)
        Add(LVarC, -1)
        Call(TranslateModel, LVarA, LVarB, LVar0, LVarC)
        Call(ScaleModel, LVarA, Float(0.5), Float(0.5), Float(0.5))
        Wait(1)
    EndLoop
    Loop(5)
        Add(LVar0, -1)
        Add(LVar2, 1)
        Add(LVar3, 1)
        Call(TranslateModel, LVar1, LVar2, LVar0, LVar3)
        Call(ScaleModel, LVar1, Float(0.5), Float(0.5), Float(0.5))
        Add(LVar5, -1)
        Add(LVar6, 1)
        Call(TranslateModel, LVar4, LVar5, LVar0, LVar6)
        Call(ScaleModel, LVar4, Float(0.5), Float(0.5), Float(0.5))
        Add(LVar8, 1)
        Add(LVar9, -1)
        Call(TranslateModel, LVar7, LVar8, LVar0, LVar9)
        Call(ScaleModel, LVar7, Float(0.5), Float(0.5), Float(0.5))
        Add(LVarB, -1)
        Add(LVarC, -1)
        Call(TranslateModel, LVarA, LVarB, LVar0, LVarC)
        Call(ScaleModel, LVarA, Float(0.5), Float(0.5), Float(0.5))
        Wait(1)
    EndLoop
    Call(EnableModel, LVar1, FALSE)
    Call(EnableModel, LVar4, FALSE)
    Call(EnableModel, LVar7, FALSE)
    Call(EnableModel, LVarA, FALSE)
    Return
    End
};

EvtScript N(EVS_UpdateDripVolume) = {
    SetGroup(0)
    UseArray(LVarA)
    Set(LVar5, ArrayVar(5))
    Loop(5)
        Call(CloneModel, DROPLET_MODEL, LVar5)
        Call(TranslateModel, LVar5, ArrayVar(0), ArrayVar(2), ArrayVar(1))
        Add(LVar5, 1)
    EndLoop
    Label(0)
    Call(RandInt, 200, LVar0)
    Add(LVar0, 50)
    Wait(LVar0)
    Call(EnableModel, ArrayVar(5), TRUE)
    Call(MakeLerp, ArrayVar(2), ArrayVar(3), ArrayVar(4), EASING_QUADRATIC_IN)
    Label(1)
    Call(UpdateLerp)
    Call(TranslateModel, ArrayVar(5), ArrayVar(0), LVar0, ArrayVar(1))
    Wait(1)
    Call(N(CheckDripCollisionWithActors), ArrayVar(5))
    IfEq(LVar2, 1)
        Goto(10)
    EndIf
    IfEq(LVar1, 1)
        Goto(1)
    EndIf
    Label(10)
    Call(EnableModel, ArrayVar(5), FALSE)
    ExecWait(N(EVS_UpdateDripSplash))
    Goto(0)
    Return
    End
};

EvtScript N(EVS_CreateDripVolumes) = {
    Set(LVarF, CLONED_MODEL(0))
    UseBuf(LVar0)
    BufRead1(LVar1)
    Loop(LVar1)
        BufRead4(LVar2, LVar3, LVar4, LVar5)
        BufRead3(LVar6, LVar7, LVar8)
        BufRead1(LVar9)
        Loop(LVar9)
            MallocArray(6, LVarA)
            UseArray(LVarA)
            Call(RandInt, LVar4, LVarB)
            Call(RandInt, LVar5, LVarC)
            Set(LVarD, LVar2)
            Set(LVarE, LVar3)
            Add(LVarD, LVarB)
            Add(LVarE, LVarC)
            Set(ArrayVar(0), LVarD)
            Set(ArrayVar(1), LVarE)
            Set(ArrayVar(2), LVar6)
            Set(ArrayVar(3), LVar7)
            Set(ArrayVar(4), LVar8)
            Set(ArrayVar(5), LVarF)
            ChildThread
                Exec(N(EVS_UpdateDripVolume))
            EndChildThread
            Add(LVarF, 5)
        EndLoop
    EndLoop
    Call(EnableModel, DROPLET_MODEL, FALSE)
    Return
    End
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
