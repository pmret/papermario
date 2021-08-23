#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goomba.h"

#define NAMESPACE b_area_kmr_part_1_goomba

s32 N(defenseTable_80219610)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021961C)[] = {
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

s32 N(idleAnimations_80219714)[];
EvtSource N(init_802197AC);

ActorPartDesc N(partsTable_802196C8)[] = {
    {
        .flags = PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80219714),
        .defenseTable = N(defenseTable_80219610),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 246,
    },
};

ActorDesc NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_goomba,
    .level = 5,
    .maxHP = 2,
    .partCount = ARRAY_COUNT(N(partsTable_802196C8)),
    .partsData = N(partsTable_802196C8),
    .script = N(init_802197AC),
    .statusTable = N(statusTable_8021961C),
    .escapeChance = 90,
    .airLiftChance = 100,
    .spookChance = 90,
    .baseStatusChance = 100,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 24, 24 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_80219714)[] = {
    STATUS_NORMAL,    NPC_ANIM(goomba, normal, idle),
    STATUS_STONE,     NPC_ANIM(goomba, normal, still),
    STATUS_SLEEP,     NPC_ANIM(goomba, normal, asleep),
    STATUS_POISON,    NPC_ANIM(goomba, normal, idle),
    STATUS_STOP,      NPC_ANIM(goomba, normal, still),
    STATUS_STATIC,    NPC_ANIM(goomba, normal, idle),
    STATUS_PARALYZE,  NPC_ANIM(goomba, normal, still),
    STATUS_DIZZY,     NPC_ANIM(goomba, normal, dizzy),
    STATUS_FEAR,      NPC_ANIM(goomba, normal, dizzy),
    STATUS_END,
};

s32 N(idleAnimations_80219760)[] = {
    STATUS_NORMAL,    NPC_ANIM(goomba, normal, run),
    STATUS_STONE,     NPC_ANIM(goomba, normal, still),
    STATUS_SLEEP,     NPC_ANIM(goomba, normal, asleep),
    STATUS_POISON,    NPC_ANIM(goomba, normal, idle),
    STATUS_STOP,      NPC_ANIM(goomba, normal, still),
    STATUS_STATIC,    NPC_ANIM(goomba, normal, run),
    STATUS_PARALYZE,  NPC_ANIM(goomba, normal, still),
    STATUS_DIZZY,     NPC_ANIM(goomba, normal, dizzy),
    STATUS_FEAR,      NPC_ANIM(goomba, normal, dizzy),
    STATUS_END,
};

EvtSource N(takeTurn_8021A300);
EvtSource N(idle_802197F8);
EvtSource N(handleEvent_80219AD4);

EvtSource N(init_802197AC) = SCRIPT({
    BindTakeTurn(ACTOR_SELF, N(takeTurn_8021A300));
    BindIdle(ACTOR_SELF, N(idle_802197F8));
    BindHandleEvent(ACTOR_SELF, N(handleEvent_80219AD4));
});

