#include "common.h"
#include "effects.h"
#include "effects_internal.h"
#include "ld_addrs.h"

typedef s32 TlbEntry[0x1000 / 4];
typedef TlbEntry TlbMappablePage[15];

#define EFFECT_LOADED 1

extern EffectGraphics gEffectGraphicsData[15];
extern EffectInstance* gEffectInstances[96];

extern TlbMappablePage D_80197000;
extern Addr D_801A6000;

#define FX_ENTRY(name, gfx_name) { \
    name##_main, effect_##name##_ROM_START, effect_##name##_ROM_END, effect_##name##_VRAM, gfx_name##_ROM_START, \
    gfx_name##_ROM_END \
}

EffectTableEntry gEffectTable[] = {
    /* 0x00 */ {},
    /* 0x01 */ FX_ENTRY(big_smoke_puff, effect_gfx_big_smoke_puff),
    /* 0x02 */ {},
    /* 0x03 */ {},
    /* 0x04 */ {},
    /* 0x05 */ {},
    /* 0x06 */ FX_ENTRY(landing_dust, effect_gfx_landing_dust),
    /* 0x07 */ FX_ENTRY(walking_dust, effect_gfx_landing_dust),
    /* 0x08 */ FX_ENTRY(flower_splash, effect_gfx_flower_splash_trail),
    /* 0x09 */ FX_ENTRY(flower_trail, effect_gfx_flower_splash_trail),
    /* 0x0A */ FX_ENTRY(cloud_puff, effect_gfx_cloud_puff_trail),
    /* 0x0B */ FX_ENTRY(cloud_trail, effect_gfx_cloud_puff_trail),
    /* 0x0C */ FX_ENTRY(footprint, effect_gfx_footprint),
    /* 0x0D */ FX_ENTRY(floating_flower, effect_gfx_floating_flower),
    /* 0x0E */ FX_ENTRY(snowflake, effect_gfx_snowflake),
    /* 0x0F */ FX_ENTRY(star, effect_gfx_star),
    /* 0x10 */ FX_ENTRY(emote, effect_gfx_emote),
    /* 0x11 */ FX_ENTRY(sparkles, effect_gfx_sparkles),
    /* 0x12 */ FX_ENTRY(shape_spell, effect_gfx_shape_spell),
    /* 0x13 */ FX_ENTRY(gather_energy_pink, effect_gfx_gather_energy_pink),
    /* 0x14 */ FX_ENTRY(drop_leaves, effect_gfx_drop_leaves),
    /* 0x15 */ FX_ENTRY(dust, effect_gfx_dust),
    /* 0x16 */ FX_ENTRY(shattering_stones, effect_gfx_shattering_stones),
    /* 0x17 */ FX_ENTRY(smoke_ring, effect_gfx_landing_dust),
    /* 0x18 */ FX_ENTRY(damage_stars, effect_gfx_damage_stars),
    /* 0x19 */ FX_ENTRY(explosion, effect_gfx_explosion),
    /* 0x1A */ FX_ENTRY(lens_flare, effect_gfx_lens_flare),
    /* 0x1B */ FX_ENTRY(got_item_outline, effect_gfx_got_item_outline),
    /* 0x1C */ FX_ENTRY(spiky_white_aura, effect_gfx_spiky_white_aura),
    /* 0x1D */ FX_ENTRY(smoke_impact, effect_gfx_landing_dust),
    /* 0x1E */ FX_ENTRY(damage_indicator, effect_gfx_damage_indicator),
    /* 0x1F */ FX_ENTRY(purple_ring, effect_gfx_purple_ring),
    /* 0x20 */ FX_ENTRY(flame, effect_gfx_flame),
    /* 0x21 */ FX_ENTRY(stars_burst, effect_gfx_damage_stars),
    /* 0x22 */ FX_ENTRY(stars_shimmer, effect_gfx_sparkles),
    /* 0x23 */ FX_ENTRY(rising_bubble, effect_gfx_rising_bubble),
    /* 0x24 */ FX_ENTRY(ring_blast, effect_gfx_ring_blast),
    /* 0x25 */ FX_ENTRY(shockwave, effect_gfx_shockwave),
    /* 0x26 */ FX_ENTRY(music_note, effect_gfx_music_note),
    /* 0x27 */ FX_ENTRY(smoke_burst, effect_gfx_landing_dust),
    /* 0x28 */ FX_ENTRY(sweat, effect_gfx_sweat),
    /* 0x29 */ FX_ENTRY(sleep_bubble, effect_gfx_sleep_bubble),
    /* 0x2A */ {},
    /* 0x2B */ FX_ENTRY(windy_leaves, effect_gfx_drop_leaves),
    /* 0x2C */ FX_ENTRY(falling_leaves, effect_gfx_falling_leaves),
    /* 0x2D */ FX_ENTRY(stars_spread, effect_gfx_stars_spread),
    /* 0x2E */ FX_ENTRY(steam_burst, effect_gfx_steam_burst),
    /* 0x2F */ FX_ENTRY(stars_orbiting, effect_gfx_stars_orbiting),
    /* 0x30 */ FX_ENTRY(big_snowflakes, effect_gfx_big_snowflakes),
    /* 0x31 */ FX_ENTRY(debuff, effect_gfx_debuff),
    /* 0x32 */ FX_ENTRY(green_impact, effect_gfx_green_impact),
    /* 0x33 */ FX_ENTRY(radial_shimmer, effect_gfx_radial_shimmer),
    /* 0x34 */ FX_ENTRY(ending_decals, effect_gfx_ending_decals),
    /* 0x35 */ FX_ENTRY(light_rays, effect_gfx_light_rays),
    /* 0x36 */ FX_ENTRY(lightning, effect_gfx_lightning),
    /* 0x37 */ FX_ENTRY(fire_breath, effect_gfx_fire_breath),
    /* 0x38 */ FX_ENTRY(shimmer_burst, effect_gfx_sparkles),
    /* 0x39 */ FX_ENTRY(energy_shockwave, effect_gfx_energy_shockwave),
    /* 0x3A */ FX_ENTRY(shimmer_wave, effect_gfx_sparkles),
    /* 0x3B */ FX_ENTRY(aura, effect_gfx_aura),
    /* 0x3C */ FX_ENTRY(bulb_glow, effect_gfx_bulb_glow),
    /* 0x3D */ FX_ENTRY(effect_3D, effect_gfx_effect_3D),
    /* 0x3E */ FX_ENTRY(blast, effect_gfx_blast),
    /* 0x3F */ FX_ENTRY(fire_flower, effect_gfx_fire_flower),
    /* 0x40 */ FX_ENTRY(recover, effect_gfx_recover),
    /* 0x41 */ FX_ENTRY(disable_x, effect_gfx_disable_x),
    /* 0x42 */ FX_ENTRY(bombette_breaking, effect_gfx_blast),
    /* 0x43 */ FX_ENTRY(firework, effect_gfx_firework),
    /* 0x44 */ FX_ENTRY(confetti, effect_gfx_confetti),
    /* 0x45 */ FX_ENTRY(snowfall, effect_gfx_snowfall),
    /* 0x46 */ FX_ENTRY(effect_46, effect_gfx_effect_46),
    /* 0x47 */ FX_ENTRY(gather_magic, effect_gfx_gather_magic),
    /* 0x48 */ FX_ENTRY(attack_result_text, effect_gfx_attack_result_text),
    /* 0x49 */ FX_ENTRY(small_gold_sparkle, effect_gfx_small_gold_sparkle),
    /* 0x4A */ FX_ENTRY(flashing_box_shockwave, effect_gfx_flashing_box_shockwave),
    /* 0x4B */ FX_ENTRY(balloon, effect_gfx_balloon),
    /* 0x4C */ FX_ENTRY(floating_rock, effect_gfx_floating_rock),
    /* 0x4D */ FX_ENTRY(chomp_drop, effect_gfx_chomp_drop),
    /* 0x4E */ FX_ENTRY(quizmo_stage, effect_gfx_quizmo_stage),
    /* 0x4F */ FX_ENTRY(radiating_energy_orb, effect_gfx_radiating_energy_orb),
    /* 0x50 */ FX_ENTRY(quizmo_answer, effect_gfx_quizmo_answer),
    /* 0x51 */ FX_ENTRY(motion_blur_flame, effect_gfx_motion_blur_flame),
    /* 0x52 */ FX_ENTRY(energy_orb_wave, effect_gfx_energy_orb_wave),
    /* 0x53 */ FX_ENTRY(merlin_house_stars, effect_gfx_merlin_house_stars),
    /* 0x54 */ FX_ENTRY(quizmo_audience, effect_gfx_quizmo_audience),
    /* 0x55 */ FX_ENTRY(butterflies, effect_gfx_butterflies),
    /* 0x56 */ FX_ENTRY(stat_change, effect_gfx_stat_change),
    /* 0x57 */ FX_ENTRY(snaking_static, effect_gfx_snaking_static),
    /* 0x58 */ FX_ENTRY(thunderbolt_ring, effect_gfx_thunderbolt_ring),
    /* 0x59 */ FX_ENTRY(squirt, effect_gfx_squirt),
    /* 0x5A */ FX_ENTRY(water_block, effect_gfx_water_block),
    /* 0x5B */ FX_ENTRY(waterfall, effect_gfx_waterfall),
    /* 0x5C */ FX_ENTRY(water_fountain, effect_gfx_water_fountain),
    /* 0x5D */ FX_ENTRY(underwater, effect_gfx_underwater),
    /* 0x5E */ FX_ENTRY(lightning_bolt, effect_gfx_lightning_bolt),
    /* 0x5F */ FX_ENTRY(water_splash, effect_gfx_water_splash),
    /* 0x60 */ FX_ENTRY(snowman_doll, effect_gfx_snowman_doll),
    /* 0x61 */ FX_ENTRY(fright_jar, effect_gfx_fright_jar),
    /* 0x62 */ FX_ENTRY(stop_watch, effect_gfx_stop_watch),
    /* 0x63 */ FX_ENTRY(effect_63, effect_gfx_effect_63),
    /* 0x64 */ FX_ENTRY(throw_spiny, effect_gfx_throw_spiny),
    /* 0x65 */ FX_ENTRY(effect_65, effect_gfx_effect_65),
    /* 0x66 */ FX_ENTRY(tubba_heart_attack, effect_gfx_tubba_heart_attack),
    /* 0x67 */ FX_ENTRY(whirlwind, effect_gfx_whirlwind),
    /* 0x68 */ FX_ENTRY(red_impact, effect_gfx_shockwave),
    /* 0x69 */ FX_ENTRY(floating_cloud_puff, effect_gfx_floating_cloud_puff),
    /* 0x6A */ {},
    /* 0x6B */ FX_ENTRY(energy_in_out, effect_gfx_energy_in_out),
    /* 0x6C */ FX_ENTRY(tattle_window, effect_gfx_tattle_window),
    /* 0x6D */ FX_ENTRY(shiny_flare, effect_gfx_shiny_flare),
    /* 0x6E */ FX_ENTRY(huff_puff_breath, effect_gfx_huff_puff_breath),
    /* 0x6F */ FX_ENTRY(cold_breath, effect_gfx_cold_breath),
    /* 0x70 */ FX_ENTRY(embers, effect_gfx_embers),
    /* 0x71 */ FX_ENTRY(hieroglyphs, effect_gfx_hieroglyphs),
    /* 0x72 */ FX_ENTRY(misc_particles, effect_gfx_misc_particles),
    /* 0x73 */ FX_ENTRY(static_status, effect_gfx_static_status),
    /* 0x74 */ FX_ENTRY(moving_cloud, effect_gfx_moving_cloud),
    /* 0x75 */ FX_ENTRY(effect_75, effect_gfx_effect_75),
    /* 0x76 */ {},
    /* 0x77 */ FX_ENTRY(firework_rocket, effect_gfx_firework_rocket),
    /* 0x78 */ FX_ENTRY(peach_star_beam, effect_gfx_peach_star_beam),
    /* 0x79 */ FX_ENTRY(chapter_change, effect_gfx_chapter_change),
    /* 0x7A */ FX_ENTRY(ice_shard, effect_gfx_ice_shard),
    /* 0x7B */ FX_ENTRY(spirit_card, effect_gfx_spirit_card),
    /* 0x7C */ FX_ENTRY(lil_oink, effect_gfx_lil_oink),
    /* 0x7D */ FX_ENTRY(something_rotating, effect_gfx_spirit_card),
    /* 0x7E */ FX_ENTRY(breaking_junk, effect_gfx_breaking_junk),
    /* 0x7F */ FX_ENTRY(partner_buff, effect_gfx_partner_buff),
    /* 0x80 */ FX_ENTRY(quizmo_assistant, effect_gfx_quizmo_assistant),
    /* 0x81 */ FX_ENTRY(ice_pillar, effect_gfx_ice_pillar),
    /* 0x82 */ FX_ENTRY(sun, effect_gfx_sun),
    /* 0x83 */ FX_ENTRY(star_spirits_energy, effect_gfx_star_spirits_energy),
    /* 0x84 */ FX_ENTRY(pink_sparkles, effect_gfx_sparkles),
    /* 0x85 */ FX_ENTRY(star_outline, effect_gfx_star_outline),
    /* 0x86 */ FX_ENTRY(effect_86, effect_gfx_effect_86),
};

