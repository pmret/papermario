#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleLakilester.h"
#include "battle/action_cmd/spiny_surge.h"
#include "battle/action_cmd/water_block.h"
#include "battle/action_cmd/hurricane.h"
#include "hud_element.h"
#include "sprite/player.h"

#define NAMESPACE battle_partner_lakilester

extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_ExecuteAction);
extern EvtScript N(EVS_Celebrate);
extern EvtScript N(EVS_RunAway);
extern EvtScript N(EVS_RunAwayFail);
extern EvtScript N(EVS_Move_SpinyFlip);
extern EvtScript N(EVS_Move_SpinySurge);
extern EvtScript N(EVS_Move_CloudNine);
extern EvtScript N(EVS_Move_Hurricane);

extern HudScript HES_AimBlinkA;
extern HudScript HES_AimReticle;
extern HudScript HES_AimTarget;
extern HudScript HES_StickTapRight;

static s32 sSavedHurricaneIntensity;
static s32 sBreathSizeIncrease;
static s32 sMaxPower;
static s32 HID_AimReticle;
static s32 HID_AimTarget;
static s32 TargetMarkRotation;
static s32 D_8023D294;
static s32 AimingTime;
static s32 D_8023D29C;
static f32 D_8023D2A0;
static f32 D_8023D2A4;
static f32 D_8023D2A8;
static f32 D_8023D2AC;
static f32 D_8023D2B0;
static f32 AimMoveAngle;
static s32 hudAim[1];
static s32 HID_AnalogStick;
static s32 HudStickPosX;
static s32 HudStickPosY;
static b32 SpinyFlipTargetingDone;
static s32 D_8023D2CC;
static s32 sTargetStates[24];
static s32 sNumEnemiesBeingBlown;
static s32 sIsHurricaneActive;
static s32 D_8023D338;

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
};

enum N(ActorVars) {
    AVAR_Unk_0      = 0,
};

enum N(ActorParams) {
    DMG_UNK         = 0,
};

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

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleLakilester_Walk,
    STATUS_KEY_DAZE,      ANIM_BattleLakilester_Injured,
    STATUS_KEY_INACTIVE,  ANIM_BattleLakilester_Still,
    STATUS_END,
};

s32 N(IdleAnimations_spiny)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleLakilester_Spiny,
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
        .targetOffset = { 12, 30 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_spiny),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LAKILESTER,
    .level = ACTOR_LEVEL_LAKILESTER,
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
    .size = { 44, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusTextOffset = { 13, 31 },
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
            SetConst(LVar1,  ANIM_BattleLakilester_Hurt)
            SetConst(LVar2,  ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Partner_LakilesterHit)
            SetConst(LVar1,  ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Partner_Drop)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1,  ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Partner_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_CONTACT)
            SetConst(LVar1,  ANIM_BattleLakilester_Hurt)
            SetConst(LVar2, 20)
            ExecWait(EVS_Partner_SpikeContact)
            SetConst(LVar1,  ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_CONTACT)
            SetConst(LVar1,  ANIM_BattleLakilester_BurnHurt)
            Set(LVar2, 20)
            SetConst(LVar3,  ANIM_BattleLakilester_BurnStill)
            ExecWait(EVS_Partner_BurnContact)
            SetConst(LVar1,  ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar1,  ANIM_BattleLakilester_BurnHurt)
            SetConst(LVar2,  ANIM_BattleLakilester_BurnStill)
            ExecWait(EVS_Partner_BurnHit)
            SetConst(LVar1,  ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar1,  ANIM_BattleLakilester_Hurt)
            Set(LVar2, 20)
            ExecWait(EVS_Partner_ShockHit)
        CaseEq(EVENT_33)
            SetConst(LVar1,  ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_RECOVER_FROM_KO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1,  ANIM_BattleLakilester_Walk)
            SetConst(LVar2,  ANIM_BattleLakilester_Run)
            Set(LVar3, 10)
            ExecWait(EVS_Partner_Recover)
        CaseOrEq(EVENT_18)
        CaseOrEq(EVENT_BLOCK)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Block)
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
            ExecWait(N(EVS_RunAway))
        CaseEq(PHASE_RUN_AWAY_FAIL)
            ExecWait(N(EVS_RunAwayFail))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Celebrate) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleLakilester_Celebrate)
    SetConst(LVar2, ANIM_BattleLakilester_Walk)
    SetConst(LVar3, ANIM_BattleLakilester_Walk)
    ExecWait(EVS_Partner_Celebrate)
    Return
    End
};

EvtScript N(EVS_RunAway) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleLakilester_Run)
    ExecWait(EVS_Partner_RunAway)
    Return
    End
};

EvtScript N(EVS_RunAwayFail) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Run)
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Walk)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

