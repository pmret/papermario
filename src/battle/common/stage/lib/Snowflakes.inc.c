#include "common.h"
#include "effects.h"

u16 N(StarAnimPhases)[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

// unused
void N(build_gfx_star)(s32 index) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(index, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        Vtx* vtx = &copiedVertices[i];
        s16 temp1 = (sins(N(StarAnimPhases)[index] * (i % 3 + 1) + i) + 0x8000) / 2;
        s32 temp2 = temp1 * 155;
        vtx->v.cn[2] = temp2 / 0x8000 + 100;
        vtx->v.cn[1] = temp2 / 0x8000 + 50;

        temp3 = sins(N(StarAnimPhases)[index] / 0x8000 * (((i / 2) % 3 + 1) << 15)  + N(StarAnimPhases)[index] / 0x4000 * 0x8000 + i) + 0x8000;
        vtx->v.cn[0] = vtx->v.cn[0] * temp3 / 0x10000;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(index));
    N(StarAnimPhases)[index] += 0x253;
}

API_CALLABLE(N(SpawnSnowfall)) {
    fx_snowfall(0, 16);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetSnowflakePosition)) {
    Bytecode* args = script->ptrReadPos;
    s32 phase = evt_get_variable(script, *args++);
    s32 posXInOut = *args++;
    s32 posYInOut = *args++;
    s32 posZInOut = *args++;
    f32 posY = sin_rad(DEG_TO_RAD(phase / 10) * 8.0f) * 10.0f;

    evt_set_variable(script, posXInOut, 0);
    evt_set_variable(script, posYInOut, posY);
    evt_set_variable(script, posZInOut, 0);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_SpawnSnowfall) = {
    Call(N(SpawnSnowfall))
    Loop(0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_RandomlySpinSnowflake) = {
    Set(LVarA, LVar0)
    Label(0)
        Call(RandInt, 30, LVar0)
        Add(LVar0, 30)
        Wait(LVar0)
        Set(LVar1, 0)
        Loop(10)
            Add(LVar1, 36)
            Call(RotateModel, LVarA, LVar1, 0, 1, 0)
            Wait(1)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_AnimateHangingSnowflake_RandomSpin) = {
    Set(LVarA, LVar0) // modelID
    Set(LVarB, LVar1)
    Exec(N(EVS_RandomlySpinSnowflake))
    Set(LVar7, 0)
    Label(0)
        Add(LVar7, 4)
        IfGt(LVar7, 3599)
            Sub(LVar7, 3600)
        EndIf
        Call(N(GetSnowflakePosition), LVar7, LVar0, LVar1, LVar2)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_AnimateHangingSnowflake_NoSpin) = {
    Set(LVarA, LVar0)
    Set(LVar7, 0)
    Label(0)
        Add(LVar7, 4)
        IfGt(LVar7, 3599)
            Sub(LVar7, 3600)
        EndIf
        Call(N(GetSnowflakePosition), LVar7, LVar0, LVar1, LVar2)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};
