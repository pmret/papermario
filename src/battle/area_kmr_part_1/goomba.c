#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goomba.h"
#include "goomba.h"

#define NAMESPACE b_area_kmr_part_1

ApiStatus N(BattleAreaAngleStuff2)(ScriptInstance* script, s32 isInitialCall);

extern s32 goomba_anims_running[];
extern s32 goomba_anims[];
extern s32 goomba_defense_table[];
extern s32 goomba_status_table[];
extern s32 goomba_defense_table[];
extern ActorPartDesc goomba_parts[];
extern Script goomba_init;
extern Script goomba_turn;
extern Script goomba_idle;
extern Script goomba_dispatch;

s32 goomba_defense_table[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 goomba_status_table[] = {
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

ActorPartDesc goomba_parts[] = {
    {
        .flags = 0x00800000,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 0xFF,
        .idleAnimations = goomba_anims,
        .defenseTable = goomba_defense_table,
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        0x00, 0xF6,
    },
};

ActorDesc goomba = {
    .flags = 0,
    .type = ACTOR_TYPE_goomba,
    .level = 5,
    .maxHP = 2,
    .partCount = 1,
    .partsData = &goomba_parts,
    .script = &goomba_init,
    .statusTable = &goomba_status_table,
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

s32 goomba_anims[] = {
    STATUS_NORMAL, NPC_ANIM(goomba, normal, idle),
    STATUS_STONE, NPC_ANIM(goomba, normal, still),
    STATUS_SLEEP, NPC_ANIM(goomba, normal, asleep),
    STATUS_POISON, NPC_ANIM(goomba, normal, idle),
    STATUS_STOP, NPC_ANIM(goomba, normal, still),
    STATUS_STATIC, NPC_ANIM(goomba, normal, idle),
    STATUS_PARALYZE, NPC_ANIM(goomba, normal, still),
    STATUS_DIZZY, NPC_ANIM(goomba, normal, dizzy),
    STATUS_FEAR, NPC_ANIM(goomba, normal, dizzy),

    STATUS_END,
};

s32 goomba_anims_running[] = {
    STATUS_NORMAL, NPC_ANIM(goomba, normal, run),
    STATUS_STONE, NPC_ANIM(goomba, normal, still),
    STATUS_SLEEP, NPC_ANIM(goomba, normal, asleep),
    STATUS_POISON, NPC_ANIM(goomba, normal, idle),
    STATUS_STOP, NPC_ANIM(goomba, normal, still),
    STATUS_STATIC, NPC_ANIM(goomba, normal, run),
    STATUS_PARALYZE, NPC_ANIM(goomba, normal, still),
    STATUS_DIZZY, NPC_ANIM(goomba, normal, dizzy),
    STATUS_FEAR, NPC_ANIM(goomba, normal, dizzy),

    STATUS_END,
};

Script goomba_init = SCRIPT({
    BindTakeTurn(ACTOR_SELF, goomba_turn);
    BindIdle(ACTOR_SELF, goomba_idle);
    BindHandleEvent(ACTOR_SELF, goomba_dispatch);
});

Script goomba_idle = SCRIPT({
10:
    RandInt(80, SI_VAR(0));
    SI_VAR(0) += 80;
    loop SI_VAR(0) {
0:
        GetStatusFlags(ACTOR_SELF, SI_VAR(1));
        if (SI_VAR(1) & 0x35D000) {
            sleep 1;
            goto 0;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 5;
    SetActorIdleSpeed(ACTOR_SELF, 1.0);
    SetIdleAnimations(ACTOR_SELF, 1, goomba_anims_running);
    SetIdleGoal(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleRunToGoal(ACTOR_SELF, 0);
    SetIdleAnimations(ACTOR_SELF, 1, goomba_anims);
    loop 20 {
1:
        GetStatusFlags(ACTOR_SELF, SI_VAR(1));
        if (SI_VAR(1) & 0x35D000) {
            sleep 1;
            goto 1;
        }
        sleep 1;
    }
    GetActorPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 5;
    SetActorIdleSpeed(ACTOR_SELF, 1.0);
    SetIdleAnimations(ACTOR_SELF, 1, goomba_anims_running);
    SetIdleGoal(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleRunToGoal(ACTOR_SELF, 0);
    SetIdleAnimations(ACTOR_SELF, 1, goomba_anims);
    loop 80 {
2:
        GetStatusFlags(ACTOR_SELF, SI_VAR(1));
        if (SI_VAR(1) & 0x35D000) {
            sleep 1;
            goto 2;
        }
        sleep 1;
    }
    goto 10;
});

Script goomba_dispatch = SCRIPT({
    UseIdleAnimation(ACTOR_SELF, 0);
    EnableIdleScript(ACTOR_SELF, 0);
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
            JumpToGoal(ACTOR_SELF, 5, 0, 1, 0);
            SetAnimationRate(ACTOR_SELF, 1, 2.0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, dizzy));
            SetGoalToHome(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 8.0);
            RunToGoal(ACTOR_SELF, 0, 0);
            SetAnimationRate(ACTOR_SELF, 1, 1.0);
            sleep 5;
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
            SetActorJumpGravity(ACTOR_SELF, 1.6);
            JumpToGoal(ACTOR_SELF, 5, 0, 1, 0);
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
            RunToGoal(ACTOR_SELF, 0, 0);
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
        } else {
        }
    }
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
    EnableIdleScript(ACTOR_SELF, 1);
    UseIdleAnimation(ACTOR_SELF, 1);
});

f32 N(floatTable)[] = {
    0.000000f, 0.017452f, 0.034899f, 0.052336f, 0.069756f, 0.087156f, 0.104528f, 0.121869f,
    0.139173f, 0.156434f, 0.173648f, 0.190809f, 0.207912f, 0.224951f, 0.241922f, 0.258819f,
    0.275637f, 0.292372f, 0.309017f, 0.325568f, 0.342020f, 0.358368f, 0.374607f, 0.390731f,
    0.406737f, 0.422618f, 0.438371f, 0.453990f, 0.469472f, 0.484810f, 0.500000f, 0.515038f,
    0.529919f, 0.544639f, 0.559193f, 0.573576f, 0.587785f, 0.601815f, 0.615661f, 0.629320f,
    0.642788f, 0.656059f, 0.669131f, 0.681998f, 0.694658f, 0.707107f, 0.719340f, 0.731354f,
    0.743145f, 0.754710f, 0.766044f, 0.777146f, 0.788011f, 0.798636f, 0.809017f, 0.819152f,
    0.829038f, 0.838671f, 0.848048f, 0.857167f, 0.866025f, 0.874620f, 0.882948f, 0.891007f,
    0.898794f, 0.906308f, 0.913545f, 0.920505f, 0.927184f, 0.933580f, 0.939693f, 0.945519f,
    0.951057f, 0.956305f, 0.961262f, 0.965926f, 0.970296f, 0.974370f, 0.978148f, 0.981627f,
    0.984808f, 0.987688f, 0.990268f, 0.992546f, 0.994522f, 0.996195f, 0.997564f, 0.998630f,
    0.999391f, 0.999848f, 1.000000f,
};

Script goomba_turn = SCRIPT({
    UseIdleAnimation(ACTOR_SELF, 0);
    EnableIdleScript(ACTOR_SELF, 0);
    SetTargetActor(ACTOR_SELF, 0);
    UseBattleCamPreset(63);
    BattleCamTargetActor(ACTOR_SELF);
    0x8024ECF8(-1, 1, 0);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, run));
    SetGoalToTarget(ACTOR_SELF);
    AddGoalPos(ACTOR_SELF, 50, 0, 0);
    SetActorSpeed(ACTOR_SELF, 6.0);
    RunToGoal(ACTOR_SELF, 0, 0);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
    SetActorDispOffset(ACTOR_SELF, 0, -1, 0);
    sleep 1;
    SetActorDispOffset(ACTOR_SELF, 0, -2, 0);
    sleep 5;
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
    EnemyTestTarget(ACTOR_SELF, SI_VAR(0), 0, 0, 1, 16);
    match SI_VAR(0) {
        6, 5 {
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
                    N(BattleAreaAngleStuff2)(SI_VAR(1), SI_VAR(2), SI_VAR(4), SI_VAR(5), SI_VAR(0));
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
            JumpToGoal(ACTOR_SELF, 16, 0, 1, 0);
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
                EnemyTestTarget(ACTOR_SELF, SI_VAR(0), 0x80000000, 0, 0, 0);
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
            JumpToGoal(ACTOR_SELF, 15, 0, 1, 0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, dizzy));
            sleep 5;
            UseBattleCamPreset(2);
            YieldTurn();
            SetActorYaw(ACTOR_SELF, 180);
            AddActorDecoration(ACTOR_SELF, 1, 0, 2);
            SetAnimationRate(ACTOR_SELF, 1, 2.0);
            SetGoalToHome(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 8.0);
            RunToGoal(ACTOR_SELF, 0, 0);
            SetAnimationRate(ACTOR_SELF, 1, 1.0);
            SetActorYaw(ACTOR_SELF, 0);
            sleep 5;
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
            SetActorJumpGravity(ACTOR_SELF, 1.6);
            JumpToGoal(ACTOR_SELF, 5, 0, 1, 0);
            RemoveActorDecoration(ACTOR_SELF, 1, 0);
            EnableIdleScript(ACTOR_SELF, 1);
            UseIdleAnimation(ACTOR_SELF, 1);
            return;
        } else {
            SetGoalToTarget(ACTOR_SELF);
            SetActorJumpGravity(ACTOR_SELF, 1.2);
            spawn {
                GetActorPos(ACTOR_SELF, SI_VAR(1), SI_VAR(2), SI_VAR(0));
                SI_VAR(0) = 0;
                loop 16 {
                    GetActorPos(ACTOR_SELF, SI_VAR(4), SI_VAR(5), SI_VAR(6));
                    N(BattleAreaAngleStuff2)(SI_VAR(1), SI_VAR(2), SI_VAR(4), SI_VAR(5), SI_VAR(0));
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
            JumpToGoal(ACTOR_SELF, 16, 0, 1, 0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, pre_headbonk));
            SetActorScale(ACTOR_SELF, 1.1, 0.8, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.3, 0.5, 1.0);
            sleep 1;
        }
    }
    EnemyDamageTarget(ACTOR_SELF, SI_VAR(0), 0, 0, 0, 1, 32);
    match SI_VAR(0) {
        0, 2 {
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
            JumpToGoal(ACTOR_SELF, 10, 0, 1, 0);
            SI_VAR(0) += 30;
            SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(ACTOR_SELF, 8, 0, 1, 0);
            SI_VAR(0) += 20;
            SetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(ACTOR_SELF, 6, 0, 1, 0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, idle));
            sleep 3;
            YieldTurn();
            SetAnimationRate(ACTOR_SELF, 1, 2.0);
            SetAnimation(ACTOR_SELF, 1, NPC_ANIM(goomba, normal, run));
            SetGoalToHome(ACTOR_SELF);
            SetActorSpeed(ACTOR_SELF, 8.0);
            RunToGoal(ACTOR_SELF, 0, 0);
            SetAnimationRate(ACTOR_SELF, 1, 1.0);
        }
    }
    EnableIdleScript(ACTOR_SELF, 1);
    UseIdleAnimation(ACTOR_SELF, 1);
});

