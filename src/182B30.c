#include "common.h"
#include "sprite.h"
#include "effects.h"
#include "battle/battle.h"
#include "sprite/npc/BattleWatt.h"

enum StandardPalettes {
    STANDARD_PAL_POISON     = 1,
    STANDARD_PAL_DIZZY      = 2,
    STANDARD_PAL_STATIC     = 3,
};

#define UNPACK_PAL_R(color) (((color) >> 11) & 0x1F)
#define UNPACK_PAL_G(color) (((color) >> 6) & 0x1F)
#define UNPACK_PAL_B(color) (((color) >> 1) & 0x1F)
#define UNPACK_PAL_A(color) ((color) & 1)

#define PACK_PAL_RGBA(r, g, b, a) (((r) << 11) | ((g) << 6) | ((b) << 1) | (a));

// lerp from A to B as alpha does from 0 to 255
#define LERP_COMPONENT(a, b, alpha) ((a) * (255 - (alpha)) + (b) * (alpha)) / 255;

#define PAL_ANIM_END 0xFF

enum PalSwapState {
    PAL_SWAP_HOLD_A     = 0,
    PAL_SWAP_A_TO_B     = 1,
    PAL_SWAP_HOLD_B     = 2,
    PAL_SWAP_B_TO_A     = 3,
};

// palette types for static palette animation
enum {
    STATIC_DEFAULT   = 0,
    STATIC_BRIGHT    = 1,
    STATIC_DARK      = 2,
};

// animated palettes for electrified sprites
// each pair gives { mode, duration }
u8 StaticPalettesAnim[] = {
    STATIC_DEFAULT,  32,
    STATIC_BRIGHT,    4,
    STATIC_DARK,      2,
    STATIC_DEFAULT,  16,
    STATIC_BRIGHT,    2,
    STATIC_DEFAULT,  64,
    STATIC_BRIGHT,    2,
    STATIC_DARK,      2,
    STATIC_DEFAULT,  28,
    STATIC_BRIGHT,    2,
    STATIC_DEFAULT,  18,
    STATIC_BRIGHT,    4,
    STATIC_DEFAULT,  16,
    STATIC_BRIGHT,    2,
    STATIC_DEFAULT,  80,
    STATIC_BRIGHT,    2,
    STATIC_DEFAULT,  16,
    STATIC_DARK,      2,
    STATIC_BRIGHT,    2,
    STATIC_DEFAULT,  32,
    STATIC_BRIGHT,    2,
    STATIC_DEFAULT,  14,
    STATIC_BRIGHT,    2,
    STATIC_DARK,      2,
    PAL_ANIM_END
};

s16 FearPaletteAnimXOffsets[] = { -2, 2, 0, 0, -2, 2, 0, 0, 0, 0, -2, 2, 0, 0, 0, 0, 0, 0, PAL_ANIM_END };

s16 ParalyzePaletteAnimXOffsets[] = { -2, 2, 0, 0, -2, 2, 0, 0, 0, 0, -2, 2, 0, 0, 0, 0, 0, 0, PAL_ANIM_END };

// palette types for watt palette animations
enum {
    WATT_DEFAULT   = 0,
    WATT_BRIGHTEST = 1,
    WATT_BRIGHTER  = 2,
};

// animated palettes for Watt
// each pair gives { mode, duration }
u8 WattIdlePalettesAnim[] = {
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,    52,
    WATT_BRIGHTEST,   4,
    WATT_DEFAULT,    54,
    WATT_DEFAULT,    54,
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,    28,
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,     6,
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,    44,
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,    44,
    PAL_ANIM_END
};

u8 WattAttackPalettesAnim[] = {
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,    10,
    WATT_BRIGHTER,    4,
    WATT_DEFAULT,    14,
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,    10,
    WATT_BRIGHTER,    4,
    WATT_DEFAULT,     4,
    PAL_ANIM_END
};

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
s32 get_npc_anim_for_status(u32*, s32);
void set_actor_pal_adjustment(Actor* actor, s32 arg1);
void create_status_icon_boost_hammer(s32 iconID);
void create_status_icon_boost_jump(s32 iconID);
void create_status_icon_peril(s32 iconID);
void create_status_icon_danger(s32 iconID);
void set_status_icons_offset(s32 iconID, s32 offsetY, s32 arg2);
void set_status_icons_properties(s32 iconID, f32 x, f32 y, f32 z, s32 arg, s32 arg2, s32 radius, s32 offsetY);

void appendGfx_npc_actor_reflection(s32, Actor*);
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

