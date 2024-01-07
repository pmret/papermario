#include "dro_02.h"
#include "model.h"
#include "sprite/player.h"
#include "include_asset.h"

// cards used during Merlee's ritual
typedef struct RitualCard {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 yaw;
    /* 0x14 */ f32 pitch;
    /* 0x18 */ s32 spriteID;
    /* 0x1C */ s32 rasterIndex;
    /* 0x20 */ s32 xoffset;
} RitualCard; // size = 0x24

BSS Evt* N(CreatorScript);

// this buffer is used as an array in scripts managaing the ritual scene
// values are enumerated below
BSS s32 N(RitualBuffer)[16];

enum {
    RITUAL_VAR_SHUFFLE_IMGFX    = ArrayVar(0),
    RITUAL_VAR_FILP1_IMGFX      = ArrayVar(1),
    RITUAL_VAR_FILP2_IMGFX      = ArrayVar(2),
    RITUAL_VAR_FILP3_IMGFX      = ArrayVar(3),
    RITUAL_VAR_POS_X            = ArrayVar(4),
    RITUAL_VAR_POS_Y            = ArrayVar(5),
    RITUAL_VAR_POS_Z            = ArrayVar(6),
    RITUAL_VAR_WORKER           = ArrayVar(7),
    RITUAL_VAR_ORB_EFFECT       = ArrayVar(8),
    RITUAL_VAR_STATE            = ArrayVar(9),
};

enum {
    RITUAL_STATE_INIT           = 0,
    RITUAL_STATE_APPEAR         = 1,
    RITUAL_STATE_2              = 2,
    RITUAL_STATE_3              = 3,
    RITUAL_STATE_4              = 4,
    RITUAL_STATE_FLIP_LEFT      = 5,
    RITUAL_STATE_FLIP_MIDDLE    = 6,
    RITUAL_STATE_FLIP_RIGHT     = 7,
    RITUAL_STATE_8              = 8,
    RITUAL_STATE_9              = 9,
    RITUAL_STATE_A              = 10,
    RITUAL_STATE_B              = 11,
    RITUAL_STATE_C              = 12,
    RITUAL_STATE_D              = 13,
};

BSS RitualCard N(RitualCards)[3];
MAP_STATIC_PAD(1,merlee);

s8 N(MerleeSpellCasts)[] = {
    20, 10, 5, 0,
};

s8 N(MerleeCoinCosts)[] = {
    50, 20, 5, 0,
};

#if !VERSION_PAL
s32 N(pad_XX111)[] = { 0 };
#endif

INCLUDE_IMG("world/area_dro/dro_02/card.png", dro_02_card);
INCLUDE_PAL("world/area_dro/dro_02/card.pal", dro_02_card_pal);
#include "world/area_dro/dro_02/card_1.vtx.inc.c"
#include "world/area_dro/dro_02/card_2.vtx.inc.c"
#include "world/area_dro/dro_02/card_setup.gfx.inc.c"
#include "world/area_dro/dro_02/card_1.gfx.inc.c"
#include "world/area_dro/dro_02/card_2.gfx.inc.c"

void N(card_worker_update)(void);
void N(card_worker_render)(void);

API_CALLABLE(N(TryEnchantPlayer)) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 tier = evt_get_variable(script, *args++);
    s32 outPrevented = *args++;
    u8 coins = N(MerleeCoinCosts)[tier];
    u8 casts = N(MerleeSpellCasts)[tier];

    if (playerData->coins < coins) {
        evt_set_variable(script, outPrevented, TRUE);
    } else {
        playerData->coins = playerData->coins - coins;
        if (playerData->merleeCastsLeft < casts) {
            playerData->merleeCastsLeft = casts;
        }
        playerData->merleeTurnCount = rand_int(2) + 1;
        switch (rand_int(3)) {
            case 0:
                playerData->merleeSpellType = MERLEE_SPELL_ATK_BOOST;
                break;
            case 1:
                playerData->merleeSpellType = MERLEE_SPELL_DEF_BOOST;
                break;
            case 2:
                playerData->merleeSpellType = MERLEE_SPELL_EXP_BOOST;
                break;
            case 3:
                playerData->merleeSpellType = MERLEE_SPELL_COIN_BOOST;
                break;
        }
        evt_set_variable(script, outPrevented, FALSE);
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(DarkenWorld)) {
    s32 i;

    if (isInitialCall) {
        mdl_set_all_tint_type(ENV_TINT_SHROUD);
        *gBackgroundTintModePtr = ENV_TINT_SHROUD;
        mdl_set_shroud_tint_params(0, 0, 0, 0);

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);
            if (npc != 0 && npc->flags != 0 && npc->npcID != NPC_PARTNER && npc->npcID != NPC_Merlee) {
                npc->flags |= NPC_FLAG_HIDING;
            }
        }
        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 8;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }
    mdl_set_shroud_tint_params(0, 0, 0, script->functionTemp[0]);

    return (script->functionTemp[0] == 255) * ApiStatus_DONE2;
}

