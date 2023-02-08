EvtScript N(EVS_NpcInit_Misstar) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_Still)
    EVT_CALL(func_802CFD30, NPC_SELF, FOLD_TYPE_8, 0, 0, 0, 128)
    EVT_RETURN
    EVT_END
};
