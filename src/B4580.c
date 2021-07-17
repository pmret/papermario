#include "common.h"

s32 D_8014C250[] = {0x0001003C, 0x00000000, 0x00000000, 0x00000000};

INCLUDE_ASM(s32, "B4580", animator_copy_vertices_to_buffer);

INCLUDE_ASM(s32, "B4580", animator_make_mirrorZ);

INCLUDE_ASM(s32, "B4580", animator_make_mirrorY);

INCLUDE_ASM(s32, "B4580", animator_make_mirrorX);

INCLUDE_ASM(s32, "B4580", animator_make_identity);

INCLUDE_ASM(s32, "B4580", get_animator_child_with_id);

INCLUDE_ASM(s32, "B4580", get_animator_child_for_model);

INCLUDE_ASM(s32, "B4580", free_animator_nodes);

INCLUDE_ASM(s32, "B4580", clear_animator_list);

INCLUDE_ASM(s32, "B4580", reset_animator_list);

INCLUDE_ASM(s32, "B4580", delete_model_animator_node);

INCLUDE_ASM(s32, "B4580", delete_model_animator_nodes);

INCLUDE_ASM(s32, "B4580", delete_model_animator);

INCLUDE_ASM(s32, "B4580", create_model_animator);

INCLUDE_ASM(s32, "B4580", create_mesh_animator);

INCLUDE_ASM(s32, "B4580", add_anim_node);

INCLUDE_ASM(s32, "B4580", update_model_animator);

INCLUDE_ASM(s32, "B4580", func_8011EA54);

INCLUDE_ASM(s32, "B4580", step_model_animator);

INCLUDE_ASM(s32, "B4580", animator_update_model_transforms);

INCLUDE_ASM(s32, "B4580", animator_node_update_model_transform);

INCLUDE_ASM(s32, "B4580", render_animated_model);

INCLUDE_ASM(s32, "B4580", render_animated_model_with_vertices);

INCLUDE_ASM(s32, "B4580", appendGfx_animator);

INCLUDE_ASM(s32, "B4580", appendGfx_animator_node);

INCLUDE_ASM(s32, "B4580", get_animator_node_for_tree_index);

INCLUDE_ASM(s32, "B4580", get_animator_node_with_id);

INCLUDE_ASM(s32, "B4580", set_animator_tree_to_node_map);

AnimatedMesh* get_animator_by_index(s32 animModelID) {
    return (*gCurrentAnimMeshListPtr)[animModelID & ~0x800];
}

AnimatedMesh* set_animator_render_callback(s32 animModelID, s32 arg1, s32 arg2) {
    AnimatedMesh* ret = (*gCurrentAnimMeshListPtr)[animModelID & ~0x800];

    ret->unk_2D4 = arg2;
    ret->unk_2D8 = arg1;
    return ret;
}

INCLUDE_ASM(s32, "B4580", enable_anim_model_fog);

INCLUDE_ASM(s32, "B4580", disable_anim_model_fog);

INCLUDE_ASM(s32, "B4580", set_anim_model_fog_dist);

INCLUDE_ASM(s32, "B4580", set_anim_model_fog_color);

INCLUDE_ASM(s32, "B4580", is_anim_model_fog_enabled);

INCLUDE_ASM(s32, "B4580", get_anim_model_fog_distance);

INCLUDE_ASM(s32, "B4580", get_anim_model_fog_color);

INCLUDE_ASM(s32, "B4580", set_animator_flags);

INCLUDE_ASM(s32, "B4580", clear_animator_flags);

INCLUDE_ASM(s32, "B4580", play_model_animation);

INCLUDE_ASM(s32, "B4580", play_model_animation_starting_from);

INCLUDE_ASM(s32, "B4580", load_model_animator_node);

INCLUDE_ASM(s32, "B4580", load_model_animator_tree);

INCLUDE_ASM(s32, "B4580", load_mesh_animator_node);

INCLUDE_ASM(s32, "B4580", load_mesh_animator_tree);

INCLUDE_ASM(s32, "B4580", reload_mesh_animator_node);

INCLUDE_ASM(s32, "B4580", reload_mesh_animator_tree);

INCLUDE_ASM(s32, "B4580", step_mesh_animator);
