#include "common.h"

void func_800EFE2C(void);
void func_800F0248(void);
void func_800F0490(void);
void func_800F0864(void);
void func_800F09EC(void);
void func_800F0B3C(void);
extern s32 D_80109480;
extern s32 D_8010CFF0;
extern s32 D_8010CFF4;

void func_800EFD00(void) {
}

void func_800EFD08(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 phi_s0 = 0;

    if (playerStatus->actionState == ACTION_STATE_JUMP) {
        phi_s0 = D_80109480;
    }

    D_80109480 = get_collider_type_by_id((s32) (u16) gCollisionStatus.currentFloor) & 0xFF;

    if (playerStatus->actionState != 3) {
        phi_s0 = D_80109480;
    }

    if (playerStatus->actionState == 0xA && playerStatus->flags < 0) {
        D_8010CFF4 = D_8010CFF0;
    }

    D_8010CFF0 = playerStatus->decorationList;

    switch (phi_s0) {
        case 6:
            func_800F0248();
            return;
        case 7:
            func_800F0490();
            return;
        case 8:
            func_800F0864();
            return;
        case 9:
            func_800F09EC();
            return;
        case 1:
            func_800F0B3C();
            return;
        default:
            func_800EFE2C();
            return;
    }
}

INCLUDE_ASM(s32, "891b0_len_fb0", func_800EFE2C);

#ifdef NON_EQUIVALENT
void playFX_08(f32, f32, f32, f32);
void playFX_09(s32, f32, f32, f32, f32, f32);
extern f32 D_8010948C;
extern u16 D_80109490;
extern s16 D_80109492;
extern s32 D_80109494;
void func_800F0248(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sp18, sp1C;
    f32 yPos, zPos, xPos;
    f32 playerColliderDiamater;
    s32 temp_v0_2;

    if ((playerStatus->actionState == ACTION_STATE_JUMP) && (playerStatus->decorationList == 1) && (D_80109492 == 5)) {
        playFX_08(playerStatus->position.x, playerStatus->position.y + 14.0f, playerStatus->position.z, D_8010948C);
        D_8010948C = clamp_angle(D_8010948C + 35.0f);
        D_80109492 = 0;
        return;
    }

    D_80109492++;

    if (D_80109492 >= 6) {
        D_80109492 = 5;
    }

    if ((((u8) playerStatus->actionState - 1) >= 2U) && ((playerStatus->actionState & 0xFF00FF00) != 0x1A000000)) {
        D_80109490 = 0;
        return;
    }
    temp_v0_2 = D_80109490;
    D_80109490 = temp_v0_2 + 1;
    if ((temp_v0_2 << 0x10) > 0) {
        D_80109490 = 0;
        sin_cos_rad((clamp_angle(-(xPos = playerStatus->currentYaw)) * TAU) / 360.0f, &sp18, &sp1C);
        playerColliderDiamater = playerStatus->colliderDiameter;
        xPos = playerStatus->position.x + (playerColliderDiamater * sp18 * -0.4f);
        zPos = playerStatus->position.z + (playerColliderDiamater * sp1C * -0.4f);
        yPos = playerStatus->position.y + 15.5f;
        playFX_09(0, xPos, yPos, zPos, (-playerStatus->currentYaw + rand_int(0xA)) - 5.0f, D_80109494);
        D_80109494 = !D_80109494;
    }
}
#else
INCLUDE_ASM(s32, "891b0_len_fb0", func_800F0248);
#endif

INCLUDE_ASM(s32, "891b0_len_fb0", func_800F0490);

INCLUDE_ASM(s32, "891b0_len_fb0", func_800F0864);

INCLUDE_ASM(s32, "891b0_len_fb0", func_800F09EC);

INCLUDE_ASM(s32, "891b0_len_fb0", func_800F0B3C);

void func_800F0C9C(void) {
}
