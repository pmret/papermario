#include "common.h"
#include "map.h"

INCLUDE_ASM(s32, "23680", spawn_drops);

// The issues here are only in the beginning where max and min are flipped
#ifdef NON_MATCHING
s32 get_coin_drop_amount(Enemy* enemy) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 amt;
    s32 mx;
    s32 diff;

    amt = enemy->drops->minCoinBonus;
    mx = enemy->drops->maxCoinBonus;

    if (enemy->drops->minCoinBonus > enemy->drops->maxCoinBonus) {
        amt = enemy->drops->maxCoinBonus;
        mx = enemy->drops->minCoinBonus;
    }

    diff = mx - amt;

    if ((amt < 0) || (diff != 0)) {
        amt = rand_int(diff) + amt;
    }

    if (amt < 0) {
        amt = 0;
    }

    if (is_ability_active(ABILITY_PAY_OFF)) {
        amt += currentEncounter->damageTaken / 2;
    }

    if (currentEncounter->merleeCoinBonus != 0) {
        amt *= 3;
    }

    if (is_ability_active(ABILITY_MONEY_MONEY)) {
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
INCLUDE_ASM(s32, "23680", get_coin_drop_amount);
#endif

void func_80048E34(Enemy* enemy, s32 arg1, s32 arg2) {
    ScriptInstance* newScript;

    if (enemy->aiScript != NULL) {
        kill_script_by_ID(enemy->aiScriptID);
        enemy->aiScript = NULL;
    }

    if (enemy->unk_BC != 0) {
        kill_script_by_ID(enemy->unk_C0);
        enemy->unk_BC = NULL;
    }

    if (enemy->aiBytecode != NULL) {
        enemy->unk_C8 = arg2;
        newScript = start_script(enemy->aiBytecode, 10, 0x20);
        enemy->aiScript = newScript;
        enemy->aiScriptID = newScript->id;
        newScript->owner2.npcID = enemy->npcID;
        newScript->owner1.enemy = enemy;
    }

    if (enemy->unk_B8 != NULL) {
        enemy->unk_C4 = arg1;
        newScript = start_script(enemy->unk_B8, 10, 0x20);
        enemy->unk_BC = newScript;
        enemy->unk_C0 = newScript->id;
        newScript->owner2.npcID = enemy->npcID;
        newScript->owner1.enemy = enemy;
    }
}

s32 func_80048F0C(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounter->numEncounters; i++) {
        Encounter* encounter = currentEncounter->encounterList[i];

        if (encounter != NULL) {
            for (j = 0; j < encounter->count; j++) {
                Enemy* enemy = encounter->enemy[j];

                if (enemy != NULL && !(enemy->flags & 0x20)) {
                    get_npc_unsafe(enemy->npcID);
                }
            }
        }
    }

    return 0;
}

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

INCLUDE_ASM(s32, "23680", func_800490B4, EnemyTerritoryThing* arg0, Enemy* arg1, f32 arg2, f32 arg3, s32 arg4);

s32 func_800493EC(Enemy* enemy, s32 arg1, f32 arg2, f32 arg3) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (arg1 >= 0) {
        s32 temp;

        if (arg1 != 0) {
            temp = rand_int(arg1 + 1);
        } else {
            temp = 0;
        }

        if (temp == 0) {
            f32 f1 = npc->pos.x;
            f32 f2 = npc->pos.z;

            add_vec2D_polar(&f1, &f2, arg3, 270.0f - npc->renderYaw);

            if (dist2D(f1, f2, playerStatus->position.x, playerStatus->position.z) <= arg2) {
                return 1;
            }
        }
    }

    return 0;
}

void ai_enemy_play_sound(Npc* npc, s32 arg1, s32 arg2) {
    Enemy* enemy = get_enemy(npc->npcID);
    s32 value2 = (arg2 & 0xFFFF0000) | 2;

    if (arg2 & 1) {
        value2 |= 0x10000;
    }

    if (enemy->npcSettings->unk_2A & 0x20) {
        value2 |= 0x20000;
    }

    sfx_play_sound_at_position(arg1, value2, npc->pos.x, npc->pos.y, npc->pos.z);
}

void func_80049550(ScriptInstance* script, s32 arg1) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = arg1;
    }
}

INCLUDE_ASM(s32, "23680", func_800495A0);

INCLUDE_ASM(s32, "23680", func_800496B8);

#define NAMESPACE base
#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "23680", func_80049C04);

void func_80049E3C(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    ai_enemy_play_sound(npc, 0x3E1, 0);
    npc->currentAnim.w = enemy->animList[4];
    npc->jumpVelocity = 10.0f;
    npc->jumpScale = 2.5f;
    npc->moveToPos.y = npc->pos.y;
    npc->flags |= 0x800;
    script->functionTemp[0] = 11;
}

void func_80049ECC(ScriptInstance* script) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    s32 flag = FALSE;

    if (npc->jumpVelocity <= 0.0) {
        if (npc->pos.y <= npc->moveToPos.y) {
            npc->pos.y = npc->moveToPos.y;
            flag = TRUE;
        }
    }

    if (!flag) {
        npc->pos.y += npc->jumpVelocity;
        npc->jumpVelocity -= npc->jumpScale;
    } else {
        npc->jumpVelocity = 0.0f;
        npc->flags &= ~0x800;
        script->functionTemp[0] = 12;
    }
}

INCLUDE_ASM(s32, "23680", func_80049F7C);

INCLUDE_ASM(s32, "23680", func_8004A124);

void func_8004A3E8(ScriptInstance* script, s32 arg1) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        npc->yaw = clamp_angle(atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x,
                                     enemy->territory->wander.point.z));
        script->functionTemp[0] = 0;
    }
}

INCLUDE_ASM(s32, "23680", DoBasicAI, ScriptInstance* script, s32 isInitialCall);
