#include "common.h"

// Works to set model->flags & 0x400 to modelListIndex, but that seems wrong and misleading (fake match)
#ifdef NON_MATCHING
ApiStatus TranslateModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 modelListIndex = get_model_list_index_from_tree_index(var1);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    Model* model = get_model_from_list_index(modelListIndex);

    if ((model->flags & 0x400) == 0) {
        guTranslateF(&model->transformMatrix, x, y, z);
        model->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guTranslateF(&mtx, x, y, z);
        guMtxCatF(&mtx, &model->transformMatrix, &model->transformMatrix);
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "code_ED510", TranslateModel, ScriptInstance* script, s32 isInitialCall);
#endif

ApiStatus RotateModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 modelListIndex = get_model_list_index_from_tree_index(var1);
    f32 a = get_float_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    Model* model = get_model_from_list_index(modelListIndex);

    if ((model->flags & 0x400) == 0) {
        guRotateF(&model->transformMatrix, a, x, y, z);
        model->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guRotateF(&mtx, a, x, y, z);
        guMtxCatF(&mtx, &model->transformMatrix, &model->transformMatrix);
    }

    return ApiStatus_DONE2;
}

// Same as TranslateModel above
#ifdef NON_MATCHING
ApiStatus ScaleModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 modelListIndex = get_model_list_index_from_tree_index(var1);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    Model* model = get_model_from_list_index(modelListIndex);

    if ((model->flags & 0x400) == 0) {
        guScaleF(&model->transformMatrix, x, y, z);
        model->flags |= 0x1400;
    } else {
        Matrix4f mtx;

        guScaleF(&mtx, x, y, z);
        guMtxCatF(&mtx, &model->transformMatrix, &model->transformMatrix);
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "code_ED510", ScaleModel, ScriptInstance* script, s32 isInitialCall);
#endif

ApiStatus GetModelIndex(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode modelID = get_variable(script, *thisPos++);
    Bytecode index = *thisPos++;

    set_variable(script, index, get_model_list_index_from_tree_index(modelID));
    return ApiStatus_DONE2;
}

ApiStatus func_802C8EE4(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode modelID = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(modelID));

    model->flags &= ~0x400;
    return ApiStatus_DONE2;
}

ApiStatus CloneModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode srcModelID = get_variable(script, *thisPos++);
    Bytecode newModelID = get_variable(script, *thisPos++);

    clone_model(srcModelID, newModelID);
    return ApiStatus_DONE2;
}

ApiStatus GetModelCenter(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    f32 centerX;
    f32 centerY;
    f32 centerZ;
    f32 sizeX;
    f32 sizeY;
    f32 sizeZ;

    get_model_center_and_size(get_variable(script, *thisPos++) & 0xFFFF, &centerX, &centerY, &centerZ, &sizeX, &sizeY,
                              &sizeZ);
    script->varTable[0] = centerX;
    script->varTable[1] = centerY;
    script->varTable[2] = centerZ;
    return ApiStatus_DONE2;
}

ApiStatus SetTexPanner(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *thisPos++);
    s32 var2 = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    set_tex_panner(model, var2);
    model->flags |= 0x800;
    return ApiStatus_DONE2;
}

ApiStatus SetModelFlag10(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode treeIndex = get_variable(script, *thisPos++);
    Bytecode enable = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    if (enable) {
        model->flags |= 0x10;
    } else {
        model->flags &= ~0x10;
    }
    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING
ApiStatus func_802C90FC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *thisPos++);
    s32 var2 = get_variable(script, *thisPos++);
    s32 var3 = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    func_8011BC7C(model, var2, var3);
    if (var2 != -1) {
        model->flags |= 0x10;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "code_ED510", func_802C90FC);
#endif

ApiStatus func_802C91A4(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode treeIndex = get_variable(script, *thisPos++);
    Bytecode var2 = get_variable(script, *thisPos++);

    get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex))->unk_A9 = var2;
    return ApiStatus_DONE2;
}

ApiStatus EnableTexPanning(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *thisPos++);
    s32 flag = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    if (flag) {
        model->flags |= 0x800;
    } else {
        model->flags &= ~0x800;
    }
    return ApiStatus_DONE2;
}

