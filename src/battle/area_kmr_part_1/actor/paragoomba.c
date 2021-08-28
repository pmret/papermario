#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/paragoomba.h"

#define NAMESPACE b_area_kmr_part_1_paragoomba

ApiStatus N(AngleCalculate)(Evt* script, s32 isInitialCall);

s32 N(defenseTable_8021CB00)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(defenseTable_8021CB0C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021CB18)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
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

s32 N(statusTable_8021CBC4)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 80,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 80,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

s32 N(idleAnimations_8021E4EC)[];
s32 N(idleAnimations_8021CD28)[];
s32 N(idleAnimations_8021CDC0)[];
s32 N(idleAnimations_8021CDCC)[];
EvtSource N(init_8021CDD8);

ActorPartDesc N(partsTable_8021CC70)[] = {
    {
        .flags = PART_FLAG_INVISIBLE | PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021E4EC),
        .defenseTable = N(defenseTable_8021CB00),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 246,
    },
    {
        .flags = PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021CD28),
        .defenseTable = N(defenseTable_8021CB0C),
        .eventFlags = EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 246,
    },
    {
        .flags = PART_FLAG_INVISIBLE | PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021CDC0),
        .defenseTable = N(defenseTable_8021CB00),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 246,
    },
    {
        .flags = PART_FLAG_INVISIBLE | PART_FLAG_NO_TARGET,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021CDCC),
        .defenseTable = N(defenseTable_8021CB00),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 246,
    },
};

ActorDesc NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_paragoomba,
    .level = 6,
    .maxHP = 2,
    .partCount = ARRAY_COUNT(N(partsTable_8021CC70)),
    .partsData = N(partsTable_8021CC70),
    .script = N(init_8021CDD8),
    .statusTable = N(statusTable_8021CBC4),
    .escapeChance = 90,
    .airLiftChance = 100,
    .spookChance = 100,
    .baseStatusChance = 100,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 36, 26 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_8021CD28)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_default_idle,
    STATUS_STONE,     NPC_ANIM_paragoomba_default_still,
    STATUS_SLEEP,     NPC_ANIM_paragoomba_default_sleep,
    STATUS_POISON,    NPC_ANIM_paragoomba_default_idle,
    STATUS_STOP,      NPC_ANIM_paragoomba_default_still,
    STATUS_STATIC,    NPC_ANIM_paragoomba_default_idle,
    STATUS_PARALYZE,  NPC_ANIM_paragoomba_default_still,
    STATUS_DIZZY,     NPC_ANIM_paragoomba_default_dizzy,
    STATUS_FEAR,      NPC_ANIM_paragoomba_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8021CD74)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_default_run,
    STATUS_STONE,     NPC_ANIM_paragoomba_default_still,
    STATUS_SLEEP,     NPC_ANIM_paragoomba_default_sleep,
    STATUS_POISON,    NPC_ANIM_paragoomba_default_idle,
    STATUS_STOP,      NPC_ANIM_paragoomba_default_still,
    STATUS_STATIC,    NPC_ANIM_paragoomba_default_run,
    STATUS_PARALYZE,  NPC_ANIM_paragoomba_default_still,
    STATUS_DIZZY,     NPC_ANIM_paragoomba_default_dizzy,
    STATUS_FEAR,      NPC_ANIM_paragoomba_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8021CDC0)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_default_left_wing_only,
    STATUS_END,
};

s32 N(idleAnimations_8021CDCC)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_default_right_wing_only,
    STATUS_END,
};

EvtSource N(takeTurn_8021D74C);
EvtSource N(idle_8021CE24);
EvtSource N(handleEvent_8021D158);

EvtSource N(init_8021CDD8) = SCRIPT({
    BindTakeTurn(ACTOR_SELF, N(takeTurn_8021D74C));
    BindIdle(ACTOR_SELF, N(idle_8021CE24));
    BindHandleEvent(ACTOR_SELF, N(handleEvent_8021D158));
});

