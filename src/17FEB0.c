#include "common.h"

HitResult calc_item_check_hit(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorMovement* walk = &battleStatus->playerActor->walk;
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
                return HIT_RESULT_MISS;
            }
            if (actor->stoneStatus == 0xC) {
                sfx_play_sound_at_position(0x10C, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                return HIT_RESULT_IMMUNE;
            }
            if ((battleStatus->currentAttackElement & 0x80) && (actorPart->eventFlags & 0x10)) {
                sfx_play_sound_at_position(0xE9, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                return HIT_RESULT_LANDED_ON_SPIKE;
            }
        } else {
            return HIT_RESULT_MISS;
        }
    }
    return HIT_RESULT_HIT;
}

INCLUDE_ASM(s32, "17FEB0", calc_item_damage_enemy);

ApiStatus ItemDamageEnemy(Evt* script, s32 isInitialCall) {
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
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
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

    evt_set_variable(script, itemDamageOut, itemDamage);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus ItemAfflictEnemy(Evt* script, s32 isInitialCall) {
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
    battleStatus->currentAttackStatus |= evt_get_variable(script, *args++);
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
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

    evt_set_variable(script, itemDamageOut, itemDamage);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80252B3C(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = evt_get_variable(script, *args++);
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
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

    evt_set_variable(script, itemDamageOut, itemDamage);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus ItemCheckHit(Evt* script, s32 isInitialCall) {
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
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
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

    evt_set_variable(script, itemDamageOut, itemDamage);

    return ApiStatus_DONE2;
}
