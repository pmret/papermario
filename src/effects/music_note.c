#include "common.h"
#include "effects_internal.h"

void music_note_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/music_note", music_note_main);

void music_note_init(void) {
}

INCLUDE_ASM(s32, "effects/music_note", music_note_update);

void music_note_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = music_note_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/music_note", music_note_appendGfx);
