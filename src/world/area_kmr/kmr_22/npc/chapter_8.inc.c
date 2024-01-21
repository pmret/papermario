EvtScript N(EVS_NpcInit_Bowser) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBowser_Talk)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    Return
    End
};
