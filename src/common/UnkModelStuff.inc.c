#include "common.h"

u16 N(UnkModelStuff_array)[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

void N(UnkModelStuff_func1)(s32 arg0) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(arg0, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        Vtx* vtx = &copiedVertices[i];
        s16 temp1 = (sins(N(UnkModelStuff_array)[arg0] * (i % 3 + 1) + i) + 0x8000) / 2;
        s32 temp2 = temp1 * 155;
        vtx->v.cn[2] = temp2 / 0x8000 + 100;
        vtx->v.cn[1] = temp2 / 0x8000 + 50;

        temp3 = sins(N(UnkModelStuff_array)[arg0] / 0x8000 * (((i / 2) % 3 + 1) << 15)  + N(UnkModelStuff_array)[arg0] / 0x4000 * 0x8000 + i) + 0x8000;
        vtx->v.cn[0] = vtx->v.cn[0] * temp3 / 0x10000;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(arg0));
    N(UnkModelStuff_array)[arg0] += 0x253;
}

#include "common/Set80071270_0_16.inc.c"
#include "common/UnkFloatFunc2.inc.c"

EvtScript N(UnkModelStuffScript1) = {
    EVT_CALL(N(Set80071270_0_16))
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(UnkModelStuffScript2) = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_LABEL(0)
    EVT_CALL(RandInt, 30, LocalVar(0))
    EVT_ADD(LocalVar(0), 30)
    EVT_WAIT(LocalVar(0))
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(10)
        EVT_ADD(LocalVar(1), 36)
        EVT_CALL(RotateModel, LocalVar(10), LocalVar(1), 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(UnkModelStuffScript3) = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_SET(LocalVar(11), LocalVar(1))
    EVT_EXEC(N(UnkModelStuffScript2))
    EVT_SET(LocalVar(7), 0)
    EVT_LABEL(0)
    EVT_ADD(LocalVar(7), 4)
    EVT_IF_GT(LocalVar(7), 3599)
        EVT_SUB(LocalVar(7), 3600)
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc2), LocalVar(7), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(TranslateModel, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(UnkModelStuffScript4) = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_SET(LocalVar(7), 0)
    EVT_LABEL(0)
    EVT_ADD(LocalVar(7), 4)
    EVT_IF_GT(LocalVar(7), 3599)
        EVT_SUB(LocalVar(7), 3600)
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc2), LocalVar(7), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(TranslateModel, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
