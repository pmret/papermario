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
u8 bWattIdlePalettesAnim[] = {
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

s16 SparkleSpawnIntervals[] = { -1, 15, 10, 7, 5, 3, 2, 1 };

void update_player_actor_shadow(void);
void appendGfx_npc_actor(s32 isPartner, s32 actorIndex);

void create_status_chill_out(s32 iconID);
void enable_status_static(s32 iconID);
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
void make_flash_palettes(ActorPart*);
void func_unkA_draw_npc(ActorPart*, s32, Matrix4f);
void func_unkB_draw_npc(ActorPart*, s32, Matrix4f);
void func_unkA_draw_player(ActorPart*, s32, Matrix4f);
void func_unkB_draw_player(ActorPart*, s32, Matrix4f);
void part_glow_on(b32 arg0, ActorPart* part, s32 yaw, b32 arg3);
void part_flash_on(b32 arg0, ActorPart* part, s32 yaw, b32 arg3);

void add_part_decor_none(ActorPart*, s32);
void add_part_decor_golden_flames(ActorPart*, s32);
void add_part_decor_sweat(ActorPart*, s32);
void add_part_decor_seeing_stars(ActorPart*, s32);
void add_part_decor_red_flames(ActorPart*, s32);
void add_part_decor_smoky_trail(ActorPart*, s32);
void add_part_decor_fiery_trail(ActorPart*, s32);
void add_part_decor_whirlwind(ActorPart*, s32);
void add_part_decor_steam(ActorPart*, s32);
void add_part_decor_sparkles(ActorPart*, s32);
void add_part_decor_bowser_aura(ActorPart*, s32);
void add_part_decor_radiating_stars(ActorPart*, s32);

void render_without_adjusted_palettes(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_sleep_palettes(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_static_palettes(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_fear_palettes(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_poison_palettes(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_paralyze_palettes(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_berserk_palettes(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_watt_idle_palettes(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_watt_attack_palettes(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
void render_with_player_debuff_palettes(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation, s32 isPoison);
void render_with_pal_blending(b32 arg0, ActorPart* part, s32 yaw, s32 arg3, Matrix4f mtx, s32 skipAnimation);
void render_with_palset_blending(b32 arg0, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation);
s32 update_part_glow(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 isReflection);
s32 update_part_flash(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 isReflection);
s32 get_player_anim_for_status(s32 animID);
void clear_part_flash_mode(ActorPart* part);

// thresholds slightly lower than in GetDamageIntensity
s32 get_flash_damage_intensity(ActorPart* part) {
    s32 ret;

    if (gBattleStatus.lastAttackDamage < 3) {
        ret = DAMAGE_INTENSITY_LIGHT;
    } else if (gBattleStatus.lastAttackDamage < 5) {
        ret = DAMAGE_INTENSITY_MEDIUM;
    } else if (gBattleStatus.lastAttackDamage < 9) {
        ret = DAMAGE_INTENSITY_HEAVY;
    } else {
        ret = DAMAGE_INTENSITY_EXTREME;
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
    DecorationTable* decorations = partsTable->decorationTable;
    s32 i, j;
    s32 numParts;

    decorations->blurDisableDelay = 0;
    decorations->blurEnableCount++;
    actor->flags |= ACTOR_FLAG_BLUR_ENABLED;
    partsTable = actor->partsTable;
    numParts = actor->numParts;

    for (i = 0; i < numParts; i++) {
        if (partsTable->idleAnimations != NULL && !(partsTable->flags & ACTOR_PART_FLAG_NO_DECORATIONS)) {
            decorations = partsTable->decorationTable;
            decorations->blurUnused = 0;
            decorations->blurBufferPos = 0;
            for (j = 0; j < ARRAY_COUNT(decorations->posX); j++) {
                decorations->posX[j] = partsTable->curPos.x;
                decorations->posY[j] = partsTable->curPos.y;
                decorations->posZ[j] = partsTable->curPos.z;
                decorations->yaw[j] = actor->yaw;
                decorations->rotPivotOffsetX[j] = (s32)(actor->rotPivotOffset.x * actor->scalingFactor);
                decorations->rotPivotOffsetY[j] = (s32)(actor->rotPivotOffset.y * actor->scalingFactor);

                decorations->rotX[j] = clamp_angle(actor->rot.x) * 0.5f;
                decorations->rotY[j] = clamp_angle(actor->rot.y) * 0.5f;
                decorations->rotZ[j] = clamp_angle(actor->rot.z) * 0.5f;
            }
        }
        partsTable = partsTable->nextPart;
    }
}

void disable_actor_blur(Actor* actor) {
    ActorPart* actorPart = actor->partsTable;

    if ((actorPart->idleAnimations != NULL) && !(actorPart->flags & ACTOR_PART_FLAG_NO_DECORATIONS)) {
        DecorationTable* decorations = actorPart->decorationTable;

        if (decorations->blurEnableCount != 0) {
            decorations->blurEnableCount--;
            if (decorations->blurEnableCount == 0) {
                decorations->blurDisableDelay = 20;
            }
        }
    }
}

void reset_actor_blur(Actor* actor) {
    ActorPart* actorPart = actor->partsTable;

    if ((actorPart->idleAnimations != NULL) && !(actorPart->flags & ACTOR_PART_FLAG_NO_DECORATIONS)) {
        DecorationTable* decorations = actorPart->decorationTable;

        if (decorations->blurEnableCount != 0) {
            decorations->blurEnableCount--;
            if (decorations->blurEnableCount == 0) {
                actor->flags &= ~ACTOR_FLAG_BLUR_ENABLED;
                decorations->blurDisableDelay = 1;
            }
        }
    }
}

void force_disable_actor_blur(Actor* actor) {
    ActorPart* actorPart = actor->partsTable;

    if (actorPart->idleAnimations != NULL && !(actorPart->flags & ACTOR_PART_FLAG_NO_DECORATIONS)) {
        DecorationTable* decorations = actorPart->decorationTable;

        decorations->blurEnableCount = 0;
        decorations->blurDisableDelay = 20;
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

void force_disable_partner_blur(void) {
    force_disable_actor_blur(gBattleStatus.partnerActor);
}

void enable_player_blur(void) {
    Actor* playerActor = gBattleStatus.playerActor;
    ActorPart* partsTable = playerActor->partsTable;
    DecorationTable* decorations = partsTable->decorationTable;
    s32 i;

    decorations->blurDisableDelay = 0;
    decorations->blurEnableCount++;
    playerActor->flags |= ACTOR_FLAG_BLUR_ENABLED;
    decorations->blurUnused = 0;
    decorations->blurBufferPos = 0;

    for (i = 0; i < ARRAY_COUNT(decorations->posX); i++) {
        decorations->posX[i] = partsTable->curPos.x;
        decorations->posY[i] = partsTable->curPos.y;
        decorations->posZ[i] = partsTable->curPos.z;
        decorations->yaw[i] = playerActor->yaw;
        decorations->rotPivotOffsetX[i] = playerActor->rotPivotOffset.x * playerActor->scalingFactor;
        decorations->rotPivotOffsetY[i] = playerActor->rotPivotOffset.y * playerActor->scalingFactor;

        decorations->rotX[i] = clamp_angle(playerActor->rot.x) * 0.5f;
        decorations->rotY[i] = clamp_angle(playerActor->rot.y) * 0.5f;
        decorations->rotZ[i] = clamp_angle(playerActor->rot.z) * 0.5f;
    }
}

void disable_player_blur(void) {
    Actor* playerActor = gBattleStatus.playerActor;
    ActorPart* partsTable = playerActor->partsTable;
    DecorationTable* decorations = partsTable->decorationTable;

    if (decorations->blurEnableCount != 0) {
        decorations->blurEnableCount--;
        if (decorations->blurEnableCount == 0) {
            decorations->blurDisableDelay = 20;
        }
    }
}

void reset_player_blur(void) {
    Actor* playerActor = gBattleStatus.playerActor;
    ActorPart* partsTable = playerActor->partsTable;
    DecorationTable* decorations = partsTable->decorationTable;

    if (decorations->blurEnableCount != 0) {
        decorations->blurEnableCount--;
        if (decorations->blurEnableCount == 0) {
            playerActor->flags &= ~ACTOR_FLAG_BLUR_ENABLED;
            decorations->blurDisableDelay = 1;
        }
    }
}

void force_disable_player_blur(void) {
    Actor* playerActor = gBattleStatus.playerActor;
    ActorPart* partsTable = playerActor->partsTable;
    DecorationTable* decorations = partsTable->decorationTable;

    decorations->blurEnableCount = 0;
    decorations->blurDisableDelay = 20;
}

void force_disable_player_blur_immediately(void) {
    Actor* playerActor = gBattleStatus.playerActor;
    ActorPart* partsTable = playerActor->partsTable;
    DecorationTable* decorations = partsTable->decorationTable;

    playerActor->flags &= ~ACTOR_FLAG_BLUR_ENABLED;
    decorations->blurEnableCount = 0;
    decorations->blurDisableDelay = 1;
}

void update_player_actor_blur_history(Actor* actor) {
    ActorPart* partsTable = actor->partsTable;
    DecorationTable* decorations = partsTable->decorationTable;

    if (!(partsTable->flags & ACTOR_PART_FLAG_INVISIBLE) && partsTable->idleAnimations != NULL) {
        s32 i = decorations->blurBufferPos;

        decorations->posX[i] = partsTable->curPos.x;
        decorations->posY[i] = partsTable->curPos.y;
        decorations->posZ[i] = partsTable->curPos.z;
        decorations->yaw[i] = actor->yaw;

        decorations->rotPivotOffsetX[i] = actor->rotPivotOffset.x * actor->scalingFactor;
        decorations->rotPivotOffsetY[i] = actor->rotPivotOffset.y * actor->scalingFactor;

        decorations->rotX[i] = clamp_angle(actor->rot.x) * 0.5f;
        decorations->rotY[i] = clamp_angle(actor->rot.y) * 0.5f;
        decorations->rotZ[i] = clamp_angle(actor->rot.z) * 0.5f;

        i++;
        if (i >= ARRAY_COUNT(decorations->posX)) {
            i = 0;
        }
        decorations->blurBufferPos = i;
    }
}

void appendGfx_player_actor_blur(Actor* actor) {
    Matrix4f mtxRotX, mtxRotY, mtxRotZ, mtxRotation;
    Matrix4f mtxScale;
    Matrix4f mtxPivotOn, mtxPivotOff, mtxTranslate;
    Matrix4f mtxTransform, mtxTemp;
    s32 strideIdx;
    s32 drawIdx;
    s32 yaw;
    ActorPart* partTable;
    DecorationTable* decorations;
    f32 rotX, rotY, rotZ;
    s32 prevOpacity;
    s32 opacity;
    s32 pivotOffsetX;
    s32 pivotOffsetY;
    s32 bufPos;
    s32 blurOpacityBase;
    s32 opacityLossIncrement;
    f32 x, y, z;

    partTable = actor->partsTable;
    decorations = partTable->decorationTable;
    if (decorations->blurDisableDelay != 0) {
        decorations->blurDisableDelay--;
        if (decorations->blurDisableDelay == 0) {
            actor->flags &= ~ACTOR_FLAG_BLUR_ENABLED;
            return;
        }
    }

    if (!(partTable->flags & ACTOR_PART_FLAG_INVISIBLE) && partTable->idleAnimations != NULL) {
        bufPos = decorations->blurBufferPos;
        strideIdx = 0;
        drawIdx = 0;

        while (TRUE) {
            bufPos--;
            strideIdx++;
            if (bufPos < 0) {
                bufPos = ARRAY_COUNT(decorations->posX) - 1;
            }
            if (bufPos == decorations->blurBufferPos) {
                break;
            }

            // only draw every third blur frame
            if (strideIdx < 3) {
                continue;
            }

            strideIdx = 0;
            drawIdx++;

            if (decorations->blurDrawCount < drawIdx) {
                break;
            }

            opacity = partTable->opacity;

            x = decorations->posX[bufPos];
            y = decorations->posY[bufPos];
            z = decorations->posZ[bufPos];

            yaw = decorations->yaw[bufPos];

            pivotOffsetX = decorations->rotPivotOffsetX[bufPos];
            pivotOffsetY = decorations->rotPivotOffsetY[bufPos];

            rotX = decorations->rotX[bufPos] * 2;
            rotY = decorations->rotY[bufPos] * 2;
            rotZ = decorations->rotZ[bufPos] * 2;

            blurOpacityBase = 120;
            opacityLossIncrement = 20;
            if (opacity < 50) {
                blurOpacityBase = 50;
                opacityLossIncrement = 8;
            } else if (opacity < 100) {
                blurOpacityBase = 70;
                opacityLossIncrement = 10;
            } else if (opacity < 150) {
                blurOpacityBase = 100;
                opacityLossIncrement = 15;
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
            partTable->opacity = blurOpacityBase - (drawIdx * opacityLossIncrement);
            render_with_adjusted_palettes(SPRITE_MODE_PLAYER, partTable, clamp_angle(yaw + 180), mtxTransform, 1);
            partTable->opacity = prevOpacity;
        }
    }
}

void update_nonplayer_actor_blur_history(b32 isPartner, Actor* actor) {
    s32 numParts = actor->numParts;
    ActorPart* partsTable = actor->partsTable;
    DecorationTable* decorations;
    s32 i, j;

    for (i = 0; i < numParts; i++) {
        if (partsTable->flags & ACTOR_PART_FLAG_INVISIBLE || partsTable->idleAnimations == NULL || partsTable->flags & ACTOR_PART_FLAG_NO_DECORATIONS) {
            partsTable = partsTable->nextPart;
        } else {
            decorations = partsTable->decorationTable;
            j = decorations->blurBufferPos;

            decorations->posX[j] = partsTable->curPos.x;
            decorations->posY[j] = partsTable->curPos.y;
            decorations->posZ[j] = partsTable->curPos.z;
            decorations->yaw[j] = actor->yaw;

            decorations->rotPivotOffsetX[j] = actor->rotPivotOffset.x;
            decorations->rotPivotOffsetY[j] = actor->rotPivotOffset.y;

            decorations->rotX[j] = clamp_angle(actor->rot.x) * 0.5f;
            decorations->rotY[j] = clamp_angle(actor->rot.y) * 0.5f;
            decorations->rotZ[j] = clamp_angle(actor->rot.z) * 0.5f;

            j++;
            if (j >= ARRAY_COUNT(decorations->posX)) {
                j = 0;
            }
            decorations->blurBufferPos = j;
        }
    }
}

void appendGfx_nonplayer_actor_blur(b32 isPartner, Actor* actor) {
    DecorationTable* decorations;
    ActorPart* partTable;
    Matrix4f mtxRotX, mtxRotY, mtxRotZ, mtxRotation;
    Matrix4f mtxScale, mtxTranslate;
    Matrix4f mtxTemp, mtxTransform;
    Matrix4f mtxPivotOn, mtxPivotOff;
    Matrix4f mtxActor, mtxPartScale;
    s32 numParts;
    s32 i, bufPos, strideIdx, drawIdx;
    f32 x, y, z;
    f32 rotX, rotY, rotZ;
    s32 yaw;
    s32 opacity;
    s32 pivotX;
    s32 pivotY;
    s32 blurOpacityBase;
    s32 opacityLossIncrement;
    s32 blurOpacity;
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
        if ((partTable->idleAnimations == NULL) || (partTable->flags & ACTOR_PART_FLAG_NO_DECORATIONS)) {
            partTable = partTable->nextPart;
            continue;
        }

        decorations = partTable->decorationTable;
        if (decorations->blurDisableDelay != 0) {
            decorations->blurDisableDelay--;
            if (decorations->blurDisableDelay == 0) {
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

        bufPos = decorations->blurBufferPos;
        strideIdx = 0;
        drawIdx = 0;

        while (TRUE) {
            bufPos--;
            strideIdx++;

            if (bufPos < 0) {
                bufPos = ACTOR_BLUR_FRAMES - 1;
            }

            if (bufPos == decorations->blurBufferPos) {
                break;
            }

            // only draw every third blur frame
            if (strideIdx < 3) {
                continue;
            }

            strideIdx = 0;
            drawIdx++;

            if (decorations->blurDrawCount < drawIdx) {
                break;
            }

            opacity = partTable->opacity;

            x = decorations->posX[bufPos];
            y = decorations->posY[bufPos];
            z = decorations->posZ[bufPos];

            yaw = decorations->yaw[bufPos];

            pivotX = decorations->rotPivotOffsetX[bufPos];
            pivotY = decorations->rotPivotOffsetY[bufPos];

            rotX = decorations->rotX[bufPos] * 2;
            rotY = decorations->rotY[bufPos] * 2;
            rotZ = decorations->rotZ[bufPos] * 2;

            blurOpacityBase = 120;
            opacityLossIncrement = 20;
            if (opacity < 50) {
                blurOpacityBase = 50;
                opacityLossIncrement = 8;
            } else if (opacity < 100) {
                blurOpacityBase = 70;
                opacityLossIncrement = 10;
            } else if (opacity < 150) {
                blurOpacityBase = 100;
                opacityLossIncrement = 15;
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

            flags = DRAW_SPRITE_OVERRIDE_ALPHA;
            blurOpacity = blurOpacityBase - drawIdx * opacityLossIncrement;
            if (!isPartner) {
                spr_draw_npc_sprite(partTable->spriteInstanceID | flags, yaw, blurOpacity, 0, mtxTransform);
            } else {
                spr_draw_npc_sprite(partTable->spriteInstanceID | flags, clamp_angle(yaw + 180), blurOpacity, 0, mtxTransform);
            }
        }
    }
}

void update_enemy_actor_blur_history(Actor* actor) {
    update_nonplayer_actor_blur_history(FALSE, actor);
}

void appendGfx_enemy_actor_blur(void* data) {
    Actor* actor = data;

    appendGfx_nonplayer_actor_blur(FALSE, actor);
}

void update_partner_actor_blur_history(Actor* actor) {
    update_nonplayer_actor_blur_history(TRUE, actor);
}

void appendGfx_partner_actor_blur(void* data) {
    Actor* actor = data;

    appendGfx_nonplayer_actor_blur(TRUE, actor);
}

void update_nonplayer_actor_shadow(b32 isPartner, Actor* actor) {
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
        if (!(actor->flags & ACTOR_FLAG_INVISIBLE)) {
            if (actor->flags & ACTOR_FLAG_BLUR_ENABLED) {
                if (!isPartner) {
                    update_enemy_actor_blur_history(actor);
                } else {
                    update_partner_actor_blur_history(actor);
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

                    if (!(actorPart->flags & ACTOR_PART_FLAG_NO_SHADOW)) {
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
                    if (actorPart->opacity < 255 || actorPart->flags & ACTOR_PART_FLAG_TRANSPARENT) {
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
        update_nonplayer_actor_shadow(FALSE, battleStatus->enemyActors[i]);
    }
}

void update_hero_shadows(void) {
    update_nonplayer_actor_shadow(TRUE, gBattleStatus.partnerActor);
    update_player_actor_shadow();
}

void func_80255FD8(void) {
}

void appendGfx_npc_actor(b32 isPartner, s32 actorIndex) {
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

    if (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (actor->flags & ACTOR_FLAG_SHOW_STATUS_ICONS)) {
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
                (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (actor->flags & ACTOR_FLAG_SHOW_STATUS_ICONS)))
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
            part->flags |= ACTOR_PART_FLAG_TRANSPARENT;
        } else {
            part->flags &= ~ACTOR_PART_FLAG_TRANSPARENT;
        }

        do {
            lastAnim = part->curAnimation;
            animChanged = FALSE;
            palChanged = FALSE;
            decorChanged = FALSE;
        } while (0); // required to match

        if (isPartner) {
            if (!(gBattleStatus.flags2 & (BS_FLAGS2_OVERRIDE_INACTIVE_PARTNER))
                && (gBattleStatus.flags2 & BS_FLAGS2_PARTNER_TURN_USED)
            ) {
                do {
                    if (actor->koStatus == 0) {
                        part->curAnimation = get_npc_anim_for_status(part->idleAnimations, STATUS_KEY_INACTIVE);
                        spr_update_sprite(part->spriteInstanceID, part->curAnimation, part->animationRate);
                        animChanged = TRUE;
                    }
                } while (0); // required to match
                set_actor_pal_adjustment(actor, ACTOR_PAL_ADJUST_PLAYER_DEBUFF);
                palChanged = TRUE;
                set_actor_glow_pal(actor, GLOW_PAL_OFF);
                decorChanged = TRUE;
            }
            if (isPartner && (gPlayerData.curPartner == PARTNER_WATT)) {
                if (!palChanged) {
                    set_actor_pal_adjustment(actor, ACTOR_PAL_ADJUST_WATT_IDLE);
                }
                palChanged = TRUE;
            }
        }
        if (actor->isGlowing) {
            if (!decorChanged) {
                set_actor_glow_pal(actor, GLOW_PAL_ON);
            }
            decorChanged = TRUE;
        }
        if (actor->debuff == STATUS_KEY_POISON) {
            if (!palChanged) {
                set_actor_pal_adjustment(actor, ACTOR_PAL_ADJUST_POISON);
            }
            palChanged = TRUE;
        }
        if (actor->debuff == STATUS_KEY_PARALYZE) {
            if (!palChanged) {
                set_actor_pal_adjustment(actor, ACTOR_PAL_ADJUST_PARALYZE);
            }
            palChanged = TRUE;
        }
        if (actor->debuff == STATUS_KEY_FEAR) {
            if (!palChanged) {
                set_actor_pal_adjustment(actor, ACTOR_PAL_ADJUST_FEAR);
            }
            palChanged = TRUE;
        }
        if (actor->staticStatus == STATUS_KEY_STATIC) {
            if (!palChanged) {
                set_actor_pal_adjustment(actor, ACTOR_PAL_ADJUST_STATIC);
            }
            palChanged = TRUE;
        }
        if (!palChanged && !(part->flags & ACTOR_PART_FLAG_HAS_PAL_EFFECT)) {
            set_actor_pal_adjustment(actor, ACTOR_PAL_ADJUST_NONE);
        }
        if (!decorChanged && !(part->flags & ACTOR_PART_FLAG_HAS_PAL_EFFECT)) {
            set_actor_glow_pal(actor, GLOW_PAL_OFF);
        }

        // adjust idle animation for status
        if (actor->flags & ACTOR_FLAG_USING_IDLE_ANIM) {
            if (!(part->flags & ACTOR_PART_FLAG_NO_STATUS_ANIMS)) {
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

        if (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (actor->flags & ACTOR_FLAG_SHOW_STATUS_ICONS)) {
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
            if ((actor->transparentStatus == STATUS_KEY_TRANSPARENT) || (part->flags & ACTOR_PART_FLAG_TRANSPARENT)) {
                create_status_transparent(actor->hudElementDataIndex, STATUS_KEY_TRANSPARENT);
            }
            if (actor->chillOutAmount != 0) {
                create_status_chill_out(actor->hudElementDataIndex);
            }
        } else {
            enable_status_debuff(actor->hudElementDataIndex);
            enable_status_static(actor->hudElementDataIndex);
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
                update_part_glow(TRUE, part, partYaw, FALSE);
                update_part_flash(TRUE, part, partYaw, FALSE);
                render_with_adjusted_palettes(SPRITE_MODE_NPC, part, partYaw, mtxTransform, 0);
            } else {
                update_part_glow(TRUE, part, clamp_angle(180.0f - partYaw), FALSE);
                update_part_flash(TRUE, part, clamp_angle(180.0f - partYaw), FALSE);
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
            update_part_glow(TRUE, part, partYaw, TRUE);
            update_part_flash(TRUE, part, partYaw, TRUE);
            render_with_adjusted_palettes(SPRITE_MODE_NPC, part, partYaw, mtxTransform, 1);
        } else {
            update_part_glow(TRUE, part, clamp_angle(partYaw + 180.0f), TRUE);
            update_part_flash(TRUE, part, clamp_angle(partYaw + 180.0f), TRUE);
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
        update_player_actor_blur_history(player);
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

    if (parts->opacity >= 255 && !(parts->flags & ACTOR_PART_FLAG_TRANSPARENT)) {
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
    s32 animChanged, palChanged, decorChanged, cond4;
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

    if (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_SHOW_STATUS_ICONS)) {
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
            (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_SHOW_STATUS_ICONS)))
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
            (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_SHOW_STATUS_ICONS)))
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
                (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_SHOW_STATUS_ICONS)))
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

    if (!(gBattleStatus.flags2 & BS_FLAGS2_HIDE_BUFF_COUNTERS)
        && !(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN)
        && (player->flags & ACTOR_FLAG_SHOW_STATUS_ICONS)
    ) {
        battleStatus->buffEffect->data.partnerBuff->visible = TRUE;
    } else {
        battleStatus->buffEffect->data.partnerBuff->visible = FALSE;
    }

    do {
        if (player->debuff == STATUS_KEY_SHRINK) {
            player->scalingFactor += (0.4 - player->scalingFactor) / 6.0;
        } else {
            player->scalingFactor += (1.0 - player->scalingFactor) / 6.0;
        }
    } while (0); // required to match

    if (player->flags & ACTOR_FLAG_SHOW_STATUS_ICONS) {
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

    if ((player->flags & ACTOR_FLAG_SHOW_STATUS_ICONS) && !(gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE)) {
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
        playerParts->flags |= ACTOR_PART_FLAG_TRANSPARENT;

        if (FALSE) { // TODO required to match - also whyyyyyy compiler, whyyyyy
    back:
            playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_STOP);
            create_status_debuff(player->hudElementDataIndex, STATUS_KEY_STOP);
            goto end;
        }
    } else {
        playerParts->flags &= ~ACTOR_PART_FLAG_TRANSPARENT;
    }

    do {
        animChanged = FALSE;
        palChanged = FALSE;
        decorChanged = FALSE;
        cond4 = FALSE;
        lastAnim = playerParts->curAnimation;
    } while (0); // required to match

    if ((((!(gBattleStatus.flags2 & BS_FLAGS2_OVERRIDE_INACTIVE_PLAYER)
            && (gBattleStatus.flags2 & BS_FLAGS2_PLAYER_TURN_USED))
                && (partner != NULL))
            || (battleStatus->outtaSightActive > 0))
        && !(player->flags & ACTOR_FLAG_NO_INACTIVE_ANIM)
        && !((partner != NULL) && (partner->flags & ACTOR_FLAG_NO_ATTACK))
    ) {
        if (!(gBattleStatus.flags2 & BS_FLAGS2_NO_PLAYER_PAL_ADJUST)) {
            if ((player->debuff != STATUS_KEY_FEAR)
                && (player->debuff != STATUS_KEY_PARALYZE)
                && (player->debuff != STATUS_KEY_FROZEN)
                && (player->debuff != STATUS_KEY_STOP)
            ) {
                if ((player->transparentStatus != STATUS_KEY_TRANSPARENT) &&
                    (player->stoneStatus != STATUS_KEY_STONE) &&
                    ((battleStatus->outtaSightActive > 0) || (gBattleStatus.flags2 & BS_FLAGS2_PLAYER_TURN_USED)))
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
                set_actor_pal_adjustment(player, ACTOR_PAL_ADJUST_PLAYER_DEBUFF);
            } else {
                set_actor_pal_adjustment(player, ACTOR_PAL_ADJUST_PLAYER_POISON);
            }
            palChanged = TRUE;

            set_actor_glow_pal(player, GLOW_PAL_OFF);
            decorChanged = TRUE;
        }
    }

    if (player->stoneStatus == STATUS_KEY_STONE) {
        playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_STONE);
        spr_update_player_sprite(PLAYER_SPRITE_MAIN, playerParts->curAnimation, playerParts->animationRate);
        animChanged = TRUE;

        if (!palChanged) {
            set_actor_pal_adjustment(player, ACTOR_PAL_ADJUST_NONE);
        }
        set_actor_glow_pal(player, GLOW_PAL_OFF);
        palChanged = TRUE;
        enable_status_debuff(player->hudElementDataIndex);
        decorChanged = TRUE;
        enable_status_static(player->hudElementDataIndex);
        cond4 = TRUE;

        enable_status_transparent(player->hudElementDataIndex);
        enable_status_chill_out(player->hudElementDataIndex);
    }

    if ((player->flags & ACTOR_FLAG_USING_IDLE_ANIM) && !animChanged) {
        s32 temp = playerParts->curAnimation;
        if (temp == get_player_anim_for_status(STATUS_KEY_STONE)) {
            playerParts->curAnimation = get_player_anim_for_status(STATUS_KEY_NORMAL);
        }
    }

    if (is_ability_active(ABILITY_BERSERKER)) {
        if (!palChanged) {
            set_actor_pal_adjustment(player, ACTOR_PAL_ADJUST_BERSERK);
        }
        palChanged = TRUE;
    }
    if (player->debuff == STATUS_KEY_POISON) {
        if (!palChanged) {
            set_actor_pal_adjustment(player, ACTOR_PAL_ADJUST_POISON);
        }
        palChanged = TRUE;
    }
    if (player->debuff == STATUS_KEY_PARALYZE) {
        if (!palChanged) {
            set_actor_pal_adjustment(player, ACTOR_PAL_ADJUST_PARALYZE);
        }
        palChanged = TRUE;
    }
    if (player->staticStatus == STATUS_KEY_STATIC) {
        if (!palChanged) {
            set_actor_pal_adjustment(player, ACTOR_PAL_ADJUST_STATIC);
        }
        palChanged = TRUE;
    }
    if (battleStatus->turboChargeTurnsLeft != 0) {
        if (!decorChanged) {
            set_actor_glow_pal(player, GLOW_PAL_ON);
        }
        decorChanged = TRUE;
    }
    if (is_ability_active(ABILITY_ZAP_TAP)) {
        if (!palChanged) {
            set_actor_pal_adjustment(player, ACTOR_PAL_ADJUST_STATIC);
        }
        palChanged = TRUE;
    }
    if (!palChanged) {
        set_actor_pal_adjustment(player, ACTOR_PAL_ADJUST_NONE);
    }
    if (!decorChanged) {
        set_actor_glow_pal(player, GLOW_PAL_OFF);
    }
    if (player->flags & ACTOR_FLAG_USING_IDLE_ANIM) {
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
            if ((player->transparentStatus == STATUS_KEY_TRANSPARENT) || (playerParts->flags & ACTOR_PART_FLAG_TRANSPARENT)) {
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

    if (!(gBattleStatus.flags1 & BS_FLAGS1_TATTLE_OPEN) && (player->flags & ACTOR_FLAG_SHOW_STATUS_ICONS)) {
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
        if ((player->transparentStatus == STATUS_KEY_TRANSPARENT) || (playerParts->flags & ACTOR_PART_FLAG_TRANSPARENT)) {
            create_status_transparent(player->hudElementDataIndex, STATUS_KEY_TRANSPARENT);
        }
    } else {
        enable_status_debuff(player->hudElementDataIndex);
        enable_status_static(player->hudElementDataIndex);
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
    update_part_glow(FALSE, playerParts, clamp_angle(playerYaw + 180.0f), FALSE);
    update_part_flash(FALSE, playerParts, clamp_angle(playerYaw + 180.0f), FALSE);
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

    update_part_glow(FALSE, part, clamp_angle(playerYaw + 180.0f), TRUE);
    update_part_flash(FALSE, part, clamp_angle(playerYaw + 180.0f), TRUE);
    render_with_adjusted_palettes(SPRITE_MODE_PLAYER, part, clamp_angle(playerYaw + 180.0f), mtxTransform, TRUE);
}

s32 render_with_adjusted_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    s32 opacity;
    s32 sprDrawOpts;

    if (part->flags & ACTOR_PART_FLAG_NO_DECORATIONS) {
        opacity = 255;
        sprDrawOpts = 0;
        if (part->opacity < 255) {
            sprDrawOpts = DRAW_SPRITE_OVERRIDE_ALPHA;
            opacity = part->opacity;
        }
        if (part->flags & ACTOR_PART_FLAG_TRANSPARENT) {
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
        case ACTOR_PAL_ADJUST_NONE:
            render_without_adjusted_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_SLEEP:
            render_with_sleep_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_STATIC:
            render_with_static_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_FEAR:
            render_with_fear_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_POISON:
            render_with_poison_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_PARALYZE:
            render_with_paralyze_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_BERSERK:
            render_with_berserk_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_WATT_IDLE:
            render_with_watt_idle_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_WATT_ATTACK:
            render_with_watt_attack_palettes(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_PLAYER_DEBUFF:
            render_with_player_debuff_palettes(isNpcSprite, part, yaw, mtx, skipAnimation, FALSE);
            break;
        case ACTOR_PAL_ADJUST_PLAYER_POISON:
            render_with_player_debuff_palettes(isNpcSprite, part, yaw, mtx, skipAnimation, TRUE);
            break;
        case ACTOR_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS:
            render_with_pal_blending(isNpcSprite, part, yaw, FALSE, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS:
            render_with_pal_blending(isNpcSprite, part, yaw, TRUE, mtx, skipAnimation);
            break;
        case ACTOR_PAL_ADJUST_BLEND_PALSETS:
            render_with_palset_blending(isNpcSprite, part, yaw, mtx, skipAnimation);
            break;
        default:
            break;
    }
    return 0;
}

void make_flash_palettes(ActorPart* part) {
    DecorationTable* decorations = part->decorationTable;
    PAL_PTR src;
    PAL_PTR dest;
    s32 i, j;

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        if (decorations->adjustedPalettes[i] != NULL) {
            src = decorations->adjustedPalettes[i];
            dest = decorations->copiedPalettes[1][i];

            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *dest = *src | 0xFFFE; // pure white, not affecting alpha bit
                src++;
                dest++;

            }
            decorations->flashPalettes[i] = decorations->copiedPalettes[1][i];
        }
    }
}

void func_unkA_draw_npc(ActorPart* part, s32 yaw, Matrix4f mtx) {
    DecorationTable* decorations = part->decorationTable;
    s32 opacity = 255;
    s32 idMask = 0;
    PAL_PTR dest;
    PAL_PTR src;
    s32 i, j;

    if (part->opacity < 255) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = part->opacity;
    }
    if (part->flags & ACTOR_PART_FLAG_TRANSPARENT) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = (opacity * 120) / 255;
    }

    if (decorations->flashEnabled != FLASH_PAL_OFF) {
        decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 0x10);
        decorations->originalPalettesCount = 0;
        while (decorations->originalPalettesList[decorations->originalPalettesCount] != (PAL_PTR) -1) {
            decorations->originalPalettesCount++;
        }

        for (i = 0; i < decorations->originalPalettesCount; i++) {
            src = decorations->originalPalettesList[i];
            dest = decorations->copiedPalettes[0][i];
            if (src != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorations->copiedPalettes[0][i]); j++) {
                    *dest = *src;
                    src++;
                    dest++;
                }
            }
        }

        for (i = 0; i < decorations->originalPalettesCount; i++) {
            decorations->adjustedPalettes[i] = decorations->copiedPalettes[0][i];
        }

        func_unkB_draw_npc(part, yaw, mtx);
    } else {
        spr_draw_npc_sprite(part->spriteInstanceID | idMask, yaw, opacity, NULL, mtx);
    }
}

void func_unkB_draw_npc(ActorPart* part, s32 yaw, Matrix4f mtx) {
    DecorationTable* decorations = part->decorationTable;
    s32 opacity = 255;
    s32 idMask = 0;

    if (part->opacity < 255) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = part->opacity;
    }

    if (part->flags & ACTOR_PART_FLAG_TRANSPARENT) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = (opacity * 120) / 255;
    }

    if (decorations->flashEnabled != FLASH_PAL_OFF) {
        make_flash_palettes(part);
        spr_draw_npc_sprite(part->spriteInstanceID | DRAW_SPRITE_OVERRIDE_PALETTES | idMask, yaw, opacity, decorations->flashPalettes, mtx);
    } else {
        spr_draw_npc_sprite(part->spriteInstanceID | DRAW_SPRITE_OVERRIDE_PALETTES | idMask, yaw, opacity, decorations->adjustedPalettes, mtx);
    }
}

void func_unkA_draw_player(ActorPart* part, s32 yaw, Matrix4f mtx) {
    DecorationTable* decorations = part->decorationTable;
    s32 opacity = 255;
    s32 idMask = 0;
    PAL_PTR src;
    PAL_PTR dest;
    s32 i, j;

    if (part->opacity < 255) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = part->opacity;
    }
    if (part->flags & ACTOR_PART_FLAG_TRANSPARENT) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = (opacity * 120) / 255;
    }

    if (decorations->flashEnabled != FLASH_PAL_OFF) {
        decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
        decorations->originalPalettesCount = 0;

        while (decorations->originalPalettesList[decorations->originalPalettesCount] != (PAL_PTR) -1) {
            decorations->originalPalettesCount++;
        }

        for (i = 0; i < decorations->originalPalettesCount; i++) {
            src = decorations->originalPalettesList[i];
            dest = decorations->copiedPalettes[0][i];
            if (decorations->originalPalettesList[i] != NULL) {
                for (j = 0; j < ARRAY_COUNT(decorations->copiedPalettes[0][i]); j++) {
                    *dest = *src;
                    dest++;
                    src++;
                }
            }
        }
        for (i = 0; i < decorations->originalPalettesCount; i++) {
            decorations->adjustedPalettes[i] = decorations->copiedPalettes[0][i];
        }
        func_unkB_draw_player(part, yaw, mtx);
    } else {
        spr_draw_player_sprite(PLAYER_SPRITE_MAIN | idMask, yaw, opacity, NULL, mtx);
    }
}

void func_unkB_draw_player(ActorPart* part, s32 yaw, Matrix4f mtx) {
    DecorationTable* decorations = part->decorationTable;
    s32 opacity = 255;
    s32 idMask = 0;

    if (part->opacity < 255) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = part->opacity;
    }
    if (part->flags & ACTOR_PART_FLAG_TRANSPARENT) {
        idMask = DRAW_SPRITE_OVERRIDE_ALPHA;
        opacity = (opacity * 120) / 255;
    }

    if (decorations->flashEnabled != FLASH_PAL_OFF) {
        make_flash_palettes(part);
        idMask |= DRAW_SPRITE_OVERRIDE_PALETTES;
        spr_draw_player_sprite(PLAYER_SPRITE_MAIN | idMask, yaw, opacity, decorations->flashPalettes, mtx);
    } else {
        idMask |= DRAW_SPRITE_OVERRIDE_PALETTES;
        spr_draw_player_sprite(PLAYER_SPRITE_MAIN | idMask, yaw, opacity, decorations->adjustedPalettes, mtx);
    }
}

void render_without_adjusted_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;

    if (decorations->resetPalAdjust) {
        part->verticalStretch = 1;
        part->palAnimPosOffset[0] = 0;
        part->palAnimPosOffset[1] = 0;
        decorations->resetPalAdjust = FALSE;
    }
    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_unkA_draw_player(part, yaw, mtx);
    } else {
        func_unkA_draw_npc(part, yaw, mtx);
    }
}

void render_with_sleep_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;
    s32 i, j;

    if (decorations->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
        }
        decorations->palAnimState = 0;
        decorations->resetPalAdjust = FALSE;
    }

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        PAL_PTR palIn = decorations->originalPalettesList[i];
        PAL_PTR palOut = decorations->copiedPalettes[0][i];
        decorations->adjustedPalettes[i] = palOut;
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
    switch (decorations->palAnimState) {
        case 0:
        case 1:
            if (isNpcSprite == SPRITE_MODE_PLAYER) {
                func_unkB_draw_player(part, yaw, mtx);
            } else {
                func_unkB_draw_npc(part, yaw, mtx);
            }
            break;
    }
}

void render_with_static_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;
    s32 paletteType;
    s32 staticPalIdx;

    if (decorations->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        for (i = 0; i < decorations->originalPalettesCount; i++) {
            palIn = decorations->originalPalettesList[i];
            palOut = decorations->copiedPalettes[0][i];
            if (palIn != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *palOut++ = *palIn++;
                }
            }
        }

        decorations->palAnimState = -2;
        decorations->palBlendAlpha = 0;
        decorations->resetPalAdjust = FALSE;
        decorations->nextPalTime = 0;
    }

    if (!skipAnimation) {
        if (decorations->nextPalTime == 0) {
            decorations->palAnimState += 2;
            if (StaticPalettesAnim[decorations->palAnimState] == PAL_ANIM_END) {
                decorations->palAnimState = 0;
            }
            decorations->nextPalTime = StaticPalettesAnim[decorations->palAnimState + 1] / 2;
        }
        paletteType = StaticPalettesAnim[decorations->palAnimState];
        decorations->nextPalTime--;
    } else {
        paletteType = StaticPalettesAnim[decorations->palAnimState];
    }

    switch (paletteType) {
        case STATIC_DEFAULT: // no change
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                palIn = decorations->originalPalettesList[i];
                palOut = decorations->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case STATIC_BRIGHT: // bright yellow
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                staticPalIdx = decorations->spriteColorVariations * STANDARD_PAL_STATIC + i;
                palIn = decorations->originalPalettesList[staticPalIdx];
                palOut = decorations->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case STATIC_DARK: // darkened via code
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                palIn = decorations->originalPalettesList[i];
                palOut = decorations->copiedPalettes[0][i];
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

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        decorations->adjustedPalettes[i] = decorations->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_unkB_draw_player(part, yaw, mtx);
    } else {
        func_unkB_draw_npc(part, yaw, mtx);
    }

    if (!skipAnimation) {
        decorations->palBlendAlpha--;
    }
}

void render_with_fear_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;
    s32 temp;

    if (decorations->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 2;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
        }

        decorations->palAnimState = 0;
        decorations->palBlendAlpha = 0;
        decorations->nextPalTime = 0;
        decorations->resetPalAdjust = FALSE;
    }

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        palIn = decorations->originalPalettesList[i];
        palOut = decorations->copiedPalettes[0][i];
        decorations->adjustedPalettes[i] = palOut;
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

    if (decorations->nextPalTime <= 0) {
        part->palAnimPosOffset[0] = FearPaletteAnimXOffsets[abs(decorations->nextPalTime)];
        if (part->palAnimPosOffset[0] == PAL_ANIM_END) {
            part->palAnimPosOffset[0] = 0;
            // 30-90
            decorations->nextPalTime = rand_int(60) + 30;
        }
    }

    if (!skipAnimation) {
        decorations->nextPalTime--;
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_unkB_draw_player(part, yaw, mtx);
    } else {
        func_unkB_draw_npc(part, yaw, mtx);
    }
}

void render_with_poison_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;

    if (decorations->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        decorations->palAnimState = 0;
        decorations->palBlendAlpha = 0;
        decorations->resetPalAdjust = FALSE;
    }

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        palIn = decorations->originalPalettesList[i];
        palOut = decorations->copiedPalettes[0][i];
        if (palIn != NULL) {
            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *palOut++ = *palIn++;
            }
        }
    }
    for (i = 0; i < decorations->spriteColorVariations; i++) {
        palIn = decorations->originalPalettesList[decorations->spriteColorVariations + i];
        palOut = decorations->copiedPalettes[0][i];
        if (palIn != NULL) {
            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *palOut++ = *palIn++;
            }
        }
    }

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        decorations->adjustedPalettes[i] = decorations->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_unkB_draw_player(part, yaw, mtx);
    } else {
        func_unkB_draw_npc(part, yaw, mtx);
    }
}

