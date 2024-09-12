#include "common.h"
#include "effects.h"
#include "ld_addrs.h"
#include "entity.h"

#define REFLECTED_SWITCH_HIDDEN 1
#define REFLECTED_SWITCH_LINKED 2

extern Gfx Entity_RedSwitch_Render[];
extern Gfx Entity_BlueSwitch_Render[];
extern Gfx Entity_GreenStompSwitch_Render[];

BSS Entity* SwitchToLink;

void entity_GreenStompSwitch_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SwitchData* data = entity->dataBuf.swtch;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if ((playerStatus->actionState == ACTION_STATE_SPIN_POUND)
            || (playerStatus->actionState == ACTION_STATE_TORNADO_POUND)) {
            exec_entity_commandlist(entity);
            data->greenMotionTimer = 8;
        }
    }
}

void entity_GreenStompSwitch_retract(Entity* entity) {
    SwitchData* data = entity->dataBuf.swtch;
    u16 curTime = data->greenMotionTimer--;

    if (curTime != 0) {
        entity->pos.y -= 1.8625;
        return;
    }
    entity_start_script(entity);
    exec_entity_commandlist(entity);
    data->greenMotionTimer = 8;
}

void entity_GreenStompSwitch_extend(Entity* entity) {
    SwitchData* data = entity->dataBuf.swtch;
    u16 curTime = data->greenMotionTimer--;

    if (curTime != 0) {
        entity->pos.y += 1.8625;
        return;
    }
    exec_entity_commandlist(entity);
    data->greenMotionTimer = 8;
}

void entity_switch_fall_down(Entity* entity) {
    SwitchData* data = entity->dataBuf.swtch;
    f32 hitDepth = 10.0f;
    f32 x = entity->pos.x;
    f32 y = entity->pos.y;
    f32 z = entity->pos.z;
    f32 hitYaw;
    f32 hitPitch;

    entity_raycast_down(&x, &y, &z, &hitYaw, &hitPitch, &hitDepth);

    if (entity->pos.y != y && entity->pos.y > y) {
        f32 fallVelocity = data->fallVel;

        fallVelocity += 0.5;
        data->fallVel = fallVelocity;
        entity->pos.y -= fallVelocity;
        if (entity->pos.y < y) {
            entity->pos.y = y;
        }
    }
}

void entity_HugeBlueSwitch_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if ((playerStatus->actionState == ACTION_STATE_SPIN_POUND)
            || (playerStatus->actionState == ACTION_STATE_TORNADO_POUND)) {
            exec_entity_commandlist(entity);
        }
    }
}

void entity_small_switch_idle(Entity* entity) {
    SwitchData* data = entity->dataBuf.swtch;
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;

    entity_switch_fall_down(entity);

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_HAMMER) {
        if (playerStatus->actionState == ACTION_STATE_HAMMER) {
            if (gPlayerData.hammerLevel < 0) {
                return;
            }
            exec_entity_commandlist(entity);

            if (data->linkedSwitch == NULL) {
                return;
            }

            exec_entity_commandlist(data->linkedSwitch);
            return;
        }
    }

    if (playerStatus->actionState == ACTION_STATE_SPIN_JUMP) {
        return;
    }

    if (partnerStatus->actingPartner == PARTNER_PARAKARRY && partnerStatus->partnerActionState != PARTNER_ACTION_NONE) {
        return;
    }

    if (!(entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR)) {
        if (!(entity->collisionFlags & ENTITY_COLLISION_PARTNER)) {
            return;
        }
    }

    exec_entity_commandlist(entity);

    if (data->linkedSwitch == NULL) {
        return;
    }

    exec_entity_commandlist(data->linkedSwitch);
}

void entity_RedSwitch_wait_and_reset(Entity* entity) {
    if (!(entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR)) {
        exec_entity_commandlist(entity);
    }
}

void entity_base_switch_anim_init(Entity* entity) {
    SwitchData* data = entity->dataBuf.swtch;

    data->fallVel = 1.0f;
    data->deltaScaleX = 0.1f;
    data->deltaScaleY = -0.1f;
    data->animStateScaleX = 0;
    data->animStateScaleY = 0;
}

