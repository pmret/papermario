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

extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_ExecuteAction);
extern EvtScript N(EVS_Celebrate);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(bellyFlop);
extern EvtScript N(squirt);
extern EvtScript N(waterBlock);
extern EvtScript N(tidalWave);

static EffectInstance* sEffect;

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

API_CALLABLE(N(SetSquirtAngle)) {
    ActorPart* targetPart;
    Actor* partner = gBattleStatus.partnerActor;

    set_goal_pos_to_part(&partner->state, partner->targetActorID, partner->targetPartID);
    targetPart = get_actor_part(get_actor(partner->targetActorID), partner->targetPartID);

    partner->state.goalPos.x += targetPart->projectileTargetOffset.x;
    partner->state.goalPos.y += targetPart->projectileTargetOffset.y;
    partner->state.goalPos.z = partner->state.goalPos.z; // required to match

    partner->state.curPos.x = partner->curPos.x + 8.0f;
    partner->state.curPos.y = partner->curPos.y + 16.0f;
    partner->state.curPos.z = partner->curPos.z;

    partner->state.angle = atan2(
        partner->state.curPos.x, partner->state.curPos.y,
        partner->state.goalPos.x, partner->state.goalPos.y
    );

    partner->rot.z = (partner->state.angle - 90.0f) * 0.25f;

    if (partner->rot.z < 0.0f) {
        partner->rot.z = 0.0f;
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

    sEffect = fx_squirt(1, partnerActor->curPos.x - 5.5, partnerActor->curPos.y + 15.5, partnerActor->curPos.z + 5, playerActor->curPos.x, playerActor->curPos.y, playerActor->curPos.z, (rand_int(10) * 0.1) + 1, 30);

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

    battleStatus->waterBlockEffect = fx_water_block(FX_WATER_BLOCK_CREATE, posX, posY, posZ, 1.5f, 0);

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
            state->curPos.x = partner->curPos.x;
            state->curPos.y = partner->curPos.y;
            state->curPos.z = partner->curPos.z;
            state->angle = 315.0f;
            state->bounceDivisor = 0.0f;
            state->moveTime = 90;
            state->speed = 32.0f;
            script->functionTemp[1] = 0;
            script->functionTemp[2] = 0;
            sEffect = fx_water_fountain(1, state->curPos.x, state->curPos.y, state->curPos.z, 1.0f, 0);
            sEffect->data.waterFountain->unk_38 = state->angle;
            sEffect->data.waterFountain->unk_3C = partner->scale.x;
            sEffect->data.waterFountain->unk_40 = partner->scale.x;
            script->functionTemp[0] = 1;
            break;
        case 1:
            add_vec2D_polar(&state->curPos.x, &state->curPos.y, state->speed, state->angle);
            if (state->curPos.x < -160.0f) {
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

            if (state->curPos.x > 160.0f) {
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
                    sfx_play_sound_at_position(SOUND_TIDAL_WAVE_LEAP_A, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_TIDAL_WAVE_LEAP_B, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                }
                script->functionTemp[2] = 1 - script->functionTemp[2];
            }

            if (state->curPos.y < 0.0f) {
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
                    sfx_play_sound_at_position(SOUND_TIDAL_WAVE_LEAP_A, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_TIDAL_WAVE_LEAP_B, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                }
                script->functionTemp[2] = 1 - script->functionTemp[2];
            }

            if (state->curPos.y > 130.0f) {
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
                    sfx_play_sound_at_position(SOUND_TIDAL_WAVE_LEAP_A, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_TIDAL_WAVE_LEAP_B, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                }
                script->functionTemp[2] = 1 - script->functionTemp[2];
            }

            state->angle = clamp_angle(state->angle + (state->bounceDivisor * 0.5));
            partner->rot.z = clamp_angle(state->angle - 315.0f);
            partner->scale.z = partner->scale.y = partner->scale.x = partner->scale.x - 0.06;
            if (partner->scale.x < 1.0) {
                partner->scale.x = 1.0f;
                partner->scale.y = 1.0f;
                partner->scale.z = 1.0f;
            }
            x = 0.0f;
            y = 0.0f;
            add_vec2D_polar(&x, &y, partner->scale.x * -15.0f, state->angle);
            sEffect->data.waterFountain->pos.x = state->curPos.x + x;
            sEffect->data.waterFountain->pos.y = state->curPos.y + y;
            sEffect->data.waterFountain->pos.z = state->curPos.z + 5.0f;
            sEffect->data.waterFountain->unk_38 = state->angle;
            sEffect->data.waterFountain->unk_3C = partner->scale.x;
            sEffect->data.waterFountain->unk_40 = partner->scale.x;
            if (state->moveTime == 70) {
                sfx_play_sound_at_position(SOUND_TIDAL_WAVE_WATER, SOUND_SPACE_DEFAULT, 0.0f, 0.0f, 0.0f);
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
            add_vec2D_polar(&state->curPos.x, &state->curPos.y, state->speed, state->angle);
            sEffect->data.waterFountain->pos.x = state->curPos.x;
            sEffect->data.waterFountain->pos.y = state->curPos.y;
            sEffect->data.waterFountain->pos.z = state->curPos.z;
            sEffect->data.waterFountain->unk_38 = state->angle;
            sEffect->data.waterFountain->unk_3C = partner->scale.x;
            sEffect->data.waterFountain->unk_40 = partner->scale.x;
            if (state->moveTime == 0) {
                partner->rot.z = 0.0f;
                sEffect->flags |= FX_INSTANCE_FLAG_DISMISS;
                return ApiStatus_DONE2;
            }
            state->moveTime--;
        default:
            partner->curPos.x = state->curPos.x;
            partner->curPos.y = state->curPos.y;
            partner->curPos.z = state->curPos.z;
            fx_water_splash(3, partner->curPos.x, partner->curPos.y, partner->curPos.z, 1.0f, 10);
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

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleSushie_Walk,
    STATUS_KEY_STONE,     ANIM_BattleSushie_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleSushie_Pray,
    STATUS_KEY_POISON,    ANIM_BattleSushie_Still,
    STATUS_KEY_STOP,      ANIM_BattleSushie_Still,
    STATUS_KEY_DAZE,      ANIM_BattleSushie_Injured,
    STATUS_KEY_INACTIVE,  ANIM_BattleSushie_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = 0,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 12, 17 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SUSHIE,
    .level = ACTOR_LEVEL_SUSHIE,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
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
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(CloseActionCommandInfo)
    Call(GetLastEvent, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            SetConst(LVar2, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Partner_Hit)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Partner_Drop)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Partner_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_CONTACT)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            Set(LVar2, 20)
            ExecWait(EVS_Partner_SpikeContact)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_CONTACT)
            SetConst(LVar1, ANIM_BattleSushie_BurnHurt)
            Set(LVar2, 20)
            SetConst(LVar3, ANIM_BattleSushie_BurnStill)
            ExecWait(EVS_Partner_BurnContact)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar1, ANIM_BattleSushie_BurnHurt)
            SetConst(LVar2, ANIM_BattleSushie_BurnStill)
            ExecWait(EVS_Partner_BurnHit)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            Set(LVar2, 20)
            ExecWait(EVS_Partner_ShockHit)
        CaseEq(EVENT_33)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_RECOVER_FROM_KO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Idle)
            SetConst(LVar2, ANIM_BattleSushie_Run)
            Set(LVar3, 0)
            ExecWait(EVS_Partner_Recover)
        CaseOrEq(EVENT_18)
        CaseOrEq(EVENT_BLOCK)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Block)
            ExecWait(EVS_Partner_NoDamageHit)
            Wait(10)
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_EXECUTE_ACTION)
            ExecWait(N(EVS_ExecuteAction))
        CaseEq(PHASE_CELEBRATE)
            ExecWait(N(EVS_Celebrate))
        CaseEq(PHASE_RUN_AWAY_START)
            ExecWait(N(runAway))
        CaseEq(PHASE_RUN_AWAY_FAIL)
            ExecWait(N(runAwayFail))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Celebrate) = {
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Celebrate)
    Wait(36)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Return
    End
};

