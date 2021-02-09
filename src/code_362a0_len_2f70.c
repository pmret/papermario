#include "common.h"

INCLUDE_ASM(s32, "code_362a0_len_2f70", allocate_hit_tables);

void func_8005AF84(void) {
}

void func_8005AF8C(void) {
}

INCLUDE_ASM(s32, "code_362a0_len_2f70", initialize_collision);

INCLUDE_ASM(s32, "code_362a0_len_2f70", load_hit_asset);

INCLUDE_ASM(s32, "code_362a0_len_2f70", load_collision);

INCLUDE_ASM(s32, "code_362a0_len_2f70", load_stage_collision);

INCLUDE_ASM(s32, "code_362a0_len_2f70", load_hit_data);

INCLUDE_ASM(void, "code_362a0_len_2f70", parent_collider_to_model, s32 colliderID, s16 modelIndex);

INCLUDE_ASM(s32, "code_362a0_len_2f70", _add_hit_vert_to_buffer);

INCLUDE_ASM(s32, "code_362a0_len_2f70", _get_hit_vert_index_from_buffer);

INCLUDE_ASM(void, "code_362a0_len_2f70", update_collider_transform, s16 colliderID);

INCLUDE_ASM(s32, "code_362a0_len_2f70", get_collider_type_by_id);

INCLUDE_ASM(s32, "code_362a0_len_2f70", get_flat_collider_normal);

INCLUDE_ASM(void, "code_362a0_len_2f70", get_collider_center, s32 colliderID, f32* x, f32* y, f32* z);

INCLUDE_ASM(s32, "code_362a0_len_2f70", test_ray_triangle_general);

INCLUDE_ASM(s32, "code_362a0_len_2f70", test_down_ray_triangle);

INCLUDE_ASM(s32, "code_362a0_len_2f70", test_up_ray_triangle);

INCLUDE_ASM(s32, "code_362a0_len_2f70", test_ray_colliders);

INCLUDE_ASM(s32, "code_362a0_len_2f70", test_ray_zones);

INCLUDE_ASM(s32, "code_362a0_len_2f70", test_up_ray_collider);

INCLUDE_ASM(s32, "code_362a0_len_2f70", test_ray_entities);

INCLUDE_ASM(s32, "code_362a0_len_2f70", func_8005DB00);

INCLUDE_ASM(s32, "code_362a0_len_2f70", func_8005DD54);

s32 func_8005DDF0(void) {
    return ~gCurrentEncounter.unk_08 != 0;
}