void render_with_paralyze_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;

    if (decorations->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
        }

        decorations->palAnimState = 0;
        decorations->nextPalTime = 0;
        decorations->palBlendAlpha = 10;
        decorations->resetPalAdjust = FALSE;
    }

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        palIn = decorations->originalPalettesList[i];
        palOut = decorations->copiedPalettes[0][i];
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

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        decorations->adjustedPalettes[i] = decorations->copiedPalettes[0][i];
    }

    switch (decorations->palAnimState) {
        case 0:
        case 1:
            if (decorations->nextPalTime <= 0) {
                part->palAnimPosOffset[1] = ParalyzePaletteAnimXOffsets[abs(decorations->nextPalTime)];
                if (part->palAnimPosOffset[1] == PAL_ANIM_END) {
                    part->palAnimPosOffset[1] = 0;
                    decorations->nextPalTime = rand_int(60) + 30; // 30-90
                }
            }

            if (!skipAnimation) {
                decorations->nextPalTime--;
            }

            switch (decorations->palBlendAlpha) {
                case 10:
                case 12:
                    if (isNpcSprite == SPRITE_MODE_PLAYER) {
                        func_unkB_draw_player(part, yaw, mtx);
                    } else {
                        func_unkB_draw_npc(part, yaw, mtx);
                    }
                    break;
                case 13:
                    decorations->palBlendAlpha = 0;
                    // fallthrough
                default:
                    if (isNpcSprite == SPRITE_MODE_PLAYER) {
                        func_unkA_draw_player(part, yaw, mtx);
                    } else {
                        func_unkA_draw_npc(part, yaw, mtx);
                    }
                    break;
            }

            if (!skipAnimation) {
                decorations->palBlendAlpha++;
            }
            break;
    }
}

