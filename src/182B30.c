#include "common.h"
#include "sprite.h"
#include "effects.h"
#include "battle/battle.h"

extern u8 D_80284080[];
extern u16 D_802840B4[];
extern u16 D_802840DC[];
extern u8 D_80284104[];
extern u8 D_80284120[];

void update_player_actor_shadow(void);
void func_80255FE0(s32, void*);
void func_802571F0(s32, Actor*);
void func_80259494(ActorPart*);
void func_8025950C(ActorPart*, s32, Matrix4f);
void func_802596C0(ActorPart*, s32, Matrix4f);
void func_802597B0(ActorPart*, s32, Matrix4f);
void func_8025995C(ActorPart*, s32, Matrix4f);
void func_8025C918(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx);
void func_8025CD40(s32, ActorPart*);

void func_8025D150(ActorPart*, s32);
void func_8025D160(ActorPart*, s32);
void func_8025D2B0(ActorPart*, s32);
void func_8025D3CC(ActorPart*, s32);
void func_8025D4C8(ActorPart*, s32);
void func_8025D640(ActorPart*, s32);
void func_8025D71C(ActorPart*, s32);
void func_8025D830(ActorPart*, s32);
void func_8025D90C(ActorPart*, s32);
void func_8025DA68(ActorPart*, s32);
void func_8025DBD0(ActorPart*, s32);
void func_8025DD60(ActorPart*, s32);

void func_80259A48(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4);
void func_80259AAC(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4);
void func_80259D9C(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4);
void func_8025A2C4(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4);
void func_8025A50C(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4);
void func_8025A74C(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4);
void func_8025AA80(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4);
void func_8025AD90(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4);
void func_8025B1A8(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4);
void func_8025B5C0(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4, s32 arg5);
void func_8025BAA0(s32 arg0, ActorPart* part, s32 yaw, s32 arg3, Matrix4f mtx, s32 arg5);
void func_8025C120(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4);

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

