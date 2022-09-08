#include "common.h"
#include "effects_internal.h"

typedef struct {
    /* 0x00 */ Gfx* displayList;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 width;
    /* 0x0A */ s16 height;
} UnkStruct; // size: 0xC

extern s32 D_E010E750[];
extern UnkStruct D_E010E79C[];
extern UnkStruct D_E010E7D8[];
extern UnkStruct D_E010E7FC[];
extern UnkStruct D_E010E838[];
extern UnkStruct D_E010E868[];

void chapter_change_init(EffectInstance* effect);
void chapter_change_update(EffectInstance* effect);
void chapter_change_render(EffectInstance* effect);
void chapter_change_appendGfx(void* effect);
void shim_draw_msg(s32, s32, s32, s32, s32, s32);
s32 shim_get_msg_width(s32, u16);

void func_E010E000(ChapterChangeFXData* data, s32 arg1, UnkStruct* arg2) {
    UnkStruct* it;
    f32 var0;
    f32 var1;
    s32 temp;
    s32 unk_1C = data->unk_1C;

    if (arg1 == 0) {
        var0 = data->unk_04;
        var1 = data->unk_08;
    } else {
        var0 = data->unk_10;
        var1 = data->unk_14;
    }

    if (arg2 != NULL) {
        for (it = arg2; it->displayList != NULL; it++) {
            gSPDisplayList(gMasterGfxPos++, it->displayList);

            temp = it->x - 384;
            gDPSetTileSize(gMasterGfxPos++, 1, (unk_1C * 4 - temp) * 4, 0, (unk_1C * 4 - it->x + 511) * 4, 0);
            gSPScisTextureRectangle(gMasterGfxPos++,
                (var0 + it->x) * 4,
                (var1 + it->y) * 4,
                (var0 + it->x + it->width) * 4,
                (var1 + it->y + it->height) * 4,
                G_TX_RENDERTILE, 0, 0, 1024, 1024);
        }

        gDPPipeSync(gMasterGfxPos++);
    }
}

EffectInstance* chapter_change_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    ChapterChangeFXData* data;
    EffectInstance* effect;
    s32 numParts = 1;

    bp.init = chapter_change_init;
    bp.update = chapter_change_update;
    bp.renderWorld = chapter_change_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_CHAPTER_CHANGE;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.chapterChange = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.chapterChange != NULL);

    data->unk_00 = arg0;
    data->unk_1C = 0;
    if (arg5 <= 0) {
        data->unk_18 = 1000;
    } else {
        data->unk_18 = arg5;
    }
    data->unk_10 = arg1;
    data->unk_04 = arg1;
    data->unk_14 = arg2;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_50 = arg4;
    data->unk_20 = 255;
    data->unk_24 = 255;
    data->unk_28 = 255;
    data->unk_2C = 255;
    data->unk_30 = 0;
    data->unk_34 = 0;
    data->unk_38 = 0;
    if (arg0 == 0 || arg0 - 10 < 9U) {
        data->unk_3C = 0;
    } else {
        data->unk_3C = 255;
    }
    data->unk_54 = D_E010E750[arg0];
    if (data->unk_54 >= 0) {
        data->unk_40 = 160;
        data->unk_44 = 160;
        data->unk_48 = shim_get_msg_width(data->unk_54, 0);
        data->unk_4C = 24;
    }

    return effect;
}

void chapter_change_init(EffectInstance* effect) {
}

void chapter_change_update(EffectInstance* effect) {
    ChapterChangeFXData* data = effect->data.chapterChange;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_18 = 0x10;
    }

    if (data->unk_18 < 1000) {
        data->unk_18--;
    }

    data->unk_1C++;

    if (data->unk_18 < 0) {
        shim_remove_effect(effect);
    }
}

void chapter_change_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = chapter_change_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void chapter_change_appendGfx(void* effect) {
    ChapterChangeFXData* data = ((EffectInstance*)effect)->data.chapterChange;
    s32 unk_2C = data->unk_2C;
    u32 unk_00 = data->unk_00;
    UnkStruct* ptr0;
    UnkStruct* ptr1;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    switch (unk_00) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            ptr0 = D_E010E7FC;
            ptr1 = &D_E010E868[(unk_00 - 1) * 2];
            break;
        case 9:
            ptr0 = D_E010E7D8;
            ptr1 = NULL;
            break;
        case 0:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
            ptr0 = D_E010E79C;
            ptr1 = D_E010E838;
            break;
        default:
            ptr1 = NULL;
            ptr0 = NULL;
            break;
    }

    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_20, data->unk_24, data->unk_28, unk_2C);
    gDPSetEnvColor(gMasterGfxPos++, data->unk_30, data->unk_34, data->unk_38, data->unk_3C);

    func_E010E000(data, 0, ptr0);
    func_E010E000(data, 1, ptr1);

    if (data->unk_54 >= 0) {
        shim_draw_msg(data->unk_54, data->unk_40 - data->unk_48, data->unk_44, 255, 21, 0);
    }

    gDPPipeSync(gMasterGfxPos++);
}