EvtSource N(idle_802197F8) = SCRIPT({
10:
    RandInt(80, SI_VAR(0));
    SI_VAR(0) += 80;
    loop SI_VAR(0) {
    0:
        GetStatusFlags(ACTOR_SELF, SI_VAR(1));
        if (SI_VAR(1) & 3526656) {
            sleep 1;
            goto 0;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 5;
    SetActorIdleSpeed(ACTOR_SELF, 1.0);
    SetIdleAnimations(ACTOR_SELF, 1, N(idleAnimations_80219760));
    SetIdleGoal(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleRunToGoal(ACTOR_SELF, 0);
    SetIdleAnimations(ACTOR_SELF, 1, N(idleAnimations_80219714));
    loop 20 {
    1:
        GetStatusFlags(ACTOR_SELF, SI_VAR(1));
        if (SI_VAR(1) & 3526656) {
            sleep 1;
            goto 1;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 5;
    SetActorIdleSpeed(ACTOR_SELF, 1.0);
    SetIdleAnimations(ACTOR_SELF, 1, N(idleAnimations_80219760));
    SetIdleGoal(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleRunToGoal(ACTOR_SELF, 0);
    SetIdleAnimations(ACTOR_SELF, 1, N(idleAnimations_80219714));
    loop 80 {
    2:
        GetStatusFlags(ACTOR_SELF, SI_VAR(1));
        if (SI_VAR(1) & 3526656) {
            sleep 1;
            goto 2;
        }
        sleep 1;
    }
    goto 10;
});

EvtSource N(handleEvent_80219AD4) = SCRIPT({
    UseIdleAnimation(ACTOR_SELF, FALSE);
    EnableIdleScript(ACTOR_SELF, FALSE);
    SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
    GetLastEvent(ACTOR_SELF, SI_VAR(0));
    match SI_VAR(0) {
        EVENT_HIT_COMBO, EVENT_HIT {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, pain);
            await DoNormalHit;
        }
        == EVENT_BURN_HIT {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, burn_pain);
            SI_VAR(2) = (const) NPC_ANIM(goomba, normal, burn_dead);
            await DoBurnHit;
        }
        == EVENT_BURN_DEATH {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, burn_pain);
            SI_VAR(2) = (const) NPC_ANIM(goomba, normal, burn_dead);
            await DoBurnHit;
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, burn_dead);
            await DoDeath;
            return;
        }
        == EVENT_SPIN_SMASH_HIT {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, pain);
            await DoSpinSmashHit;
        }
        == EVENT_SPIN_SMASH_DEATH {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, pain);
            await DoSpinSmashHit;
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, dead);
            await DoDeath;
            return;
        }
        == EVENT_SHOCK_HIT {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, electrocute);
            await DoShockHit;
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, pain);
            await DoJumpBack;
            JumpToGoal(ACTOR_SELF, 5, FALSE, TRUE, FALSE);
            SetAnimationRate(ACTOR_SELF, 1, 2.0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, dizzy));
            SetGoalToHome(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 8.0);
            RunToGoal(ACTOR_SELF, 0, FALSE);
            SetAnimationRate(ACTOR_SELF, 1, 1.0);
            sleep 5;
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
            SetActorJumpGravity(ACTOR_SELF, 1.6);
            JumpToGoal(ACTOR_SELF, 5, FALSE, TRUE, FALSE);
        }
        == EVENT_SHOCK_DEATH {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, electrocute);
            await DoShockHit;
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, dead);
            await DoDeath;
            return;
        }
        == EVENT_STAR_BEAM, 23, EVENT_IMMUNE, EVENT_AIR_LIFT_FAILED {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, idle);
            await DoImmune;
        }
        == EVENT_DEATH {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, pain);
            await DoNormalHit;
            sleep 10;
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, dead);
            await DoDeath;
            return;
        }
        == EVENT_END_FIRST_STRIKE {
            SetAnimationRate(ACTOR_SELF, 1, 2.0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, run));
            SetGoalToHome(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 4.0);
            RunToGoal(ACTOR_SELF, 0, FALSE);
            SetAnimationRate(ACTOR_SELF, 1, 1.0);
            HPBarToHome(ACTOR_SELF);
        }
        == EVENT_RECOVER_STATUS {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, idle);
            await DoRecover;
        }
        == EVENT_SCARE_AWAY {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, run);
            SI_VAR(2) = (const) NPC_ANIM(goomba, normal, pain);
            await DoScareAway;
            return;
        }
        == EVENT_BEGIN_AIR_LIFT {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, run);
            await DoAirLift;
        }
        == EVENT_BLOW_AWAY {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(goomba, normal, pain);
            await DoBlowAway;
            return;
        }
        else {
        }
    }
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
    EnableIdleScript(ACTOR_SELF, TRUE);
    UseIdleAnimation(ACTOR_SELF, TRUE);
});

#include "anglestuff.inc.c"

