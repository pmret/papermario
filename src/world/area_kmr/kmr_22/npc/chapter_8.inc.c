EvtScript N(EVS_NpcInit_Bowser) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBowser_Talk)
    EVT_CALL(SetNpcImgfxParams, NPC_SELF, IMGFX_UPD_FILL_COLOR, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};