s32 D_8007FEB8[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000008, 0x00000005, 0x00000003, 0x00000004,
    0x0000000D, 0x0000003C, 0x00000000, 0x00000200, 0x00000000, 0x00000000,
    0x00000003, 0x00000000,
};

/// Used for unbound function points in effect structs.
void stub_effect_delegate(EffectInstance* effect) {
}


void set_effect_pos_offset(EffectInstance* effect, f32 x, f32 y, f32 z) {
    s32* data = effect->data.any;

    ((f32*)data)[1] = x;
    ((f32*)data)[2] = y;
    ((f32*)data)[3] = z;
}

void clear_effect_data(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        gEffectGraphicsData[i].flags = 0;
    }

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        gEffectInstances[i] = 0;
    }

    osUnmapTLBAll();
    osMapTLB(0x10, NULL, _325AD0_VRAM, (s32)&D_801A6000 & 0xFFFFFF, -1, -1);
    dma_copy(_325AD0_ROM_START, _325AD0_ROM_END, _325AD0_VRAM);
}

void func_80059D48(void) {
}

void update_effects(void) {
    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_800 | GLOBAL_OVERRIDES_400))) {
        EffectGraphics* effectGraphics;
        s32 i;

        for (i = 0, effectGraphics = gEffectGraphicsData; i < ARRAY_COUNT(gEffectGraphicsData); i++, effectGraphics++) {
            if (effectGraphics->flags & FX_GRAPHICS_ENABLED) {
                if (!(effectGraphics->flags & FX_GRAPHICS_FLAG_2)) {
                    effectGraphics->flags |= FX_GRAPHICS_FLAG_2;
                    effectGraphics->freeDelay = 3;
                }
            }
        }

        for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
            EffectInstance* effectInstance = gEffectInstances[i];

            if (effectInstance != NULL && (effectInstance->flags & EFFECT_INSTANCE_FLAG_1)) {
                effectInstance->graphics->flags &= ~FX_GRAPHICS_FLAG_2;

                if (gGameStatusPtr->isBattle) {
                    if (effectInstance->flags & EFFECT_INSTANCE_FLAG_4) {
                        effectInstance->graphics->update(effectInstance);
                        effectInstance->flags |= EFFECT_INSTANCE_FLAG_8;
                    }
                } else {
                    if (!(effectInstance->flags & EFFECT_INSTANCE_FLAG_4)) {
                        effectInstance->graphics->update(effectInstance);
                        effectInstance->flags |= EFFECT_INSTANCE_FLAG_8;
                    }
                }
            }
        }

        for (i = 0, effectGraphics = gEffectGraphicsData; i < ARRAY_COUNT(gEffectGraphicsData); i++, effectGraphics++) {
            if (effectGraphics->flags & FX_GRAPHICS_ENABLED) {
                if (effectGraphics->flags & FX_GRAPHICS_FLAG_2) {
                    if (effectGraphics->freeDelay != 0) {
                        effectGraphics->freeDelay--;
                    } else {
                        if (effectGraphics->data != NULL) {
                            general_heap_free(effectGraphics->data);
                            effectGraphics->data = NULL;
                        }
                        effectGraphics->flags = FX_GRAPHICS_DISABLED;
                        osUnmapTLB(i);
                    }
                }
            }
        }
    }
}

