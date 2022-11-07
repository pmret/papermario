#include "nok_02.h"

#define CHUCK_QUIZMO_NPC_ID 19

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

static char* N(exit_str_0) = "nok_02";
static char* N(exit_str_1) = "obk_09";

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_80242BD0_9D9BF0);

#define NAMESPACE dup_nok_02
extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}
#define NAMESPACE nok_02

extern s32 nok_02_D_802549D0[];

ApiStatus func_80242C5C_9D9C7C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            nok_02_D_802549D0[i] = ptr[i];
        }
        nok_02_D_802549D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            nok_02_D_802549D0[i] = i + 16;
            nok_02_D_802549D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

#include "world/common/todo/SwitchToPartner.inc.c"

ApiStatus func_80243010_9DA030(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 temp_f20;
    f32 temp_f22;
    f32 f3;

    temp_f22 = evt_get_variable(script, *args++);
    temp_f20 = evt_get_variable(script, *args++);
    f3 = evt_get_variable(script, *args++);

    fx_explosion(0, temp_f22, temp_f20 + 15.0f, f3);
    exec_ShakeCam1(0, 0, 20);
    return ApiStatus_DONE2;
}

// float regalloc
#ifdef NON_MATCHING
ApiStatus func_802430CC_9DA0EC(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Npc* npc1 = evt_get_variable(script, *args++);
    Npc* npc2 = evt_get_variable(script, *args++);
    s32 outVal = FALSE;
    f32 xDiff, zDiff;

    if (playerStatus->currentSpeed >= 4.0f) {
        script->varTable[2]++;
        if (script->varTable[2] > 2) {
            script->varTable[2] = 2;
        }
    } else {
        script->varTable[2] = 0;
    }

    xDiff = npc1->pos.x - playerStatus->position.x;
    zDiff = npc1->pos.z - playerStatus->position.z;
    if ((SQ(xDiff) + SQ(zDiff) < 6400.0f) && (script->varTable[2] >= 2)) {
        outVal = TRUE;
    }

    xDiff = npc1->pos.x - npc2->pos.x;
    zDiff = npc1->pos.z - npc2->pos.z;
    if (SQ(xDiff) + SQ(zDiff) < 1600.0f) {
        outVal = TRUE;
    }

    script->varTable[0] = outVal;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7AA0", func_802430CC_9DA0EC);
#endif

ApiStatus func_80243214_9DA234(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->currentSpeed >= 4.0f) {
        script->varTable[2]++;
        if (script->varTable[2] > 2) {
            script->varTable[2] = 2;
        }
    } else {
        script->varTable[2] = 0;
    }

    script->varTable[0] = 1;
    if (script->varTable[2] >= 2) {
        script->varTable[0] = 0;
    }
    if (playerStatus->currentSpeed == 0.0f) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80243294_9DA2B4(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 randRange = 10000;
    Npc* npc1 = (Npc*) evt_get_variable(script, *args++);
    Npc* npc2 = (Npc*) evt_get_variable(script, *args++);
    f32 xDiff, zDiff;
    f32 x, z;
    f32 dist;
    s32 rand;

    while (TRUE) {
        rand = rand_int(randRange);
        x = ((rand - (randRange / 2)) / 100) + npc1->pos.x;
        rand = rand_int(randRange);
        z = ((rand - (randRange / 2)) / 100) + npc1->pos.z;

        xDiff = x - -150.0f;
        zDiff = z - 250.0f;
        if (SQ(xDiff) + SQ(zDiff) < 22500.0f) {
            xDiff = x - playerStatus->position.x;
            zDiff = z - playerStatus->position.z;
            if (SQ(xDiff) + SQ(zDiff) > 6400.0f) {
                xDiff = x - npc2->pos.x;
                zDiff = z - npc2->pos.z;
                if (SQ(xDiff) + SQ(zDiff) > 1600.0f) {
                    break;
                }
            }
        }

        randRange += 5000;
        if (randRange > 30000) {
            randRange = 30000;
        }
    }
    xDiff = x - npc1->pos.x;
    zDiff = z - npc1->pos.z;
    dist = SQ(xDiff) + SQ(zDiff);
    if (dist != 0.0f) {
        dist = sqrtf(dist) / 10.0f;
    }
    script->varTable[10] = x;
    script->varTable[11] = z;
    script->varTable[12] = (s32) dist + 1;
    return ApiStatus_DONE2;
}

ApiStatus func_8024351C_9DA53C(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 randRange = 10000;
    Npc* npc = (Npc*) evt_get_variable(script, *args++);
    f32 xDiff, zDiff;
    f32 x, z;
    f32 dist;
    s32 rand;

    while (TRUE) {
        rand = rand_int(randRange);
        x = ((rand - (randRange / 2)) / 100) + npc->pos.x;
        rand = rand_int(randRange);
        z = ((rand - (randRange / 2)) / 100) + npc->pos.z;

        xDiff = x - -150.0f;
        zDiff = z - 250.0f;
        if (SQ(xDiff) + SQ(zDiff) < 22500.0f) {
            xDiff = x - playerStatus->position.x;
            zDiff = z - playerStatus->position.z;
            if (SQ(xDiff) + SQ(zDiff) > 6400.0f) {
                break;
            }
        }

        randRange += 5000;
        if (randRange > 30000) {
            randRange = 30000;
        }
    }
    xDiff = x - npc->pos.x;
    zDiff = z - npc->pos.z;
    dist = SQ(xDiff) + SQ(zDiff);
    if (dist != 0.0f) {
        dist = sqrtf(dist) / 10.0f;
    }
    script->varTable[10] = x;
    script->varTable[11] = z;
    script->varTable[12] = (s32) dist + 1;
    return ApiStatus_DONE2;
}

ApiStatus func_80243754_9DA774(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc;
    f32 yaw;

    if (isInitialCall) {
        script->functionTempPtr[1] = npc = (Npc*) evt_get_variable(script, *args++);
        npc->moveToPos.x = (evt_get_variable(script, *args++) + npc->pos.x) * 0.5f;
        npc->moveToPos.z = (evt_get_variable(script, *args++) + npc->pos.z) * 0.5f;
        npc->moveToPos.y = dist2D(npc->moveToPos.x, npc->moveToPos.z, npc->pos.x, npc->pos.z);
        script->functionTemp[2] = atan2(npc->moveToPos.x, npc->moveToPos.z, npc->pos.x, npc->pos.z);
        npc->duration = 0;
    }

    npc = script->functionTempPtr[1];
    npc->pos.x = npc->moveToPos.x;
    npc->pos.z = npc->moveToPos.z;

    npc->duration += 9;
    if (npc->duration >= 360) {
        npc->duration = 360;
    }
    yaw = script->functionTemp[2] + npc->duration;
    npc->yaw = clamp_angle(yaw + 90.0f);
    npc_move_heading(npc, npc->moveToPos.y, yaw);

    if (npc->duration == 360) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
