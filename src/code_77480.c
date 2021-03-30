#include "common.h"

extern s32 D_8010C920;
extern s32 D_8010C93C;
extern s32 D_8010C940;
extern s32 D_8010C950;
extern s32 D_8010C958;

void func_800E0514(void);

INCLUDE_ASM(s32, "code_77480", test_below_player);

INCLUDE_ASM(s32, "code_77480", func_800DE46C);

INCLUDE_ASM(s32, "code_77480", trace_below_player);

INCLUDE_ASM(s32, "code_77480", collision_check_above);

INCLUDE_ASM(s32, "code_77480", trace_above_player);

INCLUDE_ASM(s32, "code_77480", do_lateral_collision, s32 arg0, PlayerStatus* arg1, f32* arg2, f32* arg3, f32* arg4,
            f32 arg5, f32 arg6);

INCLUDE_ASM(s32, "code_77480", func_800DEE5C);

INCLUDE_ASM(s32, "code_77480", func_800DF15C, PlayerStatus* arg0, f32* arg1, f32* arg2, f32* arg3, s32 arg4, f32 arg5,
            s32* arg6);

void func_800DF3FC(f32* arg0, f32* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp = (arg2 * arg4) + (arg3 * arg5);

    *arg0 = (arg2 - (temp * arg4)) * 0.5f;
    *arg1 = (arg3 - (temp * arg5)) * 0.5f;
}

INCLUDE_ASM(s32, "code_77480", test_player_lateral);

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
    func_800DFFCC();

    if (playerStatus->flags & 0x1000) {
        func_800E5A2C();
        if (func_800E0208() == 0) {
            collision_main_lateral();
        }
    } else if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
        func_800DFAAC();
    } else {
        func_800DFBE8();
    }

    if (playerStatus->flags & 0x4000) {
        playerStatus->moveFrames--;
        if (playerStatus->moveFrames <= 0) {
            playerStatus->moveFrames = 0;
            playerStatus->flags &= ~0x4000;
        }
    }

    if (!(playerStatus->animFlags & 0x1000)) {
        func_800EFD08();
    }

    func_800E0B90();

    gameStatus = gGameStatusPtr;
    gameStatus->playerPos.x = playerStatus->position.x;
    gameStatus->playerPos.y = playerStatus->position.y;
    gameStatus->playerPos.z = playerStatus->position.z;
    gameStatus->playerYaw = playerStatus->currentYaw;

    check_input_open_menus();
    if (!(playerStatus->animFlags & 0x1000)) {
        check_input_status_menu();
    }

    update_player_shadow();
    check_for_interactables();
    func_800E0580();
    func_800E0398();
    func_800E0294();

    playerStatus->extraVelocity.x = 0.0f;
    playerStatus->extraVelocity.y = 0.0f;
    playerStatus->extraVelocity.z = 0.0f;
    playerStatus->flags &= ~0x10;
    playerStatus->animFlags &= ~8;
}

INCLUDE_ASM(s32, "code_77480", check_input_use_partner);

void func_800DFAAC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 flags;

    check_input_use_partner();
    func_800E5A2C();

    if (!(playerStatus->flags & 8)) {
        if (playerStatus->flags & 2) {
            update_fall_state();
        }
    }

    if (playerStatus->flags & 4) {
        if (!(playerStatus->flags & 8)) {
            func_800E3100();
        }
    }

    check_input_midair_jump();

    if (playerStatus->actionState != ACTION_STATE_SLIDING) {
        collision_main_lateral();
        func_800E4508();

        if ((collision_main_above() < 0) && (playerStatus->decorationList == 0) && (playerStatus->animFlags & 0x1000)) {
            func_800E4F10();
        }

        if ((playerStatus->actionState != ACTION_STATE_ENEMY_FIRST_STRIKE)
            && (playerStatus->actionState != ACTION_STATE_STEP_UP)) {
            func_800E4744();
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

void func_800DFBE8(void) {
    func_800E5A2C();
    collision_main_lateral();
    func_800E4BB8();

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

void func_800DFC74(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    mem_clear(playerStatus, sizeof(PlayerStatus));
    playerStatus->flags = 1;
    func_800E205C();
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
    if (D_8010EBB0.unk_00 == 1 &&
        (D_8010EBB0.unk_03 == 6 || D_8010EBB0.unk_03 == 9 || D_8010EBB0.unk_03 == 7 || D_8010EBB0.unk_03 == 4 ||
         D_8010EBB0.unk_03 == 8)) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM(s32, "code_77480", func_800DFD48);

void func_800DFEFC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 temp_v0 = func_800DFD48();

    if (temp_v0 != -1) {
        playerStatus->anim = temp_v0;
        playerStatus->unk_BC = 0;
        playerStatus->flags &= ~0x10000000;
    }
}

void func_800DFF50(s32 arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->anim = arg0;
    playerStatus->unk_BC = 0;
    playerStatus->flags &= ~0x10000000;
}

void func_800DFF78(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 temp_v0 = func_800DFD48();

    if (temp_v0 != -1) {
        playerStatus->anim = temp_v0;
        playerStatus->unk_BC = 0;
        playerStatus->flags |= 0x10000000;
    }
}

INCLUDE_ASM(s32, "code_77480", func_800DFFCC);

// dist_to_player2D
f32 func_800E0088(f32 x, f32 z) {
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

    if (playerStatus->animFlags & 0x10) {
        playerStatus->flags |= 0x8000000;
    }
}

s32 func_800E0208(void) {
    s32 ret = 0;

    if (gGameStatusPtr->disableScripts && (gGameStatusPtr->currentButtons & 0x10)) {
        if (D_8010EBB0.unk_00 == 0) {
            set_action_state(ACTION_STATE_IDLE);
        }
        ret = 1;
    }
    return ret;
}

void func_800E0260(void) {
    func_800E0658();
    func_800E0AD0();
    func_800E04D0();
    func_800E0330();
}

INCLUDE_ASM(s32, "code_77480", func_800E0294);

void func_800E0330(void) {
    if ((gPlayerStatusPtr->animFlags & 0x100) && (D_8010C93C != 0)) {
        func_802B7000_E225B0();
    }
}

void func_800E0374(void) {
    D_8010C93C = 0;
    gPlayerStatusPtr->animFlags &= ~0x100;
}

INCLUDE_ASM(s32, "code_77480", func_800E0398);

void func_800E04D0(void) {
    if ((gPlayerStatusPtr->animFlags & 0x40) && (D_8010C920 != 0)) {
        func_802B71D4();
    }
}

void func_800E0514(void) {
    D_8010C920 = 0;
    gPlayerStatusPtr->animFlags &= ~0x40;
}

s32 func_800E0538(void) {
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

INCLUDE_ASM(s32, "code_77480", func_800E0580);

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

INCLUDE_ASM(s32, "code_77480", func_800E06D8);

INCLUDE_ASM(s32, "code_77480", check_for_interactables);

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

INCLUDE_ASM(s32, "code_77480", func_800E0B90);

INCLUDE_ASM(s32, "code_77480", get_player_back_anim);

void render_player(void) {
    if (!gGameStatusPtr->disableScripts) {
        render_player_model();
    }
}

INCLUDE_ASM(void, "code_77480", render_player_model);

INCLUDE_ASM(s32, "code_77480", appendGfx_player);

/// Only used when speedy spinning.
INCLUDE_ASM(s32, "code_77480", appendGfx_player_spin);

INCLUDE_ASM(s32, "code_77480", update_player_shadow);

