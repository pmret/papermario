#ifndef _EFFECTS_INTERNAL_H_
#define _EFFECTS_INTERNAL_H_

#include "effects.h"

s32 func_E0200000(s32);
s32 func_E0200044(s32, s32);

EffectInstance* shim_create_effect_instance(EffectBlueprint* effectBp);
s32 shim_load_effect(s32 effectIndex);
void shim_remove_effect(EffectInstance*);
s32 shim_rand_int(s32);
void* shim_general_heap_malloc(s32 size);
RenderTask* shim_queue_render_task(RenderTask* task);
float shim_sqrtf(float value);
f32 shim_atan2(f32 startX, f32 startZ, f32 endX, f32 endZ);
f32 shim_sin_deg(f32 x);
f32 shim_cos_deg(f32 x);
f32 shim_clamp_angle(f32 theta);
void shim_get_background_color_blend(u8* r, u8* g, u8* b, u8* a);
void shim_guMtxF2L(float mf[4][4], Mtx *m);
void shim_guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);
void shim_guScaleF(float mf[4][4], float x, float y, float z);
void shim_guRotateF(float mf[4][4], float a, float x, float y, float z);
void shim_guTranslate(Mtx *m, float x, float y, float z);
void shim_guTranslateF(float mf[4][4], float x, float y, float z);
void shim_guPositionF(float mf[4][4], float r, float p, float h, float s, float x, float y, float z);
void shim_mem_clear(void* data, s32 numBytes);
void shim_transform_point(Matrix4f mtx, f32 inX, f32 inY, f32 inZ, f32 inS, f32* outX, f32* outY, f32* outZ, f32* outS);
s32 shim_npc_raycast_down_sides(s32, f32*, f32*, f32*, f32*);
void shim_sfx_play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);

// the actual signature is going to be wrong, but it doesn't matter
// TODO remove when every effect's main is sorted out
#define FX_MAIN(name) void name(void);

