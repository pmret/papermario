#include "common.h"
#include "npc.h"
#include "effects.h"
#include "sprite.h"

extern s16 D_8010C97A;

extern f32 D_80077C10;
extern s16 D_80077C14;

extern f32 D_80077C18;
extern s16 D_80077C1C;
extern s16 D_80077C1E;
extern s32 D_80077C20;

extern s16 D_80077C30;
extern s32 D_80077C34;
extern s16 D_80077C38;
extern s16 D_80077C3A;

void STUB_npc_callback(Npc* npc) {
}

void mtx_ident_mirror_y(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = -1.0f;
    mtx[2][2] = 1.0f;
    mtx[3][3] = 1.0f;
}

void clear_npcs(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentNpcListPtr = &gWorldNpcList;
    } else {
        gCurrentNpcListPtr = &gBattleNpcList;
    }

    for (i = 0; i < MAX_NPCS; i++) {
        (*gCurrentNpcListPtr)[i] = NULL;
    }

    gNpcCount = 0;
    D_800A0B94 = 1;
}

void init_npc_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentNpcListPtr = &gWorldNpcList;
    } else {
        gCurrentNpcListPtr = &gBattleNpcList;
    }

    gNpcCount = 0;
    D_800A0B94 = 1;
}

void npc_iter_no_op(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentNpcListPtr); i++) {
        // Needed to avoid loop optimization.
        do {} while (FALSE);
    }
}

s32 _create_npc(NpcBlueprint* blueprint, AnimID** animList, s32 skipLoadingAnims) {
    Npc* npc;
    s32 i;
    s32 j;

    for (i = 0; i < MAX_NPCS; i++) {
        if ((*gCurrentNpcListPtr)[i] == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_NPCS);

    (*gCurrentNpcListPtr)[i] = npc = heap_malloc(sizeof(*npc));
    gNpcCount++;
    ASSERT(npc != NULL);

    npc->flags = blueprint->flags | (NPC_FLAG_400000 | NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_HAS_SHADOW | NPC_FLAG_PASSIVE);
    if (skipLoadingAnims) {
        npc->flags |= NPC_FLAG_NO_ANIMS_LOADED;
    }

    npc->collisionRadius = 32;
    npc->collisionHeight = 64;
    npc->renderMode = 13;
    npc->blur.any = NULL;
    npc->yaw = 0.0f;
    npc->jumpVelocity = 0.0f;
    npc->pos.x = 0.0f;
    npc->pos.y = 0.0f;
    npc->pos.z = 0.0f;
    npc->colliderPos.x = 0.0f;
    npc->colliderPos.y = 0.0f;
    npc->colliderPos.z = 0.0f;
    npc->rotationVerticalPivotOffset = 0.0f;
    npc->rotation.x = 0.0f;
    npc->rotation.y = 0.0f;
    npc->rotation.z = 0.0f;
    npc->homePos.x = 0.0f;
    npc->homePos.y = 0.0f;
    npc->homePos.z = 0.0f;
    npc->unk_96 = 0; // TODO: fix
    npc->verticalRenderOffset = 0;
    npc->alpha = 255;
    npc->alpha2 = 255;
    npc->jumpScale = 1.0f;
    npc->moveSpeed = 4.0f;
    npc->scale.x = 1.0f;
    npc->scale.y = 1.0f;
    npc->scale.z = 1.0f;
    npc->currentAnim = blueprint->initialAnim;
    npc->animationSpeed = 1.0f;
    npc->renderYaw = 0.0f;
    npc->unk_98 = 0;
    npc->unk_A2 = 0;
    npc->collisionChannel = 0x20000;
    npc->isFacingAway = 0;
    npc->yawCamOffset = 0;
    npc->turnAroundYawAdjustment = 0;
    npc->currentFloor = -1;
    npc->currentWall = -1;
    npc->palSwapType = 0;
    npc->palSwapPrevType = 0;
    npc->screenSpaceOffset2D[0] = 0.0f;
    npc->screenSpaceOffset2D[1] = 0.0f;
    npc->verticalStretch = 1.0f;

    for (j = 0; j < ARRAY_COUNT(npc->decorations); j++) {
        npc->decorations[j] = 0;
        npc->decorationType[j] = 0;
    }

    npc->onUpdate = blueprint->onUpdate;
    if (npc->onUpdate == NULL) {
        npc->onUpdate = &STUB_npc_callback;
    }

    npc->onRender = blueprint->onRender;
    if (npc->onRender == NULL) {
        npc->onRender = &STUB_npc_callback;
    }
    if (!skipLoadingAnims) {
        npc->extraAnimList = animList;
        if (!(npc->flags & NPC_FLAG_1000000)) {
            if (!(npc->flags & NPC_FLAG_PARTICLE)) {
                npc->spriteInstanceID = spr_load_npc_sprite(npc->currentAnim, animList);
            } else {
                npc->spriteInstanceID = spr_load_npc_sprite(npc->currentAnim | SPRITE_ID_TAIL_ALLOCATE, animList);
            }
        } else {
            npc->flags |= NPC_FLAG_2;
        }
    }

    npc->shadowIndex = create_shadow_type(0, npc->pos.x, npc->pos.y, npc->pos.z);
    npc->shadowScale = 1.0f;

    if (gGameStatusPtr->isBattle) {
        i |= 0x800;
    }
    return i;
}

s32 _create_npc_basic(NpcBlueprint* blueprint) {
    return _create_npc(blueprint, NULL, FALSE);
}

s32 _create_npc_standard(NpcBlueprint* blueprint, AnimID** animList) {
    return _create_npc(blueprint, animList, FALSE);
}

s32 _create_npc_partner(NpcBlueprint* blueprint) {
    return _create_npc(blueprint, NULL, TRUE);
}

void free_npc_by_index(s32 listIndex) {
    Npc* npc;
    s32 i;

    listIndex &= ~0x800;

    npc = (*gCurrentNpcListPtr)[listIndex];
    if (npc != NULL) {
        if (npc->flags) {
            if (npc->blur.any != NULL) {
                heap_free(npc->blur.any);
                npc->blur.any = NULL;
            }

            if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                ASSERT((npc->flags & NPC_FLAG_1000000) || !spr_free_sprite(npc->spriteInstanceID));
            }

            delete_shadow(npc->shadowIndex);

            for (i = 0; i < 2; i++) {
                npc_remove_decoration(npc, i);
            }

            if (npc->flags & NPC_FLAG_MOTION_BLUR) {
                disable_npc_blur(npc);
            }

            heap_free((*gCurrentNpcListPtr)[listIndex]);
            (*gCurrentNpcListPtr)[listIndex] = NULL;
            gNpcCount--;
        }
    }
}

void free_npc(Npc* npc) {
    s32 i;

    if (npc->blur.any != NULL) {
        heap_free(npc->blur.any);
        npc->blur.any = NULL;
    }

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        ASSERT((npc->flags & NPC_FLAG_1000000) || !spr_free_sprite(npc->spriteInstanceID));
    }

    delete_shadow(npc->shadowIndex);

    for (i = 0; i < 2; i++) {
        npc_remove_decoration(npc, i);
    }

    if (npc->flags & NPC_FLAG_MOTION_BLUR) {
        disable_npc_blur(npc);
    }

    heap_free(npc);

    for (i = 0; i < MAX_NPCS; i++) {
        if ((*gCurrentNpcListPtr)[i] == npc) {
            break;
        }
    }

    (*gCurrentNpcListPtr)[i] = NULL;
    gNpcCount--;
}

Npc* get_npc_by_index(s32 listIndex) {
    return (*gCurrentNpcListPtr)[listIndex & ~0x800];
}

