EvtScript N(EVS_NpcInit_Bowser) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBowser_Talk)
    EVT_CALL(func_802CFD30, NPC_SELF, 14, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};
