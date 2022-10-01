#include "pra_29.h"

#include "world/common/atomic/Reflection.inc.c"

void func_80240F20_D7DA70(Vtx* arg0, Vtx* arg1, Vtx* arg2, s32 arg3, s32 arg4);
INCLUDE_ASM(s32, "world/area_pra/pra_29/D7CB70", func_80240F20_D7DA70);

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

INCLUDE_ASM(s32, "world/area_pra/pra_29/D7CB70", func_802411D4_D7DD24);
