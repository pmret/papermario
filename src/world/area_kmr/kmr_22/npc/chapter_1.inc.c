EvtScript N(EVS_NpcInit_Eldstar) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldEldstar_Still)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_TINT, 0, 0, 0, 128)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaBros) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_PointForward)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_FILL_COLOR, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};