void npc_do_world_collision(Npc* npc) {
    f32 temp_f0;
    s32 phi_v0;
    f32 temp_x;
    f32 temp_y;
    f32 temp_z;

    if (npc->flags & NPC_FLAG_40) {
        npc->flags |= NPC_FLAG_8000000;
    } else if ((npc->pos.x != npc->colliderPos.x) || (npc->pos.y != npc->colliderPos.y)
               || (npc->pos.z != npc->colliderPos.z) || npc->flags & NPC_FLAG_8000000) {
        npc->flags &= ~NPC_FLAG_8000000;
        temp_f0 = clamp_angle(npc->yaw);
        temp_x = npc->pos.x;
        temp_y = npc->pos.y;
        temp_z = npc->pos.z;

        if (!(npc->flags & NPC_FLAG_PARTICLE)) {
            phi_v0 = npc_test_move_simple_with_slipping(npc->collisionChannel, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
        } else {
            phi_v0 = npc_test_move_complex_with_slipping(npc->collisionChannel, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
        }

        if (phi_v0) {
            npc->flags |= (NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_4000);
            npc->currentWall = D_8010C97A;
            npc->pos.x = temp_x;
            npc->pos.z = temp_z;
        } else {
            npc->flags &= ~(NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_4000);
        }

        temp_f0 = clamp_angle(npc->yaw + 45.0f);
        temp_x = npc->pos.x;
        temp_y = npc->pos.y;
        temp_z = npc->pos.z;

        if (!(npc->flags & NPC_FLAG_PARTICLE)) {
            phi_v0 = npc_test_move_simple_with_slipping(npc->collisionChannel, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
        } else {
            phi_v0 = npc_test_move_taller_with_slipping(npc->collisionChannel, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
        }

        if (phi_v0) {
            npc->flags |= NPC_FLAG_NO_PROJECT_SHADOW;
            npc->pos.x = temp_x;
            npc->pos.z = temp_z;
        } else {
            npc->flags &= ~NPC_FLAG_NO_PROJECT_SHADOW;
        }

        temp_f0 = clamp_angle(npc->yaw - 45.0f);
        temp_x = npc->pos.x;
        temp_y = npc->pos.y;
        temp_z = npc->pos.z;
        if (!(npc->flags & NPC_FLAG_PARTICLE)) {
            phi_v0 = npc_test_move_simple_with_slipping(npc->collisionChannel, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
        } else {
            phi_v0 = npc_test_move_taller_with_slipping(npc->collisionChannel, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
        }

        if (phi_v0 != 0) {
            npc->flags |= NPC_FLAG_NO_PROJECT_SHADOW;
            npc->pos.x = temp_x;
            npc->pos.z = temp_z;
        } else {
            npc->flags &= ~NPC_FLAG_NO_PROJECT_SHADOW;
        }

        if (npc->flags & NPC_FLAG_PARTICLE) {
            temp_f0 = clamp_angle(npc->yaw + 45.0f + 180.0f);
            temp_x = npc->pos.x;
            temp_y = npc->pos.y;
            temp_z = npc->pos.z;
            if (npc_test_move_simple_with_slipping(npc->collisionChannel, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight,
                              npc->collisionRadius) != 0) {
                npc->flags |= NPC_FLAG_NO_PROJECT_SHADOW;
                npc->pos.x = temp_x;
                npc->pos.z = temp_z;
            } else {
                npc->flags &= ~NPC_FLAG_NO_PROJECT_SHADOW;
            }

            temp_f0 = clamp_angle((npc->yaw - 45.0f) + 180.0f);
            temp_x = npc->pos.x;
            temp_y = npc->pos.y;
            temp_z = npc->pos.z;
            if (npc_test_move_simple_with_slipping(npc->collisionChannel, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight,
                              npc->collisionRadius) != 0) {
                npc->flags |= NPC_FLAG_NO_PROJECT_SHADOW;
                npc->pos.x = temp_x;
                npc->pos.z = temp_z;
                return;
            }
            npc->flags &= ~NPC_FLAG_NO_PROJECT_SHADOW;
        }
    }
}

// float regalloc :(
#ifdef NON_MATCHING
void npc_do_other_npc_collision(Npc* npc) {
    Npc* otherNpc;
    f32 temp_f20_2;
    f32 temp_f22_3;
    f32 temp_f24_2;
    f32 temp_f22_4;
    f32 temp_f2;
    f32 thisX, thisY, thisZ;
    f32 thisBuf;
    f32 otherX, otherZ;
    f32 otherBuf;
    f32 xDiff, zDiff;
    f32 dist;
    s32 collision;
    s32 i;

    if (!(npc->flags & NPC_FLAG_100)) {
        npc->flags &= ~NPC_FLAG_SIMPLIFIED_PHYSICS;
        thisBuf = npc->collisionRadius * 0.5f;
        thisX = npc->pos.x;
        thisY = npc->pos.y;
        thisZ = npc->pos.z;

        for (i = 0; i < 0x40; i++) {
            otherNpc = get_npc_by_index(i);
            if (otherNpc != NULL && npc != otherNpc) {
                if (otherNpc->flags != 0 && !(otherNpc->flags & (0x80000000 | NPC_FLAG_100))) {
                    if (!(otherNpc->pos.y + otherNpc->collisionHeight < thisY) &&
                        !(thisY + npc->collisionHeight < otherNpc->pos.y))
                    {
                        otherX = otherNpc->pos.x;
                        otherZ = otherNpc->pos.z;
                        xDiff = otherX - thisX;
                        zDiff = otherZ - thisZ;
                        otherBuf = otherNpc->collisionRadius * 0.5f;
                        dist = sqrtf(SQ(xDiff) + SQ(zDiff));

                        if (!(thisBuf + otherBuf <= dist)) {
                            collision = FALSE;
                            if (npc->flags & NPC_FLAG_PARTICLE) {
                                collision = gPartnerActionStatus.partnerActionState == PARTNER_ACTION_NONE;
                            } else if (!(otherNpc->flags & NPC_FLAG_PARTICLE) || gPartnerActionStatus.partnerActionState == PARTNER_ACTION_NONE) {
                                collision = TRUE;
                            }

                            if (collision) {
                                temp_f20_2 = DEG_TO_RAD(atan2(otherX, otherZ, thisX, thisZ));
                                temp_f24_2 = thisBuf + otherBuf - dist;
                                temp_f22_3 = temp_f24_2 * sin_rad(temp_f20_2);
                                temp_f22_4 = -temp_f24_2 * cos_rad(temp_f20_2);
                                thisX += temp_f22_3 * 0.1f;
                                thisZ += temp_f22_4 * 0.1f;
                            }
                            npc->flags |= NPC_FLAG_SIMPLIFIED_PHYSICS;
                        }
                    }
                }
            }
        }
        npc->pos.x = thisX;
        npc->pos.z = thisZ;
    }
}
#else
INCLUDE_ASM(void, "npc", npc_do_other_npc_collision, Npc* npc);
#endif

INCLUDE_ASM(s32, "npc", npc_do_player_collision, Npc* npc);

void npc_do_gravity(Npc* npc) {
    if (npc->flags & NPC_FLAG_GRAVITY) {
        if (npc->flags & NPC_FLAG_JUMPING) {
            npc->flags &= ~NPC_FLAG_1000;
        } else {
            f32 xTemp;
            f32 yTemp;
            f32 zTemp;
            f32 length, oldLength;
            s32 hit;

            npc->jumpScale = 1.0f;
            xTemp = npc->pos.x;
            zTemp = npc->pos.z;

            npc->jumpVelocity -= npc->jumpScale;
            npc->pos.y += npc->jumpVelocity;
            oldLength = length = fabsf(npc->jumpVelocity) + 16.0f;

            yTemp = npc->pos.y + 13.0f;

            if (!(npc->flags & NPC_FLAG_PARTICLE)) {
                hit = npc_raycast_down_sides(npc->collisionChannel, &xTemp, &yTemp, &zTemp, &length);
            } else {
                hit = npc_raycast_down_around(npc->collisionChannel, &xTemp, &yTemp, &zTemp, &length, npc->yaw,
                                             npc->collisionRadius);
            }

            if (hit && length <= oldLength) {
                npc->jumpVelocity = 0.0f;
                npc->flags |= NPC_FLAG_1000;
                npc->pos.y = yTemp;
                npc->currentFloor = D_8010C97A;
            } else {
                npc->flags &= ~NPC_FLAG_1000;
            }
        }
    }
}

s32 func_800397E8(Npc* npc, f32 arg1) {
    if (!(npc->flags & (NPC_FLAG_GRAVITY | NPC_FLAG_ENABLE_HIT_SCRIPT))) {
        f32 x;
        f32 y;
        f32 z;
        f32 length;
        f32 oldLength;
        s32 phi_v0;

        if (npc->flags & NPC_FLAG_JUMPING) {
            npc->flags &= ~NPC_FLAG_1000;
            return FALSE;
        }

        length = oldLength = fabsf(arg1) + 16;
        x = npc->pos.x;
        y = npc->pos.y + 13;
        z = npc->pos.z;

        if (!(npc->flags & NPC_FLAG_PARTICLE)) {
            phi_v0 = npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &length);
        } else {
            phi_v0 = npc_raycast_down_around(npc->collisionChannel, &x, &y, &z, &length, npc->yaw, npc->collisionRadius);
        }

        if (phi_v0 != 0 && length <= oldLength) {
            npc->pos.y = y;
            npc->currentFloor = D_8010C97A;
            npc->flags |= NPC_FLAG_1000;
            return TRUE;
        }
    } else {
        return FALSE;
    }

    npc->flags &= ~NPC_FLAG_1000;
    return FALSE;
}

void update_npcs(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 hitYaw, hitPitch, hitLength;

    playerStatus->animFlags &= ~PA_FLAGS_8000;
    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_800 | GLOBAL_OVERRIDES_400))) {
        s32 i;

        for (i = 0; i < 0x40; i++) {
            Npc* npc = (*gCurrentNpcListPtr)[i];

            if (npc != NULL) {
                if (npc->flags != 0) {
                    if (npc->flags & (NPC_FLAG_80000000 | NPC_FLAG_4)) {
                        npc_do_world_collision(npc);
                        continue;
                    }

                    npc->onUpdate(npc);
                    if (npc->flags & NPC_FLAG_8000) {
                        npc->collisionChannel |= 0x40000;
                    } else {
                        npc->collisionChannel &= ~0x40000;
                    }

                    npc->currentFloor = -1;
                    npc->currentWall = -1;
                    npc->flags &= ~(NPC_FLAG_4000 | NPC_FLAG_NO_PROJECT_SHADOW);

                    npc_do_world_collision(npc);
                    npc_do_gravity(npc);
                    func_800397E8(npc, 0.0f);
                    npc_do_player_collision(npc);
                    npc_do_other_npc_collision(npc);

                    if (npc->flags & NPC_FLAG_MOTION_BLUR) {
                        update_npc_blur(npc);
                    }

                    if ((npc->pos.y < -2000.0f) && !(npc->flags & NPC_FLAG_PARTICLE)) {
                        npc->pos.y = playerStatus->position.y;
                        npc->jumpVelocity = 0.0f;
                        npc->moveSpeed = 0.0f;
                        npc->jumpScale = 0.0f;
                        npc->flags &= ~NPC_FLAG_JUMPING;
                    }

                    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                        if (!(npc->flags & NPC_FLAG_1000000)) {
                            if (npc->currentAnim != 0) {
                                if (npc->spriteInstanceID >= 0) {
                                    spr_update_sprite(npc->spriteInstanceID, npc->currentAnim, npc->animationSpeed);
                                }
                            }
                        }
                    } else {
                        spr_update_player_sprite(1, npc->currentAnim, npc->animationSpeed);
                    }

                    if (npc->flags & NPC_FLAG_HAS_SHADOW) {
                        Shadow* shadow = get_shadow_by_index(npc->shadowIndex);
                        EntityModel* entityModel = get_entity_model(shadow->entityModelID);

                        entityModel->flags &= ~ENTITY_MODEL_FLAGS_REFLECT;
                        if (npc->flags & NPC_FLAG_REFLECT_WALL) {
                            entityModel->flags |= ENTITY_MODEL_FLAGS_REFLECT;
                        }

                        x = npc->pos.x;
                        y = npc->pos.y;
                        z = npc->pos.z;
                        if (!(npc->flags & NPC_FLAG_NO_AI)) {
                            if (
                                x != npc->colliderPos.x ||
                                y != npc->colliderPos.y ||
                                z != npc->colliderPos.z ||
                                (npc->flags & NPC_FLAG_DIRTY_SHADOW))
                            {
                                x = npc->pos.x;
                                y = npc->pos.y + (npc->collisionHeight / 2);
                                z = npc->pos.z;
                                hitLength = 1000.0f;
                                entity_raycast_down(&x, &y, &z, &hitYaw, &hitPitch, &hitLength);
                                set_npc_shadow_scale(shadow, hitLength, npc->collisionRadius);
                                shadow->position.x = x;
                                shadow->position.y = y;
                                shadow->position.z = z;
                                shadow->rotation.x = hitYaw;
                                shadow->rotation.y = npc->renderYaw;
                                shadow->rotation.z = hitPitch;
                                shadow->scale.x *= npc->shadowScale;
                                npc->flags &= ~NPC_FLAG_DIRTY_SHADOW;
                            }
                        } else {
                            if (npc->flags & NPC_FLAG_LOCK_ANIMS) {
                                shadow->position.x = npc->pos.x;
                            } else {
                                shadow->position.x = npc->pos.x;
                                shadow->position.y = npc->pos.y;
                            }
                            shadow->position.z = npc->pos.z;
                        }
                    }

                    npc->colliderPos.x = npc->pos.x;
                    npc->colliderPos.y = npc->pos.y;
                    npc->colliderPos.z = npc->pos.z;
                    npc_update_decorations(npc);

                    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                        if (!(npc->flags & NPC_FLAG_1000000)) {
                            if (npc->spriteInstanceID < 0) {
                                npc->spriteInstanceID++;
                                if (npc->spriteInstanceID == -1) {
                                    npc->spriteInstanceID = spr_load_npc_sprite(npc->currentAnim, npc->extraAnimList);
                                    ASSERT(npc->spriteInstanceID >= 0);
                                    spr_update_sprite(npc->spriteInstanceID, npc->currentAnim, npc->animationSpeed);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// float regalloc, issue at the bottom with a mov.s
#ifdef NON_MATCHING
f32 npc_get_render_yaw(Npc* npc) {
    Camera* camera = &gCameras[gCurrentCamID];
    f32 cameraYaw;
    f32 temp;
    s32 phi_s0;

    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_8000 | GLOBAL_OVERRIDES_4000))) {
        cameraYaw = camera->currentYaw;
        temp = get_clamped_angle_diff(cameraYaw, npc->yaw);

        if (temp < -5.0f && temp > -175.0f) {
            phi_s0 = 0;
            temp = clamp_angle(0.0f);
        } else if (temp > 5.0f && temp < 175.0f) {
            phi_s0 = 1;
            temp = clamp_angle(180.0f);
        } else {
            phi_s0 = 2;
            temp = clamp_angle(npc->yawCamOffset);
        }

        npc->yawCamOffset = temp;

        if (!(npc->flags & NPC_FLAG_40000)) {
            if (npc->isFacingAway != phi_s0 && phi_s0 != 2) {
                npc->isFacingAway = phi_s0;

                if (npc->isFacingAway) {
                    npc->turnAroundYawAdjustment = 180;
                } else {
                    npc->turnAroundYawAdjustment = -180;
                }

                if (fabsf(get_clamped_angle_diff(cameraYaw, npc->yaw)) >= 90.0f) {
                    npc->turnAroundYawAdjustment = -npc->turnAroundYawAdjustment;
                }
            }

            if (npc->turnAroundYawAdjustment != 0) {
                if (npc->turnAroundYawAdjustment < 0) {
                    npc->turnAroundYawAdjustment += 20;
                }
                if (npc->turnAroundYawAdjustment > 0) {
                    npc->turnAroundYawAdjustment -= 20;
                }
            }

            if (npc->flags & NPC_FLAG_200000) {
                npc->turnAroundYawAdjustment = 0;
            }

            temp = clamp_angle(clamp_angle(npc->turnAroundYawAdjustment + temp) - cameraYaw);
            npc->renderYaw = temp;
            return temp;
        }
    }
    return npc->renderYaw;
}
#else
INCLUDE_ASM(f32, "npc", npc_get_render_yaw);
#endif

void appendGfx_npc(Npc* npc) {
    Matrix4f mtx1, mtx2;
    f32 renderYaw = npc_get_render_yaw(npc);

    guTranslateF(mtx1, npc->pos.x, npc->pos.y + npc->verticalRenderOffset, npc->pos.z);
    if (npc->flags & NPC_FLAG_UPSIDE_DOWN) {
        mtx_ident_mirror_y(mtx2);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->rotationVerticalPivotOffset != 0.0f) {
        guTranslateF(mtx2, 0.0f, npc->rotationVerticalPivotOffset, 0.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->rotation.y != 0.0f) {
        guRotateF(mtx2, npc->rotation.y, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->rotation.x != 0.0f) {
        guRotateF(mtx2, npc->rotation.x, 1.0f, 0.0f, 0.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->rotation.z != 0.0f) {
        guRotateF(mtx2, npc->rotation.z, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->rotationVerticalPivotOffset != 0.0f) {
        guTranslateF(mtx2, 0.0f, -npc->rotationVerticalPivotOffset, 0.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if ((npc->screenSpaceOffset2D[0] != 0.0f) || (npc->screenSpaceOffset2D[1] != 0.0f)) {
        guTranslateF(mtx1, npc->screenSpaceOffset2D[0], npc->screenSpaceOffset2D[1], 0.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if ((npc->scale.x * SPRITE_WORLD_SCALE_D != 1.0f) || ((npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D != 1.0f)
        || (npc->scale.z * SPRITE_WORLD_SCALE_D != 1.0f)) {
        guScaleF(mtx2, npc->scale.x * SPRITE_WORLD_SCALE_D, (npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D,
                 npc->scale.z * SPRITE_WORLD_SCALE_D);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        if (!(npc->flags & NPC_FLAG_1000000) && (npc->currentAnim != 0) && (npc->spriteInstanceID >= 0)) {
            npc_draw_with_palswap(npc, renderYaw, mtx1);
            npc->animNotifyValue = spr_get_notify_value(npc->spriteInstanceID);
        }
    } else {
        npc_draw_with_palswap(npc, renderYaw, mtx1);
        npc->animNotifyValue = func_802DDEC4(1);
    }

    if (npc->flags & NPC_FLAG_REFLECT_WALL) {
        guTranslateF(mtx1, npc->pos.x, npc->pos.y + npc->verticalRenderOffset, -npc->pos.z);
        if (npc->flags & NPC_FLAG_UPSIDE_DOWN) {
            mtx_ident_mirror_y(mtx2);
            guMtxCatF(mtx2, mtx1, mtx1);
        }
        if ((npc->rotation.y != 0.0f) || (npc->rotation.x != 0.0f) || (npc->rotation.z != 0.0f)) {
            guRotateRPYF(mtx2, npc->rotation.x, npc->rotation.y, npc->rotation.z);
            guMtxCatF(mtx2, mtx1, mtx1);
        }


        if ((npc->scale.x * SPRITE_WORLD_SCALE_D != 1.0f) || ((npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D != 1.0f)
            || (npc->scale.z * SPRITE_WORLD_SCALE_D != 1.0f))
        {
            do {
                guScaleF(mtx2, npc->scale.x * SPRITE_WORLD_SCALE_D,
                               (npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D,
                               npc->scale.z * SPRITE_WORLD_SCALE_D);
            } while (0); // required to match (macro?)
            guMtxCatF(mtx2, mtx1, mtx1);

        }

        if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
            if (!(npc->flags & NPC_FLAG_1000000) && (npc->currentAnim != 0)) {
                spr_draw_npc_sprite(npc->spriteInstanceID, renderYaw, 0, 0, mtx1);
            }
        } else {
            spr_draw_player_sprite(0x40000001, renderYaw, 0, 0, mtx1);
        }
    }

    if (npc->flags & NPC_FLAG_REFLECT_FLOOR) {
        guTranslateF(mtx1, npc->pos.x, -(npc->pos.y + npc->verticalRenderOffset), npc->pos.z);
        mtx_ident_mirror_y(mtx2);
        guMtxCatF(mtx2, mtx1, mtx1);

        if (npc->rotation.y != 0.0f || npc->rotation.x != 0.0f || npc->rotation.z != 0.0f) {
            guRotateRPYF(mtx2, npc->rotation.x, npc->rotation.y, npc->rotation.z);
            guMtxCatF(mtx2, mtx1, mtx1);
        }

        if ((npc->scale.x * SPRITE_WORLD_SCALE_D != 1.0f) || ((npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D != 1.0f)
            || (npc->scale.z * SPRITE_WORLD_SCALE_D != 1.0f))
        {
            do {
                guScaleF(mtx2, npc->scale.x * SPRITE_WORLD_SCALE_D,
                               (npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D,
                               npc->scale.z * SPRITE_WORLD_SCALE_D);
            } while (0); // required to match (macro?)

            guMtxCatF(mtx2, mtx1, mtx1);
        }
        if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
            if (!(npc->flags & NPC_FLAG_1000000) && (npc->currentAnim != 0)) {
                spr_draw_npc_sprite(npc->spriteInstanceID, renderYaw, 0, 0, mtx1);
            }
        } else {
            spr_draw_player_sprite(0x40000001, renderYaw, 0, 0, mtx1);
        }
    }
    npc->onRender(npc);
}

void render_npcs(void) {
    f32 temp_f20;
    Npc* npc;
    f32 phi_f20;
    s32 i;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    f32 x;
    f32 y;
    f32 z;
    f32 s;
    Camera* cam = &gCameras[gCurrentCamID];

    for (i = 0; i < MAX_NPCS; i++) {

        Npc* npc = (*gCurrentNpcListPtr)[i];
        if (npc != NULL) {
            if (npc->flags && !(npc->flags & (NPC_FLAG_80000000 | NPC_FLAG_1000000 | NPC_FLAG_4 | NPC_FLAG_2))) {
                transform_point(cam->perspectiveMatrix, npc->pos.x, npc->pos.y, npc->pos.z, 1.0f, &x, &y, &z, &s);
                if (!(s < 0.01) || !(s > -0.01)) {
                    phi_f20 = ((z * 5000.0f) / s) + 5000.0f;
                    if (phi_f20 < 0.0f) {
                        phi_f20 = 0.0f;
                    } else if (phi_f20 > 10000.0f) {
                        phi_f20 = 10000.0f;
                    }

                    renderTaskPtr->distance = -phi_f20;
                    renderTaskPtr->appendGfxArg = npc;
                    renderTaskPtr->appendGfx = appendGfx_npc;
                    renderTaskPtr->renderMode = npc->renderMode;

                    if (npc->flags & NPC_FLAG_NO_DROPS) {
                        u8 r, g, b, a;
                        get_background_color_blend(&r, &g, &b, &a);
                        npc->alpha2 = 0xFF - a;
                    } else {
                        npc->alpha2 = 0xFF;
                    }

                    if (npc->alpha2 != 0) {
                        queue_render_task(renderTaskPtr);
                    }

                    if ((npc->flags & NPC_FLAG_MOTION_BLUR) != 0) {
                        renderTaskPtr->distance = -phi_f20;
                        renderTaskPtr->appendGfx = appendGfx_npc_blur;
                        renderTaskPtr->appendGfxArg = npc;
                        renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
                        queue_render_task(renderTaskPtr);
                    }
                }
            }
        }
    }
}

void npc_move_heading(Npc* npc, f32 speed, f32 yaw) {
    f32 angle = DEG_TO_RAD(yaw);
    f32 sin = sin_rad(angle);
    f32 cos = cos_rad(angle);

    npc->pos.x += speed * sin;
    npc->pos.z += -speed * cos;
}

Npc* get_npc_unsafe(s32 npcID) {
    s32 i;
    Npc* npc;

    for (i = 0; i < MAX_NPCS; i++) {
        npc = (*gCurrentNpcListPtr)[i];
        if (npc != NULL && npc->flags != 0 && npc->npcID == npcID) {
            break;
        }
    }
    ASSERT(i < MAX_NPCS);

    return npc;
}

Npc* get_npc_safe(s32 npcID) {
    s32 i;
    Npc* npc;

    for (i = 0; i < MAX_NPCS; i++) {
        npc = (*gCurrentNpcListPtr)[i];
        if (npc != NULL && npc->flags != 0 && npc->npcID == npcID) {
            break;
        }
    }
    if (i >= MAX_NPCS) {
        return NULL;
    }

    return npc;
}

void enable_npc_shadow(Npc* npc) {
    Shadow* shadow;

    if (!(npc->flags & NPC_FLAG_HAS_SHADOW)) {
        shadow = get_shadow_by_index(npc->shadowIndex);
        shadow->flags &= ~ENTITY_FLAGS_HIDDEN;
        npc->flags = npc->flags | (NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_HAS_SHADOW);
    }
}

void disable_npc_shadow(Npc* npc) {
    Shadow* shadow;

    if (npc->flags & NPC_FLAG_HAS_SHADOW) {
        shadow = get_shadow_by_index(npc->shadowIndex);
        shadow->flags |= ENTITY_FLAGS_HIDDEN;
        npc->flags &= ~NPC_FLAG_HAS_SHADOW;
        npc->flags &= ~NPC_FLAG_DIRTY_SHADOW;
    }
}

void set_npc_sprite(Npc* npc, s32 anim, u32** extraAnimList) {
    ASSERT((npc->flags & NPC_FLAG_1000000) || spr_free_sprite(npc->spriteInstanceID) == 0);

    npc->extraAnimList = extraAnimList;

    if (!(npc->flags & NPC_FLAG_1000000)) {
        npc->spriteInstanceID = spr_load_npc_sprite(anim, extraAnimList);
        ASSERT(npc->spriteInstanceID >= 0);
    }

    npc->currentAnim = anim;

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        if (!(npc->flags & NPC_FLAG_1000000)) {
            spr_update_sprite(npc->spriteInstanceID, anim, npc->animationSpeed);
        }
    }
}

void enable_npc_blur(Npc* npc) {
    if (!(npc->flags & NPC_FLAG_MOTION_BLUR)) {
        NpcMotionBlur* motionBlur;
        s32 i;

        npc->flags |= NPC_FLAG_MOTION_BLUR;

        motionBlur = heap_malloc(sizeof(*motionBlur));
        npc->blur.motion = motionBlur;
        ASSERT(motionBlur != NULL);
        motionBlur->unk_00 = 0;
        motionBlur->index = 0;

        for (i = 0; i < ARRAY_COUNT(motionBlur->x); i++) {
            motionBlur->x[i] = npc->pos.x;
            motionBlur->y[i] = npc->pos.y;
            motionBlur->z[i] = npc->pos.z;
        }
    }
}

void disable_npc_blur(Npc* npc) {
    if (npc->flags & NPC_FLAG_MOTION_BLUR) {
        npc->flags &= ~NPC_FLAG_MOTION_BLUR;

        heap_free(npc->blur.motion);
        npc->blur.motion = NULL;
    }
}

void update_npc_blur(Npc* npc) {
    NpcMotionBlur* motionBlur = npc->blur.motion;
    s32 index = motionBlur->index;

    motionBlur->x[index] = npc->pos.x;
    motionBlur->y[index] = npc->pos.y;
    motionBlur->z[index] = npc->pos.z;

    index++;
    if (index >= 20) {
        index = 0;
    }

    motionBlur->index = index;
}

INCLUDE_ASM(void, "npc", appendGfx_npc_blur, Npc* npc);

void npc_enable_collisions(void) {
    D_800A0B94 = 1;
}

void npc_disable_collisions(void) {
    D_800A0B94 = 0;
}

void func_8003B1A8(void) {
}

void npc_reload_all(void) {
    s32 i;
    s32 j;

    for (i = 0; i < MAX_NPCS; i++) {
        Npc* npc = (*gCurrentNpcListPtr)[i];
        if (npc != NULL) {
            if (npc->flags && !(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                if (!(npc->flags & NPC_FLAG_1000000)) {
                    if (!(npc->flags & NPC_FLAG_PARTICLE)) {
                        npc->spriteInstanceID = spr_load_npc_sprite(npc->currentAnim, npc->extraAnimList);
                    } else {
                        npc->spriteInstanceID = spr_load_npc_sprite(npc->currentAnim | SPRITE_ID_TAIL_ALLOCATE, npc->extraAnimList);
                    }
                }
                if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                    if (!(npc->flags & NPC_FLAG_1000000) && (npc->palSwapType != 0)) {
                        npc->spritePaletteList = spr_get_npc_palettes(npc->currentAnim >> 16);
                        npc->paletteCount = 0;
                        while (npc->spritePaletteList[npc->paletteCount] != -1) {
                            npc->paletteCount++;
                        }
                        npc->unk_C0 = spr_get_npc_color_variations(npc->currentAnim >> 16);
                    }
                    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                        if (!(npc->flags & NPC_FLAG_1000000)) {
                            for (j = 0; j < 2; j++) {
                                npc_reset_current_decoration(npc, j);
                            }
                            func_8003D3BC(npc);
                        }
                    }
                }
            }
        }
    }
}

void set_npc_yaw(Npc* npc, f32 yaw) {
    npc->yaw = yaw;

    if (get_clamped_angle_diff(gCameras[gCurrentCameraID].currentYaw, yaw) >= 0.0f) {
        npc->yawCamOffset = 180;
        npc->isFacingAway = TRUE;
    } else {
        npc->yawCamOffset = 0;
        npc->isFacingAway = FALSE;
    }
}

void npc_set_palswap_mode_A(Npc* npc, s32 mode) {
    if (npc->palSwapType != mode) {
        npc->palSwapPrevType = npc->palSwapType;
        npc->palSwapType = mode;
        npc->palSwapState = 0;
        npc->dirtyPalettes = 1;
    }
}

void npc_set_palswap_mode_B(Npc* npc, s32 mode) {
    if (npc->palSwapType != mode) {
        npc->palSwapPrevType = npc->palSwapType;
        npc->palSwapType = mode;
        npc->palSwapState = 0;
        npc->dirtyPalettes = -1;
    }
}

void func_8003B420(Npc* npc) {
    if (npc->palSwapPrevType == 0) {
        npc->palSwapType = 0;
        return;
    }
    npc->palSwapType = npc->palSwapPrevType;
    npc->palSwapPrevType = 0;
    npc->palSwapState = 0;
    npc->dirtyPalettes = 1;
}

void npc_set_palswap_1(Npc* npc, s32 palIndexA, s32 palIndexB, s32 timeHoldA, s32 timeAB) {
    npc->unk_308 = palIndexA;
    npc->unk_30A = palIndexB;
    npc->unk_30C = timeHoldA;
    npc->unk_30E = timeAB;
}

void npc_set_palswap_2(Npc* npc, s32 timeHoldB, s32 timeBA, s32 palIndexC, s32 palIndexD) {
    npc->unk_310 = timeHoldB;
    npc->unk_312 = timeBA;
    npc->unk_314 = palIndexC;
    npc->unk_316 = palIndexD;
}

void npc_draw_with_palswap(Npc* npc, s32 arg1, Matrix4f mtx) {
    switch (npc->palSwapType) {
        case 0:
            npc_draw_palswap_mode_0(npc, arg1, mtx);
            break;
        case 1:
            npc_draw_palswap_mode_1(npc, arg1, mtx);
            break;
        case 2:
            npc_draw_palswap_mode_2(npc, arg1, 0, mtx);
            break;
        case 3:
            npc_draw_palswap_mode_2(npc, arg1, 1, mtx);
            break;
        case 4:
            npc_draw_palswap_mode_4(npc, arg1, mtx);
            break;
    }
}

void npc_draw_palswap_mode_0(Npc* npc, s32 arg1, Matrix4f mtx) {
    if (npc->dirtyPalettes != 0) {
        npc->screenSpaceOffset2D[0] = 0.0f;
        npc->screenSpaceOffset2D[1] = 0.0f;
        npc->dirtyPalettes = 0;
        npc->verticalStretch = 1.0f;
    }

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        s32 temp_a2 = (npc->alpha * npc->alpha2 / 255);
        s32 temp = temp_a2 < 255; // TODO: better match?
        spr_draw_npc_sprite(npc->spriteInstanceID | (temp) << 31, arg1, temp_a2, NULL, mtx);
    } else {
        spr_draw_player_sprite(0x40000001, arg1, 0, 0, mtx);
    }
}

INCLUDE_ASM(s32, "npc", npc_draw_palswap_mode_1);

u16 npc_blend_palette_colors(u16 colorA, u16 colorB, s32 lerpAlpha) {
    u32 r = ((((colorA >> 11) & 0x1F) * (255 - lerpAlpha)) + (((colorB >> 11) & 0x1F) * lerpAlpha)) / 255;
    u32 g = ((((colorA >> 6)  & 0x1F) * (255 - lerpAlpha)) + (((colorB >> 6)  & 0x1F) * lerpAlpha)) / 255;
    u32 b = ((((colorA >> 1)  & 0x1F) * (255 - lerpAlpha)) + (((colorB >> 1)  & 0x1F) * lerpAlpha)) / 255;

    return (colorB & 1) | (((r & 0xFF) << 11) | ((g & 0xFF) << 6) | ((b & 0xFF) << 1));
}

INCLUDE_ASM(s32, "npc", npc_draw_palswap_mode_2);

INCLUDE_ASM(s32, "npc", npc_draw_palswap_mode_4);

void npc_set_decoration(Npc* npc, s32 idx, s32 decorationType) {
    npc__remove_decoration(npc, idx);
    npc->decorationType[idx] = decorationType;
    npc->changedDecoration[idx] = 1;
    npc->decorationInitialised[idx] = 0;
}

void npc_remove_decoration(Npc* npc, s32 idx) {
    npc__remove_decoration(npc, idx);
}

s32 npc_update_decorations(Npc* npc) {
    s32 i;

    for (i = 0; i < 2; i++) {
        switch (npc->decorationType[i]) {
            case 0:
                npc_update_decoration_none(npc, i);
                break;
            case 1:
                npc_update_decoration_bowser_aura(npc, i);
                break;
            case 2:
                npc_update_decoration_sweat(npc, i);
                break;
            case 3:
                npc_update_decoration_seeing_stars(npc, i);
                break;
            case 4:
                npc_update_decoration_glow_in_front(npc, i);
                break;
            case 5:
                npc_update_decoration_glow_behind(npc, i);
                break;
            case 6:
                npc_update_decoration_charged(npc, i);
                break;
        }
    }
}

void npc__remove_decoration(Npc* npc, s32 idx) {
    switch (npc->decorationType[idx]) {
        case 0:
            npc_remove_decoration_none(npc, idx);
            break;
        case 1:
            npc_remove_decoration_bowser_aura(npc, idx);
            break;
        case 2:
            npc_remove_decoration_sweat(npc, idx);
            break;
        case 3:
            npc_remove_decoration_seeing_stars(npc, idx);
            break;
        case 4:
            npc_remove_decoration_glow_in_front(npc, idx);
            break;
        case 5:
            npc_remove_decoration_glow_behind(npc, idx);
            break;
        case 6:
            npc_remove_decoration_charged(npc, idx);
            break;
    }
    npc->decorationType[idx] = 0;
}

void npc_reset_current_decoration(Npc* npc, s32 idx) {
    switch (npc->decorationType[idx]) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            break;
        case 6:
            npc__reset_current_decoration(npc, idx);
            break;
    }
}

void npc_update_decoration_none(Npc* npc, s32 idx) {
}

void npc_remove_decoration_none(Npc* npc, s32 idx) {
}

void npc_update_decoration_bowser_aura(Npc* npc, s32 idx) {
    AuraFXData* data;

    switch (npc->decorationInitialised[idx]) {
        case 0:
            fx_aura(2, npc->pos.x, npc->pos.y, npc->pos.z, 1.0f, &npc->decorations[idx]);
            npc->decorationInitialised[idx] = 1;
            break;
        case 1:
            break;
        default:
            return;
    }

    data = npc->decorations[idx]->data.aura;
    data->posA.x = npc->pos.x;
    data->posA.y = npc->pos.y;
    data->posA.z = npc->pos.z;
    data->scale.x = (npc->scale.x * npc->collisionRadius) * 0.01;
    data->scale.y = (npc->scale.y * npc->collisionHeight) * 0.01;
    data->renderYaw = npc->renderYaw;
}

void npc_remove_decoration_bowser_aura(Npc* npc, s32 idx) {
    npc->decorations[idx]->data.aura->fadeTime = 5;
}

void npc_update_decoration_sweat(Npc* npc, s32 idx) {
    switch (npc->decorationInitialised[idx]) {
        case 0:
            if (npc->yawCamOffset > 90) {
                fx_sweat(0, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 5.0f, 45.0f, 20);
            } else {
                fx_sweat(0, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 5.0f, -45.0f, 20);
            }
            npc->decorationUnk[idx] = 10;
            npc->decorationInitialised[idx] = 1;
            break;
        case 1:
            if (npc->decorationUnk[idx] != 0) {
                npc->decorationUnk[idx]--;
            } else {
                npc->decorationInitialised[idx] = 0;
            }
            break;
    }
}

void npc_remove_decoration_sweat(Npc* npc, s32 idx) {
}

void npc_update_decoration_seeing_stars(Npc* npc, s32 idx) {
    StarsOrbitingFXData* data;

    switch (npc->decorationInitialised[idx]) {
        case 0:
            fx_stars_orbiting(0, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 20.0f, 3, &npc->decorations[idx]);
            npc->decorationInitialised[idx] = 1;
            return;
        case 1:
            break;
        default:
            return;

    }

    data = npc->decorations[idx]->data.starsOrbiting;
    data->pos.x = npc->pos.x;
    data->pos.y = npc->pos.y + npc->collisionHeight;
    data->pos.z = npc->pos.z;
}

void npc_remove_decoration_seeing_stars(Npc* npc, s32 idx) {
    remove_effect(npc->decorations[idx]);
}

void npc_update_decoration_glow_in_front(Npc* npc, s32 idx) {
    EnergyOrbWaveFXData* data;

    switch (npc->decorationInitialised[idx]) {
        case 0:
            npc->decorations[idx] = fx_energy_orb_wave(2, npc->pos.x, npc->pos.y + npc->collisionHeight * 0.5, npc->pos.z, npc->scale.x * 0.8 + 0.2f, -1);
            npc->decorationInitialised[idx] = 1;
            break;
        case 1:
            data = npc->decorations[idx]->data.energyOrbWave;
            data->pos.x = npc->pos.x;
            data->pos.y = npc->pos.y + npc->collisionHeight * 0.5 * npc->scale.x;
            data->pos.z = npc->pos.z;
            data->scale = npc->scale.x * 0.8 + 0.2f;
            break;
    }
}

void npc_remove_decoration_glow_in_front(Npc* npc, s32 idx) {
    remove_effect(npc->decorations[idx]);
}

void npc_update_decoration_glow_behind(Npc* npc, s32 idx) {
    EnergyOrbWaveFXData* data;

    switch (npc->decorationInitialised[idx]) {
        case 0:
            npc->decorations[idx] = fx_energy_orb_wave(2, npc->pos.x, npc->pos.y + npc->collisionHeight * 0.5, npc->pos.z - 5.0f, 1.0f, 0);
            npc->decorationInitialised[idx] = 1;
            break;
        case 1:
            data = npc->decorations[idx]->data.energyOrbWave;
            data->pos.x = npc->pos.x;
            data->pos.y = npc->pos.y + npc->collisionHeight * 0.5;
            data->pos.z = npc->pos.z - 5.0f;
            data->scale = 1.0f;
            break;
    }
}

void npc_remove_decoration_glow_behind(Npc* npc, s32 idx) {
    remove_effect(npc->decorations[idx]);
}

void npc_update_decoration_charged(Npc* npc, s32 idx) {
    u8 sp50[20];
    u8 sp38[20];
    u8 sp20[20];
    s32 i;
    s32 temp3;

    if (!npc->decorationInitialised[idx]) {
        func_802DE894(npc->spriteInstanceID, 17, 20, 0, 0, 255, 0);
        npc->decorationInitialised[idx] = TRUE;
    }
    if (npc->decorationInitialised[idx] == TRUE) {
        npc->decorationUnk[idx] += 7;
        if (npc->decorationUnk[idx] >= 360) {
            npc->decorationUnk[idx] = npc->decorationUnk[idx] % 360;
        }

        for (i = 0; i < 20; i++) {
            sp50[i] = (cosine(npc->decorationUnk[idx] + i * 25) + 1.0) * 80.0f;
            sp38[i] = (cosine(npc->decorationUnk[idx] + i * 25 + 45) + 1.0) * 80.0f;
            sp20[i] = (cosine(npc->decorationUnk[idx] + i * 25 + 90) + 1.0) * 80.0f;
        }

        for (temp3 = 255, i = 0; i < 20; i++) {
            func_802DE894(npc->spriteInstanceID, 12, i, (sp50[i] << 24) | (sp38[i] << 16) | (sp20[i] << 8) | temp3, 0, 255, 0);
        }
    }
}

void npc_remove_decoration_charged(Npc* npc, s32 idx) {
}

void npc__reset_current_decoration(Npc* npc, s32 idx) {
    npc->decorationInitialised[idx] = 0;
}

Npc* npc_find_closest(f32 x, f32 y, f32 z, f32 radius) {
    Npc* closestNpc = NULL;
    f32 closestDist = radius;
    f32 maxDist = radius;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentNpcListPtr); i++) {
        Npc* npc = (*gCurrentNpcListPtr)[i];

        if (npc != NULL && npc->flags != 0 && !(npc->flags & NPC_FLAG_PARTICLE)) {
            if (!(npc->flags & (NPC_FLAG_80000000 | NPC_FLAG_4))) {
                f32 distance = fabsf(dist2D(npc->pos.x, npc->pos.z, x, z));

                if (distance <= maxDist) {
                    if (distance < closestDist) {
                        closestDist = distance;
                        closestNpc = npc;
                    }
                }
            }
        }
    }

    return closestNpc;
}

Npc* npc_find_closest_simple(f32 x, f32 y, f32 z, f32 radius) {
    Npc* closestNpc = NULL;
    f32 closestDist = radius;
    f32 maxDist = radius;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentNpcListPtr); i++) {
        Npc* npc = (*gCurrentNpcListPtr)[i];

        if (npc != NULL && npc->flags != 0 && (npc->flags & NPC_FLAG_PARTICLE)) {
            if (!(npc->flags & (NPC_FLAG_80000000 | NPC_FLAG_4))) {
                f32 distance = fabsf(dist2D(npc->pos.x, npc->pos.z, x, z));

                if (distance <= maxDist) {
                    if (distance < closestDist) {
                        closestDist = distance;
                        closestNpc = npc;
                    }
                }
            }
        }
    }

    return closestNpc;
}

// Needs work
#ifdef NON_EQUIVALENT
s32 npc_find_standing_on_entity(s32 arg0) {
    s32 entityIndex = arg0 | 0x4000;
    Entity* entity = get_entity_by_index(entityIndex);
    s32 y = entity->position.y - 10.0f;
    s32 floorID;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentNpcListPtr); i++) {
        Npc* npc = (*gCurrentNpcListPtr)[i];

        if (npc != NULL) {
            if (npc->flags != 0) {
                if (!(npc->flags & 0x80000004)) {
                    if (!(npc->pos.y < y)) {
                        if (npc->flags & 0x8008) {
                            floorID = npc_get_collider_below(npc);
                            if (floorID == 0) {
                                continue;
                            }
                        } else {
                            floorID = npc->currentFloor;

                            if (!(floorID & COLLISION_WITH_ENTITY_BIT)) {
                                continue;
                            }
                        }

                        if (entityIndex == floorID) {
                            return i;
                        }
                    }
                }
            }
        }
    }

    return -1;
}
#else
INCLUDE_ASM(s32, "npc", npc_find_standing_on_entity);
#endif

s32 npc_get_collider_below(Npc* npc) {
    f32 x;
    f32 y;
    f32 z;
    f32 yaw;

    if (npc->flags & NPC_FLAG_PARTICLE) {
        y = get_shadow_by_index(npc->shadowIndex)->position.y + 13.0f;
    } else {
        y = npc->pos.y + 13.0f;
    }

    yaw = 16.0f;
    x = npc->pos.x;
    z = npc->pos.z;

    if (npc_raycast_down_sides(0x38000, &x, &y, &z, &yaw)) {
        if (yaw <= 16.0f) {
            return D_8010C978;
        }
    }
    return 0;
}

void func_8003D3BC(Npc* npc) {
    s32 temp_s4 = npc->unk_98;
    s32 temp_s0 = npc->unk_9A;
    s32 temp_s5 = npc->unk_9C;
    s32 temp_s2 = npc->unk_9E;
    s32 temp_s6 = npc->unk_A0;
    s32 temp_s3 = npc->unk_A2;

    func_802DE894(npc->spriteInstanceID, FOLD_TYPE_NONE, 0, 0, 0, 0, 0);

    switch (temp_s4) {
        case FOLD_TYPE_NONE:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_NONE, 0, 0, 0, 0, temp_s3);
            break;
        case FOLD_TYPE_2:
        case FOLD_TYPE_3:
            npc->renderMode = 13;
            // fallthrough
        case FOLD_TYPE_1:
            func_802DE894(npc->spriteInstanceID, temp_s4, 0, 0, 0, 0, temp_s3);
            break;
        case FOLD_TYPE_4:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_4, temp_s0, temp_s5, temp_s2, 0, temp_s3);
            break;
        case FOLD_TYPE_6:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_6, temp_s0, temp_s5, temp_s2, 255, temp_s3);
            break;
        case FOLD_TYPE_7:
            npc->renderMode = 22;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_7, 255, 255, 255, temp_s0, temp_s3);
            break;
        case FOLD_TYPE_8:
            npc->renderMode = 22;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_8, temp_s0, temp_s5, temp_s2, temp_s6, temp_s3);
            break;
        case FOLD_TYPE_9:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_9, temp_s0, temp_s5, temp_s2, 255, temp_s3);
            break;
        case FOLD_TYPE_A:
            npc->renderMode = 22;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_A, temp_s0, temp_s5, temp_s2, temp_s6, temp_s3);
            break;
        case FOLD_TYPE_5:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_5, temp_s0, temp_s5, temp_s2, 0, temp_s3);
            break;
        case FOLD_TYPE_D:
            npc->renderMode = 22;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_D, temp_s0, temp_s5, temp_s2, temp_s6, temp_s3);
            break;
        case FOLD_TYPE_E:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_E, temp_s0, temp_s5, temp_s2, 255, temp_s3);
            break;
        case FOLD_TYPE_F:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_F, temp_s0, 255, 0, 255, temp_s3);
            break;
        case FOLD_TYPE_10:
            npc->renderMode = 22;
            func_802DE894(npc->spriteInstanceID, FOLD_TYPE_F, temp_s0, temp_s5, 0, temp_s5, temp_s3);
            break;
    }
}

