#include "common.h"
#include "npc.h"

void N(unkAngleFunc002)(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;

    mdl_get_copied_vertices(1, &firstVertex, &copiedVertices, &numVertices);
    N(unkVtxFunc001)(firstVertex, copiedVertices, numVertices, &N(unkAngle2));

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(1));
    if (N(unkAngle2) >= 0) {
        N(unkAngle2) += 4;
    }
    if (N(unkAngle2) >= 360) {
        N(unkAngle2) = -1;
    }
}

void N(unkAngleFunc003)(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;

    mdl_get_copied_vertices(2, &firstVertex, &copiedVertices, &numVertices);
    N(unkVtxFunc001)(firstVertex, copiedVertices, numVertices, &N(unkAngle3));

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(2));
    if (N(unkAngle3) >= 0) {
        N(unkAngle3) += 4;
    }
    if (N(unkAngle3) >= 360) {
        N(unkAngle3) = -1;
    }
}
