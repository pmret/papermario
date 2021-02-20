#include "common.h"

HitResult calc_item_check_hit(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorMovePos* movePos = &battleStatus->playerActor->movePos;
    ActorID actorID = battleStatus->currentTargetID;
    s8 currentTargetPartS8;
    u32 currentTargetPart;
    Actor* actor;
    ActorPart* actorPart;

    currentTargetPart = currentTargetPartS8 = battleStatus->currentTargetPart;
    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = currentTargetPartS8;

    actor = get_actor(actorID);
    if (actor != NULL) {
        actorPart = get_actor_part(actor, currentTargetPart);
        ASSERT(actorPart != NULL);

        if (!(actorPart->eventFlags & 0x20)) {
            if (actor->transStatus == 0xE) {
                return HitResult_MISS;
            }
            if (actor->stoneStatus == 0xC) {
                play_sound_at_position(0x10C, 0, movePos->goal.x, movePos->goal.y, movePos->goal.z);
                return HitResult_IMMUNE;
            }
            if ((battleStatus->currentAttackElement & 0x80) && (actorPart->eventFlags & 0x10)) {
                play_sound_at_position(0xE9, 0, movePos->goal.x, movePos->goal.y, movePos->goal.z);
                return HitResult_LANDED_ON_SPIKE;
            }
        } else {
            return HitResult_MISS;
        }
    }
    return HitResult_HIT;
}

INCLUDE_ASM(s32, "code_17FEB0", calc_item_damage_enemy);

ApiStatus ItemDamageEnemy(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x30;
    } else if (a5 & flag) {
        battleStatus->flags1 = (battleStatus->flags1 | flag) & ~0x20;
    } else if (a5 & 0x20) {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) | 0x20;
    } else {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) & ~0x20;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    itemDamage = calc_item_damage_enemy();
    if (itemDamage < 0) {
        return ApiStatus_FINISH;
    }

    set_variable(script, itemDamageOut, itemDamage);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus ItemAfflictEnemy(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackStatus |= get_variable(script, *args++);
    battleStatus->currentAttackDamage = get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x30;
    } else if (a5 & flag) {
        battleStatus->flags1 = (battleStatus->flags1 | flag) & ~0x20;
    } else if (a5 & 0x20) {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) | 0x20;
    } else {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) & ~0x20;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    itemDamage = calc_item_damage_enemy();
    if (itemDamage < 0) {
        return ApiStatus_FINISH;
    }

    set_variable(script, itemDamageOut, itemDamage);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80252B3C(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = get_variable(script, *args++);
    battleStatus->currentAttackDamage = get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x30;
    } else if (a5 & flag) {
        battleStatus->flags1 = (battleStatus->flags1 | flag) & ~0x20;
    } else if (a5 & 0x20) {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) | 0x20;
    } else {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) & ~0x20;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    itemDamage = calc_item_damage_enemy();
    if (itemDamage < 0) {
        return ApiStatus_FINISH;
    }

    set_variable(script, itemDamageOut, itemDamage);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus ItemCheckHit(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x30;
    } else if (a5 & flag) {
        battleStatus->flags1 = (battleStatus->flags1 | flag) & ~0x20;
    } else if (a5 & 0x20) {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) | 0x20;
    } else {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) & ~0x20;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    itemDamage = calc_item_check_hit();
    if (itemDamage < 0) {
        return ApiStatus_FINISH;
    }

    set_variable(script, itemDamageOut, itemDamage);

    return ApiStatus_DONE2;
}