void render_without_adjusted_palettes(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_sleep_palettes(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_static_palettes(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_fear_palettes(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_poison_palettes(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_paralyze_palettes(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_berserk_palettes(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_watt_idle_palettes(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_watt_attack_palettes(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_player_debuff_palettes(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation, s32 isPoison);
void render_with_pal_blending(s32 arg0, ActorPart* part, s32 yaw, s32 arg3, Matrix4f mtx, s32 skipAnimation);
void render_with_palset_blending(s32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
s32 func_8025C840(s32 arg0, ActorPart* part, s32 yaw, s32);
s32 func_8025CCC8(s32 arg0, ActorPart* part, s32 yaw, s32);
s32 get_player_anim_for_status(s32 animID);
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
                decorationTable->posX[j] = partsTable->curPos.x;
                decorationTable->posY[j] = partsTable->curPos.y;
                decorationTable->posZ[j] = partsTable->curPos.z;
                decorationTable->yaw[j] = actor->yaw;
                decorationTable->rotPivotOffsetX[j] = (s32)(actor->rotPivotOffset.x * actor->scalingFactor);
                decorationTable->rotPivotOffsetY[j] = (s32)(actor->rotPivotOffset.y * actor->scalingFactor);

                decorationTable->rotX[j] = clamp_angle(actor->rot.x) * 0.5f;
                decorationTable->rotY[j] = clamp_angle(actor->rot.y) * 0.5f;
                decorationTable->rotZ[j] = clamp_angle(actor->rot.z) * 0.5f;
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
        decorationTable->posX[i] = partsTable->curPos.x;
        decorationTable->posY[i] = partsTable->curPos.y;
        decorationTable->posZ[i] = partsTable->curPos.z;
        decorationTable->yaw[i] = playerActor->yaw;
        decorationTable->rotPivotOffsetX[i] = playerActor->rotPivotOffset.x * playerActor->scalingFactor;
        decorationTable->rotPivotOffsetY[i] = playerActor->rotPivotOffset.y * playerActor->scalingFactor;

        decorationTable->rotX[i] = clamp_angle(playerActor->rot.x) * 0.5f;
        decorationTable->rotY[i] = clamp_angle(playerActor->rot.y) * 0.5f;
        decorationTable->rotZ[i] = clamp_angle(playerActor->rot.z) * 0.5f;
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

        decorationTable->posX[i] = partsTable->curPos.x;
        decorationTable->posY[i] = partsTable->curPos.y;
        decorationTable->posZ[i] = partsTable->curPos.z;
        decorationTable->yaw[i] = actor->yaw;

        decorationTable->rotPivotOffsetX[i] = actor->rotPivotOffset.x * actor->scalingFactor;
        decorationTable->rotPivotOffsetY[i] = actor->rotPivotOffset.y * actor->scalingFactor;

        decorationTable->rotX[i] = clamp_angle(actor->rot.x) * 0.5f;
        decorationTable->rotY[i] = clamp_angle(actor->rot.y) * 0.5f;
        decorationTable->rotZ[i] = clamp_angle(actor->rot.z) * 0.5f;

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

                pivotOffsetX = decorationTable->rotPivotOffsetX[bufPos];
                pivotOffsetY = decorationTable->rotPivotOffsetY[bufPos];

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
                render_with_adjusted_palettes(SPRITE_MODE_PLAYER, partTable, clamp_angle(yaw + 180), mtxTransform, 1);
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

            decorationTable->posX[j] = partsTable->curPos.x;
            decorationTable->posY[j] = partsTable->curPos.y;
            decorationTable->posZ[j] = partsTable->curPos.z;
            decorationTable->yaw[j] = actor->yaw;

            decorationTable->rotPivotOffsetX[j] = actor->rotPivotOffset.x;
            decorationTable->rotPivotOffsetY[j] = actor->rotPivotOffset.y;

            decorationTable->rotX[j] = clamp_angle(actor->rot.x) * 0.5f;
            decorationTable->rotY[j] = clamp_angle(actor->rot.y) * 0.5f;
            decorationTable->rotZ[j] = clamp_angle(actor->rot.z) * 0.5f;

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

    guRotateF(mtxRotX, actor->rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(mtxRotY, actor->rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(mtxRotZ, actor->rot.z, 0.0f, 0.0f, 1.0f);
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

            pivotX = decorationTable->rotPivotOffsetX[j];
            pivotY = decorationTable->rotPivotOffsetY[j];

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
            x1 = actor->curPos.x + actor->headOffset.x;
            if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                y1 = actor->curPos.y + actor->headOffset.y;
            } else {
                y1 = actor->curPos.y - actor->headOffset.y;
            }
            z1 = actor->curPos.z + actor->headOffset.z;
            numParts = actor->numParts;
            actorPart = actor->partsTable;

            for (i = 0; i < numParts; i++) {
                if (!(actorPart->flags & ACTOR_PART_FLAG_INVISIBLE) && actorPart->idleAnimations != NULL) {
                    spriteID = actorPart->spriteInstanceID;
                    if (spriteID >= 0) {
                        spr_update_sprite(spriteID, actorPart->curAnimation, actorPart->animationRate);
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
                        x2 = actorPart->absolutePos.x + actorPart->visualOffset.x;
                        y2 = actorPart->absolutePos.y + actorPart->visualOffset.y;
                        z2 = actorPart->absolutePos.z + actorPart->visualOffset.z;
                        yaw = actorPart->yaw;
                    }
                    actorPart->curPos.x = x2;
                    actorPart->curPos.y = y2;
                    actorPart->curPos.z = z2;

                    if (!(actorPart->flags & ACTOR_PART_FLAG_4)) {
                        shadow = get_shadow_by_index(actorPart->shadowIndex);
                        shadow->flags &= ~ENTITY_FLAG_HIDDEN;
                        x1 = actorPart->curPos.x;
                        if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                            y1 = actorPart->curPos.y + 12.0;
                        } else {
                            y1 = actorPart->curPos.y - 12.0;
                        }
                        z1 = actorPart->curPos.z;

                        dist = 32767.0f;
                        npc_raycast_down_sides(0, &x1, &y1, &z1, &dist);

                        if (200.0f < dist) {
                            shadow->flags |= ENTITY_FLAG_HIDDEN;
                        }
                        shadow->pos.x = x1;
                        shadow->pos.y = y1;
                        shadow->pos.z = z1;
                        shadow->rot.y = clamp_angle(yaw - camera->curYaw);
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

            x1 = actor->curPos.x + actor->headOffset.x;
            if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                y1 = actor->curPos.y + actor->headOffset.y + 12.0;
            } else {
                y1 = actor->curPos.y - actor->headOffset.y + 12.0;
            }
            z1 = actor->curPos.z + actor->headOffset.z;

            dist = 32767.0f;
            npc_raycast_down_sides(0, &x1, &y1, &z1, &dist);

            if (200.0f < dist) {
                shadow->flags |= ENTITY_FLAG_HIDDEN;
            }
            shadow->pos.x = x1;
            shadow->pos.y = y1;
            shadow->pos.z = z1 + bActorOffsets[actor->actorType].shadow;
            shadow->rot.y = clamp_angle(actor->yaw - camera->curYaw);
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
    s32 palChanged;
    s32 decorChanged;
    s32 i;

    if (!isPartner) {
        actor = battleStatus->enemyActors[actorIndex];
    } else {
        actor = battleStatus->partnerActor;
    }
    actorPosX = actor->curPos.x + actor->headOffset.x;
    if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        actorPosY = actor->curPos.y + actor->headOffset.y + actor->verticalRenderOffset;
    } else {
        actorPosY = actor->curPos.y - actor->headOffset.y + actor->verticalRenderOffset;
    }
    actorPosZ = actor->curPos.z + actor->headOffset.z;

    actor->disableEffect->data.disableX->pos.x = actorPosX +
        (actor->actorBlueprint->statusIconOffset.x + actor->statusIconOffset.x) * actor->scalingFactor;
    actor->disableEffect->data.disableX->pos.y = actorPosY +
        (actor->actorBlueprint->statusIconOffset.y + actor->statusIconOffset.y) * actor->scalingFactor;
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
    if (actor->debuff == STATUS_KEY_FROZEN) {
        effect = actor->icePillarEffect;
        if (actor->icePillarEffect != NULL) {
            if ((gBattleStatus.flags1 & BS_FLAGS1_SHOW_PLAYER_DECORATIONS) ||
                (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (actor->flags & ACTOR_FLAG_8000000)))
            {
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
            effect->flags |= FX_INSTANCE_FLAG_DISMISS;
            actor->icePillarEffect = NULL;
        }
    }
    set_status_icons_properties(actor->hudElementDataIndex, actorPosX, actorPosY, actorPosZ,
        (actor->actorBlueprint->statusIconOffset.x + actor->statusIconOffset.x) * actor->scalingFactor,
        (actor->actorBlueprint->statusIconOffset.y + actor->statusIconOffset.y) * actor->scalingFactor,
        (actor->actorBlueprint->statusTextOffset.x + actor->statusTextOffset.x) * actor->scalingFactor,
        (actor->actorBlueprint->statusTextOffset.y + actor->statusTextOffset.y) * actor->scalingFactor);

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
        if (actor->debuff == STATUS_KEY_SHRINK) {
            actor->scalingFactor += ((0.4 - actor->scalingFactor) / 6.0);
        } else {
            actor->scalingFactor += ((1.0 - actor->scalingFactor) / 6.0);
        }
    } while (0); // required to match

    if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        guTranslateF(mtxPivotOn,
            -actor->rotPivotOffset.x * actor->scalingFactor,
            -actor->rotPivotOffset.y * actor->scalingFactor,
            -actor->rotPivotOffset.z * actor->scalingFactor);
        guTranslateF(mtxPivotOff,
            actor->rotPivotOffset.x * actor->scalingFactor,
            actor->rotPivotOffset.y * actor->scalingFactor,
            actor->rotPivotOffset.z * actor->scalingFactor);
    } else {
        guTranslateF(mtxPivotOn,
            -actor->rotPivotOffset.x * actor->scalingFactor,
             actor->rotPivotOffset.y * actor->scalingFactor,
            -actor->rotPivotOffset.z * actor->scalingFactor);
        guTranslateF(mtxPivotOff,
             actor->rotPivotOffset.x * actor->scalingFactor,
            -actor->rotPivotOffset.y * actor->scalingFactor,
             actor->rotPivotOffset.z * actor->scalingFactor);
    }
    guRotateF(mtxRotX, actor->rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(mtxRotY, actor->rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(mtxRotZ, actor->rot.z, 0.0f, 0.0f, 1.0f);
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
            partPosX = part->absolutePos.x + part->visualOffset.x;
            partPosY = part->absolutePos.y + part->visualOffset.y;
            partPosZ = part->absolutePos.z + part->visualOffset.z;
            guScaleF(mtxPartScale,
                actor->scale.x * SPRITE_WORLD_SCALE_D,
                actor->scale.y * SPRITE_WORLD_SCALE_D,
                actor->scale.z * SPRITE_WORLD_SCALE_D);
            partYaw = part->yaw;
        }
        part->curPos.x = partPosX;
        part->curPos.y = partPosY;
        part->curPos.z = partPosZ;

        if (part->flags & ACTOR_PART_FLAG_INVISIBLE) {
            part = part->nextPart;
            continue;
        }
        if (part->idleAnimations == NULL) {
            part = part->nextPart;
            continue;
        }

        if (actor->transparentStatus == STATUS_KEY_TRANSPARENT) {
            part->flags |= ACTOR_PART_FLAG_100;
        } else {
            part->flags &= ~ACTOR_PART_FLAG_100;
        }

        do {
            lastAnim = part->curAnimation;
            animChanged = FALSE;
            palChanged = FALSE;
            decorChanged = FALSE;
        } while (0); // required to match

        if (isPartner) {
            if ((gBattleStatus.flags2 & (BS_FLAGS2_10 | BS_FLAGS2_4)) == BS_FLAGS2_4) {
                do {
                    if (actor->koStatus == 0) {
                        part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_INACTIVE);
                        spr_update_sprite(part->spriteInstanceID, part->curAnimation, part->animationRate);
                        animChanged = TRUE;
                    }
                } while (0); // required to match
                set_actor_pal_adjustment(actor, PAL_ADJUST_PLAYER_DEBUFF);
                palChanged = TRUE;
                func_80266EE8(actor, UNK_PAL_EFFECT_0);
                decorChanged = TRUE;
            }
            if (isPartner && (gPlayerData.curPartner == PARTNER_WATT)) {
                if (!palChanged) {
                    set_actor_pal_adjustment(actor, PAL_ADJUST_WATT_IDLE);
                }
                palChanged = TRUE;
            }
        }
        if (actor->isGlowing) {
            if (!decorChanged) {
                func_80266EE8(actor, UNK_PAL_EFFECT_11);
            }
            decorChanged = TRUE;
        }
        if (actor->debuff == STATUS_KEY_POISON) {
            if (!palChanged) {
                set_actor_pal_adjustment(actor, PAL_ADJUST_POISON);
            }
            palChanged = TRUE;
        }
        if (actor->debuff == STATUS_KEY_PARALYZE) {
            if (!palChanged) {
                set_actor_pal_adjustment(actor, PAL_ADJUST_PARALYZE);
            }
            palChanged = TRUE;
        }
        if (actor->debuff == STATUS_KEY_FEAR) {
            if (!palChanged) {
                set_actor_pal_adjustment(actor, PAL_ADJUST_FEAR);
            }
            palChanged = TRUE;
        }
        if (actor->staticStatus == STATUS_KEY_STATIC) {
            if (!palChanged) {
                set_actor_pal_adjustment(actor, PAL_ADJUST_STATIC);
            }
            palChanged = TRUE;
        }
        if ((!palChanged) && !(part->flags & ACTOR_PART_FLAG_1000000)) {
            set_actor_pal_adjustment(actor, PAL_ADJUST_NONE);
        }
        if ((!decorChanged) && !(part->flags & ACTOR_PART_FLAG_1000000)) {
            func_80266EE8(actor, UNK_PAL_EFFECT_0);
        }
        if (actor->flags & ACTOR_FLAG_4000000) {
            if (!(part->flags & ACTOR_PART_FLAG_20000000)) {
                if (actor->debuff == STATUS_KEY_FROZEN) {
                    if (!animChanged) {
                        part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_FROZEN);
                        animChanged = TRUE;
                    }
                } else if (actor->debuff != STATUS_KEY_SHRINK) {
                    if (actor->debuff == STATUS_KEY_POISON) {
                        if (!animChanged) {
                            part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_POISON);
                            animChanged = TRUE;
                        }
                    } else if (actor->debuff == STATUS_KEY_DIZZY) {
                        if (!animChanged) {
                            part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_DIZZY);
                            animChanged = TRUE;
                        }
                    } else if (actor->debuff == STATUS_KEY_FEAR) {
                        if (!animChanged) {
                            part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_FEAR);
                            animChanged = TRUE;
                        }
                    } else if (actor->debuff == STATUS_KEY_SLEEP) {
                        if (!animChanged) {
                            part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_SLEEP);
                            animChanged = TRUE;
                        }
                    } else if (actor->debuff == STATUS_KEY_PARALYZE) {
                        if (!animChanged) {
                            part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_PARALYZE);
                            animChanged = TRUE;
                        }
                    }
                }

                if (actor->staticStatus == STATUS_KEY_STATIC) {
                    if (!animChanged) {
                        part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_STATIC);
                        animChanged = TRUE;
                    }

                    do {} while (0); // required to match
                }
                if (!animChanged) {
                    part->curAnimation = get_npc_anim_for_status(part->idleAnimations, 1);
                }

                if (isPartner) {
                    if (actor->koStatus == STATUS_KEY_DAZE) {
                        part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_DAZE);
                        animChanged = TRUE;
                    } else {
                        s32 temp = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_NORMAL);
                        do {
                            if (temp == get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_DAZE)) {
                                part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_NORMAL);
                            }
                        } while (0); // required to match
                    }
                }
                if (actor->debuff == STATUS_KEY_STOP) {
                    part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_STOP);
                    create_status_debuff(actor->hudElementDataIndex, STATUS_KEY_STOP);
                } else if (!animChanged) {
                    s32 temp = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_NORMAL);
                    do {
                        if (temp == get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_STOP)) {
                            part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_NORMAL);
                        }
                    } while (0); // required to match
                }
            }
        }

        if (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (actor->flags & ACTOR_FLAG_8000000)) {
            do {
                if (actor->debuff == STATUS_KEY_POISON) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_KEY_POISON);
                } else if (actor->debuff == STATUS_KEY_DIZZY) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_KEY_DIZZY);
                } else if (actor->debuff == STATUS_KEY_SLEEP) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_KEY_SLEEP);
                } else if (actor->debuff == STATUS_KEY_PARALYZE) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_KEY_PARALYZE);
                } else if (actor->debuff == STATUS_KEY_SHRINK) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_KEY_SHRINK);
                } else if (actor->debuff == STATUS_KEY_FROZEN) {
                    create_status_debuff(actor->hudElementDataIndex, STATUS_KEY_FROZEN);
                }
            } while (0); // required to match

            if (actor->staticStatus == STATUS_KEY_STATIC) {
                create_status_static(actor->hudElementDataIndex, STATUS_KEY_STATIC);
            }
            if ((actor->transparentStatus == STATUS_KEY_TRANSPARENT) || (part->flags & ACTOR_PART_FLAG_100)) {
                create_status_transparent(actor->hudElementDataIndex, STATUS_KEY_TRANSPARENT);
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
            if (lastAnim != part->curAnimation) {
                spr_update_sprite(part->spriteInstanceID, part->curAnimation, part->animationRate);
                part->animNotifyValue = spr_get_notify_value(part->spriteInstanceID);
            }
        }
        if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
            guTranslateF(mtxPivotOn,
                -part->rotPivotOffset.x * actor->scalingFactor,
                -part->rotPivotOffset.y * actor->scalingFactor,
                -part->rotPivotOffset.z * actor->scalingFactor);
            guTranslateF(mtxPivotOff,
                part->rotPivotOffset.x * actor->scalingFactor,
                part->rotPivotOffset.y * actor->scalingFactor,
                part->rotPivotOffset.z * actor->scalingFactor);
        } else {
            guTranslateF(mtxPivotOn,
                -part->rotPivotOffset.x * actor->scalingFactor,
                 part->rotPivotOffset.y * actor->scalingFactor,
                -part->rotPivotOffset.z * actor->scalingFactor);
            guTranslateF(mtxPivotOff,
                 part->rotPivotOffset.x * actor->scalingFactor,
                -part->rotPivotOffset.y * actor->scalingFactor,
                 part->rotPivotOffset.z * actor->scalingFactor);
        }
        guTranslateF(mtxTranslate,
            partPosX + part->palAnimPosOffset[0],
            partPosY + part->palAnimPosOffset[1],
            partPosZ);
        guRotateF(mtxRotX, part->rot.x, 1.0f, 0.0f, 0.0f);
        guRotateF(mtxRotY, part->rot.y, 0.0f, 1.0f, 0.0f);
        guRotateF(mtxRotZ, part->rot.z, 0.0f, 0.0f, 1.0f);
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

        part->curPos.x = partPosX + part->palAnimPosOffset[0];
        part->curPos.y = partPosY + part->palAnimPosOffset[1];
        part->curPos.z = partPosZ;

        if (part->spriteInstanceID >= 0) {
            if (!isPartner) {
                func_8025C840(1, part, partYaw, 0);
                func_8025CCC8(1, part, partYaw, 0);
                render_with_adjusted_palettes(SPRITE_MODE_NPC, part, partYaw, mtxTransform, 0);
            } else {
                func_8025C840(1, part, clamp_angle(180.0f - partYaw), 0);
                func_8025CCC8(1, part, clamp_angle(180.0f - partYaw), 0);
                render_with_adjusted_palettes(SPRITE_MODE_NPC, part, clamp_angle(180.0f - partYaw), mtxTransform, 0);
            }

            _add_part_decoration(part);
        }

        part = part->nextPart;
    }
}

