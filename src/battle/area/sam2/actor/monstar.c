#include "../area.h"
#include "sprite.h"
#include "sprite/npc/Monstar.h"
#include "battle/area/sam2/actor/img.png.h"

#define NAMESPACE A(monstar)

extern Gfx N(dlist)[];

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_BurnHit);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_Charged        = 0, // EVS_ChargeUp; never set TRUE
    AVAR_HoverPaused    = 1,
    AVAR_TurnCount      = 3,
};

enum N(ActorParams) {
    DMG_STAR_STORM      = 1,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_COSMIC,  99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
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
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_MONSTAR,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, -15 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { -6, 20 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_MONSTAR,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, -15 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_MONSTAR,
    .level = ACTOR_LEVEL_MONSTAR,
    .maxHP = 20,
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
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 100, 98 },
    .healthBarOffset = { 0, 16 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Monstar_Idle1,
    STATUS_KEY_STONE,     ANIM_Monstar_Still,
    STATUS_KEY_SLEEP,     ANIM_Monstar_Idle1,
    STATUS_KEY_POISON,    ANIM_Monstar_Idle1,
    STATUS_KEY_STOP,      ANIM_Monstar_Still,
    STATUS_KEY_STATIC,    ANIM_Monstar_Idle1,
    STATUS_KEY_PARALYZE,  ANIM_Monstar_Still,
    STATUS_KEY_PARALYZE,  ANIM_Monstar_Still,
    STATUS_KEY_DIZZY,     ANIM_Monstar_Idle1,
    STATUS_KEY_DIZZY,     ANIM_Monstar_Idle1,
    STATUS_END,
};

s32 N(ChargedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Monstar_GatherStrength1,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Charged, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnCount, 0)
    EVT_RETURN
    EVT_END
};

#include "battle/area/sam2/actor/img.png.inc.c"
#include "battle/area/sam2/actor/img.pal.inc.c"

ImgFXOverlayTexture N(MonstarDetailTexture) = {
    .raster = battle_area_sam2_actor_img_png,
    .palette = battle_area_sam2_actor_img_pal,
    .width = battle_area_sam2_actor_img_png_width,
    .height = battle_area_sam2_actor_img_png_height,
    .offsetX = -4,
    .offsetY = 0,
    .displayList = N(dlist),
};

API_CALLABLE(N(UpdateMonstarImgFX)) {
    ActorPart* part = get_actor_part(get_actor(script->owner1.actorID), 1);
    s32 i;
    u8 colR[20];
    u8 colG[20];
    u8 colB[20];
    u8 colA[20];

    if (isInitialCall) {
        script->functionTemp[1] = 0;
        script->functionTemp[2] = 0;
        script->functionTemp[0] = 0;
        set_npc_imgfx_comp(part->spriteInstanceID, 0, IMGFX_ALLOC_COLOR_BUF, 20, 0, 0, 255, 0);
    }

    set_npc_imgfx_comp(part->spriteInstanceID, 1, IMGFX_OVERLAY, (s32)&N(MonstarDetailTexture), 255, 0, 255, 0);
    script->functionTemp[1] += 10;
    if (script->functionTemp[1] >= 360) {
        script->functionTemp[1] %= 360;
    }

    for (i = 0; i < 20; i++) {
        colR[i] = (cosine(script->functionTemp[1] + i * 25) + 1.0) * 56.0;
        colG[i] = (cosine(script->functionTemp[1] + i * 25 + 45) + 1.0) * 56.0;
        colB[i] = (cosine(script->functionTemp[1] + i * 25 + 90) + 1.0) * 56.0;
    }

    for (i = 0; i < 20; i++) {
        set_npc_imgfx_comp(part->spriteInstanceID, 0, IMGFX_COLOR_BUF_SET_MODULATE, i, colR[i] << 0x18 | colG[i] << 0x10 | colB[i] << 8 | 255, 0, 255, 0);
    }

    return ApiStatus_BLOCK;
}

#include "common/Dist3D.inc.c"

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_Idle) = {
    EVT_CHILD_THREAD
        EVT_CALL(N(UpdateMonstarImgFX))
    EVT_END_CHILD_THREAD
    EVT_LABEL(0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
        EVT_CALL(MakeLerp, 0, 10, 30, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_ADD(LVar0, LVar3)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar2, LVar0, LVar4)
            EVT_LABEL(2)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HoverPaused, LVar5)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar5, 1)
                    EVT_GOTO(2)
                EVT_END_IF
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
        EVT_CALL(MakeLerp, 0, -10, 30, EASING_COS_IN_OUT)
        EVT_LABEL(3)
            EVT_CALL(UpdateLerp)
            EVT_ADD(LVar0, LVar3)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar2, LVar0, LVar4)
            EVT_LABEL(4)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HoverPaused, LVar5)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar5, 1)
                    EVT_GOTO(4)
                EVT_END_IF
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(3)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, TRUE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Monstar_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_Monstar_Hurt)
            EVT_SET(LVar2, -1)
            EVT_EXEC_WAIT(N(EVS_BurnHit))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_Monstar_Hurt)
            EVT_SET(LVar2, -1)
            EVT_EXEC_WAIT(N(EVS_BurnHit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Monstar_Hurt)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Monstar_Idle1)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Monstar_GatherStrength1)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Monstar_Idle1)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Monstar_GatherStrength1)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Monstar_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Monstar_Hurt)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Monstar_Idle1)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Monstar_Idle1)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Monstar_GatherStrength1)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Monstar_Idle1)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Monstar_GatherStrength1)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

