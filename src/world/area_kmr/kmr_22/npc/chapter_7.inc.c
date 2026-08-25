EvtScript N(EVS_NpcInit_Kalmar) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKalmar_Still)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    Return
    End
};

EvtScript N(EVS_NpcInit_CrystalKing) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_Idle)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_IceCube) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_CubeIdle)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_IceSphere) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_SphereIdle)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_IceSpike) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_PrismIdle)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};
