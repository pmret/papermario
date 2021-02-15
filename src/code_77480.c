#include "common.h"

extern s32 D_8010C920;
extern s32 D_8010C93C;
extern s32 D_8010C940;
extern s32 D_8010C950;
extern s32 D_8010C958;

INCLUDE_ASM(s32, "code_77480", test_below_player);

INCLUDE_ASM(s32, "code_77480", func_800DE46C);

INCLUDE_ASM(s32, "code_77480", trace_below_player);

INCLUDE_ASM(s32, "code_77480", collision_check_above);

INCLUDE_ASM(s32, "code_77480", trace_above_player);

INCLUDE_ASM(s32, "code_77480", do_lateral_collision);

INCLUDE_ASM(s32, "code_77480", func_800DEE5C);

INCLUDE_ASM(s32, "code_77480", func_800DF15C);

void func_800DF3FC(f32* arg0, f32* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp = (arg2 * arg4) + (arg3 * arg5);

    *arg0 = (arg2 - (temp * arg4)) * 0.5f;
    *arg1 = (arg3 - (temp * arg5)) * 0.5f;
}

INCLUDE_ASM(s32, "code_77480", test_player_lateral);

INCLUDE_ASM(s32, "code_77480", update_player);

INCLUDE_ASM(s32, "code_77480", check_input_use_partner);

INCLUDE_ASM(s32, "code_77480", func_800DFAAC);

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
    PlayerStatus* playerStatus = PLAYER_STATUS;

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
    if (D_8010EBB0[0] == 1 && (D_8010EBB0[3] == 6 || D_8010EBB0[3] == 9 || D_8010EBB0[3] == 7 || D_8010EBB0[3] == 4
                               || D_8010EBB0[3] == 8)) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM(s32, "code_77480", func_800DFD48);

void func_800DFEFC(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;
    s32 temp_v0 = func_800DFD48();

    if (temp_v0 != -1) {
        playerStatus->anim = temp_v0;
        playerStatus->unk_BC = 0;
        playerStatus->flags &= ~0x10000000;
    }
}

void func_800DFF50(s32 arg0) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    playerStatus->anim = arg0;
    playerStatus->unk_BC = 0;
    playerStatus->flags &= ~0x10000000;
}

void func_800DFF78(void) {
    PlayerStatus* playerStatus = PLAYER_STATUS;
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
    PlayerStatus* playerStatus = PLAYER_STATUS;

    return dist2D(x, z, playerStatus->position.x, playerStatus->position.z);
}

void enable_player_shadow(void) {
    get_shadow_by_index(PLAYER_STATUS->shadowID)->flags &= ~1;
}

void disable_player_shadow(void) {
    get_shadow_by_index(PLAYER_STATUS->shadowID)->flags |= 1;
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
    GameStatus* gameStatus = GAME_STATUS;
    s32 ret = 0;

    if (gameStatus->disableScripts && (gameStatus->currentButtons & 0x10)) {
        if (D_8010EBB0[0] == 0) {
            set_action_state(ActionState_IDLE);
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
    PlayerStatus* playerStatus = PLAYER_STATUS;
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
        func_802B71E8();
    }
}

void func_800E0B14(void) {
    D_8010C958 = 0;
    gPlayerStatusPtr->animFlags &= ~0x10;
}

void update_partner_timers(void) {
    PlayerData* playerData = PLAYER_DATA;

    if (!GAME_STATUS->isBattle) {
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
    if (!GAME_STATUS->disableScripts) {
        render_player_model();
    }
}

INCLUDE_ASM(void, "code_77480", render_player_model);

INCLUDE_ASM(s32, "code_77480", appendGfx_player);

/// Only used when speedy spinning.
INCLUDE_ASM(s32, "code_77480", appendGfx_player_spin);

INCLUDE_ASM(s32, "code_77480", update_player_shadow);