EvtSource N(takeTurn_8021A300) = SCRIPT({
    UseIdleAnimation(ACTOR_SELF, FALSE);
    EnableIdleScript(ACTOR_SELF, FALSE);
    SetTargetActor(ACTOR_SELF, ACTOR_PLAYER);
    UseBattleCamPreset(63);
    BattleCamTargetActor(ACTOR_SELF);
    func_8024ECF8(-1, 1, 0);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, run));
    SetGoalToTarget(ACTOR_SELF);
    AddGoalPos(ACTOR_SELF, 50, 0, 0);
    SetActorSpeed(ACTOR_SELF, 6.0);
    RunToGoal(ACTOR_SELF, 0, FALSE);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
    SetActorDispOffset(ACTOR_SELF, 0, -1, 0);
    sleep 1;
    SetActorDispOffset(ACTOR_SELF, 0, -2, 0);
    sleep 5;
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
    EnemyTestTarget(ACTOR_SELF, SI_VAR(0), ((0)), 0, 1, 16);
    match SI_VAR(0) {
        HIT_RESULT_MISS, HIT_RESULT_LUCKY {
            SI_VAR(10) = SI_VAR(0);
            SetGoalToTarget(ACTOR_SELF);
            GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) -= 10;
            SI_VAR(1) = 10;
            SI_VAR(2) += 3;
            SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetActorJumpGravity(ACTOR_SELF, 1.2);
            spawn {
                GetActorPos(ACTOR_SELF, SI_VAR(1), SI_VAR(2), SI_VAR(0));
                SI_VAR(0) = 0;
                loop 16 {
                    GetActorPos(ACTOR_SELF, SI_VAR(4), SI_VAR(5), SI_VAR(6));
                    N(AngleCalculate)(SI_VAR(1), SI_VAR(2), SI_VAR(4), SI_VAR(5), SI_VAR(0));
                    SetActorRotation(ACTOR_SELF, 0, 0, SI_VAR(0));
                    SI_VAR(1) = SI_VAR(4);
                    SI_VAR(2) = SI_VAR(5);
                    SI_VAR(3) = SI_VAR(6);
                    sleep 1;
                }
            }
            spawn {
                sleep 6;
                SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
            }
            JumpToGoal(ACTOR_SELF, 16, FALSE, TRUE, FALSE);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, asleep));
            SetActorScale(ACTOR_SELF, 1.1, 0.8, 1.0);
            SetActorDispOffset(ACTOR_SELF, 0, 5, 0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.3, 0.5, 1.0);
            SetActorDispOffset(ACTOR_SELF, 0, -2, 0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
            SetActorDispOffset(ACTOR_SELF, 0, 7, 0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, pain));
            sleep 5;
            if (SI_VAR(10) == 5) {
                EnemyTestTarget(ACTOR_SELF, SI_VAR(0), ((0x80000000)), 0, 0, 0);
            }
            sleep 5;
            SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
            SetGoalToTarget(ACTOR_SELF);
            GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) += 20;
            SI_VAR(1) = 0;
            SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetActorJumpGravity(ACTOR_SELF, 2.0);
            spawn {
                sleep 4;
                SI_VAR(0) = 180;
                loop 4 {
                    SI_VAR(0) -= 45;
                    SetActorRotation(ACTOR_SELF, 0, 0, SI_VAR(0));
                    sleep 1;
                }
                SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
            }
            JumpToGoal(ACTOR_SELF, 15, FALSE, TRUE, FALSE);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, dizzy));
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
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
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
                GetActorPos(ACTOR_SELF, SI_VAR(1), SI_VAR(2), SI_VAR(0));
                SI_VAR(0) = 0;
                loop 16 {
                    GetActorPos(ACTOR_SELF, SI_VAR(4), SI_VAR(5), SI_VAR(6));
                    N(AngleCalculate)(SI_VAR(1), SI_VAR(2), SI_VAR(4), SI_VAR(5), SI_VAR(0));
                    SetActorRotation(ACTOR_SELF, 0, 0, SI_VAR(0));
                    SI_VAR(1) = SI_VAR(4);
                    SI_VAR(2) = SI_VAR(5);
                    SI_VAR(3) = SI_VAR(6);
                    sleep 1;
                }
            }
            spawn {
                sleep 6;
                SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
            }
            JumpToGoal(ACTOR_SELF, 16, FALSE, TRUE, FALSE);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, pre_headbonk));
            SetActorScale(ACTOR_SELF, 1.1, 0.8, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.3, 0.5, 1.0);
            sleep 1;
        }
    }
    EnemyDamageTarget(ACTOR_SELF, SI_VAR(0), ((0)), 0, 0, 1, 32);
    match SI_VAR(0) {
        HIT_RESULT_HIT, 2 {
            UseBattleCamPreset(2);
            SetActorScale(ACTOR_SELF, 1.1, 0.8, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
            sleep 1;
            SetActorRotation(ACTOR_SELF, 0, 0, 0);
            SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
            GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) += 40;
            SI_VAR(1) = 0;
            SetActorJumpGravity(ACTOR_SELF, 1.8);
            SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(ACTOR_SELF, 10, FALSE, TRUE, FALSE);
            SI_VAR(0) += 30;
            SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(ACTOR_SELF, 8, FALSE, TRUE, FALSE);
            SI_VAR(0) += 20;
            SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(ACTOR_SELF, 6, FALSE, TRUE, FALSE);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
            sleep 3;
            YieldTurn();
            SetAnimationRate(ACTOR_SELF, 1, 2.0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, run));
            SetGoalToHome(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 8.0);
            RunToGoal(ACTOR_SELF, 0, FALSE);
            SetAnimationRate(ACTOR_SELF, 1, 1.0);
        }
    }
    EnableIdleScript(ACTOR_SELF, TRUE);
    UseIdleAnimation(ACTOR_SELF, TRUE);
});