void render_effects_world(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] != NULL && gEffectInstances[i]->flags & 1 && gEffectInstances[i]->flags & 8) {
            if (gGameStatusPtr->isBattle) {
                if (gEffectInstances[i]->flags & 4) {
                    gEffectInstances[i]->graphics->renderWorld(gEffectInstances[i]);
                }
            } else {
                if (!(gEffectInstances[i]->flags & 4)) {
                    gEffectInstances[i]->graphics->renderWorld(gEffectInstances[i]);
                }
            }
        }
    }
}

void render_effects_UI(void) {
    s32 cond = TRUE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        EffectInstance* effectInstance = gEffectInstances[i];

        if (effectInstance != NULL) {
            if (effectInstance->flags & EFFECT_INSTANCE_FLAG_1) {
                if (effectInstance->flags & EFFECT_INSTANCE_FLAG_8) {
                    void (*renderUI)(EffectInstance* effect);

                    if (gGameStatusPtr->isBattle && !(effectInstance->flags & EFFECT_INSTANCE_FLAG_4)) {
                        continue;
                    }

                    if (!gGameStatusPtr->isBattle && effectInstance->flags & EFFECT_INSTANCE_FLAG_4) {
                        continue;
                    }

                    renderUI = effectInstance->graphics->renderUI;
                    if (renderUI != stub_effect_delegate) {
                        if (cond) {
                            Camera* camera = &gCameras[gCurrentCameraID];

                            gDPPipeSync(gMainGfxPos++);
                            gSPViewport(gMainGfxPos++, &camera->vp);
                            gSPClearGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG |
                                                G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                                                G_SHADING_SMOOTH | G_CLIPPING | 0x40F9FA);
                            gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
                            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE,
                                              camera->viewportStartX,
                                              camera->viewportStartY,
                                              camera->viewportStartX + camera->viewportW,
                                              camera->viewportStartY + camera->viewportH);
                            gSPClipRatio(gMainGfxPos++, FRUSTRATIO_2);

                            cond = FALSE;
                            if (!(camera->flags & CAMERA_FLAG_ORTHO)) {
                                gSPPerspNormalize(gMainGfxPos++, camera->perspNorm);
                                gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID],
                                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
                            }
                        }

                        renderUI(effectInstance);
                    }
                }
            }
        }
    }
}