void func_8003D624(Npc* npc, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    npc->unk_98 = arg1;
    npc->unk_9A = arg2;
    npc->unk_9C = arg3;
    npc->unk_9E = arg4;
    npc->unk_A0 = arg5;
    npc->unk_A2 = arg6;
    func_8003D3BC(npc);
}

void func_8003D660(Npc* npc, s32 arg1) {
    PartnerActionStatus* temp = &gPartnerActionStatus;

    if ((npc->flags & (NPC_FLAG_400000 | NPC_FLAG_2)) == NPC_FLAG_400000) {
        if (npc->moveSpeed != 0.0f) {
            s32 surfaceType = get_collider_flags((u16)npc->currentFloor) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
            switch (surfaceType) {
                case SURFACE_TYPE_FLOWERS:
                    func_8003DA38(npc, arg1);
                    return;
                case SURFACE_TYPE_CLOUD:
                    func_8003DC38(npc, arg1);
                    return;
                case SURFACE_TYPE_SNOW:
                    if ((temp->partnerActionState == PARTNER_ACTION_NONE) || (temp->actingPartner != PARTNER_LAKILESTER)) {
                        func_8003DFA0(npc, arg1);
                        return;
                    }
                    break;
                case SURFACE_TYPE_HEDGES:
                    func_8003E0D4(npc, arg1);
                    return;
                case SURFACE_TYPE_WATER:
                    func_8003E1D0(npc, arg1);
                    return;
                case SURFACE_TYPE_SPIKES:
                case SURFACE_TYPE_LAVA:
                case SURFACE_TYPE_DOCK_WALL:
                case SURFACE_TYPE_SLIDE:
                default:
                    func_8003D788(npc, arg1);
                    return;
            }
        }
    }
}