void appendGfx_npc_actor_reflection(s32 flipYaw, Actor* actor) {
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

    actorPosX = actor->curPos.x + actor->headOffset.x;
    if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        actorPosY = actor->curPos.y + actor->headOffset.y;
    } else {
        actorPosY = actor->curPos.y - actor->headOffset.y;
    }
    actorPosZ = actor->curPos.z + actor->headOffset.z - 5.0f;

    if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        guTranslateF(mtxPivotOn,
            -actor->rotPivotOffset.x * actor->scalingFactor,
            -actor->rotPivotOffset.y * actor->scalingFactor,
            -actor->rotPivotOffset.z * actor->scalingFactor);
         guTranslateF(mtxPivotOff,
             actor->rotPivotOffset.x * actor->scalingFactor,
             actor->rotPivotOffset.y * actor->scalingFactor,
             actor->rotPivotOffset.z * actor->scalingFactor);
    } else {
        guTranslateF(mtxPivotOn,
            -actor->rotPivotOffset.x * actor->scalingFactor,
             actor->rotPivotOffset.y * actor->scalingFactor,
            -actor->rotPivotOffset.z * actor->scalingFactor);
         guTranslateF(mtxPivotOff,
             actor->rotPivotOffset.x * actor->scalingFactor,
             -actor->rotPivotOffset.y * actor->scalingFactor,
             actor->rotPivotOffset.z * actor->scalingFactor);
    }

    guRotateF(mtxRotX, actor->rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(mtxRotY, actor->rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(mtxRotZ, actor->rot.z, 0.0f, 0.0f, 1.0f);
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
            partPosX = part->absolutePos.x + part->visualOffset.x;
            partPosY = part->absolutePos.y + part->visualOffset.y;
            partPosZ = part->absolutePos.z + part->visualOffset.z;
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
                -part->rotPivotOffset.x * actor->scalingFactor,
                -part->rotPivotOffset.y * actor->scalingFactor,
                -part->rotPivotOffset.z * actor->scalingFactor);
            guTranslateF(mtxPivotOff,
                 part->rotPivotOffset.x * actor->scalingFactor,
                 part->rotPivotOffset.y * actor->scalingFactor,
                 part->rotPivotOffset.z * actor->scalingFactor);
        } else {
            guTranslateF(mtxPivotOn,
                -part->rotPivotOffset.x * actor->scalingFactor,
                 part->rotPivotOffset.y * actor->scalingFactor,
                -part->rotPivotOffset.z * actor->scalingFactor);
            guTranslateF(mtxPivotOff,
                 part->rotPivotOffset.x * actor->scalingFactor,
                -part->rotPivotOffset.y * actor->scalingFactor,
                 part->rotPivotOffset.z * actor->scalingFactor);
        }
        guTranslateF(mtxTranslate,
            partPosX + part->palAnimPosOffset[0],
            partPosY + part->palAnimPosOffset[1],
            partPosZ - 1.0f);

        guRotateF(mtxRotX, part->rot.x, 1.0f, 0.0f, 0.0f);
        guRotateF(mtxRotY, part->rot.y, 0.0f, 1.0f, 0.0f);
        guRotateF(mtxRotZ, part->rot.z, 0.0f, 0.0f, 1.0f);
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
            render_with_adjusted_palettes(SPRITE_MODE_NPC, part, partYaw, mtxTransform, 1);
        } else {
            func_8025C840(1, part, clamp_angle(partYaw + 180.0f), 1);
            func_8025CCC8(1, part, clamp_angle(partYaw + 180.0f), 1);
            render_with_adjusted_palettes(SPRITE_MODE_NPC, part, clamp_angle(partYaw + 180.0f), mtxTransform, 1);
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

    appendGfx_npc_actor_reflection(0, actor);
}

void appendGfx_partner_actor_reflection(void* data) {
    appendGfx_npc_actor_reflection(1, gBattleStatus.partnerActor);
}

