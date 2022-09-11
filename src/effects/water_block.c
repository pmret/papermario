#include "common.h"
#include "effects_internal.h"

s32 D_E00B4CF0[] = { 0x1904E700, 0x04010048, 0xB0B0B000, 0x1600EA00, 0x03C30000, 0xB0B0B000, 0xEA00EA00, 0x003D0000, 0xB0B0B000, 0xE704E700, 0x00010048, 0xB0B0B000, 0x192EE700, 0x040103B7, 0xB0B0B000, 0xE72EE700, 0x000103B7, 0xB0B0B000, 0x1632EA00, 0x037A03E5, 0xAED0D800, 0xEA32EA00, 0x008503E5, 0xAED0D800, 0xEA321600, 0x008503E5, 0xAED0D800, 0x16321600, 0x037A03E5, 0xAED0D800, 0xEA00EA00, 0x00850019, 0x94A5B000, 0x1600EA00, 0x037A0019, 0x94A5B000, 0x16001600, 0x037A0019, 0x94A5B000, 0xEA001600, 0x00850019, 0x94A5B000, 0xEA321600, 0x03C303FD, 0x786E8800, 0xEA32EA00, 0x003D03FD, 0x786E8800, 0xE72EE700, 0x000003B7, 0x786E8800, 0xE72E1900, 0x040003B7, 0x786E8800, 0xE704E700, 0x00000048, 0x786E8800, 0xE7041900, 0x04000048, 0x786E8800, 0xEA00EA00, 0x003D0000, 0x786E8800, 0xEA001600, 0x03C30000, 0x786E8800, 0xEA32EA00, 0x003D03FD, 0xB0B0B000, 0x1632EA00, 0x03C303FD, 0xB0B0B000, 0x16001600, 0x03C30000, 0x786E8800, 0x1600EA00, 0x003D0000, 0x786E8800, 0x1904E700, 0x00000048, 0x786E8800, 0x19041900, 0x04000048, 0x786E8800, 0x192EE700, 0x000003B7, 0x786E8800, 0x192E1900, 0x040003B7, 0x786E8800, 0x1632EA00, 0x003D03FD, 0x786E8800, 0xEA001600, 0x003D0000, 0xF0F0F000, 0x19041900, 0x04010048, 0xF0F0F000, 0x192E1900, 0x040103B7, 0xF0F0F000, 0x16321600, 0x03C303FD, 0x786E8800, 0x16001600, 0x03C30000, 0xF0F0F000, 0xE7041900, 0x00010048, 0xF0F0F000, 0xE72E1900, 0x000103B7, 0xF0F0F000, 0x16321600, 0x03C303FD, 0xF0F0F000, 0xEA321600, 0x003D03FD, 0xF0F0F000 };

void water_block_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/water_block", water_block_main);

void water_block_init(void) {
}

INCLUDE_ASM(s32, "effects/water_block", water_block_update);

void water_block_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = water_block_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 20;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00B4574(void) {
}

INCLUDE_ASM(s32, "effects/water_block", water_block_appendGfx);
