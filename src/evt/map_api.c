#include "common.h"
#include "model.h"
#include "evt.h"
#include "game_modes.h"

extern LavaReset* gLavaResetList;
extern s32 LastSafeFloor;
extern ModelTreeInfoList* gCurrentModelTreeNodeInfo;

ApiStatus TranslateModel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelIndex = evt_get_variable(script, *args++);
    f32 x;
    f32 y;
    f32 z;
    Model* model;

    modelIndex = get_model_list_index_from_tree_index(modelIndex);
    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);
    model = get_model_from_list_index(modelIndex);

    if (!(model->flags & MODEL_FLAG_HAS_TRANSFORM)) {
        guTranslateF(model->userTransformMtx, x, y, z);
        model->flags |= (MODEL_FLAG_HAS_TRANSFORM | MODEL_FLAG_MATRIX_DIRTY);
    } else {
        Matrix4f mtx;

        guTranslateF(mtx, x, y, z);
        guMtxCatF(mtx, model->userTransformMtx, model->userTransformMtx);
    }

    return ApiStatus_DONE2;
}

ApiStatus RotateModel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 modelListIndex = get_model_list_index_from_tree_index(var1);
    f32 a = evt_get_float_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    Model* model = get_model_from_list_index(modelListIndex);

    if (!(model->flags & MODEL_FLAG_HAS_TRANSFORM)) {
        guRotateF(model->userTransformMtx, a, x, y, z);
        model->flags |= (MODEL_FLAG_HAS_TRANSFORM | MODEL_FLAG_MATRIX_DIRTY);
    } else {
        Matrix4f mtx;

        guRotateF(mtx, a, x, y, z);
        guMtxCatF(mtx, model->userTransformMtx, model->userTransformMtx);
    }

    return ApiStatus_DONE2;
}

ApiStatus ScaleModel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelIndex = evt_get_variable(script, *args++);
    f32 x;
    f32 y;
    f32 z;
    Model* model;

    modelIndex = get_model_list_index_from_tree_index(modelIndex);
    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);
    model = get_model_from_list_index(modelIndex);

    if (!(model->flags & MODEL_FLAG_HAS_TRANSFORM)) {
        guScaleF(model->userTransformMtx, x, y, z);
        model->flags |= (MODEL_FLAG_HAS_TRANSFORM | MODEL_FLAG_MATRIX_DIRTY);
    } else {
        Matrix4f mtx;

        guScaleF(mtx, x, y, z);
        guMtxCatF(mtx, model->userTransformMtx, model->userTransformMtx);
    }

    return ApiStatus_DONE2;
}

ApiStatus GetModelIndex(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode modelID = evt_get_variable(script, *args++);
    Bytecode index = *args++;

    evt_set_variable(script, index, get_model_list_index_from_tree_index(modelID));
    return ApiStatus_DONE2;
}

ApiStatus InvalidateModelTransform(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode modelID = evt_get_variable(script, *args++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(modelID));

    model->flags &= ~MODEL_FLAG_HAS_TRANSFORM;
    return ApiStatus_DONE2;
}

ApiStatus CloneModel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode srcModelID = evt_get_variable(script, *args++);
    Bytecode newModelID = evt_get_variable(script, *args++);

    clone_model(srcModelID, newModelID);
    return ApiStatus_DONE2;
}

ApiStatus GetModelCenter(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 centerX;
    f32 centerY;
    f32 centerZ;
    f32 sizeX;
    f32 sizeY;
    f32 sizeZ;

    get_model_center_and_size(evt_get_variable(script, *args++), &centerX, &centerY, &centerZ, &sizeX, &sizeY,
                              &sizeZ);
    script->varTable[0] = centerX;
    script->varTable[1] = centerY;
    script->varTable[2] = centerZ;
    return ApiStatus_DONE2;
}

