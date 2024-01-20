EvtScript N(EVS_NpcInit_Mamar) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMamar_Still)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    Return
    End
};

EvtScript N(EVS_NpcInit_Tutankoopa) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Tutankoopa_Levitate)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_ChainChomp) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_ChainChomp_QuickBite)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Call(SetNpcPos, NPC_SELF, 5, -25, -180)
    Call(SetNpcAnimation, NPC_ChainChomp_02, ANIM_ChainChomp_Chain)
    Call(SetNpcImgFXParams, NPC_ChainChomp_02, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Call(SetNpcPos, NPC_ChainChomp_02, 35, -14, -180)
    Call(SetNpcAnimation, NPC_ChainChomp_03, ANIM_ChainChomp_Chain)
    Call(SetNpcImgFXParams, NPC_ChainChomp_03, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Call(SetNpcPos, NPC_ChainChomp_03, 52, -18, -180)
    Call(SetNpcAnimation, NPC_ChainChomp_04, ANIM_ChainChomp_Chain)
    Call(SetNpcImgFXParams, NPC_ChainChomp_04, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Call(SetNpcPos, NPC_ChainChomp_04, 69, -19, -180)
    Call(SetNpcAnimation, NPC_ChainChomp_05, ANIM_ChainChomp_Chain)
    Call(SetNpcImgFXParams, NPC_ChainChomp_05, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Call(SetNpcPos, NPC_ChainChomp_05, 86, -19, -180)
    Return
    End
};
