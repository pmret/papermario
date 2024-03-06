#include "../area.h"
#include "sprite.h"
#include "sprite/npc/Monstar.h"
#include "battle/area/sam2/actor/img.png.h"
#include "include_asset.h"

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
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Charged, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnCount, 0)
    Return
    End
};

INCLUDE_IMG("battle/area/sam2/actor/img.png", battle_area_sam2_actor_img_png);
INCLUDE_PAL("battle/area/sam2/actor/img.pal", battle_area_sam2_actor_img_pal);

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
    #define RGBA_BUF_SIZE 20
    ActorPart* part = get_actor_part(get_actor(script->owner1.actorID), 1);
    s32 i;
    u8 colR[RGBA_BUF_SIZE];
    u8 colG[RGBA_BUF_SIZE];
    u8 colB[RGBA_BUF_SIZE];
    u8 colA[RGBA_BUF_SIZE];

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

    for (i = 0; i < RGBA_BUF_SIZE; i++) {
        colR[i] = (cosine(script->functionTemp[1] + i * 25) + 1.0) * 56.0;
        colG[i] = (cosine(script->functionTemp[1] + i * 25 + 45) + 1.0) * 56.0;
        colB[i] = (cosine(script->functionTemp[1] + i * 25 + 90) + 1.0) * 56.0;
    }

    for (i = 0; i < RGBA_BUF_SIZE; i++) {
        set_npc_imgfx_comp(part->spriteInstanceID, 0, IMGFX_COLOR_BUF_SET_MODULATE, i, colR[i] << 0x18 | colG[i] << 0x10 | colB[i] << 8 | 255, 0, 255, 0);
    }

    return ApiStatus_BLOCK;
    
    #undef RGBA_BUF_SIZE
}