API_CALLABLE(N(UndarkenWorld)) {
    s32 i;

    if (isInitialCall) {
        mdl_set_shroud_tint_params(0, 0, 0, 255);
        script->functionTemp[0] = 255;
        script->functionTemp[1] = 0;
    }
    script->functionTemp[0] -= 8;
    if (script->functionTemp[0] < 0) {
        script->functionTemp[0] = 0;
    }
    mdl_set_shroud_tint_params(0, 0, 0, script->functionTemp[0]);

    if (script->functionTemp[0] == 0 && script->functionTemp[1] == 0) {
        script->functionTemp[1] = 1;
    } else if (script->functionTemp[1] == 1) {
        mdl_set_all_tint_type(ENV_TINT_NONE);
        *gBackgroundTintModePtr = ENV_TINT_NONE;
        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);

            if (npc != NULL && npc->flags != 0 && npc->npcID != NPC_PARTNER && npc->npcID != NPC_Merlee) {
                npc->flags &= ~NPC_FLAG_HIDING;
            }
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(CreateRitualCards)) {
    s32 imgfxIdx;

    N(CreatorScript) = script;

    imgfxIdx = imgfx_get_free_instances(1);
    imgfx_update(imgfxIdx, IMGFX_SET_ANIM, IMGFX_ANIM_SHUFFLE_CARDS, 1, 1, 0, IMGFX_FLAG_800);
    evt_set_variable(script, RITUAL_VAR_SHUFFLE_IMGFX, imgfxIdx);
    imgfxIdx = imgfx_get_free_instances(1);
    imgfx_update(imgfxIdx, IMGFX_SET_ANIM, IMGFX_ANIM_FLIP_CARD_1, 1, 1, 0, IMGFX_FLAG_800);
    evt_set_variable(script, RITUAL_VAR_FILP1_IMGFX, imgfxIdx);
    imgfxIdx = imgfx_get_free_instances(1);
    imgfx_update(imgfxIdx, IMGFX_SET_ANIM, IMGFX_ANIM_FLIP_CARD_2, 1, 1, 0, IMGFX_FLAG_800);
    evt_set_variable(script, RITUAL_VAR_FILP2_IMGFX, imgfxIdx);
    imgfxIdx = imgfx_get_free_instances(1);
    imgfx_update(imgfxIdx, IMGFX_SET_ANIM, IMGFX_ANIM_FLIP_CARD_3, 1, 1, 0, IMGFX_FLAG_800);
    evt_set_variable(script, RITUAL_VAR_FILP3_IMGFX, imgfxIdx);

    evt_set_variable(script, RITUAL_VAR_WORKER, create_worker_world(
        N(card_worker_update),
        N(card_worker_render)));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DestroyRitualCards)) {
    imgfx_release_instance(evt_get_variable(script, RITUAL_VAR_SHUFFLE_IMGFX));
    imgfx_release_instance(evt_get_variable(script, RITUAL_VAR_FILP1_IMGFX));
    imgfx_release_instance(evt_get_variable(script, RITUAL_VAR_FILP2_IMGFX));
    imgfx_release_instance(evt_get_variable(script, RITUAL_VAR_FILP3_IMGFX));
    free_worker(evt_get_variable(script, RITUAL_VAR_WORKER));
    return ApiStatus_DONE2;
}

