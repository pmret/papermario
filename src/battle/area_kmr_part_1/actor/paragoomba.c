#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/paragoomba.h"

#define NAMESPACE b_area_kmr_part_1_paragoomba

ApiStatus N(AngleCalculate)(ScriptInstance* script, s32 isInitialCall);

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
Script N(init_8021CDD8);

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
    },
};

ActorDesc NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = 8,
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
    STATUS_NORMAL,    NPC_ANIM(paragoomba, default, idle),
    STATUS_STONE,     NPC_ANIM(paragoomba, default, still),
    STATUS_SLEEP,     NPC_ANIM(paragoomba, default, sleep),
    STATUS_POISON,    NPC_ANIM(paragoomba, default, idle),
    STATUS_STOP,      NPC_ANIM(paragoomba, default, still),
    STATUS_STATIC,    NPC_ANIM(paragoomba, default, idle),
    STATUS_PARALYZE,  NPC_ANIM(paragoomba, default, still),
    STATUS_DIZZY,     NPC_ANIM(paragoomba, default, dizzy),
    STATUS_FEAR,      NPC_ANIM(paragoomba, default, dizzy),
    STATUS_END,
};

s32 N(idleAnimations_8021CD74)[] = {
    STATUS_NORMAL,    NPC_ANIM(paragoomba, default, run),
    STATUS_STONE,     NPC_ANIM(paragoomba, default, still),
    STATUS_SLEEP,     NPC_ANIM(paragoomba, default, sleep),
    STATUS_POISON,    NPC_ANIM(paragoomba, default, idle),
    STATUS_STOP,      NPC_ANIM(paragoomba, default, still),
    STATUS_STATIC,    NPC_ANIM(paragoomba, default, run),
    STATUS_PARALYZE,  NPC_ANIM(paragoomba, default, still),
    STATUS_DIZZY,     NPC_ANIM(paragoomba, default, dizzy),
    STATUS_FEAR,      NPC_ANIM(paragoomba, default, dizzy),
    STATUS_END,
};

s32 N(idleAnimations_8021CDC0)[] = {
    STATUS_NORMAL,    NPC_ANIM(paragoomba, default, left_wing_only),
    STATUS_END,
};

s32 N(idleAnimations_8021CDCC)[] = {
    STATUS_NORMAL,    NPC_ANIM(paragoomba, default, right_wing_only),
    STATUS_END,
};

Script N(takeTurn_8021D74C);
Script N(idle_8021CE24);
Script N(handleEvent_8021D158);

Script N(init_8021CDD8) = SCRIPT({
    BindTakeTurn(ACTOR_SELF, N(takeTurn_8021D74C));
    BindIdle(-127, N(idle_8021CE24));
    BindHandleEvent(-127, N(handleEvent_8021D158));
});

