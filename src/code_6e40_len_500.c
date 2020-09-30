#include "common.h"

void initialize_curtains(void) {
    D_8009BAA0 = 0;
    D_8009BA90 = 2.0f;
    D_8009BA94 = 2.0f;
    D_8009BA98 = 0;
    D_8009BA9C = 0;
}

void update_curtains(void) {
}

INCLUDE_ASM(s32, "code_6e40_len_500", render_curtains);

void set_curtain_scale_goal(f32 arg0) {
    D_8009BA94 = arg0;
}

void set_curtain_scale(f32 arg0) {
    D_8009BA94 = arg0;
    D_8009BA90 = arg0;
}

void set_curtain_draw_callback(s32 arg0) {
    D_8009BAA0 = arg0;
}

void set_curtain_fade_goal(f32 arg0) {
    D_8009BA9C = arg0;
}

void set_curtain_fade(f32 arg0) {
    D_8009BA9C = arg0;
    D_8009BA98 = arg0;
}
