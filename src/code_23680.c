#include "common.h"
#include "map.h"

INCLUDE_ASM(s32, "code_23680", spawn_drops);

// The issues here are only in the beginning where max and min are flipped
#ifdef NON_MATCHING
s32 get_coin_drop_amount(Enemy* enemy) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s16* dropTables = enemy->dropTables;
    s32 t1;
    s32 t2;
    s32 amt;
    s32 diff;
    s32 max;
    s32 min;

    t1 = dropTables[89];
    t2 = dropTables[90];

    min = t1;
    max = t2;

    if (max < min) {
        min = t2;
        max = t1;
    }

    diff = max - min;

    amt = min;
    if ((min < 0) || (diff != 0)) {
        amt = rand_int(diff) + min;
    }

    if (amt < 0) {
        amt = 0;
    }

    if (is_ability_active(Ability_PAY_OFF)) {
        amt += currentEncounter->damageTaken / 2;
    }

    if (currentEncounter->merleeCoinBonus != 0) {
        amt *= 3;
    }

    if (is_ability_active(Ability_MONEY_MONEY)) {
        amt *= 2;
    }

    amt += currentEncounter->coinsEarned;

    if (enemy->flags & 0x840000) {
        amt = 0;
    }

    if (amt > 20) {
        amt = 20;
    }

    return amt;
}
#else
INCLUDE_ASM(s32, "code_23680", get_coin_drop_amount);
#endif

INCLUDE_ASM(s32, "code_23680", func_80048E34);

INCLUDE_ASM(s32, "code_23680", func_80048F0C);

s32 is_point_within_region(s32 shape, f32 pointX, f32 pointY, f32 centerX, f32 centerY, f32 sizeX, f32 sizeZ) {
    f32 dist1;
    f32 dist2;

    switch (shape) {
        case 0:
            dist1 = dist2D(pointX, pointY, centerX, centerY);
            return (sizeX < dist1);
        case 1:
            dist1 = dist2D(pointX, 0, centerX, 0);
            dist2 = dist2D(0, pointY, 0, centerY);
            return ((sizeX < dist1) || (sizeZ < dist2));
        default:
            return FALSE;
    }
}

INCLUDE_ASM(s32, "code_23680", func_800490B4, s32 arg0, Enemy* arg1, f32 arg2, s32 arg3, s32 arg4);

INCLUDE_ASM(s32, "code_23680", func_800493EC);

INCLUDE_ASM(s32, "code_23680", func_800494C0, Npc* npc, s32 arg1, s32 arg2);

INCLUDE_ASM(s32, "code_23680", func_80049550);

INCLUDE_ASM(s32, "code_23680", func_800495A0);

INCLUDE_ASM(s32, "code_23680", func_800496B8);

#define NAMESPACE base
#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "code_23680", func_80049C04);

INCLUDE_ASM(s32, "code_23680", func_80049E3C);

INCLUDE_ASM(s32, "code_23680", func_80049ECC);

INCLUDE_ASM(s32, "code_23680", func_80049F7C);

INCLUDE_ASM(s32, "code_23680", func_8004A124);

INCLUDE_ASM(s32, "code_23680", func_8004A3E8);

INCLUDE_ASM(s32, "code_23680", DoBasicAI, ScriptInstance* script, s32 isInitialCall);
