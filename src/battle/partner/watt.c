#include "common.h"
#include "effects.h"

#define NAMESPACE battle_partner_watt

extern EffectInstance* D_80239A0C_7054FC;
extern s32 D_8023B948_707438[];

extern EffectInstance* D_8023C1B0;
extern EffectInstance* D_8023C1B4;
extern s32 D_8023C1B8;
extern s32 D_8023C1BC;
extern s32 D_8023C1C0;
extern s32 D_8023C1C4;
extern s32 D_8023C1C8;
extern EffectInstance* D_8023C1CC;
extern EffectInstance* D_8023C1D0;

ApiStatus func_80238000_703AF0(Evt* script, s32 isInitialCall) {
    Actor* partner = gBattleStatus.partnerActor;
    f32 x, y, z;

    if (isInitialCall) {
        D_8023C1BC = 1;
        D_8023C1C0 = 0;
        D_8023C1C4 = 1;
        D_8023C1C8 = 0;
        D_8023C1CC = fx_static_status(0, partner->currentPos.x, partner->currentPos.y, partner->currentPos.z, 1.0f, 5, 0);
        D_8023C1D0 = fx_static_status(1, partner->currentPos.x, -1000.0f, partner->currentPos.z, 1.0f, 5, 0);
        D_8023C1B8 = 1;
    }

    if (D_8023C1B8 == 0) {
        return ApiStatus_DONE2;
    }

    if (D_8023C1BC != 0) {
        D_8023C1C0 += 15;
        D_8023C1C0 = clamp_angle(D_8023C1C0);
    }

    partner->unk_19A = sin_rad(DEG_TO_RAD(D_8023C1C0)) * 3.0f;
    x = partner->currentPos.x + partner->headOffset.x;
    y = partner->currentPos.y + partner->headOffset.y + partner->unk_19A + 12.0f;
    z = partner->currentPos.z + partner->headOffset.z;
    if ((gBattleStatus.flags2 & (BS_FLAGS2_10 | BS_FLAGS2_4)) == BS_FLAGS2_4) {
        y = -1000.0f;
    }

    if (D_8023C1C4 != 0) {
        switch (D_8023C1C8) {
            case 0:
                if (D_8023C1CC == NULL) {
                    D_8023C1CC = fx_static_status(0, x, y, z, 1.0f, 5, 0);
                }
                if (D_8023C1D0 != NULL) {
                    D_8023C1D0->flags |= 0x10;
                    D_8023C1D0 = NULL;
                }
                D_8023C1CC->data.staticStatus->unk_04 = x;
                D_8023C1CC->data.staticStatus->unk_08 = y;
                D_8023C1CC->data.staticStatus->unk_0C = z;
                break;
            case 1:
                if (D_8023C1CC != NULL) {
                    D_8023C1CC->flags |= 0x10;
                    D_8023C1CC = NULL;
                }
                if (D_8023C1D0 == NULL) {
                    D_8023C1D0 = fx_static_status(1, x, y, z, 1.0f, 5, 0);
                }
                D_8023C1D0->data.staticStatus->unk_04 = x;
                D_8023C1D0->data.staticStatus->unk_08 = y;
                D_8023C1D0->data.staticStatus->unk_0C = z;
                break;
        }
    } else {
        if (D_8023C1CC != NULL) {
            D_8023C1CC->flags |= 0x10;
            D_8023C1CC = NULL;
        }
        if (D_8023C1D0 != NULL) {
            D_8023C1D0->flags |= 0x10;
            D_8023C1D0 = NULL;
        }
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238370_703E60(Evt* script, s32 isInitialCall) {
    D_8023C1B8 = 0;
    if (D_8023C1CC != NULL) {
        remove_effect(D_8023C1CC);
    }
    if (D_8023C1D0 != NULL) {
        remove_effect(D_8023C1D0);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802383C0_703EB0(Evt* script, s32 isInitialCall) {
    D_8023C1BC = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_802383D4_703EC4(Evt* script, s32 isInitialCall) {
    D_8023C1BC = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802383E4_703ED4(Evt* script, s32 isInitialCall) {
    D_8023C1C4 = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_802383F8_703EE8(Evt* script, s32 isInitialCall) {
    D_8023C1C4 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80238408_703EF8(Evt* script, s32 isInitialCall) {
    D_8023C1C8 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

ApiStatus func_802384B0_703FA0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    D_80239A0C_7054FC = fx_radial_shimmer(8, var1, var2, var3, 1.3f, 55);

    return ApiStatus_DONE2;
}

ApiStatus func_80238570_704060(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = D_80239A0C_7054FC;

    if (effect != NULL) {
        effect->flags |= 0x10;
    }
    D_80239A0C_7054FC = NULL;

    return ApiStatus_DONE2;
}

ApiStatus func_8023859C_70408C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    ThunderboltRingFXData* data;

    D_8023C1B4 = fx_thunderbolt_ring(0, var1, var2, var3, 1.0f, 10);
    data = D_8023C1B4->data.thunderboltRing;
    data->unk_30 = 3;

    return ApiStatus_DONE2;
}

ApiStatus func_80238668_704158(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* partner = gBattleStatus.partnerActor;
    f32 x = partner->currentPos.x + partner->headOffset.x;
    f32 y = partner->currentPos.y + partner->headOffset.y + partner->unk_19A + 12.0f;
    f32 z = partner->currentPos.z + partner->headOffset.z;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        fx_bulb_glow(0, x, y, z, 1.0f, &D_8023C1B0);
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        D_8023C1B0->data.bulbGlow->unk_14 = 5;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238784_704274(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor = get_actor(partnerActor->targetActorID);
    ActorPart* targetActorPart = get_actor_part(targetActor, partnerActor->targetPartIndex);
    s32 statusChance = lookup_status_chance(targetActor->statusTable, 5);

    if (targetActor->transparentStatus == STATUS_TRANSPARENT) {
        statusChance = 0;
    }
    if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        statusChance = 0;
    }

    script->varTable[0] = statusChance;

    return ApiStatus_DONE2;
}

// float stuff
#ifdef NON_MATCHING
ApiStatus func_80238810_704300(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* partner = gBattleStatus.partnerActor;
    Actor* player = gBattleStatus.playerActor;
    ActorState* partnerState = &partner->state;
    f32 x;
    f32 theta;
    f32 sinTheta;
    f32 cosTheta;
    f32 distance;
    f32 new_var;
    f32 angle;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            script->functionTemp[2] = evt_get_variable(script, *args++);
            partner->state.distance = dist2D(player->currentPos.x, player->currentPos.y, partner->currentPos.x, partner->currentPos.y);
            partner->state.goalPos.x = player->currentPos.x;
            partner->state.goalPos.y = player->currentPos.y + 36.0f;
            partner->state.goalPos.z = player->currentPos.z;
            partner->state.moveTime = 90;
            partner->state.currentPos.x = partner->currentPos.x;
            partner->state.currentPos.y = partner->currentPos.y;
            partner->state.currentPos.z = partner->currentPos.z;
            partner->state.angle = 90.0f;
            partner->state.velocity = 5.0f;
            partner->state.acceleration = 0.5f;
            script->functionTemp[1] = 10;
            script->functionTemp[0] = 1;
            break;
        case 1:
            theta = DEG_TO_RAD(partner->state.angle);
            sinTheta = sin_rad(theta);
            cosTheta = cos_rad(theta);
            distance = partner->state.distance;
            partner->state.velocity += partner->state.acceleration;
            angle = partner->state.angle + partner->state.velocity;
            partner->state.angle = angle;
            partner->state.currentPos.x = partner->state.goalPos.x + (distance * sinTheta);
            partner->state.currentPos.y = partner->state.goalPos.y + (-distance * cosTheta);
            partner->state.angle = clamp_angle(angle);
            partner->state.moveTime--;
            if (partner->state.moveTime == 0) {
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            theta = DEG_TO_RAD(partner->state.angle);
            sinTheta = sin_rad(theta);
            cosTheta = cos_rad(theta);
            distance = partner->state.distance;
            angle = partner->state.angle + partner->state.velocity;
            partner->state.angle = angle;
            partner->state.currentPos.x = partner->state.goalPos.x + (distance * sinTheta);
            partner->state.currentPos.y = partner->state.goalPos.y + (-distance * cosTheta);
            partner->state.angle = clamp_angle(angle);
            if (partner->state.angle < 45.0f) {
                script->functionTemp[0] = 3;
                break;
            }
        case 3:
            player->yaw = 0.0f;
            partner->yaw = 0.0f;
            return ApiStatus_DONE2;
    }

    if (partnerState->angle > 180.0f) {
        partner->yaw = 0.0f;
    } else {
        partner->yaw = 180.0f;
    }

    partner->currentPos.x = partnerState->currentPos.x;
    partner->currentPos.y = partnerState->currentPos.y;
    partner->currentPos.z = partnerState->currentPos.z;
    if (script->functionTemp[2] == 0) {
        player->yaw += script->functionTemp[1];
        script->functionTemp[1]++;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "battle/partner/watt", func_80238810_704300);
#endif

ApiStatus func_80238B3C_70462C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    ThunderboltRingFXData* data;

    D_8023C1B4 = fx_thunderbolt_ring(0, var1, var2, var3, 1.0f, 60);
    data = D_8023C1B4->data.thunderboltRing;
    data->unk_30 = 2;

    return ApiStatus_DONE2;
}

ApiStatus func_80238C08_7046F8(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = script->varTable[0];

    if (var1 > 0) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = 0;
    script->varTable[10] = var1;
    if (battleStatus->turboChargeTurnsLeft < var1) {
        battleStatus->turboChargeTurnsLeft = var1;
        battleStatus->turboChargeAmount = 1;
        battleStatus->buffEffect->data.partnerBuff->unk_0C[FX_BUFF_DATA_TURBO_CHARGE].turnsLeft = battleStatus->turboChargeTurnsLeft;
    }

    if (gBattleStatus.flags2 & 2) {
        gBattleStatus.flags2 |= 0x100;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238C84_704774(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 t1;
    s32 t2;
    s32 t3;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            script->functionTemp[1] = evt_get_variable(script, *args++);
            t1 = evt_get_variable(script, *args++);
            t2 = evt_get_variable(script, *args++);
            t3 = evt_get_variable(script, *args++);
            script->functionTemp[2] = 20;
            script->functionTemp[3] = 10;
            D_8023C1B4 = fx_thunderbolt_ring(0, t1, t2, t3, 1.0f, script->functionTemp[2] + 10);
            D_8023C1B4->data.thunderboltRing->unk_30 = 3;
            script->functionTemp[1] = D_8023B948_707438[script->functionTemp[1] / 16];
            script->functionTemp[0] = 1;
            break;
        case 1:
            D_8023C1B4->data.thunderboltRing->unk_30 =
                ((script->functionTemp[3] * 3) + (script->functionTemp[1] * (10 - script->functionTemp[3]))) / 10;
            if (script->functionTemp[3] != 0) {
                script->functionTemp[3]--;
            }
            if (script->functionTemp[2] == 0) {
                D_8023C1B4->flags |= 0x10;
                return ApiStatus_DONE2;
            }
            script->functionTemp[2]--;
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus N(AverageTargetParalyzeChance)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor;
    ActorPart* targetActorPart;
    s32 targetActorBlueprintBaseStatusChance;
    s32 chanceTotal = 0;
    s32 nTargets = 0;
    s32 i;

    for (i = 0; i < partnerActor->targetListLength; i++) {
        targetActor = get_actor(partnerActor->targetData[i].actorID);
        targetActorPart = get_actor_part(targetActor, partnerActor->targetData[i].partID);
        targetActorBlueprintBaseStatusChance = lookup_status_chance(targetActor->statusTable, STATUS_PARALYZE);

        if (targetActor->transparentStatus == STATUS_TRANSPARENT) {
            targetActorBlueprintBaseStatusChance = 0;
        }

        if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
            targetActorBlueprintBaseStatusChance = 0;
        }

        if (targetActorBlueprintBaseStatusChance > 0) {
            chanceTotal += targetActorBlueprintBaseStatusChance;
            nTargets++;
        }
    }

    if (nTargets > 0) {
        script->varTable[0] = chanceTotal / nTargets;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