u32 N(appendGfx_ritual_card)(RitualCard* card, Matrix4f mtxParent) {
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    ImgFXTexture ifxImg;
    SpriteRasterInfo rasterInfo;
    s32 ret;

    if (card->unk_00 == 0) {
        return 1;
    }

    gSPDisplayList(gMainGfxPos++, N(card_setup_gfx));

    if (card->unk_00 == 1 || card->unk_00 == 4 || card->unk_00 == 5) {
        guTranslateF(mtxTemp, card->pos.x, card->pos.y, card->pos.z);
        guMtxCatF(mtxTemp, mtxParent, mtxTransform);
        guRotateF(mtxTemp, card->yaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
        guRotateF(mtxTemp, card->pitch, 1.0f, 0.0f, 0.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        if (card->unk_00 == 1 || card->unk_00 == 4) {
            gSPDisplayList(gMainGfxPos++, N(card_1_gfx));
        }

        if (card->unk_00 == 1 || card->unk_00 == 5) {
            spr_get_player_raster_info(&rasterInfo, card->spriteID, card->rasterIndex);
            gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
            gDPLoadTLUT_pal16(gMainGfxPos++, 0, rasterInfo.defaultPal);
            gDPLoadTextureTile_4b(gMainGfxPos++, rasterInfo.raster, G_IM_FMT_CI, rasterInfo.width, rasterInfo.height,
                                    0, 0, rasterInfo.width - 1, rasterInfo.height - 1, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, 8, 8, G_TX_NOLOD, G_TX_NOLOD);
            guTranslateF(mtxTransform, card->xoffset + 30 - rasterInfo.width / 2, 0.0f, 0.0f);
            guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);
            gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, N(card_2_gfx));
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        return 1;
    }

    if (card->unk_00 == 2) {
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 256 * 4, 256 * 4, 287 * 4, 287 * 4);
        guTranslateF(mtxTemp, N(RitualCards)[0].pos.x, N(RitualCards)[0].pos.y, N(RitualCards)[0].pos.z);
        guMtxCatF(mtxTemp, mtxParent, mtxTransform);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        ret = imgfx_appendGfx_component(evt_get_variable(N(CreatorScript), RITUAL_VAR_SHUFFLE_IMGFX), &ifxImg, IMGFX_FLAG_SKIP_GFX_SETUP | IMGFX_FLAG_SKIP_TEX_SETUP, mtxTransform);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        return ret;
    }

    if (card->unk_00 == 3) {
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 256 * 4, 256 * 4, 287 * 4, 287 * 4);
        guTranslateF(mtxTemp, N(RitualCards)[0].pos.x, N(RitualCards)[0].pos.y, N(RitualCards)[0].pos.z);
        guMtxCatF(mtxTemp, mtxParent, mtxTransform);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        imgfx_appendGfx_component(evt_get_variable(N(CreatorScript), RITUAL_VAR_FILP1_IMGFX), &ifxImg, IMGFX_FLAG_SKIP_GFX_SETUP | IMGFX_FLAG_SKIP_TEX_SETUP, mtxTransform);
        imgfx_appendGfx_component(evt_get_variable(N(CreatorScript), RITUAL_VAR_FILP2_IMGFX), &ifxImg, IMGFX_FLAG_SKIP_GFX_SETUP | IMGFX_FLAG_SKIP_TEX_SETUP, mtxTransform);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        guTranslateF(mtxTemp, N(RitualCards)[0].pos.x, N(RitualCards)[0].pos.y, N(RitualCards)[0].pos.z);
        guMtxCatF(mtxTemp, mtxParent, mtxTransform);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        spr_get_player_raster_info(&rasterInfo, card->spriteID, card->rasterIndex);
        ifxImg.raster = rasterInfo.raster;
        ifxImg.palette = rasterInfo.defaultPal;
        ifxImg.width = rasterInfo.width;
        ifxImg.height = rasterInfo.height;
        ifxImg.xOffset = -(rasterInfo.width / 2);
        ifxImg.yOffset = rasterInfo.height / 2;
        ifxImg.alpha = 255;
        ret = imgfx_appendGfx_component(evt_get_variable(N(CreatorScript), RITUAL_VAR_FILP3_IMGFX), &ifxImg, IMGFX_FLAG_SKIP_GFX_SETUP, mtxTransform);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        return ret;
    }

    return 1;
}

