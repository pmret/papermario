#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "battle/action_cmd/hammer.h"
#include "battle/action_cmd/squirt.h"
#include "battle/action_cmd/water_block.h"
#include "battle/action_cmd/tidal_wave.h"
#include "sprite/npc/BattleSushie.h"

#define NAMESPACE battle_partner_sushie

extern EvtScript N(handleEvent);
extern EvtScript N(idle);
extern EvtScript N(nextTurn);
extern EvtScript N(takeTurn);
extern EvtScript N(init);
extern EvtScript N(executeAction);
extern EvtScript N(celebrate);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(bellyFlop);
extern EvtScript N(squirt);
extern EvtScript N(waterBlock);
extern EvtScript N(tidalWave);

static EffectInstance* sEffect;

API_CALLABLE(N(SetSquirtAngle)) {
    ActorPart* targetPart;
    Actor* partner = gBattleStatus.partnerActor;

    set_goal_pos_to_part(&partner->state, partner->targetActorID, partner->targetPartIndex);
    targetPart = get_actor_part(get_actor(partner->targetActorID), partner->targetPartIndex);

    partner->state.goalPos.x += targetPart->projectileTargetOffset.x;
    partner->state.goalPos.y += targetPart->projectileTargetOffset.y;
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

API_CALLABLE(N(GetSquirtDamage)) {
    Actor* partner = gBattleStatus.partnerActor;
    s32 actionCmdResult = script->varTable[0];
    s32 damage = 0;

    script->varTable[0] = 0;

    switch (partner->actorBlueprint->level) {
        case 0:
            if (actionCmdResult <= 40) {
                damage = 3;
            } else if (actionCmdResult <= 75) {
                damage = 4;
            } else {
                damage = 5;
                script->varTable[0] = 1;
            }
            break;
        case 1:
            if (actionCmdResult <= 35) {
                damage = 3;
            } else if (actionCmdResult <= 60) {
                damage = 4;
            } else if (actionCmdResult <= 80) {
                damage = 5;
            } else {
                damage = 6;
                script->varTable[0] = 1;
            }
            break;
        case 2:
            if (actionCmdResult <= 20) {
                damage = 3;
            } else if (actionCmdResult <= 30) {
                damage = 4;
            } else if (actionCmdResult <= 60) {
                damage = 5;
            } else if (actionCmdResult <= 80) {
                damage = 6;
            } else {
                damage = 7;
                script->varTable[0] = 1;
            }
            break;
    }

    script->varTable[15] = damage;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(InflateSushie)) {
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

API_CALLABLE(N(GetSquirtTargetPos)) {
    f32 posX = script->varTable[0];
    f32 posY = script->varTable[1];

    add_vec2D_polar(&posX, &posY, 300.0f, atan2(posX, posY, script->varTable[3], script->varTable[4]));

    script->varTable[3] = posX;
    script->varTable[4] = posY;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(ApplyWaterBlock)) {
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

API_CALLABLE(N(PlaySquirtFX)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* playerActor = battleStatus->playerActor;

    sEffect = fx_squirt(1, partnerActor->currentPos.x - 5.5, partnerActor->currentPos.y + 15.5, partnerActor->currentPos.z + 5, playerActor->currentPos.x, playerActor->currentPos.y, playerActor->currentPos.z, (rand_int(10) * 0.1) + 1, 30);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PlayWaterBlockFX)) {
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

API_CALLABLE(N(ProcessTidalWave)) {
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
            sEffect = fx_water_fountain(1, state->currentPos.x, state->currentPos.y, state->currentPos.z, 1.0f, 0);
            sEffect->data.waterFountain->unk_38 = state->angle;
            sEffect->data.waterFountain->unk_3C = partner->scale.x;
            sEffect->data.waterFountain->unk_40 = partner->scale.x;
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
                    sfx_play_sound_at_position(SOUND_29B, SOUND_SPACE_MODE_0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_29C, SOUND_SPACE_MODE_0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
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
                    sfx_play_sound_at_position(SOUND_29B, SOUND_SPACE_MODE_0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_29C, SOUND_SPACE_MODE_0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
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
                    sfx_play_sound_at_position(SOUND_29B, SOUND_SPACE_MODE_0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_29C, SOUND_SPACE_MODE_0, state->currentPos.x, state->currentPos.y, state->currentPos.z);
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
            sEffect->data.waterFountain->pos.x = state->currentPos.x + x;
            sEffect->data.waterFountain->pos.y = state->currentPos.y + y;
            sEffect->data.waterFountain->pos.z = state->currentPos.z + 5.0f;
            sEffect->data.waterFountain->unk_38 = state->angle;
            sEffect->data.waterFountain->unk_3C = partner->scale.x;
            sEffect->data.waterFountain->unk_40 = partner->scale.x;
            if (state->moveTime == 0x46) {
                sfx_play_sound_at_position(SOUND_29D, SOUND_SPACE_MODE_0, 0.0f, 0.0f, 0.0f);
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
            sEffect->data.waterFountain->pos.x = state->currentPos.x;
            sEffect->data.waterFountain->pos.y = state->currentPos.y;
            sEffect->data.waterFountain->pos.z = state->currentPos.z;
            sEffect->data.waterFountain->unk_38 = state->angle;
            sEffect->data.waterFountain->unk_3C = partner->scale.x;
            sEffect->data.waterFountain->unk_40 = partner->scale.x;
            if (state->moveTime == 0) {
                partner->rotation.z = 0.0f;
                sEffect->flags |= EFFECT_INSTANCE_FLAG_10;
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

API_CALLABLE(N(SetScaleTidalWaveCharge)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 var = script->varTable[0] * 3.0 / 100.0 + 1.0;
    f32 xScale = partnerActor->scale.x;
    f32 yScale = partnerActor->scale.y;
    f32 zScale = partnerActor->scale.z;

    partnerActor->scale.x = xScale + ((var - xScale) / 3);
    partnerActor->scale.y = yScale + ((var - yScale) / 3);
    partnerActor->scale.z = zScale + ((var - zScale) / 3);

    return ApiStatus_DONE2;
}

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_BattleSushie_Walk,
    STATUS_STONE, ANIM_BattleSushie_Still,
    STATUS_SLEEP, ANIM_BattleSushie_Pray,
    STATUS_POISON, ANIM_BattleSushie_Still,
    STATUS_STOP, ANIM_BattleSushie_Still,
    STATUS_DAZE, ANIM_BattleSushie_Injured,
    STATUS_TURN_DONE, ANIM_BattleSushie_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 100,
    STATUS_POISON, 100,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 100,
    STATUS_STATIC, 100,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = 0,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 12, 17 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SUSHIE,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 37, 26 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Hurt)
            EVT_SET_CONST(LVar2, ANIM_BattleSushie_Hurt)
            EVT_EXEC_WAIT(D_802977BC)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Hurt)
            EVT_EXEC_WAIT(DoPartnerBlock)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Hurt)
            EVT_SET(LVar2, 20)
            EVT_EXEC_WAIT(DoPartnerSpikeContact)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_BurnHurt)
            EVT_SET(LVar2, 20)
            EVT_SET_CONST(LVar3, ANIM_BattleSushie_BurnStill)
            EVT_EXEC_WAIT(DoPartnerBurnContact)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleSushie_BurnStill)
            EVT_EXEC_WAIT(DoPartnerBurn)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Hurt)
            EVT_SET(LVar2, 20)
            EVT_EXEC_WAIT(D_80295744)
        EVT_CASE_EQ(EVENT_33)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_RECOVER_FROM_KO)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Idle)
            EVT_SET_CONST(LVar2, ANIM_BattleSushie_Run)
            EVT_SET(LVar3, 0)
            EVT_EXEC_WAIT(DoPartnerRecover)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleSushie_Block)
            EVT_EXEC_WAIT(DoPartnerBlock)
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(N(executeAction))
        EVT_CASE_EQ(PHASE_CELEBRATE)
            EVT_EXEC_WAIT(N(celebrate))
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(N(runAway))
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(N(runAwayFail))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(celebrate) = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Celebrate)
    EVT_WAIT(36)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_BattleSushie_Run)
    EVT_EXEC_WAIT(DoPartnerRunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(executeAction) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BELLY_FLOP1)
            EVT_EXEC_WAIT(N(bellyFlop))
        EVT_CASE_EQ(MOVE_BELLY_FLOP2)
            EVT_EXEC_WAIT(N(bellyFlop))
        EVT_CASE_EQ(MOVE_BELLY_FLOP3)
            EVT_EXEC_WAIT(N(bellyFlop))
        EVT_CASE_EQ(MOVE_SQUIRT)
            EVT_EXEC_WAIT(N(squirt))
        EVT_CASE_EQ(MOVE_WATER_BLOCK)
            EVT_EXEC_WAIT(N(waterBlock))
        EVT_CASE_EQ(MOVE_TIDAL_WAVE)
            EVT_EXEC_WAIT(N(tidalWave))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome2) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Fall)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_WAIT(15)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Fall)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 15)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_WAIT(15)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(restoreFromSquirt2) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(restoreFromSquirt) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(runToTarget) = {
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(getJumpTime) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVarB, LVarC, LVarD)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVarC, LVarD, LVarE)
    EVT_IF_GT(LVarB, LVarC)
        EVT_SUB(LVarB, LVarC)
    EVT_ELSE
        EVT_SUB(LVarC, LVarB)
        EVT_SET(LVarB, LVarC)
    EVT_END_IF
    EVT_SUB(LVarB, 20)
    EVT_DIVF(LVarB, EVT_FLOAT(10.588))
    EVT_ADDF(LVarB, 15)
    EVT_SET(LVarA, LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(bellyFlop) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_EXEC_WAIT(N(runToTarget))
    EVT_EXEC_WAIT(N(getJumpTime))
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(action_command_hammer_start, 0, 57, 3)
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Tense1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_SET(LVar0, 30)
    EVT_LOOP(60)
        EVT_WAIT(1)
        EVT_SUB(LVar0, 1)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Tense2)
        EVT_END_IF
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Jump)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 12, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 20)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar2)
                EVT_CASE_EQ(MOVE_BELLY_FLOP1)
                    EVT_WAIT(13)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(1.1), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(1.1), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.2), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.2), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_CASE_EQ(MOVE_BELLY_FLOP2)
                    EVT_WAIT(13)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.15), EVT_FLOAT(1.15), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.2), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.35), EVT_FLOAT(1.35), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.4), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.55), EVT_FLOAT(1.55), EVT_FLOAT(1.0))
                EVT_CASE_EQ(MOVE_BELLY_FLOP3)
                    EVT_WAIT(13)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.2), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.5), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.6), EVT_FLOAT(1.6), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.8), EVT_FLOAT(1.8), EVT_FLOAT(1.0))
            EVT_END_SWITCH
        EVT_ELSE
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar2)
                EVT_CASE_EQ(167)
                    EVT_WAIT(13)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_CASE_EQ(168)
                    EVT_WAIT(13)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.05), EVT_FLOAT(1.05), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(1.1), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.15), EVT_FLOAT(1.15), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.2), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.0))
                EVT_CASE_EQ(169)
                    EVT_WAIT(13)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(1.1), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.2), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.4), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.5), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
            EVT_END_SWITCH
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_2034)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Jump)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Fall)
        EVT_END_THREAD
        EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.6))
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    EVT_ELSE
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Jump)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Fall)
        EVT_END_THREAD
        EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Land)
    EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BELLY_FLOP1)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 3)
        EVT_CASE_EQ(MOVE_BELLY_FLOP2)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
        EVT_CASE_EQ(MOVE_BELLY_FLOP3)
            EVT_SET(LVarE, 3)
            EVT_SET(LVarF, 5)
    EVT_END_SWITCH
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(LandJump, ACTOR_PARTNER)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, 15, 0, 0)
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, 10, 0, 0)
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
        EVT_WAIT(10)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarE, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
            EVT_CALL(MoveBattleCamOver, 8)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(squirt) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SQUIRT)
    EVT_CALL(action_command_squirt_init)
    EVT_CALL(GetActorLevel, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetupMashMeter, 3, 40, 75, 100, 0, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetupMashMeter, 4, 35, 60, 80, 100, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SetupMashMeter, 5, 20, 40, 60, 80, 100)
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(InitTargetIterator)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Jump)
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Fall)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(N(SetSquirtAngle))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Inhale)
    EVT_CALL(AddBattleCamZoom, -80)
    EVT_CALL(MoveBattleCamOver, 90 * DT)
    EVT_CALL(action_command_squirt_start, 0, 87 * DT, 3)
    EVT_LOOP(90 * DT)
        EVT_CALL(GetActionResult, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(GetActorScale, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SETF(LVar1, LVar0)
            EVT_SUBF(LVar1, EVT_FLOAT(1.0))
            EVT_DIVF(LVar1, 4)
            EVT_SUBF(LVar0, LVar1)
        EVT_ELSE
            EVT_SETF(LVar0, LVar0)
            EVT_DIVF(LVar0, 100)
            EVT_SETF(LVar1, EVT_FLOAT(1.0))
            EVT_ADDF(LVar0, LVar1)
        EVT_END_IF
        EVT_CALL(SetActorScale, ACTOR_SELF, LVar0, LVar0, EVT_FLOAT(1.0))
        EVT_SETF(LVarE, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_297)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_WATER | DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Squirt)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 10)
        EVT_ADD(LVar1, 11)
        EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
        EVT_CALL(N(GetSquirtTargetPos))
        EVT_PLAY_EFFECT(EFFECT_SQUIRT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, LVarE, 10, 0)
        EVT_WAIT(20)
        EVT_EXEC_WAIT(N(restoreFromSquirt))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Squirt)
    EVT_THREAD
        EVT_CALL(N(InflateSushie))
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_ADD(LVar1, 11)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    EVT_PLAY_EFFECT(EFFECT_SQUIRT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, LVarE, 10, 0)
    EVT_WAIT(10)
    EVT_CALL(GetActionResult, LVar0)
    EVT_CALL(N(GetSquirtDamage))
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_WATER | DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_200, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_110)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_WATER | DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_200, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_110)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(restoreFromSquirt))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_EXEC_WAIT(N(restoreFromSquirt2))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(waterBlock) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -95, 26, 10)
    EVT_CALL(SetBattleCamOffsetZ, 11)
    EVT_CALL(SetBattleCamZoom, 238)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Inhale)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WATER_BLOCK)
    EVT_CALL(action_command_water_block_init, 0)
    EVT_CALL(SetActionHudPrepareTime, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(4)
        EVT_ADD(LVar0, 45)
        EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(4)
    EVT_CALL(action_command_water_block_start, 0, 100, 3)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_HoldWater)
    EVT_WAIT(110)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_SET(LVarA, LVar0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_SpitArc)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -95, 27, 10)
    EVT_CALL(SetBattleCamOffsetZ, 11)
    EVT_CALL(SetBattleCamZoom, 277)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_298)
        EVT_CALL(N(PlaySquirtFX))
        EVT_WAIT(65)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Celebrate)
    EVT_END_THREAD
    EVT_WAIT(45)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 83)
    EVT_PLAY_EFFECT(EFFECT_WATERFALL, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 50, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_2035)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 100)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 50, 0)
        EVT_WAIT(5)
        EVT_SUB(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 50, 0)
        EVT_WAIT(5)
        EVT_SUB(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 50, 0)
        EVT_WAIT(5)
        EVT_SUB(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 50, 0)
        EVT_WAIT(5)
        EVT_SUB(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 50, 0)
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(N(PlayWaterBlockFX), LVar0, LVar1, LVar2)
    EVT_WAIT(30)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_CALL(N(ApplyWaterBlock))
    EVT_SET(LVarA, LVar0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 15)
    EVT_ADD(LVar1, 35)
    EVT_ADD(LVarF, 6)
    EVT_PLAY_EFFECT(EFFECT_STAT_CHANGE, LVarF, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), 60, 0)
    EVT_WAIT(4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(PartnerYieldTurn)
    EVT_LABEL(10)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SET(LVar1, 180)
    EVT_LOOP(4)
        EVT_SUB(LVar1, 45)
        EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_IF_EQ(LVarA, 0)
    EVT_ELSE
        EVT_CALL(ShowVariableMessageBox, BTL_MSG_26, 60, LVarA)
    EVT_END_IF
    EVT_CALL(WaitForMessageBoxDone)
    EVT_RETURN
    EVT_END
};

