#include "mac_05.h"

s32 N(UnusedInt) = 0;

f32 N(Club64SignAlphaModulus) = 0.0f;

void N(hsl_to_rgb)(f32 hue, f32 saturation, f32 lightness, f32* outR, f32* outG, f32* outB) {
    f32 hueSector;
    f32 p, q, m;
    f32 s, t;

    if (lightness <= 0.5f) {
        q = lightness * (1.0 + saturation);
    } else {
        q = (lightness + saturation) - (lightness * saturation);
    }

    if (q == 0.0f) {
        *outB = 0.0f;
        *outG = 0.0f;
        *outR = 0.0f;
        return;
    }

    hue *= 6.0f;
    hueSector = (s32) hue;
    p = (2 * lightness) - q;
    m = q * ((q - p) / q) * (hue - hueSector);
    s = p + m;
    t = q - m;

    switch ((s32) hueSector) {
        case 0:
            *outR = q;
            *outG = s;
            *outB = p;
            break;
        case 1:
            *outR = t;
            *outG = q;
            *outB = p;
            break;
        case 2:
            *outR = p;
            *outG = q;
            *outB = s;
            break;
        case 3:
            *outR = p;
            *outG = t;
            *outB = q;
            break;
        case 4:
            *outR = s;
            *outG = p;
            *outB = q;
            break;
        case 5:
            *outR = q;
            *outG = p;
            *outB = t;
            break;
    }
}

void N(gfx_build_club_64)(s32 index) {
    Vtx* first;
    Vtx* copied;
    s32 numCopied;
    s32 i;
    f32 colR, colG, colB;

    mdl_get_copied_vertices(VTX_COPY_3, &first, &copied, &numCopied);

    for (i = 0; i < numCopied; i++) {
        u8* colors = copied[i].v.cn;
        f32 hue = N(Club64SignAlphaModulus) + (f32)i / (f32)numCopied;
        if (hue > 1.0) {
            hue -= 1.0;
        }
        N(hsl_to_rgb)(hue, 1.0f, 0.5f, &colR, &colG, &colB);

        colors[0] = colR * 255.0f;
        colors[1] = colG * 255.0f;
        colors[2] = colB * 255.0f;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_3));
    N(Club64SignAlphaModulus) += 0.01;
    if (N(Club64SignAlphaModulus) > 1.0) {
        N(Club64SignAlphaModulus) -= 1.0f;
    }
}

EvtScript N(EVS_AnimateClub64Sign) = {
    Call(MakeLocalVertexCopy, VTX_COPY_3, MODEL_o187, true)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_3, Ref(N(gfx_build_club_64)), nullptr)
    Call(SetModelCustomGfx, MODEL_o187, CUSTOM_GFX_3, -1)
    Return
    End
};
