#include "common.h"

static Vtx_t* N(TriNormVertexBuffer)[32]; // unk length

enum {
    READ_STATE_CONTINUE    = 0,
    READ_STATE_DONE        = 1,
    READ_STATE_TRIANGLE    = 2,
};

void N(GetFirstTriangleNormal)(Gfx* inGfx, f32* outNx, f32* outNy, f32* outNz) {
    s32 dummy[2];
    Gfx* gfx = inGfx;
    s32 readState;
    f32 v1x, v1y, v1z;
    f32 v2x, v2y, v2z;
    f32 v3x, v3y, v3z;
    f32 d12x, d12y, d12z;
    f32 d32x, d32y, d32z;
    f32 nx, ny, nz;
    f32 norm;

    Vtx_t* vtxArray;
    u32 vtxCount;
    s32 vtxEnd;
    s32 i;

    v1x = v1y = v1z = 0.0f;
    v2x = v2y = v2z = 0.0f;
    v3x = v3y = v3z = 0.0f;

    while (true) {
        u32 w0 = gfx->words.w0;
        u32 w1 = gfx->words.w1;
        s32 op = w0 >> 24;
        readState = READ_STATE_CONTINUE;
        switch (op) {
            case G_ENDDL:
                readState = READ_STATE_DONE;
                break;
            case G_DL:
                N(GetFirstTriangleNormal)((Gfx* ) w1, outNx, outNy, outNz);
                break;
            case G_VTX:
                vtxCount = (w0 >> 0xC) & 0xFF;
                vtxArray = (Vtx_t*) w1;
                for (i = 0; i < vtxCount; i++) {
                    vtxEnd = (w0 >> 1) & 0x7F;
                    N(TriNormVertexBuffer)[(vtxEnd - vtxCount) + i] = &(vtxArray)[i];
                }
                break;
            case G_TRI1:
                v1x = N(TriNormVertexBuffer)[((w1 >> 16) & 0xFF) / 2]->ob[0];
                v1y = N(TriNormVertexBuffer)[((w1 >> 16) & 0xFF) / 2]->ob[1];
                v1z = N(TriNormVertexBuffer)[((w1 >> 16) & 0xFF) / 2]->ob[2];
                v2x = N(TriNormVertexBuffer)[((w1 >> 8) & 0xFF) / 2]->ob[0];
                v2y = N(TriNormVertexBuffer)[((w1 >> 8) & 0xFF) / 2]->ob[1];
                v2z = N(TriNormVertexBuffer)[((w1 >> 8) & 0xFF) / 2]->ob[2];
                v3x = N(TriNormVertexBuffer)[(w1 & 0xFF) / 2]->ob[0];
                v3y = N(TriNormVertexBuffer)[(w1 & 0xFF) / 2]->ob[1];
                v3z = N(TriNormVertexBuffer)[(w1 & 0xFF) / 2]->ob[2];
                readState = READ_STATE_TRIANGLE;
                break;
            case G_TRI2:
                v1x = N(TriNormVertexBuffer)[((w0 >> 16) & 0xFF) / 2]->ob[0];
                v1y = N(TriNormVertexBuffer)[((w0 >> 16) & 0xFF) / 2]->ob[1];
                v1z = N(TriNormVertexBuffer)[((w0 >> 16) & 0xFF) / 2]->ob[2];
                v2x = N(TriNormVertexBuffer)[((w0 >> 8) & 0xFF) / 2]->ob[0];
                v2y = N(TriNormVertexBuffer)[((w0 >> 8) & 0xFF) / 2]->ob[1];
                v2z = N(TriNormVertexBuffer)[((w0 >> 8) & 0xFF) / 2]->ob[2];
                v3x = N(TriNormVertexBuffer)[(w0 & 0xFF) / 2]->ob[0];
                v3y = N(TriNormVertexBuffer)[(w0 & 0xFF) / 2]->ob[1];
                v3z = N(TriNormVertexBuffer)[(w0 & 0xFF) / 2]->ob[2];
                readState = READ_STATE_TRIANGLE;
                break;
        }

        if (readState != READ_STATE_CONTINUE) {
            break;
        }
        gfx++;
    }

    if (readState == READ_STATE_TRIANGLE) {
        // get two vectors from three points
        d12x = v1x - v2x;
        d12y = v1y - v2y;
        d12z = v1z - v2z;
        d32x = v3x - v2x;
        d32y = v3y - v2y;
        d32z = v3z - v2z;
        // cross product to get normal vector
        nx = (d12y * d32z) - (d12z * d32y);
        ny = (d12z * d32x) - (d12x * d32z);
        nz = (d12x * d32y) - (d12y * d32x);
        norm = sqrtf(SQ(nx) + SQ(ny) + SQ(nz));
        *outNx = nx / norm;
        *outNy = ny / norm;
        *outNz = nz / norm;
    }
}
