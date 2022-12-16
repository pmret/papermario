#include "kmr_22.h"
#include "effects.h"

extern s16 D_80240DE0_900450[];

BSS EffectInstance* D_802483C0;
BSS s32 D_802483C4;

ApiStatus func_80240010_8FF680(Evt* script, s32 isInitialCall) {
    s32 var_s0 = script->varTable[0];
    s32 x, y;
    s32 xOffset = 0;

    if (var_s0 == 0) {
        var_s0 = 9;
        xOffset = 38;
    }

    if (isInitialCall) {
        set_curtain_scale_goal(1.0f);
        D_802483C0 = fx_chapter_change(var_s0, 100.0f, 100.0f, 0.0f, 1.0f, 0);
        D_802483C4 = 0;
    }

    x = xOffset + 117;
    if (D_802483C4 >= 0) {
        if (D_802483C4 < 0x14) {
            x -= D_80240DE0_900450[D_802483C4];
        }
    } else {
        x = xOffset - 193;
    }
    y = 58;
    D_802483C0->data.chapterChange->chapterPos.x = x;
    D_802483C0->data.chapterChange->chapterPos.y = y;

    x = xOffset + 117;
    if (D_802483C4 >= 10) {
        if (D_802483C4 < 30) {
            y -= D_80240DE0_900450[D_802483C4 - 10];
        }
    } else {
        y = -252;
    }
    D_802483C0->data.chapterChange->endOfPos.x = x;
    D_802483C0->data.chapterChange->endOfPos.y = y;

    x = 280;
    if (D_802483C4 >= 20) {
        if (D_802483C4 < 40) {
            x += D_80240DE0_900450[D_802483C4 - 20];
        }
    } else {
        x = 590;
    }
    y = 90;
    D_802483C0->data.chapterChange->unk_40 = x;
    D_802483C0->data.chapterChange->unk_44 = y;
    D_802483C4++;

    return ApiStatus_BLOCK;
}

ApiStatus func_802401E0_8FF850(Evt* script, s32 isInitialCall) {
    set_curtain_scale_goal(2.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80240208_8FF878(Evt* script, s32 isInitialCall) {
    ApiStatus ret;

    if (gGameStatusPtr->pressedButtons[0] & BUTTON_START) {
        ret = ApiStatus_DONE2;
    } else {
        ret = ApiStatus_BLOCK;
    }

    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        ret = ApiStatus_DONE2;
        script->varTable[0] = -1;
    }
    return ret;
}
