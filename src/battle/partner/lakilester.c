#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "hud_element.h"

extern s32 (*D_8023AB80_70E890)[0];
extern f32 D_8023D1E0;
extern s32 D_8023D288;
extern s32 D_8023D28C;
extern s32 D_8023D290;
extern s32 D_8023D294;
extern s32 D_8023D298;
extern s32 D_8023D29C;
extern f32 D_8023D2A0;
extern f32 D_8023D2A4;
extern f32 D_8023D2A8;
extern f32 D_8023D2AC;
extern f32 D_8023D2B0;
extern f32 D_8023D2B4;
extern s32 D_8023D2B8[1];
extern s32 D_8023D2BC;
extern s32 D_8023D2C0;
extern s32 D_8023D2C4;
extern s32 D_8023D2C8;
extern s32 D_8023D2D0[];
extern s32 D_8023D330;
extern s32 D_8023D334;

extern HudScript HES_AimReticle;
extern HudScript HES_AimTarget;
extern HudScript HES_StickNeutral;
extern HudScript HES_StickTapRight;

ApiStatus func_80238000_70BD10(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        D_8023D2C8 = 0;
    }

    if (D_8023D2C8 == 0) {
        btl_set_popup_duration(99);
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_8023803C_70BD4C(Evt* script, s32 isInitialCall);
// a few issues
#ifdef NON_MATCHING
ApiStatus func_8023803C_70BD4C(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 screenX, screenY, screenZ;
    Actor* partner = battleStatus->partnerActor;
    Actor* target;
    ActorPart* part;
    ActorState* playerState;
    ActorState* partnerState;
    f32 dpadX;
    s32 dpadY;
    s32 id;
    s32 i;

    f32 temp_f0_5;
    f32 theta;
    f32 sinTheta;
    f32 cosTheta;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f8;
    s32 (**var_s3)[0];
    s32 (*temp_a0)[0];
    s32 temp_a0_2;
    s32 temp_f10;
    s32 temp_v0_4;
    s32 temp_v1_2;
    s32* var_s0;

    partnerState = &partner->state;
    playerState = &battleStatus->playerActor->state;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            D_8023D288 = hud_element_create(HES_AimReticle);
            hud_element_set_render_depth(D_8023D288, 0xA);
            D_8023D28C = hud_element_create(HES_AimTarget);
            hud_element_set_render_depth(D_8023D28C, 0xA);
            var_s3 = &D_8023AB80_70E890;
            hud_element_create_transform_A(D_8023D28C);
            D_8023D2C0 = -48;
            D_8023D2C4 = 70;
            D_8023D2BC = id = hud_element_create(HES_StickNeutral);
            hud_element_set_render_pos(id, D_8023D2C0, D_8023D2C4);
            hud_element_set_render_depth(id, 0);
            for (i = 0; i < 1; i++) {
                temp_a0 = *var_s3;
                var_s3++;

                D_8023D2B8[i] = temp_v0_4 = hud_element_create(temp_a0);
                hud_element_set_render_depth(temp_v0_4, 0xA);
            }
            partnerState->currentPos.x = partner->currentPos.x + 33.0f;
            partnerState->currentPos.y = partner->currentPos.y + 34.0f;
            partnerState->currentPos.z = partner->currentPos.z + 15.0f;
            partnerState->unk_18.x = partner->currentPos.x + 33.0f;
            partnerState->unk_18.y = partner->currentPos.y + 34.0f;
            partnerState->unk_18.z = partner->currentPos.z + 15.0f;
            set_goal_pos_to_part(partnerState, partner->targetActorID, partner->targetPartIndex);
            target = get_actor(partner->targetActorID);
            part = get_actor_part(target, partner->targetPartIndex);
            partnerState->goalPos.x += part->unk_75;
            partnerState->goalPos.y += part->unk_76;
            partnerState->distance = dist2D(partnerState->currentPos.x,
                                            partnerState->currentPos.y,
                                            partnerState->goalPos.x,
                                            partnerState->goalPos.y);
            partnerState->speed = 0.0f;
            partnerState->unk_30.x = 0.0f;
            partnerState->unk_30.y = 0.0f;
            D_8023D290 = 0;
            D_8023D294 = 0;
            D_8023D298 = 30;
            D_8023D2A0 = 0.0f;
            D_8023D2A4 = 0.0f;
            D_8023D2A8 = 0.0f;
            D_8023D2AC = 0.0f;
            D_8023D29C = 0;
            D_8023D2B0 = 3.0f;
            D_8023D2B4 = -1.0f;
            partnerState->unk_24 = ((part->size.y + part->size.x) / 2) / 24.0;
            hud_element_set_scale(D_8023D28C, partnerState->unk_24 * target->scalingFactor);
            D_8023D2C8 = 1;
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (battleStatus->stickX != 0 || battleStatus->stickY != 0) {
                D_8023D298 = 0;
            }
            if (D_8023D298 != 0) {
                D_8023D298--;
            } else {
                D_8023D298 = 0x50;
                hud_element_set_script(D_8023D2BC, HES_StickTapRight);
                sfx_play_sound_at_position(0x312, 0, 0.0f, 0.0f, 0.0f);
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            dpadY = battleStatus->dpadY;
            if (dpadY > 0x50) {
                dpadY = 0x50;
            }
            dpadX = battleStatus->dpadX;
            if (dpadY < 35) {
                dpadY *= sin_rad(DEG_TO_RAD(dpadY * 2));
            }
            temp_f8 = D_8023D2A0;
            temp_f2 = temp_f8 + D_8023D2A4 + D_8023D2A8;
            D_8023D2A0 = dpadY;
            D_8023D2A8 = D_8023D2A4;
            temp_f10 = D_8023D2A0 - (temp_f2 / 3.0f);
            D_8023D2A4 = temp_f8;
            if (temp_f10 > 0) {
                D_8023D2AC = temp_f10;
                if (partner->state.speed != 0.0f) {
                    partner->state.speed += (D_8023D2AC / 8.5) / 3.0;
                } else {
                    partner->state.speed += (D_8023D2AC / 8.5) / 2.0;
                }
                D_8023D2B4 = dpadX;
            } else {
                D_8023D2AC = temp_f10;
            }
            if (!(dpadY < 31)) {
                D_8023D2B4 = dpadX;
            }
            if (partnerState->speed > 6.7) {
                partnerState->speed = 6.7f;
            }
            partnerState->speed = partnerState->speed - (f32) ((2.0 * (40 - dpadY)) / 40.0);
            if (partnerState->speed <= 0.0f) {
                partnerState->speed = 0.0f;
                D_8023D2AC = 0.0f;
            }
            if (D_8023D2B4 >= 0.0f) {
                theta = DEG_TO_RAD(D_8023D2B4);
                sinTheta = sin_rad(theta);
                cosTheta = cos_rad(theta);
                partnerState->currentPos.x += partnerState->speed * sinTheta;
                partnerState->currentPos.y += partnerState->speed * cosTheta;
            }
            if (partnerState->currentPos.x < -30.0f) {
                partnerState->currentPos.x = -30.0f;
            }
            if (partnerState->currentPos.x > 170.0f) {
                partnerState->currentPos.x = 170.0f;
            }
            if (partnerState->currentPos.y > 130.0f) {
                partnerState->currentPos.y = 130.0f;
            }
            if (partnerState->currentPos.y < 0.0f) {
                partnerState->currentPos.y = 0.0f;
            }
            if (battleStatus->currentButtonsPressed & 0x8000) {
                D_8023D298 = 0;
            }
            if (D_8023D298 == 60) {
                set_animation(0x100, 0, 0x100010);
            }
            if (D_8023D298 == 30) {
                set_animation(0x100, 0, 0x100011);
            }
            if (D_8023D298 != 0) {
                D_8023D298--;
                break;
            }
            script->varTable[14] = 0;
            script->varTable[15] = 0;
            script->varTable[7] = partnerState->currentPos.x;
            script->varTable[8] = partnerState->currentPos.y;
            script->varTable[9] = partnerState->currentPos.z;
            partnerState->distance = dist2D(partnerState->currentPos.x, partnerState->currentPos.y, partnerState->goalPos.x, partnerState->goalPos.y) / partnerState->unk_24;
            if (partnerState->distance <= 12.0) {
                script->varTable[15] = 1;
            }
            hud_element_free(D_8023D28C);
            hud_element_free(D_8023D288);
            hud_element_free(D_8023D2BC);
            for (i = 0; i < 1; i++) {
                id = D_8023D2B8[i];
                hud_element_free(id);
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(0x312);
            return ApiStatus_DONE2;
    }

    get_screen_coords(gCurrentCameraID,
                      partnerState->goalPos.x, partnerState->goalPos.y, partnerState->goalPos.z,
                      &screenX, &screenY, &screenZ);
    id = D_8023D28C;
    hud_element_set_render_pos(id, screenX, screenY);
    hud_element_set_transform_rotation(id, 0.0f, 0.0f, D_8023D290);
    D_8023D290 -= 10;
    D_8023D290 = clamp_angle(D_8023D290);
    get_screen_coords(gCurrentCameraID,
                      partnerState->currentPos.x, partnerState->currentPos.y, partnerState->currentPos.z,
                      &screenX, &screenY, &screenZ);
    hud_element_set_render_pos(D_8023D288, screenX, screenY);

    temp_v1_2 = script->functionTemp[0];
    if (temp_v1_2 < 3 && temp_v1_2 > 0) {
        D_8023D2C0 += 20;
        if (D_8023D2C0 > 50) {
            D_8023D2C0 = 50;
        }
        hud_element_set_render_pos(D_8023D2BC, D_8023D2C0, D_8023D2C4);
    }

    temp_a0_2 = script->functionTemp[0];
    if (temp_a0_2 < 3) {
        if (temp_a0_2 > 0) {
            playerState->currentPos.x = partnerState->currentPos.x;
            playerState->currentPos.y = partnerState->currentPos.y;
            playerState->currentPos.z = partnerState->currentPos.z;
            for (i = 0; i < 1; i++) {
                get_screen_coords(gCurrentCameraID, playerState->currentPos.x, playerState->currentPos.y, playerState->currentPos.z, &screenX, &screenY, &screenZ);
                id = D_8023D2B8[i];
                hud_element_set_render_pos(id, screenX, screenY);
            }
        }
    }

    btl_set_popup_duration(99);
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "battle/partner/lakilester", func_8023803C_70BD4C);
#endif

ApiStatus func_80238A6C_70C77C(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 xPos = partnerActor->currentPos.x + 5;
    f32 yPos = partnerActor->currentPos.y + partnerActor->size.y + 20;
    f32 zPos = partnerActor->currentPos.z;
    f32 var = rand_int(140) + 10;
    f32 var2 = rand_int(80) + 10;

    fx_throw_spiny(0, xPos, yPos, zPos, var, var2, 20, 1.5f, 30);

    return ApiStatus_DONE2;
}

ApiStatus func_80238B50_70C860(Evt* script, s32 isInitialCall) {
    s32 partnerLevel = gBattleStatus.partnerActor->actorBlueprint->level;
    s32 vt10 = script->varTable[10];
    s32 vt15 = 0;

    switch (partnerLevel) {
        case 0:
            if (vt10 < 100) {
                vt15 = 1;
            } else {
                vt15 = 2;
            }
            break;
        case 1:
            if (vt10 <= 70) {
                vt15 = 1;
            } else if (vt10 < 100) {
                vt15 = 2;
            } else {
                vt15 = 3;
            }
            break;
        case 2:
            if (vt10 <= 40) {
                vt15 = 1;
            } else if (vt10 <= 70) {
                vt15 = 2;
            } else if (vt10 < 100) {
                vt15 = 3;
            } else {
                vt15 = 4;
            }
            break;
    }

    if (vt10 >= 100) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }

    script->varTable[15] = vt15;
    return ApiStatus_DONE2;
}

ApiStatus func_80238C14_70C924(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = gBattleStatus.cloudNineEffect;

    if (effect != NULL) {
        remove_effect(effect);
        gBattleStatus.cloudNineEffect = NULL;
        gBattleStatus.cloudNineTurnsLeft = 0;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238C58_70C968(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor = battleStatus->playerActor;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            D_8023D1E0 = 0.1f;
            fx_ending_decals(0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z, 0.1f, &battleStatus->cloudNineEffect);
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (D_8023D1E0 >= 1.0) {
                return ApiStatus_DONE2;
            }
            battleStatus->cloudNineEffect->data.endingDecals->unk_10 += 0.2;
            D_8023D1E0 += 0.2;
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80238D48_70CA58(Evt* script, s32 isInitialCall) {
    if (gBattleStatus.cloudNineTurnsLeft < script->varTable[10]) {
        gBattleStatus.cloudNineTurnsLeft = script->varTable[10];
        gBattleStatus.cloudNineDodgeChance = 50;
        gBattleStatus.buffEffect->data.partnerBuff->unk_0C[FX_BUFF_DATA_CLOUD_NINE].turnsLeft = gBattleStatus.cloudNineTurnsLeft;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238D8C_70CA9C(Evt* script, s32 isInitialCall) {
    Actor* partner = gBattleStatus.partnerActor;
    s32 totalSpookChance;
    s32 spookableTargets;
    s32 targetIdx;
    SelectableTarget* target;
    Actor* actor;
    ActorPart* part;
    s32 hpCalc;
    s32 spookChance;
    s32 avgSpookChance;
    s32 i;

    D_8023D330 = 0;
    D_8023D334 = 0;

    for (i = 0; i < partner->targetListLength; i++) {
        D_8023D2D0[i] = 0;
    }

    totalSpookChance = 0;
    spookableTargets = 0;

    for (i = 0; i < partner->targetListLength; i++) {
        targetIdx = partner->targetIndexList[i];
        target = &partner->targetData[targetIdx];
        actor = get_actor(target->actorID);
        part = get_actor_part(actor, target->partID);
        hpCalc = 100 - ((actor->currentHP * 100) / actor->maxHP);
        spookChance = actor->actorBlueprint->spookChance;
        if (spookChance > 0) {
            spookChance += spookChance * hpCalc / 100;
            if (spookChance > 100) {
                spookChance = 100;
            }
            if (actor->debuff != 0) {
                spookChance = (spookChance * 150) / 100;
                if (spookChance > 150) {
                    spookChance = 150;
                }
            }
            if (actor->transparentStatus == STATUS_TRANSPARENT) {
                spookChance = 0;
            }
            if (part->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
                spookChance = 0;
            }
            spookableTargets++;
        }
        D_8023D2D0[targetIdx] = spookChance;
        totalSpookChance += spookChance;
    }

    if (spookableTargets != 0) {
        avgSpookChance = totalSpookChance / spookableTargets;
    } else {
        avgSpookChance = 0;
    }
    script->varTable[0] = avgSpookChance;

    for (i = 0; i < partner->targetListLength; i++) {
        targetIdx = partner->targetIndexList[i];
        target = &partner->targetData[targetIdx];
        actor = get_actor(target->actorID);
        part = get_actor_part(actor, target->partID);
        if (actor->transparentStatus == STATUS_TRANSPARENT || (part->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY)) {
            D_8023D2D0[targetIdx] = -1;
        } else if (D_8023D2D0[targetIdx] != 0) {
            D_8023D2D0[targetIdx] = avgSpookChance;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_8023906C_70CD7C(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 targetIdx = partner->targetIndexList[partner->selectedTargetIndex];
    s32* temp_s0 = &D_8023D2D0[targetIdx];
    SelectableTarget* target = &partner->targetData[targetIdx];

    script->varTable[0] = *temp_s0;

    if (*temp_s0 == -1) {
        return ApiStatus_DONE2;
    }

    if (*temp_s0 == 0) {
        return ApiStatus_DONE2;
    }

    get_actor(target->actorID);
    if (rand_int(99) < battleStatus->actionSuccess) {
        *temp_s0 = -1;
        script->varTable[0] = target->actorID;
    } else {
        *temp_s0 = 0;
        script->varTable[0] = ACTOR_PLAYER;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80239140_70CE50);

ApiStatus func_80239F84_70DC94(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor;
    ActorState* state;
    f64 temp_f20;

    if (isInitialCall) {
        script->functionTempPtr[1] = get_actor(script->varTable[10]);
        script->functionTemp[0] = 0;
    }

    actor = script->functionTempPtr[1];
    state = &actor->state;
    switch (script->functionTemp[0]) {
        case 0:
            actor->state.moveTime = 0;
            actor->state.currentPos.x = actor->currentPos.x;
            actor->state.currentPos.y = actor->currentPos.y;
            actor->state.currentPos.z = actor->currentPos.z;
            actor->state.speed = 5.5f;
            D_8023D330 += 1;
            battleStatus->currentAttackElement = 0;
            dispatch_event_actor(actor, 0x16);
            script->functionTemp[0] = 1;
            break;
        case 1:
            actor->state.currentPos.x += actor->state.speed;
            temp_f20 = actor->state.currentPos.y;
            actor->state.currentPos.y =
                temp_f20 + ((sin_rad(2.0f * sin_rad(DEG_TO_RAD(actor->state.moveTime)) * PI_S) * 1.4) + 0.5);
            actor->state.moveTime += 6;
            actor->state.moveTime = clamp_angle(actor->state.moveTime);
            actor->yaw += 33.0f;
            actor->yaw = clamp_angle(actor->yaw);
            if (actor->state.currentPos.x > 240.0f) {
                D_8023D330 -= 1;
                return ApiStatus_DONE2;
            }
            break;
    }
    actor->currentPos.x = state->currentPos.x;
    actor->currentPos.y = state->currentPos.y;
    actor->currentPos.z = state->currentPos.z;
    return ApiStatus_BLOCK;
}

ApiStatus func_8023A19C_70DEAC(Evt* script, s32 isInitialCall) {
    if (D_8023D330 == 0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_8023A1B0_70DEC0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = D_8023D334;
    return ApiStatus_DONE2;
}