void update_player_actor_shadow(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Camera* camera = &gCameras[CAM_BATTLE];
    Actor* player = battleStatus->playerActor;
    ActorPart* parts = player->partsTable;
    Shadow* shadow;
    f32 x, y, z, distance;

    parts->animNotifyValue = spr_update_player_sprite(PLAYER_SPRITE_MAIN, parts->curAnimation, parts->animationRate);

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
    x = player->curPos.x + player->headOffset.x;
    z = player->curPos.z + player->headOffset.z;
    y = player->curPos.y + player->headOffset.y + 12.0;
    npc_raycast_down_sides(0, &x, &y, &z, &distance);

    if (distance > 200.0f) {
        shadow->flags |= ENTITY_FLAG_HIDDEN;
    }
    shadow->pos.x = x;
    shadow->pos.y = y;
    shadow->pos.z = z;
    shadow->rot.y = clamp_angle(player->yaw - camera->curYaw);
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
    s32 animChanged, palChanged, cond3, cond4;
    u32 lastAnim;

    player = battleStatus->playerActor;
    partner = battleStatus->partnerActor;
    playerParts = player->partsTable;

    playerPosX = player->curPos.x + player->headOffset.x;
    playerPosY = player->curPos.y + player->headOffset.y + player->verticalRenderOffset;
    playerPosZ = player->curPos.z + player->headOffset.z;

    playerYaw = playerParts->yaw = player->yaw;

    player->disableEffect->data.disableX->pos.x = playerPosX +
        (player->actorBlueprint->statusIconOffset.x + player->statusIconOffset.x) * player->scalingFactor;
    player->disableEffect->data.disableX->pos.y = playerPosY +
        (player->actorBlueprint->statusIconOffset.y + player->statusIconOffset.y) * player->scalingFactor;
    player->disableEffect->data.disableX->pos.z = playerPosZ;

    if (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_8000000)) {
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
        if ((gBattleStatus.flags1 & BS_FLAGS1_SHOW_PLAYER_DECORATIONS) ||
            (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_8000000)))
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
        if ((gBattleStatus.flags1 & BS_FLAGS1_SHOW_PLAYER_DECORATIONS) ||
            (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_8000000)))
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
    if (player->debuff == STATUS_KEY_FROZEN) {
        effect = player->icePillarEffect;
        if (player->icePillarEffect != NULL) {
            if ((gBattleStatus.flags1 & BS_FLAGS1_SHOW_PLAYER_DECORATIONS) ||
                (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_8000000)))
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
            effect->flags |= FX_INSTANCE_FLAG_DISMISS;
            player->icePillarEffect = NULL;
        }
    }

    if (!(gBattleStatus.flags2 & BS_FLAGS2_10000) && !(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_8000000)) {
        battleStatus->buffEffect->data.partnerBuff->unk_02 = 1;
    } else {
        battleStatus->buffEffect->data.partnerBuff->unk_02 = 0;
    }

    do {
        if (player->debuff == STATUS_KEY_SHRINK) {
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
        if (playerData->curHP > PERIL_THRESHOLD) {
            remove_status_icon_peril(player->hudElementDataIndex);
            do {
                if (playerData->curHP <= DANGER_THRESHOLD) {
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

    if (player->transparentStatus == STATUS_KEY_TRANSPARENT) {
        playerParts->flags |= ACTOR_PART_FLAG_100;

        if (FALSE) { // TODO required to match - also whyyyyyy compiler, whyyyyy
    back:
            playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_STOP);
            create_status_debuff(player->hudElementDataIndex, STATUS_KEY_STOP);
            goto end;
        }
    } else {
        playerParts->flags &= ~ACTOR_PART_FLAG_100;
    }

    do {
        animChanged = FALSE;
        palChanged = FALSE;
        cond3 = FALSE;
        cond4 = FALSE;
        lastAnim = playerParts->curAnimation;
    } while (0); // required to match

    if (((((gBattleStatus.flags2 & (BS_FLAGS2_8 | BS_FLAGS2_2)) == BS_FLAGS2_2) && (partner != NULL)) || (battleStatus->outtaSightActive > 0))
        && !(player->flags & ACTOR_FLAG_20000000)
        && ((partner == NULL) || !(partner->flags & ACTOR_FLAG_NO_ATTACK)))
    {
        if (!(gBattleStatus.flags2 & BS_FLAGS2_100000)) {
            if ((player->debuff != STATUS_KEY_FEAR)
                && (player->debuff != STATUS_KEY_PARALYZE)
                && (player->debuff != STATUS_KEY_FROZEN)
                && (player->debuff != STATUS_KEY_STOP)
            ) {
                if ((player->transparentStatus != STATUS_KEY_TRANSPARENT) &&
                    (player->stoneStatus != STATUS_KEY_STONE) &&
                    ((battleStatus->outtaSightActive > 0) || (gBattleStatus.flags2 & BS_FLAGS2_2)))
                {
                    if (is_ability_active(ABILITY_BERSERKER)) {
                        playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_INACTIVE_BERSERK);
                    } else  if (player->debuff == STATUS_KEY_SLEEP) {
                        playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_INACTIVE_SLEEP);
                    } else if (player->debuff == STATUS_KEY_DIZZY) {
                        playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_INACTIVE_DIZZY);
                    } else {
                        playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_INACTIVE);
                    }
                    spr_update_player_sprite(PLAYER_SPRITE_MAIN, playerParts->curAnimation, playerParts->animationRate);
                    animChanged = TRUE;
                }
            }

            if (player->debuff != STATUS_KEY_POISON) {
                set_actor_pal_adjustment(player, PAL_ADJUST_PLAYER_DEBUFF);
            } else {
                set_actor_pal_adjustment(player, PAL_ADJUST_PLAYER_POISON);
            }
            palChanged = TRUE;

            func_80266EE8(player, UNK_PAL_EFFECT_0);
            cond3 = TRUE;
        }
    }

    if (player->stoneStatus == STATUS_KEY_STONE) {
        playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_STONE);
        spr_update_player_sprite(PLAYER_SPRITE_MAIN, playerParts->curAnimation, playerParts->animationRate);
        animChanged = TRUE;

        if (!palChanged) {
            set_actor_pal_adjustment(player, PAL_ADJUST_NONE);
        }
        func_80266EE8(player, UNK_PAL_EFFECT_0);
        palChanged = TRUE;
        enable_status_debuff(player->hudElementDataIndex);
        cond3 = TRUE;
        enable_status_2(player->hudElementDataIndex);
        cond4 = TRUE;

        enable_status_transparent(player->hudElementDataIndex);
        enable_status_chill_out(player->hudElementDataIndex);
    }

    if ((player->flags & ACTOR_FLAG_4000000) && !animChanged) {
        s32 temp = playerParts->curAnimation;
        if (temp == get_player_anim_for_status(STATUS_KEY_STONE)) {
            playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_NORMAL);
        }
    }

    if (is_ability_active(ABILITY_BERSERKER)) {
        if (!palChanged) {
            set_actor_pal_adjustment(player, PAL_ADJUST_BERSERK);
        }
        palChanged = TRUE;
    }
    if (player->debuff == STATUS_KEY_POISON) {
        if (!palChanged) {
            set_actor_pal_adjustment(player, PAL_ADJUST_POISON);
        }
        palChanged = TRUE;
    }
    if (player->debuff == STATUS_KEY_PARALYZE) {
        if (!palChanged) {
            set_actor_pal_adjustment(player, PAL_ADJUST_PARALYZE);
        }
        palChanged = TRUE;
    }
    if (player->staticStatus == STATUS_KEY_STATIC) {
        if (!palChanged) {
            set_actor_pal_adjustment(player, PAL_ADJUST_STATIC);
        }
        palChanged = TRUE;
    }
    if (battleStatus->turboChargeTurnsLeft != 0) {
        if (!cond3) {
            func_80266EE8(player, UNK_PAL_EFFECT_11);
        }
        cond3 = TRUE;
    }
    if (is_ability_active(ABILITY_ZAP_TAP)) {
        if (!palChanged) {
            set_actor_pal_adjustment(player, PAL_ADJUST_STATIC);
        }
        palChanged = TRUE;
    }
    if (!palChanged) {
        set_actor_pal_adjustment(player, PAL_ADJUST_NONE);
    }
    if (!cond3) {
        func_80266EE8(player, UNK_PAL_EFFECT_0);
    }
    if (player->flags & ACTOR_FLAG_4000000) {
        if (battleStatus->hustleTurns != 0) {
            playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_HUSTLE);
            animChanged = TRUE;
        } else if (!animChanged) {
            s32 temp = get_player_anim_for_status(STATUS_KEY_NORMAL);
            do {
                if (temp == get_player_anim_for_status(STATUS_KEY_HUSTLE)) {
                    playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_NORMAL);
                }
            } while (0); // required to match
        }

        do {
            if (player->debuff == STATUS_KEY_FROZEN) {
                if (!animChanged) {
                    playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_FROZEN);
                    animChanged = TRUE;
                }
            } else if (player->debuff != STATUS_KEY_SHRINK) {
                if (player->debuff == STATUS_KEY_POISON) {
                    if (!animChanged) {
                        playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_POISON);
                        animChanged = TRUE;
                    }
                } else if (player->debuff == STATUS_KEY_DIZZY) {
                    if (!animChanged) {
                        playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_DIZZY);
                        animChanged = TRUE;
                    }
                } else if (player->debuff == STATUS_KEY_SLEEP) {
                    if (!animChanged) {
                        playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_SLEEP);
                        animChanged = TRUE;
                    }
                } else if (player->debuff == STATUS_KEY_PARALYZE) {
                    if (!animChanged) {
                        playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_PARALYZE);
                        animChanged = TRUE;
                    }
                 } else {
                    if (player_team_is_ability_active(player, ABILITY_BERSERKER)) {
                        if (!animChanged) {
                            playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_BERSERK);
                            animChanged = TRUE;
                        }
                    }
                }
            }
            if (is_ability_active(ABILITY_ZAP_TAP)) {
                if (!animChanged) {
                    playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_STATIC);
                    animChanged = TRUE;
                }
                player->staticStatus = STATUS_KEY_STATIC;
                player->staticDuration = 127;
            } else if ((player->staticStatus == STATUS_KEY_STATIC) && !animChanged) {
                playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_STATIC);
                animChanged = TRUE;
            }
            if ((player->transparentStatus == STATUS_KEY_TRANSPARENT) || (playerParts->flags & ACTOR_PART_FLAG_100)) {
                if (!animChanged) {
                    playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_TRANSPARENT);
                    animChanged = TRUE;
                }
                create_status_transparent(player->hudElementDataIndex, STATUS_KEY_TRANSPARENT);
            }
            if (!animChanged) {
                playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_NORMAL);
            }
        } while (0); // needed to match
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_8000000)) {
        if (!cond4) {
            do {
                if (player->debuff == STATUS_KEY_POISON) {
                    create_status_debuff(player->hudElementDataIndex, STATUS_KEY_POISON);
                } else if (player->debuff == STATUS_KEY_SLEEP) {
                    create_status_debuff(player->hudElementDataIndex, STATUS_KEY_SLEEP);
                } else if (player->debuff == STATUS_KEY_PARALYZE) {
                    create_status_debuff(player->hudElementDataIndex, STATUS_KEY_PARALYZE);
                } else if (player->debuff == STATUS_KEY_DIZZY) {
                    create_status_debuff(player->hudElementDataIndex, STATUS_KEY_DIZZY);
                } else if (player->debuff == STATUS_KEY_SHRINK) {
                    create_status_debuff(player->hudElementDataIndex, STATUS_KEY_SHRINK);
                } else if (player->debuff == STATUS_KEY_FROZEN) {
                    create_status_debuff(player->hudElementDataIndex, STATUS_KEY_FROZEN);
                }
            } while (0); // required to match
            if (!cond4 && (is_ability_active(ABILITY_ZAP_TAP) || (player->staticStatus == STATUS_KEY_STATIC))) {
                create_status_static(player->hudElementDataIndex, STATUS_KEY_STATIC);
            }
        }
        if ((player->transparentStatus == STATUS_KEY_TRANSPARENT) || (playerParts->flags & ACTOR_PART_FLAG_100)) {
            create_status_transparent(player->hudElementDataIndex, STATUS_KEY_TRANSPARENT);
        }
    } else {
        enable_status_debuff(player->hudElementDataIndex);
        enable_status_2(player->hudElementDataIndex);
        enable_status_transparent(player->hudElementDataIndex);
        enable_status_chill_out(player->hudElementDataIndex);
    }

    if (player->debuff != STATUS_KEY_STOP) {
        if (!animChanged) {
            s32 temp = playerParts->curAnimation;
            if (temp == get_player_anim_for_status(STATUS_KEY_STOP)) {
                playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_NORMAL);
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
        player->actorBlueprint->statusTextOffset.x * player->scalingFactor,
        player->actorBlueprint->statusTextOffset.y * player->scalingFactor);
    set_status_icons_offset(player->hudElementDataIndex,
        player->size.y * player->scalingFactor,
        player->size.x * player->scalingFactor);

    playerPosX += playerParts->palAnimPosOffset[0];
    playerPosY += playerParts->palAnimPosOffset[1];

    playerParts->curPos.x = playerPosX;
    playerParts->curPos.y = playerPosY;
    playerParts->curPos.z = playerPosZ;
    guTranslateF(mtxTranslate, playerPosX, playerPosY, playerPosZ);

    guTranslateF(mtxPivotOn,
        -player->rotPivotOffset.x * player->scalingFactor,
        -player->rotPivotOffset.y * player->scalingFactor,
        -player->rotPivotOffset.z * player->scalingFactor);
    guTranslateF(mtxPivotOff,
        player->rotPivotOffset.x * player->scalingFactor,
        player->rotPivotOffset.y * player->scalingFactor,
        player->rotPivotOffset.z * player->scalingFactor);

    guRotateF(mtxRotX, player->rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(mtxRotY, player->rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(mtxRotZ, player->rot.z, 0.0f, 0.0f, 1.0f);
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

    if (lastAnim != playerParts->curAnimation) {
        spr_update_player_sprite(PLAYER_SPRITE_MAIN, playerParts->curAnimation, playerParts->animationRate);
    }
    func_8025C840(0, playerParts, clamp_angle(playerYaw + 180.0f), 0);
    func_8025CCC8(0, playerParts, clamp_angle(playerYaw + 180.0f), 0);
    render_with_adjusted_palettes(SPRITE_MODE_PLAYER, playerParts, clamp_angle(playerYaw + 180.0f), mtxTransform, 0);
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

    dx = player->curPos.x + player->headOffset.x;
    dx += part->palAnimPosOffset[0];
    dy = player->curPos.y + player->headOffset.y;
    dy += part->palAnimPosOffset[1];
    dz = player->curPos.z + player->headOffset.z - 5.0f;
    part->yaw = playerYaw;

    guTranslateF(mtxTranslate, dx, dy, dz - 1.0f);

    guTranslateF(mtxPivotOn,
        -player->rotPivotOffset.x * player->scalingFactor,
        -player->rotPivotOffset.y * player->scalingFactor,
        -player->rotPivotOffset.z * player->scalingFactor);
    guTranslateF(mtxPivotOff,
        player->rotPivotOffset.x * player->scalingFactor,
        player->rotPivotOffset.y * player->scalingFactor,
        player->rotPivotOffset.z * player->scalingFactor);

    guRotateF(mtxRotX, player->rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(mtxRotY, player->rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(mtxRotZ, player->rot.z, 0.0f, 0.0f, 1.0f);
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
    render_with_adjusted_palettes(SPRITE_MODE_PLAYER, part, clamp_angle(playerYaw + 180.0f), mtxTransform, TRUE);
}

s32 render_with_adjusted_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
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
            sprDrawOpts = DRAW_SPRITE_OVERRIDE_ALPHA;
            opacity = opacity * 120 / 255;
        }
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
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

    switch (part->decorationTable->paletteAdjustment) {
        case PAL_ADJUST_NONE:
            render_without_adjusted_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case PAL_ADJUST_SLEEP:
            render_with_sleep_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case PAL_ADJUST_STATIC:
            render_with_static_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case PAL_ADJUST_FEAR:
            render_with_fear_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case PAL_ADJUST_POISON:
            render_with_poison_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case PAL_ADJUST_PARALYZE:
            render_with_paralyze_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case PAL_ADJUST_BERSERK:
            render_with_berserk_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case PAL_ADJUST_WATT_IDLE:
            render_with_watt_idle_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case PAL_ADJUST_WATT_ATTACK:
            render_with_watt_attack_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case PAL_ADJUST_PLAYER_DEBUFF:
            render_with_player_debuff_palettes(isNpcSprite, part, yaw, mtx, skipAnimation, FALSE);
            break;
        case PAL_ADJUST_PLAYER_POISON:
            render_with_player_debuff_palettes(isNpcSprite, part, yaw, mtx, skipAnimation, TRUE);
            break;
        case PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS:
            render_with_pal_blending(isNpcSprite, part, yaw, FALSE, mtx, skipAnimation);
            break;
        case PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS:
            render_with_pal_blending(isNpcSprite, part, yaw, TRUE, mtx, skipAnimation);
            break;
        case PAL_ADJUST_BLEND_PALSETS:
            render_with_palset_blending(isNpcSprite, part, yaw, mtx, skipAnimation);
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

    for (i = 0; i < decor->originalPalettesCount; i++) {
        if (decor->adjustedPalettes[i] != NULL) {
            src = decor->adjustedPalettes[i];
            dest = decor->copiedPalettes[1][i];

            for (j = 0; j < SPR_PAL_SIZE; j++) {
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
        decor->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 0x10);
        decor->originalPalettesCount = 0;
        while (decor->originalPalettesList[decor->originalPalettesCount] != (PAL_PTR) -1) {
            decor->originalPalettesCount++;
        }

        for (i = 0; i < decor->originalPalettesCount; i++) {
            src = decor->originalPalettesList[i];
            dest = decor->copiedPalettes[0][i];
            if (src != NULL) {
                for (j = 0; j < ARRAY_COUNT(decor->copiedPalettes[0][i]); j++) {
                    *dest = *src;
                    src++;
                    dest++;
                }
            }
        }

        for (i = 0; i < decor->originalPalettesCount; i++) {
            decor->adjustedPalettes[i] = decor->copiedPalettes[0][i];
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
        spr_draw_npc_sprite(part->spriteInstanceID | DRAW_SPRITE_OVERRIDE_PALETTES | idMask, yaw, opacity, decorationTable->adjustedPalettes, mtx);
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
        decor->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
        decor->originalPalettesCount = 0;

        while (decor->originalPalettesList[decor->originalPalettesCount] != (PAL_PTR) -1) {
            decor->originalPalettesCount++;
        }

        for (i = 0; i < decor->originalPalettesCount; i++) {
            src = decor->originalPalettesList[i];
            dest = decor->copiedPalettes[0][i];
            if (decor->originalPalettesList[i] != NULL) {
                for (j = 0; j < ARRAY_COUNT(decor->copiedPalettes[0][i]); j++) {
                    *dest = *src;
                    dest++;
                    src++;
                }
            }
        }
        for (i = 0; i < decor->originalPalettesCount; i++) {
            decor->adjustedPalettes[i] = decor->copiedPalettes[0][i];
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
        spr_draw_player_sprite(PLAYER_SPRITE_MAIN | idMask, yaw, opacity, decorationTable->adjustedPalettes, mtx);
    }
}

void render_without_adjusted_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorationTable = part->decorationTable;

    if (decorationTable->resetPalAdjust) {
        part->verticalStretch = 1;
        part->palAnimPosOffset[0] = 0;
        part->palAnimPosOffset[1] = 0;
        decorationTable->resetPalAdjust = FALSE;
    }
    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_802597B0(part, yaw, mtx);
    } else {
        func_8025950C(part, yaw, mtx);
    }
}

void render_with_sleep_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorationTable = part->decorationTable;
    s32 i, j;

    if (decorationTable->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
        } else {
            decorationTable->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
        }
        decorationTable->palAnimState = 0;
        decorationTable->resetPalAdjust = FALSE;
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        PAL_PTR palIn = decorationTable->originalPalettesList[i];
        PAL_PTR palOut = decorationTable->copiedPalettes[0][i];
        decorationTable->adjustedPalettes[i] = palOut;
        if (palIn != NULL) {
            for (j = 0; j < SPR_PAL_SIZE; j++) {
                u8 r = UNPACK_PAL_R(*palIn);
                u8 g = UNPACK_PAL_G(*palIn);
                u8 b = UNPACK_PAL_B(*palIn);
                u8 a = UNPACK_PAL_A(*palIn);
                palIn++;

                // make colors darker and bluer
                r *= 0.2;
                g *= 0.4;
                b *= 0.7;

                *palOut++ = PACK_PAL_RGBA(r, g, b, a);
            }
        }
    }
    switch (decorationTable->palAnimState) {
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

void render_with_static_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorationTable = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;
    s32 paletteType;
    s32 staticPalIdx;

    if (decorationTable->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
        } else {
            decorationTable->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        for (i = 0; i < decorationTable->originalPalettesCount; i++) {
            palIn = decorationTable->originalPalettesList[i];
            palOut = decorationTable->copiedPalettes[0][i];
            if (palIn != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *palOut++ = *palIn++;
                }
            }
        }

        decorationTable->palAnimState = -2;
        decorationTable->palBlendAlpha = 0;
        decorationTable->resetPalAdjust = FALSE;
        decorationTable->nextPalTime = 0;
    }

    if (!skipAnimation) {
        if (decorationTable->nextPalTime == 0) {
            decorationTable->palAnimState += 2;
            if (StaticPalettesAnim[decorationTable->palAnimState] == PAL_ANIM_END) {
                decorationTable->palAnimState = 0;
            }
            decorationTable->nextPalTime = StaticPalettesAnim[decorationTable->palAnimState + 1] / 2;
        }
        paletteType = StaticPalettesAnim[decorationTable->palAnimState];
        decorationTable->nextPalTime--;
    } else {
        paletteType = StaticPalettesAnim[decorationTable->palAnimState];
    }

    switch (paletteType) {
        case STATIC_DEFAULT: // no change
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->originalPalettesList[i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case STATIC_BRIGHT: // bright yellow
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                staticPalIdx = decorationTable->spriteColorVariations * STANDARD_PAL_STATIC + i;
                palIn = decorationTable->originalPalettesList[staticPalIdx];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case STATIC_DARK: // darkened via code
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->originalPalettesList[i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        u8 r = UNPACK_PAL_R(*palIn);
                        u8 g = UNPACK_PAL_G(*palIn);
                        u8 b = UNPACK_PAL_B(*palIn);
                        u8 a = UNPACK_PAL_A(*palIn);
                        palIn++;

                        r *= 0.1;
                        g *= 0.1;
                        b *= 0.1;

                        *palOut++ = PACK_PAL_RGBA(r, g, b, a);
                    }
                }
            }
            break;
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        decorationTable->adjustedPalettes[i] = decorationTable->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }

    if (!skipAnimation) {
        decorationTable->palBlendAlpha--;
    }
}

void render_with_fear_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorationTable = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;
    s32 temp;

    if (decorationTable->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 2;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
        } else {
            decorationTable->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
        }

        decorationTable->palAnimState = 0;
        decorationTable->palBlendAlpha = 0;
        decorationTable->nextPalTime = 0;
        decorationTable->resetPalAdjust = FALSE;
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        palIn = decorationTable->originalPalettesList[i];
        palOut = decorationTable->copiedPalettes[0][i];
        decorationTable->adjustedPalettes[i] = palOut;
        if (palIn != NULL) {
            for (j = 0; j < SPR_PAL_SIZE; j++) {
                u8 r = UNPACK_PAL_R(*palIn);
                u8 g = UNPACK_PAL_G(*palIn);
                u8 b = UNPACK_PAL_B(*palIn);
                u8 a = UNPACK_PAL_A(*palIn);
                palIn++;

                // darken the color
                r /= 2;
                g /= 2;
                b /= 2;

                *palOut++ = PACK_PAL_RGBA(r, g, b, a);
            }
        }
    }

    if (decorationTable->nextPalTime <= 0) {
        part->palAnimPosOffset[0] = FearPaletteAnimXOffsets[abs(decorationTable->nextPalTime)];
        if (part->palAnimPosOffset[0] == PAL_ANIM_END) {
            part->palAnimPosOffset[0] = 0;
            // 30-90
            decorationTable->nextPalTime = rand_int(60) + 30;
        }
    }

    if (!skipAnimation) {
        decorationTable->nextPalTime--;
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }
}

