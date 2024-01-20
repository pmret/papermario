EvtScript N(EVS_NpcInit_Klevar) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKlevar_Still)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    Return
    End
};

EvtScript N(EVS_NpcInit_HuffNPuff_Body) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim1A)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Call(SetNpcPos, NPC_SELF, 40, 45, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_HuffNPuff_Face) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim1B)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Call(SetNpcPos, NPC_SELF, 40, 45, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_HuffNPuff_Arms) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim1C)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Call(SetNpcPos, NPC_SELF, 40, 45, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_RuffPuff_01) = {
    Call(SetNpcAnimation, NPC_RuffPuff_01, ANIM_RuffPuff_Idle)
    Call(SetNpcImgFXParams, NPC_RuffPuff_01, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Call(SetNpcPos, NPC_RuffPuff_01, 120, -1, -51)
    Call(SetNpcAnimation, NPC_RuffPuff_02, ANIM_RuffPuff_Idle)
    Call(SetNpcImgFXParams, NPC_RuffPuff_02, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Call(SetNpcPos, NPC_RuffPuff_02, -40, 59, 1)
    Return
    End
};