void N(GetCardOrientation)(s32 index, f32* outX, f32* outY, f32* outZ, f32* outAngle) {
    RitualCard* card;
    Matrix4f mtxTranform;
    Matrix4f mtxTemp;
    Matrix4f mtxParent;

    guPositionF(mtxParent, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, SPRITE_WORLD_SCALE_F,
                evt_get_variable(N(CreatorScript), RITUAL_VAR_POS_X),
                evt_get_variable(N(CreatorScript), RITUAL_VAR_POS_Y),
                evt_get_variable(N(CreatorScript), RITUAL_VAR_POS_Z));

    card = &N(RitualCards)[index];
    guTranslateF(mtxTemp, card->pos.x, card->pos.y, card->pos.z);
    guMtxCatF(mtxTemp, mtxParent, mtxTranform);
    guRotateF(mtxTemp, card->yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTranform, mtxTranform);
    guTranslateF(mtxTemp, 0.0f, 0.0f, 1.0f);
    guMtxCatF(mtxTemp, mtxTranform, mtxTranform);
    *outX = mtxTranform[3][0];
    *outY = mtxTranform[3][1];
    *outZ = mtxTranform[3][2];
    *outAngle = clamp_angle(card->yaw);
}

void N(card_worker_update)(void) {
    f32 posX5, posY5, posZ5, yaw5;
    f32 posX6, posY6, posZ6, yaw6;
    f32 posX7, posY7, posZ7, yaw7;
    f32 sp48, sp4C, sp50, sp54;
    f32 sp58, sp5C, sp60, sp64;
    f32 sp68, sp6C, sp70, sp74;
    EffectInstance* effect;
    EnergyInOutFXData* data;
    s32 i, j;

    switch (evt_get_variable(N(CreatorScript), RITUAL_VAR_STATE)) {
        case RITUAL_STATE_INIT:
            N(RitualStateTime) = 0;
            evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_APPEAR);
            N(RitualCards)[0].unk_00 = 1;
            N(RitualCards)[0].pos.x = -200.0f;
            N(RitualCards)[0].pos.y = 0.0f;
            N(RitualCards)[0].pos.z = 0.0f;
            N(RitualCards)[0].pitch = 0.0f;
            N(RitualCards)[0].yaw = 0.0f;
            N(RitualCards)[0].spriteID = 1;
            N(RitualCards)[0].rasterIndex = 12;
            N(RitualCards)[0].xoffset = 2;

            N(RitualCards)[1].unk_00 = 1;
            N(RitualCards)[1].pos.x = 200.0f;
            N(RitualCards)[1].pos.y = 0.0f;
            N(RitualCards)[1].pos.z = 1.0f;
            N(RitualCards)[1].pitch = 0.0f;
            N(RitualCards)[1].yaw = 0.0f;
            N(RitualCards)[1].spriteID = 1;
            N(RitualCards)[1].rasterIndex = 48;
            N(RitualCards)[1].xoffset = 0;


            N(RitualCards)[2].spriteID = 8;
            N(RitualCards)[2].rasterIndex = 5;
            N(RitualCards)[2].unk_00 = 1;
            N(RitualCards)[2].pos.x = 0.0f;
            N(RitualCards)[2].pos.y = 200.0f;
            N(RitualCards)[2].pos.z = 2.0f;
            N(RitualCards)[2].pitch = 0.0f;
            N(RitualCards)[2].yaw = 0.0f;
            N(RitualCards)[2].xoffset = 4;
            break;
        case RITUAL_STATE_APPEAR:
            N(RitualStateTime)++;
            N(RitualCards)[0].pos.x += 10.0f;
            N(RitualCards)[1].pos.x += -10.0f;
            N(RitualCards)[2].pos.y += -10.0f;
            if (N(RitualStateTime) == 18) {
                gPlayerStatus.pos.y = NPC_DISPOSE_POS_Y;
            }
            if (N(RitualStateTime) == 20) {
                evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_2);
                N(RitualStateTime) = 0;
            }
            break;
        case RITUAL_STATE_2:
            N(RitualCards)[0].unk_00 = 2;
            N(RitualCards)[1].unk_00 = 0;
            N(RitualCards)[2].unk_00 = 0;
            N(RitualCards)[0].pos.x = 0.0f;
            N(RitualCards)[0].pos.y = 0.0f;
            N(RitualCards)[0].pos.z = 0;
            break;
        case RITUAL_STATE_3:
            N(RitualCards)[0].unk_00 = 1;
            N(RitualCards)[1].unk_00 = 1;
            N(RitualCards)[2].unk_00 = 1;
            N(RitualStateTime)++;
            N(RitualCards)[0].pos.x -= 10.0f;
            N(RitualCards)[1].pos.x += 10.0f;
            if (N(RitualStateTime) == 10) {
                N(RitualStateTime) = 0;
                evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_4);
            }
            break;
        case RITUAL_STATE_4:
            N(RitualCards)[0].pos.x = -100.0f;
            N(RitualCards)[0].pos.y = 0.0f;
            N(RitualCards)[0].pos.z = 0;
            N(RitualCards)[1].pos.x = 100.0f;
            N(RitualCards)[1].pos.y = 0.0f;
            N(RitualCards)[1].pos.z = 1.0f;
            N(RitualCards)[2].pos.x = 0;
            N(RitualCards)[2].pos.y = 0.0f;
            N(RitualCards)[2].pos.z = 2.0f;
            N(RitualStateTime)++;
            if (N(RitualStateTime) == 20) {
                N(RitualStateTime) = 0;
                evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_FLIP_LEFT);
                sfx_play_sound_with_params(SOUND_MERLEE_SHOW_CARD, 0, 24, 0);
            }
            break;
        case RITUAL_STATE_FLIP_LEFT:
            N(RitualCards)[0].yaw += 18.0f;
            N(RitualCards)[1].yaw = 0.0f;
            N(RitualCards)[2].yaw = 0.0f;
            N(RitualStateTime)++;
            if (N(RitualStateTime) == 8) {
                N(GetCardOrientation)(0, &posX5, &posY5, &posZ5, &yaw5);
                fx_sparkles(0, posX5, posY5 + 20.0f, posZ5, 30.0f);
            }
            if (N(RitualStateTime) == 10) {
                N(RitualStateTime) = 0;
                evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_FLIP_MIDDLE);
                sfx_play_sound_with_params(SOUND_MERLEE_SHOW_CARD, 0, 64, 0);
            }
            break;
        case RITUAL_STATE_FLIP_MIDDLE:
            N(RitualCards)[0].yaw += 18.0f;
            N(RitualCards)[1].yaw = 0.0f;
            N(RitualCards)[2].yaw += 18.0f;
            N(RitualStateTime)++;
            if (N(RitualStateTime) == 8) {
                N(GetCardOrientation)(2, &posX6, &posY6, &posZ6, &yaw6);
                fx_sparkles(0, posX6, posY6 + 20.0f, posZ6, 30.0f);
            }
            if (N(RitualStateTime) == 10) {
                N(RitualStateTime) = 0;
                evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_FLIP_RIGHT);
                sfx_play_sound_with_params(SOUND_MERLEE_SHOW_CARD, 0, 104, 0);
            }
            break;
        case RITUAL_STATE_FLIP_RIGHT:
            N(RitualCards)[0].yaw = 0.0f;
            N(RitualCards)[1].yaw += 18.0f;
            N(RitualCards)[2].yaw += 18.0f;
            N(RitualStateTime)++;
            if (N(RitualStateTime) == 8) {
                N(GetCardOrientation)(1, &posX7, &posY7, &posZ7, &yaw7);
                fx_sparkles(0, posX7, posY7 + 20.0f, posZ7, 30.0f);
            }
            if (N(RitualStateTime) == 10) {
                N(RitualStateTime) = 0;
                evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_8);
            }
            break;
        case RITUAL_STATE_8:
            N(RitualCards)[0].yaw = 0.0f;
            N(RitualCards)[1].yaw += 18.0f;
            N(RitualCards)[2].yaw = 0.0f;
            N(RitualStateTime)++;
            if (N(RitualStateTime) == 10) {
                N(RitualStateTime) = 0;
                evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_9);
            }
            break;
        case RITUAL_STATE_9:
            N(RitualCards)[0].pos.x += 10.0f;
            N(RitualCards)[0].pos.y = 0.0f;
            N(RitualCards)[0].yaw = 0.0f;
            N(RitualCards)[1].pos.x -= 10.0f;
            N(RitualCards)[1].pos.y = 0.0f;
            N(RitualCards)[1].yaw = 0.0f;
            N(RitualCards)[2].pos.x = 0;
            N(RitualCards)[2].pos.y = 0.0f;
            N(RitualCards)[2].yaw = 0.0f;
            N(RitualStateTime)++;
            if (N(RitualStateTime) == 10) {
                N(RitualStateTime) = 0;
                evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_A);
                return;
            }
            break;
        case RITUAL_STATE_A:
            N(RitualCards)[0].unk_00 = 3;
            N(RitualCards)[0].spriteID = 8;
            N(RitualCards)[1].unk_00 = 0;
            N(RitualCards)[2].unk_00 = 0;
            N(RitualCards)[0].rasterIndex = 0x11;
            return;
        case RITUAL_STATE_B:
            N(RitualCards)[0].unk_00 = 4;
            N(RitualCards)[1].unk_00 = 5;
            N(RitualCards)[1].spriteID = 8;
            N(RitualCards)[0].pos.x = 0.0f;
            N(RitualCards)[0].pos.z = 0;
            N(RitualCards)[1].pos.x = 0.0f;
            N(RitualCards)[1].pos.z = 0;
            N(RitualCards)[1].rasterIndex = 10;
            N(RitualCards)[1].xoffset = 0;
            N(RitualStateTime) = 0;
            N(RitualCards)[0].pos.y = 68.0f;
            N(RitualCards)[0].yaw = 180.0f;
            N(RitualCards)[1].pos.y = 68.0f;
            N(RitualCards)[1].yaw = 180.0f;
            evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_C);
            N(D_8024EF80) = 0.0f;
            N(D_8024EF84) = 1.0f;

            N(GetCardOrientation)(1, &sp48, &sp4C, &sp50, &sp54);

            for (j = 0; j < ARRAY_COUNT(N(D_8024EF90)); j++) {
                s32 i;

                N(D_8024EF90)[j] = fx_energy_in_out(2, sp48, sp4C + 20.0f, sp50, 8.0f, -1);
                N(D_8024EF90)[j]->data.energyInOut->unk_28 = 215;
                N(D_8024EF90)[j]->data.energyInOut->unk_2C = 55;
                N(D_8024EF90)[j]->data.energyInOut->unk_30 = 255;

                for (i = 1; i < N(D_8024EF90)[j]->numParts; i++) {
                    N(D_8024EF90)[j]->data.energyInOut[i].unk_38 *= 0.1;
                }
            }
            break;
        case RITUAL_STATE_C:
            N(GetCardOrientation)(1, &sp58, &sp5C, &sp60, &sp64);

            for (j = 0; j < ARRAY_COUNT(N(D_8024EF90)); j++) {
                s32 i;

                N(D_8024EF90)[j]->data.energyInOut->pos.x = sp58;
                N(D_8024EF90)[j]->data.energyInOut->pos.y = sp5C + 20.0f;
                N(D_8024EF90)[j]->data.energyInOut->pos.z = sp60;
                N(D_8024EF90)[j]->data.energyInOut->scale -= 0.1;

                if (N(D_8024EF90)[j]->data.energyInOut->scale < 0.1) {
                    N(D_8024EF90)[j]->data.energyInOut->scale = 0.1f;
                }

                for (i = 1; i < N(D_8024EF90)[j]->numParts; i++, data++) {
                    N(D_8024EF90)[j]->data.energyInOut[i].unk_38 += 0.01;
                }
            }

            N(RitualCards)[0].pos.y += N(D_8024EF80);
            N(RitualCards)[1].pos.y += N(D_8024EF84);
            N(D_8024EF80) += 0.4;
            N(D_8024EF84) -= 0.05;
            N(RitualStateTime)++;

            if (N(RitualCards)[1].pos.y < -5.0f) {
                N(RitualCards)[1].pos.y = -5.0f;
                N(RitualStateTime) = 0;
                evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_D);
                N(RitualCards)[0].unk_00 = 0;
                N(RitualCards)[1].unk_00 = 0;
                N(GetCardOrientation)(1, &sp68, &sp6C, &sp70, &sp74);
                fx_sparkles(0, sp68, sp6C + 20.0f, sp70, 30.0f);
                sfx_play_sound(SOUND_MERLEE_COMPLETE_SPELL);

                for (j = 0; j < ARRAY_COUNT(N(D_8024EF90)); j++) {
                    N(D_8024EF90)[j]->flags |= FX_INSTANCE_FLAG_DISMISS;
                }
            }
            break;
        case RITUAL_STATE_D:
            break;
    }
}