EvtScript N(runAway) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleSushie_Run)
    ExecWait(EVS_Partner_RunAway)
    Return
    End
};

EvtScript N(runAwayFail) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

EvtScript N(EVS_ExecuteAction) = {
    Call(ShowActionHud, TRUE)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar0)
        CaseEq(BTL_MENU_TYPE_STAR_POWERS)
            Call(LoadStarPowerScript)
            ExecWait(LVar0)
            Return
    EndSwitch
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BELLY_FLOP1)
            ExecWait(N(bellyFlop))
        CaseEq(MOVE_BELLY_FLOP2)
            ExecWait(N(bellyFlop))
        CaseEq(MOVE_BELLY_FLOP3)
            ExecWait(N(bellyFlop))
        CaseEq(MOVE_SQUIRT)
            ExecWait(N(squirt))
        CaseEq(MOVE_WATER_BLOCK)
            ExecWait(N(waterBlock))
        CaseEq(MOVE_TIDAL_WAVE)
            ExecWait(N(tidalWave))
    EndSwitch
    Return
    End
};

EvtScript N(returnHome2) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Fall)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    Sub(LVar0, 30)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 6, FALSE, TRUE, FALSE)
    Sub(LVar0, 10)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Wait(15)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Fall)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 15)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.4))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    Sub(LVar0, 5)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Wait(15)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Return
    End
};