EvtSource N(idle_8021CE24) = SCRIPT({
10:
    RandInt(80, EVT_VAR(0));
    EVT_VAR(0) += 80;
    loop EVT_VAR(0) {
    0:
        GetStatusFlags(ACTOR_SELF, EVT_VAR(1));
        if (EVT_VAR(1) & 3526656) {
            sleep 1;
            goto 0;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 5;
    SetActorIdleSpeed(ACTOR_SELF, 0.6);
    SetIdleAnimations(ACTOR_SELF, 2, N(idleAnimations_8021CD74));
    SetIdleGoal(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    IdleFlyToGoal(ACTOR_SELF, 0, -5, 0);
    loop 20 {
    1:
        GetStatusFlags(ACTOR_SELF, EVT_VAR(1));
        if (EVT_VAR(1) & 3526656) {
            sleep 1;
            goto 1;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) -= 5;
    SetActorIdleSpeed(ACTOR_SELF, 0.6);
    SetIdleGoal(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    IdleFlyToGoal(ACTOR_SELF, 0, -5, 0);
    SetIdleAnimations(ACTOR_SELF, 2, N(idleAnimations_8021CD28));
    loop 40 {
    2:
        GetStatusFlags(ACTOR_SELF, EVT_VAR(1));
        if (EVT_VAR(1) & 3526656) {
            sleep 1;
            goto 2;
        }
        sleep 1;
    }
    goto 10;
});

EvtSource N(8021D0E0) = SCRIPT({
    ResetAllActorSounds(ACTOR_SELF);
    SetGoalToHome(ACTOR_SELF);
    SetActorSpeed(ACTOR_SELF, 7.0);
    FlyToGoal(ACTOR_SELF, 0, 1, 11);
    SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_idle);
});

EvtSource N(8021DF64);

EvtSource N(handleEvent_8021D158) = SCRIPT({
    UseIdleAnimation(ACTOR_SELF, FALSE);
    EnableIdleScript(ACTOR_SELF, 0);
    GetLastEvent(ACTOR_SELF, EVT_VAR(0));
    match EVT_VAR(0) {
        EVENT_HIT_COMBO, EVENT_HIT {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_pain;
            await DoNormalHit;
            GetBattlePhase(EVT_VAR(0));
            if (EVT_VAR(0) == 1) {
                GetEncounterState(EVT_VAR(0));
                if (EVT_VAR(0) == 4) {
                    await N(8021DF64);
                }
            }
        }
        == EVENT_BURN_HIT {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_burn_pain;
            EVT_VAR(2) = (const) NPC_ANIM_paragoomba_default_burn_dead;
            await DoBurnHit;
        }
        == EVENT_BURN_DEATH {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_burn_pain;
            EVT_VAR(2) = (const) NPC_ANIM_paragoomba_default_burn_dead;
            await DoBurnHit;
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_burn_dead;
            await DoDeath;
            return;
        }
        == EVENT_FALL_TRIGGER {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_pain;
            await DoNormalHit;
            await N(8021DF64);
        }
        == 15 {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_burn_pain;
            EVT_VAR(2) = (const) NPC_ANIM_paragoomba_default_burn_dead;
            await DoBurnHit;
            await N(8021DF64);
        }
        == EVENT_SHOCK_HIT {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_electrocute;
            await DoShockHit;
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_pain;
            await DoJumpBack;
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_dizzy);
            await N(8021D0E0);
        }
        == EVENT_SHOCK_DEATH {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_electrocute;
            await DoShockHit;
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_dead;
            await DoDeath;
            return;
        }
        == EVENT_STAR_BEAM, 23, EVENT_IMMUNE, EVENT_AIR_LIFT_FAILED {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_idle;
            await DoImmune;
        }
        == EVENT_DEATH {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_pain;
            await DoNormalHit;
            sleep 10;
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_dead;
            await DoDeath;
            return;
        }
        == EVENT_BEGIN_FIRST_STRIKE {
            SetActorPos(ACTOR_SELF, 20, 0, 0);
            HPBarToCurrent(ACTOR_SELF);
        }
        == EVENT_END_FIRST_STRIKE {
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_run);
            await N(8021D0E0);
            HPBarToHome(ACTOR_SELF);
        }
        == EVENT_RECOVER_STATUS {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_idle;
            await DoRecover;
        }
        == EVENT_SCARE_AWAY {
            SetActorFlagBits(ACTOR_SELF, 512, 0);
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_run;
            EVT_VAR(2) = (const) NPC_ANIM_paragoomba_default_pain;
            await DoScareAway;
            return;
        }
        == EVENT_BEGIN_AIR_LIFT {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_run;
            await DoAirLift;
        }
        == EVENT_BLOW_AWAY {
            EVT_VAR(0) = (const) 2;
            EVT_VAR(1) = (const) NPC_ANIM_paragoomba_default_pain;
            await DoBlowAway;
            return;
        }
        else {
        }
    }
    EnableIdleScript(ACTOR_SELF, -1);
    UseIdleAnimation(ACTOR_SELF, TRUE);
});

EvtSource N(takeTurn_8021D74C) = SCRIPT({
    UseIdleAnimation(ACTOR_SELF, FALSE);
    EnableIdleScript(ACTOR_SELF, 0);
    SetTargetActor(ACTOR_SELF, ACTOR_PLAYER);
    SetGoalToTarget(ACTOR_SELF);
    UseBattleCamPreset(63);
    BattleCamTargetActor(ACTOR_SELF);
    func_8024ECF8(-1, 1, 0);
    SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_run);
    SetGoalToTarget(ACTOR_SELF);
    AddGoalPos(ACTOR_SELF, 50, 0, 0);
    SetActorSpeed(ACTOR_SELF, 6.0);
    FlyToGoal(ACTOR_SELF, 0, -4, 0);
    EnemyTestTarget(ACTOR_SELF, EVT_VAR(0), ((0)), 0, 1, 16);
    match EVT_VAR(0) {
        HIT_RESULT_MISS, HIT_RESULT_LUCKY {
            EVT_VAR(10) = EVT_VAR(0);
            sleep 10;
            UseBattleCamPreset(66);
            SetBattleCamZoom(300);
            BattleCamTargetActor(ACTOR_SELF);
            func_8024ECF8(-1, 1, 0);
            PlaySoundAtActor(ACTOR_SELF, 0x20E0);
            SetActorSounds(ACTOR_SELF, 2, 0, 0);
            SetActorSpeed(ACTOR_SELF, 5.0);
            SetActorJumpGravity(ACTOR_SELF, 1.8);
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_attack);
            GetActorPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            JumpToGoal(ACTOR_SELF, 10, FALSE, FALSE, FALSE);
            PlaySoundAtActor(ACTOR_SELF, SOUND_UNUSED_2C1);
            SetActorSounds(ACTOR_SELF, 1, 0, 0);
            SetGoalToTarget(ACTOR_SELF);
            EVT_VAR(0) -= 80;
            EVT_VAR(1) = 20;
            SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            SetActorSpeed(ACTOR_SELF, 8.0);
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_attack);
            FlyToGoal(ACTOR_SELF, 0, -10, 4);
            spawn {
                loop 4 {
                    PlaySoundAtActor(ACTOR_SELF, 0x20DF);
                    sleep 4;
                }
            }
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_aim);
            AddActorDecoration(ACTOR_SELF, 2, 0, 2);
            SetAnimationRate(ACTOR_SELF, 2, 3.0);
            sleep 10;
            if (EVT_VAR(10) == 5) {
                EnemyTestTarget(ACTOR_SELF, EVT_VAR(0), ((0x80000000)), 0, 0, 0);
            }
            sleep 10;
            SetAnimationRate(ACTOR_SELF, 2, 1.0);
            UseBattleCamPreset(2);
            ResetAllActorSounds(ACTOR_SELF);
            YieldTurn();
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_run);
            SetActorYaw(ACTOR_SELF, 180);
            await N(8021D0E0);
            SetActorYaw(ACTOR_SELF, 0);
            RemoveActorDecoration(ACTOR_SELF, 2, 0);
            EnableIdleScript(ACTOR_SELF, -1);
            UseIdleAnimation(ACTOR_SELF, TRUE);
            return;
        }
        else {
            sleep 10;
            UseBattleCamPreset(66);
            SetBattleCamZoom(300);
            BattleCamTargetActor(ACTOR_SELF);
            func_8024ECF8(-1, 1, 0);
            PlaySoundAtActor(ACTOR_SELF, 0x20E0);
            SetActorSounds(ACTOR_SELF, 2, 0, 0);
            SetActorSpeed(ACTOR_SELF, 5.0);
            SetActorJumpGravity(ACTOR_SELF, 1.8);
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_attack);
            GetActorPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            JumpToGoal(ACTOR_SELF, 10, FALSE, FALSE, FALSE);
            PlaySoundAtActor(ACTOR_SELF, SOUND_UNUSED_2C1);
            SetActorSounds(ACTOR_SELF, 1, 0, 0);
            SetGoalToTarget(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 8.0);
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_attack);
            FlyToGoal(ACTOR_SELF, 0, -10, 0);
        }
    }
    sleep 2;
    EnemyDamageTarget(ACTOR_SELF, EVT_VAR(0), ((0)), 0, 0, 1, 32);
    match EVT_VAR(0) {
        HIT_RESULT_HIT, 2 {
            UseBattleCamPreset(2);
            SetGoalToTarget(ACTOR_SELF);
            AddGoalPos(ACTOR_SELF, 50, 10, 0);
            SetActorSpeed(ACTOR_SELF, 6.0);
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_run);
            FlyToGoal(ACTOR_SELF, 0, -10, 0);
            ResetAllActorSounds(ACTOR_SELF);
            sleep 5;
            YieldTurn();
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_run);
            await N(8021D0E0);
        }
    }
    EnableIdleScript(ACTOR_SELF, -1);
    UseIdleAnimation(ACTOR_SELF, TRUE);
});

