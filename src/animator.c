#include "model.h"
#include "animation_script.h"
#include "model.h"

typedef struct DisplayListBufferHandle {
    /* 0x0 */ s32 ttl;
    /* 0x4 */ void* addr;
} DisplayListBufferHandle; // size = 0x8

typedef DisplayListBufferHandle AnimatedMeshVertexCopyList[0x60];

s32 gAnimCount;

BSS AnimatedMeshVertexCopyList D_801533C0;
BSS AnimatedMeshVertexCopyList D_801536C0;
BSS AnimatedMeshList D_801539C0;
BSS AnimatedMeshList D_80153A00;
BSS AnimatedMeshList* gCurrentAnimMeshListPtr;
BSS s32 gAnimModelFogEnabled;
BSS s32 gAnimModelFogR;
BSS s32 gAnimModelFogG;
BSS s32 gAnimModelFogB;
BSS s32 gAnimModelFogA;
BSS s32 gAnimModelFogStart;
BSS s32 gAnimModelFogEnd;
BSS s32 gAnimVtxSegment;
BSS s32 D_80153A64;
BSS Matrix4f gAnimRotMtx;
BSS Matrix4f gAnimScaleMtx;
BSS Matrix4f gAnimTranslateMtx;
BSS Matrix4f gAnimRotScaleMtx;
BSS StaticAnimatorNode** gAnimTreeRoot;

extern Gfx Gfx_RM1_SURFACE_OPA[];
extern Gfx Gfx_RM1_DECAL_OPA[];
extern Gfx Gfx_RM1_INTERSECTING_OPA[];
extern Gfx Gfx_RM1_ALPHATEST[];
extern Gfx Gfx_RM1_SURFACE_XLU[];
extern Gfx Gfx_RM1_DECAL_XLU[];
extern Gfx Gfx_RM1_INTERSECTING_XLU[];
extern Gfx Gfx_RM3_SURFACE_OPA[];
extern Gfx Gfx_RM3_DECAL_OPA[];
extern Gfx Gfx_RM3_INTERSECTING_OPA[];
extern Gfx Gfx_RM3_ALPHATEST[];
extern Gfx Gfx_RM3_SURFACE_XLU[];
extern Gfx Gfx_RM3_DECAL_XLU[];
extern Gfx Gfx_RM3_INTERSECTING_XLU[];

AnimScript gAnimScriptDefault = {
    as_Wait(60)
    as_End
};

void appendGfx_animator_node(ModelAnimator*, AnimatorNode*, Matrix4f);

// copy Vtx array from node->fcData.vtxList, but overwrite xyz coordinates with ones from buffer
// if animator has own vertexArray, buffer is offset within it
Vtx* animator_copy_vertices_to_buffer(ModelAnimator* animator, AnimatorNode* node, Vec3s* buffer, s32 vtxCount,
                                      s32 overhead, s32 startIdx) {
    DisplayListBufferHandle* handle;
    Vtx* bufferMem;
    Vtx* nodeVtxList;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_801533C0); i++) {
        handle = &D_801533C0[i];
        if (handle->ttl < 0) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(D_801533C0));

    bufferMem = general_heap_malloc((vtxCount + overhead) * sizeof(*bufferMem));
    handle->addr = bufferMem;

    ASSERT(bufferMem != NULL);

    handle->ttl = 3;
    nodeVtxList = &node->fcData.vtxList[startIdx];

    if (animator->baseAddr != NULL) {
        i = ((s32)buffer & 0xFFFFFF); // needed to match
        buffer = (Vec3s*)(i + (s32)animator->baseAddr);
    }

    for (i = 0; i < vtxCount; i++) {
        *bufferMem = *nodeVtxList;
        bufferMem->v.ob[0] = buffer->x;
        bufferMem->v.ob[1] = buffer->y;
        bufferMem->v.ob[2] = buffer->z;
        bufferMem++;
        buffer++;
        nodeVtxList++;
    }
    return handle->addr;
}

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

