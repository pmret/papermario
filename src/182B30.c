#include "common.h"
#include "sprite.h"
#include "effects.h"
#include "battle/battle.h"

u8 D_80284080[] = { 0, 32, 1, 4, 2, 2, 0, 16, 1, 2, 0, 64, 1, 2, 2, 2, 0, 28, 1, 2, 0, 18, 1, 4, 0, 16, 1, 2, 0, 80,
                    1, 2, 0, 16, 2, 2, 1, 2, 0, 32, 1, 2, 0, 14, 1, 2, 2, 2, 255, 0, 0, 0 };
s16 D_802840B4[] = { -2, 2, 0, 0, -2, 2, 0, 0, 0, 0, -2, 2, 0, 0, 0, 0, 0, 0, 255, 0 };
s16 D_802840DC[] = { -2, 2, 0, 0, -2, 2, 0, 0, 0, 0, -2, 2, 0, 0, 0, 0, 0, 0, 255, 0 };
u8 D_80284104[] = { 1, 2, 0, 52, 1, 4, 0, 54, 0, 54, 1, 2, 0, 28, 1, 2, 0, 6, 1, 2, 0, 44, 1, 2, 0, 44, 255, 0 };
u8 D_80284120[] = { 1, 2, 0, 10, 2, 4, 0, 14, 1, 2, 0, 10, 2, 4, 0, 4, 255, 0, 0, 0 };
s16 D_80284134[] = { -1, 15, 10, 7, 5, 3, 2, 1, 0, 0, 0, 0, 0, 0 };


void update_player_actor_shadow(void);
void appendGfx_npc_actor(s32 isPartner, s32 actorIndex);

void create_status_chill_out(s32 iconID);
void enable_status_2(s32 iconID);
void enable_status_chill_out(s32 iconID);
void enable_status_debuff(s16);
void enable_status_transparent(s16);
void enable_status_icon_boost_jump(s32 iconID);
void enable_status_icon_boost_hammer(s32 iconID);
s32 func_80265CE8(u32*, s32);
void func_80266DAC(Actor* actor, s32 arg1);
void create_status_icon_boost_hammer(s32 iconID);
void create_status_icon_boost_jump(s32 iconID);
void create_status_icon_peril(s32 iconID);
void create_status_icon_danger(s32 iconID);
void set_status_icons_offset(s32 iconID, s32 offsetY, s32 arg2);
void set_status_icons_properties(s32 iconID, f32 x, f32 y, f32 z, s32 arg, s32 arg2, s32 radius, s32 offsetY);

void func_802571F0(s32, Actor*);
void func_80259494(ActorPart*);
void func_8025950C(ActorPart*, s32, Matrix4f);
void func_802596C0(ActorPart*, s32, Matrix4f);
void func_802597B0(ActorPart*, s32, Matrix4f);
void func_8025995C(ActorPart*, s32, Matrix4f);
void func_8025C918(s32 arg0, ActorPart* part, s32 yaw, s32 arg3);
void func_8025CD40(s32 arg0, ActorPart* part, s32 yaw, s32 arg3);

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
s32 func_8025C840(s32 arg0, ActorPart* part, s32 yaw, s32);
s32 func_8025CCC8(s32 arg0, ActorPart* part, s32 yaw, s32);
s32 func_80265D44(s32 animID);
void func_8026709C(ActorPart* part);