static const f32 padding[2] = { 0.0f, 0.0f }; // todo remove when below funcs are decompiled

void func_8003D788(Npc* npc, s32 arg1) {
    s32 phi_a2;
    f32 sinTheta;
    f32 cosTheta;

    phi_a2 = 0;
    if (gGameStatusPtr->areaID == 5) {
        phi_a2 = gGameStatusPtr->mapID == 2;
    }
    if (arg1 == 2) {
        f32 x = npc->pos.x;
        f32 y = npc->pos.y + 0.0f;
        f32 z = npc->pos.z;

        if (phi_a2 == 0) {
            fx_landing_dust(0, x, y, z, D_80077C10);
            D_80077C10 = clamp_angle(D_80077C10 + 35.0f);
        } else {
            fx_misc_particles(3, x, y, z,  13.0f, 10.0f, 1.0f, 5, 30);
        }
    } else if (arg1 != 0) {
        if (D_80077C14++ >= 4) {
            D_80077C14 = 0;
            if (phi_a2 == 0) {
                sin_cos_rad(DEG_TO_RAD(clamp_angle(-npc->yaw)), &sinTheta, &cosTheta);
                fx_walking_dust(0, npc->pos.x + (npc->collisionRadius * sinTheta * 0.2f), npc->pos.y + 1.5f,
                               npc->pos.z + (npc->collisionRadius * cosTheta * 0.2f), sinTheta, cosTheta);
            } else {
                sin_cos_rad(DEG_TO_RAD(clamp_angle(npc->yaw)), &sinTheta, &cosTheta);
                fx_misc_particles(3, npc->pos.x + (npc->collisionRadius * sinTheta), npc->pos.y + 1.5f,
                              npc->pos.z + (npc->collisionRadius * cosTheta), 5.0f, 10.0f, 1.0f, 5, 30);
            }
        }
    }
}