AnimatorNode* get_animator_child_for_model(AnimatorNode* node, s32 modelId) {
    s32 i;

    if (node->fcData.modelID == modelId) {
        return node;
    }

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            AnimatorNode* child = get_animator_child_for_model(node->children[i], modelId);

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
        gCurrentAnimMeshListPtr = &D_801539C0;
        for (i = 0; i < ARRAY_COUNT(D_801533C0); i++) {
            D_801533C0[i].ttl = -1;
        }

        for (i = 0; i < ARRAY_COUNT(D_801536C0); i++) {
            D_801536C0[i].ttl = -1;
        }
    } else {
        gCurrentAnimMeshListPtr = &D_80153A00;
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
        gCurrentAnimMeshListPtr = &D_801539C0;
    } else {
        gCurrentAnimMeshListPtr = &D_80153A00;
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

s32 create_model_animator(s16* animPos) {
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

    animator->flags = MODEL_ANIMATOR_FLAG_UPDATE_PENDING | MODEL_ANIMATOR_FLAG_ENABLED | MODEL_ANIMATOR_FLAG_CAM_2 | MODEL_ANIMATOR_FLAG_CAM_1 | MODEL_ANIMATOR_FLAG_CAM_0;
    animator->renderMode = RENDER_MODE_ALPHATEST;
    animator->nextUpdateTime = 1.0f;
    animator->timeScale = 1.0f;
    animator->animReadPos = animPos;

    if (animPos == NULL) {
        animator->animReadPos = gAnimScriptDefault;
    }

    animator->savedReadPos = animPos;
    animator->animationBuffer = NULL;
    animator->baseAddr = NULL;
    animator->fpRenderCallback = NULL;
    animator->rootNode = NULL;
    animator->nextUniqueID = 0;

    for (j = 0; j < ARRAY_COUNT(animator->staticNodeIDs); j++) {
        animator->staticNodeIDs[j] = j + 1;
    }

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_ID_BIT;
    }
    return i;
}

