#include "common.h"
#include "ld_addrs.h"

extern s32 D_8010C920;
extern UNK_FUN_PTR(D_8010C93C);
extern s32 D_8010C940;
extern s32 D_8010C950;
extern s32 D_8010C958;

extern s32 D_802BDF60;

void func_802B72C0_E22870();

void func_800E0514(void);

s32 player_raycast_below(f32 yaw, f32 diameter, f32* outX, f32* outY, f32* outZ, f32* outLength, f32* hitRx, f32* hitRz,
                         f32* hitDirX, f32* hitDirZ) {
    f32 x, y, z, length;
    f32 inputX, inputY, inputZ, inputLength;
    f32 cosTheta;
    f32 sinTheta;
    f32 temp_f20;
    f32 cosTemp;
    f32 sinTemp;
    s32 hitObjectID;
    s32 ret;

    *hitRx = 0.0f;
    *hitRz = 0.0f;
    *hitDirX = 0.0f;
    *hitDirZ = 0.0f;
    inputLength = *outLength;
    temp_f20 = diameter * 0.28f;
    sin_cos_rad(yaw * TAU / 360.0f, &sinTheta, &cosTheta);
    sinTemp = temp_f20 * sinTheta;
    cosTemp = -temp_f20 * cosTheta;
    inputX = *outX;
    inputY = *outY;
    inputZ = *outZ;

    x = inputX + sinTemp;
    y = inputY;
    z = inputZ + cosTemp;
    length = inputLength;
    hitObjectID = player_raycast_down(&x, &y, &z, &length);
    ret = -1;
    if (hitObjectID >= 0 && length <= fabsf(*outLength)) {
        *hitRx = -gGameStatusPtr->unk_11C.x;
        *hitRz = -gGameStatusPtr->unk_11C.z;
        *outX = x;
        *outY = y;
        *outZ = z;
        *outLength = length;
        *hitDirX = sinTemp;
        *hitDirZ = cosTemp;
        ret = hitObjectID;
    }

    x = inputX - sinTemp;
    y = inputY;
    z = inputZ - cosTemp;
    length = inputLength;
    hitObjectID = player_raycast_down(&x, &y, &z, &length);
    if (hitObjectID >= 0 && length <= fabsf(*outLength)) {
        *hitRx = -gGameStatusPtr->unk_11C.x;
        *hitRz = -gGameStatusPtr->unk_11C.z;
        *outX = x;
        *outY = y;
        *outZ = z;
        *outLength = length;
        *hitDirX = -sinTemp;
        *hitDirZ = -cosTemp;
        ret = hitObjectID;
    }

    x = inputX + cosTemp;
    y = inputY;
    z = inputZ + sinTemp;
    length = inputLength;
    hitObjectID = player_raycast_down(&x, &y, &z, &length);
    if (hitObjectID >= 0 && length <= fabsf(*outLength)) {
        *hitRx = -gGameStatusPtr->unk_11C.x;
        *hitRz = -gGameStatusPtr->unk_11C.z;
        *outX = x;
        *outY = y;
        *outZ = z;
        *outLength = length;
        *hitDirX = sinTemp;
        *hitDirZ = cosTemp;
        ret = hitObjectID;
    }

    x = inputX - cosTemp;
    y = inputY;
    z = inputZ - sinTemp;
    length = inputLength;
    hitObjectID = player_raycast_down(&x, &y, &z, &length);
    if (hitObjectID >= 0 && length <= fabsf(*outLength)) {
        *hitRx = -gGameStatusPtr->unk_11C.x;
        *hitRz = -gGameStatusPtr->unk_11C.z;
        *outX = x;
        *outY = y;
        *outZ = z;
        *outLength = length;
        *hitDirX = -sinTemp;
        *hitDirZ = -cosTemp;
        ret = hitObjectID;
    }

    x = inputX;
    y = inputY;
    z = inputZ;
    length = inputLength;
    hitObjectID = player_raycast_down(&x, &y, &z, &length);
    if (hitObjectID >= 0 && length <= fabsf(*outLength)) {
        *hitRx = -gGameStatusPtr->unk_11C.x;
        *hitRz = -gGameStatusPtr->unk_11C.z;
        *outX = x;
        *outY = y;
        *outZ = z;
        *outLength = length;
        *hitDirX = 0.0f;
        *hitDirZ = 0.0f;
        ret = hitObjectID;
    }

    if (ret < 0) {
        *outX = x;
        *outY = y;
        *outZ = z;
    }

    return ret;
}

