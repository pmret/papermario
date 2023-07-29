#include "common.h"
#include "sprite.h"
#include "entity.h"
#include "animation_script.h"
#include "ld_addrs.h"
#include "model.h"
#include "sprite/player.h"

extern Gfx Entity_RenderNone[];
extern AnimScript Entity_CymbalPlant_AnimationIdle;
extern AnimScript Entity_CymbalPlant_AnimationGrab;
extern AnimScript Entity_PinkFlower_AnimationLightUp;
extern StaticAnimatorNode* Entity_CymbalPlant_Mesh[];
extern EntityBlueprint Entity_PinkFlowerLight;
extern StaticAnimatorNode* Entity_PinkFlower_Mesh[];
extern AnimScript Entity_PinkFlower_AnimationIdle;
extern Mtx D_0A001098_E9C598;
extern Gfx D_0A0013B8_E9C8B8[];
extern Mtx D_0A000B70_E9D470;
extern Gfx D_0A000D18_E9D618[];
extern Gfx Entity_SpinningFlower_Render[];

BSS f32 D_802BCE20;
BSS f32 D_802BCE24[3]; // unused
BSS u16 D_802BCE30;
BSS u16 D_802BCE32;
BSS u16 D_802BCE34;

void entity_SpinningFlower_setupGfx(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    SpinningFlowerData* data = entity->dataBuf.spinningFlower;
    Gfx* gfxPos = gMainGfxPos;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Gfx* gfx;

    guMtxL2F(sp18, ENTITY_ADDR(entity, Mtx*, &D_0A000B70_E9D470));
    guRotateF(sp58, data->rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(sp98, data->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp58, sp98, sp98);
    guRotateF(sp58, data->rot.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp98, sp58, sp58);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &data->unk_30);
    gDisplayContext->matrixStack[gMatrixListPos] = data->unk_30;
    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gfx = ENTITY_ADDR(entity, Gfx*, D_0A000D18_E9D618);
    gSPDisplayList(gfxPos++, gfx);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);
    gMainGfxPos = gfxPos;
}

void func_802BB000_E2D930(Entity* entity) {
    SpinningFlowerData* data = entity->dataBuf.spinningFlower;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if ((entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) && !is_picking_up_item()) {
        if (playerStatus->actionState == ACTION_STATE_RIDE) {
            playerStatus->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
        } else if (playerStatus->actionState != ACTION_STATE_USE_SPINNING_FLOWER) {
            D_802BCE34 = data->unk_28;
            D_802BCE30 = data->unk_2A;
            D_802BCE32 = data->unk_2C;
            set_action_state(ACTION_STATE_USE_SPINNING_FLOWER);
        }
    }
}

void func_802BB0A0_E2D9D0(Entity* entity) {
    SpinningFlowerData* data = entity->dataBuf.spinningFlower;
    PlayerStatus* playerStatus = &gPlayerStatus;

    func_802BB000_E2D930(entity);
    switch (data->state) {
        case 0:
            data->unk_18 = 0;
            data->unk_00 = 0;
            data->state = 1;
            data->rot.x = 0.0f;
            data->rot.z = 0.0f;
            break;
        case 1:
            if (!(entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR)) {
                data->spinSpeed += 0.02;
                if (data->spinSpeed > 2.0) {
                    if (data->spinSpeed > 2.0) {
                        data->spinSpeed -= 0.4;
                    }
                }
            } else {
                data->spinSpeed += 0.8;
                if (data->spinSpeed > 14.0f) {
                    data->spinSpeed = 14.0f;
                }
            }
            break;
    }

    data->rot.y = clamp_angle(data->rot.y + data->spinSpeed);

    if (!(entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) &&
        (playerStatus->animFlags & PA_FLAG_SPINNING) &&
        fabs(dist2D(entity->pos.x, entity->pos.z, playerStatus->pos.x, playerStatus->pos.z)) < 60.0)
        {
        exec_entity_commandlist(entity);
    }
}

void func_802BB228_E2DB58(Entity* entity) {
    SpinningFlowerData* data = entity->dataBuf.spinningFlower;

    func_802BB000_E2D930(entity);
    data->spinSpeed += 2.0;
    if (data->spinSpeed > 40.0f) {
        data->spinSpeed = 40.0f;
    }
    data->rot.y = clamp_angle(data->rot.y + data->spinSpeed);
}

