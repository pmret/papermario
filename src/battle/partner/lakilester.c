#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleLakilester.h"
#include "battle/action_cmd/spiny_surge.h"
#include "battle/action_cmd/water_block.h"
#include "battle/action_cmd/hurricane.h"
#include "hud_element.h"

#define NAMESPACE battle_partner_lakilester

extern EvtScript N(handleEvent);
extern EvtScript N(idle);
extern EvtScript N(nextTurn);
extern EvtScript N(takeTurn);
extern EvtScript N(init);
extern EvtScript N(executeAction);
extern EvtScript N(celebrate);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(spinyFlip);
extern EvtScript N(spinySurge);
extern EvtScript N(cloudNine);
extern EvtScript N(hurricane);

typedef struct HurricaneState {
    /* 0x00 */ char unk_00[0x44];
    /* 0x44 */ s16 breathSizeIncrease;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ char unk_48[0xC];
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ char unk_56[0x4];
    /* 0x5A */ s16 startingTotalPower;
    /* 0x5C */ s8 state;
    /* 0x5D */ s8 unk_5D;
    /* 0x5E */ char unk_5E[0x12];
    /* 0x70 */ s16 intensity;
    /* 0x72 */ s16 totalPower;
    /* 0x74 */ char unk_74[0x10];
} HurricaneState;



static s32 sSavedHurricaneIntensity;
static s32 sBreathSizeIncrease;
static s32 sMaxPower;
static s32 hudAimReticle;
static s32 hudAimTarget;
static s32 sTargetMarkRotation;
static s32 D_8023D294;
static s32 sAimingTimer;
static s32 D_8023D29C;
static f32 D_8023D2A0;
static f32 D_8023D2A4;
static f32 D_8023D2A8;
static f32 D_8023D2AC;
static f32 D_8023D2B0;
static f32 sAimMoveAngle;
static s32 hudAim[1];
static s32 hudStick;
static s32 hudStickPosX;
static s32 hudStickPosY;
static s32 sSpinyFlipStarted;
static s32 D_8023D2CC;
static s32 sTargetStates[24];
static s32 sNumEnemiesBeingBlown;
static s32 sIsHurricaneActive;
static s32 D_8023D338;

extern HudScript HES_AimBlinkA;
extern HudScript HES_AimReticle;
extern HudScript HES_AimTarget;
extern HudScript HES_StickTapRight;

ApiStatus N(SpinyFlipUpdatePopup)(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        sSpinyFlipStarted = 0;
    }

    if (sSpinyFlipStarted == 0) {
        btl_set_popup_duration(99);
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}


s32 N(idleAnimations)[] = {
    STATUS_NORMAL,  ANIM_BattleLakilester_Walk,
    STATUS_DAZE, ANIM_BattleLakilester_Injured,
    STATUS_TURN_DONE, ANIM_BattleLakilester_Still,
    STATUS_END,
};

s32 N(idleAnimations_spiny)[] = {
    STATUS_NORMAL, ANIM_BattleLakilester_Spiny,
    STATUS_END,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
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
        .targetOffset = { 12, 30 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_spiny),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LAKILESTER,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .takeTurnScript = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 44, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusMessageOffset = { 13, 31 },
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
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Hurt)
            EVT_SET_CONST(LVar2,  ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(D_802976E8)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_SCRIPTED_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoPartnerBlock)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Hurt)
            EVT_SET_CONST(LVar2, 20)
            EVT_EXEC_WAIT(DoPartnerSpikeContact)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_BurnHurt)
            EVT_SET(LVar2, 20)
            EVT_SET_CONST(LVar3,  ANIM_BattleLakilester_BurnStill)
            EVT_EXEC_WAIT(DoPartnerBurnContact)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_BurnHurt)
            EVT_SET_CONST(LVar2,  ANIM_BattleLakilester_BurnStill)
            EVT_EXEC_WAIT(DoPartnerBurn)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Hurt)
            EVT_SET(LVar2, 20)
            EVT_EXEC_WAIT(D_80295744)
        EVT_CASE_EQ(EVENT_33)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_RECOVER_FROM_KO)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Walk)
            EVT_SET_CONST(LVar2,  ANIM_BattleLakilester_Run)
            EVT_SET(LVar3, 10)
            EVT_EXEC_WAIT(DoPartnerRecover)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Block)
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
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Celebrate)
    EVT_SET_CONST(LVar2,  ANIM_BattleLakilester_Walk)
    EVT_SET_CONST(LVar3,  ANIM_BattleLakilester_Walk)
    EVT_EXEC_WAIT(D_80294720)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1,  ANIM_BattleLakilester_Run)
    EVT_EXEC_WAIT(DoPartnerRunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Run)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Walk)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(executeAction) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_CALL(ShowActionHud, 1)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_SPINY_FLIP1)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
            EVT_EXEC_WAIT(N(spinyFlip))
        EVT_CASE_EQ(MOVE_SPINY_FLIP2)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
            EVT_EXEC_WAIT(N(spinyFlip))
        EVT_CASE_EQ(MOVE_SPINY_FLIP3)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
            EVT_EXEC_WAIT(N(spinyFlip))
        EVT_CASE_EQ(MOVE_SPINY_SURGE)
            EVT_EXEC_WAIT(N(spinySurge))
        EVT_CASE_EQ(MOVE_CLOUD_NINE)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
            EVT_EXEC_WAIT(N(cloudNine))
        EVT_CASE_EQ(MOVE_HURRICANE)
            EVT_EXEC_WAIT(N(hurricane))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome2) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 15, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Walk)
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 15, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Walk)
    EVT_RETURN
    EVT_END
};

HudScript* N(aimHudScripts)[] = { &HES_AimBlinkA };