EffectInstance* create_effect_instance(EffectBlueprint* effectBp) {
    EffectInstance* newEffectInst;
    EffectGraphics* curEffect;
    s32 i;

    // Search for an unused instance
    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gEffectInstances));

    // Allocate space for the new instance
    gEffectInstances[i] = newEffectInst = general_heap_malloc(sizeof(*newEffectInst));
    ASSERT(newEffectInst != NULL);

    curEffect = &gEffectGraphicsData[0];
    newEffectInst->effectIndex = effectBp->effectID;
    newEffectInst->flags = 1;

    // Look for a loaded effect of the proper index
    for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if ((curEffect->flags & EFFECT_LOADED) && (curEffect->effectIndex == effectBp->effectID)) {
            break;
        }
        curEffect++;
    }

    ASSERT(i < ARRAY_COUNT(gEffectGraphicsData));

    // If this is the first new instance of the effect, initialize the function pointers
    if (curEffect->instanceCounter == 0) {
        curEffect->update = effectBp->update;
        if (curEffect->update == NULL) {
            curEffect->renderWorld = stub_effect_delegate;
        }

        curEffect->renderWorld = effectBp->renderWorld;
        if (curEffect->renderUI == NULL) {
            curEffect->renderUI = stub_effect_delegate;
        }

        curEffect->renderUI = effectBp->unk_14;
        if (curEffect->renderUI == NULL) {
            curEffect->renderUI = stub_effect_delegate;
        }
    }

    curEffect->instanceCounter++;
    newEffectInst->graphics = curEffect;

    if (effectBp->init != NULL) {
        effectBp->init(newEffectInst);
    }

    if (gGameStatusPtr->isBattle) {
        newEffectInst->flags |= 4;
    }
    return newEffectInst;
}