ApiStatus SetTexPanner(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIndex = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    set_tex_panner(model, var2);
    model->flags |= MODEL_FLAG_HAS_TEX_PANNER;
    return ApiStatus_DONE2;
}

ApiStatus SetCustomGfxEnabled(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode treeIndex = evt_get_variable(script, *args++);
    Bytecode enable = evt_get_variable(script, *args++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    if (enable) {
        model->flags |= MODEL_FLAG_USES_CUSTOM_GFX;
    } else {
        model->flags &= ~MODEL_FLAG_USES_CUSTOM_GFX;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetModelCustomGfx(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIndex = evt_get_variable(script, *args++);
    s32 customGfxUnit = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    Model* model;

    treeIndex = get_model_list_index_from_tree_index(treeIndex);
    model = get_model_from_list_index(treeIndex);

    set_mdl_custom_gfx_set(model, customGfxUnit, var3);
    if (customGfxUnit != -1) {
        model->flags |= MODEL_FLAG_USES_CUSTOM_GFX;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetModelTexVariant(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode modelID = evt_get_variable(script, *args++);
    Bytecode variation = evt_get_variable(script, *args++);
    s32 modelIndex = get_model_list_index_from_tree_index(modelID);
    Model* model = get_model_from_list_index(modelIndex);

    model->textureVariation = variation;
    return ApiStatus_DONE2;
}

ApiStatus EnableTexPanning(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args++);
    s32 flag = evt_get_variable(script, *args++);
    s32 modelIndex = get_model_list_index_from_tree_index(modelID);
    Model* model = get_model_from_list_index(modelIndex);

    if (flag) {
        model->flags |= MODEL_FLAG_HAS_TEX_PANNER;
    } else {
        model->flags &= ~MODEL_FLAG_HAS_TEX_PANNER;
    }
    return ApiStatus_DONE2;
}

ApiStatus EnableModel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelIndex = get_model_list_index_from_tree_index(evt_get_variable(script, *args++));
    Bytecode enabled = evt_get_variable(script, *args++);
    Model* model = get_model_from_list_index(modelIndex);

    if (enabled) {
        model->flags &= ~MODEL_FLAG_HIDDEN;
    } else {
        model->flags |= MODEL_FLAG_HIDDEN;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetGroupVisibility(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode groupModelID = evt_get_variable(script, *args++);
    Bytecode enabled = evt_get_variable(script, *args++);

    mdl_group_set_visibility(groupModelID, MODEL_FLAG_HIDDEN, enabled);
    return ApiStatus_DONE2;
}

ApiStatus SetTexPanOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode texPanner = evt_get_variable(script, *args++);
    Bytecode tileSelect = evt_get_variable(script, *args++);
    Bytecode u = evt_get_variable(script, *args++);
    Bytecode v = evt_get_variable(script, *args++);

    if (tileSelect == 0) {
        set_main_pan_u(texPanner, u);
        set_main_pan_v(texPanner, v);
    } else {
        set_aux_pan_u(texPanner, u);
        set_aux_pan_v(texPanner, v);
    }

    return ApiStatus_DONE2;
}

ApiStatus SetCustomGfx(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    Gfx* pre = (Gfx*) evt_get_variable(script, *args++);
    Gfx* post = (Gfx*) evt_get_variable(script, *args++);

    set_custom_gfx(idx, pre, post);
    return ApiStatus_DONE2;
}

ApiStatus SetCustomGfxBuilders(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    ModelCustomGfxBuilderFunc pre = (ModelCustomGfxBuilderFunc) evt_get_variable(script, *args++);
    ModelCustomGfxBuilderFunc post = (ModelCustomGfxBuilderFunc) evt_get_variable(script, *args++);

    set_custom_gfx_builders(index, pre, post);
    return ApiStatus_DONE2;
}

ApiStatus SetModelFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelIndex;
    s32 a1;
    s32 enable;
    Model* model;

    modelIndex = evt_get_variable(script, *args++);
    modelIndex = get_model_list_index_from_tree_index(modelIndex);
    a1 = *args++;
    enable = evt_get_variable(script, *args++);
    model = get_model_from_list_index(modelIndex);

    if (enable) {
        model->flags |= a1;
    } else {
        model->flags &= ~a1;
    }

    return ApiStatus_DONE2;
}

void apply_transform_to_children(ApiStatus (*apiFunc)(Evt*, s32), Evt* script) {
    Evt localEvt;
    ModelTreeInfo* parentModelInfo;
    ModelTreeInfo* childModelInfo;
    s32 parentModelID;
    s32 originalArg;
    s32* argsPtr;
    s32 modelIndex;
    s32 firstChild;
    s32 lastChild;
    s32 i;

    firstChild = -1;
    parentModelID = evt_get_variable(script, *script->ptrReadPos);
    modelIndex = (*gCurrentModelTreeNodeInfo)[parentModelID].modelIndex;
    lastChild = -1;

    if (modelIndex < 0xFF) {
        firstChild = lastChild = modelIndex;
    } else {
        s32 treeDepth = (*gCurrentModelTreeNodeInfo)[parentModelID].treeDepth;

        // check all models with a lowerID in the tree
        for (i = parentModelID - 1; i >= 0; i--) {
            childModelInfo = &(*gCurrentModelTreeNodeInfo)[i];

            if (treeDepth < childModelInfo->treeDepth) {
                s32 childModelIndex = childModelInfo->modelIndex;

                if (childModelIndex < 0xFF) {
                    if (lastChild == -1) {
                        lastChild = childModelIndex;
                    }
                    firstChild = childModelIndex;
                }
            } else {
                // if node is no longer deeper than parent, we've exhausted the children
                break;
            }
        }
    }

    // copy the input script into a local one we will modify
    localEvt = *script;

    argsPtr = localEvt.ptrReadPos;
    originalArg = *argsPtr;

    for (i = firstChild; i <= lastChild; i++) {
        Model* model = (*gCurrentModels)[i];

        localEvt.ptrReadPos = argsPtr;
        *argsPtr = model->modelID;

        apiFunc(&localEvt, TRUE);
    }

    *argsPtr = originalArg;
}

ApiStatus MakeTransformGroup(Evt* script, s32 isInitialCall) {
    mdl_make_transform_group((u16)evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus SetTransformGroupEnabled(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    u16 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    if (var2 != 0) {
        enable_transform_group(var1);
    } else {
        disable_transform_group(var1);
    }
    return ApiStatus_DONE2;
}

ApiStatus TranslateGroup(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args);
    s32 index = get_transform_group_index(modelID);
    ModelTransformGroup* transformGroup;
    Matrix4f mtx;
    f32 x, y, z;

    if (index == -1) {
        apply_transform_to_children(TranslateModel, script);
        return ApiStatus_DONE2;
    }

    args++;

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    transformGroup = get_transform_group(index);

    index = transformGroup->flags & TRANSFORM_GROUP_FLAG_HAS_TRANSFORM; // TODO fix weird match
    if (!index) {
        guTranslateF(transformGroup->userTransformMtx, x, y, z);
        transformGroup->flags |= TRANSFORM_GROUP_FLAG_HAS_TRANSFORM;
        transformGroup->flags |= TRANSFORM_GROUP_FLAG_MATRIX_DIRTY;
    } else {
        guTranslateF(mtx, x, y, z);
        guMtxCatF(mtx, transformGroup->userTransformMtx, transformGroup->userTransformMtx);
    }

    return ApiStatus_DONE2;
}

ApiStatus RotateGroup(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args);
    s32 index = get_transform_group_index(modelID);
    ModelTransformGroup* transformGroup;
    Matrix4f mtx;
    f32 a, x, y, z;

    if (index == -1) {
        apply_transform_to_children(RotateModel, script);
        return ApiStatus_DONE2;
    }

    args++;

    a = evt_get_float_variable(script, *args++);
    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    transformGroup = get_transform_group(index);

    if (!(transformGroup->flags & TRANSFORM_GROUP_FLAG_HAS_TRANSFORM)) {
        guRotateF(transformGroup->userTransformMtx, a, x, y, z);
        transformGroup->flags |= TRANSFORM_GROUP_FLAG_HAS_TRANSFORM;
        transformGroup->flags |= TRANSFORM_GROUP_FLAG_MATRIX_DIRTY;
    } else {
        guRotateF(mtx, a, x, y, z);
        guMtxCatF(mtx, transformGroup->userTransformMtx, transformGroup->userTransformMtx);
    }

    return ApiStatus_DONE2;
}

ApiStatus ScaleGroup(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args);
    s32 transformIndex = get_transform_group_index(modelID);
    ModelTransformGroup* transformGroup;
    Matrix4f mtx;
    f32 x, y, z;

    if (transformIndex == -1) {
        apply_transform_to_children(ScaleModel, script);
        return ApiStatus_DONE2;
    }

    args++;

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    transformGroup = get_transform_group(transformIndex);

    transformIndex = transformGroup->flags & TRANSFORM_GROUP_FLAG_HAS_TRANSFORM; // TODO fix weird match
    if (!(transformIndex)) {
        guScaleF(transformGroup->userTransformMtx, x, y, z);
        transformGroup->flags |= TRANSFORM_GROUP_FLAG_HAS_TRANSFORM;
        transformGroup->flags |= TRANSFORM_GROUP_FLAG_MATRIX_DIRTY;
    } else {
        guScaleF(mtx, x, y, z);
        guMtxCatF(mtx, transformGroup->userTransformMtx, transformGroup->userTransformMtx);
    }

    return ApiStatus_DONE2;
}

ApiStatus GetTransformGroup(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args++);
    Bytecode var2 = *args++;

    evt_set_variable(script, var2, get_transform_group_index(modelID));
    return ApiStatus_DONE2;
}

ApiStatus EnableGroup(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args);
    s32 index = get_transform_group_index(modelID);
    s32 flagUnset;
    ModelTransformGroup* transformGroup;

    if (index == -1) {
        apply_transform_to_children(EnableModel, script);
        return ApiStatus_DONE2;
    }

    args++;

    flagUnset = evt_get_variable(script, *args++);
    transformGroup = get_transform_group(index);

    for (index = transformGroup->minChildModelIndex; index <= transformGroup->maxChildModelIndex; index++) {
        Model* model = get_model_from_list_index(index);
        if (flagUnset) {
            model->flags &= ~MODEL_FLAG_HIDDEN;
        } else {
            model->flags |= MODEL_FLAG_HIDDEN;
        }
    }

    return ApiStatus_DONE2;
}