s32 entity_RedSwitch_animate_scale(Entity* entity) {
    f32 phi_f4;
    f32 temp_f6;
    SwitchData* data = entity->dataBuf.swtch;
    s32 phi_s2 = 0;

    switch (data->animStateScaleX) {
        case 0:
            temp_f6 = data->baseScale.z * 0.3;
            phi_f4 = ((data->baseScale.x + temp_f6) - entity->scale.x) / 4.0;
            if (phi_f4 < 0.01) {
                phi_f4 = 0.01f;
            }
            data->deltaScaleX += phi_f4;
            entity->scale.x += data->deltaScaleX;
            if ((data->baseScale.x + temp_f6) <= entity->scale.x) {
                data->deltaScaleX = 0.0f;
                data->animStateScaleX++;
            }
            break;
        case 1:
            temp_f6 = data->baseScale.z * -0.2;
            phi_f4 = ((data->baseScale.x + temp_f6) - entity->scale.x) / 6.0;
            if (phi_f4 > -0.01) {
                phi_f4 = -0.01f;
            }
            data->deltaScaleX += phi_f4;
            entity->scale.x += data->deltaScaleX;
            if (entity->scale.x <= (data->baseScale.x + temp_f6)) {
                data->deltaScaleX = 0.0f;
                data->animStateScaleX++;
            }
            break;
        case 2:
            temp_f6 = data->baseScale.z * 0.15;
            phi_f4 = ((data->baseScale.x + temp_f6) - entity->scale.x) / 4.0;
            if (phi_f4 < 0.01) {
                phi_f4 = 0.01f;
            }
            data->deltaScaleX += phi_f4;
            entity->scale.x += data->deltaScaleX;
            if ((data->baseScale.x + temp_f6) <= entity->scale.x) {
                data->deltaScaleX = 0.0f;
                data->animStateScaleX++;
            }
            break;
        case 3:
            temp_f6 = data->baseScale.z * -0.1;
            phi_f4 = ((data->baseScale.x + temp_f6) - entity->scale.x) / 6.0;
            if (phi_f4 > -0.01) {
                phi_f4 = -0.01f;
            }
            data->deltaScaleX += phi_f4;
            entity->scale.x += data->deltaScaleX;
            if (entity->scale.x <= (data->baseScale.x + temp_f6)) {
                data->deltaScaleX = 0.0f;
                data->animStateScaleX++;
            }
            break;
        case 4:
            phi_f4 = (data->baseScale.x - entity->scale.x) / 4.0;
            if (phi_f4 < 0.01) {
                phi_f4 = 0.01f;
            }
            data->deltaScaleX += phi_f4;
            entity->scale.x += data->deltaScaleX;
            if (data->baseScale.x <= entity->scale.x) {
                entity->scale.x = data->baseScale.x;
                data->deltaScaleX = 0.0f;
                data->animStateScaleX++;
            }
            break;
        case 5:
            phi_s2++;
            break;
    }

    entity->scale.z = entity->scale.x;

    switch (data->animStateScaleY) {
        case 0:
            temp_f6 = data->baseScale.z * -0.5;
            phi_f4 = ((data->baseScale.y + temp_f6) - entity->scale.y) / 5.0;
            if (phi_f4 > -0.01) {
                phi_f4 = -0.01f;
            }
            data->deltaScaleY += phi_f4;
            entity->scale.y += data->deltaScaleY;
            if (entity->scale.y <= (data->baseScale.y + temp_f6)) {
                data->deltaScaleY = 0.0f;
                data->animStateScaleY++;
            }
            break;
        case 1:
            temp_f6 = data->baseScale.z * 0.1;
            phi_f4 = ((data->baseScale.y + temp_f6) - entity->scale.y) / 10.0;
            if (phi_f4 < 0.01) {
                phi_f4 = 0.01f;
            }
            data->deltaScaleY += phi_f4;
            entity->scale.y += data->deltaScaleY;
            if ((data->baseScale.y + temp_f6) <= entity->scale.y) {
                data->deltaScaleY = 0.0f;
                data->animStateScaleY++;
            }
            break;
        case 2:
            temp_f6 = data->baseScale.z * -0.3;
            phi_f4 = ((data->baseScale.y + temp_f6) - entity->scale.y) / 5.0;
            if (phi_f4 > -0.01) {
                phi_f4 = -0.01f;
            }
            data->deltaScaleY += phi_f4;
            entity->scale.y += data->deltaScaleY;
            if (entity->scale.y <= (data->baseScale.y + temp_f6)) {
                data->deltaScaleY = 0.0f;
                data->animStateScaleY++;
            }
            break;
        case 3:
            temp_f6 = data->baseScale.z * 0.0;
            phi_f4 = ((data->baseScale.y + temp_f6) - entity->scale.y) / 10.0;
            if (phi_f4 < 0.01) {
                phi_f4 = 0.01f;
            }
            data->deltaScaleY += phi_f4;
            entity->scale.y += data->deltaScaleY;
            if ((data->baseScale.y + temp_f6) <= entity->scale.y) {
                data->deltaScaleY = 0.0f;
                data->animStateScaleY++;
            }
            break;
        case 4:
            phi_f4 = (data->baseScale.y - entity->scale.y) / 5.0;
            if (phi_f4 > -0.01) {
                phi_f4 = -0.01f;
            }
            data->deltaScaleY += phi_f4;
            entity->scale.y += data->deltaScaleY;
            if (entity->scale.y <= data->baseScale.y) {
                entity->scale.y = data->baseScale.y;
                data->deltaScaleY = 0.0f;
                data->animStateScaleY++;
            }
            break;
        case 5:
            phi_s2++;
            break;
    }

    entity_switch_fall_down(entity);
    if (phi_s2 == 2) {
        data->animStateScaleX = 0;
        data->animStateScaleY = 0;
        exec_entity_commandlist(entity);
    }
}

