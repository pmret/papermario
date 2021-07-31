#include "common.h"

s32 func_80254250(void) {
    s32 ret;

    if (gBattleStatus.lastAttackDamage < 3) {
        ret = 0;
    } else if (gBattleStatus.lastAttackDamage < 5) {
        ret = 1;
    } else if (gBattleStatus.lastAttackDamage < 9) {
        ret = 2;
    } else {
        ret = 3;
    }

    return ret;
}

void mtx_mirror_y(Matrix4f arg0) {

    guMtxIdentF(arg0);
    (arg0)[0][0] = 1.0f;
    (arg0)[1][1] = -1.0f;
    (arg0)[2][2] = 1.0f;
    (arg0)[3][3] = 1.0f;
}

INCLUDE_ASM(s32, "182B30", enable_actor_blur);

void disable_actor_blur(Actor* actor) {
    ActorPart* actorPart = actor->partsTable;

    if ((actorPart->idleAnimations != NULL) && !(actorPart->flags & 2)) {
        DecorationTable* decorationTable = actorPart->decorationTable;

        if (decorationTable->unk_7DB != 0) {
            decorationTable->unk_7DB--;
            if (decorationTable->unk_7DB == 0) {
                decorationTable->effectType = 20;
            }
        }
    }
}

void reset_actor_blur(Actor* actor) {
    ActorPart* actorPart = actor->partsTable;

    if ((actorPart->idleAnimations != NULL) && !(actorPart->flags & 2)) {
        DecorationTable* decorationTable = actorPart->decorationTable;

        if (decorationTable->unk_7DB != 0) {
            decorationTable->unk_7DB--;
            if (decorationTable->unk_7DB == 0) {
                actor->flags &= ~ACTOR_FLAG_10000000;
                decorationTable->effectType = 1;
            }
        }
    }
}

void func_80254610(Actor* actor) {
    ActorPart* actorPart = actor->partsTable;

    if (actorPart->idleAnimations != NULL && !(actorPart->flags & 2)) {
        DecorationTable* decorationTable = actorPart->decorationTable;

        decorationTable->unk_7DB = 0;
        decorationTable->effectType = 20;
    }
}

void enable_partner_blur(void) {
    enable_actor_blur(gBattleStatus.partnerActor);
}

void disable_partner_blur(void) {
    disable_actor_blur(gBattleStatus.partnerActor);
}

void reset_partner_blur(void) {
    reset_actor_blur(gBattleStatus.partnerActor);
}

void func_802546B0(void) {
    func_80254610(gBattleStatus.partnerActor);
}

void enable_player_blur(void) {
    Actor* playerActor = gBattleStatus.playerActor;
    ActorPart* partsTable = playerActor->partsTable;
    DecorationTable* decorationTable = partsTable->decorationTable;
    s32 i;

    decorationTable->effectType = 0;
    decorationTable->unk_7DB++;
    playerActor->flags |= ACTOR_FLAG_10000000;
    decorationTable->unk_7D8 = 0;
    decorationTable->unk_7D9 = 0;

    for (i = 0; i < ARRAY_COUNT(decorationTable->posX); i++) {
        decorationTable->posX[i] = partsTable->currentPos.x;
        decorationTable->posY[i] = partsTable->currentPos.y;
        decorationTable->posZ[i] = partsTable->currentPos.z;
        decorationTable->scale[i] = playerActor->yaw;
        decorationTable->rotationPivotOffsetX[i] = (s32)(playerActor->rotationPivotOffset.x * playerActor->scalingFactor);
        decorationTable->rotationPivotOffsetY[i] = (s32)(playerActor->rotationPivotOffset.y * playerActor->scalingFactor);

        *(&decorationTable->rotX[i]) = clamp_angle(playerActor->rotation.x) * 0.5f;
        *(&decorationTable->rotY[i]) = clamp_angle(playerActor->rotation.y) * 0.5f;
        *(&decorationTable->rotZ[i]) = clamp_angle(playerActor->rotation.z) * 0.5f;
    }
}

void disable_player_blur(void) {
    DecorationTable* decorationTable = gBattleStatus.playerActor->partsTable->decorationTable;

    if (decorationTable->unk_7DB != 0) {
        decorationTable->unk_7DB--;
        if (decorationTable->unk_7DB == 0) {
            decorationTable->effectType = 20;
        }
    }
}