#include "common/Dist3D.inc.c"

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_Idle) = {
    ChildThread
        Call(N(UpdateMonstarImgFX))
    EndChildThread
    Label(0)
        Call(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
        Call(MakeLerp, 0, 10, 30, EASING_COS_IN_OUT)
        Label(1)
            Call(UpdateLerp)
            Add(LVar0, LVar3)
            Call(SetActorPos, ACTOR_SELF, LVar2, LVar0, LVar4)
            Label(2)
                Call(GetActorVar, ACTOR_SELF, AVAR_HoverPaused, LVar5)
                Wait(1)
                IfEq(LVar5, 1)
                    Goto(2)
                EndIf
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Call(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
        Call(MakeLerp, 0, -10, 30, EASING_COS_IN_OUT)
        Label(3)
            Call(UpdateLerp)
            Add(LVar0, LVar3)
            Call(SetActorPos, ACTOR_SELF, LVar2, LVar0, LVar4)
            Label(4)
                Call(GetActorVar, ACTOR_SELF, AVAR_HoverPaused, LVar5)
                Wait(1)
                IfEq(LVar5, 1)
                    Goto(4)
                EndIf
            IfEq(LVar1, 1)
                Goto(3)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, TRUE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Monstar_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, 1)
            Set(LVar1, ANIM_Monstar_Hurt)
            Set(LVar2, -1)
            ExecWait(N(EVS_BurnHit))
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, 1)
            Set(LVar1, ANIM_Monstar_Hurt)
            Set(LVar2, -1)
            ExecWait(N(EVS_BurnHit))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Monstar_Hurt)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            Call(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Monstar_Idle1)
                CaseEq(1)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Monstar_GatherStrength1)
            EndSwitch
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_IMMUNE)
            Call(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Monstar_Idle1)
                CaseEq(1)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Monstar_GatherStrength1)
            EndSwitch
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Monstar_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Monstar_Hurt)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Monstar_Idle1)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Monstar_Idle1)
                CaseEq(1)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Monstar_GatherStrength1)
            EndSwitch
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Monstar_Idle1)
                CaseEq(1)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Monstar_GatherStrength1)
            EndSwitch
            ExecWait(EVS_Enemy_NoDamageHit)
    EndSwitch
    Call(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, FALSE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

// unused
EvtScript N(EVS_ChargeUp) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, TRUE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_13)
    Call(SetBattleCamZoom, 10)
    Call(SetBattleCamOffsetZ, 5)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_GatherStrength1)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ChargedAnims)))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 40)
    Sub(LVar2, 5)
    PlayEffect(EFFECT_RADIAL_SHIMMER, 10, LVar0, LVar1, LVar2, Float(1.0), 300, 0)
    Wait(75)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, FALSE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_StarStorm) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, TRUE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamZoom, 250)
    Call(SetBattleCamOffsetZ, 55)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_GatherStrength1)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_GatherStrength2)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_GatherStrength3)
    EndThread
    Thread
        Call(N(UnkBackgroundFunc3))
        Call(MakeLerp, 0, 200, 60, EASING_QUADRATIC_IN)
        Label(0)
        Call(UpdateLerp)
        Call(N(SetBackgroundAlpha), LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    Call(N(StartRumbleWithParams), 80, 120)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamZoom, 100)
    Call(SetBattleCamOffsetZ, 60)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 60)
    Wait(60)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MONSTAR_CAST_SPELL)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MONSTAR_STAR_STORM)
    Thread
        Wait(10)
        Loop(18)
            Call(RandInt, 150, LVar0)
            Add(LVar0, 100)
            Call(N(StartRumbleWithParams), LVar0, 20)
            Wait(10)
        EndLoop
    EndThread
    Thread
        Loop(60)
            // choose from FX_STAR_BACKGROUND to FX_STAR_SMALL_BOUNCING
            Call(RandInt, 1, LVar0)
            Add(LVar0, 2)
            Call(RandInt, 400, LVar1)
            Sub(LVar1, 100)
            Call(RandInt, 100, LVar2)
            Sub(LVar2, 50)
            Set(LVar3, LVar1)
            Sub(LVar3, 200)
            Set(LVar4, LVar2)
            Call(RandInt, 10, LVar5)
            Add(LVar5, 10)
            PlayEffect(EFFECT_STAR, LVar0, LVar1, 240, LVar2, LVar3, 0, LVar4, LVar5, 0)
            Wait(3)
        EndLoop
    EndThread
    Wait(8)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 50)
    Add(LVar2, 5)
    PlayEffect(EFFECT_RADIAL_SHIMMER, 11, LVar0, LVar1, LVar2, Float(0.8), 160, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Release)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Wait(170)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Idle1)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            Call(MakeLerp, 200, 0, 60, EASING_LINEAR)
            Label(1)
            Call(UpdateLerp)
            Call(N(SetBackgroundAlpha), LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(20)
            Call(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, FALSE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Wait(170)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_STAR_STORM, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Idle1)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            Call(MakeLerp, 200, 0, 60, EASING_LINEAR)
            Label(2)
            Call(UpdateLerp)
            Call(N(SetBackgroundAlpha), LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
            Wait(20)
        EndCaseGroup
    EndSwitch
    Call(SetActorVar, ACTOR_SELF, AVAR_HoverPaused, FALSE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    ExecWait(N(EVS_Attack_StarStorm))
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 72)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamZoom, 340)
    Call(MoveBattleCamOver, 20)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(ActorSpeak, MSG_CH7_00E5, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Talk, ANIM_Monstar_Talk)
        CaseEq(1)
            Call(ActorSpeak, MSG_CH7_00E6, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Talk, ANIM_Monstar_Talk)
        CaseEq(2)
            Call(ActorSpeak, MSG_CH7_00E7, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Talk, ANIM_Monstar_Talk)
        CaseDefault
            Call(ActorSpeak, MSG_CH7_00E6, ACTOR_SELF, PRT_MAIN, ANIM_Monstar_Talk, ANIM_Monstar_Talk)
    EndSwitch
    Call(AddActorVar, ACTOR_SELF, AVAR_TurnCount, 1)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Return
    End
};