void N(card_worker_render)(void) {
    Matrix4f mtx;
    u32 temp_s1;

    guPositionF(mtx, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, SPRITE_WORLD_SCALE_F,
                evt_get_variable(N(CreatorScript), RITUAL_VAR_POS_X),
                evt_get_variable(N(CreatorScript), RITUAL_VAR_POS_Y),
                evt_get_variable(N(CreatorScript), RITUAL_VAR_POS_Z));

    temp_s1 = N(appendGfx_ritual_card)(&N(RitualCards)[0], mtx);
    N(appendGfx_ritual_card)(&N(RitualCards)[1], mtx);
    N(appendGfx_ritual_card)(&N(RitualCards)[2], mtx);
    if ((N(RitualCards)[0].unk_00 == 2) && ((temp_s1 - 1) < 2)) {
        evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_3);
    }
    if ((N(RitualCards)[0].unk_00 == 3) && ((temp_s1 - 1) < 2)) {
        evt_set_variable(N(CreatorScript), RITUAL_VAR_STATE, RITUAL_STATE_B);
    }
}

API_CALLABLE(N(func_8024303C_96C1FC)) {
    sfx_play_sound_with_params(SOUND_SHUFFLE_CARD_A, 0, 24, 0);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80243068_96C228)) {
    sfx_play_sound_with_params(SOUND_SHUFFLE_CARD_B, 0, 104, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcAuxAI_Merlee) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Merlee) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PerformRitual) = {
    EVT_USE_ARRAY(EVT_PTR(N(RitualBuffer)))
    EVT_SET(RITUAL_VAR_STATE, RITUAL_STATE_INIT)
    EVT_CALL(GetNpcPos, NPC_Merlee, RITUAL_VAR_POS_X, RITUAL_VAR_POS_Y, RITUAL_VAR_POS_Z)
    EVT_ADD(RITUAL_VAR_POS_X, 60)
    EVT_ADD(RITUAL_VAR_POS_Z, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Merlee, SOUND_MERLEE_TWIRL, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(MakeLerp, 720, 0, 60, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Merlee, 0, LVar0, 0)
            EVT_IF_GT(LVar0, 360)
                EVT_ADD(LVar0, -360)
            EVT_END_IF
            EVT_SWITCH(LVar0)
                EVT_CASE_RANGE(90, 270)
                    EVT_SET(LVar2, ANIM_WorldMerlee_SpinBack)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar2, ANIM_WorldMerlee_SpinFront)
            EVT_END_SWITCH
            EVT_CALL(SetNpcAnimation, NPC_Merlee, LVar2)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcRotation, NPC_Merlee, 0, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Merlee, ANIM_WorldMerlee_Gather)
        EVT_WAIT(200)
        EVT_CALL(SetNpcAnimation, NPC_Merlee, ANIM_WorldMerlee_Bow)
        EVT_WAIT(40)
        EVT_CALL(SetNpcAnimation, NPC_Merlee, ANIM_WorldMerlee_Gather)
        EVT_WAIT(75)
        EVT_CALL(SetNpcAnimation, NPC_Merlee, ANIM_WorldMerlee_Release)
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(PlaySoundAtNpc, NPC_Merlee, SOUND_MERLEE_GATHER_ENERGY, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar0, RITUAL_VAR_POS_Y)
    EVT_ADD(LVar0, 25)
    EVT_PLAY_EFFECT(EFFECT_RADIATING_ENERGY_ORB, 0, RITUAL_VAR_POS_X, LVar0, RITUAL_VAR_POS_Z, 1, -1)
    EVT_SET(RITUAL_VAR_ORB_EFFECT, LVarF)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(DismissEffect, RITUAL_VAR_ORB_EFFECT)
    EVT_END_THREAD
    EVT_CALL(N(DarkenWorld))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(InterpPlayerYaw, 0, 0)
    EVT_CALL(N(CreateRitualCards))
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_EQ(RITUAL_VAR_STATE, RITUAL_STATE_2)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(9)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(4)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(4)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(2)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(2)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(2)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(2)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(6)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, SOUND_SEQ_SHUFFLE_CARD)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_GE(RITUAL_VAR_STATE, RITUAL_STATE_3)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(9)
        EVT_CALL(N(func_8024303C_96C1FC))
        EVT_WAIT(2)
        EVT_CALL(N(func_80243068_96C228))
        EVT_LOOP(0)
            EVT_IF_GE(RITUAL_VAR_STATE, RITUAL_STATE_A)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(3)
        EVT_CALL(PlaySound, SOUND_MERLEE_GATHER_CARDS)
        EVT_LOOP(0)
            EVT_IF_GE(RITUAL_VAR_STATE, RITUAL_STATE_B)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(15)
        EVT_CALL(PlaySound, SOUND_MERLEE_RELEASE_PLAYER)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_IF_EQ(RITUAL_VAR_STATE, RITUAL_STATE_D)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerPos, RITUAL_VAR_POS_X, RITUAL_VAR_POS_Y, RITUAL_VAR_POS_Z)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_UsePower)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerPos, RITUAL_VAR_POS_X, RITUAL_VAR_POS_Y, RITUAL_VAR_POS_Z)
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(N(DestroyRitualCards))
    EVT_THREAD
        EVT_CALL(N(UndarkenWorld))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BeginMerleeCamera) = {
    EVT_CALL(GetNpcPos, NPC_Merlee, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 200)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(8.0))
    EVT_CALL(SetCamPitch, 0, 20, -15)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EndMerleeCamera) = {
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(3.0))
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};