void func_80254950(void) {
    Actor* playerActor = gBattleStatus.playerActor;
    DecorationTable* decorationTable = playerActor->partsTable->decorationTable;

    if (decorationTable->unk_7DB != 0) {
        decorationTable->unk_7DB--;
        if (decorationTable->unk_7DB == 0) {
            playerActor->flags &= ~ACTOR_FLAG_10000000;
            decorationTable->effectType = 1;
        }
    }
}

void func_802549A0(void) {
    DecorationTable* decorationTable = gBattleStatus.playerActor->partsTable->decorationTable;

    decorationTable->unk_7DB = 0;
    decorationTable->effectType = 20;
}

void func_802549C0(void) {
    Actor* playerActor = gBattleStatus.playerActor;
    DecorationTable* decorationTable = playerActor->partsTable->decorationTable;

    playerActor->flags &= ~ACTOR_FLAG_10000000;
    decorationTable->unk_7DB = 0;
    decorationTable->effectType = 1;
}

INCLUDE_ASM(s32, "182B30", func_802549F4);

INCLUDE_ASM(void, "182B30", func_80254C50);

INCLUDE_ASM(s32, "182B30", func_802550BC);

INCLUDE_ASM(s32, "182B30", func_802552EC);

void func_8025593C(s32 arg0) {
    func_802550BC(0, arg0);
}

void func_8025595C(Actor* actor) {
    func_802552EC(0, actor);
}

void func_8025597C(s32 arg0) {
    func_802550BC(1, arg0);
}

void func_8025599C(s32 arg0) {
    func_802552EC(1, arg0);
}

INCLUDE_ASM(s32, "182B30", update_actor_shadow);

s32 update_enemy_shadows(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        update_actor_shadow(0, battleStatus->enemyActors[i]);
    }
}

void update_hero_shadows(void) {
    update_actor_shadow(1, gBattleStatus.partnerActor);
    update_player_actor_shadow();
}

void func_80255FD8(void) {
}

INCLUDE_ASM(s32, "182B30", func_80255FE0);

INCLUDE_ASM(s32, "182B30", func_802571F0);

void func_80257B28(s32 arg0) {
    func_80255FE0(0, arg0);
}

void func_80257B48(s32 arg0) {
    func_80255FE0(1, arg0);
}

void func_80257B68(Actor* actor) {
    func_802571F0(0, actor);
}

void func_80257B88(void) {
    func_802571F0(1, gBattleStatus.partnerActor);
}

INCLUDE_ASM(s32, "182B30", update_player_actor_shadow);

INCLUDE_ASM(void, "182B30", func_80257DA4);

INCLUDE_ASM(void, "182B30", func_80258E14);

INCLUDE_ASM(s32, "182B30", func_802591EC);

INCLUDE_ASM(s32, "182B30", func_80259494);

INCLUDE_ASM(s32, "182B30", func_8025950C);

INCLUDE_ASM(s32, "182B30", func_802596C0);

INCLUDE_ASM(s32, "182B30", func_802597B0);

INCLUDE_ASM(s32, "182B30", func_8025995C);

void func_80259A48(s32 arg0, ActorPart* arg1, s32 arg2, s32 arg3) {
    DecorationTable* decorationTable = arg1->decorationTable;

    if (decorationTable->unk_6C1 != 0) {
        arg1->verticalStretch = 1;
        arg1->unkOffset[0] = 0;
        arg1->unkOffset[1] = 0;
        decorationTable->unk_6C1 = 0;
    }
    if (arg0 == 0) {
        func_802597B0(arg1, arg2, arg3);
    } else {
        func_8025950C(arg1, arg2, arg3);
    }
}

INCLUDE_ASM(s32, "182B30", func_80259AAC);

INCLUDE_ASM(s32, "182B30", func_80259D9C);

INCLUDE_ASM(s32, "182B30", func_8025A2C4);

INCLUDE_ASM(s32, "182B30", func_8025A50C);

INCLUDE_ASM(s32, "182B30", func_8025A74C);

INCLUDE_ASM(s32, "182B30", func_8025AA80);

INCLUDE_ASM(s32, "182B30", func_8025AD90);

INCLUDE_ASM(s32, "182B30", func_8025B1A8);

INCLUDE_ASM(s32, "182B30", func_8025B5C0);

INCLUDE_ASM(s32, "182B30", func_8025BAA0);

INCLUDE_ASM(s32, "182B30", func_8025C120);

s32 func_8025C840(s32 arg0, ActorPart* arg1) {

    if (!(arg1->flags & 2)) {
        switch (arg1->decorationTable->unk_750) {
            case 0:
                func_8025C8A0(arg0, arg1);
                return 0;
            case 11:
                func_8025C918();
                break;
        }
    }
    return 0;
}

