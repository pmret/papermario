#include "common.h"
#include "entity.h"

extern VirtualEntityList bBattleVirtualEntityList;
extern VirtualEntityList wWorldVirtualEntityList;
extern VirtualEntityList* gCurrentVirtualEntityListPtr;

s32 create_worker_backUI(void (*updateFunc)(void), void (*drawFunc)(void));

void virtual_entity_appendGfx_quad(u8 r, u8 g, u8 b, u8 a, u16 left, u16 top, u16 right, u16 bottom) {
    gDPPipeSync(gMainGfxPos++);

    if (a == 0xFF) {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_08, PM_CC_08);
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    }

    gDPSetPrimColor(gMainGfxPos++, 0, 0, r, g, b, a);
    gDPFillRectangle(gMainGfxPos++, left, top, right, bottom);
    gDPPipeSync(gMainGfxPos++);
    gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
}

void virtual_entity_render_quad(s32 r, s32 g, s32 b, s32 a, s32 posX, s32 posY, s32 width, s32 height) {
    u16 endX = posX + width;
    u16 endY = posY + height;

    virtual_entity_appendGfx_quad(r, g, b, a, posX, posY, endX, endY);
}

void virtual_entity_move_polar(VirtualEntity* virtualEntity, f32 magnitude, f32 angle) {
    f32 theta = DEG_TO_RAD(angle);
    f32 sinTheta = sin_rad(theta);
    f32 cosTheta = cos_rad(theta);

    virtualEntity->pos.x += magnitude * sinTheta;
    virtualEntity->pos.z += -magnitude * cosTheta;
}

void virtual_entity_list_update(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentVirtualEntityListPtr); i++) {
        VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[i];

        if (virtualEntity != NULL && virtualEntity->entityModelIndex >= 0) {
            exec_entity_model_commandlist(virtualEntity->entityModelIndex);
        }
    }
}

void virtual_entity_list_render_world(void) {
    Matrix4f translation;
    Matrix4f xRot;
    Matrix4f yRot;
    Matrix4f zRot;
    Matrix4f rotation;
    Matrix4f temp;
    Matrix4f transform;
    Matrix4f scale;
    Mtx transformMtxL;
    VirtualEntity* virtualEntity;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentVirtualEntityListPtr); i++) {
        virtualEntity = (*gCurrentVirtualEntityListPtr)[i];
        if (virtualEntity != NULL) {
            if (!(virtualEntity->entityModelIndex < 0 || get_entity_model(virtualEntity->entityModelIndex)->flags & ENTITY_MODEL_FLAG_CAM3)) {
                guTranslateF(translation, virtualEntity->pos.x, virtualEntity->pos.y, virtualEntity->pos.z);
                guRotateF(xRot, virtualEntity->rot.x, 1.0f, 0.0f, 0.0f);
                guRotateF(yRot, virtualEntity->rot.y, 0.0f, 1.0f, 0.0f);
                guRotateF(zRot, virtualEntity->rot.z, 0.0f, 0.0f, 1.0f);
                guScaleF(scale, virtualEntity->scale.x, virtualEntity->scale.y, virtualEntity->scale.z);
                guMtxCatF(zRot, xRot, temp);
                guMtxCatF(temp, yRot, rotation);
                guMtxCatF(scale, rotation, temp);
                guMtxCatF(temp, translation, transform);
                guMtxF2L(transform, &transformMtxL);
                draw_entity_model_A(virtualEntity->entityModelIndex, &transformMtxL);
            }
        }
    }
}

