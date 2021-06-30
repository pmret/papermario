#include "common.h"

typedef struct LavaReset {
    /* 0x00 */ s32 colliderID;
    /* 0x04 */ Vec3f pos;
} LavaReset; // size = 0x10;

extern LavaReset* gLavaResetList;
extern s32 D_802DADA4;

ApiStatus TranslateModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelIndex = get_variable(script, *args++);
    f32 x;
    f32 y;
    f32 z;
    Model* model;

    modelIndex = get_model_list_index_from_tree_index(modelIndex);
    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);
    model = get_model_from_list_index(modelIndex);

    if (!(model->flags & 0x400)) {
        guTranslateF(model->transformMatrix, x, y, z);
        model->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guTranslateF(mtx, x, y, z);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
    }

    return ApiStatus_DONE2;
}

ApiStatus RotateModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 modelListIndex = get_model_list_index_from_tree_index(var1);
    f32 a = get_float_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    Model* model = get_model_from_list_index(modelListIndex);

    if (!(model->flags & 0x400)) {
        guRotateF(model->transformMatrix, a, x, y, z);
        model->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guRotateF(mtx, a, x, y, z);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
    }

    return ApiStatus_DONE2;
}

ApiStatus ScaleModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelIndex = get_variable(script, *args++);
    f32 x;
    f32 y;
    f32 z;
    Model* model;

    modelIndex = get_model_list_index_from_tree_index(modelIndex);
    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);
    model = get_model_from_list_index(modelIndex);

    if (!(model->flags & 0x400)) {
        guScaleF(model->transformMatrix, x, y, z);
        model->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guScaleF(mtx, x, y, z);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
    }

    return ApiStatus_DONE2;
}

ApiStatus GetModelIndex(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode modelID = get_variable(script, *args++);
    Bytecode index = *args++;

    set_variable(script, index, get_model_list_index_from_tree_index(modelID));
    return ApiStatus_DONE2;
}

ApiStatus InvalidateModelTransform(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode modelID = get_variable(script, *args++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(modelID));

    model->flags &= ~0x400;
    return ApiStatus_DONE2;
}

ApiStatus CloneModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode srcModelID = get_variable(script, *args++);
    Bytecode newModelID = get_variable(script, *args++);

    clone_model(srcModelID, newModelID);
    return ApiStatus_DONE2;
}

ApiStatus GetModelCenter(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 centerX;
    f32 centerY;
    f32 centerZ;
    f32 sizeX;
    f32 sizeY;
    f32 sizeZ;

    get_model_center_and_size(get_variable(script, *args++), &centerX, &centerY, &centerZ, &sizeX, &sizeY,
                              &sizeZ);
    script->varTable[0] = centerX;
    script->varTable[1] = centerY;
    script->varTable[2] = centerZ;
    return ApiStatus_DONE2;
}

ApiStatus SetTexPanner(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    set_tex_panner(model, var2);
    model->flags |= 0x800;
    return ApiStatus_DONE2;
}

