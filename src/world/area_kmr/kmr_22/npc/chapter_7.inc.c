EvtScript N(EVS_NpcInit_Kalmar) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKalmar_Still)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    Return
    End
};

EvtScript N(EVS_NpcInit_CrystalKing) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_Anim09)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_IceCube) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_Anim0A)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_IceSphere) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_Anim0B)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_IceSpike) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_Anim0C)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};
