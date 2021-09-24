/// This include provides functions and scripts for setting up mirror reflections for the player and partner, used in
/// Crystal Palace (area_pra).
///
/// See also tst_11, which has a more primitive reflection implementation.

#include "common.h"
#include "map.h"

enum Reflection {
    REFLECTION_FLOOR_WALL,
    REFLECTION_FLOOR,
    REFLECTION_WALL,
};

void N(reflection_setup_wall)(void);
void N(reflection_setup_floor)(void);
void N(reflection_render_wall)(PlayerStatus* playerStatus);
void N(reflection_render_floor_fancy)(PlayerStatus* playerStatus);
void N(reflection_render_floor)(PlayerStatus* playerStatus);
void N(SetPartnerFlagsA0000)(void);
void N(SetPartnerFlags80000)(void);
void N(SetPartnerFlags20000)(void);

s32 N(reflection_unk_resolve_anim)(s32 playerAnim) {
    u32 val;

    playerAnim &= ~0x1000000;
    val = playerAnim + ~0x6000B;
    if (val < 0x10 && val & 1) {
        playerAnim--;
    }

    return playerAnim;
}

s32 N(reflection_unk_change_anim_facing)(s32 playerAnim) {
    s32 temp_v1 = playerAnim >> 0x10;
    u32 temp_v1_2;

    switch ((u8)temp_v1) {
        case 1:
            if (playerAnim > 0x1000C) {
                return playerAnim;
            }
            break;
        case 6:
            // above function, inlined
            temp_v1_2 = playerAnim + 0xFFF9FFF4; // + ~0x0006000B
            if (temp_v1_2 < 16) {
                if (temp_v1_2 & 1) {
                    return playerAnim;
                } else {
                    return playerAnim + 1;
                }
            }
            break;
        case 8:
        case 9:
            return playerAnim;
    }

    return playerAnim | 0x1000000;
}

ApiStatus N(ReflectWall)(Evt* script, s32 isInitialCall) {
    script->array[0] = (s32) create_generic_entity_world(NULL, N(reflection_setup_wall));
    return ApiStatus_DONE2;
}

void N(reflection_setup_wall)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 anim;
    EntityModel* entityModel;
    s32 renderMode = playerStatus->renderMode;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX;
    s32 screenY;
    s32 screenZ;

    if (playerStatus->flags & 1) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->entityModelID);
        entityModel->flags |= 0x200;

        get_screen_coords(gCurrentCamID, playerStatus->position.x, playerStatus->position.y, -playerStatus->position.z,
                          &screenX, &screenY, &screenZ);

        anim = N(reflection_unk_resolve_anim)(playerStatus->trueAnimation);

        if (playerStatus->targetYaw > 135.0f && playerStatus->targetYaw < 225.0f) {
            anim = N(reflection_unk_change_anim_facing)(anim);
        }

        spr_update_player_sprite(2, anim, 1.0f);

        if (!(playerStatus->flags & 0x20000)) {
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
        renderTaskPtr->appendGfx = N(reflection_render_wall);
        renderTaskPtr->distance = -screenZ;
        queue_render_task(renderTaskPtr);
    }
}

void N(reflection_render_wall)(PlayerStatus* playerStatus) {
    f32 yaw = -gCameras[gCurrentCamID].currentYaw;
    Matrix4f main;
    Matrix4f translation;
    Matrix4f rotation;
    Matrix4f scale;

    guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
    guRotateF(main, clamp_angle(playerStatus->unk_8C), 0.0f, 0.0f, 1.0f);
    guMtxCatF(rotation, main, main);
    guRotateF(rotation, yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guRotateF(rotation, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guScaleF(scale, SPRITE_WORLD_SCALE, SPRITE_WORLD_SCALE, SPRITE_WORLD_SCALE);
    guMtxCatF(main, scale, main);
    guTranslateF(translation, playerStatus->position.x, playerStatus->position.y, -playerStatus->position.z - 3.0f);
    guMtxCatF(main, translation, main);
    spr_draw_player_sprite(2, 0, 0, NULL, main);
}

ApiStatus N(ReflectFloor)(Evt* script, s32 isInitialCall) {
    switch (script->varTable[0]) {
        case REFLECTION_FLOOR_WALL:
        case REFLECTION_FLOOR:
            script->array[0] = create_generic_entity_world(NULL, N(reflection_setup_floor));
            gOverrideFlags |= 0x80;
            break;
        case REFLECTION_WALL:
            break;
    }

    return ApiStatus_DONE2;
}

void N(reflection_setup_floor)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EntityModel* entityModel;
    s32 renderMode = playerStatus->renderMode;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX;
    s32 screenY;
    s32 screenZ;

    if (playerStatus->flags & 1) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->entityModelID);

        get_screen_coords(gCurrentCamID, playerStatus->position.x, -playerStatus->position.y, playerStatus->position.z,
                          &screenX, &screenY, &screenZ);

        spr_update_player_sprite(1, playerStatus->trueAnimation, 1.0f);

        if (!(playerStatus->flags & 0x20000)) {
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
        renderTaskPtr->appendGfx = (!(playerStatus->flags & 0x20000) ?
                                    N(reflection_render_floor) :
                                    N(reflection_render_floor_fancy));
        queue_render_task(renderTaskPtr);
    }
}