void entity_base_switch_start_bound_script(Entity* entity) {
    SwitchData* data = entity->dataBuf.swtch;
    set_area_flag(data->areaFlagIndex);
    entity_start_script(entity);
}

void entity_base_switch_animate_scale(Entity* entity) {
    f32 phi_f4;
    f32 scaleChange;
    SwitchData* data = entity->dataBuf.swtch;
    s32 phi_s2 = 0;

    switch (data->animStateScaleX) {
        case 0:
            scaleChange = data->baseScale.z * 0.3;
            phi_f4 = ((data->baseScale.x + scaleChange) - entity->scale.x) / 4.0;
            if (phi_f4 < 0.01) {
                phi_f4 = 0.01f;
            }
            data->deltaScaleX += phi_f4;
            entity->scale.x += data->deltaScaleX;
            if ((data->baseScale.x + scaleChange) <= entity->scale.x) {
                data->deltaScaleX = 0.0f;
                data->animStateScaleX++;
            }
            break;
        case 1:
            scaleChange = (data->baseScale.z * -0.2);
            phi_f4 = ((data->baseScale.x + scaleChange) - entity->scale.x) / 6.0;
            if (phi_f4 > -0.01) {
                phi_f4 = -0.01f;
            }
            data->deltaScaleX += phi_f4;
            entity->scale.x += data->deltaScaleX;
            if (entity->scale.x <= (data->baseScale.x + scaleChange)) {
                data->deltaScaleX = 0.0f;
                data->animStateScaleX++;
            }
            break;
        case 2:
            scaleChange = data->baseScale.z * 0.15;
            phi_f4 = ((data->baseScale.x + scaleChange) - entity->scale.x) / 4.0;
            if (phi_f4 < 0.01) {
                phi_f4 = 0.01f;
            }
            data->deltaScaleX += phi_f4;
            entity->scale.x += data->deltaScaleX;
            if ((data->baseScale.x + scaleChange) <= entity->scale.x) {
                data->deltaScaleX = 0.0f;
                data->animStateScaleX++;
            }
            break;
        case 3:
            scaleChange = data->baseScale.z * -0.1;
            phi_f4 = ((data->baseScale.x + scaleChange) - entity->scale.x) / 6.0;
            if (phi_f4 > -0.01) {
                phi_f4 = -0.01f;
            }
            data->deltaScaleX += phi_f4;
            entity->scale.x += data->deltaScaleX;
            if (entity->scale.x <= (data->baseScale.x + scaleChange)) {
                data->deltaScaleX = 0.0f;
                data->animStateScaleX++;
            }
            break;
        case 4:
            phi_s2++;
            break;
    }

    entity->scale.z = entity->scale.x;

    switch (data->animStateScaleY) {
        case 0:
            scaleChange = data->baseScale.z * -0.5;
            phi_f4 = ((data->baseScale.y + scaleChange) - entity->scale.y) / 5.0;
            if (phi_f4 > -0.01) {
                phi_f4 = -0.01f;
            }
            data->deltaScaleY += phi_f4;
            entity->scale.y += data->deltaScaleY;
            if (entity->scale.y <= (data->baseScale.y + scaleChange)) {
                data->deltaScaleY = 0.0f;
                data->animStateScaleY++;
            }
            break;
        case 1:
            scaleChange = data->baseScale.z * 0.1;
            phi_f4 = ((data->baseScale.y + scaleChange) - entity->scale.y) / 10.0;
            if (phi_f4 < 0.01) {
                phi_f4 = 0.01f;
            }
            data->deltaScaleY += phi_f4;
            entity->scale.y += data->deltaScaleY;
            if ((data->baseScale.y + scaleChange) <= entity->scale.y) {
                data->deltaScaleY = 0.0f;
                data->animStateScaleY++;
            }
            break;
        case 2:
            scaleChange = data->baseScale.z * -0.3;
            phi_f4 = ((data->baseScale.y + scaleChange) - entity->scale.y) / 5.0;
            if (phi_f4 > -0.01) {
                phi_f4 = -0.01f;
            }
            data->deltaScaleY += phi_f4;
            entity->scale.y += data->deltaScaleY;
            if (entity->scale.y <= (data->baseScale.y + scaleChange)) {
                data->deltaScaleY = 0.0f;
                data->animStateScaleY++;
            }
            break;
        case 3:
            phi_s2++;
            break;
    }

    entity_switch_fall_down(entity);
    if (phi_s2 == 2) {
        data->animStateScaleX = 0;
        data->animStateScaleY = 0;
        exec_entity_commandlist(entity);
    }

    data->scaleAnimTimer++;
    if (data->scaleAnimTimer == 10 && data->linkedSwitch == NULL) {
        fx_cold_breath(0, entity->pos.x, entity->pos.y, entity->pos.z, 1.0f, 60);
    }
}

