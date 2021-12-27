#include "common.h"
#include "sprite.h"

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

void enable_actor_blur(Actor* actor) {
    ActorPart* partsTable = actor->partsTable;
    DecorationTable* decorationTable = partsTable->decorationTable;
    s32 i, j;
    s32 numParts;

    decorationTable->effectType = 0;
    decorationTable->unk_7DB++;
    actor->flags |= ACTOR_FLAG_10000000;
    partsTable = actor->partsTable;
    numParts = actor->numParts;

    for (i = 0; i < numParts; i++) {
        if (partsTable->idleAnimations != NULL && !(partsTable->flags & ACTOR_PART_FLAG_2)) {
            decorationTable = partsTable->decorationTable;
            decorationTable->unk_7D8 = 0;
            decorationTable->unk_7D9 = 0;
            for (j = 0; j < ARRAY_COUNT(decorationTable->posX); j++) {
                decorationTable->posX[j] = partsTable->currentPos.x;
                decorationTable->posY[j] = partsTable->currentPos.y;
                decorationTable->posZ[j] = partsTable->currentPos.z;
                decorationTable->scale[j] = actor->yaw;
                decorationTable->rotationPivotOffsetX[j] = (s32)(actor->rotationPivotOffset.x * actor->scalingFactor);
                decorationTable->rotationPivotOffsetY[j] = (s32)(actor->rotationPivotOffset.y * actor->scalingFactor);

                decorationTable->rotX[j] = clamp_angle(actor->rotation.x) * 0.5f;
                decorationTable->rotY[j] = clamp_angle(actor->rotation.y) * 0.5f;
                decorationTable->rotZ[j] = clamp_angle(actor->rotation.z) * 0.5f;
            }
        }
        partsTable = partsTable->nextPart;
    }
}

