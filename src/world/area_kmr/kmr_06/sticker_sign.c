#include "kmr_06.h"
#include "ld_addrs.h"

extern s32 gItemIconRasterOffsets[];
extern s32 gItemIconPaletteOffsets[];

typedef struct StickerData {
    /* 0x00 */ s32 imgfxIdx;
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

void N(appendGfx_sticker)(void* renderData) {
    ImgFXTexture ifxImg;
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;

    StickerData* sticker = (StickerData*) evt_get_variable(NULL, MV_StickerData);
    IMG_PTR img = (IMG_PTR) evt_get_variable(NULL, MV_StickerImage);
    PAL_PTR pal = (PAL_PTR) evt_get_variable(NULL, MV_StickerPalette);
    u32 imgfxFlags = IMGFX_FLAG_400;

    gDPPipeSync(gMainGfxPos++);
    guTranslateF(mtxTransform, sticker->pos.x, sticker->pos.y, sticker->pos.z);
    guRotateF(mtxTemp, sticker->yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guRotateF(mtxTemp, sticker->pitch, 1.0f, 0.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guScaleF(mtxTemp, sticker->scale.x, sticker->scale.y, sticker->scale.z);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    ifxImg.raster = img;
    ifxImg.palette = pal;
    ifxImg.width = 32;
    ifxImg.height = 32;
    ifxImg.xOffset = -16;
    ifxImg.yOffset = 16;
    ifxImg.alpha = 255;

    if (sticker->yaw != 0.0 || sticker->pitch != 0.0) {
        imgfxFlags |= IMGFX_FLAG_2000;
    }
    imgfx_update(0, IMGFX_CLEAR, 0, 0, 0, 0, 0);
    imgfx_appendGfx_component(0, &ifxImg, imgfxFlags, mtxTransform);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void N(worker_render_sticker)(void) {
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;

    renderTaskPtr->renderMode = RENDER_MODE_ALPHATEST;
    renderTaskPtr->appendGfxArg = 0;
    renderTaskPtr->appendGfx = &N(appendGfx_sticker);
    renderTaskPtr->dist = 0;
    queue_render_task(renderTaskPtr);
}

API_CALLABLE(N(CreateSticker)) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);

    StickerData* sticker = (StickerData*) heap_malloc(sizeof(*sticker));
    IMG_PTR iconImg = heap_malloc(0x200);
    PAL_PTR iconPal = heap_malloc(0x20);

    s32 iconBase = (s32) icon_ROM_START;
    s32 iconImgEnd = iconBase + 0x200;
    s32 iconPalEnd = iconBase + 0x20;

    sticker->pos.x = 0.0f;
    sticker->pos.y = 0.0f;
    sticker->pos.z = 0.0f;
    sticker->pitch = 0.0f;
    sticker->yaw = 0.0f;
    sticker->goalPos.x = 0.0f;
    sticker->goalPos.y = 0.0f;
    sticker->goalPos.z = 0.0f;
    sticker->moveAngle = 0.0f;
    sticker->moveSpeed = 0.0f;
    sticker->fallSpeed = 0.0f;
    sticker->gravity = 0.0f;
    sticker->scale.x = 1.0f;
    sticker->scale.y = 1.0f;
    sticker->scale.z = 1.0f;

    sticker->duration = 0;
    dma_copy(
        (u8*) (iconBase + gItemIconRasterOffsets[itemID]),
        (u8*) (iconImgEnd + gItemIconRasterOffsets[itemID]),
        iconImg);
    dma_copy(
        (u8*) (iconBase + gItemIconPaletteOffsets[itemID]),
        (u8*) (iconPalEnd + gItemIconPaletteOffsets[itemID]),
        iconPal);

    sticker->imgfxIdx = imgfx_get_free_instances(1);
    sticker->workerID = create_worker_scene(NULL, N(worker_render_sticker));
    evt_set_variable(script, MV_StickerData, (s32) sticker);
    evt_set_variable(script, MV_StickerImage, (s32) iconImg);
    evt_set_variable(script, MV_StickerPalette, (s32) iconPal);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetStickerPos)) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    StickerData* sticker = (StickerData*) evt_get_variable(script, MV_StickerData);

    sticker->pos.x = x;
    sticker->pos.y = y;
    sticker->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetStickerRotation)) {
    Bytecode* args = script->ptrReadPos;
    f32 pitch = evt_get_float_variable(script, *args++);
    f32 yaw = evt_get_float_variable(script, *args++);
    StickerData* sticker = (StickerData*) evt_get_variable(script, MV_StickerData);

    sticker->pitch = pitch;
    sticker->yaw = yaw;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(JumpStickerTo)) {
    Bytecode* args = script->ptrReadPos;
    StickerData* data = (StickerData*) evt_get_variable(script, MV_StickerData);
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
            // oversight here:
            // moveSpeed is initialized to zero and never changed except in prior calls to JumpStickerTo
            // this will cause a divide by zero if duration = 0 is used for the first call
            data->duration = dist / data->moveSpeed;
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

API_CALLABLE(N(SetStickerGravity)) {
    Bytecode* args = script->ptrReadPos;
    f32 gravity = evt_get_float_variable(script, *args++);
    StickerData* data = (StickerData*) evt_get_variable(script, MV_StickerData);

    data->gravity = gravity;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeleteSticker)) {
    StickerData* data = (StickerData*) evt_get_variable(script, MV_StickerData);
    IMG_PTR img = (IMG_PTR) evt_get_variable(script, MV_StickerImage);
    PAL_PTR pal = (PAL_PTR) evt_get_variable(script, MV_StickerPalette);

    free_worker(data->workerID);

    heap_free(data);
    heap_free(img);
    heap_free(pal);

    evt_set_variable(script, MV_StickerData, NULL);
    evt_set_variable(script, MV_StickerImage, NULL);
    evt_set_variable(script, MV_StickerPalette, NULL);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnInspect_StickerSign) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    SuspendGroup(EVT_GROUP_FLAG_INTERACT)
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_Sign_EatMushroomsTip, 160, 40)
    IfEq(GF_KMR06_Item_Mushroom, FALSE)
        IfEq(AF_JAN01_TreeDrop_StarPiece, FALSE)
            Set(AF_JAN01_TreeDrop_StarPiece, TRUE)
            Thread
                Wait(2)
                SetF(LVar0, Float(0.0))
                Loop(18)
                    AddF(LVar0, Float(10.0))
                    Call(N(SetStickerRotation), 0, LVar0)
                    Wait(1)
                EndLoop
                Call(N(SetStickerRotation), 0, 0)
            EndThread
            Thread
                Call(N(SetStickerGravity), Float(0.6))
                Call(N(JumpStickerTo), 362, 0, 40, 23)
                Call(N(DeleteSticker))
                Call(MakeItemEntity, ITEM_MUSHROOM, 362, 0, 40, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR06_Item_Mushroom)
            EndThread
            Wait(10)
        EndIf
    EndIf
    ResumeGroup(EVT_GROUP_FLAG_INTERACT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupStickerSign) = {
    IfEq(GF_KMR06_Item_Mushroom, FALSE)
        Call(N(CreateSticker), ITEM_MUSHROOM)
        Call(N(SetStickerPos), 362, 40, -17)
    EndIf
    BindTrigger(Ref(N(EVS_OnInspect_StickerSign)), TRIGGER_WALL_PRESS_A, COLLIDER_o852, 1, 0)
    Return
    End
};
