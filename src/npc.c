#include "common.h"
#include "map.h"
#include "npc.h"
#include "effects.h"

extern s16 D_8010C97A;
extern s32 D_8010C978;

extern f32 D_80077C10;
extern s16 D_80077C14;

extern f32 D_80077C18;
extern s16 D_80077C1C;
extern s16 D_80077C1E;
extern s32 D_80077C20;

extern s16 D_80077C30;
extern s32 D_80077C34;
extern s16 D_80077C3A;

void STUB_npc_callback(void) {
}

void mtx_ident_mirror_y(Matrix4f mtx) {
    guMtxIdentF(*mtx);
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

s32 _create_npc(NpcBlueprint* blueprint, NpcAnimID** animList, s32 skipLoadingAnims) {
    Npc* npc;
    s32 i;
    s32 j;

    for (i = 0; i < MAX_NPCS; i++) {
        if ((*gCurrentNpcListPtr)[i] == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_NPCS);

    (*gCurrentNpcListPtr)[i] = npc = heap_malloc(sizeof(Npc));
    gNpcCount++;
    ASSERT(npc != NULL);

    npc->flags = blueprint->flags | (NPC_FLAG_400000 | NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_HAS_SHADOW | NPC_FLAG_PASSIVE);
    if (skipLoadingAnims) {
        npc->flags |= NPC_FLAG_NO_ANIMS_LOADED;
    }

    npc->collisionRadius = 32;
    npc->collisionHeight = 64;
    npc->renderMode = 13;
    npc->blurBuf = NULL;
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
    npc->unk_AB = 0;
    npc->alpha = 255;
    npc->alpha2 = 255;
    npc->jumpScale = 1.0f;
    npc->moveSpeed = 4.0f;
    npc->scale.x = 1.0f;
    npc->scale.y = 1.0f;
    npc->scale.z = 1.0f;
    npc->currentAnim.w = blueprint->initialAnim;
    npc->animationSpeed = 1.0f;
    npc->renderYaw = 0.0f;
    npc->unk_98 = 0;
    npc->unk_A2 = 0;
    npc->unk_80 = 0x20000;
    npc->isFacingAway = 0;
    npc->yawCamOffset = 0;
    npc->turnAroundYawAdjustment = 0;
    npc->unk_84 = -1;
    npc->unk_86 = -1;
    npc->unk_B4 = 0;
    npc->unk_B5 = 0;
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
                npc->spriteInstanceID = spr_load_npc_sprite(npc->currentAnim.w, animList);
            } else {
                npc->spriteInstanceID = spr_load_npc_sprite(npc->currentAnim.w | 0x80000000, animList);
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

void _create_npc_standard(NpcBlueprint* blueprint, NpcAnimID** animList) {
    _create_npc(blueprint, animList, FALSE);
}

void _create_npc_partner(NpcBlueprint* blueprint) {
    _create_npc(blueprint, NULL, TRUE);
}

void free_npc_by_index(s32 listIndex) {
    Npc* npc;
    s32 i;

    listIndex &= ~0x800;

    npc = (*gCurrentNpcListPtr)[listIndex];
    if (npc != NULL) {
        if (npc->flags) {
            if (npc->blurBuf != NULL) {
                heap_free(npc->blurBuf);
                npc->blurBuf = NULL;
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

    if (npc->blurBuf != NULL) {
        heap_free(npc->blurBuf);
        npc->blurBuf = NULL;
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

    if (npc->flags & 0x40) {
        npc->flags |= NPC_FLAG_8000000;
    } else if ((npc->pos.x != npc->colliderPos.x) || (npc->pos.y != npc->colliderPos.y)
               || (npc->pos.z != npc->colliderPos.z) || npc->flags & NPC_FLAG_8000000) {
        npc->flags &= ~NPC_FLAG_8000000;
        temp_f0 = clamp_angle(npc->yaw);
        temp_x = npc->pos.x;
        temp_y = npc->pos.y;
        temp_z = npc->pos.z;

        if (!(npc->flags & NPC_FLAG_PARTICLE)) {
            phi_v0 = npc_test_move_simple_with_slipping(npc->unk_80, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
        } else {
            phi_v0 = npc_test_move_complex_with_slipping(npc->unk_80, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
        }

        if (phi_v0) {
            npc->flags |= (NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_4000);
            npc->unk_86 = D_8010C97A;
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
            phi_v0 = npc_test_move_simple_with_slipping(npc->unk_80, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
        } else {
            phi_v0 = npc_test_move_taller_with_slipping(npc->unk_80, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
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
            phi_v0 = npc_test_move_simple_with_slipping(npc->unk_80, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
        } else {
            phi_v0 = npc_test_move_taller_with_slipping(npc->unk_80, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight, npc->collisionRadius);
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
            if (npc_test_move_simple_with_slipping(npc->unk_80, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight,
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
            if (npc_test_move_simple_with_slipping(npc->unk_80, &temp_x, &temp_y, &temp_z, 0, temp_f0, npc->collisionHeight,
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

INCLUDE_ASM(void, "npc", npc_do_other_npc_collision, Npc* npc);

INCLUDE_ASM(s32, "npc", npc_do_player_collision, Npc* npc);

INCLUDE_ASM(void, "npc", npc_do_gravity, Npc* npc);

s32 func_800397E8(Npc* npc, f32 arg1) {
    if (!(npc->flags & NPC_FLAG_208)) {
        f32 x;
        f32 y;
        f32 z;
        f32 subroutine_arg;
        f32 temp_v1;
        s32 phi_v0;

        if (npc->flags & NPC_FLAG_NO_Y_MOVEMENT) {
            npc->flags &= ~NPC_FLAG_1000;
            return 0;
        }

        temp_v1 = fabsf(arg1) + 16;
        subroutine_arg = temp_v1;
        x = npc->pos.x;
        y = npc->pos.y + 13;
        z = npc->pos.z;

        if (!(npc->flags & NPC_FLAG_PARTICLE)) {
            phi_v0 = npc_raycast_down_sides(npc->unk_80, &x, &y, &z, &subroutine_arg);
        } else {
            phi_v0 = npc_raycast_down_ahead(npc->unk_80, &x, &y, &z, &subroutine_arg, npc->yaw,
                                            npc->collisionRadius);
        }

        if (phi_v0 != 0 && subroutine_arg <= temp_v1) {
            npc->pos.y = y;
            npc->unk_84 = D_8010C97A;
            npc->flags |= NPC_FLAG_1000;
            return 1;
        }
    } else {
        return 0;
    }

    npc->flags &= ~NPC_FLAG_1000;
    return 0;
}

INCLUDE_ASM(void, "npc", update_npcs, void);

INCLUDE_ASM(f32, "npc", npc_get_render_yaw);

#ifdef NON_MATCHING
// float regalloc
void appendGfx_npc(Npc* npc) {
    Matrix4f subroutine_arg6;
    Matrix4f subroutine_arg16;
    f32 temp_f22 = npc_get_render_yaw();

    guTranslateF(subroutine_arg6, npc->pos.x, npc->pos.y + npc->unk_AB, npc->pos.z);
    if (npc->flags & NPC_FLAG_80) {
        mtx_ident_mirror_y(subroutine_arg16);
        guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
    }

    if (npc->rotationVerticalPivotOffset != 0.0f) {
        guTranslateF(subroutine_arg16, 0.0f, npc->rotationVerticalPivotOffset, 0.0f);
        guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
    }

    if (npc->rotation.y != 0.0f) {
        guRotateF(subroutine_arg16, npc->rotation.y, 0.0f, 1.0f, 0.0f);
        guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
    }

    if (npc->rotation.x != 0.0f) {
        guRotateF(subroutine_arg16, npc->rotation.x, 1.0f, 0.0f, 0.0f);
        guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
    }

    if (npc->rotation.z != 0.0f) {
        guRotateF(subroutine_arg16, npc->rotation.z, 0.0f, 0.0f, 1.0f);
        guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
    }

    if (npc->rotationVerticalPivotOffset != 0.0f) {
        guTranslateF(subroutine_arg16, 0.0f, -npc->rotationVerticalPivotOffset, 0.0f);
        guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
    }

    if ((npc->screenSpaceOffset2D[0] != 0.0f) || (npc->screenSpaceOffset2D[1] != 0.0f)) {
        guTranslateF(subroutine_arg6, npc->screenSpaceOffset2D[0], npc->screenSpaceOffset2D[1], 0.0f);
        guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
    }

    if ((npc->scale.x * (5.0 / 7) != 1.0f) || ((npc->scale.y * npc->verticalStretch) * (5.0 / 7) != 1.0f)
        || (npc->scale.z * (5.0 / 7) != 1.0f)) {
        guScaleF(subroutine_arg16, npc->scale.x * (5.0 / 7), (npc->scale.y * npc->verticalStretch) * (5.0 / 7),
                 npc->scale.z * (5.0 / 7));
        guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
    }

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        if (!(npc->flags & NPC_FLAG_100000) && (npc->currentAnim.w != 0) && (npc->spriteInstanceID >= 0)) {
            npc_draw_with_palswap(npc, temp_f22, subroutine_arg6);
            npc->unk_2C = func_802DE5C8(npc->spriteInstanceID);
        }
    } else {
        npc_draw_with_palswap(npc, temp_f22, subroutine_arg6);
        npc->unk_2C = func_802DDEC4(1);
    }

    if (npc->flags & NPC_FLAG_REFLECT_WALL) {
        guTranslateF(subroutine_arg6, npc->pos.x, npc->pos.y + npc->unk_AB, -npc->pos.z);
        if (npc->flags & NPC_FLAG_80) {
            mtx_ident_mirror_y(subroutine_arg16);
            guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
        }
        if ((npc->rotation.y != 0.0f) || (npc->rotation.x != 0.0f) || (npc->rotation.z != 0.0f)) {
            guRotateRPYF(subroutine_arg16, npc->rotation.x, npc->rotation.y, npc->rotation.z);
            guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
        }

        if ((npc->scale.x * (5.0 / 7) != 1.0f) || ((npc->scale.y * npc->verticalStretch) * (5.0 / 7) != 1.0f)
            || (npc->scale.z * (5.0 / 7) != 1.0f)) {
            guScaleF(subroutine_arg16, npc->scale.x * (5.0 / 7), (npc->scale.y * npc->verticalStretch) * (5.0 / 7),
                     npc->scale.z * (5.0 / 7));
            guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
        }

        if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
            if (!(npc->flags & NPC_FLAG_1000000) && (npc->currentAnim.w != 0)) {
                spr_draw_npc_sprite(npc->spriteInstanceID, temp_f22, 0, 0, subroutine_arg6);
            }
        } else {
            spr_draw_player_sprite(0x40000001, temp_f22, 0, 0, subroutine_arg6);
        }
    }

    if (npc->flags & NPC_FLAG_REFLECT_FLOOR) {
        guTranslateF(subroutine_arg6, npc->pos.x, -(npc->pos.y + npc->unk_AB), npc->pos.z);
        mtx_ident_mirror_y(subroutine_arg16);
        guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);

        if (npc->rotation.y != 0.0f || npc->rotation.x != 0.0f || npc->rotation.z != 0.0f) {
            guRotateRPYF(subroutine_arg16, npc->rotation.x, npc->rotation.y, npc->rotation.z);
            guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
        }

        if ((npc->scale.x * (5.0 / 7) != 1.0f) || ((npc->scale.y * npc->verticalStretch) * (5.0 / 7) != 1.0f)
            || (npc->scale.z * (5.0 / 7) != 1.0f)) {
            guScaleF(subroutine_arg16, npc->scale.x * (5.0 / 7), (npc->scale.y * npc->verticalStretch) * (5.0 / 7),
                     npc->scale.z * (5.0 / 7));
            guMtxCatF(subroutine_arg16, subroutine_arg6, subroutine_arg6);
        }

        if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
            if (!(npc->flags & NPC_FLAG_1000000) && (npc->currentAnim.w != 0)) {
                spr_draw_npc_sprite(npc->spriteInstanceID, temp_f22, 0, 0, subroutine_arg6);
            }
        } else {
            spr_draw_player_sprite(0x40000001, temp_f22, 0, 0, subroutine_arg6);
        }
    }
    npc->onRender(npc);
}
#else
INCLUDE_ASM(void, "npc", appendGfx_npc, Npc* npc);
#endif

void render_npcs(void) {
    f32 temp_f20;
    Npc* npc;
    f32 phi_f20;
    s32 i;
    RenderTask renderTask;
    RenderTask* task = &renderTask; // WTF?
    f32 x;
    f32 y;
    f32 z;
    f32 s;
    Camera* cam = &gCameras[gCurrentCamID];

    for (i = 0; i < MAX_NPCS; i++) {

        Npc* npc = (*gCurrentNpcListPtr)[i];
        if (npc != NULL) {
            if (npc->flags && !(npc->flags & (NPC_FLAG_80000000 | NPC_FLAG_1000000 | NPC_FLAG_4 | NPC_FLAG_2))) {
                transform_point(&cam->perspectiveMatrix, npc->pos.x, npc->pos.y, npc->pos.z, 1.0f, &x, &y, &z, &s);
                if (!(s < 0.01) || !(s > -0.01)) {
                    phi_f20 = ((z * 5000.0f) / s) + 5000.0f;
                    if (phi_f20 < 0.0f) {
                        phi_f20 = 0.0f;
                    } else if (phi_f20 > 10000.0f) {
                        phi_f20 = 10000.0f;
                    }

                    task->distance = -phi_f20;
                    task->appendGfxArg = npc;
                    task->appendGfx = &appendGfx_npc;
                    task->renderMode = npc->renderMode;
                    if (npc->flags & NPC_FLAG_NO_DROPS) {
                        u8 r, g, b, a;
                        get_background_color_blend(&r, &g, &b, &a);
                        npc->alpha2 = 0xFF - a;
                    } else {
                        npc->alpha2 = 0xFF;
                    }

                    if (npc->alpha2 != 0) {
                        queue_render_task(task);
                    }

                    if ((npc->flags & NPC_FLAG_MOTION_BLUR) != 0) {
                        task->distance = -phi_f20;
                        task->appendGfx = &appendGfx_npc_blur;
                        task->appendGfxArg = npc;
                        task->renderMode = 0x11;
                        queue_render_task(task);
                    }
                }
            }
        }
    }
}

void npc_move_heading(Npc* npc, f32 speed, f32 yaw) {
    f32 angle = (yaw * TAU) / 360.0f;
    f32 sin = sin_rad(angle);
    f32 cos = cos_rad(angle);

    npc->pos.x += speed * sin;
    npc->pos.z += -speed * cos;
}

Npc* get_npc_unsafe(NpcID npcID) {
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

Npc* get_npc_safe(NpcID npcID) {
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
        shadow->flags &= ~1;
        npc->flags = npc->flags | (NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_HAS_SHADOW);
    }
}

void disable_npc_shadow(Npc* npc) {
    Shadow* shadow;

    if (npc->flags & NPC_FLAG_HAS_SHADOW) {
        shadow = get_shadow_by_index(npc->shadowIndex);
        shadow->flags |= 1;
        npc->flags &= ~NPC_FLAG_HAS_SHADOW;
        npc->flags &= ~NPC_FLAG_DIRTY_SHADOW;
    }
}

void set_npc_sprite(Npc* npc, s32 anim, s32** extraAnimList) {
    ASSERT((npc->flags & NPC_FLAG_1000000) || spr_free_sprite(npc->spriteInstanceID) == 0);

    npc->extraAnimList = extraAnimList;

    if (!(npc->flags & NPC_FLAG_1000000)) {
        npc->spriteInstanceID = spr_load_npc_sprite(anim, extraAnimList);
        ASSERT(npc->spriteInstanceID >= 0);
    }


    npc->currentAnim.w = anim;

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        if (!(npc->flags & NPC_FLAG_1000000)) {
            spr_update_sprite(npc->spriteInstanceID, anim, npc->animationSpeed);
        }
    }
}

void enable_npc_blur(Npc* npc) {
    if (!(npc->flags & NPC_FLAG_MOTION_BLUR)) {
        BlurBuffer* blurBuf;
        s32 i;

        npc->flags |= NPC_FLAG_MOTION_BLUR;

        blurBuf = heap_malloc(sizeof(BlurBuffer));
        npc->blurBuf = blurBuf;
        ASSERT(blurBuf != NULL);
        blurBuf->unk_00 = 0;
        blurBuf->index = 0;

        for (i = 0; i < ARRAY_COUNT(blurBuf->x); i++) {
            blurBuf->x[i] = npc->pos.x;
            blurBuf->y[i] = npc->pos.y;
            blurBuf->z[i] = npc->pos.z;
        }
    }
}

void disable_npc_blur(Npc* npc) {
    if (npc->flags & NPC_FLAG_MOTION_BLUR) {
        npc->flags &= ~NPC_FLAG_MOTION_BLUR;

        heap_free(npc->blurBuf);
        npc->blurBuf = NULL;
    }
}

void update_npc_blur(Npc* npc) {
    BlurBuffer* blurBuf = npc->blurBuf;
    s32 index = blurBuf->index;

    blurBuf->x[index] = npc->pos.x;
    blurBuf->y[index] = npc->pos.y;
    blurBuf->z[index] = npc->pos.z;

    index++;
    if (index >= 20) {
        index = 0;
    }

    blurBuf->index = index;
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
                        npc->spriteInstanceID = spr_load_npc_sprite(npc->currentAnim.w, npc->extraAnimList);
                    } else {
                        npc->spriteInstanceID = spr_load_npc_sprite(npc->currentAnim.w | 0x80000000, npc->extraAnimList);
                    }
                }
                if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                    if (!(npc->flags & NPC_FLAG_1000000) && (npc->unk_B4 != 0)) {
                        npc->spritePaletteList = spr_get_npc_palettes(npc->currentAnim.h);
                        npc->paletteCount = 0;
                        while (npc->spritePaletteList[npc->paletteCount] != -1) {
                            npc->paletteCount++;
                        }
                        npc->unk_C0 = spr_get_npc_color_variations(npc->currentAnim.h);
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

void npc_set_palswap_mode_A(Npc* npc, s32 arg1) {
    if (npc->unk_B4 != arg1) {
        npc->unk_B5 = npc->unk_B4;
        npc->unk_B4 = arg1;
        npc->unk_B7 = 0;
        npc->unk_B6 = 1;
    }
}

void npc_set_palswap_mode_B(Npc* npc, s32 arg1) {
    if (npc->unk_B4 != arg1) {
        npc->unk_B5 = npc->unk_B4;
        npc->unk_B4 = arg1;
        npc->unk_B7 = 0;
        npc->unk_B6 = -1;
    }
}

void func_8003B420(Npc* npc) {
    if (npc->unk_B5 == 0) {
        npc->unk_B4 = 0;
        return;
    }
    npc->unk_B4 = npc->unk_B5;
    npc->unk_B5 = 0;
    npc->unk_B7 = 0;
    npc->unk_B6 = 1;
}

INCLUDE_ASM(s32, "npc", npc_set_palswap_1);

INCLUDE_ASM(s32, "npc", npc_set_palswap_2);

void npc_draw_with_palswap(Npc* npc, s32 arg1, s32 arg2) {
    switch (npc->unk_B4) {
        case 0:
            npc_draw_palswap_mode_0(npc, arg1, arg2);
            break;
        case 1:
            npc_draw_palswap_mode_1(npc, arg1, arg2);
            break;
        case 2:
            npc_draw_palswap_mode_2(npc, arg1, 0, arg2);
            break;
        case 3:
            npc_draw_palswap_mode_2(npc, arg1, 1, arg2);
            break;
        case 4:
            npc_draw_palswap_mode_4(npc, arg1, arg2);
            break;
    }
}

void npc_draw_palswap_mode_0(Npc* npc, s32 arg1, s32 arg2) {
    if (npc->unk_B6 != 0) {
        npc->screenSpaceOffset2D[0] = 0.0f;
        npc->screenSpaceOffset2D[1] = 0.0f;
        npc->unk_B6 = 0;
        npc->verticalStretch = 1.0f;
    }

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        s32 temp_a2 = (npc->alpha * npc->alpha2 / 255);
        s32 temp = temp_a2 < 255; // TODO: better match?
        spr_draw_npc_sprite(npc->spriteInstanceID | (temp) << 31, arg1, temp_a2, NULL, arg2);
    } else {
        spr_draw_player_sprite(0x40000001, arg1, 0, 0, arg2);
    }
}

INCLUDE_ASM(s32, "npc", npc_draw_palswap_mode_1);

INCLUDE_ASM(s32, "npc", npc_blend_palette_colors);

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
    EffectInstanceData* instanceData;

    switch (npc->decorationInitialised[idx]) {
        case 0:
            playFX_3B(2, npc->pos.x, npc->pos.y, npc->pos.z, 1.0f, &npc->decorations[idx]);
            npc->decorationInitialised[idx] = 1;
            break;
        case 1:
            break;
        default:
            return;
    }

    instanceData = npc->decorations[idx]->data;
    instanceData->pos.x = npc->pos.x;
    instanceData->pos.y = npc->pos.y;
    instanceData->pos.z = npc->pos.z;
    instanceData->scale.x = (npc->scale.x * npc->collisionRadius) * 0.01;
    instanceData->scale.y = (npc->scale.y * npc->collisionHeight) * 0.01;
    instanceData->unk_64 = npc->renderYaw;
}

void npc_remove_decoration_bowser_aura(Npc* npc, s32 idx) {
    npc->decorations[idx]->data->unk_2C = 5;
}

void npc_update_decoration_sweat(Npc* npc, s32 idx) {
    switch (npc->decorationInitialised[idx]) {
        case 0:
            if (npc->yawCamOffset > 90) {
                fx_sweat(0, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 5.0f, 45.0f, 0x14);
            } else {
                fx_sweat(0, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 5.0f, -45.0f, 0x14);
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
    EffectInstanceData* instanceData;

    switch (npc->decorationInitialised[idx]) {
        case 0:
            playFX_2F(0, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 20.0f, 3, &npc->decorations[idx]);
            npc->decorationInitialised[idx] = 1;
            return;
        case 1:
            break;
        default:
            return;

    }

    instanceData = npc->decorations[idx]->data;
    instanceData->pos.x = npc->pos.x;
    instanceData->pos.y = npc->pos.y + npc->collisionHeight;
    instanceData->pos.z = npc->pos.z;
}

void npc_remove_decoration_seeing_stars(Npc* npc, s32 idx) {
    remove_effect(npc->decorations[idx]);
}

void npc_update_decoration_glow_in_front(Npc* npc, s32 idx) {
    EffectInstanceData* instanceData;

    switch (npc->decorationInitialised[idx]) {
        case 0:
            npc->decorations[idx] = playFX_52(2, npc->pos.x, npc->pos.y + npc->collisionHeight * 0.5, npc->pos.z,
                                                  npc->scale.x * 0.8 + 0.2f, -1);
            npc->decorationInitialised[idx] = 1;
            break;
        case 1:
            instanceData = npc->decorations[idx]->data;
            instanceData->pos.x = npc->pos.x;
            instanceData->pos.y = npc->pos.y + npc->collisionHeight * 0.5 * npc->scale.x;
            instanceData->pos.z = npc->pos.z;
            instanceData->unk_30 = npc->scale.x * 0.8 + 0.2f;
            break;
    }
}

void npc_remove_decoration_glow_in_front(Npc* npc, s32 idx) {
    remove_effect(npc->decorations[idx]);
}

void npc_update_decoration_glow_behind(Npc* npc, s32 idx) {
    EffectInstanceData* instanceData;

    switch (npc->decorationInitialised[idx]) {
        case 0:
            npc->decorations[idx] = playFX_52(2, npc->pos.x, npc->pos.y + npc->collisionHeight * 0.5, npc->pos.z - 5.0f, 1.0f,
                                                  0);
            npc->decorationInitialised[idx] = 1;
            break;
        case 1:
            instanceData = npc->decorations[idx]->data;
            instanceData->pos.x = npc->pos.x;
            instanceData->pos.y = npc->pos.y + npc->collisionHeight * 0.5;
            instanceData->pos.z = npc->pos.z - 5.0f;
            instanceData->unk_30 = 1.0f;
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
#ifdef NON_MATCHING
s32 npc_find_standing_on_entity(s32 arg0) {
    s32 entityIndex = (arg0 | 0x4000);
    s32 yTemp = get_entity_by_index(entityIndex)->position.y - 10.0f;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentNpcListPtr); i++) {
        Npc* npc = (*gCurrentNpcListPtr)[i];

        if (npc != NULL && npc->flags != 0) {
            if (!(npc->flags & (0x80000000 | 0x4))) {
                if (!(npc->pos.y < yTemp)) {
                    s32 temp_v0;

                    if (npc->flags & 0x8008) {
                        temp_v0 = npc_get_collider_below(npc);
                        if (temp_v0 != 0) {
                            if (entityIndex == temp_v0) {
                                return i;
                            }
                        }
                    } else if (npc->unk_84 & 0x4000) {
                        if (entityIndex == npc->unk_84) {
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

#ifdef NON_MATCHING
// Rodata issue. Most likely the last function in the TU with a jumptable.
void func_8003D3BC(Npc* npc) {
    s32 temp_s4 = npc->unk_98;
    s32 temp_s0 = npc->unk_9A;
    s32 temp_s5 = npc->unk_9C;
    s32 temp_s2 = npc->unk_9E;
    s32 temp_s6 = npc->unk_A0;
    s32 temp_s3 = npc->unk_A2;

    func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);

    switch (temp_s4) {
        case 0:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, temp_s3);
            break;
        case 2:
        case 3:
            npc->renderMode = 13;
        case 1:
            func_802DE894(npc->spriteInstanceID, temp_s4, 0, 0, 0, 0, temp_s3);
            break;
        case 4:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, 4, temp_s0, temp_s5, temp_s2, 0, temp_s3);
            break;
        case 6:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, 6, temp_s0, temp_s5, temp_s2, 255, temp_s3);
            break;
        case 7:
            npc->renderMode = 22;
            func_802DE894(npc->spriteInstanceID, 7, 255, 255, 255, temp_s0, temp_s3);
            break;
        case 8:
            npc->renderMode = 22;
            func_802DE894(npc->spriteInstanceID, 8, temp_s0, temp_s5, temp_s2, temp_s6, temp_s3);
            break;
        case 9:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, 9, temp_s0, temp_s5, temp_s2, 255, temp_s3);
            break;
        case 10:
            npc->renderMode = 22;
            func_802DE894(npc->spriteInstanceID, 10, temp_s0, temp_s5, temp_s2, temp_s6, temp_s3);
            break;
        case 5:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, 5, temp_s0, temp_s5, temp_s2, 0, temp_s3);
            break;
        case 13:
            npc->renderMode = 22;
            func_802DE894(npc->spriteInstanceID, 13, temp_s0, temp_s5, temp_s2, temp_s6, temp_s3);
            break;
        case 14:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, 14, temp_s0, temp_s5, temp_s2, 255, temp_s3);
            break;
        case 15:
            npc->renderMode = 13;
            func_802DE894(npc->spriteInstanceID, 15, temp_s0, 255, 0, 255, temp_s3);
            break;
        case 16:
            npc->renderMode = 22;
            func_802DE894(npc->spriteInstanceID, 15, temp_s0, temp_s5, 0, temp_s5, temp_s3);
            break;
        default:
            break;
    }
}
#else
INCLUDE_ASM(void, "npc", func_8003D3BC, Npc* npc);
#endif

void func_8003D624(Npc* npc, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    npc->unk_98 = arg1;
    npc->unk_9A = arg2;
    npc->unk_9C = arg3;
    npc->unk_9E = arg4;
    npc->unk_A0 = arg5;
    npc->unk_A2 = arg6;
    func_8003D3BC(npc);
}

#ifdef NON_MATCHING
// Rodata padding issue. Most likely belongs to a separate TU than the function above with the switch.
void func_8003D660(Npc* npc, s32 arg1) {
    Temp8010EBB0* temp = &D_8010EBB0;

    if ((npc->flags & (NPC_FLAG_400000 | NPC_FLAG_2)) == NPC_FLAG_400000) {
        if (npc->moveSpeed != 0.0f) {
            switch (get_collider_type_by_id((u16)npc->unk_84) & 0xFF) {
                case 6:
                    func_8003DA38(npc, arg1);
                    return;
                case 7:
                    func_8003DC38(npc, arg1);
                    return;
                case 8:
                    if ((temp->unk_00 == 0) || (temp->unk_03 != 8)) {
                        func_8003DFA0(npc, arg1);
                        return;
                    }
                    break;
                case 9:
                    func_8003E0D4(npc, arg1);
                    return;
                case 1:
                    func_8003E1D0(npc, arg1);
                    return;
                case 2:
                case 3:
                case 4:
                case 5:
                default:
                    func_8003D788(npc, arg1);
                    return;
            }
        }
    }
}
#else
INCLUDE_ASM(void, "npc", func_8003D660, Npc* npc, s32 arg1);
#endif

void func_8003D788(Npc* npc, s32 arg1) {
    s32 phi_a2;
    f32 subroutine_argA;
    f32 subroutine_argB;

    phi_a2 = 0;
    if (gGameStatusPtr->areaID == 5) {
        phi_a2 = gGameStatusPtr->mapID == 2;
    }
    if (arg1 == 2) {
        f32 x = npc->pos.x;
        f32 y = npc->pos.y + 0.0f;
        f32 z = npc->pos.z;

        if (phi_a2 == 0) {
            fx_land(0, x, y, z, D_80077C10);
            D_80077C10 = clamp_angle(D_80077C10 + 35.0f);
        } else {
            playFX_72(3, x, y, z,  13.0f, 10.0f, 1.0f, 5, 30);
        }
    } else if (arg1 != 0) {
        if (D_80077C14++ >= 4) {
            D_80077C14 = 0;
            if (phi_a2 == 0) {
                sin_cos_rad((clamp_angle(-npc->yaw) * TAU) / 360.0f, &subroutine_argA, &subroutine_argB);
                fx_walk(0, npc->pos.x + (npc->collisionRadius * subroutine_argA * 0.2f), npc->pos.y + 1.5f,
                               npc->pos.z + (npc->collisionRadius * subroutine_argB * 0.2f), subroutine_argA, subroutine_argB);
            } else {
                sin_cos_rad((clamp_angle(npc->yaw) * TAU) / 360.0f, &subroutine_argA, &subroutine_argB);
                playFX_72(3, npc->pos.x + (npc->collisionRadius * subroutine_argA), npc->pos.y + 1.5f,
                              npc->pos.z + (npc->collisionRadius * subroutine_argB), 5.0f, 10.0f, 1.0f, 5, 30);
            }
        }
    }
}

INCLUDE_ASM(void, "npc", func_8003DA38, Npc* npc, s32 arg1);

INCLUDE_ASM(s32, "npc", func_8003DC38);

void func_8003DFA0(Npc* npc) {
    if (D_80077C30++ >= 4) {
        f32 temp_f20;
        f32 x;
        f32 z;

        D_80077C30 = 0;
        temp_f20 = (clamp_angle(-npc->yaw) * TAU) / 360.0f;
        x = sin_rad(temp_f20);
        z = cos_rad(temp_f20);
        playFX_0C(npc->pos.x + (npc->collisionRadius * x * 0.2f), npc->pos.y + 1.5f,
                  npc->pos.z + (npc->collisionRadius * z * 0.2f), -npc->yaw, D_80077C34);
        D_80077C34 = !D_80077C34;
    }
}


INCLUDE_ASM(s32, "npc", func_8003E0D4);

void func_8003E1D0(Npc* npc) {
    if (D_80077C3A++ >= 4) {
        f32 temp_f20;
        f32 x;
        f32 z;

        D_80077C3A = 0;
        temp_f20 = (clamp_angle(-npc->yaw) * TAU) / 360.0f;
        x = sin_rad(temp_f20);
        z = cos_rad(temp_f20);
        playFX_23(0, npc->pos.x + (npc->collisionRadius * x * 0.2f), npc->pos.y + 0.0f,
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

    currentEncounter->flags = 0;
    currentEncounter->numEncounters = 0;
    currentEncounter->eFirstStrike = 0;
    currentEncounter->hitType = 0;
    currentEncounter->unk_0A = 0;
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
    currentEncounter->eFirstStrike = 0;
    currentEncounter->hitType = 0;
    currentEncounter->unk_0A = 0;
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

void make_npcs(s8 flags, s8 mapID, s32* npcGroupList) {
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

#ifdef NON_MATCHING
// regalloc. s2/s3 switched
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

    if (!(enemy->flags & 4)) {
        if (!(enemy->flags & 8) || (enemy == encounterStatus->currentEnemy)) {
            if (!(enemy->flags & 1)) {
                if (!(enemy->flags & 0x10)) {
                    COPY_set_defeated((s8)encounterStatus->mapID, encounter->encounterID + i);
                }
            }
        }
    }
    heap_free(enemy);
}
#else
INCLUDE_ASM(void, "npc", kill_enemy);
#endif

s32 bind_enemy_ai(Enemy* enemy, Script* aiScriptBytecode) {
    ScriptInstance* aiScript;
    s32 id;

    if (enemy->aiScript != NULL) {
        kill_script_by_ID(enemy->aiScript->id);
    }
    enemy->aiBytecode = aiScriptBytecode;
    aiScript = enemy->aiScript = start_script(aiScriptBytecode, 0xA, 0);
    id = enemy->aiScriptID = aiScript->id;
    aiScript->owner1.enemy = enemy;
    return id;
}

s32 bind_enemy_aux(Enemy* enemy, Script* auxScriptBytecode) {
    ScriptInstance* auxScript;
    s32 id;

    if (enemy->auxScript != NULL) {
        kill_script_by_ID(enemy->auxScript->id);
    }
    enemy->auxBytecode = auxScriptBytecode;
    auxScript = enemy->auxScript = start_script(auxScriptBytecode, 0xA, 0);
    id = enemy->auxScriptID = auxScript->id;
    auxScript->owner1.enemy = enemy;
    return id;
}

s32 bind_enemy_interact(Enemy* enemy, Script* interactScriptBytecode) {
    ScriptInstance* interactScript;
    s32 id;

    if (enemy->interactScript != NULL) {
        kill_script_by_ID(enemy->interactScript->id);
    }
    enemy->interactBytecode = interactScriptBytecode;
    interactScript = enemy->interactScript = start_script(interactScriptBytecode, 0xA, 0);
    id = enemy->interactScriptID = interactScript->id;
    interactScript->owner1.enemy = enemy;
    return id;
}

void bind_npc_ai(s32 npcID, Script* npcAiBytecode) {
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

void bind_npc_aux(s32 npcID, Script* npcAuxBytecode) {
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

void bind_npc_interact(s32 npcID, Script* npcInteractBytecode) {
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
