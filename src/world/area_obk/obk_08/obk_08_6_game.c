#include "obk_08.h"

API_CALLABLE(N(func_80241220_BD4A90)) {
    Npc* npc1 = get_npc_unsafe(NPC_LeaderBoo);
    Npc* npc2 = get_npc_unsafe(NPC_Boo_01);

    npc1->pos.x = npc2->pos.x;
    npc1->pos.z = npc2->pos.z;
    npc_move_heading(npc1, npc2->planarFlyDist, script->varTable[0]);
    npc1->pos.y = npc2->pos.y + 1000.0f + 25.0f;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802412BC_BD4B2C)) {
    script->varTable[0] = clamp_angle(script->varTable[0] - 2);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241300_BD4B70)) {
    Npc* npc1 = get_npc_unsafe(NPC_KeepAwayBoo1);
    Npc* npc2 = get_npc_unsafe(NPC_KeepAwayBoo2);
    Npc* npc3 = get_npc_unsafe(NPC_KeepAwayBoo3);
    Npc* npc4 = get_npc_unsafe(NPC_KeepAwayBoo4);
    Npc* npc5 = get_npc_unsafe(NPC_KeepAwayBoo5);
    Npc* npc6 = get_npc_unsafe(NPC_KeepAwayBoo6);
    Npc* npc7 = get_npc_unsafe(NPC_KeepAwayBoo7);
    Npc* npc8 = get_npc_unsafe(NPC_KeepAwayBoo8);
    s32 keepAwayNpcID = 0;

    script->varTable[1] = FALSE;
    evt_set_variable(script, MV_ThrowTargetNpc, 0);

    if (npc1->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc1->yaw) {
        script->varTable[1] = TRUE;
        keepAwayNpcID = NPC_KeepAwayBoo1;
    }
    if (npc2->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc2->yaw) {
        script->varTable[1] = TRUE;
        keepAwayNpcID = NPC_KeepAwayBoo2;
    }
    if (npc3->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc3->yaw) {
        script->varTable[1] = TRUE;
        keepAwayNpcID = NPC_KeepAwayBoo3;
    }
    if (npc4->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc4->yaw) {
        script->varTable[1] = TRUE;
        keepAwayNpcID = NPC_KeepAwayBoo4;
    }
    if (npc5->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc5->yaw) {
        script->varTable[1] = TRUE;
        keepAwayNpcID = NPC_KeepAwayBoo5;
    }
    if (npc6->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc6->yaw) {
        script->varTable[1] = TRUE;
        keepAwayNpcID = NPC_KeepAwayBoo6;
    }
    if (npc7->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc7->yaw) {
        script->varTable[1] = TRUE;
        keepAwayNpcID = NPC_KeepAwayBoo7;
    }
    if (npc8->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc8->yaw) {
        script->varTable[1] = TRUE;
        keepAwayNpcID = NPC_KeepAwayBoo8;
    }

    evt_set_variable(script, MV_ThrowTargetNpc, keepAwayNpcID);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetPlayerPosOutsideKeepAwayRing)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc npc;
    f32 dist = dist2D(playerStatus->pos.x, playerStatus->pos.z, 0.0f, 0.0f);
    f32 yaw;
    s32 gt;
    s32 lt;

    if (!(dist > 90.0f)) {
        gt = FALSE;
    } else {
        gt = TRUE;
    }

    if (!(dist < 150.0f)) {
        lt = FALSE;
    } else {
        lt = TRUE;
    }

    if ((gt | lt) != 0) {
        yaw = atan2(playerStatus->pos.x, playerStatus->pos.z, 0.0f, 0.0f) + 180.0f;
        npc.pos.x = 0.0f;
        npc.pos.y = 0.0f;
        npc.pos.z = 0.0f;
        npc_move_heading(&npc, 80.0f, yaw);
        script->varTable[0] = npc.pos.x;
        script->varTable[1] = npc.pos.y;
        script->varTable[2] = npc.pos.z;
        script->varTable[3] = 1;
    } else {
        script->varTable[0] = playerStatus->pos.x;
        script->varTable[1] = playerStatus->pos.y;
        script->varTable[2] = playerStatus->pos.z;
        script->varTable[3] = 0;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_DetermineCarrierNPC) = {
    EVT_SWITCH(MV_ThrowTargetNpc)
        EVT_CASE_EQ(NPC_Boo_01)
            EVT_SET(MV_ItemCarrierNpc, NPC_Boo_01)
        EVT_CASE_EQ(NPC_KeepAwayBoo1)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo1)
        EVT_CASE_EQ(NPC_KeepAwayBoo2)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo2)
        EVT_CASE_EQ(NPC_KeepAwayBoo3)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo3)
        EVT_CASE_EQ(NPC_KeepAwayBoo4)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo4)
        EVT_CASE_EQ(NPC_KeepAwayBoo5)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo5)
        EVT_CASE_EQ(NPC_KeepAwayBoo6)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo6)
        EVT_CASE_EQ(NPC_KeepAwayBoo7)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo7)
        EVT_CASE_EQ(NPC_KeepAwayBoo8)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TetherItemToNpcWithOffset) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, LVar0, LVar6, LVar7, LVar8)
        EVT_ADD(LVar6, LVar3)
        EVT_ADD(LVar7, LVar4)
        EVT_ADD(LVar8, LVar5)
        EVT_CALL(SetItemPos, MV_KeepAwayItem, LVar6, LVar7, LVar8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BooSpookAndVanish) = {
    EVT_CALL(SetNpcFlagBits, LVarA, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
    EVT_CALL(NpcFacePlayer, LVarA, 0)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, LVarA, ANIM_Boo_Spook)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, 255, 0, 60, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, LVarA, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcPos, LVarA, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BoosUnleashed) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(SetMusicTrack, 0, SONG_BOO_MINIGAME, 0, 8)
    EVT_WAIT(20)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
        EVT_CALL(PlayerMoveTo, -170, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(450.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_WAIT(60)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(325.0), EVT_FLOAT(13.0), EVT_FLOAT(-13.0))
    EVT_CALL(SetNpcPos, NPC_LeaderBoo, 0, 45, 20)
    EVT_CALL(SetItemPos, MV_KeepAwayItem, 0, 65, 0)
    EVT_CALL(MakeLerp, 0, 255, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetItemAlpha, MV_KeepAwayItem, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0030)
    EVT_LABEL(50)
        EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(500.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, 255, 0, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            EVT_CALL(SetItemAlpha, MV_KeepAwayItem, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_IF_EQ(MV_Unk_01, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(10)
        EVT_SET(LVar0, 270)
        EVT_SET(MV_Unk_Angle, LVar0)
        EVT_CALL(N(func_80241220_BD4A90))
        EVT_CALL(MakeLerp, 0, 255, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            EVT_CALL(GetNpcPos, NPC_LeaderBoo, LVar3, LVar4, LVar5)
            EVT_ADD(LVar4, 20)
            EVT_CALL(SetItemPos, MV_KeepAwayItem, LVar3, LVar4, LVar5)
            EVT_CALL(SetItemAlpha, MV_KeepAwayItem, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(20)
        EVT_CALL(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0031)
        EVT_WAIT(20)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_LeaderBoo, LVar3, LVar4, LVar5)
            EVT_SET(LVar6, LVar4)
            EVT_ADD(LVar6, 20)
            EVT_CALL(MakeLerp, LVar6, LVar4, 20, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetItemPos, MV_KeepAwayItem, LVar3, LVar0, LVar5)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetItemPos, MV_KeepAwayItem, NPC_DISPOSE_LOCATION)
        EVT_END_THREAD
        EVT_WAIT(20)
        EVT_CALL(RandInt, 360, LVar0)
        EVT_ADD(LVar0, 180)
        EVT_SET(LVarA, LVar0)
        EVT_CALL(RandInt, 20, LVar0)
        EVT_ADD(LVar0, 360)
        EVT_SET(LVarB, LVar0)
        EVT_SET(LVar0, MV_Unk_Angle)
        EVT_LOOP(0)
            EVT_CALL(N(func_80241220_BD4A90))
            EVT_CALL(N(func_802412BC_BD4B2C))
            EVT_WAIT(1)
            EVT_ADD(LVarA, -2)
            EVT_IF_LE(LVarA, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_CALL(N(func_80241220_BD4A90))
            EVT_CALL(N(func_802412BC_BD4B2C))
            EVT_CALL(N(func_80241300_BD4B70))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_THREAD
            EVT_CALL(PlaySoundAtNpc, NPC_LeaderBoo, SOUND_THROW, SOUND_SPACE_DEFAULT)
            EVT_CALL(GetNpcPos, NPC_LeaderBoo, LVar3, LVar4, LVar5)
            EVT_ADD(LVar5, 20)
            EVT_SET(LVar6, LVar4)
            EVT_ADD(LVar6, -30)
            EVT_CALL(MakeLerp, LVar4, LVar6, 15, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetItemPos, MV_KeepAwayItem, LVar3, LVar0, LVar5)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetItemPos, MV_KeepAwayItem, NPC_DISPOSE_LOCATION)
        EVT_END_THREAD
        EVT_LOOP(0)
            EVT_CALL(N(func_80241220_BD4A90))
            EVT_CALL(N(func_802412BC_BD4B2C))
            EVT_WAIT(1)
            EVT_ADD(LVarB, -2)
            EVT_IF_LE(LVarB, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0032)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_WAIT(10)
        EVT_SET(MV_KeepAwayResult, KEEP_AWAY_WAITING)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_IF_NE(MV_KeepAwayResult, KEEP_AWAY_WAITING)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_SET(MV_Unk_02, 1)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_EXEC_WAIT(N(EVS_DetermineCarrierNPC))
        EVT_IF_EQ(MV_KeepAwayResult, KEEP_AWAY_RIGHT)
            EVT_CALL(GetNpcPos, MV_ItemCarrierNpc, LVar3, LVar4, LVar5)
            EVT_CALL(SetNpcPos, NPC_DummyBoo, LVar3, LVar4, LVar5)
            EVT_SET(LVar0, NPC_DummyBoo)
            EVT_VEC3I_SET(LVar3, 0, 0, -20)
            EVT_EXEC(N(EVS_TetherItemToNpcWithOffset))
            EVT_CALL(PlaySoundAtNpc, NPC_DummyBoo, SOUND_THROW, SOUND_SPACE_DEFAULT)
            EVT_CALL(SetNpcJumpscale, NPC_DummyBoo, EVT_FLOAT(2.0))
            EVT_CALL(NpcJump0, NPC_DummyBoo, 0, 0, 0, 20)
            EVT_CALL(SetNpcPos, NPC_DummyBoo, NPC_DISPOSE_LOCATION)
            EVT_CALL(MakeItemEntity, ITEM_BOO_RECORD, 0, 0, -20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OBK08_Item_Record)
            EVT_WAIT(20)
            EVT_CALL(GetNpcPos, NPC_LeaderBoo, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0033)
            EVT_WAIT(20)
            EVT_THREAD
                EVT_CALL(SetNpcJumpscale, NPC_LeaderBoo, 0)
                EVT_CALL(NpcJump1, NPC_LeaderBoo, 0, 45, 0, 20)
                EVT_CALL(InterpNpcYaw, NPC_LeaderBoo, 90, 0)
            EVT_END_THREAD
            EVT_CALL(N(GetPlayerPosOutsideKeepAwayRing))
            EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
            EVT_CALL(PlayerMoveTo, LVar0, LVar2, 0)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_WAIT(20)
            EVT_THREAD
                EVT_WAIT(30)
                EVT_CALL(PlaySound, SOUND_BOO_SPOOK)
            EVT_END_THREAD
            EVT_SET(LVarA, NPC_KeepAwayBoo1)
            EVT_EXEC(N(EVS_BooSpookAndVanish))
            EVT_SET(LVarA, NPC_KeepAwayBoo2)
            EVT_EXEC(N(EVS_BooSpookAndVanish))
            EVT_SET(LVarA, NPC_KeepAwayBoo3)
            EVT_EXEC(N(EVS_BooSpookAndVanish))
            EVT_SET(LVarA, NPC_KeepAwayBoo4)
            EVT_EXEC(N(EVS_BooSpookAndVanish))
            EVT_SET(LVarA, NPC_KeepAwayBoo5)
            EVT_EXEC(N(EVS_BooSpookAndVanish))
            EVT_SET(LVarA, NPC_KeepAwayBoo6)
            EVT_EXEC(N(EVS_BooSpookAndVanish))
            EVT_SET(LVarA, NPC_KeepAwayBoo7)
            EVT_EXEC(N(EVS_BooSpookAndVanish))
            EVT_SET(LVarA, NPC_KeepAwayBoo8)
            EVT_EXEC(N(EVS_BooSpookAndVanish))
            EVT_SET(LVarA, NPC_LeaderBoo)
            EVT_EXEC(N(EVS_BooSpookAndVanish))
            EVT_WAIT(60)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_ELSE
            EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(450.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
            EVT_WAIT(30)
            EVT_CALL(SetNpcFlagBits, MV_ItemCarrierNpc, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
            EVT_CALL(GetNpcPos, MV_ItemCarrierNpc, LVar3, LVar4, LVar5)
            EVT_CALL(GetAngleBetweenNPCs, MV_ItemCarrierNpc, NPC_Boo_01, LVar0)
            EVT_CALL(InterpNpcYaw, MV_ItemCarrierNpc, LVar0, 0)
            EVT_CALL(SetNpcJumpscale, MV_ItemCarrierNpc, 0)
            EVT_CALL(NpcJump0, MV_ItemCarrierNpc, 0, 45, 0, 20)
            EVT_CALL(InterpNpcYaw, MV_ItemCarrierNpc, 90, 0)
            EVT_CALL(GetNpcPos, MV_ItemCarrierNpc, LVar6, LVar7, LVar8)
            EVT_SET(LVarA, LVar7)
            EVT_ADD(LVarA, 20)
            EVT_CALL(MakeLerp, LVar7, LVarA, 20, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetItemPos, MV_KeepAwayItem, LVar6, LVar0, LVar8)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(20)
            EVT_CALL(SpeakToPlayer, MV_ItemCarrierNpc, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0034)
            EVT_CALL(GetNpcPos, NPC_LeaderBoo, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, MV_ItemCarrierNpc, LVarA, LVarB, LVarC)
            EVT_CALL(SetNpcPos, NPC_LeaderBoo, LVarA, LVarB, LVarC)
            EVT_CALL(SetNpcPos, MV_ItemCarrierNpc, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_CALL(MakeLerp, 255, 0, 20, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcImgFXParams, MV_ItemCarrierNpc, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(10)
            EVT_CALL(SetNpcPos, MV_ItemCarrierNpc, LVar3, LVar4, LVar5)
            EVT_CALL(InterpNpcYaw, MV_ItemCarrierNpc, 90, 0)
            EVT_CALL(MakeLerp, 0, 255, 20, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcImgFXParams, MV_ItemCarrierNpc, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(SetNpcFlagBits, MV_ItemCarrierNpc, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
            EVT_SET(MV_KeepAwayResult, KEEP_AWAY_WAITING)
            EVT_SET(MV_Unk_02, 0)
            EVT_CALL(N(GetPlayerPosOutsideKeepAwayRing))
            EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
            EVT_CALL(PlayerMoveTo, LVar0, LVar2, 0)
            EVT_GOTO(50)
        EVT_END_IF
    EVT_SET(GB_StoryProgress, STORY_CH3_GOT_RECORD)
    EVT_EXEC(N(EVS_BindCabinetTriggers))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
