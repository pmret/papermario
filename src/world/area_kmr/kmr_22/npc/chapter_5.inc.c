EvtScript N(EVS_NpcInit_Misstar) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_Still)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    Return
    End
};
