#include "common.h"
#include "entity_script.h"
#include "effects.h"
#include "ld_addrs.h"

extern Gfx D_0A001FA0[];
extern Gfx D_0A001EF8[];
extern Gfx D_0A001690[];
extern Gfx D_0A001840[];
extern Gfx D_0A001AC8[];
extern Gfx D_0A001B70[];

extern Gfx D_0A002210_E5CD60[];
extern Gfx D_0A001FA0_E5CAF0[];
extern Mtx D_0A001EF8_E5CA48;

void entity_Padlock_setupGfx(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    PadlockData* data = entity->dataBuf.padlock;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Matrix4f spD8;

    guMtxIdentF(sp58);
    guMtxL2F(sp98, data->unk_14);
    guMtxCatF(sp58, sp98, sp98);
    sp98[3][0] += data->shacklePos;
    guRotateF(spD8, entity->rotation.x, -1.0f, 0.0f, 0.0f);
    guMtxCatF(spD8, sp98, sp98);
    guRotateF(spD8, entity->rotation.z, 0.0f, 0.0f, 1.0f);
    guRotateF(sp18, entity->rotation.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(spD8, sp18, sp18);
    guRotateF(spD8, entity->rotation.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp18, spD8, spD8);
    guMtxCatF(sp98, spD8, sp98);
    guScaleF(sp18, entity->scale.x, entity->scale.y, entity->scale.z);
    guMtxCatF(sp98, sp18, sp18);
    guTranslateF(sp58, entity->position.x, entity->position.y, entity->position.z);
    guMtxCatF(sp18, sp58, sp58);
    guMtxF2L(sp58, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, data->unk_18);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

void func_802BB044_E2B774(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PadlockData* data = entity->dataBuf.padlock;
    f32 deltaX, deltaZ;

    if (playerStatus->colliderHeight < fabs(playerStatus->position.y - entity->position.y)) {
        entity->flags |= ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX;
    } else {
        entity->flags &= ~ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX;
    }

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if (data->unk_00 == 0.0f) {
            suggest_player_anim_clearUnkFlag(0x10005);
        }

        data->unk_00 += 0.5;

        if (data->unk_00 >= 2.5) {
            data->unk_00 = 2.5f;
        }

        deltaX = data->unk_00 * sin_rad((180.0f - entity->rotation.y) * TAU / 360.0f);
        deltaZ = data->unk_00 * cos_rad((180.0f - entity->rotation.y) * TAU / 360.0f);

        playerStatus->position.x += deltaX;
        playerStatus->position.z -= deltaZ;
    } else {
        data->unk_00 = 0.0f;
    }
}

void entity_Padlock_idle(Entity* entity) {
    PadlockData* data = entity->dataBuf.padlock;

    switch (data->state) {
        case 0:
            func_802BB044_E2B774(entity);
            if (entity->flags & ENTITY_FLAGS_100000) {
                data->state++;
                sfx_play_sound(SOUND_269);
            }
            break;
        case 1:
            data->shacklePos += 5.0f;
            if (data->shacklePos >= 20.0f) {
                data->shacklePos = 20.0f;
                data->state++;
                entity->rotation.z += 12.0;
                data->fallSpeed = -2.0f;
                data->rotationSpeed = 0.2f;
            }
            break;
        case 2:
            data->rotationSpeed += 0.2;
            entity->rotation.x += data->rotationSpeed;

            data->fallSpeed -= 1.0;
            entity->position.y += data->fallSpeed;

            if (entity->position.y <= entity->shadowPosY) {
                entity->position.y = entity->shadowPosY;
                data->fallSpeed = 5.0f;
                data->rotationSpeed = 3.0f;
                data->state++;
                fx_sparkles(0, entity->position.x, entity->position.y + 25.0f, entity->position.z, 10.0f);
                entity->flags |= ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX;
            }
            break;
        case 3:
            data->rotationSpeed += 0.2;
            entity->rotation.x += data->rotationSpeed;

            data->fallSpeed -= 2.0;
            entity->position.y += data->fallSpeed;

            if (entity->position.y <= entity->shadowPosY) {
                entity->position.y = entity->shadowPosY;
                data->timer = 2;
                data->fallSpeed = 10.0f;
                data->rotationSpeed = 0.2f;
                data->state++;
                sfx_play_sound(SOUND_26A);
            }
            break;
        case 4:
            if (--data->timer <= 0) {
                data->state++;
            }
            break;
        case 5:
            data->rotationSpeed *= 2.0f;
            if (data->rotationSpeed > 30.0f) {
                data->rotationSpeed = 30.0f;
            }
            entity->rotation.x += data->rotationSpeed;
            if (entity->rotation.x >= 90.0) {
                entity->rotation.x = 90.0f;
                data->rotationSpeed = -20.0f;
                data->state++;
                sfx_play_sound(SOUND_26A);
            }
            break;
        case 6:
            data->rotationSpeed += 10.0f;
            if (data->rotationSpeed > 30.0f) {
                data->rotationSpeed = 30.0f;
            }
            entity->rotation.x += data->rotationSpeed;
            if (entity->rotation.x >= 90.0) {
                entity->rotation.x = 90.0f;
                data->timer = 5;
                data->state++;
                sfx_play_sound(SOUND_26A);
            }
            break;
        case 7:
            if (--data->timer <= 0) {
                data->state++;
                entity_start_script(entity);
                data->timer = 5;
            }
            break;
        case 8:
            if (--data->timer <= 0) {
                data->state++;
                entity->flags |= ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HIDDEN;
                exec_entity_commandlist(entity);
            }
            break;
    }

    if (data->state == 2 || data->state == 3 || data->state == 4 || data->state == 5 || data->state == 6 || data->state == 7 || data->state == 8) {
        data->blinkCounter++;
        if (data->blinkCounter & 1) {
            entity->flags |= ENTITY_FLAGS_HIDDEN;
        } else {
            entity->flags &= ~ENTITY_FLAGS_HIDDEN;
        }
    }
}

void entity_Padlock_init(Entity* entity) {
    PadlockData* data;

    entity->renderSetupFunc = entity_Padlock_setupGfx;
    data = entity->dataBuf.padlock;
    data->unk_14 = (Mtx*)((s32)entity->vertexData + (u16)&D_0A001EF8_E5CA48);
    data->unk_18 = D_0A001FA0_E5CAF0;
}

void entity_PadlockRedFrame_init(Entity* entity) {
    PadlockData* data;

    entity->renderSetupFunc = entity_Padlock_setupGfx;
    data = entity->dataBuf.padlock;
    data->unk_14 = (Mtx*)((s32)entity->vertexData + (u16)D_0A001690);
    data->unk_18 = D_0A001840;
}

void entity_PadlockRedFace_init(Entity* entity) {
    PadlockData* data;

    entity->renderSetupFunc = entity_Padlock_setupGfx;
    data = entity->dataBuf.padlock;
    data->unk_14 = (Mtx*)((s32)entity->vertexData + (u16)D_0A001AC8);
    data->unk_18 = D_0A001B70;
}

void entity_PadlockBlueFace_init(Entity* entity) {
    PadlockData* data;

    entity->renderSetupFunc = entity_Padlock_setupGfx;
    data = entity->dataBuf.padlock;
    data->unk_14 = (Mtx*)((s32)entity->vertexData + (u16)D_0A001AC8);
    data->unk_18 = D_0A001B70;
}

EntityScript D_802BCCE0_E2D410 = {
    es_SetCallback(entity_Padlock_idle, 0)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityModelScript D_802BCCF8_E2D428 = STANDARD_ENTITY_MODEL_SCRIPT(D_0A002210_E5CD60, RENDER_MODE_SURFACE_OPA);

EntityModelScript D_802BCD14_E2D444 = STANDARD_ENTITY_MODEL_SCRIPT(0x0A001990, RENDER_MODE_SURFACE_OPA);

EntityModelScript D_802BCD30_E2D460 = STANDARD_ENTITY_MODEL_SCRIPT(0x0A001E00, RENDER_MODE_SURFACE_OPA);

EntityModelScript D_802BCD4C_E2D47C = STANDARD_ENTITY_MODEL_SCRIPT(0x0A001E00, RENDER_MODE_SURFACE_OPA);

EntityBlueprint D_802BCD68_E2D498 = {
    .flags = ENTITY_FLAGS_SHOWS_INSPECT_PROMPT | ENTITY_FLAGS_400 | ENTITY_FLAGS_100,
    .typeDataSize = 0x1C,
    .renderCommandList = D_802BCCF8_E2D428,
    .modelAnimationNodes = 0x00000000,
    .fpInit = entity_Padlock_init,
    .updateEntityScript = D_802BCCE0_E2D410,
    .fpHandleCollision = 0x00000000,
    {{ entity_model_Padlock_ROM_START, entity_model_Padlock_ROM_END }},
    .entityType = ENTITY_TYPE_PADLOCK,
    .aabbSize = { 30, 175, 10 }
};

EntityBlueprint D_802BCD8C_E2D4BC = {
    .flags = ENTITY_FLAGS_SHOWS_INSPECT_PROMPT | ENTITY_FLAGS_400 | ENTITY_FLAGS_100,
    .typeDataSize = 0x1C,
    .renderCommandList = D_802BCD14_E2D444,
    .modelAnimationNodes = 0x00000000,
    .fpInit = entity_PadlockRedFrame_init,
    .updateEntityScript = D_802BCCE0_E2D410,
    .fpHandleCollision = 0x00000000,
    {{ 0x00E5CD80, 0x00E5E730 }},
    .entityType = ENTITY_TYPE_PADLOCK_RED_FRAME,
    .aabbSize = { 30, 175, 10 }
};

EntityBlueprint D_802BCDB0_E2D4E0 = {
    .flags = ENTITY_FLAGS_SHOWS_INSPECT_PROMPT | ENTITY_FLAGS_400 | ENTITY_FLAGS_100,
    .typeDataSize = 0x1C,
    .renderCommandList = D_802BCD30_E2D460,
    .modelAnimationNodes = 0x00000000,
    .fpInit = entity_PadlockRedFace_init,
    .updateEntityScript = D_802BCCE0_E2D410,
    .fpHandleCollision = 0x00000000,
    {{ 0x00E5E730, 0x00E60550 }},
    .entityType = ENTITY_TYPE_PADLOCK_RED_FACE,
    .aabbSize = { 30, 175, 10 }
 };

EntityBlueprint D_802BCDD4_E2D504 = {
    .flags = ENTITY_FLAGS_SHOWS_INSPECT_PROMPT | ENTITY_FLAGS_400 | ENTITY_FLAGS_100,
    .typeDataSize = 0x1C,
    .renderCommandList = D_802BCD4C_E2D47C,
    .modelAnimationNodes = 0x00000000,
    .fpInit = entity_PadlockBlueFace_init,
    .updateEntityScript = D_802BCCE0_E2D410,
    .fpHandleCollision = 0x00000000,
    {{ 0x00E60550, 0x00E62370 }},
    .entityType = ENTITY_TYPE_PADLOCK_BLUE_FACE,
    .aabbSize = { 30, 175, 10 }
};
