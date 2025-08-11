#include "../area.h"
#include "sprite.h"
#include "sprite/npc/BigLanternGhost.h"

#define NAMESPACE A(big_lantern_ghost)

extern s32 N(DefaultAnims)[];

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(updateEffectThread);
extern EvtScript N(setGhostNoTarget);
extern EvtScript N(onHit);
extern EvtScript N(checkExtinguish);
extern EvtScript N(onDeath);
extern EvtScript N(EVS_ReturnHome);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
};

enum N(ActorVars) {
    N(VAR_LANTERN_BRIGHTNESS)   = 0,
    N(VAR_DARKENING)            = 1,
    N(VAR_LANTERN_X)            = 2,
    N(VAR_LANTERN_Y)            = 3,
    N(VAR_LANTERN_Z)            = 4,
    N(VAR_EXTINGUISHED_ONCE)    = 5,
    N(VAR_6)                    = 6,
    N(VAR_SPEAK_FLAGS)          = 7,
    N(VAR_EFFECT)               = 10,
    N(VAR_MOVE_ID)              = 11,
    N(VAR_LIGHT_BEAM_COUNTER)   = 12,
    N(VAR_HIT_SOUND_COUNTER)    = 13,
};

enum N(MoveIds) {
    N(MOVE_HEAVY_JUMP) = 0,
    N(MOVE_EXTINGUISH) = 1,
    N(MOVE_LIGHT_BEAM) = 2,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(defenseTable2)[] = {
    ELEMENT_NORMAL,  99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           60,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,               60,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 54 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_DAMAGE_IMMUNE,
        .index = PRT_2,
        .posOffset = { -40, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -9 },
        .overrideNameMsg = MSG_EnemyName_Lantern,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BIG_LANTERN_GHOST,
    .level = ACTOR_LEVEL_BIG_LANTERN_GHOST,
    .maxHP = 40,
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
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 86, 60 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -30, 55 },
    .statusTextOffset = { 20, 45 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BigLanternGhost_Anim01,
    STATUS_KEY_STONE,     ANIM_BigLanternGhost_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BigLanternGhost_Anim0C,
    STATUS_KEY_POISON,    ANIM_BigLanternGhost_Anim01,
    STATUS_KEY_STOP,      ANIM_BigLanternGhost_Anim00,
    STATUS_KEY_STATIC,    ANIM_BigLanternGhost_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_BigLanternGhost_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_BigLanternGhost_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BigLanternGhost_Anim0D,
    STATUS_KEY_FEAR,      ANIM_BigLanternGhost_Anim0D,
    STATUS_END,
};

API_CALLABLE(N(init_overlay)) {
    get_actor(script->owner1.actorID);

    set_screen_overlay_params_back(OVERLAY_BATTLE_DARKNESS, 220.0f);
    set_screen_overlay_alpha(SCREEN_LAYER_BACK, 200.0f);
    return ApiStatus_DONE2;
}

s32 N(get_darkening)(ActorState* actorState, s32 targetDarkening) {
    s32 delta = targetDarkening - actorState->varTable[N(VAR_DARKENING)];

    if (delta >= 4) {
        actorState->varTable[N(VAR_DARKENING)] += 4;
    } else if (delta >= -4) {
        actorState->varTable[N(VAR_DARKENING)] = targetDarkening;
    } else {
        actorState->varTable[N(VAR_DARKENING)] -= 4;
    }

    return actorState->varTable[N(VAR_DARKENING)];
}

API_CALLABLE(N(update_effect)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);
    Actor* actor = get_actor(script->owner1.actorID);
    ActorState* actorState;
    ActorPart* actorPart;
    BulbGlowFXData* effectData;
    s32 partX, partY, partZ;
    f32 posX, posY, posZ;
    f32 rotX, rotY, rotZ;
    f32 yaw;
    f32 f24, f22;
    s32 opacity;
    s32 compListIdx;

    if (actor == nullptr) {
        set_screen_overlay_alpha(SCREEN_LAYER_BACK, 0.0f);
        return ApiStatus_BLOCK;
    }

    actorState = &actor->state;
    if (effect != nullptr) {
        effectData = effect->data.bulbGlow;
    }

    posX = actor->curPos.x;
    posY = actor->curPos.y;
    posZ = actor->curPos.z;

    rotX = actor->rot.x;
    rotY = actor->rot.y + actor->yaw;
    rotZ = actor->rot.z;

    actorPart = get_actor_part(actor, 1);
    if (actorPart->curAnimation == ANIM_BigLanternGhost_Anim0C) {
        spr_get_comp_position(actor->partsTable->spriteInstanceID, 0, &partX, &partY, &partZ);
    } else {
        spr_get_comp_position(actor->partsTable->spriteInstanceID, 1, &partX, &partY, &partZ);
    }