void entity_SpinningFlower_init(Entity* entity) {
    SpinningFlowerData* data = entity->dataBuf.spinningFlower;
    s32 x, y, z;

    x = CreateEntityVarArgBuffer[0];
    y = CreateEntityVarArgBuffer[1];
    z = CreateEntityVarArgBuffer[2];
    if (!(x | y | z)) {
        x = entity->pos.x;
        y = entity->pos.y + 100.0f;
        z = entity->pos.z;
    }

    data->unk_28 = x;
    data->unk_2A = y;
    data->unk_2C = z;
    data->state = 0;
    entity->renderSetupFunc = entity_SpinningFlower_setupGfx;
}

void func_802BB314_E2DC44(Entity* entity) {
    sfx_play_sound_at_position(SOUND_8000006A, SOUND_SPACE_MODE_0, entity->pos.x, entity->pos.y, entity->pos.z);
}

void func_802BB34C_E2DC7C(void) {
    sfx_play_sound(SOUND_391 | SOUND_ID_TRIGGER_CHANGE_SOUND);
    snd_stop_tracking_env_sound_pos(SOUND_391, TRUE);
}

void entity_PinkFlowerLight_setupGfx(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    PinkFlowerData* data = entity->dataBuf.pinkFlower;
    Gfx* gfxPos = gMainGfxPos;
    Matrix4f sp18;
    Matrix4f sp58;
    f32 sinAngle, cosAngle;

    guRotateF(sp58, entity->rot.y, 0.0f, 1.0f, 0.0f);
    guScaleF(sp18, entity->scale.x, entity->scale.x, entity->scale.x);
    guMtxCatF(sp18, sp58, sp58);
    guMtxL2F(sp18, ENTITY_ADDR(entity, Mtx*, &D_0A001098_E9C598));
    sin_cos_rad(DEG_TO_RAD(gCameras[CAM_DEFAULT].curYaw + 180.0f), &sinAngle, &cosAngle);
    sp18[3][1] += 10.0f;
    sp18[3][2] -= 10.0f;
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, entity->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp18, sp58, sp18);
    guRotateF(sp58, data->initialRotY, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp18, sp58, sp18);
    guTranslateF(sp58, entity->pos.x + 16.0f * sinAngle, entity->pos.y , entity->pos.z - 16.0f * cosAngle);
    guMtxCatF(sp18, sp58, sp18);
    gDPSetCombineMode(gfxPos++, PM_CC_01, PM_CC_02);
    gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, entity->alpha);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfxPos++, D_0A0013B8_E9C8B8);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);
    gMainGfxPos = gfxPos;
}

void entity_PinkFlower_idle(Entity* entity) {
    PinkFlowerData* data = entity->dataBuf.pinkFlower;

    if (gPlayerStatus.animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE
            && entity->collisionFlags & (ENTITY_COLLISION_PLAYER_TOUCH_WALL | ENTITY_COLLISION_PLAYER_HAMMER)) {
        if (entity->flags & ENTITY_FLAG_SHOWS_INSPECT_PROMPT) {
            entity->flags &= ~ENTITY_FLAG_SHOWS_INSPECT_PROMPT;
            data = get_entity_by_index(data->linkedEntityIndex)->dataBuf.pinkFlower;
            if (data->state == 0) {
                data->state = 1;
                exec_entity_commandlist(entity);
                play_model_animation(entity->virtualModelIndex, Entity_PinkFlower_AnimationLightUp);
            }
        }
    }
}