s32 player_raycast_below_cam_relative(PlayerStatus* playerStatus, f32* outX, f32* outY, f32* outZ, f32* outLength,
                                      f32* hitRx, f32* hitRz, f32* hitDirX, f32* hitDirZ) {
    f32 yaw = 0.0f;

    if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
        yaw = 180.0f;
    }

    return player_raycast_below(yaw - 90.0f + gCameras[gCurrentCameraID].currentYaw, playerStatus->colliderDiameter,
                                outX, outY, outZ, outLength, hitRx, hitRz, hitDirX, hitDirZ);
}


INCLUDE_ASM(s32, "77480", player_raycast_down);

INCLUDE_ASM(s32, "77480", player_raycast_up_corners);

INCLUDE_ASM(s32, "77480", player_raycast_up_corner);

INCLUDE_ASM(s32, "77480", player_test_lateral_overlap, s32 arg0, PlayerStatus* arg1, f32* arg2, f32* arg3, f32* arg4,
            f32 arg5, f32 arg6);

INCLUDE_ASM(s32, "77480", player_raycast_general);

INCLUDE_ASM(s32, "77480", player_test_move_without_slipping, PlayerStatus* arg0, f32* arg1, f32* arg2, f32* arg3, s32 arg4, f32 arg5,
            s32* arg6);

void player_get_slip_vector(f32* arg0, f32* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp = (arg2 * arg4) + (arg3 * arg5);

    *arg0 = (arg2 - (temp * arg4)) * 0.5f;
    *arg1 = (arg3 - (temp * arg5)) * 0.5f;
}

INCLUDE_ASM(s32, "77480", player_test_move_with_slipping);

void update_player(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    GameStatus* gameStatus;

    update_partner_timers();

    if ((playerStatus->decorationList > 100) || (playerStatus->position.y < -2000.0f)) {
        if (!(playerStatus->animFlags & 0x10000000)) {
            playerStatus->decorationList = 0;
            playerStatus->position.x = playerStatus->lastGoodPosition.x;
            playerStatus->position.y = playerStatus->lastGoodPosition.y;
            playerStatus->position.z = playerStatus->lastGoodPosition.z;

            if (playerStatus->animFlags & 0x400000) {
                Npc* partner;

                playerStatus->animFlags |= 0x20000004;
                partner = get_npc_unsafe(NPC_PARTNER);
                partner->pos.x = playerStatus->lastGoodPosition.x;
                partner->pos.y = playerStatus->lastGoodPosition.y + playerStatus->colliderHeight;
                partner->pos.z = playerStatus->lastGoodPosition.z;
                partner->moveToPos.y = playerStatus->lastGoodPosition.y;
            } else {
                playerStatus->decorationList = 10;
            }
        }
    }

    collisionStatus->currentWall = -1;
    collisionStatus->lastWallHammered = -1;
    collisionStatus->unk_0A = -1;
    collisionStatus->floorBelow = 1;

    update_player_input();
    playerStatus->flags &= ~0x400;
    update_player_blink();

    if (playerStatus->flags & 0x1000) {
        phys_update_action_state();
        if (func_800E0208() == 0) {
            collision_main_lateral();
        }
    } else if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
        phys_update_standard();
    } else {
        phys_update_lava_reset();
    }

    if (playerStatus->flags & 0x4000) {
        playerStatus->moveFrames--;
        if (playerStatus->moveFrames <= 0) {
            playerStatus->moveFrames = 0;
            playerStatus->flags &= ~0x4000;
        }
    }

    if (!(playerStatus->animFlags & PLAYER_ANIM_FLAG_PEACH_PHYSICS)) {
        func_800EFD08();
    }

    func_800E0B90();

    gameStatus = gGameStatusPtr;
    gameStatus->playerPos.x = playerStatus->position.x;
    gameStatus->playerPos.y = playerStatus->position.y;
    gameStatus->playerPos.z = playerStatus->position.z;
    gameStatus->playerYaw = playerStatus->currentYaw;

    check_input_open_menus();
    if (!(playerStatus->animFlags & PLAYER_ANIM_FLAG_PEACH_PHYSICS)) {
        check_input_status_menu();
    }

    update_player_shadow();
    check_for_interactables();
    check_for_conversation_prompt();
    check_for_pulse_stone();
    check_for_ispy();

    playerStatus->extraVelocity.x = 0.0f;
    playerStatus->extraVelocity.y = 0.0f;
    playerStatus->extraVelocity.z = 0.0f;
    playerStatus->flags &= ~0x10;
    playerStatus->animFlags &= ~8;
}

