#include "common.h"

s32 D_8014C250[] = {0x0001003C, 0x00000000, 0x00000000, 0x00000000};

extern s32 gAnimModelFogEnabled;
extern s32 gAnimModelFogR;
extern s32 gAnimModelFogG;
extern s32 gAnimModelFogB;
extern s32 gAnimModelFogA;
extern s32 gAnimModelFogStart;
extern s32 gAnimModelFogEnd;
extern Matrix4f D_80153A68;
extern Matrix4f D_80153AA8;
extern Matrix4f D_80153AE8;
extern Matrix4f D_80153B28;

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

    for (i = 0; i < ARRAY_COUNT(root->children); i++) {
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

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
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

AnimatorNode* add_anim_node(ModelAnimator* animator, s32 parentNodeID, AnimatorNodeBlueprint* nodeBP) {
    AnimatorNode* ret;
    AnimatorNode* child;
    s32 nextUniqueID;
    s32 nullRootNode;
    s32 i;

    ret = heap_malloc(sizeof(*ret));
    ASSERT(ret != NULL);

    ret->flags = 0x10;
    ret->displayList = nodeBP->displayList;
    ret->basePos.x = nodeBP->unk_04.x;
    ret->basePos.y = nodeBP->unk_04.y;
    ret->basePos.z = nodeBP->unk_04.z;
    ret->pos.x = 0.0f;
    ret->pos.y = 0.0f;
    ret->pos.z = 0.0f;
    ret->rotation.x = nodeBP->rotation.x;
    ret->rotation.y = nodeBP->rotation.y;
    ret->rotation.z = nodeBP->rotation.z;
    ret->scale.x = 1.0f;
    ret->scale.y = 1.0f;
    ret->scale.z = 1.0f;
    ret->vertexStartOffset = -1;

    for (i = 0; i < ARRAY_COUNT(ret->children); i++) {
        ret->children[i] = NULL;
    }

    nextUniqueID = animator->nextUniqueID;
    nextUniqueID = nextUniqueID + 1;

    if (parentNodeID == 0) {
        s32 nullRootNode = animator->rootNode == NULL; // todo ???

        ret->uniqueIndex = nextUniqueID;

        if (nullRootNode) {
            animator->rootNode = ret;
        } else {
            child = get_animator_child_with_id(animator->rootNode, 1);
            ASSERT(child != NULL);

            for (i = 0; i < ARRAY_COUNT(child->children); i++) {
                if (child->children[i] == NULL) {
                    child->children[i] = ret;
                    break;
                }
            }

            ASSERT(i < ARRAY_COUNT(child->children));
        }
    } else {
        ret->uniqueIndex = nextUniqueID;
        child = get_animator_child_with_id(animator->rootNode, parentNodeID);
        ASSERT(child != NULL);

        for (i = 0; i < ARRAY_COUNT(child->children); i++) {
            if (child->children[i] == NULL) {
                child->children[i] = ret;
                break;
            }
        }

        ASSERT(i < ARRAY_COUNT(child->children));
    }

    animator->nextUniqueID = nextUniqueID;
    return ret;
}

INCLUDE_ASM(s32, "B4580", update_model_animator);

INCLUDE_ASM(s32, "B4580", func_8011EA54);

INCLUDE_ASM(s32, "B4580", step_model_animator);

INCLUDE_ASM(s32, "B4580", animator_update_model_transforms);

void animator_node_update_model_transform(ModelAnimator* animator, f32 (*flipMtx)[4], AnimatorNode* node, Matrix4s* rootTransform) {
    Matrix4f sp10;
    s32 i;

    guRotateRPYF(D_80153A68, clamp_angle(node->rotation.x), clamp_angle(node->rotation.y), clamp_angle(node->rotation.z));
    guScaleF(D_80153AA8, node->scale.x, node->scale.y, node->scale.z);
    guTranslateF(D_80153AE8, node->basePos.x + node->pos.x, node->basePos.y + node->pos.y, node->basePos.z + node->pos.z);
    guMtxCatF(D_80153AA8, D_80153A68, D_80153B28);
    guMtxCatF(D_80153B28, D_80153AE8, sp10);

    if (!(animator->flags & 0x20000)) {
        guMtxCatF(sp10, flipMtx, sp10);
    }

    copy_matrix(sp10, node->mtx[0]);

    if (node->flags & 0x1000) {
        Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(node->modelID));

        copy_matrix(sp10, model->transformMatrix);
        guMtxL2F(sp10, rootTransform);
        guMtxCatF(model->transformMatrix, sp10, model->transformMatrix);
        model->flags |= 0x1000;
    }

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            animator_node_update_model_transform(animator, sp10, node->children[i], rootTransform);
        }
    }
}

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