void virtual_entity_list_render_UI(void) {
    Matrix4f translation;
    Matrix4f xRot;
    Matrix4f yRot;
    Matrix4f zRot;
    Matrix4f rotation;
    Matrix4f temp;
    Matrix4f transform;
    Matrix4f scale;
    Mtx transformMtxL;
    VirtualEntity* virtualEntity;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentVirtualEntityListPtr); i++) {
        virtualEntity = (*gCurrentVirtualEntityListPtr)[i];
        if (virtualEntity != NULL) {
            if (!(virtualEntity->entityModelIndex < 0 || !(get_entity_model(virtualEntity->entityModelIndex)->flags & ENTITY_MODEL_FLAG_CAM3))) {
                guTranslateF(translation, virtualEntity->pos.x, virtualEntity->pos.y, virtualEntity->pos.z);
                guRotateF(xRot, virtualEntity->rot.x, 1.0f, 0.0f, 0.0f);
                guRotateF(yRot, virtualEntity->rot.y, 0.0f, 1.0f, 0.0f);
                guRotateF(zRot, virtualEntity->rot.z, 0.0f, 0.0f, 1.0f);
                guScaleF(scale, virtualEntity->scale.x, virtualEntity->scale.y, virtualEntity->scale.z);
                guMtxCatF(zRot, xRot, temp);
                guMtxCatF(temp, yRot, rotation);
                guMtxCatF(scale, rotation, temp);
                guMtxCatF(temp, translation, transform);
                guMtxF2L(transform, &transformMtxL);
                draw_entity_model_E(virtualEntity->entityModelIndex, &transformMtxL);
            }
        }
    }
}

ApiStatus InitVirtualEntityList(Evt* script, s32 isInitialCall) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentVirtualEntityListPtr = &wWorldVirtualEntityList;
    } else {
        gCurrentVirtualEntityListPtr = &bBattleVirtualEntityList;
    }
    return ApiStatus_DONE2;
}

ApiStatus CreateVirtualEntityAt(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    EntityModelScript* cmdList = (EntityModelScript*) evt_get_variable(script, *args++);
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    virtualEntity->entityModelIndex = load_entity_model(cmdList);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;
    exec_entity_model_commandlist(virtualEntity->entityModelIndex);

    return ApiStatus_DONE2;
}

ApiStatus CreateVirtualEntity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    EntityModelScript* cmdList = (EntityModelScript*)evt_get_variable(script, *args++);
    VirtualEntity* virtualEntity;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentVirtualEntityListPtr); i++) {
        virtualEntity = (*gCurrentVirtualEntityListPtr)[i];
        if (virtualEntity->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*gCurrentVirtualEntityListPtr)) {
        return ApiStatus_DONE2;
    }

    virtualEntity->entityModelIndex = load_entity_model(cmdList);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;

    exec_entity_model_commandlist(virtualEntity->entityModelIndex);
    evt_set_variable(script, outVar, i);

    return ApiStatus_DONE2;
}

ApiStatus CreateVirtualEntity_ALT(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    EntityModelScript* cmdList = (EntityModelScript*) evt_get_variable(script, *args++);
    VirtualEntity* virtualEntity;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentVirtualEntityListPtr); i++) {
        virtualEntity = (*gCurrentVirtualEntityListPtr)[i];
        if (virtualEntity->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*gCurrentVirtualEntityListPtr)) {
        return ApiStatus_DONE2;
    }

    virtualEntity->entityModelIndex = ALT_load_entity_model(cmdList);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;

    exec_entity_model_commandlist(virtualEntity->entityModelIndex);
    evt_set_variable(script, outVar, i);

    return ApiStatus_DONE2;
}

ApiStatus DeleteVirtualEntity(Evt* script, s32 isInitialCall) {
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[evt_get_variable(script, *script->ptrReadPos)];

    free_entity_model_by_index(virtualEntity->entityModelIndex);
    virtualEntity->entityModelIndex = -1;
    return ApiStatus_DONE2;
}

ApiStatus SetVirtualEntityRenderCommands(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    EntityModelScript* cmdList = (EntityModelScript*) evt_get_variable(script, *args++);

    set_entity_model_render_command_list((*gCurrentVirtualEntityListPtr)[index]->entityModelIndex, cmdList);
    return ApiStatus_DONE2;
}