ApiStatus N(SpinyFlipActionCommand)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 screenX, screenY, screenZ;
    Actor* partner = battleStatus->partnerActor;
    Actor* target;
    ActorPart* part;
    ActorState* playerState;
    ActorState* partnerState;
    f32 speed;
    f32 dpadAngle;
    s32 dpadAmplitude;
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
    s32 idAim;
    s32 temp_v1_2;
    s32* var_s0;

    partnerState = &partner->state;
    playerState = &battleStatus->playerActor->state;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            hudAimReticle = hud_element_create(&HES_AimReticle);
            hud_element_set_render_depth(hudAimReticle, 10);
            hudAimTarget = hud_element_create(&HES_AimTarget);
            hud_element_set_render_depth(hudAimTarget, 10);
            hud_element_create_transform_A(hudAimTarget);
            hudStickPosX = -48;
            hudStickPosY = 70;
            hudStick = id = hud_element_create(&HES_StickNeutral);
            hud_element_set_render_pos(id, hudStickPosX, hudStickPosY);
            hud_element_set_render_depth(id, 0);
            for (i = 0; i < ARRAY_COUNT(N(aimHudScripts)); i++) {
                hudAim[i] = idAim = hud_element_create(N(aimHudScripts)[i]);
                hud_element_set_render_depth(idAim, 10);
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
            partnerState->goalPos.z = partnerState->goalPos.z; // required to match
            partnerState->distance = dist2D(partnerState->currentPos.x,
                                            partnerState->currentPos.y,
                                            partnerState->goalPos.x,
                                            partnerState->goalPos.y);
            partnerState->speed = 0.0f;
            partnerState->unk_30.x = 0.0f;
            partnerState->unk_30.y = 0.0f;
            sTargetMarkRotation = 0;
            D_8023D294 = 0;
            sAimingTimer = 30;
            D_8023D2A0 = 0.0f;
            D_8023D2A4 = 0.0f;
            D_8023D2A8 = 0.0f;
            D_8023D2AC = 0.0f;
            D_8023D29C = 0;
            D_8023D2B0 = 3.0f;
            sAimMoveAngle = -1.0f;
            partnerState->unk_24 = ((part->size.y + part->size.x) / 2) / 24.0;
            hud_element_set_scale(hudAimTarget, partnerState->unk_24 * target->scalingFactor);
            sSpinyFlipStarted = 1;
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (battleStatus->stickX != 0 || battleStatus->stickY != 0) {
                sAimingTimer = 0;
            }
            if (sAimingTimer != 0) {
                sAimingTimer--;
            } else {
                sAimingTimer = 80;
                hud_element_set_script(hudStick, &HES_StickTapRight);
                sfx_play_sound_at_position(SOUND_312, SOUND_SPACE_MODE_0, 0.0f, 0.0f, 0.0f);
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            dpadAmplitude = battleStatus->dpadY;
            if (dpadAmplitude > 80) {
                dpadAmplitude = 80;
            }
            dpadAngle = battleStatus->dpadX;
            if (dpadAmplitude < 35) {
                f32 temp = dpadAmplitude;
                dpadAmplitude = temp * sin_rad(DEG_TO_RAD(dpadAmplitude * 2));
            }
            temp_f8 = D_8023D2A0;
            temp_f2 = temp_f8 + D_8023D2A4 + D_8023D2A8;
            D_8023D2A0 = dpadAmplitude;
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
                sAimMoveAngle = dpadAngle;
            } else {
                D_8023D2AC = temp_f10;
            }
            if (!(dpadAmplitude < 31)) {
                sAimMoveAngle = dpadAngle;
            }
            if (partnerState->speed > 6.7) {
                partnerState->speed = 6.7f;
            }
            partnerState->speed = partnerState->speed - (f32) ((2.0 * (40 - dpadAmplitude)) / 40.0);
            if (partnerState->speed <= 0.0f) {
                partnerState->speed = 0.0f;
                D_8023D2AC = 0.0f;
            }
            if (sAimMoveAngle >= 0.0f) {
                theta = DEG_TO_RAD(sAimMoveAngle);
                sinTheta = sin_rad(theta);
                cosTheta = cos_rad(theta);
                speed = partnerState->speed;
                partnerState->currentPos.x += speed * sinTheta;
                partnerState->currentPos.y += speed * cosTheta;
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
            if (battleStatus->currentButtonsPressed & BUTTON_A) {
                sAimingTimer = 0;
            }
            if (sAimingTimer == 60) {
                set_animation(ACTOR_PARTNER, 0,  ANIM_BattleLakilester_HoldSpiny);
            }
            if (sAimingTimer == 30) {
                set_animation(ACTOR_PARTNER, 0, ANIM_BattleLakilester_StrainHoldSpiny);
            }
            if (sAimingTimer != 0) {
                sAimingTimer--;
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
            hud_element_free(hudAimTarget);
            hud_element_free(hudAimReticle);
            hud_element_free(hudStick);
            for (i = 0; i < ARRAY_COUNT(N(aimHudScripts)); i++) {
                id = hudAim[i];
                hud_element_free(id);
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(SOUND_312);
            return ApiStatus_DONE2;
    }

    get_screen_coords(gCurrentCameraID,
                      partnerState->goalPos.x, partnerState->goalPos.y, partnerState->goalPos.z,
                      &screenX, &screenY, &screenZ);
    id = hudAimTarget;
    hud_element_set_render_pos(id, screenX, screenY);
    hud_element_set_transform_rotation(id, 0.0f, 0.0f, sTargetMarkRotation);
    sTargetMarkRotation -= 10;
    sTargetMarkRotation = clamp_angle(sTargetMarkRotation);
    get_screen_coords(gCurrentCameraID,
                      partnerState->currentPos.x, partnerState->currentPos.y, partnerState->currentPos.z,
                      &screenX, &screenY, &screenZ);
    hud_element_set_render_pos(hudAimReticle, screenX, screenY);

    switch (script->functionTemp[0]) {
        case 1:
        case 2:
            hudStickPosX += 20;
            if (hudStickPosX > 50) {
                hudStickPosX = 50;
            }
            hud_element_set_render_pos(hudStick, hudStickPosX, hudStickPosY);
            break;
    }

    switch (script->functionTemp[0]) {
        case 1:
        case 2:
            playerState->currentPos.x = partnerState->currentPos.x;
            playerState->currentPos.y = partnerState->currentPos.y;
            playerState->currentPos.z = partnerState->currentPos.z;
            for (i = 0; i < ARRAY_COUNT(N(aimHudScripts)); i++) {
                get_screen_coords(gCurrentCameraID, playerState->currentPos.x, playerState->currentPos.y, playerState->currentPos.z, &screenX, &screenY, &screenZ);
                id = hudAim[i];
                hud_element_set_render_pos(id, screenX, screenY);
            }
            break;
    }

    btl_set_popup_duration(99);
    return ApiStatus_BLOCK;
}

ApiStatus N(ThrowSpinyFX)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(GetSpinySurgeDamage)(Evt* script, s32 isInitialCall) {
    s32 partnerLevel = gBattleStatus.partnerActor->actorBlueprint->level;
    s32 actionCommandResult = script->varTable[10];
    s32 damage = 0;

    switch (partnerLevel) {
        case 0:
            if (actionCommandResult <= 99) {
                damage = 1;
            } else {
                damage = 2;
            }
            break;
        case 1:
            if (actionCommandResult <= 70) {
                damage = 1;
            } else if (actionCommandResult <= 99) {
                damage = 2;
            } else {
                damage = 3;
            }
            break;
        case 2:
            if (actionCommandResult <= 40) {
                damage = 1;
            } else if (actionCommandResult <= 70) {
                damage = 2;
            } else if (actionCommandResult <= 99) {
                damage = 3;
            } else {
                damage = 4;
            }
            break;
    }

    if (actionCommandResult >= 100) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }

    script->varTable[15] = damage;
    return ApiStatus_DONE2;
}

ApiStatus N(RemoveCloudNineFX)(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = gBattleStatus.cloudNineEffect;

    if (effect != NULL) {
        remove_effect(effect);
        gBattleStatus.cloudNineEffect = NULL;
        gBattleStatus.cloudNineTurnsLeft = 0;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(CloudNineFX)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor = battleStatus->playerActor;

    static f32 sCounter;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            sCounter = 0.1f;
            fx_ending_decals(0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z, 0.1f, &battleStatus->cloudNineEffect);
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (sCounter >= 1.0) {
                return ApiStatus_DONE2;
            }
            battleStatus->cloudNineEffect->data.endingDecals->scale += 0.2;
            sCounter += 0.2;
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus N(ApplyCloudNine)(Evt* script, s32 isInitialCall) {
    if (gBattleStatus.cloudNineTurnsLeft < script->varTable[10]) {
        gBattleStatus.cloudNineTurnsLeft = script->varTable[10];
        gBattleStatus.cloudNineDodgeChance = 50;
        gBattleStatus.buffEffect->data.partnerBuff->unk_0C[FX_BUFF_DATA_CLOUD_NINE].turnsLeft = gBattleStatus.cloudNineTurnsLeft;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(InitHurricane)(Evt* script, s32 isInitialCall) {
    Actor* partner = gBattleStatus.partnerActor;
    s32 totalChance;
    s32 affectedTargets;
    s32 targetIdx;
    SelectableTarget* target;
    Actor* actor;
    ActorPart* part;
    s32 hpMissingPercent;
    s32 hurricaneChance;
    s32 avgHurricaneChance;
    s32 i;

    sNumEnemiesBeingBlown = 0;
    sIsHurricaneActive = FALSE;

    for (i = 0; i < partner->targetListLength; i++) {
        sTargetStates[i] = 0;
    }

    totalChance = 0;
    affectedTargets = 0;

    for (i = 0; i < partner->targetListLength; i++) {
        targetIdx = partner->targetIndexList[i];
        target = &partner->targetData[targetIdx];
        actor = get_actor(target->actorID);
        part = get_actor_part(actor, target->partID);
        hpMissingPercent = 100 - ((actor->currentHP * 100) / actor->maxHP);
        hurricaneChance = actor->actorBlueprint->hurricaneChance;
        if (hurricaneChance > 0) {
            hurricaneChance += hurricaneChance * hpMissingPercent / 100;
            if (hurricaneChance > 100) {
                hurricaneChance = 100;
            }
            if (actor->debuff != 0) {
                hurricaneChance = hurricaneChance * 150 / 100;
                if (hurricaneChance > 150) {
                    hurricaneChance = 150;
                }
            }
            if (actor->transparentStatus == STATUS_TRANSPARENT) {
                hurricaneChance = 0;
            }
            if (part->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
                hurricaneChance = 0;
            }
            affectedTargets++;
        }
        sTargetStates[targetIdx] = hurricaneChance;
        totalChance += hurricaneChance;
    }

    if (affectedTargets != 0) {
        avgHurricaneChance = totalChance / affectedTargets;
    } else {
        avgHurricaneChance = 0;
    }
    script->varTable[0] = avgHurricaneChance;

    for (i = 0; i < partner->targetListLength; i++) {
        targetIdx = partner->targetIndexList[i];
        target = &partner->targetData[targetIdx];
        actor = get_actor(target->actorID);
        part = get_actor_part(actor, target->partID);
        if (actor->transparentStatus == STATUS_TRANSPARENT || (part->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY)) {
            sTargetStates[targetIdx] = -1;
        } else if (sTargetStates[targetIdx] != 0) {
            sTargetStates[targetIdx] = avgHurricaneChance;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus N(CanTargetBeBlown)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 targetIdx = partner->targetIndexList[partner->selectedTargetIndex];
    s32* hurricaneChance = &sTargetStates[targetIdx];
    SelectableTarget* target = &partner->targetData[targetIdx];

    script->varTable[0] = *hurricaneChance;

    if (*hurricaneChance == -1) {
        return ApiStatus_DONE2;
    }

    if (*hurricaneChance == 0) {
        return ApiStatus_DONE2;
    }

    get_actor(target->actorID);
    if (rand_int(99) < battleStatus->actionSuccess) {
        *hurricaneChance = -1;
        script->varTable[0] = target->actorID;
    } else {
        *hurricaneChance = 0;
        script->varTable[0] = ACTOR_PLAYER;
    }
    return ApiStatus_DONE2;
}

EvtScript N(spinyFlip) = {
    EVT_THREAD
        EVT_CALL(N(SpinyFlipUpdatePopup))
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Run)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Idle)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 47, 46, 12)
    EVT_CALL(SetBattleCamOffsetZ, 7)
    EVT_CALL(SetBattleCamZoom, 416)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 3)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 5)
    EVT_CALL(SetPartPos, ACTOR_PARTNER, 2, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2,  ANIM_BattleLakilester_Spiny)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_LiftSpiny)
    EVT_LOOP(4)
        EVT_ADD(LVar1, 6)
        EVT_CALL(SetPartPos, ACTOR_PARTNER, 2, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 8)
    EVT_ADD(LVar1, 40)
    EVT_ADD(LVar2, 5)
    EVT_CALL(PlayEffect, EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 80, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_PARTNER, 0, 1)
    EVT_THREAD
        EVT_LOOP(40)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 1, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_PARTNER, 2, 1, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, -1, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_PARTNER, 2, -1, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(GetActorVar, ACTOR_PARTNER, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
        EVT_CALL(SetPartDispOffset, ACTOR_PARTNER, 2, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(N(SpinyFlipActionCommand))
    EVT_CALL(SetActorVar, ACTOR_PARTNER, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_ThrowSpiny)
    EVT_WAIT(3)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, ATTACK_EVENT_FLAG_4 | ATTACK_EVENT_FLAG_10, 0, 2, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_SET(LVarF, -1)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_201B)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(-1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2,  ANIM_BattleLakilester_SpinySpin)
            EVT_CALL(SetPartJumpGravity, ACTOR_PARTNER, 2, EVT_FLOAT(1.5))
            EVT_SET(LVar0, LVar7)
            EVT_SET(LVar1, LVar8)
            EVT_SET(LVar2, LVar9)
            EVT_CALL(JumpPartTo, ACTOR_PARTNER, 2, LVar7, LVar8, LVar9, 20)
            EVT_CALL(LandJumpPart, 256, 2)
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2,  ANIM_BattleLakilester_SpinySpin)
            EVT_CALL(SetPartJumpGravity, ACTOR_PARTNER, 2, EVT_FLOAT(1.5))
            EVT_SET(LVar0, LVar7)
            EVT_SET(LVar1, LVar8)
            EVT_SET(LVar2, LVar9)
            EVT_CALL(JumpPartTo, ACTOR_PARTNER, 2, LVar7, LVar8, LVar9, 20)
            EVT_CALL(LandJumpPart, 256, 2)
        EVT_CASE_DEFAULT
            EVT_CALL(SetAnimation, ACTOR_SELF, 2,  ANIM_BattleLakilester_SpinySpin)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartJumpGravity, ACTOR_PARTNER, 2, EVT_FLOAT(1.5))
            EVT_CALL(JumpPartTo, ACTOR_PARTNER, 2, LVar0, LVar1, LVar2, 20)
    EVT_END_SWITCH
    EVT_THREAD
        EVT_ADD(LVar0, 50)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetPartJumpGravity, ACTOR_PARTNER, 2, EVT_FLOAT(1.5))
        EVT_CALL(JumpPartTo, ACTOR_PARTNER, 2, LVar0, LVar1, LVar2, 15)
        EVT_CALL(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_END_THREAD
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_SPINY_FLIP1)
            EVT_SET(LVarE, 3)
        EVT_CASE_EQ(MOVE_SPINY_FLIP2)
            EVT_SET(LVarE, 4)
        EVT_CASE_EQ(MOVE_SPINY_FLIP3)
            EVT_SET(LVarE, 5)
    EVT_END_SWITCH
    EVT_SWITCH(LVarF)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_SPINY_SURGE | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarE, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, HIT_RESULT_QUAKE_IMMUNE)
    EVT_END_SWITCH
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(1)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_END_SWITCH
    EVT_WAIT(15)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(spinySurge) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SPINY_SURGE)
    EVT_CALL(action_command_spiny_surge_init)
    EVT_CALL(GetActorLevel, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetupMashMeter, 2, 99, 100, 0, 0, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetupMashMeter, 3, 70, 99, 100, 0, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SetupMashMeter, 4, 40, 70, 99, 100, 0)
    EVT_END_SWITCH
    EVT_CALL(SetActionHudPrepareTime, 10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 45, 60, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Run)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, 60, 20, 0)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Idle)
    EVT_WAIT(10)
    EVT_CALL(GetActorLevel, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVarA, 60)
        EVT_CASE_EQ(1)
            EVT_SET(LVarA, 60)
        EVT_CASE_EQ(2)
            EVT_SET(LVarA, 60)
    EVT_END_SWITCH
    EVT_SET(LVarB, LVarA)
    EVT_ADD(LVarB, -3)
    EVT_CALL(action_command_spiny_surge_start, 0, LVarB, 3)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetActorVar, ACTOR_PARTNER, 0, 0)
    EVT_SET(LVar9, 0)
    EVT_SET(LocalFlag(2), 0)
    EVT_SET(LocalFlag(3), 0)
    EVT_LOOP(LVarA)
        EVT_CALL(GetActionResult, LVar0)
        EVT_IF_EQ(LVar9, 2)
            EVT_SET(LVar0, 3)
        EVT_END_IF
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(-1)
                EVT_SET(LVar9, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Idle)
            EVT_CASE_EQ(1)
                EVT_IF_EQ(LVar9, 1)
                    EVT_BREAK_SWITCH
                EVT_END_IF
                EVT_CALL(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, 0)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 3)
                EVT_ADD(LVar1, 34)
                EVT_ADD(LVar2, 5)
                EVT_CALL(SetPartPos, ACTOR_PARTNER, 2, LVar0, LVar1, LVar2)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_LiftSpiny)
                EVT_SET(LVar9, 1)
            EVT_CASE_EQ(2)
                EVT_IF_EQ(LVar9, 0)
                    EVT_BREAK_SWITCH
                EVT_END_IF
                EVT_IF_EQ(LocalFlag(2), 0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_201B)
                    EVT_SET(LocalFlag(2), 1)
                EVT_ELSE
                    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_201C)
                    EVT_SET(LocalFlag(2), 0)
                EVT_END_IF
                EVT_CALL(N(ThrowSpinyFX))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_ThrowSpinyAlt)
                EVT_CALL(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
                EVT_CHILD_THREAD
                    EVT_CALL(GetActorVar, ACTOR_PARTNER, 0, LVar0)
                    EVT_ADD(LVar0, 1)
                    EVT_CALL(SetActorVar, ACTOR_PARTNER, 0, LVar0)
                    EVT_WAIT(15)
                    EVT_CALL(GetActorVar, ACTOR_PARTNER, 0, LVar0)
                    EVT_SUB(LVar0, 1)
                    EVT_CALL(SetActorVar, ACTOR_PARTNER, 0, LVar0)
                EVT_END_CHILD_THREAD
                EVT_SET(LocalFlag(3), 1)
                EVT_SET(LVar9, 0)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Idle)
    EVT_LOOP(0)
        EVT_CALL(GetActorVar, ACTOR_PARTNER, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_IF_EQ(LocalFlag(3), 0)
        EVT_SET(LVar0, 0)
        EVT_SET(LVarF, 0)
        EVT_WAIT(15)
        EVT_GOTO(13)
    EVT_END_IF
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, ATTACK_EVENT_FLAG_4 | ATTACK_EVENT_FLAG_10, 0, 2, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_CALL(GetActionCommandResult, LVarA)
    EVT_CALL(N(GetSpinySurgeDamage))
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_SPINY_SURGE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 0, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_SPINY_SURGE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 0, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_END_SWITCH
    EVT_WAIT(6)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, 0, LVar1)
    EVT_IF_NE(LVar1, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_LABEL(13)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(cloudNine_normal) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_8, 0)
    EVT_CALL(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_20000000, 1)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WATER_BLOCK)
    EVT_CALL(action_command_water_block_init, 2)
    EVT_CALL(SetActionHudPrepareTime, 50)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_10)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 17)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(func_8024EDA4)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 40)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, 10)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_SET(LVar0, 0)
    EVT_LOOP(10)
        EVT_ADD(LVar0, 18)
        EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_CloudNineBegin)
    EVT_WAIT(5)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_CloudNineIdle)
    EVT_WAIT(15)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -12)
    EVT_ADD(LVar1, 13)
    EVT_ADD(LVar2, -5)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_ReadyJump)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 18, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_ReadyJump)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(action_command_water_block_start, 0, 97, 3)
    EVT_CALL(AddBattleCamZoom, -75)
    EVT_CALL(MoveBattleCamOver, 100)
    EVT_CALL(func_8024ECF8, 0, 0, 1)
    EVT_WAIT(100)
    EVT_WAIT(3)
    EVT_CALL(AddBattleCamZoom, 50)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_CALL(GetActionCommandResult, LVarA)
    EVT_IF_GT(LVarA, 0)
        EVT_CALL(N(RemoveCloudNineFX))
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_201D)
        EVT_CALL(N(CloudNineFX))
        EVT_CALL(N(ApplyCloudNine))
        EVT_CALL(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_8000000, 1)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_CloudNineEnd)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
        EVT_LOOP(10)
            EVT_SET(LVar0, LVar3)
            EVT_SET(LVar1, LVar4)
            EVT_SET(LVar2, LVar5)
            EVT_CALL(RandInt, 40, LVar6)
            EVT_SUB(LVar6, 20)
            EVT_ADD(LVar0, LVar6)
            EVT_CALL(RandInt, 30, LVar6)
            EVT_SUB(LVar6, 15)
            EVT_ADD(LVar1, LVar6)
            EVT_CALL(PlayEffect, EFFECT_FLOATING_CLOUD_PUFF, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 20, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_ReadyJump)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerFallToGoal, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Walk)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_ReadyJump)
    EVT_WAIT(7)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_THREAD
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
        EVT_CALL(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_20000000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_SUB(LVar1, 40)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, 10)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_SET(LVar0, 180)
    EVT_LOOP(10)
        EVT_SUB(LVar0, 18)
        EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(10)
    EVT_IF_GT(LVarA, 0)
        EVT_CALL(ShowMessageBox, 40, 60)
        EVT_CALL(WaitForMessageBoxDone)
    EVT_END_IF
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_8, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(cloudNine_immobile) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WATER_BLOCK)
    EVT_CALL(action_command_water_block_init, 2)
    EVT_CALL(SetActionHudPrepareTime, 50)
    EVT_CALL(N(RemoveCloudNineFX))
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_10)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(func_8024EDA4)
    EVT_WAIT(10)
    EVT_SET(LVar0, 0)
    EVT_LOOP(10)
        EVT_ADD(LVar0, 18)
        EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_CloudNineBegin)
    EVT_WAIT(20)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 12)
    EVT_ADD(LVar1, -7)
    EVT_ADD(LVar2, 5)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, -10, 10)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 40)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(FlyToGoal, ACTOR_PLAYER, 20, 0, 10)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 40)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 0, 10)
    EVT_CALL(action_command_water_block_start, 0, 97, 3)
    EVT_CALL(AddBattleCamZoom, -75)
    EVT_CALL(MoveBattleCamOver, 100)
    EVT_CALL(func_8024ECF8, 0, 0, 1)
    EVT_WAIT(100)
    EVT_WAIT(3)
    EVT_CALL(AddBattleCamZoom, 50)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_CALL(GetActionCommandResult, LVarA)
    EVT_IF_GT(LVarA, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_201D)
        EVT_CALL(N(CloudNineFX))
        EVT_CALL(N(ApplyCloudNine))
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_CloudNineEnd)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
        EVT_LOOP(10)
            EVT_SET(LVar0, LVar3)
            EVT_SET(LVar1, LVar4)
            EVT_SET(LVar2, LVar5)
            EVT_CALL(RandInt, 40, LVar6)
            EVT_SUB(LVar6, 20)
            EVT_ADD(LVar0, LVar6)
            EVT_CALL(RandInt, 30, LVar6)
            EVT_SUB(LVar6, 15)
            EVT_ADD(LVar1, LVar6)
            EVT_CALL(PlayEffect, EFFECT_FLOATING_CLOUD_PUFF, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 20, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(FallToGoal, ACTOR_PLAYER, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Walk)
    EVT_THREAD
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 0, 10)
    EVT_END_THREAD
    EVT_SET(LVar0, 180)
    EVT_LOOP(10)
        EVT_SUB(LVar0, 18)
        EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(10)
    EVT_IF_GT(LVarA, 0)
        EVT_CALL(ShowMessageBox, 40, 60)
        EVT_CALL(WaitForMessageBoxDone)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(cloudNine) = {
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_EXEC_WAIT(N(cloudNine_immobile))
    EVT_ELSE
        EVT_EXEC_WAIT(N(cloudNine_normal))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

enum {
    STATE_INHALE   = -1,
    STATE_DISABLED =  0,
    STATE_EXHALE   =  1,
};

ApiStatus N(ProcessHurricane)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    ActorState* partnerState = &partner->state;
    EffectInstance* effect;
    Actor* targetActor;
    SelectableTarget* target;
    s32 targetIndex;
    s32 temp;
    s32 i;
    f32 x, y, z;
    f32 x2, y2, z2;
    f32 tempF1, tempF2;
    f32 totalPower;
    f64 tempF64;

    static EffectInstance* sHuffPuffBreathEffect;
    static HurricaneState sHurricaneState;
    static s32 sUnusedAngle;
    static s32 sHurricaneIntensity;
    static s32 sHuffPuffBreathState;
    static s32 D_8023D278;
    static HurricaneState* hurricaneState = &sHurricaneState;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            partner->state.angle = 0.0f;
            partner->state.moveTime = 165;
            partner->state.moveArcAmplitude = 0;
            sIsHurricaneActive = TRUE;
            D_8023D338 = 255;
            sHuffPuffBreathEffect = effect = fx_huff_puff_breath(0, NPC_DISPOSE_LOCATION, 0.0f, -2.0f, 0.6f, 0);

            effect->data.huffPuffBreath->primR = 20;
            effect->data.huffPuffBreath->primG = 80;
            effect->data.huffPuffBreath->primB = 255;

            effect->data.huffPuffBreath->envR = 200;
            effect->data.huffPuffBreath->envG = 240;
            effect->data.huffPuffBreath->envB = 240;

            hurricaneState->unk_54 = 177;
            hurricaneState->breathSizeIncrease = 0;
            hurricaneState->unk_46 = 0;
            hurricaneState->state = 0;
            hurricaneState->totalPower = 5000;
            hurricaneState->intensity = 0;
            hurricaneState->startingTotalPower = -1;


            sSavedHurricaneIntensity = 0;
            D_8023D278 = (1.0 - sin_rad(hurricaneState->intensity * PI_S * 0.5f / 750.0f)) * 8.0 + 13.0;
            sHuffPuffBreathState = -1;

            sUnusedAngle = 0;
            sHurricaneIntensity = 0;
            sBreathSizeIncrease = 0;

            sMaxPower = 2000;
            script->functionTemp[1] = rand_int(10) + 11;
            script->functionTemp[2] = 0;
            script->functionTemp[0] = 1;
            break;
        case 1:
            partner->state.angle = sUnusedAngle * 150 / 100 - 75; // angle is not used

            for (i = 0; i < partner->targetListLength; i++) {
                targetIndex = partner->targetIndexList[i];
                temp = sTargetStates[targetIndex];
                if (temp != -1) {
                    if (temp != 0) {
                        target = &partner->targetData[targetIndex];
                        targetActor = get_actor(target->actorID);
                        targetActor->yaw = clamp_angle(targetActor->yaw + 13.0f + sHurricaneIntensity * 4);
                    }
                }
            }

            if (partnerState->moveTime != 0) {
                partnerState->moveTime--;
                break;
            }

            for (i = 0; i < partner->targetListLength; i++) {
                targetIndex = partner->targetIndexList[i];
                temp = sTargetStates[targetIndex];
                if (temp != -1) {
                    if (temp != 0) {
                        target = &partner->targetData[targetIndex];
                        targetActor = get_actor(target->actorID);
                        targetActor->yaw = 0.0f;
                    }
                }
            }

            sIsHurricaneActive = FALSE;
            remove_effect(sHuffPuffBreathEffect);
            return ApiStatus_DONE2;
    }

    sHuffPuffBreathEffect->data.huffPuffBreath->scale = sBreathSizeIncrease / 50.0 + 1.0;
    x = partner->currentPos.x;
    y = partner->currentPos.y;
    rand_int(1000);
    tempF1 = 5.0f;
    switch (sHuffPuffBreathState) {
        case STATE_INHALE:
            x = partner->currentPos.x;
            y = partner->currentPos.y + 15.0f;
            z = partner->currentPos.z + tempF1;
            add_vec2D_polar(&x, &y, 12.0f, 90.0f);
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.x = x;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.y = y;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.z = z;
            sHuffPuffBreathEffect->data.huffPuffBreath->speedX = -2.0f;

            // looks like this was breath inhale phase, but then the devs removed it
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.x = 0.0f;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.y = -1000.0f;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.z = 0.0f;

            if (script->functionTemp[2] != 0) {
                sfx_play_sound_at_position(SOUND_201E, SOUND_SPACE_MODE_0, partner->currentPos.x, partner->currentPos.y, partner->currentPos.z);
            }
            script->functionTemp[2] = 0;

            partnerState->moveArcAmplitude = 0;
            set_animation(ACTOR_PARTNER, -1, ANIM_BattleLakilester_HurricaneInhale);
            break;
        case STATE_DISABLED:
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.x = 0.0f;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.y = -1000.0f;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.z = 0.0f;
            break;
        case STATE_EXHALE:
            x = partner->currentPos.x;
            y = partner->currentPos.y + 15.0f;
            z = partner->currentPos.z + tempF1;
            add_vec2D_polar(&x, &y, 12.0f, 90.0f);
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.x = x;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.y = y;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.z = z;
            sHuffPuffBreathEffect->data.huffPuffBreath->speedX = 2.0f;

            if (script->functionTemp[2] == 0) {
                sfx_play_sound_at_position(SOUND_201F, SOUND_SPACE_MODE_0, partner->currentPos.x, partner->currentPos.y, partner->currentPos.z);
            }
            script->functionTemp[2] = 1;

            if (partnerState->moveArcAmplitude == 0) {
                script->functionTemp[1] = 1;
            }
            partnerState->moveArcAmplitude = 1;

            set_animation(ACTOR_PARTNER, -1, ANIM_BattleLakilester_HurricaneExhale);
            break;
    }


    if (gGameStatusPtr->frameCounter % (7 - sHurricaneIntensity / 2) == 0) {
        x = -220.0f;
        y = 176 - rand_int(100);
        z = 50.0f;
        x2 = 220.0f;
        y2 = y - (rand_int(100) + 100);
        z2 = 50.0f;
        tempF1 = rand_int(1000);
        tempF1 = tempF1 / 3000.0f + 0.5;
        tempF2 = rand_int(1000);
        tempF2 = tempF2 / 300.0f + 5.75 + sHurricaneIntensity;
        fx_moving_cloud(1, x, y, z, x2, y2, z2, tempF2, tempF1);
    }

    if (gGameStatusPtr->frameCounter % (7 - sHurricaneIntensity / 2) == 0) {
        x = -220.0f;
        y = 176 - rand_int(100);
        z = -50.0f;
        x2 = 220.0f;
        y2 = y - (rand_int(100) + 100);
        z2 = -50.0f;
        tempF1 = rand_int(1000);
        tempF1 = tempF1 / 4000.0f + 0.1;
        tempF2 = rand_int(1000);
        tempF2 = tempF2 / 300.0f + 2.75 + sHurricaneIntensity / 2;
        fx_moving_cloud(1, x, y, z, x2, y2, z2, tempF2, tempF1);
    }