Script N(idle_8021CE24) = SCRIPT({
10:
    RandInt(80, SI_VAR(0));
    SI_VAR(0) += 80;
    loop SI_VAR(0) {
    0:
        GetStatusFlags(-127, SI_VAR(1));
        if (SI_VAR(1) & 3526656) {
            sleep 1;
            goto 0;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 5;
    SetActorIdleSpeed(-127, 0.6);
    SetIdleAnimations(-127, 2, N(idleAnimations_8021CD74));
    SetIdleGoal(-127, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleFlyToGoal(-127, 0, -5, 0);
    loop 20 {
    1:
        GetStatusFlags(-127, SI_VAR(1));
        if (SI_VAR(1) & 3526656) {
            sleep 1;
            goto 1;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 5;
    SetActorIdleSpeed(-127, 0.6);
    SetIdleGoal(-127, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleFlyToGoal(-127, 0, -5, 0);
    SetIdleAnimations(-127, 2, N(idleAnimations_8021CD28));
    loop 40 {
    2:
        GetStatusFlags(-127, SI_VAR(1));
        if (SI_VAR(1) & 3526656) {
            sleep 1;
            goto 2;
        }
        sleep 1;
    }
    goto 10;
});

Script N(8021D0E0) = SCRIPT({
    ResetAllActorSounds(-127);
    SetGoalToHome(ACTOR_SELF);
    SetActorSpeed(ACTOR_SELF, 7.0);
    FlyToGoal(-127, 0, 1, 11);
    SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, idle));
});

Script N(8021DF64);

Script N(handleEvent_8021D158) = SCRIPT({
    UseIdleAnimation(ACTOR_SELF, FALSE);
    EnableIdleScript(ACTOR_SELF, FALSE);
    GetLastEvent(ACTOR_SELF, SI_VAR(0));
    match SI_VAR(0) {
        EVENT_HIT_COMBO, EVENT_HIT {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, pain);
            await DoNormalHit;
            GetBattlePhase(SI_VAR(0));
            if (SI_VAR(0) == 1) {
                GetEncounterState(SI_VAR(0));
                if (SI_VAR(0) == 4) {
                    await N(8021DF64);
                }
            }
        }
        == EVENT_BURN_HIT {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, burn_pain);
            SI_VAR(2) = (const) NPC_ANIM(paragoomba, default, burn_dead);
            await DoBurnHit;
        }
        == EVENT_BURN_DEATH {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, burn_pain);
            SI_VAR(2) = (const) NPC_ANIM(paragoomba, default, burn_dead);
            await DoBurnHit;
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, burn_dead);
            await DoDeath;
            return;
        }
        == EVENT_FALL_TRIGGER {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, pain);
            await DoNormalHit;
            await N(8021DF64);
        }
        == 15 {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, burn_pain);
            SI_VAR(2) = (const) NPC_ANIM(paragoomba, default, burn_dead);
            await DoBurnHit;
            await N(8021DF64);
        }
        == EVENT_SHOCK_HIT {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, electrocute);
            await DoShockHit;
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, pain);
            await DoJumpBack;
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, dizzy));
            await N(8021D0E0);
        }
        == EVENT_SHOCK_DEATH {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, electrocute);
            await DoShockHit;
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, dead);
            await DoDeath;
            return;
        }
        == EVENT_STAR_BEAM, 23, EVENT_IMMUNE, EVENT_AIR_LIFT_FAILED {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, idle);
            await DoImmune;
        }
        == EVENT_DEATH {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, pain);
            await DoNormalHit;
            sleep 10;
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, dead);
            await DoDeath;
            return;
        }
        == EVENT_BEGIN_FIRST_STRIKE {
            SetActorPos(-127, 20, 0, 0);
            HPBarToCurrent(-127);
        }
        == EVENT_END_FIRST_STRIKE {
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, run));
            await N(8021D0E0);
            HPBarToHome(ACTOR_SELF);
        }
        == EVENT_RECOVER_STATUS {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, idle);
            await DoRecover;
        }
        == EVENT_SCARE_AWAY {
            SetActorFlagBits(-127, 512, 0);
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, run);
            SI_VAR(2) = (const) NPC_ANIM(paragoomba, default, pain);
            await DoScareAway;
            return;
        }
        == EVENT_BEGIN_AIR_LIFT {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, run);
            await DoAirLift;
        }
        == EVENT_BLOW_AWAY {
            SI_VAR(0) = (const) 2;
            SI_VAR(1) = (const) NPC_ANIM(paragoomba, default, pain);
            await DoBlowAway;
            return;
        }
        else {
        }
    }
    EnableIdleScript(ACTOR_SELF, FALSE);
    UseIdleAnimation(ACTOR_SELF, TRUE);
});

