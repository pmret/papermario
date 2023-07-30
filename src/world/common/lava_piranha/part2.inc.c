#include "ld_addrs.h"

BSS s32 N(VineRenderState);

MAP_STATIC_PAD(1, unk_static_pad);

#define PIRANHA_DMA_ENTRY(name) \
    (s32) world_model_anim_kzn_##name##_ROM_START,\
    (s32) world_model_anim_kzn_##name##_ROM_END,\
    (s32) world_model_anim_kzn_##name##_VRAM

s32 N(VineAnimationsDmaTable)[] = {
    PIRANHA_DMA_ENTRY(00),
    PIRANHA_DMA_ENTRY(01),
    PIRANHA_DMA_ENTRY(02),
    PIRANHA_DMA_ENTRY(03),
    PIRANHA_DMA_ENTRY(04),
    PIRANHA_DMA_ENTRY(05),
    PIRANHA_DMA_ENTRY(06),
    PIRANHA_DMA_ENTRY(07),
    PIRANHA_DMA_ENTRY(08),
    PIRANHA_DMA_ENTRY(09),
    PIRANHA_DMA_ENTRY(0A),
    PIRANHA_DMA_ENTRY(0B),
    PIRANHA_DMA_ENTRY(0C),
    PIRANHA_DMA_ENTRY(0D),
    PIRANHA_DMA_ENTRY(0E),
    PIRANHA_DMA_ENTRY(0F),
    PIRANHA_DMA_ENTRY(10),
    PIRANHA_DMA_ENTRY(11),
    PIRANHA_DMA_ENTRY(12),
    PIRANHA_DMA_ENTRY(13),
    PIRANHA_DMA_ENTRY(14),
    PIRANHA_DMA_ENTRY(15),
    PIRANHA_DMA_ENTRY(16),
    PIRANHA_DMA_ENTRY(17),
    PIRANHA_DMA_ENTRY(18),
    PIRANHA_DMA_ENTRY(19),
    PIRANHA_DMA_ENTRY(1A),
    PIRANHA_DMA_ENTRY(1B),
    PIRANHA_DMA_ENTRY(1C),
    PIRANHA_DMA_ENTRY(1D),
    PIRANHA_DMA_ENTRY(1E),
    PIRANHA_DMA_ENTRY(1F),
    PIRANHA_DMA_ENTRY(20),
    PIRANHA_DMA_ENTRY(21),
    PIRANHA_DMA_ENTRY(22),
    PIRANHA_DMA_ENTRY(23),
    PIRANHA_DMA_ENTRY(24),
};

void N(make_vine_interpolation)(LavaPiranhaVine* vine) {
    Evt dummyEvt;
    Evt* dummyEvtPtr = &dummyEvt;
    s32 args[4];
    s32 count;

    // setup dummy call to LoadPath
    args[0] = 3 * vine->boneCount;      // generate three output samples per input
    args[1] = (s32) &vine->bonePos;     // points
    args[2] = vine->boneCount;          // num vectors
    args[3] = EASING_LINEAR;
    dummyEvtPtr->ptrReadPos = args;
    LoadPath(dummyEvtPtr, 1);

    count = 0;
    do {
        GetNextPathPos(dummyEvtPtr, 1);
        vine->points[count].x = evt_get_float_variable(dummyEvtPtr, LVar1);
        vine->points[count].y = evt_get_float_variable(dummyEvtPtr, LVar2);
        vine->points[count].z = evt_get_float_variable(dummyEvtPtr, LVar3);
        count++;
    } while (dummyEvtPtr->varTable[0] != 0);
    vine->numPoints = count;
}

API_CALLABLE(N(SetVineBonePos)) {
    Bytecode* args = script->ptrReadPos;
    s32 vineIdx = evt_get_variable(script, *args++);
    s32 jointIdx = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
    LavaPiranhaVine* vine = &vines[vineIdx];

    vine->bonePos[jointIdx].x = x;
    vine->bonePos[jointIdx].y = y;
    vine->bonePos[jointIdx].z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetVineBoneRot)) {
    Bytecode* args = script->ptrReadPos;
    s32 vineIdx = evt_get_variable(script, *args++);
    s32 jointIdx = evt_get_variable(script, *args++);
    s32 rx = evt_get_variable(script, *args++);
    s32 ry = evt_get_variable(script, *args++);
    s32 rz = evt_get_variable(script, *args++);
    LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
    LavaPiranhaVine* vine = &vines[vineIdx];

    vine->boneRot[jointIdx] = rz;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetVineBoneScale)) {
    Bytecode* args = script->ptrReadPos;
    s32 vineIdx = evt_get_variable(script, *args++);
    s32 jointIdx = evt_get_variable(script, *args++);
    s32 sx = evt_get_variable(script, *args++);
    s32 sy = evt_get_variable(script, *args++);
    s32 sz = evt_get_variable(script, *args++);
    LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
    LavaPiranhaVine* vine = &vines[vineIdx];

    // do nothing
    return ApiStatus_DONE2;
}