RESTART:
    switch (hurricaneState->state) {
        case 0:
            sHuffPuffBreathState = STATE_EXHALE;
            if (hurricaneState->startingTotalPower < 0) {
                hurricaneState->startingTotalPower = hurricaneState->totalPower;
            }

            totalPower = hurricaneState->totalPower;
            if (totalPower > 5000.0f) {
                totalPower = 5000.0f;
            }

            tempF64 = D_8023D278;
            tempF1 = tempF64 + tempF64 * (1.0 - sin_rad(totalPower * PI_S * 0.5f / 5000.0f + PI_S / 2)) * 1.5;
            hurricaneState->intensity += tempF1;
            sSavedHurricaneIntensity += D_8023D278;

            if (hurricaneState->totalPower > 9000) {
                hurricaneState->intensity -= hurricaneState->intensity / 2;
            }

            if (hurricaneState->intensity < 0) {
                hurricaneState->intensity = 0;
            }

            hurricaneState->intensity += tempF1;
            if (hurricaneState->intensity > 750) {
                hurricaneState->intensity = 750;
            }

            if (sSavedHurricaneIntensity > 1000) {
                sSavedHurricaneIntensity = 1000;
            }

            hurricaneState->totalPower += hurricaneState->intensity;

            if (hurricaneState->totalPower > sMaxPower + 5000) {
                hurricaneState->totalPower = sMaxPower + 5000;
                hurricaneState->state = 1;
                hurricaneState->unk_5D = 5;
                hurricaneState->intensity = sSavedHurricaneIntensity;
            }
            break;
        case 1:
            sHuffPuffBreathState = STATE_DISABLED;
            hurricaneState->state = 10;
            break;
    }

    switch (hurricaneState->state) {
        case 10:
            sHuffPuffBreathState = STATE_INHALE;
            tempF1 = hurricaneState->intensity + hurricaneState->intensity / 3;
            if (tempF1 < 200.0f) {
                tempF1 = 200.0f;
            }
            hurricaneState->totalPower -= tempF1;
            if (hurricaneState->totalPower < 5000 - sMaxPower) {
                hurricaneState->totalPower = 5000 - sMaxPower;
                hurricaneState->state = 11;
                hurricaneState->unk_5D = 5;
                hurricaneState->startingTotalPower = -1;
                sMaxPower += 1000;
                if (sMaxPower > 5000) {
                    sMaxPower = 5000;
                }
            }
            break;
        case 11:
            sHuffPuffBreathState = STATE_DISABLED;
            hurricaneState->state = 0;
            hurricaneState->intensity -= hurricaneState->intensity / 2.8;
            sSavedHurricaneIntensity = hurricaneState->intensity;
            D_8023D278 = (1.0 - sin_rad(hurricaneState->intensity * PI_S * 0.5f / 750.0f)) * 8.0 + 13.0;
            goto RESTART;
    }

    if (hurricaneState->state == 0) {
        hurricaneState->breathSizeIncrease += hurricaneState->intensity / 4;
    }

    if (hurricaneState->breathSizeIncrease > 10000) {
        hurricaneState->breathSizeIncrease = 10000;
    }

    sUnusedAngle = hurricaneState->totalPower / 100;
    sHurricaneIntensity = hurricaneState->intensity / 100;
    if (sHurricaneIntensity > 10) {
        sHurricaneIntensity = 10;
    }
    sBreathSizeIncrease = hurricaneState->breathSizeIncrease / 100;

    return ApiStatus_BLOCK;
}