void entity_base_switch_init(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SwitchData* data = entity->dataBuf.swtch;

    playerStatus->animFlags |= PA_FLAG_MAP_HAS_SWITCH;
    data->baseScale.x = 1.0f;
    data->baseScale.y = 1.0f;
    data->baseScale.z = 1.0f;
}

void entity_BlueSwitch_init(Entity* entity) {
    SwitchData* data = entity->dataBuf.swtch;

    entity_base_switch_init(entity);
    if (CreateEntityVarArgBuffer[0] == REFLECTED_SWITCH_LINKED) {
        SwitchToLink = entity;
        return;
    }

    if (CreateEntityVarArgBuffer[0] == REFLECTED_SWITCH_HIDDEN) {
        if (SwitchToLink != NULL) {
            data->linkedSwitch = SwitchToLink;
            entity->flags |= ENTITY_FLAG_HIDDEN;
            return;
        }
    } else {
        SwitchToLink = NULL;
    }
}

void entity_HugeBlueSwitch_init(Entity* entity) {
    SwitchData* data;

    entity_base_switch_init(entity);
    data = entity->dataBuf.swtch;
    entity->scale.x = 3.0f;
    entity->scale.y = 3.0f;
    entity->scale.z = 3.0f;
    data->baseScale.x = 3.0f;
    data->baseScale.y = 3.0f;
    data->baseScale.z = 3.0f;
}

EntityScript Entity_RedSwitch_Script = {
    es_SetCallback(entity_small_switch_idle, 0)
    es_PlaySound(SOUND_ACTIVATE_SWITCH)
    es_Call(entity_base_switch_start_bound_script)
    es_Call(entity_base_switch_anim_init)
    es_SetCallback(entity_RedSwitch_animate_scale, 0)
    es_SetCallback(entity_RedSwitch_wait_and_reset, 0)
    es_Restart
    es_End
};