s32 create_mesh_animator(s16* animPos, s16* animBuffer) {
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

    animator->flags = MODEL_ANIMATOR_FLAG_UPDATE_PENDING | MODEL_ANIMATOR_FLAG_ENABLED | MODEL_ANIMATOR_FLAG_CAM_2 | MODEL_ANIMATOR_FLAG_CAM_1 | MODEL_ANIMATOR_FLAG_CAM_0;
    animator->renderMode = RENDER_MODE_ALPHATEST;
    animator->baseAddr = NULL;
    animator->fpRenderCallback = NULL;
    animator->rootNode = NULL;
    animator->nextUniqueID = 0;
    animator->animationBuffer = animBuffer;
    animator->nextUpdateTime = 1.0f;
    animator->timeScale = 1.0f;
    animPos = (s16*)(((s32)animPos & 0xFFFFFF) + (s32)animator->animationBuffer);
    animator->animReadPos = animPos;
    animator->savedReadPos = animPos;

    for (j = 0; j < ARRAY_COUNT(animator->staticNodeIDs); j++) {
        animator->staticNodeIDs[j] = j + 1;
    }

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_ID_BIT;
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

    ret->flags = MODEL_ANIMATOR_FLAG_ENABLED;
    ret->displayList = nodeBP->displayList;
    ret->basePos.x = nodeBP->basePos.x;
    ret->basePos.y = nodeBP->basePos.y;
    ret->basePos.z = nodeBP->basePos.z;
    ret->pos.x = 0.0f;
    ret->pos.y = 0.0f;
    ret->pos.z = 0.0f;
    ret->rot.x = nodeBP->rot.x;
    ret->rot.y = nodeBP->rot.y;
    ret->rot.z = nodeBP->rot.z;
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

void update_model_animator(s32 animatorID) {
    ModelAnimator* animator;
    s32 temp;
    s32 i;

    if (gGameStatusPtr->isBattle && !(animatorID & BATTLE_ID_BIT)) {
        return;
    }

    animatorID &= ~BATTLE_ID_BIT;
    animator = (*gCurrentAnimMeshListPtr)[animatorID];

    if (animator == NULL || animator->flags == 0) {
        return;
    }

    if (animator->flags & MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION) {
        return;
    }
    
    animator->flags &= ~MODEL_ANIMATOR_FLAG_UPDATE_PENDING;
    animator->nextUpdateTime -= animator->timeScale;

    temp = 0;
    if (animator->nextUpdateTime <= 0.0f) {
        if (!(animator->flags & MODEL_ANIMATOR_FLAG_MESH)) {
            do {
                temp = step_model_animator(animator);
            } while (temp > 0);
        } else {
            animator->nextUpdateTime = 1.0f;
            reload_mesh_animator_tree(animator);
            do {
                temp = step_mesh_animator(animator);
            } while (temp > 0);
        }
    }
    if (temp == -1) {
        return;
    }

    animator_update_model_transforms(animator, NULL);

    for (i = 0; i < ARRAY_COUNT(D_801533C0); i++) {
        if (D_801533C0[i].ttl >= 0) {
            D_801533C0[i].ttl--;
            if (D_801533C0[i].ttl == 0) {
                D_801533C0[i].ttl = -1;
                general_heap_free(D_801533C0[i].addr);
            }
        }
    }

    for (i = 0; i < ARRAY_COUNT(D_801536C0); i++) {
        if (D_801536C0[i].ttl >= 0) {
            D_801536C0[i].ttl--;
            if (D_801536C0[i].ttl == 0) {
                D_801536C0[i].ttl = -1;
                general_heap_free(D_801536C0[i].addr);
            }
        }
    }
}

void update_model_animator_with_transform(s32 animatorID, Mtx* mtx) {
    ModelAnimator* animator;
    s32 temp;
    s32 i;

    if (gGameStatusPtr->isBattle && !(animatorID & BATTLE_ID_BIT)) {
        return;
    }

    animatorID &= ~BATTLE_ID_BIT;
    animator = (*gCurrentAnimMeshListPtr)[animatorID];

    if (animator == NULL || animator->flags == 0) {
        return;
    }

    if (animator->flags & MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION) {
        return;
    }

    animator->flags &= ~MODEL_ANIMATOR_FLAG_UPDATE_PENDING;
    animator->nextUpdateTime -= animator->timeScale;

    temp = 0;
    if (animator->nextUpdateTime <= 0.0f) {
        if (!(animator->flags & MODEL_ANIMATOR_FLAG_MESH)) {
            do {
                temp = step_model_animator(animator);
            } while (temp > 0);
        } else {
            animator->nextUpdateTime = 1.0f;
            reload_mesh_animator_tree(animator);
            do {
                temp = step_mesh_animator(animator);
            } while (temp > 0);
        }
    }
    if (temp == -1) {
        return;
    }

    animator_update_model_transforms(animator, mtx);

    for (i = 0; i < ARRAY_COUNT(D_801533C0); i++) {
        if (D_801533C0[i].ttl >= 0) {
            D_801533C0[i].ttl--;
            if (D_801533C0[i].ttl == 0) {
                D_801533C0[i].ttl = -1;
                general_heap_free(D_801533C0[i].addr);
            }
        }
    }

    for (i = 0; i < ARRAY_COUNT(D_801536C0); i++) {
        if (D_801536C0[i].ttl >= 0) {
            D_801536C0[i].ttl--;
            if (D_801536C0[i].ttl == 0) {
                D_801536C0[i].ttl = -1;
                general_heap_free(D_801536C0[i].addr);
            }
        }
    }
}

s32 step_model_animator(ModelAnimator* animator) {
    s16* args = animator->animReadPos;
    AnimatorNode* node;
    f32 x, y, z;
    s32 flags;
    s32 nodeId;

    switch (*args++) {
        case AS_END:
            return -1;
        case AS_SET_RENDER_MODE:
            animator->renderMode = *args++;
            animator->animReadPos = args;
            return 1;
        case AS_WAIT:
            animator->nextUpdateTime = *args++;
            animator->animReadPos = args;
            break;
        case AS_END_LOOP:
            animator->animReadPos = animator->savedReadPos;
            return 1;
        case AS_LOOP:
            animator->animReadPos = animator->savedReadPos = args;
            return 1;
        case AS_SET_FLAGS:
            flags = *args++;
            animator->animReadPos = args;
            animator->flags |= flags & 0xFFFF;
            return 1;
        case AS_SET_NODE_FLAGS:
            node = get_animator_child_with_id(animator->rootNode, animator->staticNodeIDs[*args++ - 1]);
            flags = *args++;
            node->flags |= flags;
            animator->animReadPos = args;
            return 1;
        case AS_CLEAR_NODE_FLAGS:
            node = get_animator_child_with_id(animator->rootNode, animator->staticNodeIDs[*args++ - 1]);
            flags = *args++;
            node->flags &= ~flags;
            animator->animReadPos = args;
            return 1;
        case AS_OP_19:
            animator->flags |= MODEL_ANIMATOR_FLAG_NO_FLIP;
            animator->animReadPos = args;
            return 1;
        case AS_SET_ROTATION:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;

            node = get_animator_child_with_id(animator->rootNode, nodeId);
            ASSERT(node != NULL);
            node->rot.x = x;
            node->rot.y = y;
            node->rot.z = z;
            return 1;
        case AS_ADD_ROTATION:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;

            node = get_animator_child_with_id(animator->rootNode, nodeId);
            ASSERT(node != NULL);
            node->rot.x += x;
            node->rot.y += y;
            node->rot.z += z;
            return 1;
        case AS_SET_POS:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = *args++;
            y = *args++;
            z = *args++;
            animator->animReadPos = args;
            node = get_animator_child_with_id(animator->rootNode, nodeId);
            ASSERT(node != NULL);
            node->pos.x = x;
            node->pos.y = y;
            node->pos.z = z;
            return 1;
        case AS_SET_SCALE:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;

            node = get_animator_child_with_id(animator->rootNode, nodeId);
            ASSERT(node != NULL);
            node->scale.x = x;
            node->scale.y = y;
            node->scale.z = z;
            return 1;
    }
    return 0;
}

void animator_update_model_transforms(ModelAnimator* animator, Mtx* rootTransform) {
    Matrix4f flipMtx;

    if (animator->rootNode != NULL) {
        switch (animator->flags & (MODEL_ANIMATOR_FLAG_FLIP_Z | MODEL_ANIMATOR_FLAG_FLIP_Y | MODEL_ANIMATOR_FLAG_FLIP_X)) {
            case MODEL_ANIMATOR_FLAG_FLIP_Z:
                animator_make_mirrorZ(flipMtx);
                break;
            case MODEL_ANIMATOR_FLAG_FLIP_Y:
                animator_make_mirrorY(flipMtx);
                break;
            case MODEL_ANIMATOR_FLAG_FLIP_X:
                animator_make_mirrorX(flipMtx);
                break;
            default:
                animator_make_identity(flipMtx);
                break;
        }
        animator_node_update_model_transform(animator, flipMtx, animator->rootNode, rootTransform);
    }
}

void animator_node_update_model_transform(ModelAnimator* animator, f32 (*flipMtx)[4], AnimatorNode* node,
                                          Mtx* rootTransform) {
    Matrix4f sp10;
    s32 i;

    guRotateRPYF(gAnimRotMtx, clamp_angle(node->rot.x), clamp_angle(node->rot.y), clamp_angle(node->rot.z));
    guScaleF(gAnimScaleMtx, node->scale.x, node->scale.y, node->scale.z);
    guTranslateF(gAnimTranslateMtx, node->basePos.x + node->pos.x, node->basePos.y + node->pos.y, node->basePos.z + node->pos.z);
    guMtxCatF(gAnimScaleMtx, gAnimRotMtx, gAnimRotScaleMtx);
    guMtxCatF(gAnimRotScaleMtx, gAnimTranslateMtx, sp10);

    if (!(animator->flags & MODEL_ANIMATOR_FLAG_NO_FLIP)) {
        guMtxCatF(sp10, flipMtx, sp10);
    }

    copy_matrix(sp10, node->mtx);

    if (node->flags & MODEL_ANIMATOR_FLAG_HAS_MODEL) {
        Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(node->fcData.modelID));

        copy_matrix(sp10, model->userTransformMtx);
        guMtxL2F(sp10, rootTransform);
        guMtxCatF(model->userTransformMtx, sp10, model->userTransformMtx);
        model->flags |= MODEL_FLAG_MATRIX_DIRTY;
    }

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            animator_node_update_model_transform(animator, sp10, node->children[i], rootTransform);
        }
    }
}