ApiStatus SetVirtualEntityPosition(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    virtualEntity->pos.x = x;
    virtualEntity->pos.y = y;
    virtualEntity->pos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus GetVirtualEntityPosition(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];
    s32 outVar1 = *args++;
    s32 outVar2 = *args++;
    s32 outVar3 = *args++;

    evt_set_variable(script, outVar1, virtualEntity->pos.x);
    evt_set_variable(script, outVar2, virtualEntity->pos.y);
    evt_set_variable(script, outVar3, virtualEntity->pos.z);
    return ApiStatus_DONE2;
}

ApiStatus SetVirtualEntityRotation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    virtualEntity->rot.x = x;
    virtualEntity->rot.y = y;
    virtualEntity->rot.z = z;
    return ApiStatus_DONE2;
}

ApiStatus SetVirtualEntityScale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    virtualEntity->scale.x = x;
    virtualEntity->scale.y = y;
    virtualEntity->scale.z = z;
    return ApiStatus_DONE2;
}

ApiStatus SetVirtualEntityMoveSpeed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    (*gCurrentVirtualEntityListPtr)[index]->moveSpeed = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus SetVirtualEntityJumpGravity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    (*gCurrentVirtualEntityListPtr)[index]->jumpGravity = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus VirtualEntityMoveTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    VirtualEntity* virtualEntity;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        s32 index = evt_get_variable(script, *args++);
        f32 xTemp = evt_get_variable(script, *args++);
        f32 yTemp = evt_get_variable(script, *args++);
        f32 zTemp = evt_get_variable(script, *args++);
        s32 moveTime = evt_get_variable(script, *args++);
        f32 goalPosX;
        f32 goalPosZ;

        virtualEntity = (*gCurrentVirtualEntityListPtr)[index];
        script->functionTemp[1] = index;

        virtualEntity->goalPos.x = xTemp;
        virtualEntity->goalPos.y = yTemp;
        virtualEntity->goalPos.z = zTemp;

        xTemp = virtualEntity->pos.x;
        zTemp = virtualEntity->pos.z;

        goalPosX = virtualEntity->goalPos.x;
        goalPosZ = virtualEntity->goalPos.z;

        virtualEntity->moveTime = moveTime;
        virtualEntity->moveAngle = atan2(xTemp, zTemp, goalPosX, goalPosZ);
        virtualEntity->moveDist = dist2D(xTemp, zTemp, goalPosX, goalPosZ);

        if (virtualEntity->moveTime == 0.0f) {
            virtualEntity->moveTime = virtualEntity->moveDist / virtualEntity->moveSpeed;
        } else {
            virtualEntity->moveSpeed = virtualEntity->moveDist / virtualEntity->moveTime;
        }

        script->functionTemp[0] = 1;
    }

    virtualEntity = (*gCurrentVirtualEntityListPtr)[script->functionTemp[1]];
    virtual_entity_move_polar(virtualEntity, virtualEntity->moveSpeed, virtualEntity->moveAngle);
    virtualEntity->moveTime--;

    if (virtualEntity->moveTime <= 0.0f) {
        virtualEntity->pos.x = virtualEntity->goalPos.x;
        virtualEntity->pos.z = virtualEntity->goalPos.z;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus VirtualEntityJumpTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    VirtualEntity* virtualEntity;
    s32 index;
    f32 xTemp;
    f32 yTemp;
    f32 zTemp;
    s32 moveTime;
    f32 goalPosX;
    f32 goalPosY;
    f32 goalPosZ;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        index = evt_get_variable(script, *args++);
        xTemp = evt_get_variable(script, *args++);
        yTemp = evt_get_variable(script, *args++);
        zTemp = evt_get_variable(script, *args++);
        moveTime = evt_get_variable(script, *args++);

        virtualEntity = (*gCurrentVirtualEntityListPtr)[index];
        script->functionTemp[1] = index;

        virtualEntity->goalPos.x = xTemp;
        virtualEntity->goalPos.y = yTemp;
        virtualEntity->goalPos.z = zTemp;

        xTemp = virtualEntity->pos.x;
        yTemp = virtualEntity->pos.y;
        zTemp = virtualEntity->pos.z;

        goalPosX = virtualEntity->goalPos.x;
        yTemp = virtualEntity->goalPos.y - yTemp;
        goalPosZ = virtualEntity->goalPos.z;


        virtualEntity->moveTime = moveTime;
        virtualEntity->moveAngle = atan2(xTemp, zTemp, goalPosX, goalPosZ);
        virtualEntity->moveDist = dist2D(xTemp, zTemp, goalPosX, goalPosZ);

        if (virtualEntity->moveTime == 0.0f) {
            virtualEntity->moveTime = virtualEntity->moveDist / virtualEntity->moveSpeed;
        } else {
            virtualEntity->moveSpeed = virtualEntity->moveDist / virtualEntity->moveTime;
        }

        virtualEntity->jumpVel = (virtualEntity->jumpGravity * virtualEntity->moveTime / 2) +
                                      (yTemp / virtualEntity->moveTime);
        script->functionTemp[0] = 1;
    }

    virtualEntity = (*gCurrentVirtualEntityListPtr)[script->functionTemp[1]];
    virtualEntity->pos.y += virtualEntity->jumpVel;
    virtualEntity->jumpVel -= virtualEntity->jumpGravity;

    virtual_entity_move_polar(virtualEntity, virtualEntity->moveSpeed, virtualEntity->moveAngle);

    virtualEntity->moveTime -= 1.0f;
    if (virtualEntity->moveTime <= 0.0f) {
        virtualEntity->pos.x = virtualEntity->goalPos.x;
        virtualEntity->pos.y = virtualEntity->goalPos.y;
        virtualEntity->pos.z = virtualEntity->goalPos.z;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus VirtualEntityLandJump(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    VirtualEntity* virtualEntity;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[0] = 1;
    }

    virtualEntity = (*gCurrentVirtualEntityListPtr)[script->functionTemp[1]];
    virtualEntity->pos.y += virtualEntity->jumpVel;
    virtualEntity->jumpVel -= virtualEntity->jumpGravity;

    virtual_entity_move_polar(virtualEntity, virtualEntity->moveSpeed, virtualEntity->moveAngle);

    if (virtualEntity->pos.y < 0.0f) {
        virtualEntity->pos.y = 0.0f;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus SetVirtualEntityFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 flags = *args++;
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    get_entity_model(virtualEntity->entityModelIndex)->flags = flags;
    return ApiStatus_DONE2;
}

ApiStatus SetVirtualEntityFlagBits(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 bits = *args++;
    s32 mode = evt_get_variable(script, *args++);
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    if (mode) {
        set_entity_model_flags(virtualEntity->entityModelIndex, bits);
    } else {
        clear_entity_model_flags(virtualEntity->entityModelIndex, bits);
    }

    return ApiStatus_DONE2;
}

ApiStatus SetVirtualEntityRenderMode(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 mode = evt_get_variable(script, *args++);
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];
    EntityModel* entityModel = get_entity_model(virtualEntity->entityModelIndex);

    switch (mode) {
        case -1:
            entityModel->renderMode = RENDER_MODE_SURFACE_OPA;
            break;
        case 0:
            entityModel->renderMode = RENDER_MODE_SURFACE_OPA;
            evt_get_variable(script, *args++);
            evt_get_variable(script, *args++);
            evt_get_variable(script, *args++);
            break;
        case 2:
            entityModel->renderMode = RENDER_MODE_ALPHATEST;
            evt_get_variable(script, *args++);
            evt_get_variable(script, *args++);
            evt_get_variable(script, *args++);
            break;
        case 3:
            entityModel->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            evt_get_variable(script, *args++);
            break;
        case 4:
            entityModel->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            evt_get_variable(script, *args++);
            evt_get_variable(script, *args++);
            evt_get_variable(script, *args++);
            evt_get_variable(script, *args++);
            break;
    }
    return ApiStatus_DONE2;
}