void render_with_berserk_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;
    s32 i, j;

    if (decorations->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->palAnimState = 0;
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->palAnimState = 0;
        }
        decorations->palBlendAlpha = 0;
        decorations->palAnimState = 0;
        decorations->resetPalAdjust = FALSE;
    }

    // adjust each palette
    for (i = 0; i < decorations->originalPalettesCount; i++) {
        PAL_PTR palIn = decorations->originalPalettesList[i];
        PAL_PTR palOut = decorations->copiedPalettes[0][i];
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

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        decorations->adjustedPalettes[i] = decorations->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_unkB_draw_player(part, yaw, mtx);
    } else {
        func_unkB_draw_npc(part, yaw, mtx);
    }
}

void render_with_watt_idle_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;
    s32 palIdx;
    s32 brightnessLevel;

    if (decorations->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        for (i = 0; i < decorations->originalPalettesCount; i++) {
            palIn = decorations->originalPalettesList[i];
            palOut = decorations->copiedPalettes[0][i];
            if (palIn != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *palOut++ = *palIn++;
                }
            }
        }

        decorations->palAnimState = -2;
        decorations->palBlendAlpha = 0;
        decorations->resetPalAdjust = FALSE;
        decorations->nextPalTime = 0;
    }

    if (!skipAnimation) {
        if (decorations->nextPalTime == 0) {
            decorations->palAnimState += 2;
            if (bWattIdlePalettesAnim[decorations->palAnimState] == PAL_ANIM_END) {
                decorations->palAnimState = 0;
            }
            decorations->nextPalTime = bWattIdlePalettesAnim[decorations->palAnimState + 1] / 2;
        }
        brightnessLevel = bWattIdlePalettesAnim[decorations->palAnimState];
        decorations->nextPalTime--;
    } else {
        //@bug if only called with skipAnimation set, palAnimPos will always be -2 and the array access is OOB
        brightnessLevel = bWattIdlePalettesAnim[decorations->palAnimState];
    }

    switch (brightnessLevel) {
        case WATT_DEFAULT:
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                // use watt's base palettes
                palIn = decorations->originalPalettesList[i];
                palOut = decorations->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case WATT_BRIGHTEST:
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                // use watt's Brightest palettes
                palIdx = decorations->spriteColorVariations * SPR_PAL_BattleWatt_Brightest + i;
                palIn = decorations->originalPalettesList[palIdx];
                palOut = decorations->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case WATT_BRIGHTER:
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                // use watt's Brighter palettes
                palIdx = decorations->spriteColorVariations * SPR_PAL_BattleWatt_Brighter + i;
                palIn = decorations->originalPalettesList[palIdx];
                palOut = decorations->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
    }

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        decorations->adjustedPalettes[i] = decorations->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_unkB_draw_player(part, yaw, mtx);
    } else {
        func_unkB_draw_npc(part, yaw, mtx);
    }

    if (!skipAnimation) {
        decorations->palBlendAlpha--;
    }
}