void render_animated_model(s32 animatorID, Mtx* rootTransform) {
    ModelAnimator* animator;
    RenderTask rt;
    RenderTask* rtPtr = &rt;

    if (gGameStatusPtr->isBattle && !(animatorID & BATTLE_ID_BIT)) {
        return;
    }
    
    animatorID &= ~BATTLE_ID_BIT;
    animator = (*gCurrentAnimMeshListPtr)[animatorID];

    if (animator == NULL || animator->flags == 0) {
        return;
    }

    if (!(animator->flags & MODEL_ANIMATOR_FLAG_UPDATE_PENDING)
        && animator->flags & (1 << gCurrentCamID)
        && !(animator->flags & MODEL_ANIMATOR_FLAG_HIDDEN)
    ) {
        animator->mtx = *rootTransform;
        animator->baseAddr = NULL;
        rtPtr->appendGfxArg = animator;
        rtPtr->appendGfx = (void (*)(void*))appendGfx_animator;
        rtPtr->dist = 0;
        rtPtr->renderMode = animator->renderMode;
        queue_render_task(rtPtr);
    }
}

void render_animated_model_with_vertices(s32 animatorID, Mtx* rootTransform, s32 segment, void* baseAddr) {
    ModelAnimator* animator;
    RenderTask rt;
    RenderTask* rtPtr = &rt;

    if (gGameStatusPtr->isBattle && !(animatorID & BATTLE_ID_BIT)) {
        return;
    }

    animatorID &= ~BATTLE_ID_BIT;
    animator = (*gCurrentAnimMeshListPtr)[animatorID];

    if (animator == NULL || animator->flags == 0) {
        return;
    }

    if (!(animator->flags & MODEL_ANIMATOR_FLAG_UPDATE_PENDING)
        && animator->flags & (1 << gCurrentCamID)
        && !(animator->flags & MODEL_ANIMATOR_FLAG_HIDDEN)
    ) {
        animator->mtx = *rootTransform;
        gAnimVtxSegment = segment;
        animator->baseAddr = baseAddr;
        rtPtr->appendGfxArg = animator;
        rtPtr->appendGfx = (void (*)(void*))appendGfx_animator;
        rtPtr->dist = 0;
        rtPtr->renderMode = animator->renderMode;
        queue_render_task(rtPtr);
    }
}

