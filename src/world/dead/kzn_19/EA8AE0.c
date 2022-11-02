#include "kzn_19.h"

extern Gfx D_80243AD8_EAC5B8[];
extern s32 D_80243BB8_EAC698[];
extern s32 D_80243DD8_EAC8B8;
extern s32 D_80243DDC_EAC8BC;
extern s32 D_80248380;
extern s32 N(D_80248388)[];

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/todo/StarSpiritEffectFunc.inc.c"

static char* N(exit_str_0) = "kmr_23";
static char* N(exit_str_1) = "kzn_18";
static char* N(exit_str_2) = "kzn_20";

enum {
    VINE_0      = 0,
    VINE_1      = 1,
    VINE_2      = 2,
    VINE_3      = 3,
    NUM_VINES   = 4
};

enum {
    VINE_0_BASE  = 0x80200000,
    VINE_1_BASE  = 0x80204000,
    VINE_2_BASE  = 0x80207000,
    VINE_3_BASE  = 0x8020A000,
}; // TODO shiftability -- hard-coded addresses in gBackgroundImage

// make_vine_interpolation
void func_80240B00_EA95E0(LavaPiranhaVine* vine) {
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

// SetVineBonePos
ApiStatus func_80240BD4_EA96B4(Evt *script, s32 isInitialCall) {
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

// SetVineBoneRot
ApiStatus func_80240CD8_EA97B8(Evt *script, s32 isInitialCall) {
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

// SetVineBoneScale
ApiStatus func_80240DA4_EA9884(Evt* script, s32 isInitialCall) {
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

// appendGfx_piranha_vines
void func_80240E2C_EA990C(void* data) {
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

    if (D_80248380 == -1) {
        return;
    }

    if (D_80248380 == 0) {
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

            func_80240B00_EA95E0(vine);
        }

        D_80248380 = 1;
    }

    gDPPipeSync(gMasterGfxPos++);
    gSPDisplayList(gMasterGfxPos++, D_80243AD8_EAC5B8);

    for (i = 0; i < NUM_VINES; i++) {
        LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
        LavaPiranhaVine* vine = &vines[i];

        boneLength = vine->boneLength;
        boneCount = vine->boneCount;
        numPoints = vine->numPoints;

        // we'll build the vertex data and place it in the display list, so jump forward
        // here and leave space behind for the gSPBranchList command followed by two vertices
        // for each point in numPoints

        vtxBuffer = (Vtx_t*)(gMasterGfxPos + 1);
        gSPBranchList(gMasterGfxPos, &gMasterGfxPos[1 + 2 * (2 * numPoints)]);
        vtx = (Vtx_t*) (++gMasterGfxPos);
        gMasterGfxPos = &gMasterGfxPos[2 * (2 * numPoints)];

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
            vtx->cn[1] = j * 120;;
            vtx->cn[2] = j * 30;
            vtx++;

            vtx->ob[0] = posX - deltaX;
            vtx->ob[1] = posY - deltaY;
            vtx->ob[2] = posZ;
            vtx->tc[0] = j * 0x140;
            vtx->tc[1] = 0x400;
            vtx->cn[0] = j * 50;
            vtx->cn[1] = j * 120;;
            vtx->cn[2] = j * 30;
            vtx++;
        }

        for (j = 0; j < numPoints - 1; j++) {
            gSPVertex(gMasterGfxPos++, &vtxBuffer[2*j], 4, 0);
            gSP2Triangles(gMasterGfxPos++, 1, 0, 2, 0, 1, 2, 3, 0);
        }
    }

    gDPPipeSync(gMasterGfxPos++);
}

// worker_render_piranha_vines
void func_802413C0_EA9EA0(void) {
    RenderTask renderTask;

    renderTask.appendGfx = &func_80240E2C_EA990C;
    renderTask.appendGfxArg = 0;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    queue_render_task(&renderTask);
}

// MarkVineInterpolationDirty
ApiStatus func_802413FC_EA9EDC(Evt* script, s32 isInitialCall) {
    D_80248380 = 0;
    return ApiStatus_DONE2;
}

// CreateVineRenderer
ApiStatus func_8024140C_EA9EEC(Evt* script, s32 isInitialCall) {
    LavaPiranhaVine* data = heap_malloc(NUM_VINES * sizeof(*data));
    evt_set_variable(script, MV_VinesData, (s32) data);
    D_80248380 = -1;
    create_generic_entity_world(0, &func_802413C0_EA9EA0);
    return ApiStatus_DONE2;
}

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

#ifdef NON_MATCHING
ApiStatus func_802417AC_EAA28C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        D_80243DD8_EAC8B8 = FALSE;
    }
    if (D_80243DD8_EAC8B8) {
        D_80243DD8_EAC8B8 = FALSE;

        evt_set_variable(script, *args++, D_80243DDC_EAC8BC);

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "EA8AE0", func_802417AC_EAA28C);
#endif

INCLUDE_ASM(s32, "EA8AE0", func_80241800_EAA2E0);

ApiStatus func_80241838_EAA318(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80248388)[i] = ptr[i];
        }
        N(D_80248388)[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            N(D_80248388)[i] = i + 16;
            N(D_80248388)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

// LoadAnimationFromTable
API_CALLABLE(func_80241BC0_EAA6A0) {
    Bytecode* args = script->ptrReadPos;
    s32 type = evt_get_variable(script, *args++);
    s32 index = evt_get_variable(script, *args++);

    switch (type) {
        case VINE_0:
            dma_copy(
                (u8*) D_80243BB8_EAC698[3 * index + 0],
                (u8*) D_80243BB8_EAC698[3 * index + 1],
                (void*) VINE_0_BASE);
            break;
        case VINE_1:
            dma_copy(
                (u8*) D_80243BB8_EAC698[3 * index + 0],
                (u8*) D_80243BB8_EAC698[3 * index + 1],
                (void*) VINE_1_BASE);
            break;
        case VINE_2:
            dma_copy(
                (u8*) D_80243BB8_EAC698[3 * index + 0],
                (u8*) D_80243BB8_EAC698[3 * index + 1],
                (void*) VINE_2_BASE);
            break;
        case VINE_3:
            dma_copy(
                (u8*) D_80243BB8_EAC698[3 * index + 0],
                (u8*) D_80243BB8_EAC698[3 * index + 1],
                (void*) VINE_3_BASE);
            break;
    }
    return ApiStatus_DONE2;
}
