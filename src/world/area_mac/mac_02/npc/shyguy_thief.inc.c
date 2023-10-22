EvtScript N(D_8024B5AC_82E86C) = {
    EVT_CALL(GetNpcPos, NPC_ShyGuy, LVar2, LVar3, LVar4)
    EVT_ADD(LVar3, 20)
    EVT_CALL(MakeItemEntity, ITEM_FRYING_PAN, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(1)
    EVT_LOOP(70)
        EVT_CALL(GetNpcPos, NPC_ShyGuy, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 20)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B6A0_82E960) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B6E8_82E9A8) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 40)
            EVT_IF_LT(LVar2, 180)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Bridge_0016, 160, 40)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(3.0), -140, 20, -140, 400, 15, -6)
    EVT_CALL(SetNpcPos, NPC_ShyGuy, -200, 20, -260)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy, ANIM_ShyGuy_Red_Anim04)
    EVT_WAIT(10)
    EVT_EXEC(N(D_8024B5AC_82E86C))
    EVT_THREAD
        EVT_CALL(EnableGroup, MODEL_cook_in, TRUE)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit1u, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 8)
            EVT_CALL(RotateModel, MODEL_c_door, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(5)
        EVT_LOOP(10)
            EVT_ADD(LVar0, -8)
            EVT_CALL(RotateModel, MODEL_c_door, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit1u, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
        EVT_CALL(EnableGroup, MODEL_cook_in, FALSE)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    EVT_EXEC_GET_TID(N(D_8024B6A0_82E960), LVarA)
    EVT_CALL(SetNpcSpeed, NPC_ShyGuy, 8)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy, -140, -240, 0)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy, -140, -140, 0)
    EVT_CALL(NpcJump0, NPC_ShyGuy, -140, 0, -100, 0)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy, -190, -20, 0)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy, -350, -20, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_ShyGuy, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
    EVT_WAIT(10)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        EVT_EXEC(N(D_8024B6E8_82E9A8))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