void check_input_use_partner(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    u32 actionState = playerStatus->actionState;

    if (!(playerStatus->animFlags & 0x4000)) {
        if (playerStatus->animFlags & 8 || playerStatus->statusMenuCounterinputEnabledCounter == 0) {
            if (playerStatus->pressedButtons & BUTTON_C_DOWN && !(playerStatus->flags & 0x80) &&
                !(playerStatus->pressedButtons & BUTTON_B) && !(playerStatus->animFlags & 0x1000) &&
                actionState <= ACTION_STATE_RUN) {

                if (playerData->currentPartner == PARTNER_GOOMBARIO) {
                    D_802BDF60 = playerStatus->unk_C6;
                }
                partner_use_ability();
            }
        }
    }
}

void phys_update_standard(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 flags;

    check_input_use_partner();
    phys_update_action_state();

    if (!(playerStatus->flags & 8)) {
        if (playerStatus->flags & 2) {
            phys_update_jump();
        }
    }

    if (playerStatus->flags & 4) {
        if (!(playerStatus->flags & 8)) {
            phys_update_falling();
        }
    }

    check_input_midair_jump();

    if (playerStatus->actionState != ACTION_STATE_SLIDE) {
        collision_main_lateral();
        collision_check_player_overlaps();

        if (
            collision_main_above() < 0 &&
            playerStatus->decorationList == 0 &&
            playerStatus->animFlags & PLAYER_ANIM_FLAG_PEACH_PHYSICS
        ) {
            func_800E4F10();
        }

        if ((playerStatus->actionState != ACTION_STATE_ENEMY_FIRST_STRIKE)
            && (playerStatus->actionState != ACTION_STATE_STEP_UP)) {
            phys_main_collision_below();
        }
    }

    if (playerStatus->animFlags & 2) {
        func_802BE070_31DBE0();
    }

    if (!(playerStatus->flags & 0x4000000)) {
        gCameras->targetPos.x = playerStatus->position.x;
        gCameras->targetPos.y = playerStatus->position.y;
        gCameras->targetPos.z = playerStatus->position.z;
    }
}

void phys_update_lava_reset(void) {
    phys_update_action_state();
    collision_main_lateral();
    collision_lava_reset_check_additional_overlaps();

    if (!(gPlayerStatusPtr->flags & 0x4000000)) {
        Camera* camera = &gCameras[0];

        camera->targetPos.x = gPlayerStatusPtr->position.x;
        camera->targetPos.y = gPlayerStatusPtr->position.y;
        camera->targetPos.z = gPlayerStatusPtr->position.z;
    }
}

void clear_player_status(void) {
    mem_clear(&gPlayerStatus, sizeof(gPlayerStatus));
}

void player_reset_data(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    mem_clear(playerStatus, sizeof(PlayerStatus));
    playerStatus->flags = 1;
    reset_player_status();
    playerStatus->shadowID = create_shadow_type(0, playerStatus->position.x, playerStatus->position.y,
                             playerStatus->position.z);
    func_800E6B68();
    func_800E0B14();
    func_800E069C();
    func_800E0514();
    func_800E0374();
    func_800E5520();
}