ApiStatus N(BlowTargetAway)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* target;
    ActorState* state;
    f64 temp_f20;

    if (isInitialCall) {
        script->functionTempPtr[1] = get_actor(script->varTable[10]);
        script->functionTemp[0] = 0;
    }

    target = script->functionTempPtr[1];
    state = &target->state;
    switch (script->functionTemp[0]) {
        case 0:
            target->state.moveTime = 0;
            target->state.currentPos.x = target->currentPos.x;
            target->state.currentPos.y = target->currentPos.y;
            target->state.currentPos.z = target->currentPos.z;
            target->state.speed = 5.5f;
            sNumEnemiesBeingBlown += 1;
            battleStatus->currentAttackElement = 0;
            dispatch_event_actor(target, EVENT_BLOW_AWAY);
            script->functionTemp[0] = 1;
            break;
        case 1:
            target->state.currentPos.x += target->state.speed;
            temp_f20 = target->state.currentPos.y;
            target->state.currentPos.y =
                temp_f20 + ((sin_rad(2.0f * sin_rad(DEG_TO_RAD(target->state.moveTime)) * PI_S) * 1.4) + 0.5);
            target->state.moveTime += 6;
            target->state.moveTime = clamp_angle(target->state.moveTime);
            target->yaw += 33.0f;
            target->yaw = clamp_angle(target->yaw);
            if (target->state.currentPos.x > 240.0f) {
                sNumEnemiesBeingBlown -= 1;
                return ApiStatus_DONE2;
            }
            break;
    }
    target->currentPos.x = state->currentPos.x;
    target->currentPos.y = state->currentPos.y;
    target->currentPos.z = state->currentPos.z;
    return ApiStatus_BLOCK;
}