// floats suck
#ifdef NON_MATCHING
void func_8003DA38(Npc* npc, s32 arg1) {
    f32 theta;
    f32 sinTheta;
    f32 cosTheta;
    f32 x, y, z;

    if (arg1 == 2 && D_80077C1E == 5) {
        fx_flower_splash(npc->pos.x, npc->pos.y + 14.0f, npc->pos.z, D_80077C18);
        D_80077C18 = clamp_angle(D_80077C18 + 35.0f);
        D_80077C1E = 0;
        return;
    }

    D_80077C1E++;
    if (D_80077C1E > 5) {
        D_80077C1E = 5;
    }

    if (D_80077C1C++ > 0) {
        D_80077C1C = 0;
        theta = DEG_TO_RAD(clamp_angle(-npc->yaw));
        sinTheta = sin_rad(theta);
        cosTheta = cos_rad(theta);

        x = npc->pos.x + (npc->collisionRadius * sinTheta * -0.4f);
        z = npc->pos.z + (npc->collisionRadius * cosTheta * -0.4f);
        y = npc->pos.y + 15.5f;

        fx_flower_trail(1, x, y, z, -npc->yaw + rand_int(10) - 5.0f, D_80077C20);
        D_80077C20 = D_80077C20 == 0;
    }
}
#else
INCLUDE_ASM(void, "npc", func_8003DA38, Npc* npc, s32 arg1);
#endif

