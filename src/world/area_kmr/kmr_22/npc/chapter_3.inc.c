EvtScript N(EVS_NpcInit_Skolar) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldSkolar_Still)
    EVT_CALL(func_802CFD30, -1, 8, 0, 0, 0, 128)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tubba) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim10)
    EVT_CALL(func_802CFD30, -1, 14, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};