s32 func_80254250(ActorPart* part) {
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
    actor->flags |= ACTOR_FLAG_BLUR_ENABLED;
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
                decorationTable->yaw[j] = actor->yaw;
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
                actor->flags &= ~ACTOR_FLAG_BLUR_ENABLED;
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
    playerActor->flags |= ACTOR_FLAG_BLUR_ENABLED;
    decorationTable->unk_7D8 = 0;
    decorationTable->unk_7D9 = 0;

    for (i = 0; i < ARRAY_COUNT(decorationTable->posX); i++) {
        decorationTable->posX[i] = partsTable->currentPos.x;
        decorationTable->posY[i] = partsTable->currentPos.y;
        decorationTable->posZ[i] = partsTable->currentPos.z;
        decorationTable->yaw[i] = playerActor->yaw;
        decorationTable->rotationPivotOffsetX[i] = playerActor->rotationPivotOffset.x * playerActor->scalingFactor;
        decorationTable->rotationPivotOffsetY[i] = playerActor->rotationPivotOffset.y * playerActor->scalingFactor;

        decorationTable->rotX[i] = clamp_angle(playerActor->rotation.x) * 0.5f;
        decorationTable->rotY[i] = clamp_angle(playerActor->rotation.y) * 0.5f;
        decorationTable->rotZ[i] = clamp_angle(playerActor->rotation.z) * 0.5f;
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
            playerActor->flags &= ~ACTOR_FLAG_BLUR_ENABLED;
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

    playerActor->flags &= ~ACTOR_FLAG_BLUR_ENABLED;
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
        decorationTable->yaw[i] = actor->yaw;

        decorationTable->rotationPivotOffsetX[i] = actor->rotationPivotOffset.x * actor->scalingFactor;
        decorationTable->rotationPivotOffsetY[i] = actor->rotationPivotOffset.y * actor->scalingFactor;

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

void appendGfx_player_actor_blur(Actor* actor) {
    Matrix4f mtxRotX, mtxRotY, mtxRotZ, mtxRotation;
    Matrix4f mtxScale;
    Matrix4f mtxPivotOn, mtxPivotOff, mtxTranslate;
    Matrix4f mtxTransform, mtxTemp;
    s32 delay;
    s32 num;
    s32 yaw;
    ActorPart* partTable;
    DecorationTable* decorationTable;
    f32 rotX, rotY, rotZ;
    s32 prevOpacity;
    s32 temp_v1;
    s32 pivotOffsetX;
    s32 pivotOffsetY;
    s32 bufPos;
    s32 newOpacityBase;
    s32 newOpacityModulus;
    f32 x, y, z;

    partTable = actor->partsTable;
    decorationTable = partTable->decorationTable;
    if (decorationTable->effectType != 0) {
        decorationTable->effectType--;
        if (decorationTable->effectType == 0) {
            actor->flags &= ~ACTOR_FLAG_BLUR_ENABLED;
            return;
        }
    }

    if (!(partTable->flags & ACTOR_PART_FLAG_INVISIBLE) && partTable->idleAnimations != NULL) {
        delay = 0;
        num = 0;
        bufPos = decorationTable->unk_7D9;

        while (1) {
            bufPos--;
            delay++;
            if (bufPos < 0) {
                bufPos = ARRAY_COUNT(decorationTable->posX) - 1;
            }
            if (bufPos == decorationTable->unk_7D9) {
                break;
            }

            if (delay >= 3) {
                delay = 0;
                num++;

                if (decorationTable->unk_7DA < num) {
                    break;
                }
                temp_v1 = partTable->opacity;
                x = decorationTable->posX[bufPos];
                y = decorationTable->posY[bufPos];
                z = decorationTable->posZ[bufPos];

                yaw = decorationTable->yaw[bufPos];

                pivotOffsetX = decorationTable->rotationPivotOffsetX[bufPos];
                pivotOffsetY = decorationTable->rotationPivotOffsetY[bufPos];

                rotX = decorationTable->rotX[bufPos] * 2;
                rotY = decorationTable->rotY[bufPos] * 2;
                rotZ = decorationTable->rotZ[bufPos] * 2;

                newOpacityBase = 120;
                newOpacityModulus = 20;
                if (temp_v1 < 50) {
                    newOpacityBase = 50;
                    newOpacityModulus = 8;
                } else if (temp_v1 < 100) {
                    newOpacityBase = 70;
                    newOpacityModulus = 10;
                } else if (temp_v1 < 150) {
                    newOpacityBase = 100;
                    newOpacityModulus = 15;
                }

                guTranslateF(mtxTranslate, x, y, z);
                guTranslateF(mtxPivotOn, -pivotOffsetX, -pivotOffsetY, 0.0f);
                guTranslateF(mtxPivotOff, pivotOffsetX, pivotOffsetY, 0.0f);
                guRotateF(mtxRotX, rotX, 1.0f, 0.0f, 0.0f);
                guRotateF(mtxRotY, rotY, 0.0f, 1.0f, 0.0f);
                guRotateF(mtxRotZ, rotZ, 0.0f, 0.0f, 1.0f);
                guMtxCatF(mtxRotX, mtxRotY, mtxTransform);
                guMtxCatF(mtxTransform, mtxRotZ, mtxRotation);
                guScaleF(mtxScale, actor->scale.x * SPRITE_WORLD_SCALE_D * actor->scalingFactor,
                                actor->scale.y * SPRITE_WORLD_SCALE_D * actor->scalingFactor * partTable->verticalStretch,
                                actor->scale.z * SPRITE_WORLD_SCALE_D);
                guMtxCatF(mtxScale, mtxPivotOn, mtxTemp);
                guMtxCatF(mtxTemp, mtxRotation, mtxTransform);
                guMtxCatF(mtxTransform, mtxPivotOff, mtxTemp);
                guMtxCatF(mtxTemp, mtxTranslate, mtxTransform);
                prevOpacity = partTable->opacity;
                partTable->opacity = newOpacityBase - (num * newOpacityModulus);
                func_802591EC(0, partTable, clamp_angle(yaw + 180), mtxTransform, 1);
                partTable->opacity = prevOpacity;
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
            decorationTable->yaw[j] = actor->yaw;

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
    Matrix4f mtxRotX, mtxRotY, mtxRotZ, mtxRotation;
    Matrix4f mtxScale, mtxTranslate;
    Matrix4f mtxTemp, mtxTransform;
    Matrix4f mtxPivotOn, mtxPivotOff;
    Matrix4f mtxActor, mtxPartScale;
    s32 numParts;
    s32 i, j, k, l;
    f32 x, y, z;
    f32 rotX, rotY, rotZ;
    s32 yaw;
    s32 opacity;
    s32 pivotX;
    s32 pivotY;
    s32 phi_fp;
    s32 phi_s6;
    s32 temp;
    s32 flags;

    guRotateF(mtxRotX, actor->rotation.x, 1.0f, 0.0f, 0.0f);
    guRotateF(mtxRotY, actor->rotation.y, 0.0f, 1.0f, 0.0f);
    guRotateF(mtxRotZ, actor->rotation.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(mtxRotX, mtxRotY, mtxTemp);
    guMtxCatF(mtxTemp, mtxRotZ, mtxRotation);
    guScaleF(mtxScale, actor->scale.x * SPRITE_WORLD_SCALE_D * actor->scalingFactor,
                    actor->scale.y * SPRITE_WORLD_SCALE_D * actor->scalingFactor,
                    actor->scale.z * SPRITE_WORLD_SCALE_D);
    guMtxCatF(mtxScale, mtxRotation, mtxActor);

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
                actor->flags &= ~ACTOR_FLAG_BLUR_ENABLED;
                partTable = partTable->nextPart;
                continue;
            }
        }

        if (partTable->flags & ACTOR_PART_FLAG_INVISIBLE) {
            partTable = partTable->nextPart;
            continue;
        }

        if (partTable->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION) {
            guScaleF(mtxPartScale, actor->scale.x * SPRITE_WORLD_SCALE_D, actor->scale.y * SPRITE_WORLD_SCALE_D, actor->scale.z * SPRITE_WORLD_SCALE_D);
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

            yaw = decorationTable->yaw[j];

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

            if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                guTranslateF(mtxPivotOn, -pivotX, -pivotY, 0.0f);
                guTranslateF(mtxPivotOff, pivotX, pivotY, 0.0f);
            } else {
                guTranslateF(mtxPivotOn, -pivotX, pivotY, 0.0f);
                guTranslateF(mtxPivotOff, pivotX, -pivotY, 0.0f);
            }

            guTranslateF(mtxTranslate, x, y, z);
            guRotateF(mtxRotX, rotX, 1.0f, 0.0f, 0.0f);
            guRotateF(mtxRotY, rotY, 0.0f, 1.0f, 0.0f);
            guRotateF(mtxRotZ, rotZ, 0.0f, 0.0f, 1.0f);
            guMtxCatF(mtxRotY, mtxRotX, mtxTemp);
            guMtxCatF(mtxTemp, mtxRotZ, mtxRotation);
            guScaleF(mtxScale, partTable->scale.x, partTable->scale.y * partTable->verticalStretch, partTable->scale.z);
            guMtxCatF(mtxScale, mtxPivotOn, mtxTransform);
            guMtxCatF(mtxTransform, mtxRotation, mtxTemp);
            guMtxCatF(mtxTemp, mtxPivotOff, mtxTransform);

            if (!(partTable->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
                guMtxCatF(mtxTransform, mtxActor, mtxTemp);
            } else {
                guMtxCatF(mtxTransform, mtxPartScale, mtxTemp);
            }
            guMtxCatF(mtxTemp, mtxTranslate, mtxTransform);

            flags = ACTOR_PART_FLAG_80000000;
            temp = phi_fp - l * phi_s6;
            if (arg0 == 0) {
                spr_draw_npc_sprite(partTable->spriteInstanceID | flags, yaw, temp, 0, mtxTransform);
            } else {
                spr_draw_npc_sprite(partTable->spriteInstanceID | flags, clamp_angle(yaw + 180), temp, 0, mtxTransform);
            }
        }
    }
}

void func_8025593C(Actor* actor) {
    func_802550BC(0, actor);
}

void appendGfx_enemy_actor_blur(void* data) {
    Actor* actor = data;

    func_802552EC(0, actor);
}

void func_8025597C(Actor* actor) {
    func_802550BC(1, actor);
}

void appendGfx_partner_actor_blur(void* data) {
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
        shadow->flags |= ENTITY_FLAG_HIDDEN;
        if (!(actor->flags & ACTOR_FLAG_DISABLED)) {
            if (actor->flags & ACTOR_FLAG_BLUR_ENABLED) {
                if (arg0 == 0) {
                    func_8025593C(actor);
                } else {
                    func_8025597C(actor);
                }
            }

            actor->renderMode = RENDER_MODE_ALPHATEST;
            x1 = actor->currentPos.x + actor->headOffset.x;
            if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                y1 = actor->currentPos.y + actor->headOffset.y;
            } else {
                y1 = actor->currentPos.y - actor->headOffset.y;
            }
            z1 = actor->currentPos.z + actor->headOffset.z;
            numParts = actor->numParts;
            actorPart = actor->partsTable;

            for (i = 0; i < numParts; i++) {
                if (!(actorPart->flags & ACTOR_PART_FLAG_INVISIBLE) && actorPart->idleAnimations != NULL) {
                    spriteID = actorPart->spriteInstanceID;
                    if (spriteID >= 0) {
                        spr_update_sprite(spriteID, actorPart->currentAnimation, actorPart->animationRate);
                        actorPart->animNotifyValue = spr_get_notify_value(actorPart->spriteInstanceID);
                    }

                    if (!(actorPart->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
                        x2 = x1 + actorPart->partOffset.x + actorPart->visualOffset.x;
                        if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
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
                        shadow->flags &= ~ENTITY_FLAG_HIDDEN;
                        x1 = actorPart->currentPos.x;
                        if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                            y1 = actorPart->currentPos.y + 12.0;
                        } else {
                            y1 = actorPart->currentPos.y - 12.0;
                        }
                        z1 = actorPart->currentPos.z;

                        dist = 32767.0f;
                        npc_raycast_down_sides(0, &x1, &y1, &z1, &dist);

                        if (200.0f < dist) {
                            shadow->flags |= ENTITY_FLAG_HIDDEN;
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
                shadow->flags &= ~ENTITY_FLAG_HIDDEN;
            }

            x1 = actor->currentPos.x + actor->headOffset.x;
            if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                y1 = actor->currentPos.y + actor->headOffset.y + 12.0;
            } else {
                y1 = actor->currentPos.y - actor->headOffset.y + 12.0;
            }
            z1 = actor->currentPos.z + actor->headOffset.z;

            dist = 32767.0f;
            npc_raycast_down_sides(0, &x1, &y1, &z1, &dist);

            if (200.0f < dist) {
                shadow->flags |= ENTITY_FLAG_HIDDEN;
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

void appendGfx_npc_actor(s32 isPartner, s32 actorIndex) {
    BattleStatus* battleStatus = &gBattleStatus;
    Matrix4f mtxRotX, mtxRotY, mtxRotZ, mtxRotation;
    Matrix4f mtxScale, mtxScaleMod;
    Matrix4f mtxPivotOn, mtxPivotOff, mtxTranslate;
    Matrix4f mtxTemp, mtxActor, mtxTransform, mtxPartScale;
    Actor* actor;
    ActorPart* part;
    EffectInstance* effect;
    s32 numParts;
    f32 actorPosX, actorPosY, actorPosZ;
    f32 partPosX, partPosY, partPosZ, partYaw;
    u32 lastAnim;
    s32 animChanged;
    s32 cond2;
    s32 decorChanged;
    s32 i;

    if (!isPartner) {
        actor = battleStatus->enemyActors[actorIndex];
    } else {
        actor = battleStatus->partnerActor;
    }
    actorPosX = actor->currentPos.x + actor->headOffset.x;
    if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        actorPosY = actor->currentPos.y + actor->headOffset.y + actor->verticalRenderOffset;
    } else {
        actorPosY = actor->currentPos.y - actor->headOffset.y + actor->verticalRenderOffset;
    }
    actorPosZ = actor->currentPos.z + actor->headOffset.z;

    actor->disableEffect->data.disableX->pos.x = actorPosX + ((actor->actorBlueprint->statusIconOffset.x + actor->unk_194) * actor->scalingFactor);
    actor->disableEffect->data.disableX->pos.y = actorPosY + ((actor->actorBlueprint->statusIconOffset.y + actor->unk_195) * actor->scalingFactor);
    actor->disableEffect->data.disableX->pos.z = actorPosZ;

    if (!(gBattleStatus.flags1 & ACTOR_PART_FLAG_4) && (actor->flags & ACTOR_FLAG_8000000)) {
        if (actor->disableDismissTimer != 0) {
            actor->disableDismissTimer--;
            actor->disableEffect->data.disableX->pos.y = NPC_DISPOSE_POS_Y;
        } else {
            actor->disableEffect->data.disableX->scale = (actor->scalingFactor * 0.75);
        }
    } else {
        actor->disableEffect->data.disableX->pos.y = NPC_DISPOSE_POS_Y;
        actor->disableDismissTimer = 10;
    }
    if (actor->debuff == STATUS_FROZEN) {
        effect = actor->icePillarEffect;
        if (actor->icePillarEffect != NULL) {
            if ((gBattleStatus.flags1 & BS_FLAGS1_8) || (!(gBattleStatus.flags1 & BS_FLAGS1_4) && (actor->flags & ACTOR_FLAG_8000000))) {
                effect->data.icePillar->pos.x = actorPosX;
                effect->data.icePillar->pos.y = actorPosY;
                effect->data.icePillar->pos.z = actorPosZ;
                effect->data.icePillar->scale = actor->size.y / 24.0;
            } else {
                effect->data.icePillar->pos.x = NPC_DISPOSE_POS_X;
                effect->data.icePillar->pos.y = NPC_DISPOSE_POS_Y;
                effect->data.icePillar->pos.z = NPC_DISPOSE_POS_Z;
            }
        }
    } else {
        effect = actor->icePillarEffect;
        if (effect != NULL) {
            effect->flags |= EFFECT_INSTANCE_FLAG_10;
            actor->icePillarEffect = NULL;
        }
    }
    set_status_icons_properties(actor->hudElementDataIndex, actorPosX, actorPosY, actorPosZ,
        (actor->actorBlueprint->statusIconOffset.x + actor->unk_194) * actor->scalingFactor,
        (actor->actorBlueprint->statusIconOffset.y + actor->unk_195) * actor->scalingFactor,
        (actor->actorBlueprint->statusMessageOffset.x + actor->unk_196) * actor->scalingFactor,
        (actor->actorBlueprint->statusMessageOffset.y + actor->unk_197) * actor->scalingFactor);

    if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        set_status_icons_offset(actor->hudElementDataIndex,
            actor->size.y * actor->scalingFactor,
            actor->size.x * actor->scalingFactor);
    } else {
        set_status_icons_offset(actor->hudElementDataIndex,
            -actor->size.y * actor->scalingFactor,
             actor->size.x * actor->scalingFactor);
    }

    do {
        if (actor->debuff == STATUS_SHRINK) {
            actor->scalingFactor += ((0.4 - actor->scalingFactor) / 6.0);
        } else {
            actor->scalingFactor += ((1.0 - actor->scalingFactor) / 6.0);
        }
    } while (0); // required to match

    if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        guTranslateF(mtxPivotOn,
            -actor->rotationPivotOffset.x * actor->scalingFactor,
            -actor->rotationPivotOffset.y * actor->scalingFactor,
            -actor->rotationPivotOffset.z * actor->scalingFactor);
        guTranslateF(mtxPivotOff,
            actor->rotationPivotOffset.x * actor->scalingFactor,
            actor->rotationPivotOffset.y * actor->scalingFactor,
            actor->rotationPivotOffset.z * actor->scalingFactor);
    } else {
        guTranslateF(mtxPivotOn,
            -actor->rotationPivotOffset.x * actor->scalingFactor,
             actor->rotationPivotOffset.y * actor->scalingFactor,
            -actor->rotationPivotOffset.z * actor->scalingFactor);
        guTranslateF(mtxPivotOff,
             actor->rotationPivotOffset.x * actor->scalingFactor,
            -actor->rotationPivotOffset.y * actor->scalingFactor,
             actor->rotationPivotOffset.z * actor->scalingFactor);
    }
    guRotateF(mtxRotX, actor->rotation.x, 1.0f, 0.0f, 0.0f);
    guRotateF(mtxRotY, actor->rotation.y, 0.0f, 1.0f, 0.0f);
    guRotateF(mtxRotZ, actor->rotation.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(mtxRotY, mtxRotX, mtxTemp);
    guMtxCatF(mtxTemp, mtxRotZ, mtxRotation);
    guScaleF(mtxScale,
        actor->scale.x * SPRITE_WORLD_SCALE_D * actor->scalingFactor,
        actor->scale.y * SPRITE_WORLD_SCALE_D * actor->scalingFactor,
        actor->scale.z * SPRITE_WORLD_SCALE_D);
    guScaleF(mtxScaleMod, actor->scaleModifier.x, actor->scaleModifier.y, actor->scaleModifier.z);
    guMtxCatF(mtxPivotOn, mtxScale, mtxTemp);
    guMtxCatF(mtxTemp, mtxScaleMod, mtxScale);
    guMtxCatF(mtxScale, mtxRotation, mtxTransform);
    guMtxCatF(mtxTransform, mtxPivotOff, mtxActor);

    part = actor->partsTable;
    numParts = actor->numParts;
    for (i = 0; i < numParts; i++) {
        if (!(part->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
            partPosX = actorPosX + part->partOffset.x + part->visualOffset.x;
            if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                partPosY = actorPosY + part->partOffset.y + part->visualOffset.y;
            } else {
                partPosY = (actorPosY - part->partOffset.y) - part->visualOffset.y;
            }
            partPosZ = actorPosZ + part->partOffset.z + part->visualOffset.z;
            partYaw = part->yaw = actor->yaw;
        } else {
            partPosX = part->absolutePosition.x + part->visualOffset.x;
            partPosY = part->absolutePosition.y + part->visualOffset.y;
            partPosZ = part->absolutePosition.z + part->visualOffset.z;
            guScaleF(mtxPartScale,
                actor->scale.x * SPRITE_WORLD_SCALE_D,
                actor->scale.y * SPRITE_WORLD_SCALE_D,
                actor->scale.z * SPRITE_WORLD_SCALE_D);
            partYaw = part->yaw;
        }
        part->currentPos.x = partPosX;
        part->currentPos.y = partPosY;
        part->currentPos.z = partPosZ;

        if (part->flags & ACTOR_PART_FLAG_INVISIBLE) {
            part = part->nextPart;
            continue;
        }
        if (part->idleAnimations == NULL) {
            part = part->nextPart;
            continue;
        }

        if (actor->transparentStatus == STATUS_TRANSPARENT) {
            part->flags |= ACTOR_PART_FLAG_100;
        } else {
            part->flags &= ~ACTOR_PART_FLAG_100;
        }

        do {
            lastAnim = part->currentAnimation;
            animChanged = FALSE;
            cond2 = FALSE;
            decorChanged = FALSE;
        } while (0); // required to match

        if (isPartner) {
            if ((gBattleStatus.flags2 & (BS_FLAGS2_10 | BS_FLAGS2_4)) == BS_FLAGS2_4) {
                do {
                    if (actor->koStatus == 0) {
                        part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_TURN_DONE);
                        spr_update_sprite(part->spriteInstanceID, part->currentAnimation, part->animationRate);
                        animChanged = TRUE;
                    }
                } while (0); // required to match
                func_80266DAC(actor, 0xC);
                cond2 = TRUE;
                func_80266EE8(actor, 0);
                decorChanged = TRUE;
            }
            if (isPartner && (gPlayerData.currentPartner == PARTNER_WATT)) {
                if (!cond2) {
                    func_80266DAC(actor, 9);
                }
                cond2 = TRUE;
            }
        }
        if (actor->isGlowing) {
            if (!decorChanged) {
                func_80266EE8(actor, 0xB);
            }
            decorChanged = TRUE;
        }
        if (actor->debuff == STATUS_POISON) {
            if (!cond2) {
                func_80266DAC(actor, 6);
            }
            cond2 = TRUE;
        }
        if (actor->debuff == STATUS_PARALYZE) {
            if (!cond2) {
                func_80266DAC(actor, 7);
            }
            cond2 = TRUE;
        }
        if (actor->debuff == STATUS_FEAR) {
            if (!cond2) {
                func_80266DAC(actor, 5);
            }
            cond2 = TRUE;
        }
        if (actor->staticStatus == STATUS_STATIC) {
            if (!cond2) {
                func_80266DAC(actor, 4);
            }
            cond2 = TRUE;
        }
        if ((!cond2) && !(part->flags & ACTOR_PART_FLAG_1000000)) {
            func_80266DAC(actor, 0);
        }
        if ((!decorChanged) && !(part->flags & ACTOR_PART_FLAG_1000000)) {
            func_80266EE8(actor, 0);
        }
        if (actor->flags & ACTOR_FLAG_4000000) {
            if (!(part->flags & ACTOR_PART_FLAG_20000000)) {
                if (actor->debuff == STATUS_FROZEN) {
                    if (!animChanged) {
                        part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_FROZEN);
                        animChanged = TRUE;
                    }
                } else if (actor->debuff != STATUS_SHRINK) {
                    if (actor->debuff == STATUS_POISON) {
                        if (!animChanged) {
                            part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_POISON);
                            animChanged = TRUE;
                        }
                    } else if (actor->debuff == STATUS_DIZZY) {
                        if (!animChanged) {
                            part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_DIZZY);
                            animChanged = TRUE;
                        }
                    } else if (actor->debuff == STATUS_FEAR) {
                        if (!animChanged) {
                            part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_FEAR);
                            animChanged = TRUE;
                        }
                    } else if (actor->debuff == STATUS_SLEEP) {
                        if (!animChanged) {
                            part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_SLEEP);
                            animChanged = TRUE;
                        }
                    } else if (actor->debuff == STATUS_PARALYZE) {
                        if (!animChanged) {
                            part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_PARALYZE);
                            animChanged = TRUE;
                        }
                    }
                }

                if (actor->staticStatus == STATUS_STATIC) {
                    if (!animChanged) {
                        part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_STATIC);
                        animChanged = TRUE;
                    }

                    do {} while (0); // required to match
                }
                if (!animChanged) {
                    part->currentAnimation = func_80265CE8(part->idleAnimations, 1);
                }

                if (isPartner) {
                    if (actor->koStatus == STATUS_DAZE) {
                        part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_DAZE);
                        animChanged = TRUE;
                    } else {
                        s32 temp = func_80265CE8(part->idleAnimations, STATUS_NORMAL);
                        do {
                            if (temp == func_80265CE8(part->idleAnimations, STATUS_DAZE)) {
                                part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_NORMAL);
                            }
                        } while (0); // required to match
                    }
                }
                if (actor->debuff == STATUS_STOP) {
                    part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_STOP);
                    create_status_debuff(actor->hudElementDataIndex, STATUS_STOP);
                } else if (!animChanged) {
                    s32 temp = func_80265CE8(part->idleAnimations, STATUS_NORMAL);
                    do {
                        if (temp == func_80265CE8(part->idleAnimations, STATUS_STOP)) {
                            part->currentAnimation = func_80265CE8(part->idleAnimations, STATUS_NORMAL);
                        }
                    } while (0); // required to match
                }
            }
        }

        if (!(gBattleStatus.flags1 & BS_FLAGS1_4) && (actor->flags & ACTOR_FLAG_8000000)) {
            do {
                if (actor->debuff == STATUS_POISON) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_POISON);
                } else if (actor->debuff == STATUS_DIZZY) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_DIZZY);
                } else if (actor->debuff == STATUS_SLEEP) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_SLEEP);
                } else if (actor->debuff == STATUS_PARALYZE) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_PARALYZE);
                } else if (actor->debuff == STATUS_SHRINK) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_SHRINK);
                } else if (actor->debuff == STATUS_FROZEN) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_FROZEN);
                }
            } while (0); // required to match

            if (actor->staticStatus == STATUS_STATIC) {
                create_status_static(actor->hudElementDataIndex, STATUS_STATIC);
            }
            if ((actor->transparentStatus == STATUS_TRANSPARENT) || (part->flags & ACTOR_PART_FLAG_100)) {
                create_status_transparent(actor->hudElementDataIndex, STATUS_TRANSPARENT);
            }
            if (actor->chillOutAmount != 0) {
                create_status_chill_out(actor->hudElementDataIndex);
            }
        } else {
            enable_status_debuff(actor->hudElementDataIndex);
            enable_status_2(actor->hudElementDataIndex);
            enable_status_transparent(actor->hudElementDataIndex);
            enable_status_chill_out(actor->hudElementDataIndex);
        }
        if (part->spriteInstanceID >= 0) {
            if (lastAnim != part->currentAnimation) {
                spr_update_sprite(part->spriteInstanceID, part->currentAnimation, part->animationRate);
                part->animNotifyValue = spr_get_notify_value(part->spriteInstanceID);
            }
        }
        if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
            guTranslateF(mtxPivotOn,
                -part->rotationPivotOffset.x * actor->scalingFactor,
                -part->rotationPivotOffset.y * actor->scalingFactor,
                -part->rotationPivotOffset.z * actor->scalingFactor);
            guTranslateF(mtxPivotOff,
                part->rotationPivotOffset.x * actor->scalingFactor,
                part->rotationPivotOffset.y * actor->scalingFactor,
                part->rotationPivotOffset.z * actor->scalingFactor);
        } else {
            guTranslateF(mtxPivotOn,
                -part->rotationPivotOffset.x * actor->scalingFactor,
                 part->rotationPivotOffset.y * actor->scalingFactor,
                -part->rotationPivotOffset.z * actor->scalingFactor);
            guTranslateF(mtxPivotOff,
                 part->rotationPivotOffset.x * actor->scalingFactor,
                -part->rotationPivotOffset.y * actor->scalingFactor,
                 part->rotationPivotOffset.z * actor->scalingFactor);
        }
        guTranslateF(mtxTranslate,
            partPosX + part->unkOffset[0],
            partPosY + part->unkOffset[1],
            partPosZ);
        guRotateF(mtxRotX, part->rotation.x, 1.0f, 0.0f, 0.0f);
        guRotateF(mtxRotY, part->rotation.y, 0.0f, 1.0f, 0.0f);
        guRotateF(mtxRotZ, part->rotation.z, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxRotY, mtxRotX, mtxTemp);
        guMtxCatF(mtxTemp, mtxRotZ, mtxRotation);
        guScaleF(mtxScale, part->scale.x, part->scale.y * part->verticalStretch, part->scale.z);
        guMtxCatF(mtxScale, mtxPivotOn, mtxTransform);
        guMtxCatF(mtxTransform, mtxRotation, mtxTemp);
        guMtxCatF(mtxTemp, mtxPivotOff, mtxTransform);

        if (!(part->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
            guMtxCatF(mtxTransform, mtxActor, mtxTemp);
        } else {
            guMtxCatF(mtxTransform, mtxPartScale, mtxTemp);
        }
        guMtxCatF(mtxTemp, mtxTranslate, mtxTransform);

        part->currentPos.x = partPosX + part->unkOffset[0];
        part->currentPos.y = partPosY + part->unkOffset[1];
        part->currentPos.z = partPosZ;

        if (part->spriteInstanceID >= 0) {
            if (!isPartner) {
                func_8025C840(1, part, partYaw, 0);
                func_8025CCC8(1, part, partYaw, 0);
                func_802591EC(1, part, partYaw, mtxTransform, 0);
            } else {
                func_8025C840(1, part, clamp_angle(180.0f - partYaw), 0);
                func_8025CCC8(1, part, clamp_angle(180.0f - partYaw), 0);
                func_802591EC(1, part, clamp_angle(180.0f - partYaw), mtxTransform, 0);
            }

            _add_part_decoration(part);
        }

        part = part->nextPart;
    }
}