void render_with_watt_attack_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;
    PAL_PTR palIn;
    PAL_PTR palOut;
    s32 i, j;
    s32 palIdx;
    s32 brightness;

    if (decorations->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        for (i = 0; i < decorations->originalPalettesCount; i++) {
            palIn = decorations->originalPalettesList[i];
            palOut = decorations->copiedPalettes[0][i];
            if (palIn != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *palOut++ = *palIn++;
                }
            }
        }

        decorations->palAnimState = -2;
        decorations->palBlendAlpha = 0;
        decorations->resetPalAdjust = FALSE;
        decorations->nextPalTime = 0;
    }

    if (!skipAnimation) {
        if (decorations->nextPalTime == 0) {
            decorations->palAnimState += 2;
            if (WattAttackPalettesAnim[decorations->palAnimState] == PAL_ANIM_END) {
                decorations->palAnimState = 0;
            }
            decorations->nextPalTime = WattAttackPalettesAnim[decorations->palAnimState + 1] / 2;
        }
        brightness = WattAttackPalettesAnim[decorations->palAnimState];
        decorations->nextPalTime--;
    } else {
        //@bug if only called with skipAnimation set, palAnimPos will always be -2 and the array access is OOB
        brightness = WattAttackPalettesAnim[decorations->palAnimState];
    }

    switch (brightness) {
        case WATT_DEFAULT:
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                palIn = decorations->originalPalettesList[i];
                palOut = decorations->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case WATT_BRIGHTEST:
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                // use watt's Brightest palettes
                palIdx = decorations->spriteColorVariations * SPR_PAL_BattleWatt_Brightest + i;
                palIn = decorations->originalPalettesList[palIdx];
                palOut = decorations->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
        case WATT_BRIGHTER:
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                // use watt's Brighter palettes
                palIdx = decorations->spriteColorVariations * SPR_PAL_BattleWatt_Brighter + i;
                palIn = decorations->originalPalettesList[palIdx];
                palOut = decorations->copiedPalettes[0][i];
                if (palIn != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *palOut++ = *palIn++;
                    }
                }
            }
            break;
    }

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        decorations->adjustedPalettes[i] = decorations->copiedPalettes[0][i];
    }

    if (isNpcSprite == SPRITE_MODE_PLAYER) {
        func_unkB_draw_player(part, yaw, mtx);
    } else {
        func_unkB_draw_npc(part, yaw, mtx);
    }

    if (!skipAnimation) {
        decorations->palBlendAlpha--;
    }
}

