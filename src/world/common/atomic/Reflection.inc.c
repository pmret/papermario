/// This include provides functions and scripts for setting up mirror reflections for the player and partner, used in
/// Crystal Palace (area_pra).
///
/// See also tst_11, which has a more primitive reflection implementation.

#include "common.h"
#include "npc.h"
#include "sprite.h"

enum Reflection {
    REFLECTION_FLOOR_WALL,
    REFLECTION_FLOOR,
    REFLECTION_WALL,
};

void N(worker_reflect_player_wall)(void);
void N(worker_reflect_player_floor)(void);
void N(appendGfx_reflect_player_wall)(PlayerStatus* playerStatus);
void N(appendGfx_reflect_player_floor_fancy)(PlayerStatus* playerStatus);
void N(appendGfx_reflect_player_floor_basic)(PlayerStatus* playerStatus);
void N(worker_reflect_partner_all)(void);
void N(worker_reflect_partner_floor)(void);
void N(worker_reflect_partner_wall)(void);

s32 N(reflection_unk_resolve_anim)(s32 playerAnim) {
    AnimID temp;

    playerAnim &= ~SPRITE_ID_BACK_FACING;
    temp = playerAnim + ~ANIM_Mario_6000B;
    if (temp < 16 && temp & 1) {
        playerAnim--;
    }

    return playerAnim;
}

s32 N(reflection_unk_change_anim_facing)(s32 playerAnim) {
    s32 sprIndex = (playerAnim >> 0x10) & 0xFF;
    u32 temp;

    switch (sprIndex) {
        case SPR_Mario_1:
            if (playerAnim > ANIM_Mario_1000C) {
                return playerAnim;
            }
            break;
        case SPR_Mario_6:
            temp = playerAnim + ~ANIM_Mario_6000B;
            if (temp < 16) {
                if (temp & 1) {
                    return playerAnim;
                } else {
                    return playerAnim + 1;
                }
            }
            break;
        case SPR_Mario_8:
        case SPR_Mario_9:
            return playerAnim;
    }

    return playerAnim | SPRITE_ID_BACK_FACING;
}

API_CALLABLE(N(EnableWallReflection)){
    script->array[0] = (s32) create_worker_world(NULL, N(worker_reflect_player_wall));
    return ApiStatus_DONE2;
}

void N(worker_reflect_player_wall)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 anim;
    EntityModel* entityModel;
    s32 renderMode = playerStatus->renderMode;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX, screenY, screenZ;

    if (playerStatus->flags & PS_FLAGS_HAS_REFLECTION) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->entityModelID);
        entityModel->flags |= ENTITY_MODEL_FLAGS_REFLECT;

        get_screen_coords(gCurrentCamID, playerStatus->position.x, playerStatus->position.y, -playerStatus->position.z,
                          &screenX, &screenY, &screenZ);

        anim = N(reflection_unk_resolve_anim)(playerStatus->trueAnimation);

        if (playerStatus->targetYaw > 135.0f && playerStatus->targetYaw < 225.0f) {
            anim = N(reflection_unk_change_anim_facing)(anim);
        }

        spr_update_player_sprite(2, anim, 1.0f);

        if (!(playerStatus->flags & PS_FLAGS_20000)) {
            if (playerStatus->alpha1 != D_802D9D70) {
                if (playerStatus->alpha1 < 254) {
                    renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
                    func_802DDEE4(2, -1, 7, 0, 0, 0, playerStatus->alpha1, 0);
                } else {
                    renderMode = RENDER_MODE_ALPHATEST;
                    func_802DDEE4(2, -1, 0, 0, 0, 0, 0, 0);
                }
            }
            D_802D9D70 = playerStatus->alpha1;
        } else {
            renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
            D_802D9D70 = 0;
        }

        renderTaskPtr->renderMode = renderMode;
        renderTaskPtr->appendGfxArg = playerStatus;
        renderTaskPtr->appendGfx = (void(*))N(appendGfx_reflect_player_wall);
        renderTaskPtr->distance = -screenZ;
        queue_render_task(renderTaskPtr);
    }
}

