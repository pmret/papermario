#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "goomba.h"

ApiStatus func_8021818C_430B2C(ScriptInstance* script, s32 isInitialCall);
s32 idleAnimations_80219760[];
s32 idleAnimations_80219714[];
s32 defenseTable_80219610[];
s32 statusTable_8021961C[];
s32 defenseTable_80219610[];
s32 partsTable_802196C8[];
Script script_Init_802197AC;
Script script_TakeTurn_8021A300;
Script script_Idle_802197F8;
Script script_HandleEvent_80219AD4;

// 431FB0-431FBC (VRAM: 80219610)
s32 defenseTable_80219610[] = {
    0x00000001, 0x00000000, 0x00000000,
};

// 431FBC-432068 (VRAM: 8021961C)
s32 statusTable_8021961C[] = {
    0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000006, 0x00000064, 0x00000009, 0x00000064,
    0x00000007, 0x00000064, 0x00000004, 0x00000064, 0x00000003, 0x00000064, 0x0000000B, 0x00000064,
    0x00000005, 0x00000064, 0x0000000A, 0x00000064, 0x00000008, 0x00000064, 0x0000001F, 0x00000000,
    0x00000020, 0x00000000, 0x00000025, 0x00000000, 0x00000022, 0x00000000, 0x00000024, 0x00000000,
    0x00000023, 0x00000000, 0x00000021, 0x00000000, 0x00000026, 0x00000000, 0x00000027, 0x00000000,
    0x00000029, 0x00000000, 0x00000000,
};

// 432068-43208C (VRAM: 802196C8)
s32 partsTable_802196C8[] = {
    0x00800000, 0x01000000, 0x001400FF, idleAnimations_80219714, defenseTable_80219610, 0x00000000, 0x00000000, 0x00F60000,
    0x00000000,
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
    0x00000001, 0x00260001, 0x0000000C, 0x00260000, 0x00000006, 0x00260008, 0x00000009, 0x00260001,
    0x00000008, 0x00260000, 0x0000000B, 0x00260001, 0x00000005, 0x00260000, 0x00000004, 0x00260007,
    0x00000003, 0x00260007, 0x00000000,
};

// 432100-43214C (VRAM: 80219760)
s32 idleAnimations_80219760[] = {
    0x00000001, 0x00260003, 0x0000000C, 0x00260000, 0x00000006, 0x00260008, 0x00000009, 0x00260001,
    0x00000008, 0x00260000, 0x0000000B, 0x00260003, 0x00000005, 0x00260000, 0x00000004, 0x00260007,
    0x00000003, 0x00260007, 0x00000000,
};

// 43214C-432198 (VRAM: 802197AC)
Script script_Init_802197AC = SCRIPT({
    BindTakeTurn(0xFFFFFF81, script_TakeTurn_8021A300);
    BindIdle(0xFFFFFF81, script_Idle_802197F8);
    BindHandleEvent(0xFFFFFF81, script_HandleEvent_80219AD4);
});

