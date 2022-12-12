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
void shim_guPerspectiveF(f32 mf[4][4], u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void shim_guPositionF(float mf[4][4], float r, float p, float h, float s, float x, float y, float z);
void shim_guOrthoF(float mf[4][4], float l, float r, float b, float t, float n, float f, float scale);
void shim_guFrustumF(float mf[4][4], float l, float r, float b, float t, float n, float f, float scale);
void shim_mem_clear(void* data, s32 numBytes);
void shim_transform_point(Matrix4f mtx, f32 inX, f32 inY, f32 inZ, f32 inS, f32* outX, f32* outY, f32* outZ, f32* outS);
s32 shim_npc_raycast_down_sides(s32, f32*, f32*, f32*, f32*);
void shim_sfx_play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);
void shim_mdl_draw_hidden_panel_surface(Gfx**, u16 treeIndex);
void shim_draw_box(s32 flags, WindowStyle windowStyle, s32 posX, s32 posY, s32 posZ, s32 width, s32 height, u8 opacity,
                   u8 darkening, f32 scaleX, f32 scaleY, f32 rotX, f32 rotY, f32 rotZ, void (*fpDrawContents)(void*),
                   void* drawContentsArg0, Matrix4f rotScaleMtx, s32 translateX, s32 translateY, f32 (*outMtx)[4]);

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
void emote_main(s32, Npc*, f32, f32, f32, f32, f32, s32, EffectInstance**);
void sparkles_main(s32, f32, f32, f32, f32);
EffectInstance* shape_spell_main(s32, f32, f32, f32, f32, f32, f32, s32);
void gather_energy_pink_main(s32, f32, f32, f32, f32, s32);
void drop_leaves_main(s32, f32, f32, f32, s32);
EffectInstance* dust_main(s32, f32, f32, f32, s32);
void shattering_stones_main(s32, f32, f32, f32, f32);
void smoke_ring_main(s32, f32, f32, f32);
void damage_stars_main(s32, f32, f32, f32, f32, f32, f32, s32);
void explosion_main(s32, f32, f32, f32);
void lens_flare_main(s32, f32, f32, f32, s32);
void got_item_outline_main(s32, f32, f32, f32, f32, EffectInstance**);
void spiky_white_aura_main(s32, f32, f32, f32, s32);
void smoke_impact_main(s32, f32, f32, f32, f32, s32, f32, s32);
void damage_indicator_main(s32, f32, f32, f32, f32, f32, s32, EffectInstance**);
EffectInstance* purple_ring_main(s32, f32, f32, f32, f32, f32, f32, f32);
void flame_main(s32, f32, f32, f32, f32, EffectInstance**);
void stars_burst_main(s32, f32, f32, f32, f32, f32, s32);
void stars_shimmer_main(s32, f32 x, f32 y, f32 z, f32, f32, s32, s32);
void rising_bubble_main(s32, f32, f32, f32, f32);
void ring_blast_main(s32, f32, f32, f32, f32, s32);
void shockwave_main(s32, f32, f32, f32);
void music_note_main(s32, f32, f32, f32);
void smoke_burst_main(s32, f32, f32, f32, f32, s32);
void sweat_main(s32, f32, f32, f32, f32, f32, s32);
void sleep_bubble_main(s32, f32, f32, f32, f32, f32, EffectInstance**);
void windy_leaves_main(s32, f32, f32, f32);
void falling_leaves_main(s32, f32, f32, f32);
void stars_spread_main(s32, f32, f32, f32, s32, s32);
void steam_burst_main(s32, f32, f32, f32, f32, s32);
void stars_orbiting_main(s32, f32, f32, f32, f32, s32, EffectInstance**);
void big_snowflakes_main(s32, f32, f32, f32);
EffectInstance* debuff_main(s32, f32, f32, f32);
EffectInstance* green_impact_main(s32, f32, f32, f32, f32);
EffectInstance* radial_shimmer_main(s32, f32, f32, f32, f32, s32);
void ending_decals_main(s32, f32, f32, f32, f32, EffectInstance**);
void light_rays_main(s32, f32, f32, f32, f32, EffectInstance**);
EffectInstance* lightning_main(s32, f32, f32, f32, f32, f32);
EffectInstance* fire_breath_main(s32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
EffectInstance* shimmer_burst_main(s32, f32, f32, f32, f32, s32);
void energy_shockwave_main(s32, f32, f32, f32, f32, s32);
EffectInstance* shimmer_wave_main(s32, f32, f32, f32, f32, f32, s32, s32);
void aura_main(s32, f32, f32, f32, f32, EffectInstance**);
void bulb_glow_main(s32, f32, f32, f32, f32, EffectInstance**);
void fx_3D_main(s32, f32, f32, f32, f32, f32, f32, s32, EffectInstance**);
void blast_main(s32, f32, f32, f32, f32, s32);
EffectInstance* fire_flower_main(s32, f32, f32, f32, s32);
EffectInstance* recover_main(s32, f32, f32, f32, s32);
EffectInstance* disable_x_main(s32, f32, f32, f32, s32);
EffectInstance* bombette_breaking_main(s32, s32, s32, f32, s32, s32);
EffectInstance* firework_main(s32, f32, f32, f32, f32, s32);
EffectInstance* confetti_main(s32, f32, f32, f32, f32, s32);
EffectInstance* snowfall_main(s32, s32);
EffectInstance* fx_46_main(s32, PlayerStatus*, f32, s32);
EffectInstance* gather_magic_main(s32, f32, f32, f32, f32, s32);
EffectInstance* attack_result_text_main(s32, f32, f32, f32, f32, s32);
EffectInstance* small_gold_sparkle_main(s32, f32, f32, f32, f32);
EffectInstance* flashing_box_shockwave_main(s32, f32, f32, f32, f32, f32);
EffectInstance* balloon_main(s32, f32, f32, f32, f32, s32);
EffectInstance* floating_rock_main(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* chomp_drop_main(s32, f32, f32, f32, f32, s32, f32, s32, f32, s32);
EffectInstance* quizmo_stage_main(s32, f32, f32, f32);
EffectInstance* radiating_energy_orb_main(s32, f32, f32, f32, f32, s32);
EffectInstance* quizmo_answer_main(s32, f32, f32, f32);
EffectInstance* motion_blur_flame_main(s32, f32, f32, f32, f32, s32);
EffectInstance* energy_orb_wave_main(s32, f32, f32, f32, f32, s32);
EffectInstance* merlin_house_stars_main(s32, f32, f32, f32);
EffectInstance* quizmo_audience_main(s32, f32, f32, f32);
EffectInstance* butterflies_main(s32, f32, f32, f32);
EffectInstance* stat_change_main(s32, f32, f32, f32, f32, s32);
EffectInstance* snaking_static_main(s32, f32, f32, f32, f32, s32);
EffectInstance* thunderbolt_ring_main(s32, f32, f32, f32, f32, s32);
EffectInstance* squirt_main(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* water_block_main(s32, f32, f32, f32, f32, s32);
EffectInstance* waterfall_main(s32, f32, f32, f32, f32, s32);
EffectInstance* water_fountain_main(s32, f32, f32, f32, f32, s32);
EffectInstance* underwater_main(s32, f32, f32, f32, f32, s32);
EffectInstance* lightning_bolt_main(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* water_splash_main(s32, f32, f32, f32, f32, s32);
EffectInstance* snowman_doll_main(s32, f32, f32, f32, f32, s32);
EffectInstance* fright_jar_main(s32, f32, f32, f32, f32, s32);
EffectInstance* stop_watch_main(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_63_main(s32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
EffectInstance* throw_spiny_main(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* fx_65_main(s32, f32, f32, f32, f32, s32);
EffectInstance* tubba_heart_attack_main(s32, f32, f32, f32, f32, s32);
EffectInstance* whirlwind_main(s32, f32, f32, f32, f32, s32);
EffectInstance* red_impact_main(s32, f32, f32, f32, f32);
EffectInstance* floating_cloud_puff_main(s32, f32, f32, f32, f32, s32);
EffectInstance* energy_in_out_main(s32, f32, f32, f32, f32, s32);
EffectInstance* tattle_window_main(s32, f32, f32, f32, f32, s32);
EffectInstance* shiny_flare_main(s32, f32, f32, f32, f32);
EffectInstance* huff_puff_breath_main(s32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* cold_breath_main(s32, f32, f32, f32, f32, s32);
EffectInstance* embers_main(s32, f32, f32, f32, f32, f32, f32, s32, s32, f32, f32);
EffectInstance* hieroglyphs_main(s32, f32, f32, f32, f32, s32);
EffectInstance *misc_particles_main(s32, f32, f32, f32, f32, f32, f32, s32, s32);
EffectInstance* static_status_main(s32, f32, f32, f32, f32, s32, s32);
EffectInstance* moving_cloud_main(s32, f32, f32, f32, f32, f32, f32, f32, f32);
EffectInstance* fx_75_main(s32, f32, f32, f32, f32, s32);
EffectInstance* firework_rocket_main(s32, f32, f32, f32, f32, f32, f32, f32, s32);
EffectInstance* peach_star_beam_main(s32, f32, f32, f32, f32, s32);
EffectInstance* chapter_change_main(s32, f32, f32, f32, f32, s32);
EffectInstance* ice_shard_main(s32, f32, f32, f32, f32, s32);
EffectInstance* spirit_card_main(s32, f32, f32, f32, f32, s32);
EffectInstance* lil_oink_main(void);
EffectInstance* something_rotating_main(s32, f32, f32, f32, f32, s32);
EffectInstance* breaking_junk_main(s32, f32, f32, f32, f32, s32);
EffectInstance* partner_buff_main(s32, f32, f32, f32, f32, s32);
EffectInstance* quizmo_assistant_main(s32, f32, f32, f32, f32, s32);
EffectInstance* ice_pillar_main(s32 arg0, f32 x, f32 y, f32 z, f32 arg4, s32 arg5);
EffectInstance* sun_main(s32, f32, f32, f32, f32, s32);
EffectInstance* star_spirits_energy_main(s32, f32, f32, f32, f32, s32);
EffectInstance* pink_sparkles_main(s32, f32, f32, f32, f32, f32);
EffectInstance* star_outline_main(s32, f32, f32, f32, f32, s32);
EffectInstance* fx_86_main(s32, f32, f32, f32, f32, s32);

#endif
