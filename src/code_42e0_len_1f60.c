#include "common.h"

INCLUDE_ASM("code_42e0_len_1f60", poll_rumble);

INCLUDE_ASM("code_42e0_len_1f60", start_rumble);

INCLUDE_ASM("code_42e0_len_1f60", func_80028F8C);

INCLUDE_ASM("code_42e0_len_1f60", func_80028FE0);

INCLUDE_API_ASM("code_42e0_len_1f60", length2D);

HeapNode* INCLUDE_ASM("code_42e0_len_1f60", _heap_create, s32 addr, s32 size);

INCLUDE_ASM("code_42e0_len_1f60", _heap_malloc);

INCLUDE_ASM("code_42e0_len_1f60", _heap_malloc_tail);

INCLUDE_ASM("code_42e0_len_1f60", _heap_free);

INCLUDE_ASM("code_42e0_len_1f60", _heap_realloc);

INCLUDE_API_ASM("code_42e0_len_1f60", cosine);

INCLUDE_API_ASM("code_42e0_len_1f60", sign);

INCLUDE_ASM("code_42e0_len_1f60", int_to_string);

INCLUDE_ASM("code_42e0_len_1f60", mem_clear);

INCLUDE_ASM("code_42e0_len_1f60", transform_point);

INCLUDE_ASM("code_42e0_len_1f60", copy_matrix);

INCLUDE_ASM("code_42e0_len_1f60", dma_copy);

INCLUDE_ASM("code_42e0_len_1f60", func_80029860);

INCLUDE_ASM("code_42e0_len_1f60", _advance_rng);

INCLUDE_ASM("code_42e0_len_1f60", func_80029934);

INCLUDE_ASM("code_42e0_len_1f60", func_80029994);

s32 INCLUDE_ASM("code_42e0_len_1f60", rand_int, s32 arg0);

INCLUDE_API_ASM("code_42e0_len_1f60", signF);

INCLUDE_API_ASM("code_42e0_len_1f60", round);

f32 INCLUDE_ASM("code_42e0_len_1f60", clamp_angle, f32 theta);

INCLUDE_ASM("code_42e0_len_1f60", get_clamped_angle_diff);

f32 INCLUDE_ASM("code_42e0_len_1f60", atan2, f32 startX, f32 startZ, f32 endX, f32 endZ);

INCLUDE_ASM("code_42e0_len_1f60", get_player_normal_yaw);

INCLUDE_ASM("code_42e0_len_1f60", get_player_normal_pitch);

f32 INCLUDE_ASM("code_42e0_len_1f60", dist2D, f32 ax, f32 ay, f32 bx, f32 by);

f32 INCLUDE_ASM("code_42e0_len_1f60", dist3D, f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz);

void INCLUDE_ASM("code_42e0_len_1f60", add_vec2D_polar, f32* x, f32* y, f32 r, f32 theta);

INCLUDE_ASM("code_42e0_len_1f60", _wrap_trig_lookup_value);

INCLUDE_ASM("code_42e0_len_1f60", sin_cos_rad);

INCLUDE_ASM("code_42e0_len_1f60", sin_rad);

INCLUDE_ASM("code_42e0_len_1f60", cos_rad);

INCLUDE_ASM("code_42e0_len_1f60", sin_cos_deg);

f32 INCLUDE_ASM("code_42e0_len_1f60", sin_deg, f32 x);

f32 INCLUDE_ASM("code_42e0_len_1f60", cos_deg, f32 x);

f32 INCLUDE_ASM("code_42e0_len_1f60", update_lerp, Easing easing, f32 start, f32 end, s32 elapsed, s32 duration);

INCLUDE_ASM("code_42e0_len_1f60", func_8002A904);

INCLUDE_ASM("code_42e0_len_1f60", func_8002AAC4);

INCLUDE_ASM("code_42e0_len_1f60", func_8002AB5C);