void entity_PinkFlower_init(Entity* entity) {
    PinkFlowerData* data = entity->dataBuf.pinkFlower;
    Entity* newEntity;
    s32 entityIndex;

    get_animator_by_index(entity->virtualModelIndex)->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    entityIndex = create_entity(&Entity_PinkFlowerLight, (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z, 0, MAKE_ENTITY_END);
    data->linkedEntityIndex = entityIndex;
    newEntity = get_entity_by_index(entityIndex);
    data = newEntity->dataBuf.pinkFlower;
    data->linkedEntityIndex = entity->listIndex;
    data->initialRotY = newEntity->rot.y;
}

void entity_PinkFlowerLight_init(Entity* entity) {
    entity->scale.x = 0.0f;
    entity->renderSetupFunc = entity_PinkFlowerLight_setupGfx;
}

void entity_PinkFlowerLight_idle(Entity* entity) {
    PinkFlowerData* data = entity->dataBuf.pinkFlower;

    switch (data->timer) {
        case 0:
            if (data->state != 0) {
                data->state = 0;
                data->timer++;
                entity->rot.z = -25.0f;
                entity->scale.x = 1.8f;
                entity->alpha = 255;
            }
            break;
        case 1:
            entity->rot.z += 1.0f;
            if (entity->rot.z >= 8.0f) {
                entity->rot.z = 8.0f;
            }

            entity->alpha -= 6;
            if (entity->alpha < 6) {
                entity->alpha = 6;
            }

            entity->scale.x -= 0.03;
            if (entity->scale.x <= 0.1) {
                data->timer = 0;
                entity->scale.x = 0.0f;
            }
            entity->scale.y = entity->scale.x;
            entity->scale.z = entity->scale.x;
            break;
    }

    data->initialRotY = get_entity_by_index(data->linkedEntityIndex)->rot.y;
    entity->rot.y = gCameras[CAM_DEFAULT].curYaw;
}

void func_802BB8D4_E2E204(Entity* entity) {
    CymbalPlantData* data = entity->dataBuf.cymbalPlant;
    data->dist = fabs(dist2D(entity->pos.x - 2.0f, entity->pos.z - 2.0f, gPlayerStatus.pos.x, gPlayerStatus.pos.z) * 0.25);
    data->angle = atan2(gPlayerStatus.pos.x, gPlayerStatus.pos.z, entity->pos.x - 2.0f, entity->pos.z - 2.0f);
}

void func_802BB98C_E2E2BC(Entity* entity) {
    CymbalPlantData* data = entity->dataBuf.cymbalPlant;
    gCameras[CAM_DEFAULT].targetPos.x = gPlayerStatus.pos.x;
    gCameras[CAM_DEFAULT].targetPos.y = gPlayerStatus.pos.y;
    gCameras[CAM_DEFAULT].targetPos.z = gPlayerStatus.pos.z;
    add_vec2D_polar(&gPlayerStatus.pos.x, &gPlayerStatus.pos.z, data->dist, data->angle);
}

void entity_CymbalPlant_idle(Entity* entity) {
    CymbalPlantData* data = entity->dataBuf.cymbalPlant;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw;
    f32 targetYaw;

    switch (data->state) {
        case 0:
            if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
                if (partnerStatus->actingPartner != 0) {
                    playerStatus->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
                }
                func_800EF300();
                playerStatus->animFlags |= PA_FLAG_INTERRUPT_SPIN;
                data->timer = 4;
                data->unk_01++;
                data->state++;
                disable_player_input();
                set_action_state(ACTION_STATE_IDLE);
                play_model_animation(entity->virtualModelIndex, Entity_CymbalPlant_AnimationGrab);
                sfx_play_sound(SOUND_F2);
                func_802BB8D4_E2E204(entity);
            } else {
                data->unk_01 = 0;
            }
            break;
        case 1:
            playerStatus->animFlags |= PA_FLAG_INTERRUPT_SPIN;
            if (--data->timer == 0) {
                start_rumble(128, 10);
                data->timer = 30;
                data->state++;
                yaw = playerStatus->spriteFacingAngle;
                playerStatus->spriteFacingAngle = 80.0f;
                playerStatus->flags |= PS_FLAG_ROTATION_LOCKED;
                D_802BCE20 = yaw;
            }
            func_802BB98C_E2E2BC(entity);
            break;
        case 2:
            if (--data->timer == 0) {
                data->state++;
                set_player_imgfx_comp(PLAYER_SPRITE_MAIN, -1, IMGFX_CLEAR, 0, 0, 0, 0, 0);
                set_player_imgfx_all(ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_CYMBAL_CRUSH, 1, 1, 0, 0);
            }
            break;
        case 3:
            data->state++;
            break;
        case 4:
            playerStatus->spriteFacingAngle = D_802BCE20;
            targetYaw = 270.0f;
            if (D_802BCE20 != 0.0f) {
                targetYaw = 90.0f;
            }
            playerStatus->targetYaw = targetYaw;
            data->timer = 80;
            data->state++;
            break;
        case 5:
            if (--data->timer == 0) {
                data->state++;
                set_player_imgfx_comp(PLAYER_SPRITE_MAIN, -1, IMGFX_CLEAR, 0, 0, 0, 0, 0);
                enable_player_input();
                playerStatus->flags &= ~PS_FLAG_ROTATION_LOCKED;
            }
            break;
        case 6:
            if (!(entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) && partnerStatus->partnerActionState == PARTNER_ACTION_NONE) {
                data->state = 0;
                enable_partner_ai();
                phys_adjust_cam_on_landing();
            }
            break;
    }
}