EvtScript N(EVS_Death) = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    IfNe(LVar1, -1)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        Wait(10)
    EndIf
    Call(GetDamageSource, LVar5)
    Switch(LVar5)
        CaseOrEq(DMG_SRC_NEXT_SLAP_LEFT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_LAST_SLAP_LEFT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_NEXT_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_LAST_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_SPIN_SMASH)
        EndCaseGroup
        CaseDefault
            Set(LFlag0, FALSE)
            Call(GetOriginalActorType, ACTOR_SELF, LVar1)
            Switch(LVar1)
                CaseOrEq(ACTOR_TYPE_BOB_OMB)
                CaseOrEq(ACTOR_TYPE_BULLET_BILL)
                CaseOrEq(ACTOR_TYPE_BOMBSHELL_BILL)
                EndCaseGroup
                CaseDefault
            EndSwitch
            IfNe(LVar2, EXEC_DEATH_NO_SPINNING)
                Set(LVar2, 0)
                Loop(24)
                    Call(SetActorYaw, ACTOR_SELF, LVar2)
                    Add(LVar2, 30)
                    Wait(1)
                EndLoop
                Call(SetActorYaw, ACTOR_SELF, 0)
            EndIf
    EndSwitch
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Add(LVar2, 10)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Set(LVar3, 0)
    Loop(12)
        Call(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        Add(LVar3, 8)
        Wait(1)
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ExecWait(EVS_ForceNextTarget)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_BurnHit) = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(GetDamageSource, LVar3)
    Switch(LVar3)
        CaseEq(DMG_SRC_FIRE_SHELL)
            Call(GetOriginalActorType, ACTOR_SELF, LVar7)
            Switch(LVar7)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EndCaseGroup
                CaseDefault
                    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
                    Add(LVar5, 55)
                    Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, FALSE, FALSE)
            EndSwitch
            Set(LVar7, 0)
            Loop(30)
                Add(LVar7, 48)
                Call(SetActorYaw, ACTOR_SELF, LVar7)
                Wait(1)
            EndLoop
            Call(GetOriginalActorType, ACTOR_SELF, LVar7)
            Switch(LVar7)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    Wait(30)
                EndCaseGroup
                CaseDefault
                    Sub(LVar5, 55)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
                    IfEq(LVar5, 0)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    Else
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EndIf
            EndSwitch
        CaseDefault
            Wait(20)
    EndSwitch
    IfNe(LVar2, -1)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar2)
    EndIf
    Wait(10)
    Call(GetLastEvent, ACTOR_SELF, LVar1)
    Switch(LVar1)
        CaseEq(EVENT_BURN_HIT)
            Call(GetPartEventFlags, ACTOR_SELF, LVar0, LVar1)
            IfNotFlag(LVar1, ACTOR_EVENT_FLAG_FIREY | ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                Call(GetStatusFlags, ACTOR_SELF, LVar5)
                IfFlag(LVar5, STATUS_FLAG_SHRINK)
                    MulF(LVar3, Float(0.4))
                    MulF(LVar4, Float(0.4))
                EndIf
                DivF(LVar3, Float(2.0))
                Call(GetActorFlags, ACTOR_SELF, LVar5)
                IfFlag(LVar5, ACTOR_FLAG_UPSIDE_DOWN)
                    SubF(LVar1, LVar3)
                Else
                    AddF(LVar1, LVar3)
                EndIf
                AddF(LVar2, Float(5.0))
                DivF(LVar3, Float(10.0))
                Call(GetStatusFlags, ACTOR_SELF, LVar5)
                IfFlag(LVar5, STATUS_FLAG_SHRINK)
                    MulF(LVar3, Float(0.4))
                    IfLt(LVar3, 1)
                        SetF(LVar3, Float(1.0))
                    EndIf
                EndIf
                PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
            EndIf
        CaseEq(EVENT_BURN_DEATH)
            // do nothing
    EndSwitch
    Return
    End
};
