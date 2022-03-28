#include "common.h"

void entity_shattering_setupGfx(s32 entityIndex);

void entity_BrickBlock_idle(Entity* entity) {
    entity_base_block_idle(entity);
}

INCLUDE_ASM(void, "entity/103CD0", entity_shattering_init_pieces, Entity* entity, void* arg1, void* arg2);
/*void entity_shattering_init_pieces(Entity* entity, void* arg1, void* arg2) {
    Matrix4f sp10, sp50;
    SwitchData* data = entity->dataBuf.swtch;
    s32 i;

    s32 phi_s7;
    u16* phi_s3;
    s32 phi_s0;
    f32 phi_f20;


    data->unk_34 = entity->vertexData[(s32)arg1].m;
    entity->renderSetupFunc = entity_shattering_setupGfx;
    entity->alpha = 255;
    entity->position.y = data->unk_38;
    guTranslateF(sp50, entity->position.x, entity->position.y, entity->position.z);

    if (!is_block_on_ground(entity)) {
        phi_s7 = 1;
    } else {
        phi_s7 = 2;
    }

    data->unk_3E = 0;
    data->unk_3C.s = 0xFF;
    phi_s3 = data; // ???

    for (i = 0; i < ARRAY_COUNT(data->fragmentRotX); i++) {
        guMtxL2F(sp10, &entity->vertexData[(s32)arg2 & 0xFFFF]);
        guMtxCatF(sp50, sp10, sp10);
        data->fragmentPosX[i] = sp10[3][0];
        data->fragmentPosY[i] = sp10[3][1];
        data->fragmentPosZ[i] = sp10[3][2];
        data->unk_72[i] = -rand_int(255);

        if (phi_s7 == 1) {
            phi_s3[i] |= 1;
            phi_s0 = 20;
            phi_f20 = 6.4f;
        } else {
            phi_s3[i] |= 2;
            phi_s0 = 40;
            phi_f20 = 8.6f;
        }

        data->unk_59[i] = phi_s0 + rand_int(10);
        if ((i % 2) == 0) {
            data->unk_59[i] = -data->unk_59[i];
        }

        data->unk_1EC[i] = phi_f20 + (f32)(rand_float() * 2.7);
        data->unk_40[i] = 0;
        data->fragmentRotX[i] = 0;
        data->fragmentRotY[i] = 0;
    }
}*/

INCLUDE_ASM(void, "entity/103CD0", entity_shattering_idle, Entity* entity);

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
INCLUDE_ASM(s32, "entity/103CD0", entity_shattering_setupGfx);
#endif
