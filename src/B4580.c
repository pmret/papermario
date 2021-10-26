#include "common.h"

s32 D_8014C250[] = {0x0001003C, 0x00000000, 0x00000000, 0x00000000};

extern s32 gAnimCount;

typedef struct DisplayListBufferHandle {
    /* 0x0 */ s32 mode;
    /* 0x4 */ Gfx* addr;
} DisplayListBufferHandle; // size = 0x8

typedef DisplayListBufferHandle AnimatedMeshVertexCopyList[0x60];

extern AnimatedMeshVertexCopyList D_801533C0;
extern AnimatedMeshVertexCopyList D_801536C0;
extern AnimatedMeshList D_801539C0;
extern AnimatedMeshList D_80153A00;
extern s32 gAnimModelFogEnabled;
extern s32 gAnimModelFogR;
extern s32 gAnimModelFogG;
extern s32 gAnimModelFogB;
extern s32 gAnimModelFogA;
extern s32 gAnimModelFogStart;
extern s32 gAnimModelFogEnd;
extern s32 D_80153A60;
extern Matrix4f gAnimRotMtx;
extern Matrix4f gAnimScaleMtx;
extern Matrix4f gAnimTranslateMtx;
extern Matrix4f gAnimRotScaleMtx;
extern StaticAnimatorNode** gAnimTreeRoot;

void appendGfx_animator(ModelAnimator* animator);

Vtx* animator_copy_vertices_to_buffer(ModelAnimator* animator, AnimatorNode* node, Vtx* buffer, s32 vtxCount,
                                      s32 overhead, s32 startIdx);
INCLUDE_ASM(s32, "B4580", animator_copy_vertices_to_buffer);
// Vtx* animator_copy_vertices_to_buffer(ModelAnimator* animator, AnimatorNode* node, Vtx* buffer, s32 vtxCount,
//                                       s32 overhead, s32 startIdx) {
//     DisplayListBufferHandle* handle;
//     Vtx* bufferMem;
//     Vtx* phi_v1;
//     s32 i;


//     for (i = 0; i < ARRAY_COUNT(D_801533C0); i++) {
//         handle = &D_801533C0[i];
//         if (handle->mode < 0) {
//             break;
//         }
//     }

//     ASSERT(i < ARRAY_COUNT(D_801533C0));

//     bufferMem = general_heap_malloc((vtxCount + overhead) * sizeof(*buffer));
//     handle->addr = bufferMem;

//     ASSERT(bufferMem != NULL);

//     handle->mode = 3;
//     phi_v1 = &node->fcData.vtxList[startIdx];
//     if (animator->vertexArray != NULL) {
//         buffer = ((s32) buffer & 0xFFFFFF) + animator->vertexArray;
//     }

//     for (i = 0; i < vtxCount; i++) {
//         *bufferMem = *phi_v1;
//         phi_v1->v.ob[0] = buffer->v.ob[0];
//         phi_v1->v.ob[1] = buffer->v.ob[1];
//         phi_v1->v.ob[2] = buffer->v.ob[2];
//         buffer++;
//         bufferMem++;
//         phi_v1++;
//     }
//     return handle->addr;
// }

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

AnimatorNode* get_animator_child_with_id(AnimatorNode* node, s32 id) {
    s32 i;

    if (node->uniqueIndex == id) {
        return node;
    }

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            AnimatorNode* child = get_animator_child_with_id(node->children[i], id);

            if (child != NULL) {
                return child;
            }

        }
    }

    return NULL;
}

AnimatorNode* get_animator_child_for_model(AnimatorNode* node, s32 id) {
    s32 i;

    if (node->fcData.modelID == id) {
        return node;
    }

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            AnimatorNode* child = get_animator_child_for_model(node->children[i], id);

            if (child != NULL) {
                return child;
            }

        }
    }

    return NULL;
}

void free_animator_nodes(AnimatorNode* root) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(root->children); i++) {
        if (root->children[i] != NULL) {
            free_animator_nodes(root->children[i]);
        }
    }
    heap_free(root);
}