ApiStatus MakeLocalVertexCopy(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 copyIndex = evt_get_variable(script, *args++);
    u16 modelID = evt_get_variable(script, *args++);
    s32 isMakingCopy = evt_get_variable(script, *args++);

    mdl_make_local_vertex_copy(copyIndex, modelID, isMakingCopy);
    return ApiStatus_DONE2;
}

void modify_collider_family_flags(s32 index, s32 flags, s32 mode) {
    Collider* collider = &gCollisionData.colliderList[index];

    if (collider->nextSibling >= 0) {
        modify_collider_family_flags(collider->nextSibling, flags, mode);
    }

    if (collider->firstChild >= 0) {
        modify_collider_family_flags(collider->firstChild, flags, mode);
    }

    switch (mode) {
        case MODIFY_COLLIDER_FLAGS_SET_BITS:
            collider->flags |= flags;
            break;
        case MODIFY_COLLIDER_FLAGS_CLEAR_BITS:
            collider->flags &= ~flags;
            break;
        case MODIFY_COLLIDER_FLAGS_SET_VALUE:
            collider->flags = flags;
            break;
        case MODIFY_COLLIDER_FLAGS_SET_SURFACE:
            collider->flags &= ~0xFF;
            collider->flags |= flags & 0xFF;
            break;

    }
}

