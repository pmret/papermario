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
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SuspiciousGuy_OpenDoor) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_hu, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar0, 0)
    EVT_LOOP(20)
        EVT_ADD(LVar0, 3)
        EVT_CALL(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar0, 90)
    EVT_CALL(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SuspiciousGuy_CloseDoor) = {
    EVT_SET(LVar0, 90)
    EVT_LOOP(20)
        EVT_ADD(LVar0, -3)
        EVT_CALL(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar0, 0)
    EVT_CALL(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_hu, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenSecretDoor) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_hk, SOUND_OMO_SECRET_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar0, 0)
    EVT_LOOP(36)
        EVT_ADD(LVar0, 10)
        EVT_CALL(RotateModel, MODEL_hkai1, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_hkai2, LVar0, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar0, 0)
    EVT_CALL(RotateModel, MODEL_hkai1, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_hkai2, LVar0, 0, 1, 0)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_hk, SOUND_OMO_SECRET_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySound, SOUND_CHIME_BEGIN_AMBUSH)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SuspiciousGuy_RevealSecretRoom) = {
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim11, ANIM_ShyGuy_Pink_Anim01, 5, MSG_MAC_Housing_00B3)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim02)
    EVT_WAIT(4 * DT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim03)
    EVT_WAIT(4 * DT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim04)
    EVT_WAIT(4 * DT)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -440, 3, 50 * DT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim01)
    EVT_WAIT(8 * DT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim00)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 180, 10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 0, 10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 180, 10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 0, 10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim11, ANIM_ShyGuy_Pink_Anim01, 5, MSG_MAC_Housing_00B4)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim08)
    EVT_WAIT(4 * DT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim09)
    EVT_WAIT(4 * DT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim0A)
    EVT_EXEC(N(EVS_OpenSecretDoor))
    EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_01, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_ShyGuy_01, -440, 20, -75, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim00)
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_FOUND_HIDDEN_DOOR)
        EVT_SET(GB_StoryProgress, STORY_CH4_FOUND_HIDDEN_DOOR)
        EVT_EXEC_WAIT(N(EVS_MakeHiddenRoom))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SuspiciousGuy_RunAway) = {
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_SHY_GUY_OUCH, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_ShyGuy_01, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim11, ANIM_ShyGuy_Pink_Anim01, 0, MSG_MAC_Housing_00B2)
    EVT_CALL(InterpNpcYaw, NPC_ShyGuy_01, 180, 10)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim02)
    EVT_WAIT(4 * DT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim03)
    EVT_WAIT(4 * DT)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim04)
    EVT_WAIT(4 * DT)
    EVT_EXEC_WAIT(N(EVS_SuspiciousGuy_OpenDoor))
    EVT_SET(LVar0, NPC_ShyGuy_01)
    EVT_EXEC_GET_TID(N(EVS_ShyGuy_PlayFootstepSounds), LVarA)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -501, 223, 15 * DT)
    EVT_KILL_THREAD(LVarA)
    EVT_EXEC_WAIT(N(EVS_SuspiciousGuy_CloseDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HiddenRoom_WaitForOuttaSight) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_IF_NE(GB_StoryProgress, STORY_CH4_MET_WITH_TWINK)
        EVT_RETURN
    EVT_END_IF
    EVT_LOOP(150 * DT)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar2, 200)
            EVT_RETURN
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar7, 0)
    // wait for player to use bow within 100 <= z <= 200
    EVT_LOOP(0)
        EVT_CALL(N(IsPartnerBow))
        EVT_IF_TRUE(LVar0)
            EVT_SET(LVar7, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar2, 100)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_IF_GT(LVar2, 200)
            // automatically satisfied while exiting the front door
            EVT_RETURN
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_SuspiciousGuy_OpenDoor))
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, -501, 20, 223)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim02)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -506, 168, 15)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Pink_Anim00)
    EVT_EXEC_WAIT(N(EVS_SuspiciousGuy_CloseDoor))
    EVT_IF_EQ(LVar7, 1)
        EVT_EXEC_WAIT(N(EVS_SuspiciousGuy_RevealSecretRoom))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_SuspiciousGuy_RunAway))
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_THREAD
            EVT_WAIT(10 * DT)
            EVT_EXEC(N(EVS_HiddenRoom_WaitForOuttaSight))
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShyGuy_StealStoreroomKey) = {
    EVT_CALL(GetNpcPos, NPC_ShyGuy_02, LVar2, LVar3, LVar4)
    EVT_ADD(LVar3, 20)
    EVT_CALL(MakeItemEntity, ITEM_VIS_GROUP(ITEM_STOREROOM_KEY, VIS_GROUP_1), LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(1)
    EVT_LOOP(30)
        EVT_CALL(GetNpcPos, NPC_ShyGuy_02, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 20)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnEnterShop) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(GB_StoryProgress, STORY_CH4_GOT_STOREROOM_KEY)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_MAC04_StoreroomKeyStolen, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_ShyGuy_02, 250, 20, -402)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0000)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_THREAD
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(20)
        EVT_SET(LVar0, 0)
        EVT_LOOP(36)
            EVT_CALL(InterpPlayerYaw, LVar0, 0)
            EVT_ADD(LVar0, 45)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(InterpPlayerYaw, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(23)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_mu, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 8)
            EVT_CALL(RotateModel, MODEL_msdoor, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_ADD(LVar0, -8)
            EVT_CALL(RotateModel, MODEL_msdoor, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit_mu, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_ShyGuy_StealStoreroomKey))
    EVT_SET(LVar0, NPC_ShyGuy_02)
    EVT_EXEC_GET_TID(N(EVS_ShyGuy_PlayFootstepSounds), LVarA)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_02, 254, -66, 30)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_ShyGuy_02, NPC_DISPOSE_LOCATION)
    EVT_SET(GF_MAC04_StoreroomKeyStolen, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_02) = {
    EVT_RETURN
    EVT_END
};