EvtSource N(8021E584);

#include "common/StartRumbleWithParams.inc.c"

EvtSource N(8021DF64) = SCRIPT({
    func_8027D32C(-127);
    SetPartFlags(ACTOR_SELF, 2, 131077);
    SetPartFlags(ACTOR_SELF, 3, 1179652);
    SetPartFlags(ACTOR_SELF, 4, 1179652);
    SetPartFlags(ACTOR_SELF, 1, 8388612);
    GetActorPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPartPos(ACTOR_SELF, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPartDispOffset(ACTOR_SELF, 3, -9, 7, -2);
    SetPartPos(ACTOR_SELF, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPartDispOffset(ACTOR_SELF, 4, 11, 7, -2);
    GetLastEvent(ACTOR_SELF, EVT_VAR(0));
    if (EVT_VAR(0) == 15) {
        SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_burn_dead);
    } else {
        SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_pain);
    }
    SetActorSounds(ACTOR_SELF, 2, 769, 0);
    GetActorPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(1) = 0;
    SetActorJumpGravity(ACTOR_SELF, 0.8);
    SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    JumpToGoal(ACTOR_SELF, 15, FALSE, TRUE, FALSE);
    N(StartRumbleWithParams)(100, 10);
    spawn {
        ShakeCam(1, 0, 5, 0.3);
    }
    ResetActorSounds(ACTOR_SELF, 2);
    GetLastEvent(ACTOR_SELF, EVT_VAR(3));
    if (EVT_VAR(3) == 15) {
        SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_pain);
        GetActorPos(ACTOR_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
        EVT_VAR(4) += 10;
        EVT_VAR(5) += 5;
        PlayEffect(0x27, 0, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5), 1.0, 10, 0, 0, 0, 0, 0, 0, 0);
    }
    SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    JumpToGoal(ACTOR_SELF, 10, FALSE, TRUE, FALSE);
    SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    JumpToGoal(ACTOR_SELF, 5, FALSE, TRUE, FALSE);
    loop 10 {
        SetPartFlagBits(ACTOR_SELF, 3, 1, 1);
        SetPartFlagBits(ACTOR_SELF, 4, 1, 1);
        sleep 1;
        SetPartFlagBits(ACTOR_SELF, 3, 1, 0);
        SetPartFlagBits(ACTOR_SELF, 4, 1, 0);
        sleep 1;
    }
    SetPartFlagBits(ACTOR_SELF, 3, 1, 1);
    SetPartFlagBits(ACTOR_SELF, 4, 1, 1);
    GetIndexFromHome(ACTOR_SELF, EVT_VAR(0));
    EVT_VAR(0) %= 4;
    SetGoalToIndex(ACTOR_SELF, EVT_VAR(0));
    GetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetHomePos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle);
    SetActorFlagBits(ACTOR_SELF, 512, 0);
    SetStatusTable(ACTOR_SELF, N(statusTable_8021CB18));
    SetActorType(ACTOR_SELF, ACTOR_TYPE_goomba);
    await N(8021E584);
    SetActorFlagBits(ACTOR_SELF, 4096, 1);
    HPBarToHome(ACTOR_SELF);
    ResetAllActorSounds(-127);
});

