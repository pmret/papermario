#include "common.h"
#include "entity.h"
#include "ld_addrs.h"

extern Gfx Entity_ArrowSign_Render[];
extern Gfx Entity_ArrowSign_RenderRotatedSign[];
extern Mtx Entity_ArrowSign_mtxSign;

void entity_ArrowSign_setupGfx(s32 entityIndex) {
    Gfx* gfxPos = gMainGfxPos;
    Entity* entity = get_entity_by_index(entityIndex);
    ArrowSignData* data = entity->dataBuf.arrowSign;
    Matrix4f sp18;
    Matrix4f sp58;
    Gfx* gfx;

    guMtxL2F(sp18, ENTITY_ADDR(entity, Mtx*, &Entity_ArrowSign_mtxSign));
    guRotateF(sp58, clamp_angle(data->angle - 90.0f), 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gfx = ENTITY_ADDR(entity, Gfx*, Entity_ArrowSign_RenderRotatedSign);
    gSPDisplayList(gfxPos++, gfx);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);
    gMainGfxPos = gfxPos;
}

void entity_ArrowSign_idle(void) {
}

void entity_ArrowSign_init(Entity* entity) {
    f32 angle = CreateEntityVarArgBuffer[0];
    ArrowSignData* data = entity->dataBuf.arrowSign;

    data->angle = angle;
    data->unk_08 = angle;
    entity->renderSetupFunc = entity_ArrowSign_setupGfx;
}

s32 entity_ArrowSign_handle_collision(Entity* entity) {
    if (!(gPlayerStatus.animFlags & PA_FLAG_USING_WATT) &&
        (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_WALL)) {
        entity_start_script(entity);
    }
}

EntityScript Entity_ArrowSign_Script = {
    es_SetCallback(entity_ArrowSign_idle, 0)
    es_End
};

EntityModelScript Entity_ArrowSign_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_ArrowSign_Render, RENDER_MODE_SURFACE_OPA);

EntityBlueprint Entity_ArrowSign = {
    .flags = ENTITY_FLAG_CIRCULAR_SHADOW | ENTITY_FLAG_400 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(ArrowSignData),
    .renderCommandList = Entity_ArrowSign_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_ArrowSign_init,
    .updateEntityScript = Entity_ArrowSign_Script,
    .fpHandleCollision = entity_ArrowSign_handle_collision,
    { .dma = ENTITY_ROM(ArrowSign) },
    .entityType = ENTITY_TYPE_RED_ARROW_SIGNS,
    .aabbSize = { 18, 50, 10 }
};