void appendGfx_animator(ModelAnimator* animator) {
    Matrix4f sp10;

    if (animator->baseAddr != NULL) {
        gSPSegment(gMainGfxPos++, gAnimVtxSegment, VIRTUAL_TO_PHYSICAL(animator->baseAddr));
    }

    gDisplayContext->matrixStack[gMatrixListPos] = animator->mtx;
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    //TODO find better match
    switch (gAnimModelFogEnabled != 0) {
        case FALSE:
            switch (animator->renderMode) {
                case RENDER_MODE_SURFACE_OPA:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_OPA);
                    break;
                case RENDER_MODE_DECAL_OPA:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM1_DECAL_OPA);
                    break;
                case RENDER_MODE_INTERSECTING_OPA:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM1_INTERSECTING_OPA);
                    break;
                case RENDER_MODE_ALPHATEST:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM1_ALPHATEST);
                    break;
                case RENDER_MODE_SURFACE_XLU_LAYER1:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_XLU);
                    break;
                case RENDER_MODE_DECAL_XLU:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM1_DECAL_XLU);
                    break;
                case RENDER_MODE_INTERSECTING_XLU:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM1_INTERSECTING_XLU);
                    break;
            }
            break;
        case TRUE:
            switch (animator->renderMode) {
                case RENDER_MODE_SURFACE_OPA:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM3_SURFACE_OPA);
                    break;
                case RENDER_MODE_DECAL_OPA:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM3_DECAL_OPA);
                    break;
                case RENDER_MODE_INTERSECTING_OPA:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM3_INTERSECTING_OPA);
                    break;
                case RENDER_MODE_ALPHATEST:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM3_ALPHATEST);
                    break;
                case RENDER_MODE_SURFACE_XLU_LAYER1:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM3_SURFACE_XLU);
                    break;
                case RENDER_MODE_DECAL_XLU:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM3_DECAL_XLU);
                    break;
                case RENDER_MODE_INTERSECTING_XLU:
                    gSPDisplayList(gMainGfxPos++, Gfx_RM3_INTERSECTING_XLU);
                    break;
            }

            gDPSetFogColor(gMainGfxPos++, gAnimModelFogR, gAnimModelFogG, gAnimModelFogB, gAnimModelFogA);
            gSPFogPosition(gMainGfxPos++, gAnimModelFogStart, gAnimModelFogEnd);
            break;
    }

    guMtxL2F(sp10, &animator->mtx);
    appendGfx_animator_node(animator, animator->rootNode, sp10);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void appendGfx_animator_node(ModelAnimator* animator, AnimatorNode* node, Matrix4f mtx) {
    DisplayListBufferHandle* bufferHandle;
    u32 w0,w1;
    s32 cmd;
    s32 i;

    if (node->flags & MODEL_ANIMATOR_FLAG_HIDDEN) {
        for (i = 0; i < ARRAY_COUNT(node->children); i++) {
            if (node->children[i] != NULL) {
                guMtxCatF(node->mtx, mtx, node->mtx);
                appendGfx_animator_node(animator, node->children[i], node->mtx);
            }
        }
        return;
    }

    guMtxCatF(node->mtx, mtx, node->mtx);
    guMtxF2L(node->mtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);

    gSPTexture(gMainGfxPos++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
    if (animator->flags & MODEL_ANIMATOR_FLAG_CULL_BACK) {
        gSPSetGeometryMode(gMainGfxPos++, G_CULL_BACK);
    }
    if (!gAnimModelFogEnabled) {
        gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    } else {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_42, PM_CC2_MULTIPLY_SHADE);
    }
    gDPPipeSync(gMainGfxPos++);

    if (animator->fpRenderCallback != NULL) animator->fpRenderCallback(animator->renderCallbackArg);

    gDPPipeSync(gMainGfxPos++);

    if (node->displayList != NULL) {
        if (node->vertexStartOffset < 0) {
            gSPDisplayList(gMainGfxPos++, node->displayList);
        } else {
            Gfx* gfxPos;
            s32 vtxIdx, dlIdx;
            s32 j = 0;
            s32 k;

            if ((node->displayList[0].words.w0 >> 0x18) != G_ENDDL) {
                Gfx* gfxPtr = node->displayList;
                s32 endDL = G_ENDDL;

                for(;; j++) {
                    w0 = gfxPtr->words.w0;
                    gfxPtr++;
                    cmd = w0 >> 0x18;
                    if (cmd == endDL) {
                        break;
                    }
                }
            }
            j++;
            for (k = 0; k < ARRAY_COUNT(D_801536C0); k++) {
                bufferHandle = &D_801536C0[k];
                if (bufferHandle->ttl < 0) {
                    break;
                }
            }
            ASSERT(k < ARRAY_COUNT(D_801536C0));

            bufferHandle->addr = gfxPos = general_heap_malloc(j * sizeof(Gfx));
            ASSERT(gfxPos != NULL);
            bufferHandle->ttl = 3;

            vtxIdx = 0;
            dlIdx = 0;

            do {
                w0 = ((s32*)node->displayList)[dlIdx++];
                w1 = ((s32*)node->displayList)[dlIdx++];
                cmd = w0 >> 0x18;
                if (cmd == G_ENDDL) {
                    break;
                }
                if (cmd == G_VTX) {
                    s32 startIdx = _SHIFTR(w0,1,7);
                    s32 vtxCount = _SHIFTR(w0,12,8);
                    Vtx* newBuffer;

                    startIdx -= vtxCount;

                    if (node->fcData.vtxList == NULL) {
                        newBuffer = &((Vtx*)w1)[node->vertexStartOffset + vtxIdx];
                        gSPVertex(gfxPos++, newBuffer, vtxCount, startIdx);
                    } else {
                        newBuffer = animator_copy_vertices_to_buffer(
                            animator,
                            node,
                            (Vec3s*)(w1 + (node->vertexStartOffset + vtxIdx) * 0x6),
                            vtxCount,
                            startIdx,
                            vtxIdx
                        );
                        gSPVertex(gfxPos++, newBuffer, vtxCount, startIdx);
                    }
                    vtxIdx += vtxCount;
                } else {
                    Gfx* temp[1] = {gfxPos++}; // required to match
                    temp[0]->words.w0 = w0;
                    temp[0]->words.w1 = w1;
                }
            } while (TRUE);

            gSPEndDisplayList(gfxPos++);
            gSPDisplayList(gMainGfxPos++, bufferHandle->addr);
        }
    }
    gDPPipeSync(gMainGfxPos++);

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            appendGfx_animator_node(animator, node->children[i], node->mtx);
        }
    }
}