void remove_effect(EffectInstance* effectInstance) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] == effectInstance) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gEffectInstances));

    if (effectInstance->data.any == NULL) {
        general_heap_free(effectInstance);
        gEffectInstances[i] = NULL;
    } else {
        general_heap_free(effectInstance->data.any);
        general_heap_free(effectInstance);
        gEffectInstances[i] = NULL;
    }
}

void remove_all_effects(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        EffectInstance* effect = gEffectInstances[i];

        if (effect != NULL && effect->flags & 4) {
            if (effect->data.any != NULL) {
                general_heap_free(effect->data.any);
            }
            general_heap_free(effect);
            gEffectInstances[i] = NULL;
        }
    }
}

s32 load_effect(s32 effectIndex) {
    EffectTableEntry* effectEntry = &gEffectTable[effectIndex];
    EffectGraphics* curEffect;
    TlbMappablePage* tlbMappablePages;
    s32 i;

    // Look for a loaded effect matching the desired index
    for (i = 0, curEffect = &gEffectGraphicsData[0]; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if (curEffect->flags & EFFECT_LOADED && curEffect->effectIndex == effectIndex) {
            break;
        }
        curEffect++;
    }

    // If an effect was found within the table, initialize it and return
    if (i < ARRAY_COUNT(gEffectGraphicsData)) {
        curEffect->effectIndex = effectIndex;
        curEffect->instanceCounter = 0;
        curEffect->flags = EFFECT_LOADED;
        return 1;
    }

    // If a loaded effect wasn't found, look for the first empty space
    for (i = 0, curEffect = &gEffectGraphicsData[0]; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if (!(curEffect->flags & EFFECT_LOADED)) {
            break;
        }
        curEffect++;
    }

    // If no empty space was found, panic
    ASSERT(i < ARRAY_COUNT(gEffectGraphicsData));

    // Map space for the effect
    tlbMappablePages = &D_80197000;
    osMapTLB(i, 0, effectEntry->dmaDest, (s32)((*tlbMappablePages)[i]) & 0xFFFFFF, -1, -1);

    // Copy the effect into the newly mapped space
    dma_copy(effectEntry->dmaStart, effectEntry->dmaEnd, effectEntry->dmaDest);

    // If there's extra data the effect normally loads, allocate space and copy into the new space
    if (effectEntry->graphicsDmaStart != NULL) {
        void* effectDataBuf = general_heap_malloc(effectEntry->graphicsDmaEnd - effectEntry->graphicsDmaStart);
        curEffect->data = effectDataBuf;
        ASSERT(effectDataBuf != NULL);
        dma_copy(effectEntry->graphicsDmaStart, effectEntry->graphicsDmaEnd, curEffect->data);
    }

    // Initialize the newly loaded effect data
    curEffect->effectIndex = effectIndex;
    curEffect->instanceCounter = 0;
    curEffect->flags = EFFECT_LOADED;
    return 1;
}
