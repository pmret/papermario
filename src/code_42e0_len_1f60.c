#include "common.h"

void poll_rumble(void) {
    // TODO: replace with defines
    nuContRmbCheck(0);
    nuContRmbModeSet(0, 2);
}

INCLUDE_ASM("code_42e0_len_1f60", start_rumble);

INCLUDE_ASM("code_42e0_len_1f60", func_80028F8C);

INCLUDE_ASM("code_42e0_len_1f60", func_80028FE0);

f32 length2D(f32 x, f32 y) {
    return sqrtf(SQ(x) + SQ(y));
}

HeapNode* INCLUDE_ASM("code_42e0_len_1f60", _heap_create, void* addr, s32 size);

INCLUDE_ASM("code_42e0_len_1f60", _heap_malloc);

INCLUDE_ASM("code_42e0_len_1f60", _heap_malloc_tail);

INCLUDE_ASM("code_42e0_len_1f60", _heap_free);

INCLUDE_ASM("code_42e0_len_1f60", _heap_realloc);

INCLUDE_API_ASM("code_42e0_len_1f60", cosine);

s32 sign(s32 val) {
    s32 ret = -1;

    if (val >= 0) {
        ret = val > 0;
    }
    return ret;
}

INCLUDE_ASM("code_42e0_len_1f60", int_to_string);

void mem_clear(s8* data, s32 numBytes) {
    while (numBytes > 0) {
        *data = 0;
        data++;
        numBytes--;
    }
}

INCLUDE_ASM("code_42e0_len_1f60", transform_point);

void copy_matrix(Matrix4f* src, Matrix4f* dest) {
    bcopy(src, dest, sizeof(Matrix4f));
}

INCLUDE_ASM("code_42e0_len_1f60", dma_copy);

INCLUDE_ASM("code_42e0_len_1f60", func_80029860);

s32 _advance_rng(void) {
    s32* rngVal = &D_80074410;

    (*gGameStatusPtr)->nextRNG = *rngVal = (*rngVal * 0x5D588B65) + 1;

    return *rngVal;
}

INCLUDE_ASM("code_42e0_len_1f60", func_80029934);

INCLUDE_ASM("code_42e0_len_1f60", func_80029994);

s32 INCLUDE_ASM("code_42e0_len_1f60", rand_int, s32 arg0);

f32 signF(f32 val) {
    f32 ret;

    if (!(val > 0.0f)) {
        ret = -1.0f;
        if (!(val < 0.0f)) {
            ret = 0.0f;
        }
    } else {
        ret = 1.0f;
    }

    return ret;
}

INCLUDE_API_ASM("code_42e0_len_1f60", round);

f32 INCLUDE_ASM("code_42e0_len_1f60", clamp_angle, f32 theta);

f32 get_clamped_angle_diff(f32 a, f32 b) {
    if (fabsf(b - a) >= 180.0f) {
        if (b < a) {
            b += 360.0f;
        } else {
            b -= 360.0f;
        }
    }
    return b - a;
}

f32 INCLUDE_ASM("code_42e0_len_1f60", atan2, f32 startX, f32 startZ, f32 endX, f32 endZ);

f32 get_player_normal_yaw(void) {
    return atan2(0, 0, (*gGameStatusPtr)->playerTraceNormal[0], (*gGameStatusPtr)->playerTraceNormal[2]);
}

INCLUDE_ASM("code_42e0_len_1f60", get_player_normal_pitch);

f32 dist2D(f32 ax, f32 ay, f32 bx, f32 by) {
    f32 xDiff = bx - ax;
    f32 yDiff = by - ay;

    return sqrtf(SQ(xDiff) + SQ(yDiff));
}

f32 dist3D(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz) {
    f32 xDiff = bx - ax;
    f32 yDiff = by - ay;
    f32 zDiff = bz - az;

    return sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff));
}

void INCLUDE_ASM("code_42e0_len_1f60", add_vec2D_polar, f32* x, f32* y, f32 r, f32 theta);

INCLUDE_ASM("code_42e0_len_1f60", _wrap_trig_lookup_value);

INCLUDE_ASM("code_42e0_len_1f60", sin_cos_rad);

INCLUDE_ASM("code_42e0_len_1f60", sin_rad);

INCLUDE_ASM("code_42e0_len_1f60", cos_rad);

INCLUDE_ASM("code_42e0_len_1f60", sin_cos_deg);

f32 INCLUDE_ASM("code_42e0_len_1f60", sin_deg, f32 x);

f32 INCLUDE_ASM("code_42e0_len_1f60", cos_deg, f32 x);

f32 INCLUDE_ASM("code_42e0_len_1f60", update_lerp, Easing easing, f32 start, f32 end, s32 elapsed, s32 duration);

INCLUDE_ASM("code_42e0_len_1f60", func_8002A904);

INCLUDE_ASM("code_42e0_len_1f60", func_8002AAC4);

INCLUDE_ASM("code_42e0_len_1f60", func_8002AB5C);
