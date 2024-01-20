#include "pra_29.h"

void N(set_bride_vertex_positions)(Vtx* arg0, Vtx* arg1, Vtx* dest, s32 numVerticies, s32 extendAmt) {
    s32 temp_t3;
    s32 var_t2;
    s32 temp_t5;
    s32 i;

    temp_t3 = 255 - extendAmt;
    var_t2 = extendAmt;
    if (var_t2 > 255) {
        var_t2 = 255;
    }
    temp_t5 = 255 - var_t2;

    for (i = 0; i < numVerticies; i++) {
        dest[i].v.ob[0] = ((arg0[i].v.ob[0] * temp_t3) + (arg1[i].v.ob[0] * extendAmt)) / 255;
        dest[i].v.ob[1] = ((arg0[i].v.ob[1] * temp_t3) + (arg1[i].v.ob[1] * extendAmt)) / 255;
        dest[i].v.ob[2] = ((arg0[i].v.ob[2] * temp_t3) + (arg1[i].v.ob[2] * extendAmt)) / 255;
        dest[i].v.tc[0] = ((arg0[i].v.tc[0] * temp_t5) + (arg1[i].v.tc[0] * var_t2)) / 255;
        dest[i].v.tc[1] = ((arg0[i].v.tc[1] * temp_t5) + (arg1[i].v.tc[1] * var_t2)) / 255;
    }
}

void N(setup_gfx_bridge)(s32 index) {
    Vtx* srcVtx1;
    Vtx* srcVtx2;
    Vtx* dest1;
    Vtx* dest2;
    s32 numVertices;
    s32 extendAmt = evt_get_variable(NULL, MV_BridgeExtendAmt);
    if (extendAmt <= 255) {
        mdl_get_copied_vertices(index * 3 + 0, &srcVtx1, &dest1, &numVertices);
        mdl_get_copied_vertices(index * 3 + 1, &srcVtx2, &dest2, &numVertices);
        N(set_bride_vertex_positions)(srcVtx2, srcVtx1, dest1, numVertices, extendAmt);
        if (extendAmt == 0) {
            return;
        }
        gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(index * 3));
    } else {
        mdl_get_copied_vertices(index * 3 + 0, &srcVtx1, &dest1, &numVertices);
        mdl_get_copied_vertices(index * 3 + 2, &srcVtx2, &dest2, &numVertices);
        N(set_bride_vertex_positions)(srcVtx1, srcVtx2, dest1, numVertices, extendAmt - 256);
        gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(index * 3));
    }

}

#include "world/common/todo/PlayRisingBubble.inc.c"

EvtScript N(EVS_ExtendBridgeFromMirror) = {
    Wait(40)
    Thread
        Loop(5)
            Call(N(PlayRisingBubble), 260, 0, 0)
            Wait(10)
        EndLoop
    EndThread
    Call(PlaySoundAt, SOUND_PRA_EXTEND_HIDDEN_BRIDGE, SOUND_SPACE_DEFAULT, 250, 0, 0)
    Call(MakeLerp, 0, 511, 80, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Set(MV_BridgeExtendAmt, LVar0)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1041, COLLIDER_FLAGS_UPPER_MASK)
    Set(GB_StoryProgress, STORY_CH7_EXTENDED_PALACE_BRIDGE)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupBridge) = {
    IfLt(GB_StoryProgress, STORY_CH7_EXTENDED_PALACE_BRIDGE)
        Call(EnableModel, MODEL_u00, FALSE)
        Call(EnableModel, MODEL_s00, FALSE)
        Set(MV_BridgeExtendAmt, 0)
        Set(MV_UnusedBridgeAlpha, 255)
        Call(SetModelCustomGfx, MODEL_u02, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
        Call(SetModelCustomGfx, MODEL_s02, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
        Call(SetModelFlags, MODEL_u02, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
        Call(SetModelFlags, MODEL_s02, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
        Call(SetCustomGfxBuilders, CUSTOM_GFX_0, Ref(N(setup_gfx_bridge)), NULL)
        Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(setup_gfx_bridge)), NULL)
        Call(MakeLocalVertexCopy, VTX_COPY_0, MODEL_u02, TRUE)
        Call(MakeLocalVertexCopy, VTX_COPY_1, MODEL_u01, FALSE)
        Call(MakeLocalVertexCopy, VTX_COPY_2, MODEL_u03, FALSE)
        Call(SetModelFlags, MODEL_u02, MODEL_FLAG_USES_CUSTOM_GFX | MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
        Call(MakeLocalVertexCopy, VTX_COPY_3, MODEL_s02, TRUE)
        Call(MakeLocalVertexCopy, VTX_COPY_4, MODEL_s01, FALSE)
        Call(MakeLocalVertexCopy, VTX_COPY_5, MODEL_s03, FALSE)
        Call(SetModelFlags, MODEL_s02, MODEL_FLAG_USES_CUSTOM_GFX | MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
        BindTrigger(Ref(N(EVS_ExtendBridgeFromMirror)), TRIGGER_AREA_FLAG_SET, AF_PRA09_HitSwitch, 1, 0)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1041, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_u00, FALSE)
        Call(EnableModel, MODEL_u01, FALSE)
        Call(EnableModel, MODEL_u02, FALSE)
        Call(EnableModel, MODEL_s00, FALSE)
        Call(EnableModel, MODEL_s01, FALSE)
        Call(EnableModel, MODEL_s02, FALSE)
    EndIf
    Return
    End
};
