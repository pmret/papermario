#include "world/common/todo/GetFloorCollider.inc.c"

API_CALLABLE(N(IsPartnerBow)) {
    if (gPartnerStatus.actingPartner == PARTNER_BOW) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ShyGuy_PlayFootstepSounds) = {
    Loop(0)
        Call(PlaySoundAtNpc, LVar0, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        Wait(2)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SuspiciousGuy_OpenDoor) = {
    Call(PlaySoundAtCollider, COLLIDER_deilit_hu, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Set(LVar0, 0)
    Loop(20)
        Add(LVar0, 3)
        Call(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
        Wait(1)
    EndLoop
    Set(LVar0, 90)
    Call(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SuspiciousGuy_CloseDoor) = {
    Set(LVar0, 90)
    Loop(20)
        Add(LVar0, -3)
        Call(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
        Wait(1)
    EndLoop
    Set(LVar0, 0)
    Call(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
    Call(PlaySoundAtCollider, COLLIDER_deilit_hu, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_OpenSecretDoor) = {
    Call(PlaySoundAtCollider, COLLIDER_deilit_hk, SOUND_OMO_SECRET_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Set(LVar0, 0)
    Loop(36)
        Add(LVar0, 10)
        Call(RotateModel, MODEL_hkai1, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_hkai2, LVar0, 0, 1, 0)
        Wait(1)
    EndLoop
    Set(LVar0, 0)
    Call(RotateModel, MODEL_hkai1, LVar0, 0, 1, 0)
    Call(RotateModel, MODEL_hkai2, LVar0, 0, 1, 0)
    Call(PlaySoundAtCollider, COLLIDER_deilit_hk, SOUND_OMO_SECRET_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(PlaySound, SOUND_CHIME_BEGIN_AMBUSH)
    Return
    End
};

EvtScript N(EVS_SuspiciousGuy_RevealSecretRoom) = {
    Wait(20 * DT)
    Call(SetNpcFlagBits, NPC_ShyGuy_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SpeakToPlayer, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim11, ANIM_ShyGuy_Pink_Anim01, 5, MSG_MAC_Housing_00B3)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim02)
    Wait(4 * DT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim03)
    Wait(4 * DT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim04)
    Wait(4 * DT)
    Call(NpcMoveTo, NPC_ShyGuy_01, -440, 3, 50 * DT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim01)
    Wait(8 * DT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim00)
    Call(InterpNpcYaw, NPC_ShyGuy_01, 180, 10 * DT)
    Call(InterpNpcYaw, NPC_ShyGuy_01, 0, 10 * DT)
    Call(InterpNpcYaw, NPC_ShyGuy_01, 180, 10 * DT)
    Call(InterpNpcYaw, NPC_ShyGuy_01, 0, 10 * DT)
    Call(SpeakToPlayer, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim11, ANIM_ShyGuy_Pink_Anim01, 5, MSG_MAC_Housing_00B4)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim08)
    Wait(4 * DT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim09)
    Wait(4 * DT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim0A)
    Exec(N(EVS_OpenSecretDoor))
    Call(SetNpcJumpscale, NPC_ShyGuy_01, Float(0.5))
    Call(NpcJump0, NPC_ShyGuy_01, -440, 20, -75, 20 * DT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim00)
    IfLt(GB_StoryProgress, STORY_CH4_FOUND_HIDDEN_DOOR)
        Set(GB_StoryProgress, STORY_CH4_FOUND_HIDDEN_DOOR)
        ExecWait(N(EVS_MakeHiddenRoom))
    EndIf
    Return
    End
};

EvtScript N(EVS_SuspiciousGuy_RunAway) = {
    Call(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_SHY_GUY_OUCH, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_ShyGuy_01, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim11, ANIM_ShyGuy_Pink_Anim01, 0, MSG_MAC_Housing_00B2)
    Call(InterpNpcYaw, NPC_ShyGuy_01, 180, 10)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim02)
    Wait(4 * DT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim03)
    Wait(4 * DT)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim04)
    Wait(4 * DT)
    ExecWait(N(EVS_SuspiciousGuy_OpenDoor))
    Set(LVar0, NPC_ShyGuy_01)
    ExecGetTID(N(EVS_ShyGuy_PlayFootstepSounds), LVarA)
    Call(NpcMoveTo, NPC_ShyGuy_01, -501, 223, 15 * DT)
    KillThread(LVarA)
    ExecWait(N(EVS_SuspiciousGuy_CloseDoor))
    Return
    End
};

EvtScript N(EVS_HiddenRoom_WaitForOuttaSight) = {
    SetGroup(EVT_GROUP_NOT_BATTLE)
    IfNe(GB_StoryProgress, STORY_CH4_MET_WITH_TWINK)
        Return
    EndIf
    Loop(150 * DT)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGt(LVar2, 200)
            Return
        EndIf
        Wait(1)
    EndLoop
    Set(LVar7, 0)
    // wait for player to use bow within 100 <= z <= 200
    Loop(0)
        Call(N(IsPartnerBow))
        IfTrue(LVar0)
            Set(LVar7, 1)
            BreakLoop
        EndIf
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar2, 100)
            BreakLoop
        EndIf
        IfGt(LVar2, 200)
            // automatically satisfied while exiting the front door
            Return
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    ExecWait(N(EVS_SuspiciousGuy_OpenDoor))
    Call(SetNpcPos, NPC_ShyGuy_01, -501, 20, 223)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim02)
    Call(NpcMoveTo, NPC_ShyGuy_01, -506, 168, 15)
    Call(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim00)
    ExecWait(N(EVS_SuspiciousGuy_CloseDoor))
    IfEq(LVar7, 1)
        ExecWait(N(EVS_SuspiciousGuy_RevealSecretRoom))
    Else
        ExecWait(N(EVS_SuspiciousGuy_RunAway))
        Call(N(GetFloorCollider), LVar0)
        Thread
            Wait(10 * DT)
            Exec(N(EVS_HiddenRoom_WaitForOuttaSight))
        EndThread
    EndIf
    Call(SetNpcPos, NPC_ShyGuy_01, NPC_DISPOSE_LOCATION)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ShyGuy_StealStoreroomKey) = {
    Call(GetNpcPos, NPC_ShyGuy_02, LVar2, LVar3, LVar4)
    Add(LVar3, 20)
    Call(MakeItemEntity, ITEM_VIS_GROUP(ITEM_STOREROOM_KEY, VIS_GROUP_1), LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVar9, LVar0)
    Wait(1)
    Loop(30)
        Call(GetNpcPos, NPC_ShyGuy_02, LVar2, LVar3, LVar4)
        Add(LVar3, 20)
        Call(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        Wait(1)
    EndLoop
    Call(RemoveItemEntity, LVar9)
    Return
    End
};

EvtScript N(EVS_OnEnterShop) = {
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        Return
    EndIf
    IfGt(GB_StoryProgress, STORY_CH4_GOT_STOREROOM_KEY)
        Return
    EndIf
    IfNe(GF_MAC04_StoreroomKeyStolen, FALSE)
        Return
    EndIf
    Call(SetNpcPos, NPC_ShyGuy_02, 250, 20, -402)
    Call(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim04)
    Call(DisablePlayerInput, TRUE)
    Wait(30)
    Call(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0000)
    Call(DisablePlayerInput, FALSE)
    Thread
        Call(DisablePlayerInput, TRUE)
        Wait(20)
        Set(LVar0, 0)
        Loop(36)
            Call(InterpPlayerYaw, LVar0, 0)
            Add(LVar0, 45)
            Wait(1)
        EndLoop
        Call(InterpPlayerYaw, 0, 0)
        Call(DisablePlayerInput, FALSE)
    EndThread
    Thread
        Wait(23)
        Call(PlaySoundAtCollider, COLLIDER_deilit_mu, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 8)
            Call(RotateModel, MODEL_msdoor, LVar0, 0, -1, 0)
            Wait(1)
        EndLoop
        Loop(10)
            Add(LVar0, -8)
            Call(RotateModel, MODEL_msdoor, LVar0, 0, -1, 0)
            Wait(1)
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_deilit_mu, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Exec(N(EVS_ShyGuy_StealStoreroomKey))
    Set(LVar0, NPC_ShyGuy_02)
    ExecGetTID(N(EVS_ShyGuy_PlayFootstepSounds), LVarA)
    Call(NpcMoveTo, NPC_ShyGuy_02, 254, -66, 30)
    KillThread(LVarA)
    Call(SetNpcPos, NPC_ShyGuy_02, NPC_DISPOSE_LOCATION)
    Set(GF_MAC04_StoreroomKeyStolen, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy_02) = {
    Return
    End
};
