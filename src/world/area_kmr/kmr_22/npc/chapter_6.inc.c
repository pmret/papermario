EvtScript N(EVS_NpcInit_Klevar) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKlevar_Still)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HuffNPuff_Body) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim1A)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, 40, 45, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HuffNPuff_Face) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim1B)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, 40, 45, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HuffNPuff_Arms) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim1C)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, 40, 45, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_RuffPuff_01) = {
    EVT_CALL(SetNpcAnimation, NPC_RuffPuff_01, ANIM_RuffPuff_Idle)
    EVT_CALL(SetNpcImgFXParams, NPC_RuffPuff_01, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_CALL(SetNpcPos, NPC_RuffPuff_01, 120, -1, -51)
    EVT_CALL(SetNpcAnimation, NPC_RuffPuff_02, ANIM_RuffPuff_Idle)
    EVT_CALL(SetNpcImgFXParams, NPC_RuffPuff_02, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_CALL(SetNpcPos, NPC_RuffPuff_02, -40, 59, 1)
    EVT_RETURN
    EVT_END
};