s32 func_800DFCF4(void) {
    if (gPartnerActionStatus.actionState.b[0] == 1 &&
        (gPartnerActionStatus.actionState.b[3]  == 6 || gPartnerActionStatus.actionState.b[3]  == 9 ||
         gPartnerActionStatus.actionState.b[3]  == 7 || gPartnerActionStatus.actionState.b[3]  == 4 ||
         gPartnerActionStatus.actionState.b[3]  == 8)) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM(s32, "77480", get_overriding_player_anim);

void suggest_player_anim_clearUnkFlag(s32 arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 temp_v0 = get_overriding_player_anim(arg0);

    if (temp_v0 != -1) {
        playerStatus->anim = temp_v0;
        playerStatus->unk_BC = 0;
        playerStatus->flags &= ~0x10000000;
    }
}

void force_player_anim(s32 arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->anim = arg0;
    playerStatus->unk_BC = 0;
    playerStatus->flags &= ~0x10000000;
}

void suggest_player_anim_setUnkFlag(s32 arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 temp_v0 = get_overriding_player_anim(arg0);

    if (temp_v0 != -1) {
        playerStatus->anim = temp_v0;
        playerStatus->unk_BC = 0;
        playerStatus->flags |= 0x10000000;
    }
}

INCLUDE_ASM(s32, "77480", update_player_blink);

// dist_to_player2D
f32 get_xz_dist_to_player(f32 x, f32 z) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    return dist2D(x, z, playerStatus->position.x, playerStatus->position.z);
}

void enable_player_shadow(void) {
    get_shadow_by_index(gPlayerStatus.shadowID)->flags &= ~1;
}

void disable_player_shadow(void) {
    get_shadow_by_index(gPlayerStatus.shadowID)->flags |= 1;
}

s32 disable_player_static_collisions(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->flags |= 0x1000;
    playerStatus->enableCollisionOverlapsCheck++;
    return playerStatus->enableCollisionOverlapsCheck;
}

s32 enable_player_static_collisions(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->enableCollisionOverlapsCheck--;
    if (playerStatus->enableCollisionOverlapsCheck == 0) {
        playerStatus->flags &= ~0x1000;
    }
    return playerStatus->enableCollisionOverlapsCheck;
}

s32 disable_player_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->flags |= 0x2000;
    playerStatus->statusMenuCounterinputEnabledCounter++;
    return playerStatus->statusMenuCounterinputEnabledCounter;
}

s32 enable_player_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->statusMenuCounterinputEnabledCounter--;
    if (playerStatus->statusMenuCounterinputEnabledCounter == 0) {
        playerStatus->flags &= ~0x2000;
    }
    return playerStatus->statusMenuCounterinputEnabledCounter;
}

void func_800E01DC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->animFlags & PLAYER_ANIM_FLAG_INTERACT_PROMPT) {
        playerStatus->flags |= 0x8000000;
    }
}

s32 func_800E0208(void) {
    s32 ret = 0;

    if (gGameStatusPtr->disableScripts && (gGameStatusPtr->currentButtons & 0x10)) {
        if (gPartnerActionStatus.actionState.b[0] == 0) {
            set_action_state(ACTION_STATE_IDLE);
        }
        ret = 1;
    }
    return ret;
}

void player_render_interact_prompts(void) {
    func_800E0658();
    func_800E0AD0();
    func_800E04D0();
    func_800E0330();
}

// Weird control flow / issue with loading linker addrs
#ifdef NON_MATCHING
extern s8 D_8015A57A;
void check_for_ispy(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (D_8015A57A != 0) {
        if (D_8010C93C == 0) {
            if (!(playerStatus->animFlags & 0x30)) {
                dma_copy(E225B0_ROM_START, E225B0_ROM_END, E225B0_VRAM);
                D_8010C93C = func_802B72C0_E22870;
            }
        } if (D_8010C93C == 0) {
            return;
        }
    }
    if (D_8010C93C != 0) {
        D_8010C93C();
    }
}
#else
INCLUDE_ASM(s32, "77480", check_for_ispy);
#endif

void func_800E0330(void) {
    if ((gPlayerStatusPtr->animFlags & PLAYER_ANIM_FLAG_100) && (D_8010C93C != NULL)) {
        func_802B7000_E225B0();
    }
}

void func_800E0374(void) {
    D_8010C93C = NULL;
    gPlayerStatusPtr->animFlags &= ~PLAYER_ANIM_FLAG_100;
}

INCLUDE_ASM(s32, "77480", check_for_pulse_stone);

void func_800E04D0(void) {
    if ((gPlayerStatusPtr->animFlags & 0x40) && (D_8010C920 != 0)) {
        func_802B71D4();
    }
}

void func_800E0514(void) {
    D_8010C920 = 0;
    gPlayerStatusPtr->animFlags &= ~0x40;
}

s32 has_valid_conversation_npc(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32* unk_C8 = playerStatus->unk_C8;
    s32 ret = 0;
    s32 cond;

    if (unk_C8 != NULL && !(*unk_C8 & 0x10000000)) {
        cond = (playerStatus->flags & 0x2002000) == 0x2000000;
        ret = cond;
    }
    return ret;
}

