#include "common.h"

s32 D_8014C250[] = {0x0001003C, 0x00000000, 0x00000000, 0x00000000};

extern s32 gAnimModelFogEnabled;
extern s32 gAnimModelFogR;
extern s32 gAnimModelFogG;
extern s32 gAnimModelFogB;
extern s32 gAnimModelFogA;
extern s32 gAnimModelFogStart;
extern s32 gAnimModelFogEnd;

INCLUDE_ASM(s32, "B4580", animator_copy_vertices_to_buffer);

void animator_make_mirrorZ(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = 1.0f;
    mtx[2][2] = -1.0f;
    mtx[3][3] = 1.0f;
}

void animator_make_mirrorY(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = -1.0f;
    mtx[2][2] = 1.0f;
    mtx[3][3] = 1.0f;
}

void animator_make_mirrorX(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = -1.0f;
    mtx[1][1] = 1.0f;
    mtx[2][2] = 1.0f;
    mtx[3][3] = 1.0f;
}

void animator_make_identity(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = 1.0f;
    mtx[2][2] = 1.0f;
    mtx[3][3] = 1.0f;
}

AnimatorNode* get_animator_child_with_id(AnimatorNode* node, s32 id);
INCLUDE_ASM(s32, "B4580", get_animator_child_with_id);

INCLUDE_ASM(s32, "B4580", get_animator_child_for_model);

void free_animator_nodes(AnimatorNode* root) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        if (root->children[i] != NULL) {
            free_animator_nodes(root->children[i]);
        }
    }
    heap_free(root);
}

INCLUDE_ASM(s32, "B4580", clear_animator_list);

INCLUDE_ASM(s32, "B4580", reset_animator_list);

void delete_model_animator_node(AnimatorNode* node) {
    s32 i;

    node->flags = 0;

    for (i = 0; i < 0x20; i++) {
        if (node->children[i] != NULL) {
            delete_model_animator_node(node->children[i]);
            node->children[i] = NULL;
        }
    }

    heap_free(node);
}

void delete_model_animator_nodes(ModelAnimator* animator) {
    animator->nextUniqueID = 0;

    if (animator->rootNode != NULL) {
        delete_model_animator_node(animator->rootNode);
        animator->rootNode = NULL;
    }
}

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
// AnimatorNode* get_animator_node_for_tree_index(ModelAnimator* animator, s32 arg1) {
//     return get_animator_child_with_id(animator->rootNode, animator->unk_14[arg1]);
// }

AnimatorNode* get_animator_node_with_id(ModelAnimator* animator) {
    return get_animator_child_for_model(animator->rootNode);
}

void set_animator_tree_to_node_map(ModelAnimator* animator, s32* nodeIDs, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        animator->unk_15[i] = *nodeIDs;
        nodeIDs++;
    }
}

ModelAnimator* get_animator_by_index(s32 animModelID) {
    return (*gCurrentAnimMeshListPtr)[animModelID & ~0x800];
}

ModelAnimator* set_animator_render_callback(s32 animModelID, s32 callbackArg, s32 callbackFunc) {
    ModelAnimator* ret = (*gCurrentAnimMeshListPtr)[animModelID & ~0x800];

    ret->fpRenderCallback = callbackFunc;
    ret->renderCallbackArg = callbackArg;
    return ret;
}

void enable_anim_model_fog(void) {
    gAnimModelFogEnabled = TRUE;
}

void disable_anim_model_fog(void) {
    gAnimModelFogEnabled = FALSE;
}

void set_anim_model_fog_dist(s32 start, s32 end) {
    gAnimModelFogStart = start;
    gAnimModelFogEnd = end;
}

void set_anim_model_fog_color(s32 r, s32 g, s32 b, s32 a) {
    gAnimModelFogR = r;
    gAnimModelFogG = g;
    gAnimModelFogB = b;
    gAnimModelFogA = a;
}

s32 is_anim_model_fog_enabled(void) {
    return gAnimModelFogEnabled;
}

void get_anim_model_fog_distance(s32* start, s32* end) {
    *start = gAnimModelFogStart;
    *end = gAnimModelFogEnd;
}

void get_anim_model_fog_color(s32* r, s32* g, s32* b, s32* a) {
    *r = gAnimModelFogR;
    *g = gAnimModelFogG;
    *b = gAnimModelFogB;
    *a = gAnimModelFogA;
}

void set_animator_flags(s32 index, s32 bits) {
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~0x800];

    animator->flags |= bits;
}

void clear_animator_flags(s32 index, s32 bits) {
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~0x800];

    animator->flags &= ~bits;
}

void play_model_animation(s32 index, s32 animPos) {
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~0x800];

    if (animator->animationBuffer != NULL) {
        animPos = (animPos & 0xFFFFFF) + (s32)animator->animationBuffer; // array access?
    }
    animator->animReadPos = animPos;
    animator->savedReadPos = animPos;
    animator->treeIndexPos = 0;
    animator->nextUpdateTime = 1.0f;
}

INCLUDE_ASM(s32, "B4580", play_model_animation_starting_from);

INCLUDE_ASM(s32, "B4580", load_model_animator_node);

INCLUDE_ASM(s32, "B4580", load_model_animator_tree);

INCLUDE_ASM(s32, "B4580", load_mesh_animator_node);

INCLUDE_ASM(s32, "B4580", load_mesh_animator_tree);

INCLUDE_ASM(s32, "B4580", reload_mesh_animator_node);

INCLUDE_ASM(s32, "B4580", reload_mesh_animator_tree);

INCLUDE_ASM(s32, "B4580", step_mesh_animator);
