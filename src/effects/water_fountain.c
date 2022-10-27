#include "common.h"
#include "effects_internal.h"

s32 D_E00B88F0[] = { 0x27BD0108, 0x00000000, 0x00000000, 0x00000000 };

s32 D_E00B8900[] = { 0x0000001E, 0x008C0000, 0xFF000006, 0x001E0078, 0x0000FA00, 0x010C001E, 0x006EFFFB, 0xF0000111, 0x00320064, 0xFFECF000, 0x0216003C, 0x005AFFE2, 0xF000021A, 0x0046005A, 0xFFD8F000, 0x031C0050, 0x0055FFCE, 0xF0000420, 0x005A005A, 0xFFC4F000, 0x05230064, 0x0064FFBA, 0xF0000726, 0x006E006E, 0xFFB0F000, 0x08280078, 0x0078FFA6, 0xF0000B2A, 0x00820082, 0xFF9CF000, 0x0E2B0096, 0x0096FF92, 0xF000122C, 0x00BE00BE, 0xFF88F000, 0x152D00E6, 0x00E6FF7E, 0xF000182E, 0x010E010E, 0xFF74F000, 0x1B2F0136, 0x0136FF6A, 0xF0001E30, 0x015E015E, 0xFF60C800, 0x2131017C, 0x017CFF56, 0x8C002432, 0x01900190, 0xFF4C2800, 0x0000001E, 0x008C0000, 0xFF000006, 0x001E0078, 0x0000F000, 0xFF0C001E, 0x006E0005, 0xE600FF11, 0x00320064, 0x0014DC00, 0xFE16003C, 0x005A001E, 0xD200FE1A, 0x0046005A, 0x0028C800, 0xFD1C0050, 0x00550032, 0xBE00FC20, 0x005A0050, 0x003CB400, 0xFB230064, 0x004D0046, 0xAA00F926, 0x006E0041, 0x0050A000, 0xF8280078, 0x0036005A, 0x9600F52A, 0x0082003C, 0x00648C00, 0xF22B008C, 0x0046006E, 0x8200EE2C, 0x00960050, 0x00787800, 0xEB2D00A0, 0x005A0082, 0x6E00E82E, 0x00AA0064, 0x008C5A00, 0xE52F00B4, 0x006E0096, 0x5000E230, 0x00BE0078, 0x00A04600, 0xDF3100C8, 0x008200AA, 0x1E00DC32, 0x00D2008C, 0x00B40A00, 0x0000001E, 0x008C0000, 0xFF000006, 0x001E0078, 0x0000F000, 0x000C001E, 0x006E0005, 0xE6000011, 0x00320064, 0x0014DC00, 0x0016003C, 0x005A001E, 0xD200001A, 0x0046005A, 0x0028C800, 0x001C0050, 0x00550032, 0xBE000020, 0x005A0050, 0x003CB400, 0x00230064, 0x004D0046, 0xAA000026, 0x006E0041, 0x0050A000, 0x00280078, 0x0036005A, 0x9600002A, 0x0082003C, 0x00648C00, 0x002B008C, 0x0046006E, 0x8200002C, 0x00960050, 0x00787800, 0x002D00A0, 0x005A0082, 0x6E00002E, 0x00AA0064, 0x008C5A00, 0x002F00B4, 0x006E0096, 0x50000030, 0x00BE0078, 0x00A04600, 0x003100C8, 0x008200AA, 0x1E000032, 0x00D2008C, 0x00B40A00 };

s32 D_E00B8B58[] = { 0x0000001E, 0x008C0000, 0xFF000006, 0x001E0078, 0x0000F000, 0x010C001E, 0x006EFFFB, 0xE6000111, 0x00320064, 0xFFECDC00, 0x0216003C, 0x005AFFE2, 0xD200021A, 0x0046005A, 0xFFD8C800, 0x031C0050, 0x0055FFCE, 0xBE000420, 0x005A0050, 0xFFC4B400, 0x05230064, 0x004DFFBA, 0x78000726, 0x006E0041, 0xFFB05000, 0x08280078, 0x0036FFA6, 0x28000000, 0x001E008C, 0x0000FF00, 0x0006001E, 0x00780000, 0xF000FF0C, 0x001E006E, 0x0005E600, 0xFF110032, 0x00640014, 0xDC00FE16, 0x003C005A, 0x001ED200, 0xFE1A0046, 0x005A0028, 0xC800FD1C, 0x00500055, 0x0032BE00, 0xFC20005A, 0x0050003C, 0xB400FB23, 0x0064004D, 0x00467800, 0xF926006E, 0x00410050, 0x5000F828, 0x00780036, 0x005A2800, 0x0000001E, 0x008C0000, 0xFF000006, 0x001E0078, 0x0000F000, 0x000C001E, 0x006E0005, 0xE6000011, 0x00320064, 0x0014DC00, 0x0016003C, 0x005A001E, 0xD200001A, 0x0046005A, 0x0028C800, 0x001C0050, 0x00550032, 0xBE000020, 0x005A0050, 0x003CB400, 0x00240064, 0x004D0046, 0x78000027, 0x006E0041, 0x00505000, 0x002A0078, 0x0036005A, 0x28000000 };

s32 D_E00B8CA4[] = { 0x00000000, 0x00000028, 0x00000037, 0x000000BE, 0x00000014, 0x00000082, 0x0000010E, 0x0000012C, 0x00000000, 0x00000000, 0x00000000 };

void water_fountain_appendGfx(void* effect);
void water_fountain_init(EffectInstance* effect);
void water_fountain_update(EffectInstance* effect);
void water_fountain_render(EffectInstance* effect);

EffectInstance* water_fountain_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 arg5) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    WaterFountainFXData* data;
    s32 numParts = 1;

    effectBp.init = water_fountain_init;
    effectBp.update = water_fountain_update;
    effectBp.renderWorld = water_fountain_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_WATER_FOUNTAIN;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.waterFountain = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_24 = 255;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_34 = arg4;
    data->unk_18 = 70;
    data->unk_1C = 180;
    data->unk_20 = 255;
    data->unk_28 = 255;
    data->unk_2C = 255;
    data->unk_30 = 255;
    data->unk_38 = 0;
    data->unk_3C = 1.0f;
    data->unk_40 = 1.0f;

    return effect;
}

void water_fountain_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/water_fountain", water_fountain_update);

void water_fountain_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = water_fountain_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00B8200(void) {
}

INCLUDE_ASM(s32, "effects/water_fountain", water_fountain_appendGfx);