AnimatorNode* get_animator_node_for_tree_index(ModelAnimator* animator, s32 arg1) {
    return get_animator_child_with_id(animator->rootNode, animator->staticNodeIDs[arg1 - 1]);
}

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
    return (*gCurrentAnimMeshListPtr)[animModelID & ~BATTLE_ID_BIT];
}

ModelAnimator* set_animator_render_callback(s32 animModelID, void* callbackArg, void (*callbackFunc)(void*)) {
    ModelAnimator* ret = (*gCurrentAnimMeshListPtr)[animModelID & ~BATTLE_ID_BIT];

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
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~BATTLE_ID_BIT];

    animator->flags |= bits;
}

void clear_animator_flags(s32 index, s32 bits) {
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~BATTLE_ID_BIT];

    animator->flags &= ~bits;
}

void play_model_animation(s32 index, s16* animPos) {
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~BATTLE_ID_BIT];

    if (animator->animationBuffer != NULL) {
        animPos = (s16*) (((s32)animPos & 0xFFFFFF) + (s32)animator->animationBuffer); // TODO: array access? / cleanup
    }
    animator->animReadPos = animPos;
    animator->savedReadPos = animPos;
    animator->treeIndexPos = 0;
    animator->nextUpdateTime = 1.0f;
}

void play_model_animation_starting_from(s32 index, s16* animPos, s32 framesToSkip) {
    s32 indexMasked = index & ~BATTLE_ID_BIT;
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[indexMasked];
    s32 i;

    if (animator->animationBuffer != NULL) {
        animPos = (s16*) (((s32)animPos & 0xFFFFFF) + (s32)animator->animationBuffer); // TODO: array access? / cleanup
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
        bpPtr->rot.x = ((f32) node->rot.x * 180.0) / 32767.0;
        bpPtr->rot.y = ((f32) node->rot.y * 180.0) / 32767.0;
        bpPtr->rot.z = ((f32) node->rot.z * 180.0) / 32767.0;

        newNode = add_anim_node(animator, parentNodeID, bpPtr);

        if (node->modelID != 0) {
            newNode->fcData.modelID = node->modelID - 1;
            newNode->flags |= MODEL_ANIMATOR_FLAG_HAS_MODEL;
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
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~BATTLE_ID_BIT];
    s32 nodeIDs[ARRAY_COUNT(animator->staticNodeIDs)];

    if (animator == NULL || animator->flags == 0) {
        return;
    }
    
    gAnimTreeRoot = tree;
    load_model_animator_node(*tree, animator, 0, nodeIDs);
    set_animator_tree_to_node_map(animator, nodeIDs, ARRAY_COUNT(animator->staticNodeIDs));
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
    s32 indexMasked = index & ~BATTLE_ID_BIT;
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[indexMasked];
    s32 nodeIDs[ARRAY_COUNT(animator->staticNodeIDs)];
    s32 i;

    if (animator == NULL || animator->flags == 0) {
        return;
    }

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
    animator->flags |= MODEL_ANIMATOR_FLAG_MESH;
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
        bpPtr->rot.x = ((f32) node->rot.x * 180.0) / 32767.0;
        bpPtr->rot.y = ((f32) node->rot.y * 180.0) / 32767.0;
        bpPtr->rot.z = ((f32) node->rot.z * 180.0) / 32767.0;

        newNode = add_anim_node(animator, parentNodeID, bpPtr);
        newNode->vertexStartOffset = node->vertexStartOffset;
        newNode->fcData.vtxList = node->vtxList;

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

s32 step_mesh_animator(ModelAnimator* animator) {
    s16* args = animator->animReadPos;
    s16* oldPos = animator->animReadPos;
    AnimatorNode* node;
    f32 x, y, z;
    s32 flags;
    s32 nodeId;

    switch (*args++) {
        case AS_END:
            return -1;
        case AS_SET_RENDER_MODE:
            animator->renderMode = *args++;
            animator->animReadPos = args;
            return 1;
        case AS_WAIT:
            args++;
            animator->animReadPos = args;
            return 1;
        case AS_END_LOOP:
            animator->animReadPos = animator->savedReadPos;
            animator->treeIndexPos = animator->savedTreePos;
            reload_mesh_animator_tree(animator);
            return 1;
        case AS_OP_4:
            animator->animReadPos = animator->savedReadPos;
            animator->treeIndexPos = animator->savedTreePos;
            break;
        case AS_LOOP:
            animator->animReadPos = animator->savedReadPos = args;
            animator->savedTreePos = animator->treeIndexPos;
            return 1;
        case AS_SET_FLAGS:
            flags = *args++;
            animator->animReadPos = args;
            animator->flags |= flags & 0xFFFF;
            return 1;
        case AS_SET_NODE_FLAGS:
            node = get_animator_child_with_id(animator->rootNode, animator->staticNodeIDs[*args++ - 1]);
            flags = *args++;
            node->flags |= flags;
            animator->animReadPos = args;
            return 1;
        case AS_CLEAR_NODE_FLAGS:
            node = get_animator_child_with_id(animator->rootNode, animator->staticNodeIDs[*args++ - 1]);
            flags = *args++;
            node->flags &= ~flags;
            animator->animReadPos = args;
            return 1;
        case AS_OP_19:
            animator->flags |= MODEL_ANIMATOR_FLAG_NO_FLIP;
            animator->animReadPos = args;
            return 1;
        case AS_SET_ROTATION:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;
            if (nodeId != 0xFF) {
                node = get_animator_child_with_id(animator->rootNode, nodeId);
                if (node != NULL) {
                    node->rot.x = x;
                    node->rot.y = y;
                    node->rot.z = z;
                    return 1;
                } else {
                    animator->animReadPos = oldPos;
                    animator->treeIndexPos++;
                    break;
                }
            }
            return 1;
        case AS_ADD_ROTATION:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;
            if (nodeId != 0xFF) {
                node = get_animator_child_with_id(animator->rootNode, nodeId);
                if (node != NULL) {
                    node->rot.x += x;
                    node->rot.y += y;
                    node->rot.z += z;
                    return 1;
                } else {
                    animator->animReadPos = oldPos;
                    animator->treeIndexPos++;
                    break;
                }
            }
            return 1;
        case AS_SET_POS:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = *args++;
            y = *args++;
            z = *args++;
            animator->animReadPos = args;
            if (nodeId != 0xFF) {
                node = get_animator_child_with_id(animator->rootNode, nodeId);
                if (node != NULL) {
                    node->pos.x = x;
                    node->pos.y = y;
                    node->pos.z = z;
                    return 1;
                } else {
                    animator->animReadPos = oldPos;
                    animator->treeIndexPos++;
                    break;
                }
            }
            return 1;
        case AS_SET_SCALE:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;
            if (nodeId != 0xFF) {
                node = get_animator_child_with_id(animator->rootNode, nodeId);
                if (node != NULL) {
                    node->scale.x = x;
                    node->scale.y = y;
                    node->scale.z = z;
                    return 1;
                } else {
                    animator->animReadPos = oldPos;
                    animator->treeIndexPos++;
                    break;
                }
            }
            return 1;
    }
    return 0;
}
