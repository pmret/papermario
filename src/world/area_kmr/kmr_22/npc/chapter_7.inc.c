EvtScript N(EVS_NpcInit_Kalmar) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKalmar_Still)
    EVT_CALL(SetNpcFoldParams, NPC_SELF, FOLD_UPD_SET_TINT, 0, 0, 0, 128)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_CrystalKing) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_Anim09)
    EVT_CALL(SetNpcFoldParams, NPC_SELF, FOLD_TYPE_E, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_IceCube) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_Anim0A)
    EVT_CALL(SetNpcFoldParams, NPC_SELF, FOLD_TYPE_E, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_IceSphere) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_Anim0B)
    EVT_CALL(SetNpcFoldParams, NPC_SELF, FOLD_TYPE_E, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_IceSpike) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_CrystalKing_Anim0C)
    EVT_CALL(SetNpcFoldParams, NPC_SELF, FOLD_TYPE_E, 80, 80, 80, 0)
    EVT_RETURN
    EVT_END
};
