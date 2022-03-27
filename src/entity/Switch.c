#include "common.h"
#include "effects.h"

#define REFLECTED_SWITCH_HIDDEN 1
#define REFLECTED_SWITCH_LINKED 2

void entity_shattering_init_pieces(Entity* entity, void* arg1, void* arg2);

void entity_GreenStompSwitch_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SwitchData* data = entity->dataBuf.swtch;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if ((playerStatus->actionState == ACTION_STATE_GROUND_POUND)
            || (playerStatus->actionState == ACTION_STATE_ULTRA_POUND)) {
            exec_entity_commandlist(entity);
            data->greenMotionTimer = 8;
        }
    }
}

void entity_GreenStompSwitch_retract(Entity* entity) {
    SwitchData* data = entity->dataBuf.swtch;
    u16 curTime = data->greenMotionTimer--;

    if (curTime != 0) {
        entity->position.y -= 1.8625;
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
        entity->position.y += 1.8625;
        return;
    }
    exec_entity_commandlist(entity);
    data->greenMotionTimer = 8;
}

void entity_switch_fall_down(Entity* entity) {
    SwitchData* data = entity->dataBuf.swtch;
    f32 hitDepth = 10.0f;
    f32 x = entity->position.x;
    f32 y = entity->position.y;
    f32 z = entity->position.z;
    f32 hitYaw;
    f32 hitPitch;

    entity_raycast_down(&x, &y, &z, &hitYaw, &hitPitch, &hitDepth);

    if (entity->position.y != y && entity->position.y > y) {
        f32 fallVelocity = data->fallVelocity;

        fallVelocity += 0.5;
        data->fallVelocity = fallVelocity;
        entity->position.y -= fallVelocity;
        if (entity->position.y < y) {
            entity->position.y = y;
        }
    }
}

void entity_HugeBlueSwitch_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if ((playerStatus->actionState == ACTION_STATE_GROUND_POUND)
            || (playerStatus->actionState == ACTION_STATE_ULTRA_POUND)) {
            exec_entity_commandlist(entity);
        }
    }
}

