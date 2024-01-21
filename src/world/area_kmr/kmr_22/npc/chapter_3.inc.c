EvtScript N(EVS_NpcInit_Skolar) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldSkolar_Still)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    Return
    End
};

EvtScript N(EVS_NpcInit_Tubba) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim10)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};