// Copy of goomba.c follows..................
// TODO: deduplicate

s32 N(idleAnimations_8021E4EC)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_normal_idle,
    STATUS_STONE,     NPC_ANIM_goomba_normal_still,
    STATUS_SLEEP,     NPC_ANIM_goomba_normal_asleep,
    STATUS_POISON,    NPC_ANIM_goomba_normal_idle,
    STATUS_STOP,      NPC_ANIM_goomba_normal_still,
    STATUS_STATIC,    NPC_ANIM_goomba_normal_idle,
    STATUS_PARALYZE,  NPC_ANIM_goomba_normal_still,
    STATUS_DIZZY,     NPC_ANIM_goomba_normal_dizzy,
    STATUS_FEAR,      NPC_ANIM_goomba_normal_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8021E538)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_normal_run,
    STATUS_STONE,     NPC_ANIM_goomba_normal_still,
    STATUS_SLEEP,     NPC_ANIM_goomba_normal_asleep,
    STATUS_POISON,    NPC_ANIM_goomba_normal_idle,
    STATUS_STOP,      NPC_ANIM_goomba_normal_still,
    STATUS_STATIC,    NPC_ANIM_goomba_normal_run,
    STATUS_PARALYZE,  NPC_ANIM_goomba_normal_still,
    STATUS_DIZZY,     NPC_ANIM_goomba_normal_dizzy,
    STATUS_FEAR,      NPC_ANIM_goomba_normal_dizzy,
    STATUS_END,
};