void func_802571F0(s32 flipYaw, Actor* actor) {
    Matrix4f mtxRotX, mtxRotY, mtxRotZ, mtxRotation, mtxScale;
    Matrix4f mtxPivotOn, mtxPivotOff, mtxTranslate;
    Matrix4f mtxTemp, mtxTransform, mtxMirror;
    Matrix4f mtxActor, mtxPartScale;
    ActorPart* part;
    f32 actorPosX, actorPosY, actorPosZ;
    f32 partPosX, partPosY, partPosZ;
    f32 partYaw;
    s32 numParts;
    s32 i;

    actorPosX = actor->currentPos.x + actor->headOffset.x;
    if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        actorPosY = actor->currentPos.y + actor->headOffset.y;
    } else {
        actorPosY = actor->currentPos.y - actor->headOffset.y;
    }
    actorPosZ = actor->currentPos.z + actor->headOffset.z - 5.0f;

    if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        guTranslateF(mtxPivotOn,
            -actor->rotationPivotOffset.x * actor->scalingFactor,
            -actor->rotationPivotOffset.y * actor->scalingFactor,
            -actor->rotationPivotOffset.z * actor->scalingFactor);
         guTranslateF(mtxPivotOff,
             actor->rotationPivotOffset.x * actor->scalingFactor,
             actor->rotationPivotOffset.y * actor->scalingFactor,
             actor->rotationPivotOffset.z * actor->scalingFactor);
    } else {
        guTranslateF(mtxPivotOn,
            -actor->rotationPivotOffset.x * actor->scalingFactor,
             actor->rotationPivotOffset.y * actor->scalingFactor,
            -actor->rotationPivotOffset.z * actor->scalingFactor);
         guTranslateF(mtxPivotOff,
             actor->rotationPivotOffset.x * actor->scalingFactor,
             -actor->rotationPivotOffset.y * actor->scalingFactor,
             actor->rotationPivotOffset.z * actor->scalingFactor);
    }

    guRotateF(mtxRotX, actor->rotation.x, 1.0f, 0.0f, 0.0f);
    guRotateF(mtxRotY, actor->rotation.y, 0.0f, 1.0f, 0.0f);
    guRotateF(mtxRotZ, actor->rotation.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(mtxRotY, mtxRotX, mtxTemp);
    guMtxCatF(mtxTemp, mtxRotZ, mtxRotation);

    guScaleF(mtxScale,
        actor->scale.x * SPRITE_WORLD_SCALE_D * actor->scalingFactor,
        actor->scale.y * SPRITE_WORLD_SCALE_D * actor->scalingFactor,
        actor->scale.z * SPRITE_WORLD_SCALE_D);

    guMtxCatF(mtxPivotOn, mtxScale, mtxTemp);
    guMtxCatF(mtxTemp, mtxRotation, mtxTransform);
    guMtxCatF(mtxTransform, mtxPivotOff, mtxActor);

    part = actor->partsTable;
    numParts = actor->numParts;
    for (i = 0; i < numParts; i++) {
        // determine part position
        if (!(part->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
            partPosX = actorPosX + part->partOffset.x + part->visualOffset.x;
            if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                partPosY = actorPosY + part->partOffset.y + part->visualOffset.y;
            } else {
                partPosY = actorPosY - part->partOffset.y - part->visualOffset.y;
            }
            partPosZ = actorPosZ + part->partOffset.z + part->visualOffset.z;
            partYaw = part->yaw = actor->yaw;
        } else {
            partPosX = part->absolutePosition.x + part->visualOffset.x;
            partPosY = part->absolutePosition.y + part->visualOffset.y;
            partPosZ = part->absolutePosition.z + part->visualOffset.z;
            guScaleF(mtxPartScale,
                actor->scale.x * SPRITE_WORLD_SCALE_D,
                actor->scale.y * SPRITE_WORLD_SCALE_D,
                actor->scale.z * SPRITE_WORLD_SCALE_D);
            partYaw = part->yaw;
        }

        if (part->flags & ACTOR_PART_FLAG_INVISIBLE) {
            part = part->nextPart;
            continue;
        }
        if (part->idleAnimations == NULL) {
            part = part->nextPart;
            continue;
        }

        if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
            guTranslateF(mtxPivotOn,
                -part->rotationPivotOffset.x * actor->scalingFactor,
                -part->rotationPivotOffset.y * actor->scalingFactor,
                -part->rotationPivotOffset.z * actor->scalingFactor);
            guTranslateF(mtxPivotOff,
                 part->rotationPivotOffset.x * actor->scalingFactor,
                 part->rotationPivotOffset.y * actor->scalingFactor,
                 part->rotationPivotOffset.z * actor->scalingFactor);
        } else {
            guTranslateF(mtxPivotOn,
                -part->rotationPivotOffset.x * actor->scalingFactor,
                 part->rotationPivotOffset.y * actor->scalingFactor,
                -part->rotationPivotOffset.z * actor->scalingFactor);
            guTranslateF(mtxPivotOff,
                 part->rotationPivotOffset.x * actor->scalingFactor,
                -part->rotationPivotOffset.y * actor->scalingFactor,
                 part->rotationPivotOffset.z * actor->scalingFactor);
        }
        guTranslateF(mtxTranslate,
            partPosX + part->unkOffset[0],
            partPosY + part->unkOffset[1],
            partPosZ - 1.0f);

        guRotateF(mtxRotX, part->rotation.x, 1.0f, 0.0f, 0.0f);
        guRotateF(mtxRotY, part->rotation.y, 0.0f, 1.0f, 0.0f);
        guRotateF(mtxRotZ, part->rotation.z, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxRotY, mtxRotX, mtxTemp);
        guMtxCatF(mtxTemp, mtxRotZ, mtxRotation);

        guScaleF(mtxScale, part->scale.x, part->scale.y * part->verticalStretch, part->scale.z);
        mtx_mirror_y(mtxMirror);
        guMtxCatF(mtxScale, mtxPivotOn, mtxTemp);
        guMtxCatF(mtxTemp, mtxRotation, mtxTransform);
        guMtxCatF(mtxTransform, mtxPivotOff, mtxTemp);
        if (!(part->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
            guMtxCatF(mtxTemp, mtxActor, mtxTransform);
        } else {
            guMtxCatF(mtxTemp, mtxPartScale, mtxTransform);
        }
        guMtxCatF(mtxTransform, mtxTranslate, mtxTemp);
        guMtxCatF(mtxTemp, mtxMirror, mtxTransform);

        if (flipYaw == 0) {
            func_8025C840(1, part, partYaw, 1);
            func_8025CCC8(1, part, partYaw, 1);
            func_802591EC(1, part, partYaw, mtxTransform, 1);
        } else {
            func_8025C840(1, part, clamp_angle(partYaw + 180.0f), 1);
            func_8025CCC8(1, part, clamp_angle(partYaw + 180.0f), 1);
            func_802591EC(1, part, clamp_angle(partYaw + 180.0f), mtxTransform, 1);
        }

        part = part->nextPart;
    }
}

void appendGfx_enemy_actor(void* data) {
    appendGfx_npc_actor(FALSE, (s32) data);
}

void appendGfx_partner_actor(void* data) {
    appendGfx_npc_actor(TRUE, (s32) data);
}

void appendGfx_enemy_actor_reflection(void* data) {
    Actor* actor = data;

    func_802571F0(0, actor);
}

void appendGfx_partner_actor_reflection(void* data) {
    func_802571F0(1, gBattleStatus.partnerActor);
}

void update_player_actor_shadow(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Camera* camera = &gCameras[CAM_BATTLE];
    Actor* player = battleStatus->playerActor;
    ActorPart* parts = player->partsTable;
    Shadow* shadow;
    f32 x, y, z, distance;

    parts->animNotifyValue = spr_update_player_sprite(PLAYER_SPRITE_MAIN, parts->currentAnimation, parts->animationRate);

    if (player->flags & ACTOR_FLAG_BLUR_ENABLED) {
        func_802549F4(player);
    }

    shadow = get_shadow_by_index(player->shadow.id);
    shadow->flags &= ~ENTITY_FLAG_HIDDEN;

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
        shadow->flags |= ENTITY_FLAG_HIDDEN;
    }
    shadow->position.x = x;
    shadow->position.y = y;
    shadow->position.z = z;
    shadow->rotation.y = clamp_angle(player->yaw - camera->currentYaw);
    set_standard_shadow_scale(shadow, distance);
    shadow->scale.x *= player->shadowScale * player->scalingFactor;

    if (parts->opacity >= 255 && !(parts->flags & ACTOR_PART_FLAG_100)) {
        player->renderMode = RENDER_MODE_ALPHATEST;
    } else {
        player->renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;
    }
}

