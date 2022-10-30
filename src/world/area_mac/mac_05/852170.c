#include "mac_05.h"
#include "effects.h"

static char* N(exit_str_0) = "mac_04";
static char* N(exit_str_1) = "kgr_01";

#define CHUCK_QUIZMO_NPC_ID 6

#include "world/common/atomic/TexturePan.inc.c"

#define NAMESPACE dup_mac_05
#include "world/common/todo/UnkFloatFunc001.inc.c"
#define NAMESPACE mac_05

ApiStatus func_8024047C_8525EC(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->exitTangent = 0.0f;
    return ApiStatus_BLOCK;
}

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802425E0_854750);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242634_8547A4);

extern s32 mac_05_D_80252A00[];

ApiStatus func_8024266C_8547DC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            mac_05_D_80252A00[i] = ptr[i];
        }
        mac_05_D_80252A00[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            mac_05_D_80252A00[i] = i + 16;
            mac_05_D_80252A00[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 mac_05_D_80252BC8[];

ApiStatus func_80242708_854878(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            mac_05_D_80252BC8[i] = ptr[i];
        }
        mac_05_D_80252BC8[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            mac_05_D_80252BC8[i] = i + 128;
            mac_05_D_80252BC8[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

// float stuff
#ifdef NON_MATCHING
ApiStatus func_80242A90_854C00(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s1 = evt_get_variable(script, *args++);
    s32 temp_s3 = *args++;
    s32 temp_s4 = *args++;
    s32 temp_s5 = *args++;
    Npc* npc = get_npc_safe(0);
    f32 temp_f20;
    f32 var_f20;
    f32 var_f22;
    f32 var_f24;
    f32 var_f26;

    switch (temp_s1) {
        case 0:
            var_f26 = 55.0f;
            break;
        case 1:
            var_f26 = 85.0f;
            break;
        case 2:
            var_f26 = 25.0f;
            break;
        case 3:
            var_f24 = -295.0f;
            var_f22 = -10.0f;
            var_f20 = 400.0f;
            break;
        case 4:
            var_f24 = -285.0f;
            var_f22 = -10.0f;
            var_f20 = 380.0f;
            break;
        default:
            var_f24 = -295.0f;
            var_f22 = -10.0f;
            var_f20 = 420.0f;
            break;
    }
    if (temp_s1 < 3) {
        temp_f20 = -npc->yaw;
        var_f24 = npc->pos.x + 30.0f + (sin_deg(temp_f20) * var_f26);
        var_f22 = npc->pos.y + 50.0f;
        var_f20 = npc->pos.z + (cos_deg(temp_f20) * var_f26);
    }
    evt_set_float_variable(script, temp_s3, var_f24);
    evt_set_float_variable(script, temp_s4, var_f22);
    evt_set_float_variable(script, temp_s5, var_f20);
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242A90_854C00);
#endif

static char* N(exit_str_2) = "mac_06";

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242C78_854DE8);

ApiStatus func_80242E84_854FF4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_safe(0);

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        if (script->functionTemp[0] == 0) {
            script->functionTemp[2] = 0;
            script->functionTemp[1] = 90;
        } else {
            script->functionTemp[2] = 10;
            script->functionTemp[1] = 290;
            npc->pos.x = 650.0f;
            npc->pos.y = -30.0f;
            npc->pos.z = 372.0f;
        }
    }

    switch (script->functionTemp[2]) {
        case 0:
            npc->currentAnim = 0xB60001;
            npc->yaw -= 1.0f;
            npc->pos.x += 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[2] = 1;
                script->functionTemp[1] = 200;
            }
            break;
        case 1:
            if (evt_get_variable(NULL, MapFlag(1)) != 0) {
                npc->pos.x += 3.0f;
                script->functionTemp[1]--;
                if (script->functionTemp[1] <= 0) {
                    return ApiStatus_DONE1;
                }
            }
            break;
        case 10:
            npc->yaw = 270.0f;
            npc->pos.x -= 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[2] = 11;
                script->functionTemp[1] = 90;
            }
            break;
        case 11:
            npc->yaw -= 1.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                return ApiStatus_DONE1;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

#include "world/common/todo/GetFloorCollider.inc.c"

ApiStatus func_802430B4_855224(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_safe(-4);
    s32 outVal = -1;

    if (gCollisionStatus.bombetteExploded >= 0) {
        f32 temp = 11.0f;
        f32 x = npc->pos.x;
        f32 y = npc->pos.y + temp;
        f32 z = npc->pos.z;

        temp = 12.0f;
        if (npc_raycast_down_around(npc->collisionChannel, &x, &y, &z, &temp, npc->yaw, npc->collisionRadius) &&
            temp <= 12.0f)
        {
            outVal = D_8010C978;
        }
    }
    evt_set_variable(script, *args++, outVal);
    return ApiStatus_DONE2;
}

ApiStatus func_802431B0_855320(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(4);
    f32 x = npc->pos.x + 20.0f;
    f32 y = npc->pos.y;
    f32 z = npc->pos.z - 15.0f;

    if (y < 0.0f) {
        fx_rising_bubble(0, x, y, z, 0.0f);
        sfx_adjust_env_sound_pos(SOUND_JR_TROOPA_SWIM, 0, x, y, z);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80243254_8553C4(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outVar0 = *args++;
    s32 outVar1 = *args++;
    Npc* npc = resolve_npc(script, npcID);
    f32 theta;
    f32 x;
    f32 z;

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    theta = clamp_angle(atan2(playerStatus->position.x, playerStatus->position.z, npc->pos.x, npc->pos.z));
    x = playerStatus->position.x + (sin_deg(theta) * 40.0f);
    z = playerStatus->position.z - (cos_deg(theta) * 40.0f);
    evt_set_variable(script, outVar0, x);
    evt_set_variable(script, outVar1, z);
    return ApiStatus_DONE2;
}

ApiStatus func_8024335C_8554CC(Evt* script, s32 isInitialCall) {
    if (func_8014AD40() == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_80243380_8554F0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = (s32) ((gPlayerData.frameCounter - gPlayerData.tradeEventStartTime) / 3600) < script->varTable[0];
    return ApiStatus_DONE2;
}

ApiStatus func_802433BC_85552C(Evt* script, s32 isInitialCall) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}