s32 func_8025C8A0(s32 arg0, ActorPart* arg1) {

    if (arg1->decorationTable->unk_751 != 0) {
        arg1->decorationTable->unk_751 = 0;
        if (arg0 == 0) {
            return func_802DDFF8(0, 0, 0, 0, 0, 0, 0);
        }
        return func_802DE894(arg1->unk_84, 0, 0, 0, 0, 0, 0);
    }
}

INCLUDE_ASM(s32, "182B30", func_8025C918);

s32 func_8025CCC8(s32 arg0, ActorPart* arg1) {

    if (!(arg1->flags & 2)) {
        switch (arg1->decorationTable->unk_764) {
            case 0:
                func_8025CD28(arg0, arg1);
                return 0;
            case 1:
                func_8025CD40();
                break;
        }
    }
    return 0;
}

void func_8025CD28(s32 arg0, ActorPart* arg1) {
    DecorationTable* decorationTable = arg1->decorationTable;

    if (decorationTable->unk_765 != 0) {
        decorationTable->unk_765 = 0;
    }
    decorationTable->unk_768 = 0;
}

INCLUDE_ASM(s32, "182B30", func_8025CD40);

INCLUDE_ASM(s32, "182B30", func_8025CEC8);

void _remove_part_decoration(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decorationTable = part->decorationTable;

    switch (decorationTable->decorationType[decorationIndex]) {
        case 0:
            func_8025D158(part, decorationIndex);
            break;
        case 1:
            func_8025D290(part, decorationIndex);
            break;
        case 2:
            func_8025D3C4(part, decorationIndex);
            break;
        case 3:
            func_8025D4A0(part, decorationIndex);
            break;
        case 4:
            func_8025D620(part, decorationIndex);
            break;
        case 5:
            func_8025D6FC(part, decorationIndex);
            break;
        case 6:
            func_8025D810(part, decorationIndex);
            break;
        case 7:
            func_8025D8EC(part, decorationIndex);
            break;
        case 8:
            func_8025DA60(part, decorationIndex);
            break;
        case 9:
            func_8025DBC8(part, decorationIndex);
            break;
        case 10:
            func_8025DD40(part, decorationIndex);
            break;
        case 11:
            func_8025DE88(part, decorationIndex);
            break;
    }

    decorationTable->decorationType[decorationIndex] = 0;
}

void func_8025D150(void) {
}

void func_8025D158(ActorPart* part, s32 decorationIndex) {
}

INCLUDE_ASM(s32, "182B30", func_8025D160);

void func_8025D290(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->unk_8B0[decorationIndex]->unk_0C->unk_2C = 5;
}

INCLUDE_ASM(s32, "182B30", func_8025D2B0);

void func_8025D3C4(ActorPart* part, s32 decorationIndex) {
}

INCLUDE_ASM(s32, "182B30", func_8025D3CC);

void func_8025D4A0(ActorPart* part, s32 decorationIndex) {
    remove_effect(part->decorationTable->unk_8B0[decorationIndex]);
}

INCLUDE_ASM(s32, "182B30", func_8025D4C8);

void func_8025D620(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->unk_8B0[decorationIndex]->unk_0C->unk_2C = 5;
}

INCLUDE_ASM(s32, "182B30", func_8025D640);

void func_8025D6FC(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->unk_8B0[decorationIndex]->unk_00 |= 0x10;
}

INCLUDE_ASM(s32, "182B30", func_8025D71C);

void func_8025D810(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->unk_8B0[decorationIndex]->unk_00 |= 0x10;
}

INCLUDE_ASM(s32, "182B30", func_8025D830);

void func_8025D8EC(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->unk_8B0[decorationIndex]->unk_00 |= 0x10;
}

INCLUDE_ASM(s32, "182B30", func_8025D90C);

void func_8025DA60(ActorPart* part, s32 decorationIndex) {
}

INCLUDE_ASM(s32, "182B30", func_8025DA68);

void func_8025DBC8(ActorPart* part, s32 decorationIndex) {
}

INCLUDE_ASM(s32, "182B30", func_8025DBD0);

void func_8025DD40(ActorPart* actorPart, s32 decorationIndex) {
    actorPart->decorationTable->unk_8B0[decorationIndex]->unk_0C->unk_2C = 5;
}

INCLUDE_ASM(s32, "182B30", func_8025DD60);

void func_8025DE88(ActorPart* actorPart, s32 decorationIndex) {
    actorPart->decorationTable->unk_8B0[decorationIndex]->unk_00 |= 0x10;
}

