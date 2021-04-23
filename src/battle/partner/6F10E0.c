#define NAMESPACE battle_partner_goombario

#include "common.h"
#include "battle/battle.h"

extern Actor D_8023CDA0;
extern s32 D_8023CDA4;
extern MessageID bActorTattles[ACTOR_TYPE_COUNT];

ApiStatus func_80238000_6F10E0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 posX = partnerActor->currentPos.x;
    f32 posY = partnerActor->currentPos.y;
    f32 posZ = partnerActor->currentPos.z;
    f32 goalX = partnerActor->walk.goalPos.x;
    f32 goalY = partnerActor->walk.goalPos.y;
    f32 goalZ = partnerActor->walk.goalPos.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] >= 21) {
        script->varTable[0] = 20;
    }

    if (battleStatus->unk_83 != 0) {
        if (script->varTable[0] < 10) {
            script->varTable[0] = 10;
        }
    } else if (script->varTable[0] < 15) {
        script->varTable[0] = 15;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/6F10E0", func_802380E4_6F11C4);

INCLUDE_ASM(s32, "battle/partner/6F10E0", func_8023817C_6F125C);

ApiStatus func_80238A20_6F1B00(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = gBattleStatus.partnerActor;
    Vec3f* pos = &partnerActor->walk.currentPos;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (script->functionTemp[0].s == 0) {
        partnerActor->walk.currentPos.x = partnerActor->currentPos.x;
        partnerActor->walk.currentPos.y = partnerActor->currentPos.y;
        partnerActor->walk.currentPos.z = partnerActor->currentPos.z;
        script->functionTemp[0].s = 1;
    }

    if (partnerActor->walk.velocity > 0.0f) {
        set_animation(0x100, 0, partnerActor->animJumpRise);
    }

    if (partnerActor->walk.velocity < 0.0f) {
        set_animation(0x100, 0, partnerActor->animJumpFall);
    }

    partnerActor->walk.currentPos.y = (partnerActor->walk.currentPos.y + partnerActor->walk.velocity);
    partnerActor->walk.velocity = (partnerActor->walk.velocity - partnerActor->walk.acceleration);
    add_xz_vec3f(pos, partnerActor->walk.speed, partnerActor->walk.angle);
    partnerActor->currentPos.x = partnerActor->walk.currentPos.x;
    partnerActor->currentPos.y = partnerActor->walk.currentPos.y;
    partnerActor->currentPos.z = partnerActor->walk.currentPos.z;

    if (partnerActor->currentPos.y < 10.0f) {
        partnerActor->currentPos.y = 10.0f;

        play_movement_dust_effects(2, partnerActor->currentPos.x, partnerActor->currentPos.y, partnerActor->currentPos.z,
                                   partnerActor->yaw);
        sfx_play_sound(0x148);

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238B60_6F1C40(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor = get_actor(partnerActor->targetActorID);
    MessageID* tattle = &bActorTattles[targetActor->actorType];

    script->varTable[0] = *tattle;

    if (script->varTable[0] == NULL) {
        script->varTable[0] = bActorTattles[0];
    }

    save_tattle_flags(targetActor->actorType);

    return ApiStatus_DONE2;
}


INCLUDE_ASM(s32, "battle/partner/6F10E0", func_80238BCC_6F1CAC);

INCLUDE_ASM(s32, "battle/partner/6F10E0", func_80238E04_6F1EE4);

INCLUDE_ASM(s32, "battle/partner/6F10E0", func_80238E48_6F1F28);

INCLUDE_ASM(s32, "battle/partner/6F10E0", func_80238E74_6F1F54);

INCLUDE_ASM(s32, "battle/partner/6F10E0", func_80238EDC_6F1FBC);

ApiStatus func_8023903C_6F211C(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->partnerActor->isGlowing = FALSE;
    battleStatus->flags1 &= ~0x40000000;

    return ApiStatus_DONE2;
}

ApiStatus func_80239068_6F2148(ScriptInstance* script, s32 isInitialCall) {
    Actor* partnerActor = gBattleStatus.partnerActor;

    if (!(gBattleStatus.flags1 & 0x40000000)) {
        partnerActor->isGlowing = FALSE;
    }

    script->varTable[0] = partnerActor->isGlowing;
    partnerActor->isGlowing = FALSE;
    gBattleStatus.flags1 &= ~0x40000000;

    return ApiStatus_DONE2;
}

ApiStatus func_802390B0_6F2190(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    script->varTable[0] = battleStatus->partnerActor->isGlowing;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/6F10E0", func_802390C8_6F21A8);

ApiStatus func_80239190_6F2270(ScriptInstance* script, s32 isInitialCall) {
    if (D_8023CDA4 == 0) {
        script->varTable[0] = 36;
    } else {
        script->varTable[0] = 37;
    }

    return ApiStatus_DONE2;
}