INCLUDE_ASM(s32, "77480", check_for_conversation_prompt);

void func_800E0658(void) {
    if ((gPlayerStatusPtr->animFlags & 0x20) && (D_8010C940 != 0)) {
        func_802B71C8();
    }
}

void func_800E069C(void) {
    D_8010C940 = 0;
    gPlayerStatusPtr->animFlags &= ~0x20;
}

void func_800E06C0(s32 arg0) {
    D_8010C950 = (arg0 == 1);
}

INCLUDE_ASM(s32, "77480", func_800E06D8);

INCLUDE_ASM(s32, "77480", check_for_interactables);

void func_800E0AD0(void) {
    if ((gPlayerStatusPtr->animFlags & 0x10) && (D_8010C958 != 0)) {
        func_802B71E8_E202F8();
    }
}

void func_800E0B14(void) {
    D_8010C958 = 0;
    gPlayerStatusPtr->animFlags &= ~0x10;
}

void update_partner_timers(void) {
    PlayerData* playerData = &gPlayerData;

    if (!gGameStatusPtr->isBattle) {
        s32 i;

        for (i = 1; i < ARRAY_COUNT(playerData->unk_2C4); i++) {
            if (playerData->partners[i].enabled) {
                playerData->unk_2C4[i] += 1;
            }
        }
    }
}

INCLUDE_ASM(s32, "77480", func_800E0B90);

INCLUDE_ASM(s32, "77480", get_player_back_anim);

void render_player(void) {
    if (!gGameStatusPtr->disableScripts) {
        render_player_model();
    }
}

INCLUDE_ASM(void, "77480", render_player_model);

INCLUDE_ASM(s32, "77480", appendGfx_player);

/// Only used when speedy spinning.
INCLUDE_ASM(s32, "77480", appendGfx_player_spin);

void update_player_shadow(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Shadow* shadow = get_shadow_by_index(gPlayerStatusPtr->shadowID);
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 shadowScale = 0.0f;
    f32 yawTemp = 0.0f;
    f32 hitDirX, hitDirZ;
    f32 hitRx, hitRz;
    f32 x, y, z;
    f32 playerX, playerZ;
    s32 dist;
    f32 raycastYaw;

    if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
        yawTemp = 180.0f;
    }

    raycastYaw = (yawTemp - 90.0f) + gCameras[gCurrentCameraID].currentYaw;
    shadow->position.x = playerX = playerStatus->position.x;
    shadow->position.z = playerZ = playerStatus->position.z;
    x = playerX;
    y = playerStatus->position.y + (playerStatus->colliderHeight / 3.5f);
    z = playerZ;
    shadowScale = 1024.0f;
    gCollisionStatus.floorBelow = player_raycast_below(raycastYaw, playerStatus->colliderDiameter, &x, &y, &z,
                                                       &shadowScale, &hitRx, &hitRz, &hitDirX, &hitDirZ);
    shadow->rotation.x = hitRx;
    shadow->rotation.z = hitRz;
    shadow->rotation.y = clamp_angle(-camera->currentYaw);
    hitRx += 180.0f;
    hitRz += 180.0f;

    if (hitRx != 0.0f || hitRz != 0.0f) {
        s32 dist = dist2D(x, z, playerStatus->position.x, playerStatus->position.z);
        f32 tan = atan2(playerStatus->position.x, playerStatus->position.z, x, z);
        s32 angleTemp = clamp_angle((-90.0f - tan) + get_player_normal_yaw());

        if (gGameStatusPtr->playerTraceNormal.y != 0.0f) {
            y -= sqrtf(SQ(gGameStatusPtr->playerTraceNormal.x) + SQ(gGameStatusPtr->playerTraceNormal.z)) /
                       gGameStatusPtr->playerTraceNormal.y * dist * sin_deg(angleTemp);
        }
    }

    shadow->position.y = y;
    shadow->unk_05 = (f64)playerStatus->alpha1 / 2;

    if (!(gGameStatusPtr->peachFlags & 1)) {
        set_standard_shadow_scale(shadow, shadowScale);
    } else {
        set_peach_shadow_scale(shadow, shadowScale);
    }
}