void appendGfx_player_actor(void* arg0) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Matrix4f mtxRotX, mtxRotY, mtxRotZ, mtxRotation;
    Matrix4f mtxScale;
    Matrix4f mtxPivotOn, mtxPivotOff, mtxTranslate;
    Matrix4f mtxTemp, mtxTransform;

    Actor* partner;
    Actor* player;
    ActorPart* playerParts;
    EffectInstance* effect;
    f32 playerPosX, playerPosY, playerPosZ, playerYaw;
    s32 cond1, cond2, cond3, cond4;
    u32 lastAnim;

    player = battleStatus->playerActor;
    partner = battleStatus->partnerActor;
    playerParts = player->partsTable;

    playerPosX = player->currentPos.x + player->headOffset.x;
    playerPosY = player->currentPos.y + player->headOffset.y + player->verticalRenderOffset;
    playerPosZ = player->currentPos.z + player->headOffset.z;

    playerYaw = playerParts->yaw = player->yaw;

    player->disableEffect->data.disableX->pos.x = playerPosX +
        ((player->actorBlueprint->statusIconOffset.x + player->unk_194) * player->scalingFactor);
    player->disableEffect->data.disableX->pos.y = playerPosY +
        ((player->actorBlueprint->statusIconOffset.y + player->unk_195) * player->scalingFactor);
    player->disableEffect->data.disableX->pos.z = playerPosZ;

    if (!(gBattleStatus.flags1 & BS_FLAGS1_4) && (player->flags & ACTOR_FLAG_8000000)) {
        if (player->disableDismissTimer != 0) {
            player->disableDismissTimer--;
            player->disableEffect->data.disableX->pos.y = NPC_DISPOSE_POS_Y;
        } else {
            player->disableEffect->data.disableX->scale = player->scalingFactor * 0.75;
        }
    } else {
        player->disableEffect->data.disableX->pos.y = NPC_DISPOSE_POS_Y;
        player->disableDismissTimer = 10;
    }

    if (battleStatus->waterBlockTurnsLeft != 0) {
        if ((gBattleStatus.flags1 & BS_FLAGS1_8) ||
            (!(gBattleStatus.flags1 & BS_FLAGS1_4) && (player->flags & ACTOR_FLAG_8000000)))
        {
            effect = battleStatus->waterBlockEffect;
            effect->data.waterBlock->pos.x = playerPosX;
            effect->data.waterBlock->pos.y = playerPosY;
            effect->data.waterBlock->pos.z = playerPosZ;
        } else {
            effect = battleStatus->waterBlockEffect;
            effect->data.waterBlock->pos.x = playerPosX;
            effect->data.waterBlock->pos.y = NPC_DISPOSE_POS_Y;
            effect->data.waterBlock->pos.z = playerPosZ;
        }
    }
    if (battleStatus->cloudNineTurnsLeft != 0) {
        if ((gBattleStatus.flags1 & BS_FLAGS1_8) ||
            (!(gBattleStatus.flags1 & BS_FLAGS1_4) && (player->flags & ACTOR_FLAG_8000000)))
        {
            effect = battleStatus->cloudNineEffect;
            effect->data.endingDecals->pos.x = playerPosX;
            effect->data.endingDecals->pos.y = playerPosY;
            effect->data.endingDecals->pos.z = playerPosZ;
            effect->data.endingDecals->scale = player->scalingFactor;
        } else {
            effect = battleStatus->cloudNineEffect;
            effect->data.endingDecals->pos.x = playerPosX;
            effect->data.endingDecals->pos.y = NPC_DISPOSE_POS_Y;
            effect->data.endingDecals->pos.z = playerPosZ;
        }
    }
    if (player->debuff == STATUS_FROZEN) {
        effect = player->icePillarEffect;
        if (player->icePillarEffect != NULL) {
            if ((gBattleStatus.flags1 & BS_FLAGS1_8) ||
                (!(gBattleStatus.flags1 & BS_FLAGS1_4) && (player->flags & ACTOR_FLAG_8000000)))
            {
                effect->data.icePillar->pos.x = playerPosX - 8.0f;
                effect->data.icePillar->pos.y = playerPosY;
                effect->data.icePillar->pos.z = playerPosZ;
                effect->data.icePillar->scale = player->size.y / 24.0;
            } else {
                effect->data.icePillar->pos.x = NPC_DISPOSE_POS_X;
                effect->data.icePillar->pos.y = NPC_DISPOSE_POS_Y;
                effect->data.icePillar->pos.z = NPC_DISPOSE_POS_Z;
            }
        } else {
            effect->data.icePillar->pos.x = NPC_DISPOSE_POS_X;
            effect->data.icePillar->pos.y = NPC_DISPOSE_POS_Y;
            effect->data.icePillar->pos.z = NPC_DISPOSE_POS_Z;
        }
    } else {
        effect = player->icePillarEffect;
        if (effect != NULL) {
            effect->flags |= 0x10;
            player->icePillarEffect = NULL;
        }
    }

    if (!(gBattleStatus.flags2 & BS_FLAGS2_10000) && !(gBattleStatus.flags1 & BS_FLAGS1_4) && (player->flags & ACTOR_FLAG_8000000)) {
        battleStatus->buffEffect->data.partnerBuff->unk_02 = 1;
    } else {
        battleStatus->buffEffect->data.partnerBuff->unk_02 = 0;
    }

    do {
        if (player->debuff == STATUS_SHRINK) {
            player->scalingFactor += (0.4 - player->scalingFactor) / 6.0;
        } else {
            player->scalingFactor += (1.0 - player->scalingFactor) / 6.0;
        }
    } while (0); // required to match

    if (player->flags & ACTOR_FLAG_8000000) {
        if (battleStatus->hammerCharge > 0) {
            create_status_icon_boost_hammer(player->hudElementDataIndex);
            remove_status_icon_boost_jump(player->hudElementDataIndex);
        } else {
            remove_status_icon_boost_hammer(player->hudElementDataIndex);
        }
        if (battleStatus->jumpCharge > 0) {
            create_status_icon_boost_jump(player->hudElementDataIndex);
            remove_status_icon_boost_hammer(player->hudElementDataIndex);
        } else {
            remove_status_icon_boost_jump(player->hudElementDataIndex);
        }
    } else {
        enable_status_icon_boost_jump(player->hudElementDataIndex);
        enable_status_icon_boost_hammer(player->hudElementDataIndex);
    }

    if ((player->flags & ACTOR_FLAG_8000000) && !(gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE)) {
        if (playerData->curHP > 1) {
            remove_status_icon_peril(player->hudElementDataIndex);
            do {
                if (playerData->curHP <= 5) {
                    create_status_icon_danger(player->hudElementDataIndex);
                    remove_status_icon_peril(player->hudElementDataIndex);
                } else {
                    remove_status_icon_danger(player->hudElementDataIndex);
                }
            } while (0); // required to match
        } else {
            create_status_icon_peril(player->hudElementDataIndex);
            remove_status_icon_danger(player->hudElementDataIndex);
        }
    } else {
        remove_status_icon_peril(player->hudElementDataIndex);
        remove_status_icon_danger(player->hudElementDataIndex);
    }

    if (player->transparentStatus == 0xE) {
        playerParts->flags |= ACTOR_PART_FLAG_100;

        if (FALSE) { // TODO required to match - also whyyyyyy compiler, whyyyyy
    back:
            playerParts->currentAnimation = func_80265D44(8);
            create_status_debuff(player->hudElementDataIndex, 8);
            goto end;
        }
    } else {
        playerParts->flags &= ~ACTOR_PART_FLAG_100;
    }

    do {
        cond1 = FALSE;
        cond2 = FALSE;
        cond3 = FALSE;
        cond4 = FALSE;
        lastAnim = playerParts->currentAnimation;
    } while (0); // required to match

    if (((((gBattleStatus.flags2 & (BS_FLAGS2_8 | BS_FLAGS2_2)) == BS_FLAGS2_2) && (partner != NULL)) || (battleStatus->outtaSightActive > 0))
        && !(player->flags & ACTOR_FLAG_20000000)
        && ((partner == NULL) || !(partner->flags & ACTOR_FLAG_NO_ATTACK)))
    {
        if (!(gBattleStatus.flags2 & BS_FLAGS2_100000)) {
            if ((player->debuff != STATUS_FEAR)
                && (player->debuff != STATUS_PARALYZE)
                && (player->debuff != STATUS_FROZEN)
                && (player->debuff != STATUS_STOP)
            ) {
                if ((player->transparentStatus != STATUS_TRANSPARENT) &&
                    (player->stoneStatus != STATUS_STONE) &&
                    ((battleStatus->outtaSightActive > 0) || (gBattleStatus.flags2 & BS_FLAGS2_2)))
                {
                    if (is_ability_active(ABILITY_BERSERKER)) {
                        playerParts->currentAnimation = func_80265D44(0x13);
                    } else  if (player->debuff == STATUS_SLEEP) {
                        playerParts->currentAnimation = func_80265D44(0x15);
                    } else if (player->debuff == STATUS_DIZZY) {
                        playerParts->currentAnimation = func_80265D44(0x18);
                    } else {
                        playerParts->currentAnimation = func_80265D44(0x12);
                    }
                    spr_update_player_sprite(PLAYER_SPRITE_MAIN, playerParts->currentAnimation, playerParts->animationRate);
                    cond1 = TRUE;
                }
            }

            if (player->debuff != STATUS_POISON) {
                func_80266DAC(player, 0xC);
            } else {
                func_80266DAC(player, 0xD);
            }
            cond2 = TRUE;

            func_80266EE8(player, 0);
            cond3 = TRUE;
        }
    }

    if (player->stoneStatus == STATUS_STONE) {
        playerParts->currentAnimation = func_80265D44(0xC);
        spr_update_player_sprite(PLAYER_SPRITE_MAIN, playerParts->currentAnimation, playerParts->animationRate);
        cond1 = TRUE;

        if (!cond2) {
            func_80266DAC(player, 0);
        }
        func_80266EE8(player, 0);
        cond2 = TRUE;
        enable_status_debuff(player->hudElementDataIndex);
        cond3 = TRUE;
        enable_status_2(player->hudElementDataIndex);
        cond4 = TRUE;

        enable_status_transparent(player->hudElementDataIndex);
        enable_status_chill_out(player->hudElementDataIndex);
    }

    if ((player->flags & ACTOR_FLAG_4000000) && !cond1) {
        s32 temp = playerParts->currentAnimation;
        if (temp == func_80265D44(0xC)) {
            playerParts->currentAnimation = func_80265D44(1);
        }
    }

    if (is_ability_active(ABILITY_BERSERKER)) {
        if (!cond2) {
            func_80266DAC(player, 8);
        }
        cond2 = TRUE;
    }
    if (player->debuff == STATUS_POISON) {
        if (!cond2) {
            func_80266DAC(player, 6);
        }
        cond2 = TRUE;
    }
    if (player->debuff == STATUS_PARALYZE) {
        if (!cond2) {
            func_80266DAC(player, 7);
        }
        cond2 = TRUE;
    }
    if (player->staticStatus == STATUS_STATIC) {
        if (!cond2) {
            func_80266DAC(player, 4);
        }
        cond2 = TRUE;
    }
    if (battleStatus->turboChargeTurnsLeft != 0) {
        if (!cond3) {
            func_80266EE8(player, 0xB);
        }
        cond3 = TRUE;
    }
    if (is_ability_active(ABILITY_ZAP_TAP)) {
        if (!cond2) {
            func_80266DAC(player, 4);
        }
        cond2 = TRUE;
    }
    if (!cond2) {
        func_80266DAC(player, 0);
    }
    if (!cond3) {
        func_80266EE8(player, 0);
    }
    if (player->flags & ACTOR_FLAG_4000000) {
        if (battleStatus->hustleTurns != 0) {
            playerParts->currentAnimation = func_80265D44(0x19);
            cond1 = TRUE;
        } else if (!cond1) {
            s32 temp = func_80265D44(1);
            do {
                if (temp == func_80265D44(0x19)) {
                    playerParts->currentAnimation = func_80265D44(1);
                }
            } while (0); // required to match
        }

        do {
            if (player->debuff == STATUS_FROZEN) {
                if (!cond1) {
                    playerParts->currentAnimation = func_80265D44(7);
                    cond1 = TRUE;
                }
            } else if (player->debuff != STATUS_SHRINK) {
                if (player->debuff == STATUS_POISON) {
                    if (!cond1) {
                        playerParts->currentAnimation = func_80265D44(9);
                        cond1 = TRUE;
                    }
                } else if (player->debuff == STATUS_DIZZY) {
                    if (!cond1) {
                        playerParts->currentAnimation = func_80265D44(4);
                        cond1 = TRUE;
                    }
                } else if (player->debuff == STATUS_SLEEP) {
                    if (!cond1) {
                        playerParts->currentAnimation = func_80265D44(6);
                        cond1 = TRUE;
                    }
                } else if (player->debuff == STATUS_PARALYZE) {
                    if (!cond1) {
                        playerParts->currentAnimation = func_80265D44(5);
                        cond1 = TRUE;
                    }
                 } else {
                    if (player_team_is_ability_active(player, ABILITY_BERSERKER)) {
                        if (!cond1) {
                            playerParts->currentAnimation = func_80265D44(0x10);
                            cond1 = TRUE;
                        }
                    }
                }
            }
            if (is_ability_active(ABILITY_ZAP_TAP)) {
                if (!cond1) {
                    playerParts->currentAnimation = func_80265D44(0xB);
                    cond1 = TRUE;
                }
                player->staticStatus = STATUS_STATIC;
                player->staticDuration = 127;
            } else if ((player->staticStatus == STATUS_STATIC) && !cond1) {
                playerParts->currentAnimation = func_80265D44(0xB);
                cond1 = TRUE;
            }
            if ((player->transparentStatus == STATUS_TRANSPARENT) || (playerParts->flags & ACTOR_PART_FLAG_100)) {
                if (!cond1) {
                    playerParts->currentAnimation = func_80265D44(0xE);
                    cond1 = TRUE;
                }
                create_status_transparent(player->hudElementDataIndex, 0xE);
            }
            if (!cond1) {
                playerParts->currentAnimation = func_80265D44(1);
            }
        } while (0); // needed to match
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_4) && (player->flags & ACTOR_FLAG_8000000)) {
        if (!cond4) {
            do {
                if (player->debuff == STATUS_POISON) {
                    create_status_debuff(player->hudElementDataIndex, player->debuff);
                } else if (player->debuff == STATUS_SLEEP) {
                    create_status_debuff(player->hudElementDataIndex, player->debuff);
                } else if (player->debuff == STATUS_PARALYZE) {
                    create_status_debuff(player->hudElementDataIndex, player->debuff);
                } else if (player->debuff == STATUS_DIZZY) {
                    create_status_debuff(player->hudElementDataIndex, player->debuff);
                } else if (player->debuff == STATUS_SHRINK) {
                    create_status_debuff(player->hudElementDataIndex, player->debuff);
                } else if (player->debuff == STATUS_FROZEN) {
                    create_status_debuff(player->hudElementDataIndex, player->debuff);
                }
            } while (0); // required to match
            if (!cond4 && (is_ability_active(ABILITY_ZAP_TAP) || (player->staticStatus == STATUS_STATIC))) {
                create_status_static(player->hudElementDataIndex, 0xB);
            }
        }
        if ((player->transparentStatus == STATUS_TRANSPARENT) || (playerParts->flags & ACTOR_PART_FLAG_100)) {
            create_status_transparent(player->hudElementDataIndex, 0xE);
        }
    } else {
        enable_status_debuff(player->hudElementDataIndex);
        enable_status_2(player->hudElementDataIndex);
        enable_status_transparent(player->hudElementDataIndex);
        enable_status_chill_out(player->hudElementDataIndex);
    }

    if (player->debuff != STATUS_STOP) {
        if (!cond1) {
            s32 temp = playerParts->currentAnimation;
            if (temp == func_80265D44(8)) {
                playerParts->currentAnimation = func_80265D44(1);
            }
        }
    } else {
        goto back;
    }