ApiStatus N(AllEnemiesBlownAway)(Evt* script, s32 isInitialCall) {
    if (sNumEnemiesBeingBlown == 0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus N(IsHurricaneActive)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = sIsHurricaneActive;
    return ApiStatus_DONE2;
}

EvtScript N(hurricane) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_HURRICANE)
    EVT_CALL(action_command_hurricane_init)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_CALL(SetActionHudPrepareTime, 15)
    EVT_CALL(func_80269EAC, 20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -45, 54, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 280)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Run)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, 40, 20, 0)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Idle)
    EVT_WAIT(15)
    EVT_CALL(N(InitHurricane))
    EVT_CALL(action_command_hurricane_start, 0, 147, 3, LVar0)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
    EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 20, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 35, 54, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 430)
    EVT_CALL(MoveBattleCamOver, 150)
    EVT_CALL(func_8024ECF8, 0, 0, 1)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_288)
    EVT_THREAD
        EVT_CALL(N(ProcessHurricane))
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_LOOP(150)
        EVT_CALL(N(IsHurricaneActive))
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(GetActionSuccessCopy, LVar0)
        EVT_IF_EQ(LVar0, 100)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(15)
    EVT_CALL(GetActionSuccessCopy, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_END_SWITCH
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(N(CanTargetBeBlown))
    EVT_IF_GT(LVar0, 0)
        EVT_SET(LVarA, LVar0)
        EVT_THREAD
            EVT_CALL(N(BlowTargetAway))
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_STAR_POINTS_DROPPED, 1)
            EVT_CALL(RemoveActor, LVarA)
        EVT_END_THREAD
    EVT_ELSE
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(PartnerDamageEnemy, LVar2, DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_FORCE_HIT_IMMUNE)
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_WAIT(34)
    EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_EXEC_WAIT(N(returnHome))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1,  ANIM_BattleLakilester_Walk)
    EVT_CALL(N(AllEnemiesBlownAway))
    EVT_CALL(PartnerYieldTurn)
    EVT_RETURN
    EVT_END
};
