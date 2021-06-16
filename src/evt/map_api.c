#include "common.h"

typedef struct TempSetZoneEnabled {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 id1;
    /* 0x06 */ s16 id2;
    /* 0x08 */ char unk_08[0x14];
} TempSetZoneEnabled; // size = 0x1C

extern TempSetZoneEnabled* D_800D91D4;

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
        guTranslateF(&model->transformMatrix, x, y, z);
        model->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guTranslateF(&mtx, x, y, z);
        guMtxCatF(&mtx, &model->transformMatrix, &model->transformMatrix);
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
        guScaleF(&model->transformMatrix, x, y, z);
        model->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guScaleF(&mtx, x, y, z);
        guMtxCatF(&mtx, &model->transformMatrix, &model->transformMatrix);
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

ApiStatus func_802C8EE4(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetModelFlag10(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus func_802C90FC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    Model* model;

    treeIndex = get_model_list_index_from_tree_index(treeIndex);
    model = get_model_from_list_index(treeIndex);

    func_8011BC7C(model, var2, var3);
    if (var2 != -1) {
        model->flags |= 0x10;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802C91A4(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus func_802C9428(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    func_8011BCB4(var1, var2, var3);
    return ApiStatus_DONE2;
}

ApiStatus func_802C94A0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    func_8011BCD0(var1, var2, var3);
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

INCLUDE_ASM(s32, "evt/map_api", func_802C95A0);

ApiStatus func_802C971C(ScriptInstance* script, s32 isInitialCall) {
    func_8011B37C((u16)get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_802C9748(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    u16 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    if (var2 != 0) {
        func_8011B5D0(var1);
    } else {
        func_8011B660(var1);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/map_api", TranslateGroup, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/map_api", RotateGroup, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/map_api", ScaleGroup, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802C9B40(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    Bytecode var2 = *args++;

    set_variable(script, var2, func_8011B090(var1));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/map_api", EnableGroup, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802C9C70(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    u16 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    func_8011C164(var1, var2, var3);
    return ApiStatus_DONE2;
}

// Sub vs add at the beginning with the colliderList access
#ifdef NON_MATCHING
void modify_collider_family_flags(s32 arg0, s32 arg1, s32 arg2) {
    Collider* collider = &gCollisionData.colliderList[arg0];

    if (collider->nextSibling >= 0) {
        modify_collider_family_flags(collider->nextSibling, arg1, arg2);
    }

    if (collider->firstChild >= 0) {
        modify_collider_family_flags(collider->firstChild, arg1, arg2);
    }

    switch (arg2) {
        case 0:
            collider->flags |= arg1;
            break;
        case 1:
            collider->flags &= ~arg1;
            break;
        case 2:
            collider->flags = arg1;
            break;
        case 3:
            collider->flags &= ~0xFF;
            collider->flags |= (u8)arg1;
            break;

    }
}
#else
INCLUDE_ASM(s32, "evt/map_api", modify_collider_family_flags);
#endif

INCLUDE_ASM(s32, "evt/map_api", ModifyColliderFlags, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/map_api", ResetFromLava, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/map_api", func_802C9FD4);

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

INCLUDE_ASM(s32, "evt/map_api", goto_map);

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
