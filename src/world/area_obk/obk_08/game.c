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
    Switch(MV_ThrowTargetNpc)
        CaseEq(NPC_Boo_01)
            Set(MV_ItemCarrierNpc, NPC_Boo_01)
        CaseEq(NPC_KeepAwayBoo1)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo1)
        CaseEq(NPC_KeepAwayBoo2)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo2)
        CaseEq(NPC_KeepAwayBoo3)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo3)
        CaseEq(NPC_KeepAwayBoo4)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo4)
        CaseEq(NPC_KeepAwayBoo5)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo5)
        CaseEq(NPC_KeepAwayBoo6)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo6)
        CaseEq(NPC_KeepAwayBoo7)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo7)
        CaseEq(NPC_KeepAwayBoo8)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo8)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TetherItemToNpcWithOffset) = {
    Loop(0)
        Call(GetNpcPos, LVar0, LVar6, LVar7, LVar8)
        Add(LVar6, LVar3)
        Add(LVar7, LVar4)
        Add(LVar8, LVar5)
        Call(SetItemPos, MV_KeepAwayItem, LVar6, LVar7, LVar8)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_BooSpookAndVanish) = {
    Call(SetNpcFlagBits, LVarA, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
    Call(NpcFacePlayer, LVarA, 0)
    Wait(5)
    Call(SetNpcAnimation, LVarA, ANIM_Boo_Spook)
    Wait(10)
    Call(MakeLerp, 255, 0, 60, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, LVarA, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(SetNpcPos, LVarA, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_Scene_BoosUnleashed) = {
    Call(DisablePlayerInput, TRUE)
    Call(InterruptUsePartner)
    Call(SetMusic, 0, SONG_BOO_MINIGAME, 0, VOL_LEVEL_FULL)
    Wait(20)
    Call(InterpPlayerYaw, 90, 0)
    Wait(20)
    Thread
        Call(SetPlayerSpeed, Float(2.0))
        Call(PlayerMoveTo, -170, 0, 0)
    EndThread
    Call(SetCamProperties, CAM_DEFAULT, Float(2.0), 0, 0, 0, Float(450.0), Float(15.0), Float(-7.0))
    Wait(60)
    Call(SetCamProperties, CAM_DEFAULT, Float(2.0), 0, 0, 0, Float(325.0), Float(13.0), Float(-13.0))
    Call(SetNpcPos, NPC_LeaderBoo, 0, 45, 20)
    Call(SetItemPos, MV_KeepAwayItem, 0, 65, 0)
    Call(MakeLerp, 0, 255, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetItemAlpha, MV_KeepAwayItem, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0030)
    Label(50)
        Call(SetCamProperties, CAM_DEFAULT, Float(2.0), 0, 0, 0, Float(500.0), Float(15.0), Float(-7.0))
        Wait(20)
        Call(MakeLerp, 255, 0, 30, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Call(SetItemAlpha, MV_KeepAwayItem, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(0)
            Wait(1)
            IfEq(MV_Unk_01, 1)
                BreakLoop
            EndIf
        EndLoop
        Wait(10)
        Set(LVar0, 270)
        Set(MV_Unk_Angle, LVar0)
        Call(N(func_80241220_BD4A90))
        Call(MakeLerp, 0, 255, 30, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Call(GetNpcPos, NPC_LeaderBoo, LVar3, LVar4, LVar5)
            Add(LVar4, 20)
            Call(SetItemPos, MV_KeepAwayItem, LVar3, LVar4, LVar5)
            Call(SetItemAlpha, MV_KeepAwayItem, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(20)
        Call(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0031)
        Wait(20)
        Thread
            Call(GetNpcPos, NPC_LeaderBoo, LVar3, LVar4, LVar5)
            Set(LVar6, LVar4)
            Add(LVar6, 20)
            Call(MakeLerp, LVar6, LVar4, 20, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(SetItemPos, MV_KeepAwayItem, LVar3, LVar0, LVar5)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Call(SetItemPos, MV_KeepAwayItem, NPC_DISPOSE_LOCATION)
        EndThread
        Wait(20)
        Call(RandInt, 360, LVar0)
        Add(LVar0, 180)
        Set(LVarA, LVar0)
        Call(RandInt, 20, LVar0)
        Add(LVar0, 360)
        Set(LVarB, LVar0)
        Set(LVar0, MV_Unk_Angle)
        Loop(0)
            Call(N(func_80241220_BD4A90))
            Call(N(func_802412BC_BD4B2C))
            Wait(1)
            Add(LVarA, -2)
            IfLe(LVarA, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(0)
            Call(N(func_80241220_BD4A90))
            Call(N(func_802412BC_BD4B2C))
            Call(N(func_80241300_BD4B70))
            Wait(1)
            IfEq(LVar1, TRUE)
                BreakLoop
            EndIf
        EndLoop
        Thread
            Call(PlaySoundAtNpc, NPC_LeaderBoo, SOUND_THROW, SOUND_SPACE_DEFAULT)
            Call(GetNpcPos, NPC_LeaderBoo, LVar3, LVar4, LVar5)
            Add(LVar5, 20)
            Set(LVar6, LVar4)
            Add(LVar6, -30)
            Call(MakeLerp, LVar4, LVar6, 15, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(SetItemPos, MV_KeepAwayItem, LVar3, LVar0, LVar5)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Call(SetItemPos, MV_KeepAwayItem, NPC_DISPOSE_LOCATION)
        EndThread
        Loop(0)
            Call(N(func_80241220_BD4A90))
            Call(N(func_802412BC_BD4B2C))
            Wait(1)
            Add(LVarB, -2)
            IfLe(LVarB, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0032)
        Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
        Wait(10)
        Set(MV_KeepAwayResult, KEEP_AWAY_WAITING)
        Call(DisablePlayerInput, FALSE)
        Loop(0)
            Wait(1)
            IfNe(MV_KeepAwayResult, KEEP_AWAY_WAITING)
                BreakLoop
            EndIf
        EndLoop
        Set(MV_Unk_02, 1)
        Call(DisablePlayerInput, TRUE)
        ExecWait(N(EVS_DetermineCarrierNPC))
        IfEq(MV_KeepAwayResult, KEEP_AWAY_RIGHT)
            Call(GetNpcPos, MV_ItemCarrierNpc, LVar3, LVar4, LVar5)
            Call(SetNpcPos, NPC_DummyBoo, LVar3, LVar4, LVar5)
            Set(LVar0, NPC_DummyBoo)
            EVT_VEC3I_SET(LVar3, 0, 0, -20)
            Exec(N(EVS_TetherItemToNpcWithOffset))
            Call(PlaySoundAtNpc, NPC_DummyBoo, SOUND_THROW, SOUND_SPACE_DEFAULT)
            Call(SetNpcJumpscale, NPC_DummyBoo, Float(2.0))
            Call(NpcJump0, NPC_DummyBoo, 0, 0, 0, 20)
            Call(SetNpcPos, NPC_DummyBoo, NPC_DISPOSE_LOCATION)
            Call(MakeItemEntity, ITEM_BOO_RECORD, 0, 0, -20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OBK08_Item_Record)
            Wait(20)
            Call(GetNpcPos, NPC_LeaderBoo, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
            Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0033)
            Wait(20)
            Thread
                Call(SetNpcJumpscale, NPC_LeaderBoo, 0)
                Call(NpcJump1, NPC_LeaderBoo, 0, 45, 0, 20)
                Call(InterpNpcYaw, NPC_LeaderBoo, 90, 0)
            EndThread
            Call(N(GetPlayerPosOutsideKeepAwayRing))
            Call(SetPlayerSpeed, Float(4.0))
            Call(PlayerMoveTo, LVar0, LVar2, 0)
            Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
            Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
            Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
            Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Wait(20)
            Thread
                Wait(30)
                Call(PlaySound, SOUND_BOO_SPOOK)
            EndThread
            Set(LVarA, NPC_KeepAwayBoo1)
            Exec(N(EVS_BooSpookAndVanish))
            Set(LVarA, NPC_KeepAwayBoo2)
            Exec(N(EVS_BooSpookAndVanish))
            Set(LVarA, NPC_KeepAwayBoo3)
            Exec(N(EVS_BooSpookAndVanish))
            Set(LVarA, NPC_KeepAwayBoo4)
            Exec(N(EVS_BooSpookAndVanish))
            Set(LVarA, NPC_KeepAwayBoo5)
            Exec(N(EVS_BooSpookAndVanish))
            Set(LVarA, NPC_KeepAwayBoo6)
            Exec(N(EVS_BooSpookAndVanish))
            Set(LVarA, NPC_KeepAwayBoo7)
            Exec(N(EVS_BooSpookAndVanish))
            Set(LVarA, NPC_KeepAwayBoo8)
            Exec(N(EVS_BooSpookAndVanish))
            Set(LVarA, NPC_LeaderBoo)
            Exec(N(EVS_BooSpookAndVanish))
            Wait(60)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
            Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
        Else
            Call(SetCamProperties, CAM_DEFAULT, Float(2.0), 0, 0, 0, Float(450.0), Float(15.0), Float(-7.0))
            Wait(30)
            Call(SetNpcFlagBits, MV_ItemCarrierNpc, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
            Call(GetNpcPos, MV_ItemCarrierNpc, LVar3, LVar4, LVar5)
            Call(GetAngleBetweenNPCs, MV_ItemCarrierNpc, NPC_Boo_01, LVar0)
            Call(InterpNpcYaw, MV_ItemCarrierNpc, LVar0, 0)
            Call(SetNpcJumpscale, MV_ItemCarrierNpc, 0)
            Call(NpcJump0, MV_ItemCarrierNpc, 0, 45, 0, 20)
            Call(InterpNpcYaw, MV_ItemCarrierNpc, 90, 0)
            Call(GetNpcPos, MV_ItemCarrierNpc, LVar6, LVar7, LVar8)
            Set(LVarA, LVar7)
            Add(LVarA, 20)
            Call(MakeLerp, LVar7, LVarA, 20, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(SetItemPos, MV_KeepAwayItem, LVar6, LVar0, LVar8)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Wait(20)
            Call(SpeakToPlayer, MV_ItemCarrierNpc, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0034)
            Call(GetNpcPos, NPC_LeaderBoo, LVar0, LVar1, LVar2)
            Call(GetNpcPos, MV_ItemCarrierNpc, LVarA, LVarB, LVarC)
            Call(SetNpcPos, NPC_LeaderBoo, LVarA, LVarB, LVarC)
            Call(SetNpcPos, MV_ItemCarrierNpc, LVar0, LVar1, LVar2)
            Wait(1)
            Call(MakeLerp, 255, 0, 20, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(SetNpcImgFXParams, MV_ItemCarrierNpc, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Wait(10)
            Call(SetNpcPos, MV_ItemCarrierNpc, LVar3, LVar4, LVar5)
            Call(InterpNpcYaw, MV_ItemCarrierNpc, 90, 0)
            Call(MakeLerp, 0, 255, 20, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(SetNpcImgFXParams, MV_ItemCarrierNpc, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(SetNpcFlagBits, MV_ItemCarrierNpc, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
            Set(MV_KeepAwayResult, KEEP_AWAY_WAITING)
            Set(MV_Unk_02, 0)
            Call(N(GetPlayerPosOutsideKeepAwayRing))
            Call(SetPlayerSpeed, Float(4.0))
            Call(PlayerMoveTo, LVar0, LVar2, 0)
            Goto(50)
        EndIf
    Set(GB_StoryProgress, STORY_CH3_GOT_RECORD)
    Exec(N(EVS_BindCabinetTriggers))
    Exec(N(EVS_SetupMusic))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
