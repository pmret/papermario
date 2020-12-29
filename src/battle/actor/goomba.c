#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goomba.h"
#include "goomba.h"

ApiStatus func_8021818C_430B2C(ScriptInstance* script, s32 isInitialCall);
s32 idleAnimations_80219760[];
s32 idleAnimations_80219714[];
s32 defenseTable_80219610[];
s32 statusTable_8021961C[];
s32 defenseTable_80219610[];
ActorPartDesc partsTable_802196C8[];
Script script_Init_802197AC;
Script script_TakeTurn_8021A300;
Script script_Idle_802197F8;
Script script_HandleEvent_80219AD4;

// 431FB0-431FBC (VRAM: 80219610)
s32 defenseTable_80219610[] = {
    Element_NORMAL, 0,

    Element_END,
};

// 431FBC-432068 (VRAM: 8021961C)
s32 statusTable_8021961C[] = {
    Debuff_NORMAL, 0,
    Debuff_DEFAULT, 0,
    Debuff_SLEEP, 100,
    Debuff_POISON, 100,
    Debuff_FROZEN, 100,
    Debuff_DIZZY, 100,
    Debuff_FEAR, 100,
    Debuff_STATIC, 100,
    Debuff_PARALYZE, 100,
    Debuff_SHRINK, 100,
    Debuff_STOP, 100,

    Debuff_DEFAULT_TURN_MOD, 0,
    Debuff_SLEEP_TURN_MOD, 0,
    Debuff_POISON_TURN_MOD, 0,
    Debuff_FROZEN_TURN_MOD, 0,
    Debuff_DIZZY_TURN_MOD, 0,
    Debuff_FEAR_TURN_MOD, 0,
    Debuff_STATIC_TURN_MOD, 0,
    Debuff_PARALYZE_TURN_MOD, 0,
    Debuff_SHRINK_TURN_MOD, 0,
    Debuff_STOP_TURN_MOD, 0,

    Debuff_END,
};

// 432068-43208C (VRAM: 802196C8)
ActorPartDesc partsTable_802196C8[] = {
    {
        .flags = 0x00800000,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0x14 },
        .opacity = 0xFF,
        .idleAnimations = idleAnimations_80219714,
        .defenseTable = defenseTable_80219610,
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        0x00, 0xF6,
    },
};

