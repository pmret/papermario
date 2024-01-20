EvtScript N(D_8024B5AC_82E86C) = {
    Call(GetNpcPos, NPC_ShyGuy, LVar2, LVar3, LVar4)
    Add(LVar3, 20)
    Call(MakeItemEntity, ITEM_FRYING_PAN, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVar9, LVar0)
    Wait(1)
    Loop(70)
        Call(GetNpcPos, NPC_ShyGuy, LVar2, LVar3, LVar4)
        Add(LVar3, 20)
        Call(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        Wait(1)
    EndLoop
    Call(RemoveItemEntity, LVar9)
    Return
    End
};

EvtScript N(D_8024B6A0_82E960) = {
    Loop(0)
        Call(PlaySoundAtNpc, NPC_ShyGuy, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        Wait(2)
    EndLoop
    Return
    End
};

EvtScript N(D_8024B6E8_82E9A8) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 40)
            IfLt(LVar2, 180)
                BreakLoop
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_MAC_Bridge_0016, 160, 40)
    Call(SetCamProperties, CAM_DEFAULT, Float(3.0), -140, 20, -140, 400, 15, -6)
    Call(SetNpcPos, NPC_ShyGuy, -200, 20, -260)
    Call(SetNpcAnimation, NPC_ShyGuy, ANIM_ShyGuy_Red_Anim04)
    Wait(10)
    Exec(N(D_8024B5AC_82E86C))
    Thread
        Call(EnableGroup, MODEL_cook_in, TRUE)
        Call(PlaySoundAtCollider, COLLIDER_deilit1u, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 8)
            Call(RotateModel, MODEL_c_door, LVar0, 0, -1, 0)
            Wait(1)
        EndLoop
        Wait(5)
        Loop(10)
            Add(LVar0, -8)
            Call(RotateModel, MODEL_c_door, LVar0, 0, -1, 0)
            Wait(1)
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_deilit1u, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
        Call(EnableGroup, MODEL_cook_in, FALSE)
    EndThread
    Wait(5)
    Call(PlaySoundAtNpc, NPC_ShyGuy, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    ExecGetTID(N(D_8024B6A0_82E960), LVarA)
    Call(SetNpcSpeed, NPC_ShyGuy, 8)
    Call(NpcMoveTo, NPC_ShyGuy, -140, -240, 0)
    Call(NpcMoveTo, NPC_ShyGuy, -140, -140, 0)
    Call(NpcJump0, NPC_ShyGuy, -140, 0, -100, 0)
    Call(NpcMoveTo, NPC_ShyGuy, -190, -20, 0)
    Call(NpcMoveTo, NPC_ShyGuy, -350, -20, 0)
    KillThread(LVarA)
    Call(SetNpcPos, NPC_ShyGuy, NPC_DISPOSE_LOCATION)
    Set(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
    Wait(10)
    Call(ResetCam, CAM_DEFAULT, Float(3.0))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    IfLt(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        Exec(N(D_8024B6E8_82E9A8))
    EndIf
    Return
    End
};