EvtScript N(restoreFromSquirt2) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Return
    End
};

EvtScript N(restoreFromSquirt) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Return
    End
};

EvtScript N(runToTarget) = {
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Return
    End
};

EvtScript N(getJumpTime) = {
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(GetGoalPos, ACTOR_PARTNER, LVarB, LVarC, LVarD)
    Call(GetActorPos, ACTOR_PARTNER, LVarC, LVarD, LVarE)
    IfGt(LVarB, LVarC)
        Sub(LVarB, LVarC)
    Else
        Sub(LVarC, LVarB)
        Set(LVarB, LVarC)
    EndIf
    Sub(LVarB, 20)
    DivF(LVarB, Float(10.588))
    AddF(LVarB, 15)
    Set(LVarA, LVarB)
    Return
    End
};

EvtScript N(bellyFlop) = {
    Call(LoadActionCommand, ACTION_COMMAND_SMASH)
    Call(action_command_hammer_init)
    ExecWait(N(runToTarget))
    ExecWait(N(getJumpTime))
    Loop(30)
        Wait(1)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(action_command_hammer_start, 0, 57, 3)
    Call(SetActionQuality, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Tense1)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_59)
    Set(LVar0, 30)
    Loop(60)
        Wait(1)
        Sub(LVar0, 1)
        IfEq(LVar0, 0)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Tense2)
        EndIf
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Call(GetPartnerActionSuccess, LVar0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
        Call(MoveBattleCamOver, 20)
    EndThread
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Jump)
    Thread
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 12, 0)
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 36)
            Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotation, ACTOR_PARTNER, 0, 0, 20)
    EndThread
    Thread
        Call(GetPartnerActionSuccess, LVar0)
        IfGt(LVar0, 0)
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar2)
                CaseEq(MOVE_BELLY_FLOP1)
                    Wait(13)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(1.1), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(1.1), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.2), Float(1.2), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.2), Float(1.2), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(1.3), Float(1.0))
                CaseEq(MOVE_BELLY_FLOP2)
                    Wait(13)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.15), Float(1.15), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.2), Float(1.2), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.35), Float(1.35), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.4), Float(1.4), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.55), Float(1.55), Float(1.0))
                CaseEq(MOVE_BELLY_FLOP3)
                    Wait(13)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.2), Float(1.2), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(1.3), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.5), Float(1.5), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.6), Float(1.6), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.8), Float(1.8), Float(1.0))
            EndSwitch
        Else
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar2)
                CaseEq(167)
                    Wait(13)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
                CaseEq(168)
                    Wait(13)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.05), Float(1.05), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(1.1), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.15), Float(1.15), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.2), Float(1.2), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.25), Float(1.25), Float(1.0))
                CaseEq(169)
                    Wait(13)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(1.1), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.2), Float(1.2), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(1.3), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.4), Float(1.4), Float(1.0))
                    Wait(1)
                    Call(SetActorScale, ACTOR_PARTNER, Float(1.5), Float(1.5), Float(1.0))
            EndSwitch
        EndIf
    EndThread
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_SUSHIE_BELLY_FLOP)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(GetPartnerActionSuccess, LVar0)
    IfGt(LVar0, 0)
        Thread
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Jump)
            Wait(10)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Fall)
        EndThread
        Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.6))
        Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    Else
        Thread
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Jump)
            Wait(10)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Fall)
        EndThread
        Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
        Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    EndIf
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Land)
    Call(SetActorRotation, ACTOR_PARTNER, 0, 0, 0)
    Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BELLY_FLOP1)
            Set(LVarE, 1)
            Set(LVarF, 3)
        CaseEq(MOVE_BELLY_FLOP2)
            Set(LVarE, 2)
            Set(LVarF, 4)
        CaseEq(MOVE_BELLY_FLOP3)
            Set(LVarE, 3)
            Set(LVarF, 5)
    EndSwitch
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
        Call(LandJump, ACTOR_PARTNER)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(AddGoalPos, ACTOR_PARTNER, 15, 0, 0)
        Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
        Call(AddGoalPos, ACTOR_PARTNER, 10, 0, 0)
        Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
        Wait(10)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Return
    EndIf
    Thread
        Wait(3)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    EndThread
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
            Call(MoveBattleCamOver, 8)
            ExecWait(N(returnHome2))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(squirt) = {
    Call(LoadActionCommand, ACTION_COMMAND_SQUIRT)
    Call(action_command_squirt_init)
    Call(GetActorLevel, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SetupMashMeter, 3, 40, 75, 100, 0, 0)
        CaseEq(1)
            Call(SetupMashMeter, 4, 35, 60, 80, 100, 0)
        CaseEq(2)
            Call(SetupMashMeter, 5, 20, 40, 60, 80, 100)
    EndSwitch
    Call(UseBattleCamPreset, BTL_CAM_PRESET_13)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 40)
    Call(InitTargetIterator)
    Thread
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Jump)
        Wait(5)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Fall)
    EndThread
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Call(N(SetSquirtAngle))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Inhale)
    Call(AddBattleCamZoom, -80)
    Call(MoveBattleCamOver, 90 * DT)
    Call(action_command_squirt_start, 0, 87 * DT, 3)
    Loop(90 * DT)
        Call(GetActionQuality, LVar0)
        IfEq(LVar0, 0)
            Call(GetActorScale, ACTOR_SELF, LVar0, LVar1, LVar2)
            SetF(LVar1, LVar0)
            SubF(LVar1, Float(1.0))
            DivF(LVar1, 4)
            SubF(LVar0, LVar1)
        Else
            SetF(LVar0, LVar0)
            DivF(LVar0, 100)
            SetF(LVar1, Float(1.0))
            AddF(LVar0, LVar1)
        EndIf
        Call(SetActorScale, ACTOR_SELF, LVar0, LVar0, Float(1.0))
        SetF(LVarE, LVar0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_SUSHIE_SQUIRT)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(MoveBattleCamOver, 10)
    Call(PartnerTestEnemy, LVar0, DAMAGE_TYPE_WATER | DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Squirt)
        Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar0, 10)
        Add(LVar1, 11)
        Call(GetGoalPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
        Call(N(GetSquirtTargetPos))
        PlayEffect(EFFECT_SQUIRT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, LVarE, 10, 0)
        Wait(20)
        ExecWait(N(restoreFromSquirt))
        Return
    EndIf
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Squirt)
    Thread
        Call(N(InflateSushie))
    EndThread
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Add(LVar1, 11)
    Call(GetGoalPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    PlayEffect(EFFECT_SQUIRT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, LVarE, 10, 0)
    Wait(10)
    Call(GetActionQuality, LVar0)
    Call(N(GetSquirtDamage))
    Switch(LVar0)
        CaseGt(0)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_WATER | DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_200, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_HIT_RATTLE)
        CaseDefault
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_WATER | DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_200, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_HIT_RATTLE)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(restoreFromSquirt))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            ExecWait(N(restoreFromSquirt2))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(waterBlock) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(InitTargetIterator)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, -95, 26, 10)
    Call(SetBattleCamOffsetZ, 11)
    Call(SetBattleCamZoom, 238)
    Call(MoveBattleCamOver, 30)
    Wait(10)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Inhale)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Call(LoadActionCommand, ACTION_COMMAND_WATER_BLOCK)
    Call(action_command_water_block_init, 0)
    Call(SetActionHudPrepareTime, 0)
    Set(LVar0, 0)
    Loop(4)
        Add(LVar0, 45)
        Call(SetActorYaw, ACTOR_PARTNER, LVar0)
        Wait(1)
    EndLoop
    Wait(4)
    Call(action_command_water_block_start, 0, 100, 3)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_HoldWater)
    Wait(110)
    Call(GetPartnerActionSuccess, LVar0)
    IfEq(LVar0, 0)
        Set(LVarA, LVar0)
        Goto(10)
    EndIf
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_SpitArc)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, -95, 27, 10)
    Call(SetBattleCamOffsetZ, 11)
    Call(SetBattleCamZoom, 277)
    Call(MoveBattleCamOver, 10)
    Thread
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_SUSHIE_FOUNTAIN)
        Call(N(PlaySquirtFX))
        Wait(65)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Celebrate)
    EndThread
    Wait(45)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 83)
    PlayEffect(EFFECT_WATERFALL, 0, LVar0, LVar1, LVar2, Float(1.0), 50, 0)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_CREATE_WATER_BLOCK)
    Thread
        Wait(20)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 100)
        PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 50, 0)
        Wait(5)
        Sub(LVar1, 20)
        PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 50, 0)
        Wait(5)
        Sub(LVar1, 20)
        PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 50, 0)
        Wait(5)
        Sub(LVar1, 20)
        PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 50, 0)
        Wait(5)
        Sub(LVar1, 20)
        PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 50, 0)
    EndThread
    Wait(40)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(PlayWaterBlockFX), LVar0, LVar1, LVar2)
    Wait(30)
    Call(GetPartnerActionSuccess, LVar0)
    Call(N(ApplyWaterBlock))
    Set(LVarA, LVar0)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 15)
    Add(LVar1, 35)
    Add(LVarF, 6)
    PlayEffect(EFFECT_STAT_CHANGE, LVarF, LVar0, LVar1, LVar2, Float(1.5), 60, 0)
    Wait(4)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(PartnerYieldTurn)
    Label(10)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Set(LVar1, 180)
    Loop(4)
        Sub(LVar1, 45)
        Call(SetActorYaw, ACTOR_PARTNER, LVar1)
    EndLoop
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    IfEq(LVarA, 0)
    Else
        Call(ShowVariableMessageBox, BTL_MSG_WATER_BLOCK_BEGIN, 60, LVarA)
    EndIf
    Call(WaitForMessageBoxDone)
    Return
    End
};