void N(appendGfx_reflect_player_wall)(PlayerStatus* playerStatus) {
    f32 yaw = -gCameras[gCurrentCamID].currentYaw;
    Matrix4f main;
    Matrix4f translation;
    Matrix4f rotation;
    Matrix4f scale;

    guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
    guRotateF(main, clamp_angle(playerStatus->pitch), 0.0f, 0.0f, 1.0f);
    guMtxCatF(rotation, main, main);
    guRotateF(rotation, yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guRotateF(rotation, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guScaleF(scale, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F);
    guMtxCatF(main, scale, main);
    guTranslateF(translation, playerStatus->position.x, playerStatus->position.y, -playerStatus->position.z - 3.0f);
    guMtxCatF(main, translation, main);
    spr_draw_player_sprite(2, 0, 0, NULL, main);
}

API_CALLABLE(N(EnableFloorReflection)){
    switch (script->varTable[0]) {
        case REFLECTION_FLOOR_WALL:
        case REFLECTION_FLOOR:
            script->array[0] = create_worker_world(NULL, N(worker_reflect_player_floor));
            gOverrideFlags |= GLOBAL_OVERRIDES_80;
            break;
        case REFLECTION_WALL:
            break;
    }

    return ApiStatus_DONE2;
}

void N(worker_reflect_player_floor)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EntityModel* entityModel;
    s32 renderMode = playerStatus->renderMode;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX, screenY, screenZ;

    if (playerStatus->flags & PS_FLAGS_HAS_REFLECTION) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->entityModelID);

        get_screen_coords(gCurrentCamID, playerStatus->position.x, -playerStatus->position.y, playerStatus->position.z,
                          &screenX, &screenY, &screenZ);

        spr_update_player_sprite(1, playerStatus->trueAnimation, 1.0f);

        if (!(playerStatus->flags & PS_FLAGS_20000)) {
            if (playerStatus->alpha1 != D_802D9D71) {
                if (playerStatus->alpha1 < 254) {
                    renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
                    func_802DDEE4(1, -1, 7, 0, 0, 0, playerStatus->alpha1, 0);
                } else {
                    renderMode = RENDER_MODE_ALPHATEST;
                    func_802DDEE4(1, -1, 0, 0, 0, 0, 0, 0);
                }
            }
            D_802D9D71 = playerStatus->alpha1;
        } else {
            renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
            D_802D9D71 = 0;
        }

        renderTaskPtr->renderMode = renderMode;
        renderTaskPtr->appendGfxArg = playerStatus;
        renderTaskPtr->distance = -screenZ;
        renderTaskPtr->appendGfx = (void (*)(void*)) (
            !(playerStatus->flags & PS_FLAGS_20000)
                ? N(appendGfx_reflect_player_floor_basic)
                : N(appendGfx_reflect_player_floor_fancy)
        );
        queue_render_task(renderTaskPtr);
    }
}

void N(appendGfx_reflect_player_floor_basic)(PlayerStatus* playerStatus) {
    f32 yaw = -gCameras[gCurrentCamID].currentYaw;
    Matrix4f main;
    Matrix4f translation;
    Matrix4f rotation;
    Matrix4f scale;
    s32 flags;

    guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
    guRotateF(main, clamp_angle(playerStatus->pitch), 0.0f, 0.0f, 1.0f);
    guMtxCatF(rotation, main, main);
    guRotateF(rotation, yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guRotateF(rotation, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guScaleF(scale, SPRITE_WORLD_SCALE_F, -SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F);
    guMtxCatF(main, scale, main);
    guTranslateF(translation, playerStatus->position.x, -playerStatus->position.y, playerStatus->position.z);
    guMtxCatF(main, translation, main);

    if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
        flags = 0x10000001;
    } else {
        flags = 1;
    }

    spr_draw_player_sprite(flags, 0, 0, NULL, main);
}

void N(appendGfx_reflect_player_floor_fancy)(PlayerStatus* playerStatus) {
    Matrix4f mtx;
    Matrix4f translation;
    Matrix4f rotation;
    Matrix4f scale;
    f32 yaw;
    f32 blurAngle;
    s32 tint;
    f32 px;
    f32 py;
    f32 pz;
    s32 x;
    s32 y;
    s32 z;
    s32 i;
    s32 flags;

    for (i = 0; i < 2; i++) {
        yaw = -gCameras[gCurrentCamID].currentYaw;

        if (i == 0) {
            if ((playerStatus->spriteFacingAngle > 90.0f) && (playerStatus->spriteFacingAngle <= 180.0f)) {
                yaw = 180.0f - playerStatus->spriteFacingAngle;
            } else {
                if ((playerStatus->spriteFacingAngle > 180.0f) && (playerStatus->spriteFacingAngle <= 270.0f)) {
                    yaw = playerStatus->spriteFacingAngle - 180.0f;
                } else if ((playerStatus->spriteFacingAngle > 270.0f) && (playerStatus->spriteFacingAngle <= 360.0f)) {
                    yaw = 360.0f - playerStatus->spriteFacingAngle;
                } else {
                    yaw = playerStatus->spriteFacingAngle;
                }
            }

            tint = yaw / 25.0f;
            tint = 255 - (tint * 60);
            if (tint < 100) {
                tint = 100;
            }

            func_802DDEE4(1, -1, 6, tint, tint, tint, 255, 0);

            guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
            guRotateF(mtx, clamp_angle(playerStatus->pitch), 0.0f, 0.0f, 1.0f);
            guMtxCatF(rotation, mtx, mtx);
            px = playerStatus->position.x;
            py = playerStatus->position.y;
            pz = playerStatus->position.z;
        } else {
            // Spinning blur animation

            blurAngle = phys_get_spin_history(i, &x, &y, &z);

            if (y == 0x80000000) {
                py = playerStatus->position.y;
            } else {
                py = y;
            }

            px = playerStatus->position.x;
            pz = playerStatus->position.z;
            func_802DDEE4(1, -1, 7, 0, 0, 0, 0x40, 0);
            guRotateF(mtx, yaw, 0.0f, -1.0f, 0.0f);
            guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
            guRotateF(mtx, blurAngle, 0.0f, 1.0f, 0.0f);
            guMtxCatF(rotation, mtx, mtx);
        }

        guTranslateF(translation, 0.0f, -playerStatus->colliderHeight * 0.5f, 0.0f);
        guMtxCatF(translation, mtx, mtx);
        guRotateF(rotation, yaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtx, rotation, mtx);
        guRotateF(rotation, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtx, rotation, mtx);
        guTranslateF(translation, 0.0f, playerStatus->colliderHeight * 0.5f, 0.0f);
        guMtxCatF(mtx, translation, mtx);
        guScaleF(scale, SPRITE_WORLD_SCALE_F, -SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F);
        guMtxCatF(mtx, scale, mtx);
        guTranslateF(translation, px, -py, pz);
        guMtxCatF(mtx, translation, mtx);

        flags = 1;
        if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
            flags |= DRAW_SPRITE_UPSIDE_DOWN;
        }

        spr_draw_player_sprite(flags, 0, 0, NULL, mtx);
    }
}