end:
    set_status_icons_properties(player->hudElementDataIndex,
        playerPosX, playerPosY, playerPosZ,
        player->actorBlueprint->statusIconOffset.x * player->scalingFactor,
        player->actorBlueprint->statusIconOffset.y * player->scalingFactor,
        player->actorBlueprint->statusMessageOffset.x * player->scalingFactor,
        player->actorBlueprint->statusMessageOffset.y * player->scalingFactor);
    set_status_icons_offset(player->hudElementDataIndex,
        player->size.y * player->scalingFactor,
        player->size.x * player->scalingFactor);

    playerPosX += playerParts->unkOffset[0];
    playerPosY += playerParts->unkOffset[1];

    playerParts->currentPos.x = playerPosX;
    playerParts->currentPos.y = playerPosY;
    playerParts->currentPos.z = playerPosZ;
    guTranslateF(mtxTranslate, playerPosX, playerPosY, playerPosZ);

    guTranslateF(mtxPivotOn,
        -player->rotationPivotOffset.x * player->scalingFactor,
        -player->rotationPivotOffset.y * player->scalingFactor,
        -player->rotationPivotOffset.z * player->scalingFactor);
    guTranslateF(mtxPivotOff,
        player->rotationPivotOffset.x * player->scalingFactor,
        player->rotationPivotOffset.y * player->scalingFactor,
        player->rotationPivotOffset.z * player->scalingFactor);

    guRotateF(mtxRotX, player->rotation.x, 1.0f, 0.0f, 0.0f);
    guRotateF(mtxRotY, player->rotation.y, 0.0f, 1.0f, 0.0f);
    guRotateF(mtxRotZ, player->rotation.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(mtxRotY, mtxRotX, mtxTemp);
    guMtxCatF(mtxTemp, mtxRotZ, mtxRotation);

    guScaleF(mtxScale,
        player->scale.x * SPRITE_WORLD_SCALE_D * player->scalingFactor,
        player->scale.y * SPRITE_WORLD_SCALE_D * player->scalingFactor * playerParts->verticalStretch,
        player->scale.z * SPRITE_WORLD_SCALE_D);

    guMtxCatF(mtxScale, mtxPivotOn, mtxTemp);
    guMtxCatF(mtxTemp, mtxRotation, mtxTransform);
    guMtxCatF(mtxTransform, mtxPivotOff, mtxTemp);
    guMtxCatF(mtxTemp, mtxTranslate, mtxTransform);

    if (lastAnim != playerParts->currentAnimation) {
        spr_update_player_sprite(PLAYER_SPRITE_MAIN, playerParts->currentAnimation, playerParts->animationRate);
    }
    func_8025C840(0, playerParts, clamp_angle(playerYaw + 180.0f), 0);
    func_8025CCC8(0, playerParts, clamp_angle(playerYaw + 180.0f), 0);
    func_802591EC(0, playerParts, clamp_angle(playerYaw + 180.0f), mtxTransform, 0);
    _add_part_decoration(playerParts);
}

void appendGfx_player_actor_reflection(void* arg0) {
    Matrix4f mtxRotX, mtxRotY, mtxRotZ, mtxRotation, mtxScale;
    Matrix4f mtxPivotOn, mtxPivotOff, mtxTranslate;
    Matrix4f mtxTemp, mtxTransform, mtxMirror;
    Actor* player = gBattleStatus.playerActor;
    ActorPart* part = &player->partsTable[0];
    f32 playerYaw = player->yaw;
    f32 dx, dy, dz;

    dx = player->currentPos.x + player->headOffset.x;
    dx += part->unkOffset[0];
    dy = player->currentPos.y + player->headOffset.y;
    dy += part->unkOffset[1];
    dz = player->currentPos.z + player->headOffset.z - 5.0f;
    part->yaw = playerYaw;

    guTranslateF(mtxTranslate, dx, dy, dz - 1.0f);

    guTranslateF(mtxPivotOn,
        -player->rotationPivotOffset.x * player->scalingFactor,
        -player->rotationPivotOffset.y * player->scalingFactor,
        -player->rotationPivotOffset.z * player->scalingFactor);
    guTranslateF(mtxPivotOff,
        player->rotationPivotOffset.x * player->scalingFactor,
        player->rotationPivotOffset.y * player->scalingFactor,
        player->rotationPivotOffset.z * player->scalingFactor);

    guRotateF(mtxRotX, player->rotation.x, 1.0f, 0.0f, 0.0f);
    guRotateF(mtxRotY, player->rotation.y, 0.0f, 1.0f, 0.0f);
    guRotateF(mtxRotZ, player->rotation.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(mtxRotY, mtxRotX, mtxTemp);
    guMtxCatF(mtxTemp, mtxRotZ, mtxRotation);
    guScaleF(mtxScale,
        player->scale.x * SPRITE_WORLD_SCALE_D * player->scalingFactor,
        player->scale.y * SPRITE_WORLD_SCALE_D * player->scalingFactor * part->verticalStretch,
        player->scale.z * SPRITE_WORLD_SCALE_D);
    mtx_mirror_y(mtxMirror);

    guMtxCatF(mtxScale, mtxPivotOn, mtxTemp);
    guMtxCatF(mtxTemp, mtxRotation, mtxTemp);
    guMtxCatF(mtxTemp, mtxPivotOff, mtxTemp);
    guMtxCatF(mtxTemp, mtxTranslate, mtxTransform);
    guMtxCatF(mtxTransform, mtxMirror, mtxTransform);

    func_8025C840(0, part, clamp_angle(playerYaw + 180.0f), 1);
    func_8025CCC8(0, part, clamp_angle(playerYaw + 180.0f), 1);
    func_802591EC(0, part, clamp_angle(playerYaw + 180.0f), mtxTransform, 1);
}

s32 func_802591EC(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    s32 opacity;
    s32 sprDrawOpts;

    if (part->flags & ACTOR_PART_FLAG_2) {
        opacity = 255;
        sprDrawOpts = 0;
        if (part->opacity < 255) {
            sprDrawOpts = DRAW_SPRITE_OVERRIDE_ALPHA;
            opacity = part->opacity;
        }
        if (part->flags & ACTOR_PART_FLAG_100) {
            opacity = opacity * 120 / 255;
            sprDrawOpts = DRAW_SPRITE_OVERRIDE_ALPHA;
        }
        if (arg0 == 0) {
            if (opacity == 255) {
                spr_draw_player_sprite(PLAYER_SPRITE_MAIN, yaw, 0, NULL, mtx);
            } else {
                spr_draw_player_sprite(PLAYER_SPRITE_MAIN | sprDrawOpts, yaw, opacity, NULL, mtx);
            }
        } else {
            if (opacity == 255) {
                spr_draw_npc_sprite(part->spriteInstanceID, yaw, 0, NULL, mtx);
            } else {
                spr_draw_npc_sprite(part->spriteInstanceID | sprDrawOpts, yaw, opacity, NULL, mtx);
            }
        }
        return 0;
    }

    switch (part->decorationTable->unk_6C0) {
        case 0:
            func_80259A48(arg0, part, yaw, mtx, arg4);
            break;
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
    return 0;
}

void func_80259494(ActorPart* part) {
    DecorationTable* decor = part->decorationTable;
    PAL_PTR src;
    PAL_PTR dest;
    s32 i, j;

    for (i = 0; i < decor->numSpritePalettes; i++) {
        if (decor->unk_6D4[i] != NULL) {
            src = decor->unk_6D4[i];
            dest = decor->copiedPalettes[1][i];

            for (j = 0; j < ARRAY_COUNT(decor->copiedPalettes[1][i]); j++) {
                *dest = *src | 0xFFFE;
                src++;
                dest++;

            }
            decor->unk_76C[i] = decor->copiedPalettes[1][i];
        }
    }
}

void func_8025950C(ActorPart* part, s32 yaw, Matrix4f mtx) {
    DecorationTable* decor = part->decorationTable;
    s32 opacity = 255;
    s32 idMask = 0;
    PAL_PTR dest;
    PAL_PTR src;
    s32 i, j;

    if (part->opacity < 255) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = part->opacity;
    }
    if (part->flags & ACTOR_PART_FLAG_100) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = (opacity * 120) / 255;
    }

    if (decor->unk_768 != 0) {
        decor->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 0x10);
        decor->numSpritePalettes = 0;
        while (decor->spritePalettes[decor->numSpritePalettes] != (PAL_PTR) -1) {
            decor->numSpritePalettes++;
        }

        for (i = 0; i < decor->numSpritePalettes; i++) {
            src = decor->spritePalettes[i];
            dest = decor->copiedPalettes[0][i];
            if (src != NULL) {
                for (j = 0; j < ARRAY_COUNT(decor->copiedPalettes[0][i]); j++) {
                    *dest = *src;
                    src++;
                    dest++;
                }
            }
        }

        for (i = 0; i < decor->numSpritePalettes; i++) {
            decor->unk_6D4[i] = decor->copiedPalettes[0][i];
        }

        func_802596C0(part, yaw, mtx);
    } else {
        spr_draw_npc_sprite(part->spriteInstanceID | idMask, yaw, opacity, NULL, mtx);
    }
}

void func_802596C0(ActorPart* part, s32 yaw, Matrix4f mtx) {
    DecorationTable* decorationTable = part->decorationTable;
    s32 opacity = 255;
    s32 idMask = 0;

    if (part->opacity < 255) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = part->opacity;
    }

    if (part->flags & ACTOR_PART_FLAG_100) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = (opacity * 120) / 255;
    }

    if (decorationTable->unk_768 != 0) {
        func_80259494(part);
        spr_draw_npc_sprite(part->spriteInstanceID | DRAW_SPRITE_OVERRIDE_PALETTES | idMask, yaw, opacity, decorationTable->unk_76C, mtx);
    } else {
        spr_draw_npc_sprite(part->spriteInstanceID | DRAW_SPRITE_OVERRIDE_PALETTES | idMask, yaw, opacity, decorationTable->unk_6D4, mtx);
    }
}

void func_802597B0(ActorPart* part, s32 yaw, Matrix4f mtx) {
    DecorationTable* decor = part->decorationTable;
    s32 opacity = 255;
    s32 idMask = 0;
    PAL_PTR src;
    PAL_PTR dest;
    s32 i, j;

    if (part->opacity < 255) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = part->opacity;
    }
    if (part->flags & ACTOR_PART_FLAG_100) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = (opacity * 120) / 255;
    }

    if (decor->unk_768 != 0) {
        decor->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
        decor->numSpritePalettes = 0;

        while (decor->spritePalettes[decor->numSpritePalettes] != (PAL_PTR) -1) {
            decor->numSpritePalettes++;
        }

        for (i = 0; i < decor->numSpritePalettes; i++) {
            src = decor->spritePalettes[i];
            dest = decor->copiedPalettes[0][i];
            if (decor->spritePalettes[i] != NULL) {
                for (j = 0; j < ARRAY_COUNT(decor->copiedPalettes[0][i]); j++) {
                    *dest = *src;
                    dest++;
                    src++;
                }
            }
        }
        for (i = 0; i < decor->numSpritePalettes; i++) {
            decor->unk_6D4[i] = decor->copiedPalettes[0][i];
        }
        func_8025995C(part, yaw, mtx);
    } else {
        spr_draw_player_sprite(PLAYER_SPRITE_MAIN | idMask, yaw, opacity, NULL, mtx);
    }
}

void func_8025995C(ActorPart* part, s32 yaw, Matrix4f mtx) {
    DecorationTable* decorationTable = part->decorationTable;
    s32 opacity = 255;
    s32 idMask = 0;

    if (part->opacity < 255) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = part->opacity;
    }
    if (part->flags & ACTOR_PART_FLAG_100) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = (opacity * 120) / 255;
    }

    if (decorationTable->unk_768 != 0) {
        func_80259494(part);
        idMask |= DRAW_SPRITE_OVERRIDE_PALETTES;
        spr_draw_player_sprite(PLAYER_SPRITE_MAIN | idMask, yaw, opacity, decorationTable->unk_76C, mtx);
    } else {
        idMask |= DRAW_SPRITE_OVERRIDE_PALETTES;
        spr_draw_player_sprite(PLAYER_SPRITE_MAIN | idMask, yaw, opacity, decorationTable->unk_6D4, mtx);
    }
}

