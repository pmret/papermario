#ifndef _EFFECT_SHIMS_H_
#define _EFFECT_SHIMS_H_

void shim_guRotateF(float mf[4][4], float a, float x, float y, float z);
void shim_guTranslateF(float mf[4][4], float x, float y, float z);
void shim_guTranslate(Mtx *m, float x, float y, float z);
void shim_guScaleF(float mf[4][4], float x, float y, float z);
void shim_guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);
void shim_guMtxF2L(float mf[4][4], Mtx *m);
RenderTask* shim_queue_render_task(RenderTask* task);
EffectInstance* shim_create_effect_instance(EffectBlueprint* effectBp);
void shim_remove_effect(EffectInstance*);
void* shim_general_heap_malloc(s32 size);
void shim_mem_clear(void* data, s32 numBytes);
s32 shim_rand_int(s32);
f32 shim_clamp_angle(f32 theta);
f32 shim_sin_deg(f32 x);
f32 shim_cos_deg(f32 x);
f32 shim_atan2(f32 startX, f32 startZ, f32 endX, f32 endZ);
b32 shim_npc_raycast_down_sides(s32, f32*, f32*, f32*, f32*);
s32 shim_load_effect(s32 effectIndex);
float shim_sqrtf(float value);
void shim_mdl_draw_hidden_panel_surface(Gfx**, u16 treeIndex);
s32 shim_is_point_visible(f32, f32, f32, s32, f32*, f32*);
void shim_guPerspectiveF(f32 mf[4][4], u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void shim_transform_point(Matrix4f mtx, f32 inX, f32 inY, f32 inZ, f32 inS, f32* outX, f32* outY, f32* outZ, f32* outW);
void shim_guPositionF(float mf[4][4], float r, float p, float h, float s, float x, float y, float z);
void shim_guOrthoF(float mf[4][4], float l, float r, float b, float t, float n, float f, float scale);
void shim_guFrustumF(float mf[4][4], float l, float r, float b, float t, float n, float f, float scale);
void shim_draw_prev_frame_buffer_at_screen_pos(s32, s32, s32, s32, f32);
void shim_draw_box(
    s32 flags, WindowStyle windowStyle, s32 posX, s32 posY, s32 posZ, s32 width, s32 height, u8 opacity,
    u8 darkening, f32 scaleX, f32 scaleY, f32 rotX, f32 rotY, f32 rotZ, void (*fpDrawContents)(void*),
    void* drawContentsArg0, Matrix4f rotScaleMtx, s32 translateX, s32 translateY, f32 (*outMtx)[4]
);
void shim_draw_msg(s32, s32, s32, s32, s32, s32);
s32 shim_get_msg_width(s32, u16);
void shim_mdl_get_shroud_tint_params(u8* r, u8* g, u8* b, u8* a);
void shim_sfx_play_sound_at_position(s32 soundID, s32 value2, f32 posX, f32 posY, f32 posZ);

#define guRotateF shim_guRotateF
#define guTranslateF shim_guTranslateF
#define guTranslate shim_guTranslate
#define guScaleF shim_guScaleF
#define guMtxCatF shim_guMtxCatF
#define guMtxF2L shim_guMtxF2L
#define queue_render_task shim_queue_render_task
#define create_effect_instance shim_create_effect_instance
#define remove_effect shim_remove_effect
#define general_heap_malloc shim_general_heap_malloc
#define mem_clear shim_mem_clear
#define rand_int shim_rand_int
#define clamp_angle shim_clamp_angle
#define sin_deg shim_sin_deg
#define cos_deg shim_cos_deg
#define atan2 shim_atan2
#define npc_raycast_down_sides shim_npc_raycast_down_sides
#define load_effect shim_load_effect
#define sqrtf shim_sqrtf
#define mdl_draw_hidden_panel_surface shim_mdl_draw_hidden_panel_surface
#define is_point_visible shim_is_point_visible
#define guPerspectiveF shim_guPerspectiveF
#define transform_point shim_transform_point
#define guPositionF shim_guPositionF
#define guOrthoF shim_guOrthoF
#define guFrustumF shim_guFrustumF
#define draw_prev_frame_buffer_at_screen_pos shim_draw_prev_frame_buffer_at_screen_pos
#define draw_box shim_draw_box
#define draw_msg shim_draw_msg
#define get_msg_width shim_get_msg_width
#define mdl_get_shroud_tint_params shim_mdl_get_shroud_tint_params
#define sfx_play_sound_at_position shim_sfx_play_sound_at_position

#endif
