EvtScript N(EVS_NpcInit_Mamar) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMamar_Still)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tutankoopa) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Tutankoopa_Levitate)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ChainChomp) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ChainChomp_QuickBite)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, 5, -25, -180)
    EVT_CALL(SetNpcAnimation, NPC_ChainChomp_02, ANIM_ChainChomp_Chain)
    EVT_CALL(SetNpcImgFXParams, NPC_ChainChomp_02, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_CALL(SetNpcPos, NPC_ChainChomp_02, 35, -14, -180)
    EVT_CALL(SetNpcAnimation, NPC_ChainChomp_03, ANIM_ChainChomp_Chain)
    EVT_CALL(SetNpcImgFXParams, NPC_ChainChomp_03, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_CALL(SetNpcPos, NPC_ChainChomp_03, 52, -18, -180)
    EVT_CALL(SetNpcAnimation, NPC_ChainChomp_04, ANIM_ChainChomp_Chain)
    EVT_CALL(SetNpcImgFXParams, NPC_ChainChomp_04, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_CALL(SetNpcPos, NPC_ChainChomp_04, 69, -19, -180)
    EVT_CALL(SetNpcAnimation, NPC_ChainChomp_05, ANIM_ChainChomp_Chain)
    EVT_CALL(SetNpcImgFXParams, NPC_ChainChomp_05, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_CALL(SetNpcPos, NPC_ChainChomp_05, 86, -19, -180)
    EVT_RETURN
    EVT_END
};
