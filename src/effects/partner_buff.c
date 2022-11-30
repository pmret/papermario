#include "common.h"
#include "effects_internal.h"

void partner_buff_init(EffectInstance* effect);
void partner_buff_update(EffectInstance* effect);
void partner_buff_render(EffectInstance* effect);
void func_E011A3A0(EffectInstance* effect);
void func_E011A700(EffectInstance* effect);

enum {
    BUFF_STATE_IDLE                     = 0,
    BUFF_STATE_DECREMENT_TURNS_INIT     = 1,
    BUFF_STATE_DECREMENT_TURNS          = 10,
    BUFF_STATE_SET_TURNS_INIT           = 2,
    BUFF_STATE_SET_TURNS                = 20,
    BUFF_STATE_FADE_OUT                 = 3,
    BUFF_STATE_FADE_IN_INIT             = 4,
    BUFF_STATE_FADE_IN                  = 40
};

extern Gfx D_09001800[];
extern Gfx D_090019A0[];
extern Gfx D_09001A18[];
extern Gfx D_09001A90[];
extern Gfx D_09001B08[];
extern Gfx D_09001B80[];

Gfx* D_E011AC20[] = { D_09001800 };
Gfx* D_E011AC24[] = { D_090019A0, D_09001A18, D_09001A90, D_09001B08, D_09001B80, NULL, NULL, NULL, NULL, NULL };

s8 D_E011AC4C[] = { 15, 15, 15, 15, 15, 35, 75, 100, 100, 100, 100, 0 };
s8 D_E011AC58[] = { 100, 100, 100, 100, 100, 90, 10, 10, 10, 10, 10, 0 };
s8 D_E011AC64[] = { 0, -1, -3, -4, -4, 4, 32, 32, 32, 32, 32, 0 };

EffectInstance* partner_buff_main(s32 useRandomValues, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    PartnerBuffFXData* part;
    s32 numParts = 1;
    s32 i;

    bp.unk_00 = 0;
    bp.init = partner_buff_init;
    bp.update = partner_buff_update;
    bp.renderWorld = partner_buff_render;
    bp.unk_14 = func_E011A3A0;
    bp.effectID = EFFECT_PARTNER_BUFF;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.partnerBuff = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.partnerBuff != NULL);

    part->useRandomValues = useRandomValues;
    part->lifeTime = 0;
    if (duration <= 0) {
        part->timeLeft = 1000;
    } else {
        part->timeLeft = duration;
    }

    for (i = 0; i < ARRAY_COUNT(part->unk_0C); i++) {
        part->unk_0C[i].alpha = 0;
        part->unk_0C[i].turnsDisplay = 0;
        part->unk_0C[i].turnsLeft = 0;
        part->unk_0C[i].state = BUFF_STATE_IDLE;
        part->unk_0C[i].stateTimer = 0;
    }

    part->unk_02 = 0;
    if (useRandomValues == 1) {
        part->unk_02 = 1;
    }

    return effect;
}

void partner_buff_init(EffectInstance* effect) {
}

void partner_buff_update(EffectInstance* effect) {
    PartnerBuffFXData* data = effect->data.partnerBuff;
    s32 useRandomValues = data->useRandomValues;
    s32 time;
    s32 i;

    if (effect->flags & EFFECT_INSTANCE_FLAGS_10) {
        effect->flags &= ~EFFECT_INSTANCE_FLAGS_10;
        data->timeLeft = 16;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifeTime++;
    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }

    time = data->lifeTime;

    for (i = 0; i < ARRAY_COUNT(data->unk_0C); i++) {
        BuffData* buff = &data->unk_0C[i];

        if (buff->turnsLeft < 0) {
            buff->turnsLeft = 0;
        }
        // possibly a leftover debug option
        if (useRandomValues == 1 && time % 30 == 0) {
            buff->turnsLeft = shim_rand_int(4);
        }

        switch (buff->state) {
            case BUFF_STATE_IDLE:
                if (buff->alpha == 255) {
                    if (buff->turnsLeft < buff->turnsDisplay) {
                        buff->state = BUFF_STATE_DECREMENT_TURNS_INIT;
                    } else if (buff->turnsDisplay < buff->turnsLeft) {
                        buff->state = BUFF_STATE_SET_TURNS_INIT;
                    } else if (buff->turnsDisplay == 0) {
                        buff->state = BUFF_STATE_FADE_OUT;
                    }
                } else if ((buff->alpha == 0) && (buff->turnsLeft > 0)) {
                    buff->state = BUFF_STATE_FADE_IN_INIT;
                }
                break;
            case BUFF_STATE_DECREMENT_TURNS_INIT:
                buff->stateTimer = 0;
                buff->state = BUFF_STATE_DECREMENT_TURNS;
                // fallthrough
            case BUFF_STATE_DECREMENT_TURNS:
                buff->stateTimer++;
                if (buff->stateTimer > 10) {
                    buff->stateTimer = 0;
                    buff->state = BUFF_STATE_IDLE;
                    buff->turnsDisplay--;
                }
                break;
            case BUFF_STATE_SET_TURNS_INIT:
                buff->stateTimer = 0;
                buff->state = BUFF_STATE_SET_TURNS;
                // fallthrough
            case BUFF_STATE_SET_TURNS:
                buff->stateTimer++;
                if (buff->stateTimer > 10) {
                    buff->stateTimer = 0;
                    buff->state = BUFF_STATE_IDLE;
                    buff->turnsDisplay = buff->turnsLeft;
                }
                break;
            case BUFF_STATE_FADE_OUT:
                buff->alpha -= 32;
                if (buff->alpha < 0) {
                    buff->alpha = 0;
                    buff->state = BUFF_STATE_IDLE;
                }
                break;
            case BUFF_STATE_FADE_IN_INIT:
                buff->state = BUFF_STATE_FADE_IN;
                buff->turnsDisplay = buff->turnsLeft;
                // fallthrough
            case BUFF_STATE_FADE_IN:
                buff->alpha += 64;
                if (buff->alpha > 255) {
                    buff->alpha = 255;
                    buff->state = BUFF_STATE_IDLE;
                }
                break;
        }
    }
}