INCLUDE_ASM(s32, "npc", func_8003DC38);

void func_8003DFA0(Npc* npc, s32 arg1) {
    if (D_80077C30++ >= 4) {
        f32 temp_f20;
        f32 x;
        f32 z;

        D_80077C30 = 0;
        temp_f20 = DEG_TO_RAD(clamp_angle(-npc->yaw));
        x = sin_rad(temp_f20);
        z = cos_rad(temp_f20);
        fx_footprint(npc->pos.x + (npc->collisionRadius * x * 0.2f), npc->pos.y + 1.5f,
                  npc->pos.z + (npc->collisionRadius * z * 0.2f), -npc->yaw, D_80077C34);
        D_80077C34 = !D_80077C34;
    }
}

void func_8003E0D4(Npc* npc, s32 arg1) {
    if (D_80077C38++ >= 4) {
        f32 theta;
        f32 sinTheta;
        f32 cosTheta;

        D_80077C38 = 0;
        theta = DEG_TO_RAD(clamp_angle(-npc->yaw));
        sinTheta = sin_rad(theta);
        cosTheta = cos_rad(theta);
        fx_falling_leaves(1, npc->pos.x + (npc->collisionRadius * sinTheta * 0.2f),
                  40.0f, npc->pos.z + (npc->collisionRadius * cosTheta * 0.2f));
    }
}