void render_with_poison_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorationTable = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;

    if (decorationTable->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
        } else {
            decorationTable->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        decorationTable->palAnimState = 0;
        decorationTable->palBlendAlpha = 0;
        decorationTable->resetPalAdjust = FALSE;
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        palIn = decorationTable->originalPalettesList[i];
        palOut = decorationTable->copiedPalettes[0][i];
        if (palIn != NULL) {
            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *palOut++ = *palIn++;
            }
        }
    }
    for (i = 0; i < decorationTable->spriteColorVariations; i++) {
        palIn = decorationTable->originalPalettesList[decorationTable->spriteColorVariations + i];
        palOut = decorationTable->copiedPalettes[0][i];
        if (palIn != NULL) {
            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *palOut++ = *palIn++;
            }
        }
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        decorationTable->adjustedPalettes[i] = decorationTable->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }
}

void render_with_paralyze_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorationTable = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;

    if (decorationTable->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
        } else {
            decorationTable->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
        }

        decorationTable->palAnimState = 0;
        decorationTable->nextPalTime = 0;
        decorationTable->palBlendAlpha = 10;
        decorationTable->resetPalAdjust = FALSE;
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        palIn = decorationTable->originalPalettesList[i];
        palOut = decorationTable->copiedPalettes[0][i];
        if (palIn != NULL) {
            for (j = 0; j < SPR_PAL_SIZE; j++) {
                u8 r = UNPACK_PAL_R(*palIn);
                u8 g = UNPACK_PAL_G(*palIn);
                u8 b = UNPACK_PAL_B(*palIn);
                u8 a = UNPACK_PAL_A(*palIn);
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

                *palOut++ = PACK_PAL_RGBA(r, g, b, a);
            }
        }
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        decorationTable->adjustedPalettes[i] = decorationTable->copiedPalettes[0][i];
    }

    switch (decorationTable->palAnimState) {
        case 0:
        case 1:
            if (decorationTable->nextPalTime <= 0) {
                part->palAnimPosOffset[1] = ParalyzePaletteAnimXOffsets[abs(decorationTable->nextPalTime)];
                if (part->palAnimPosOffset[1] == PAL_ANIM_END) {
                    part->palAnimPosOffset[1] = 0;
                    // 30-90
                    decorationTable->nextPalTime = rand_int(60) + 30;
                }
            }

            if (!skipAnimation) {
                decorationTable->nextPalTime--;
            }

            switch (decorationTable->palBlendAlpha) {
                case 10:
                case 12:
                    if (isNpcSprite == SPRITE_MODE_PLAYER) {
                        func_8025995C(part, yaw, mtx);
                    } else {
                        func_802596C0(part, yaw, mtx);
                    }
                    break;
                case 13:
                    decorationTable->palBlendAlpha = 0;
                    // fallthrough
                default:
                    if (isNpcSprite == SPRITE_MODE_PLAYER) {
                        func_802597B0(part, yaw, mtx);
                    } else {
                        func_8025950C(part, yaw, mtx);
                    }
                    break;
            }

            if (!skipAnimation) {
                decorationTable->palBlendAlpha++;
            }
            break;
    }
}