EvtScript N(EVS_NpcInteract_Merlee) = {
    EVT_CALL(func_802D2C14, 1)
    EVT_EXEC_WAIT(N(EVS_BeginMerleeCamera))
    EVT_SET(LVar0, 0)
    EVT_IF_EQ(GB_KootFavor_Current, KOOT_FAVOR_CH4_1)
        EVT_ADD(LVar0, 1)
    EVT_END_IF
    EVT_IF_EQ(GF_HOS06_MerluvleeRequestedCrystalBall, 1)
        EVT_ADD(LVar0, 1)
    EVT_END_IF
    EVT_IF_EQ(GF_DRO01_Gift_CrystalBall, 0)
        EVT_ADD(LVar0, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 3)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMerlee_Talk, ANIM_WorldMerlee_Idle, 0, MSG_CH2_00DC)
        EVT_SET(LVar0, ITEM_CRYSTAL_BALL)
        EVT_SET(LVar1, 1)
        EVT_EXEC_WAIT(N(GiveItemReward))
        EVT_CALL(AddKeyItem, ITEM_CRYSTAL_BALL)
        EVT_SET(GF_DRO01_Gift_CrystalBall, 1)
        EVT_WAIT(20)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(EVS_EndMerleeCamera))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMerlee_Talk, ANIM_WorldMerlee_Idle, 0, MSG_CH2_00D6)
    EVT_CALL(ShowChoice, MSG_Choice_0011)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(ContinueSpeech, -1, ANIM_WorldMerlee_Talk, ANIM_WorldMerlee_Idle, 0, MSG_CH2_00D7)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(EVS_EndMerleeCamera))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ContinueSpeech, -1, ANIM_WorldMerlee_Talk, ANIM_WorldMerlee_Idle, 0, MSG_CH2_00D8)
    EVT_CALL(ShowCoinCounter, 1)
    EVT_CALL(ShowChoice, MSG_Choice_0018)
    EVT_CALL(ShowCoinCounter, 0)
    EVT_IF_EQ(LVar0, 3)
        EVT_CALL(ContinueSpeech, -1, ANIM_WorldMerlee_Talk, ANIM_WorldMerlee_Idle, 0, MSG_CH2_00D7)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(EVS_EndMerleeCamera))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(TryEnchantPlayer), LVar0, LVar1)
    EVT_IF_NE(LVar1, 0)
        EVT_CALL(ContinueSpeech, -1, ANIM_WorldMerlee_Talk, ANIM_WorldMerlee_Idle, 0, MSG_CH2_00D9)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(EVS_EndMerleeCamera))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ContinueSpeech, -1, ANIM_WorldMerlee_Talk, ANIM_WorldMerlee_Idle, 0, MSG_CH2_00DA)
    EVT_CALL(SetMusicTrack, 0, SONG_MERLEE_SPELL, 0, 8)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_EXEC_GET_TID(N(EVS_PerformRitual), LVar9)
    EVT_LOOP(0)
        EVT_IS_THREAD_RUNNING(LVar9, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, 4, ANIM_WorldMerlee_Idle)
    EVT_CALL(PlayerMoveTo, -100, -370, 8)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMerlee_Talk, ANIM_WorldMerlee_Idle, 0, MSG_CH2_00DB)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(func_802D2C14, 0)
    EVT_EXEC_WAIT(N(EVS_EndMerleeCamera))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Merlee) = {
    .height = 32,
    .radius = 32,
    .otherAI = &N(EVS_NpcAuxAI_Merlee),
    .onInteract = &N(EVS_NpcInteract_Merlee),
    .ai = &N(EVS_NpcAI_Merlee),
    .level = ACTOR_LEVEL_NONE,
};
