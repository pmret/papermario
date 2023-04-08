EvtScript N(EVS_NpcInit_Bowser) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBowser_Talk)
    EVT_CALL(SetNpcFoldParams, NPC_SELF, FOLD_TYPE_E, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};