void func_8003E1D0(Npc* npc, s32 arg1) {
    if (D_80077C3A++ >= 4) {
        f32 temp_f20;
        f32 x;
        f32 z;

        D_80077C3A = 0;
        temp_f20 = DEG_TO_RAD(clamp_angle(-npc->yaw));
        x = sin_rad(temp_f20);
        z = cos_rad(temp_f20);
        fx_rising_bubble(0, npc->pos.x + (npc->collisionRadius * x * 0.2f), npc->pos.y + 0.0f,
                  npc->pos.z + (npc->collisionRadius * z * 0.2f), 0.0f);
    }
}

void COPY_set_defeated(s32 mapID, s32 encounterID) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 encounterIdx = encounterID / 32;
    s32 encounterShift;
    s32 flag;

    flag = encounterID % 32;
    encounterShift = flag;
    flag = currentEncounter->defeatFlags[mapID][encounterIdx];
    currentEncounter->defeatFlags[mapID][encounterIdx] = flag | (1 << encounterShift);

    // TODO: The below should work but has regalloc issues:
    /*EncounterStatus *currentEncounter = &gCurrentEncounter;
    s32 encounterIdx = encounterID / 32;
    s32 encounterShift = encounterID % 32;

    currentEncounter->defeatFlags[mapID][encounterIdx] |= (1 << encounterShift);*/
}

void init_encounter_status(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(currentEncounter->encounterList); i++) {
        currentEncounter->encounterList[i] = 0;
    }

    currentEncounter->flags = ENCOUNTER_STATUS_FLAGS_0;
    currentEncounter->numEncounters = 0;
    currentEncounter->firstStrikeType = FIRST_STRIKE_NONE;
    currentEncounter->hitType = 0;
    currentEncounter->battleTriggerCooldown = 0;
    currentEncounter->npcGroupList = 0;
    currentEncounter->unk_08 = 0;
    currentEncounter->dropWhackaBump = 0;

    for (i = 0; i < ARRAY_COUNT(currentEncounter->defeatFlags); i++) {
        for (j = 0; j < ARRAY_COUNT(currentEncounter->defeatFlags[i]); j++) {
            currentEncounter->defeatFlags[i][j] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(currentEncounter->recentMaps); i++) {
        currentEncounter->recentMaps[i] = -1;
    }

    func_80045AC0();
    gGameState = 0;
    create_generic_entity_world(0, npc_dyn_entity_draw_no_op);
}

void clear_encounter_status(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(currentEncounter->encounterList); i++) {
        currentEncounter->encounterList[i] = 0;
    }

    if (gGameStatusPtr->didAreaChange) {
        for (i = 0; i < ARRAY_COUNT(currentEncounter->defeatFlags); i++) {
            for (j = 0; j < ARRAY_COUNT(currentEncounter->defeatFlags[i]); j++) {
                currentEncounter->defeatFlags[i][j] = 0;
            }
        }

        if (gGameStatusPtr->didAreaChange) {
            for (i = 0; i < ARRAY_COUNT(currentEncounter->recentMaps); i++) {
                currentEncounter->recentMaps[i] = -1;
            }
        }
    }

    currentEncounter->numEncounters = 0;
    currentEncounter->firstStrikeType = FIRST_STRIKE_NONE;
    currentEncounter->hitType = 0;
    currentEncounter->battleTriggerCooldown = 0;
    currentEncounter->currentAreaIndex = gGameStatusPtr->areaID;
    currentEncounter->currentMapIndex = gGameStatusPtr->mapID;
    currentEncounter->currentEntryIndex = gGameStatusPtr->entryID;
    currentEncounter->npcGroupList = 0;
    currentEncounter->unk_08 = 0;
    currentEncounter->unk_12 = 0;

    func_80045AC0();
    gGameState = 0;
    create_generic_entity_world(NULL, npc_dyn_entity_draw_no_op);
}

