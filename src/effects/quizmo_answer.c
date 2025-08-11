#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000400_3A2840[];
extern Gfx D_090004A8_3A28E8[];

EffectInstance* quizmo_answer_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;

    bp.unk_00 = 0;
    bp.init = nullptr;
    bp.update = nullptr;
    bp.renderScene = nullptr;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_QUIZMO_ANSWER;

    effect = create_effect_instance(&bp);
    effect->data.quizmoAnswer = nullptr;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->shared->graphics));

    if (arg0 == 0) {
        gSPDisplayList(gMainGfxPos++, D_09000400_3A2840);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 64, 64, 230);
    } else {
        gSPDisplayList(gMainGfxPos++, D_090004A8_3A28E8);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 80, 80, 255, 230);
    }

    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gSPTextureRectangle(gMainGfxPos++, 512, 304, 768, 560, G_TX_RENDERTILE, 0, 1024, 1024, 1024);
    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x00, nullptr);

    remove_effect(effect);
    return nullptr;
}