void N(appendGfx_piranha_vines)(void* data) {
    Vtx_t* vtxBuffer;
    Vtx_t* vtx;

    f32 boneLength;
    s32 boneCount;

    f32 angle;
    f32 nextAngle;
    f32 curAngle1;
    f32 curAngle2;

    f32 alphaCoord;
    f32 alphaFrac;
    s32 nearest;

    s32 numPoints;
    s32 i, j;

    f32 deltaX, deltaY;
    f32 posX, posY, posZ;

    if (N(VineRenderState) == -1) {
        return;
    }

    if (N(VineRenderState) == 0) {
        for (i = 0; i < NUM_VINES; i++) {
            LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
            LavaPiranhaVine* vine = &vines[i];

            switch (i) {
                default:
                    return;
                case 0:
                    boneCount = 9;
                    boneLength = 10.0f;
                    break;
                case 1:
                    boneCount = 7;
                    boneLength = 8.0f;
                    break;
                case 2:
                    boneCount = 7;
                    boneLength = 8.0f;
                    break;
                case 3:
                    boneCount = 5;
                    boneLength = 8.0f;
                    break;
            }

            vine->boneCount = boneCount;
            vine->boneLength = boneLength;

            for (j = 0; j < boneCount; j++) {
                if (j == (boneCount - 1)) {
                    vine->boneRot[j] += 90.0f;
                } else {
                    curAngle1 = vine->boneRot[j];
                    nextAngle = vine->boneRot[j + 1];
                    if (nextAngle - curAngle1 > 180.0f) {
                        curAngle1 += 360.0f;
                    } else if (nextAngle - curAngle1 < -180.0f) {
                        nextAngle += 360.0f;
                    }
                    // average cur and next angles
                    vine->boneRot[j] = ((curAngle1 + nextAngle) / 2.0) + 90.0;
                }
            }

            N(make_vine_interpolation)(vine);
        }

        N(VineRenderState) = 1;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPDisplayList(gMainGfxPos++, N(lava_piranha_vine_gfx));

    for (i = 0; i < NUM_VINES; i++) {
        LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
        LavaPiranhaVine* vine = &vines[i];

        boneLength = vine->boneLength;
        boneCount = vine->boneCount;
        numPoints = vine->numPoints;

        // we'll build the vertex data and place it in the display list, so jump forward
        // here and leave space behind for the gSPBranchList command followed by two vertices
        // for each point in numPoints

        vtxBuffer = (Vtx_t*)(gMainGfxPos + 1);
        gSPBranchList(gMainGfxPos, &gMainGfxPos[1 + 2 * (2 * numPoints)]);
        vtx = (Vtx_t*) (++gMainGfxPos);
        gMainGfxPos = &gMainGfxPos[2 * (2 * numPoints)];

        for (j = 0; j < numPoints; j++) {
            posX = vine->points[j].x;
            posY = vine->points[j].y;
            posZ = vine->points[j].z;

            alphaCoord = ((f32) j * boneCount) / numPoints;
            nearest = (s32) alphaCoord;
            alphaFrac = alphaCoord - (f32)nearest;

            if (nearest + 1 >= boneCount) {
                angle = vine->boneRot[boneCount - 1];
            } else {
                curAngle2 = vine->boneRot[nearest];
                nextAngle = vine->boneRot[nearest + 1];
                if (nextAngle - curAngle2 > 180.0f) {
                    nextAngle -= 360.0f;
                }
                if (nextAngle - curAngle2 < -180.0f) {
                    nextAngle += 360.0f;
                }
                angle = ((nextAngle - curAngle2) * alphaFrac) + curAngle2;
            }

            deltaX =  sin_deg(angle) * boneLength;
            deltaY = -cos_deg(angle) * boneLength;

            vtx->ob[0] = posX + deltaX;
            vtx->ob[1] = posY + deltaY;
            vtx->ob[2] = posZ;
            vtx->tc[0] = j * 0x140;
            vtx->tc[1] = 0;
            vtx->cn[0] = j * 50;
            vtx->cn[1] = j * 120;
            vtx->cn[2] = j * 30;
            vtx++;

            vtx->ob[0] = posX - deltaX;
            vtx->ob[1] = posY - deltaY;
            vtx->ob[2] = posZ;
            vtx->tc[0] = j * 0x140;
            vtx->tc[1] = 0x400;
            vtx->cn[0] = j * 50;
            vtx->cn[1] = j * 120;
            vtx->cn[2] = j * 30;
            vtx++;
        }

        for (j = 0; j < numPoints - 1; j++) {
            gSPVertex(gMainGfxPos++, &vtxBuffer[2*j], 4, 0);
            gSP2Triangles(gMainGfxPos++, 1, 0, 2, 0, 1, 2, 3, 0);
        }
    }

    gDPPipeSync(gMainGfxPos++);
}

void N(worker_render_piranha_vines)(void) {
    RenderTask renderTask;

    renderTask.appendGfx = &N(appendGfx_piranha_vines);
    renderTask.appendGfxArg = 0;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    queue_render_task(&renderTask);
}

API_CALLABLE(N(MarkVineInterpolationDirty)) {
    N(VineRenderState) = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CreateVineRenderer)) {
    LavaPiranhaVine* data = heap_malloc(NUM_VINES * sizeof(*data));
    evt_set_variable(script, MV_VinesData, (s32) data);
    N(VineRenderState) = -1;
    create_worker_world(NULL, &N(worker_render_piranha_vines));
    return ApiStatus_DONE2;
}