VirtualEntity* virtual_entity_get_by_index(s32 index) {
    return (*gCurrentVirtualEntityListPtr)[index];
}

VirtualEntity* virtual_entity_create_at_index(s32 index, EntityModelScript* entityModelData) {
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    virtualEntity->entityModelIndex = load_entity_model(entityModelData);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;
    exec_entity_model_commandlist(virtualEntity->entityModelIndex);

    return (*gCurrentVirtualEntityListPtr)[index];
}

s32 virtual_entity_create(EntityModelScript* cmdList) {
    s32 i;
    VirtualEntity* virtualEntity;

    for (i = 0; i < ARRAY_COUNT(*gCurrentVirtualEntityListPtr); i++) {
        virtualEntity = (*gCurrentVirtualEntityListPtr)[i];
        if (virtualEntity->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*gCurrentVirtualEntityListPtr)) {
        return 0;
    }

    virtualEntity->entityModelIndex = load_entity_model(cmdList);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;

    exec_entity_model_commandlist(virtualEntity->entityModelIndex);

    return i;
}

VirtualEntity* ALT_virtual_entity_create(EntityModelScript* cmdList) {
    s32 i;
    VirtualEntity* virtualEntity;

    for (i = 0; i < ARRAY_COUNT(*gCurrentVirtualEntityListPtr); i++) {
        virtualEntity = (*gCurrentVirtualEntityListPtr)[i];
        if (virtualEntity->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*gCurrentVirtualEntityListPtr)) {
        return NULL;
    }

    virtualEntity->entityModelIndex = ALT_load_entity_model(cmdList);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;

    exec_entity_model_commandlist(virtualEntity->entityModelIndex);

    return (*gCurrentVirtualEntityListPtr)[i];
}