    partY += 20;

    f24 = (f32)partX * SPRITE_WORLD_SCALE_D;
    f22 = (f32)partY * SPRITE_WORLD_SCALE_D;

    f24 *= cos_deg(rotY);
    f22 *= sin_deg(rotX + 90.0);

    partX = f24 * cos_deg(rotZ) + f22 * sin_deg(rotZ);
    partY = f24 * -sin_deg(rotZ) + f22 * cos_deg(rotZ);

    switch (actorState->varTable[N(VAR_LANTERN_BRIGHTNESS)]) {
        case 0:
            opacity = N(get_darkening)(actorState, 290);
            break;
        case 1:
            opacity = N(get_darkening)(actorState, 250) + (rand_int(0x4000) % 5);
            break;
        case 2:
            opacity = N(get_darkening)(actorState, 240) + (rand_int(0x4000) % 5);
            break;
        case 3:
            opacity = N(get_darkening)(actorState, 230) + (rand_int(0x4000) % 5);
            break;
        case 4:
            opacity = N(get_darkening)(actorState, 220) + (rand_int(0x4000) % 5);
            break;
        case 5:
            opacity = N(get_darkening)(actorState, 210) + (rand_int(0x4000) % 5);
            break;
        case 6:
            opacity = N(get_darkening)(actorState, 180) + (rand_int(0x4000) % 5);
            break;
        case 7:
            opacity = N(get_darkening)(actorState, 140) + (rand_int(0x4000) % 5);
            break;
        case 8:
            opacity = N(get_darkening)(actorState, 100) + (rand_int(0x4000) % 5);
            break;
        case 9:
            opacity = N(get_darkening)(actorState, 70) + (rand_int(0x4000) % 5);
            break;
        case 10:
            opacity = N(get_darkening)(actorState, 40) + (rand_int(0x4000) % 5);
            break;
        case 11:
            opacity = N(get_darkening)(actorState, 20);
            opacity = N(get_darkening)(actorState, 20);
            opacity = N(get_darkening)(actorState, 20);
            break;
        default:
            opacity = 0;
            break;
    }

    set_screen_overlay_alpha(SCREEN_LAYER_BACK, opacity);
    set_screen_overlay_center_worldpos(SCREEN_LAYER_BACK, 0, posX + partX, posY + partY, posZ + partZ);

    actorState->varTable[N(VAR_LANTERN_X)] = posX + partX;
    actorState->varTable[N(VAR_LANTERN_Y)] = posY + partY;
    actorState->varTable[N(VAR_LANTERN_Z)] = posZ + partZ;

    actorPart = get_actor_part(actor, 2);
    actorPart->partOffset.x = partX - 5;
    actorPart->partOffset.y = partY + 5;

    if (effect != nullptr) {
        effectData->pos.x = actorState->varTable[N(VAR_LANTERN_X)];
        effectData->pos.y = actorState->varTable[N(VAR_LANTERN_Y)];
        effectData->pos.z = actorState->varTable[N(VAR_LANTERN_Z)] + 25;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, N(VAR_EXTINGUISHED_ONCE), 0)
    Call(SetActorVar, ACTOR_SELF, N(VAR_6), 10)
    Call(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), 2)
    Call(SetActorVar, ACTOR_SELF, N(VAR_DARKENING), 240)
    Call(SetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), 0)
    Call(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_HEAVY_JUMP))
    Call(SetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), 0)
    PlayEffect(EFFECT_BULB_GLOW, 1, LVar0, LVar1, LVar2, Float(1.0), LVar0, 0)
    Call(SetActorVar, ACTOR_SELF, N(VAR_EFFECT), LVar0)
    Call(N(init_overlay))
    Exec(N(updateEffectThread))
    ExecWait(N(setGhostNoTarget))
    Wait(2)
    Call(SetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 0)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), LVar0)
            IfNotFlag(LVar0, 1)
                BitwiseOrConst(LVar0, 1)
                Call(SetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), LVar0)
                Call(UseBattleCamPreset, BTL_CAM_ACTOR)
                Call(BattleCamTargetActor, ACTOR_SELF)
                Call(SetBattleCamOffsetY, 40)
                Call(MoveBattleCamOver, 30)
                Wait(30)
                Call(ActorSpeak, MSG_CH4_0051, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EndIf
        CaseEq(PHASE_ENEMY_BEGIN)
    EndSwitch
    Return
    End
};