// unused
EvtScript N(EVS_ChargeUp) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, TRUE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(SetBattleCamZoom, 10)
    EVT_CALL(SetBattleCamOffsetZ, 5)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_GatherStrength1)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ChargedAnims)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 40)
    EVT_SUB(LVar2, 5)
    EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 10, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 300, 0)
    EVT_WAIT(75)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_StarStorm) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, TRUE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 250)
    EVT_CALL(SetBattleCamOffsetZ, 55)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_GatherStrength1)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_GatherStrength2)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_GatherStrength3)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(UnkBackgroundFunc3))
        EVT_CALL(MakeLerp, 0, 200, 60, EASING_QUADRATIC_IN)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetBackgroundAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    EVT_CALL(N(StartRumbleWithParams), 80, 120)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 100)
    EVT_CALL(SetBattleCamOffsetZ, 60)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_WAIT(60)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MONSTAR_CAST_SPELL)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MONSTAR_STAR_STORM)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(18)
            EVT_CALL(RandInt, 150, LVar0)
            EVT_ADD(LVar0, 100)
            EVT_CALL(N(StartRumbleWithParams), LVar0, 20)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(60)
            // choose from FX_STAR_BACKGROUND to FX_STAR_SMALL_BOUNCING
            EVT_CALL(RandInt, 1, LVar0)
            EVT_ADD(LVar0, 2)
            EVT_CALL(RandInt, 400, LVar1)
            EVT_SUB(LVar1, 100)
            EVT_CALL(RandInt, 100, LVar2)
            EVT_SUB(LVar2, 50)
            EVT_SET(LVar3, LVar1)
            EVT_SUB(LVar3, 200)
            EVT_SET(LVar4, LVar2)
            EVT_CALL(RandInt, 10, LVar5)
            EVT_ADD(LVar5, 10)
            EVT_PLAY_EFFECT(EFFECT_STAR, LVar0, LVar1, 240, LVar2, LVar3, 0, LVar4, LVar5, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(8)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 5)
    EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 11, LVar0, LVar1, LVar2, EVT_FLOAT(0.8), 160, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Release)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(170)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Idle1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
            EVT_CALL(MakeLerp, 200, 0, 60, EASING_LINEAR)
            EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetBackgroundAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, FALSE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(170)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_STAR_STORM, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Idle1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
            EVT_CALL(MakeLerp, 200, 0, 60, EASING_LINEAR)
            EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetBackgroundAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_EXEC_WAIT(N(EVS_Attack_StarStorm))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 72)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 340)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(ActorSpeak, MSG_CH7_00E5, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Talk, ANIM_Monstar_Talk)
        EVT_CASE_EQ(1)
            EVT_CALL(ActorSpeak, MSG_CH7_00E6, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Talk, ANIM_Monstar_Talk)
        EVT_CASE_EQ(2)
            EVT_CALL(ActorSpeak, MSG_CH7_00E7, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Talk, ANIM_Monstar_Talk)
        EVT_CASE_DEFAULT
            EVT_CALL(ActorSpeak, MSG_CH7_00E6, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Talk, ANIM_Monstar_Talk)
    EVT_END_SWITCH
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_TurnCount, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Death) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_IF_NE(LVar1, -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(GetDamageSource, LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_SPIN_SMASH)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LFlag0, FALSE)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar1)
            EVT_SWITCH(LVar1)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOB_OMB)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BULLET_BILL)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOMBSHELL_BILL)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
            EVT_IF_NE(LVar2, EXEC_DEATH_NO_SPINNING)
                EVT_SET(LVar2, 0)
                EVT_LOOP(24)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
                    EVT_ADD(LVar2, 30)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 10)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SET(LVar3, 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        EVT_ADD(LVar3, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_EXEC_WAIT(EVS_ForceNextTarget)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BurnHit) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetDamageSource, LVar3)
    EVT_SWITCH(LVar3)
        EVT_CASE_EQ(DMG_SRC_FIRE_SHELL)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar7)
            EVT_SWITCH(LVar7)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
                    EVT_ADD(LVar5, 55)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, FALSE, FALSE)
            EVT_END_SWITCH
            EVT_SET(LVar7, 0)
            EVT_LOOP(30)
                EVT_ADD(LVar7, 48)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar7)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar7)
            EVT_SWITCH(LVar7)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SUB(LVar5, 55)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
                    EVT_IF_EQ(LVar5, 0)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_ELSE
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_WAIT(20)
    EVT_END_SWITCH
    EVT_IF_NE(LVar2, -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar2)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetPartEventFlags, ACTOR_SELF, LVar0, LVar1)
            EVT_IF_NOT_FLAG(LVar1, ACTOR_EVENT_FLAG_FIREY | ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_MULF(LVar3, EVT_FLOAT(0.4))
                    EVT_MULF(LVar4, EVT_FLOAT(0.4))
                EVT_END_IF
                EVT_DIVF(LVar3, EVT_FLOAT(2.0))
                EVT_CALL(GetActorFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, ACTOR_FLAG_UPSIDE_DOWN)
                    EVT_SUBF(LVar1, LVar3)
                EVT_ELSE
                    EVT_ADDF(LVar1, LVar3)
                EVT_END_IF
                EVT_ADDF(LVar2, EVT_FLOAT(5.0))
                EVT_DIVF(LVar3, EVT_FLOAT(10.0))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_MULF(LVar3, EVT_FLOAT(0.4))
                    EVT_IF_LT(LVar3, 1)
                        EVT_SETF(LVar3, EVT_FLOAT(1.0))
                    EVT_END_IF
                EVT_END_IF
                EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            // do nothing
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