void func_80259A48(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;

    if (decorationTable->unk_6C1 != 0) {
        part->verticalStretch = 1;
        part->unkOffset[0] = 0;
        part->unkOffset[1] = 0;
        decorationTable->unk_6C1 = 0;
    }
    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_802597B0(part, yaw, mtx);
    } else {
        func_8025950C(part, yaw, mtx);
    }
}

void func_80259AAC(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    s32 i, j;

    if (decorationTable->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
        } else {
            decorationTable->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
        }
        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6C1 = 0;
    }

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        u16* palIn = decorationTable->spritePalettes[i];
        u16* palOut = decorationTable->copiedPalettes[0][i];
        decorationTable->unk_6D4[i] = palOut;
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
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
            if (isNpcSprite == SPRITE_MODE_PLAYER) {
                func_8025995C(part, yaw, mtx);
            } else {
                func_802596C0(part, yaw, mtx);
            }
            break;
    }
}

void func_80259D9C(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;
    s32 temp;

    if (decorationTable->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->spriteColorVariations = 6;
        } else {
            decorationTable->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->spriteColorVariations = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }

        for (i = 0; i < decorationTable->numSpritePalettes; i++) {
            palIn = decorationTable->spritePalettes[i];
            palOut = decorationTable->copiedPalettes[0][i];
            if (palIn != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
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
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->spritePalettes[i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 1:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->spritePalettes[decorationTable->spriteColorVariations * 3 + i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->spritePalettes[i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
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

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }

    if (arg4 == 0) {
        decorationTable->unk_6CA--;
    }
}

void func_8025A2C4(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;
    s32 temp;

    if (decorationTable->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 2;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
        } else {
            decorationTable->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
        }

        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C8 = 0;
        decorationTable->unk_6C1 = 0;
    }

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        palIn = decorationTable->spritePalettes[i];
        palOut = decorationTable->copiedPalettes[0][i];
        decorationTable->unk_6D4[i] = palOut;
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                u8 r = ((*palIn >> 11) / 2) & 0xF;
                u8 g = ((*palIn >>  6) / 2) & 0xF;
                u8 b = ((*palIn >>  1) / 2) & 0xF;
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

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }
}

void func_8025A50C(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;

    if (decorationTable->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
        } else {
            decorationTable->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->spriteColorVariations = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }

        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C1 = 0;
    }

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        palIn = decorationTable->spritePalettes[i];
        palOut = decorationTable->copiedPalettes[0][i];
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                *palOut++ = *palIn++;
            }
        }
    }
    for (i = 0; i < decorationTable->spriteColorVariations; i++) {
        palIn = decorationTable->spritePalettes[decorationTable->spriteColorVariations + i];
        palOut = decorationTable->copiedPalettes[0][i];
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                *palOut++ = *palIn++;
            }
        }
    }

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }
}

void func_8025A74C(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;

    if (decorationTable->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
        } else {
            decorationTable->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
        }

        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6C8 = 0;
        decorationTable->unk_6CA = 10;
        decorationTable->unk_6C1 = 0;
    }
    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        palIn = decorationTable->spritePalettes[i];
        palOut = decorationTable->copiedPalettes[0][i];
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                u8 r = ((*palIn >> 11) & 0x1F);
                u8 g = ((*palIn >> 6) & 0x1F);
                u8 b = ((*palIn >> 1) & 0x1F);
                u8 a = *palIn & 1;
                palIn++;
                r += 4;
                if (r > 31) {
                    r = 31;
                }
                g += 4;
                if (g > 31) {
                    g = 31;
                }
                b += 4;
                if (b > 31) {
                    b = 31;
                }

                *palOut++ = (r << 11) | (g << 6) | (b << 1) | a;
            }
        }
    }

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->copiedPalettes[0][i];
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

            switch (decorationTable->unk_6CA) {
                case 10:
                case 12:
                    if (isNpcSprite == SPRITE_MODE_PLAYER) {
                        func_8025995C(part, yaw, mtx);
                    } else {
                        func_802596C0(part, yaw, mtx);
                    }
                    break;
                case 13:
                    decorationTable->unk_6CA = 0;
                    // fallthrough
                default:
                    if (isNpcSprite == SPRITE_MODE_PLAYER) {
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

void func_8025AA80(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    s32 i, j;

    if (decorationTable->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->unk_6C2 = 0;
        } else {
            decorationTable->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->unk_6C2 = 0;
        }
        decorationTable->unk_6CA = 0;
        decorationTable->unk_6C2 = 0;
        decorationTable->unk_6C1 = 0;
    }

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        PAL_PTR palIn = decorationTable->spritePalettes[i];
        PAL_PTR palOut = decorationTable->copiedPalettes[0][i];
        if (palIn != NULL) {
            for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
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

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }
}

void func_8025AD90(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;
    s32 temp;

    if (decorationTable->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->spriteColorVariations = 6;
        } else {
            decorationTable->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->spriteColorVariations = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }

        for (i = 0; i < decorationTable->numSpritePalettes; i++) {
            palIn = decorationTable->spritePalettes[i];
            palOut = decorationTable->copiedPalettes[0][i];
            if (palIn != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
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
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->spritePalettes[i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 1:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->spritePalettes[decorationTable->spriteColorVariations * 5 + i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->spritePalettes[decorationTable->spriteColorVariations * 6 + i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
    }

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }

    if (arg4 == 0) {
        decorationTable->unk_6CA--;
    }
}

void func_8025B1A8(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decorationTable = part->decorationTable;
    u16* palIn;
    u16* palOut;
    s32 i, j;
    s32 temp;

    if (decorationTable->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->spriteColorVariations = 6;
        } else {
            decorationTable->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->spriteColorVariations = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }

        for (i = 0; i < decorationTable->numSpritePalettes; i++) {
            palIn = decorationTable->spritePalettes[i];
            palOut = decorationTable->copiedPalettes[0][i];
            if (palIn != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
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
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->spritePalettes[i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 1:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->spritePalettes[decorationTable->spriteColorVariations * 5 + i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->spritePalettes[decorationTable->spriteColorVariations * 6 + i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
    }

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }

    if (arg4 == 0) {
        decorationTable->unk_6CA--;
    }
}

void func_8025B5C0(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4, s32 arg5) {
    DecorationTable* decorationTable = part->decorationTable;
    PAL_PTR color2;
    PAL_PTR color1;
    PAL_PTR palOut;
    s32 i, j;
    u8 alpha;

    if (decorationTable->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }

            if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                decorationTable->spriteColorVariations = 4;
            } else {
                decorationTable->spriteColorVariations = 6;
            }
        } else {
            decorationTable->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decorationTable->numSpritePalettes = 0;
            while ((s32)decorationTable->spritePalettes[decorationTable->numSpritePalettes] != -1) {
                decorationTable->numSpritePalettes++;
            }
            decorationTable->spriteColorVariations = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }

        if (decorationTable->unk_6C1 == 1) {
            decorationTable->unk_6C2 = 0;
            decorationTable->unk_6CA = 0;
        } else {
            decorationTable->unk_6C2 = 0;
            decorationTable->unk_6CA = 255;
        }

        for (i = 0; i < decorationTable->numSpritePalettes; i++) {
            color2 = decorationTable->spritePalettes[i];
            color1 = decorationTable->copiedPalettes[0][i];
            decorationTable->unk_6D4[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                    *color1++ = *color2++;
                }
            }
        }

        if (arg5) {
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                color2 = decorationTable->spritePalettes[decorationTable->spriteColorVariations + i];
                palOut = decorationTable->copiedPalettes[0][i];
                for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                    *palOut++ = *color2++;
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
                if (decorationTable->unk_6CA > 25500) {
                    decorationTable->unk_6CA = 25500;
                }
            }
            alpha = decorationTable->unk_6CA / 100;
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                if (arg5 == 0) {
                    color2 = decorationTable->spritePalettes[i];
                } else {
                    color2 = decorationTable->spritePalettes[decorationTable->spriteColorVariations + i];
                }
                color1 = decorationTable->spritePalettes[decorationTable->spriteColorVariations * 2 + i];
                palOut = decorationTable->copiedPalettes[0][i];

                for (j = 0; j < ARRAY_COUNT(decorationTable->copiedPalettes[0][i]); j++) {
                    u8 r2 = (*color2 >> 11) & 0x1F;
                    u8 g2 = (*color2 >> 6) & 0x1F;
                    u8 b2 = (*color2 >> 1) & 0x1F;
                    u8 r1 = (*color1 >> 11) & 0x1F;
                    u8 g1 = (*color1 >> 6) & 0x1F;
                    u8 b1 = (*color1 >> 1) & 0x1F;
                    u8 a1 = *color1 & 1;
                    color2++;
                    color1++;

                    r2 = (r2 * (255 - alpha) + r1 * alpha) / 255;
                    g2 = (g2 * (255 - alpha) + g1 * alpha) / 255;
                    b2 = (b2 * (255 - alpha) + b1 * alpha) / 255;

                    *palOut++ = (r2 << 11) | (g2 << 6) | (b2 << 1) | a1;
                }
            }
            if (alpha == 255) {
                decorationTable->unk_6C2 = 1;
            }
        }
    }

    for (i = 0; i < decorationTable->numSpritePalettes; i++) {
        decorationTable->unk_6D4[i] = decorationTable->copiedPalettes[0][i];
    }

    switch (decorationTable->unk_6C2) {
        case 0:
        case 1:
            if (isNpcSprite == SPRITE_MODE_PLAYER) {
                func_8025995C(part, yaw, mtx);
            } else {
                func_802596C0(part, yaw, mtx);
            }
            break;
    }
}

void func_8025BAA0(s32 isNpcSprite, ActorPart* part, s32 yaw, s32 arg3, Matrix4f mtx, s32 arg5) {
    DecorationTable* decor = part->decorationTable;
    PAL_PTR color1;
    PAL_PTR color2;
    PAL_PTR blendColor;
    s32 i, j;
    u8 blendAlpha;
    u8 r2, g2, b2, a1;
    u8 r1, g1, b1;

    if (decor->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decor->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decor->numSpritePalettes = 0;
            while ((s32)decor->spritePalettes[decor->numSpritePalettes] != -1) {
                decor->numSpritePalettes++;
            }
        } else {
            decor->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decor->numSpritePalettes = 0;
            while ((s32)decor->spritePalettes[decor->numSpritePalettes] != -1) {
                decor->numSpritePalettes++;
            }
        }

        if (decor->unk_6C1 == 1) {
            decor->unk_6C2 = 0;
            decor->unk_6CA = 0;
        } else {
            decor->unk_6C2 = 0;
            decor->unk_6CA = 255;
        }

        for (i = 0; i < decor->numSpritePalettes; i++) {
            color2 = decor->spritePalettes[i];
            color1 = decor->copiedPalettes[0][i];
            decor->unk_6D4[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < 16; j++) {
                    *color1++ = *color2++;
                }
            }
        }

        if (arg3 == 0) {
            decor->unk_746 = decor->unk_744;
            decor->unk_748 = decor->unk_746;
            decor->unk_74A = decor->unk_746;
            decor->unk_744 = 0;
        }

        decor->unk_6C8 = decor->unk_744;
        decor->unk_6CA = 0;
        decor->unk_6C2 = 0;
        decor->unk_6C1 = 0;
    }

    switch (decor->unk_6C2) {
        case 0:
            if (arg5 != 0) {
                break;
            }
            if (decor->unk_6C8 != 0) {
                decor->unk_6C8--;
                break;
            }
            decor->unk_6CA = 0;
            decor->unk_6C2 = 1;
            // fallthrough
        case 1:
            if (arg5 == 0) {
                decor->unk_6CA += 25600 / decor->unk_746;
                if (decor->unk_6CA > 25500) {
                    decor->unk_6CA = 25500;
                }
            }
            blendAlpha = decor->unk_6CA / 100;
            color2 = decor->spritePalettes[decor->unk_740];
            color1 = decor->spritePalettes[decor->unk_742];
            blendColor = decor->unk_6D4[0] = decor->copiedPalettes[0][0];

            for (j = 0; j < 16; j++) {
                r2 = (*color2 >> 11) & 0x1F;
                g2 = (*color2 >> 6) & 0x1F;
                b2 = (*color2 >> 1) & 0x1F;
                r1 = (*color1 >> 11) & 0x1F;
                g1 = (*color1 >> 6) & 0x1F;
                b1 = (*color1 >> 1) & 0x1F;
                a1 = *color1 & 1;
                color2++;
                color1++;

                r1 = (r2 * (255 - blendAlpha) + r1 * blendAlpha) / 255;
                g1 = (g2 * (255 - blendAlpha) + g1 * blendAlpha) / 255;
                b1 = (b2 * (255 - blendAlpha) + b1 * blendAlpha) / 255;

                *blendColor++ = (r1 << 11) | (g1 << 6) | (b1 << 1) | a1;
            }
            if (blendAlpha == 255) {
                decor->unk_6C2 = 2;
                decor->unk_6C8 = decor->unk_748;
            }
            break;
    }
    switch (decor->unk_6C2) {
        case 2:
            if (arg5 != 0) {
                break;
            }
            if (decor->unk_6C8 != 0) {
                decor->unk_6C8--;
                break;
            }
            decor->unk_6CA = 0;
            decor->unk_6C2 = 3;
            // fallthrough
        case 3:
            if (arg5 == 0) {
                decor->unk_6CA += 25600 / decor->unk_74A;
                if (decor->unk_6CA > 25500) {
                    decor->unk_6CA = 25500;
                }
            }
            blendAlpha = decor->unk_6CA / 100;
            color2 = decor->spritePalettes[decor->unk_742];
            color1 = decor->spritePalettes[decor->unk_740];
            blendColor = decor->copiedPalettes[0][0];
            decor->unk_6D4[0] = blendColor;

            for (j = 0; j < 16; j++) {
                r2 = (*color2 >> 11) & 0x1F;
                g2 = (*color2 >> 6) & 0x1F;
                b2 = (*color2 >> 1) & 0x1F;
                r1 = (*color1 >> 11) & 0x1F;
                g1 = (*color1 >> 6) & 0x1F;
                b1 = (*color1 >> 1) & 0x1F;
                a1 = *color1 & 1;
                color2++;
                color1++;

                r1 = (r2 * (255 - blendAlpha) + r1 * blendAlpha) / 255;
                g1 = (g2 * (255 - blendAlpha) + g1 * blendAlpha) / 255;
                b1 = (b2 * (255 - blendAlpha) + b1 * blendAlpha) / 255;

                *blendColor++ = ((r1) << 11) | ((g1) << 6) | ((b1) << 1) | a1;
            }
            if (blendAlpha == 255) {
                decor->unk_6C2 = 0;
                decor->unk_6C8 = decor->unk_744;
            }
            break;
    }

    switch (decor->unk_6C2) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (isNpcSprite == SPRITE_MODE_PLAYER) {
                func_8025995C(part, yaw, mtx);
            } else {
                func_802596C0(part, yaw, mtx);
            }
            break;
    }
}