void render_with_berserk_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorationTable = part->decorationTable;
    s32 i, j;

    if (decorationTable->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->palAnimState = 0;
        } else {
            decorationTable->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->palAnimState = 0;
        }
        decorationTable->palBlendAlpha = 0;
        decorationTable->palAnimState = 0;
        decorationTable->resetPalAdjust = FALSE;
    }

    // adjust each palette
    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        PAL_PTR palIn = decorationTable->originalPalettesList[i];
        PAL_PTR palOut = decorationTable->copiedPalettes[0][i];
        if (palIn != NULL) {
            for (j = 0; j < SPR_PAL_SIZE; j++) {
                u8 r = UNPACK_PAL_R(*palIn);
                u8 g = UNPACK_PAL_G(*palIn);
                u8 b = UNPACK_PAL_B(*palIn);
                u8 a = UNPACK_PAL_A(*palIn);
                palIn++;

                // make each color darker and redder
                r *= 0.8;
                g *= 0.6;
                b *= 0.1;

                *palOut++ = PACK_PAL_RGBA(r, g, b, a);
            }
        }
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        decorationTable->adjustedPalettes[i] = decorationTable->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }
}

void render_with_watt_idle_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorationTable = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;
    s32 palIdx;
    s32 brightnessLevel;

    if (decorationTable->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
        } else {
            decorationTable->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        for (i = 0; i < decorationTable->originalPalettesCount; i++) {
            palIn = decorationTable->originalPalettesList[i];
            palOut = decorationTable->copiedPalettes[0][i];
            if (palIn != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *palOut++ = *palIn++;
                }
            }
        }

        decorationTable->palAnimState = -2;
        decorationTable->palBlendAlpha = 0;
        decorationTable->resetPalAdjust = FALSE;
        decorationTable->nextPalTime = 0;
    }

    if (!skipAnimation) {
        if (decorationTable->nextPalTime == 0) {
            decorationTable->palAnimState += 2;
            if (WattIdlePalettesAnim[decorationTable->palAnimState] == PAL_ANIM_END) {
                decorationTable->palAnimState = 0;
            }
            decorationTable->nextPalTime = WattIdlePalettesAnim[decorationTable->palAnimState + 1] / 2;
        }
        brightnessLevel = WattIdlePalettesAnim[decorationTable->palAnimState];
        decorationTable->nextPalTime--;
    } else {
        //@bug if only called with skipAnimation set, palAnimPos will always be -2 and the array access is OOB
        brightnessLevel = WattIdlePalettesAnim[decorationTable->palAnimState];
    }

    switch (brightnessLevel) {
        case WATT_DEFAULT:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                // use watt's base palettes
                palIn = decorationTable->originalPalettesList[i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case WATT_BRIGHTEST:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                // use watt's Brightest palettes
                palIdx = decorationTable->spriteColorVariations * SPR_PAL_BattleWatt_Brightest + i;
                palIn = decorationTable->originalPalettesList[palIdx];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case WATT_BRIGHTER:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                // use watt's Brighter palettes
                palIdx = decorationTable->spriteColorVariations * SPR_PAL_BattleWatt_Brighter + i;
                palIn = decorationTable->originalPalettesList[palIdx];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        decorationTable->adjustedPalettes[i] = decorationTable->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }

    if (!skipAnimation) {
        decorationTable->palBlendAlpha--;
    }
}

void render_with_watt_attack_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorationTable = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;
    s32 palIdx;
    s32 brightness;

    if (decorationTable->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
        } else {
            decorationTable->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        for (i = 0; i < decorationTable->originalPalettesCount; i++) {
            palIn = decorationTable->originalPalettesList[i];
            palOut = decorationTable->copiedPalettes[0][i];
            if (palIn != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *palOut++ = *palIn++;
                }
            }
        }

        decorationTable->palAnimState = -2;
        decorationTable->palBlendAlpha = 0;
        decorationTable->resetPalAdjust = FALSE;
        decorationTable->nextPalTime = 0;
    }

    if (!skipAnimation) {
        if (decorationTable->nextPalTime == 0) {
            decorationTable->palAnimState += 2;
            if (WattAttackPalettesAnim[decorationTable->palAnimState] == PAL_ANIM_END) {
                decorationTable->palAnimState = 0;
            }
            decorationTable->nextPalTime = WattAttackPalettesAnim[decorationTable->palAnimState + 1] / 2;
        }
        brightness = WattAttackPalettesAnim[decorationTable->palAnimState];
        decorationTable->nextPalTime--;
    } else {
        //@bug if only called with skipAnimation set, palAnimPos will always be -2 and the array access is OOB
        brightness = WattAttackPalettesAnim[decorationTable->palAnimState];
    }

    switch (brightness) {
        case WATT_DEFAULT:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                palIn = decorationTable->originalPalettesList[i];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case WATT_BRIGHTEST:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                // use watt's Brightest palettes
                palIdx = decorationTable->spriteColorVariations * SPR_PAL_BattleWatt_Brightest + i;
                palIn = decorationTable->originalPalettesList[palIdx];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case WATT_BRIGHTER:
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                // use watt's Brighter palettes
                palIdx = decorationTable->spriteColorVariations * SPR_PAL_BattleWatt_Brighter + i;
                palIn = decorationTable->originalPalettesList[palIdx];
                palOut = decorationTable->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        decorationTable->adjustedPalettes[i] = decorationTable->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_8025995C(part, yaw, mtx);
    } else {
        func_802596C0(part, yaw, mtx);
    }

    if (!skipAnimation) {
        decorationTable->palBlendAlpha--;
    }
}

