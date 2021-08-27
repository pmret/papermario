#include "common.h"

extern u8 D_802BCA30_E31380[];
// size unknown
typedef struct structE2F750 {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ char unk_04[0x9C];
    /* 0xA0 */ s32 unk_A0;
    /* 0xA4 */ s16 unk_A4;
    /* 0xA6 */ s16 unk_A6;
    /* 0xA8 */ s16 unk_A8;
    /* 0xAA */ char unk_AA[14];
    /* 0xB8 */ f32 unk_B8;
} structE2F750;

INCLUDE_ASM(s32, "entity/sbk_omo/E2F750", func_802BAE00_E2F750);

INCLUDE_ASM(s32, "entity/sbk_omo/E2F750", func_802BAF84_E2F8D4);

INCLUDE_ASM(s32, "entity/sbk_omo/E2F750", func_802BB108_E2FA58);

s32 func_802BB3B8_E2FD08(void);
INCLUDE_ASM(s32, "entity/sbk_omo/E2F750", func_802BB3B8_E2FD08);

void func_802BB704_E30054(Entity* entity) {
    structE2F750* data = (structE2F750*)entity->dataBuf;
    s32 i;

    data->unk_02--;
    if (data->unk_02 <= 0) {
        i = data->unk_01;
        if (D_802BCA30_E31380[i] == 0xFF) {
            i = 0;
        }
        data->unk_03 = D_802BCA30_E31380[i++];
        data->unk_02 = D_802BCA30_E31380[i++];
        data->unk_01 = i;
    }
}

s32 func_802BB76C_E300BC(Entity* entity);
INCLUDE_ASM(s32, "entity/sbk_omo/E2F750", func_802BB76C_E300BC);

s32 func_802BB7E0_E30130(Entity* entity);
INCLUDE_ASM(s32, "entity/sbk_omo/E2F750", func_802BB7E0_E30130);

void func_802BB8E4_E30234(Entity* entity) {
    structE2F750* data = (structE2F750*)entity->dataBuf;
    f32 temp_f0;
    f32 temp_f20_2;

    f32 temp_f4 = (atan2(entity->position.x, entity->position.z, data->unk_A4, data->unk_A8) - data->unk_B8) * 0.03125f;
    if (temp_f4 >= 0.0f && temp_f4 < 0.01) {
        temp_f4 = 0.01f;
    }
    if (temp_f4 < 0.0f && temp_f4 > -0.01) {
        temp_f4 = -0.01f;
    }

    temp_f0 = clamp_angle(data->unk_B8 + temp_f4);
    data->unk_B8 = temp_f0;
    temp_f20_2 = temp_f0 * 6.28318f / 360.0f;
    entity->position.x += sin_rad(temp_f20_2);
    entity->position.z -= cos_rad(temp_f20_2);

    if (func_802BB76C_E300BC(entity) != 0) {
        func_802BB7E0_E30130(entity);
    }
}

INCLUDE_ASM(s32, "entity/sbk_omo/E2F750", func_802BBA60_E303B0);

void func_802BBDB8_E30708(Entity* entity) {
    f32 scaleX;

    entity->scale.x += 0.1;
    if (entity->scale.x >= 1.0) {
        entity->scale.x = 1.0f;
    }

    entity->scale.z = entity->scale.y = entity->scale.x;
}

void func_802BBE14_E30764(Entity* entity) {
    structE2F750* data = (structE2F750*)entity->dataBuf;

    data->unk_A0 = *D_8015C7D0;
    func_802BB7E0_E30130(entity);
    data->unk_03 = 0;
    entity->renderSetupFunc = &func_802BB3B8_E2FD08;
    entity->scale.x = 0;
    entity->scale.y = 0;
    entity->scale.z = 0;
}