EvtScript N(EVS_ExecuteAction) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Call(ShowActionHud, TRUE)
    Switch(LVar0)
        CaseEq(BTL_MENU_TYPE_STAR_POWERS)
            Call(LoadStarPowerScript)
            ExecWait(LVar0)
            Return
    EndSwitch
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_SPINY_FLIP1)
            Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            ExecWait(N(EVS_Move_SpinyFlip))
        CaseEq(MOVE_SPINY_FLIP2)
            Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            ExecWait(N(EVS_Move_SpinyFlip))
        CaseEq(MOVE_SPINY_FLIP3)
            Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            ExecWait(N(EVS_Move_SpinyFlip))
        CaseEq(MOVE_SPINY_SURGE)
            ExecWait(N(EVS_Move_SpinySurge))
        CaseEq(MOVE_CLOUD_NINE)
            Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            ExecWait(N(EVS_Move_CloudNine))
        CaseEq(MOVE_HURRICANE)
            ExecWait(N(EVS_Move_Hurricane))
    EndSwitch
    Return
    End
};

EvtScript N(returnHome2) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 15, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Walk)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 15, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Walk)
    Return
    End
};

HudScript* N(AimDotHudScripts)[] = {
    &HES_AimBlinkA
};

API_CALLABLE(N(SpinyFlipUpdatePopup)) {
    if (isInitialCall) {
        SpinyFlipTargetingDone = FALSE;
    }

    if (!SpinyFlipTargetingDone) {
        btl_set_popup_duration(99);
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

API_CALLABLE(N(SpinyFlipActionCommand)) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 screenX, screenY, screenZ;
    Actor* partner = battleStatus->partnerActor;
    Actor* target;
    ActorPart* part;
    ActorState* playerState;
    ActorState* partnerState;
    f32 speed;
    f32 stickAngle;
    s32 stickMagnitude;
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

    enum SpinyFlipState {
        SPINY_FLIP_INIT     = 0,
        SPINY_FLIP_DELAY    = 1, // give player time to start aiming
        SPINY_FLIP_AIMING   = 2, // player is aiming
    };

    partnerState = &partner->state;
    playerState = &battleStatus->playerActor->state;

    if (isInitialCall) {
        script->functionTemp[0] = SPINY_FLIP_INIT;
    }

    switch (script->functionTemp[0]) {
        case SPINY_FLIP_INIT:
            HID_AimReticle = hud_element_create(&HES_AimReticle);
            hud_element_set_render_depth(HID_AimReticle, 10);
            HID_AimTarget = hud_element_create(&HES_AimTarget);
            hud_element_set_render_depth(HID_AimTarget, 10);
            hud_element_create_transform_A(HID_AimTarget);
            HudStickPosX = -48;
            HudStickPosY = 70;
            HID_AnalogStick = id = hud_element_create(&HES_StickNeutral);
            hud_element_set_render_pos(id, HudStickPosX, HudStickPosY);
            hud_element_set_render_depth(id, 0);
            for (i = 0; i < ARRAY_COUNT(N(AimDotHudScripts)); i++) {
                hudAim[i] = idAim = hud_element_create(N(AimDotHudScripts)[i]);
                hud_element_set_render_depth(idAim, 10);
            }
            partnerState->curPos.x = partner->curPos.x + 33.0f;
            partnerState->curPos.y = partner->curPos.y + 34.0f;
            partnerState->curPos.z = partner->curPos.z + 15.0f;
            partnerState->unk_18.x = partner->curPos.x + 33.0f;
            partnerState->unk_18.y = partner->curPos.y + 34.0f;
            partnerState->unk_18.z = partner->curPos.z + 15.0f;
            set_goal_pos_to_part(partnerState, partner->targetActorID, partner->targetPartID);
            target = get_actor(partner->targetActorID);
            part = get_actor_part(target, partner->targetPartID);
            partnerState->goalPos.x += part->projectileTargetOffset.x;
            partnerState->goalPos.y += part->projectileTargetOffset.y;
            partnerState->goalPos.z = partnerState->goalPos.z; // required to match
            partnerState->dist = dist2D(partnerState->curPos.x,
                                            partnerState->curPos.y,
                                            partnerState->goalPos.x,
                                            partnerState->goalPos.y);
            partnerState->speed = 0.0f;
            partnerState->velStep.x = 0.0f;
            partnerState->velStep.y = 0.0f;
            TargetMarkRotation = 0;
            D_8023D294 = 0;
            AimingTime = 30;
            D_8023D2A0 = 0.0f;
            D_8023D2A4 = 0.0f;
            D_8023D2A8 = 0.0f;
            D_8023D2AC = 0.0f;
            D_8023D29C = 0;
            D_8023D2B0 = 3.0f;
            AimMoveAngle = -1.0f;
            partnerState->unk_24 = ((part->size.y + part->size.x) / 2) / 24.0;
            hud_element_set_scale(HID_AimTarget, partnerState->unk_24 * target->scalingFactor);
            SpinyFlipTargetingDone = TRUE;
            script->functionTemp[0] = SPINY_FLIP_DELAY;
            break;
        case SPINY_FLIP_DELAY:
            if (battleStatus->stickX != 0 || battleStatus->stickY != 0) {
                AimingTime = 0;
            }
            if (AimingTime != 0) {
                AimingTime--;
            } else {
                AimingTime = (s32)(80 * DT);
                hud_element_set_script(HID_AnalogStick, &HES_StickTapRight);
                sfx_play_sound_at_position(SOUND_AIM_SPINY_FLIP, SOUND_SPACE_DEFAULT, 0.0f, 0.0f, 0.0f);
                script->functionTemp[0] = SPINY_FLIP_AIMING;
            }
            break;
        case SPINY_FLIP_AIMING:
            stickMagnitude = battleStatus->stickMagnitude;
            if (stickMagnitude > 80) {
                stickMagnitude = 80;
            }
            stickAngle = battleStatus->stickAngle;
            if (stickMagnitude < 35) {
                f32 temp = stickMagnitude;
                stickMagnitude = temp * sin_rad(DEG_TO_RAD(stickMagnitude * 2));
            }
            temp_f8 = D_8023D2A0;
            temp_f2 = temp_f8 + D_8023D2A4 + D_8023D2A8;
            D_8023D2A0 = stickMagnitude;
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
                AimMoveAngle = stickAngle;
            } else {
                D_8023D2AC = temp_f10;
            }
            if (!(stickMagnitude < 31)) {
                AimMoveAngle = stickAngle;
            }
            if (partnerState->speed > 6.7) {
                partnerState->speed = 6.7;
            }
            partnerState->speed -= (f32) ((2.0 * (40 - stickMagnitude)) / 40.0);
            if (partnerState->speed <= 0.0f) {
                partnerState->speed = 0.0f;
                D_8023D2AC = 0.0f;
            }
            if (AimMoveAngle >= 0.0f) {
                theta = DEG_TO_RAD(AimMoveAngle);
                sinTheta = sin_rad(theta);
                cosTheta = cos_rad(theta);
                speed = partnerState->speed;
                partnerState->curPos.x += speed * sinTheta;
                partnerState->curPos.y += speed * cosTheta;
            }
            if (partnerState->curPos.x < -30.0f) {
                partnerState->curPos.x = -30.0f;
            }
            if (partnerState->curPos.x > 170.0f) {
                partnerState->curPos.x = 170.0f;
            }
            if (partnerState->curPos.y > 130.0f) {
                partnerState->curPos.y = 130.0f;
            }
            if (partnerState->curPos.y < 0.0f) {
                partnerState->curPos.y = 0.0f;
            }
            if (battleStatus->curButtonsPressed & BUTTON_A) {
                AimingTime = 0;
            }
            if (AimingTime == 60) {
                set_actor_anim(ACTOR_PARTNER, 0,  ANIM_BattleLakilester_HoldSpiny);
            }
            if (AimingTime == 30) {
                set_actor_anim(ACTOR_PARTNER, 0, ANIM_BattleLakilester_StrainHoldSpiny);
            }
            if (AimingTime != 0) {
                AimingTime--;
                break;
            }
            script->varTable[14] = 0;
            script->varTable[15] = 0;
            script->varTable[7] = partnerState->curPos.x;
            script->varTable[8] = partnerState->curPos.y;
            script->varTable[9] = partnerState->curPos.z;
            partnerState->dist = dist2D(partnerState->curPos.x, partnerState->curPos.y, partnerState->goalPos.x, partnerState->goalPos.y) / partnerState->unk_24;
            if (partnerState->dist <= 12.0) {
                script->varTable[15] = 1;
            }
            hud_element_free(HID_AimTarget);
            hud_element_free(HID_AimReticle);
            hud_element_free(HID_AnalogStick);
            for (i = 0; i < ARRAY_COUNT(N(AimDotHudScripts)); i++) {
                id = hudAim[i];
                hud_element_free(id);
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(SOUND_AIM_SPINY_FLIP);
            return ApiStatus_DONE2;
    }

    get_screen_coords(gCurrentCameraID,
                      partnerState->goalPos.x, partnerState->goalPos.y, partnerState->goalPos.z,
                      &screenX, &screenY, &screenZ);
    id = HID_AimTarget;
    hud_element_set_render_pos(id, screenX, screenY);
    hud_element_set_transform_rotation(id, 0.0f, 0.0f, TargetMarkRotation);
    TargetMarkRotation -= 10;
    TargetMarkRotation = clamp_angle(TargetMarkRotation);
    get_screen_coords(gCurrentCameraID,
                      partnerState->curPos.x, partnerState->curPos.y, partnerState->curPos.z,
                      &screenX, &screenY, &screenZ);
    hud_element_set_render_pos(HID_AimReticle, screenX, screenY);

    // show analog stick hud element
    switch (script->functionTemp[0]) {
        case SPINY_FLIP_DELAY:
        case SPINY_FLIP_AIMING:
            HudStickPosX += 20;
            if (HudStickPosX > 50) {
                HudStickPosX = 50;
            }
            hud_element_set_render_pos(HID_AnalogStick, HudStickPosX, HudStickPosY);
            break;
    }

    // show aim dot hud element in center of 
    switch (script->functionTemp[0]) {
        case SPINY_FLIP_DELAY:
        case SPINY_FLIP_AIMING:
            playerState->curPos.x = partnerState->curPos.x;
            playerState->curPos.y = partnerState->curPos.y;
            playerState->curPos.z = partnerState->curPos.z;
            for (i = 0; i < ARRAY_COUNT(N(AimDotHudScripts)); i++) {
                get_screen_coords(gCurrentCameraID, playerState->curPos.x, playerState->curPos.y, playerState->curPos.z, &screenX, &screenY, &screenZ);
                id = hudAim[i];
                hud_element_set_render_pos(id, screenX, screenY);
            }
            break;
    }

    btl_set_popup_duration(99);
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(ThrowSpinyFX)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 xPos = partnerActor->curPos.x + 5;
    f32 yPos = partnerActor->curPos.y + partnerActor->size.y + 20;
    f32 zPos = partnerActor->curPos.z;
    f32 var = rand_int(140) + 10;
    f32 var2 = rand_int(80) + 10;

    fx_throw_spiny(0, xPos, yPos, zPos, var, var2, 20, 1.5f, 30);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetSpinySurgeDamage)) {
    s32 partnerLevel = gBattleStatus.partnerActor->actorBlueprint->level;
    s32 actionCommandResult = script->varTable[10];
    s32 damage = 0;

    switch (partnerLevel) {
        case PARTNER_RANK_NORMAL:
            if (actionCommandResult <= 99) {
                damage = 1;
            } else {
                damage = 2;
            }
            break;
        case PARTNER_RANK_SUPER:
            if (actionCommandResult <= 70) {
                damage = 1;
            } else if (actionCommandResult <= 99) {
                damage = 2;
            } else {
                damage = 3;
            }
            break;
        case PARTNER_RANK_ULTRA:
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

API_CALLABLE(N(RemoveCloudNineFX)) {
    EffectInstance* effect = gBattleStatus.cloudNineEffect;

    if (effect != NULL) {
        remove_effect(effect);
        gBattleStatus.cloudNineEffect = NULL;
        gBattleStatus.cloudNineTurnsLeft = 0;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnCloudNineFX)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor = battleStatus->playerActor;

    static f32 sCounter;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            sCounter = 0.1f;
            fx_ending_decals(0, actor->curPos.x, actor->curPos.y, actor->curPos.z, 0.1f, &battleStatus->cloudNineEffect);
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

API_CALLABLE(N(ApplyCloudNine)) {
    if (gBattleStatus.cloudNineTurnsLeft < script->varTable[10]) {
        gBattleStatus.cloudNineTurnsLeft = script->varTable[10];
        gBattleStatus.cloudNineDodgeChance = 50;
        gBattleStatus.buffEffect->data.partnerBuff->unk_0C[FX_BUFF_DATA_CLOUD_NINE].turnsLeft = gBattleStatus.cloudNineTurnsLeft;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(InitHurricane)) {
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
        hpMissingPercent = 100 - ((actor->curHP * 100) / actor->maxHP);
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
            if (actor->transparentStatus == STATUS_KEY_TRANSPARENT) {
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
        if (actor->transparentStatus == STATUS_KEY_TRANSPARENT || (part->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY)) {
            sTargetStates[targetIdx] = -1;
        } else if (sTargetStates[targetIdx] != 0) {
            sTargetStates[targetIdx] = avgHurricaneChance;
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CanTargetBeBlown)) {
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

EvtScript N(EVS_Move_SpinyFlip) = {
    Thread
        Call(N(SpinyFlipUpdatePopup))
    EndThread
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Run)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Add(LVar1, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Idle)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, 47, 46, 12)
    Call(SetBattleCamOffsetZ, 7)
    Call(SetBattleCamZoom, 416)
    Call(MoveBattleCamOver, 30)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 3)
    Add(LVar1, 10)
    Add(LVar2, 5)
    Call(SetPartPos, ACTOR_PARTNER, 2, LVar0, LVar1, LVar2)
    Wait(1)
    Call(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_2, ANIM_BattleLakilester_Spiny)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_LiftSpiny)
    Loop(4)
        Add(LVar1, 6)
        Call(SetPartPos, ACTOR_PARTNER, 2, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 8)
    Add(LVar1, 40)
    Add(LVar2, 5)
    PlayEffect(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, Float(1.0), 80 * DT, 0)
    Call(SetActorVar, ACTOR_PARTNER, AVAR_Unk_0, 1)
    Thread
        Loop(40 * DT)
            Call(SetActorDispOffset, ACTOR_PARTNER, 1, 0, 0)
            Call(SetPartDispOffset, ACTOR_PARTNER, 2, 1, 0, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_PARTNER, -1, 0, 0)
            Call(SetPartDispOffset, ACTOR_PARTNER, 2, -1, 0, 0)
            Wait(1)
            Call(GetActorVar, ACTOR_PARTNER, AVAR_Unk_0, LVar0)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
        Call(SetPartDispOffset, ACTOR_PARTNER, 2, 0, 0, 0)
    EndThread
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(N(SpinyFlipActionCommand))
    Call(SetActorVar, ACTOR_PARTNER, AVAR_Unk_0, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_ThrowSpiny)
    Wait(3)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Set(LVarF, -1)
    EndIf
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_LAKILESTER_THROW_SPINY_A)
    Switch(LVarF)
        CaseEq(-1)
            Call(SetAnimation, ACTOR_SELF, PRT_2, ANIM_BattleLakilester_SpinySpin)
            Call(SetPartJumpGravity, ACTOR_PARTNER, 2, Float(1.5))
            Set(LVar0, LVar7)
            Set(LVar1, LVar8)
            Set(LVar2, LVar9)
            Call(JumpPartTo, ACTOR_PARTNER, 2, LVar7, LVar8, LVar9, 20)
            Call(LandJumpPart, ACTOR_PARTNER, 2)
        CaseEq(0)
            Call(SetAnimation, ACTOR_SELF, PRT_2, ANIM_BattleLakilester_SpinySpin)
            Call(SetPartJumpGravity, ACTOR_PARTNER, 2, Float(1.5))
            Set(LVar0, LVar7)
            Set(LVar1, LVar8)
            Set(LVar2, LVar9)
            Call(JumpPartTo, ACTOR_PARTNER, 2, LVar7, LVar8, LVar9, 20)
            Call(LandJumpPart, ACTOR_PARTNER, 2)
        CaseDefault
            Call(SetAnimation, ACTOR_SELF, PRT_2, ANIM_BattleLakilester_SpinySpin)
            Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(SetPartJumpGravity, ACTOR_PARTNER, 2, Float(1.5))
            Call(JumpPartTo, ACTOR_PARTNER, 2, LVar0, LVar1, LVar2, 20)
    EndSwitch
    Thread
        Add(LVar0, 50)
        Set(LVar1, 0)
        Call(SetPartJumpGravity, ACTOR_PARTNER, 2, Float(1.5))
        Call(JumpPartTo, ACTOR_PARTNER, 2, LVar0, LVar1, LVar2, 15)
        Call(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EndThread
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_SPINY_FLIP1)
            Set(LVarE, 3)
        CaseEq(MOVE_SPINY_FLIP2)
            Set(LVarE, 4)
        CaseEq(MOVE_SPINY_FLIP3)
            Set(LVarE, 5)
    EndSwitch
    Switch(LVarF)
        CaseGt(0)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_SPINY_SURGE | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Set(LVar0, HIT_RESULT_NO_DAMAGE)
    EndSwitch
    Switch(LVarF)
        CaseEq(1)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
        CaseDefault
            Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EndSwitch
    Wait(15)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            ExecWait(N(returnHome2))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Move_SpinySurge) = {
    Call(LoadActionCommand, ACTION_COMMAND_SPINY_SURGE)
    Call(action_command_spiny_surge_init)
    Call(GetActorLevel, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SetupMashMeter, 2, 99, 100, 0, 0, 0)
        CaseEq(1)
            Call(SetupMashMeter, 3, 70, 99, 100, 0, 0)
        CaseEq(2)
            Call(SetupMashMeter, 4, 40, 70, 99, 100, 0)
    EndSwitch
    Call(SetActionHudPrepareTime, 10)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, 45, 60, 0)
    Call(SetBattleCamOffsetZ, 0)
    Call(SetBattleCamZoom, 400)
    Call(MoveBattleCamOver, 30)
    Call(InitTargetIterator)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Run)
    Call(AddGoalPos, ACTOR_PARTNER, 60, 20, 0)
    Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Idle)
    Wait(10)
    Call(GetActorLevel, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Set(LVarA, 60 * DT)
        CaseEq(1)
            Set(LVarA, 60 * DT)
        CaseEq(2)
            Set(LVarA, 60 * DT)
    EndSwitch
    Set(LVarB, LVarA)
    Add(LVarB, -3)
    Call(action_command_spiny_surge_start, 0, LVarB, 3)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Call(InitTargetIterator)
    Call(SetActorVar, ACTOR_PARTNER, AVAR_Unk_0, 0)
    Set(LVar9, 0)
    Set(LFlag2, FALSE)
    Set(LFlag3, FALSE)
    Loop(LVarA)
        Call(GetActionQuality, LVar0)
        IfEq(LVar9, 2)
            Set(LVar0, 3)
        EndIf
        Switch(LVar0)
            CaseEq(-1)
                Set(LVar9, 0)
                Call(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Idle)
            CaseEq(1)
                IfEq(LVar9, 1)
                    BreakSwitch
                EndIf
                Call(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
                Add(LVar0, 3)
                Add(LVar1, 34)
                Add(LVar2, 5)
                Call(SetPartPos, ACTOR_PARTNER, 2, LVar0, LVar1, LVar2)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_LiftSpiny)
                Set(LVar9, 1)
            CaseEq(2)
                IfEq(LVar9, 0)
                    BreakSwitch
                EndIf
                IfEq(LFlag2, FALSE)
                    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_LAKILESTER_THROW_SPINY_A)
                    Set(LFlag2, TRUE)
                Else
                    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_LAKILESTER_THROW_SPINY_B)
                    Set(LFlag2, FALSE)
                EndIf
                Call(N(ThrowSpinyFX))
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_ThrowSpinyAlt)
                Call(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                ChildThread
                    Call(GetActorVar, ACTOR_PARTNER, AVAR_Unk_0, LVar0)
                    Add(LVar0, 1)
                    Call(SetActorVar, ACTOR_PARTNER, AVAR_Unk_0, LVar0)
                    Wait(15)
                    Call(GetActorVar, ACTOR_PARTNER, AVAR_Unk_0, LVar0)
                    Sub(LVar0, 1)
                    Call(SetActorVar, ACTOR_PARTNER, AVAR_Unk_0, LVar0)
                EndChildThread
                Set(LFlag3, TRUE)
                Set(LVar9, 0)
        EndSwitch
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_PARTNER, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Idle)
    Loop(0)
        Call(GetActorVar, ACTOR_PARTNER, AVAR_Unk_0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Wait(10)
    IfEq(LFlag3, FALSE)
        Set(LVar0, 0)
        Set(LVarF, 0)
        Wait(15)
        Goto(13)
    EndIf
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(12)
        EndIf
        Call(GetPartnerActionSuccess, LVarA)
        Call(N(GetSpinySurgeDamage))
        Switch(LVar0)
            CaseGt(0)
                Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_SPINY_SURGE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
            CaseDefault
                Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_SPINY_SURGE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
        EndSwitch
        Switch(LVar0)
            CaseGt(0)
                Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
            CaseDefault
                Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EndSwitch
        Wait(6)
        Label(12)
        Call(ChooseNextTarget, ITER_NEXT, LVar1)
        IfNe(LVar1, ITER_NO_MORE)
            Goto(0)
        EndIf
    Wait(30)
    Label(13)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            ExecWait(N(returnHome2))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(cloudNine_normal) = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetBattleFlagBits, BS_FLAGS1_SHOW_PLAYER_DECORATIONS, FALSE)
    Call(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_NO_INACTIVE_ANIM, TRUE)
    Call(LoadActionCommand, ACTION_COMMAND_WATER_BLOCK)
    Call(action_command_water_block_init, 2)
    Call(SetActionHudPrepareTime, 50)
    Call(InitTargetIterator)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_10)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamOffsetZ, 17)
    Call(SetBattleCamZoom, 300)
    Call(MoveBattleCamOver, 30)
    Call(func_8024EDA4)
    Wait(10)
    Thread
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar1, 40)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    EndThread
    Wait(15)
    Set(LVar0, 0)
    Loop(10)
        Add(LVar0, 18)
        Call(SetActorYaw, ACTOR_PARTNER, LVar0)
        Wait(1)
    EndLoop
    Wait(10)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_CloudNineBegin)
    Wait(5)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_CloudNineIdle)
    Wait(15)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, -12)
    Add(LVar1, 13)
    Add(LVar2, -5)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_FightingStance)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(func_80273444, 18, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_FightingStance)
    Wait(3)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(action_command_water_block_start, 0, 97, 3)
    Call(AddBattleCamZoom, -75)
    Call(MoveBattleCamOver, 100)
    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
    Wait(100)
    Wait(3)
    Call(AddBattleCamZoom, 50)
    Call(MoveBattleCamOver, 5)
    Call(GetPartnerActionSuccess, LVarA)
    IfGt(LVarA, 0)
        Call(N(RemoveCloudNineFX))
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_LAKILESTER_MAKE_CLOUD_NINE)
        Call(N(SpawnCloudNineFX))
        Call(N(ApplyCloudNine))
        Call(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_SHOW_STATUS_ICONS, TRUE)
    EndIf
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_CloudNineEnd)
    Thread
        Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
        Loop(10)
            Set(LVar0, LVar3)
            Set(LVar1, LVar4)
            Set(LVar2, LVar5)
            Call(RandInt, 40, LVar6)
            Sub(LVar6, 20)
            Add(LVar0, LVar6)
            Call(RandInt, 30, LVar6)
            Sub(LVar6, 15)
            Add(LVar1, LVar6)
            PlayEffect(EFFECT_FLOATING_CLOUD_PUFF, 0, LVar0, LVar1, LVar2, Float(1.0), 20, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_FightingStance)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayerFallToGoal, 10)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Walk)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_FightingStance)
    Wait(7)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Thread
        Call(SetGoalToHome, ACTOR_PLAYER)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
        Call(PlayerRunToGoal, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_NO_INACTIVE_ANIM, FALSE)
    EndThread
    Thread
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Sub(LVar1, 40)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    EndThread
    Wait(15)
    Set(LVar0, 180)
    Loop(10)
        Sub(LVar0, 18)
        Call(SetActorYaw, ACTOR_PARTNER, LVar0)
        Wait(1)
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(10)
    IfGt(LVarA, 0)
        Call(ShowMessageBox, BTL_MSG_CLOUD_NINE_BEGIN, 60)
        Call(WaitForMessageBoxDone)
    EndIf
    Call(SetBattleFlagBits, BS_FLAGS1_SHOW_PLAYER_DECORATIONS, TRUE)
    Return
    End
};