void render_with_player_debuff_palettes(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation, b32 isPoison) {
    DecorationTable* decorations = part->decorationTable;
    PAL_PTR color2;
    PAL_PTR color1;
    PAL_PTR palOut;
    s32 i, j;
    u8 blendAlpha;

    if (decorations->resetPalAdjust) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }

            if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                decorations->spriteColorVariations = SPR_PEACH_BTL_PAL_STRIDE;
            } else {
                decorations->spriteColorVariations = SPR_PLAYER_COLOR_VARIATIONS;
            }
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
            decorations->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        if (decorations->resetPalAdjust == TRUE) {
            decorations->palAnimState = 0;
            decorations->palBlendAlpha = 0;
        } else {
            decorations->palAnimState = 0;
            decorations->palBlendAlpha = 255;
        }

        for (i = 0; i < decorations->originalPalettesCount; i++) {
            color2 = decorations->originalPalettesList[i];
            color1 = decorations->copiedPalettes[0][i];
            decorations->adjustedPalettes[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *color1++ = *color2++;
                }
            }
        }

        if (isPoison) {
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                color2 = decorations->originalPalettesList[decorations->spriteColorVariations + i];
                palOut = decorations->copiedPalettes[0][i];
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *palOut++ = *color2++;
                }
            }
        }

        decorations->nextPalTime = 10;
        decorations->palBlendAlpha = 0;
        decorations->palAnimState = 0;
        decorations->resetPalAdjust = FALSE;
    }

    if (decorations->palAnimState == 0) {
        if (!skipAnimation && decorations->nextPalTime != 0) {
            decorations->nextPalTime--;
        } else {
            if (!skipAnimation) {
                decorations->palBlendAlpha += 2560;
                if (decorations->palBlendAlpha > 255 * 100) {
                    decorations->palBlendAlpha = 255 * 100;
                }
            }
            blendAlpha = decorations->palBlendAlpha / 100;
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                if (!isPoison) {
                    color2 = decorations->originalPalettesList[i];
                } else {
                    color2 = decorations->originalPalettesList[decorations->spriteColorVariations * STANDARD_PAL_POISON + i];
                }
                color1 = decorations->originalPalettesList[decorations->spriteColorVariations * STANDARD_PAL_DIZZY + i];
                palOut = decorations->copiedPalettes[0][i];

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
                decorations->palAnimState = 1;
            }
        }
    }

    for (i = 0; i < decorations->originalPalettesCount; i++) {
        decorations->adjustedPalettes[i] = decorations->copiedPalettes[0][i];
    }

    switch (decorations->palAnimState) {
        case 0:
        case 1:
            if (isNpcSprite == SPRITE_MODE_PLAYER) {
                func_unkB_draw_player(part, yaw, mtx);
            } else {
                func_unkB_draw_npc(part, yaw, mtx);
            }
            break;
    }
}

