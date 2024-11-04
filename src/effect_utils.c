#include "common.h"
#include "effects.h"
#include "nu/nusys.h"

u32 effect_prng_seed = 0x1E6D3457;

void* effectFuncs[] = {
    guRotateF, guTranslateF, guTranslate, guScaleF, guMtxCatF, guMtxF2L, guMtxL2F, queue_render_task,
    create_effect_instance, remove_effect, general_heap_malloc, mem_clear, NULL, rand_int, clamp_angle, sin_deg,
    cos_deg, atan2, npc_raycast_down_sides, load_effect, sqrtf, mdl_draw_hidden_panel_surface, is_point_visible,
    guPerspectiveF, guMtxIdentF, transform_point, guLookAtHiliteF, set_screen_overlay_params_back,
    set_screen_overlay_center, set_screen_overlay_center_worldpos, mdl_get_next_texture_address, guPositionF, guOrthoF,
    guFrustumF, draw_prev_frame_buffer_at_screen_pos, draw_box, draw_msg, get_msg_width, mdl_get_shroud_tint_params, sfx_play_sound_at_position
};

s32 SimpleRandLUT[128] = {
    0x100B2AF5, 0x45B59924, 0x35094B45, 0x4ABFA67A, 0x164F5371, 0x7B195845, 0x58562A56, 0x25733D41,
    0x48008107, 0x0E004F28, 0x6963B8AD, 0x5B82AB71, 0x6BC1F51B, 0x3D947816, 0x39705175, 0x44409A59,
    0x0ED99067, 0x5F70B6F8, 0x3225AEEE, 0x08B5E97C, 0x2CDE7594, 0x5E9E5B7D, 0x5B2A2888, 0x107F0F50,
    0x58FBC53B, 0x65F69F19, 0x3AF6CEF3, 0x15C3894F, 0x4C931A2C, 0x39A897E9, 0x5945BB8C, 0x5C9E4521,
    0x7F5E310D, 0x0E4F06D2, 0x275DEB9C, 0x15AD847F, 0x09685F17, 0x7FB415F2, 0x3B20C1C0, 0x5168E01E,
    0x0DB4651A, 0x24847A6D, 0x2CEB8B8F, 0x79765A35, 0x6218F283, 0x665BDD04, 0x3DB6F48F, 0x70F282EB,
    0x45CC93FC, 0x6FDCA37D, 0x79A86C67, 0x72AB0990, 0x4E7AFEFA, 0x54D294F0, 0x032A18E0, 0x2776C435,
    0x3AC93409, 0x3E20E7D4, 0x3D3A4D85, 0x075C4E35, 0x77C97FBD, 0x16800911, 0x63FA9357, 0x7727B0CB,
    0x24CF0FE3, 0x0B587EF3, 0x0CD5354A, 0x2E376EFA, 0x0B0C94E5, 0x47F5F70A, 0x7FA04F19, 0x18C0FA00,
    0x6C7A7178, 0x2C8BDAA8, 0x12375435, 0x4E9363FB, 0x12E7B7AD, 0x4FEE48C4, 0x3F85E6E6, 0x58B44BA9,
    0x3FCAEC41, 0x392E534E, 0x4B5F553A, 0x0E45EB3C, 0x0E00E83E, 0x4E896E1A, 0x35BCAF71, 0x48CA1C47,
    0x0CAA55EE, 0x72F6FCF6, 0x50266A7D, 0x0473D5AC, 0x09770608, 0x3420FDD4, 0x7B9B8677, 0x2E4615EB,
    0x3F797CC7, 0x0870BBC1, 0x5C7D84E6, 0x4A8611AC, 0x5066B2CB, 0x5C1DD3FF, 0x63470BAC, 0x3CE12443,
    0x08A9AEA7, 0x757E5FE2, 0x0B74883F, 0x1B916654, 0x456CA8A6, 0x4AFA6F25, 0x7445B1FE, 0x053794E8,
    0x0428C273, 0x3FA50738, 0x137D8024, 0x1229AAB1, 0x0E2E7552, 0x493A2F95, 0x5AF3C6F9, 0x1AD8CB41,
    0x3C312C8C, 0x2B1A3176, 0x1F4CA0ED, 0x45A83294, 0x5F3B2F4A, 0x1AE82764, 0x73EE487F, 0x1EB4AC11,
};