void disable_actor_blur(Actor* actor) {
    ActorPart* actorPart = actor->partsTable;

    if ((actorPart->idleAnimations != NULL) && !(actorPart->flags & ACTOR_PART_FLAG_2)) {
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

    if ((actorPart->idleAnimations != NULL) && !(actorPart->flags & ACTOR_PART_FLAG_2)) {
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

    if (actorPart->idleAnimations != NULL && !(actorPart->flags & ACTOR_PART_FLAG_2)) {
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

void func_802549F4(Actor* actor) {
    ActorPart* partsTable = actor->partsTable;
    DecorationTable* decorationTable = partsTable->decorationTable;

    if (!(partsTable->flags & ACTOR_PART_FLAG_INVISIBLE) && partsTable->idleAnimations != NULL) {
        s32 i = decorationTable->unk_7D9;

        decorationTable->posX[i] = partsTable->currentPos.x;
        decorationTable->posY[i] = partsTable->currentPos.y;
        decorationTable->posZ[i] = partsTable->currentPos.z;
        decorationTable->scale[i] = actor->yaw;

        decorationTable->rotationPivotOffsetX[i] = (s32)(actor->rotationPivotOffset.x * actor->scalingFactor);
        decorationTable->rotationPivotOffsetY[i] = (s32)(actor->rotationPivotOffset.y * actor->scalingFactor);

        decorationTable->rotX[i] = clamp_angle(actor->rotation.x) * 0.5f;
        decorationTable->rotY[i] = clamp_angle(actor->rotation.y) * 0.5f;
        decorationTable->rotZ[i] = clamp_angle(actor->rotation.z) * 0.5f;

        i++;
        if (i >= ARRAY_COUNT(decorationTable->posX)) {
            i = 0;
        }
        decorationTable->unk_7D9 = i;
    }
}

void func_80254C50(Actor* actor) {
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Matrix4f spD8;
    Matrix4f sp118;
    Matrix4f sp158;
    Matrix4f sp198;
    Matrix4f sp1D8;
    Matrix4f sp218;
    Matrix4f sp258;
    s32 sp298;
    s32 sp29C;
    s32 scale;
    ActorPart* partTable;
    DecorationTable* decorationTable;
    f32 rotX, rotY, rotZ;
    s32 temp_s0_2;
    s32 temp_v1;
    s32 temp_s0;
    s32 temp_s1;
    s32 i;
    s32 phi_s6;
    s32 phi_s4;
    f32 x, y, z;

    partTable = actor->partsTable;
    decorationTable = partTable->decorationTable;
    if (decorationTable->effectType != 0) {
        decorationTable->effectType--;
        if (decorationTable->effectType == 0) {
            actor->flags &= ~ACTOR_FLAG_10000000;
            return;
        }
    }

    if (!(partTable->flags & ACTOR_PART_FLAG_INVISIBLE) && partTable->idleAnimations != NULL) {
        sp298 = 0;
        sp29C = 0;
        i = decorationTable->unk_7D9;

        while (1) {
            i--;
            sp298 += 1;
            if (i < 0) {
                i = 0xF;
            }
            if (i == decorationTable->unk_7D9) {
                break;
            }

            if (sp298 >= 3) {
                sp298 = 0;
                sp29C++;

                if (decorationTable->unk_7DA < sp29C) {
                    break;
                }
                temp_v1 = partTable->opacity;
                x = decorationTable->posX[i];
                y = decorationTable->posY[i];
                z = decorationTable->posZ[i];

                scale = decorationTable->scale[i];

                temp_s0 = decorationTable->rotationPivotOffsetX[i];
                temp_s1 = decorationTable->rotationPivotOffsetY[i];

                rotX = decorationTable->rotX[i] * 2;
                rotY = decorationTable->rotY[i] * 2;
                rotZ = decorationTable->rotZ[i] * 2;

                phi_s6 = 120;
                phi_s4 = 20;
                if (temp_v1 < 50) {
                    phi_s6 = 50;
                    phi_s4 = 8;
                } else if (temp_v1 < 100) {
                    phi_s6 = 70;
                    phi_s4 = 10;
                } else if (temp_v1 < 150) {
                    phi_s6 = 100;
                    phi_s4 = 15;
                }

                guTranslateF(sp1D8, x, y, z);
                guTranslateF(sp158, -temp_s0, -temp_s1, 0.0f);
                guTranslateF(sp198, temp_s0, temp_s1, 0.0f);
                guRotateF(sp18, rotX, 1.0f, 0.0f, 0.0f);
                guRotateF(sp58, rotY, 0.0f, 1.0f, 0.0f);
                guRotateF(sp98, rotZ, 0.0f, 0.0f, 1.0f);
                guMtxCatF(sp18, sp58, sp218);
                guMtxCatF(sp218, sp98, spD8);
                guScaleF(sp118, actor->scale.x * (5.0 / 7.0) * actor->scalingFactor,
                                actor->scale.y * (5.0 / 7.0) * actor->scalingFactor * partTable->verticalStretch,
                                actor->scale.z * (5.0 / 7.0));
                guMtxCatF(sp118, sp158, sp258);
                guMtxCatF(sp258, spD8, sp218);
                guMtxCatF(sp218, sp198, sp258);
                guMtxCatF(sp258, sp1D8, sp218);
                temp_s0_2 = partTable->opacity;
                partTable->opacity = phi_s6 - (sp29C * phi_s4);
                func_802591EC(0, partTable, clamp_angle(scale + 0xB4), &sp218, 1);
                partTable->opacity = temp_s0_2;
            } 
        }
    }
}

void func_802550BC(s32 arg0, Actor* actor) {
    s32 numParts = actor->numParts;
    ActorPart* partsTable = actor->partsTable;
    DecorationTable* decorationTable;
    s32 i, j;

    for (i = 0; i < numParts; i++) {
        if (partsTable->flags & ACTOR_PART_FLAG_INVISIBLE || partsTable->idleAnimations == NULL || partsTable->flags & ACTOR_PART_FLAG_2) {
            partsTable = partsTable->nextPart;
        } else {
            decorationTable = partsTable->decorationTable;
            j = decorationTable->unk_7D9;

            decorationTable->posX[j] = partsTable->currentPos.x;
            decorationTable->posY[j] = partsTable->currentPos.y;
            decorationTable->posZ[j] = partsTable->currentPos.z;
            decorationTable->scale[j] = actor->yaw;

            decorationTable->rotationPivotOffsetX[j] = actor->rotationPivotOffset.x;
            decorationTable->rotationPivotOffsetY[j] = actor->rotationPivotOffset.y;

            decorationTable->rotX[j] = clamp_angle(actor->rotation.x) * 0.5f;
            decorationTable->rotY[j] = clamp_angle(actor->rotation.y) * 0.5f;
            decorationTable->rotZ[j] = clamp_angle(actor->rotation.z) * 0.5f;

            j++;
            if (j >= ARRAY_COUNT(decorationTable->posX)) {
                j = 0;
            }
            decorationTable->unk_7D9 = j;
        }
    }
}

void func_802552EC(s32 arg0, Actor* actor) {
    DecorationTable* decorationTable;
    ActorPart* partTable;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Matrix4f spD8;
    Matrix4f sp118;
    Matrix4f sp158;
    Matrix4f sp198;
    Matrix4f sp1D8;
    Matrix4f sp218;
    Matrix4f sp258;
    Matrix4f sp298;
    Matrix4f sp2D8;
    s32 numParts;
    s32 i, j, k, l;
    f32 x, y, z;
    f32 rotX, rotY, rotZ;
    s32 scale;
    s32 opacity;
    s32 pivotX;
    s32 pivotY;
    s32 phi_fp;
    s32 phi_s6;
    s32 temp;
    s32 flags;

    guRotateF(sp18, actor->rotation.x, 1.0f, 0.0f, 0.0f);
    guRotateF(sp58, actor->rotation.y, 0.0f, 1.0f, 0.0f);
    guRotateF(sp98, actor->rotation.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp18, sp58, sp198);
    guMtxCatF(sp198, sp98, spD8);
    guScaleF(sp118, actor->scale.x * (5.0 / 7.0) * actor->scalingFactor,
                    actor->scale.y * (5.0 / 7.0) * actor->scalingFactor, 
                    actor->scale.z * (5.0 / 7.0));
    guMtxCatF(sp118, spD8, sp298);

    numParts = actor->numParts;
    partTable = actor->partsTable;
    for (i = 0; i < numParts; i++) {
        if ((partTable->idleAnimations == NULL) || (partTable->flags & ACTOR_PART_FLAG_2)) {  
            partTable = partTable->nextPart;
            continue; 
        }

        decorationTable = partTable->decorationTable;
        if (decorationTable->effectType != 0) {
            decorationTable->effectType--;
            if (decorationTable->effectType == 0) {
                actor->flags &= ~ACTOR_FLAG_10000000;
                partTable = partTable->nextPart;
                continue;
            }
        }

        if (partTable->flags & ACTOR_PART_FLAG_INVISIBLE) {
            partTable = partTable->nextPart;
            continue;
        }

        if (partTable->flags & ACTOR_PART_FLAG_100000) {
            guScaleF(sp2D8, actor->scale.x * (5.0 / 7.0), actor->scale.y * (5.0 / 7.0), actor->scale.z * (5.0 / 7.0));
        }

        j = decorationTable->unk_7D9;
        k = 0;
        l = 0;

        while (1) {
            j--;
            k++;

            if (j < 0) {
                j = 15;
            }

            if (j == decorationTable->unk_7D9 || k < 3) {
                break;
            }


            k = 0;
            l++;

            if (decorationTable->unk_7DA < l) {
                break;
            }

            opacity = partTable->opacity;

            x = decorationTable->posX[j];
            y = decorationTable->posY[j];
            z = decorationTable->posZ[j];

            scale = decorationTable->scale[j];

            pivotX = decorationTable->rotationPivotOffsetX[j];
            pivotY = decorationTable->rotationPivotOffsetY[j];

            rotX = decorationTable->rotX[j] * 2;
            rotY = decorationTable->rotY[j] * 2;
            rotZ = decorationTable->rotZ[j] * 2;

            phi_fp = 120;
            phi_s6 = 20;
            if (opacity < 50) {
                phi_fp = 50;
                phi_s6 = 8;
            } else if (opacity < 100) {
                phi_fp = 70;
                phi_s6 = 10;
            } else if (opacity < 150) {
                phi_fp = 100;
                phi_s6 = 15;
            }

            if (!(actor->flags & ACTOR_FLAG_HP_OFFSET_BELOW)) {
                guTranslateF(sp218, -pivotX, -pivotY, 0.0f);
                guTranslateF(sp258, pivotX, pivotY, 0.0f);
            } else {
                guTranslateF(sp218, -pivotX, pivotY, 0.0f);
                guTranslateF(sp258, pivotX, -pivotY, 0.0f);
            }

            guTranslateF(sp158, x, y, z);
            guRotateF(sp18, rotX, 1.0f, 0.0f, 0.0f);
            guRotateF(sp58, rotY, 0.0f, 1.0f, 0.0f);
            guRotateF(sp98, rotZ, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp58, sp18, sp198);
            guMtxCatF(sp198, sp98, spD8);
            guScaleF(sp118, partTable->scale.x, partTable->scale.y * partTable->verticalStretch, partTable->scale.z);
            guMtxCatF(sp118, sp218, sp1D8);
            guMtxCatF(sp1D8, spD8, sp198);
            guMtxCatF(sp198, sp258, sp1D8);

            if (!(partTable->flags & ACTOR_PART_FLAG_100000)) {
                guMtxCatF(sp1D8, sp298, sp198);
            } else {
                guMtxCatF(sp1D8, sp2D8, sp198);
            }
            guMtxCatF(sp198, sp158, sp1D8);

            flags = ACTOR_PART_FLAG_80000000;
            temp = phi_fp - l * phi_s6;
            if (arg0 == 0) {
                spr_draw_npc_sprite(partTable->unk_84 | flags, scale, temp, 0, sp1D8);
            } else {
                spr_draw_npc_sprite(partTable->unk_84 | flags, clamp_angle(scale + 0xB4), temp, 0, sp1D8);
            }
        }
    }
}

void func_8025593C(Actor* actor) {
    func_802550BC(0, actor);
}

void func_8025595C(Actor* actor) {
    func_802552EC(0, actor);
}

void func_8025597C(Actor* actor) {
    func_802550BC(1, actor);
}

void func_8025599C(Actor* actor) {
    func_802552EC(1, actor);
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

void update_player_actor_shadow(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Camera* camera = &gCameras[CAM_BATTLE];
    Actor* player = battleStatus->playerActor;
    ActorPart* parts = player->partsTable;
    Shadow* shadow;
    f32 x, y, z, distance;

    parts->unk_8C = spr_update_player_sprite(0, parts->currentAnimation, parts->animationRate);

    if (player->flags & ACTOR_FLAG_10000000) {
        func_802549F4(player);
    }

    shadow = get_shadow_by_index(player->shadow);
    shadow->flags &= ~SHADOW_FLAGS_1;

    if (!battleStatus->outtaSightActive) {
        shadow->unk_05 = 128;
    } else {
        shadow->unk_05 = 40;
    }

    distance = 32767.0f;
    x = player->currentPos.x + player->headOffset.x;
    z = player->currentPos.z + player->headOffset.z;
    y = player->currentPos.y + player->headOffset.y + 12.0;
    npc_raycast_down_sides(0, &x, &y, &z, &distance);

    if (distance > 200.0f) {
        shadow->flags |= SHADOW_FLAGS_1;
    }
    shadow->position.x = x;
    shadow->position.y = y;
    shadow->position.z = z;
    shadow->rotation.y = clamp_angle(player->yaw - camera->currentYaw);
    set_standard_shadow_scale(shadow, distance);
    shadow->scale.x *= player->shadowScale * player->scalingFactor;

    if (parts->opacity >= 255 && !(parts->flags & 0x100)) {
        player->renderMode = RENDER_MODE_ALPHATEST;
    } else {
        player->renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;
    }
}

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

