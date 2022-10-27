#include "common.h"
#include "effects.h"
#include "battle/battle.h"

extern EffectInstance* D_8023C070;

ApiStatus func_80238000_707CA0(Evt* script, s32 isInitialCall) {
    ActorPart* targetPart;
    Actor* partner = gBattleStatus.partnerActor;

    set_goal_pos_to_part(&partner->state, partner->targetActorID, partner->targetPartIndex);
    targetPart = get_actor_part(get_actor(partner->targetActorID), partner->targetPartIndex);

    partner->state.goalPos.x += targetPart->unk_75;
    partner->state.goalPos.y += targetPart->unk_76;
    partner->state.goalPos.z = partner->state.goalPos.z; // required to match

    partner->state.currentPos.x = partner->currentPos.x + 8.0f;
    partner->state.currentPos.y = partner->currentPos.y + 16.0f;
    partner->state.currentPos.z = partner->currentPos.z;

    partner->state.angle = atan2(
        partner->state.currentPos.x, partner->state.currentPos.y,
        partner->state.goalPos.x, partner->state.goalPos.y
    );

    partner->rotation.z = (partner->state.angle - 90.0f) * 0.25f;

    if (partner->rotation.z < 0.0f) {
        partner->rotation.z = 0.0f;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238114_707DB4(Evt* script, s32 isInitialCall) {
    Actor* partner = gBattleStatus.partnerActor;
    s32 vt0 = script->varTable[0];
    s32 vt15 = 0;

    script->varTable[0] = 0;

    switch (partner->actorBlueprint->level) {
        case 0:
            vt15 = 3;
            if (vt0 > 40) {
                vt15 = 4;
                if (vt0 > 75) {
                    vt15 = 5;
                    script->varTable[0] = 1;
                }
            }
            break;
        case 1:
            vt15 = 3;
            if (vt0 > 35) {
                vt15 = 4;
                if (vt0 > 60) {
                    vt15 = 5;
                    if (vt0 > 80) {
                        vt15 = 6;
                        script->varTable[0] = 1;
                    }
                }
            }
            break;
        case 2:
            vt15 = 3;
            if (vt0 > 20) {
                vt15 = 4;
                if (vt0 > 30) {
                    vt15 = 5;
                    if (vt0 > 60) {
                        vt15 = 6;
                        if (vt0 > 80) {
                            vt15 = 7;
                            script->varTable[0] = 1;
                        }
                    }
                }
            }
            break;
    }

    script->varTable[15] = vt15;
    return ApiStatus_DONE2;
}

ApiStatus func_802381EC_707E8C(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 xScale;
    f32 yScale;
    f32 zScale;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 6;
    }

    xScale = partnerActor->scale.x;
    yScale = partnerActor->scale.y;
    zScale = partnerActor->scale.z;
    partnerActor->scale.x = xScale + ((1.0 - xScale) / 3.0);
    partnerActor->scale.y = yScale + ((1.0 - yScale) / 3.0);
    partnerActor->scale.z = zScale + ((1.0 - zScale) / 3.0);

    if (script->functionTemp[1] != 0) {
        script->functionTemp[1]--;
        return ApiStatus_BLOCK;
    }

    partnerActor->scale.x = 1.0f;
    partnerActor->scale.y = 1.0f;
    partnerActor->scale.z = 1.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_802382A4_707F44(Evt* script, s32 isInitialCall) {
    f32 posX = script->varTable[0];
    f32 posY = script->varTable[1];

    add_vec2D_polar(&posX, &posY, 300, atan2(posX, posY, script->varTable[3], script->varTable[4]));

    script->varTable[3] = posX;
    script->varTable[4] = posY;

    return ApiStatus_DONE2;
}

ApiStatus func_80238328_707FC8(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var = script->varTable[0];

    if (var > 0) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = 0;
    script->varTable[10] = var;
    if (battleStatus->waterBlockTurnsLeft < var) {
        battleStatus->waterBlockTurnsLeft = var;
        battleStatus->waterBlockAmount = 1;
        battleStatus->buffEffect->data.partnerBuff->unk_0C[FX_BUFF_DATA_WATER_BLOCK].turnsLeft = battleStatus->waterBlockTurnsLeft;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238388_708028(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* playerActor = battleStatus->playerActor;

    D_8023C070 = fx_squirt(1, partnerActor->currentPos.x - 5.5, partnerActor->currentPos.y + 15.5, partnerActor->currentPos.z + 5, playerActor->currentPos.x, playerActor->currentPos.y, playerActor->currentPos.z, (rand_int(10) * 0.1) + 1, 30);

    return ApiStatus_DONE2;
}

ApiStatus func_80238480_708120(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    EffectInstance* effect = battleStatus->waterBlockEffect;

    if (effect != NULL) {
        remove_effect(effect);
    }

    battleStatus->waterBlockEffect = fx_water_block(0, posX, posY, posZ, 1.5f, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80238540_7081E0(Evt* script, s32 isInitialCall) {
    Actor* partner = gBattleStatus.partnerActor;
    ActorState* state = &partner->state;
    f32 x, y;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            state->currentPos.x = partner->currentPos.x;
            state->currentPos.y = partner->currentPos.y;
            state->currentPos.z = partner->currentPos.z;
            state->angle = 315.0f;
            state->bounceDivisor = 0.0f;
            state->moveTime = 90;
            state->speed = 32.0f;
            script->functionTemp[1] = 0;
            script->functionTemp[2] = 0;
            D_8023C070 = fx_water_fountain(1, state->currentPos.x, state->currentPos.y, state->currentPos.z, 1.0f, 0);
            D_8023C070->data.waterFountain->unk_38 = state->angle;
            D_8023C070->data.waterFountain->unk_3C = partner->scale.x;
            D_8023C070->data.waterFountain->unk_40 = partner->scale.x;
            script->functionTemp[0] = 1;
            break;
        case 1:
            add_vec2D_polar(&state->currentPos.x, &state->currentPos.y, state->speed, state->angle);
            if (state->currentPos.x < -160.0f) {
                if (script->functionTemp[1] != 0) {
                    script->functionTemp[0] = 2;
                    break;
                }
                if (state->angle >= 270.0f && state->angle < 360.0f) {
                    state->angle = 90.0f + (90.0f - clamp_angle(state->angle + 180.0f));
                    state->bounceDivisor = rand_int(4) - 2;
                }
                if (state->angle >= 180.0f && state->angle < 270.0f) {
                    state->angle = 90.0f - (clamp_angle(state->angle + 180.0f) - 90.0f);
                    state->bounceDivisor = rand_int(4) - 2;
                }
            }

            if (state->currentPos.x > 160.0f) {
                if (script->functionTemp[1] != 0) {
                    script->functionTemp[0] = 2;
                    break;
                }

                do {
                    if (state->angle >= 0.0f && state->angle < 90.0f) {
                        state->angle = 270.0f + (270.0f - clamp_angle(state->angle + 180.0f));
                        state->bounceDivisor = rand_int(4) - 2;
                    } else if (state->angle >= 90.0f && state->angle < 180.0f) {
                        state->angle = 270.0f - (clamp_angle(state->angle + 180.0f) - 270.0f);
                        state->bounceDivisor = rand_int(4) - 2;
                    }
                } while (0);

                if (script->functionTemp[2] != 0) {
                    sfx_play_sound_at_position(SOUND_29B, 0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_29C, 0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
                }
                script->functionTemp[2] = 1 - script->functionTemp[2];
            }

            if (state->currentPos.y < 0.0f) {
                if (script->functionTemp[1] != 0) {
                    script->functionTemp[0] = 2;
                    break;
                }

                do {
                    if (state->angle >= 270.0f && state->angle < 360.0f) {
                        state->angle = 180.0f + (180.0f - clamp_angle(state->angle + 180.0f));
                        state->bounceDivisor = rand_int(4) - 2;
                    } else if (state->angle >= 0.0f && state->angle < 90.0f) {
                        state->angle = 180.0f - (clamp_angle(state->angle + 180.0f) - 180.0f);
                        state->bounceDivisor = rand_int(4) - 2;
                    }
                } while (0); // TODO macro?

                if (script->functionTemp[2] != 0) {
                    sfx_play_sound_at_position(SOUND_29B, 0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_29C, 0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
                }
                script->functionTemp[2] = 1 - script->functionTemp[2];
            }

            if (state->currentPos.y > 130.0f) {
                if (script->functionTemp[1] != 0) {
                    script->functionTemp[0] = 2;
                    break;
                }

                do {
                    if (state->angle >= 90.0f && state->angle < 180.0f) {
                        state->angle = 360.0f + (360.0f - clamp_angle(state->angle + 180.0f));
                        state->bounceDivisor = rand_int(4) - 2;
                    } else if (state->angle >= 180.0f && state->angle < 270.0f) {
                        state->angle = 360.0f - (clamp_angle(state->angle + 180.0f) - 360.0f);
                        state->bounceDivisor = rand_int(4) - 2;
                    }
                } while (0); // TODO macro?

                if (script->functionTemp[2] != 0) {
                    sfx_play_sound_at_position(SOUND_29B, 0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_29C, 0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
                }
                script->functionTemp[2] = 1 - script->functionTemp[2];
            }

            state->angle = clamp_angle(state->angle + (state->bounceDivisor * 0.5));
            partner->rotation.z = clamp_angle(state->angle - 315.0f);
            partner->scale.z = partner->scale.y = partner->scale.x = partner->scale.x - 0.06;
            if (partner->scale.x < 1.0) {
                partner->scale.x = 1.0f;
                partner->scale.y = 1.0f;
                partner->scale.z = 1.0f;
            }
            x = 0.0f;
            y = 0.0f;
            add_vec2D_polar(&x, &y, partner->scale.x * -15.0f, state->angle);
            D_8023C070->data.waterFountain->pos.x = state->currentPos.x + x;
            D_8023C070->data.waterFountain->pos.y = state->currentPos.y + y;
            D_8023C070->data.waterFountain->pos.z = state->currentPos.z + 5.0f;
            D_8023C070->data.waterFountain->unk_38 = state->angle;
            D_8023C070->data.waterFountain->unk_3C = partner->scale.x;
            D_8023C070->data.waterFountain->unk_40 = partner->scale.x;
            if (state->moveTime == 0x46) {
                sfx_play_sound_at_position(SOUND_29D, 0, 0.0f, 0.0f, 0.0f);
                fx_underwater(0, -50.0f, 20.0f, 0.0f, 1.0f, 120);
            }

            if (state->moveTime != 0) {
                state->moveTime--;
            } else {
                script->functionTemp[1] = 1;
            }
            break;
    }

    switch (script->functionTemp[0]) {
        case 2:
            state->moveTime = 5;
            script->functionTemp[0] = 3;
        case 3:
            add_vec2D_polar(&state->currentPos.x, &state->currentPos.y, state->speed, state->angle);
            D_8023C070->data.waterFountain->pos.x = state->currentPos.x;
            D_8023C070->data.waterFountain->pos.y = state->currentPos.y;
            D_8023C070->data.waterFountain->pos.z = state->currentPos.z;
            D_8023C070->data.waterFountain->unk_38 = state->angle;
            D_8023C070->data.waterFountain->unk_3C = partner->scale.x;
            D_8023C070->data.waterFountain->unk_40 = partner->scale.x;
            if (state->moveTime == 0) {
                partner->rotation.z = 0.0f;
                D_8023C070->flags |= ACTOR_FLAG_10;
                return ApiStatus_DONE2;
            }
            state->moveTime--;
        default:
            partner->currentPos.x = state->currentPos.x;
            partner->currentPos.y = state->currentPos.y;
            partner->currentPos.z = state->currentPos.z;
            fx_water_splash(3, partner->currentPos.x, partner->currentPos.y, partner->currentPos.z, 1.0f, 10);
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80238E30_708AD0(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 var = (((f64) script->varTable[0] * 3) / 100) + 1;
    f32 xScale = partnerActor->scale.x;
    f32 yScale = partnerActor->scale.y;
    f32 zScale = partnerActor->scale.z;

    partnerActor->scale.x = xScale + ((var - xScale) / 3);
    partnerActor->scale.y = yScale + ((var - yScale) / 3);
    partnerActor->scale.z = zScale + ((var - zScale) / 3);

    return ApiStatus_DONE2;
}