void func_8025C120(s32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, s32 arg4) {
    DecorationTable* decor = part->decorationTable;
    PAL_PTR color1;
    PAL_PTR color2;
    PAL_PTR blendColor;
    s32 i, j;
    u8 blendAlpha;
    u8 r2, g2, b2, a1;
    u8 r1, g1, b1;

    if (decor->unk_6C1 != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decor->spritePalettes = spr_get_player_palettes(part->currentAnimation >> 16);
            decor->numSpritePalettes = 0;
            while (decor->spritePalettes[decor->numSpritePalettes] != (PAL_PTR) -1) {
                decor->numSpritePalettes++;
            }
        } else {
            decor->spritePalettes = spr_get_npc_palettes(part->currentAnimation >> 16);
            decor->numSpritePalettes = 0;
            while (decor->spritePalettes[decor->numSpritePalettes] != (PAL_PTR) -1) {
                decor->numSpritePalettes++;
            }
            decor->spriteColorVariations = spr_get_npc_color_variations(part->currentAnimation >> 16);
        }
        if (decor->unk_6C1 == 1) {
            decor->unk_6C2 = 0;
            decor->unk_6CA = 0;
        } else {
            decor->unk_6C2 = 0;
            decor->unk_6CA = 255;
        }

         for (i = 0; i < decor->numSpritePalettes; i++) {
            color2 = decor->spritePalettes[i];
            color1 = decor->copiedPalettes[0][i];
            decor->unk_6D4[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < 16; j++) {
                    *color1++ = *color2++;
                }
            }
        }

        decor->unk_6C8 = decor->unk_744;
        decor->unk_6CA = 0;
        decor->unk_6C2 = 0;
        decor->unk_6C1 = 0;
    }

    switch (decor->unk_6C2) {
        case 0:
            if (arg4 != 0) {
                break;
            }
            if (decor->unk_6C8 != 0) {
                decor->unk_6C8--;
                break;
            }
            decor->unk_6CA = 0;
            decor->unk_6C2 = 1;
            // fallthrough
        case 1:
            if (arg4 == 0) {
                decor->unk_6CA += 0x6400 / decor->unk_746;
                if (decor->unk_6CA > 25500) {
                    decor->unk_6CA = 25500;
                }
            }
            blendAlpha = decor->unk_6CA / 100;
            for (i = 0; i < decor->spriteColorVariations; i++) {
                color2 = decor->spritePalettes[decor->unk_740 * decor->spriteColorVariations + i];
                color1 = decor->spritePalettes[decor->unk_742 * decor->spriteColorVariations + i];
                blendColor = decor->copiedPalettes[0][i];
                decor->unk_6D4[i] = blendColor;

                for (j = 0; j < 16; j++) {
                    r2 = (*color2 >> 11) & 0x1F;
                    g2 = (*color2 >> 6) & 0x1F;
                    b2 = (*color2 >> 1) & 0x1F;
                    r1 = (*color1 >> 11) & 0x1F;
                    g1 = (*color1 >> 6) & 0x1F;
                    b1 = (*color1 >> 1) & 0x1F;
                    a1 = *color1 & 1;
                    color2++;
                    color1++;

                    r1 = (r2 * (255 - blendAlpha) + r1 * blendAlpha) / 255;
                    g1 = (g2 * (255 - blendAlpha) + g1 * blendAlpha) / 255;
                    b1 = (b2 * (255 - blendAlpha) + b1 * blendAlpha) / 255;

                    *blendColor++ = (r1 << 11) | (g1 << 6) | (b1 << 1) | a1;
                }
            }
            if (blendAlpha == 255) {
                decor->unk_6C2 = 2;
                decor->unk_6C8 = decor->unk_748;
            }
            break;
    }

    switch (decor->unk_6C2) {
        case 2:
            if (arg4 != 0) {
                break;
            }
            if (decor->unk_6C8 != 0) {
                decor->unk_6C8--;
                break;
            }
            decor->unk_6CA = 0;
            decor->unk_6C2 = 3;
            // fallthrough
        case 3:
            if (arg4 == 0) {
                decor->unk_6CA += 0x6400 / decor->unk_74A;
                if (decor->unk_6CA > 25500) {
                    decor->unk_6CA = 25500;
                }
            }
            blendAlpha = decor->unk_6CA / 100;
            for (i = 0; i < decor->spriteColorVariations; i++) {
                color2 = decor->spritePalettes[decor->unk_740 * decor->spriteColorVariations + i];
                color1 = decor->spritePalettes[decor->unk_742 * decor->spriteColorVariations + i];
                blendColor = decor->copiedPalettes[0][i];
                decor->unk_6D4[i] = blendColor;

                for (j = 0; j < 16; j++) {
                    r2 = (*color2 >> 11) & 0x1F;
                    g2 = (*color2 >> 6) & 0x1F;
                    b2 = (*color2 >> 1) & 0x1F;
                    r1 = (*color1 >> 11) & 0x1F;
                    g1 = (*color1 >> 6) & 0x1F;
                    b1 = (*color1 >> 1) & 0x1F;
                    a1 = *color1 & 1;
                    color2++;
                    color1++;

                    r1 = (r2 * (255 - blendAlpha) + r1 * blendAlpha) / 255;
                    g1 = (g2 * (255 - blendAlpha) + g1 * blendAlpha) / 255;
                    b1 = (b2 * (255 - blendAlpha) + b1 * blendAlpha) / 255;

                    *blendColor++ = ((r1) << 11) | ((g1) << 6) | ((b1) << 1) | a1;
                }
            }
            if (blendAlpha == 255) {
                decor->unk_6C2 = 0;
                decor->unk_6C8 = decor->unk_744;
            }
            break;
    }

    switch (decor->unk_6C2) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (isNpcSprite == SPRITE_MODE_PLAYER) {
                func_8025995C(part, yaw, mtx);
            } else {
                func_802596C0(part, yaw, mtx);
            }
            break;
    }
}

s32 func_8025C840(s32 arg0, ActorPart* part, s32 yaw, s32 arg3) {
    if (!(part->flags & ACTOR_PART_FLAG_2)) {
        switch (part->decorationTable->unk_750) {
            case 0:
                func_8025C8A0(arg0, part, yaw, arg3);
                return 0;
            case 11:
                func_8025C918(arg0, part, yaw, arg3);
                break;
        }
    }
    return 0;
}

void func_8025C8A0(s32 isNpcSprite, ActorPart* part, s32 yaw, s32 arg3) {
    if (part->decorationTable->unk_751 != 0) {
        part->decorationTable->unk_751 = 0;
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            func_802DDFF8(PLAYER_SPRITE_MAIN, FOLD_UPD_CLEAR, 0, 0, 0, 0, 0);
        } else {
            func_802DE894(part->spriteInstanceID, FOLD_UPD_CLEAR, 0, 0, 0, 0, 0);
        }
    }
}

void func_8025C918(s32 isNpcSprite, ActorPart* part, s32 yaw, s32 arg3) {
    DecorationTable* decor = part->decorationTable;
    u8 rbuf[20];
    u8 gbuf[20];
    u8 bbuf[20];
    s32 alpha;
    s32 color;
    s32 i;
    s32 baseAngle;

    if (decor->unk_751 != 0) {
        decor->unk_752 = -2;
        decor->unk75A = 0;
        decor->unk_751 = 0;
        decor->unk758 = 0;
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            func_802DDFF8(PLAYER_SPRITE_MAIN, FOLD_UPD_ALLOC_COLOR_BUF, 20, 0, 0, 255, 0);
        } else {
            func_802DE894(part->spriteInstanceID, FOLD_UPD_ALLOC_COLOR_BUF, 20, 0, 0, 255, 0);
        }
    }

    decor->unk75C += 7;
    baseAngle = decor->unk75C;

    if (decor->unk75C >= 360) {
        decor->unk75C = baseAngle % 360;
    }

    for (i = 0; i < ARRAY_COUNT(rbuf); i++) {
        rbuf[i] = (cosine(decor->unk75C + (25 * i)) + 1.0) * 112.0;
        gbuf[i] = (cosine(decor->unk75C + (25 * i) + 45) + 1.0) * 112.0;
        bbuf[i] = (cosine(decor->unk75C + (25 * i) + 90) + 1.0) * 112.0;
    }

    alpha = 255;
    if (part->opacity < 255) {
        alpha = part->opacity;
    }
    if (part->flags & 0x100) {
        alpha = (alpha * 120) / 255;
    }

    for (i = 0; i < ARRAY_COUNT(rbuf); i++) {
        color = (rbuf[i] << 0x18) | (gbuf[i] << 0x10) | (bbuf[i] << 8) | alpha;
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            func_802DDFF8(PLAYER_SPRITE_MAIN, FOLD_UPD_COLOR_BUF_SET_C, i, color, 0, 255, 0);
        } else {
            func_802DE894(part->spriteInstanceID, FOLD_UPD_COLOR_BUF_SET_C, i, color, 0, 255, 0);
        }
    }

    if (arg3 == 0) {
        decor->unk75A -= 1;
    }
}

s32 func_8025CCC8(s32 arg0, ActorPart* part, s32 yaw, s32 arg3) {
    if (!(part->flags & ACTOR_PART_FLAG_2)) {
        switch (part->decorationTable->unk_764) {
            case 0:
                func_8025CD28(arg0, part, yaw, arg3);
                return 0;
            case 1:
                func_8025CD40(arg0, part, yaw, arg3);
                return 0;
        }
    }
    return 0;
}

void func_8025CD28(s32 arg0, ActorPart* part, s32 yaw, s32 arg3) {
    DecorationTable* decorationTable = part->decorationTable;

    if (decorationTable->unk_765 != 0) {
        decorationTable->unk_765 = 0;
    }
    decorationTable->unk_768 = 0;
}

void func_8025CD40(s32 arg0, ActorPart* part, s32 yaw, s32 arg3) {
    DecorationTable* decor = part->decorationTable;

    if (decor->unk_765 != 0) {
        switch (func_80254250(part)) {
            case 0:
                decor->unk_767 = 1;
                decor->unk_766 = 0;
                break;
            case 1:
                decor->unk_767 = 8;
                decor->unk_766 = 1;
                break;
            case 2:
            default:
                decor->unk_767 = 0xE;
                decor->unk_766 = 2;
                break;
        }
        decor->unk_768 = 0;
        decor->unk_765 = 0;
    }

    if (decor->unk_766 == 3) {
        decor->unk_768 = 0;
        func_8026709C(part);
    }

    switch (decor->unk_766) {
        case 0:
            switch (decor->unk_767) {
                case 0:
                    decor->unk_768 = -1;
                    decor->unk_766 = 3;
                    break;
                default:
                    decor->unk_768 = 0;
                    if (arg3 == 0) {
                        decor->unk_767--;
                    }
                    break;
            }
            break;
        case 1:
           switch (decor->unk_767) {
                case 1:
                case 2:
                case 5:
                case 6:
                    decor->unk_768 = -1;
                    break;
                case 3:
                case 4:
                case 7:
                case 8:
                    decor->unk_768 = 0;
                    break;
                case 0:
                    decor->unk_766 = 3;
                    break;
            }
            if (arg3 == 0) {
                decor->unk_767--;
            }
            break;
        case 2:
           switch (decor->unk_767) {
                case 1:
                case 2:
                case 5:
                case 6:
                case 9:
                case 10:
                case 13:
                case 14:
                    decor->unk_768 = 0;
                    break;
                case 3:
                case 4:
                case 7:
                case 8:
                case 11:
                case 12:
                    decor->unk_768 = -1;
                    break;
                case 0:
                    decor->unk_766 = 3;
                    break;
            }
            if (arg3 == 0) {
                decor->unk_767--;
            }
            break;
    }
}

void _add_part_decoration(ActorPart* actorPart) {
    DecorationTable* decorationTable;
    s32 i;

    if (!(actorPart->flags & 2)) {
        decorationTable = actorPart->decorationTable;
        for (i = 0; i < ARRAY_COUNT(decorationTable->type); i++) {
            switch (decorationTable->type[i]) {
                case ACTOR_DECORATION_NONE:
                    func_8025D150(actorPart, i);
                    break;
                case ACTOR_DECORATION_GOLDEN_FLAMES:
                    func_8025D160(actorPart, i);
                    break;
                case ACTOR_DECORATION_SWEAT:
                    func_8025D2B0(actorPart, i);
                    break;
                case ACTOR_DECORATION_SEEING_STARS:
                    func_8025D3CC(actorPart, i);
                    break;
                case ACTOR_DECORATION_RED_FLAMES:
                    func_8025D4C8(actorPart, i);
                    break;
                case ACTOR_DECORATION_GREY_SMOKE_TRAIL:
                    func_8025D640(actorPart, i);
                    break;
                case ACTOR_DECORATION_FIRE_SMOKE_TRAIL:
                    func_8025D71C(actorPart, i);
                    break;
                case ACTOR_DECORATION_WHIRLWIND:
                    func_8025D830(actorPart, i);
                    break;
                case ACTOR_DECORATION_STEAM_EMITTER:
                    func_8025D90C(actorPart, i);
                    break;
                case ACTOR_DECORATION_9:
                    func_8025DA68(actorPart, i);
                    break;
                case ACTOR_DECORATION_A:
                    func_8025DBD0(actorPart, i);
                    break;
                case ACTOR_DECORATION_RADIAL_STAR_EMITTER:
                    func_8025DD60(actorPart, i);
                    break;
            }
        }
    }
}