ApiStatus SetCustomGfxEnabled(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode treeIndex = get_variable(script, *args++);
    Bytecode enable = get_variable(script, *args++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    if (enable) {
        model->flags |= 0x10;
    } else {
        model->flags &= ~0x10;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetModelCustomGfx(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    Model* model;

    treeIndex = get_model_list_index_from_tree_index(treeIndex);
    model = get_model_from_list_index(treeIndex);

    set_mdl_custom_gfx_set(model, var2, var3);
    if (var2 != -1) {
        model->flags |= 0x10;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetModelTexVariant(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode treeIndex = get_variable(script, *args++);
    Bytecode var2 = get_variable(script, *args++);

    get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex))->unk_A9 = var2;
    return ApiStatus_DONE2;
}

ApiStatus EnableTexPanning(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *args++);
    s32 flag = get_variable(script, *args++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    if (flag) {
        model->flags |= 0x800;
    } else {
        model->flags &= ~0x800;
    }
    return ApiStatus_DONE2;
}

ApiStatus EnableModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 listIndex = get_model_list_index_from_tree_index(get_variable(script, *args++));
    Bytecode flag = get_variable(script, *args++);
    Model* model = get_model_from_list_index(listIndex);

    if (flag != 0) {
        model->flags &= ~0x2;
    } else {
        model->flags |= 0x2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetGroupEnabled(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var1 = get_variable(script, *args++);
    Bytecode var2 = get_variable(script, *args++);

    func_8011B7C0(var1, 2, var2);
    return ApiStatus_DONE2;
}

ApiStatus SetTexPanOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var1 = get_variable(script, *args++);
    Bytecode var2 = get_variable(script, *args++);
    Bytecode var3 = get_variable(script, *args++);
    Bytecode var4 = get_variable(script, *args++);

    if (var2 == 0) {
        set_main_pan_u(var1, var3);
        set_main_pan_v(var1, var4);
    } else {
        set_aux_pan_u(var1, var3);
        set_aux_pan_v(var1, var4);
    }

    return ApiStatus_DONE2;
}

ApiStatus SetCustomGfx(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    set_custom_gfx(var1, var2, var3);
    return ApiStatus_DONE2;
}

ApiStatus SetCustomGfxBuilders(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    set_custom_gfx_builders(var1, var2, var3);
    return ApiStatus_DONE2;
}

ApiStatus SetModelFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelIndex;
    s32 a1;
    s32 enable;
    Model* model;

    modelIndex = get_variable(script, *args++);
    modelIndex = get_model_list_index_from_tree_index(modelIndex);
    a1 = *args++;
    enable = get_variable(script, *args++);
    model = get_model_from_list_index(modelIndex);

    if (enable) {
        model->flags |= a1;
    } else {
        model->flags &= ~a1;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/map_api", apply_transform_to_children);

ApiStatus MakeTransformGroup(ScriptInstance* script, s32 isInitialCall) {
    make_transform_group((u16)get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus SetTransformGroupEnabled(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    u16 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    if (var2 != 0) {
        enable_transform_group(var1);
    } else {
        disable_transform_group(var1);
    }
    return ApiStatus_DONE2;
}

ApiStatus TranslateGroup(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args);
    s32 index = get_transform_group_index(var1);
    ModelTransformGroup* transformGroup;
    f32 x, y, z;

    if (index == -1) {
        apply_transform_to_children(TranslateModel, script);
        return ApiStatus_DONE2;
    }

    args++;

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    transformGroup = get_transform_group(index);

    index = transformGroup->flags & 0x400; // TODO fix weird match
    if (!index) {
        guTranslateF(transformGroup->matrixB, x, y, z);
        transformGroup->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guTranslateF(mtx, x, y, z);
        guMtxCatF(mtx, transformGroup->matrixB, transformGroup->matrixB);
    }

    return ApiStatus_DONE2;
}

ApiStatus RotateGroup(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_transform_group_index(get_variable(script, *args));
    ModelTransformGroup* transformGroup;
    f32 a, x, y, z;

    if (index == -1) {
        apply_transform_to_children(RotateModel, script);
        return ApiStatus_DONE2;
    }

    args++;

    a = get_float_variable(script, *args++);
    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    transformGroup = get_transform_group(index);

    if (!(transformGroup->flags & 0x400)) {
        guRotateF(transformGroup->matrixB, a, x, y, z);
        transformGroup->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guRotateF(mtx, a, x, y, z);
        guMtxCatF(mtx, transformGroup->matrixB, transformGroup->matrixB);
    }

    return ApiStatus_DONE2;
}

ApiStatus ScaleGroup(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args);
    s32 index = get_transform_group_index(var1);
    ModelTransformGroup* transformGroup;
    f32 x, y, z;

    if (index == -1) {
        apply_transform_to_children(ScaleModel, script);
        return ApiStatus_DONE2;
    }

    args++;

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    transformGroup = get_transform_group(index);

    index = transformGroup->flags & 0x400; // TODO fix weird match
    if (!(index)) {
        guScaleF(transformGroup->matrixB, x, y, z);
        transformGroup->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guScaleF(mtx, x, y, z);
        guMtxCatF(mtx, transformGroup->matrixB, transformGroup->matrixB);
    }

    return ApiStatus_DONE2;
}

ApiStatus GetTransformGroup(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    Bytecode var2 = *args++;

    set_variable(script, var2, get_transform_group_index(var1));
    return ApiStatus_DONE2;
}

ApiStatus EnableGroup(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_transform_group_index(get_variable(script, *args));
    s32 flagUnset;
    ModelTransformGroup* transformGroup;

    if (index == -1) {
        apply_transform_to_children(EnableModel, script);
        return ApiStatus_DONE2;
    }

    args++;

    flagUnset = get_variable(script, *args++);
    transformGroup = get_transform_group(index);

    for (index = transformGroup->minChildModelIndex; index <= transformGroup->maxChildModelIndex; index++) {
        Model* model = get_model_from_list_index(index);
        if (flagUnset) {
            model->flags &= ~0x2;
        } else {
            model->flags |= 0x2;
        }
    }

    return ApiStatus_DONE2;
}

ApiStatus MakeLocalVertexCopy(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    u16 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    mdl_make_local_vertex_copy(var1, var2, var3);
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
        case 0:
            collider->flags |= flags;
            break;
        case 1:
            collider->flags &= ~flags;
            break;
        case 2:
            collider->flags = flags;
            break;
        case 3:
            collider->flags &= ~0xFF;
            collider->flags |= flags & 0xFF;
            break;

    }
}

ApiStatus ModifyColliderFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 mode = get_variable(script, *args++);
    s32 index = get_variable(script, *args++);
    s32 flags = get_variable(script, *args++);
    Collider* collider = &gCollisionData.colliderList[index];

    if (collider->firstChild >= 0) {
        modify_collider_family_flags(collider->firstChild, flags, mode);
    }

    switch (mode) {
        case 0:
            collider->flags |= flags;
            break;
        case 1:
            collider->flags &= ~flags;
            break;
        case 2:
            collider->flags = flags;
            break;
        case 3:
            collider->flags &= ~0xFF;
            collider->flags |= flags & 0xFF;
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus ResetFromLava(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    Collider* collider;
    LavaReset* lavaReset;

    if (isInitialCall) {
        lavaReset = gLavaResetList = get_variable(script, *args++);

        while (TRUE) {
            if (lavaReset->colliderID == -1) {
                break;
            }
            collider = &gCollisionData.colliderList[lavaReset->colliderID];
            if (collider->firstChild >= 0) {
                modify_collider_family_flags(collider->firstChild, 0x100, 0);
            }
            collider->flags |= 0x100;
            lavaReset++;
        }

        D_802DADA4 = -1;
    }

    if (!(collisionStatus->currentFloor & 0x4000)) {
        collider = &gCollisionData.colliderList[collisionStatus->currentFloor];
        if (collider->flags & 0x100) {
            D_802DADA4 = collisionStatus->currentFloor;
            return ApiStatus_BLOCK;
        }
    }

    return ApiStatus_BLOCK;
}

s32 get_lava_reset_pos(f32* outX, f32* outY, f32* outZ) {
    Vec4f *temp_v0;
    s32 temp_a0;
    LavaReset* lavaReset = gLavaResetList;

    if (D_802DADA4 == -1) {
        temp_v0 = &(*get_current_map_header()->entryList)[gGameStatusPtr->entryID];
        *outX = temp_v0->x;
        *outY = temp_v0->y;
        *outZ = temp_v0->z;
        return -1;
    }

    while (TRUE) {
        if (lavaReset->colliderID == -1) {
            break;
        }

        if (lavaReset->colliderID == D_802DADA4) {
            *outX = lavaReset->pos.x;
            *outY = lavaReset->pos.y;
            *outZ = lavaReset->pos.z;
            return 1;
        }
        lavaReset++;
    }
    return 0;
}

ApiStatus GetColliderCenter(ScriptInstance* script, s32 isInitialCall) {
    f32 x, y, z;

    get_collider_center(get_variable(script, *script->ptrReadPos), &x, &y, &z);

    script->varTable[0] = x;
    script->varTable[1] = y;
    script->varTable[2] = z;

    return ApiStatus_DONE2;
}

ApiStatus ParentColliderToModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s16 colliderID = get_variable(script, *args++);
    s32 treeIndex = get_variable(script, *args++);

    parent_collider_to_model(colliderID, get_model_list_index_from_tree_index(treeIndex));
    update_collider_transform(colliderID);
    return ApiStatus_DONE2;
}

ApiStatus UpdateColliderTransform(ScriptInstance* script, s32 isInitialCall) {
    update_collider_transform(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

void set_zone_enabled(s32 zoneID, s32 enabled) {
    TempSetZoneEnabled* unkStruct = &D_800D91D4[zoneID];

    if (unkStruct->id1 >= 0) {
        set_zone_enabled(unkStruct->id1, enabled);
    }
    if (unkStruct->id2 >= 0) {
        set_zone_enabled(unkStruct->id2, enabled);
    }

    switch (enabled) {
        case 0:
            unkStruct->flags |= 0x10000;
            break;
        case 1:
            unkStruct->flags &= ~0x10000;
            break;
    }
}

ApiStatus SetZoneEnabled(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);
    TempSetZoneEnabled* unkStruct = &D_800D91D4[idx];

    if (unkStruct->id2 >= 0) {
        set_zone_enabled(unkStruct->id2, enabled);
    }

    switch (enabled) {
        case FALSE:
            unkStruct->flags |= 0x10000;
            break;
        case TRUE:
            unkStruct->flags &= ~0x10000;
            break;
    }

    return ApiStatus_DONE2;
}

void goto_map(ScriptInstance* script, s32 mode) {
    Bytecode* args = script->ptrReadPos;
    s16 mapID;
    s16 areaID;
    s16 mapTransitionEffect = 0;

    if (mode == 2) {
        areaID = get_variable(script, *args++);
        mapID = get_variable(script, *args++);
    } else {
        get_map_IDs_by_name(get_variable(script, *args++), &areaID, &mapID);
    }

    gGameStatusPtr->areaID = areaID;
    gGameStatusPtr->mapID = mapID;
    gGameStatusPtr->entryID = get_variable(script, *args++);

    if (mode == 1) {
        mapTransitionEffect = get_variable(script, *args++);
    }

    set_map_transition_effect(mapTransitionEffect);
    set_game_mode(5);
}

ApiStatus GotoMap(ScriptInstance* script, s32 isInitialCall) {
    goto_map(script, 0);
    return ApiStatus_DONE1;
}

ApiStatus GotoMapSpecial(ScriptInstance* script, s32 isInitialCall) {
    goto_map(script, 1);
    return ApiStatus_DONE1;
}

ApiStatus GotoMapByID(ScriptInstance* script, s32 isInitialCall) {
    goto_map(script, 2);
    return ApiStatus_DONE1;
}

ApiStatus GetEntryID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gGameStatusPtr->entryID);
    return ApiStatus_DONE2;
}

ApiStatus GetMapID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gGameStatusPtr->mapID);
    return ApiStatus_DONE2;
}

ApiStatus GetLoadType(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gGameStatusPtr->loadType != 0);
    return ApiStatus_DONE2;
}

ApiStatus SetRenderMode(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *args++);
    s8 renderMode = get_variable(script, *args++);

    get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex))->renderMode = renderMode;

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = get_variable(script, *args++);
    SoundID soundID = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    f32 x, y, z;
    f32 sx, sy, sz;

    get_model_center_and_size(modelID, &x, &y, &z, &sx, &sy, &sz);
    sfx_play_sound_at_position(soundID, var3, x, y, z);

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtCollider(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 colliderID = get_variable(script, *args++);
    SoundID soundID = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    f32 x, y, z;

    get_collider_center(colliderID, &x, &y, &z);
    sfx_play_sound_at_position(soundID, var3, x, y, z);

    return ApiStatus_DONE2;
}