EvtScript N(cloudNine_immobile) = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(LoadActionCommand, ACTION_COMMAND_WATER_BLOCK)
    Call(action_command_water_block_init, 2)
    Call(SetActionHudPrepareTime, 50)
    Call(N(RemoveCloudNineFX))
    Call(InitTargetIterator)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_10)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamOffsetZ, 0)
    Call(SetBattleCamZoom, 300)
    Call(MoveBattleCamOver, 30)
    Call(func_8024EDA4)
    Wait(10)
    Set(LVar0, 0)
    Loop(10)
        Add(LVar0, 18)
        Call(SetActorYaw, ACTOR_PARTNER, LVar0)
        Wait(1)
    EndLoop
    Wait(10)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_CloudNineBegin)
    Wait(20)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 12)
    Add(LVar1, -7)
    Add(LVar2, 5)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_PARTNER, 20, -10, EASING_COS_IN_OUT)
    Thread
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 40)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(FlyToGoal, ACTOR_PLAYER, 20, 0, EASING_COS_IN_OUT)
    EndThread
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar1, 40)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_COS_IN_OUT)
    Call(action_command_water_block_start, 0, 97, 3)
    Call(AddBattleCamZoom, -75)
    Call(MoveBattleCamOver, 100)
    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
    Wait(100)
    Wait(3)
    Call(AddBattleCamZoom, 50)
    Call(MoveBattleCamOver, 5)
    Call(GetPartnerActionSuccess, LVarA)
    IfGt(LVarA, 0)
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_LAKILESTER_MAKE_CLOUD_NINE)
        Call(N(SpawnCloudNineFX))
        Call(N(ApplyCloudNine))
    EndIf
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_CloudNineEnd)
    Thread
        Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
        Loop(10)
            Set(LVar0, LVar3)
            Set(LVar1, LVar4)
            Set(LVar2, LVar5)
            Call(RandInt, 40, LVar6)
            Sub(LVar6, 20)
            Add(LVar0, LVar6)
            Call(RandInt, 30, LVar6)
            Sub(LVar6, 15)
            Add(LVar1, LVar6)
            PlayEffect(EFFECT_FLOATING_CLOUD_PUFF, 0, LVar0, LVar1, LVar2, Float(1.0), 20, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(FallToGoal, ACTOR_PLAYER, 10)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Walk)
    Thread
        Call(SetGoalToHome, ACTOR_PLAYER)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
        Call(PlayerRunToGoal, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EndThread
    Thread
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_COS_IN_OUT)
    EndThread
    Set(LVar0, 180)
    Loop(10)
        Sub(LVar0, 18)
        Call(SetActorYaw, ACTOR_PARTNER, LVar0)
        Wait(1)
    EndLoop
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(10)
    IfGt(LVarA, 0)
        Call(ShowMessageBox, BTL_MSG_CLOUD_NINE_BEGIN, 60)
        Call(WaitForMessageBoxDone)
    EndIf
    Return
    End
};