// 43208C-4320B4 (VRAM: 802196EC)
ActorDesc goomba = {
    .flags = 0,
    .type = 7,
    .level = 5,
    .maxHP = 2,
    .partCount = 1,
    .partsData = &partsTable_802196C8,
    .script = &script_Init_802197AC,
    .statusTable = &statusTable_8021961C,
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

// 4320B4-432100 (VRAM: 80219714)
s32 idleAnimations_80219714[] = {
    Debuff_NORMAL, NPC_ANIM(goomba, normal, idle),
    Debuff_STONE, NPC_ANIM(goomba, normal, still),
    Debuff_SLEEP, NPC_ANIM(goomba, normal, asleep),
    Debuff_POISON, NPC_ANIM(goomba, normal, idle),
    Debuff_STOP, NPC_ANIM(goomba, normal, still),
    Debuff_STATIC, NPC_ANIM(goomba, normal, idle),
    Debuff_PARALYZE, NPC_ANIM(goomba, normal, still),
    Debuff_DIZZY, NPC_ANIM(goomba, normal, dizzy),
    Debuff_FEAR, NPC_ANIM(goomba, normal, dizzy),

    Debuff_END,
};

// 432100-43214C (VRAM: 80219760)
s32 idleAnimations_80219760[] = {
    Debuff_NORMAL, NPC_ANIM(goomba, normal, run),
    Debuff_STONE, NPC_ANIM(goomba, normal, still),
    Debuff_SLEEP, NPC_ANIM(goomba, normal, asleep),
    Debuff_POISON, NPC_ANIM(goomba, normal, idle),
    Debuff_STOP, NPC_ANIM(goomba, normal, still),
    Debuff_STATIC, NPC_ANIM(goomba, normal, run),
    Debuff_PARALYZE, NPC_ANIM(goomba, normal, still),
    Debuff_DIZZY, NPC_ANIM(goomba, normal, dizzy),
    Debuff_FEAR, NPC_ANIM(goomba, normal, dizzy),

    Debuff_END,
};

// 43214C-432198 (VRAM: 802197AC)
Script script_Init_802197AC = SCRIPT({
    BindTakeTurn(ActorID_SELF, script_TakeTurn_8021A300);
    BindIdle(ActorID_SELF, script_Idle_802197F8);
    BindHandleEvent(ActorID_SELF, script_HandleEvent_80219AD4);
});

// 432198-432474 (VRAM: 802197F8)
Script script_Idle_802197F8 = SCRIPT({
10:
    RandInt(80, SI_VAR(0));
    SI_VAR(0) += 80;
    loop SI_VAR(0) {
0:
        GetStatusFlags(ActorID_SELF, SI_VAR(1));
        if (SI_VAR(1) & 0x35D000) {
            sleep 1;
            goto 0;
        }
        sleep 1;
    }
    GetActorPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 5;
    SetActorIdleSpeed(ActorID_SELF, 1.0);
    SetIdleAnimations(ActorID_SELF, 1, idleAnimations_80219760);
    SetIdleGoal(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleRunToGoal(ActorID_SELF, 0);
    SetIdleAnimations(ActorID_SELF, 1, idleAnimations_80219714);
    loop 20 {
1:
        GetStatusFlags(ActorID_SELF, SI_VAR(1));
        if (SI_VAR(1) & 0x35D000) {
            sleep 1;
            goto 1;
        }
        sleep 1;
    }
    GetActorPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 5;
    SetActorIdleSpeed(ActorID_SELF, 1.0);
    SetIdleAnimations(ActorID_SELF, 1, idleAnimations_80219760);
    SetIdleGoal(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleRunToGoal(ActorID_SELF, 0);
    SetIdleAnimations(ActorID_SELF, 1, idleAnimations_80219714);
    loop 80 {
2:
        GetStatusFlags(ActorID_SELF, SI_VAR(1));
        if (SI_VAR(1) & 0x35D000) {
            sleep 1;
            goto 2;
        }
        sleep 1;
    }
    goto 10;
});

// 432474-432B34 (VRAM: 80219AD4)
Script script_HandleEvent_80219AD4 = SCRIPT({
    UseIdleAnimation(ActorID_SELF, 0);
    EnableIdleScript(ActorID_SELF, 0);
    SetActorScale(ActorID_SELF, 1.0, 1.0, 1.0);
    GetLastEvent(ActorID_SELF, SI_VAR(0));
    match SI_VAR(0) {
        9, 10 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, pain);
            await DoNormalHit;
        }
        == 14 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, burn_pain);
            SI_VAR(2) = c NPC_ANIM(goomba, normal, burn_dead);
            await DoBurnHit;
        }
        == 36 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, burn_pain);
            SI_VAR(2) = c NPC_ANIM(goomba, normal, burn_dead);
            await DoBurnHit;
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, burn_dead);
            await DoDeath;
            return;
        }
        == 11 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, pain);
            await DoSpinSmashHit;
        }
        == 33 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, pain);
            await DoSpinSmashHit;
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, dead);
            await DoDeath;
            return;
        }
        == 47 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, electrocute);
            await DoShockHit;
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, pain);
            await DoJumpBack;
            JumpToGoal(ActorID_SELF, 5, 0, 1, 0);
            SetAnimationRate(ActorID_SELF, 1, 2.0);
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, dizzy));
            SetGoalToHome(ActorID_SELF);
            SetActorSpeed(ActorID_SELF, 8.0);
            RunToGoal(ActorID_SELF, 0, 0);
            SetAnimationRate(ActorID_SELF, 1, 1.0);
            sleep 5;
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, idle));
            SetActorJumpGravity(ActorID_SELF, 1.6);
            JumpToGoal(ActorID_SELF, 5, 0, 1, 0);
        }
        == 38 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, electrocute);
            await DoShockHit;
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, dead);
            await DoDeath;
            return;
        }
        == 19, 23, 25, 31 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, idle);
            await DoImmune;
        }
        == 32 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, pain);
            await DoNormalHit;
            sleep 10;
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, dead);
            await DoDeath;
            return;
        }
        == 53 {
            SetAnimationRate(ActorID_SELF, 1, 2.0);
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, run));
            SetGoalToHome(ActorID_SELF);
            SetActorSpeed(ActorID_SELF, 4.0);
            RunToGoal(ActorID_SELF, 0, 0);
            SetAnimationRate(ActorID_SELF, 1, 1.0);
            HPBarToHome(ActorID_SELF);
        }
        == 49 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, idle);
            await DoRecover;
        }
        == 57 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, run);
            SI_VAR(2) = c NPC_ANIM(goomba, normal, pain);
            await DoScareAway;
            return;
        }
        == 58 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, run);
            await DoAirLift;
        }
        == 22 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c NPC_ANIM(goomba, normal, pain);
            await DoBlowAway;
            return;
        } else {
        }
    }
    SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, idle));
    EnableIdleScript(ActorID_SELF, 1);
    UseIdleAnimation(ActorID_SELF, 1);
});