void func_8003E50C(void) {
}

void func_8003E514(s8 arg0) {
    gCurrentEncounter.unk_08 = arg0;
}

void update_encounters(void) {
    switch (gGameState) {
        case 0:
            break;
        case 1:
            create_encounters();
            break;
        case 2:
            update_encounters_neutral();
            break;
        case 3:
            update_encounters_pre_battle();
            break;
        case 4:
            update_encounters_conversation();
            break;
        case 5:
            update_encounters_post_battle();
            break;
    }

    update_merlee_messages();
}

void draw_encounter_ui(void) {
    switch (gGameState) {
        case 0:
            break;
        case 1:
            init_encounters_ui();
            break;
        case 2:
            draw_encounters_neutral();
            break;
        case 3:
            draw_encounters_pre_battle();
            break;
        case 4:
            draw_encounters_conversation();
            break;
        case 5:
            draw_encounters_post_battle();
            break;
    }

    draw_merlee_messages();
}

void draw_first_strike_ui(void) {
    switch (gGameState) {
        case 0:
        default:
            break;
        case 3:
            show_first_strike_message();
    }
}

void npc_dyn_entity_draw_no_op(void) {
}

void make_npcs(s32 flags, s32 mapID, s32* npcGroupList) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    currentEncounter->resetMapEncounterFlags = flags;
    currentEncounter->mapID = mapID;
    currentEncounter->npcGroupList = npcGroupList;

    if (gGameStatusPtr->didAreaChange) {
        for (i = 0; i < ARRAY_COUNT(currentEncounter->defeatFlags); i++) {
            for (j = 0; j < ARRAY_COUNT(currentEncounter->defeatFlags[i]); j++) {
                currentEncounter->defeatFlags[i][j] = 0;
            }
        }

        if (gGameStatusPtr->didAreaChange) {
            for (i = 0; i < ARRAY_COUNT(currentEncounter->recentMaps); i++) {
                currentEncounter->recentMaps[i] = -1;
            }
        }
    }

    if (npcGroupList != NULL) {
        gGameState = 1;
        D_8009A678 = 1;
        D_8009A5D0 = 0;
    }
}

s32 kill_encounter(Enemy* enemy) {
    Encounter* encounter = gCurrentEncounter.encounterList[enemy->encounterIndex];
    s32 i;

    for (i = 0; i < encounter->count; i++) {
        Enemy* currentEnemy = encounter->enemy[i];
        if (currentEnemy != NULL) {
            kill_enemy(currentEnemy);
            encounter->enemy[i] = NULL;
        }
    }
}

void kill_enemy(Enemy* enemy) {
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    Encounter* encounter = encounterStatus->encounterList[enemy->encounterIndex];
    s32 i;
    s32 j;

    for (i = 0; i < encounter->count; i++) {
        Enemy* currentEnemy = encounter->enemy[i];
        if (currentEnemy == enemy) {
            break;
        }
    }

    if (enemy->initScript != NULL) {
        kill_script_by_ID(enemy->initScriptID);
    }
    if (enemy->interactScript != NULL) {
        kill_script_by_ID(enemy->interactScriptID);
    }
    if (enemy->aiScript != NULL) {
        kill_script_by_ID(enemy->aiScriptID);
    }
    if (enemy->hitScript != NULL) {
        kill_script_by_ID(enemy->hitScriptID);
    }
    if (enemy->auxScript != NULL) {
        kill_script_by_ID(enemy->auxScriptID);
    }
    if (enemy->defeatScript != NULL) {
        kill_script_by_ID(enemy->defeatScriptID);
    }

    enemy->interactBytecode = NULL;
    enemy->aiBytecode = NULL;
    enemy->hitBytecode = NULL;
    enemy->auxBytecode = NULL;
    enemy->defeatBytecode = NULL;

    free_npc(get_npc_unsafe(enemy->npcID));

    if (enemy->unk_64 != NULL) {
        heap_free(enemy->unk_64);
    }

    for (j = 0; j < ARRAY_COUNT(encounter->enemy); j++) {
        if (encounter->enemy[j] == enemy) {
            encounter->enemy[j] = NULL;
        }
    }

    do {
        if (!(enemy->flags & ENEMY_FLAGS_4)) {
            if (!(enemy->flags & ENEMY_FLAGS_8) || (enemy == encounterStatus->currentEnemy)) {
                if (!(enemy->flags & ENEMY_FLAGS_1)) {
                    if (!(enemy->flags & ENEMY_FLAGS_10)) {
                        COPY_set_defeated(encounterStatus->mapID, encounter->encounterID + i);
                    }
                }
            }
        }
    } while (0); // required to match

    heap_free(enemy);
}

s32 bind_enemy_ai(Enemy* enemy, EvtScript* aiScriptBytecode) {
    Evt* aiScript;
    s32 id;

    if (enemy->aiScript != NULL) {
        kill_script_by_ID(enemy->aiScript->id);
    }
    enemy->aiBytecode = aiScriptBytecode;
    aiScript = enemy->aiScript = start_script(aiScriptBytecode, EVT_PRIORITY_A, 0);
    id = enemy->aiScriptID = aiScript->id;
    aiScript->owner1.enemy = enemy;
    return id;
}

s32 bind_enemy_aux(Enemy* enemy, EvtScript* auxScriptBytecode) {
    Evt* auxScript;
    s32 id;

    if (enemy->auxScript != NULL) {
        kill_script_by_ID(enemy->auxScript->id);
    }
    enemy->auxBytecode = auxScriptBytecode;
    auxScript = enemy->auxScript = start_script(auxScriptBytecode, EVT_PRIORITY_A, 0);
    id = enemy->auxScriptID = auxScript->id;
    auxScript->owner1.enemy = enemy;
    return id;
}

s32 bind_enemy_interact(Enemy* enemy, EvtScript* interactScriptBytecode) {
    Evt* interactScript;
    s32 id;

    if (enemy->interactScript != NULL) {
        kill_script_by_ID(enemy->interactScript->id);
    }
    enemy->interactBytecode = interactScriptBytecode;
    interactScript = enemy->interactScript = start_script(interactScriptBytecode, EVT_PRIORITY_A, 0);
    id = enemy->interactScriptID = interactScript->id;
    interactScript->owner1.enemy = enemy;
    return id;
}

void bind_npc_ai(s32 npcID, EvtScript* npcAiBytecode) {
    EncounterStatus* currentEncounterStatus = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounterStatus->numEncounters; i++) {
        Encounter* currentEncounter = currentEncounterStatus->encounterList[i];
        if (currentEncounter != NULL) {
            for (j = 0; j < currentEncounter->count; j++) {
                Enemy* currentEnemy = currentEncounter->enemy[j];
                if ((currentEnemy != NULL) && (currentEnemy->npcID == npcID)) {
                    bind_enemy_ai(currentEnemy, npcAiBytecode);
                    break;
                }
            }
        }
    }
}

void bind_npc_aux(s32 npcID, EvtScript* npcAuxBytecode) {
    EncounterStatus* currentEncounterStatus = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounterStatus->numEncounters; i++) {
        Encounter* currentEncounter = currentEncounterStatus->encounterList[i];
        if (currentEncounter != NULL) {
            for (j = 0; j < currentEncounter->count; j++) {
                Enemy* currentEnemy = currentEncounter->enemy[j];
                if ((currentEnemy != NULL) && (currentEnemy->npcID == npcID)) {
                    bind_enemy_aux(currentEnemy, npcAuxBytecode);
                    break;
                }
            }
        }
    }
}

void bind_npc_interact(s32 npcID, EvtScript* npcInteractBytecode) {
    EncounterStatus* currentEncounterStatus = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounterStatus->numEncounters; i++) {
        Encounter* currentEncounter = currentEncounterStatus->encounterList[i];
        if (currentEncounter != NULL) {
            for (j = 0; j < currentEncounter->count; j++) {
                Enemy* currentEnemy = currentEncounter->enemy[j];
                if ((currentEnemy != NULL) && (currentEnemy->npcID == npcID)) {
                    bind_enemy_interact(currentEnemy, npcInteractBytecode);
                    break;
                }
            }
        }
    }
}

Enemy* get_enemy(s32 npcID) {
    EncounterStatus* currentEncounterStatus = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounterStatus->numEncounters; i++) {
        Encounter* currentEncounter = currentEncounterStatus->encounterList[i];
        if (currentEncounter != NULL) {
            for (j = 0; j < currentEncounter->count; j++) {
                Enemy* currentEnemy = currentEncounter->enemy[j];
                if ((currentEnemy != NULL) && (currentEnemy->npcID == npcID)) {
                    return currentEnemy;
                }
            }
        }
    }
    PANIC();
}

Enemy* get_enemy_safe(s32 npcID) {
    EncounterStatus* currentEncounterStatus = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounterStatus->numEncounters; i++) {
        Encounter* currentEncounter = currentEncounterStatus->encounterList[i];

        if (currentEncounter != NULL) {
            for (j = 0; j < currentEncounter->count; j++) {
                Enemy* currentEnemy = currentEncounter->enemy[j];
                if ((currentEnemy != NULL) && (currentEnemy->npcID == npcID)) {
                    return currentEnemy;
                }
            }
        }
    }
    return NULL;
}