// 432198-432474 (VRAM: 802197F8)
Script script_Idle_802197F8 = SCRIPT({
10:
    RandInt(80, SI_VAR(0));
    SI_VAR(0) += 80;
    loop SI_VAR(0) {
0:
        GetStatusFlags(0xFFFFFF81, SI_VAR(1));
        if (SI_VAR(1) ? 0x35D000) {
            sleep 1;
            goto 0;
        }
        sleep 1;
    }
    GetActorPos(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 5;
    SetActorIdleSpeed(0xFFFFFF81, 1.0);
    SetIdleAnimations(0xFFFFFF81, 1, idleAnimations_80219760);
    SetIdleGoal(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleRunToGoal(0xFFFFFF81, 0);
    SetIdleAnimations(0xFFFFFF81, 1, idleAnimations_80219714);
    loop 20 {
1:
        GetStatusFlags(0xFFFFFF81, SI_VAR(1));
        if (SI_VAR(1) ? 0x35D000) {
            sleep 1;
            goto 1;
        }
        sleep 1;
    }
    GetActorPos(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 5;
    SetActorIdleSpeed(0xFFFFFF81, 1.0);
    SetIdleAnimations(0xFFFFFF81, 1, idleAnimations_80219760);
    SetIdleGoal(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    IdleRunToGoal(0xFFFFFF81, 0);
    SetIdleAnimations(0xFFFFFF81, 1, idleAnimations_80219714);
    loop 80 {
2:
        GetStatusFlags(0xFFFFFF81, SI_VAR(1));
        if (SI_VAR(1) ? 0x35D000) {
            sleep 1;
            goto 2;
        }
        sleep 1;
    }
    goto 10;
});

// 432474-432B34 (VRAM: 80219AD4)
Script script_HandleEvent_80219AD4 = SCRIPT({
    UseIdleAnimation(0xFFFFFF81, 0);
    EnableIdleScript(0xFFFFFF81, 0);
    SetActorScale(0xFFFFFF81, 1.0, 1.0, 1.0);
    GetLastEvent(0xFFFFFF81, SI_VAR(0));
    match SI_VAR(0) {
        9, 10 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260005;
            await DoNormalHit;
        }
        == 14 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260009;
            SI_VAR(2) = c 0x26000A;
            await DoBurnHit;
        }
        == 36 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260009;
            SI_VAR(2) = c 0x26000A;
            await DoBurnHit;
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x26000A;
            await DoDeath;
            return;
        }
        == 11 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260005;
            await DoSpinSmashHit;
        }
        == 33 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260005;
            await DoSpinSmashHit;
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260006;
            await DoDeath;
            return;
        }
        == 47 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x26000E;
            await DoShockHit;
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260005;
            await DoJumpBack;
            JumpToGoal(0xFFFFFF81, 5, 0, 1, 0);
            SetAnimationRate(0xFFFFFF81, 1, 2.0);
            SetAnimation(0xFFFFFF81, 1, 0x260007);
            SetGoalToHome(0xFFFFFF81);
            SetActorSpeed(0xFFFFFF81, 8.0);
            RunToGoal(0xFFFFFF81, 0, 0);
            SetAnimationRate(0xFFFFFF81, 1, 1.0);
            sleep 5;
            SetAnimation(0xFFFFFF81, 1, 0x260001);
            SetActorJumpGravity(0xFFFFFF81, 1.6005859375);
            JumpToGoal(0xFFFFFF81, 5, 0, 1, 0);
        }
        == 38 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x26000E;
            await DoShockHit;
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260006;
            await DoDeath;
            return;
        }
        == 19, 23, 25, 31 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260001;
            await DoImmune;
        }
        == 32 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260005;
            await DoNormalHit;
            sleep 10;
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260006;
            await DoDeath;
            return;
        }
        == 53 {
            SetAnimationRate(0xFFFFFF81, 1, 2.0);
            SetAnimation(0xFFFFFF81, 1, 0x260003);
            SetGoalToHome(0xFFFFFF81);
            SetActorSpeed(0xFFFFFF81, 4.0);
            RunToGoal(0xFFFFFF81, 0, 0);
            SetAnimationRate(0xFFFFFF81, 1, 1.0);
            HPBarToHome(0xFFFFFF81);
        }
        == 49 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260001;
            await DoRecover;
        }
        == 57 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260003;
            SI_VAR(2) = c 0x260005;
            await DoScareAway;
            return;
        }
        == 58 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260003;
            await DoAirLift;
        }
        == 22 {
            SI_VAR(0) = c 0x1;
            SI_VAR(1) = c 0x260005;
            await DoBlowAway;
            return;
        } else {
        }
    }
    SetAnimation(0xFFFFFF81, 1, 0x260001);
    EnableIdleScript(0xFFFFFF81, 1);
    UseIdleAnimation(0xFFFFFF81, 1);
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
    UseIdleAnimation(0xFFFFFF81, 0);
    EnableIdleScript(0xFFFFFF81, 0);
    SetTargetActor(0xFFFFFF81, 0);
    UseCamPreset(63);
    BattleCamTargetActor(0xFFFFFF81);
    0x8024ECF8(-1, 1, 0);
    SetAnimation(0xFFFFFF81, 1, 0x260003);
    SetGoalToTarget(0xFFFFFF81);
    AddGoalPos(0xFFFFFF81, 50, 0, 0);
    SetActorSpeed(0xFFFFFF81, 6.0);
    RunToGoal(0xFFFFFF81, 0, 0);
    SetAnimation(0xFFFFFF81, 1, 0x260001);
    SetActorDispOffset(0xFFFFFF81, 0, -1, 0);
    sleep 1;
    SetActorDispOffset(0xFFFFFF81, 0, 0xFFFFFFFE, 0);
    sleep 5;
    SetActorDispOffset(0xFFFFFF81, 0, 0, 0);
    SetAnimation(0xFFFFFF81, 1, 0x260004);
    EnemyTestTarget(0xFFFFFF81, SI_VAR(0), 0, 0, 1, 16);
    match SI_VAR(0) {
        6, 5 {
            SI_VAR(10) = SI_VAR(0);
            SetGoalToTarget(0xFFFFFF81);
            GetGoalPos(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) -= 10;
            SI_VAR(1) = 10;
            SI_VAR(2) += 3;
            SetGoalPos(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetActorJumpGravity(0xFFFFFF81, 1.2001953125);
            spawn {
                GetActorPos(0xFFFFFF81, SI_VAR(1), SI_VAR(2), SI_VAR(0));
                SI_VAR(0) = 0;
                loop 16 {
                    GetActorPos(0xFFFFFF81, SI_VAR(4), SI_VAR(5), SI_VAR(6));
                    func_8021818C_430B2C(SI_VAR(1), SI_VAR(2), SI_VAR(4), SI_VAR(5), SI_VAR(0));
                    SetActorRotation(0xFFFFFF81, 0, 0, SI_VAR(0));
                    SI_VAR(1) = SI_VAR(4);
                    SI_VAR(2) = SI_VAR(5);
                    SI_VAR(3) = SI_VAR(6);
                    sleep 1;
                }
            }
            spawn {
                sleep 6;
                SetAnimation(0xFFFFFF81, 1, 0x260004);
            }
            JumpToGoal(0xFFFFFF81, 16, 0, 1, 0);
            SetAnimation(0xFFFFFF81, 1, 0x260008);
            SetActorScale(0xFFFFFF81, 1.1005859375, 0.80078125, 1.0);
            SetActorDispOffset(0xFFFFFF81, 0, 5, 0);
            sleep 1;
            SetActorScale(0xFFFFFF81, 1.30078125, 0.5, 1.0);
            SetActorDispOffset(0xFFFFFF81, 0, 0xFFFFFFFE, 0);
            sleep 1;
            SetActorScale(0xFFFFFF81, 1.0, 1.0, 1.0);
            SetActorDispOffset(0xFFFFFF81, 0, 7, 0);
            SetAnimation(0xFFFFFF81, 1, 0x260005);
            sleep 5;
            if (SI_VAR(10) == 5) {
                EnemyTestTarget(0xFFFFFF81, SI_VAR(0), 0x80000000, 0, 0, 0);
            }
            sleep 5;
            SetActorDispOffset(0xFFFFFF81, 0, 0, 0);
            SetAnimation(0xFFFFFF81, 1, 0x260004);
            SetGoalToTarget(0xFFFFFF81);
            GetGoalPos(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) += 20;
            SI_VAR(1) = 0;
            SetGoalPos(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetActorJumpGravity(0xFFFFFF81, 2.0);
            spawn {
                sleep 4;
                SI_VAR(0) = 180;
                loop 4 {
                    SI_VAR(0) -= 45;
                    SetActorRotation(0xFFFFFF81, 0, 0, SI_VAR(0));
                    sleep 1;
                }
                SetAnimation(0xFFFFFF81, 1, 0x260004);
            }
            JumpToGoal(0xFFFFFF81, 15, 0, 1, 0);
            SetAnimation(0xFFFFFF81, 1, 0x260007);
            sleep 5;
            UseCamPreset(2);
            YieldTurn();
            SetActorYaw(0xFFFFFF81, 180);
            AddActorDecoration(0xFFFFFF81, 1, 0, 2);
            SetAnimationRate(0xFFFFFF81, 1, 2.0);
            SetGoalToHome(0xFFFFFF81);
            SetActorSpeed(0xFFFFFF81, 8.0);
            RunToGoal(0xFFFFFF81, 0, 0);
            SetAnimationRate(0xFFFFFF81, 1, 1.0);
            SetActorYaw(0xFFFFFF81, 0);
            sleep 5;
            SetAnimation(0xFFFFFF81, 1, 0x260001);
            SetActorJumpGravity(0xFFFFFF81, 1.6005859375);
            JumpToGoal(0xFFFFFF81, 5, 0, 1, 0);
            RemoveActorDecoration(0xFFFFFF81, 1, 0);
            EnableIdleScript(0xFFFFFF81, 1);
            UseIdleAnimation(0xFFFFFF81, 1);
            return;
        } else {
            SetGoalToTarget(0xFFFFFF81);
            SetActorJumpGravity(0xFFFFFF81, 1.2001953125);
            spawn {
                GetActorPos(0xFFFFFF81, SI_VAR(1), SI_VAR(2), SI_VAR(0));
                SI_VAR(0) = 0;
                loop 16 {
                    GetActorPos(0xFFFFFF81, SI_VAR(4), SI_VAR(5), SI_VAR(6));
                    func_8021818C_430B2C(SI_VAR(1), SI_VAR(2), SI_VAR(4), SI_VAR(5), SI_VAR(0));
                    SetActorRotation(0xFFFFFF81, 0, 0, SI_VAR(0));
                    SI_VAR(1) = SI_VAR(4);
                    SI_VAR(2) = SI_VAR(5);
                    SI_VAR(3) = SI_VAR(6);
                    sleep 1;
                }
            }
            spawn {
                sleep 6;
                SetAnimation(0xFFFFFF81, 1, 0x260004);
            }
            JumpToGoal(0xFFFFFF81, 16, 0, 1, 0);
            SetAnimation(0xFFFFFF81, 1, 0x26000B);
            SetActorScale(0xFFFFFF81, 1.1005859375, 0.80078125, 1.0);
            sleep 1;
            SetActorScale(0xFFFFFF81, 1.30078125, 0.5, 1.0);
            sleep 1;
        }
    }
    EnemyDamageTarget(0xFFFFFF81, SI_VAR(0), 0, 0, 0, 1, 32);
    match SI_VAR(0) {
        0, 2 {
            UseCamPreset(2);
            SetActorScale(0xFFFFFF81, 1.1005859375, 0.80078125, 1.0);
            sleep 1;
            SetActorScale(0xFFFFFF81, 1.0, 1.0, 1.0);
            sleep 1;
            SetActorRotation(0xFFFFFF81, 0, 0, 0);
            SetActorDispOffset(0xFFFFFF81, 0, 0, 0);
            SetAnimation(0xFFFFFF81, 1, 0x260001);
            GetGoalPos(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) += 40;
            SI_VAR(1) = 0;
            SetActorJumpGravity(0xFFFFFF81, 1.80078125);
            SetGoalPos(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(0xFFFFFF81, 10, 0, 1, 0);
            SI_VAR(0) += 30;
            SetGoalPos(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(0xFFFFFF81, 8, 0, 1, 0);
            SI_VAR(0) += 20;
            SetGoalPos(0xFFFFFF81, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            JumpToGoal(0xFFFFFF81, 6, 0, 1, 0);
            SetAnimation(0xFFFFFF81, 1, 0x260001);
            sleep 3;
            YieldTurn();
            SetAnimationRate(0xFFFFFF81, 1, 2.0);
            SetAnimation(0xFFFFFF81, 1, 0x260003);
            SetGoalToHome(0xFFFFFF81);
            SetActorSpeed(0xFFFFFF81, 8.0);
            RunToGoal(0xFFFFFF81, 0, 0);
            SetAnimationRate(0xFFFFFF81, 1, 1.0);
        }
    }
    EnableIdleScript(0xFFFFFF81, 1);
    UseIdleAnimation(0xFFFFFF81, 1);
});