void mtx_mirror_y(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = -1.0f;
    mtx[2][2] = 1.0f;
    mtx[3][3] = 1.0f;
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
                guScaleF(sp118, actor->scale.x * SPRITE_PIXEL_SCALE * actor->scalingFactor,
                                actor->scale.y * SPRITE_PIXEL_SCALE * actor->scalingFactor * partTable->verticalStretch,
                                actor->scale.z * SPRITE_PIXEL_SCALE);
                guMtxCatF(sp118, sp158, sp258);
                guMtxCatF(sp258, spD8, sp218);
                guMtxCatF(sp218, sp198, sp258);
                guMtxCatF(sp258, sp1D8, sp218);
                temp_s0_2 = partTable->opacity;
                partTable->opacity = phi_s6 - (sp29C * phi_s4);
                func_802591EC(0, partTable, clamp_angle(scale + 180), sp218, 1);
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
    guScaleF(sp118, actor->scale.x * SPRITE_PIXEL_SCALE * actor->scalingFactor,
                    actor->scale.y * SPRITE_PIXEL_SCALE * actor->scalingFactor,
                    actor->scale.z * SPRITE_PIXEL_SCALE);
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
            guScaleF(sp2D8, actor->scale.x * SPRITE_PIXEL_SCALE, actor->scale.y * SPRITE_PIXEL_SCALE, actor->scale.z * SPRITE_PIXEL_SCALE);
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

            if (j == decorationTable->unk_7D9) {
                break;
            }

            if (k < 3) {
                continue;
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

void func_8025595C(void* data) {
    Actor* actor = data;

    func_802552EC(0, actor);
}

void func_8025597C(Actor* actor) {
    func_802550BC(1, actor);
}

void func_8025599C(void* data) {
    Actor* actor = data;

    func_802552EC(1, actor);
}

void update_actor_shadow(s32 arg0, Actor* actor) {
    Camera* camera = &gCameras[CAM_BATTLE];
    ActorPart* actorPart;
    Shadow* shadow;
    s32 numParts;
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    f32 dist;
    s32 spriteID;
    f32 yaw;
    s32 i;

    if (actor != NULL) {
        shadow = get_shadow_by_index(actor->shadow.id);
        shadow->flags |= SHADOW_FLAGS_HIDDEN;
        if (!(actor->flags & ACTOR_FLAG_DISABLED)) {
            if (actor->flags & ACTOR_FLAG_10000000) {
                if (arg0 == 0) {
                    func_8025593C(actor);
                } else {
                    func_8025597C(actor);
                }
            }

            actor->renderMode = RENDER_MODE_ALPHATEST;
            x1 = actor->currentPos.x + actor->headOffset.x;
            if (!(actor->flags & ACTOR_FLAG_HP_OFFSET_BELOW)) {
                y1 = actor->currentPos.y + actor->headOffset.y;
            } else {
                y1 = actor->currentPos.y - actor->headOffset.y;
            }
            z1 = actor->currentPos.z + actor->headOffset.z;
            numParts = actor->numParts;
            actorPart = actor->partsTable;

            for (i = 0; i < numParts; i++) {
                if (!(actorPart->flags & ACTOR_PART_FLAG_INVISIBLE) && actorPart->idleAnimations != NULL) {
                    spriteID = actorPart->unk_84;
                    if (spriteID >= 0) {
                        spr_update_sprite(spriteID, actorPart->currentAnimation, actorPart->animationRate);
                        actorPart->unk_8C = func_802DE5C8(actorPart->unk_84);
                    }

                    if (!(actorPart->flags & ACTOR_PART_FLAG_100000)) {
                        x2 = x1 + actorPart->partOffset.x + actorPart->visualOffset.x;
                        if (!(actor->flags & ACTOR_FLAG_HP_OFFSET_BELOW)) {
                            y2 = y1 + actorPart->partOffset.y + actorPart->visualOffset.y;
                        } else {
                            y2 = y1 - actorPart->partOffset.y - actorPart->visualOffset.y;
                        }
                        z2 = z1 + actorPart->partOffset.z + actorPart->visualOffset.z;
                        yaw = actorPart->yaw = actor->yaw;
                    } else {
                        x2 = actorPart->absolutePosition.x + actorPart->visualOffset.x;
                        y2 = actorPart->absolutePosition.y + actorPart->visualOffset.y;
                        z2 = actorPart->absolutePosition.z + actorPart->visualOffset.z;
                        yaw = actorPart->yaw;
                    }
                    actorPart->currentPos.x = x2;
                    actorPart->currentPos.y = y2;
                    actorPart->currentPos.z = z2;

                    if (!(actorPart->flags & ACTOR_PART_FLAG_4)) {
                        shadow = get_shadow_by_index(actorPart->shadowIndex);
                        shadow->flags &= ~SHADOW_FLAGS_HIDDEN;
                        x1 = actorPart->currentPos.x;
                        if (!(actor->flags & ACTOR_FLAG_HP_OFFSET_BELOW)) {
                            y1 = actorPart->currentPos.y + 12.0;
                        } else {
                            y1 = actorPart->currentPos.y - 12.0;
                        }
                        z1 = actorPart->currentPos.z;

                        dist = 32767.0f;
                        npc_raycast_down_sides(0, &x1, &y1, &z1, &dist);

                        if (200.0f < dist) {
                            shadow->flags |= SHADOW_FLAGS_HIDDEN;
                        }
                        shadow->position.x = x1;
                        shadow->position.y = y1;
                        shadow->position.z = z1;
                        shadow->rotation.y = clamp_angle(yaw - camera->currentYaw);
                        set_standard_shadow_scale(shadow, dist);
                        shadow->scale.x *= actorPart->shadowScale;
                    }
                    if (actorPart->opacity < 255 || actorPart->flags & ACTOR_PART_FLAG_100) {
                        actor->renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;
                    }
                }
                actorPart = actorPart->nextPart;
            }

            shadow = get_shadow_by_index(actor->shadow.id);
            if (!(actor->flags & ACTOR_FLAG_NO_SHADOW)) {
                shadow->flags &= ~ACTOR_FLAG_DISABLED;
            }

            x1 = actor->currentPos.x + actor->headOffset.x;
            if (!(actor->flags & ACTOR_FLAG_HP_OFFSET_BELOW)) {
                y1 = actor->currentPos.y + actor->headOffset.y + 12.0;
            } else {
                y1 = actor->currentPos.y - actor->headOffset.y + 12.0;
            }
            z1 = actor->currentPos.z + actor->headOffset.z;

            dist = 32767.0f;
            npc_raycast_down_sides(0, &x1, &y1, &z1, &dist);

            if (200.0f < dist) {
                shadow->flags |= SHADOW_FLAGS_HIDDEN;
            }
            shadow->position.x = x1;
            shadow->position.y = y1;
            shadow->position.z = z1 + bActorOffsets[actor->actorType].shadow;
            shadow->rotation.y = clamp_angle(actor->yaw - camera->currentYaw);
            set_standard_shadow_scale(shadow, dist);
            shadow->scale.x *= actor->shadowScale * actor->scalingFactor;
        }
    }
}

void update_enemy_shadows(void) {
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

void func_80257B28(void* data) {
    func_80255FE0(0, data);
}

void func_80257B48(void* data) {
    func_80255FE0(1, data);
}

void func_80257B68(void* data) {
    Actor* actor = data;

    func_802571F0(0, actor);
}

void func_80257B88(void* data) {
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

    shadow = get_shadow_by_index(player->shadow.id);
    shadow->flags &= ~SHADOW_FLAGS_HIDDEN;

    if (!battleStatus->outtaSightActive) {
        shadow->alpha = 128;
    } else {
        shadow->alpha = 40;
    }

    distance = 32767.0f;
    x = player->currentPos.x + player->headOffset.x;
    z = player->currentPos.z + player->headOffset.z;
    y = player->currentPos.y + player->headOffset.y + 12.0;
    npc_raycast_down_sides(0, &x, &y, &z, &distance);

    if (distance > 200.0f) {
        shadow->flags |= SHADOW_FLAGS_HIDDEN;
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

s32 func_802591EC(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    s32 opacity;
    s32 sprMask;

    if (part->flags & ACTOR_PART_FLAG_2) {
        opacity = 255;
        sprMask = 0;
        if (part->opacity < 255) {
            sprMask = 0x80000000;
            opacity = part->opacity;
        }
        if (part->flags & ACTOR_PART_FLAG_100) {
            opacity = opacity * 120 / 255;
            sprMask = 0x80000000;
        }
        if (arg0 == 0) {
            if (opacity == 255) {
                spr_draw_player_sprite(0, yaw, 0, NULL, mtx);
            } else {
                spr_draw_player_sprite(sprMask, yaw, opacity, NULL, mtx);
            }
        } else {
            if (opacity == 255) {
                spr_draw_npc_sprite(part->unk_84, yaw, 0, NULL, mtx);
            } else {
                spr_draw_npc_sprite(part->unk_84 | sprMask, yaw, opacity, NULL, mtx);
            }
        }
        return 0;
    } else {
        switch (part->decorationTable->unk_6C0) {
            case 0:
                func_80259A48(arg0, part, yaw, mtx, arg4);
                return 0;
            case 3:
                func_80259AAC(arg0, part, yaw, mtx, arg4);
                break;
            case 4:
                func_80259D9C(arg0, part, yaw, mtx, arg4);
                break;
            case 5:
                func_8025A2C4(arg0, part, yaw, mtx, arg4);
                break;
            case 6:
                func_8025A50C(arg0, part, yaw, mtx, arg4);
                break;
            case 7:
                func_8025A74C(arg0, part, yaw, mtx, arg4);
                break;
            case 8:
                func_8025AA80(arg0, part, yaw, mtx, arg4);
                break;
            case 9:
                func_8025AD90(arg0, part, yaw, mtx, arg4);
                break;
            case 10:
                func_8025B1A8(arg0, part, yaw, mtx, arg4);
                break;
            case 12:
                func_8025B5C0(arg0, part, yaw, mtx, arg4, 0);
                break;
            case 13:
                func_8025B5C0(arg0, part, yaw, mtx, arg4, 1);
                break;
            case 14:
                func_8025BAA0(arg0, part, yaw, 0, mtx, arg4);
                break;
            case 15:
                func_8025BAA0(arg0, part, yaw, 1, mtx, arg4);
                break;
            case 16:
                func_8025C120(arg0, part, yaw, mtx, arg4);
                break;
            default:
                break;
        }
    }

    return 0;
}

INCLUDE_ASM(s32, "182B30", func_80259494);

INCLUDE_ASM(s32, "182B30", func_8025950C);

void func_802596C0(ActorPart* part, s32 yaw, Matrix4f mtx) {
    DecorationTable* decorationTable = part->decorationTable;
    s32 opacity;
    s32 idMask;

    opacity = 255;

    idMask = 0;

    if (part->opacity < 255) {
        idMask = 0x80000000;
        opacity = part->opacity;
    }

    if (part->flags & ACTOR_PART_FLAG_100) {
        idMask = 0x80000000;
        opacity = (opacity * 120) / 255;
    }

    if (decorationTable->unk_768 != 0) {
        func_80259494(part);
        spr_draw_npc_sprite(part->unk_84 | 0x20000000 | idMask, yaw, opacity, decorationTable->unk_76C, mtx);
    } else {
        spr_draw_npc_sprite(part->unk_84 | 0x20000000 | idMask, yaw, opacity, decorationTable->unk_6D4, mtx);
    }
}

INCLUDE_ASM(s32, "182B30", func_802597B0);

void func_8025995C(ActorPart* part, s32 yaw, Matrix4f mtx) {
    DecorationTable* decorationTable = part->decorationTable;
    s32 partOpacity = part->opacity;
    s32 opacity = 255;
    s32 idMask = 0;

    if (partOpacity < 0xFF) {
        idMask = 0x80000000;
        opacity = partOpacity;
    }
    if (part->flags & 0x100) {
        idMask = 0x80000000;
        opacity = (opacity * 120) / 255;
    }

    if (decorationTable->unk_768 != 0) {
        func_80259494(part);
        idMask |= 0x20000000;
        spr_draw_player_sprite(idMask, yaw, opacity, decorationTable->unk_76C, mtx);
    } else {
        idMask |= 0x20000000;
        spr_draw_player_sprite(idMask, yaw, opacity, decorationTable->unk_6D4, mtx);
    }
}

void func_80259A48(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;

    if (decorationTable->unk_6C1 != 0) {
        part->verticalStretch = 1;
        part->unkOffset[0] = 0;
        part->unkOffset[1] = 0;
        decorationTable->unk_6C1 = 0;
    }
    if (arg0 == 0) {
        func_802597B0(part, yaw, mtx);
    } else {
        func_8025950C(part, yaw, mtx);
    }
}

void func_80259AAC(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    s32 i, j;

    if (decorationTable->unk_6C1 != 0) {
        if (arg0 == 0) {
            decorationTable->palettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
        } else {
            decorationTable->palettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
        }
        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6C1 = 0;
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        u16* palIn = decorationTable->palettes[i];
        u16* palOut = decorationTable->unk_00[i];
        decorationTable->unk_6D4[i] = palOut;
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                u8 r = ((*palIn >> 11) & 0x1F);
                u8 g = ((*palIn >> 6) & 0x1F);
                u8 b = ((*palIn >> 1) & 0x1F);
                u8 a = *palIn & 1;
                palIn++;

                r *= 0.2;
                g *= 0.4;
                b *= 0.7;

                *palOut++ = (r << 11) | (g << 6) | (b << 1) | a;
            }
        }
    }
    switch (decorationTable->unk_6C2) {
        case 0:
        case 1:
            if (arg0 == 0) {
                func_8025995C(part, yaw, mtx);
            } else {
                func_802596C0(part, yaw, mtx);
            }
            break;
    }
}

void func_80259D9C(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;
    s32 temp;

    if (decorationTable->unk_6C1 != 0) {
        if (arg0 == 0) {
            decorationTable->palettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6CC = 6;
        } else {
            decorationTable->palettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6CC = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }

        for (i = 0; i < decorationTable->numPalettes; i++) {
            palIn = decorationTable->palettes[i];
            palOut = decorationTable->unk_00[i];
            if (palIn != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                    *palOut++ = *palIn++;
                }
            }
        }

        decorationTable->unk_6C2 = -2;
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C1 = 0;
        decorationTable->unk_6C8 = 0;
    }
    if (arg4 == 0) {
        if (decorationTable->unk_6C8 == 0) {
            decorationTable->unk_6C2 += 2;
            if (D_80284080[decorationTable->unk_6C2] == 255) {
                decorationTable->unk_6C2 = 0;
            }
            decorationTable->unk_6C8 = D_80284080[decorationTable->unk_6C2 + 1] / 2;
        }
        temp = D_80284080[decorationTable->unk_6C2];
        decorationTable->unk_6C8--;
    } else {
        temp = D_80284080[decorationTable->unk_6C2];
    }
    switch (temp) {
        case 0:
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                palIn = decorationTable->palettes[i];
                palOut = decorationTable->unk_00[i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 1:
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                palIn = decorationTable->palettes[decorationTable->unk_6CC * 3 + i];
                palOut = decorationTable->unk_00[i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                palIn = decorationTable->palettes[i];
                palOut = decorationTable->unk_00[i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                        u8 r = ((*palIn >> 11) & 0x1F);
                        u8 g = ((*palIn >> 6) & 0x1F);
                        u8 b = ((*palIn >> 1) & 0x1F);
                        u8 a = *palIn & 1;
                        palIn++;

                        r *= 0.1;
                        g *= 0.1;
                        b *= 0.1;

                        *palOut++ = (r << 11) | (g << 6) | (b << 1) | a;
                    }
                }
            }
            break;
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->unk_00[i];
    }

    if (arg0 == 0) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }

    if (arg4 == 0) {
        decorationTable->unk_6CA--;
    }
}

void func_8025A2C4(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;
    s32 temp;

    if (decorationTable->unk_6C1 != 0) {
        if (arg0 == 0) {
            decorationTable->palettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 2;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
        } else {
            decorationTable->palettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
        }

        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C8 = 0;
        decorationTable->unk_6C1 = 0;
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        palIn = decorationTable->palettes[i];
        palOut = decorationTable->unk_00[i];
        decorationTable->unk_6D4[i] = palOut;
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                u8 r = ((*palIn >> 12) & 0xF);
                u8 g = ((*palIn >> 7) & 0xF);
                u8 b = ((*palIn >> 2) & 0xF);
                u8 a = *palIn & 1;
                palIn++;
                *palOut++ = (r << 11) | (g << 6) | (b << 1) | a;
            }
        }
    }

    if (decorationTable->unk_6C8 <= 0) {
        part->unkOffset[0] = D_802840B4[abs(decorationTable->unk_6C8)];
        if (part->unkOffset[0] == 255) {
            part->unkOffset[0] = 0;
            decorationTable->unk_6C8 = rand_int(60) + 30;
        }
    }

    if (arg4 == 0) {
        decorationTable->unk_6C8--;
    }

    if (arg0 == 0) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }
}