EvtScript N(updateEffectThread) = {
    SetPriority(99)
    Label(0)
    Call(ActorExists, ACTOR_SELF, LVar0)
    IfNe(LVar0, 0)
        Call(GetActorVar, ACTOR_SELF, N(VAR_EFFECT), LVar0)
    Else
        Set(LVar0, 0)
    EndIf
    Call(N(update_effect), LVar0)
    Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
    Call(ActorExists, ACTOR_ENEMY0, LVar0)
    IfNe(LVar0, 0)
        Wait(1)
        Goto(0)
    EndIf
    Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            ExecWait(N(onHit))
            ExecWait(N(checkExtinguish))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            ExecWait(N(onHit))
            ExecWait(N(checkExtinguish))
            Set(LVar0, 1)
            Set(LVar1, 7143434)
            Set(LVar2, 7143435)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            ExecWait(N(onHit))
            Set(LVar0, 1)
            Set(LVar1, 7143434)
            Set(LVar2, 7143435)
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim0B)
            ExecWait(N(onDeath))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            ExecWait(N(onHit))
            ExecWait(N(checkExtinguish))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(N(onDeath))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            ExecWait(N(onHit))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            ExecWait(N(onHit))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(N(onDeath))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(func_8026E914, LVar0, LVar1)
            IfEq(LVar1, 2)
                Call(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar2)
                IfLt(LVar2, 10)
                    Add(LVar2, 2)
                    Call(GetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), LVar0)
                    Switch(LVar0)
                        CaseEq(0)
                            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_REVEAL_MORE_1)
                            Call(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        CaseEq(1)
                            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_REVEAL_MORE_2)
                            Call(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        CaseEq(2)
                            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_REVEAL_MORE_3)
                            Call(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        CaseEq(3)
                            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_REVEAL_MORE_4)
                            Call(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        CaseDefault
                    EndSwitch
                    IfGt(LVar2, 10)
                        Set(LVar2, 10)
                    EndIf
                    Call(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar2)
                    ExecWait(N(setGhostNoTarget))
                    Call(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar0)
                    IfGe(LVar0, 6)
                        ExecWait(N(checkExtinguish))
                    EndIf
                EndIf
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_SPIKE_TAUNT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(N(onDeath))
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            ExecWait(N(EVS_ReturnHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim09)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BigLanternGhost_Anim01)
            SetConst(LVar2, ANIM_BigLanternGhost_Anim09)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(onHit) = {
    Call(func_8026E914, LVar0, LVar1)
    IfNe(LVar1, 1)
        Return
    EndIf
    Call(GetLastDamage, ACTOR_SELF, LVar1)
    Mul(LVar1, 10)
    Call(GetActorVar, ACTOR_SELF, N(VAR_6), LVar0)
    Add(LVar0, LVar1)
    Call(SetActorVar, ACTOR_SELF, N(VAR_6), LVar0)
    Return
    End
};

EvtScript N(checkExtinguish) = {
    Call(GetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), LVar0)
    IfNe(LVar0, N(MOVE_LIGHT_BEAM))
        Call(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_EXTINGUISH))
    EndIf
    Return
    End
};

