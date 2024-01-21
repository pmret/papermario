EvtScript N(EVS_NpcInit_Eldstar) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldEldstar_Still)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaBros) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_PointForward)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};