EntityScript Entity_HugeBlueSwitch_Script = {
    es_SetCallback(entity_HugeBlueSwitch_idle, 0)
    es_PlaySound(SOUND_ACTIVATE_SWITCH)
    es_Call(entity_base_switch_start_bound_script)
    es_Call(entity_base_switch_anim_init)
    es_SetCallback(entity_base_switch_animate_scale, 0)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_BlueSwitch_Script = {
    es_SetCallback(entity_small_switch_idle, 0)
    es_PlaySound(SOUND_ACTIVATE_SWITCH)
    es_Call(entity_base_switch_start_bound_script)
    es_Call(entity_base_switch_anim_init)
    es_SetCallback(entity_base_switch_animate_scale, 0)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_GreenStompSwitch_Script = {
    es_SetCallback(entity_GreenStompSwitch_idle, 0)
    es_SetCallback(entity_GreenStompSwitch_retract, 0)
    es_PlaySound(SOUND_ACTIVATE_SWITCH)
    es_SetCallback(NULL, 128)
    es_SetCallback(entity_GreenStompSwitch_extend, 0)
    es_Restart
};

EntityModelScript Entity_BlueSwitch_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_BlueSwitch_Render, RENDER_MODE_SURFACE_XLU_LAYER1);

EntityModelScript Entity_HugeBlueSwitch_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_BlueSwitch_Render, RENDER_MODE_SURFACE_XLU_LAYER1);

EntityModelScript Entity_RedSwitch_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_RedSwitch_Render, RENDER_MODE_SURFACE_XLU_LAYER1);

EntityModelScript Entity_GreenStompSwitch_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_GreenStompSwitch_Render, RENDER_MODE_SURFACE_OPA);

EntityBlueprint Entity_RedSwitch = {
    .flags = ENTITY_FLAG_8000 | ENTITY_FLAG_ALWAYS_FACE_CAMERA,
    .typeDataSize = sizeof(SwitchData),
    .renderCommandList = Entity_RedSwitch_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_switch_init,
    .updateEntityScript = Entity_RedSwitch_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(RedSwitch) },
    .entityType = ENTITY_TYPE_RED_SWITCH,
    .aabbSize = {22, 23, 22}
};

EntityBlueprint Entity_BlueSwitch = {
    .flags = ENTITY_FLAG_8000 | ENTITY_FLAG_ALWAYS_FACE_CAMERA | ENTITY_FLAG_CIRCULAR_SHADOW | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_HAS_DYNAMIC_SHADOW,
    .typeDataSize = sizeof(SwitchData),
    .renderCommandList = Entity_BlueSwitch_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_BlueSwitch_init,
    .updateEntityScript = Entity_BlueSwitch_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(BlueSwitch) },
    .entityType = ENTITY_TYPE_BLUE_SWITCH,
    .aabbSize = {22, 23, 22}
};

EntityBlueprint Entity_HugeBlueSwitch = {
    .flags = ENTITY_FLAG_8000 | ENTITY_FLAG_ALWAYS_FACE_CAMERA | ENTITY_FLAG_CIRCULAR_SHADOW | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_HAS_DYNAMIC_SHADOW,
    .typeDataSize = sizeof(SwitchData),
    .renderCommandList = Entity_HugeBlueSwitch_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_HugeBlueSwitch_init,
    .updateEntityScript = Entity_HugeBlueSwitch_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(BlueSwitch) },
    .entityType = ENTITY_TYPE_HUGE_BLUE_SWITCH,
    .aabbSize = {66, 75, 66}
};

EntityBlueprint Entity_GreenStompSwitch = {
    .flags = ENTITY_FLAG_8000 | ENTITY_FLAG_4000,
    .typeDataSize = sizeof(SwitchData),
    .renderCommandList = Entity_GreenStompSwitch_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_switch_init,
    .updateEntityScript = Entity_GreenStompSwitch_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(GreenStompSwitch) },
    .entityType = ENTITY_TYPE_GREEN_STOMP_SWITCH,
    .aabbSize = {50, 15, 50}
};