ApiStatus ModifyColliderFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 mode = evt_get_variable(script, *args++);
    s32 index = evt_get_variable(script, *args++);
    s32 flags = evt_get_variable(script, *args++);
    Collider* collider = &gCollisionData.colliderList[index];

    if (collider->firstChild >= 0) {
        modify_collider_family_flags(collider->firstChild, flags, mode);
    }

    switch (mode) {
        case MODIFY_COLLIDER_FLAGS_SET_BITS:
            collider->flags |= flags;
            break;
        case MODIFY_COLLIDER_FLAGS_CLEAR_BITS:
            collider->flags &= ~flags;
            break;
        case MODIFY_COLLIDER_FLAGS_SET_VALUE:
            collider->flags = flags;
            break;
        case MODIFY_COLLIDER_FLAGS_SET_SURFACE:
            collider->flags &= ~0xFF;
            collider->flags |= flags & 0xFF;
            break;
    }

    return ApiStatus_DONE2;
}

//TODO rename to MonitorLastSafeFloor
ApiStatus ResetFromLava(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    Collider* collider;
    LavaReset* lavaReset;

    if (isInitialCall) {
        lavaReset = gLavaResetList = (LavaReset*)evt_get_variable(script, *args++);

        while (TRUE) {
            if (lavaReset->colliderID == -1) {
                break;
            }
            collider = &gCollisionData.colliderList[lavaReset->colliderID];
            if (collider->firstChild >= 0) {
                modify_collider_family_flags(collider->firstChild, COLLIDER_FLAG_SAFE_FLOOR, 0);
            }
            collider->flags |= COLLIDER_FLAG_SAFE_FLOOR;
            lavaReset++;
        }

        LastSafeFloor = -1;
    }

    if (!(collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT)) {
        collider = &gCollisionData.colliderList[collisionStatus->curFloor];
        if (collider->flags & COLLIDER_FLAG_SAFE_FLOOR) {
            LastSafeFloor = collisionStatus->curFloor;
            return ApiStatus_BLOCK;
        }
    }

    return ApiStatus_BLOCK;
}