Script N(takeTurn_8021D74C) = SCRIPT({
    UseIdleAnimation(ACTOR_SELF, FALSE);
    EnableIdleScript(ACTOR_SELF, FALSE);
    SetTargetActor(ACTOR_SELF, ACTOR_PLAYER);
    SetGoalToTarget(ACTOR_SELF);
    UseBattleCamPreset(63);
    BattleCamTargetActor(ACTOR_SELF);
    func_8024ECF8(-1, 1, 0);
    SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, run));
    SetGoalToTarget(ACTOR_SELF);
    AddGoalPos(ACTOR_SELF, 50, 0, 0);
    SetActorSpeed(ACTOR_SELF, 6.0);
    FlyToGoal(-127, 0, -4, 0);
    EnemyTestTarget(ACTOR_SELF, SI_VAR(0), ((0)), 0, 1, 16);
    match SI_VAR(0) {
        HIT_RESULT_MISS, HIT_RESULT_LUCKY {
            SI_VAR(10) = SI_VAR(0);
            sleep 10;
            UseBattleCamPreset(66);
            SetBattleCamZoom(300);
            BattleCamTargetActor(ACTOR_SELF);
            func_8024ECF8(-1, 1, 0);
            PlaySoundAtActor(ACTOR_SELF, 0x20E0);
            SetActorSounds(-127, 2, 0, 0);
            SetActorSpeed(ACTOR_SELF, 5.0);
            SetActorJumpGravity(ACTOR_SELF, 1.8);
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, attack));
            GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(ACTOR_SELF, 10, FALSE, FALSE, FALSE);
            PlaySoundAtActor(ACTOR_SELF, SOUND_UNUSED_2C1);
            SetActorSounds(-127, 1, 0, 0);
            SetGoalToTarget(ACTOR_SELF);
            SI_VAR(0) -= 80;
            SI_VAR(1) = 20;
            SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetActorSpeed(ACTOR_SELF, 8.0);
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, attack));
            FlyToGoal(-127, 0, -10, 4);
            spawn {
                loop 4 {
                    PlaySoundAtActor(ACTOR_SELF, 0x20DF);
                    sleep 4;
                }
            }
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, aim));
            AddActorDecoration(ACTOR_SELF, 2, 0, 2);
            SetAnimationRate(ACTOR_SELF, 2, 3.0);
            sleep 10;
            if (SI_VAR(10) == 5) {
                EnemyTestTarget(ACTOR_SELF, SI_VAR(0), ((0x80000000)), 0, 0, 0);
            }
            sleep 10;
            SetAnimationRate(ACTOR_SELF, 2, 1.0);
            UseBattleCamPreset(2);
            ResetAllActorSounds(-127);
            YieldTurn();
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, run));
            SetActorYaw(ACTOR_SELF, 180);
            await N(8021D0E0);
            SetActorYaw(ACTOR_SELF, 0);
            RemoveActorDecoration(ACTOR_SELF, 2, 0);
            EnableIdleScript(ACTOR_SELF, FALSE);
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
            SetActorSounds(-127, 2, 0, 0);
            SetActorSpeed(ACTOR_SELF, 5.0);
            SetActorJumpGravity(ACTOR_SELF, 1.8);
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, attack));
            GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(ACTOR_SELF, 10, FALSE, FALSE, FALSE);
            PlaySoundAtActor(ACTOR_SELF, SOUND_UNUSED_2C1);
            SetActorSounds(-127, 1, 0, 0);
            SetGoalToTarget(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 8.0);
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, attack));
            FlyToGoal(-127, 0, -10, 0);
        }
    }
    sleep 2;
    EnemyDamageTarget(ACTOR_SELF, SI_VAR(0), ((0)), 0, 0, 1, 32);
    match SI_VAR(0) {
        HIT_RESULT_HIT, 2 {
            UseBattleCamPreset(2);
            SetGoalToTarget(ACTOR_SELF);
            AddGoalPos(ACTOR_SELF, 50, 10, 0);
            SetActorSpeed(ACTOR_SELF, 6.0);
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, run));
            FlyToGoal(-127, 0, -10, 0);
            ResetAllActorSounds(-127);
            sleep 5;
            YieldTurn();
            SetAnimation(ACTOR_SELF, 2, NPC_ANIM(paragoomba, default, run));
            await N(8021D0E0);
        }
    }
    EnableIdleScript(ACTOR_SELF, FALSE);
    UseIdleAnimation(ACTOR_SELF, TRUE);
});

Script N(8021E584);

#include "common/StartRumbleWithParams.inc.c"