void _remove_part_decoration(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decorationTable = part->decorationTable;

    switch (decorationTable->type[decorationIndex]) {
        case ACTOR_DECORATION_NONE:
            func_8025D158(part, decorationIndex);
            break;
        case ACTOR_DECORATION_GOLDEN_FLAMES:
            func_8025D290(part, decorationIndex);
            break;
        case ACTOR_DECORATION_SWEAT:
            func_8025D3C4(part, decorationIndex);
            break;
        case ACTOR_DECORATION_SEEING_STARS:
            func_8025D4A0(part, decorationIndex);
            break;
        case ACTOR_DECORATION_RED_FLAMES:
            func_8025D620(part, decorationIndex);
            break;
        case ACTOR_DECORATION_GREY_SMOKE_TRAIL:
            func_8025D6FC(part, decorationIndex);
            break;
        case ACTOR_DECORATION_FIRE_SMOKE_TRAIL:
            func_8025D810(part, decorationIndex);
            break;
        case ACTOR_DECORATION_WHIRLWIND:
            func_8025D8EC(part, decorationIndex);
            break;
        case ACTOR_DECORATION_STEAM_EMITTER:
            func_8025DA60(part, decorationIndex);
            break;
        case ACTOR_DECORATION_9:
            func_8025DBC8(part, decorationIndex);
            break;
        case ACTOR_DECORATION_A:
            func_8025DD40(part, decorationIndex);
            break;
        case ACTOR_DECORATION_RADIAL_STAR_EMITTER:
            func_8025DE88(part, decorationIndex);
            break;
    }

    decorationTable->type[decorationIndex] = 0;
}

void func_8025D150(ActorPart* actorPart, s32 i) {
}

void func_8025D158(ActorPart* part, s32 decorationIndex) {
}

void func_8025D160(ActorPart* arg0, s32 index) {
    DecorationTable* table = arg0->decorationTable;
    EffectInstance* effect;
    AuraFXData* data;
    f32 scale;

    switch (table->state[index]) {
        case 0:
            fx_aura(3, arg0->currentPos.x, arg0->currentPos.y, arg0->currentPos.z, 0.4f, &table->effect[index]);
            table->state[index] = 1;
            table->unk_8C6[index].unk00 = 0x28;
            table->unk_8C6[index].unk02 = 0x28;
            table->unk_8C6[index].unk04 = 0;
            break;
        case 1:
            effect = table->effect[index];
            data = effect->data.aura;
            data->posA.x = arg0->currentPos.x + table->unk_8C6[index].unk04;
            data->posA.y = arg0->currentPos.y;
            data->posA.z = arg0->currentPos.z;
            scale = table->unk_8C6[index].unk00;
            scale /= 100.0f;
            effect->data.aura->scale.x = scale;
            scale = table->unk_8C6[index].unk02;
            scale /= 100.0f;
            effect->data.aura->scale.y = scale;
            break;
    }
}

void func_8025D290(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->effect[decorationIndex]->data.aura->fadeTime = 5;
}

void func_8025D2B0(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decor = part->decorationTable;

    switch (decor->state[decorationIndex]) {
        case 0:
            if (part->yaw > 90.0f) {
                fx_sweat(0, part->currentPos.x, part->currentPos.y + part->size.y, part->currentPos.z, 5.0f, 45.0f, 20);
            } else {
                fx_sweat(0, part->currentPos.x, part->currentPos.y + part->size.y, part->currentPos.z, 5.0f, -45.0f, 20);
            }
            decor->stateResetTimer[decorationIndex] = 10;
            decor->state[decorationIndex] = TRUE;
            break;
        case 1:
            if (decor->stateResetTimer[decorationIndex] != 0) {
                decor->stateResetTimer[decorationIndex]--;
            } else {
                decor->state[decorationIndex] = FALSE;
            }
            break;
    }
}

void func_8025D3C4(ActorPart* part, s32 decorationIndex) {
}

void func_8025D3CC(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decor;
    StarsOrbitingFXData* data;
    s8 temp_v1;

    decor = part->decorationTable;
    switch (decor->state[decorationIndex]) {
        case 0:
            fx_stars_orbiting(0, part->currentPos.x, part->currentPos.y + part->size.y, part->currentPos.z,
                20.0f, 3, &decor->effect[decorationIndex]);
            decor->state[decorationIndex] = 1;
            break;
        case 1:
            data = decor->effect[decorationIndex]->data.starsOrbiting;
            data->pos.x = part->currentPos.x;
            data->pos.y = part->currentPos.y + part->size.y;
            data->pos.z = part->currentPos.z;
            break;
    }
}

void func_8025D4A0(ActorPart* part, s32 decorationIndex) {
    remove_effect(part->decorationTable->effect[decorationIndex]);
}

void func_8025D4C8(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decor = part->decorationTable;
    EffectInstance* effect;
    AuraFXData* data;
    f32 scale;

    switch (decor->state[decorationIndex]) {
        case 0:
            fx_aura(1, part->currentPos.x, part->currentPos.y, part->currentPos.z, 0.4f, &decor->effect[decorationIndex]);
            decor->state[decorationIndex] = 1;
            decor->unk_8C6[decorationIndex].unk00 = 40;
            decor->unk_8C6[decorationIndex].unk02 = 40;
            decor->unk_8C6[decorationIndex].unk04 = 255;
            decor->unk_8C6[decorationIndex].unk06 = 0;
            decor->unk_8C6[decorationIndex].unk08 = 255;
            decor->unk_8C6[decorationIndex].unk0A = 0;
            decor->unk_8C6[decorationIndex].unk0C = 0;
            // fallthrough
        case 1:
            effect = decor->effect[decorationIndex];
            data = effect->data.aura;
            data->posA.x = part->currentPos.x;
            data->posA.y = part->currentPos.y;
            data->posA.z = part->currentPos.z + decor->unk_8C6[decorationIndex].unk06;

            scale = decor->unk_8C6[decorationIndex].unk00;
            scale /= 100.0f;
            effect->data.aura->scale.x = scale;
            scale = decor->unk_8C6[decorationIndex].unk02;
            scale /= 100.0f;
            effect->data.aura->scale.y = scale;
            effect->data.aura->primA = decor->unk_8C6[decorationIndex].unk04;
            break;
    }
}

void func_8025D620(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->effect[decorationIndex]->data.aura->fadeTime = 5;
}

void func_8025D640(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decor = part->decorationTable;
    EffectInstance* effect;

    switch (decor->state[decorationIndex]) {
        case 0:
            decor->effect[decorationIndex] = fx_65(1, part->currentPos.x, part->currentPos.y, part->currentPos.z, 1.0f, 0);
            decor->state[decorationIndex] = 1;
            break;
        case 1:
            effect = decor->effect[decorationIndex];
            effect->data.unk_65->pos.x = part->currentPos.x;
            effect->data.unk_65->pos.y = part->currentPos.y;
            effect->data.unk_65->pos.z = part->currentPos.z;
            break;
    }
}

void func_8025D6FC(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->effect[decorationIndex]->flags |= 0x10;
}

void func_8025D71C(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decor = part->decorationTable;
    EffectInstance* effect;

    switch (decor->state[decorationIndex]) {
        case 0:
            decor->effect[decorationIndex] = fx_65(2, part->currentPos.x, part->currentPos.y, part->currentPos.z, 1.0f, 0);
            decor->unk_8C6[decorationIndex].unk00 = 1;
            decor->state[decorationIndex] = 1;
            break;
        case 1:
            effect = decor->effect[decorationIndex];
            effect->data.unk_65->pos.x = part->currentPos.x;
            effect->data.unk_65->pos.y = part->currentPos.y;
            effect->data.unk_65->pos.z = part->currentPos.z;
            effect->data.unk_65->scale = decor->unk_8C6[decorationIndex].unk00 / 100.0f;
            break;
    }
}

void func_8025D810(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->effect[decorationIndex]->flags |= 0x10;
}

void func_8025D830(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decor = part->decorationTable;
    EffectInstance* effect;

    switch (decor->state[decorationIndex]) {
        case 0:
            decor->effect[decorationIndex] = fx_whirlwind(2, part->currentPos.x, part->currentPos.y, part->currentPos.z, 1.0f, 0);
            decor->state[decorationIndex] = 1;
            break;
        case 1:
            effect = decor->effect[decorationIndex];
            effect->data.whirlwind->pos.x = part->currentPos.x;
            effect->data.whirlwind->pos.y = part->currentPos.y;
            effect->data.whirlwind->pos.z = part->currentPos.z;
            break;
    }
}

void func_8025D8EC(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->effect[decorationIndex]->flags |= EFFECT_INSTANCE_FLAG_10;
}

void func_8025D90C(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decor = part->decorationTable;
    f32 angle, sinA, cosA;

    switch (decor->state[decorationIndex]) {
        case 0:
            decor->stateResetTimer[decorationIndex] = 0;
            decor->state[decorationIndex] = 1;
            // fallthrough
        case 1:
            decor->stateResetTimer[decorationIndex]++;
            if (decor->stateResetTimer[decorationIndex] >= 4) {
                decor->stateResetTimer[decorationIndex] = 0;
                angle = DEG_TO_RAD(clamp_angle(-part->yaw));
                sinA = sin_rad(angle);
                cosA = cos_rad(angle);
                fx_walking_dust(0,
                    part->currentPos.x + (part->size.x * sinA * 0.2f),
                    part->currentPos.y + 1.5f,
                    part->currentPos.z + (part->size.x * cosA * 0.2f),
                    sinA, cosA);
            }
            break;
    }
}

void func_8025DA60(ActorPart* part, s32 decorationIndex) {
}

void func_8025DA68(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decor = part->decorationTable;
    f32 x, y, z;

    if (D_80284134[decor->unk_8C6[decorationIndex].unk00] >= 0) {
        switch (decor->state[decorationIndex]) {
            case 0:
                decor->stateResetTimer[decorationIndex] = 0;
                decor->state[decorationIndex] = 1;
                // fallthrough
            case 1:
                x = part->currentPos.x;
                y = part->currentPos.y + (part->size.y / 2);
                z = part->currentPos.z - 5.0f;
                // @bug? perhaps this should be % 4?
                if ((gGameStatusPtr->frameCounter / 4) == 0) {
                    fx_sparkles(FX_SPARKLES_1, x, y, z, 10.0f);
                }
                decor->stateResetTimer[decorationIndex]++;
                if (D_80284134[decor->unk_8C6[decorationIndex].unk00] < decor->stateResetTimer[decorationIndex]) {
                    decor->stateResetTimer[decorationIndex] = 0;
                    fx_sparkles(FX_SPARKLES_1, x, y, z, 20.0f);
                }
                break;
        }
    }
}

void func_8025DBC8(ActorPart* part, s32 decorationIndex) {
}

void func_8025DBD0(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decor = part->decorationTable;
    EffectInstance* effect;
    AuraFXData* data;
    f32 scale;

    switch (decor->state[decorationIndex]) {
        case 0:
            fx_aura(2, part->currentPos.x, part->currentPos.y, part->currentPos.z, 1.2f, &decor->effect[decorationIndex]);
            decor->state[decorationIndex] = 1;
            decor->unk_8C6[decorationIndex].unk00 = 150;
            decor->unk_8C6[decorationIndex].unk02 = 150;
            decor->unk_8C6[decorationIndex].unk04 = 255;
            decor->unk_8C6[decorationIndex].unk06 = 0;
            // fallthrough
        case 1:
            effect = decor->effect[decorationIndex];
            data = effect->data.aura;
            data->posA.x = part->currentPos.x;
            data->posA.y = part->currentPos.y;
            data->posA.z = part->currentPos.z + decor->unk_8C6[decorationIndex].unk06;

            scale = decor->unk_8C6[decorationIndex].unk00;
            scale /= 100.0f;
            effect->data.aura->scale.x = scale;
            scale = decor->unk_8C6[decorationIndex].unk02;
            scale /= 100.0f;
            effect->data.aura->scale.y = scale * (0.8 - 1e-16); // epsilon?
            effect->data.aura->primA = decor->unk_8C6[decorationIndex].unk04;
            effect->data.aura->renderYaw = part->yaw;
            break;
    }
}

void func_8025DD40(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->effect[decorationIndex]->data.aura->fadeTime = 5;
}

void func_8025DD60(ActorPart* part, s32 decorationIndex) {
    DecorationTable* decor = part->decorationTable;
    EnergyInOutFXData* data;
    f32 scale;

    switch (decor->state[decorationIndex]) {
        case 0:
            decor->effect[decorationIndex] = fx_energy_in_out(4, part->currentPos.x, part->currentPos.y, part->currentPos.z, 1.2f, 0);
            decor->state[decorationIndex] = 1;
            decor->unk_8C6[decorationIndex].unk00 = 0x78;
            decor->unk_8C6[decorationIndex].unk02 = 0;
            // fallthrough
        case 1:
            data = decor->effect[decorationIndex]->data.energyInOut;
            scale = decor->unk_8C6[decorationIndex].unk00;
            scale /= 100.0f;
            data->unk_44 = scale;
            data->pos.x = part->currentPos.x;
            data->pos.y = (part->currentPos.y + (scale * 41.0f));
            data->pos.z = (part->currentPos.z + decor->unk_8C6[decorationIndex].unk02);
            break;
    }
}

void func_8025DE88(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->effect[decorationIndex]->flags |= 0x10;
}