s32 get_lava_reset_pos(f32* outX, f32* outY, f32* outZ) {
    Vec4f *temp_v0;
    s32 temp_a0;
    LavaReset* lavaReset = gLavaResetList;

    if (LastSafeFloor == -1) {
        temp_v0 = &(*get_current_map_settings()->entryList)[gGameStatusPtr->entryID];
        *outX = temp_v0->x;
        *outY = temp_v0->y;
        *outZ = temp_v0->z;
        return -1;
    }

    while (TRUE) {
        if (lavaReset->colliderID == -1) {
            break;
        }

        if (lavaReset->colliderID == LastSafeFloor) {
            *outX = lavaReset->pos.x;
            *outY = lavaReset->pos.y;
            *outZ = lavaReset->pos.z;
            return 1;
        }
        lavaReset++;
    }
    return 0;
}

ApiStatus GetColliderCenter(Evt* script, s32 isInitialCall) {
    f32 x, y, z;

    get_collider_center(evt_get_variable(script, *script->ptrReadPos), &x, &y, &z);

    script->varTable[0] = x;
    script->varTable[1] = y;
    script->varTable[2] = z;

    return ApiStatus_DONE2;
}

ApiStatus ParentColliderToModel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s16 colliderID = evt_get_variable(script, *args++);
    s32 treeIndex = evt_get_variable(script, *args++);

    parent_collider_to_model(colliderID, get_model_list_index_from_tree_index(treeIndex));
    update_collider_transform(colliderID);
    return ApiStatus_DONE2;
}