void func_8025A50C(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;

    if (decorationTable->unk_6C1 != 0) {
        if (arg0 == 0) {
            decorationTable->palettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6CC = 6;
        } else {
            decorationTable->palettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6CC = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }

        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C1 = 0;
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        palIn = decorationTable->palettes[i];
        palOut = decorationTable->unk_00[i];
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                *palOut++ = *palIn++;
            }
        }
    }
    for (i = 0; i < decorationTable->unk_6CC; i++) {
        palIn = decorationTable->palettes[decorationTable->unk_6CC + i];
        palOut = decorationTable->unk_00[i];
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                *palOut++ = *palIn++;
            }
        }
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->unk_00[i];
    }

    if (arg0 == 0) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }
}

void func_8025A74C(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;

    if (decorationTable->unk_6C1 != 0) {
        if (arg0 == 0) {
            decorationTable->palettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
        } else {
            decorationTable->palettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
        }

        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6C8 = 0;
        decorationTable->unk_6CA = 10;
        decorationTable->unk_6C1 = 0;
    }
    for (i = 0; i < decorationTable->numPalettes; i++) {
        palIn = decorationTable->palettes[i];
        palOut = decorationTable->unk_00[i];
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                u8 r = ((*palIn >> 11) & 0x1F);
                u8 g = ((*palIn >> 6) & 0x1F);
                u8 b = ((*palIn >> 1) & 0x1F);
                u8 a = *palIn & 1;
                palIn++;
                r += 4;
                if (r > 0x1F) {
                    r = 0x1F;
                }
                g += 4;
                if (g > 0x1F) {
                    g = 0x1F;
                }
                b += 4;
                if (b > 0x1F) {
                    b = 0x1F;
                }

                *palOut++ = (r << 11) | (g << 6) | (b << 1) | a;
            }
        }
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->unk_00[i];
    }

    switch (decorationTable->unk_6C2) {
        case 0:
        case 1:
            if (decorationTable->unk_6C8 <= 0) {
                part->unkOffset[1] = D_802840DC[abs(decorationTable->unk_6C8)];
                if (part->unkOffset[1] == 255) {
                    part->unkOffset[1] = 0;
                    decorationTable->unk_6C8 = rand_int(60) + 30;
                }
            }

            if (arg4 == 0) {
                decorationTable->unk_6C8--;
            }

            switch ((s16)decorationTable->unk_6CA) {
                case 10:
                case 12:
                    if (arg0 == 0) {
                        func_8025995C(part, yaw, mtx);
                    } else {
                        func_802596C0(part, yaw, mtx);
                    }
                    break;
                case 13:
                    decorationTable->unk_6CA = 0;
                    /* fallthrough */
                default:
                    if (arg0 == 0) {
                        func_802597B0(part, yaw, mtx);
                    } else {
                        func_8025950C(part, yaw, mtx);
                    }
                    break;
            }

            if (arg4 == 0) {
                decorationTable->unk_6CA++;
            }
            break;
    }
}

