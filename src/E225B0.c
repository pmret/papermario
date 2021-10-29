#include "common.h"

typedef struct struct802B7C78 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 scale;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
} struct802B7C78;

typedef struct UnknownCommand {
    /* 0x00 */ Matrix4f* unk_00;
    /* 0x04 */ Matrix4f* unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u8 unk_10;
} UnknownCommand;

extern Matrix4f D_802B7580_E22B30;
extern Matrix4f D_802B7BA0_E23150;
extern Matrix4f D_802B7BC0_E23170;
extern Matrix4f D_802B7BE0_E23190;
extern Gfx D_802B7C00_E231B0[];

extern void (*D_8010C93C)(void);
extern struct802B7C78* D_802B7C78_E23228;
extern struct8015A578 D_8015A578;

void func_8013AA9C(s32, s32, s32, s32, s32, s32, s32);
void func_8013AF70(s32, UnknownCommand*, s32, Matrix4f*);
void func_802B735C_E2290C(void);

void func_802B7000_E225B0(void) {
    Matrix4f matrix1;
    Matrix4f matrix2;
    UnknownCommand command;

    Gfx* oldMasterGfxPos;
    f32 scale;
    s32 temp;
    s32 matrixIndex;
    struct802B7C78* localD_802B7C78_E23228;
    u16 oldMatrixListPos;

    if (gPlayerStatus.animFlags & 0x100) {
        guScaleF(matrix1, D_802B7C78_E23228->scale, D_802B7C78_E23228->scale,
            D_802B7C78_E23228->scale);
        guRotateF(matrix2, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(matrix1, matrix2, matrix1);
        guTranslateF(matrix2, D_802B7C78_E23228->x, D_802B7C78_E23228->y, D_802B7C78_E23228->z);
        guMtxCatF(matrix1, matrix2, matrix2);
        guMtxF2L(matrix2, (Mtx*) &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], 3);
        gSPDisplayList(gMasterGfxPos++, D_802B7C00_E231B0);

        localD_802B7C78_E23228 = D_802B7C78_E23228;
        if (localD_802B7C78_E23228->unk_18 < 47) {
            localD_802B7C78_E23228->unk_20 += 1;
        }

        temp = D_802B7C78_E23228->unk_20;
        temp = temp - (temp / 12) * 12;
        switch (temp) {
            case 0:
            case 1:
            case 2:
            case 3:
                command.unk_04 = &D_802B7BA0_E23150;
                break;
            case 4:
            case 5:
            case 6:
            case 7:
                command.unk_04 = &D_802B7BC0_E23170;
                break;
            case 8:
            case 9:
            case 10:
            case 11:
                command.unk_04 = &D_802B7BE0_E23190;
                break;
        }
        func_8013AA9C(0, 7, 0xFF, 0xFF, 0xFF, D_802B7C78_E23228->unk_28, 0);

        command.unk_00 = &D_802B7580_E22B30;
        command.unk_08 = 0x38;
        command.unk_0A = 0x38;
        command.unk_0C = -0x1C;
        command.unk_0E = 0x2E;
        command.unk_10 = 0xFF;

        func_8013AF70(0, &command, 0, &matrix2);
        gSPPopMatrix(gMasterGfxPos++, 0);
    }
}


void func_802B72C0_E22870(void) {
    mem_clear(D_802B7C78_E23228, sizeof(*D_802B7C78_E23228));

    D_802B7C78_E23228->x = gPlayerStatus.position.x;
    D_802B7C78_E23228->y = gPlayerStatus.position.y + gPlayerStatus.colliderHeight + 8.0f;
    D_802B7C78_E23228->z = gPlayerStatus.position.z;

    D_802B7C78_E23228->unk_28 = 0xFF;

    gPlayerStatus.animFlags |= 0x100;
    D_8010C93C = &func_802B735C_E2290C;
}

void func_802B735C_E2290C(void) {
    f32 temp_f2;
    s32 temp_v0_3;
    s32 temp_v1;
    struct802B7C78* temp_a0;
    struct802B7C78* temp_v1_3;
    s32 phi_v0;
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    temp_a0 = D_802B7C78_E23228;
    temp_f2 = temp_a0->y;
    temp_v1 = temp_a0->unk_24;
    temp_a0->y = temp_f2 + (((playerStatus->position.y + playerStatus->colliderHeight + 10.0f) - temp_f2) / 1.5f);
    temp_a0->x = playerStatus->position.x;
    temp_a0->z = playerStatus->position.z;

    switch (temp_v1) {
        case 0:
            if (partnerActionStatus->actionState.b[0] && partnerActionStatus->actionState.b[3] == 8) {
                phi_v0 = gGameStatusPtr->unk_7D;
            } else {
                phi_v0 = playerStatus->flags & 0x3000;
            }
            if (phi_v0 == 0) {
                temp_v1_3 = D_802B7C78_E23228;
                temp_v1_3->unk_24 += 1;
                return;
            }
            break;
        case 1:
            if (playerStatus->flags & 0x20) {
                temp_a0->unk_24 = 3;
                return;
            }

            if (temp_a0->unk_18++ >= 0x10) {
                temp_a0->scale = 0.36f;
                temp_a0->unk_24 += 1;
            }
            break;
        case 2:
            temp_a0->scale = 0.57f;
            temp_a0->unk_24 += 1;
            sfx_play_sound_at_player(SOUND_UNKNOWN_17B, 0);
            break;
        case 3:
            temp_a0->scale = 0.53f;
            if (temp_a0->unk_18 >= 0x2F || playerStatus->flags & 0x20) {
                temp_a0->unk_28 -= 0x40;
                if (temp_a0->unk_28 < 0) {
                    temp_a0->unk_28 = 0;
                    temp_a0->unk_18 = 0x33;
                }
            }

            if (D_802B7C78_E23228->unk_18++ >= 0x33) {
                D_8015A578.unk_02 = 0;
                D_8010C93C = NULL;
                playerStatus->animFlags &= ~0x100;
            }
            break;
    }
}