void big_smoke_puff_main(f32 x, f32 y, f32 z);
void landing_dust_main(s32 type, f32 x, f32 y, f32 z, f32);
void walking_dust_main(s32, f32, f32, f32, f32, f32);
void flower_splash_main(f32, f32, f32, f32);
void flower_trail_main(s32, f32, f32, f32, f32, f32);
void cloud_puff_main(f32, f32, f32, f32);
void cloud_trail_main(s32, f32, f32, f32);
void footprint_main(f32, f32, f32, f32, f32, f32, f32, f32);
void floating_flower_main(s32, f32, f32, f32, s32);
void snowflake_main(f32, f32, f32, s32, s32);
EffectInstance* star_main(s32, f32, f32, f32, f32, f32, f32, f32);
void emote_main(s32, s32, f32, f32, f32, f32, f32, s32, EffectInstance**);
FX_MAIN(sparkles_main);
EffectInstance* shape_spell_main(s32, f32, f32, f32, f32, f32, f32, s32);
FX_MAIN(gather_energy_pink_main);
FX_MAIN(drop_leaves_main);
FX_MAIN(dust_main);
FX_MAIN(shattering_stones_main);
FX_MAIN(smoke_ring_main);
FX_MAIN(damage_stars_main);
FX_MAIN(explosion_main);
FX_MAIN(lens_flare_main);
FX_MAIN(got_item_outline_main);
FX_MAIN(spiky_white_aura_main);
FX_MAIN(smoke_impact_main);
FX_MAIN(damage_indicator_main);
FX_MAIN(purple_ring_main);
FX_MAIN(flame_main);
FX_MAIN(stars_burst_main);
FX_MAIN(stars_shimmer_main);
FX_MAIN(rising_bubble_main);
FX_MAIN(ring_blast_main);
FX_MAIN(shockwave_main);
void music_note_main(s32, f32, f32, f32);
FX_MAIN(smoke_burst_main);
FX_MAIN(sweat_main);
void sleep_bubble_main(s32, f32, f32, f32, f32, f32, EffectInstance**);
FX_MAIN(windy_leaves_main);
FX_MAIN(falling_leaves_main);
FX_MAIN(stars_spread_main);
FX_MAIN(steam_burst_main);
FX_MAIN(stars_orbiting_main);
FX_MAIN(big_snowflakes_main);
EffectInstance* debuff_main(s32, f32, f32, f32);
FX_MAIN(green_impact_main);
FX_MAIN(radial_shimmer_main);
FX_MAIN(ending_decals_main);
FX_MAIN(light_rays_main);
FX_MAIN(lightning_main);
EffectInstance* fire_breath_main(s32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
FX_MAIN(shimmer_burst_main);
FX_MAIN(energy_shockwave_main);
FX_MAIN(shimmer_wave_main);
void aura_main(s32, f32, f32, f32, f32, EffectInstance**);
FX_MAIN(fx_3C_main);
FX_MAIN(fx_3D_main);
void blast_main(s32, f32, f32, f32, f32, s32);
EffectInstance* fire_flower_main(s32, f32, f32, f32, s32);
FX_MAIN(recover_main);
FX_MAIN(disable_x_main);
FX_MAIN(bombette_breaking_main);
FX_MAIN(firework_main);
FX_MAIN(confetti_main);
FX_MAIN(snowfall_main);
FX_MAIN(fx_46_main);
FX_MAIN(gather_magic_main);
EffectInstance* attack_result_text_main(s32, f32, f32, f32, f32, s32);
EffectInstance* small_gold_sparkle_main(EffectInstanceDataThing*, f32, f32, f32, f32);
FX_MAIN(flashing_box_shockwave_main);
EffectInstance* balloon_main(s32, f32, f32, f32, f32, s32);
FX_MAIN(floating_rock_main);
FX_MAIN(chomp_drop_main);
FX_MAIN(quizmo_stage_main);
FX_MAIN(radiating_energy_orb_main);
FX_MAIN(quizmo_answer_main);
FX_MAIN(motion_blur_flame_main);
FX_MAIN(energy_orb_wave_main);
FX_MAIN(merlin_house_stars_main);
FX_MAIN(quizmo_audience_main);
FX_MAIN(butterflies_main);
EffectInstance* stat_change_main(s32, f32, f32, f32, f32, s32);
FX_MAIN(snaking_static_main);
FX_MAIN(thunderbolt_ring_main);
FX_MAIN(squirt_main);
FX_MAIN(water_block_main);
FX_MAIN(waterfall_main);
FX_MAIN(water_fountain_main);
FX_MAIN(underwater_main);
FX_MAIN(lightning_bolt_main);
FX_MAIN(water_splash_main);
FX_MAIN(snowman_doll_main);
FX_MAIN(fright_jar_main);
FX_MAIN(stop_watch_main);
FX_MAIN(fx_63_main);
FX_MAIN(throw_spiny_main);
FX_MAIN(fx_65_main);
FX_MAIN(tubba_heart_attack_main);
FX_MAIN(whirlwind_main);
FX_MAIN(red_impact_main);
FX_MAIN(floating_cloud_puff_main);
FX_MAIN(energy_in_out_main);
EffectInstance* tattle_window_main(s32, f32, f32, f32, f32, s32);
FX_MAIN(shiny_flare_main);
FX_MAIN(huff_puff_breath_main);
FX_MAIN(cold_breath_main);
FX_MAIN(embers_main);
FX_MAIN(hieroglyphs_main);
FX_MAIN(misc_particles_main);
FX_MAIN(static_status_main);
FX_MAIN(moving_cloud_main);
FX_MAIN(fx_75_main);
FX_MAIN(firework_rocket_main);
FX_MAIN(peach_star_beam_main);
FX_MAIN(chapter_change_main);
FX_MAIN(ice_shard_main);
FX_MAIN(spirit_card_main);
FX_MAIN(lil_oink_main);
FX_MAIN(something_rotating_main);
FX_MAIN(breaking_junk_main);
FX_MAIN(partner_buff_main);
FX_MAIN(quizmo_assistant_main);
FX_MAIN(ice_pillar_main);
FX_MAIN(sun_main);
FX_MAIN(star_spirits_energy_main);
FX_MAIN(pink_sparkles_main);
FX_MAIN(star_outline_main);
EffectInstance* fx_86_main(s32, f32, f32, f32, f32, s32);

#endif