EvtScript N(EVS_Move_CloudNine) = {
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
        ExecWait(N(cloudNine_immobile))
    Else
        ExecWait(N(cloudNine_normal))
    EndIf
    Return
    End
};

enum {
    STATE_INHALE   = -1,
    STATE_DISABLED =  0,
    STATE_EXHALE   =  1,
};

#if VERSION_PAL
#define HURRICANE_PARTNER_MOVE_TIME 140
#define HURRICANE_UNUSED_TIME 152
#else
#define HURRICANE_PARTNER_MOVE_TIME 165
#define HURRICANE_UNUSED_TIME 177
#endif

API_CALLABLE(N(ProcessHurricane)) {
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
            partner->state.moveTime = HURRICANE_PARTNER_MOVE_TIME;
            partner->state.moveArcAmplitude = 0;
            sIsHurricaneActive = TRUE;
            D_8023D338 = 255;
            sHuffPuffBreathEffect = effect = fx_huff_puff_breath(0, NPC_DISPOSE_LOCATION, 0.0f, -2.0f, 0.6f, 0);

            effect->data.huffPuffBreath->primCol.r = 20;
            effect->data.huffPuffBreath->primCol.g = 80;
            effect->data.huffPuffBreath->primCol.b = 255;

            effect->data.huffPuffBreath->envCol.r = 200;
            effect->data.huffPuffBreath->envCol.g = 240;
            effect->data.huffPuffBreath->envCol.b = 240;

            hurricaneState->unk_54 = HURRICANE_UNUSED_TIME;
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
    x = partner->curPos.x;
    y = partner->curPos.y;
    rand_int(1000);
    tempF1 = 5.0f;
    switch (sHuffPuffBreathState) {
        case STATE_INHALE:
            x = partner->curPos.x;
            y = partner->curPos.y + 15.0f;
            z = partner->curPos.z + tempF1;
            add_vec2D_polar(&x, &y, 12.0f, 90.0f);
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.x = x;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.y = y;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.z = z;
            sHuffPuffBreathEffect->data.huffPuffBreath->speedX = -2.0f;

            // looks like this was breath inhale phase, but then the devs removed it
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.x = NPC_DISPOSE_POS_X;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.y = NPC_DISPOSE_POS_Y;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.z = NPC_DISPOSE_POS_Z;

            if (script->functionTemp[2] != 0) {
                sfx_play_sound_at_position(SOUND_LAKILESTER_HURRICANE_INHALE, SOUND_SPACE_DEFAULT, partner->curPos.x, partner->curPos.y, partner->curPos.z);
            }
            script->functionTemp[2] = 0;

            partnerState->moveArcAmplitude = 0;
            set_actor_anim(ACTOR_PARTNER, -1, ANIM_BattleLakilester_HurricaneInhale);
            break;
        case STATE_DISABLED:
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.x = NPC_DISPOSE_POS_X;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.y = NPC_DISPOSE_POS_Y;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.z = NPC_DISPOSE_POS_Z;
            break;
        case STATE_EXHALE:
            x = partner->curPos.x;
            y = partner->curPos.y + 15.0f;
            z = partner->curPos.z + tempF1;
            add_vec2D_polar(&x, &y, 12.0f, 90.0f);
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.x = x;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.y = y;
            sHuffPuffBreathEffect->data.huffPuffBreath->pos.z = z;
            sHuffPuffBreathEffect->data.huffPuffBreath->speedX = 2.0f;

            if (script->functionTemp[2] == 0) {
                sfx_play_sound_at_position(SOUND_LAKILESTER_HURRICANE_EXHALE, SOUND_SPACE_DEFAULT, partner->curPos.x, partner->curPos.y, partner->curPos.z);
            }
            script->functionTemp[2] = 1;

            if (partnerState->moveArcAmplitude == 0) {
                script->functionTemp[1] = 1;
            }
            partnerState->moveArcAmplitude = 1;

            set_actor_anim(ACTOR_PARTNER, -1, ANIM_BattleLakilester_HurricaneExhale);
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

API_CALLABLE(N(BlowTargetAway)) {
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
            target->state.curPos.x = target->curPos.x;
            target->state.curPos.y = target->curPos.y;
            target->state.curPos.z = target->curPos.z;
            target->state.speed = 5.5f;
            sNumEnemiesBeingBlown += 1;
            battleStatus->curAttackElement = 0;
            dispatch_event_actor(target, EVENT_BLOW_AWAY);
            script->functionTemp[0] = 1;
            break;
        case 1:
            target->state.curPos.x += target->state.speed;
            temp_f20 = target->state.curPos.y;
            target->state.curPos.y =
                temp_f20 + ((sin_rad(2.0f * sin_rad(DEG_TO_RAD(target->state.moveTime)) * PI_S) * 1.4) + 0.5);
            target->state.moveTime += 6;
            target->state.moveTime = clamp_angle(target->state.moveTime);
            target->yaw += 33.0f;
            target->yaw = clamp_angle(target->yaw);
            if (target->state.curPos.x > 240.0f) {
                sNumEnemiesBeingBlown -= 1;
                return ApiStatus_DONE2;
            }
            break;
    }
    target->curPos.x = state->curPos.x;
    target->curPos.y = state->curPos.y;
    target->curPos.z = state->curPos.z;
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(AllEnemiesBlownAway)) {
    if (sNumEnemiesBeingBlown == 0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(IsHurricaneActive)) {
    script->varTable[0] = sIsHurricaneActive;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Move_Hurricane) = {
    Call(LoadActionCommand, ACTION_COMMAND_HURRICANE)
    Call(action_command_hurricane_init)
    Call(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    Call(SetActionHudPrepareTime, 15)
    Call(SetDamageSource, DMG_SRC_HURRICANE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, -45, 54, 0)
    Call(SetBattleCamOffsetZ, 0)
    Call(SetBattleCamZoom, 280)
    Call(MoveBattleCamOver, 40)
    Call(InitTargetIterator)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Run)
    Call(AddGoalPos, ACTOR_PARTNER, 40, 20, 0)
    Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Idle)
    Wait(15)
    Call(N(InitHurricane))
    Call(action_command_hurricane_start, 0, 147 * DT, 3, LVar0)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 20, 0)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, 35, 54, 0)
    Call(SetBattleCamOffsetZ, 0)
    Call(SetBattleCamZoom, 430)
    Call(MoveBattleCamOver, 150 * DT)
    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_LAKILESTER_HURRICANE_WIND)
    Thread
        Call(N(ProcessHurricane))
    EndThread
    Wait(2)
    Loop(150 * DT)
        Call(N(IsHurricaneActive))
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Call(GetActionSuccessCopy, LVar0)
        IfEq(LVar0, 100)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Wait(15)
    Call(GetActionSuccessCopy, LVar0)
    Switch(LVar0)
        CaseGt(99)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
        CaseDefault
            Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EndSwitch
    Call(InitTargetIterator)
    Label(10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(N(CanTargetBeBlown))
    IfGt(LVar0, 0)
        Set(LVarA, LVar0)
        Thread
            Call(N(BlowTargetAway))
            Call(SetBattleFlagBits, BS_FLAGS1_STAR_POINTS_DROPPED, TRUE)
            Call(RemoveActor, LVarA)
        EndThread
    Else
        IfEq(LVar0, 0)
            Call(PartnerDamageEnemy, LVar2, DAMAGE_TYPE_NO_CONTACT, 0, 0, 0, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_FORCE_IMMUNE_HIT)
        EndIf
    EndIf
    Label(11)
    Call(ChooseNextTarget, ITER_NEXT, LVar0)
    IfNe(LVar0, ITER_NO_MORE)
        Goto(10)
    EndIf
    Wait(34)
    Call(SetActorRotation, ACTOR_PARTNER, 0, 0, 0)
    Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    ExecWait(N(EVS_ReturnHome))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleLakilester_Walk)
    Call(N(AllEnemiesBlownAway))
    Call(PartnerYieldTurn)
    Return
    End
};

MATCHING_BSS(0xCC0);