void render_with_pal_blending(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 hasDifferentIntervals, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;
    PAL_PTR color1;
    PAL_PTR color2;
    PAL_PTR outColor;
    s32 i, j;
    u8 blendAlpha;
    u8 r2, g2, b2, a1;
    u8 r1, g1, b1;

    if (decorations->resetPalAdjust != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while ((s32)decorations->originalPalettesList[decorations->originalPalettesCount] != -1) {
                decorations->originalPalettesCount++;
            }
        }

        if (decorations->resetPalAdjust == 1) {
            decorations->palAnimState = 0;
            decorations->palBlendAlpha = 0;
        } else {
            decorations->palAnimState = 0;
            decorations->palBlendAlpha = 255;
        }

        for (i = 0; i < decorations->originalPalettesCount; i++) {
            color2 = decorations->originalPalettesList[i];
            color1 = decorations->copiedPalettes[0][i];
            decorations->adjustedPalettes[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *color1++ = *color2++;
                }
            }
        }

        if (!hasDifferentIntervals) {
            decorations->palswapTimeAtoB = decorations->palswapTimeHoldA;
            decorations->palswapTimeHoldB = decorations->palswapTimeAtoB;
            decorations->palswapTimeBtoA = decorations->palswapTimeAtoB;
            decorations->palswapTimeHoldA = 0;
        }

        decorations->nextPalTime = decorations->palswapTimeHoldA;
        decorations->palBlendAlpha = 0;
        decorations->palAnimState = PAL_SWAP_HOLD_A;
        decorations->resetPalAdjust = FALSE;
    }

    // blending from A -> B
    switch (decorations->palAnimState) {
        case PAL_SWAP_HOLD_A:
            if (skipAnimation) {
                break;
            }
            if (decorations->nextPalTime != 0) {
                decorations->nextPalTime--;
                break;
            }
            decorations->palBlendAlpha = 0;
            decorations->palAnimState = PAL_SWAP_A_TO_B;
            // fallthrough
        case PAL_SWAP_A_TO_B:
            if (!skipAnimation) {
                decorations->palBlendAlpha += 25600 / decorations->palswapTimeAtoB;
                if (decorations->palBlendAlpha > 255 * 100) {
                    decorations->palBlendAlpha = 255 * 100;
                }
            }
            blendAlpha = decorations->palBlendAlpha / 100;
            // blend two palettes
            color2 = decorations->originalPalettesList[decorations->blendPalA];
            color1 = decorations->originalPalettesList[decorations->blendPalB];
            outColor = decorations->adjustedPalettes[0] = decorations->copiedPalettes[0][0];

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
                decorations->palAnimState = PAL_SWAP_HOLD_B;
                decorations->nextPalTime = decorations->palswapTimeHoldB;
            }
            break;
    }

    // blending from B -> A
    switch (decorations->palAnimState) {
        case PAL_SWAP_HOLD_B:
            if (skipAnimation) {
                break;
            }
            if (decorations->nextPalTime != 0) {
                decorations->nextPalTime--;
                break;
            }
            decorations->palBlendAlpha = 0;
            decorations->palAnimState = PAL_SWAP_B_TO_A;
            // fallthrough
        case PAL_SWAP_B_TO_A:
            if (!skipAnimation) {
                decorations->palBlendAlpha += 25600 / decorations->palswapTimeBtoA;
                if (decorations->palBlendAlpha > 255 * 100) {
                    decorations->palBlendAlpha = 255 * 100;
                }
            }
            blendAlpha = decorations->palBlendAlpha / 100;
            // blend two palettes
            color2 = decorations->originalPalettesList[decorations->blendPalB];
            color1 = decorations->originalPalettesList[decorations->blendPalA];
            outColor = decorations->copiedPalettes[0][0];
            decorations->adjustedPalettes[0] = outColor;

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
                decorations->palAnimState = PAL_SWAP_HOLD_A;
                decorations->nextPalTime = decorations->palswapTimeHoldA;
            }
            break;
    }

    switch (decorations->palAnimState) {
        case PAL_SWAP_HOLD_A:
        case PAL_SWAP_A_TO_B:
        case PAL_SWAP_HOLD_B:
        case PAL_SWAP_B_TO_A:
            if (isNpcSprite == SPRITE_MODE_PLAYER) {
                func_unkB_draw_player(part, yaw, mtx);
            } else {
                func_unkB_draw_npc(part, yaw, mtx);
            }
            break;
    }
}

void render_with_palset_blending(b32 isNpcSprite, ActorPart* part, s32 yaw, Matrix4f mtx, b32 skipAnimation) {
    DecorationTable* decorations = part->decorationTable;
    PAL_PTR color1;
    PAL_PTR color2;
    PAL_PTR outColor;
    s32 i, j;
    u8 blendAlpha;
    u8 r2, g2, b2, a1;
    u8 r1, g1, b1;

    // copy palettes from sprite data
    if (decorations->resetPalAdjust != 0) {
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            decorations->originalPalettesList = spr_get_player_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while (decorations->originalPalettesList[decorations->originalPalettesCount] != (PAL_PTR) -1) {
                decorations->originalPalettesCount++;
            }
        } else {
            decorations->originalPalettesList = spr_get_npc_palettes(part->curAnimation >> 16);
            decorations->originalPalettesCount = 0;
            while (decorations->originalPalettesList[decorations->originalPalettesCount] != (PAL_PTR) -1) {
                decorations->originalPalettesCount++;
            }
            decorations->spriteColorVariations = spr_get_npc_color_variations(part->curAnimation >> 16);
        }

        if (decorations->resetPalAdjust == 1) {
            decorations->palAnimState = PAL_SWAP_HOLD_A;
            decorations->palBlendAlpha = 0;
        } else {
            decorations->palAnimState = PAL_SWAP_HOLD_A;
            decorations->palBlendAlpha = 255;
        }

         for (i = 0; i < decorations->originalPalettesCount; i++) {
            color2 = decorations->originalPalettesList[i];
            color1 = decorations->copiedPalettes[0][i];
            decorations->adjustedPalettes[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *color1++ = *color2++;
                }
            }
        }

        decorations->nextPalTime = decorations->palswapTimeHoldA;
        decorations->palBlendAlpha = 0;
        decorations->palAnimState = PAL_SWAP_HOLD_A;
        decorations->resetPalAdjust = FALSE;
    }

    // blending from A -> B
    switch (decorations->palAnimState) {
        case PAL_SWAP_HOLD_A:
            if (skipAnimation) {
                break;
            }
            if (decorations->nextPalTime != 0) {
                decorations->nextPalTime--;
                break;
            }
            decorations->palBlendAlpha = 0;
            decorations->palAnimState = PAL_SWAP_A_TO_B;
            // fallthrough
        case PAL_SWAP_A_TO_B:
            if (!skipAnimation) {
                decorations->palBlendAlpha += 25600 / decorations->palswapTimeAtoB;
                if (decorations->palBlendAlpha > 255 * 100) {
                    decorations->palBlendAlpha = 255 * 100;
                }
            }
            blendAlpha = decorations->palBlendAlpha / 100;
            // blend all palettes from two palette sets
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                color2 = decorations->originalPalettesList[decorations->blendPalA * decorations->spriteColorVariations + i];
                color1 = decorations->originalPalettesList[decorations->blendPalB * decorations->spriteColorVariations + i];
                outColor = decorations->copiedPalettes[0][i];
                decorations->adjustedPalettes[i] = outColor;

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
                decorations->palAnimState = PAL_SWAP_HOLD_B;
                decorations->nextPalTime = decorations->palswapTimeHoldB;
            }
            break;
    }

    switch (decorations->palAnimState) {
        case PAL_SWAP_HOLD_B:
            if (skipAnimation) {
                break;
            }
            if (decorations->nextPalTime != 0) {
                decorations->nextPalTime--;
                break;
            }
            decorations->palBlendAlpha = 0;
            decorations->palAnimState = PAL_SWAP_B_TO_A;
            // fallthrough
        case PAL_SWAP_B_TO_A:
            if (!skipAnimation) {
                decorations->palBlendAlpha += 25600 / decorations->palswapTimeBtoA;
                if (decorations->palBlendAlpha > 255 * 100) {
                    decorations->palBlendAlpha = 255 * 100;
                }
            }
            blendAlpha = decorations->palBlendAlpha / 100;
            // blend all palettes from two palette sets
            for (i = 0; i < decorations->spriteColorVariations; i++) {
                color2 = decorations->originalPalettesList[decorations->blendPalA * decorations->spriteColorVariations + i];
                color1 = decorations->originalPalettesList[decorations->blendPalB * decorations->spriteColorVariations + i];
                outColor = decorations->copiedPalettes[0][i];
                decorations->adjustedPalettes[i] = outColor;

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
                decorations->palAnimState = PAL_SWAP_HOLD_A;
                decorations->nextPalTime = decorations->palswapTimeHoldA;
            }
            break;
    }

    switch (decorations->palAnimState) {
        case PAL_SWAP_HOLD_A:
        case PAL_SWAP_A_TO_B:
        case PAL_SWAP_HOLD_B:
        case PAL_SWAP_B_TO_A:
            if (isNpcSprite == SPRITE_MODE_PLAYER) {
                func_unkB_draw_player(part, yaw, mtx);
            } else {
                func_unkB_draw_npc(part, yaw, mtx);
            }
            break;
    }
}