void clear_animator_list(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentAnimMeshListPtr = D_801539C0;
        for (i = 0; i < ARRAY_COUNT(D_801533C0); i++) {
            D_801533C0[i].mode = -1;
        }

        for (i = 0; i < ARRAY_COUNT(D_801536C0); i++) {
            D_801536C0[i].mode = -1;
        }
    } else {
        gCurrentAnimMeshListPtr = D_80153A00;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentAnimMeshListPtr); i++) {
        (*gCurrentAnimMeshListPtr)[i] = NULL;
    }

    gAnimModelFogR = 10;
    gAnimModelFogG = 10;
    gAnimModelFogB = 10;
    gAnimModelFogA = 10;
    gAnimModelFogStart = 800;
    gAnimCount = 0;
    gAnimModelFogEnabled = 0;
    gAnimModelFogEnd = 1000;
}

void reset_animator_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentAnimMeshListPtr = D_801539C0;
    } else {
        gCurrentAnimMeshListPtr = D_80153A00;
    }

    gAnimModelFogR = 10;
    gAnimModelFogG = 10;
    gAnimModelFogB = 10;
    gAnimModelFogA = 10;
    gAnimModelFogStart = 800;
    gAnimCount = 0;
    gAnimModelFogEnabled = 0;
    gAnimModelFogEnd = 1000;
}

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

void delete_model_animator(ModelAnimator* animator) {
    s32 i;

    animator->nextUniqueID = 0;

    if (animator->rootNode != NULL) {
        delete_model_animator_node(animator->rootNode);
        animator->rootNode = NULL;

        for (i = 0; i < ARRAY_COUNT(*gCurrentAnimMeshListPtr); i++) {
            if ((*gCurrentAnimMeshListPtr)[i] == animator) {
                (*gCurrentAnimMeshListPtr)[i] = NULL;
                break;
            }
        }

        heap_free(animator);
        gAnimCount--;
    }
}