EvtScript N(tidalWave) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_TIDAL_WAVE)
    EVT_CALL(action_command_tidal_wave_init)
    EVT_CALL(SetupMashMeter, 5, 20, 30, 60, 80, 100)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -65, 53, 10)
    EVT_CALL(SetBattleCamOffsetZ, 16)
    EVT_CALL(SetBattleCamZoom, 214)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.5))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, 30, 40, 0)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_HoldWater)
    EVT_CALL(action_command_tidal_wave_start, 0, 100, 3)
    EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 12, 0)
    EVT_THREAD
        EVT_WAIT(54)
        EVT_LOOP(8)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, -1, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(7)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 1, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, -1, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(8)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 1, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, -2, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_THREAD
    EVT_LOOP(100)
        EVT_CALL(GetActionResult, LVar0)
        EVT_CALL(N(SetScaleTidalWaveCharge))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_WAIT(10)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 1)
    EVT_CALL(N(ProcessTidalWave))
    EVT_CALL(SetActorPos, ACTOR_PARTNER, -220, 0, 0)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 0)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(GetActionSuccessCopy, LVar0)
    EVT_SET(LVarE, LVar0)
    EVT_SET(LVarF, LVar0)
    EVT_CALL(InitTargetIterator)
    EVT_LOOP(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_10)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SWITCH(LVarE)
            EVT_CASE_GE(6)
                EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_WATER | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 0, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
            EVT_CASE_DEFAULT
                EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_WATER | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 0, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_END_SWITCH
        EVT_WAIT(5)
        EVT_LABEL(10)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_EQ(LVar0, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, 0, 150, 0)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 40, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.7))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};