Script N(8021DF64) = SCRIPT({
    func_8027D32C(-127);
    SetPartFlags(-127, 2, 131077);
    SetPartFlags(-127, 3, 1179652);
    SetPartFlags(-127, 4, 1179652);
    SetPartFlags(-127, 1, 8388612);
    GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPartPos(-127, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPartDispOffset(-127, 3, -9, 7, -2);
    SetPartPos(-127, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPartDispOffset(-127, 4, 11, 7, -2);
    GetLastEvent(ACTOR_SELF, SI_VAR(0));
    if (SI_VAR(0) == 15) {
        SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, burn_dead));
    } else {
        SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, pain));
    }
    SetActorSounds(-127, 2, 769, 0);
    GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) = 0;
    SetActorJumpGravity(ACTOR_SELF, 0.8);
    SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    JumpToGoal(ACTOR_SELF, 15, FALSE, TRUE, FALSE);
    N(StartRumbleWithParams)(100, 10);
    spawn {
        ShakeCam(1, 0, 5, 0.3);
    }
    ResetActorSounds(-127, 2);
    GetLastEvent(ACTOR_SELF, SI_VAR(3));
    if (SI_VAR(3) == 15) {
        SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, pain));
        GetActorPos(ACTOR_SELF, SI_VAR(3), SI_VAR(4), SI_VAR(5));
        SI_VAR(4) += 10;
        SI_VAR(5) += 5;
        PlayEffect(0x27, 0, SI_VAR(3), SI_VAR(4), SI_VAR(5), 1.0, 10, 0, 0, 0, 0, 0, 0, 0);
    }
    SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    JumpToGoal(ACTOR_SELF, 10, FALSE, TRUE, FALSE);
    SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    JumpToGoal(ACTOR_SELF, 5, FALSE, TRUE, FALSE);
    loop 10 {
        SetPartFlagBits(-127, 3, 1, 1);
        SetPartFlagBits(-127, 4, 1, 1);
        sleep 1;
        SetPartFlagBits(-127, 3, 1, 0);
        SetPartFlagBits(-127, 4, 1, 0);
        sleep 1;
    }
    SetPartFlagBits(-127, 3, 1, 1);
    SetPartFlagBits(-127, 4, 1, 1);
    GetIndexFromHome(-127, SI_VAR(0));
    SI_VAR(0) %= 4;
    SetGoalToIndex(-127, SI_VAR(0));
    GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetHomePos(-127, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
    SetActorFlagBits(-127, 512, 0);
    SetStatusTable(-127, N(statusTable_8021CB18));
    SetActorType(-127, 7);
    await N(8021E584);
    SetActorFlagBits(-127, 4096, 1);
    HPBarToHome(ACTOR_SELF);
    ResetAllActorSounds(-127);
});

s32 N(idleAnimations_8021E4EC)[] = {
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

s32 N(idleAnimations_8021E538)[] = {
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

Script N(takeTurn_8021F0D8);
Script N(idle_8021E5D0);
Script N(handleEvent_8021E8AC);

Script N(8021E584) = SCRIPT({
    BindTakeTurn(-127, N(takeTurn_8021F0D8));
    BindIdle(-127, N(idle_8021E5D0));
    BindHandleEvent(-127, N(handleEvent_8021E8AC));
});

Script N(idle_8021E5D0) = SCRIPT({
10:
    RandInt(80, SI_VAR(0));
    SI_VAR(0) += 80;
    loop SI_VAR(0) {
    0:
        GetStatusFlags(-127, SI_VAR(1));
        if (SI_VAR(1) & 3526656) {
            sleep 1;
            goto 0;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 5;
    SetActorIdleSpeed(-127, 1.0);
    SetIdleAnimations(-127, 1, N(idleAnimations_8021E538));
    SetIdleGoal(-127, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleRunToGoal(-127, 0);
    SetIdleAnimations(-127, 1, N(idleAnimations_8021E4EC));
    loop 20 {
    1:
        GetStatusFlags(-127, SI_VAR(1));
        if (SI_VAR(1) & 3526656) {
            sleep 1;
            goto 1;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 5;
    SetActorIdleSpeed(-127, 1.0);
    SetIdleAnimations(-127, 1, N(idleAnimations_8021E538));
    SetIdleGoal(-127, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleRunToGoal(-127, 0);
    SetIdleAnimations(-127, 1, N(idleAnimations_8021E4EC));
    loop 80 {
    2:
        GetStatusFlags(-127, SI_VAR(1));
        if (SI_VAR(1) & 3526656) {
            sleep 1;
            goto 2;
        }
        sleep 1;
    }
    goto 10;
});

Script N(handleEvent_8021E8AC) = SCRIPT({
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

Script N(takeTurn_8021F0D8) = SCRIPT({
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