EvtSource N(takeTurn_8021F0D8);
EvtSource N(idle_8021E5D0);
EvtSource N(handleEvent_8021E8AC);

EvtSource N(8021E584) = SCRIPT({
    BindTakeTurn(ACTOR_SELF, N(takeTurn_8021F0D8));
    BindIdle(ACTOR_SELF, N(idle_8021E5D0));
    BindHandleEvent(ACTOR_SELF, N(handleEvent_8021E8AC));
});

EvtSource N(idle_8021E5D0) = SCRIPT({
10:
    RandInt(80, EVT_VAR(0));
    EVT_VAR(0) += 80;
    loop EVT_VAR(0) {
    0:
        GetStatusFlags(ACTOR_SELF, EVT_VAR(1));
        if (EVT_VAR(1) & 3526656) {
            sleep 1;
            goto 0;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 5;
    SetActorIdleSpeed(ACTOR_SELF, 1.0);
    SetIdleAnimations(ACTOR_SELF, 1, N(idleAnimations_8021E538));
    SetIdleGoal(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    IdleRunToGoal(ACTOR_SELF, 0);
    SetIdleAnimations(ACTOR_SELF, 1, N(idleAnimations_8021E4EC));
    loop 20 {
    1:
        GetStatusFlags(ACTOR_SELF, EVT_VAR(1));
        if (EVT_VAR(1) & 3526656) {
            sleep 1;
            goto 1;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) -= 5;
    SetActorIdleSpeed(ACTOR_SELF, 1.0);
    SetIdleAnimations(ACTOR_SELF, 1, N(idleAnimations_8021E538));
    SetIdleGoal(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    IdleRunToGoal(ACTOR_SELF, 0);
    SetIdleAnimations(ACTOR_SELF, 1, N(idleAnimations_8021E4EC));
    loop 80 {
    2:
        GetStatusFlags(ACTOR_SELF, EVT_VAR(1));
        if (EVT_VAR(1) & 3526656) {
            sleep 1;
            goto 2;
        }
        sleep 1;
    }
    goto 10;
});

EvtSource N(handleEvent_8021E8AC) = SCRIPT({
    UseIdleAnimation(ACTOR_SELF, FALSE);
    EnableIdleScript(ACTOR_SELF, FALSE);
    SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
    GetLastEvent(ACTOR_SELF, EVT_VAR(0));
    match EVT_VAR(0) {
        EVENT_HIT_COMBO, EVENT_HIT {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_pain;
            await DoNormalHit;
        }
        == EVENT_BURN_HIT {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_burn_pain;
            EVT_VAR(2) = (const) NPC_ANIM_goomba_normal_burn_dead;
            await DoBurnHit;
        }
        == EVENT_BURN_DEATH {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_burn_pain;
            EVT_VAR(2) = (const) NPC_ANIM_goomba_normal_burn_dead;
            await DoBurnHit;
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_burn_dead;
            await DoDeath;
            return;
        }
        == EVENT_SPIN_SMASH_HIT {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_pain;
            await DoSpinSmashHit;
        }
        == EVENT_SPIN_SMASH_DEATH {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_pain;
            await DoSpinSmashHit;
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_dead;
            await DoDeath;
            return;
        }
        == EVENT_SHOCK_HIT {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_electrocute;
            await DoShockHit;
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_pain;
            await DoJumpBack;
            JumpToGoal(ACTOR_SELF, 5, FALSE, TRUE, FALSE);
            SetAnimationRate(ACTOR_SELF, 1, 2.0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_dizzy);
            SetGoalToHome(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 8.0);
            RunToGoal(ACTOR_SELF, 0, FALSE);
            SetAnimationRate(ACTOR_SELF, 1, 1.0);
            sleep 5;
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle);
            SetActorJumpGravity(ACTOR_SELF, 1.6);
            JumpToGoal(ACTOR_SELF, 5, FALSE, TRUE, FALSE);
        }
        == EVENT_SHOCK_DEATH {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_electrocute;
            await DoShockHit;
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_dead;
            await DoDeath;
            return;
        }
        == EVENT_STAR_BEAM, 23, EVENT_IMMUNE, EVENT_AIR_LIFT_FAILED {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_idle;
            await DoImmune;
        }
        == EVENT_DEATH {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_pain;
            await DoNormalHit;
            sleep 10;
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_dead;
            await DoDeath;
            return;
        }
        == EVENT_END_FIRST_STRIKE {
            SetAnimationRate(ACTOR_SELF, 1, 2.0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_run);
            SetGoalToHome(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 4.0);
            RunToGoal(ACTOR_SELF, 0, FALSE);
            SetAnimationRate(ACTOR_SELF, 1, 1.0);
            HPBarToHome(ACTOR_SELF);
        }
        == EVENT_RECOVER_STATUS {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_idle;
            await DoRecover;
        }
        == EVENT_SCARE_AWAY {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_run;
            EVT_VAR(2) = (const) NPC_ANIM_goomba_normal_pain;
            await DoScareAway;
            return;
        }
        == EVENT_BEGIN_AIR_LIFT {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_run;
            await DoAirLift;
        }
        == EVENT_BLOW_AWAY {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_goomba_normal_pain;
            await DoBlowAway;
            return;
        }
        else {
        }
    }
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle);
    EnableIdleScript(ACTOR_SELF, TRUE);
    UseIdleAnimation(ACTOR_SELF, TRUE);
});

#include "anglestuff.inc.c"

EvtSource N(takeTurn_8021F0D8) = SCRIPT({
    UseIdleAnimation(ACTOR_SELF, FALSE);
    EnableIdleScript(ACTOR_SELF, FALSE);
    SetTargetActor(ACTOR_SELF, ACTOR_PLAYER);
    UseBattleCamPreset(63);
    BattleCamTargetActor(ACTOR_SELF);
    func_8024ECF8(-1, 1, 0);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_run);
    SetGoalToTarget(ACTOR_SELF);
    AddGoalPos(ACTOR_SELF, 50, 0, 0);
    SetActorSpeed(ACTOR_SELF, 6.0);
    RunToGoal(ACTOR_SELF, 0, FALSE);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle);
    SetActorDispOffset(ACTOR_SELF, 0, -1, 0);
    sleep 1;
    SetActorDispOffset(ACTOR_SELF, 0, -2, 0);
    sleep 5;
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_headbonk);
    EnemyTestTarget(ACTOR_SELF, EVT_VAR(0), ((0)), 0, 1, 16);
    match EVT_VAR(0) {
        HIT_RESULT_MISS, HIT_RESULT_LUCKY {
            EVT_VAR(10) = EVT_VAR(0);
            SetGoalToTarget(ACTOR_SELF);
            GetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            EVT_VAR(0) -= 10;
            EVT_VAR(1) = 10;
            EVT_VAR(2) += 3;
            SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            SetActorJumpGravity(ACTOR_SELF, 1.2);
            spawn {
                GetActorPos(ACTOR_SELF, EVT_VAR(1), EVT_VAR(2), EVT_VAR(0));
                EVT_VAR(0) = 0;
                loop 16 {
                    GetActorPos(ACTOR_SELF, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6));
                    N(AngleCalculate)(EVT_VAR(1), EVT_VAR(2), EVT_VAR(4), EVT_VAR(5), EVT_VAR(0));
                    SetActorRotation(ACTOR_SELF, 0, 0, EVT_VAR(0));
                    EVT_VAR(1) = EVT_VAR(4);
                    EVT_VAR(2) = EVT_VAR(5);
                    EVT_VAR(3) = EVT_VAR(6);
                    sleep 1;
                }
            }
            spawn {
                sleep 6;
                SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_headbonk);
            }
            JumpToGoal(ACTOR_SELF, 16, FALSE, TRUE, FALSE);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_asleep);
            SetActorScale(ACTOR_SELF, 1.1, 0.8, 1.0);
            SetActorDispOffset(ACTOR_SELF, 0, 5, 0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.3, 0.5, 1.0);
            SetActorDispOffset(ACTOR_SELF, 0, -2, 0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
            SetActorDispOffset(ACTOR_SELF, 0, 7, 0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_pain);
            sleep 5;
            if (EVT_VAR(10) == 5) {
                EnemyTestTarget(ACTOR_SELF, EVT_VAR(0), ((0x80000000)), 0, 0, 0);
            }
            sleep 5;
            SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_headbonk);
            SetGoalToTarget(ACTOR_SELF);
            GetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            EVT_VAR(0) += 20;
            EVT_VAR(1) = 0;
            SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            SetActorJumpGravity(ACTOR_SELF, 2.0);
            spawn {
                sleep 4;
                EVT_VAR(0) = 180;
                loop 4 {
                    EVT_VAR(0) -= 45;
                    SetActorRotation(ACTOR_SELF, 0, 0, EVT_VAR(0));
                    sleep 1;
                }
                SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_headbonk);
            }
            JumpToGoal(ACTOR_SELF, 15, FALSE, TRUE, FALSE);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_dizzy);
            sleep 5;
            UseBattleCamPreset(2);
            YieldTurn();
            SetActorYaw(ACTOR_SELF, 180);
            AddActorDecoration(ACTOR_SELF, 1, 0, 2);
            SetAnimationRate(ACTOR_SELF, 1, 2.0);
            SetGoalToHome(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 8.0);
            RunToGoal(ACTOR_SELF, 0, FALSE);
            SetAnimationRate(ACTOR_SELF, 1, 1.0);
            SetActorYaw(ACTOR_SELF, 0);
            sleep 5;
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle);
            SetActorJumpGravity(ACTOR_SELF, 1.6);
            JumpToGoal(ACTOR_SELF, 5, FALSE, TRUE, FALSE);
            RemoveActorDecoration(ACTOR_SELF, 1, 0);
            EnableIdleScript(ACTOR_SELF, TRUE);
            UseIdleAnimation(ACTOR_SELF, TRUE);
            return;
        }
        else {
            SetGoalToTarget(ACTOR_SELF);
            SetActorJumpGravity(ACTOR_SELF, 1.2);
            spawn {
                GetActorPos(ACTOR_SELF, EVT_VAR(1), EVT_VAR(2), EVT_VAR(0));
                EVT_VAR(0) = 0;
                loop 16 {
                    GetActorPos(ACTOR_SELF, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6));
                    N(AngleCalculate)(EVT_VAR(1), EVT_VAR(2), EVT_VAR(4), EVT_VAR(5), EVT_VAR(0));
                    SetActorRotation(ACTOR_SELF, 0, 0, EVT_VAR(0));
                    EVT_VAR(1) = EVT_VAR(4);
                    EVT_VAR(2) = EVT_VAR(5);
                    EVT_VAR(3) = EVT_VAR(6);
                    sleep 1;
                }
            }
            spawn {
                sleep 6;
                SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_headbonk);
            }
            JumpToGoal(ACTOR_SELF, 16, FALSE, TRUE, FALSE);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_pre_headbonk);
            SetActorScale(ACTOR_SELF, 1.1, 0.8, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.3, 0.5, 1.0);
            sleep 1;
        }
    }
    EnemyDamageTarget(ACTOR_SELF, EVT_VAR(0), ((0)), 0, 0, 1, 32);
    match EVT_VAR(0) {
        HIT_RESULT_HIT, 2 {
            UseBattleCamPreset(2);
            SetActorScale(ACTOR_SELF, 1.1, 0.8, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
            sleep 1;
            SetActorRotation(ACTOR_SELF, 0, 0, 0);
            SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle);
            GetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            EVT_VAR(0) += 40;
            EVT_VAR(1) = 0;
            SetActorJumpGravity(ACTOR_SELF, 1.8);
            SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            JumpToGoal(ACTOR_SELF, 10, FALSE, TRUE, FALSE);
            EVT_VAR(0) += 30;
            SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            JumpToGoal(ACTOR_SELF, 8, FALSE, TRUE, FALSE);
            EVT_VAR(0) += 20;
            SetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            JumpToGoal(ACTOR_SELF, 6, FALSE, TRUE, FALSE);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle);
            sleep 3;
            YieldTurn();
            SetAnimationRate(ACTOR_SELF, 1, 2.0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM_goomba_normal_run);
            SetGoalToHome(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 8.0);
            RunToGoal(ACTOR_SELF, 0, FALSE);
            SetAnimationRate(ACTOR_SELF, 1, 1.0);
        }
    }
    EnableIdleScript(ACTOR_SELF, TRUE);
    UseIdleAnimation(ACTOR_SELF, TRUE);
});