void entity_small_switch_idle(Entity* entity) {
    SwitchData* data = entity->dataBuf.swtch;
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

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

    if (partnerActionStatus->actionState.b[3] == 4 && partnerActionStatus->actionState.b[0] != 0) {
        return;
    }

    if (!(entity->collisionFlags & 1)) {
        if (!(entity->collisionFlags & 0x80)) {
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
    if (!(entity->collisionFlags & 1)) {
        exec_entity_commandlist(entity);
    }
}

void entity_base_switch_anim_init(Entity* entity) {
    SwitchData* temp = entity->dataBuf.swtch;

    temp->fallVelocity = 1.0f;
    temp->deltaScaleX = 0.1f;
    temp->deltaScaleY = -0.1f;
    temp->animStateScaleX = 0;
    temp->animStateScaleY = 0;
}

s32 entity_RedSwitch_animate_scale(Entity* entity) {
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f6;
    SwitchData* data = entity->dataBuf.swtch;
    f32 phi_f4;
    s32 phi_s2 = 0;

    switch (data->animStateScaleX) {
        case 0:
            temp_f6 = data->baseScale.z * 0.3;
            temp_f4 = ((data->baseScale.x + temp_f6) - entity->scale.x) / 4.0;
            phi_f4 = temp_f4;
            if (temp_f4 < 0.01) {
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
            temp_f4 = ((data->baseScale.x + temp_f6) - entity->scale.x) / 6.0;
            phi_f4 = temp_f4;
            if (temp_f4 > -0.01) {
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
            temp_f4 = ((data->baseScale.x + temp_f6) - entity->scale.x) / 4.0;
            phi_f4 = temp_f4;
            if (temp_f4 < 0.01) {
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
            temp_f4 = ((data->baseScale.x + temp_f6) - entity->scale.x) / 6.0;
            phi_f4 = temp_f4;
            if (temp_f4 > -0.01) {
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
            temp_f4 = (data->baseScale.x - entity->scale.x) / 4.0;
            phi_f4 = temp_f4;
            if (temp_f4 < 0.01) {
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
            temp_f4 = ((data->baseScale.y + temp_f6) - entity->scale.y) / 5.0;
            phi_f4 = temp_f4;
            if (temp_f4 > -0.01) {
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
            temp_f4 = ((data->baseScale.y + temp_f6) - entity->scale.y) / 10.0;
            phi_f4 = temp_f4;
            if (temp_f4 < 0.01) {
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
            temp_f4 = ((data->baseScale.y + temp_f6) - entity->scale.y) / 5.0;
            phi_f4 = temp_f4;
            if (temp_f4 > -0.01) {
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
            temp_f4 = ((data->baseScale.y + temp_f6) - entity->scale.y) / 10.0;
            phi_f4 = temp_f4;
            if (temp_f4 < 0.01) {
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
            temp_f4 = (data->baseScale.y - entity->scale.y) / 5.0;
            phi_f4 = temp_f4;
            if (temp_f4 > -0.01) {
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
    f32 temp_f0;
    f32 temp_f4;
    f32 scaleChange;
    SwitchData* data = entity->dataBuf.swtch;
    f32 phi_f4;
    s32 phi_s2 = 0;

    switch (data->animStateScaleX) {
        case 0:
            scaleChange = data->baseScale.z * 0.3;
            temp_f4 = ((data->baseScale.x + scaleChange) - entity->scale.x) / 4.0;
            phi_f4 = temp_f4;
            if (temp_f4 < 0.01) {
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
            temp_f4 = ((data->baseScale.x + scaleChange) - entity->scale.x) / 6.0;
            phi_f4 = temp_f4;
            if (temp_f4 > -0.01) {
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
            temp_f4 = ((data->baseScale.x + scaleChange) - entity->scale.x) / 4.0;
            phi_f4 = temp_f4;
            if (temp_f4 < 0.01) {
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
            temp_f4 = ((data->baseScale.x + scaleChange) - entity->scale.x) / 6.0;
            phi_f4 = temp_f4;
            if (temp_f4 > -0.01) {
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
            temp_f4 = ((data->baseScale.y + scaleChange) - entity->scale.y) / 5.0;
            phi_f4 = temp_f4;
            if (temp_f4 > -0.01) {
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
            temp_f4 = ((data->baseScale.y + scaleChange) - entity->scale.y) / 10.0;
            phi_f4 = temp_f4;
            if (temp_f4 < 0.01) {
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
            temp_f4 = ((data->baseScale.y + scaleChange) - entity->scale.y) / 5.0;
            phi_f4 = temp_f4;
            if (temp_f4 > -0.01) {
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
    if ((data->scaleAnimTimer == 10) && (data->linkedSwitch == NULL)) {
        fx_cold_breath(0, entity->position.x, entity->position.y, entity->position.z, 1.0f, 0x3C);
    }
}

void entity_base_switch_init(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SwitchData* data = entity->dataBuf.swtch;

    playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_1000000;
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
            entity->flags |= ENTITY_FLAGS_HIDDEN;
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

void entity_BrickBlock_idle(Entity* entity) {
    entity_base_block_idle(entity);
}

void entity_shattering_setupGfx(s32 entityIndex);
INCLUDE_ASM(void, "entity/Switch", entity_shattering_init_pieces, Entity* entity, void* arg1, void* arg2);
// void entity_shattering_init_pieces(Entity* entity, void* arg1, void* arg2) {
//     Matrix4f sp10, sp50;
//     SwitchData* data = entity->dataBuf.swtch;
//     s32 i;

//     s32 phi_s7;
//     u16* phi_s3;
//     s32 phi_s0;
//     f32 phi_f20;


//     data->unk_34 = entity->vertexData[(s32)arg1].m;
//     entity->renderSetupFunc = entity_shattering_setupGfx;
//     entity->alpha = 255;
//     entity->position.y = data->unk_38;
//     guTranslateF(sp50, entity->position.x, entity->position.y, entity->position.z);

//     if (!is_block_on_ground(entity)) {
//         phi_s7 = 1;
//     } else {
//         phi_s7 = 2;
//     }

//     data->unk_3E = 0;
//     data->unk_3C.s = 0xFF;
//     phi_s3 = data; // ???

//     for (i = 0; i < ARRAY_COUNT(data->fragmentRotX); i++) {
//         guMtxL2F(sp10, &entity->vertexData[(s32)arg2 & 0xFFFF]);
//         guMtxCatF(sp50, sp10, sp10);
//         data->fragmentPosX[i] = sp10[3][0];
//         data->fragmentPosY[i] = sp10[3][1];
//         data->fragmentPosZ[i] = sp10[3][2];
//         data->unk_72[i] = -rand_int(255);

//         if (phi_s7 == 1) {
//             phi_s3[i] |= 1;
//             phi_s0 = 20;
//             phi_f20 = 6.4f;
//         } else {
//             phi_s3[i] |= 2;
//             phi_s0 = 40;
//             phi_f20 = 8.6f;
//         }

//         data->unk_59[i] = phi_s0 + rand_int(10);
//         if ((i % 2) == 0) {
//             data->unk_59[i] = -data->unk_59[i];
//         }

//         data->unk_1EC[i] = phi_f20 + (f32)(rand_float() * 2.7);
//         data->unk_40[i] = 0;
//         data->fragmentRotX[i] = 0;
//         data->fragmentRotY[i] = 0;
//     }
// }

INCLUDE_ASM(void, "entity/Switch", entity_shattering_idle, Entity* entity);

#ifdef NON_EQUIVALENT
// display list issues
void entity_shattering_setupGfx(s32 entityIndex) {
    Gfx* temp_s2;
    SwitchData* data;
    struct802E2BA4* phi_fp;
    Matrix4f subroutine_arg6;
    Matrix4f subroutine_arg16;
    Matrix4f subroutine_arg36;
    Matrix4f subroutine_arg48;
    s32 i;
    f32 x_inv;
    f32 y_inv;
    f32 z_inv;
    Entity* entity;
    f32 threeSixty;
    f32 someFloat;
    f32 one;
    s16 temp;

    temp_s2 = gMasterGfxPos;
    threeSixty = 360.0f;
    someFloat = 0.00390625f;
    entity = get_entity_by_index(entityIndex);
    data = entity->dataBuf.swtch;
    x_inv = -entity->position.x;
    y_inv = -entity->position.y;
    z_inv = -entity->position.z;
    phi_fp = data->renderYaw;
    for (i = 0; i < 24; i++) {
        if (data->unk_3C.s == 0xFF) {
            gDPSetRenderMode(temp_s2++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            gDPSetCombineMode(temp_s2++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        } else {
            gDPSetCombineLERP(temp_s2++, 0, 0, 0, TEXEL0, SHADE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
            gDPSetPrimColor(temp_s2++, 0, 0, 0x00, 0x00, 0x00, data->unk_3C.b[1])
        }
        guTranslateF(&subroutine_arg6, x_inv, y_inv, z_inv);
        guRotateF(&subroutine_arg36, data->unk_8B[i] * threeSixty * someFloat, 1.0f, 0.0f, 0.0f);
        guRotateF(&subroutine_arg48, data->unk_A4[i] * threeSixty * someFloat, 0.0f, 1.0f, 0.0f);
        guMtxCatF(&subroutine_arg36, &subroutine_arg48, &subroutine_arg48);
        guMtxCatF(&subroutine_arg48, &subroutine_arg6, &subroutine_arg6);
        guTranslateF(&subroutine_arg16, data->unk_C0[i], data->unk_124[i], data->unk_188[i]);
        guMtxCatF(&subroutine_arg6, &subroutine_arg16, &subroutine_arg16);
        guMtxF2L(&subroutine_arg16, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(temp_s2++, &gDisplayContext->matrixStack[++gMatrixListPos], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(temp_s2++, entity->vertexData + phi_fp->unk_02[i][0]);
        gSPPopMatrix(temp_s2++, G_MTX_MODELVIEW);
    }
    gMasterGfxPos = temp_s2;
}
#else
INCLUDE_ASM(s32, "entity/Switch", entity_shattering_setupGfx);
#endif