ApiStatus EnableModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 listIndex = get_model_list_index_from_tree_index(get_variable(script, *thisPos++));
    Bytecode flag = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(listIndex);

    if (flag != 0) {
        model->flags &= ~0x2;
    } else {
        model->flags |= 0x2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetGroupEnabled(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var1 = get_variable(script, *thisPos++);
    Bytecode var2 = get_variable(script, *thisPos++);

    func_8011B7C0(var1, 2, var2);
    return ApiStatus_DONE2;
}

ApiStatus SetTexPanOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var1 = get_variable(script, *thisPos++);
    Bytecode var2 = get_variable(script, *thisPos++);
    Bytecode var3 = get_variable(script, *thisPos++);
    Bytecode var4 = get_variable(script, *thisPos++);

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
    Bytecode* thisPos = script->ptrReadPos;
    s32 var1 = get_variable(script, *thisPos++);
    s32 var2 = get_variable(script, *thisPos++);
    s32 var3 = get_variable(script, *thisPos++);

    func_8011BCB4(var1, var2, var3);
    return ApiStatus_DONE2;
}

ApiStatus func_802C94A0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 var1 = get_variable(script, *thisPos++);
    s32 var2 = get_variable(script, *thisPos++);
    s32 var3 = get_variable(script, *thisPos++);

    func_8011BCD0(var1, var2, var3);
    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING
ApiStatus SetModelFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *args++);
    s32 listIndex = get_model_list_index_from_tree_index(treeIndex);
    s32 a1 = *args++;
    s32 enable = get_variable(script, *args++);
    Model* model = get_model_from_list_index(listIndex);

    if (enable) {
        model->flags |= a1;
    } else {
        model->flags &= ~a1;
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "code_ED510", SetModelFlags, ScriptInstance* script, s32 isInitialCall);
#endif

INCLUDE_ASM(s32, "code_ED510", func_802C95A0);

ApiStatus func_802C971C(ScriptInstance* script, s32 isInitialCall) {
    func_8011B37C((u16)get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_802C9748(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    u16 var1 = get_variable(script, *thisPos++);
    s32 var2 = get_variable(script, *thisPos++);

    if (var2 != 0) {
        func_8011B5D0(var1);
    } else {
        func_8011B660(var1);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_ED510", TranslateGroup, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_ED510", RotateGroup, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_ED510", ScaleGroup, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802C9B40(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 var1 = get_variable(script, *thisPos++);
    Bytecode var2 = *thisPos++;

    set_variable(script, var2, func_8011B090(var1));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_ED510", EnableGroup, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802C9C70(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 var1 = get_variable(script, *thisPos++);
    u16 var2 = get_variable(script, *thisPos++);
    s32 var3 = get_variable(script, *thisPos++);

    func_8011C164(var1, var2, var3);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_ED510", modify_collider_family_flags);

INCLUDE_ASM(s32, "code_ED510", ModifyColliderFlags, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_ED510", ResetFromLava, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_ED510", func_802C9FD4);

ApiStatus GetColliderCenter(ScriptInstance* script, s32 isInitialCall) {
    f32 x, y, z;

    get_collider_center(get_variable(script, *script->ptrReadPos), &x, &y, &z);

    script->varTable[0] = x;
    script->varTable[1] = y;
    script->varTable[2] = z;

    return ApiStatus_DONE2;
}

ApiStatus ParentColliderToModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s16 colliderID = get_variable(script, *thisPos++);
    s32 treeIndex = get_variable(script, *thisPos++);

    parent_collider_to_model(colliderID, get_model_list_index_from_tree_index(treeIndex));
    update_collider_transform(colliderID);
    return ApiStatus_DONE2;
}

ApiStatus UpdateColliderTransform(ScriptInstance* script, s32 isInitialCall) {
    update_collider_transform(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_ED510", set_zone_enabled);

INCLUDE_ASM(s32, "code_ED510", SetZoneEnabled);

INCLUDE_ASM(s32, "code_ED510", goto_map);

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
    Bytecode* thisPos = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *thisPos++);
    s8 renderMode = get_variable(script, *thisPos++);

    get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex))->renderMode = renderMode;

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = get_variable(script, *args++);
    SoundID soundID = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    f32 x, y, z;
    f32 n1, n2, n3;

    get_model_center_and_size((u16)modelID, &x, &y, &z, &n1, &n2, &n3);
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