void render_with_player_debuff_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation, b32 isPoison) {
    DecorationTable* decorationTable = part->decorationTable;
    PAL_PTR color2;
    PAL_PTR color1;
    PAL_PTR palOut;
    s32 i, j;
    u8 blendAlpha;

    if (decorationTable->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorationTable->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }

            if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                decorationTable->spriteColorVariations = SPR_PEACH_BTL_PAL_STRIDE;
            } else {
                decorationTable->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
            }
        } else {
            decorationTable->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorationTable->originalPalettesCount = 0;
            while ((s32)decorationTable->originalPalettesList[decorationTable->originalPalettesCount] != -1) {
                decorationTable->originalPalettesCount++;
            }
            decorationTable->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        if (decorationTable->resetPalAdjust == TRUE) {
            decorationTable->palAnimState = 0;
            decorationTable->palBlendAlpha = 0;
        } else {
            decorationTable->palAnimState = 0;
            decorationTable->palBlendAlpha = 255;
        }

        for (i = 0; i < decorationTable->originalPalettesCount; i++) {
            color2 = decorationTable->originalPalettesList[i];
            color1 = decorationTable->copiedPalettes[0][i];
            decorationTable->adjustedPalettes[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *color1++ = *color2++;
                }
            }
        }

        if (isPoison) {
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                color2 = decorationTable->originalPalettesList[decorationTable->spriteColorVariations + i];
                palOut = decorationTable->copiedPalettes[0][i];
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *palOut++ = *color2++;
                }
            }
        }

        decorationTable->nextPalTime = 10;
        decorationTable->palBlendAlpha = 0;
        decorationTable->palAnimState = 0;
        decorationTable->resetPalAdjust = FALSE;
    }

    if (decorationTable->palAnimState == 0) {
        if (!skipAnimation && decorationTable->nextPalTime != 0) {
            decorationTable->nextPalTime--;
        } else {
            if (!skipAnimation) {
                decorationTable->palBlendAlpha += 2560;
                if (decorationTable->palBlendAlpha > 255 * 100) {
                    decorationTable->palBlendAlpha = 255 * 100;
                }
            }
            blendAlpha = decorationTable->palBlendAlpha / 100;
            for (i = 0; i < decorationTable->spriteColorVariations; i++) {
                if (!isPoison) {
                    color2 = decorationTable->originalPalettesList[i];
                } else {
                    color2 = decorationTable->originalPalettesList[decorationTable->spriteColorVariations * STANDARD_PAL_POISON + i];
                }
                color1 = decorationTable->originalPalettesList[decorationTable->spriteColorVariations * STANDARD_PAL_DIZZY + i];
                palOut = decorationTable->copiedPalettes[0][i];

                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    u8 r2 = UNPACK_PAL_R(*color2);
                    u8 g2 = UNPACK_PAL_G(*color2);
                    u8 b2 = UNPACK_PAL_B(*color2);
                    u8 r1 = UNPACK_PAL_R(*color1);
                    u8 g1 = UNPACK_PAL_G(*color1);
                    u8 b1 = UNPACK_PAL_B(*color1);
                    u8 a1 = UNPACK_PAL_A(*color1);
                    color2++;
                    color1++;

                    r1 = LERP_COMPONENT(r2, r1, blendAlpha);
                    g1 = LERP_COMPONENT(g2, g1, blendAlpha);
                    b1 = LERP_COMPONENT(b2, b1, blendAlpha);

                    *palOut++ = PACK_PAL_RGBA(r1, g1, b1, a1);
                }
            }
            if (blendAlpha == 255) {
                decorationTable->palAnimState = 1;
            }
        }
    }

    for (i = 0; i < decorationTable->originalPalettesCount; i++) {
        decorationTable->adjustedPalettes[i] = decorationTable->copiedPalettes[0][i];
    }

    switch (decorationTable->palAnimState) {
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

void render_with_pal_blending(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 hasDifferentIntervals, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decor = part->decorationTable;
    PAL_PTR color1;
    PAL_PTR color2;
    PAL_PTR outColor;
    s32 i, j;
    u8 blendAlpha;
    u8 r2, g2, b2, a1;
    u8 r1, g1, b1;

    if (decor->resetPalAdjust != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decor->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decor->originalPalettesCount = 0;
            while ((s32)decor->originalPalettesList[decor->originalPalettesCount] != -1) {
                decor->originalPalettesCount++;
            }
        } else {
            decor->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decor->originalPalettesCount = 0;
            while ((s32)decor->originalPalettesList[decor->originalPalettesCount] != -1) {
                decor->originalPalettesCount++;
            }
        }

        if (decor->resetPalAdjust == 1) {
            decor->palAnimState = 0;
            decor->palBlendAlpha = 0;
        } else {
            decor->palAnimState = 0;
            decor->palBlendAlpha = 255;
        }

        for (i = 0; i < decor->originalPalettesCount; i++) {
            color2 = decor->originalPalettesList[i];
            color1 = decor->copiedPalettes[0][i];
            decor->adjustedPalettes[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *color1++ = *color2++;
                }
            }
        }

        if (!hasDifferentIntervals) {
            decor->palswapTimeAtoB = decor->palswapTimeHoldA;
            decor->palswapTimeHoldB = decor->palswapTimeAtoB;
            decor->palswapTimeBtoA = decor->palswapTimeAtoB;
            decor->palswapTimeHoldA = 0;
        }

        decor->nextPalTime = decor->palswapTimeHoldA;
        decor->palBlendAlpha = 0;
        decor->palAnimState = PAL_SWAP_HOLD_A;
        decor->resetPalAdjust = FALSE;
    }

    // blending from A -> B
    switch (decor->palAnimState) {
        case PAL_SWAP_HOLD_A:
            if (skipAnimation) {
                break;
            }
            if (decor->nextPalTime != 0) {
                decor->nextPalTime--;
                break;
            }
            decor->palBlendAlpha = 0;
            decor->palAnimState = PAL_SWAP_A_TO_B;
            // fallthrough
        case PAL_SWAP_A_TO_B:
            if (!skipAnimation) {
                decor->palBlendAlpha += 25600 / decor->palswapTimeAtoB;
                if (decor->palBlendAlpha > 255 * 100) {
                    decor->palBlendAlpha = 255 * 100;
                }
            }
            blendAlpha = decor->palBlendAlpha / 100;
            // blend two palettes
            color2 = decor->originalPalettesList[decor->blendPalA];
            color1 = decor->originalPalettesList[decor->blendPalB];
            outColor = decor->adjustedPalettes[0] = decor->copiedPalettes[0][0];

            for (j = 0; j < SPR_PAL_SIZE; j++) {
                r2 = UNPACK_PAL_R(*color2);
                g2 = UNPACK_PAL_G(*color2);
                b2 = UNPACK_PAL_B(*color2);
                r1 = UNPACK_PAL_R(*color1);
                g1 = UNPACK_PAL_G(*color1);
                b1 = UNPACK_PAL_B(*color1);
                a1 = UNPACK_PAL_A(*color1);
                color2++;
                color1++;

                r1 = LERP_COMPONENT(r2, r1, blendAlpha);
                g1 = LERP_COMPONENT(g2, g1, blendAlpha);
                b1 = LERP_COMPONENT(b2, b1, blendAlpha);

                *outColor++ = PACK_PAL_RGBA(r1, g1, b1, a1);
            }
            if (blendAlpha == 255) {
                decor->palAnimState = PAL_SWAP_HOLD_B;
                decor->nextPalTime = decor->palswapTimeHoldB;
            }
            break;
    }

    // blending from B -> A
    switch (decor->palAnimState) {
        case PAL_SWAP_HOLD_B:
            if (skipAnimation) {
                break;
            }
            if (decor->nextPalTime != 0) {
                decor->nextPalTime--;
                break;
            }
            decor->palBlendAlpha = 0;
            decor->palAnimState = PAL_SWAP_B_TO_A;
            // fallthrough
        case PAL_SWAP_B_TO_A:
            if (!skipAnimation) {
                decor->palBlendAlpha += 25600 / decor->palswapTimeBtoA;
                if (decor->palBlendAlpha > 255 * 100) {
                    decor->palBlendAlpha = 255 * 100;
                }
            }
            blendAlpha = decor->palBlendAlpha / 100;
            // blend two palettes
            color2 = decor->originalPalettesList[decor->blendPalB];
            color1 = decor->originalPalettesList[decor->blendPalA];
            outColor = decor->copiedPalettes[0][0];
            decor->adjustedPalettes[0] = outColor;

            for (j = 0; j < SPR_PAL_SIZE; j++) {
                r2 = UNPACK_PAL_R(*color2);
                g2 = UNPACK_PAL_G(*color2);
                b2 = UNPACK_PAL_B(*color2);
                r1 = UNPACK_PAL_R(*color1);
                g1 = UNPACK_PAL_G(*color1);
                b1 = UNPACK_PAL_B(*color1);
                a1 = UNPACK_PAL_A(*color1);
                color2++;
                color1++;

                r1 = LERP_COMPONENT(r2, r1, blendAlpha);
                g1 = LERP_COMPONENT(g2, g1, blendAlpha);
                b1 = LERP_COMPONENT(b2, b1, blendAlpha);

                *outColor++ = PACK_PAL_RGBA(r1, g1, b1, a1);
            }
            if (blendAlpha == 255) {
                decor->palAnimState = PAL_SWAP_HOLD_A;
                decor->nextPalTime = decor->palswapTimeHoldA;
            }
            break;
    }

    switch (decor->palAnimState) {
        case PAL_SWAP_HOLD_A:
        case PAL_SWAP_A_TO_B:
        case PAL_SWAP_HOLD_B:
        case PAL_SWAP_B_TO_A:
            if (isNpcSprite == SPRITE_MODE_PLAYER) {
                func_8025995C(part, yaw, mtx);
            } else {
                func_802596C0(part, yaw, mtx);
            }
            break;
    }
}