void func_8025AA80(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    s32 i, j;

    if (decorationTable->unk_6C1 != 0) {
        if (arg0 == 0) {
            decorationTable->palettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6C2 = 0;
        } else {
            decorationTable->palettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6C2 = 0;
        }
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6C1 = 0;
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        u16* palIn = decorationTable->palettes[i];
        u16* palOut = decorationTable->unk_00[i];
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                u8 r = ((*palIn >> 11) & 0x1F);
                u8 g = ((*palIn >> 6) & 0x1F);
                u8 b = ((*palIn >> 1) & 0x1F);
                u8 a = *palIn & 1;
                palIn++;

                r *= 0.8;
                g *= 0.6;
                b *= 0.1;

                *palOut++ = (r << 11) | (g << 6) | (b << 1) | a;
            }
        }
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->unk_00[i];
    }

    if (arg0 == 0) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }
}

void func_8025AD90(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;
    s32 temp;

    if (decorationTable->unk_6C1 != 0) {
        if (arg0 == 0) {
            decorationTable->palettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6CC = 6;
        } else {
            decorationTable->palettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6CC = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }

        for (i = 0; i < decorationTable->numPalettes; i++) {
            palIn = decorationTable->palettes[i];
            palOut = decorationTable->unk_00[i];
            if (palIn != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                    *palOut++ = *palIn++;
                }
            }
        }

        decorationTable->unk_6C2 = -2;
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C1 = 0;
        decorationTable->unk_6C8 = 0;
    }
    if (arg4 == 0) {
        if (decorationTable->unk_6C8 == 0) {
            decorationTable->unk_6C2 += 2;
            if (D_80284104[decorationTable->unk_6C2] == 255) {
                decorationTable->unk_6C2 = 0;
            }
            decorationTable->unk_6C8 = D_80284104[decorationTable->unk_6C2 + 1] / 2;
        }
        temp = D_80284104[decorationTable->unk_6C2];
        decorationTable->unk_6C8--;
    } else {
        temp = D_80284104[decorationTable->unk_6C2];
    }
    switch (temp) {
        case 0:
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                palIn = decorationTable->palettes[i];
                palOut = decorationTable->unk_00[i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 1:
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                palIn = decorationTable->palettes[decorationTable->unk_6CC * 5 + i];
                palOut = decorationTable->unk_00[i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                palIn = decorationTable->palettes[decorationTable->unk_6CC * 6 + i];
                palOut = decorationTable->unk_00[i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->unk_00[i];
    }

    if (arg0 == 0) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }

    if (arg4 == 0) {
        decorationTable->unk_6CA--;
    }
}

void func_8025B1A8(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;
    s32 temp;

    if (decorationTable->unk_6C1 != 0) {
        if (arg0 == 0) {
            decorationTable->palettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6CC = 6;
        } else {
            decorationTable->palettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6CC = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }

        for (i = 0; i < decorationTable->numPalettes; i++) {
            palIn = decorationTable->palettes[i];
            palOut = decorationTable->unk_00[i];
            if (palIn != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                    *palOut++ = *palIn++;
                }
            }
        }

        decorationTable->unk_6C2 = -2;
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C1 = 0;
        decorationTable->unk_6C8 = 0;
    }
    if (arg4 == 0) {
        if (decorationTable->unk_6C8 == 0) {
            decorationTable->unk_6C2 += 2;
            if (D_80284120[decorationTable->unk_6C2] == 255) {
                decorationTable->unk_6C2 = 0;
            }
            decorationTable->unk_6C8 = D_80284120[decorationTable->unk_6C2 + 1] / 2;
        }
        temp = D_80284120[decorationTable->unk_6C2];
        decorationTable->unk_6C8--;
    } else {
        temp = D_80284120[decorationTable->unk_6C2];
    }
    switch (temp) {
        case 0:
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                palIn = decorationTable->palettes[i];
                palOut = decorationTable->unk_00[i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 1:
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                palIn = decorationTable->palettes[decorationTable->unk_6CC * 5 + i];
                palOut = decorationTable->unk_00[i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                palIn = decorationTable->palettes[decorationTable->unk_6CC * 6 + i];
                palOut = decorationTable->unk_00[i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->unk_00[i];
    }

    if (arg0 == 0) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }

    if (arg4 == 0) {
        decorationTable->unk_6CA--;
    }
}

void func_8025B5C0(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4, s32 arg5) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palIn2;
    u16* palOut;
    s32 i, j;
    u8 alpha;

    if (decorationTable->unk_6C1 != 0) {
        if (arg0 == 0) {
            decorationTable->palettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }

            if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                decorationTable->unk_6CC = 4;
            } else {
                decorationTable->unk_6CC = 6;
            }
        } else {
            decorationTable->palettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while ((s32)decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
            decorationTable->unk_6CC = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }

        if (decorationTable->unk_6C1 == 1) {
            decorationTable->unk_6C2 = 0;
            decorationTable->unk_6CA = 0;
        } else {
            decorationTable->unk_6C2 = 0;
            decorationTable->unk_6CA = 255;
        }

        for (i = 0; i < decorationTable->numPalettes; i++) {
            palIn = decorationTable->palettes[i];
            palIn2 = decorationTable->unk_00[i];
            decorationTable->unk_6D4[i] = palIn2;
            if (palIn != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                    *palIn2++ = *palIn++;
                }
            }
        }

        if (arg5) {
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                palIn = decorationTable->palettes[decorationTable->unk_6CC + i];
                palOut = decorationTable->unk_00[i];
                for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                    *palOut++ = *palIn++;
                }
            }
        }

        decorationTable->unk_6C8 = 10;
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6C1 = 0;
    }

    if (decorationTable->unk_6C2 == 0) {
        if (arg4 == 0 && decorationTable->unk_6C8 != 0) {
            decorationTable->unk_6C8--;
        } else {
            if (arg4 == 0) {
                decorationTable->unk_6CA += 2560;
                if ((s16)decorationTable->unk_6CA > 25500) {
                    decorationTable->unk_6CA = 25500;
                }
            }
            alpha = (s16)decorationTable->unk_6CA / 100;
            for (i = 0; i < decorationTable->unk_6CC; i++) {
                if (arg5 == 0) {
                    palIn = decorationTable->palettes[i];
                } else {
                    palIn = decorationTable->palettes[decorationTable->unk_6CC + i];
                }
                palIn2 = decorationTable->palettes[decorationTable->unk_6CC * 2 + i];
                palOut = decorationTable->unk_00[i];

                for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                    u8 r = (*palIn >> 11) & 0x1F;
                    u8 g = (*palIn >> 6) & 0x1F;
                    u8 b = (*palIn >> 1) & 0x1F;
                    u8 r1 = (*palIn2 >> 11) & 0x1F;
                    u8 g1 = (*palIn2 >> 6) & 0x1F;
                    u8 b1 = (*palIn2 >> 1) & 0x1F;
                    u8 a = *palIn2 & 1;
                    palIn++;
                    palIn2++;

                    r = (r * (255 - alpha) + r1 * alpha) / 255;
                    g = (g * (255 - alpha) + g1 * alpha) / 255;
                    b = (b * (255 - alpha) + b1 * alpha) / 255;

                    *palOut++ = (r << 11) | (g << 6) | (b << 1) | a;
                }
            }
            if (alpha == 255) {
                decorationTable->unk_6C2 = 1;
            }
        }
    }

    for (i = 0; i < decorationTable->numPalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->unk_00[i];
    }

    switch (decorationTable->unk_6C2) {
        case 0:
        case 1:
            if (arg0 == 0) {
                func_8025995C(part, yaw, mtx);
            } else {
                func_802596C0(part, yaw, mtx);
            }
            break;
    }
}