EvtScript N(tidalWave) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(LoadActionCommand, ACTION_COMMAND_TIDAL_WAVE)
    Call(action_command_tidal_wave_init)
    Call(SetupMashMeter, 5, 20, 30, 60, 80, 100)
    Call(InitTargetIterator)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, -65, 53, 10)
    Call(SetBattleCamOffsetZ, 16)
    Call(SetBattleCamZoom, 214)
    Call(MoveBattleCamOver, 20)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Run)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.5))
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
    Call(AddGoalPos, ACTOR_PARTNER, 30, 40, 0)
    Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_HoldWater)
    Call(action_command_tidal_wave_start, 0, 100, 3)
    Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 12, 0)
    Thread
        Wait(54)
        Loop(8)
            Call(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_PARTNER, -1, 0, 0)
            Wait(1)
        EndLoop
        Loop(7)
            Call(SetActorDispOffset, ACTOR_PARTNER, 1, 0, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_PARTNER, -1, 0, 0)
            Wait(1)
        EndLoop
        Loop(8)
            Call(SetActorDispOffset, ACTOR_PARTNER, 1, 0, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_PARTNER, -2, 0, 0)
            Wait(1)
        EndLoop
        Call(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EndThread
    Loop(100)
        Call(GetActionQuality, LVar0)
        Call(N(SetScaleTidalWaveCharge))
        Wait(1)
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 5)
    Wait(10)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
    Call(N(ProcessTidalWave))
    Call(SetActorPos, ACTOR_PARTNER, -220, 0, 0)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    Wait(15)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(MoveBattleCamOver, 20)
    Call(GetActionSuccessCopy, LVar0)
    Set(LVarE, LVar0)
    Set(LVarF, LVar0)
    Call(InitTargetIterator)
    Loop(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(10)
        EndIf
        Switch(LVarE)
            CaseGe(6)
                Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_WATER | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
            CaseDefault
                Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_WATER | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
        EndSwitch
        Wait(5)
        Label(10)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfEq(LVar0, ITER_NO_MORE)
            BreakLoop
        EndIf
    EndLoop
    Call(PartnerYieldTurn)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(AddGoalPos, ACTOR_PARTNER, 0, 150, 0)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleSushie_Idle)
    Call(JumpToGoal, ACTOR_PARTNER, 40, FALSE, TRUE, FALSE)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.7))
    Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Return
    End
};