s32 create_model_animator(u32* animPos) {
    ModelAnimator* animator;
    s32 i, j;

    for (i = 0; i < ARRAY_COUNT(*gCurrentAnimMeshListPtr); i++) {
        if ((*gCurrentAnimMeshListPtr)[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(*gCurrentAnimMeshListPtr));

    (*gCurrentAnimMeshListPtr)[i] = animator = heap_malloc(sizeof(*animator));
    gAnimCount += 1;

    ASSERT(animator != NULL);

    animator->flags = 0x40 | 0x10 | 0x4 | 0x2 | 0x1;
    animator->renderMode = RENDER_MODE_ALPHATEST;
    animator->nextUpdateTime = 1.0f;
    animator->timeScale = 1.0f;
    animator->animReadPos = animPos;

    if (animPos == NULL) {
        animator->animReadPos = D_8014C250;
    }

    animator->savedReadPos = animPos;
    animator->animationBuffer = NULL;
    animator->vertexArray = NULL;
    animator->fpRenderCallback = NULL;
    animator->rootNode = NULL;
    animator->nextUniqueID = 0;

    for (j = 0; j < ARRAY_COUNT(animator->staticNodeIDs); j++) {
        animator->staticNodeIDs[j] = j + 1;
    }

    if (gGameStatusPtr->isBattle) {
        i |= 0x800;
    }
    return i;
}

s32 create_mesh_animator(s32 animPos, s8* animBuffer) {
    ModelAnimator* animator;
    s32 i, j;

    for (i = 0; i < ARRAY_COUNT(*gCurrentAnimMeshListPtr); i++) {
        if ((*gCurrentAnimMeshListPtr)[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(*gCurrentAnimMeshListPtr));

    (*gCurrentAnimMeshListPtr)[i] = animator = heap_malloc(sizeof(*animator));
    gAnimCount += 1;

    ASSERT(animator != NULL);

    animator->flags = 0x40 | 0x10 | 0x4 | 0x2 | 0x1;
    animator->renderMode = RENDER_MODE_ALPHATEST;
    animator->vertexArray = NULL;
    animator->fpRenderCallback = NULL;
    animator->rootNode = NULL;
    animator->nextUniqueID = 0;
    animator->animationBuffer = animBuffer;
    animator->nextUpdateTime = 1.0f;
    animator->timeScale = 1.0f;
    animPos = (animPos & 0xFFFFFF) + (s32)animator->animationBuffer;
    animator->animReadPos = animPos;
    animator->savedReadPos = animPos;

    for (j = 0; j < ARRAY_COUNT(animator->staticNodeIDs); j++) {
        animator->staticNodeIDs[j] = j + 1;
    }

    if (gGameStatusPtr->isBattle) {
        i |= 0x800;
    }
    return i;
}

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
    ret->basePos.x = nodeBP->basePos.x;
    ret->basePos.y = nodeBP->basePos.y;
    ret->basePos.z = nodeBP->basePos.z;
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

void animator_update_model_transforms(ModelAnimator* animator, Mtx* rootTransform) {
    Matrix4f flipMtx;

    if (animator->rootNode != NULL) {
        switch (animator->flags & 0x700) {
            case 0x100:
                animator_make_mirrorZ(flipMtx);
                break;
            case 0x200:
                animator_make_mirrorY(flipMtx);
                break;
            case 0x400:
                animator_make_mirrorX(flipMtx);
                break;
            default:
                animator_make_identity(flipMtx);
                break;
        }
        animator_node_update_model_transform(animator, flipMtx, animator->rootNode, rootTransform);
    }
}

void animator_node_update_model_transform(ModelAnimator* animator, f32 (*flipMtx)[4], AnimatorNode* node, Mtx* rootTransform) {
    Matrix4f sp10;
    s32 i;

    guRotateRPYF(gAnimRotMtx, clamp_angle(node->rotation.x), clamp_angle(node->rotation.y), clamp_angle(node->rotation.z));
    guScaleF(gAnimScaleMtx, node->scale.x, node->scale.y, node->scale.z);
    guTranslateF(gAnimTranslateMtx, node->basePos.x + node->pos.x, node->basePos.y + node->pos.y, node->basePos.z + node->pos.z);
    guMtxCatF(gAnimScaleMtx, gAnimRotMtx, gAnimRotScaleMtx);
    guMtxCatF(gAnimRotScaleMtx, gAnimTranslateMtx, sp10);

    if (!(animator->flags & 0x20000)) {
        guMtxCatF(sp10, flipMtx, sp10);
    }

    copy_matrix(sp10, node->mtx[0]);

    if (node->flags & 0x1000) {
        Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(node->fcData.modelID));

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

void render_animated_model(s32 animatorID, Mtx* rootTransform) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;

    if (!gGameStatusPtr->isBattle || animatorID & 0x800) {
        ModelAnimator* animator;

        animatorID &= ~0x800;
        animator = (*gCurrentAnimMeshListPtr)[animatorID];
        if (animator != NULL && animator->flags != 0 && !(animator->flags & 0x40) &&
            animator->flags & (1 << gCurrentCamID) && !(animator->flags & 0x80))
        {
            animator->mtx = *rootTransform;
            animator->vertexArray = NULL;
            rtPtr->appendGfxArg = animator;
            rtPtr->appendGfx = &appendGfx_animator;
            rtPtr->distance = 0;
            rtPtr->renderMode = animator->renderMode;
            queue_render_task(rtPtr);
        }
    }
}

void render_animated_model_with_vertices(s32 animatorID, Mtx* rootTransform, s32 vtxSegment, Vtx* vertexArray) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;

    if (!gGameStatusPtr->isBattle || animatorID & 0x800) {
        ModelAnimator* animator;

        animatorID &= ~0x800;
        animator = (*gCurrentAnimMeshListPtr)[animatorID];
        if (animator != NULL && animator->flags != 0 && !(animator->flags & 0x40) &&
            animator->flags & (1 << gCurrentCamID) && !(animator->flags & 0x80))
        {
            animator->mtx = *rootTransform;
            D_80153A60 = vtxSegment;
            animator->vertexArray = vertexArray;
            rtPtr->appendGfxArg = animator;
            rtPtr->appendGfx = &appendGfx_animator;
            rtPtr->distance = 0;
            rtPtr->renderMode = animator->renderMode;
            queue_render_task(rtPtr);
        }
    }
}

INCLUDE_ASM(s32, "B4580", appendGfx_animator);

INCLUDE_ASM(s32, "B4580", appendGfx_animator_node);

AnimatorNode* get_animator_node_for_tree_index(ModelAnimator* animator, s32 treeIndex);
INCLUDE_ASM(s32, "B4580", get_animator_node_for_tree_index);
// AnimatorNode* get_animator_node_for_tree_index(ModelAnimator* animator, s32 arg1) {
//     return get_animator_child_with_id(animator->rootNode, animator->unk_14[arg1]);
// }

AnimatorNode* get_animator_node_with_id(ModelAnimator* animator, s32 id) {
    return get_animator_child_for_model(animator->rootNode, id);
}

void set_animator_tree_to_node_map(ModelAnimator* animator, s32* nodeIDs, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        animator->staticNodeIDs[i] = *nodeIDs;
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
        animPos = (animPos & 0xFFFFFF) + (s32)animator->animationBuffer; // TODO: array access?
    }
    animator->animReadPos = animPos;
    animator->savedReadPos = animPos;
    animator->treeIndexPos = 0;
    animator->nextUpdateTime = 1.0f;
}

void play_model_animation_starting_from(s32 index, s32 animPos, s32 framesToSkip) {
    s32 indexMasked = index & ~0x800;
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[indexMasked];
    s32 i;

    if (animator->animationBuffer != NULL) {
        animPos = (animPos & 0xFFFFFF) + (s32)animator->animationBuffer; // TODO: array access?
    }

    animator->animReadPos = animPos;
    animator->savedReadPos = animPos;
    animator->treeIndexPos = 0;
    animator->nextUpdateTime = 1.0f;

    for (i = 0; i < framesToSkip; i++) {
        update_model_animator(indexMasked);
    }
}

void load_model_animator_node(StaticAnimatorNode* node, ModelAnimator* animator, s32 parentNodeID, s32* treeIndexToNodeIDs) {
    AnimatorNodeBlueprint bp;
    AnimatorNodeBlueprint* bpPtr = &bp;
    AnimatorNode* newNode;
    s32 i;

    if (node != NULL) {
        bpPtr->displayList = node->displayList;
        bpPtr->basePos.x = 0.0f;
        bpPtr->basePos.y = 0.0f;
        bpPtr->basePos.z = 0.0f;
        bpPtr->rotation.x = ((f32) node->rot.x * 180.0) / 32767.0;
        bpPtr->rotation.y = ((f32) node->rot.y * 180.0) / 32767.0;
        bpPtr->rotation.z = ((f32) node->rot.z * 180.0) / 32767.0;

        newNode = add_anim_node(animator, parentNodeID, bpPtr);

        if (node->modelID != 0) {
            newNode->fcData.modelID = node->modelID - 1;
            newNode->flags |= 0x1000;
        }

        i = 0;
        while (gAnimTreeRoot[i] != node) {
            i++;
        }

        treeIndexToNodeIDs[i] = newNode->uniqueIndex;

        if (node->child != NULL) {
            load_model_animator_node(node->child, animator, newNode->uniqueIndex, treeIndexToNodeIDs);
        }

        if (node->sibling != NULL) {
            load_model_animator_node(node->sibling, animator, parentNodeID, treeIndexToNodeIDs);
        }
    }
}

void load_model_animator_tree(s32 index, StaticAnimatorNode** tree) {
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~0x800];
    s32 nodeIDs[ARRAY_COUNT(animator->staticNodeIDs)];

    if (animator != NULL && animator->flags != 0) {
        gAnimTreeRoot = tree;
        load_model_animator_node(*tree, animator, 0, nodeIDs);
        set_animator_tree_to_node_map(animator, &nodeIDs, ARRAY_COUNT(animator->staticNodeIDs));
    }
}

void load_mesh_animator_node(StaticAnimatorNode* node, ModelAnimator* animator, s32 parentNodeID, s32* treeIndexToNodeIDs) {
    if (node != NULL) {
        if (node->child != NULL && parentNodeID == 0) {
            load_mesh_animator_node(node->child, animator, 0, treeIndexToNodeIDs);
        } else {
            do {
                animator->staticNodes[parentNodeID] = node;
                node = node->sibling;
                parentNodeID++;
            } while (node != NULL);
        }
    }
}

void load_mesh_animator_tree(s32 index, StaticAnimatorNode** tree) {
    s32 indexMasked = index & ~0x800;
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[indexMasked];
    s32 nodeIDs[ARRAY_COUNT(animator->staticNodeIDs)];
    s32 i;

    if (animator != NULL && animator->flags != 0) {
        if ((*tree)->vertexStartOffset == 0) {
            load_model_animator_tree(indexMasked, tree);
            return;
        }

        gAnimTreeRoot = tree;
        animator->staticRoot = tree;
        animator->treeIndexPos = 0;
        animator->savedTreePos = 0;

        for (i = 0; i < ARRAY_COUNT(animator->staticNodes); i++) {
            animator->staticNodes[i] = NULL;
        }

        load_mesh_animator_node(*gAnimTreeRoot, animator, 0, nodeIDs);
        animator->flags |= 0x8000;
    }
}

void reload_mesh_animator_node(StaticAnimatorNode* node, ModelAnimator* animator, s32 parentNodeID, s32* treeIndexToNodeIDs) {
    AnimatorNodeBlueprint bp;
    AnimatorNodeBlueprint* bpPtr = &bp;
    AnimatorNode* newNode;
    s32 i;

    if (node != NULL) {
        bpPtr->displayList = node->displayList;
        bpPtr->basePos.x = 0.0f;
        bpPtr->basePos.y = 0.0f;
        bpPtr->basePos.z = 0.0f;
        bpPtr->rotation.x = ((f32) node->rot.x * 180.0) / 32767.0;
        bpPtr->rotation.y = ((f32) node->rot.y * 180.0) / 32767.0;
        bpPtr->rotation.z = ((f32) node->rot.z * 180.0) / 32767.0;

        newNode = add_anim_node(animator, parentNodeID, bpPtr);
        newNode->vertexStartOffset = node->vertexStartOffset;
        newNode->fcData.modelID = node->vertexList; // TODO see note in struct def: "also ptr to vtx list? union?"

        i = 0;
        while (gAnimTreeRoot[i] != node) {
            i++;
        }

        treeIndexToNodeIDs[i] = newNode->uniqueIndex;

        if (node->child != NULL) {
            reload_mesh_animator_node(node->child, animator, newNode->uniqueIndex, treeIndexToNodeIDs);
        }
    }
}

void reload_mesh_animator_tree(ModelAnimator* animator) {
    s32 nodeIDs[ARRAY_COUNT(animator->staticNodeIDs)];
    s32 i;

    delete_model_animator_nodes(animator);
    gAnimTreeRoot = animator->staticRoot;

    for (i = 0; i < ARRAY_COUNT(animator->staticNodes); i++) {
        nodeIDs[i] = 0;
    }

    reload_mesh_animator_node(animator->staticNodes[animator->treeIndexPos], animator, 0, nodeIDs);
    nodeIDs[0] = -1;
    set_animator_tree_to_node_map(animator, nodeIDs, ARRAY_COUNT(nodeIDs));
}

INCLUDE_ASM(s32, "B4580", step_mesh_animator);
