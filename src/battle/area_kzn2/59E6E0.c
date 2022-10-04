#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_kzn2

s32 bgm_init_music_players(void);

extern Gfx D_8021CF40_5A3620[];
extern s32 D_80222B68_5A9248;
extern s32 D_80222D48_5A9428[];
extern s32 D_80222E20_5A9500[];

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
};

typedef struct LavaPiranhaVine {
    /* 0x000 */ Vec3f bonePos[9];
    /* 0x06C */ f32 boneRot[9];
    /* 0x090 */ s32 boneCount;
    /* 0x094 */ f32 boneLength;
    /* 0x098 */ Vec3f points[27];
    /* 0x1DC */ s32 numPoints;
} LavaPiranhaVine;

#include "common/StartRumbleWithParams.inc.c"

static LavaPiranhaVine N(VineData)[NUM_VINES];
static s32 N(VineRenderState);

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
    LavaPiranhaVine* vine = &N(VineData)[vineIdx];

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
    f32 rz = evt_get_variable(script, *args++);
    LavaPiranhaVine* vine = &N(VineData)[vineIdx];

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
    LavaPiranhaVine* vine = &N(VineData)[vineIdx];

    // do nothing
    return ApiStatus_DONE2;
}

// the f64 90.0 ends up in the wrong place
#ifdef NON_MATCHING
// N(appendGfx_piranha_vines)
void func_8021835C_59EA3C(void* data) {
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
            LavaPiranhaVine* vine = &N(VineData)[i];

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

            b_area_kzn2_make_vine_interpolation(vine);
        }

        N(VineRenderState) = 1;
    }

    gDPPipeSync(gMasterGfxPos++);
    gSPDisplayList(gMasterGfxPos++, D_8021CF40_5A3620);

    for (i = 0; i < NUM_VINES; i++) {
        LavaPiranhaVine* vine = &N(VineData)[i];

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
#else
void func_8021835C_59EA3C(void* data);
INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_8021835C_59EA3C);
#endif

void N(worker_render_piranha_vines)(void) {
    RenderTask renderTask;

    renderTask.appendGfx = &func_8021835C_59EA3C;
    renderTask.appendGfxArg = 0;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    queue_render_task(&renderTask);
}

API_CALLABLE(N(MarkVineInterpolationDirty)) {
    N(VineRenderState) = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CreateVineRenderer)) {
    N(VineRenderState) = -1;
    create_generic_entity_world(NULL, &N(worker_render_piranha_vines));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80218930_59F010)) { 
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FlameFXData* flameData = effect->data.flame;
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    f32 angle = evt_get_variable(script, *args++);
    s32 radius = evt_get_variable(script, *args++);
    s32 offsetY = evt_get_variable(script, *args++);
    s32 unk_10 = evt_get_variable(script, *args++);
    
    flameData->pos.x = posX - cos_deg(angle) * radius;
    flameData->pos.y = (posY + offsetY) - sin_deg(angle) * radius;
    flameData->unk_10 = unk_10 * 0.01f;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80218A98_59F178)) {
    D_80222B68_5A9248++;

    // play 'end battle' song
    if (isInitialCall) {
        sfx_play_sound(SOUND_D4);
        bgm_set_song(0, SONG_BATTLE_END, 0, 500, 8);
        return ApiStatus_BLOCK;
    }

    switch (D_80222B68_5A9248) {
        case 80:
            // after a short time, stop the 'end battle' song
            bgm_init_music_players();
            return ApiStatus_BLOCK;
        case 340:
            // restart the boss theme with the more intense variation
            bgm_set_song(0, SONG_LAVA_PIRANHA_BATTLE, 1, 500, 8);
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80218B38_59F218)) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    evt_set_variable(script, outVar, D_80222D48_5A9428[index]);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80218B90_59F270)) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    evt_set_variable(script, outVar, D_80222E20_5A9500[index]);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80218BE8_59F2C8)) {
    Bytecode* args = script->ptrReadPos;
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    f32 angle = evt_get_variable(script, *args++);
    s32 radius = evt_get_variable(script, *args++);
    s32 deltaY = evt_get_variable(script, *args++);
    
    posX = posX - cos_deg(angle) * radius;
    posY = (posY + deltaY) - sin_deg(angle) * radius;
    evt_set_variable(script, *args++, posX);
    evt_set_variable(script, *args++, posY);
    return ApiStatus_DONE2;
}