/// int var0 = reflection type
/// bool var1 = enable wall reflection
API_CALLABLE(N(EnablePartnerReflection)){
    Npc* partner;

    if (script->varTable[1] == FALSE) {
        switch (script->varTable[0]) {
            case REFLECTION_FLOOR_WALL:
                script->array[1] = create_worker_world(N(worker_reflect_partner_all), NULL);
                break;
            case REFLECTION_FLOOR:
                script->array[1] = create_worker_world(N(worker_reflect_partner_floor), NULL);
                break;
            case REFLECTION_WALL:
                script->array[1] = create_worker_world(N(worker_reflect_partner_wall), NULL);
                break;
        }
    } else {
        switch (script->varTable[0]) {
            case REFLECTION_FLOOR_WALL:
            case REFLECTION_FLOOR:
                script->array[1] = create_worker_world(N(worker_reflect_partner_floor), NULL);
                break;
            case REFLECTION_WALL:
                break;
        }
    }

    partner = get_npc_safe(NPC_PARTNER);

    if (partner == NULL) {
        return ApiStatus_DONE2;
    }

    if (script->varTable[1] == FALSE) {
        switch (script->varTable[0]) {
            case REFLECTION_FLOOR_WALL:
                partner->flags |= NPC_FLAG_REFLECT_WALL | NPC_FLAG_REFLECT_FLOOR;
                break;
            case REFLECTION_FLOOR:
                partner->flags |= NPC_FLAG_REFLECT_FLOOR;
                break;
            case REFLECTION_WALL:
                partner->flags |= NPC_FLAG_REFLECT_WALL;
                break;
        }
    } else {
        switch (script->varTable[0]) {
            case REFLECTION_FLOOR_WALL:
            case REFLECTION_FLOOR:
                partner->flags |= NPC_FLAG_REFLECT_FLOOR;
                break;
            case REFLECTION_WALL:
                break;
        }
    }

    return ApiStatus_DONE2;
}

void N(worker_reflect_partner_all)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= NPC_FLAG_REFLECT_WALL | NPC_FLAG_REFLECT_FLOOR;
    }
}

void N(worker_reflect_partner_floor)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= NPC_FLAG_REFLECT_FLOOR;
    }
}

void N(worker_reflect_partner_wall)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= NPC_FLAG_REFLECT_WALL;
    }
}

// TODO: scripts in this include, e.g. the following.
// Requires most of area_pra to have its data decomped.

/*
#new:EvtScript $Script_802415D0
{
    0:  NewArray  00000010 *VarA
   10:  If  *Var1  ==  00000000
   20:      Switch  *Var0
   2C:          Case  ==  00000000
   38:              Call  $Function_802400EC ( )    // EnableWallReflection
   44:          Case  ==  00000001
   50:          Case  ==  00000002
   5C:              Call  $Function_802400EC ( )    // EnableWallReflection
   68:      EndSwitch
   70:  EndIf
   78:  Call  $Function_8024049C    ( *Var0 )       // EnableFloorReflection
   88:  Call  $Function_80240D3C    ( *Var0 )       // EnablePartnerReflection
   98:  Return
   A0:  End
}
*/