void render_with_palset_blending(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decor = part->decorationTable;
    PAL_PTR color1;
    PAL_PTR color2;
    PAL_PTR outColor;
    s32 i, j;
    u8 blendAlpha;
    u8 r2, g2, b2, a1;
    u8 r1, g1, b1;

    if (decor->resetPalAdjust != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decor->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decor->originalPalettesCount = 0;
            while (decor->originalPalettesList[decor->originalPalettesCount] != (PAL_PTR) -1) {
                decor->originalPalettesCount++;
            }
        } else {
            decor->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decor->originalPalettesCount = 0;
            while (decor->originalPalettesList[decor->originalPalettesCount] != (PAL_PTR) -1) {
                decor->originalPalettesCount++;
            }
            decor->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        if (decor->resetPalAdjust == 1) {
            decor->palAnimState = 0;
            decor->palBlendAlpha = 0;
        } else {
            decor->palAnimState = 0;
            decor->palBlendAlpha = 255;
        }

         for (i = 0; i < decor->originalPalettesCount; i++) {
            color2 = decor->originalPalettesList[i];
            color1 = decor->copiedPalettes[0][i];
            decor->adjustedPalettes[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *color1++ = *color2++;
                }
            }
        }

        decor->nextPalTime = decor->palswapTimeHoldA;
        decor->palBlendAlpha = 0;
        decor->palAnimState = PAL_SWAP_HOLD_A;
        decor->resetPalAdjust = FALSE;
    }

    // blending from A -> B
    switch (decor->palAnimState) {
        case PAL_SWAP_HOLD_A:
            if (skipAnimation) {
                break;
            }
            if (decor->nextPalTime != 0) {
                decor->nextPalTime--;
                break;
            }
            decor->palBlendAlpha = 0;
            decor->palAnimState = PAL_SWAP_A_TO_B;
            // fallthrough
        case PAL_SWAP_A_TO_B:
            if (!skipAnimation) {
                decor->palBlendAlpha += 25600 / decor->palswapTimeAtoB;
                if (decor->palBlendAlpha > 255 * 100) {
                    decor->palBlendAlpha = 255 * 100;
                }
            }
            blendAlpha = decor->palBlendAlpha / 100;
            // blend all palettes from two palette sets
            for (i = 0; i < decor->spriteColorVariations; i++) {
                color2 = decor->originalPalettesList[decor->blendPalA * decor->spriteColorVariations + i];
                color1 = decor->originalPalettesList[decor->blendPalB * decor->spriteColorVariations + i];
                outColor = decor->copiedPalettes[0][i];
                decor->adjustedPalettes[i] = outColor;

                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    r2 = UNPACK_PAL_R(*color2);
                    g2 = UNPACK_PAL_G(*color2);
                    b2 = UNPACK_PAL_B(*color2);
                    r1 = UNPACK_PAL_R(*color1);
                    g1 = UNPACK_PAL_G(*color1);
                    b1 = UNPACK_PAL_B(*color1);
                    a1 = UNPACK_PAL_A(*color1);
                    color2++;
                    color1++;

                    r1 = LERP_COMPONENT(r2, r1, blendAlpha);
                    g1 = LERP_COMPONENT(g2, g1, blendAlpha);
                    b1 = LERP_COMPONENT(b2, b1, blendAlpha);

                    *outColor++ = PACK_PAL_RGBA(r1, g1, b1, a1);
                }
            }
            if (blendAlpha == 255) {
                decor->palAnimState = PAL_SWAP_HOLD_B;
                decor->nextPalTime = decor->palswapTimeHoldB;
            }
            break;
    }

    switch (decor->palAnimState) {
        case PAL_SWAP_HOLD_B:
            if (skipAnimation) {
                break;
            }
            if (decor->nextPalTime != 0) {
                decor->nextPalTime--;
                break;
            }
            decor->palBlendAlpha = 0;
            decor->palAnimState = PAL_SWAP_B_TO_A;
            // fallthrough
        case PAL_SWAP_B_TO_A:
            if (!skipAnimation) {
                decor->palBlendAlpha += 25600 / decor->palswapTimeBtoA;
                if (decor->palBlendAlpha > 255 * 100) {
                    decor->palBlendAlpha = 255 * 100;
                }
            }
            blendAlpha = decor->palBlendAlpha / 100;
            // blend all palettes from two palette sets
            for (i = 0; i < decor->spriteColorVariations; i++) {
                color2 = decor->originalPalettesList[decor->blendPalA * decor->spriteColorVariations + i];
                color1 = decor->originalPalettesList[decor->blendPalB * decor->spriteColorVariations + i];
                outColor = decor->copiedPalettes[0][i];
                decor->adjustedPalettes[i] = outColor;

                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    r2 = UNPACK_PAL_R(*color2);
                    g2 = UNPACK_PAL_G(*color2);
                    b2 = UNPACK_PAL_B(*color2);
                    r1 = UNPACK_PAL_R(*color1);
                    g1 = UNPACK_PAL_G(*color1);
                    b1 = UNPACK_PAL_B(*color1);
                    a1 = UNPACK_PAL_A(*color1);
                    color2++;
                    color1++;

                    r1 = LERP_COMPONENT(r2, r1, blendAlpha);
                    g1 = LERP_COMPONENT(g2, g1, blendAlpha);
                    b1 = LERP_COMPONENT(b2, b1, blendAlpha);

                    *outColor++ = PACK_PAL_RGBA(r1, g1, b1, a1);
                }
            }
            if (blendAlpha == 255) {
                decor->palAnimState = PAL_SWAP_HOLD_A;
                decor->nextPalTime = decor->palswapTimeHoldA;
            }
            break;
    }

    switch (decor->palAnimState) {
        case PAL_SWAP_HOLD_A:
        case PAL_SWAP_A_TO_B:
        case PAL_SWAP_HOLD_B:
        case PAL_SWAP_B_TO_A:
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

void func_8025C8A0(b32 isNpcSprite, ActorPart* part, s32 yaw, s32 arg3) {
    if (part->decorationTable->unk_751 != 0) {
        part->decorationTable->unk_751 = 0;
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            set_player_imgfx_all(PLAYER_SPRITE_MAIN, IMGFX_CLEAR, 0, 0, 0, 0, 0);
        } else {
            set_npc_imgfx_all(part->spriteInstanceID, IMGFX_CLEAR, 0, 0, 0, 0, 0);
        }
    }
}

void func_8025C918(b32 isNpcSprite, ActorPart* part, s32 yaw, s32 arg3) {
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
            set_player_imgfx_all(PLAYER_SPRITE_MAIN, IMGFX_ALLOC_COLOR_BUF, 20, 0, 0, 255, 0);
        } else {
            set_npc_imgfx_all(part->spriteInstanceID, IMGFX_ALLOC_COLOR_BUF, 20, 0, 0, 255, 0);
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
            set_player_imgfx_all(PLAYER_SPRITE_MAIN, IMGFX_COLOR_BUF_SET_MODULATE, i, color, 0, 255, 0);
        } else {
            set_npc_imgfx_all(part->spriteInstanceID, IMGFX_COLOR_BUF_SET_MODULATE, i, color, 0, 255, 0);
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
            fx_aura(3, arg0->curPos.x, arg0->curPos.y, arg0->curPos.z, 0.4f, &table->effect[index]);
            table->state[index] = 1;
            table->unk_8C6[index].unk00 = 40;
            table->unk_8C6[index].unk02 = 40;
            table->unk_8C6[index].unk04 = 0;
            break;
        case 1:
            effect = table->effect[index];
            data = effect->data.aura;
            data->posA.x = arg0->curPos.x + table->unk_8C6[index].unk04;
            data->posA.y = arg0->curPos.y;
            data->posA.z = arg0->curPos.z;
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
                fx_sweat(0, part->curPos.x, part->curPos.y + part->size.y, part->curPos.z, 5.0f, 45.0f, 20);
            } else {
                fx_sweat(0, part->curPos.x, part->curPos.y + part->size.y, part->curPos.z, 5.0f, -45.0f, 20);
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
            fx_stars_orbiting(0, part->curPos.x, part->curPos.y + part->size.y, part->curPos.z,
                20.0f, 3, &decor->effect[decorationIndex]);
            decor->state[decorationIndex] = 1;
            break;
        case 1:
            data = decor->effect[decorationIndex]->data.starsOrbiting;
            data->pos.x = part->curPos.x;
            data->pos.y = part->curPos.y + part->size.y;
            data->pos.z = part->curPos.z;
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
            fx_aura(1, part->curPos.x, part->curPos.y, part->curPos.z, 0.4f, &decor->effect[decorationIndex]);
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
            data->posA.x = part->curPos.x;
            data->posA.y = part->curPos.y;
            data->posA.z = part->curPos.z + decor->unk_8C6[decorationIndex].unk06;

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
            decor->effect[decorationIndex] = fx_effect_65(1, part->curPos.x, part->curPos.y, part->curPos.z, 1.0f, 0);
            decor->state[decorationIndex] = 1;
            break;
        case 1:
            effect = decor->effect[decorationIndex];
            effect->data.unk_65->pos.x = part->curPos.x;
            effect->data.unk_65->pos.y = part->curPos.y;
            effect->data.unk_65->pos.z = part->curPos.z;
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
            decor->effect[decorationIndex] = fx_effect_65(2, part->curPos.x, part->curPos.y, part->curPos.z, 1.0f, 0);
            decor->unk_8C6[decorationIndex].unk00 = 1;
            decor->state[decorationIndex] = 1;
            break;
        case 1:
            effect = decor->effect[decorationIndex];
            effect->data.unk_65->pos.x = part->curPos.x;
            effect->data.unk_65->pos.y = part->curPos.y;
            effect->data.unk_65->pos.z = part->curPos.z;
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
            decor->effect[decorationIndex] = fx_whirlwind(2, part->curPos.x, part->curPos.y, part->curPos.z, 1.0f, 0);
            decor->state[decorationIndex] = 1;
            break;
        case 1:
            effect = decor->effect[decorationIndex];
            effect->data.whirlwind->pos.x = part->curPos.x;
            effect->data.whirlwind->pos.y = part->curPos.y;
            effect->data.whirlwind->pos.z = part->curPos.z;
            break;
    }
}

void func_8025D8EC(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->effect[decorationIndex]->flags |= FX_INSTANCE_FLAG_DISMISS;
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
                    part->curPos.x + (part->size.x * sinA * 0.2f),
                    part->curPos.y + 1.5f,
                    part->curPos.z + (part->size.x * cosA * 0.2f),
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
                x = part->curPos.x;
                y = part->curPos.y + (part->size.y / 2);
                z = part->curPos.z - 5.0f;
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
            fx_aura(2, part->curPos.x, part->curPos.y, part->curPos.z, 1.2f, &decor->effect[decorationIndex]);
            decor->state[decorationIndex] = 1;
            decor->unk_8C6[decorationIndex].unk00 = 150;
            decor->unk_8C6[decorationIndex].unk02 = 150;
            decor->unk_8C6[decorationIndex].unk04 = 255;
            decor->unk_8C6[decorationIndex].unk06 = 0;
            // fallthrough
        case 1:
            effect = decor->effect[decorationIndex];
            data = effect->data.aura;
            data->posA.x = part->curPos.x;
            data->posA.y = part->curPos.y;
            data->posA.z = part->curPos.z + decor->unk_8C6[decorationIndex].unk06;

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
            decor->effect[decorationIndex] = fx_energy_in_out(4, part->curPos.x, part->curPos.y, part->curPos.z, 1.2f, 0);
            decor->state[decorationIndex] = 1;
            decor->unk_8C6[decorationIndex].unk00 = 120;
            decor->unk_8C6[decorationIndex].unk02 = 0;
            // fallthrough
        case 1:
            data = decor->effect[decorationIndex]->data.energyInOut;
            scale = decor->unk_8C6[decorationIndex].unk00;
            scale /= 100.0f;
            data->unk_44 = scale;
            data->pos.x = part->curPos.x;
            data->pos.y = (part->curPos.y + (scale * 41.0f));
            data->pos.z = (part->curPos.z + decor->unk_8C6[decorationIndex].unk02);
            break;
    }
}

void func_8025DE88(ActorPart* part, s32 decorationIndex) {
    part->decorationTable->effect[decorationIndex]->flags |= 0x10;
}