EntityScript Entity_SpinningFlower_Script = {
    es_SetCallback(func_802BB0A0_E2D9D0, 0)
    es_Call(func_802BB314_E2DC44)
    es_SetCallback(func_802BB228_E2DB58, 70)
    es_Call(func_802BB34C_E2DC7C)
    es_Restart
    es_End
};

EntityScript Entity_PinkFlower_Script = {
    es_SetCallback(entity_PinkFlower_idle, 0)
    es_PlaySound(SOUND_F4)
    es_SetCallback(NULL, 50)
    es_SetFlags(ENTITY_FLAG_SHOWS_INSPECT_PROMPT)
    es_Restart
    es_End
};

EntityScript Entity_PinkFlowerLight_Script = {
    es_SetCallback(entity_PinkFlowerLight_idle, 0)
    es_Restart
    es_End
};

EntityScript Entity_CymbalPlant_Update = {
    es_SetCallback(entity_CymbalPlant_idle, 0)
    es_End
};

EntityModelScript Entity_PinkFlowerLight_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_RenderNone, RENDER_MODE_SURFACE_XLU_LAYER2);
EntityModelScript Entity_SpinningFlower_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_SpinningFlower_Render, RENDER_MODE_SURFACE_XLU_LAYER1);

DmaEntry Entity_CymbalPlant_dma[] = { ENTITY_ROM(CymbalPlant_gfx), ENTITY_ROM(CymbalPlant_anim) };
DmaEntry Entity_PinkFlower_dma[] = { ENTITY_ROM(PinkFlower_gfx), ENTITY_ROM(PinkFlower_anim) };

EntityBlueprint Entity_CymbalPlant = {
    .flags = ENTITY_FLAG_SQUARE_SHADOW | ENTITY_FLAG_400 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(CymbalPlantData),
    .renderCommandList = Entity_CymbalPlant_AnimationIdle,
    .modelAnimationNodes = Entity_CymbalPlant_Mesh,
    .fpInit = NULL,
    .updateEntityScript = Entity_CymbalPlant_Update,
    .fpHandleCollision = NULL,
    { .dmaList = Entity_CymbalPlant_dma },
    .entityType = ENTITY_TYPE_CYMBAL_PLANT,
    .aabbSize = { 103, 30, 24 }
};

EntityBlueprint Entity_PinkFlower = {
    .flags = ENTITY_FLAG_SHOWS_INSPECT_PROMPT | ENTITY_FLAG_SQUARE_SHADOW | ENTITY_FLAG_400 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(PinkFlowerData),
    .renderCommandList = Entity_PinkFlower_AnimationIdle,
    .modelAnimationNodes = Entity_PinkFlower_Mesh,
    .fpInit = entity_PinkFlower_init,
    .updateEntityScript = Entity_PinkFlower_Script,
    .fpHandleCollision = NULL,
    { .dmaList = Entity_PinkFlower_dma },
    .entityType = ENTITY_TYPE_PINK_FLOWER,
    .aabbSize = { 44, 100, 25 }
};

EntityBlueprint Entity_PinkFlowerLight = {
    .flags = ENTITY_FLAG_SHOWS_INSPECT_PROMPT | ENTITY_FLAG_DISABLE_COLLISION,
    .typeDataSize = sizeof(PinkFlowerData),
    .renderCommandList = Entity_PinkFlowerLight_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_PinkFlowerLight_init,
    .updateEntityScript = Entity_PinkFlowerLight_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(PinkFlower_gfx) },
    .entityType = ENTITY_TYPE_PINK_FLOWER,
    .aabbSize = { 44, 100, 25 }
};

EntityBlueprint Entity_SpinningFlower = {
    .flags = 0,
    .typeDataSize = sizeof(SpinningFlowerData),
    .renderCommandList = Entity_SpinningFlower_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_SpinningFlower_init,
    .updateEntityScript = Entity_SpinningFlower_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(SpinningFlower) },
    .entityType = ENTITY_TYPE_SPINNING_FLOWER,
    .aabbSize = { 45, 22, 42 }
};
