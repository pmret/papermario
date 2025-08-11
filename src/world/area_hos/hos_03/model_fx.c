#include "hos_03.h"

#include "world/common/atomic/TexturePan.inc.c"

u16 N(D_80243BCC_A1ECCC) = 0;
u16 N(D_80243BCE_A1ECCE) = 0;

void N(func_8024033C_A1B43C)(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    f32 angle = sins(N(D_80243BCC_A1ECCC)) * (1.0f / 32768.0f) * 45.0f;
    N(D_80243BCC_A1ECCC) += 0x400;
    guRotate(&gDisplayContext->matrixStack[gMatrixListPos], angle, 0.0f, 1.0f, 0.0f);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    mdl_get_copied_vertices(VTX_COPY_1, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(N(D_80243BCE_A1ECCE) * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 100;
        colors[1] = temp1 * 155 / 0x8000 + 100;

        temp3 = sins(N(D_80243BCE_A1ECCE) / 0x8000 * (((i / 2) % 3 + 1) << 15)  + N(D_80243BCE_A1ECCE) / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000;
    }

    gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH);
    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_1));
    N(D_80243BCE_A1ECCE) += 0x666;
}

u16 N(D_80243BD0_A1ECD0) = 0;

void N(func_8024060C_A1B70C)(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(VTX_COPY_2, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(N(D_80243BD0_A1ECD0) * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 100;
        colors[1] = temp1 * 155 / 0x8000 + 100;

        temp3 = sins(N(D_80243BD0_A1ECD0) / 0x8000 * (((i / 2) % 3 + 1) << 15)  + N(D_80243BD0_A1ECD0) / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_2));
    N(D_80243BD0_A1ECD0) += (s32)RAD_TO_BINANG(25.1898);
}

u16 N(AuroraPhaseAngle) = 0;

void N(build_gfx_aurora)(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;

    mdl_get_copied_vertices(VTX_COPY_0, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        Vtx* vtxDst = &copiedVertices[i];
        Vtx* vtxSrc = &firstVertex[i];
        s32 v0 = sins(N(AuroraPhaseAngle) * (i % 3 + 1) + i * 0x2AAA) * 50;
        vtxDst->v.ob[1] = vtxSrc->v.ob[1] + v0 / 0x8000;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_0));
    N(AuroraPhaseAngle) += 0xA3;
}

u16 N(HaloScalePhaseAngle) = 0;

void N(build_gfx_lamp_halos)(void) {
    f32 scale = ((sins(N(HaloScalePhaseAngle)) * (1.0f / 0x8000)) * 0.5 * 0.5) + 1.05;

    N(HaloScalePhaseAngle) += (s32)RAD_TO_BINANG(25.1720);
    guScale(&gDisplayContext->matrixStack[gMatrixListPos], scale, scale, scale);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

API_CALLABLE(N(func_80240A50_A1BB50)) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupAurora) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  100,  -80,  -50,  120)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o29, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o204, TEX_PANNER_1)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP( -300,  500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o87, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o134, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o171, TEX_PANNER_3)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(    0, -800,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o90, TEX_PANNER_4)
    Call(SetTexPanner, MODEL_o135, TEX_PANNER_4)
    Call(SetTexPanner, MODEL_o172, TEX_PANNER_4)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(    0,-1500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o91, TEX_PANNER_5)
    Call(SetTexPanner, MODEL_o136, TEX_PANNER_5)
    Call(SetTexPanner, MODEL_o173, TEX_PANNER_5)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_6)
        TEX_PAN_PARAMS_STEP(    0, 3000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o159, TEX_PANNER_6)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_7)
        TEX_PAN_PARAMS_STEP(    0, 4000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o160, TEX_PANNER_7)
    Call(MakeLocalVertexCopy, VTX_COPY_0, MODEL_o76, true)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(build_gfx_aurora)), nullptr)
    Call(SetModelCustomGfx, MODEL_o76, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Return
    End
};