// very simple 'random' number generator that mutates a single value in memory
// prng implementation is identical to that of guRandom
u32 effect_rand_int(s32 max) {
    u32 seed = (effect_prng_seed << 2) + 2;

    seed *= (seed + 1);
    seed = seed >> 2;

    effect_prng_seed = seed;

    return effect_prng_seed % (max + 1);
}

// very simple stateless 'random' number generator using a LUT
s32 effect_simple_rand(s32 max, s32 idx) {
    s32 lookupVal = SimpleRandLUT[idx % ARRAY_COUNT(SimpleRandLUT)];

    if (lookupVal < 0) {
        lookupVal = -lookupVal;
    }

    return lookupVal % (max + 1);
}

// Unused, UB, abandon all hope, ye who enter here
void func_E02000AC(s32 arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 width;
    s32 x;
    s32 new_var;
    s32 var_t3;
    s32 s2 = 20;
    s32 s1 = 0;

    gDPSetPrimColor(gMainGfxPos++, 0, 0, 128, 128, 128, 255);
    width = 80;

    for (i = 0; i < 10; i++, s1 = i * 24, s2 = i * 24 + 20) {
        x = arg0;
        new_var = x + width;
        var_t3 = i * 6;
        gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, nuGfxCfb_ptr);
        gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                  6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 7, G_TX_NOLOD);
        gDPLoadSync(gMainGfxPos++);
        gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, s1, 0x013C, s2);
        gDPPipeSync(gMainGfxPos++);
        gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 0x0000, G_TX_RENDERTILE, 0,
                   G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 7, G_TX_NOLOD);
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, arg0 << G_TEXTURE_IMAGE_FRAC,
                       (arg1 + var_t3) << G_TEXTURE_IMAGE_FRAC, (arg0 + 79) << G_TEXTURE_IMAGE_FRAC,
                       ((arg1 + var_t3) + 5) << G_TEXTURE_IMAGE_FRAC);
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE + 1, arg0 << G_TEXTURE_IMAGE_FRAC,
                       (arg1 + var_t3) << G_TEXTURE_IMAGE_FRAC, (arg0 + 79) << G_TEXTURE_IMAGE_FRAC,
                       ((arg1 + var_t3) + 5) << G_TEXTURE_IMAGE_FRAC);

        for (j = 0; j < 1; j++) {
            gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, nuGfxCfb_ptr);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                       ((((((x + width) - 1) - x) + 1) * G_IM_SIZ_16b_TILE_BYTES) + 7) >> 3, 0x100, G_TX_LOADTILE, 0,
                       G_TX_WRAP, 6, G_TX_NOLOD, G_TX_WRAP, 7, G_TX_NOLOD);
            gDPLoadSync(gMainGfxPos++);
            gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, x << G_TEXTURE_IMAGE_FRAC,
                        (arg1 + var_t3) << G_TEXTURE_IMAGE_FRAC,
                        ((new_var) - 1) << G_TEXTURE_IMAGE_FRAC,
                        ((arg1 + var_t3) + 5) << G_TEXTURE_IMAGE_FRAC);
            gDPPipeSync(gMainGfxPos++);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                       ((((((x + width) - 1) - x) + 1) * G_IM_SIZ_16b_TILE_BYTES) + 7) >> 3, 0x100, G_TX_RENDERTILE + 1,
                       0, G_TX_WRAP, 6, G_TX_NOLOD, G_TX_WRAP, 7, G_TX_NOLOD);
            gSPTextureRectangle(gMainGfxPos++, x * 4, (arg1 + var_t3) * 4, (x + width) * 4, ((arg1 + var_t3) + 6) * 4,
                                0, x * 32, (arg1 + (i * 6)) * 32, 0x400, 0x400);
        }
        gDPPipeSync(gMainGfxPos++);
    }
}