#ifdef NON_MATCHING
void func_8025BAA0(s32 arg0, ActorPart* part, s32 yaw, s32 arg3, Matrix4f mtx, s32 arg5) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* t1;
    u16* t2;
    u16* palOut;
    s32 i, j;
    u8 alpha;

    if (decorationTable->unk_6C1 != 0) {
        if (arg0 == 0) {
            decorationTable->palettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while (decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
        } else {
            decorationTable->palettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numPalettes = 0;
            while (decorationTable->palettes[decorationTable->numPalettes] != -1) {
                decorationTable->numPalettes++;
            }
        }

        if (decorationTable->unk_6C1 == 1) {
            decorationTable->unk_6C2 = 0;
            decorationTable->unk_6CA = 0;
        } else {
            decorationTable->unk_6C2 = 0;
            decorationTable->unk_6CA = 255;
        }

        for (i = 0; i < decorationTable->numPalettes; i++) {
            t2 = decorationTable->palettes[i];
            t1 = decorationTable->unk_00[i];
            decorationTable->unk_6D4[i] = t1;
            if (t2 != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[i]); j++) {
                    *t1++ = *t2++;
                }
            }
        }

        if (arg3 == 0) {
            decorationTable->unk_746 = decorationTable->unk_744;
            decorationTable->unk_748 = decorationTable->unk_746;
            decorationTable->unk_74A = decorationTable->unk_746;
            decorationTable->unk_744 = 0;
        }

        decorationTable->unk_6C8 = decorationTable->unk_744;
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6C1 = 0;
    }

    switch (decorationTable->unk_6C2) {
        case 0:
            if (arg5 != 0) {
                break;
            }
            if (decorationTable->unk_6C8 != 0) {
                decorationTable->unk_6C8--;
                break;
            }
            decorationTable->unk_6CA = 0;
            decorationTable->unk_6C2 = 1;
            /* fallthrough */
        case 1:
            if (arg5 == 0) {
                decorationTable->unk_6CA += 25600 / decorationTable->unk_746;
                if ((s16)decorationTable->unk_6CA > 25500) {
                    decorationTable->unk_6CA = 25500;
                }
            }
            alpha = (s16)decorationTable->unk_6CA / 100;
            t2 = decorationTable->palettes[decorationTable->unk_740];
            t1 = decorationTable->palettes[decorationTable->unk_742];
            palOut = decorationTable->unk_00[0];
            decorationTable->unk_6D4[0] = palOut;

            for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[0]); t2++, t1++, j++) {
                s32 r1 = (*t1 >> 11) & 0x1F;
                s32 r = (*t2 >> 11) & 0x1F;
                s32 g1 = (*t1 >> 6) & 0x1F;
                s32 g = (*t2 >> 6) & 0x1F;
                s32 b1 = (*t1 >> 1) & 0x1F;
                s32 b = (*t2 >> 1) & 0x1F;
                u8 a = *t1 & 1;

                r *= (255 - alpha);
                r1 = (r + r1 * alpha) / 255;
                g1 = (g * (255 - alpha) + g1 * alpha) / 255;
                b1 = (b * (255 - alpha) + b1 * alpha) / 255;
            }
            if (alpha == 255) {
                decorationTable->unk_6C2 = 2;
                decorationTable->unk_6C8 = decorationTable->unk_748;
            }
            break;
    }
    switch (decorationTable->unk_6C2) {
        case 2:
            if (arg5 != 0) {
                break;
            }
            if (decorationTable->unk_6C8 != 0) {
                decorationTable->unk_6C8--;
                break;
            }
            decorationTable->unk_6CA = 0;
            decorationTable->unk_6C2 = 3;
            /* fallthrough */
        case 3:
            if (arg5 == 0) {
                decorationTable->unk_6CA += 25600 / decorationTable->unk_74A;
                if ((s16)decorationTable->unk_6CA > 25500) {
                    decorationTable->unk_6CA = 25500;
                }
            }
            alpha = (s16)decorationTable->unk_6CA / 100;
            t2 = decorationTable->palettes[decorationTable->unk_742];
            t1 = decorationTable->palettes[decorationTable->unk_740];
            palOut = decorationTable->unk_00[0];
            decorationTable->unk_6D4[0] = palOut;

            for (j = 0; j < ARRAY_COUNT(decorationTable->unk_00[0]); j++) {
                s32 r1 = (*t1 >> 11) & 0x1F;
                s32 r = (*t2 >> 11) & 0x1F;
                s32 g1 = (*t1 >> 6) & 0x1F;
                s32 g = (*t2 >> 6) & 0x1F;
                s32 b1 = (*t1 >> 1) & 0x1F;
                s32 b = (*t2 >> 1) & 0x1F;
                u8 a = *t1 & 1;
                t2++;
                t1++;

                r1 = (r * (255 - alpha) + r1 * alpha) / 255;
                g1 = (g * (255 - alpha) + g1 * alpha) / 255;
                b1 = (b * (255 - alpha) + b1 * alpha) / 255;

                *palOut++ = ((r1 & 0xFF) << 11) | ((g1 & 0xFF) << 6) | ((b1 & 0xFF) << 1) | a;
            }
            if (alpha == 255) {
                decorationTable->unk_6C2 = 0;
                decorationTable->unk_6C8 = decorationTable->unk_744;
            }
            break;
    }

    switch (decorationTable->unk_6C2) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (arg0 == 0) {
                func_8025995C(part, yaw, mtx);
            } else {
                func_802596C0(part, yaw, mtx);
            }
            break;
    }
}
#else
INCLUDE_ASM(s32, "182B30", func_8025BAA0);
#endif