s32 update_part_glow(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 isReflection) {
    if (!(part->flags & ACTOR_PART_FLAG_NO_DECORATIONS)) {
        switch (part->decorationTable->glowState) {
            case GLOW_PAL_OFF:
                part_glow_off(isNpcSprite, part, yaw, isReflection);
                return 0;
            case GLOW_PAL_ON:
                part_glow_on(isNpcSprite, part, yaw, isReflection);
                break;
        }
    }
    return 0;
}

void part_glow_off(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 isReflection) {
    if (part->decorationTable->glowStateChanged) {
        part->decorationTable->glowStateChanged = FALSE;
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            set_player_imgfx_all(PLAYER_SPRITE_MAIN, IMGFX_CLEAR, 0, 0, 0, 0, 0);
        } else {
            set_npc_imgfx_all(part->spriteInstanceID, IMGFX_CLEAR, 0, 0, 0, 0, 0);
        }
    }
}

void part_glow_on(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 isReflection) {
    DecorationTable* decorations = part->decorationTable;
    u8 rbuf[20];
    u8 gbuf[20];
    u8 bbuf[20];
    s32 color;
    s32 alpha;
    s32 i;

    if (decorations->glowStateChanged) {
        decorations->glowUnk1 = -2;
        decorations->glowUnk3 = 0;
        decorations->glowStateChanged = FALSE;
        decorations->glowUnk2 = 0;
        if (isNpcSprite == SPRITE_MODE_PLAYER) {
            set_player_imgfx_all(PLAYER_SPRITE_MAIN, IMGFX_ALLOC_COLOR_BUF, 20, 0, 0, 255, 0);
        } else {
            set_npc_imgfx_all(part->spriteInstanceID, IMGFX_ALLOC_COLOR_BUF, 20, 0, 0, 255, 0);
        }
    }

    decorations->glowPhase += 7;

    if (decorations->glowPhase >= 360) {
        decorations->glowPhase %= 360;
    }

    for (i = 0; i < ARRAY_COUNT(rbuf); i++) {
        rbuf[i] = (cosine(decorations->glowPhase + (25 * i)) + 1.0) * 112.0;
        gbuf[i] = (cosine(decorations->glowPhase + (25 * i) + 45) + 1.0) * 112.0;
        bbuf[i] = (cosine(decorations->glowPhase + (25 * i) + 90) + 1.0) * 112.0;
    }

    alpha = 255;
    if (part->opacity < 255) {
        alpha = part->opacity;
    }
    if (part->flags & ACTOR_PART_FLAG_TRANSPARENT) {
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

    if (!isReflection) {
        decorations->glowUnk3 -= 1;
    }
}

s32 update_part_flash(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 isReflection) {
    if (!(part->flags & ACTOR_PART_FLAG_NO_DECORATIONS)) {
        switch (part->decorationTable->flashState) {
            case 0:
                part_flash_off(isNpcSprite, part, yaw, isReflection);
                return 0;
            case 1:
                part_flash_on(isNpcSprite, part, yaw, isReflection);
                return 0;
        }
    }
    return 0;
}

void part_flash_off(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 isReflection) {
    DecorationTable* decorations = part->decorationTable;

    if (decorations->flashStateChanged) {
        decorations->flashStateChanged = FALSE;
    }
    decorations->flashEnabled = FLASH_PAL_OFF;
}

void part_flash_on(b32 isNpcSprite, ActorPart* part, s32 yaw, b32 isReflection) {
    DecorationTable* decorations = part->decorationTable;

    if (decorations->flashStateChanged) {
        switch (get_flash_damage_intensity(part)) {
            case DAMAGE_INTENSITY_LIGHT:
                decorations->flashFramesLeft = 1;
                decorations->flashMode = FLASH_MODE_LIGHT;
                break;
            case DAMAGE_INTENSITY_MEDIUM:
                decorations->flashFramesLeft = 8;
                decorations->flashMode = FLASH_MODE_MEDIUM;
                break;
            case DAMAGE_INTENSITY_HEAVY:
            default:
                decorations->flashFramesLeft = 14;
                decorations->flashMode = FLASH_MODE_HEAVY;
                break;
        }
        decorations->flashEnabled = FLASH_PAL_OFF;
        decorations->flashStateChanged = FALSE;
    }

    if (decorations->flashMode == FLASH_MODE_DISPOSE) {
        decorations->flashEnabled = FLASH_PAL_OFF;
        clear_part_flash_mode(part);
    }

    switch (decorations->flashMode) {
        case FLASH_MODE_LIGHT:
            switch (decorations->flashFramesLeft) {
                case 0:
                    decorations->flashEnabled = FLASH_PAL_ON;
                    decorations->flashMode = FLASH_MODE_DISPOSE;
                    break;
                default:
                    decorations->flashEnabled = FLASH_PAL_OFF;
                    if (!isReflection) {
                        decorations->flashFramesLeft--;
                    }
                    break;
            }
            break;
        case FLASH_MODE_MEDIUM:
           switch (decorations->flashFramesLeft) {
                case 1:
                case 2:
                case 5:
                case 6:
                    decorations->flashEnabled = FLASH_PAL_ON;
                    break;
                case 3:
                case 4:
                case 7:
                case 8:
                    decorations->flashEnabled = FLASH_PAL_OFF;
                    break;
                case 0:
                    decorations->flashMode = FLASH_MODE_DISPOSE;
                    break;
            }
            if (!isReflection) {
                decorations->flashFramesLeft--;
            }
            break;
        case FLASH_MODE_HEAVY:
           switch (decorations->flashFramesLeft) {
                case 1:
                case 2:
                case 5:
                case 6:
                case 9:
                case 10:
                case 13:
                case 14:
                    decorations->flashEnabled = FLASH_PAL_OFF;
                    break;
                case 3:
                case 4:
                case 7:
                case 8:
                case 11:
                case 12:
                    decorations->flashEnabled = FLASH_PAL_ON;
                    break;
                case 0:
                    decorations->flashMode = FLASH_MODE_DISPOSE;
                    break;
            }
            if (!isReflection) {
                decorations->flashFramesLeft--;
            }
            break;
    }
}

void _add_part_decoration(ActorPart* actorPart) {
    DecorationTable* decorations;
    s32 i;

    if (actorPart->flags & ACTOR_PART_FLAG_NO_DECORATIONS) {
        return;
    }

    decorations = actorPart->decorationTable;
    for (i = 0; i < ARRAY_COUNT(decorations->type); i++) {
        switch (decorations->type[i]) {
            case ACTOR_DECORATION_NONE:
                add_part_decor_none(actorPart, i);
                break;
            case ACTOR_DECORATION_GOLDEN_FLAMES:
                add_part_decor_golden_flames(actorPart, i);
                break;
            case ACTOR_DECORATION_SWEAT:
                add_part_decor_sweat(actorPart, i);
                break;
            case ACTOR_DECORATION_SEEING_STARS:
                add_part_decor_seeing_stars(actorPart, i);
                break;
            case ACTOR_DECORATION_RED_FLAMES:
                add_part_decor_red_flames(actorPart, i);
                break;
            case ACTOR_DECORATION_GREY_SMOKE_TRAIL:
                add_part_decor_smoky_trail(actorPart, i);
                break;
            case ACTOR_DECORATION_FIRE_SMOKE_TRAIL:
                add_part_decor_fiery_trail(actorPart, i);
                break;
            case ACTOR_DECORATION_WHIRLWIND:
                add_part_decor_whirlwind(actorPart, i);
                break;
            case ACTOR_DECORATION_STEAM_EMITTER:
                add_part_decor_steam(actorPart, i);
                break;
            case ACTOR_DECORATION_SPARKLES:
                add_part_decor_sparkles(actorPart, i);
                break;
            case ACTOR_DECORATION_BOWSER_AURA:
                add_part_decor_bowser_aura(actorPart, i);
                break;
            case ACTOR_DECORATION_RADIAL_STAR_EMITTER:
                add_part_decor_radiating_stars(actorPart, i);
                break;
        }
    }
}

void _remove_part_decoration(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;

    switch (decorations->type[idx]) {
        case ACTOR_DECORATION_NONE:
            remove_part_decor_none(part, idx);
            break;
        case ACTOR_DECORATION_GOLDEN_FLAMES:
            remove_part_decor_golden_flames(part, idx);
            break;
        case ACTOR_DECORATION_SWEAT:
            remove_part_decor_sweat(part, idx);
            break;
        case ACTOR_DECORATION_SEEING_STARS:
            remove_part_decor_seeing_stars(part, idx);
            break;
        case ACTOR_DECORATION_RED_FLAMES:
            remove_part_decor_red_flames(part, idx);
            break;
        case ACTOR_DECORATION_GREY_SMOKE_TRAIL:
            remove_part_decor_smoky_trail(part, idx);
            break;
        case ACTOR_DECORATION_FIRE_SMOKE_TRAIL:
            remove_part_decor_fiery_trail(part, idx);
            break;
        case ACTOR_DECORATION_WHIRLWIND:
            remove_part_decor_whirlwind(part, idx);
            break;
        case ACTOR_DECORATION_STEAM_EMITTER:
            remove_part_decor_steam(part, idx);
            break;
        case ACTOR_DECORATION_SPARKLES:
            remove_part_decor_sparkles(part, idx);
            break;
        case ACTOR_DECORATION_BOWSER_AURA:
            remove_part_decor_bowser_aura(part, idx);
            break;
        case ACTOR_DECORATION_RADIAL_STAR_EMITTER:
            remove_part_decor_radiating_stars(part, idx);
            break;
    }

    decorations->type[idx] = ACTOR_DECORATION_NONE;
}

void add_part_decor_none(ActorPart* actorPart, s32 i) {
}

void remove_part_decor_none(ActorPart* part, s32 idx) {
}

void add_part_decor_golden_flames(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;
    EffectInstance* effect;
    AuraFXData* data;
    f32 scale;

    switch (decorations->state[idx]) {
        case 0:
            fx_aura(FX_AURA_GOLD, part->curPos.x, part->curPos.y, part->curPos.z, 0.4f, &decorations->effect[idx]);
            decorations->state[idx] = 1;
            decorations->decorData[idx].goldenFlames.scaleX = 40;
            decorations->decorData[idx].goldenFlames.scaleY = 40;
            decorations->decorData[idx].goldenFlames.offsetX = 0;
            break;
        case 1:
            effect = decorations->effect[idx];
            data = effect->data.aura;
            data->posA.x = part->curPos.x + decorations->decorData[idx].goldenFlames.offsetX;
            data->posA.y = part->curPos.y;
            data->posA.z = part->curPos.z;
            scale = decorations->decorData[idx].goldenFlames.scaleX;
            scale /= 100.0f;
            effect->data.aura->scale.x = scale;
            scale = decorations->decorData[idx].goldenFlames.scaleY;
            scale /= 100.0f;
            effect->data.aura->scale.y = scale;
            break;
    }
}

void remove_part_decor_golden_flames(ActorPart* part, s32 idx) {
    part->decorationTable->effect[idx]->data.aura->fadeTime = 5;
}

void add_part_decor_sweat(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;

    switch (decorations->state[idx]) {
        case 0:
            if (part->yaw > 90.0f) {
                fx_sweat(0, part->curPos.x, part->curPos.y + part->size.y, part->curPos.z, 5.0f, 45.0f, 20);
            } else {
                fx_sweat(0, part->curPos.x, part->curPos.y + part->size.y, part->curPos.z, 5.0f, -45.0f, 20);
            }
            decorations->stateResetTimer[idx] = 10;
            decorations->state[idx] = TRUE;
            break;
        case 1:
            if (decorations->stateResetTimer[idx] != 0) {
                decorations->stateResetTimer[idx]--;
            } else {
                decorations->state[idx] = FALSE;
            }
            break;
    }
}

void remove_part_decor_sweat(ActorPart* part, s32 idx) {
}

void add_part_decor_seeing_stars(ActorPart* part, s32 idx) {
    DecorationTable* decorations;
    StarsOrbitingFXData* data;

    decorations = part->decorationTable;
    switch (decorations->state[idx]) {
        case 0:
            fx_stars_orbiting(0, part->curPos.x, part->curPos.y + part->size.y, part->curPos.z, 20.0f, 3, &decorations->effect[idx]);
            decorations->state[idx] = 1;
            break;
        case 1:
            data = decorations->effect[idx]->data.starsOrbiting;
            data->pos.x = part->curPos.x;
            data->pos.y = part->curPos.y + part->size.y;
            data->pos.z = part->curPos.z;
            break;
    }
}

void remove_part_decor_seeing_stars(ActorPart* part, s32 idx) {
    remove_effect(part->decorationTable->effect[idx]);
}

void add_part_decor_red_flames(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;
    EffectInstance* effect;
    AuraFXData* data;
    f32 scale;

    switch (decorations->state[idx]) {
        case 0:
            fx_aura(FX_AURA_RED, part->curPos.x, part->curPos.y, part->curPos.z, 0.4f, &decorations->effect[idx]);
            decorations->state[idx] = 1;
            decorations->decorData[idx].redFlames.scaleX = 40;
            decorations->decorData[idx].redFlames.scaleY = 40;
            decorations->decorData[idx].redFlames.alpha = 255;
            decorations->decorData[idx].redFlames.offsetZ = 0;
            decorations->decorData[idx].redFlames.unused1 = 255;
            decorations->decorData[idx].redFlames.unused2 = 0;
            decorations->decorData[idx].redFlames.unused3 = 0;
            // fallthrough
        case 1:
            effect = decorations->effect[idx];
            data = effect->data.aura;
            data->posA.x = part->curPos.x;
            data->posA.y = part->curPos.y;
            data->posA.z = part->curPos.z + decorations->decorData[idx].redFlames.offsetZ;

            scale = decorations->decorData[idx].redFlames.scaleX;
            scale /= 100.0f;
            effect->data.aura->scale.x = scale;
            scale = decorations->decorData[idx].redFlames.scaleY;
            scale /= 100.0f;
            effect->data.aura->scale.y = scale;
            effect->data.aura->primA = decorations->decorData[idx].redFlames.alpha;
            break;
    }
}

void remove_part_decor_red_flames(ActorPart* part, s32 idx) {
    part->decorationTable->effect[idx]->data.aura->fadeTime = 5;
}

void add_part_decor_smoky_trail(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;
    EffectInstance* effect;

    switch (decorations->state[idx]) {
        case 0:
            decorations->effect[idx] = fx_effect_65(1, part->curPos.x, part->curPos.y, part->curPos.z, 1.0f, 0);
            decorations->state[idx] = 1;
            break;
        case 1:
            effect = decorations->effect[idx];
            effect->data.unk_65->pos.x = part->curPos.x;
            effect->data.unk_65->pos.y = part->curPos.y;
            effect->data.unk_65->pos.z = part->curPos.z;
            break;
    }
}

void remove_part_decor_smoky_trail(ActorPart* part, s32 idx) {
    part->decorationTable->effect[idx]->flags |= FX_INSTANCE_FLAG_DISMISS;
}

void add_part_decor_fiery_trail(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;
    EffectInstance* effect;

    switch (decorations->state[idx]) {
        case 0:
            decorations->effect[idx] = fx_effect_65(2, part->curPos.x, part->curPos.y, part->curPos.z, 1.0f, 0);
            decorations->decorData[idx].fireTrail.scale = 1;
            decorations->state[idx] = 1;
            break;
        case 1:
            effect = decorations->effect[idx];
            effect->data.unk_65->pos.x = part->curPos.x;
            effect->data.unk_65->pos.y = part->curPos.y;
            effect->data.unk_65->pos.z = part->curPos.z;
            effect->data.unk_65->scale = decorations->decorData[idx].fireTrail.scale / 100.0f;
            break;
    }
}

void remove_part_decor_fiery_trail(ActorPart* part, s32 idx) {
    part->decorationTable->effect[idx]->flags |= FX_INSTANCE_FLAG_DISMISS;
}

void add_part_decor_whirlwind(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;
    EffectInstance* effect;

    switch (decorations->state[idx]) {
        case 0:
            decorations->effect[idx] = fx_whirlwind(2, part->curPos.x, part->curPos.y, part->curPos.z, 1.0f, 0);
            decorations->state[idx] = 1;
            break;
        case 1:
            effect = decorations->effect[idx];
            effect->data.whirlwind->pos.x = part->curPos.x;
            effect->data.whirlwind->pos.y = part->curPos.y;
            effect->data.whirlwind->pos.z = part->curPos.z;
            break;
    }
}

void remove_part_decor_whirlwind(ActorPart* part, s32 idx) {
    part->decorationTable->effect[idx]->flags |= FX_INSTANCE_FLAG_DISMISS;
}

void add_part_decor_steam(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;
    f32 angle, sinA, cosA;

    switch (decorations->state[idx]) {
        case 0:
            decorations->stateResetTimer[idx] = 0;
            decorations->state[idx] = 1;
            // fallthrough
        case 1:
            decorations->stateResetTimer[idx]++;
            if (decorations->stateResetTimer[idx] >= 4) {
                decorations->stateResetTimer[idx] = 0;
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

void remove_part_decor_steam(ActorPart* part, s32 idx) {
}

void add_part_decor_sparkles(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;
    f32 x, y, z;

    if (SparkleSpawnIntervals[decorations->decorData[idx].sparkles.spawnInterval] >= 0) {
        switch (decorations->state[idx]) {
            case 0:
                decorations->stateResetTimer[idx] = 0;
                decorations->state[idx] = 1;
                // fallthrough
            case 1:
                x = part->curPos.x;
                y = part->curPos.y + (part->size.y / 2);
                z = part->curPos.z - 5.0f;
                // @bug this should be % 4
                if ((gGameStatusPtr->frameCounter / 4) == 0) {
                    fx_sparkles(FX_SPARKLES_1, x, y, z, 10.0f);
                }
                decorations->stateResetTimer[idx]++;
                if (SparkleSpawnIntervals[decorations->decorData[idx].sparkles.spawnInterval] < decorations->stateResetTimer[idx]) {
                    decorations->stateResetTimer[idx] = 0;
                    fx_sparkles(FX_SPARKLES_1, x, y, z, 20.0f);
                }
                break;
        }
    }
}

void remove_part_decor_sparkles(ActorPart* part, s32 idx) {
}

void add_part_decor_bowser_aura(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;
    EffectInstance* effect;
    AuraFXData* data;
    f32 scale;

    switch (decorations->state[idx]) {
        case 0:
            fx_aura(FX_AURA_BLUE, part->curPos.x, part->curPos.y, part->curPos.z, 1.2f, &decorations->effect[idx]);
            decorations->state[idx] = 1;
            decorations->decorData[idx].bowserAura.scaleX = 150;
            decorations->decorData[idx].bowserAura.scaleY = 150;
            decorations->decorData[idx].bowserAura.alpha = 255;
            decorations->decorData[idx].bowserAura.offsetZ = 0;
            // fallthrough
        case 1:
            effect = decorations->effect[idx];
            data = effect->data.aura;
            data->posA.x = part->curPos.x;
            data->posA.y = part->curPos.y;
            data->posA.z = part->curPos.z + decorations->decorData[idx].bowserAura.offsetZ;

            scale = decorations->decorData[idx].bowserAura.scaleX;
            scale /= 100.0f;
            effect->data.aura->scale.x = scale;
            scale = decorations->decorData[idx].bowserAura.scaleY;
            scale /= 100.0f;
            effect->data.aura->scale.y = scale * (0.8 - 1e-16); // small epsilon
            effect->data.aura->primA = decorations->decorData[idx].bowserAura.alpha;
            effect->data.aura->renderYaw = part->yaw;
            break;
    }
}

void remove_part_decor_bowser_aura(ActorPart* part, s32 idx) {
    part->decorationTable->effect[idx]->data.aura->fadeTime = 5;
}

void add_part_decor_radiating_stars(ActorPart* part, s32 idx) {
    DecorationTable* decorations = part->decorationTable;
    EnergyInOutFXData* data;
    f32 scale;

    switch (decorations->state[idx]) {
        case 0:
            decorations->effect[idx] = fx_energy_in_out(4, part->curPos.x, part->curPos.y, part->curPos.z, 1.2f, 0);
            decorations->state[idx] = 1;
            decorations->decorData[idx].stars.scalePct = 120;
            decorations->decorData[idx].stars.offsetY = 0;
            // fallthrough
        case 1:
            data = decorations->effect[idx]->data.energyInOut;
            scale = decorations->decorData[idx].stars.scalePct;
            scale /= 100.0f;
            data->unk_44 = scale;
            data->pos.x = part->curPos.x;
            data->pos.y = (part->curPos.y + (scale * 41.0f));
            data->pos.z = (part->curPos.z + decorations->decorData[idx].stars.offsetY);
            break;
    }
}

void remove_part_decor_radiating_stars(ActorPart* part, s32 idx) {
    part->decorationTable->effect[idx]->flags |= FX_INSTANCE_FLAG_DISMISS;
}