ApiStatus UpdateColliderTransform(Evt* script, s32 isInitialCall) {
    update_collider_transform(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

void set_zone_enabled(s32 zoneID, s32 enabled) {
    Collider* zone = &gZoneCollisionData.colliderList[zoneID];

    if (zone->nextSibling >= 0) {
        set_zone_enabled(zone->nextSibling, enabled);
    }
    if (zone->firstChild >= 0) {
        set_zone_enabled(zone->firstChild, enabled);
    }

    switch (enabled) {
        case 0:
            zone->flags |= TEMP_SET_ZONE_ENABLED_FLAG_10000;
            break;
        case 1:
            zone->flags &= ~TEMP_SET_ZONE_ENABLED_FLAG_10000;
            break;
    }
}

ApiStatus SetZoneEnabled(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 zoneID = evt_get_variable(script, *args++);
    s32 enabled = evt_get_variable(script, *args++);
    Collider* zone = &gZoneCollisionData.colliderList[zoneID];

    if (zone->firstChild >= 0) {
        set_zone_enabled(zone->firstChild, enabled);
    }

    switch (enabled) {
        case FALSE:
            zone->flags |= TEMP_SET_ZONE_ENABLED_FLAG_10000;
            break;
        case TRUE:
            zone->flags &= ~TEMP_SET_ZONE_ENABLED_FLAG_10000;
            break;
    }

    return ApiStatus_DONE2;
}

void goto_map(Evt* script, s32 mode) {
    Bytecode* args = script->ptrReadPos;
    s16 mapID;
    s16 areaID;
    s16 mapTransitionEffect = TRANSITION_STANDARD;

    if (mode == 2) {
        areaID = evt_get_variable(script, *args++);
        mapID = evt_get_variable(script, *args++);
    } else {
        get_map_IDs_by_name((char*)evt_get_variable(script, *args++), &areaID, &mapID);
    }

    gGameStatusPtr->areaID = areaID;
    gGameStatusPtr->mapID = mapID;
    gGameStatusPtr->entryID = evt_get_variable(script, *args++);

    if (mode == 1) {
        mapTransitionEffect = evt_get_variable(script, *args++);
    }

    set_map_transition_effect(mapTransitionEffect);
    set_game_mode(GAME_MODE_CHANGE_MAP);
}

ApiStatus GotoMap(Evt* script, s32 isInitialCall) {
    goto_map(script, 0);
    return ApiStatus_DONE1;
}

ApiStatus GotoMapSpecial(Evt* script, s32 isInitialCall) {
    goto_map(script, 1);
    return ApiStatus_DONE1;
}

ApiStatus GotoMapByID(Evt* script, s32 isInitialCall) {
    goto_map(script, 2);
    return ApiStatus_DONE1;
}

ApiStatus GetEntryID(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gGameStatusPtr->entryID);
    return ApiStatus_DONE2;
}

ApiStatus GetMapID(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gGameStatusPtr->mapID);
    return ApiStatus_DONE2;
}

ApiStatus GetLoadType(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gGameStatusPtr->loadType != 0);
    return ApiStatus_DONE2;
}

ApiStatus SetRenderMode(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIndex = evt_get_variable(script, *args++);
    s8 renderMode = evt_get_variable(script, *args++);

    get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex))->renderMode = renderMode;

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtModel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args++);
    s32 soundID = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 x, y, z;
    f32 sx, sy, sz;

    get_model_center_and_size(modelID, &x, &y, &z, &sx, &sy, &sz);
    sfx_play_sound_at_position(soundID, var3, x, y, z);

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtCollider(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 colliderID = evt_get_variable(script, *args++);
    s32 soundID = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 x, y, z;

    get_collider_center(colliderID, &x, &y, &z);
    sfx_play_sound_at_position(soundID, var3, x, y, z);

    return ApiStatus_DONE2;
}
