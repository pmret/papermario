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

s32 func_80048F0C(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounter->numEncounters; i++) {
        Encounter* encounter = currentEncounter->enounterList[i];

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

INCLUDE_ASM(s32, "code_23680", func_800490B4, s32 arg0, Enemy* arg1, f32 arg2, s32 arg3, s32 arg4);

s32 func_800493EC(Enemy* enemy, s32 arg1, f32 arg2, f32 arg3) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 ret;

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

            add_vec2D_polar(&f1, &f2, arg3, 270.0f - npc->unk_34);

            if (!(dist2D(f1, f2, playerStatus->position.x, playerStatus->position.z) <= arg2)) {
                ret = 0;
            } else {
                ret = 1;
            }
        } else {
            ret = 0;
        }
    } else {
        ret = 0;
    }

    return ret;
}

void func_800494C0(Npc *npc, s32 arg1, s32 arg2) {
    Enemy* enemy = get_enemy(npc->npcID);
    s32 value2 = (arg2 & 0xFFFF0000) | 2;

    if (arg2 & 1) {
        value2 |= 0x10000;
    }

    if (enemy->npcSettings->unk_2A & 0x20) {
        value2 |= 0x20000;
    }

    play_sound_at_position(arg1, value2, npc->pos.x, npc->pos.y, npc->pos.z);
}

void func_80049550(ScriptInstance* script, s32 arg1) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0].s = arg1;
    }
}

INCLUDE_ASM(s32, "code_23680", func_800495A0);

INCLUDE_ASM(s32, "code_23680", func_800496B8);

#define NAMESPACE base
#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "code_23680", func_80049C04);

void func_80049E3C(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    func_800494C0(npc, 0x3E1, 0);
    npc->currentAnim = enemy->animList[4];
    npc->jumpVelocity = 10.0f;
    npc->jumpScale = 2.5f;
    npc->moveToPos.y = npc->pos.y;
    npc->flags |= 0x800;
    script->functionTemp[0].s = 11;
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
        script->functionTemp[0].s = 12;
    }
}

INCLUDE_ASM(s32, "code_23680", func_80049F7C);

INCLUDE_ASM(s32, "code_23680", func_8004A124);

void func_8004A3E8(ScriptInstance* script, s32 arg1) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        npc->yaw = clamp_angle(atan2(npc->pos.x, npc->pos.z, enemy->territory->unk_00.x, enemy->territory->unk_00.z));
        script->functionTemp[0].s = 0;
    }
}

INCLUDE_ASM(s32, "code_23680", DoBasicAI, ScriptInstance* script, s32 isInitialCall);
// s32 DoBasicAI(ScriptInstance *script, s32 isInitialCall) {
//     Enemy* enemy = script->owner1.enemy;
//     Npc* npc = get_npc_unsafe(enemy->npcID);
//     NpcAISettings* npcAISettings = get_variable(script, *script->ptrReadPos);
//     s32 something;

//     if ((isInitialCall) || (enemy->unk_B0 & 4)) {
//         script->functionTemp[0].s = 0;
//         npc->duration = 0;
//         npc->flags &= ~0x800;
//         npc->currentAnim = *enemy->animList;

//         if (enemy->territory->unk_34 != 0) {
//             npc->flags &= ~0x200;
//             npc->flags |= 8;
//         } else {
//             npc->flags |= 0x200;
//             npc->flags &= ~8;
//         }

//         if (enemy->unk_B0 & 4) {
//             script->functionTemp[0].s = 99;
//             script->functionTemp[1].s = 0;
//         } else if (enemy->flags & 0x40000000) {
//             script->functionTemp[0].s = 12;
//         }

//         enemy->unk_B0 &= ~4;
//         enemy->flags &= 0xBFFFFFFF;
//     }

//     switch (script->functionTemp[0].s) {
//         case 0:
//             func_800495A0(script, npcAISettings, something);
//         case 1:
//             func_800496B8(script, npcAISettings, something);
//             return ApiStatus_BLOCK;
//         case 2:
//             base_UnkNpcAIFunc1(script, npcAISettings);
//         case 3:
//             func_80049C04(script, npcAISettings, something);
//             return ApiStatus_BLOCK;
//         case 10:
//             func_80049E3C(script);
//         case 11:
//             func_80049ECC(script);
//             return ApiStatus_BLOCK;
//         case 12:
//             func_80049F7C(script, npcAISettings, something);
//         case 13:
//             func_8004A124(script, npcAISettings, something);
//         case 14:
//             func_8004A3E8(script, npcAISettings);
//             return ApiStatus_BLOCK;
//         case 99:
//             func_8004A73C(script);
//     }
//     return ApiStatus_BLOCK;
// }
