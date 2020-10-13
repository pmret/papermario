#include "common.h"

void poll_rumble(void) {
    // TODO: replace with defines
    nuContRmbCheck(0);
    nuContRmbModeSet(0, 2);
}

INCLUDE_ASM(s32, "code_42e0_len_1f60", start_rumble);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_80028F8C);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_80028FE0);

f32 length2D(f32 x, f32 y) {
    return sqrtf(SQ(x) + SQ(y));
}

INCLUDE_ASM(HeapNode*, "code_42e0_len_1f60", _heap_create, void* addr, s32 size);

INCLUDE_ASM(s32, "code_42e0_len_1f60", _heap_malloc);

INCLUDE_ASM(s32, "code_42e0_len_1f60", _heap_malloc_tail);

INCLUDE_ASM(s32, "code_42e0_len_1f60", _heap_free);

INCLUDE_ASM(s32, "code_42e0_len_1f60", _heap_realloc);

INCLUDE_ASM(s32, "code_42e0_len_1f60", cosine);

s32 sign(s32 val) {
    s32 sign = -1;

    if (val >= 0) {
        sign = val > 0;
    }
    return sign;
}

INCLUDE_ASM(s32, "code_42e0_len_1f60", int_to_string);

void mem_clear(s8* data, s32 numBytes) {
    while (numBytes > 0) {
        *data = 0;
        data++;
        numBytes--;
    }
}

INCLUDE_ASM(s32, "code_42e0_len_1f60", transform_point);

void copy_matrix(Matrix4f* src, Matrix4f* dest) {
    bcopy(src, dest, sizeof(Matrix4f));
}

INCLUDE_ASM(s32, "code_42e0_len_1f60", dma_copy);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_800297D4);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_80029860);

s32 _advance_rng(void) {
    s32* rngVal = &gRandSeed;

    (*gGameStatusPtr)->nextRNG = *rngVal = (*rngVal * 0x5D588B65) + 1;

    return *rngVal;
}

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_80029934);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_80029994);

INCLUDE_ASM(s32, "code_42e0_len_1f60", rand_int, s32 arg0);

f32 signF(f32 val) {
    f32 sign;

    if (!(val > 0.0f)) {
        sign = -1.0f;
        if (!(val < 0.0f)) {
            sign = 0.0f;
        }
    } else {
        sign = 1.0f;
    }

    return sign;
}

INCLUDE_ASM(s16, "code_42e0_len_1f60", round, f32 arg0);

INCLUDE_ASM(f32, "code_42e0_len_1f60", clamp_angle, f32 theta);

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

INCLUDE_ASM(f32, "code_42e0_len_1f60", atan2, f32 startX, f32 startZ, f32 endX, f32 endZ);

f32 get_player_normal_yaw(void) {
    return atan2(0, 0, (*gGameStatusPtr)->playerTraceNormal.x, (*gGameStatusPtr)->playerTraceNormal.z);
}

INCLUDE_ASM(s32, "code_42e0_len_1f60", get_player_normal_pitch);

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

INCLUDE_ASM(void, "code_42e0_len_1f60", add_vec2D_polar, f32* x, f32* y, f32 r, f32 theta);

INCLUDE_ASM(s32, "code_42e0_len_1f60", _wrap_trig_lookup_value);

INCLUDE_ASM(s32, "code_42e0_len_1f60", sin_cos_rad);

INCLUDE_ASM(s32, "code_42e0_len_1f60", sin_rad);

INCLUDE_ASM(s32, "code_42e0_len_1f60", cos_rad);

INCLUDE_ASM(s32, "code_42e0_len_1f60", sin_cos_deg);

INCLUDE_ASM(f32, "code_42e0_len_1f60", sin_deg, f32 x);

INCLUDE_ASM(f32, "code_42e0_len_1f60", cos_deg, f32 x);

INCLUDE_ASM(f32, "code_42e0_len_1f60", update_lerp, Easing easing, f32 start, f32 end, s32 elapsed, s32 duration);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_8002A904);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_8002AAC4);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_8002AB5C);
