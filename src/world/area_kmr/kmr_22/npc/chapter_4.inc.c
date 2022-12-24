EvtScript N(EVS_NpcInit_Muskular) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMuskular_Still)
    EVT_CALL(func_802CFD30, -1, 8, 0, 0, 0, 128)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GeneralGuy) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GeneralGuy_Anim03)
    EVT_CALL(func_802CFD30, -1, 14, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim02)
    EVT_CALL(func_802CFD30, -1, 14, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};
