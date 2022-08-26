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
        if ((useRandomValues == 1) && (time % 30 == 0)) {
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
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0x00, 0x00, 0x00, alpha);
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

INCLUDE_ASM(s32, "effects/partner_buff", func_E011A700);
