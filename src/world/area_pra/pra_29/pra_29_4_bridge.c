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
    EVT_WAIT(40)
    EVT_THREAD
        EVT_LOOP(5)
            EVT_CALL(N(PlayRisingBubble), 260, 0, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_PRA_EXTEND_HIDDEN_BRIDGE, SOUND_SPACE_DEFAULT, 250, 0, 0)
    EVT_CALL(MakeLerp, 0, 511, 80, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(MV_BridgeExtendAmt, LVar0)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1041, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_StoryProgress, STORY_CH7_EXTENDED_PALACE_BRIDGE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBridge) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_EXTENDED_PALACE_BRIDGE)
        EVT_CALL(EnableModel, MODEL_u00, FALSE)
        EVT_CALL(EnableModel, MODEL_s00, FALSE)
        EVT_SET(MV_BridgeExtendAmt, 0)
        EVT_SET(MV_UnusedBridgeAlpha, 255)
        EVT_CALL(SetModelCustomGfx, MODEL_u02, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
        EVT_CALL(SetModelCustomGfx, MODEL_s02, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
        EVT_CALL(SetModelFlags, MODEL_u02, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
        EVT_CALL(SetModelFlags, MODEL_s02, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
        EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_bridge)), NULL)
        EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(setup_gfx_bridge)), NULL)
        EVT_CALL(MakeLocalVertexCopy, VTX_COPY_0, MODEL_u02, TRUE)
        EVT_CALL(MakeLocalVertexCopy, VTX_COPY_1, MODEL_u01, FALSE)
        EVT_CALL(MakeLocalVertexCopy, VTX_COPY_2, MODEL_u03, FALSE)
        EVT_CALL(SetModelFlags, MODEL_u02, MODEL_FLAG_USES_CUSTOM_GFX | MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
        EVT_CALL(MakeLocalVertexCopy, VTX_COPY_3, MODEL_s02, TRUE)
        EVT_CALL(MakeLocalVertexCopy, VTX_COPY_4, MODEL_s01, FALSE)
        EVT_CALL(MakeLocalVertexCopy, VTX_COPY_5, MODEL_s03, FALSE)
        EVT_CALL(SetModelFlags, MODEL_s02, MODEL_FLAG_USES_CUSTOM_GFX | MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExtendBridgeFromMirror)), TRIGGER_AREA_FLAG_SET, AF_PRA09_HitSwitch, 1, 0)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1041, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_u00, FALSE)
        EVT_CALL(EnableModel, MODEL_u01, FALSE)
        EVT_CALL(EnableModel, MODEL_u02, FALSE)
        EVT_CALL(EnableModel, MODEL_s00, FALSE)
        EVT_CALL(EnableModel, MODEL_s01, FALSE)
        EVT_CALL(EnableModel, MODEL_s02, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
