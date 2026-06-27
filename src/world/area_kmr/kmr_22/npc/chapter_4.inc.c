EvtScript N(EVS_NpcInit_Muskular) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMuskular_Still)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    Return
    End
};

EvtScript N(EVS_NpcInit_GeneralGuy) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_GeneralGuy_Point)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Walk)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};