void partner_buff_render(EffectInstance* effect) {
}

void func_E011A3A0(EffectInstance* effect) {
    func_E011A700(effect);
}

void func_E011A3BC(s16 alpha) {
    if (alpha == 255) {
        gDPSetRenderMode(gMasterGfxPos++, AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
            GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM),
            GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
        gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    } else {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, 
                          TEXEL0, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, alpha);
    }
}

void func_E011A48C(s32 posX, s32 posY, s32 tile, f32 scale) {
    gSPScisTextureRectangle(gMasterGfxPos++,
        posX * 4,
        posY * 4,
        (posX + 32) * 4,
        (posY + 32) * 4,
        tile,
        0,
        1024,
        scale,
        -scale);
    gDPPipeSync(gMasterGfxPos++);
}

// almost - some ordering
#ifdef NON_MATCHING
void func_E011A700(EffectInstance* effect) {
    PartnerBuffFXData* data = effect->data.partnerBuff;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 i;
    f32 temp_f4;
    s32 alpha;
    s32 temp_v0_2;
    s16 stateTimer;
    s16 turnsDisplay;
    s32 idx;
    Gfx* dlist;
    s32 xOffset;
    s32 numShown;
    f32 x, y;
    f32 new_var;
    
    if (data->unk_02 != 0) {
        gDPPipeSync(gMasterGfxPos++);
        gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

        gSPDisplayList(gMasterGfxPos++, D_E011AC20[0]);
        
        numShown = 0;
        for (i = 0; i < ARRAY_COUNT(data->unk_0C); i++) {
            BuffData* buffData = &data->unk_0C[i];

            alpha = buffData->alpha;
            if (alpha != 0) {
                gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 2, i, G_ON);
                func_E011A3BC(alpha);
                func_E011A48C(20 + numShown * 32, 50, i, 1024.0f);
                numShown++;
            }
        }

        gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
        
        xOffset = 20;
        for (i = 0; i < ARRAY_COUNT(data->unk_0C); i++) {
            BuffData* buffData = &data->unk_0C[i];

            turnsDisplay = buffData->turnsDisplay;
            stateTimer = buffData->stateTimer;
            alpha = buffData->alpha;

            if (alpha != 0) {
                if (turnsDisplay < 0) {
                    turnsDisplay = 0;
                }
                if (turnsDisplay > 9) {
                    turnsDisplay = 9;
                }
                func_E011A3BC(alpha);

                if (buffData->state == BUFF_STATE_DECREMENT_TURNS || buffData->state == BUFF_STATE_SET_TURNS) {
                    if (buffData->state == BUFF_STATE_DECREMENT_TURNS) {
                        idx = turnsDisplay - 1;
                    } else if (buffData->state == BUFF_STATE_SET_TURNS) {
                        idx = turnsDisplay + 1;
                    }
                    dlist = D_E011AC24[idx];
                    if (dlist != NULL) {
                        gSPDisplayList(gMasterGfxPos++, dlist);
                        temp_f4 = D_E011AC4C[(s16)stateTimer] * 0.01f;
                        idx = (-(temp_f4 - 1.0f) * 16.0f) + 0.5;
                        x = idx + xOffset;
                        y = idx + 50;
                        func_E011A48C(x, y, 0, 1024.0f / temp_f4);
                    }
                }
        
                dlist = D_E011AC24[turnsDisplay];
                if (dlist != NULL) {
                    gSPDisplayList(gMasterGfxPos++, dlist);
                    
                    temp_v0_2 = D_E011AC64[(s16)stateTimer];
                    idx = -temp_v0_2; // TODO required to match (re-use of idx2)
                    temp_f4 = D_E011AC58[(s16)stateTimer] * 0.01f;
                    x = temp_v0_2 + xOffset;
                    y = idx + 50;
                    func_E011A48C(x, y, 0, 1024.0f / temp_f4);
                }
                
                xOffset += 32;
            }
        }

        gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE,
            camera->viewportStartX, 
            camera->viewportStartY, 
            camera->viewportStartX + camera->viewportW, 
            camera->viewportStartY + camera->viewportH
        );
        gDPPipeSync(gMasterGfxPos++);
    }
}
#else
INCLUDE_ASM(s32, "effects/partner_buff", func_E011A700);
#endif