void virtual_entity_set_pos(s32 index, s32 posX, s32 posY, s32 posZ) {
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    virtualEntity->pos.x = posX;
    virtualEntity->pos.y = posY;
    virtualEntity->pos.z = posZ;
}

void virtual_entity_set_scale(s32 index, f32 scaleX, f32 scaleY, f32 scaleZ) {
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    virtualEntity->scale.x = scaleX;
    virtualEntity->scale.y = scaleY;
    virtualEntity->scale.z = scaleZ;
}

void virtual_entity_set_rotation(s32 index, f32 angleX, f32 angleY, f32 angleZ) {
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    virtualEntity->rot.x = angleX;
    virtualEntity->rot.y = angleY;
    virtualEntity->rot.z = angleZ;
}

void virtual_entity_delete_by_index(s32 index) {
    VirtualEntity* virtualEntity = (*gCurrentVirtualEntityListPtr)[index];

    free_entity_model_by_index(virtualEntity->entityModelIndex);
    virtualEntity->entityModelIndex = -1;
}

void virtual_entity_delete_by_ref(VirtualEntity* obj) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentVirtualEntityListPtr); i++) {
        if ((*gCurrentVirtualEntityListPtr)[i] == obj) {
            virtual_entity_delete_by_index(i);
            return;
        }
    }
}

void clear_virtual_entity_list(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentVirtualEntityListPtr = &wWorldVirtualEntityList;
    } else {
        gCurrentVirtualEntityListPtr = &bBattleVirtualEntityList;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentVirtualEntityListPtr); i++) {
        (*gCurrentVirtualEntityListPtr)[i] = heap_malloc(sizeof(VirtualEntity));
        ASSERT((*gCurrentVirtualEntityListPtr)[i] != NULL);
        (*gCurrentVirtualEntityListPtr)[i]->entityModelIndex = -1;
    }

    create_worker_world(virtual_entity_list_update, virtual_entity_list_render_world);
    create_worker_backUI(NULL, virtual_entity_list_render_UI);
}

void init_virtual_entity_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentVirtualEntityListPtr = &wWorldVirtualEntityList;
    } else {
        gCurrentVirtualEntityListPtr = &bBattleVirtualEntityList;
    }
}