INCLUDE_ASM(s32, "182B30", func_8025C120);

s32 func_8025C840(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx) {
    if (!(part->flags & 2)) {
        switch (part->decorationTable->unk_750) {
            case 0:
                func_8025C8A0(arg0, part);
                return 0;
            case 11:
                func_8025C918(arg0, part, yaw, mtx);
                break;
        }
    }
    return 0;
}

void func_8025C8A0(s32 arg0, ActorPart* arg1) {
    if (arg1->decorationTable->unk_751 != 0) {
        arg1->decorationTable->unk_751 = 0;
        if (arg0 == 0) {
            func_802DDFF8(0, 0, 0, 0, 0, 0, 0);
        } else {
            func_802DE894(arg1->unk_84, 0, 0, 0, 0, 0, 0);
        }
    }
}

INCLUDE_ASM(s32, "182B30", func_8025C918);

s32 func_8025CCC8(s32 arg0, ActorPart* part) {
    if (!(part->flags & ACTOR_PART_FLAG_2)) {
        switch (part->decorationTable->unk_764) {
            case 0:
                func_8025CD28(arg0, part);
                return 0;
            case 1:
                func_8025CD40(arg0, part);
                return 0;
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

void func_8025CEC8(ActorPart* actorPart) {
    DecorationTable* decorationTable;
    s32 i;
    
    if (!(actorPart->flags & 2)) {
        decorationTable = actorPart->decorationTable;
        for (i = 0; i < ARRAY_COUNT(decorationTable->decorationType); i++) {
            switch (decorationTable->decorationType[i]) {
                case 0:
                    func_8025D150(actorPart, i);
                    break;
                case 1:
                    func_8025D160(actorPart, i);
                    break;
                case 2:
                    func_8025D2B0(actorPart, i);
                    break;
                case 3:
                    func_8025D3CC(actorPart, i);
                    break;
                case 4:
                    func_8025D4C8(actorPart, i);
                    break;
                case 5:
                    func_8025D640(actorPart, i);
                    break;
                case 6:
                    func_8025D71C(actorPart, i);
                    break;
                case 7:
                    func_8025D830(actorPart, i);
                    break;
                case 8:
                    func_8025D90C(actorPart, i);
                    break;
                case 9:
                    func_8025DA68(actorPart, i);
                    break;
                case 10:
                    func_8025DBD0(actorPart, i);
                    break;
                case 11:
                    func_8025DD60(actorPart, i);
                    break;
            }
        }
    }
}


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

void func_8025D150(ActorPart* actorPart, s32 i) {
}

void func_8025D158(ActorPart* part, s32 decorationIndex) {
}

INCLUDE_ASM(s32, "182B30", func_8025D160);

void func_8025D290(ActorPart* part, s32 decorationIndex) {
    // TODO cast to appropriate struct data type once we know what it is
    ((s32*) part->decorationTable->unk_8B0[decorationIndex]->data)[11] = 5;
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
    // TODO cast to appropriate struct data type once we know what it is
    ((s32*) part->decorationTable->unk_8B0[decorationIndex]->data)[11] = 5;
}

INCLUDE_ASM(s32, "182B30", func_8025D640);

void func_8025D6FC(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->unk_8B0[decorationIndex]->flags |= 0x10;
}

INCLUDE_ASM(s32, "182B30", func_8025D71C);

void func_8025D810(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->unk_8B0[decorationIndex]->flags |= 0x10;
}

INCLUDE_ASM(s32, "182B30", func_8025D830);

void func_8025D8EC(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->unk_8B0[decorationIndex]->flags |= 0x10;
}

INCLUDE_ASM(s32, "182B30", func_8025D90C);

void func_8025DA60(ActorPart* part, s32 decorationIndex) {
}

INCLUDE_ASM(s32, "182B30", func_8025DA68);

void func_8025DBC8(ActorPart* part, s32 decorationIndex) {
}

INCLUDE_ASM(s32, "182B30", func_8025DBD0);

void func_8025DD40(ActorPart* part, s32 decorationIndex) {
    // TODO cast to appropriate struct data type once we know what it is
    ((s32*) part->decorationTable->unk_8B0[decorationIndex]->data)[11] = 5;
}

INCLUDE_ASM(s32, "182B30", func_8025DD60);

void func_8025DE88(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->unk_8B0[decorationIndex]->flags |= 0x10;
}