// 432B34-432CA0 (VRAM: 8021A194)
f32 floatTable_8021A194[] = {
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

// 432CA0-433968 (VRAM: 8021A300)
Script script_TakeTurn_8021A300 = SCRIPT({
    UseIdleAnimation(ActorID_SELF, 0);
    EnableIdleScript(ActorID_SELF, 0);
    SetTargetActor(ActorID_SELF, 0);
    UseCamPreset(63);
    BattleCamTargetActor(ActorID_SELF);
    0x8024ECF8(-1, 1, 0);
    SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, run));
    SetGoalToTarget(ActorID_SELF);
    AddGoalPos(ActorID_SELF, 50, 0, 0);
    SetActorSpeed(ActorID_SELF, 6.0);
    RunToGoal(ActorID_SELF, 0, 0);
    SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, idle));
    SetActorDispOffset(ActorID_SELF, 0, -1, 0);
    sleep 1;
    SetActorDispOffset(ActorID_SELF, 0, -2, 0);
    sleep 5;
    SetActorDispOffset(ActorID_SELF, 0, 0, 0);
    SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
    EnemyTestTarget(ActorID_SELF, SI_VAR(0), 0, 0, 1, 16);
    match SI_VAR(0) {
        6, 5 {
            SI_VAR(10) = SI_VAR(0);
            SetGoalToTarget(ActorID_SELF);
            GetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) -= 10;
            SI_VAR(1) = 10;
            SI_VAR(2) += 3;
            SetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetActorJumpGravity(ActorID_SELF, 1.2);
            spawn {
                GetActorPos(ActorID_SELF, SI_VAR(1), SI_VAR(2), SI_VAR(0));
                SI_VAR(0) = 0;
                loop 16 {
                    GetActorPos(ActorID_SELF, SI_VAR(4), SI_VAR(5), SI_VAR(6));
                    func_8021818C_430B2C(SI_VAR(1), SI_VAR(2), SI_VAR(4), SI_VAR(5), SI_VAR(0));
                    SetActorRotation(ActorID_SELF, 0, 0, SI_VAR(0));
                    SI_VAR(1) = SI_VAR(4);
                    SI_VAR(2) = SI_VAR(5);
                    SI_VAR(3) = SI_VAR(6);
                    sleep 1;
                }
            }
            spawn {
                sleep 6;
                SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
            }
            JumpToGoal(ActorID_SELF, 16, 0, 1, 0);
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, asleep));
            SetActorScale(ActorID_SELF, 1.1, 0.8, 1.0);
            SetActorDispOffset(ActorID_SELF, 0, 5, 0);
            sleep 1;
            SetActorScale(ActorID_SELF, 1.3, 0.5, 1.0);
            SetActorDispOffset(ActorID_SELF, 0, -2, 0);
            sleep 1;
            SetActorScale(ActorID_SELF, 1.0, 1.0, 1.0);
            SetActorDispOffset(ActorID_SELF, 0, 7, 0);
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, pain));
            sleep 5;
            if (SI_VAR(10) == 5) {
                EnemyTestTarget(ActorID_SELF, SI_VAR(0), 0x80000000, 0, 0, 0);
            }
            sleep 5;
            SetActorDispOffset(ActorID_SELF, 0, 0, 0);
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
            SetGoalToTarget(ActorID_SELF);
            GetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) += 20;
            SI_VAR(1) = 0;
            SetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetActorJumpGravity(ActorID_SELF, 2.0);
            spawn {
                sleep 4;
                SI_VAR(0) = 180;
                loop 4 {
                    SI_VAR(0) -= 45;
                    SetActorRotation(ActorID_SELF, 0, 0, SI_VAR(0));
                    sleep 1;
                }
                SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
            }
            JumpToGoal(ActorID_SELF, 15, 0, 1, 0);
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, dizzy));
            sleep 5;
            UseCamPreset(2);
            YieldTurn();
            SetActorYaw(ActorID_SELF, 180);
            AddActorDecoration(ActorID_SELF, 1, 0, 2);
            SetAnimationRate(ActorID_SELF, 1, 2.0);
            SetGoalToHome(ActorID_SELF);
            SetActorSpeed(ActorID_SELF, 8.0);
            RunToGoal(ActorID_SELF, 0, 0);
            SetAnimationRate(ActorID_SELF, 1, 1.0);
            SetActorYaw(ActorID_SELF, 0);
            sleep 5;
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, idle));
            SetActorJumpGravity(ActorID_SELF, 1.6);
            JumpToGoal(ActorID_SELF, 5, 0, 1, 0);
            RemoveActorDecoration(ActorID_SELF, 1, 0);
            EnableIdleScript(ActorID_SELF, 1);
            UseIdleAnimation(ActorID_SELF, 1);
            return;
        } else {
            SetGoalToTarget(ActorID_SELF);
            SetActorJumpGravity(ActorID_SELF, 1.2);
            spawn {
                GetActorPos(ActorID_SELF, SI_VAR(1), SI_VAR(2), SI_VAR(0));
                SI_VAR(0) = 0;
                loop 16 {
                    GetActorPos(ActorID_SELF, SI_VAR(4), SI_VAR(5), SI_VAR(6));
                    func_8021818C_430B2C(SI_VAR(1), SI_VAR(2), SI_VAR(4), SI_VAR(5), SI_VAR(0));
                    SetActorRotation(ActorID_SELF, 0, 0, SI_VAR(0));
                    SI_VAR(1) = SI_VAR(4);
                    SI_VAR(2) = SI_VAR(5);
                    SI_VAR(3) = SI_VAR(6);
                    sleep 1;
                }
            }
            spawn {
                sleep 6;
                SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, headbonk));
            }
            JumpToGoal(ActorID_SELF, 16, 0, 1, 0);
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, pre_headbonk));
            SetActorScale(ActorID_SELF, 1.1, 0.8, 1.0);
            sleep 1;
            SetActorScale(ActorID_SELF, 1.3, 0.5, 1.0);
            sleep 1;
        }
    }
    EnemyDamageTarget(ActorID_SELF, SI_VAR(0), 0, 0, 0, 1, 32);
    match SI_VAR(0) {
        0, 2 {
            UseCamPreset(2);
            SetActorScale(ActorID_SELF, 1.1, 0.8, 1.0);
            sleep 1;
            SetActorScale(ActorID_SELF, 1.0, 1.0, 1.0);
            sleep 1;
            SetActorRotation(ActorID_SELF, 0, 0, 0);
            SetActorDispOffset(ActorID_SELF, 0, 0, 0);
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, idle));
            GetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) += 40;
            SI_VAR(1) = 0;
            SetActorJumpGravity(ActorID_SELF, 1.8);
            SetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(ActorID_SELF, 10, 0, 1, 0);
            SI_VAR(0) += 30;
            SetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(ActorID_SELF, 8, 0, 1, 0);
            SI_VAR(0) += 20;
            SetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(ActorID_SELF, 6, 0, 1, 0);
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, idle));
            sleep 3;
            YieldTurn();
            SetAnimationRate(ActorID_SELF, 1, 2.0);
            SetAnimation(ActorID_SELF, 1, NPC_ANIM(goomba, normal, run));
            SetGoalToHome(ActorID_SELF);
            SetActorSpeed(ActorID_SELF, 8.0);
            RunToGoal(ActorID_SELF, 0, 0);
            SetAnimationRate(ActorID_SELF, 1, 1.0);
        }
    }
    EnableIdleScript(ActorID_SELF, 1);
    UseIdleAnimation(ActorID_SELF, 1);
});

