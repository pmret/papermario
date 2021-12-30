#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goomba_bros.h"

#define NAMESPACE b_area_kmr_part_2

#include "common/BattleAreaAngleStuff.inc.c"

#define NAMESPACE dup_b_area_kmr_part_2
#include "common/BattleAreaAngleStuff.inc.c"
#define NAMESPACE b_area_kmr_part_2

#define NAMESPACE dup2_b_area_kmr_part_2
#include "common/BattleAreaAngleStuff.inc.c"
#define NAMESPACE b_area_kmr_part_2

#include "common/DivActorLevel4.inc.c"

#define NAMESPACE dup3_b_area_kmr_part_2
#include "common/BattleAreaAngleStuff.inc.c"
#define NAMESPACE b_area_kmr_part_2

#define NAMESPACE dup_b_area_kmr_part_2
#include "common/DivActorLevel4.inc.c"
#define NAMESPACE b_area_kmr_part_2

ApiStatus func_80218A60_43A4F0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    fx_land(2, var1, var2, evt_get_variable(script, *args++), 0);
    return ApiStatus_DONE2;
}

extern ActorDesc D_8021998C_43B41C;
extern s32 D_8021B79C_43D22C[];
extern s32 D_80220A10_4424A0[];
extern s32 D_8021EEDC_44096C[];
extern s32 D_8021D4DC_43EF6C[];
extern s32 D_80223450_444EE0[];
extern s32 D_80225884_447314[];
extern s32 D_80224B7C_44660C[];
extern s32 D_80225860_4472F0[];
extern s32 D_8022582C_4472BC[];
extern s32 D_802258BC_44734C[];
extern s32 D_80224730_4461C0[];
extern s32 D_802258B4_447344[];
extern s32 D_802258AC_44733C[];
extern s32 D_80224FCC_446A5C[];
extern s32 D_802258A4_447334[];
extern s32 D_802253D8_446E68[];
extern s32 D_8022589C_44732C[];
extern s32 D_802199B4_43B444[];
extern s32 D_8021B268_43CCF8[];
extern s32 D_8021A5A0_43C030[];
extern s32 D_80219A98_43B528[];
extern s32 D_80219D74_43B804[];
extern s32 D_8021B388_43CE18[];


s32 D_802198B0_43B340[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 D_802198BC_43B34C[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
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

ActorPartDesc D_80219968_43B3F8[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = D_802199B4_43B444,
        .defenseTable = D_802198B0_43B340,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = ELEMENT_IMMUNITY_FLAGS_0,
        .unk_1C = 253,
    },
};

ActorDesc D_8021998C_43B41C = {
    .flags = 0,
    .type = ACTOR_TYPE_BLUE_GOOMBA_BOSS,
    .level = 20,
    .maxHP = 6,
    .partCount = 1,
    .partsData = D_80219968_43B3F8,
    .script = D_8021B268_43CCF8,
    .statusTable = D_802198BC_43B34C,
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 32, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 8, 25 },
};

s32 D_802199B4_43B444[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_bros_Palette_01_Anim_2,
    STATUS_STONE,     NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_goomba_bros_Palette_01_Anim_D,
    STATUS_POISON,    NPC_ANIM_goomba_bros_Palette_01_Anim_2,
    STATUS_STOP,      NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_goomba_bros_Palette_01_Anim_2,
    STATUS_PARALYZE,  NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_goomba_bros_Palette_01_Anim_C,
    STATUS_FEAR,      NPC_ANIM_goomba_bros_Palette_01_Anim_C,
    STATUS_END,
};

s32 D_80219A00_43B490[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_bros_Palette_01_Anim_6,
    STATUS_STONE,     NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_goomba_bros_Palette_01_Anim_D,
    STATUS_POISON,    NPC_ANIM_goomba_bros_Palette_01_Anim_2,
    STATUS_STOP,      NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_goomba_bros_Palette_01_Anim_6,
    STATUS_PARALYZE,  NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_goomba_bros_Palette_01_Anim_C,
    STATUS_FEAR,      NPC_ANIM_goomba_bros_Palette_01_Anim_C,
    STATUS_END,
};

EvtSource D_80219A4C_43B4DC = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, D_8021A5A0_43C030)
    EVT_CALL(BindIdle, ACTOR_SELF, D_80219A98_43B528)
    EVT_CALL(BindHandleEvent, ACTOR_SELF, D_80219D74_43B804)
    EVT_RETURN
    EVT_END
};

EvtSource D_80219A98_43B528 = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, LW(0))
    EVT_ADD(LW(0), 80)
    EVT_LOOP(LW(0))
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, D_80219A00_43B490)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(D_802199B4_43B444))
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, D_80219A00_43B490)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(D_802199B4_43B444))
    EVT_LOOP(80)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtSource D_80219D74_43B804 = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_E)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_bros_Palette_01_Anim_F)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_E)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_bros_Palette_01_Anim_F)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_F)
            EVT_EXEC_WAIT(D_8021B388_43CE18)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(D_8021B388_43CE18)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_C)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6005859375))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(D_8021B388_43CE18)
            EVT_RETURN
        EVT_CASE_EQ(19)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_2)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(D_8021B388_43CE18)
            EVT_RETURN
        EVT_CASE_EQ(53)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_6)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_2)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_6)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_2)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

f32 b_area_kmr_part_2_floatTable[] = {
    0.0, 0.017452, 0.034899, 0.052336, 0.069756, 0.087156, 0.104528, 0.121869, 0.139173, 0.156434, 0.173648, 0.190809, 0.207912, 0.224951, 0.241922, 0.258819, 0.275637, 0.292372, 0.309017, 0.325568, 0.34202, 0.358368, 0.374607, 0.390731, 0.406737, 0.422618, 0.438371, 0.45399, 0.469472, 0.48481, 0.5, 0.515038, 0.529919, 0.544639, 0.559193, 0.573576, 0.587785, 0.601815, 0.615661, 0.62932, 0.642788, 0.656059, 0.669131, 0.681998, 0.694658, 0.707107, 0.71934, 0.731354, 0.743145, 0.75471, 0.766044, 0.777146, 0.788011, 0.798636, 0.809017, 0.819152, 0.829038, 0.838671, 0.848048, 0.857167, 0.866025, 0.87462, 0.882948, 0.891007, 0.898794, 0.906308, 0.913545, 0.920505, 0.927184, 0.93358, 0.939693, 0.945519, 0.951057, 0.956305, 0.961262, 0.965926, 0.970296, 0.97437, 0.978148, 0.981627, 0.984808, 0.987688, 0.990268, 0.992546, 0.994522, 0.996195, 0.997564, 0.99863, 0.999391, 0.999848, 1.0
};