void N(reflection_render_floor)(PlayerStatus* playerStatus) {
    f32 yaw = -gCameras[gCurrentCamID].currentYaw;
    Matrix4f main;
    Matrix4f translation;
    Matrix4f rotation;
    Matrix4f scale;
    s32 flags;

    guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
    guRotateF(main, clamp_angle(playerStatus->unk_8C), 0.0f, 0.0f, 1.0f);
    guMtxCatF(rotation, main, main);
    guRotateF(rotation, yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guRotateF(rotation, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guScaleF(scale, SPRITE_WORLD_SCALE, -SPRITE_WORLD_SCALE, SPRITE_WORLD_SCALE);
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

void N(reflection_render_floor_fancy)(PlayerStatus* playerStatus) {
    Matrix4f main;
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
            guRotateF(main, clamp_angle(playerStatus->unk_8C), 0.0f, 0.0f, 1.0f);
            guMtxCatF(rotation, main, main);
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
            guRotateF(main, yaw, 0.0f, -1.0f, 0.0f);
            guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
            guRotateF(main, blurAngle, 0.0f, 1.0f, 0.0f);
            guMtxCatF(rotation, main, main);
        }

        guTranslateF(translation, 0.0f, -playerStatus->colliderHeight * 0.5f, 0.0f);
        guMtxCatF(translation, main, main);
        guRotateF(rotation, yaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(main, rotation, main);
        guRotateF(rotation, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
        guMtxCatF(main, rotation, main);
        guTranslateF(translation, 0.0f, playerStatus->colliderHeight * 0.5f, 0.0f);
        guMtxCatF(main, translation, main);
        guScaleF(scale, SPRITE_WORLD_SCALE, -SPRITE_WORLD_SCALE, SPRITE_WORLD_SCALE);
        guMtxCatF(main, scale, main);
        guTranslateF(translation, px, -py, pz);
        guMtxCatF(main, translation, main);

        if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
            flags = 0x10000001;
        } else {
            flags = 1;
        }

        spr_draw_player_sprite(flags, 0, 0, 0, &main);
    }
}

/// int var0 = reflection type
/// bool var1 = enable wall reflection
ApiStatus N(ReflectPartner)(Evt* script, s32 isInitialCall) {
    Npc* partner;

    if (script->varTable[1] == FALSE) {
        switch (script->varTable[0]) {
            case REFLECTION_FLOOR_WALL:
                script->array[1] = create_generic_entity_world(N(SetPartnerFlagsA0000), NULL);
                break;
            case REFLECTION_FLOOR:
                script->array[1] = create_generic_entity_world(N(SetPartnerFlags80000), NULL);
                break;
            case REFLECTION_WALL:
                script->array[1] = create_generic_entity_world(N(SetPartnerFlags20000), NULL);
                break;
        }
    } else {
        switch (script->varTable[0]) {
            case REFLECTION_FLOOR_WALL:
            case REFLECTION_FLOOR:
                script->array[1] = create_generic_entity_world(N(SetPartnerFlags80000), NULL);
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

void N(SetPartnerFlagsA0000)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= NPC_FLAG_REFLECT_WALL | NPC_FLAG_REFLECT_FLOOR;
    }
}

void N(SetPartnerFlags80000)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= NPC_FLAG_REFLECT_FLOOR;
    }
}

void N(SetPartnerFlags20000)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= NPC_FLAG_REFLECT_WALL;
    }
}

// TODO: scripts in this include, e.g. the following.
// Requires most of area_pra to have its data decomped.

/*
#new:EvtSource $Script_802415D0
{
    0:  NewArray  00000010 *VarA
   10:  If  *Var1  ==  00000000
   20:      Switch  *Var0
   2C:          Case  ==  00000000
   38:              Call  $Function_802400EC ( )    // ReflectWall
   44:          Case  ==  00000001
   50:          Case  ==  00000002
   5C:              Call  $Function_802400EC ( )    // ReflectWall
   68:      EndSwitch
   70:  EndIf
   78:  Call  $Function_8024049C    ( *Var0 )       // ReflectFloor
   88:  Call  $Function_80240D3C    ( *Var0 )       // ReflectPartner
   98:  Return
   A0:  End
}
*/