EvtScript N(attackHeavyJump) = {
    Call(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar0)
    IfGe(LVar0, 6)
        ExecWait(N(checkExtinguish))
    EndIf
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamDist, 260)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim06)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
    Wait(8)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_LARGE_ACTOR_JUMP, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim10)
            Thread
                Wait(10)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim11)
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_STEP)
            Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            Sub(LVar0, 15)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 12, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
            Sub(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_STEP)
            Wait(8)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            ExecWait(N(EVS_ReturnHome))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim10)
    Thread
        Wait(7)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim11)
    EndThread
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(JumpToGoal, ACTOR_SELF, 16, false, true, false)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 5, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_STEP)
            Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
            Call(SetBattleCamDist, 320)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(MoveBattleCamOver, 20)
            Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
            Thread
                Wait(5)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim10)
            EndThread
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 12, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_STEP)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_STEP)
            Wait(8)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(attackLightBeam) = {
    Call(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_HEAVY_JUMP))
    Call(SetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), 3)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
    Call(SetBattleCamDist, 240)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 80)
    Set(LVar1, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim06)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_TARGET_MIDPOINT)
    Call(SetBattleCamDist, 350)
    Call(SetBattleCamOffsetY, 35)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_LIGHT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim0F)
    Call(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar5)
    Call(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), 11)
    Call(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_X), LVar0)
    Call(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_Y), LVar1)
    Call(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_Z), LVar2)
    Add(LVar1, 10)
    Add(LVar2, 2)
    Thread
        Wait(1)
        PlayEffect(EFFECT_LIGHT_RAYS, 2, LVar0, LVar1, LVar2, Float(1.0), LVarB, 0)
        Wait(30)
        Call(RemoveEffect, LVarB)
    EndThread
    Thread
        Wait(1)
        PlayEffect(EFFECT_RADIATING_ENERGY_ORB, 1, LVar0, LVar1, LVar2, Float(1.5), 30, 0)
    EndThread
    Wait(5)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            Switch(LVarA)
                CaseEq(HIT_RESULT_MISS)
                CaseDefault
                    Call(ActorExists, ACTOR_PARTNER, LVar0)
                    IfEq(LVar0, 1)
                        Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                        Call(SetGoalToTarget, ACTOR_SELF)
                        Call(EnemyDamageTarget, ACTOR_SELF, LVarD, 0, SUPPRESS_EVENT_ALL, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
                    EndIf
            EndSwitch
        EndCaseGroup
        CaseDefault
            Wait(2)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(EnemyDamageTarget, ACTOR_SELF, LVarE, DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
            Wait(2)
            Call(ActorExists, ACTOR_PARTNER, LVar0)
            IfEq(LVar0, 1)
                Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(EnemyDamageTarget, ACTOR_SELF, LVarD, DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
            EndIf
    EndSwitch
    Wait(40)
    Call(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar5)
    Thread
        Call(GetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), LVar0)
        Wait(10)
        Switch(LVar0)
            CaseEq(0)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_4)
            CaseEq(1)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_3)
            CaseEq(2)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_2)
            CaseEq(3)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_1)
        EndSwitch
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim14)
    Wait(60)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ExecWait(N(EVS_ReturnHome))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(extinguish) = {
    Call(SetActorVar, ACTOR_SELF, N(VAR_EXTINGUISHED_ONCE), 1)
    Call(SetActorVar, ACTOR_SELF, N(VAR_6), 1000)
    Call(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_LIGHT_BEAM))
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), LVar0)
    IfNotFlag(LVar0, 2)
        BitwiseOrConst(LVar0, 2)
        Call(SetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), LVar0)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR)
        Call(SetBattleCamOffsetY, 40)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 30)
        Wait(30)
        Call(GetEnemyMaxHP, ACTOR_SELF, LVar0)
        Call(GetActorHP, ACTOR_SELF, LVar1)
        IfEq(LVar0, LVar1)
            Call(ActorSpeak, MSG_CH4_0053, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01)
        Else
            Call(ActorSpeak, MSG_CH4_0052, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01)
        EndIf
    EndIf
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
    Call(SetBattleCamDist, 230)
    Call(SetBattleCamOffsetY, 25)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Wait(20)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_INHALE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim0F)
    Wait(8)
    Thread
        Wait(2)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_BLOW)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim0E)
    Wait(5)
    Call(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), 2)
    Thread
        Call(GetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), LVar0)
        Call(SetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 0)
        Wait(10)
        Switch(LVar0)
            CaseEq(4)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_4)
            CaseEq(3)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_3)
            CaseEq(2)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_2)
            CaseEq(1)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_1)
        EndSwitch
    EndThread
    Wait(14)
    Wait(1)
    Wait(15)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
    ExecWait(N(setGhostNoTarget))
    Wait(30)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), LVar0)
    IfGt(LVar0, 0)
        Sub(LVar0, 1)
        Call(SetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), LVar0)
    EndIf
    Call(GetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), LVar0)
    Switch(LVar0)
        CaseEq(N(MOVE_LIGHT_BEAM))
            Call(GetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), LVar0)
            IfGt(LVar0, 0)
                Call(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_HEAVY_JUMP))
            EndIf
        CaseEq(N(MOVE_EXTINGUISH))
            Call(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar0)
            IfLt(LVar0, 6)
                Call(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_HEAVY_JUMP))
            EndIf
    EndSwitch
    Call(GetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), LVar0)
    Switch(LVar0)
        CaseEq(N(MOVE_LIGHT_BEAM))
            ExecWait(N(attackLightBeam))
        CaseEq(N(MOVE_EXTINGUISH))
            ExecWait(N(extinguish))
        CaseDefault
            ExecWait(N(attackHeavyJump))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BigLanternGhost_Anim07)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
    Return
    End
};

EvtScript N(setGhostNoTarget) = {
    Call(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar0)
    Switch(LVar0)
        CaseLt(5)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, true)
        CaseLt(8)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, false)
        CaseDefault
            Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, false)
    EndSwitch
    Return
    End
};

EvtScript N(onDeath) = {
    ExecWait(EVS_Enemy_DeathWithoutRemove)
    Call(GetActorVar, ACTOR_SELF, N(VAR_EFFECT), LVar0)
    Call(RemoveEffect, LVar0)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};
