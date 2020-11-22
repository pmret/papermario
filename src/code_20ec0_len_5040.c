#include "common.h"
#include "map.h"

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045AC0);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045B10);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045B68);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045BC8);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045C28);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045C88);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045CC4);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045D00);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045D7C);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045E4C);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045ED0);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045FA4);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80045FB4);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80046030);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800465E0);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047608);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800476F4);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_8004778C);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800477F4);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047820);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047898);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800478F8);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047928);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800479A0);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047A00);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047A30);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047AA8);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047B08);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047B38);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047B84);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047BE4);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047C14);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047CA4);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047D00);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047D30);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047DC0);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047E1C);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047E4C);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047EDC);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047F28);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047F58);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80047FE8);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80048034);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80048064);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800480F4);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80048140);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80048170);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80048200);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_8004824C);

INCLUDE_ASM(s32, "code_20ec0_len_5040", spawn_drops);

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
INCLUDE_ASM(s32, "code_20ec0_len_5040", get_coin_drop_amount);
#endif

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80048E34);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80048F0C);

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

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800490B4);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800493EC);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800494C0, Npc* npc, s32 arg1, s32 arg2);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80049550);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800495A0);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_800496B8);

// Same as UnkNpcAIFunc1
void func_80049B44(ScriptInstance* script, NpcAISettings* aiSettings) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = (aiSettings->waitTime / 2) + rand_int((aiSettings->waitTime / 2) + 1);
    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->currentAnim = *enemy->animList;
    script->functionTemp[0].s = 3;
}

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80049C04);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80049E3C);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80049ECC);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_80049F7C);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_8004A124);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_8004A3E8);

INCLUDE_ASM(s32, "code_20ec0_len_5040", DoBasicAI, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_8004A6F0);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_8004A73C);

INCLUDE_ASM(s32, "code_20ec0_len_5040", func_8004A784);
