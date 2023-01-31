#include "common.h"

enum {
    INTRO_MATH_EASING_LINEAR            = 0,
    INTRO_MATH_EASING_SIN_OUT           = 1,
    INTRO_MATH_EASING_SIN_OUT_DELAYED   = 2,
    INTRO_MATH_EASING_COS_IN_OUT        = 3,
    INTRO_MATH_EASING_4                 = 4,
    #ifdef INTRO_MATH_EXTENDED
    INTRO_MATH_EASING_5                 = 5,
    #endif
};

void N(lerp_value_with_max_step)(f32 start, f32 end, f32 current, f32 maximum, f32* out) {
    f32 remaining = end - current;

    if (end - start > 0.0f) {
        if (remaining < 0.0f) {
            *out = end;
        } else if (maximum < remaining) {
            *out += maximum;
        } else {
            *out += remaining;
        }
    } else if (remaining > 0.0f) {
        *out = end;
    } else if (remaining < -maximum) {
        *out -= maximum;
    } else {
        *out += remaining;
    }
}

void N(interp_value_with_easing)(s32 easingMode, f32 start, f32 end, f32 curent, f32 max, f32* out) {
    f32 alpha;

    if (curent > max) {
        curent = max;
    }

    switch (easingMode) {
        case INTRO_MATH_EASING_SIN_OUT:
            alpha = sin_deg((curent / max) * 90.0f);
            break;
        case INTRO_MATH_EASING_SIN_OUT_DELAYED:
            if (curent < 30.0f) {
                alpha = 0.0f;
            } else {
                alpha = sin_deg((((curent - 30.0f) / (max - 30.0f)) * 90.0f) + -90.0f) + 1.0f;
            }
            break;
        case INTRO_MATH_EASING_COS_IN_OUT:
            alpha = (sin_deg(((curent / max) * 180.0f) - 90.0f) + 1.0f) * 0.5;
            break;
        case INTRO_MATH_EASING_4:
            alpha = sin_deg(((curent / max) * 90.0f) - 90.0f) + 1.0f;
            break;
        #ifdef INTRO_MATH_EXTENDED
        case INTRO_MATH_EASING_5:
            alpha = (2.0 * (sin_deg(((curent / max) * 60.0f) - 60.0f) + 0.8660254f)) / 1.7320507764816284;
            break;
        #endif
        default:
            alpha = curent / max;
            break;
    }
    *out = start + ((end - start) * alpha);
}
