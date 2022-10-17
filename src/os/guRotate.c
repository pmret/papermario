#include "PR/guint.h"

f32 sin_rad(f32 x);
f32 cos_rad(f32 x);

s32 _osViModeNtscLan1[] = { 0x02000000, 0x0000311E, 0x00000140, 0x03E52239, 0x0000020D, 0x00000C15, 0x0C150C15, 0x006C02EC, 0x00000200, 0x00000000, 0x00000280, 0x00000400, 0x002501FF, 0x000E0204, 0x00000002, 0x00000280, 0x00000400, 0x002501FF, 0x000E0204, 0x00000002 };

s32 _osViModeMPalLan1[] = { 0x1E000000, 0x0000311E, 0x00000140, 0x04651E39, 0x0000020D, 0x00040C11, 0x0C190C1A, 0x006C02EC, 0x00000200, 0x00000000, 0x00000280, 0x00000400, 0x002501FF, 0x000E0204, 0x00000002, 0x00000280, 0x00000400, 0x002501FF, 0x000E0204, 0x00000002 };

void guRotateF(float mf[4][4], float a, float x, float y, float z) {
	static float dtor = 3.1415926 / 180.0;
	float sine;
	float cosine;
	float ab, bc, ca, t;
    float xs, ys, zs;

	guNormalize(&x, &y, &z);
	a *= dtor;
	sine = sin_rad(a);
	cosine = cos_rad(a);
	t = 1.0f - cosine;
	ab = x * y * t;
	bc = y * z * t;
	ca = z * x * t;

	guMtxIdentF(mf);

    ys = y * sine;
    xs = x * sine;
    zs = z * sine;

	t = x * x;
	mf[0][0] = t + cosine * (1.0f - t);
	mf[2][1] = bc - xs;
	mf[1][2] = bc + xs;

	t = y * y;
	mf[1][1] = t + cosine * (1.0f - t);
	mf[2][0] = ca + ys;
	mf[0][2] = ca - ys;

	t = z * z;
	mf[2][2] = t + cosine * (1.0f - t);
	mf[1][0] = ab - zs;
	mf[0][1] = ab + zs;
}

void guRotate(Mtx *m, float a, float x, float y, float z) {
	float mf[4][4];

	guRotateF(mf, a, x, y, z);

	guMtxF2L(mf, m);
}
