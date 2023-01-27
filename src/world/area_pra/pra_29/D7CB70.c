#include "pra_29.h"

#include "../common/Reflection.inc.c"

void func_80240F20_D7DA70(Vtx* arg0, Vtx* arg1, Vtx* arg2, s32 numVerticies, s32 arg4) {
    s32 temp_t3;
    s32 var_t2;
    s32 temp_t5;
    s32 i;

    temp_t3 = 255 - arg4;
    var_t2 = arg4;
    if (var_t2 > 255) {
        var_t2 = 255;
    }
    temp_t5 = 255 - var_t2;

    for (i = 0; i < numVerticies; i++) {
        arg2[i].v.ob[0] = ((arg0[i].v.ob[0] * temp_t3) + (arg1[i].v.ob[0] * arg4)) / 255;
        arg2[i].v.ob[1] = ((arg0[i].v.ob[1] * temp_t3) + (arg1[i].v.ob[1] * arg4)) / 255;
        arg2[i].v.ob[2] = ((arg0[i].v.ob[2] * temp_t3) + (arg1[i].v.ob[2] * arg4)) / 255;
        arg2[i].v.tc[0] = ((arg0[i].v.tc[0] * temp_t5) + (arg1[i].v.tc[0] * var_t2)) / 255;
        arg2[i].v.tc[1] = ((arg0[i].v.tc[1] * temp_t5) + (arg1[i].v.tc[1] * var_t2)) / 255;
    }
}

void func_802410B0_D7DC00(s32 index) {
    Vtx* first1;
    Vtx* copied1;
    s32 numVertices;
    Vtx* first2;
    Vtx* copied2;
    s32 v0 = evt_get_variable(NULL, MapVar(0));
    if (v0 < 256) {
        mdl_get_copied_vertices(index * 3, &first1, &copied1, &numVertices);
        mdl_get_copied_vertices(index * 3 + 1, &first2, &copied2, &numVertices);
        func_80240F20_D7DA70(first2, first1, copied1, numVertices, v0);
        if (v0 == 0) {
            return;
        }
        gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(index * 3));
    } else {
        mdl_get_copied_vertices(index * 3, &first1, &copied1, &numVertices);
        mdl_get_copied_vertices(index * 3 + 2, &first2, &copied2, &numVertices);
        func_80240F20_D7DA70(first1, first2, copied1, numVertices, v0 - 256);
        gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(index * 3));
    }

}

#include "world/common/todo/PlayRisingBubble.inc.c"
