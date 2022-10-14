#include "kmr_06.h"

typedef struct StickerData {
    /* 0x00 */ s32 folderID;
    /* 0x04 */ s32 workerID;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ f32 pitch;
    /* 0x18 */ f32 yaw;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ Vec3f goalPos;
    /* 0x34 */ f32 moveAngle;
    /* 0x38 */ f32 moveSpeed;
    /* 0x3C */ f32 fallSpeed;
    /* 0x40 */ f32 gravity;
    /* 0x44 */ s32 duration;
} StickerData;

API_CALLABLE(func_80241A68_8D2F78);
API_CALLABLE(func_802417E0_8D2CF0);

void N(appendGfx_sticker)(void* renderData) {
    FoldImageRecPart foldImage;
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    
    StickerData* sticker = (StickerData*) evt_get_variable(NULL, MapVar(10));
    IMG_PTR img = (IMG_PTR) evt_get_variable(NULL, MapVar(11));
    PAL_PTR pal = (PAL_PTR) evt_get_variable(NULL, MapVar(12));
    u32 foldFlags = FOLD_STATE_FLAG_400;
    
    gDPPipeSync(gMasterGfxPos++);
    guTranslateF(mtxTransform, sticker->pos.x, sticker->pos.y, sticker->pos.z);
    guRotateF(mtxTemp, sticker->yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guRotateF(mtxTemp, sticker->pitch, 1.0f, 0.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guScaleF(mtxTemp, sticker->scale.x, sticker->scale.y, sticker->scale.z);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    foldImage.raster = img;
    foldImage.palette = pal;
    foldImage.width = 32;
    foldImage.height = 32;
    foldImage.xOffset = -16;
    foldImage.yOffset = 16;
    foldImage.opacity = 255;
    
    if (sticker->yaw != 0.0 || sticker->pitch != 0.0) {
        foldFlags |= FOLD_STATE_FLAG_2000;
    }
    fold_update(0, 0, 0, 0, 0, 0, 0);
    fold_appendGfx_component(0, &foldImage, foldFlags, mtxTransform);
    
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

void N(worker_render_sticker)(void) {
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;

    renderTaskPtr->renderMode = RENDER_MODE_ALPHATEST;
    renderTaskPtr->appendGfxArg = 0;
    renderTaskPtr->appendGfx = &N(appendGfx_sticker);
    renderTaskPtr->distance = 0;
    queue_render_task(renderTaskPtr);
}

INCLUDE_ASM(s32, "world/area_kmr/kmr_06/kmr_06_5_sticker_sign", func_802417E0_8D2CF0);

API_CALLABLE(N(SetStickerPos)) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    StickerData* sticker = (StickerData*) evt_get_variable(script, MapVar(10));
    
    sticker->pos.x = x;
    sticker->pos.y = y;
    sticker->pos.z = z;
    return 2;
}

API_CALLABLE(N(SetStickerRotation)) {
    Bytecode* args = script->ptrReadPos;
    f32 pitch = evt_get_float_variable(script, *args++);
    f32 yaw = evt_get_float_variable(script, *args++);
    StickerData* sticker = (StickerData*) evt_get_variable(script, MapVar(10));

    sticker->pitch = pitch;
    sticker->yaw = yaw;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80241A68_8D2F78) {
    Bytecode* args = script->ptrReadPos;
    StickerData* data = (StickerData*) evt_get_variable(script, MapVar(10));
    f32 x, y, z, dist;
    
    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }
    
    if (script->functionTemp[0] == 0) {
        x = evt_get_float_variable(script, *args++);
        y = evt_get_float_variable(script, *args++) + 12.0f;
        z = evt_get_float_variable(script, *args++);
        data->goalPos.x = x;
        data->goalPos.y = y;
        data->goalPos.z = z;
        data->duration = evt_get_variable(script, *args++);
        dist = dist2D(data->pos.x, data->pos.z, data->goalPos.x, data->goalPos.z);
        data->moveAngle = atan2(data->pos.x, data->pos.z, data->goalPos.x, data->goalPos.z);

        y = data->goalPos.y - data->pos.y;
        if (data->duration == 0) {
            data->duration = dist / data->moveSpeed; //@bug moveSpeed is never assigned!
        } else {
            data->moveSpeed = dist / data->duration;
        }
       
        data->fallSpeed = (data->gravity * data->duration * 0.5f) + y / data->duration;
        script->functionTemp[0] = 1;
    }
    
    data->pos.x = data->pos.x + data->moveSpeed * sin_deg(data->moveAngle);
    data->pos.z = data->pos.z - data->moveSpeed * cos_deg(data->moveAngle);
    data->pos.y = data->pos.y + data->fallSpeed;
    data->fallSpeed -= data->gravity;
    
    data->duration--;
    if (data->duration < 0) {
        data->fallSpeed = 0.0f;
        data->pos.x = data->goalPos.x;
        data->pos.y = data->goalPos.y;
        data->pos.z = data->goalPos.z;
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80241C78_8D3188)) {
    Bytecode* args = script->ptrReadPos;
    f32 gravity = evt_get_float_variable(script, *args++);
    StickerData* data = (StickerData*) evt_get_variable(script, MapVar(10));
    
    data->gravity = gravity;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeleteSticker)) {
    StickerData* data = (StickerData*) evt_get_variable(script, MapVar(10));
    IMG_PTR img = (IMG_PTR) evt_get_variable(script, MapVar(11));
    PAL_PTR pal = (PAL_PTR) evt_get_variable(script, MapVar(12));

    free_generic_entity(data->workerID);

    heap_free(data);
    heap_free(img);
    heap_free(pal);

    evt_set_variable(script, MapVar(10), NULL);
    evt_set_variable(script, MapVar(11), NULL);
    evt_set_variable(script, MapVar(12), NULL);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnInspect_StickerSign) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Sign_EatMushroomsTip, 160, 40)
    EVT_IF_EQ(GF_KMR06_Item_Mushroom, FALSE)
        EVT_IF_EQ(MF_Unk_0A, FALSE)
            EVT_SET(MF_Unk_0A, TRUE)
            EVT_THREAD
                EVT_WAIT(2)
                EVT_SETF(LVar0, EVT_FLOAT(0.0))
                EVT_LOOP(18)
                    EVT_ADDF(LVar0, EVT_FLOAT(10.0))
                    EVT_CALL(N(SetStickerRotation), 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(N(SetStickerRotation), 0, 0)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(N(func_80241C78_8D3188), EVT_FLOAT(0.6))
                EVT_CALL(func_80241A68_8D2F78, 362, 0, 40, 23)
                EVT_CALL(N(DeleteSticker))
                EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 362, 0, 40, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR06_Item_Mushroom)
            EVT_END_THREAD
            EVT_WAIT(10)
        EVT_END_IF
    EVT_END_IF
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupStickerSign) = {
    EVT_IF_EQ(GF_KMR06_Item_Mushroom, FALSE)
        EVT_CALL(func_802417E0_8D2CF0, ITEM_MUSHROOM)
        EVT_CALL(N(SetStickerPos), 362, 40, -17)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnInspect_StickerSign)), TRIGGER_WALL_PRESS_A, COLLIDER_o852, 1, 0)
    EVT_RETURN
    EVT_END
};
